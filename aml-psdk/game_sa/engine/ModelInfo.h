#ifndef __AML_PSDK_SAMODELINFO_H
#define __AML_PSDK_SAMODELINFO_H

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/renderware/RwMatrix.h>
#include "../enum/WeaponType.h"
#include "../base/Lists.h"
#include "2dEffect.h"

struct CBox;
struct CBoundingBox;
struct C2dEffect;
struct CColModel;
struct RwObject;
struct RpClump;
struct RpAtomic;
struct CModelInfoAccelerator;
struct CBaseModelInfo;
struct CAtomicModelInfo;
struct CDamageAtomicModelInfo;
struct CLodAtomicModelInfo;
struct CTimeModelInfo;
struct CLodTimeModelInfo;
struct CWeaponModelInfo;
struct CClumpModelInfo;
struct CVehicleModelInfo;
struct CPedModelInfo;
struct RwFrame;

typedef CStore<C2dEffect, 100> t2dEffectStore;

enum ModelInfoType : i32
{
    MODEL_INFO_NONE = 0,
    MODEL_INFO_ATOMIC = 1,
    MODEL_INFO_MLO = 2,
    MODEL_INFO_TIME = 3,
    MODEL_INFO_WEAPON = 4,
    MODEL_INFO_CLUMP = 5,
    MODEL_INFO_VEHICLE = 6,
    MODEL_INFO_PED = 7,
    MODEL_INFO_LOD = 8,
    MODEL_INFO_XTRACOMPS = 9
};

struct tTimeInfo
{
    u8  m_nTimeOn;
    u8  m_nTimeOff;
    i16 m_nOtherTimeModel = -1;
};

struct RwObjectNameIdAssocation
{
    char *m_pName;
    int m_dwHierarchyId;
    unsigned int m_dwFlags;
};

DECL_CLASS(CModelInfoAccelerator)
    // Construct/Deconstruct functions
    DECL_DTORCALL(CModelInfoAccelerator, _ZN21CModelInfoAcceleratorD2Ev);
    DECL_CTORCALL(CModelInfoAccelerator, _ZN21CModelInfoAcceleratorC2Ev);
    // Member functions
    DECL_THISCALL_SIMPLE(AllocModelInfoIds, _ZN21CModelInfoAccelerator17AllocModelInfoIdsEv, void);
    DECL_THISCALL_SIMPLE(FreeModelInfoIds, _ZN21CModelInfoAccelerator16FreeModelInfoIdsEv, void);
    DECL_THISCALL_SIMPLE(GetModelInfoIdFile, _ZN21CModelInfoAccelerator18GetModelInfoIdFileEv, bool);
    DECL_THISCALL_SIMPLE(EndOfLoadPhase, _ZN21CModelInfoAccelerator14EndOfLoadPhaseEv, void);
    DECL_THISCALL_HEAD(AddModelInfoId, _ZN21CModelInfoAccelerator14AddModelInfoIdEt, void, u16 id)
    DECL_THISCALL_TAIL(AddModelInfoId, id)
    DECL_THISCALL_SIMPLE(Init, _ZN21CModelInfoAccelerator4InitEv, void);
    DECL_THISCALL_HEAD(Begin, _ZN21CModelInfoAccelerator5BeginEPc, void, char* pFileName)
    DECL_THISCALL_TAIL(Begin, pFileName)
    DECL_THISCALL_HEAD(End, _ZN21CModelInfoAccelerator3EndEPc, void, char* pFileName)
    DECL_THISCALL_TAIL(End, pFileName)
    DECL_THISCALL_SIMPLE(GetNextModelInfoId, _ZN21CModelInfoAccelerator18GetNextModelInfoIdEv, u16);
    DECL_THISCALL_HEAD(GetEntry, _ZN21CModelInfoAccelerator8GetEntryEPP14CBaseModelInfoPiPc, void, CBaseModelInfo** ppModelInfo, i32* pIndex, char* pName)
    DECL_THISCALL_TAIL(GetEntry, ppModelInfo, pIndex, pName)

    // Member values
    u16* m_pArrayModelInfoIds;
    u16 m_nModelInfosAdded;
    char m_FileName[20];
    bool m_bHasRun;
    bool m_bFileFound;
DECL_CLASS_END()
CHECKSIZE(CModelInfoAccelerator, 0x1C, 0x20);

struct colModelNodeInfo
{
    char* pName;
    u32 boneId;
    i32 nPieceType;
    float xOffset;
    float yOffset;
    float zOffset;
    float fRadius;
};
CHECKSIZE(colModelNodeInfo, 0x1C, 0x20);

DECL_CLASS_VTABLE(CBaseModelInfo)
    // Construct/Deconstruct functions
    DECL_CTORCALL(CBaseModelInfo, _ZN14CBaseModelInfoC2Ev);
    DECL_DTORCALL_VIRTUAL(CBaseModelInfo, _ZN14CBaseModelInfoD2Ev, _ZN14CBaseModelInfo, _ZTV14CBaseModelInfo);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(CBaseModelInfo, AsAtomicModelInfoPtr, _ZTV14CBaseModelInfo, 2, CAtomicModelInfo*)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CBaseModelInfo, AsDamageAtomicModelInfoPtr, _ZTV14CBaseModelInfo, 3, CDamageAtomicModelInfo*)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CBaseModelInfo, AsLodAtomicModelInfoPtr, _ZTV14CBaseModelInfo, 4, CLodAtomicModelInfo*)
    DECL_VIRTUALCALL_TAIL()
    virtual ModelInfoType GetModelType() = 0;
    DECL_VIRTUALCALL_HEAD(CBaseModelInfo, GetTimeInfo, _ZTV14CBaseModelInfo, 6, tTimeInfo*)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CBaseModelInfo, Init, _ZTV14CBaseModelInfo, 7, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CBaseModelInfo, Shutdown, _ZTV14CBaseModelInfo, 8, void)
    DECL_VIRTUALCALL_TAIL()
    virtual void DeleteRwObject() = 0;
    virtual i32 GetRwModelType() = 0;
    virtual RwObject* CreateInstance() = 0;
    virtual RwObject* CreateInstance(RwMatrix* matrix) = 0;
    DECL_VIRTUALCALL_HEAD(CBaseModelInfo, SetAnimFile, _ZTV14CBaseModelInfo, 13, void, const char* filename)
    DECL_VIRTUALCALL_TAIL(filename)
    DECL_VIRTUALCALL_HEAD(CBaseModelInfo, ConvertAnimFileIndex, _ZTV14CBaseModelInfo, 14, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CBaseModelInfo, GetAnimFileIndex, _ZTV14CBaseModelInfo, 15, uintptr_t)
    DECL_VIRTUALCALL_TAIL()

    // Member functions
    DECL_THISCALL_SIMPLE(DeleteCollisionModel, _ZN14CBaseModelInfo20DeleteCollisionModelEv, void);
    DECL_THISCALL_SIMPLE(ClearTexDictionary, _ZN14CBaseModelInfo18ClearTexDictionaryEv, void);
    DECL_THISCALL_SIMPLE(AddTexDictionaryRef, _ZN14CBaseModelInfo19AddTexDictionaryRefEv, void);
    DECL_THISCALL_SIMPLE(RemoveTexDictionaryRef, _ZN14CBaseModelInfo22RemoveTexDictionaryRefEv, void);
    DECL_THISCALL_SIMPLE(AddRef, _ZN14CBaseModelInfo6AddRefEv, void);
    DECL_THISCALL_SIMPLE(RemoveRef, _ZN14CBaseModelInfo9RemoveRefEv, void);
    DECL_THISCALL_SIMPLE(Init2dEffects, _ZN14CBaseModelInfo13Init2dEffectsEv, void);

    DECL_THISCALL_HEAD(SetTexDictionary, _ZN14CBaseModelInfo16SetTexDictionaryEPKcS1_, void, const char *pName, const char *dbName)
    DECL_THISCALL_TAIL(SetTexDictionary, pName, dbName)

    DECL_THISCALL_HEAD(SetColModel, _ZN14CBaseModelInfo11SetColModelEP9CColModelb, void, CColModel *pColModel, bool bOwnColModel)
    DECL_THISCALL_TAIL(SetColModel, pColModel, bOwnColModel)

    DECL_THISCALL_HEAD(Get2dEffect, _ZN14CBaseModelInfo11Get2dEffectEi, C2dEffect*, i32 index)
    DECL_THISCALL_TAIL(Get2dEffect, index)

    DECL_THISCALL_HEAD(Add2dEffect, _ZN14CBaseModelInfo11Add2dEffectEP9C2dEffect, void, C2dEffect *pEffect)
    DECL_THISCALL_TAIL(Add2dEffect, pEffect)

    // Member values
    unsigned int   m_nKey;
    char           m_szModelName[21];
    short m_nRefCount;
    short          m_nTxdIndex;
    unsigned char  m_nAlpha; // 0 - 255
    unsigned char  m_nNum2dEffects;
    short          m_n2dEffectIndex;
    short          m_nObjectInfoIndex;
    union
    {
        unsigned short m_nFlags;
        struct
        {
            unsigned char bHasBeenPreRendered : 1;
            unsigned char bDrawLast : 1;
            unsigned char bAdditiveRender : 1;
            unsigned char bDontWriteZBuffer : 1;
            unsigned char bDontCastShadowsOn : 1;
            unsigned char bDoWeOwnTheColModel : 1;
            unsigned char bIsBackfaceCulled : 1;
            unsigned char bIsLod : 1;
            union
            {
                struct // Atomic flags
                {
                    unsigned char bIsRoad : 1;
                    unsigned char bHasComplexAtomicHierarchy : 1;
                    unsigned char bDontCollideWithFlyer : 1;
                    unsigned char nSpecialType : 4;
                    unsigned char bWetRoadReflection : 1;
                };
                struct // Vehicle flags
                {
                    unsigned char bUsesVehDummy : 1;
                    unsigned char : 1;
                    unsigned char nCarmodId : 5;
                    unsigned char bUseCommonVehicleDictionary : 1;
                };
                struct // Clump flags
                {
                    unsigned char bHasAnimBlend : 1;
                    unsigned char bHasComplexHierarchy : 1;
                    unsigned char bAnimSomething : 1;
                    unsigned char bOwnsCollisionModel : 1;
                    unsigned char : 3;
                    unsigned char bTagDisabled : 1;
                };
            };
        };
    };
    CColModel        *m_pColModel;
    float             m_fDrawDistance;
    union
    {
        RwObject* m_pRwObject;
        RpClump* m_pRwClump;
        RpAtomic* m_pRwAtomic;
    };
DECL_CLASS_END()
CHECKSIZE(CBaseModelInfo, 0x38, 0x48);



DECL_CLASS_BASED(CAtomicModelInfo, CBaseModelInfo)
    CAtomicModelInfo() = delete;
    DECL_VIRTUALCALL_HEAD(CAtomicModelInfo, GetModelType, _ZTV16CAtomicModelInfo, 5, ModelInfoType)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CAtomicModelInfo, DeleteRwObject, _ZTV16CAtomicModelInfo, 9, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CAtomicModelInfo, GetRwModelType, _ZTV16CAtomicModelInfo, 10, i32)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CAtomicModelInfo, CreateInstance, _ZTV16CAtomicModelInfo, 11, RwObject*)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CAtomicModelInfo, CreateInstance, _ZTV16CAtomicModelInfo, 12, RwObject*, RwMatrix* matrix)
    DECL_VIRTUALCALL_TAIL(matrix)

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(CAtomicModelInfo, SetAtomic, _ZTV16CAtomicModelInfo, 16, void, RpAtomic *pAtomic)
    DECL_VIRTUALCALL_TAIL(pAtomic)

    // Member functions
    DECL_THISCALL_HEAD(SetupVehicleUpgradeFlags, _ZN16CAtomicModelInfo24SetupVehicleUpgradeFlagsEPKc, void, const char *pName)
    DECL_THISCALL_TAIL(SetupVehicleUpgradeFlags, pName)
    
    DECL_THISCALL_HEAD(GetAtomicFromDistance, _ZN16CAtomicModelInfo21GetAtomicFromDistanceEf, RpAtomic*, float dist)
    DECL_THISCALL_TAIL(GetAtomicFromDistance, dist)
DECL_CLASS_END()



DECL_CLASS_BASED(CLodAtomicModelInfo, CAtomicModelInfo)
    CLodAtomicModelInfo() = delete;
    // Construct/Deconstruct functions
    DECL_THISCALL_SIMPLE(Delete, _ZN19CLodAtomicModelInfoD0Ev, void);

    // Member values
    i16 numChildren;
    i16 numChildrenRendered;
DECL_CLASS_END()
CHECKSIZE(CLodAtomicModelInfo, 0x3C, 0x50);

DECL_CLASS_BASED(CLodTimeModelInfo, CLodAtomicModelInfo)
    CLodTimeModelInfo() = delete;
    // Construct/Deconstruct functions
    DECL_THISCALL_SIMPLE(Delete, _ZN17CLodTimeModelInfoD0Ev, void);

    // Member values
    tTimeInfo m_time;
DECL_CLASS_END()
CHECKSIZE(CLodTimeModelInfo, 0x40, 0x50);

DECL_CLASS_BASED(CClumpModelInfo, CBaseModelInfo)
    CClumpModelInfo() = delete;
    DECL_VIRTUALCALL_HEAD(CClumpModelInfo, GetModelType, _ZTV15CClumpModelInfo, 5, ModelInfoType)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CClumpModelInfo, DeleteRwObject, _ZTV15CClumpModelInfo, 9, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CClumpModelInfo, GetRwModelType, _ZTV15CClumpModelInfo, 10, i32)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CClumpModelInfo, CreateInstance, _ZTV15CClumpModelInfo, 11, RwObject*)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CClumpModelInfo, CreateInstance, _ZTV15CClumpModelInfo, 12, RwObject*, RwMatrix* matrix)
    DECL_VIRTUALCALL_TAIL(matrix)

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(CClumpModelInfo, GetBoundingBox, _ZTV15CClumpModelInfo, 16, CBoundingBox &)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CClumpModelInfo, SetClump, _ZTV15CClumpModelInfo, 17, void, RpClump *clump)
    DECL_VIRTUALCALL_TAIL(clump)

    // STATIC functions
    DECL_FASTCALL_SIMPLE(SetAtomicRendererCB, _ZN15CClumpModelInfo19SetAtomicRendererCBEP8RpAtomicPv, RpAtomic*, RpAtomic *pAtomic, void *pData);
    DECL_FASTCALL_SIMPLE(FindFrameFromNameCB, _ZN15CClumpModelInfo19FindFrameFromNameCBEP7RwFramePv, RwFrame*, RwFrame *pFrame, void *pData);
    DECL_FASTCALL_SIMPLE(FindFrameFromNameWithoutIdCB, _ZN15CClumpModelInfo28FindFrameFromNameWithoutIdCBEP7RwFramePv, RwFrame*, RwFrame *pFrame, void *pData);
    DECL_FASTCALL_SIMPLE(FindFrameFromIdCB, _ZN15CClumpModelInfo17FindFrameFromIdCBEP7RwFramePv, RwFrame*, RwFrame *pFrame, void *pData);
    DECL_FASTCALL_SIMPLE(FillFrameArrayCB, _ZN15CClumpModelInfo16FillFrameArrayCBEP7RwFramePv, RwFrame*, RwFrame *pFrame, void *pData);
    DECL_FASTCALL_SIMPLE(GetFrameFromId, _ZN15CClumpModelInfo14GetFrameFromIdEP7RpClumpi, RwFrame*, RpClump *pClump, i32 id);
    DECL_FASTCALL_SIMPLE(GetFrameFromName, _ZN15CClumpModelInfo16GetFrameFromNameEP7RpClumpPKc, RwFrame*, RpClump *pClump, const char *pName);
    DECL_FASTCALL_SIMPLE(FillFrameArray, _ZN15CClumpModelInfo14FillFrameArrayEP7RpClumpPP7RwFrame, void, RpClump *pClump, RwFrame **ppFrame);

    // Member functions
    DECL_THISCALL_HEAD(SetFrameIds, _ZN15CClumpModelInfo11SetFrameIdsEP24RwObjectNameIdAssocation, void, RwObjectNameIdAssocation *pAssocArray)
    DECL_THISCALL_TAIL(SetFrameIds, pAssocArray)

    // Member values
    union
    {
        char        *m_animFileName;
        uintptr_t m_dwAnimFileIndex;
    };
DECL_CLASS_END()



DECL_CLASS_BASED(CWeaponModelInfo, CClumpModelInfo)
    CWeaponModelInfo() = delete;
    // Member values
    eWeaponType m_weaponInfo;
DECL_CLASS_END()



DECL_CLASS_BASED(CPedModelInfo, CClumpModelInfo)
    CPedModelInfo() = delete;
    // Construct/Deconstruct functions
    DECL_DTORCALL_VIRTUAL(CPedModelInfo, _ZN13CPedModelInfoD2Ev, _ZN13CPedModelInfo, _ZTV13CPedModelInfo);

    // STATIC values
    DECL_OBJECT_ARRAY_PLT(RwObjectNameIdAssocation, m_pPedIds, BYBIT(0x67796C, 0x84D300));

    // Member functions
    DECL_THISCALL_HEAD(AddXtraAtomics, _ZN13CPedModelInfo14AddXtraAtomicsEP7RpClump, void, RpClump* pClump)
    DECL_THISCALL_TAIL(AddXtraAtomics, pClump)
    DECL_THISCALL_HEAD(SetFaceTexture, _ZN13CPedModelInfo14SetFaceTextureEP9RwTexture, void, RwTexture* pTexture)
    DECL_THISCALL_TAIL(SetFaceTexture, pTexture)
    DECL_THISCALL_HEAD(CreateHitColModelSkinned, _ZN13CPedModelInfo24CreateHitColModelSkinnedEP7RpClump, void, RpClump* pClump)
    DECL_THISCALL_TAIL(CreateHitColModelSkinned, pClump)
    DECL_THISCALL_HEAD(AnimatePedColModelSkinned, _ZN13CPedModelInfo25AnimatePedColModelSkinnedEP7RpClump, CColModel*, RpClump* pClump)
    DECL_THISCALL_TAIL(AnimatePedColModelSkinned, pClump)
    DECL_THISCALL_HEAD(AnimatePedColModelSkinnedWorld, _ZN13CPedModelInfo30AnimatePedColModelSkinnedWorldEP7RpClump, CColModel*, RpClump* pClump)
    DECL_THISCALL_TAIL(AnimatePedColModelSkinnedWorld, pClump)
    DECL_THISCALL_SIMPLE(IncrementVoice, _ZN13CPedModelInfo14IncrementVoiceEv, void);

    // Member values
    int            m_nAnimType;
    unsigned int   m_nPedType;
    unsigned int   m_nStatType;
    unsigned short m_nCarsCanDriveMask;
    unsigned short m_nPedFlags;
    CColModel     *m_pHitColModel;
    signed char    m_nRadio1;
    signed char    m_nRadio2;
    unsigned char  m_nRace;
    short          m_nPedAudioType;
    short          m_nVoice1;
    short          m_nVoice2;
    short          m_nVoiceId;
DECL_CLASS_END()



DECL_CLASS_BASED(CDamageAtomicModelInfo, CAtomicModelInfo)
    CDamageAtomicModelInfo() = delete;
    // STATIC values
    DECL_VALUE_PLT_BOOL(m_bCreateDamagedVersion, BYBIT(0x677244, 0x84C4C0));

    // Member functions
    DECL_THISCALL_HEAD(SetDamagedAtomic, _ZN22CDamageAtomicModelInfo16SetDamagedAtomicEP8RpAtomic, void, RpAtomic* pAtomic)
    DECL_THISCALL_TAIL(SetDamagedAtomic, pAtomic)

    // Member values
    RpAtomic* m_pDamagedAtomic;
DECL_CLASS_END()



DECL_CLASS_BASED(CTimeModelInfo, CAtomicModelInfo)
    CTimeModelInfo() = delete;
    // Member values
    tTimeInfo m_timeInfo;
DECL_CLASS_END()



DECL_CLASS(CModelInfo)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(PrintModelInfoStoreUsage, _ZN10CModelInfo24PrintModelInfoStoreUsageEv, void);
    DECL_FASTCALL_SIMPLE(Initialise, _ZN10CModelInfo10InitialiseEv, void);
    DECL_FASTCALL_SIMPLE(AddAtomicModel, _ZN10CModelInfo14AddAtomicModelEi, CAtomicModelInfo*, i32 index);
    DECL_FASTCALL_SIMPLE(ReInit2dEffects, _ZN10CModelInfo15ReInit2dEffectsEv, void);
    DECL_FASTCALL_SIMPLE(ShutDown, _ZN10CModelInfo8ShutDownEv, void);
    DECL_FASTCALL_SIMPLE(GetModelInfo1, _ZN10CModelInfo12GetModelInfoEPKcPi, CBaseModelInfo*, const char *pName, i32 *pIndex);
    DECL_FASTCALL_SIMPLE(GetModelInfoFromHashKey, _ZN10CModelInfo23GetModelInfoFromHashKeyEjPi, CBaseModelInfo*, u32 key, i32 *pIndex);
    DECL_FASTCALL_SIMPLE(GetModelInfoUInt16, _ZN10CModelInfo18GetModelInfoUInt16EPKcPt, CBaseModelInfo*, const char *pName, u16 *pIndex);
    DECL_FASTCALL_SIMPLE(GetModelInfo2, _ZN10CModelInfo12GetModelInfoEPKcii, CBaseModelInfo*, const char *pName, i32 start, i32 end);
    DECL_FASTCALL_SIMPLE(GetModelInfoFast, _ZN10CModelInfo16GetModelInfoFastEP21CModelInfoAcceleratorPKcPi, CBaseModelInfo*, CModelInfoAccelerator *pAccel, const char *pName, i32 *pIndex);
    DECL_FASTCALL_SIMPLE(AddDamageAtomicModel, _ZN10CModelInfo20AddDamageAtomicModelEi, CDamageAtomicModelInfo*, i32 index);
    DECL_FASTCALL_SIMPLE(AddLodAtomicModel, _ZN10CModelInfo17AddLodAtomicModelEi, CLodAtomicModelInfo*, i32 index);
    DECL_FASTCALL_SIMPLE(AddTimeModel, _ZN10CModelInfo12AddTimeModelEi, CTimeModelInfo*, i32 index);
    DECL_FASTCALL_SIMPLE(AddLodTimeModel, _ZN10CModelInfo15AddLodTimeModelEi, CLodTimeModelInfo*, i32 index);
    DECL_FASTCALL_SIMPLE(AddWeaponModel, _ZN10CModelInfo14AddWeaponModelEi, CWeaponModelInfo*, i32 index);
    DECL_FASTCALL_SIMPLE(AddClumpModel, _ZN10CModelInfo13AddClumpModelEi, CClumpModelInfo*, i32 index);
    DECL_FASTCALL_SIMPLE(AddVehicleModel, _ZN10CModelInfo15AddVehicleModelEi, CVehicleModelInfo*, i32 index);
    DECL_FASTCALL_SIMPLE(AddPedModel, _ZN10CModelInfo11AddPedModelEi, CPedModelInfo*, i32 index);
    DECL_FASTCALL_SIMPLE(Get2dEffectStore, _ZN10CModelInfo16Get2dEffectStoreEv, t2dEffectStore&);
    DECL_FASTCALL_SIMPLE(IsBoatModel, _ZN10CModelInfo11IsBoatModelEi, u8, i32 index);
    DECL_FASTCALL_SIMPLE(IsCarModel, _ZN10CModelInfo10IsCarModelEi, u8, i32 index);
    DECL_FASTCALL_SIMPLE(IsTrainModel, _ZN10CModelInfo12IsTrainModelEi, u8, i32 index);
    DECL_FASTCALL_SIMPLE(IsHeliModel, _ZN10CModelInfo11IsHeliModelEi, u8, i32 index);
    DECL_FASTCALL_SIMPLE(IsPlaneModel, _ZN10CModelInfo12IsPlaneModelEi, u8, i32 index);
    DECL_FASTCALL_SIMPLE(IsBikeModel, _ZN10CModelInfo11IsBikeModelEi, u8, i32 index);
    DECL_FASTCALL_SIMPLE(IsFakePlaneModel, _ZN10CModelInfo16IsFakePlaneModelEi, u8, i32 index);
    DECL_FASTCALL_SIMPLE(IsMonsterTruckModel, _ZN10CModelInfo19IsMonsterTruckModelEi, u8, i32 index);
    DECL_FASTCALL_SIMPLE(IsQuadBikeModel, _ZN10CModelInfo15IsQuadBikeModelEi, u8, i32 index);
    DECL_FASTCALL_SIMPLE(IsBmxModel, _ZN10CModelInfo10IsBmxModelEi, u8, i32 index);
    DECL_FASTCALL_SIMPLE(IsTrailerModel, _ZN10CModelInfo14IsTrailerModelEi, u8, i32 index);
    DECL_FASTCALL_SIMPLE(IsVehicleModelType, _ZN10CModelInfo18IsVehicleModelTypeEi, i32, i32 index);

    // STATIC values
    DECL_VALUE_PLT_I32(ms_lastPositionSearched, BYBIT(0x676B64, 0x84B710));

    // STATIC members
    DECL_OBJECT_ARRAY_PLT(CBaseModelInfo*, ms_modelInfoPtrs, BYBIT(0x6796D4, 0x850DB8));

    // Helper functions
    static inline CBaseModelInfo* GetModelInfo(const char *pName, i32 *pIndex)
    {
        return GetModelInfo1(pName, pIndex);
    }
    static inline CBaseModelInfo* GetModelInfo(const char *pName, i32 start, i32 end)
    {
        return GetModelInfo2(pName, start, end);
    }
DECL_CLASS_END()

#define ms_modelInfoPtrs ms_modelInfoPtrs()
#define m_bCreateDamagedVersion m_bCreateDamagedVersion()

#define m_pPedIds m_pPedIds()

#define ms_lastPositionSearched ms_lastPositionSearched()

struct VehicleDesc
{
    RwObjectNameIdAssocation* pAssocArray;
};
CHECKSIZE(VehicleDesc, 0x4, 0x8);

#endif // __AML_PSDK_SAMODELINFO_H
