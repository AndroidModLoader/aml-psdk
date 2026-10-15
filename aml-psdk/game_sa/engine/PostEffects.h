#ifndef __AML_PSDK_SAPOSTEFFECTS_H
#define __AML_PSDK_SAPOSTEFFECTS_H

#include "../plugin.h"
#include <aml-psdk/gta_base/RGBA.h>
#include <aml-psdk/renderware/RwRGBA.h>
#include <aml-psdk/renderware/RwRaster.h>

struct RwTexture;
struct CPed;

DECL_CLASS(CPostEffects)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(Close, _ZN12CPostEffects5CloseEv, void);
    DECL_FASTCALL_SIMPLE(SetupBackBufferVertex, _ZN12CPostEffects21SetupBackBufferVertexEv, void);
    DECL_FASTCALL_SIMPLE(ScriptResetForEffects, _ZN12CPostEffects21ScriptResetForEffectsEv, void);
    DECL_FASTCALL_SIMPLE(ScriptNightVisionSwitch, _ZN12CPostEffects23ScriptNightVisionSwitchEb, void, bool n);
    DECL_FASTCALL_SIMPLE(ScriptInfraredVisionSwitch, _ZN12CPostEffects26ScriptInfraredVisionSwitchEb, void, bool n);
    DECL_FASTCALL_SIMPLE(ScriptHeatHazeFXSwitch, _ZN12CPostEffects22ScriptHeatHazeFXSwitchEb, void, bool n);
    DECL_FASTCALL_SIMPLE(ScriptDarknessFilterSwitch, _ZN12CPostEffects26ScriptDarknessFilterSwitchEbi, void, bool n, i32 alpha);
    DECL_FASTCALL_SIMPLE(ScriptCCTVSwitch, _ZN12CPostEffects16ScriptCCTVSwitchEb, void, bool n);
    DECL_FASTCALL_SIMPLE(Render, _ZN12CPostEffects6RenderEv, void);
    DECL_FASTCALL_SIMPLE(MobileRender, _ZN12CPostEffects12MobileRenderEv, void);
    DECL_FASTCALL_SIMPLE(ColourFilter, _ZN12CPostEffects12ColourFilterE6RwRGBAS0_, void, RwRGBA col1, RwRGBA col2);
    DECL_FASTCALL_SIMPLE(NightVision, _ZN12CPostEffects11NightVisionE6RwRGBA, void, RwRGBA colour);
    DECL_FASTCALL_SIMPLE(NightVisionSetLights, _ZN12CPostEffects20NightVisionSetLightsEv, void);
    DECL_FASTCALL_SIMPLE(InfraredVision, _ZN12CPostEffects14InfraredVisionE6RwRGBAS0_, void, RwRGBA colour, RwRGBA colourMain);
    DECL_FASTCALL_SIMPLE(InfraredVisionSetLightsForHeatObjects, _ZN12CPostEffects37InfraredVisionSetLightsForHeatObjectsEv, void);
    DECL_FASTCALL_SIMPLE(InfraredVisionStoreAndSetLightsForHeatObjects, _ZN12CPostEffects45InfraredVisionStoreAndSetLightsForHeatObjectsEP4CPed, void, CPed* pPed);
    DECL_FASTCALL_SIMPLE(InfraredVisionRestoreLightsForHeatObjects, _ZN12CPostEffects41InfraredVisionRestoreLightsForHeatObjectsEv, void);
    DECL_FASTCALL_SIMPLE(InfraredVisionSetLightsForDefaultObjects, _ZN12CPostEffects40InfraredVisionSetLightsForDefaultObjectsEv, void);
    DECL_FASTCALL_SIMPLE(HeatHazeFXInit, _ZN12CPostEffects14HeatHazeFXInitEv, void);
    DECL_FASTCALL_SIMPLE(HeatHazeFX, _ZN12CPostEffects10HeatHazeFXEfb, void, float fIntensity, bool bAlphaMaskMode);
    DECL_FASTCALL_SIMPLE(Radiosity, _ZN12CPostEffects9RadiosityEiiii, void, i32 intensityLimit, i32 filterPasses, i32 renderPasses, i32 intensity);
    DECL_FASTCALL_SIMPLE(DarknessFilter, _ZN12CPostEffects14DarknessFilterEi, void, i32 alpha);
    DECL_FASTCALL_SIMPLE(CCTV, _ZN12CPostEffects4CCTVEv, void);
    DECL_FASTCALL_SIMPLE(Fog, _ZN12CPostEffects3FogEv, void);
    DECL_FASTCALL_SIMPLE(SpeedFX, _ZN12CPostEffects7SpeedFXEf, void, float speed);
    DECL_FASTCALL_SIMPLE(FilterFX_StoreAndSetDayNightBalance, _ZN12CPostEffects35FilterFX_StoreAndSetDayNightBalanceEv, void);
    DECL_FASTCALL_SIMPLE(FilterFX_RestoreDayNightBalance, _ZN12CPostEffects31FilterFX_RestoreDayNightBalanceEv, void);
    DECL_FASTCALL_SIMPLE(IsVisionFXActive, _ZN12CPostEffects16IsVisionFXActiveEv, bool);
    DECL_FASTCALL_SIMPLE(SetFilterMainColour, _ZN12CPostEffects19SetFilterMainColourEP8RwRaster6RwRGBA, void, RwRaster* pRaster, RwRGBA colour);
    DECL_FASTCALL_SIMPLE(UnderWaterRipple, _ZN12CPostEffects16UnderWaterRippleE6RwRGBAffiff, void, RwRGBA col, float xoffset, float yoffset, i32 strength, float speed, float freq);
    DECL_FASTCALL_SIMPLE(Update, _ZN12CPostEffects6UpdateEv, void);
    DECL_FASTCALL_SIMPLE(DoScreenModeDependentInitializations, _ZN12CPostEffects36DoScreenModeDependentInitializationsEv, void);
    DECL_FASTCALL_SIMPLE(ImmediateModeFilterStuffInitialize, _ZN12CPostEffects34ImmediateModeFilterStuffInitializeEv, void);
    DECL_FASTCALL_SIMPLE(ImmediateModeRenderStatesStore, _ZN12CPostEffects30ImmediateModeRenderStatesStoreEv, void);
    DECL_FASTCALL_SIMPLE(ImmediateModeRenderStatesSet, _ZN12CPostEffects28ImmediateModeRenderStatesSetEv, void);
    DECL_FASTCALL_SIMPLE(ImmediateModeRenderStatesReStore, _ZN12CPostEffects32ImmediateModeRenderStatesReStoreEv, void);
    DECL_FASTCALL_SIMPLE(DrawQuad, _ZN12CPostEffects8DrawQuadEffffhhhhP8RwRaster, void, RwReal xPos, RwReal yPos, RwReal xSize, RwReal ySize, RwUInt8 r, RwUInt8 g, RwUInt8 b, RwUInt8 a, RwRaster* pRaster);
    DECL_FASTCALL_SIMPLE(DrawQuadSetUVs, _ZN12CPostEffects14DrawQuadSetUVsEffffffff, void, RwReal u1, RwReal v1, RwReal u2, RwReal v2, RwReal u3, RwReal v3, RwReal u4, RwReal v4);
    DECL_FASTCALL_SIMPLE(DrawQuadSetPixelUVs, _ZN12CPostEffects19DrawQuadSetPixelUVsEffffffff, void, RwReal u1, RwReal v1, RwReal u2, RwReal v2, RwReal u3, RwReal v3, RwReal u4, RwReal v4);
    DECL_FASTCALL_SIMPLE(DrawQuadSetDefaultUVs, _ZN12CPostEffects21DrawQuadSetDefaultUVsEv, void);
    DECL_FASTCALL_SIMPLE(Save, _ZN12CPostEffects4SaveEv, void);
    DECL_FASTCALL_SIMPLE(Load, _ZN12CPostEffects4LoadEv, void);
    DECL_FASTCALL_SIMPLE(RasterCreatePostEffects, _ZN12CPostEffects23RasterCreatePostEffectsE6RwRect, RwRaster*, RwRect rect);
    // STATIC values
    DECL_VALUE_PLT_FLT(m_colour1Multiplier, BYBIT(0x6778C4, 0x84D1B0));
    DECL_VALUE_PLT_FLT(m_colour2Multiplier, BYBIT(0x678774, 0x84EF10));
    DECL_VALUE_PLT_FLT(SCREEN_EXTRA_MULT_CHANGE_RATE, BYBIT(0x6781F4, 0x84E400));
    DECL_VALUE_PLT_FLT(SCREEN_EXTRA_MULT_BASE_CAP, BYBIT(0x677D34, 0x84DA88));
    DECL_VALUE_PLT_FLT(SCREEN_EXTRA_MULT_BASE_MULT, BYBIT(0x6778E8, 0x84D1F8));
    DECL_VALUE_PLT_I32(m_colourLeftUOffset, BYBIT(0x6778D4, 0x84D1D0));
    DECL_VALUE_PLT_I32(m_colourRightUOffset, BYBIT(0x676F90, 0x84BF60));
    DECL_VALUE_PLT_I32(m_colourTopVOffset, BYBIT(0x67686C, 0x84B130));
    DECL_VALUE_PLT_I32(m_colourBottomVOffset, BYBIT(0x679154, 0x8502D0));
    DECL_VALUE_PLT_BOOL(m_bSeamRemover, BYBIT(0x679844, 0x851098));
    DECL_VALUE_PLT_BOOL(m_bSeamRemoverSeamSearchMode, BYBIT(0x6778E4, 0x84D1F0));
    DECL_VALUE_PLT_BOOL(m_bSeamRemoverDebugMode, BYBIT(0x676A20, 0x84B488));
    DECL_VALUE_PLT_I32(m_SeamRemoverMode, BYBIT(0x678D58, 0x84FAD8));
    DECL_VALUE_PLT_I32(m_SeamRemoverShiftTopLeft, BYBIT(0x679260, 0x8504D8));
    DECL_VALUE_PLT_I32(m_SeamRemoverShiftBottomRight, BYBIT(0x6799C8, 0x8513A8));
    DECL_VALUE_PLT_BOOL(m_smokeyEnable, BYBIT(0x67698C, 0x84B368));
    DECL_VALUE_PLT_I32(m_smokeyStrength, BYBIT(0x678284, 0x84E520));
    DECL_VALUE_PLT_I32(m_smokeyDistance, BYBIT(0x6768F4, 0x84B238));
    DECL_VALUE_PLT_BOOL(m_waterEnable, BYBIT(0x678168, 0x84E2E8));
    DECL_VALUE_PLT_FLT(m_VisionFXDayNightBalance, BYBIT(0x67762C, 0x84CC88));
    DECL_VALUE_PLT_BOOL(m_bHeatHazeFX, BYBIT(0x6776BC, 0x84CDA8));
    DECL_VALUE_PLT_BOOL(m_bHeatHazeMaskModeTest, BYBIT(0x6761E8, 0x84A430));
    DECL_VALUE_PLT_I32(m_HeatHazeFXHourOfDayStart, BYBIT(0x679054, 0x8500D0));
    DECL_VALUE_PLT_I32(m_HeatHazeFXHourOfDayEnd, BYBIT(0x679484, 0x850920));
    DECL_VALUE_PLT_FLT(m_fHeatHazeFXFadeSpeed, BYBIT(0x678790, 0x84EF48));
    DECL_VALUE_PLT_FLT(m_fHeatHazeFXInsideBuildingFadeSpeed, BYBIT(0x6772E0, 0x84C5F8));
    DECL_VALUE_PLT_I32(m_HeatHazeFXType, BYBIT(0x678130, 0x84E278));
    DECL_VALUE_PLT_I32(m_HeatHazeFXTypeLast, BYBIT(0x67778C, 0x84CF40));
    DECL_VALUE_PLT_I32(m_HeatHazeFXIntensity, BYBIT(0x679F60, 0x851EC8));
    DECL_VALUE_PLT_I32(m_HeatHazeFXRandomShift, BYBIT(0x679C20, 0x851858));
    DECL_VALUE_PLT_I32(m_HeatHazeFXSpeedMin, BYBIT(0x679654, 0x850CB8));
    DECL_VALUE_PLT_I32(m_HeatHazeFXSpeedMax, BYBIT(0x677D08, 0x84DA30));
    DECL_VALUE_PLT_I32(m_HeatHazeFXScanSizeX, BYBIT(0x678144, 0x84E2A0));
    DECL_VALUE_PLT_I32(m_HeatHazeFXScanSizeY, BYBIT(0x679010, 0x850048));
    DECL_VALUE_PLT_I32(m_HeatHazeFXRenderSizeX, BYBIT(0x678820, 0x84F060));
    DECL_VALUE_PLT_I32(m_HeatHazeFXRenderSizeY, BYBIT(0x677E78, 0x84DD10));
    DECL_VALUE_PLT_BOOL(m_bDarknessFilter, BYBIT(0x677504, 0x84CA40));
    DECL_VALUE_PLT_I32(m_DarknessFilterAlpha, BYBIT(0x679C50, 0x8518B8));
    DECL_VALUE_PLT_I32(m_DarknessFilterAlphaDefault, BYBIT(0x67997C, 0x851310));
    DECL_VALUE_PLT_I32(m_DarknessFilterRadiosityIntensityLimit, BYBIT(0x679644, 0x850C98));
    DECL_VALUE_PLT_BOOL(m_bCCTV, BYBIT(0x6763A4, 0x84A7A0));
    DECL_OBJECT_PLT(CRGBA, m_CCTVcol, BYBIT(0x6783FC, 0x84E810));
    DECL_VALUE_PLT_BOOL(m_bFog, BYBIT(0x6799C4, 0x8513A0));
    DECL_VALUE_PLT_BOOL(m_bSpeedFX, BYBIT(0x6771B8, 0x84C3A0));
    DECL_VALUE_PLT_BOOL(m_bSpeedFXTestMode, BYBIT(0x678C5C, 0x84F8E0));
    DECL_VALUE_PLT_I32(m_SpeedFXAlpha, BYBIT(0x676624, 0x84ACA0));
    DECL_VALUE_PLT_BOOL(m_bSpeedFXUserFlag, BYBIT(0x677F60, 0x84DEE0));
    DECL_VALUE_PLT_BOOL(m_bSpeedFXUserFlagCurrentFrame, BYBIT(0x676A34, 0x84B4B0));
    DECL_VALUE_PLT_FLT(m_fSpeedFXManualSpeedCurrentFrame, BYBIT(0x678704, 0x84EE30));
    DECL_VALUE_PLT_BOOL(m_bInCutscene, BYBIT(0x678C00, 0x84F828));
    DECL_VALUE_PLT_BOOL(m_bNightVision, BYBIT(0x676674, 0x84AD40));
    DECL_VALUE_PLT_I32(m_NightVisionGrainStrength, BYBIT(0x678B04, 0x84F630));
    DECL_OBJECT_PLT(CRGBA, m_NightVisionMainCol, BYBIT(0x6766A0, 0x84AD98));
    DECL_VALUE_PLT_FLT(m_fNightVisionSwitchOnFXTime, BYBIT(0x678EB0, 0x84FD88));
    DECL_VALUE_PLT_FLT(m_fNightVisionSwitchOnFXCount, BYBIT(0x677268, 0x84C508));
    DECL_VALUE_PLT_FLT(m_fInfraredVisionSwitchOnFXCount, BYBIT(0x677820, 0x84D068));
    DECL_VALUE_PLT_BOOL(m_bInfraredVision, BYBIT(0x678FE4, 0x84FFF0));
    DECL_VALUE_PLT_I32(m_InfraredVisionGrainStrength, BYBIT(0x678C40, 0x84F8A8));
    DECL_VALUE_PLT_FLT(m_fInfraredVisionFilterRadius, BYBIT(0x679548, 0x850AA0));
    DECL_OBJECT_PLT(RwRGBAReal, m_fInfraredVisionHeatObjectCol, BYBIT(0x6764B8, 0x84A9C8));
    DECL_OBJECT_PLT(CRGBA, m_InfraredVisionCol, BYBIT(0x6767A4, 0x84AFA0));
    DECL_OBJECT_PLT(CRGBA, m_InfraredVisionMainCol, BYBIT(0x679BAC, 0x851778));
    DECL_VALUE_PLT_BOOL(m_bRadiosity, BYBIT(0x679914, 0x851248));
    DECL_VALUE_PLT_BOOL(m_bRadiosityLinearFilter, BYBIT(0x679568, 0x850AE0));
    DECL_VALUE_PLT_BOOL(m_bRadiosityStripCopyMode, BYBIT(0x678EEC, 0x84FE00));
    DECL_VALUE_PLT_I32(m_RadiosityPixelsX, BYBIT(0x676DEC, 0x84BC20));
    DECL_VALUE_PLT_I32(m_RadiosityPixelsY, BYBIT(0x676710, 0x84AE78));
    DECL_VALUE_PLT_I32(m_RadiosityFilterPasses, BYBIT(0x676064, 0x84A138));
    DECL_VALUE_PLT_I32(m_RadiosityRenderPasses, BYBIT(0x6779C8, 0x84D3C0));
    DECL_VALUE_PLT_I32(m_RadiosityIntensityLimit, BYBIT(0x6768A4, 0x84B1A0));
    DECL_VALUE_PLT_I32(m_RadiosityIntensity, BYBIT(0x679BF4, 0x851800));
    DECL_VALUE_PLT_I32(m_RadiosityFilterUCorrection, BYBIT(0x676180, 0x84A360));
    DECL_VALUE_PLT_I32(m_RadiosityFilterVCorrection, BYBIT(0x6790F8, 0x850218));
    DECL_VALUE_PLT_BOOL(m_bRadiosityDebug, BYBIT(0x677270, 0x84C518));
    DECL_VALUE_PLT_BOOL(m_bRadiosityBypassTimeCycleIntensityLimit, BYBIT(0x679738, 0x850E78));
    DECL_VALUE_PLT_BOOL(m_bDisableAllPostEffect, BYBIT(0x677C8C, 0x84D938));
    DECL_VALUE_PLT_BOOL(m_bSavePhotoFromScript, BYBIT(0x678AA8, 0x84F578));
    DECL_VALUE_PLT_BOOL(m_bGrainEnable, BYBIT(0x677264, 0x84C500));
    DECL_VALUE_PLT_I32(m_grainStrength, BYBIT(0x678FE0, 0x84FFE8));
    DECL_VALUE_PLT_BOOL(m_bHilightEnable, BYBIT(0x678364, 0x84E6E0));
    DECL_VALUE_PLT_I32(m_hilightStrength, BYBIT(0x676208, 0x84A470));
    DECL_VALUE_PLT_I32(m_hilightScale, BYBIT(0x678950, 0x84F2C0));
    DECL_VALUE_PLT_I32(m_hilightOffset, BYBIT(0x676EB8, 0x84BDB0));
    DECL_VALUE_PLT_BOOL(m_hilightMblur, BYBIT(0x6791D8, 0x8503D0));
    DECL_VALUE_PLT_I32(m_waterStrength, BYBIT(0x67878C, 0x84EF40));
    DECL_VALUE_PLT_FLT(m_xoffset, BYBIT(0x6763B8, 0x84A7C8));
    DECL_VALUE_PLT_FLT(m_yoffset, BYBIT(0x6765C8, 0x84ABE8));
    DECL_VALUE_PLT_FLT(m_waterSpeed, BYBIT(0x67659C, 0x84AB90));
    DECL_VALUE_PLT_FLT(m_waterFreq, BYBIT(0x677500, 0x84CA38));
    DECL_OBJECT_PLT(CRGBA, m_waterCol, BYBIT(0x67808C, 0x84E130));
    DECL_VALUE_PLT_BOOL(m_bWaterDepthDarkness, BYBIT(0x676E8C, 0x84BD58));
    DECL_VALUE_PLT_FLT(m_fWaterFullDarknessDepth, BYBIT(0x677784, 0x84CF30));
    DECL_VALUE_PLT_FLT(m_fWaterFXStartUnderWaterness, BYBIT(0x676B50, 0x84B6E8));
    DECL_VALUE_PLT_BOOL(m_bRainEnable, BYBIT(0x677CC8, 0x84D9B0));
    DECL_OBJECT_PLT(RwRaster*, pRasterFrontBuffer, BYBIT(0x679810, 0x851028));
    DECL_VALUE_PLT_BOOL(m_bColorEnable, BYBIT(0x678B18, 0x84F658));
    DECL_VALUE_PLT_I32(m_defScreenXPosn, BYBIT(0x6763AC, 0x84A7B0));
    DECL_VALUE_PLT_I32(m_defScreenYPosn, BYBIT(0x678054, 0x84E0C8));
DECL_CLASS_END()

#endif // __AML_PSDK_SAPOSTEFFECTS_H
