#ifndef __AML_PSDK_SAINTERIOR_H
#define __AML_PSDK_SAINTERIOR_H

#include "Furniture.h"
#include <aml-psdk/game_sa/base/Matrix.h>
#include <aml-psdk/gta_base/Rect.h>

struct CEntity;
struct CPed;
struct CEntryExit;
struct Interior_c;
struct InteriorGroup_c;
struct InteriorEffectInfo_t;
struct C2dEffect;

DECL_CLASS(CInteriorAttr)
    // Member values
    u8 m_type;
    i8 m_group;
    u8 m_width;
    u8 m_depth;
    u8 m_height;
    i8 m_door;
    i8 m_lDoorStart;
    i8 m_lDoorEnd;
    i8 m_rDoorStart;
    i8 m_rDoorEnd;
    i8 m_tDoorStart;
    i8 m_tDoorEnd;
    i8 m_lWindowStart;
    i8 m_lWindowEnd;
    i8 m_rWindowStart;
    i8 m_rWindowEnd;
    i8 m_tWindowStart;
    i8 m_tWindowEnd;
    i8 m_noGoLeft[3];
    i8 m_noGoBottom[3];
    i8 m_noGoWidth[3];
    i8 m_noGoDepth[3];
    u8 m_seed;
    u8 m_status;
    float m_rot;
DECL_CLASS_END()
CHECKSIZE(CInteriorAttr, 0x24, 0x24);

DECL_CLASS(GotoPt_t)
    // Member values
    i8 tileX;
    i8 tileY;
    i8 link1;
    i8 link2;
    RwV3d pos;
DECL_CLASS_END()
CHECKSIZE(GotoPt_t, 0x10, 0x10);

DECL_CLASS(InteriorInfo_t)
    // Member values
    i8 type;
    u8 beingUsed;
    RwV3d pos;
    RwV3d dir;
    CEntity* pNoCollisionEntity;
DECL_CLASS_END()
CHECKSIZE(InteriorInfo_t, 0x20, 0x28);

DECL_CLASS(StealableInfo_t)
    // Member values
    CEntity* pEntity;
    i32 modelIndex;
    i32 interiorId;
    CVector pos;
    u8 isStolen;
DECL_CLASS_END()
CHECKSIZE(StealableInfo_t, 0x1C, 0x20);

DECL_CLASS_BASED(Interior_c, ListItem_c)
    // Member functions
    DECL_CTORCALL(Interior_c, _ZN10Interior_cC2Ev);
    DECL_DTORCALL(Interior_c, _ZN10Interior_cD2Ev);
    DECL_THISCALL_HEAD(Init, _ZN10Interior_c4InitEP5RwV3d, i32, RwV3d* pos)
    DECL_THISCALL_TAIL(Init, pos)
    DECL_THISCALL_SIMPLE(Exit, _ZN10Interior_c4ExitEv, void);
    DECL_THISCALL_HEAD(GetFurnitureEntity, _ZN10Interior_c18GetFurnitureEntityEP7CEntity, FurnitureEntity_c*, CEntity* pEntity)
    DECL_THISCALL_TAIL(GetFurnitureEntity, pEntity)
    DECL_THISCALL_HEAD(GetBoundingBox, _ZN10Interior_c14GetBoundingBoxEP17FurnitureEntity_cP7CVector, u8, FurnitureEntity_c* pFurnitureEntity, CVector* pCorner)
    DECL_THISCALL_TAIL(GetBoundingBox, pFurnitureEntity, pCorner)
    DECL_THISCALL_HEAD(FindBoundingBox, _ZN10Interior_c15FindBoundingBoxEiiPiS0_S0_S0_S0_, void, i32 x, i32 y, i32* minX, i32* maxX, i32* minY, i32* maxY, i32* tileInfo)
    DECL_THISCALL_TAIL(FindBoundingBox, x, y, minX, maxX, minY, maxY, tileInfo)
    DECL_THISCALL_HEAD(IsPtInside, _ZN10Interior_c10IsPtInsideEP5RwV3dfff, u8, RwV3d* pos, float widthBias, float depthBias, float heightBias)
    DECL_THISCALL_TAIL(IsPtInside, pos, widthBias, depthBias, heightBias)
    DECL_THISCALL_HEAD(CalcMatrix, _ZN10Interior_c10CalcMatrixEP5RwV3d, void, RwV3d* pos)
    DECL_THISCALL_TAIL(CalcMatrix, pos)
    DECL_THISCALL_SIMPLE(CalcExitPts, _ZN10Interior_c11CalcExitPtsEv, void);
    DECL_THISCALL_SIMPLE(IsVisible, _ZN10Interior_c9IsVisibleEv, u8);
    DECL_THISCALL_SIMPLE(Furnish, _ZN10Interior_c7FurnishEv, void);
    DECL_THISCALL_SIMPLE(Unfurnish, _ZN10Interior_c9UnfurnishEv, void);
    DECL_THISCALL_HEAD(PlaceFurniture, _ZN10Interior_c14PlaceFurnitureEP11Furniture_ciifiiPiS2_h, CEntity*, Furniture_c* pFurn, i32 x, i32 y, float z, i32 heightInfo, i32 dir, i32* w, i32* d, u8 force)
    DECL_THISCALL_TAIL(PlaceFurniture, pFurn, x, y, z, heightInfo, dir, w, d, force)
    DECL_THISCALL_HEAD(PlaceFurnitureOnWall, _ZN10Interior_c20PlaceFurnitureOnWallEiiifiiiiPiS0_S0_S0_S0_S0_, CEntity*, i32 interior, i32 subGroup, i32 type, float z, i32 heightInfo, i32 wallId, i32 pos, i32 offset, i32* retWallId, i32* retPos, i32* x, i32* y, i32* w, i32* d)
    DECL_THISCALL_TAIL(PlaceFurnitureOnWall, interior, subGroup, type, z, heightInfo, wallId, pos, offset, retWallId, retPos, x, y, w, d)
    DECL_THISCALL_HEAD(PlaceFurnitureInCorner, _ZN10Interior_c22PlaceFurnitureInCornerEiiifiiiPiS0_S0_S0_S0_, CEntity*, i32 interior, i32 subGroup, i32 type, float z, i32 heightInfo, i32 wallId, i32 offset, i32* retWallId, i32* x, i32* y, i32* w, i32* d)
    DECL_THISCALL_TAIL(PlaceFurnitureInCorner, interior, subGroup, type, z, heightInfo, wallId, offset, retWallId, x, y, w, d)
    DECL_THISCALL_HEAD(PlaceObject, _ZN10Interior_c11PlaceObjectEhP11Furniture_cffff, CEntity*, u8 isStealable, Furniture_c* pFurn, float x, float y, float z, float rot)
    DECL_THISCALL_TAIL(PlaceObject, isStealable, pFurn, x, y, z, rot)
    DECL_THISCALL_SIMPLE(ResetTiles, _ZN10Interior_c10ResetTilesEv, void);
    DECL_THISCALL_HEAD(CheckTilesEmpty, _ZN10Interior_c15CheckTilesEmptyEiiiih, u8, i32 x, i32 y, i32 w, i32 d, u8 canPlaceOnWindow)
    DECL_THISCALL_TAIL(CheckTilesEmpty, x, y, w, d, canPlaceOnWindow)
    DECL_THISCALL_HEAD(SetTilesStatus, _ZN10Interior_c14SetTilesStatusEiiiiih, void, i32 x, i32 y, i32 w, i32 d, i32 status, u8 force)
    DECL_THISCALL_TAIL(SetTilesStatus, x, y, w, d, status, force)
    DECL_THISCALL_HEAD(SetCornerTiles, _ZN10Interior_c14SetCornerTilesEiiih, void, i32 wallId, i32 size, i32 status, u8 force)
    DECL_THISCALL_TAIL(SetCornerTiles, wallId, size, status, force)
    DECL_THISCALL_HEAD(GetTileStatus, _ZN10Interior_c13GetTileStatusEii, i32, i32 x, i32 y)
    DECL_THISCALL_TAIL(GetTileStatus, x, y)
    DECL_THISCALL_HEAD(GetNumEmptyTiles, _ZN10Interior_c16GetNumEmptyTilesEiiii, i32, i32 x, i32 y, i32 dir, i32 size)
    DECL_THISCALL_TAIL(GetNumEmptyTiles, x, y, dir, size)
    DECL_THISCALL_HEAD(FindFirstEmptyTile, _ZN10Interior_c18FindFirstEmptyTileEiii, i32, i32 x, i32 y, i32 dir)
    DECL_THISCALL_TAIL(FindFirstEmptyTile, x, y, dir)
    DECL_THISCALL_HEAD(GetRandomTile, _ZN10Interior_c13GetRandomTileEiPiS0_, void, i32 status, i32* x, i32* y)
    DECL_THISCALL_TAIL(GetRandomTile, status, x, y)
    DECL_THISCALL_HEAD(GetTileCentre, _ZN10Interior_c13GetTileCentreEffP5RwV3d, void, float x, float y, RwV3d* centre)
    DECL_THISCALL_TAIL(GetTileCentre, x, y, centre)
    DECL_THISCALL_HEAD(FindEmptyTiles, _ZN10Interior_c14FindEmptyTilesEiiPiS0_, u8, i32 w, i32 h, i32* x, i32* y)
    DECL_THISCALL_TAIL(FindEmptyTiles, w, h, x, y)
    DECL_THISCALL_HEAD(AddGotoPt, _ZN10Interior_c9AddGotoPtEiiff, void, i32 tileX, i32 tileY, float offsetX, float offsetY)
    DECL_THISCALL_TAIL(AddGotoPt, tileX, tileY, offsetX, offsetY)
    DECL_THISCALL_HEAD(AddInteriorInfo, _ZN10Interior_c15AddInteriorInfoEiffiP7CEntity, u8, i32 type, float tileX, float tileY, i32 dir, CEntity* pNoCollisionEntity)
    DECL_THISCALL_TAIL(AddInteriorInfo, type, tileX, tileY, dir, pNoCollisionEntity)
    DECL_THISCALL_SIMPLE(AddPickups, _ZN10Interior_c10AddPickupsEv, void);
    DECL_THISCALL_HEAD(FurnishShop, _ZN10Interior_c11FurnishShopEi, void, i32 subType)
    DECL_THISCALL_TAIL(FurnishShop, subType)
    DECL_THISCALL_HEAD(Shop_PlaceCounter, _ZN10Interior_c17Shop_PlaceCounterEh, i32, u8 onLeft)
    DECL_THISCALL_TAIL(Shop_PlaceCounter, onLeft)
    DECL_THISCALL_SIMPLE(Shop_PlaceFixedUnits, _ZN10Interior_c20Shop_PlaceFixedUnitsEv, void);
    DECL_THISCALL_SIMPLE(Shop_FurnishEdges, _ZN10Interior_c17Shop_FurnishEdgesEv, void);
    DECL_THISCALL_SIMPLE(Shop_GetRandomUnitType, _ZN10Interior_c22Shop_GetRandomUnitTypeEv, i32);
    DECL_THISCALL_HEAD(Shop_PlaceEdgeUnits, _ZN10Interior_c19Shop_PlaceEdgeUnitsEiiii, i32, i32 type, i32 x, i32 y, i32 dir)
    DECL_THISCALL_TAIL(Shop_PlaceEdgeUnits, type, x, y, dir)
    DECL_THISCALL_HEAD(Shop_Place3PieceUnit, _ZN10Interior_c20Shop_Place3PieceUnitEiiiii, u8, i32 type, i32 x, i32 y, i32 dir, i32 len)
    DECL_THISCALL_TAIL(Shop_Place3PieceUnit, type, x, y, dir, len)
    DECL_THISCALL_SIMPLE(Shop_FurnishAisles, _ZN10Interior_c18Shop_FurnishAislesEv, void);
    DECL_THISCALL_SIMPLE(Shop_FurnishCeiling, _ZN10Interior_c19Shop_FurnishCeilingEv, void);
    DECL_THISCALL_HEAD(Shop_AddShelfInfo, _ZN10Interior_c17Shop_AddShelfInfoEiii, void, i32 tileX, i32 tileY, i32 dir)
    DECL_THISCALL_TAIL(Shop_AddShelfInfo, tileX, tileY, dir)
    DECL_THISCALL_SIMPLE(FurnishOffice, _ZN10Interior_c13FurnishOfficeEv, void);
    DECL_THISCALL_SIMPLE(Office_FurnishEdges, _ZN10Interior_c19Office_FurnishEdgesEv, void);
    DECL_THISCALL_SIMPLE(Office_FurnishCenter, _ZN10Interior_c20Office_FurnishCenterEv, void);
    DECL_THISCALL_HEAD(Office_PlaceEdgeDesks, _ZN10Interior_c21Office_PlaceEdgeDesksEiiiii, i32, i32 type, i32 x, i32 y, i32 dir, i32 wall)
    DECL_THISCALL_TAIL(Office_PlaceEdgeDesks, type, x, y, dir, wall)
    DECL_THISCALL_HEAD(Office_PlaceEdgeFillers, _ZN10Interior_c23Office_PlaceEdgeFillersEiiiii, i32, i32 type, i32 x, i32 y, i32 dir, i32 wall)
    DECL_THISCALL_TAIL(Office_PlaceEdgeFillers, type, x, y, dir, wall)
    DECL_THISCALL_HEAD(Office_PlaceDeskQuad, _ZN10Interior_c20Office_PlaceDeskQuadEiiii, i32, i32 formation, i32 tileX, i32 tileY, i32 type)
    DECL_THISCALL_TAIL(Office_PlaceDeskQuad, formation, tileX, tileY, type)
    DECL_THISCALL_HEAD(Office_PlaceDesk, _ZN10Interior_c16Office_PlaceDeskEiiiihi, i32, i32 tileX, i32 tileY, i32 dir, i32 pedChance, u8 lShape, i32 type)
    DECL_THISCALL_TAIL(Office_PlaceDesk, tileX, tileY, dir, pedChance, lShape, type)
    DECL_THISCALL_SIMPLE(FurnishLounge, _ZN10Interior_c13FurnishLoungeEv, void);
    DECL_THISCALL_HEAD(Lounge_AddTV, _ZN10Interior_c12Lounge_AddTVEiiii, void, i32 wallId, i32 x, i32 y, i32 d)
    DECL_THISCALL_TAIL(Lounge_AddTV, wallId, x, y, d)
    DECL_THISCALL_HEAD(Lounge_AddHifi, _ZN10Interior_c14Lounge_AddHifiEiiii, void, i32 wallId, i32 x, i32 y, i32 d)
    DECL_THISCALL_TAIL(Lounge_AddHifi, wallId, x, y, d)
    DECL_THISCALL_HEAD(Lounge_AddChairInfo, _ZN10Interior_c19Lounge_AddChairInfoEiiP7CEntity, void, i32 wallId, i32 pos, CEntity* pChairEntity)
    DECL_THISCALL_TAIL(Lounge_AddChairInfo, wallId, pos, pChairEntity)
    DECL_THISCALL_HEAD(Lounge_AddSofaInfo, _ZN10Interior_c18Lounge_AddSofaInfoEiiP7CEntity, void, i32 wallId, i32 pos, CEntity* pSofaEntity)
    DECL_THISCALL_TAIL(Lounge_AddSofaInfo, wallId, pos, pSofaEntity)
    DECL_THISCALL_SIMPLE(FurnishKitchen, _ZN10Interior_c14FurnishKitchenEv, void);
    DECL_THISCALL_SIMPLE(Kitchen_FurnishEdges, _ZN10Interior_c20Kitchen_FurnishEdgesEv, void);
    DECL_THISCALL_SIMPLE(FurnishBedroom, _ZN10Interior_c14FurnishBedroomEv, void);
    DECL_THISCALL_HEAD(Bedroom_AddTableItem, _ZN10Interior_c20Bedroom_AddTableItemEiiiiii, void, i32 interior, i32 subGroup, i32 wallId, i32 x, i32 y, i32 d)
    DECL_THISCALL_TAIL(Bedroom_AddTableItem, interior, subGroup, wallId, x, y, d)

    // Member values
    i32 m_interiorId;
    InteriorGroup_c* m_pInteriorGroup;
    i32 m_areaCode;
    CInteriorAttr* m_box;
    RwMatrix m_mat;
    float m_distSq;
    List_c m_furnitureEntityList;
    u8 m_tiles[30][30];
    CNodeAddress m_exitAddr;
    CNodeAddress m_doorAddr;
    RwV3d m_exitPos;
    RwV3d m_doorPos;
    i8 m_numGotoPts;
    i8 m_numInteriorInfos;
    GotoPt_t m_gotoPts[16];
    GotoPt_t m_exitPts[8];
    InteriorInfo_t m_interiorInfos[16];
    i8 m_shopSubType;
    i8 m_style;
    i8 m_style2;
DECL_CLASS_END()
CHECKSIZE(Interior_c, 0x794, 0x840);

DECL_CLASS_BASED(InteriorGroup_c, ListItem_c)
    // Member functions
    DECL_THISCALL_HEAD(Init, _ZN15InteriorGroup_c4InitEP7CEntityi, void, CEntity* pEntity, i32 groupId)
    DECL_THISCALL_TAIL(Init, pEntity, groupId)
    DECL_THISCALL_SIMPLE(Exit, _ZN15InteriorGroup_c4ExitEv, void);
    DECL_THISCALL_SIMPLE(Update, _ZN15InteriorGroup_c6UpdateEv, void);
    DECL_THISCALL_HEAD(AddInterior, _ZN15InteriorGroup_c11AddInteriorEP10Interior_c, void, Interior_c* pInterior)
    DECL_THISCALL_TAIL(AddInterior, pInterior)
    DECL_THISCALL_HEAD(RemoveInterior, _ZN15InteriorGroup_c14RemoveInteriorEP10Interior_c, u8, Interior_c* pInterior)
    DECL_THISCALL_TAIL(RemoveInterior, pInterior)
    DECL_THISCALL_SIMPLE(GetRandomInterior, _ZN15InteriorGroup_c17GetRandomInteriorEv, Interior_c*);
    DECL_THISCALL_HEAD(GetNumInteriorInfos, _ZN15InteriorGroup_c19GetNumInteriorInfosEi, i32, i32 infoType)
    DECL_THISCALL_TAIL(GetNumInteriorInfos, infoType)
    DECL_THISCALL_HEAD(FindInteriorInfo, _ZN15InteriorGroup_c16FindInteriorInfoEiPP14InteriorInfo_tPP10Interior_c, u8, i32 infoType, InteriorInfo_t** ppInteriorInfo, Interior_c** ppInterior)
    DECL_THISCALL_TAIL(FindInteriorInfo, infoType, ppInteriorInfo, ppInterior)
    DECL_THISCALL_HEAD(FindClosestInteriorInfo, _ZN15InteriorGroup_c23FindClosestInteriorInfoEi7CVectorfPP14InteriorInfo_tPP10Interior_cPf, u8, i32 infoType, CVector pos, float range, InteriorInfo_t** ppInteriorInfo, Interior_c** ppInterior, float* distSq)
    DECL_THISCALL_TAIL(FindClosestInteriorInfo, infoType, pos, range, ppInteriorInfo, ppInterior, distSq)
    DECL_THISCALL_HEAD(GetPed, _ZN15InteriorGroup_c6GetPedEi, CPed*, i32 id)
    DECL_THISCALL_TAIL(GetPed, id)
    DECL_THISCALL_HEAD(MarkPedForRemoval, _ZN15InteriorGroup_c17MarkPedForRemovalEP4CPed, void, CPed* pPed)
    DECL_THISCALL_TAIL(MarkPedForRemoval, pPed)
    DECL_THISCALL_SIMPLE(GetEntity, _ZN15InteriorGroup_c9GetEntityEv, CEntity*);
    DECL_THISCALL_SIMPLE(GetEntryExitPtr, _ZN15InteriorGroup_c15GetEntryExitPtrEv, CEntryExit*);
    DECL_THISCALL_SIMPLE(Setup, _ZN15InteriorGroup_c5SetupEv, void);
    DECL_THISCALL_SIMPLE(ArePathsLoaded, _ZN15InteriorGroup_c14ArePathsLoadedEv, u8);
    DECL_THISCALL_SIMPLE(SetupPaths, _ZN15InteriorGroup_c10SetupPathsEv, void);
    DECL_THISCALL_SIMPLE(SetupPeds, _ZN15InteriorGroup_c9SetupPedsEv, void);
    DECL_THISCALL_SIMPLE(SetupHousePeds, _ZN15InteriorGroup_c14SetupHousePedsEv, void);
    DECL_THISCALL_SIMPLE(SetupOfficePeds, _ZN15InteriorGroup_c15SetupOfficePedsEv, void);
    DECL_THISCALL_SIMPLE(SetupShopPeds, _ZN15InteriorGroup_c13SetupShopPedsEv, void);
    DECL_THISCALL_HEAD(RemovePed, _ZN15InteriorGroup_c9RemovePedEP4CPed, void, CPed* pPed)
    DECL_THISCALL_TAIL(RemovePed, pPed)
    DECL_THISCALL_SIMPLE(UpdatePeds, _ZN15InteriorGroup_c10UpdatePedsEv, void);
    DECL_THISCALL_SIMPLE(UpdateHousePeds, _ZN15InteriorGroup_c15UpdateHousePedsEv, void);
    DECL_THISCALL_SIMPLE(UpdateShopPeds, _ZN15InteriorGroup_c14UpdateShopPedsEv, void);
    DECL_THISCALL_SIMPLE(UpdateOfficePeds, _ZN15InteriorGroup_c16UpdateOfficePedsEv, void);
    DECL_THISCALL_SIMPLE(ReferenceAnims, _ZN15InteriorGroup_c14ReferenceAnimsEv, void);
    DECL_THISCALL_SIMPLE(DereferenceAnims, _ZN15InteriorGroup_c16DereferenceAnimsEv, void);
    DECL_THISCALL_HEAD(ContainsInteriorType, _ZN15InteriorGroup_c20ContainsInteriorTypeEi, u8, i32 interiorType)
    DECL_THISCALL_TAIL(ContainsInteriorType, interiorType)
    DECL_THISCALL_SIMPLE(CalcIsVisible, _ZN15InteriorGroup_c13CalcIsVisibleEv, void);

    // Member values
    CEntity* m_pEntity;
    i8 m_uniqueId;
    i8 m_groupId;
    i8 m_groupType;
    i8 m_numInteriors;
    Interior_c* m_pInteriors[8];
    CEntryExit* m_pEntryExit;
    u8 m_isVisible;
    u8 m_lastIsVisible;
    i8 m_numPeds;
    CPed* m_pPeds[16];
    CPed* m_pPedsToRemove[16];
    u8 m_pathsSetup;
    u8 m_pedsSetup;
    u8 m_animsReferenced;
DECL_CLASS_END()
CHECKSIZE(InteriorGroup_c, 0xBC, 0x178);

DECL_CLASS(InteriorManager_c)
    // Member functions
    DECL_CTORCALL(InteriorManager_c, _ZN17InteriorManager_cC2Ev);
    DECL_DTORCALL(InteriorManager_c, _ZN17InteriorManager_cD2Ev);
    DECL_THISCALL_SIMPLE(Init, _ZN17InteriorManager_c4InitEv, u8);
    DECL_THISCALL_SIMPLE(Exit, _ZN17InteriorManager_c4ExitEv, void);
    DECL_THISCALL_SIMPLE(Update, _ZN17InteriorManager_c6UpdateEv, bool);
    DECL_THISCALL_HEAD(Freeze, _ZN17InteriorManager_c6FreezeEh, void, u8 freeze)
    DECL_THISCALL_TAIL(Freeze, freeze)
    DECL_THISCALL_HEAD(Activate, _ZN17InteriorManager_c8ActivateEh, void, u8 active)
    DECL_THISCALL_TAIL(Activate, active)
    DECL_THISCALL_HEAD(ActivatePeds, _ZN17InteriorManager_c12ActivatePedsEh, void, u8 active)
    DECL_THISCALL_TAIL(ActivatePeds, active)
    DECL_THISCALL_HEAD(GetBoundingBox, _ZN17InteriorManager_c14GetBoundingBoxEP7CEntityP7CVector, u8, CEntity* pEntity, CVector* pCorners)
    DECL_THISCALL_TAIL(GetBoundingBox, pEntity, pCorners)
    DECL_THISCALL_HEAD(AreAnimsLoaded, _ZN17InteriorManager_c14AreAnimsLoadedEi, u8, i32 groupType)
    DECL_THISCALL_TAIL(AreAnimsLoaded, groupType)
    DECL_THISCALL_HEAD(SetEntryExitPtr, _ZN17InteriorManager_c15SetEntryExitPtrEP10CEntryExit, void, CEntryExit* pEntryExit)
    DECL_THISCALL_TAIL(SetEntryExitPtr, pEntryExit)
    DECL_THISCALL_HEAD(GetPedsInteriorGroup, _ZN17InteriorManager_c20GetPedsInteriorGroupEP4CPed, InteriorGroup_c*, CPed* pPed)
    DECL_THISCALL_TAIL(GetPedsInteriorGroup, pPed)
    DECL_THISCALL_HEAD(GetPedsInterior, _ZN17InteriorManager_c15GetPedsInteriorEP4CPed, Interior_c*, CPed* pPed)
    DECL_THISCALL_TAIL(GetPedsInterior, pPed)
    DECL_THISCALL_HEAD(GetVectorsInterior, _ZN17InteriorManager_c18GetVectorsInteriorEP7CVector, Interior_c*, CVector* pVector)
    DECL_THISCALL_TAIL(GetVectorsInterior, pVector)
    DECL_THISCALL_HEAD(IsGroupActive, _ZN17InteriorManager_c13IsGroupActiveEi, u8, i32 groupId)
    DECL_THISCALL_TAIL(IsGroupActive, groupId)
    DECL_THISCALL_HEAD(HasInteriorHadStealDataSetup, _ZN17InteriorManager_c28HasInteriorHadStealDataSetupEP10Interior_c, u8, Interior_c* pInterior)
    DECL_THISCALL_TAIL(HasInteriorHadStealDataSetup, pInterior)
    DECL_THISCALL_HEAD(FindStealableObjectId, _ZN17InteriorManager_c21FindStealableObjectIdEii7CVector, i32, i32 arg1, i32 arg2, CVector arg3)
    DECL_THISCALL_TAIL(FindStealableObjectId, arg1, arg2, arg3)
    DECL_THISCALL_NAMED_HEAD(FindStealableObjectId2, FindStealableObjectId, _ZN17InteriorManager_c21FindStealableObjectIdEP7CEntity, i32, CEntity* pEntity)
    DECL_THISCALL_TAIL(FindStealableObjectId2, pEntity)
    DECL_THISCALL_HEAD(SetStealableObjectStolen, _ZN17InteriorManager_c24SetStealableObjectStolenEP7CEntityh, void, CEntity* pEntity, u8 isStolen)
    DECL_THISCALL_TAIL(SetStealableObjectStolen, pEntity, isStolen)
    DECL_THISCALL_SIMPLE(GetInteriorFromPool, _ZN17InteriorManager_c19GetInteriorFromPoolEv, Interior_c*);
    DECL_THISCALL_HEAD(ReturnInteriorToPool, _ZN17InteriorManager_c20ReturnInteriorToPoolEP10Interior_c, void, Interior_c* pInterior)
    DECL_THISCALL_TAIL(ReturnInteriorToPool, pInterior)
    DECL_THISCALL_HEAD(GetVisibleEffects, _ZN17InteriorManager_c17GetVisibleEffectsEP20InteriorEffectInfo_ti, i32, InteriorEffectInfo_t* pInteriorEffectInfos, i32 maxSize)
    DECL_THISCALL_TAIL(GetVisibleEffects, pInteriorEffectInfos, maxSize)
    DECL_THISCALL_HEAD(IsInteriorEffectVisible, _ZN17InteriorManager_c23IsInteriorEffectVisibleEP9C2dEffectP7CEntity, u8, C2dEffect* pEffect, CEntity* pEntity)
    DECL_THISCALL_TAIL(IsInteriorEffectVisible, pEffect, pEntity)
    DECL_THISCALL_HEAD(AddSameGroupEffectInfos, _ZN17InteriorManager_c23AddSameGroupEffectInfosEP20InteriorEffectInfo_ti, void, InteriorEffectInfo_t* pInteriorEffectInfo, i32 maxSize)
    DECL_THISCALL_TAIL(AddSameGroupEffectInfos, pInteriorEffectInfo, maxSize)
    DECL_THISCALL_HEAD(PruneVisibleEffects, _ZN17InteriorManager_c19PruneVisibleEffectsEP20InteriorEffectInfo_tiif, void, InteriorEffectInfo_t* pInteriorEffectInfos, i32 numInfos, i32 reqdNumInfos, float maxDist)
    DECL_THISCALL_TAIL(PruneVisibleEffects, pInteriorEffectInfos, numInfos, reqdNumInfos, maxDist)

    // Member values
    Interior_c m_interiors[8];
    List_c m_interiorPool;
    InteriorGroup_c m_interiorGroups[8];
    List_c m_interiorGroupList;
    List_c m_interiorGroupPool;
    i32 m_numStealInfosIds;
    i32 m_stealInfoSetupIds[64];
    i32 m_numStealableObjects;
    StealableInfo_t m_stealableInfos[32];
    u8 m_pedsAlive[16];
    CEntryExit* m_pEntryExit;
    CRect m_entryExitRect;
    u8 m_freeze;
    u8 m_active;
    u8 m_activePeds;
    i32 m_timeLastPickupsGenerated;
DECL_CLASS_END()
CHECKSIZE(InteriorManager_c, 0x4758, 0x5340);

DECL_OBJECT_PLT_GLOBAL(InteriorManager_c, g_interiorMan, BYBIT(0x679C7C, 0x851910));

#endif // __AML_PSDK_SAINTERIOR_H
