#ifndef __AML_PSDK_SATIMECYCLE_H
#define __AML_PSDK_SATIMECYCLE_H

/*
    Plugin-SDK (Grand Theft Auto San Andreas) header file
    Authors: GTA Community. See more here
    https://github.com/DK22Pac/plugin-sdk
    Do not delete this comment block. Respect others' work!
*/

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/game_sa/base/ColourSet.h>
#include <aml-psdk/game_sa/base/ColModel.h>
#include <aml-psdk/gta_base/RGBA.h>

struct CTimeCycleBox
{
    CBox box;
    i16 farclip;
    u8 lodDistMult;
    i32 extraColor;
    float strength;
    float falloff;
};
CHECKSIZE(CTimeCycleBox, 0x28, 0x28);

typedef float tTimeCycleGrade[4];
typedef u8 tTimeCycleU8[23];
typedef i8 tTimeCycleI8[23];
typedef i16 tTimeCycleI16[23];
typedef tTimeCycleGrade tTimeCycleGradeRow[23];

DECL_CLASS(CTimeCycle)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(Update, _ZN10CTimeCycle6UpdateEv, void);
    DECL_FASTCALL_SIMPLE(CalcColoursForPoint, _ZN10CTimeCycle19CalcColoursForPointE7CVectorP10CColourSet, void, CVector point, CColourSet* set);
    DECL_FASTCALL_SIMPLE(FindTimeCycleBox, _ZN10CTimeCycle16FindTimeCycleBoxE7CVectorPP13CTimeCycleBoxPfbbS2_, void,
        CVector pos, CTimeCycleBox** out, float* currentBox, bool isLOD, bool isFarClip, CTimeCycleBox* alreadyFoundBox);
    DECL_FASTCALL_SIMPLE(SetConstantParametersForPostFX, _ZN10CTimeCycle30SetConstantParametersForPostFXEv, void);
    DECL_FASTCALL_SIMPLE(FindFarClipForCoors, _ZN10CTimeCycle19FindFarClipForCoorsE7CVector, float, CVector cameraPos);
    DECL_FASTCALL_SIMPLE(StartExtraColour, _ZN10CTimeCycle16StartExtraColourEib, void, i32 colour, bool bNoExtraColorInterior);
    DECL_FASTCALL_SIMPLE(StopExtraColour, _ZN10CTimeCycle15StopExtraColourEb, void, bool bNoExtraColorInterior);
    DECL_FASTCALL_SIMPLE(AddOne, _ZN10CTimeCycle6AddOneER4CBoxsifff, void, CBox& box, i16 farClip, i32 extraColor, float strength, float falloff, float lodDistMult);
    DECL_FASTCALL_SIMPLE(Shutdown, _ZN10CTimeCycle8ShutdownEv, void);
    DECL_FASTCALL_SIMPLE(InitForRestart, _ZN10CTimeCycle14InitForRestartEv, void);
    DECL_FASTCALL_SIMPLE(GetAmbientRed, _ZN10CTimeCycle13GetAmbientRedEv, float);
    DECL_FASTCALL_SIMPLE(GetAmbientGreen, _ZN10CTimeCycle15GetAmbientGreenEv, float);
    DECL_FASTCALL_SIMPLE(GetAmbientBlue, _ZN10CTimeCycle14GetAmbientBlueEv, float);
    DECL_FASTCALL_SIMPLE(GetAmbientRed_Obj, _ZN10CTimeCycle17GetAmbientRed_ObjEv, float);
    DECL_FASTCALL_SIMPLE(GetAmbientGreen_Obj, _ZN10CTimeCycle19GetAmbientGreen_ObjEv, float);
    DECL_FASTCALL_SIMPLE(GetAmbientBlue_Obj, _ZN10CTimeCycle18GetAmbientBlue_ObjEv, float);
    DECL_FASTCALL_SIMPLE(GetAmbientRed_BeforeBrightness, _ZN10CTimeCycle30GetAmbientRed_BeforeBrightnessEv, float);
    DECL_FASTCALL_SIMPLE(GetAmbientGreen_BeforeBrightness, _ZN10CTimeCycle32GetAmbientGreen_BeforeBrightnessEv, float);
    DECL_FASTCALL_SIMPLE(GetAmbientBlue_BeforeBrightness, _ZN10CTimeCycle31GetAmbientBlue_BeforeBrightnessEv, float);
    DECL_FASTCALL_SIMPLE(Initialise, _ZN10CTimeCycle10InitialiseEb, void, bool bReload);

    // STATIC values
    DECL_OBJECT_PLT(CColourSet, m_CurrentColours, BYBIT(0x676BC4, 0x84B7D0));
    DECL_OBJECT_ARRAY_PLT(tTimeCycleU8, m_nAmbientRed, BYBIT(0x677EDC, 0x84DDD8));
    DECL_OBJECT_ARRAY_PLT(tTimeCycleU8, m_nAmbientGreen, BYBIT(0x678E80, 0x84FD28));
    DECL_OBJECT_ARRAY_PLT(tTimeCycleU8, m_nAmbientBlue, BYBIT(0x676AFC, 0x84B640));
    DECL_OBJECT_ARRAY_PLT(tTimeCycleU8, m_nAmbientRed_Obj, BYBIT(0x6791AC, 0x850378));
    DECL_OBJECT_ARRAY_PLT(tTimeCycleU8, m_nAmbientGreen_Obj, BYBIT(0x675FF4, 0x84A058));
    DECL_OBJECT_ARRAY_PLT(tTimeCycleU8, m_nAmbientBlue_Obj, BYBIT(0x67696C, 0x84B328));
    DECL_OBJECT_ARRAY_PLT(tTimeCycleU8, m_nSkyTopRed, BYBIT(0x679E90, 0x851D30));
    DECL_OBJECT_ARRAY_PLT(tTimeCycleU8, m_nSkyTopGreen, BYBIT(0x679E38, 0x851C80));
    DECL_OBJECT_ARRAY_PLT(tTimeCycleU8, m_nSkyTopBlue, BYBIT(0x677D48, 0x84DAB0));
    DECL_OBJECT_ARRAY_PLT(tTimeCycleU8, m_nSkyBottomRed, BYBIT(0x677D28, 0x84DA70));
    DECL_OBJECT_ARRAY_PLT(tTimeCycleU8, m_nSkyBottomGreen, BYBIT(0x678F70, 0x84FF08));
    DECL_OBJECT_ARRAY_PLT(tTimeCycleU8, m_nSkyBottomBlue, BYBIT(0x6799A8, 0x851368));
    DECL_OBJECT_ARRAY_PLT(tTimeCycleU8, m_nSunCoreRed, BYBIT(0x67858C, 0x84EB30));
    DECL_OBJECT_ARRAY_PLT(tTimeCycleU8, m_nSunCoreGreen, BYBIT(0x679014, 0x850050));
    DECL_OBJECT_ARRAY_PLT(tTimeCycleU8, m_nSunCoreBlue, BYBIT(0x67621C, 0x84A498));
    DECL_OBJECT_ARRAY_PLT(tTimeCycleU8, m_nSunCoronaRed, BYBIT(0x677734, 0x84CE90));
    DECL_OBJECT_ARRAY_PLT(tTimeCycleU8, m_nSunCoronaGreen, BYBIT(0x6785F4, 0x84EC00));
    DECL_OBJECT_ARRAY_PLT(tTimeCycleU8, m_nSunCoronaBlue, BYBIT(0x678518, 0x84EA48));
    DECL_OBJECT_ARRAY_PLT(tTimeCycleI8, m_fSunSize, BYBIT(0x679744, 0x850E90));
    DECL_OBJECT_ARRAY_PLT(tTimeCycleI8, m_fSpriteSize, BYBIT(0x676F50, 0x84BEE0));
    DECL_OBJECT_ARRAY_PLT(tTimeCycleI8, m_fSpriteBrightness, BYBIT(0x679280, 0x850518));
    DECL_OBJECT_ARRAY_PLT(tTimeCycleU8, m_nShadowStrength, BYBIT(0x676434, 0x84A8C0));
    DECL_OBJECT_ARRAY_PLT(tTimeCycleU8, m_nLightShadowStrength, BYBIT(0x678298, 0x84E548));
    DECL_OBJECT_ARRAY_PLT(tTimeCycleU8, m_nPoleShadowStrength, BYBIT(0x6760FC, 0x84A258));
    DECL_OBJECT_ARRAY_PLT(tTimeCycleI16, m_fFarClip, BYBIT(0x6761A4, 0x84A3A8));
    DECL_OBJECT_ARRAY_PLT(tTimeCycleI16, m_fFogStart, BYBIT(0x679AD8, 0x8515D0));
    DECL_OBJECT_ARRAY_PLT(tTimeCycleU8, m_fLightsOnGroundBrightness, BYBIT(0x67979C, 0x850F40));
    DECL_OBJECT_ARRAY_PLT(tTimeCycleU8, m_nLowCloudsRed, BYBIT(0x6796B8, 0x850D80));
    DECL_OBJECT_ARRAY_PLT(tTimeCycleU8, m_nLowCloudsGreen, BYBIT(0x678A7C, 0x84F520));
    DECL_OBJECT_ARRAY_PLT(tTimeCycleU8, m_nLowCloudsBlue, BYBIT(0x6784B8, 0x84E988));
    DECL_OBJECT_ARRAY_PLT(tTimeCycleU8, m_nFluffyCloudsBottomRed, BYBIT(0x679E50, 0x851CB0));
    DECL_OBJECT_ARRAY_PLT(tTimeCycleU8, m_nFluffyCloudsBottomGreen, BYBIT(0x678BD4, 0x84F7D0));
    DECL_OBJECT_ARRAY_PLT(tTimeCycleU8, m_nFluffyCloudsBottomBlue, BYBIT(0x678294, 0x84E540));
    DECL_OBJECT_ARRAY_PLT(tTimeCycleU8, m_fWaterRed, BYBIT(0x679314, 0x850640));
    DECL_OBJECT_ARRAY_PLT(tTimeCycleU8, m_fWaterGreen, BYBIT(0x6788FC, 0x84F218));
    DECL_OBJECT_ARRAY_PLT(tTimeCycleU8, m_fWaterBlue, BYBIT(0x676A98, 0x84B578));
    DECL_OBJECT_ARRAY_PLT(tTimeCycleU8, m_fWaterAlpha, BYBIT(0x6766C0, 0x84ADD8));
    DECL_OBJECT_ARRAY_PLT(tTimeCycleU8, m_fPostFx1Red, BYBIT(0x676574, 0x84AB40));
    DECL_OBJECT_ARRAY_PLT(tTimeCycleU8, m_fPostFx1Green, BYBIT(0x676744, 0x84AEE0));
    DECL_OBJECT_ARRAY_PLT(tTimeCycleU8, m_fPostFx1Blue, BYBIT(0x679420, 0x850858));
    DECL_OBJECT_ARRAY_PLT(tTimeCycleU8, m_fPostFx1Alpha, BYBIT(0x6763E4, 0x84A820));
    DECL_OBJECT_ARRAY_PLT(tTimeCycleU8, m_fPostFx2Red, BYBIT(0x678D80, 0x84FB28));
    DECL_OBJECT_ARRAY_PLT(tTimeCycleU8, m_fPostFx2Green, BYBIT(0x6769D4, 0x84B3F0));
    DECL_OBJECT_ARRAY_PLT(tTimeCycleU8, m_fPostFx2Blue, BYBIT(0x67988C, 0x851130));
    DECL_OBJECT_ARRAY_PLT(tTimeCycleU8, m_fPostFx2Alpha, BYBIT(0x679BE8, 0x8517E8));
    DECL_OBJECT_ARRAY_PLT(tTimeCycleU8, m_fCloudAlpha, BYBIT(0x676CF8, 0x84BA38));
    DECL_OBJECT_ARRAY_PLT(tTimeCycleU8, m_nHighLightMinIntensity, BYBIT(0x67619C, 0x84A398));
    DECL_OBJECT_ARRAY_PLT(tTimeCycleU8, m_nWaterFogAlpha, BYBIT(0x678F74, 0x84FF10));
    DECL_OBJECT_ARRAY_PLT(tTimeCycleU8, m_nDirectionalMult, BYBIT(0x678CE4, 0x84F9F0));
    DECL_OBJECT_ARRAY_PLT(CTimeCycleBox, m_aBoxes, BYBIT(0x679DF0, 0x851BF8));
    DECL_VALUE_PLT_I32(m_NumBoxes, BYBIT(0x679630, 0x850C70));
    DECL_OBJECT_ARRAY_PLT(tTimeCycleGradeRow, m_vRedGrade, BYBIT(0x678630, 0x84EC88));
    DECL_OBJECT_ARRAY_PLT(tTimeCycleGradeRow, m_vGreenGrade, BYBIT(0x679B58, 0x8516D0));
    DECL_OBJECT_ARRAY_PLT(tTimeCycleGradeRow, m_vBlueGrade, BYBIT(0x677E70, 0x84DD00));
    DECL_VALUE_PLT_U32(m_CurrentStoredValue, BYBIT(0x676414, 0x84A880));
    DECL_OBJECT_ARRAY_PLT(CVector, m_VectorToSun, BYBIT(0x6793EC, 0x8507F0));
    DECL_OBJECT_ARRAY_PLT(float, m_fShadowFrontX, BYBIT(0x678E34, 0x84FC90));
    DECL_OBJECT_ARRAY_PLT(float, m_fShadowFrontY, BYBIT(0x6772BC, 0x84C5B0));
    DECL_OBJECT_ARRAY_PLT(float, m_fShadowSideX, BYBIT(0x6794D4, 0x8509C0));
    DECL_OBJECT_ARRAY_PLT(float, m_fShadowSideY, BYBIT(0x67924C, 0x8504B0));
    DECL_OBJECT_ARRAY_PLT(float, m_fShadowDisplacementX, BYBIT(0x677F8C, 0x84DF38));
    DECL_OBJECT_ARRAY_PLT(float, m_fShadowDisplacementY, BYBIT(0x679B64, 0x8516E8));
    DECL_VALUE_PLT_I32(m_FogReduction, BYBIT(0x6778C0, 0x84D1A8));
    DECL_VALUE_PLT_I32(m_ExtraColour, BYBIT(0x67819C, 0x84E350));
    DECL_VALUE_PLT_I32(m_ExtraColourWeatherType, BYBIT(0x67823C, 0x84E490));
    DECL_VALUE_PLT_U32(m_bExtraColourOn, BYBIT(0x678B98, 0x84F758));
    DECL_VALUE_PLT_FLT(m_ExtraColourInter, BYBIT(0x679A9C, 0x851558));
    DECL_OBJECT_PLT(CRGBA, m_BelowHorizonGrey, BYBIT(0x6770CC, 0x84C1D0));
    DECL_OBJECT_PLT(CVector, m_vecDirnLightToSun, BYBIT(0x679E34, 0x851C78));
    DECL_VALUE_PLT_FLT(m_BrightnessAddedToAmbientRed, BYBIT(0x678398, 0x84E748));
    DECL_VALUE_PLT_FLT(m_BrightnessAddedToAmbientGreen, BYBIT(0x677470, 0x84C918));
    DECL_VALUE_PLT_FLT(m_BrightnessAddedToAmbientBlue, BYBIT(0x676EF4, 0x84BE28));
DECL_CLASS_END()

#define m_CurrentColours m_CurrentColours()
#define m_nAmbientRed m_nAmbientRed()
#define m_nAmbientGreen m_nAmbientGreen()
#define m_nAmbientBlue m_nAmbientBlue()
#define m_nAmbientRed_Obj m_nAmbientRed_Obj()
#define m_nAmbientGreen_Obj m_nAmbientGreen_Obj()
#define m_nAmbientBlue_Obj m_nAmbientBlue_Obj()
#define m_nDirectionalMult m_nDirectionalMult()
#define m_aBoxes m_aBoxes()
#define m_NumBoxes m_NumBoxes()
#define m_CurrentStoredValue m_CurrentStoredValue()
#define m_VectorToSun m_VectorToSun()
#define m_fShadowFrontX m_fShadowFrontX()
#define m_fShadowFrontY m_fShadowFrontY()
#define m_fShadowSideX m_fShadowSideX()
#define m_fShadowSideY m_fShadowSideY()
#define m_fShadowDisplacementX m_fShadowDisplacementX()
#define m_fShadowDisplacementY m_fShadowDisplacementY()
#define m_FogReduction m_FogReduction()
#define m_ExtraColour m_ExtraColour()
#define m_ExtraColourWeatherType m_ExtraColourWeatherType()
#define m_bExtraColourOn m_bExtraColourOn()
#define m_ExtraColourInter m_ExtraColourInter()
#define m_BelowHorizonGrey m_BelowHorizonGrey()
#define m_vecDirnLightToSun m_vecDirnLightToSun()
#define m_BrightnessAddedToAmbientRed m_BrightnessAddedToAmbientRed()
#define m_BrightnessAddedToAmbientGreen m_BrightnessAddedToAmbientGreen()
#define m_BrightnessAddedToAmbientBlue m_BrightnessAddedToAmbientBlue()

#endif // __AML_PSDK_SATIMECYCLE_H
