#ifndef __AML_PSDK_SASPECIALFX_H
#define __AML_PSDK_SASPECIALFX_H

#include "../plugin.h"

DECL_CLASS(CSpecialFX)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(Init, _ZN10CSpecialFX4InitEv, void);
    DECL_FASTCALL_SIMPLE(Shutdown, _ZN10CSpecialFX8ShutdownEv, void);
    DECL_FASTCALL_SIMPLE(Update, _ZN10CSpecialFX6UpdateEv, void);
    DECL_FASTCALL_SIMPLE(Render, _ZN10CSpecialFX6RenderEv, void);
    DECL_FASTCALL_SIMPLE(Render2DFXs, _ZN10CSpecialFX11Render2DFXsEv, void);
    DECL_FASTCALL_SIMPLE(AddWeaponStreak, _ZN10CSpecialFX15AddWeaponStreakEi, void, i32 nWeaponType);

    // STATIC values
    DECL_VALUE_PLT_BOOL(bVideoCam, BYBIT(0x679B20, 0x851660));
    DECL_VALUE_PLT_BOOL(bLiftCam, BYBIT(0x678A08, 0x84F430));
    DECL_VALUE_PLT_U32(SnapShotFrames, BYBIT(0x678F1C, 0x84FE60));
    DECL_VALUE_PLT_BOOL(bSnapShotActive, BYBIT(0x676A6C, 0x84B520));
DECL_CLASS_END()

#endif // __AML_PSDK_SASPECIALFX_H
