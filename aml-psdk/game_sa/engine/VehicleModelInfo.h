#ifndef __AML_PSDK_SAVEHICLEMODELINFO_H
#define __AML_PSDK_SAVEHICLEMODELINFO_H

#include "ModelInfo.h"
#include "../enum/Vehicles.h"
#include "../base/Quaternion.h"

struct RpMaterial;
struct CAnimBlock;
struct CVehicle;

struct UpgradePosnDesc
{
    CVector m_vPosition;
    CQuaternion m_qRotation;
    int m_nParentComponentId;
};

DECL_CLASS_BASED(CVehicleModelInfo, CClumpModelInfo)
    // Construct/Deconstruct functions
    DECL_CTORCALL(CVehicleModelInfo, _ZN17CVehicleModelInfoC2Ev);

    // STATIC functions
    DECL_FASTCALL_SIMPLE(SetupCommonData, _ZN17CVehicleModelInfo15SetupCommonDataEv, void);
    DECL_FASTCALL_SIMPLE(ShutdownLightTexture, _ZN17CVehicleModelInfo20ShutdownLightTextureEv, void);
    DECL_FASTCALL_SIMPLE(GetMaximumNumberOfPassengersFromNumberOfDoors, _ZN17CVehicleModelInfo45GetMaximumNumberOfPassengersFromNumberOfDoorsEi, i32, i32 modelId);
    DECL_FASTCALL_SIMPLE(LoadVehicleColours, _ZN17CVehicleModelInfo18LoadVehicleColoursEv, void);
    DECL_FASTCALL_SIMPLE(DeleteVehicleColourTextures, _ZN17CVehicleModelInfo27DeleteVehicleColourTexturesEv, void);
    DECL_FASTCALL_SIMPLE(LoadEnvironmentMaps, _ZN17CVehicleModelInfo19LoadEnvironmentMapsEv, void);
    DECL_FASTCALL_SIMPLE(ShutdownEnvironmentMaps, _ZN17CVehicleModelInfo23ShutdownEnvironmentMapsEv, void);
    DECL_FASTCALL_SIMPLE(SetRenderPipelinesCB, _ZN17CVehicleModelInfo20SetRenderPipelinesCBEP8RpAtomicPv, RpAtomic*, RpAtomic* atomic, void* data);
    DECL_FASTCALL_SIMPLE(LoadVehicleUpgrades, _ZN17CVehicleModelInfo19LoadVehicleUpgradesEv, void);
    DECL_FASTCALL_SIMPLE(AddWheelUpgrade, _ZN17CVehicleModelInfo15AddWheelUpgradeEii, void, i32 wheelSetNumber, i32 modelId);
    DECL_FASTCALL_SIMPLE(GetNumWheelUpgrades, _ZN17CVehicleModelInfo19GetNumWheelUpgradesEi, i32, i32 wheelSetNumber);
    DECL_FASTCALL_SIMPLE(GetWheelUpgrade, _ZN17CVehicleModelInfo15GetWheelUpgradeEii, i32, i32 wheelSetNumber, i32 wheelUpgradeNumber);
    DECL_FASTCALL_SIMPLE(SetAtomicFlagCB, _ZN17CVehicleModelInfo15SetAtomicFlagCBEP8RwObjectPv, RwObject*, RwObject* object, void* data);
    DECL_FASTCALL_SIMPLE(ClearAtomicFlagCB, _ZN17CVehicleModelInfo17ClearAtomicFlagCBEP8RwObjectPv, RwObject*, RwObject* object, void* data);
    DECL_FASTCALL_SIMPLE(HideAllComponentsAtomicCB, _ZN17CVehicleModelInfo25HideAllComponentsAtomicCBEP8RpAtomicPv, RpAtomic*, RpAtomic* atomic, void* data);
    DECL_FASTCALL_SIMPLE(UseCommonVehicleTexDicationary, _ZN17CVehicleModelInfo30UseCommonVehicleTexDicationaryEv, void);
    DECL_FASTCALL_SIMPLE(StopUsingCommonVehicleTexDicationary, _ZN17CVehicleModelInfo36StopUsingCommonVehicleTexDicationaryEv, void);
    DECL_FASTCALL_SIMPLE(SetupLightFlags, _ZN17CVehicleModelInfo15SetupLightFlagsEP8CVehicle, void, CVehicle* vehicle);
    DECL_FASTCALL_SIMPLE(HasAlphaMaterialCB, _ZN17CVehicleModelInfo18HasAlphaMaterialCBEP10RpMaterialPv, RpMaterial*, RpMaterial* material, void* data);
    DECL_FASTCALL_SIMPLE(SetEditableMaterials, _ZN17CVehicleModelInfo20SetEditableMaterialsEP7RpClump, void, RpClump* clump);
    DECL_FASTCALL_SIMPLE(SetEditableMaterialsCB1, _ZN17CVehicleModelInfo22SetEditableMaterialsCBEP8RpAtomicPv, RpAtomic*, RpAtomic* pAtomic, void* pData);
    DECL_FASTCALL_SIMPLE(ResetEditableMaterials, _ZN17CVehicleModelInfo22ResetEditableMaterialsEP7RpClump, void, RpClump* clump);
    DECL_FASTCALL_SIMPLE(CollapseFramesCB, _ZN17CVehicleModelInfo16CollapseFramesCBEP7RwFramePv, RwFrame*, RwFrame* frame, void* data);
    DECL_FASTCALL_SIMPLE(MoveObjectsCB, _ZN17CVehicleModelInfo13MoveObjectsCBEP8RwObjectPv, RwObject*, RwObject* object, void* data);
    DECL_FASTCALL_SIMPLE(SetAtomicRendererCB, _ZN17CVehicleModelInfo19SetAtomicRendererCBEP8RpAtomicPv, RpAtomic*, RpAtomic* atomic, void* data);
    DECL_FASTCALL_SIMPLE(SetAtomicRendererCB_RealHeli, _ZN17CVehicleModelInfo28SetAtomicRendererCB_RealHeliEP8RpAtomicPv, RpAtomic*, RpAtomic* atomic, void* data);
    DECL_FASTCALL_SIMPLE(SetAtomicRendererCB_Heli, _ZN17CVehicleModelInfo24SetAtomicRendererCB_HeliEP8RpAtomicPv, RpAtomic*, RpAtomic* atomic, void* data);
    DECL_FASTCALL_SIMPLE(SetAtomicRendererCB_Boat, _ZN17CVehicleModelInfo24SetAtomicRendererCB_BoatEP8RpAtomicPv, RpAtomic*, RpAtomic* atomic, void* data);
    DECL_FASTCALL_SIMPLE(SetAtomicRendererCB_Train, _ZN17CVehicleModelInfo25SetAtomicRendererCB_TrainEP8RpAtomicPv, RpAtomic*, RpAtomic* atomic, void* data);
    DECL_FASTCALL_SIMPLE(SetAtomicRendererCB_BigVehicle, _ZN17CVehicleModelInfo30SetAtomicRendererCB_BigVehicleEP8RpAtomicPv, RpAtomic*, RpAtomic* pAtomic, void* pData);
    DECL_FASTCALL_SIMPLE(HideDamagedAtomicCB, _ZN17CVehicleModelInfo19HideDamagedAtomicCBEP8RpAtomicPv, RpAtomic*, RpAtomic* atomic, void* data);
    DECL_FASTCALL_SIMPLE(GetEditableMaterialListCB1, _ZN17CVehicleModelInfo25GetEditableMaterialListCBEP8RpAtomicPv, RpAtomic*, RpAtomic* pRpAtomic1, void* pvoid2);
    DECL_FASTCALL_SIMPLE(SetEditableMaterialsCB2, _ZN17CVehicleModelInfo22SetEditableMaterialsCBEP10RpMaterialPv, RpMaterial*, RpMaterial* pRpMaterial1, void* pvoid2);
    DECL_FASTCALL_SIMPLE(GetEditableMaterialListCB2, _ZN17CVehicleModelInfo25GetEditableMaterialListCBEP10RpMaterialPv, RpMaterial*, RpMaterial* pMaterial, void* pData);
    DECL_FASTCALL_SIMPLE(SetEnvironmentMapCB, _ZN17CVehicleModelInfo19SetEnvironmentMapCBEP10RpMaterialPv, RpMaterial*, RpMaterial* material, void* data);
    DECL_FASTCALL_SIMPLE(SetEnvironmentMapAtomicCB, _ZN17CVehicleModelInfo25SetEnvironmentMapAtomicCBEP8RpAtomicPv, RpAtomic*, RpAtomic* atomic, void* data);
    DECL_FASTCALL_SIMPLE(GetMatFXEffectMaterialCB, _ZN17CVehicleModelInfo24GetMatFXEffectMaterialCBEP10RpMaterialPv, RpMaterial*, RpMaterial* material, void* data);
    DECL_FASTCALL_SIMPLE(SetEnvMapCoeffAtomicCB, _ZN17CVehicleModelInfo22SetEnvMapCoeffAtomicCBEP8RpAtomicPv, RpAtomic*, RpAtomic* atomic, void* data);
    DECL_FASTCALL_SIMPLE(SetEnvMapCoeffCB, _ZN17CVehicleModelInfo16SetEnvMapCoeffCBEP10RpMaterialPv, RpMaterial*, RpMaterial* material, void* data);
    DECL_FASTCALL_SIMPLE(FindTextureCB, _ZN17CVehicleModelInfo13FindTextureCBEPKc, RwTexture*, char const* name);

    // STATIC values
    DECL_OBJECT_PLT(RwTexture*, ms_pLightsTexture, BYBIT(0x679D00, 0x851A18));
    DECL_OBJECT_PLT(RwTexture*, ms_pLightsOnTexture, BYBIT(0x678214, 0x84E440));
    DECL_OBJECT_ARRAY_PLT(i16, ms_numWheelUpgrades, BYBIT(0x676E48, 0x84BCD0));
    typedef i16 tms_upgradeWheelsRow[15];
    DECL_OBJECT_ARRAY_PLT(tms_upgradeWheelsRow, ms_upgradeWheels, BYBIT(0x6774C8, 0x84C9C8));
    DECL_OBJECT_ARRAY_PLT(u8, ms_currentCol, BYBIT(0x6761E4, 0x84A428));
    DECL_OBJECT_PLT(RwTexture*, ms_pRemapTexture, BYBIT(0x679B48, 0x8516B0));
    DECL_OBJECT_ARRAY_PLT(i8, ms_compsUsed, BYBIT(0x677170, 0x84C318));
    DECL_OBJECT_ARRAY_PLT(i8, ms_compsToUse, BYBIT(0x676F3C, 0x84BEB8));
    DECL_OBJECT_ARRAY_PLT(bool, ms_lightsOn, BYBIT(0x676CE0, 0x84BA08));

    // Member functions
    DECL_THISCALL_HEAD(GetWheelPosn, _ZN17CVehicleModelInfo12GetWheelPosnEiR7CVectorb, void, i32 wheel, CVector& outVec, bool local)
    DECL_THISCALL_TAIL(GetWheelPosn, wheel, outVec, local)
    DECL_THISCALL_HEAD(GetOriginalCompPosition, _ZN17CVehicleModelInfo23GetOriginalCompPositionER7CVectori, bool, CVector& outVec, i32 component)
    DECL_THISCALL_TAIL(GetOriginalCompPosition, outVec, component)
    DECL_THISCALL_SIMPLE(ChooseComponent, _ZN17CVehicleModelInfo15ChooseComponentEv, i32);
    DECL_THISCALL_SIMPLE(ChooseSecondComponent, _ZN17CVehicleModelInfo21ChooseSecondComponentEv, i32);
    DECL_THISCALL_SIMPLE(FindEditableMaterialList, _ZN17CVehicleModelInfo24FindEditableMaterialListEv, void);
    DECL_THISCALL_HEAD(SetVehicleColour, _ZN17CVehicleModelInfo16SetVehicleColourEhhhh, void, u8 prim, u8 sec, u8 tert, u8 quat)
    DECL_THISCALL_TAIL(SetVehicleColour, prim, sec, tert, quat)
    DECL_THISCALL_HEAD(ChooseVehicleColour, _ZN17CVehicleModelInfo19ChooseVehicleColourERhS0_S0_S0_i, void, u8& prim, u8& sec, u8& tert, u8& quat, i32 variationShift)
    DECL_THISCALL_TAIL(ChooseVehicleColour, prim, sec, tert, quat, variationShift)
    DECL_THISCALL_SIMPLE(DisableEnvMap, _ZN17CVehicleModelInfo13DisableEnvMapEv, void);
    DECL_THISCALL_HEAD(SetEnvMapCoeff, _ZN17CVehicleModelInfo14SetEnvMapCoeffEf, void, float coeff)
    DECL_THISCALL_TAIL(SetEnvMapCoeff, coeff)
    DECL_THISCALL_SIMPLE(GetNumRemaps, _ZN17CVehicleModelInfo12GetNumRemapsEv, i32);
    DECL_THISCALL_HEAD(AddRemap, _ZN17CVehicleModelInfo8AddRemapEPKc, void, char const* txd)
    DECL_THISCALL_TAIL(AddRemap, txd)
    DECL_THISCALL_SIMPLE(SetRenderPipelines, _ZN17CVehicleModelInfo18SetRenderPipelinesEv, void);
    DECL_THISCALL_SIMPLE(SetCarCustomPlate, _ZN17CVehicleModelInfo17SetCarCustomPlateEv, void);
    DECL_THISCALL_HEAD(IsUpgradeAvailable, _ZN17CVehicleModelInfo18IsUpgradeAvailableE18VehicleUpgradePosn, bool, VehicleUpgradePosn upgrade)
    DECL_THISCALL_TAIL(IsUpgradeAvailable, upgrade)
    DECL_THISCALL_HEAD(SetCustomCarPlateText, _ZN17CVehicleModelInfo21SetCustomCarPlateTextEPc, void, char* text)
    DECL_THISCALL_TAIL(SetCustomCarPlateText, text)
    DECL_THISCALL_SIMPLE(GetCustomCarPlateText, _ZN17CVehicleModelInfo21GetCustomCarPlateTextEv, char*);
    DECL_THISCALL_SIMPLE(SetAtomicRenderCallbacks, _ZN17CVehicleModelInfo24SetAtomicRenderCallbacksEv, void);
    DECL_THISCALL_HEAD(SetVehicleComponentFlags, _ZN17CVehicleModelInfo24SetVehicleComponentFlagsEP7RwFramej, void, RwFrame* component, u32 flags)
    DECL_THISCALL_TAIL(SetVehicleComponentFlags, component, flags)
    DECL_THISCALL_SIMPLE(PreprocessHierarchy, _ZN17CVehicleModelInfo19PreprocessHierarchyEv, void);
    DECL_THISCALL_SIMPLE(ReduceMaterialsInVehicle, _ZN17CVehicleModelInfo24ReduceMaterialsInVehicleEv, void);

    // Member values
    RpMaterial      *m_pPlateMaterial;
    char             m_szPlateText[9];
    unsigned char    m_nPlateType;
    char             m_szGameName[8];
    unsigned int     m_nVehicleType;
    float            m_fWheelSizeFront;
    float            m_fWheelSizeRear;
    short            m_nWheelModelIndex;
    short            m_nHandlingId;
    signed char      m_nNumDoors;
    signed char      m_nVehicleClass; // see eVehicleClass
    signed char      m_nFlags;
    signed char      m_nWheelUpgradeClass;
    signed char      m_nTimesUsed;
    short            m_nFrq;
    union
    {
        unsigned int m_nCompRules;
        struct
        {
            unsigned int nExtraA_comp1 : 4;
            unsigned int nExtraA_comp2 : 4;
            unsigned int nExtraA_comp3 : 4;
            unsigned int nExtraA_rule  : 4;
            unsigned int nExtraB_comp1 : 4;
            unsigned int nExtraB_comp2 : 4;
            unsigned int nExtraB_comp3 : 4;
            unsigned int nExtraB_rule  : 4;
        } m_nCompRulesBits;
    };
    float               m_fBikeSteerAngle;

    struct CVehicleStructure
    {
        CVector         m_avDummyPos[15];
        UpgradePosnDesc m_aUpgrades[18];
        RpAtomic       *m_apExtras[6];
        RpAtomic       *m_apExtrasLOD[6];
        signed char     m_nNumExtras;
        unsigned int    m_nMaskComponentsDamagable;

        // STATIC member
        //static CPool<CVehicleModelInfo> *&m_pInfoPool; // TODO:
    } *m_pVehicleStruct;

    RpMaterial         *m_firstColour[49];
    RpMaterial         *m_secondColour[33];
    RpMaterial         *m_thirdColour[17];
    RpMaterial         *m_fourthColour[17];
    RpMaterial         *m_apDirtMaterials[64];
    unsigned char       m_anPrimaryColors[8];
    unsigned char       m_anSecondaryColors[8];
    unsigned char       m_anTertiaryColors[8];
    unsigned char       m_anQuaternaryColors[8];
    unsigned char       m_nNumColorVariations;
    unsigned char       m_nLastColorVariation;
    unsigned char       m_nCurrentPrimaryColor;
    unsigned char       m_nCurrentSecondaryColor;
    unsigned char       m_nCurrentTertiaryColor;
    unsigned char       m_nCurrentQuaternaryColor;
    short               m_anUpgrades[18];
    const char         *m_anRemaps[4]; // Not TXDs on mobile
    union
    {
        uintptr_t m_nAnimFileIndex;
        uintptr_t       m_pAnimBlock;
    };
DECL_CLASS_END()
CHECKSIZE(CVehicleModelInfo, 0x3A8, 0x6B0);

#define ms_pLightsTexture ms_pLightsTexture()
#define ms_pLightsOnTexture ms_pLightsOnTexture()
#define ms_numWheelUpgrades ms_numWheelUpgrades()
#define ms_upgradeWheels ms_upgradeWheels()
#define ms_currentCol ms_currentCol()
#define ms_pRemapTexture ms_pRemapTexture()
#define ms_compsUsed ms_compsUsed()
#define ms_compsToUse ms_compsToUse()
#define ms_lightsOn ms_lightsOn()

#endif // __AML_PSDK_SAVEHICLEMODELINFO_H
