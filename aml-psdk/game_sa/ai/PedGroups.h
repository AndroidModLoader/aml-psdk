#ifndef __AML_PSDK_SAPEDGROUPS_H
#define __AML_PSDK_SAPEDGROUPS_H

#include "PedGroup.h"

DECL_CLASS(CPedGroups)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(AddGroup, _ZN10CPedGroups8AddGroupEv, i32);
    DECL_FASTCALL_SIMPLE(RemoveGroup, _ZN10CPedGroups11RemoveGroupEi, void, int const iGroupID);
    DECL_FASTCALL_SIMPLE(RemoveAllFollowersFromGroup, _ZN10CPedGroups27RemoveAllFollowersFromGroupEi, void, int const iGroupID);
    DECL_FASTCALL_SIMPLE(Process, _ZN10CPedGroups7ProcessEv, void);
    DECL_FASTCALL_SIMPLE(Init, _ZN10CPedGroups4InitEv, void);
    DECL_FASTCALL_SIMPLE(IsGroupLeader, _ZN10CPedGroups13IsGroupLeaderEP4CPed, bool, CPed* pPed);
    DECL_FASTCALL_SIMPLE(AreInSameGroup, _ZN10CPedGroups14AreInSameGroupEPK4CPedS2_, bool, CPed const* pPed1, CPed const* pPed2);
    DECL_FASTCALL_SIMPLE(GetPedsGroup, _ZN10CPedGroups12GetPedsGroupEPK4CPed, CPedGroup*, CPed const* pPed);
    DECL_FASTCALL_SIMPLE(GetGroupId, _ZN10CPedGroups10GetGroupIdEP9CPedGroup, i32, CPedGroup* pPedGroup);
    DECL_FASTCALL_SIMPLE(IsInPlayersGroup, _ZN10CPedGroups16IsInPlayersGroupEPK4CPed, bool, CPed const* pPed);
    DECL_FASTCALL_SIMPLE(RegisterKillByPlayer, _ZN10CPedGroups20RegisterKillByPlayerEv, void);
    DECL_FASTCALL_SIMPLE(CleanUpForShutDown, _ZN10CPedGroups18CleanUpForShutDownEv, void);
    DECL_FASTCALL_SIMPLE(Save, _ZN10CPedGroups4SaveEv, void);
    DECL_FASTCALL_SIMPLE(Load, _ZN10CPedGroups4LoadEv, void);

    enum
    {
        MAX_NUM_GROUPS = 8,
    };

    // STATIC values
    DECL_OBJECT_ARRAY_PLT(bool, ms_activeGroups, BYBIT(0x677358, 0x84C6E8));
    DECL_OBJECT_ARRAY_PLT(u16, ScriptReferenceIndex, BYBIT(0x677A48, 0x84D4B8));
    DECL_OBJECT_ARRAY_PLT(CPedGroup, ms_groups, BYBIT(0x676C20, 0x84B888));
    DECL_VALUE_PLT_BOOL(ms_bIsPlayerOnAMission, BYBIT(0x6780E8, 0x84E1E8));
    DECL_OBJECT_PLT(int, ms_iNoOfPlayerKills, BYBIT(0x679F84, 0x851F18));

DECL_CLASS_END()
CHECKSIZE(CPedGroups, 0x1, 0x1);

#endif // __AML_PSDK_SAPEDGROUPS_H
