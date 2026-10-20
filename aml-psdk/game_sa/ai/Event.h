#ifndef __AML_PSDK_SAAIEVENT_H
#define __AML_PSDK_SAAIEVENT_H

#include <aml-psdk/game_sa/plugin.h>

struct CPed;
struct CPedGroup;
struct CEntity;
struct CVector;

struct CEvent;

DECL_CLASS_VTABLE(CEventGroup)
    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CEventGroup, _ZN11CEventGroupC2EP4CPed, CPed* pPed)
    DECL_CTORCALL_ARG_TAIL(pPed)
    DECL_DTORCALL_VIRTUAL(CEventGroup, _ZN11CEventGroupD2Ev, _ZN11CEventGroup, _ZTV11CEventGroup);

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
CHECKSIZE(CEventGroup, 0x4C, 0x98);

DECL_CLASS_BASED(CEventGlobalGroup, CEventGroup)
    // Construct/Deconstruct functions
    DECL_CTORCALL(CEventGlobalGroup, _ZN17CEventGlobalGroupC2Ev);
    DECL_DTORCALL_VIRTUAL(CEventGlobalGroup, _ZN17CEventGlobalGroupD2Ev, _ZN17CEventGlobalGroup, _ZTV17CEventGlobalGroup);

    // Member functions
    DECL_THISCALL_HEAD(AddEventsToPed, _ZN17CEventGlobalGroup14AddEventsToPedEP4CPed, void, CPed* ped)
    DECL_THISCALL_TAIL(AddEventsToPed, ped)
    DECL_THISCALL_HEAD(AddEventsToGroup, _ZN17CEventGlobalGroup16AddEventsToGroupEP9CPedGroup, void, CPedGroup* group)
    DECL_THISCALL_TAIL(AddEventsToGroup, group)
    DECL_THISCALL_HEAD(GetSoundLevel, _ZN17CEventGlobalGroup13GetSoundLevelEP7CEntityR7CVector, float, CEntity* entity, CVector& pos)
    DECL_THISCALL_TAIL(GetSoundLevel, entity, pos)

DECL_CLASS_END()
CHECKSIZE(CEventGlobalGroup, 0x4c, 0x98);

DECL_CLASS(CEventSource)
    enum
    {
        EVENT_SOURCE_UNDEFINED = 0,
        EVENT_SOURCE_PLAYER = 1,
        EVENT_SOURCE_FRIEND = 2,
        EVENT_SOURCE_THREAT = 3,
        MAX_NUM_EVENT_SOURCES = 4
    };

    // STATIC functions
    DECL_FASTCALL_SIMPLE(ComputeEventSourceType, _ZN12CEventSource22ComputeEventSourceTypeERK6CEventRK4CPed, i32, CEvent const& event, CPed const& ped);

DECL_CLASS_END()
CHECKSIZE(CEventSource, 0x1, 0x1);

#endif // __AML_PSDK_SAAIEVENT_H
