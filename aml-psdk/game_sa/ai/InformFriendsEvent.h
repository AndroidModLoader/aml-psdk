#ifndef __AML_PSDK_SAINFORMFRIENDSEVENT_H
#define __AML_PSDK_SAINFORMFRIENDSEVENT_H

#include "../plugin.h"

struct CPed;
struct CEvent;

DECL_CLASS(CInformFriendsEvent)
    // Construct/Deconstruct functions
    DECL_CTORCALL(CInformFriendsEvent, _ZN19CInformFriendsEventC2Ev);
    DECL_DTORCALL(CInformFriendsEvent, _ZN19CInformFriendsEventD2Ev);

    // Member functions
    DECL_THISCALL_SIMPLE(Process, _ZN19CInformFriendsEvent7ProcessEv, void);
    DECL_THISCALL_HEAD(Set, _ZN19CInformFriendsEvent3SetEP4CPedP6CEventi, void, CPed* ped, CEvent* event, i32 delay)
    DECL_THISCALL_TAIL(Set, ped, event, delay)
    DECL_THISCALL_SIMPLE(Flush, _ZN19CInformFriendsEvent5FlushEv, void);

    // Member values
    CPed* m_pPedToInform;
    CEvent* m_pEvent;
    i32 m_informTime;
DECL_CLASS_END()
CHECKSIZE(CInformFriendsEvent, 0xC, 0x18);

DECL_CLASS(CInformFriendsEventQueue)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(Init, _ZN24CInformFriendsEventQueue4InitEv, void);
    DECL_FASTCALL_SIMPLE(Add, _ZN24CInformFriendsEventQueue3AddEP4CPedP6CEvent, bool, CPed* ped, CEvent* event);
    DECL_FASTCALL_SIMPLE(Process, _ZN24CInformFriendsEventQueue7ProcessEv, void);
    DECL_FASTCALL_SIMPLE(Flush, _ZN24CInformFriendsEventQueue5FlushEv, void);

    // STATIC values
    DECL_OBJECT_ARRAY_PLT(CInformFriendsEvent, ms_informFriendsEvents, BYBIT(0x679574, 0x850AF8));
DECL_CLASS_END()

#define ms_informFriendsEvents ms_informFriendsEvents()

#endif // __AML_PSDK_SAINFORMFRIENDSEVENT_H
