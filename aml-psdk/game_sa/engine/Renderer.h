#ifndef __AML_PSDK_SARENDERER_H
#define __AML_PSDK_SARENDERER_H

/*
    Plugin-SDK (Grand Theft Auto San Andreas) header file
    Authors: GTA Community. See more here
    https://github.com/DK22Pac/plugin-sdk
    Do not delete this comment block. Respect others' work!
*/

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/gta_base/Vector.h>

struct CEntity;
struct CPhysical;
struct CBaseModelInfo;
struct CPtrList;
struct RwMatrix;

struct tRenderListEntry
{
    CEntity *pEntity;
    float distance;
};
CHECKSIZE(tRenderListEntry, 0x8, 0x10);

enum VisibilityState
{
    ENTITY_INVISIBLE = 0,
    ENTITY_VISIBLE = 1,
    ENTITY_OFFSCREEN = 2,
    ENTITY_STREAM_MODEL = 3,
};

DECL_CLASS(CRenderer)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(Init, _ZN9CRenderer4InitEv, void);
    DECL_FASTCALL_SIMPLE(Shutdown, _ZN9CRenderer8ShutdownEv, void);
    DECL_FASTCALL_SIMPLE(ConstructReflectionList, _ZN9CRenderer23ConstructReflectionListEv, void);
    DECL_FASTCALL_SIMPLE(ConstructRenderList, _ZN9CRenderer19ConstructRenderListEv, void);
    DECL_FASTCALL_SIMPLE(PreRender, _ZN9CRenderer9PreRenderEv, void);
    DECL_FASTCALL_SIMPLE(RenderRoads, _ZN9CRenderer11RenderRoadsEv, void);
    DECL_FASTCALL_SIMPLE(RenderEverythingBarRoads, _ZN9CRenderer24RenderEverythingBarRoadsEv, void);
    DECL_FASTCALL_SIMPLE(RenderFadingInEntities, _ZN9CRenderer22RenderFadingInEntitiesEv, void);
    DECL_FASTCALL_SIMPLE(RenderFadingInUnderwaterEntities, _ZN9CRenderer32RenderFadingInUnderwaterEntitiesEv, void);
    DECL_FASTCALL_SIMPLE(RenderFirstPersonVehicle, _ZN9CRenderer24RenderFirstPersonVehicleEv, void);
    DECL_FASTCALL_SIMPLE(RenderOneRoad, _ZN9CRenderer13RenderOneRoadEP7CEntity, void, CEntity* entity);
    DECL_FASTCALL_SIMPLE(RenderOneNonRoad, _ZN9CRenderer16RenderOneNonRoadEP7CEntity, void, CEntity* entity);
    DECL_FASTCALL_SIMPLE(RemoveVehiclePedLights, _ZN9CRenderer22RemoveVehiclePedLightsEP9CPhysicalb, void, CPhysical* entity, bool bLighting);
    DECL_FASTCALL_SIMPLE(RequestObjectsInDirection, _ZN9CRenderer25RequestObjectsInDirectionERK7CVectorfi, void, CVector const& posn, float angle, i32 modelRequestFlags);
    DECL_FASTCALL_SIMPLE(RequestObjectsInFrustum, _ZN9CRenderer23RequestObjectsInFrustumEP11RwMatrixTagi, void, RwMatrix* transformMat, i32 modelRequestFlags);
    DECL_FASTCALL_SIMPLE(GetObjectsInFrustum, _ZN9CRenderer19GetObjectsInFrustumEPP7CEntityfP11RwMatrixTag, i32, CEntity** outEntities, float distance, RwMatrix* transformMat);
    DECL_FASTCALL_SIMPLE(SetupEntityVisibility, _ZN9CRenderer21SetupEntityVisibilityEP7CEntityRf, VisibilityState, CEntity* entity, float& outDistance);
    DECL_FASTCALL_SIMPLE(SetupBigBuildingVisibility, _ZN9CRenderer26SetupBigBuildingVisibilityEP7CEntityRf, VisibilityState, CEntity* entity, float& outDistance);
    DECL_FASTCALL_SIMPLE(SetupMapEntityVisibility, _ZN9CRenderer24SetupMapEntityVisibilityEP7CEntityP14CBaseModelInfofb, VisibilityState, CEntity* entity, CBaseModelInfo* modelInfo, float distance, bool bTimeInRange);
    DECL_FASTCALL_SIMPLE(ShouldModelBeStreamed, _ZN9CRenderer21ShouldModelBeStreamedEP7CEntityRK7CVectorf, bool, CEntity* entity, CVector const& origin, float farClip);
    DECL_FASTCALL_SIMPLE(AddEntityToRenderList, _ZN9CRenderer21AddEntityToRenderListEP7CEntityf, void, CEntity* entity, float distance);
    DECL_FASTCALL_SIMPLE(ScanWorld, _ZN9CRenderer9ScanWorldEv, void);
    DECL_FASTCALL_SIMPLE(ScanSectorList, _ZN9CRenderer14ScanSectorListEii, void, i32 sector_x, i32 sector_y);
    DECL_FASTCALL_SIMPLE(ScanSectorList_RequestModels, _ZN9CRenderer28ScanSectorList_RequestModelsEii, void, i32 sector_x, i32 sector_y);
    DECL_FASTCALL_SIMPLE(ScanPtrList_RequestModels, _ZN9CRenderer25ScanPtrList_RequestModelsER8CPtrList, void, CPtrList& ptrList);
    DECL_FASTCALL_SIMPLE(ScanSectorList_ListModels, _ZN9CRenderer25ScanSectorList_ListModelsEii, void, i32 sector_x, i32 sector_y);
    DECL_FASTCALL_SIMPLE(ScanSectorList_ListModelsVisible, _ZN9CRenderer32ScanSectorList_ListModelsVisibleEii, void, i32 sector_x, i32 sector_y);
    DECL_FASTCALL_SIMPLE(ScanBigBuildingList, _ZN9CRenderer19ScanBigBuildingListEii, void, i32 sector_x, i32 sector_y);
    DECL_FASTCALL_SIMPLE(GetLodRenderListBase, _ZN9CRenderer20GetLodRenderListBaseEv, tRenderListEntry*);
    DECL_FASTCALL_SIMPLE(GetLodDontRenderListBase, _ZN9CRenderer24GetLodDontRenderListBaseEv, tRenderListEntry*);
    DECL_FASTCALL_SIMPLE(ResetLodRenderLists, _ZN9CRenderer19ResetLodRenderListsEv, void);
    DECL_FASTCALL_SIMPLE(AddToLodRenderList, _ZN9CRenderer18AddToLodRenderListEP7CEntityf, void, CEntity* entity, float distance);
    DECL_FASTCALL_SIMPLE(AddToLodDontRenderList, _ZN9CRenderer22AddToLodDontRenderListEP7CEntityf, void, CEntity* entity, float distance);
    DECL_FASTCALL_SIMPLE(ProcessLodRenderLists, _ZN9CRenderer21ProcessLodRenderListsEv, void);

    // STATIC values
    DECL_OBJECT_SYM(CVector, ms_vecCameraPosition, _ZN9CRenderer20ms_vecCameraPositionE);
    DECL_OBJECT_SYM(float, ms_fCameraHeading, _ZN9CRenderer17ms_fCameraHeadingE);
    DECL_OBJECT_SYM(float, ms_fFarClipPlane, _ZN9CRenderer16ms_fFarClipPlaneE);
    DECL_OBJECT_SYM(bool, ms_bRenderOutsideTunnels, _ZN9CRenderer24ms_bRenderOutsideTunnelsE);
    DECL_OBJECT_SYM(bool, ms_bRenderTunnels, _ZN9CRenderer17ms_bRenderTunnelsE);
    DECL_OBJECT_SYM(i32, ms_nNoOfVisibleEntities, _ZN9CRenderer23ms_nNoOfVisibleEntitiesE);
    DECL_OBJECT_SYM(i32, ms_nNoOfVisibleLods, _ZN9CRenderer19ms_nNoOfVisibleLodsE);
    DECL_OBJECT_SYM(i32, ms_nNoOfVisibleSuperLods, _ZN9CRenderer24ms_nNoOfVisibleSuperLodsE);
    DECL_OBJECT_SYM(i32, ms_nNoOfInVisibleEntities, _ZN9CRenderer25ms_nNoOfInVisibleEntitiesE);
    DECL_OBJECT_ARRAY_SYM(CEntity*, ms_aVisibleEntityPtrs, _ZN9CRenderer21ms_aVisibleEntityPtrsE);
    DECL_OBJECT_ARRAY_SYM(CEntity*, ms_aVisibleLodPtrs, _ZN9CRenderer18ms_aVisibleLodPtrsE);
    DECL_OBJECT_ARRAY_SYM(CEntity*, ms_aVisibleSuperLodPtrs, _ZN9CRenderer23ms_aVisibleSuperLodPtrsE);
    DECL_OBJECT_ARRAY_SYM(CEntity*, ms_aInVisibleEntityPtrs, _ZN9CRenderer23ms_aInVisibleEntityPtrsE);
    DECL_OBJECT_SYM(bool, m_loadingPriority, _ZN9CRenderer17m_loadingPriorityE);
    DECL_OBJECT_SYM(bool, ms_bInTheSky, _ZN9CRenderer12ms_bInTheSkyE);
    DECL_OBJECT_SYM(CEntity*, m_pFirstPersonVehicle, _ZN9CRenderer21m_pFirstPersonVehicleE);
    DECL_OBJECT_SYM(float, ms_lodDistScale, _ZN9CRenderer15ms_lodDistScaleE);
    DECL_OBJECT_SYM(float, ms_lowLodDistScale, _ZN9CRenderer18ms_lowLodDistScaleE);
    DECL_OBJECT_SYM(tRenderListEntry*, ms_pLodRenderList, _ZN9CRenderer17ms_pLodRenderListE);
    DECL_OBJECT_SYM(tRenderListEntry*, ms_pLodDontRenderList, _ZN9CRenderer21ms_pLodDontRenderListE);
DECL_CLASS_END()

#define ms_vecCameraPosition ms_vecCameraPosition()
#define ms_fCameraHeading ms_fCameraHeading()
#define ms_fFarClipPlane ms_fFarClipPlane()
#define ms_bRenderOutsideTunnels ms_bRenderOutsideTunnels()
#define ms_bRenderTunnels ms_bRenderTunnels()
#define ms_nNoOfVisibleEntities ms_nNoOfVisibleEntities()
#define ms_nNoOfVisibleLods ms_nNoOfVisibleLods()
#define ms_nNoOfVisibleSuperLods ms_nNoOfVisibleSuperLods()
#define ms_nNoOfInVisibleEntities ms_nNoOfInVisibleEntities()
#define ms_aVisibleEntityPtrs ms_aVisibleEntityPtrs()
#define ms_aVisibleLodPtrs ms_aVisibleLodPtrs()
#define ms_aVisibleSuperLodPtrs ms_aVisibleSuperLodPtrs()
#define ms_aInVisibleEntityPtrs ms_aInVisibleEntityPtrs()
#define m_loadingPriority m_loadingPriority()
#define ms_bInTheSky ms_bInTheSky()
#define m_pFirstPersonVehicle m_pFirstPersonVehicle()
#define ms_lodDistScale ms_lodDistScale()
#define ms_lowLodDistScale ms_lowLodDistScale()
#define ms_pLodRenderList ms_pLodRenderList()
#define ms_pLodDontRenderList ms_pLodDontRenderList()

#endif // __AML_PSDK_SARENDERER_H
