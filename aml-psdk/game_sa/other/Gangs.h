#ifndef __AML_PSDK_SAGANGS_H
#define __AML_PSDK_SAGANGS_H

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/game_sa/other/GangInfo.h>
#include <aml-psdk/game_sa/enum/PedEnums.h>

DECL_CLASS(CGangs)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(Save, _ZN6CGangs4SaveEv, bool);
    DECL_FASTCALL_SIMPLE(Load, _ZN6CGangs4LoadEv, bool);
    DECL_FASTCALL_SIMPLE(SetWillAttackPlayerWithCops, _ZN6CGangs27SetWillAttackPlayerWithCopsE8ePedTypeb, void, ePedType pedType, bool bAttackPlayerWithCops);
    DECL_FASTCALL_SIMPLE(GetWillAttackPlayerWithCops, _ZN6CGangs27GetWillAttackPlayerWithCopsE8ePedType, bool, ePedType pedType);
    DECL_FASTCALL_SIMPLE(Initialise, _ZN6CGangs10InitialiseEv, void);
    DECL_FASTCALL_SIMPLE(SetGangWeapons, _ZN6CGangs14SetGangWeaponsEsiii, void, i16 gangId, i32 weapId1, i32 weapId2, i32 weapId3);
    DECL_FASTCALL_SIMPLE(SetGangPedModelOverride, _ZN6CGangs23SetGangPedModelOverrideEsa, void, i16 gangId, i8 PedModelOverride);
    DECL_FASTCALL_SIMPLE(ChooseGangPedModel, _ZN6CGangs18ChooseGangPedModelEs, u32, i16 gangId);

    // STATIC values
    DECL_OBJECT_ARRAY_PLT(CGangInfo, Gang, BYBIT(0x679C78, 0x851908));
    DECL_OBJECT_ARRAY_PLT(bool, GangAttackWithCops, BYBIT(0x676704, 0x84AE60));
DECL_CLASS_END()

#define GangAttackWithCops GangAttackWithCops()

#endif // __AML_PSDK_SAGANGS_H
