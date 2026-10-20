#ifndef __AML_PSDK_SACLOUDS_H
#define __AML_PSDK_SACLOUDS_H

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/gta_base/Vector.h>
#include <aml-psdk/gta_base/RGBA.h>

struct RwTexture;
struct movingFog;

DECL_CLASS(volumeClouds)
    // Member values
    bool bUsed[180];
    bool bJustCreated[180];
    CVector pos[180];
    CVector size[180];
    i32 alpha[180];
    RwTexture* pTexture[1];
    CVector quadNormal[3];
    float modelX[18];
    float modelY[18];
    float modelZ[18];
    float modelU[18];
    float modelV[18];
DECL_CLASS_END()
CHECKSIZE(volumeClouds, 0x16a8, 0x16b0);

DECL_CLASS(CClouds)
    enum
    {
        V_CLOUD_TEXTURE_1 = 0,
        V_CLOUD_TEXTURES_TOTAL = 1
    };

    // STATIC functions
    DECL_FASTCALL_SIMPLE(Init, _ZN7CClouds4InitEv, void);
    DECL_FASTCALL_SIMPLE(Shutdown, _ZN7CClouds8ShutdownEv, void);
    DECL_FASTCALL_SIMPLE(Update, _ZN7CClouds6UpdateEv, void);
    DECL_FASTCALL_SIMPLE(Render, _ZN7CClouds6RenderEv, void);
    DECL_FASTCALL_SIMPLE(SetUpOneSkyPoly, _ZN7CClouds15SetUpOneSkyPolyE7CVectorS0_S0_S0_hhhhhh, void, CVector pos1, CVector pos2, CVector pos3, CVector pos4, u8 value1, u8 value2, u8 value3, u8 value4, u8 value5, u8 value6);
    DECL_FASTCALL_SIMPLE(RenderSkyPolys, _ZN7CClouds14RenderSkyPolysEv, void);
    DECL_FASTCALL_SIMPLE(RenderBottomFromHeight, _ZN7CClouds22RenderBottomFromHeightEv, void);
    DECL_FASTCALL_SIMPLE(VolumetricCloudsInit, _ZN7CClouds20VolumetricCloudsInitEv, void);
    DECL_FASTCALL_SIMPLE(VolumetricClouds_GetFirstFreeSlot, _ZN7CClouds33VolumetricClouds_GetFirstFreeSlotEv, i32);
    DECL_FASTCALL_SIMPLE(VolumetricClouds_Delete, _ZN7CClouds23VolumetricClouds_DeleteEi, void, i32 index);
    DECL_FASTCALL_SIMPLE(VolumetricClouds_Create, _ZN7CClouds23VolumetricClouds_CreateEP7CVector, i32, CVector* pos);
    DECL_FASTCALL_SIMPLE(VolumetricCloudsGetMaxDistance, _ZN7CClouds30VolumetricCloudsGetMaxDistanceEv, float);
    DECL_FASTCALL_SIMPLE(VolumetricCloudsRender, _ZN7CClouds22VolumetricCloudsRenderEv, void);
    DECL_FASTCALL_SIMPLE(MovingFogInit, _ZN7CClouds13MovingFogInitEv, void);
    DECL_FASTCALL_SIMPLE(MovingFog_GetFXIntensity, _ZN7CClouds24MovingFog_GetFXIntensityEv, float);
    DECL_FASTCALL_SIMPLE(MovingFog_GetWind, _ZN7CClouds17MovingFog_GetWindEv, CVector);
    DECL_FASTCALL_SIMPLE(MovingFog_GetFirstFreeSlot, _ZN7CClouds26MovingFog_GetFirstFreeSlotEv, i32);
    DECL_FASTCALL_SIMPLE(MovingFog_Delete, _ZN7CClouds16MovingFog_DeleteEi, void, i32 index);
    DECL_FASTCALL_SIMPLE(MovingFog_Create, _ZN7CClouds16MovingFog_CreateEP7CVector, void, CVector* pos);
    DECL_FASTCALL_SIMPLE(MovingFog_Update, _ZN7CClouds16MovingFog_UpdateEv, void);
    DECL_FASTCALL_SIMPLE(MovingFogRender, _ZN7CClouds15MovingFogRenderEv, void);

    // STATIC values
    DECL_OBJECT_PLT(float, CloudRotation, BYBIT(0x676988, 0x84b360));
    DECL_OBJECT_PLT(u32, IndividualRotation, BYBIT(0x6785f0, 0x84ebf8));
    DECL_OBJECT_SYM(CRGBA, ms_colourTop, _ZN7CClouds12ms_colourTopE);
    DECL_OBJECT_SYM(CRGBA, ms_colourBottom, _ZN7CClouds15ms_colourBottomE);
    DECL_OBJECT_SYM(float, ms_horizonZ, _ZN7CClouds11ms_horizonZE);
    DECL_OBJECT_PLT(float, ms_cameraRoll, BYBIT(0x6785e4, 0x84ebe0));
    DECL_OBJECT_SYM(float, ms_HorizonTilt, _ZN7CClouds14ms_HorizonTiltE);
    DECL_OBJECT_SYM(float, m_fFrothIntensity, _ZN7CClouds17m_fFrothIntensityE);
    DECL_OBJECT_SYM(CVector, m_FrothCoors, _ZN7CClouds12m_FrothCoorsE);
    DECL_OBJECT_PLT(float, m_fVolumetricCloudDensity, BYBIT(0x679884, 0x851120));
    DECL_OBJECT_PLT(i32, m_VolumetricCloudsUsedNum, BYBIT(0x679998, 0x851348));
    DECL_OBJECT_PLT(bool, m_bVolumetricCloudHeightSwitch, BYBIT(0x679140, 0x8502a8));
    DECL_OBJECT_PLT(float, m_fVolumetricCloudMaxDistance, BYBIT(0x67859c, 0x84eb50));
    DECL_OBJECT_PLT(float, m_fVolumetricCloudWindMoveFactor, BYBIT(0x6799e8, 0x8513e8));
    DECL_OBJECT_PLT(volumeClouds, ms_vc, BYBIT(0x676dc4, 0x84bbd0));
    DECL_OBJECT_PLT(movingFog, ms_mf, BYBIT(0x6797b8, 0x850f78));

DECL_CLASS_END()
CHECKSIZE(CClouds, 0x1, 0x1);

#endif // __AML_PSDK_SACLOUDS_H
