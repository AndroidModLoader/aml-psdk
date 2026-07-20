#ifndef __AML_PSDK_SAVISIBILITYPLUGINS_H
#define __AML_PSDK_SAVISIBILITYPLUGINS_H

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/game_sa/base/Lists.h>
#include <aml-psdk/renderware/RpAtomic.h>
#include <aml-psdk/renderware/RwCamera.h>

typedef void (*RenderFunction)(void *pObj, float dist);

struct AlphaObjectInfo
{
    void           *pObj;
    RenderFunction  RenderFn;
    float           dist;
};
CHECKSIZE(AlphaObjectInfo, 0xC, 0x18);  // 64-bit from the IDB; 32-bit measured from this layout

struct CBaseModelInfo;
struct CClumpModelInfo;
struct CEntity;
struct CPed;
struct RpAtomic;
struct RpClump;
struct RwCamera;
struct RwFrame;
struct RwMatrix;
struct RwV3d;

DECL_CLASS(CVisibilityPlugins)
    // Functions
    DECL_FASTCALL_SIMPLE(AtomicConstructor, _ZN18CVisibilityPlugins17AtomicConstructorEPvii, void*, void* atom, RwInt32 offset, RwInt32 size);
    DECL_FASTCALL_SIMPLE(AtomicCopyConstructor, _ZN18CVisibilityPlugins21AtomicCopyConstructorEPvPKvii, void*, void* pDestAtom, const void* pSrcAtom, RwInt32 offset, RwInt32 size);
    DECL_FASTCALL_SIMPLE(AtomicDestructor, _ZN18CVisibilityPlugins16AtomicDestructorEPvii, void*, void* atom, RwInt32 offset, RwInt32 size);
    DECL_FASTCALL_SIMPLE(FrameConstructor, _ZN18CVisibilityPlugins16FrameConstructorEPvii, void*, void* pFrame, RwInt32 offset, RwInt32 size);
    DECL_FASTCALL_SIMPLE(FrameCopyConstructor, _ZN18CVisibilityPlugins20FrameCopyConstructorEPvPKvii, void*, void* pDestFrame, const void* pSrcFrame, RwInt32 offset, RwInt32 size);
    DECL_FASTCALL_SIMPLE(FrameDestructor, _ZN18CVisibilityPlugins15FrameDestructorEPvii, void*, void* pFrame, RwInt32 offset, RwInt32 size);
    DECL_FASTCALL_SIMPLE(ClumpConstructor, _ZN18CVisibilityPlugins16ClumpConstructorEPvii, void*, void* pClump, RwInt32 offset, RwInt32 size);
    DECL_FASTCALL_SIMPLE(DefaultVisibilityCB, _ZN18CVisibilityPlugins19DefaultVisibilityCBEP7RpClump, i32, RpClump* pClump);
    DECL_FASTCALL_SIMPLE(ClumpCopyConstructor, _ZN18CVisibilityPlugins20ClumpCopyConstructorEPvPKvii, void*, void* pDestClump, const void* pSrcClump, RwInt32 offset, RwInt32 size);
    DECL_FASTCALL_SIMPLE(ClumpDestructor, _ZN18CVisibilityPlugins15ClumpDestructorEPvii, void*, void* pClump, RwInt32 offset, RwInt32 size);
    DECL_FASTCALL_SIMPLE(PluginAttach, _ZN18CVisibilityPlugins12PluginAttachEv, i32);
    DECL_FASTCALL_SIMPLE(Initialise, _ZN18CVisibilityPlugins10InitialiseEv, void);
    DECL_FASTCALL_SIMPLE(Shutdown, _ZN18CVisibilityPlugins8ShutdownEv, void);
    DECL_FASTCALL_SIMPLE(RenderWeaponPedsForPC, _ZN18CVisibilityPlugins21RenderWeaponPedsForPCEv, void);
    DECL_FASTCALL_SIMPLE(SetModelInfoIndex, _ZN18CVisibilityPlugins17SetModelInfoIndexEP8RpAtomici, void, RpAtomic* pAtomic, i32 index);
    DECL_FASTCALL_SIMPLE(GetModelInfoIndex, _ZN18CVisibilityPlugins17GetModelInfoIndexEP8RpAtomic, i32, RpAtomic* pAtomic);
    DECL_FASTCALL_SIMPLE(GetModelInfo, _ZN18CVisibilityPlugins12GetModelInfoEP8RpAtomic, CBaseModelInfo*, RpAtomic* pAtomic);
    DECL_FASTCALL_SIMPLE(SetAtomicId, _ZN18CVisibilityPlugins11SetAtomicIdEP8RpAtomici, void, RpAtomic* pAtomic, i32 id);
    DECL_FASTCALL_SIMPLE(SetAtomicFlag, _ZN18CVisibilityPlugins13SetAtomicFlagEP8RpAtomict, void, RpAtomic* pAtomic, u16 flag);
    DECL_FASTCALL_SIMPLE(SetClumpForAllAtomicsFlag, _ZN18CVisibilityPlugins25SetClumpForAllAtomicsFlagEP7RpClumpi, void, RpClump* pClump, i32 id);
    DECL_FASTCALL_SIMPLE(ClearAtomicFlag, _ZN18CVisibilityPlugins15ClearAtomicFlagEP8RpAtomict, void, RpAtomic* pAtomic, u16 flag);
    DECL_FASTCALL_SIMPLE(ClearClumpForAllAtomicsFlag, _ZN18CVisibilityPlugins27ClearClumpForAllAtomicsFlagEP7RpClumpi, void, RpClump* pClump, i32 id);
    DECL_FASTCALL_SIMPLE(GetAtomicId, _ZN18CVisibilityPlugins11GetAtomicIdEP8RpAtomic, i32, RpAtomic* pAtomic);
    DECL_FASTCALL_SIMPLE(SetUserValue, _ZN18CVisibilityPlugins12SetUserValueEP8RpAtomict, void, RpAtomic* pAtomic, u16 value);
    DECL_FASTCALL_SIMPLE(GetUserValue, _ZN18CVisibilityPlugins12GetUserValueEP8RpAtomic, u16, RpAtomic* pAtomic);
    DECL_FASTCALL_SIMPLE(SetupVehicleVariables, _ZN18CVisibilityPlugins21SetupVehicleVariablesEP7RpClump, void, RpClump* pClump);
    DECL_FASTCALL_SIMPLE(GetDistanceSquaredFromCamera, _ZN18CVisibilityPlugins28GetDistanceSquaredFromCameraEP7RwFrame, float, RwFrame* pFrame);
    DECL_FASTCALL_SIMPLE(RenderWheelAtomicCB, _ZN18CVisibilityPlugins19RenderWheelAtomicCBEP8RpAtomic, RpAtomic*, RpAtomic* pAtomic);
    DECL_FASTCALL_SIMPLE(RenderObjNormalAtomic, _ZN18CVisibilityPlugins21RenderObjNormalAtomicEP8RpAtomic, RpAtomic*, RpAtomic* pAtomic);
    DECL_FASTCALL_SIMPLE(RenderAtomicWithAlpha, _ZN18CVisibilityPlugins21RenderAtomicWithAlphaEP8RpAtomici, void, RpAtomic* pAtomic, i32 alpha);
    DECL_FASTCALL_SIMPLE(CalculateFadingAtomicAlpha, _ZN18CVisibilityPlugins26CalculateFadingAtomicAlphaEP14CBaseModelInfoP7CEntityf, i32, CBaseModelInfo* pModelInfo, CEntity* pEntity, float dist);
    DECL_FASTCALL_SIMPLE(SetupRenderFadingAtomic, _ZN18CVisibilityPlugins23SetupRenderFadingAtomicEP14CBaseModelInfoi, void, CBaseModelInfo* pModelInfo, i32 alpha);
    DECL_FASTCALL_SIMPLE(ResetRenderFadingAtomic, _ZN18CVisibilityPlugins23ResetRenderFadingAtomicEP14CBaseModelInfo, void, CBaseModelInfo* pModelInfo);
    DECL_FASTCALL_SIMPLE(RenderFadingAtomic, _ZN18CVisibilityPlugins18RenderFadingAtomicEP14CBaseModelInfoP8RpAtomici, void, CBaseModelInfo* pModelInfo, RpAtomic* pAtomic, i32 alpha);
    DECL_FASTCALL_SIMPLE(RenderAtomicWithAlphaCB, _ZN18CVisibilityPlugins23RenderAtomicWithAlphaCBEP8RpAtomicPv, RpAtomic*, RpAtomic* pAtomic, void* pAlpha);
    DECL_FASTCALL_SIMPLE(RenderFadingClump, _ZN18CVisibilityPlugins17RenderFadingClumpEP14CBaseModelInfoP7RpClumpi, void, CBaseModelInfo* pModelInfo, RpClump* pClump, i32 alpha);
    DECL_FASTCALL_SIMPLE(RenderVehicleReallyLowDetailCB, _ZN18CVisibilityPlugins30RenderVehicleReallyLowDetailCBEP8RpAtomic, RpAtomic*, RpAtomic* pAtomic);
    DECL_FASTCALL_SIMPLE(GetClumpAlpha, _ZN18CVisibilityPlugins13GetClumpAlphaEP7RpClump, i32, RpClump* pClump);
    DECL_FASTCALL_SIMPLE(GetDotProductWithCameraVector, _ZN18CVisibilityPlugins29GetDotProductWithCameraVectorEP11RwMatrixTagS1_j, float, RwMatrix* pMatrix, RwMatrix* pCarMatrix, u32 atomicId);
    DECL_FASTCALL_SIMPLE(RenderVehicleHiDetailCB, _ZN18CVisibilityPlugins23RenderVehicleHiDetailCBEP8RpAtomic, RpAtomic*, RpAtomic* pAtomic);
    DECL_FASTCALL_SIMPLE(RenderVehicleHiDetailAlphaCB, _ZN18CVisibilityPlugins28RenderVehicleHiDetailAlphaCBEP8RpAtomic, RpAtomic*, RpAtomic* pAtomic);
    DECL_FASTCALL_SIMPLE(InsertAtomicIntoSortedList, _ZN18CVisibilityPlugins26InsertAtomicIntoSortedListEP8RpAtomicf, bool, RpAtomic* pAtomic, float dist);
    DECL_FASTCALL_SIMPLE(RenderHeliRotorAlphaCB, _ZN18CVisibilityPlugins22RenderHeliRotorAlphaCBEP8RpAtomic, RpAtomic*, RpAtomic* pAtomic);
    DECL_FASTCALL_SIMPLE(RenderHeliTailRotorAlphaCB, _ZN18CVisibilityPlugins26RenderHeliTailRotorAlphaCBEP8RpAtomic, RpAtomic*, RpAtomic* pAtomic);
    DECL_FASTCALL_SIMPLE(RenderTrainHiDetailCB, _ZN18CVisibilityPlugins21RenderTrainHiDetailCBEP8RpAtomic, RpAtomic*, RpAtomic* pAtomic);
    DECL_FASTCALL_SIMPLE(RenderTrainHiDetailAlphaCB, _ZN18CVisibilityPlugins26RenderTrainHiDetailAlphaCBEP8RpAtomic, RpAtomic*, RpAtomic* pAtomic);
    DECL_FASTCALL_SIMPLE(RenderVehicleReallyLowDetailCB_BigVehicle, _ZN18CVisibilityPlugins41RenderVehicleReallyLowDetailCB_BigVehicleEP8RpAtomic, RpAtomic*, RpAtomic* pAtomic);
    DECL_FASTCALL_SIMPLE(RenderVehicleHiDetailCB_BigVehicle, _ZN18CVisibilityPlugins34RenderVehicleHiDetailCB_BigVehicleEP8RpAtomic, RpAtomic*, RpAtomic* pAtomic);
    DECL_FASTCALL_SIMPLE(RenderVehicleHiDetailAlphaCB_BigVehicle, _ZN18CVisibilityPlugins39RenderVehicleHiDetailAlphaCB_BigVehicleEP8RpAtomic, RpAtomic*, RpAtomic* pAtomic);
    DECL_FASTCALL_SIMPLE(RenderVehicleLoDetailCB_Boat, _ZN18CVisibilityPlugins28RenderVehicleLoDetailCB_BoatEP8RpAtomic, RpAtomic*, RpAtomic* pAtomic);
    DECL_FASTCALL_SIMPLE(RenderVehicleHiDetailCB_Boat, _ZN18CVisibilityPlugins28RenderVehicleHiDetailCB_BoatEP8RpAtomic, RpAtomic*, RpAtomic* pAtomic);
    DECL_FASTCALL_SIMPLE(RenderVehicleHiDetailAlphaCB_Boat, _ZN18CVisibilityPlugins33RenderVehicleHiDetailAlphaCB_BoatEP8RpAtomic, RpAtomic*, RpAtomic* pAtomic);
    DECL_FASTCALL_SIMPLE(InsertAtomicIntoBoatSortedList, _ZN18CVisibilityPlugins30InsertAtomicIntoBoatSortedListEP8RpAtomicf, bool, RpAtomic* pAtomic, float dist);
    DECL_FASTCALL_SIMPLE(RenderPlayerCB, _ZN18CVisibilityPlugins14RenderPlayerCBEP8RpAtomic, RpAtomic*, RpAtomic* pAtomic);
    DECL_FASTCALL_SIMPLE(RenderPedCB, _ZN18CVisibilityPlugins11RenderPedCBEP8RpAtomic, RpAtomic*, RpAtomic* pAtomic);
    DECL_FASTCALL_SIMPLE(RenderFadingClumpCB, _ZN18CVisibilityPlugins19RenderFadingClumpCBEP8RpAtomic, RpAtomic*, RpAtomic* pAtomic);
    DECL_FASTCALL_SIMPLE(RenderWeaponCB, _ZN18CVisibilityPlugins14RenderWeaponCBEP8RpAtomic, RpAtomic*, RpAtomic* pAtomic);
    DECL_FASTCALL_SIMPLE(GetClumpModelInfo, _ZN18CVisibilityPlugins17GetClumpModelInfoEP7RpClump, CClumpModelInfo*, RpClump* pClump);
    DECL_FASTCALL_SIMPLE(SetAtomicRenderCallback, _ZN18CVisibilityPlugins23SetAtomicRenderCallbackEP8RpAtomicPFS1_S1_E, void, RpAtomic* pAtomic, RpAtomicCallBackRender renderCB);
    DECL_FASTCALL_SIMPLE(SetRenderWareCamera, _ZN18CVisibilityPlugins19SetRenderWareCameraEP8RwCamera, void, RwCamera* pCamera);
    DECL_FASTCALL_SIMPLE(IsAtomicVisible, _ZN18CVisibilityPlugins15IsAtomicVisibleEP8RpAtomic, i32, RpAtomic* pAtomic);
    DECL_FASTCALL_SIMPLE(SetFrameHierarchyId, BYBIT(_ZN18CVisibilityPlugins19SetFrameHierarchyIdEP7RwFramej, _ZN18CVisibilityPlugins19SetFrameHierarchyIdEP7RwFramey), void, RwFrame* pFrame, uintptr_t value);
    DECL_FASTCALL_SIMPLE(GetFrameHierarchyId, _ZN18CVisibilityPlugins19GetFrameHierarchyIdEP7RwFrame, uintptr_t, RwFrame* pFrame);
    DECL_FASTCALL_SIMPLE(FrustumSphereCB, _ZN18CVisibilityPlugins15FrustumSphereCBEP7RpClump, i32, RpClump* pClump);
    DECL_FASTCALL_SIMPLE(VehicleVisibilityCB, _ZN18CVisibilityPlugins19VehicleVisibilityCBEP7RpClump, i32, RpClump* pClump);
    DECL_FASTCALL_SIMPLE(VehicleVisibilityCB_BigVehicle, _ZN18CVisibilityPlugins30VehicleVisibilityCB_BigVehicleEP7RpClump, i32, RpClump* pClump);
    DECL_FASTCALL_SIMPLE(SetClumpModelInfo, _ZN18CVisibilityPlugins17SetClumpModelInfoEP7RpClumpP15CClumpModelInfo, void, RpClump* pClump, CClumpModelInfo* pModelInfo);
    DECL_FASTCALL_SIMPLE(IsClumpVisible, _ZN18CVisibilityPlugins14IsClumpVisibleEP7RpClump, i32, RpClump* pClump);
    DECL_FASTCALL_SIMPLE(SetClumpAlpha, _ZN18CVisibilityPlugins13SetClumpAlphaEP7RpClumpi, void, RpClump* pClump, i32 alpha);
    DECL_FASTCALL_SIMPLE(InitAlphaAtomicList, _ZN18CVisibilityPlugins19InitAlphaAtomicListEv, void);
    DECL_FASTCALL_SIMPLE(InitAlphaEntityList, _ZN18CVisibilityPlugins19InitAlphaEntityListEv, void);
    DECL_FASTCALL_SIMPLE(RenderAtomic, _ZN18CVisibilityPlugins12RenderAtomicEPvf, void, RpAtomic* pObj, float dist);
    DECL_FASTCALL_SIMPLE(InsertEntityIntoSortedList, _ZN18CVisibilityPlugins26InsertEntityIntoSortedListEP7CEntityf, bool, CEntity* pEntity, float dist);
    DECL_FASTCALL_SIMPLE(RenderEntity, _ZN18CVisibilityPlugins12RenderEntityEPvf, void, CEntity* pObj, float dist);
    DECL_FASTCALL_SIMPLE(InsertEntityIntoReallyDrawLastList, _ZN18CVisibilityPlugins34InsertEntityIntoReallyDrawLastListEP7CEntityf, bool, CEntity* pEntity, float dist);
    DECL_FASTCALL_SIMPLE(InsertEntityIntoUnderwaterList, _ZN18CVisibilityPlugins30InsertEntityIntoUnderwaterListEP7CEntityf, bool, CEntity* pEntity, float dist);
    DECL_FASTCALL_SIMPLE(InsertObjectIntoSortedList, _ZN18CVisibilityPlugins26InsertObjectIntoSortedListEPvfPFvS0_fE, bool, void* pObj, float dist, RenderFunction fn);
    DECL_FASTCALL_SIMPLE(InsertAtomicIntoReallyDrawLastList, _ZN18CVisibilityPlugins34InsertAtomicIntoReallyDrawLastListEP8RpAtomicf, bool, RpAtomic* pAtomic, float dist);
    DECL_FASTCALL_SIMPLE(RenderAlphaAtomics, _ZN18CVisibilityPlugins18RenderAlphaAtomicsEv, void);
    DECL_FASTCALL_SIMPLE(RenderOrderedList, _ZN18CVisibilityPlugins17RenderOrderedListER9CLinkListINS_15AlphaObjectInfoEE, void, CLinkList<AlphaObjectInfo>* list);
    DECL_FASTCALL_SIMPLE(RenderBoatAlphaAtomics, _ZN18CVisibilityPlugins22RenderBoatAlphaAtomicsEv, void);
    DECL_FASTCALL_SIMPLE(RenderFadingEntities, _ZN18CVisibilityPlugins20RenderFadingEntitiesEv, void);
    DECL_FASTCALL_SIMPLE(RenderFadingUnderwaterEntities, _ZN18CVisibilityPlugins30RenderFadingUnderwaterEntitiesEv, void);
    DECL_FASTCALL_SIMPLE(RenderReallyDrawLastObjects, _ZN18CVisibilityPlugins27RenderReallyDrawLastObjectsEv, void);
    DECL_FASTCALL_SIMPLE(GetDistanceSquaredFromCamera1, _ZN18CVisibilityPlugins28GetDistanceSquaredFromCameraEP5RwV3d, float, RwV3d* pVec);

    // Static values
    DECL_VALUE_PLT_I32(ms_atomicPluginOffset, BYBIT(0x6797BC, 0x850F80)); // RwInt32
    DECL_VALUE_PLT_I32(ms_framePluginOffset, BYBIT(0x676EBC, 0x84BDB8)); // RwInt32
    DECL_VALUE_PLT_I32(ms_clumpPluginOffset, BYBIT(0x678BAC, 0x84F780)); // RwInt32
    DECL_OBJECT_ADDR(RpAtomicCallBackRender, ms_defaultRenderer, BYBIT(0xA83F68, 0xD28610));  // no .got slot: addressed PC-relatively
    DECL_OBJECT_PLT(RwCamera*, ms_pCamera, BYBIT(0x6777F0, 0x84D008));
    DECL_OBJECT_PLT(RwV3d*, ms_pCameraPosn, BYBIT(0x67653C, 0x84AAD0));
    DECL_OBJECT_PLT(CLinkList<AlphaObjectInfo>, m_alphaList, BYBIT(0x676454, 0x84A900));
    DECL_OBJECT_PLT(CLinkList<AlphaObjectInfo>, m_alphaBoatAtomicList, BYBIT(0x676908, 0x84B260));
    DECL_OBJECT_PLT(CLinkList<AlphaObjectInfo>, m_alphaEntityList, BYBIT(0x677D68, 0x84DAF0));
    DECL_OBJECT_PLT(CLinkList<AlphaObjectInfo>, m_alphaUnderwaterEntityList, BYBIT(0x675F90, 0x849F90));
    DECL_OBJECT_PLT(CLinkList<AlphaObjectInfo>, m_alphaReallyDrawLastList, BYBIT(0x6799D8, 0x8513C8));
    DECL_VALUE_PLT_FLT(ms_vehicleLod0RenderMultiPassDist, BYBIT(0x6791EC, 0x8503F8));
    DECL_VALUE_PLT_FLT(ms_vehicleLod0Dist, BYBIT(0x677650, 0x84CCD0));
    DECL_VALUE_PLT_FLT(ms_vehicleLod1Dist, BYBIT(0x676DB0, 0x84BBA8));
    DECL_VALUE_PLT_FLT(ms_bigVehicleLod0Dist, BYBIT(0x675FFC, 0x84A068));
    DECL_VALUE_PLT_FLT(ms_pedLodDist, BYBIT(0x676210, 0x84A480));
    DECL_VALUE_PLT_FLT(ms_pedFadeDist, BYBIT(0x678AB4, 0x84F590));
    DECL_VALUE_PLT_FLT(ms_cullCompsDist, BYBIT(0x678E40, 0x84FCA8));
    DECL_VALUE_PLT_FLT(ms_cullBigCompsDist, BYBIT(0x679060, 0x8500E8));
    DECL_OBJECT_PLT(CLinkList<CPed *>, ms_weaponPedsForPC, BYBIT(0x679CF8, 0x851A08));
DECL_CLASS_END()

#define ms_atomicPluginOffset ms_atomicPluginOffset()
#define ms_framePluginOffset ms_framePluginOffset()
#define ms_clumpPluginOffset ms_clumpPluginOffset()
#define ms_defaultRenderer ms_defaultRenderer()
#define ms_pCamera ms_pCamera()
#define ms_pCameraPosn ms_pCameraPosn()
#define m_alphaList m_alphaList()
#define m_alphaBoatAtomicList m_alphaBoatAtomicList()
#define m_alphaEntityList m_alphaEntityList()
#define m_alphaUnderwaterEntityList m_alphaUnderwaterEntityList()
#define m_alphaReallyDrawLastList m_alphaReallyDrawLastList()
#define ms_vehicleLod0RenderMultiPassDist ms_vehicleLod0RenderMultiPassDist()
#define ms_vehicleLod0Dist ms_vehicleLod0Dist()
#define ms_vehicleLod1Dist ms_vehicleLod1Dist()
#define ms_bigVehicleLod0Dist ms_bigVehicleLod0Dist()
#define ms_pedLodDist ms_pedLodDist()
#define ms_pedFadeDist ms_pedFadeDist()
#define ms_cullCompsDist ms_cullCompsDist()
#define ms_cullBigCompsDist ms_cullBigCompsDist()
#define ms_weaponPedsForPC ms_weaponPedsForPC()

#endif // __AML_PSDK_SAVISIBILITYPLUGINS_H
