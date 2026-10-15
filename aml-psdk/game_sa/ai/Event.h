#ifndef __AML_PSDK_SAAIEVENT_H
#define __AML_PSDK_SAAIEVENT_H

#include <aml-psdk/game_sa/plugin.h>

struct CPed;

struct CEvent;

DECL_CLASS_VTABLE(CEventGroup)
    // Construct/Deconstruct functions
    CEventGroup(){}
    DECL_CTORCALL_PROXY(CEventGroup, _ZN11CEventGroupC2EP4CPed, CPed* pPed);
    DECL_DTORCALL_PROXY(CEventGroup, _ZN11CEventGroupD2Ev);

    CPed         *m_pPed;
    int           m_dwCount;
    CEvent       *m_apEvents[16];

    // Member functions
    DECL_THISCALL_HEAD(Add, _ZN11CEventGroup3AddER6CEventb, CEvent*, CEvent& rEvent, bool bForcePersistence)
    DECL_THISCALL_TAIL(Add, rEvent, bForcePersistence)
    DECL_THISCALL_HEAD(Remove, _ZN11CEventGroup6RemoveEP6CEvent, void, CEvent* pEvent)
    DECL_THISCALL_TAIL(Remove, pEvent)
    DECL_THISCALL_HEAD(HasEventOfType, _ZNK11CEventGroup14HasEventOfTypeEPK6CEvent, bool, CEvent const* pEvent)
    DECL_THISCALL_TAIL(HasEventOfType, pEvent)
    DECL_THISCALL_HEAD(GetEventOfType, _ZNK11CEventGroup14GetEventOfTypeEi, CEvent*, i32 iEventType)
    DECL_THISCALL_TAIL(GetEventOfType, iEventType)
    DECL_THISCALL_HEAD(HasEvent, _ZNK11CEventGroup8HasEventEPK6CEvent, bool, CEvent const* pEvent)
    DECL_THISCALL_TAIL(HasEvent, pEvent)
    DECL_THISCALL_SIMPLE(TickEvents, _ZN11CEventGroup10TickEventsEv, void);
    DECL_THISCALL_SIMPLE(Reorganise, _ZN11CEventGroup10ReorganiseEv, void);
    DECL_THISCALL_HEAD(RemoveInvalidEvents, _ZN11CEventGroup19RemoveInvalidEventsEb, void, bool bEverythingButScriptEvents)
    DECL_THISCALL_TAIL(RemoveInvalidEvents, bEverythingButScriptEvents)
    DECL_THISCALL_SIMPLE(GetHighestPriorityEvent, _ZNK11CEventGroup23GetHighestPriorityEventEv, CEvent*);
    DECL_THISCALL_HEAD(Flush, _ZN11CEventGroup5FlushEb, void, bool bKeepJoinGroupScriptCommands)
    DECL_THISCALL_TAIL(Flush, bKeepJoinGroupScriptCommands)
    DECL_THISCALL_HEAD(HasScriptCommandOfTaskType, _ZNK11CEventGroup26HasScriptCommandOfTaskTypeEi, bool, i32 iTaskType)
    DECL_THISCALL_TAIL(HasScriptCommandOfTaskType, iTaskType)
DECL_CLASS_END()

#endif // __AML_PSDK_SAAIEVENT_H
