#ifndef __AML_PSDK_SASURFACEINFOS_H
#define __AML_PSDK_SASURFACEINFOS_H

#include "../plugin.h"
#include "../base/ColModel.h"
#include "../enum/Collision.h"

struct SurfaceInfo_t
{
    i8 tyreGrip;
    i8 wetMult;
    u32 adhesionGroup : 3;
    u32 skidmarkType : 2;
    u32 frictionEffect : 3;
    u32 bulletFx : 3;
    u32 isSoftLanding : 1;
    u32 isSeeThrough : 1;
    u32 isShootThrough : 1;
    u32 isSand : 1;
    u32 isWater : 1;
    u32 isShallowWater : 1;
    u32 isBeach : 1;
    u32 isSteepSlope : 1;
    u32 isGlass : 1;
    u32 isStairs : 1;
    u32 isSkateable : 1;
    u32 isPavement : 1;
    u32 roughness : 2;
    u32 flammability : 2;
    u32 createsSparks : 1;
    u32 cantSprintOn : 1;
    u32 leavesFootsteps : 1;
    u32 producesFootDust : 1;
    u32 makesCarDirty : 1;
    u32 makesCarClean : 1;
    u32 createsWheelGrass : 1;
    u32 createsWheelGravel : 1;
    u32 createsWheelMud : 1;
    u32 createsWheelDust : 1;
    u32 createsWheelSand : 1;
    u32 createsWheelSpray : 1;
    u32 createsPlants : 1;
    u32 createsObjects : 1;
    u32 canClimb : 1;
    u32 isAudioConcrete : 1;
    u32 isAudioGrass : 1;
    u32 isAudioSand : 1;
    u32 isAudioGravel : 1;
    u32 isAudioWood : 1;
    u32 isAudioWater : 1;
    u32 isAudioMetal : 1;
    u32 isAudioLongGrass : 1;
    u32 isAudioTile : 1;
};
CHECKSIZE(SurfaceInfo_t, 0xC, 0xC);

DECL_CLASS(SurfaceInfos_c)
    // Construct/Deconstruct functions
    DECL_CTORCALL(SurfaceInfos_c, _ZN14SurfaceInfos_cC2Ev);
    DECL_DTORCALL(SurfaceInfos_c, _ZN14SurfaceInfos_cD2Ev);

    // Member functions
    DECL_THISCALL_SIMPLE(Init, _ZN14SurfaceInfos_c4InitEv, void);
    DECL_THISCALL_HEAD(GetSurfaceIdFromName, _ZN14SurfaceInfos_c20GetSurfaceIdFromNameEPc, u32, char* surfaceName)
    DECL_THISCALL_TAIL(GetSurfaceIdFromName, surfaceName)
    DECL_THISCALL_HEAD(GetAdhesionGroup, _ZN14SurfaceInfos_c16GetAdhesionGroupEj, i32, u32 surfaceId)
    DECL_THISCALL_TAIL(GetAdhesionGroup, surfaceId)
    DECL_THISCALL_HEAD(GetTyreGrip, _ZN14SurfaceInfos_c11GetTyreGripEj, float, u32 surfaceId)
    DECL_THISCALL_TAIL(GetTyreGrip, surfaceId)
    DECL_THISCALL_HEAD(GetWetMultiplier, _ZN14SurfaceInfos_c16GetWetMultiplierEj, float, u32 surfaceId)
    DECL_THISCALL_TAIL(GetWetMultiplier, surfaceId)
    DECL_THISCALL_HEAD(GetSkidmarkType, _ZN14SurfaceInfos_c15GetSkidmarkTypeEj, eSkidmarkType, u32 surfaceId)
    DECL_THISCALL_TAIL(GetSkidmarkType, surfaceId)
    DECL_THISCALL_HEAD(GetFrictionEffect, _ZN14SurfaceInfos_c17GetFrictionEffectEj, i32, u32 surfaceId)
    DECL_THISCALL_TAIL(GetFrictionEffect, surfaceId)
    DECL_THISCALL_HEAD(GetBulletFx, _ZN14SurfaceInfos_c11GetBulletFxEj, i32, u32 surfaceId)
    DECL_THISCALL_TAIL(GetBulletFx, surfaceId)
    DECL_THISCALL_HEAD(IsSoftLanding, _ZN14SurfaceInfos_c13IsSoftLandingEj, u8, u32 surfaceId)
    DECL_THISCALL_TAIL(IsSoftLanding, surfaceId)
    DECL_THISCALL_HEAD(IsSeeThrough, _ZN14SurfaceInfos_c12IsSeeThroughEj, u8, u32 surfaceId)
    DECL_THISCALL_TAIL(IsSeeThrough, surfaceId)
    DECL_THISCALL_HEAD(IsShootThrough, _ZN14SurfaceInfos_c14IsShootThroughEj, u8, u32 surfaceId)
    DECL_THISCALL_TAIL(IsShootThrough, surfaceId)
    DECL_THISCALL_HEAD(IsSand, _ZN14SurfaceInfos_c6IsSandEj, u8, u32 surfaceId)
    DECL_THISCALL_TAIL(IsSand, surfaceId)
    DECL_THISCALL_HEAD(IsWater, _ZN14SurfaceInfos_c7IsWaterEj, u8, u32 surfaceId)
    DECL_THISCALL_TAIL(IsWater, surfaceId)
    DECL_THISCALL_HEAD(IsShallowWater, _ZN14SurfaceInfos_c14IsShallowWaterEj, u8, u32 surfaceId)
    DECL_THISCALL_TAIL(IsShallowWater, surfaceId)
    DECL_THISCALL_HEAD(IsBeach, _ZN14SurfaceInfos_c7IsBeachEj, u8, u32 surfaceId)
    DECL_THISCALL_TAIL(IsBeach, surfaceId)
    DECL_THISCALL_HEAD(IsSteepSlope, _ZN14SurfaceInfos_c12IsSteepSlopeEj, u8, u32 surfaceId)
    DECL_THISCALL_TAIL(IsSteepSlope, surfaceId)
    DECL_THISCALL_HEAD(IsGlass, _ZN14SurfaceInfos_c7IsGlassEj, u8, u32 surfaceId)
    DECL_THISCALL_TAIL(IsGlass, surfaceId)
    DECL_THISCALL_HEAD(IsStairs, _ZN14SurfaceInfos_c8IsStairsEj, u8, u32 surfaceId)
    DECL_THISCALL_TAIL(IsStairs, surfaceId)
    DECL_THISCALL_HEAD(IsSkateable, _ZN14SurfaceInfos_c11IsSkateableEj, u8, u32 surfaceId)
    DECL_THISCALL_TAIL(IsSkateable, surfaceId)
    DECL_THISCALL_HEAD(IsPavement, _ZN14SurfaceInfos_c10IsPavementEj, u8, u32 surfaceId)
    DECL_THISCALL_TAIL(IsPavement, surfaceId)
    DECL_THISCALL_HEAD(GetRoughness, _ZN14SurfaceInfos_c12GetRoughnessEj, i32, u32 surfaceId)
    DECL_THISCALL_TAIL(GetRoughness, surfaceId)
    DECL_THISCALL_HEAD(GetFlammability, _ZN14SurfaceInfos_c15GetFlammabilityEj, i32, u32 surfaceId)
    DECL_THISCALL_TAIL(GetFlammability, surfaceId)
    DECL_THISCALL_HEAD(CreatesSparks, _ZN14SurfaceInfos_c13CreatesSparksEj, u8, u32 surfaceId)
    DECL_THISCALL_TAIL(CreatesSparks, surfaceId)
    DECL_THISCALL_HEAD(CantSprintOn, _ZN14SurfaceInfos_c12CantSprintOnEj, u8, u32 surfaceId)
    DECL_THISCALL_TAIL(CantSprintOn, surfaceId)
    DECL_THISCALL_HEAD(LeavesFootsteps, _ZN14SurfaceInfos_c15LeavesFootstepsEj, u8, u32 surfaceId)
    DECL_THISCALL_TAIL(LeavesFootsteps, surfaceId)
    DECL_THISCALL_HEAD(ProducesFootDust, _ZN14SurfaceInfos_c16ProducesFootDustEj, u8, u32 surfaceId)
    DECL_THISCALL_TAIL(ProducesFootDust, surfaceId)
    DECL_THISCALL_HEAD(MakesCarDirty, _ZN14SurfaceInfos_c13MakesCarDirtyEj, u8, u32 surfaceId)
    DECL_THISCALL_TAIL(MakesCarDirty, surfaceId)
    DECL_THISCALL_HEAD(MakesCarClean, _ZN14SurfaceInfos_c13MakesCarCleanEj, u8, u32 surfaceId)
    DECL_THISCALL_TAIL(MakesCarClean, surfaceId)
    DECL_THISCALL_HEAD(CreatesWheelGrass, _ZN14SurfaceInfos_c17CreatesWheelGrassEj, u8, u32 surfaceId)
    DECL_THISCALL_TAIL(CreatesWheelGrass, surfaceId)
    DECL_THISCALL_HEAD(CreatesWheelGravel, _ZN14SurfaceInfos_c18CreatesWheelGravelEj, u8, u32 surfaceId)
    DECL_THISCALL_TAIL(CreatesWheelGravel, surfaceId)
    DECL_THISCALL_HEAD(CreatesWheelMud, _ZN14SurfaceInfos_c15CreatesWheelMudEj, u8, u32 surfaceId)
    DECL_THISCALL_TAIL(CreatesWheelMud, surfaceId)
    DECL_THISCALL_HEAD(CreatesWheelDust, _ZN14SurfaceInfos_c16CreatesWheelDustEj, u8, u32 surfaceId)
    DECL_THISCALL_TAIL(CreatesWheelDust, surfaceId)
    DECL_THISCALL_HEAD(CreatesWheelSand, _ZN14SurfaceInfos_c16CreatesWheelSandEj, u8, u32 surfaceId)
    DECL_THISCALL_TAIL(CreatesWheelSand, surfaceId)
    DECL_THISCALL_HEAD(CreatesWheelSpray, _ZN14SurfaceInfos_c17CreatesWheelSprayEj, u8, u32 surfaceId)
    DECL_THISCALL_TAIL(CreatesWheelSpray, surfaceId)
    DECL_THISCALL_HEAD(CreatesPlants, _ZN14SurfaceInfos_c13CreatesPlantsEj, u8, u32 surfaceId)
    DECL_THISCALL_TAIL(CreatesPlants, surfaceId)
    DECL_THISCALL_HEAD(CreatesObjects, _ZN14SurfaceInfos_c14CreatesObjectsEj, u8, u32 surfaceId)
    DECL_THISCALL_TAIL(CreatesObjects, surfaceId)
    DECL_THISCALL_HEAD(CanClimb, _ZN14SurfaceInfos_c8CanClimbEj, u8, u32 surfaceId)
    DECL_THISCALL_TAIL(CanClimb, surfaceId)
    DECL_THISCALL_HEAD(IsAudioConcrete, _ZN14SurfaceInfos_c15IsAudioConcreteEj, u8, u32 surfaceId)
    DECL_THISCALL_TAIL(IsAudioConcrete, surfaceId)
    DECL_THISCALL_HEAD(IsAudioGrass, _ZN14SurfaceInfos_c12IsAudioGrassEj, u8, u32 surfaceId)
    DECL_THISCALL_TAIL(IsAudioGrass, surfaceId)
    DECL_THISCALL_HEAD(IsAudioSand, _ZN14SurfaceInfos_c11IsAudioSandEj, u8, u32 surfaceId)
    DECL_THISCALL_TAIL(IsAudioSand, surfaceId)
    DECL_THISCALL_HEAD(IsAudioGravel, _ZN14SurfaceInfos_c13IsAudioGravelEj, u8, u32 surfaceId)
    DECL_THISCALL_TAIL(IsAudioGravel, surfaceId)
    DECL_THISCALL_HEAD(IsAudioWood, _ZN14SurfaceInfos_c11IsAudioWoodEj, u8, u32 surfaceId)
    DECL_THISCALL_TAIL(IsAudioWood, surfaceId)
    DECL_THISCALL_HEAD(IsAudioWater, _ZN14SurfaceInfos_c12IsAudioWaterEj, u8, u32 surfaceId)
    DECL_THISCALL_TAIL(IsAudioWater, surfaceId)
    DECL_THISCALL_HEAD(IsAudioMetal, _ZN14SurfaceInfos_c12IsAudioMetalEj, u8, u32 surfaceId)
    DECL_THISCALL_TAIL(IsAudioMetal, surfaceId)
    DECL_THISCALL_HEAD(IsAudioLongGrass, _ZN14SurfaceInfos_c16IsAudioLongGrassEj, u8, u32 surfaceId)
    DECL_THISCALL_TAIL(IsAudioLongGrass, surfaceId)
    DECL_THISCALL_HEAD(IsAudioTile, _ZN14SurfaceInfos_c11IsAudioTileEj, u8, u32 surfaceId)
    DECL_THISCALL_TAIL(IsAudioTile, surfaceId)
    DECL_THISCALL_HEAD(GetAdhesiveLimit, _ZN14SurfaceInfos_c16GetAdhesiveLimitER9CColPoint, float, CColPoint& colPoint)
    DECL_THISCALL_TAIL(GetAdhesiveLimit, colPoint)
    DECL_THISCALL_SIMPLE(LoadAdhesiveLimits, _ZN14SurfaceInfos_c18LoadAdhesiveLimitsEv, void);
    DECL_THISCALL_SIMPLE(LoadSurfaceInfos, _ZN14SurfaceInfos_c16LoadSurfaceInfosEv, void);
    DECL_THISCALL_SIMPLE(LoadSurfaceAudioInfos, _ZN14SurfaceInfos_c21LoadSurfaceAudioInfosEv, void);

    // Member values
    float m_adhesiveLimitTable[36];
    SurfaceInfo_t m_surfaceInfos[209];
DECL_CLASS_END()
CHECKSIZE(SurfaceInfos_c, 0xA5C, 0xA5C);

DECL_OBJECT_PLT_GLOBAL(SurfaceInfos_c, g_surfaceInfos, BYBIT(0x677674, 0x84CD18));

#endif // __AML_PSDK_SASURFACEINFOS_H
