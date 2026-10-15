#ifndef __AML_PSDK_SACUSTOMCARPLATE_H
#define __AML_PSDK_SACUSTOMCARPLATE_H

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/renderware/RpClump.h>
#include <aml-psdk/renderware/RwTexture.h>
#include <aml-psdk/gta_base/Vector.h>

DECL_CLASS(CCustomCarPlateMgr)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(Initialise, _ZN18CCustomCarPlateMgr10InitialiseEv, u8);
    DECL_FASTCALL_SIMPLE(Shutdown, _ZN18CCustomCarPlateMgr8ShutdownEv, void);
    DECL_FASTCALL_SIMPLE(LoadPlatecharsetDat, _ZN18CCustomCarPlateMgr19LoadPlatecharsetDatEPKcPhii, u8, char const* pFilename, u8* pDstPal, i32 maxNumPalettes, i32 maxNumPalColors);
    DECL_FASTCALL_SIMPLE(GetMapRegionPlateDesign, _ZN18CCustomCarPlateMgr23GetMapRegionPlateDesignEv, u8);
    DECL_FASTCALL_SIMPLE(SetupClump, _ZN18CCustomCarPlateMgr10SetupClumpEP7RpClumpPch, RpMaterial*, RpClump* pClump, char* pText, u8 plateDesign);
    DECL_FASTCALL_SIMPLE(SetupClumpAfterVehicleUpgrade, _ZN18CCustomCarPlateMgr29SetupClumpAfterVehicleUpgradeEP7RpClumpP10RpMaterialh, u8, RpClump* pClump, RpMaterial* pCarPlateMaterial, u8 plateDesign);
    DECL_FASTCALL_SIMPLE(SetupMaterialPlateTexture, _ZN18CCustomCarPlateMgr25SetupMaterialPlateTextureEP10RpMaterialPch, RpMaterial*, RpMaterial* pMaterial, char* PlateText, u8 plateDesign);
    DECL_FASTCALL_SIMPLE(CreatePlateTexture, _ZN18CCustomCarPlateMgr18CreatePlateTextureEPch, RwTexture*, char* PlateText, u8 plateDesign);
    DECL_FASTCALL_SIMPLE(SetupMaterialPlatebackTexture, _ZN18CCustomCarPlateMgr29SetupMaterialPlatebackTextureEP10RpMaterialh, RpMaterial*, RpMaterial* pMaterial, u8 plateDesign);
    DECL_FASTCALL_SIMPLE(GeneratePlateText, _ZN18CCustomCarPlateMgr17GeneratePlateTextEPci, u8, char* pDestBuf, i32 maxNumChars);

    // STATIC values
    DECL_OBJECT_PLT(RwTexture*, pCharsetTex, BYBIT(0x677E04, 0x84DC28));
    DECL_OBJECT_ARRAY_PLT(RwTexture*, pPlatebackTexTab, BYBIT(0x6794BC, 0x850990));

DECL_CLASS_END()
CHECKSIZE(CCustomCarPlateMgr, 0x1, 0x1);

#endif // __AML_PSDK_SACUSTOMCARPLATE_H
