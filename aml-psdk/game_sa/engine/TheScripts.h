#ifndef __AML_PSDK_SATHESCRIPTS_H
#define __AML_PSDK_SATHESCRIPTS_H

#include "../plugin.h"
#include "RunningScript.h"
#include "StreamedScripts.h"
#include "ScriptResourceManager.h"
#include "MissionCleanup.h"
#include "Sprite2d.h"

struct CVehicle;
struct CEntity;
struct CObject;
struct CBuilding;
struct FxSystem_c;
struct CCheckpoint;

struct tScriptSphere
{
    u8 bUsed;
    u16 wUniqueID;
    u32 nSphereID;
    CVector vCoords;
    float fRadius;
};
CHECKSIZE(tScriptSphere, 0x18, 0x18);

struct tScriptCheckpoint
{
    u8 bUsed;
    u16 wUniqueID;
    CCheckpoint *m_pCheckpoint;
};
CHECKSIZE(tScriptCheckpoint, 0x08, 0x10);

struct tScriptEffectSystem
{
    u8 bUsed;
    u16 wUniqueID;
    FxSystem_c *m_pFxSystem;
};
CHECKSIZE(tScriptEffectSystem, 0x08, 0x10);

struct tScriptSearchlight
{
    u8 bUsed;
    u8 bClipIfColliding;
    u8 bRenderGroundLight;
    u8 nSearchLightState;
    u16 wUniqueID;
    CVector position;
    CVector target;
    float targetRadius;
    float baseRadius;
    CVector pathCoord1;
    CVector pathCoord2;
    float pathSpeed;
    CEntity *attachedEntity;
    CEntity *followingEntity;
    CObject *tower;
    CObject *housing;
    CObject *bulb;
    CVector targetSpot;
    CVector ellipseForward;
    CVector ellipseSide;
};
CHECKSIZE(tScriptSearchlight, 0x7C, 0x98);

struct tBuildingSwap
{
    CBuilding *m_pCBuilding;
    i32 m_nNewModelIndex;
    i32 m_nOldModelIndex;
};
CHECKSIZE(tBuildingSwap, 0x0C, 0x10);

struct tInvisibilitySetting
{
    CEntity *m_pEntity;
};
CHECKSIZE(tInvisibilitySetting, 0x04, 0x08);

struct tEntityWaitingForScriptBrain
{
    CEntity *m_pEntity;
    i16 m_nScriptBrainIndex;
};
CHECKSIZE(tEntityWaitingForScriptBrain, 0x08, 0x10);

struct tScriptConnectedLodObjects
{
    i32 m_nObject1ID;
    i32 m_nObject2ID;
};
CHECKSIZE(tScriptConnectedLodObjects, 0x08, 0x08);

struct tScriptAttachedAnimGroup
{
    i32 m_nModelID;
    char m_IfpName[16];
};
CHECKSIZE(tScriptAttachedAnimGroup, 0x14, 0x14);

DECL_CLASS(CTheScripts)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(PrintListSizes, _ZN11CTheScripts14PrintListSizesEv, void);
    DECL_FASTCALL_SIMPLE(DrawScriptSpritesAndRectangles, _ZN11CTheScripts30DrawScriptSpritesAndRectanglesEh, void, u8 bDrawBeforeFade);
    DECL_FASTCALL_SIMPLE(WipeLocalVariableMemoryForMissionScript, _ZN11CTheScripts39WipeLocalVariableMemoryForMissionScriptEv, void);
    DECL_FASTCALL_SIMPLE(GetScriptIndexFromPointer, _ZN11CTheScripts25GetScriptIndexFromPointerEP14CRunningScript, u16, CRunningScript* thread);
    DECL_FASTCALL_SIMPLE(StartTestScript, _ZN11CTheScripts15StartTestScriptEv, void);
    DECL_FASTCALL_SIMPLE(DrawDebugSquare, _ZN11CTheScripts15DrawDebugSquareEffff, void, float arg1, float arg2, float arg3, float arg4);
    DECL_FASTCALL_SIMPLE(DrawDebugCube, _ZN11CTheScripts13DrawDebugCubeEffffff, void, float arg1, float arg2, float arg3, float arg4, float arg5, float arg6);
    DECL_FASTCALL_SIMPLE(DrawDebugAngledSquare, _ZN11CTheScripts21DrawDebugAngledSquareEffffffff, void, float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4);
    DECL_FASTCALL_SIMPLE(DrawDebugAngledCube, _ZN11CTheScripts19DrawDebugAngledCubeEffffffffff, void, float arg1, float arg2, float arg3, float arg4, float arg5, float arg6, float arg7, float arg8, float arg9, float arg10);
    DECL_FASTCALL_SIMPLE(ScriptDebugCircle2D, _ZN11CTheScripts19ScriptDebugCircle2DEffffi, void, float x, float y, float width, float height, i32 color);
    DECL_FASTCALL_SIMPLE(ScriptDebugLine3D, _ZN11CTheScripts17ScriptDebugLine3DEffffffjj, void, float arg1, float arg2, float arg3, float arg4, float arg5, float arg6, u32 arg7, u32 arg8);
    DECL_FASTCALL_SIMPLE(RenderTheScriptDebugLines, _ZN11CTheScripts25RenderTheScriptDebugLinesEv, void);
    DECL_FASTCALL_SIMPLE(Save, _ZN11CTheScripts4SaveEv, void);
    DECL_FASTCALL_SIMPLE(SaveAfter, _ZN11CTheScripts9SaveAfterEv, void);
    DECL_FASTCALL_SIMPLE(Load, _ZN11CTheScripts4LoadEv, void);
    DECL_FASTCALL_SIMPLE(LoadAfter, _ZN11CTheScripts9LoadAfterEv, void);
    DECL_FASTCALL_SIMPLE(DoScriptSetupAfterPoolsHaveLoaded, _ZN11CTheScripts33DoScriptSetupAfterPoolsHaveLoadedEv, void);
    DECL_FASTCALL_SIMPLE(ClearSpaceForMissionEntity, _ZN11CTheScripts26ClearSpaceForMissionEntityERK7CVectorP7CEntity, void, CVector const& pos, CEntity* pEntity);
    DECL_FASTCALL_SIMPLE(IsPedStopped, _ZN11CTheScripts12IsPedStoppedEP4CPed, u8, CPed* ped);
    DECL_FASTCALL_SIMPLE(RemoveThisPed, _ZN11CTheScripts13RemoveThisPedEP4CPed, void, CPed* ped);
    DECL_FASTCALL_SIMPLE(CleanUpThisPed, _ZN11CTheScripts14CleanUpThisPedEP4CPed, void, CPed* ped);
    DECL_FASTCALL_SIMPLE(CleanUpThisObject, _ZN11CTheScripts17CleanUpThisObjectEP7CObject, void, CObject* pObject);
    DECL_FASTCALL_SIMPLE(ReadObjectNamesFromScript, _ZN11CTheScripts25ReadObjectNamesFromScriptEv, void);
    DECL_FASTCALL_SIMPLE(UpdateObjectIndices, _ZN11CTheScripts19UpdateObjectIndicesEv, void);
    DECL_FASTCALL_SIMPLE(ReadMultiScriptFileOffsetsFromScript, _ZN11CTheScripts36ReadMultiScriptFileOffsetsFromScriptEv, void);
    DECL_FASTCALL_SIMPLE(GetUniqueScriptThingIndex, _ZN11CTheScripts25GetUniqueScriptThingIndexEih, i32, i32 playergroup, u8 type);
    DECL_FASTCALL_SIMPLE(GetNewUniqueScriptThingIndex, _ZN11CTheScripts28GetNewUniqueScriptThingIndexEih, i32, i32 index, u8 type);
    DECL_FASTCALL_SIMPLE(DrawScriptSpheres, _ZN11CTheScripts17DrawScriptSpheresEv, void);
    DECL_FASTCALL_SIMPLE(AddScriptSphere, _ZN11CTheScripts15AddScriptSphereEj7CVectorf, i32, u32 id, CVector posn, float radius);
    DECL_FASTCALL_SIMPLE(RemoveScriptSphere, _ZN11CTheScripts18RemoveScriptSphereEi, void, i32 index);
    DECL_FASTCALL_SIMPLE(AddScriptEffectSystem, _ZN11CTheScripts21AddScriptEffectSystemEP10FxSystem_c, i32, FxSystem_c* a1);
    DECL_FASTCALL_SIMPLE(RemoveScriptEffectSystem, _ZN11CTheScripts24RemoveScriptEffectSystemEi, void, i32 arg1);
    DECL_FASTCALL_SIMPLE(AddScriptSearchLight, _ZN11CTheScripts20AddScriptSearchLightEfffP7CEntityfffff, i32, float startX, float startY, float startZ, CEntity* entity, float targetX, float targetY, float targetZ, float targetRadius, float baseRadius);
    DECL_FASTCALL_SIMPLE(RemoveScriptSearchLight, _ZN11CTheScripts23RemoveScriptSearchLightEi, void, i32 index);
    DECL_FASTCALL_SIMPLE(IsPointWithinSearchLight, _ZN11CTheScripts24IsPointWithinSearchLightER7CVectori, u8, CVector& pointPosn, i32 index);
    DECL_FASTCALL_SIMPLE(IsEntityWithinSearchLight, _ZN11CTheScripts25IsEntityWithinSearchLightEiP7CEntity, u8, i32 index, CEntity* pEntity);
    DECL_FASTCALL_SIMPLE(IsEntityWithinAnySearchLight, _ZN11CTheScripts28IsEntityWithinAnySearchLightEP7CEntityPi, u8, CEntity* pEntity, i32* pIndex);
    DECL_FASTCALL_SIMPLE(MoveSearchLightBetweenTwoPoints, _ZN11CTheScripts31MoveSearchLightBetweenTwoPointsEifffffff, void, i32 index, float x1, float y1, float z1, float x2, float y2, float z2, float pathSpeed);
    DECL_FASTCALL_SIMPLE(MoveSearchLightToEntity, _ZN11CTheScripts23MoveSearchLightToEntityEiP7CEntityf, void, i32 index, CEntity* pEntity, float pathSpeed);
    DECL_FASTCALL_SIMPLE(MoveSearchLightToPointAndStop, _ZN11CTheScripts29MoveSearchLightToPointAndStopEiffff, void, i32 index, float x, float y, float z, float pathSpeed);
    DECL_FASTCALL_SIMPLE(ProcessAllSearchLights, _ZN11CTheScripts22ProcessAllSearchLightsEv, void);
    DECL_FASTCALL_SIMPLE(RenderAllSearchLights, _ZN11CTheScripts21RenderAllSearchLightsEv, void);
    DECL_FASTCALL_SIMPLE(AttachSearchlightToSearchlightObject, _ZN11CTheScripts36AttachSearchlightToSearchlightObjectEiP7CObjectS1_S1_fff, void, i32 searchlightid, CObject* tower, CObject* housing, CObject* bulb, float offsetX, float offsetY, float offsetZ);
    DECL_FASTCALL_SIMPLE(AddScriptCheckpoint, _ZN11CTheScripts19AddScriptCheckpointEfffffffi, i32, float at_X, float at_Y, float at_Z, float PointTo_X, float PointTo_Y, float PointTo_Z, float radius, i32 type);
    DECL_FASTCALL_SIMPLE(RemoveScriptCheckpoint, _ZN11CTheScripts22RemoveScriptCheckpointEi, void, i32 arg1);
    DECL_FASTCALL_SIMPLE(AddToBuildingSwapArray, _ZN11CTheScripts22AddToBuildingSwapArrayEP9CBuildingii, void, CBuilding* a1, i32 newModelId, i32 oldModelId);
    DECL_FASTCALL_SIMPLE(AddToInvisibilitySwapArray, _ZN11CTheScripts26AddToInvisibilitySwapArrayEP7CEntityb, void, CEntity* a2, bool bVisible);
    DECL_FASTCALL_SIMPLE(UndoBuildingSwaps, _ZN11CTheScripts17UndoBuildingSwapsEv, void);
    DECL_FASTCALL_SIMPLE(UndoEntityInvisibilitySettings, _ZN11CTheScripts30UndoEntityInvisibilitySettingsEv, void);
    DECL_FASTCALL_SIMPLE(ClearAllSuppressedCarModels, _ZN11CTheScripts27ClearAllSuppressedCarModelsEv, void);
    DECL_FASTCALL_SIMPLE(AddToSuppressedCarModelArray, _ZN11CTheScripts28AddToSuppressedCarModelArrayEi, void, i32 arg1);
    DECL_FASTCALL_SIMPLE(RemoveFromSuppressedCarModelArray, _ZN11CTheScripts33RemoveFromSuppressedCarModelArrayEi, void, i32 arg1);
    DECL_FASTCALL_SIMPLE(HasCarModelBeenSuppressed, _ZN11CTheScripts25HasCarModelBeenSuppressedEi, u8, i32 arg1);
    DECL_FASTCALL_SIMPLE(ClearAllVehicleModelsBlockedByScript, _ZN11CTheScripts36ClearAllVehicleModelsBlockedByScriptEv, void);
    DECL_FASTCALL_SIMPLE(AddToVehicleModelsBlockedByScript, _ZN11CTheScripts33AddToVehicleModelsBlockedByScriptEi, void, i32 modelindex);
    DECL_FASTCALL_SIMPLE(RemoveFromVehicleModelsBlockedByScript, _ZN11CTheScripts38RemoveFromVehicleModelsBlockedByScriptEi, void, i32 modelindex);
    DECL_FASTCALL_SIMPLE(HasVehicleModelBeenBlockedByScript, _ZN11CTheScripts34HasVehicleModelBeenBlockedByScriptEi, u8, i32 modelindex);
    DECL_FASTCALL_SIMPLE(InitialiseConnectLodObjects, _ZN11CTheScripts27InitialiseConnectLodObjectsEt, void, u16 a1);
    DECL_FASTCALL_SIMPLE(InitialiseAllConnectLodObjects, _ZN11CTheScripts30InitialiseAllConnectLodObjectsEv, void);
    DECL_FASTCALL_SIMPLE(AddToListOfConnectedLodObjects, _ZN11CTheScripts30AddToListOfConnectedLodObjectsEP7CObjectS1_, void, CObject* pObject1, CObject* pObject2);
    DECL_FASTCALL_SIMPLE(ScriptConnectLodsFunction, _ZN11CTheScripts25ScriptConnectLodsFunctionEii, bool, i32 objecthandle1, i32 objecthandle2);
    DECL_FASTCALL_SIMPLE(InitialiseSpecialAnimGroup, _ZN11CTheScripts26InitialiseSpecialAnimGroupEt, void, u16 a1);
    DECL_FASTCALL_SIMPLE(InitialiseSpecialAnimGroupsAttachedToCharModels, _ZN11CTheScripts47InitialiseSpecialAnimGroupsAttachedToCharModelsEv, void);
    DECL_FASTCALL_SIMPLE(AddToListOfSpecialAnimGroupsAttachedToCharModels, _ZN11CTheScripts48AddToListOfSpecialAnimGroupsAttachedToCharModelsEiPc, void, i32 modelid, char* ifpName);
    DECL_FASTCALL_SIMPLE(ScriptAttachAnimGroupToCharModel, _ZN11CTheScripts32ScriptAttachAnimGroupToCharModelEiPc, u8, i32 modelId, char* ifpName);
    DECL_FASTCALL_SIMPLE(ReinitialiseSwitchStatementData, _ZN11CTheScripts31ReinitialiseSwitchStatementDataEv, void);
    DECL_FASTCALL_SIMPLE(AddToSwitchJumpTable, _ZN11CTheScripts20AddToSwitchJumpTableEii, void, i32 switchValue, i32 switchLabelLocalAddress);
    DECL_FASTCALL_SIMPLE(UseSwitchJumpTable, _ZN11CTheScripts18UseSwitchJumpTableEPi, void, i32* pSwitchLabelAddress);
    DECL_FASTCALL_SIMPLE(CheckStreamedScriptVersion, _ZN11CTheScripts26CheckStreamedScriptVersionEP8RwStreamPc, bool, RwStream* arg1, char* arg2);
    DECL_FASTCALL_SIMPLE(AddToWaitingForScriptBrainArray, _ZN11CTheScripts31AddToWaitingForScriptBrainArrayEP7CEntitys, void, CEntity* pEntity, i16 arg2);
    DECL_FASTCALL_SIMPLE(RemoveFromWaitingForScriptBrainArray, _ZN11CTheScripts36RemoveFromWaitingForScriptBrainArrayEP7CEntitys, void, CEntity* a1, i16 modelIndex);
    DECL_FASTCALL_SIMPLE(ProcessWaitingForScriptBrainArray, _ZN11CTheScripts33ProcessWaitingForScriptBrainArrayEv, void);
    DECL_FASTCALL_SIMPLE(CurrentMissionName, _ZN11CTheScripts18CurrentMissionNameEv, char*);
    DECL_FASTCALL_SIMPLE(Init, _ZN11CTheScripts4InitEv, void);
    DECL_FASTCALL_SIMPLE(Process, _ZN11CTheScripts7ProcessEv, void);
    DECL_FASTCALL_SIMPLE(StartNewScript, _ZN11CTheScripts14StartNewScriptEPh, CRunningScript*, u8* startIp);
    DECL_FASTCALL_SIMPLE(StartNewScript2, _ZN11CTheScripts14StartNewScriptEPht, CRunningScript*, u8* startIp, u16 scriptIndex);
    DECL_FASTCALL_SIMPLE(IsPlayerOnAMission, _ZN11CTheScripts18IsPlayerOnAMissionEv, u8);
    DECL_FASTCALL_SIMPLE(IsVehicleStopped, _ZN11CTheScripts16IsVehicleStoppedEP8CVehicle, u8, CVehicle* vehicle);
    DECL_FASTCALL_SIMPLE(CleanUpThisVehicle, _ZN11CTheScripts18CleanUpThisVehicleEP8CVehicle, void, CVehicle* vehicle);
    DECL_FASTCALL_SIMPLE(RemoveScriptTextureDictionary, _ZN11CTheScripts29RemoveScriptTextureDictionaryEv, void);
    DECL_FASTCALL_SIMPLE(GetActualScriptThingIndex, _ZN11CTheScripts25GetActualScriptThingIndexEih, i32, i32 index, u8 type);

    // STATIC values
    DECL_OBJECT_ARRAY_PLT(tScriptSphere, ScriptSphereArray, BYBIT(0x6796E0, 0x850DD0));
    DECL_OBJECT_ARRAY_PLT(tScriptCheckpoint, ScriptCheckpointArray, BYBIT(0x678750, 0x84EEC8));
    DECL_OBJECT_ARRAY_PLT(tScriptEffectSystem, ScriptEffectSystemArray, BYBIT(0x679834, 0x851078));
    DECL_OBJECT_ARRAY_PLT(tScriptSearchlight, ScriptSearchLightArray, BYBIT(0x6797B4, 0x850F70));
    DECL_OBJECT_ARRAY_PLT(tBuildingSwap, BuildingSwapArray, BYBIT(0x678770, 0x84EF08));
    DECL_OBJECT_ARRAY_PLT(tInvisibilitySetting, InvisibilitySettingArray, BYBIT(0x6796F8, 0x850E00));
    DECL_OBJECT_ARRAY_PLT(tEntityWaitingForScriptBrain, EntitiesWaitingForScriptBrain, BYBIT(0x676C28, 0x84B898));
    DECL_OBJECT_ARRAY_PLT(tScriptConnectedLodObjects, ScriptConnectLodsObjects, BYBIT(0x676F08, 0x84BE50));
    DECL_OBJECT_ARRAY_PLT(tScriptAttachedAnimGroup, ScriptAttachedAnimGroups, BYBIT(0x679AD4, 0x8515C8));
    DECL_VALUE_PLT_U32(OnAMissionFlag, BYBIT(0x678D00, 0x84FA28));
    DECL_VALUE_PLT_U32(LastMissionPassedTime, BYBIT(0x677540, 0x84CAB8));
    DECL_VALUE_PLT_I32(LastRandomPedId, BYBIT(0x677EFC, 0x84DE18));
    DECL_VALUE_PLT_U16(NumberOfUsedObjects, BYBIT(0x677278, 0x84C528));
    DECL_VALUE_PLT_U16(NumberOfIntroTextLinesThisFrame, BYBIT(0x6762D4, 0x84A608));
    DECL_VALUE_PLT_U8(UseTextCommands, BYBIT(0x67876C, 0x84EF00));
    DECL_VALUE_PLT_U8(bUseMessageFormatting, BYBIT(0x677800, 0x84D028));
    DECL_VALUE_PLT_U16(MessageCentre, BYBIT(0x679C40, 0x851898));
    DECL_VALUE_PLT_U16(MessageWidth, BYBIT(0x676A74, 0x84B530));
    DECL_VALUE_PLT_U16(NumberOfIntroRectanglesThisFrame, BYBIT(0x676E14, 0x84BC70));
    DECL_OBJECT_ARRAY_PLT(CSprite2d, ScriptSprites, BYBIT(0x678EAC, 0x84FD80));
    DECL_OBJECT_ARRAY_PLT(i32, SuppressedVehicleModels, BYBIT(0x67982C, 0x851068));
    DECL_OBJECT_ARRAY_PLT(i32, VehicleModelsBlockedByScript, BYBIT(0x678D6C, 0x84FB00));
    DECL_VALUE_PLT_I16(ScriptsUpdated, BYBIT(0x678498, 0x84E948));
    DECL_VALUE_PLT_I16(CommandsExecuted, BYBIT(0x6786B8, 0x84ED98));
    DECL_OBJECT_PLT(u8 const, DbgFlag, BYBIT(0x678350, 0x84E6B8));
    DECL_VALUE_PLT_U8(StoreVehicleWasRandom, BYBIT(0x677B5C, 0x84D6D8));
    DECL_VALUE_PLT_I32(StoreVehicleIndex, BYBIT(0x67751C, 0x84CA70));
    DECL_VALUE_PLT_U8(bUsingAMultiScriptFile, BYBIT(0x679EC4, 0x851D98));
    DECL_VALUE_PLT_U8(bPlayerHasMetDebbieHarry, BYBIT(0x678870, 0x84F100));
    DECL_VALUE_PLT_U8(RiotIntensity, BYBIT(0x67615C, 0x84A318));
    DECL_VALUE_PLT_U8(bPlayerIsOffTheMap, BYBIT(0x6784F4, 0x84EA00));
    DECL_VALUE_PLT_U8(RadarZoomValue, BYBIT(0x676DAC, 0x84BBA0));
    DECL_VALUE_PLT_U8(RadarShowBlipOnAllLevels, BYBIT(0x676370, 0x84A738));
    DECL_VALUE_PLT_U8(HideAllFrontEndMapBlips, BYBIT(0x6788A4, 0x84F168));
    DECL_VALUE_PLT_U8(bDisplayHud, BYBIT(0x677CFC, 0x84DA18));
    DECL_VALUE_PLT_FLT(fCameraHeadingWhenPlayerIsAttached, BYBIT(0x679AF4, 0x851608));
    DECL_VALUE_PLT_FLT(fCameraHeadingStepWhenPlayerIsAttached, BYBIT(0x6773E4, 0x84C800));
    DECL_VALUE_PLT_U8(bEnableCraneRaise, BYBIT(0x6762B0, 0x84A5C0));
    DECL_VALUE_PLT_U8(bEnableCraneLower, BYBIT(0x6770D0, 0x84C1D8));
    DECL_VALUE_PLT_U8(bEnableCraneRelease, BYBIT(0x6784E8, 0x84E9E8));
    DECL_VALUE_PLT_I32(ForceRandomCarModel, BYBIT(0x675FB4, 0x849FD8));
    DECL_VALUE_PLT_U8(bAddNextMessageToPreviousBriefs, BYBIT(0x676128, 0x84A2B0));
    DECL_VALUE_PLT_U8(bScriptHasFadedOut, BYBIT(0x67863C, 0x84ECA0));
    DECL_VALUE_PLT_U8(bDrawOddJobTitleBeforeFade, BYBIT(0x679CA8, 0x851968));
    DECL_VALUE_PLT_U8(bDrawSubtitlesBeforeFade, BYBIT(0x6787E4, 0x84EFF0));
    DECL_VALUE_PLT_U32(MainScriptSize, BYBIT(0x6766D8, 0x84AE08));
    DECL_VALUE_PLT_U32(LargestMissionScriptSize, BYBIT(0x67682C, 0x84B0B0));
    DECL_VALUE_PLT_I16(NumberOfMissionScripts, BYBIT(0x676F84, 0x84BF48));
    DECL_VALUE_PLT_I16(NumberOfExclusiveMissionScripts, BYBIT(0x678A98, 0x84F558));
    DECL_VALUE_PLT_U32(LargestNumberOfMissionScriptLocalVariables, BYBIT(0x676FC8, 0x84BFC8));
    DECL_VALUE_PLT_U8(bAlreadyRunningAMissionScript, BYBIT(0x679934, 0x851288));
    DECL_VALUE_PLT_U8(FailCurrentMission, BYBIT(0x678D3C, 0x84FAA0));
    DECL_VALUE_PLT_U32(ScriptPickupCycleIndex, BYBIT(0x679A0C, 0x851430));
    DECL_VALUE_PLT_U8(bMiniGameInProgress, BYBIT(0x6774E8, 0x84CA08));
    DECL_VALUE_PLT_U8(bDisplayNonMiniGameHelpMessages, BYBIT(0x6782E0, 0x84E5D8));
    DECL_OBJECT_ARRAY_PLT(i16, CardStack, BYBIT(0x678754, 0x84EED0));
    DECL_VALUE_PLT_I16(CardStackPosition, BYBIT(0x678300, 0x84E618));
    DECL_VALUE_PLT_U16(NumberOfScriptSearchLights, BYBIT(0x679A44, 0x8514A0));
    DECL_VALUE_PLT_U16(NumberOfScriptCheckpoints, BYBIT(0x679794, 0x850F30));
    DECL_VALUE_PLT_U16(NumberOfEntriesStillToReadForSwitch, BYBIT(0x677EF4, 0x84DE08));
    DECL_VALUE_PLT_I32(ValueToCheckInSwitchStatement, BYBIT(0x679598, 0x850B40));
    DECL_VALUE_PLT_U8(SwitchDefaultExists, BYBIT(0x6780C0, 0x84E198));
    DECL_VALUE_PLT_I32(SwitchDefaultAddress, BYBIT(0x677438, 0x84C8A8));
    DECL_VALUE_PLT_U16(NumberOfEntriesInSwitchTable, BYBIT(0x679498, 0x850948));
    DECL_OBJECT_ARRAY_PLT(CRunningScript, ScriptsArray, BYBIT(0x679658, 0x850CC0));
    DECL_OBJECT_PLT(CRunningScript*, pActiveScripts, BYBIT(0x679D14, 0x851A40));
    DECL_OBJECT_PLT(CRunningScript*, pIdleScripts, BYBIT(0x679B34, 0x851688));
    DECL_OBJECT_ARRAY_PLT(u8, ScriptSpace, BYBIT(0x676040, 0x84A0F0));
    DECL_OBJECT_ARRAY_PLT(i32, LocalVariablesForCurrentMission, BYBIT(0x676BE4, 0x84B810));
    DECL_OBJECT_PLT(CMissionCleanup, MissionCleanUp, BYBIT(0x677318, 0x84C668));
    DECL_OBJECT_PLT(CScriptResourceManager, ScriptResourceManager, BYBIT(0x677EB0, 0x84DD80));
    DECL_OBJECT_PLT(CStreamedScripts, StreamedScripts, BYBIT(0x6761B8, 0x84A3D0));
DECL_CLASS_END()

#define ScriptsArray ScriptsArray()
#define ScriptSphereArray ScriptSphereArray()
#define ScriptCheckpointArray ScriptCheckpointArray()
#define ScriptEffectSystemArray ScriptEffectSystemArray()
#define ScriptSearchLightArray ScriptSearchLightArray()
#define BuildingSwapArray BuildingSwapArray()
#define InvisibilitySettingArray InvisibilitySettingArray()
#define EntitiesWaitingForScriptBrain EntitiesWaitingForScriptBrain()
#define ScriptConnectLodsObjects ScriptConnectLodsObjects()
#define ScriptAttachedAnimGroups ScriptAttachedAnimGroups()
#define pActiveScripts pActiveScripts()
#define pIdleScripts pIdleScripts()
#define ScriptSpace ScriptSpace()
#define LocalVariablesForCurrentMission LocalVariablesForCurrentMission()
#define MissionCleanUp MissionCleanUp()
#define ScriptResourceManager ScriptResourceManager()
#define StreamedScripts StreamedScripts()

#define OnAMissionFlag OnAMissionFlag()
#define LastMissionPassedTime LastMissionPassedTime()
#define LastRandomPedId LastRandomPedId()
#define NumberOfUsedObjects NumberOfUsedObjects()
#define NumberOfIntroTextLinesThisFrame NumberOfIntroTextLinesThisFrame()
#define UseTextCommands UseTextCommands()
#define bUseMessageFormatting bUseMessageFormatting()
#define MessageCentre MessageCentre()
#define MessageWidth MessageWidth()
#define NumberOfIntroRectanglesThisFrame NumberOfIntroRectanglesThisFrame()
#define ScriptSprites ScriptSprites()
#define SuppressedVehicleModels SuppressedVehicleModels()
#define VehicleModelsBlockedByScript VehicleModelsBlockedByScript()
#define ScriptsUpdated ScriptsUpdated()
#define CommandsExecuted CommandsExecuted()
#define DbgFlag DbgFlag()
#define StoreVehicleWasRandom StoreVehicleWasRandom()
#define StoreVehicleIndex StoreVehicleIndex()
#define bUsingAMultiScriptFile bUsingAMultiScriptFile()
#define bPlayerHasMetDebbieHarry bPlayerHasMetDebbieHarry()
#define RiotIntensity RiotIntensity()
#define bPlayerIsOffTheMap bPlayerIsOffTheMap()
#define RadarZoomValue RadarZoomValue()
#define RadarShowBlipOnAllLevels RadarShowBlipOnAllLevels()
#define HideAllFrontEndMapBlips HideAllFrontEndMapBlips()
#define bDisplayHud bDisplayHud()
#define fCameraHeadingWhenPlayerIsAttached fCameraHeadingWhenPlayerIsAttached()
#define fCameraHeadingStepWhenPlayerIsAttached fCameraHeadingStepWhenPlayerIsAttached()
#define bEnableCraneRaise bEnableCraneRaise()
#define bEnableCraneLower bEnableCraneLower()
#define bEnableCraneRelease bEnableCraneRelease()
#define ForceRandomCarModel ForceRandomCarModel()
#define bAddNextMessageToPreviousBriefs bAddNextMessageToPreviousBriefs()
#define bScriptHasFadedOut bScriptHasFadedOut()
#define bDrawOddJobTitleBeforeFade bDrawOddJobTitleBeforeFade()
#define bDrawSubtitlesBeforeFade bDrawSubtitlesBeforeFade()
#define MainScriptSize MainScriptSize()
#define LargestMissionScriptSize LargestMissionScriptSize()
#define NumberOfMissionScripts NumberOfMissionScripts()
#define NumberOfExclusiveMissionScripts NumberOfExclusiveMissionScripts()
#define LargestNumberOfMissionScriptLocalVariables LargestNumberOfMissionScriptLocalVariables()
#define bAlreadyRunningAMissionScript bAlreadyRunningAMissionScript()
#define FailCurrentMission FailCurrentMission()
#define ScriptPickupCycleIndex ScriptPickupCycleIndex()
#define bMiniGameInProgress bMiniGameInProgress()
#define bDisplayNonMiniGameHelpMessages bDisplayNonMiniGameHelpMessages()
#define CardStack CardStack()
#define CardStackPosition CardStackPosition()
#define NumberOfScriptSearchLights NumberOfScriptSearchLights()
#define NumberOfScriptCheckpoints NumberOfScriptCheckpoints()
#define NumberOfEntriesStillToReadForSwitch NumberOfEntriesStillToReadForSwitch()
#define ValueToCheckInSwitchStatement ValueToCheckInSwitchStatement()
#define SwitchDefaultExists SwitchDefaultExists()
#define SwitchDefaultAddress SwitchDefaultAddress()
#define NumberOfEntriesInSwitchTable NumberOfEntriesInSwitchTable()

#endif // __AML_PSDK_SATHESCRIPTS_H
