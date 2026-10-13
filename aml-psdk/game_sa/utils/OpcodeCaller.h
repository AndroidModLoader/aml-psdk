#ifndef __AML_PSDK_SAOPCODECALLER_H
#define __AML_PSDK_SAOPCODECALLER_H

#include <aml-psdk/game_sa/engine/RunningScript.h>
#include <stddef.h>
#include "OpcodeCallerIDs.h"

struct ZeroArg {};

struct OpcodeCaller
{
    OpcodeCaller()
    {
        ResetScript();
    }

    static inline void ResetScript()
    {
        memset(&g_Script, 0, sizeof(g_Script));
        strcpy(g_Script.m_szName, "amlpsdk");
        g_Script.m_pBaseIP = g_Script.m_pCurrentIP = g_ScriptBuffer;
        
        // CRunningScript::Init
        g_Script.m_nScriptBrainType = -1;
        g_Script.m_bWastedBustedCheck = true;
    }

    static inline void ResetCommand()
    {
        g_Script.m_pNext = g_Script.m_pPrev = NULL;
        strcpy(g_Script.m_szName, "amlpsdk");
        g_Script.m_pBaseIP = g_Script.m_pCurrentIP = g_ScriptBuffer;
        g_Script.m_nSP = 0;
        memset((u8*)&g_Script + offsetof(CRunningScript, m_anTimers), 0, sizeof(g_Script) - offsetof(CRunningScript, m_anTimers));
        g_Script.m_nScriptBrainType = -1;
        g_Script.m_bWastedBustedCheck = true;
    }

    static inline bool ReserveBuffer(uint16_t size)
    {
        if(g_bBufferError) return false;
        if(size > sizeof(g_ScriptBuffer) || g_nBufferPos > sizeof(g_ScriptBuffer) - size)
        {
            g_bBufferError = true;
            return false;
        }
        return true;
    }

    static inline void PushVarToBuffer(ZeroArg)
    {
        if(!ReserveBuffer(1)) return;
        g_ScriptBuffer[g_nBufferPos++] = 0x00;
    }
    static inline void PushVarToBuffer(int v)
    {
        if(!ReserveBuffer(5)) return;
        g_ScriptBuffer[g_nBufferPos] = 0x01;
        memcpy(&g_ScriptBuffer[++g_nBufferPos], &v, 4);
        g_nBufferPos += 4;
    }
    static inline void PushVarToBuffer(unsigned int v)
    {
        if(!ReserveBuffer(5)) return;
        g_ScriptBuffer[g_nBufferPos] = 0x01;
        memcpy(&g_ScriptBuffer[++g_nBufferPos], &v, 4);
        g_nBufferPos += 4;
    }
    static inline void PushVarToBuffer(float v)
    {
        if(!ReserveBuffer(5)) return;
        g_ScriptBuffer[g_nBufferPos] = 0x06;
        memcpy(&g_ScriptBuffer[++g_nBufferPos], &v, 4);
        g_nBufferPos += 4;
    }
    static inline void PushVarToBuffer(double v)
    {
        PushVarToBuffer((float)v);
    }
    static inline void PushVarToBuffer(const char* s)
    {
        if(g_bBufferError) return;
        if(!s)
        {
            g_bBufferError = true;
            return;
        }
        size_t aLen = strnlen(s, 128);
        if(aLen == 128)
        {
            g_bBufferError = true;
            return;
        }
        if(!ReserveBuffer(aLen + 2)) return;
        g_ScriptBuffer[g_nBufferPos] = 0x0E;
        g_ScriptBuffer[++g_nBufferPos] = aLen;
        memcpy(&g_ScriptBuffer[++g_nBufferPos], s, aLen);
        g_nBufferPos += aLen;
    }
    static inline void PushVariable(void *v)
    {
        if(g_bBufferError) return;
        if(!v || g_nVarsCount >= sizeof(g_ScriptVarPointers) / sizeof(g_ScriptVarPointers[0]))
        {
            g_bBufferError = true;
            return;
        }
        if(!ReserveBuffer(3)) return;
        g_ScriptBuffer[g_nBufferPos] = 0x03;
        g_ScriptVarPointers[g_nVarsCount] = (uint32_t*)v;
        memcpy(&g_Script.m_aLocalVars[g_nVarsCount], v, 4);
        uint16_t varIndex = g_nVarsCount;
        memcpy(&g_ScriptBuffer[++g_nBufferPos], &varIndex, 2);
        g_nBufferPos += 2;
        ++g_nVarsCount;
    }
    static inline void PushVarToBuffer(int *v)
    {
        PushVariable(v);
    }
    static inline void PushVarToBuffer(unsigned int *v)
    {
        PushVariable(v);
    }
    static inline void PushVarToBuffer(float *v)
    {
        PushVariable(v);
    }

    static inline CRunningScript g_Script { 0 };
    static inline uint8_t g_ScriptBuffer[512] { 0 };
    static inline u32* g_ScriptVarPointers[40] { NULL };
    static inline uint16_t g_nBufferPos = 0;
    static inline uint8_t g_nVarsCount = 0;
    static inline bool g_bBufferError = false;
    static inline uint32_t g_nCallDepth = 0;
    static inline uint32_t g_nBatchDepth = 0;
    static inline tScriptParam* g_pScriptParams = NULL;
    static inline tScriptParam g_SavedScriptParams[32] { { 0 } };
};
inline OpcodeCaller g_OpcodeCallerStub;

inline void PushVars() {}

template <typename T>
inline void PushVars(T arg)
{
    OpcodeCaller::PushVarToBuffer(arg);
}
template <typename A1, typename... Args>
inline void PushVars(A1 arg, Args... args)
{
    PushVars(arg);
    PushVars(args...);
}

template<typename... ArgTypes>
__attribute__((always_inline)) inline bool CommandByIDDirect(uint16_t opcode, ArgTypes... args)
{
    ++OpcodeCaller::g_nCallDepth;
    OpcodeCaller::ResetCommand();
    memcpy(OpcodeCaller::g_ScriptBuffer, &opcode, 2);
    OpcodeCaller::g_nBufferPos = 2;
    OpcodeCaller::g_nVarsCount = 0;
    OpcodeCaller::g_bBufferError = false;
    PushVars(args...);

    bool result = false;
    if(!OpcodeCaller::g_bBufferError)
    {
        if(!OpcodeCaller::g_pScriptParams)
        {
            OpcodeCaller::g_pScriptParams = GetMainLibrarySymbol<tScriptParam*>("ScriptParams");
        }
        tScriptParam* pScriptParams = OpcodeCaller::g_pScriptParams;
        if(pScriptParams)
        {
            uint8_t varsCount = OpcodeCaller::g_nVarsCount;
            bool saveParams = !OpcodeCaller::g_nBatchDepth || OpcodeCaller::g_nCallDepth > 1;
            if(saveParams) memcpy(OpcodeCaller::g_SavedScriptParams, pScriptParams, sizeof(OpcodeCaller::g_SavedScriptParams));
            OpcodeCaller::g_Script.ProcessOneCommand();
            if(saveParams) memcpy(pScriptParams, OpcodeCaller::g_SavedScriptParams, sizeof(OpcodeCaller::g_SavedScriptParams));
            for(int i = 0; i < varsCount; ++i)
            {
                memcpy(OpcodeCaller::g_ScriptVarPointers[i], &OpcodeCaller::g_Script.m_aLocalVars[i], 4);
            }
            result = OpcodeCaller::g_Script.m_bCondResult;
        }
    }

    --OpcodeCaller::g_nCallDepth;
    return result;
}

template<typename... ArgTypes>
__attribute__((noinline, cold)) inline bool CommandByIDNested(uint16_t opcode, ArgTypes... args)
{
    CRunningScript savedScript;
    uint8_t savedBuffer[sizeof(OpcodeCaller::g_ScriptBuffer)];
    u32* savedVarPointers[40];
    tScriptParam savedScriptParams[32];
    uint16_t savedBufferPos = OpcodeCaller::g_nBufferPos;
    uint8_t savedVarsCount = OpcodeCaller::g_nVarsCount;
    bool savedBufferError = OpcodeCaller::g_bBufferError;
    memcpy(&savedScript, &OpcodeCaller::g_Script, sizeof(savedScript));
    memcpy(savedBuffer, OpcodeCaller::g_ScriptBuffer, sizeof(savedBuffer));
    memcpy(savedVarPointers, OpcodeCaller::g_ScriptVarPointers, sizeof(savedVarPointers));
    memcpy(savedScriptParams, OpcodeCaller::g_SavedScriptParams, sizeof(savedScriptParams));

    bool result = CommandByIDDirect(opcode, args...);

    memcpy(&OpcodeCaller::g_Script, &savedScript, sizeof(savedScript));
    memcpy(OpcodeCaller::g_ScriptBuffer, savedBuffer, sizeof(savedBuffer));
    memcpy(OpcodeCaller::g_ScriptVarPointers, savedVarPointers, sizeof(savedVarPointers));
    memcpy(OpcodeCaller::g_SavedScriptParams, savedScriptParams, sizeof(savedScriptParams));
    OpcodeCaller::g_nBufferPos = savedBufferPos;
    OpcodeCaller::g_nVarsCount = savedVarsCount;
    OpcodeCaller::g_bBufferError = savedBufferError;
    return result;
}

template<typename... ArgTypes>
inline bool CommandByID(uint16_t opcode, ArgTypes... args)
{
    if(OpcodeCaller::g_nCallDepth) return CommandByIDNested(opcode, args...);
    return CommandByIDDirect(opcode, args...);
}

template <uint16_t CommandID, typename... ArgTypes>
inline bool Command(ArgTypes... arguments)
{
    return CommandByID(CommandID, arguments...);
}

template<typename Fn>
inline void CommandBatch(Fn fn)
{
    if(OpcodeCaller::g_nCallDepth || OpcodeCaller::g_nBatchDepth)
    {
        fn();
        return;
    }
    if(!OpcodeCaller::g_pScriptParams)
    {
        OpcodeCaller::g_pScriptParams = GetMainLibrarySymbol<tScriptParam*>("ScriptParams");
    }
    if(!OpcodeCaller::g_pScriptParams)
    {
        fn();
        return;
    }

    struct BatchState
    {
        tScriptParam* params;
        tScriptParam savedParams[32];

        BatchState(tScriptParam* pParams) : params(pParams)
        {
            memcpy(savedParams, params, sizeof(savedParams));
            ++OpcodeCaller::g_nBatchDepth;
        }
        ~BatchState()
        {
            --OpcodeCaller::g_nBatchDepth;
            memcpy(params, savedParams, sizeof(savedParams));
        }
    };
    BatchState state(OpcodeCaller::g_pScriptParams);
    fn();
}

#endif // __AML_PSDK_SAOPCODECALLER_H
