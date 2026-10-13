#ifndef __AML_PSDK_SASTREAMINGUTILS_H
#define __AML_PSDK_SASTREAMINGUTILS_H

#include "../engine/Streaming.h"
#include "../base/Timer.h"
#include "../Events.h"
#include <functional>
#include <vector>

struct StreamingUtils
{
    struct Request
    {
        u32 m_nId;
        i32 m_nModelId;
        u32 m_nStartTime;
        u32 m_nTimeout;
        std::function<void(i32, bool)> m_fnCallback;
    };

    static inline std::vector<Request> m_aRequests;
    static inline std::vector<Request> m_aProcessingRequests;
    static inline u32 m_nNextId = 0;
    static inline bool m_bInjected = false;
    static inline bool m_bProcessing = false;
    static constexpr i32 MAX_MODELS = 26316;

    static inline bool HasModelLoaded(i32 modelId)
    {
        return modelId >= 0 && modelId < MAX_MODELS && CStreaming::ms_aInfoForModel[modelId].m_status == 1;
    }

    // Call on the game thread. A zero timeout waits until loading completes.
    static inline u32 RequestModel(i32 modelId, std::function<void(i32, bool)> fn, i32 flags = 0, u32 timeout = 10000)
    {
        if(modelId < 0 || modelId >= MAX_MODELS || !fn || !CStreaming::IsInitialised()) return 0;
        if(!m_bInjected)
        {
            Events::streamingUpdateEvent.after += ProcessRequests;
            Events::reInitGameEvent.before += Clear;
            Events::shutdownPoolsEvent.before += Clear;
            m_bInjected = true;
        }
        do { ++m_nNextId; } while(!m_nNextId || IsRequestPending(m_nNextId));
        u32 id = m_nNextId;
        m_aRequests.push_back({ id, modelId, CTimer::GetTimeMS(), timeout, std::move(fn) });
        CStreaming::RequestModel(modelId, flags);
        return id;
    }

    // Cancels the callback. Other mods may still need the native model request.
    static inline bool CancelRequest(u32 id)
    {
        if(!id) return false;
        for(auto* requests : { &m_aRequests, &m_aProcessingRequests })
        {
            for(auto& request : *requests)
            {
                if(request.m_nId != id) continue;
                request.m_nId = 0;
                request.m_fnCallback = NULL;
                return true;
            }
        }
        return false;
    }

    static inline bool IsRequestPending(u32 id)
    {
        if(!id) return false;
        for(auto* requests : { &m_aRequests, &m_aProcessingRequests })
        {
            for(auto& request : *requests) if(request.m_nId == id) return true;
        }
        return false;
    }

    static inline void Clear()
    {
        m_aRequests.clear();
        m_aProcessingRequests.clear();
    }

    static inline void ProcessRequests()
    {
        if(m_bProcessing || m_aRequests.empty()) return;
        m_bProcessing = true;
        m_aRequests.swap(m_aProcessingRequests);
        struct ProcessingState
        {
            ~ProcessingState()
            {
                for(auto& request : m_aProcessingRequests)
                {
                    if(request.m_nId) m_aRequests.push_back(std::move(request));
                }
                m_aProcessingRequests.clear();
                m_bProcessing = false;
            }
        };
        ProcessingState state;
        u32 now = CTimer::GetTimeMS();
        for(size_t i = 0; i < m_aProcessingRequests.size(); ++i)
        {
            Request& request = m_aProcessingRequests[i];
            if(!request.m_nId) continue;
            bool loaded = HasModelLoaded(request.m_nModelId);
            if(!loaded && (!request.m_nTimeout || now - request.m_nStartTime < request.m_nTimeout)) continue;
            i32 modelId = request.m_nModelId;
            auto fn = std::move(request.m_fnCallback);
            request.m_nId = 0;
            fn(modelId, loaded);
        }
    }
};

#endif // __AML_PSDK_SASTREAMINGUTILS_H
