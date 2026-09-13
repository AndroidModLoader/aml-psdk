#ifndef __AML_PSDK_SAWEAPONEFFECTS_H
#define __AML_PSDK_SAWEAPONEFFECTS_H

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/gta_base/Vector.h>

struct CPad;
struct CVector;

// CPlayerCrossHair - one instance per player, stored in the CWeaponEffects
// global array gCrossHair[2] (stride 0x2C, verified from the arm64 binary).
DECL_CLASS(CPlayerCrossHair)
    // Values
    u8       bActive;          // +0x00
    u32      uiClearTime;      // +0x04
    CVector  vecTargetPos;     // +0x08 (RwV3D: 3 floats)
    u8       red;              // +0x14
    u8       green;            // +0x15
    u8       blue;             // +0x16
    u8       alpha;            // +0x17
    float    fScreenScale;     // +0x18
    float    fField1C;         // +0x1C
    u32      uiScreenSize;     // +0x20
    float    fScale;           // +0x24
    u8       bField28;         // +0x28

    // Functions
    DECL_THISCALL(Update, _ZN16CPlayerCrossHair6UpdateEiP4CPad, void, int player, CPad* pad);
    DECL_THISCALL(Render, _ZN16CPlayerCrossHair6RenderEi, void, int player);
DECL_CLASS_END()
CHECKSIZE(CPlayerCrossHair, 0x2C, 0x2C);

// CWeaponEffects - fully static class, functions resolved by mangled symbol
DECL_CLASS(CWeaponEffects)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(Init, _ZN14CWeaponEffects4InitEv, void);
    DECL_FASTCALL_SIMPLE(Shutdown, _ZN14CWeaponEffects8ShutdownEv, void);
    DECL_FASTCALL_SIMPLE(Render, _ZN14CWeaponEffects6RenderEv, void);
    DECL_FASTCALL_SIMPLE(ClearCrossHair, _ZN14CWeaponEffects14ClearCrossHairEi, void, int player);
    DECL_FASTCALL_SIMPLE(ClearCrossHairImmediately, _ZN14CWeaponEffects25ClearCrossHairImmediatelyEi, void, int player);
    DECL_FASTCALL_SIMPLE(ClearCrossHairs, _ZN14CWeaponEffects15ClearCrossHairsEv, void);
    DECL_FASTCALL_SIMPLE(ClearAllCrosshairs, _ZN14CWeaponEffects18ClearAllCrosshairsEv, void);
    DECL_FASTCALL_SIMPLE(IsLockedOn, _ZN14CWeaponEffects10IsLockedOnEi, int, int player);
    DECL_FASTCALL_SIMPLE(MarkTarget, _ZN14CWeaponEffects10MarkTargetEi7CVectorhhhhfh, void, int player, CVector vecTargetPos, u8 red, u8 green, u8 blue, u8 alpha, float fScale, u8 bFade);
DECL_CLASS_END()

#endif // __AML_PSDK_SAWEAPONEFFECTS_H