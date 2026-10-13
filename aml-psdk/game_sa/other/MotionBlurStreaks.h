#ifndef __AML_PSDK_SAMOTIONBLURSTREAKS_H
#define __AML_PSDK_SAMOTIONBLURSTREAKS_H

/*
    Plugin-SDK (Grand Theft Auto San Andreas) header file
    Authors: GTA Community. See more here
    https://github.com/DK22Pac/plugin-sdk
    Do not delete this comment block. Respect others' work!
*/

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/gta_base/Vector.h>
#include <aml-psdk/gta_base/RGBA.h>

B32MACRO(typedef u32 tMotionBlurStreakId;)
B64MACRO(typedef unsigned long long tMotionBlurStreakId;)

DECL_CLASS(CRegisteredMotionBlurStreak)
    // Member functions
    DECL_THISCALL_SIMPLE(Update, _ZN27CRegisteredMotionBlurStreak6UpdateEv, void);
    DECL_THISCALL_SIMPLE(Render, _ZN27CRegisteredMotionBlurStreak6RenderEv, void);

    // Member values
    tMotionBlurStreakId m_nId;
    CRGBA m_color;
    CVector m_avecLeftPoints[3];
    CVector m_avecRightPoints[3];
    bool m_abUpdated[3];
DECL_CLASS_END()
CHECKSIZE(CRegisteredMotionBlurStreak, 0x54, 0x58);

DECL_CLASS(CMotionBlurStreaks)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(RegisterStreak, BYBIT(_ZN18CMotionBlurStreaks14RegisterStreakEjhhhh7CVectorS0_, _ZN18CMotionBlurStreaks14RegisterStreakEyhhhh7CVectorS0_), void, tMotionBlurStreakId ID, u8 R, u8 G, u8 B, u8 A, CVector FirstPoint, CVector SecondPoint);
    DECL_FASTCALL_SIMPLE(Init, _ZN18CMotionBlurStreaks4InitEv, void);
    DECL_FASTCALL_SIMPLE(Render, _ZN18CMotionBlurStreaks6RenderEv, void);
    DECL_FASTCALL_SIMPLE(Update, _ZN18CMotionBlurStreaks6UpdateEv, void);

    // STATIC values
    DECL_OBJECT_ARRAY_SYM(CRegisteredMotionBlurStreak, aStreaks, _ZN18CMotionBlurStreaks8aStreaksE);

DECL_CLASS_END()

#define aStreaks aStreaks()

#endif // __AML_PSDK_SAMOTIONBLURSTREAKS_H
