#ifndef __AML_PSDK_VCDRAW_H
#define __AML_PSDK_VCDRAW_H

#include <aml-psdk/game_vc/plugin.h>

DECL_CLASS(CDraw)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(SetFOV, _ZN5CDraw6SetFOVEf, void, float fov);
    DECL_FASTCALL_SIMPLE(CalculateAspectRatio, _ZN5CDraw20CalculateAspectRatioEv, float);

    // STATIC values
    DECL_VALUE_PLT_FLT(ms_fFOV, BYBIT(0x395C68, 0x5798E0));
    DECL_VALUE_PLT_FLT(ms_fNearClipZ, BYBIT(0x396E6C, 0x57BCD0));
    DECL_VALUE_PLT_FLT(ms_fFarClipZ, BYBIT(0x394CC8, 0x577A60));
    DECL_VALUE_PLT_FLT(ms_fLODDistance, BYBIT(0x39608C, 0x57A130));
    DECL_VALUE_PLT_FLT(ms_fAspectRatio, BYBIT(0x394CDC, 0x577A88));
    DECL_VALUE_PLT_U8(FadeRed, BYBIT(0x396F04, 0x57BE00));
    DECL_VALUE_PLT_U8(FadeGreen, BYBIT(0x39540C, 0x578870));
    DECL_VALUE_PLT_U8(FadeBlue, BYBIT(0x395E30, 0x579C98));
    DECL_VALUE_PLT_U8(FadeValue, BYBIT(0x395E84, 0x579D38));
DECL_CLASS_END()

#define ms_fFOV ms_fFOV()
#define ms_fNearClipZ ms_fNearClipZ()
#define ms_fFarClipZ ms_fFarClipZ()
#define ms_fLODDistance ms_fLODDistance()
#define ms_fAspectRatio ms_fAspectRatio()
#define FadeRed FadeRed()
#define FadeGreen FadeGreen()
#define FadeBlue FadeBlue()
#define FadeValue FadeValue()

#endif // __AML_PSDK_VCDRAW_H
