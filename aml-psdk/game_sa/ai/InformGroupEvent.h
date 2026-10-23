#ifndef __AML_PSDK_SAINFORMGROUPEVENT_H
#define __AML_PSDK_SAINFORMGROUPEVENT_H

#include "../plugin.h"

struct CPed;
struct CPedGroup;
struct CEvent;

DECL_CLASS(CInformGroupEvent)
    // Construct/Deconstruct functions
    DECL_CTORCALL(CInformGroupEvent, _ZN17CInformGroupEventC2Ev);
    DECL_DTORCALL(CInformGroupEvent, _ZN17CInformGroupEventD2Ev);

    // Member functions
    DECL_THISCALL_SIMPLE(Process, _ZN17CInformGroupEvent7ProcessEv, void);
    DECL_THISCALL_HEAD(Set, _ZN17CInformGroupEvent3SetEP4CPedP9CPedGroupP6CEventi, void, CPed* ped, CPedGroup* group, CEvent* event, i32 delay)
    DECL_THISCALL_TAIL(Set, ped, group, event, delay)
    DECL_THISCALL_SIMPLE(Flush, _ZN17CInformGroupEvent5FlushEv, void);

    // Member values
    CPed* m_pPedWhoInformed;
    CPedGroup* m_pPedWhoInformedGroup;
    CEvent* m_pEvent;
    i32 m_informTime;
DECL_CLASS_END()
CHECKSIZE(CInformGroupEvent, 0x10, 0x20);

DECL_CLASS(CInformGroupEventQueue)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(Init, _ZN22CInformGroupEventQueue4InitEv, void);
    DECL_FASTCALL_SIMPLE(Add, _ZN22CInformGroupEventQueue3AddEP4CPedP9CPedGroupP6CEvent, bool, CPed* ped, CPedGroup* group, CEvent* event);
    DECL_FASTCALL_SIMPLE(Process, _ZN22CInformGroupEventQueue7ProcessEv, void);
    DECL_FASTCALL_SIMPLE(Flush, _ZN22CInformGroupEventQueue5FlushEv, void);

    // STATIC values
    DECL_OBJECT_ARRAY_PLT(CInformGroupEvent, ms_informGroupEvents, BYBIT(0x678AF8, 0x84F618));
DECL_CLASS_END()

#define ms_informGroupEvents ms_informGroupEvents()

#endif // __AML_PSDK_SAINFORMGROUPEVENT_H
