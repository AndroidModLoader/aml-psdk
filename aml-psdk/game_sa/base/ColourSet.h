#ifndef __AML_PSDK_SACOLOURSET_H
#define __AML_PSDK_SACOLOURSET_H

/*
    Plugin-SDK (Grand Theft Auto San Andreas) header file
    Authors: GTA Community. See more here
    https://github.com/DK22Pac/plugin-sdk
    Do not delete this comment block. Respect others' work!
*/

#include <aml-psdk/game_sa/plugin.h>

DECL_CLASS(CColourSet)
    // Construct functions
    DECL_CTORCALL_ARG_HEAD(CColourSet, _ZN10CColourSetC2Eii, i32 weatherId, i32 timeId)
    DECL_CTORCALL_ARG_TAIL(weatherId, timeId)

    // Member functions
    DECL_THISCALL_HEAD(Interpolate, _ZN10CColourSet11InterpolateEPS_S0_ffb, void, CColourSet *a, CColourSet *b, float factor_a, float factor_b, bool bIgnoreSky)
    DECL_THISCALL_TAIL(Interpolate, a, b, factor_a, factor_b, bIgnoreSky)

    // Member values
    float          m_fAmbientRed;
    float          m_fAmbientGreen;
    float          m_fAmbientBlue;
    float          m_fAmbientRed_Obj;
    float          m_fAmbientGreen_Obj;
    float          m_fAmbientBlue_Obj;
    // Mobile stores ambient colours before brightness in these Plugin-SDK slots.
    float          m_fDirectionalRed;
    float          m_fDirectionalGreen;
    float          m_fDirectionalBlue;
    u16            m_nSkyTopRed;
    u16            m_nSkyTopGreen;
    u16            m_nSkyTopBlue;
    u16            m_nSkyBottomRed;
    u16            m_nSkyBottomGreen;
    u16            m_nSkyBottomBlue;
    u16            m_nSunCoreRed;
    u16            m_nSunCoreGreen;
    u16            m_nSunCoreBlue;
    u16            m_nSunCoronaRed;
    u16            m_nSunCoronaGreen;
    u16            m_nSunCoronaBlue;
    float          m_fSunSize;
    float          m_fSpriteSize;
    float          m_fSpriteBrightness;
    i16            m_nShadowStrength;
    i16            m_nLightShadowStrength;
    i16            m_nPoleShadowStrength;
    float          m_fFarClip;
    float          m_fFogStart;
    float          m_fLightsOnGroundBrightness;
    u16            m_nLowCloudsRed;
    u16            m_nLowCloudsGreen;
    u16            m_nLowCloudsBlue;
    u16            m_nFluffyCloudsBottomRed;
    u16            m_nFluffyCloudsBottomGreen;
    u16            m_nFluffyCloudsBottomBlue;
    float          m_fWaterRed;
    float          m_fWaterGreen;
    float          m_fWaterBlue;
    float          m_fWaterAlpha;
    float          m_fPostFx1Red;
    float          m_fPostFx1Green;
    float          m_fPostFx1Blue;
    float          m_fPostFx1Alpha;
    float          m_fPostFx2Red;
    float          m_fPostFx2Green;
    float          m_fPostFx2Blue;
    float          m_fPostFx2Alpha;
    float          m_fCloudAlpha;
    i32            m_nHighLightMinIntensity;
    u16            m_nWaterFogAlpha;
    float          m_fIllumination;
    float          m_fLodDistMult;
    float          m_vRedGrade[4];
    float          m_vGreenGrade[4];
    float          m_vBlueGrade[4];
DECL_CLASS_END()
CHECKSIZE(CColourSet, 0xDC, 0xDC);

#endif // __AML_PSDK_SACOLOURSET_H
