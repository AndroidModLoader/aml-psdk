#ifndef __AML_PSDK_CALLEVENTS_H
#define __AML_PSDK_CALLEVENTS_H

#include "sdk_base.h"
#include <cstdint>
#include <vector>
#include <tuple>
#include <type_traits>
#include <utility>
#include <memory>

enum class EventPhase { Before, After };
struct EventHooker
{
    enum EventHookType { EHT_SYM, EHT_ADDR, EHT_PLT, EHT_BL, EHT_BLX /* <- ARM64 = BL */} type;
    const char* sym;
    uintptr_t   addr;

    void Install(void* detour, void** orig) const
    {
        if(type == EHT_PLT)
        {
            aml->HookPLT((void*)(GetMainLibraryAddress() + addr), detour, orig);
        }
        else if(type == EHT_ADDR)
        {
            aml->Hook((void*)(GetMainLibraryAddress() + addr), detour, orig);
        }
        else if(type == EHT_BL)
        {
            aml->HookBL((void*)(GetMainLibraryAddress() + addr), detour, orig);
        }
        else if(type == EHT_BLX)
        {
            aml->HookBLX((void*)(GetMainLibraryAddress() + addr), detour, orig);
        }
        else if(sym != NULL)
        {
            aml->Hook(GetMainLibrarySymbol(sym), detour, orig);
        }
    }
};

template <class Tag, EventPhase Def, class Sig, std::size_t... Pick> struct CallEvent;

template <class Tag, EventPhase Def, class R, class... A, std::size_t... Pick>
struct CallEvent<Tag, Def, R(A...), Pick...>
{
    using AllArgs  = std::tuple<A...>;
    using Listener = void(*)(std::tuple_element_t<Pick, AllArgs>...);
    using OrigT    = R(*)(A...);

    static inline OrigT                 m_pOriginalFunc = nullptr;
    static std::vector<Listener>& BeforeListeners() { static std::vector<Listener> listeners; return listeners; }
    static std::vector<Listener>& AfterListeners() { static std::vector<Listener> listeners; return listeners; }
    static std::shared_ptr<const std::vector<Listener>>& BeforeSnapshot()
    {
        static std::shared_ptr<const std::vector<Listener>> snapshot;
        return snapshot;
    }
    static std::shared_ptr<const std::vector<Listener>>& AfterSnapshot()
    {
        static std::shared_ptr<const std::vector<Listener>> snapshot;
        return snapshot;
    }
    static inline std::vector<Listener>& s_before = BeforeListeners();
    static inline std::vector<Listener>& s_after = AfterListeners();

    EventHooker m_hook;
    explicit CallEvent(EventHooker h) : m_hook(h) {}

    struct List
    {
        std::vector<Listener>& v; CallEvent* e;
        void operator+=(Listener fn) { if(fn) { v.push_back(fn); e->StartEvent(); } }
        void operator-=(Listener fn) { for(auto it = v.begin(); it != v.end(); ++it) if(*it == fn) { v.erase(it); break; } }
    };
    List before{ BeforeListeners(), this };
    List after { AfterListeners(),  this };

    void operator+=(Listener fn) { if constexpr (Def == EventPhase::Before) before += fn; else after += fn; }
    void operator-=(Listener fn) { if constexpr (Def == EventPhase::Before) before -= fn; else after -= fn; }

    void StartEvent()
    {
        if(!m_pOriginalFunc) m_hook.Install((void*)(&EventExecuted), (void**)(&m_pOriginalFunc));
    }

    static void ExecuteListeners(std::vector<Listener>& listeners,
        std::shared_ptr<const std::vector<Listener>>& cache, AllArgs& args)
    {
        if(listeners.empty()) return;
        if(!cache || *cache != listeners) cache = std::make_shared<const std::vector<Listener>>(listeners);
        auto snapshot = cache;
        for(auto fn : *snapshot) if(fn) fn(std::get<Pick>(args)...);
    }

    static R EventExecuted(A... a)
    {
        AllArgs t{a...};
        ExecuteListeners(BeforeListeners(), BeforeSnapshot(), t);
        if constexpr (std::is_void_v<R>)
        {
            std::apply(m_pOriginalFunc, t);
            ExecuteListeners(AfterListeners(), AfterSnapshot(), t);
        }
        else
        {
            R r = std::apply(m_pOriginalFunc, t);
            ExecuteListeners(AfterListeners(), AfterSnapshot(), t);
            return r;
        }
    }
};

#define EVENT_SYM(name, ret, args, sym, ...) \
    struct name##_tag {}; \
    static inline CallEvent<name##_tag, EventPhase::After, ret args, ##__VA_ARGS__> name { EventHooker{EventHooker::EHT_SYM, #sym, 0} }
#define EVENT_SYM_BEFORE(name, ret, args, sym, ...) \
    struct name##_tag {}; \
    static inline CallEvent<name##_tag, EventPhase::Before, ret args, ##__VA_ARGS__> name { EventHooker{EventHooker::EHT_SYM, #sym, 0} }

#define EVENT_ADDR(name, ret, args, addr, ...) \
    struct name##_tag {}; \
    static inline CallEvent<name##_tag, EventPhase::After, ret args, ##__VA_ARGS__> name { EventHooker{EventHooker::EHT_ADDR, NULL, (uintptr_t)(addr)} }
#define EVENT_ADDR_BEFORE(name, ret, args, addr, ...) \
    struct name##_tag {}; \
    static inline CallEvent<name##_tag, EventPhase::Before, ret args, ##__VA_ARGS__> name { EventHooker{EventHooker::EHT_ADDR, NULL, (uintptr_t)(addr)} }
    
#define EVENT_PLT(name, ret, args, addr, ...) \
    struct name##_tag {}; \
    static inline CallEvent<name##_tag, EventPhase::After, ret args, ##__VA_ARGS__> name { EventHooker{EventHooker::EHT_PLT, NULL, (uintptr_t)(addr)} }
#define EVENT_PLT_BEFORE(name, ret, args, addr, ...) \
    struct name##_tag {}; \
    static inline CallEvent<name##_tag, EventPhase::Before, ret args, ##__VA_ARGS__> name { EventHooker{EventHooker::EHT_PLT, NULL, (uintptr_t)(addr)} }
    
#define EVENT_BL(name, ret, args, addr, ...) \
    struct name##_tag {}; \
    static inline CallEvent<name##_tag, EventPhase::After, ret args, ##__VA_ARGS__> name { EventHooker{EventHooker::EHT_BL, NULL, (uintptr_t)(addr)} }
#define EVENT_BL_BEFORE(name, ret, args, addr, ...) \
    struct name##_tag {}; \
    static inline CallEvent<name##_tag, EventPhase::Before, ret args, ##__VA_ARGS__> name { EventHooker{EventHooker::EHT_BL, NULL, (uintptr_t)(addr)} }
    
#define EVENT_BLX(name, ret, args, addr, ...) \
    struct name##_tag {}; \
    static inline CallEvent<name##_tag, EventPhase::After, ret args, ##__VA_ARGS__> name { EventHooker{EventHooker::EHT_BLX, NULL, (uintptr_t)(addr)} }
#define EVENT_BLX_BEFORE(name, ret, args, addr, ...) \
    struct name##_tag {}; \
    static inline CallEvent<name##_tag, EventPhase::Before, ret args, ##__VA_ARGS__> name { EventHooker{EventHooker::EHT_BLX, NULL, (uintptr_t)(addr)} }



#endif // __AML_PSDK_CALLEVENTS_H
