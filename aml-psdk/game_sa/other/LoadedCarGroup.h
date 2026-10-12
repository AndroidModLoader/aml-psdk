#ifndef __AML_PSDK_SALOADEDCARGROUP_H
#define __AML_PSDK_SALOADEDCARGROUP_H

#include <aml-psdk/game_sa/plugin.h>

DECL_CLASS(CLoadedCarGroup)
    i16                                aMembers[23];

    // Functions
    DECL_THISCALL_SIMPLE(Clear, _ZN15CLoadedCarGroup5ClearEv, void);
    DECL_THISCALL(AddMember, _ZN15CLoadedCarGroup9AddMemberEi, void, i32 modelId);
    DECL_THISCALL(RemoveMember, _ZN15CLoadedCarGroup12RemoveMemberEi, void, i32 modelId);
    DECL_THISCALL(GetMember, _ZN15CLoadedCarGroup9GetMemberEi, i32, i32 index);
    DECL_THISCALL_SIMPLE(CountMembers, _ZN15CLoadedCarGroup12CountMembersEv, i32);
    DECL_THISCALL(PickRandomCar, _ZN15CLoadedCarGroup13PickRandomCarEbb, i32, bool bOnlyPickNormalCars, bool bNotTooManyInWorld);
    DECL_THISCALL(PickLeastUsedModel, _ZN15CLoadedCarGroup18PickLeastUsedModelEi, i32, i32 maxTimesUsed);
    DECL_THISCALL_SIMPLE(SortBasedOnUsage, _ZN15CLoadedCarGroup16SortBasedOnUsageEv, void);
DECL_CLASS_END()
CHECKSIZE(CLoadedCarGroup, 0x2E, 0x2E);  // 64-bit from the IDB; 32-bit measured from this layout

#endif // __AML_PSDK_SALOADEDCARGROUP_H
