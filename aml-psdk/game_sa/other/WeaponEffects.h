#ifndef __AML_PSDK_SAWEAPONEFFECTS_H
#define __AML_PSDK_SAWEAPONEFFECTS_H

/*
    Plugin-SDK (Grand Theft Auto San Andreas) header file
    Authors: GTA Community. See more here
    https://github.com/DK22Pac/plugin-sdk
    Do not delete this comment block. Respect others' work!
*/

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/gta_base/Vector.h>
#include <aml-psdk/gta_base/RGBA.h>

struct RwTexture;

DECL_CLASS(CWeaponEffects)
    // Construct/Deconstruct functions
    DECL_CTORCALL(CWeaponEffects, _ZN14CWeaponEffectsC2Ev);
    DECL_DTORCALL(CWeaponEffects, _ZN14CWeaponEffectsD2Ev);

    // STATIC functions
    DECL_FASTCALL_SIMPLE(Init, _ZN14CWeaponEffects4InitEv, void);
    DECL_FASTCALL_SIMPLE(Shutdown, _ZN14CWeaponEffects8ShutdownEv, void);
    DECL_FASTCALL_SIMPLE(IsLockedOn, _ZN14CWeaponEffects10IsLockedOnEi, u8, i32 Index);
    DECL_FASTCALL_SIMPLE(MarkTarget, _ZN14CWeaponEffects10MarkTargetEi7CVectorhhhhfh, void, i32 Index, CVector vecTargetPos, u8 red, u8 green, u8 blue, u8 alpha, float fScale, u8 type);
    DECL_FASTCALL_SIMPLE(ClearCrossHair, _ZN14CWeaponEffects14ClearCrossHairEi, void, i32 Index);
    DECL_FASTCALL_SIMPLE(ClearCrossHairs, _ZN14CWeaponEffects15ClearCrossHairsEv, void);
    DECL_FASTCALL_SIMPLE(ClearCrossHairImmediately, _ZN14CWeaponEffects25ClearCrossHairImmediatelyEi, void, i32 Index);
    DECL_FASTCALL_SIMPLE(ClearAllCrosshairs, _ZN14CWeaponEffects18ClearAllCrosshairsEv, void);
    DECL_FASTCALL_SIMPLE(Render, _ZN14CWeaponEffects6RenderEv, void);

    // Member values
    bool m_bActive;
    u32 m_nTimeWhenToDeactivate;
    CVector m_vecPosn;
    CRGBA m_color;
    float m_fSize;
    float m_fRotation;
    float m_fRadius;
    float m_fLockOnProgress;
    u8 m_nType;
DECL_CLASS_END()
CHECKSIZE(CWeaponEffects, 0x2C, 0x2C);

DECL_OBJECT_ARRAY_PLT_GLOBAL(CWeaponEffects, gCrossHair, BYBIT(0x677D88, 0x84DB30));
#define gCrossHair gCrossHair()

DECL_OBJECT_PLT_GLOBAL(RwTexture*, gpCrossHairTex, BYBIT(0x676278, 0x84A550));
#define gpCrossHairTex gpCrossHairTex()

DECL_OBJECT_ARRAY_PLT_GLOBAL(RwTexture*, gpCrossHairTexFlight, BYBIT(0x6798E0, 0x8511E0));
#define gpCrossHairTexFlight gpCrossHairTexFlight()

#endif // __AML_PSDK_SAWEAPONEFFECTS_H
