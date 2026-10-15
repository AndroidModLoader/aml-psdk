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
struct CPedGenerator;

enum EScriptWindowType
{
    WINDOW_NONE = 0,
    WINDOW_HEADER_AND_TEXT = 1,
    WINDOW_HEADER_NO_TEXT = 2,
    WINDOW_SOLID_COLOUR = 3,
    WINDOW_SPRITE_NO_ROTATION = 4,
    WINDOW_SPRITE_WITH_ROTATION = 5,
};

struct tUsedObject
{
    char Name[24];
    i32 Index;
};
CHECKSIZE(tUsedObject, 0x1C, 0x1C);

struct tScriptText
{
    float ScriptTextXScale;
    float ScriptTextYScale;
    CRGBA ScriptTextColor;
    u8 ScriptTextJustify;
    u8 ScriptTextCentre;
    u8 ScriptTextBackgrnd;
    u8 ScriptTextBackgrndOnlyText;
    float ScriptTextWrapX;
    float ScriptTextCentreSize;
    CRGBA ScriptTextBackgrndColor;
    u8 ScriptTextProportional;
    CRGBA ScriptTextDropShadowColour;
    i8 ScriptTextDropShadow;
    i8 ScriptTextEdge;
    u8 ScriptTextBeforeFade;
    u8 ScriptTextRightJustify;
    i32 ScriptTextFontStyle;
    float ScriptTextAtX;
    float ScriptTextAtY;
    char ScriptTextLabel[8];
    i32 NumberToInsert1;
    i32 NumberToInsert2;
};
CHECKSIZE(tScriptText, 0x44, 0x44);

struct tScriptRectangle
{
    EScriptWindowType eWindowType;
    u8 ScriptRectBeforeFade;
    i16 ScriptSpriteIndex;
    float ScriptRectMinX;
    float ScriptRectMinY;
    float ScriptRectMaxX;
    float ScriptRectMaxY;
    float ScriptRectRotation;
    CRGBA ScriptRectColour;
    char pTitle[10];
    char pMessage[10];
    i32 nAlignment;
    i32 nSwirl;
};
CHECKSIZE(tScriptRectangle, 0x3C, 0x3C);

struct tScriptUniqueThing
{
    u8 bUsed;
    u16 ReferenceIndex;
};
CHECKSIZE(tScriptUniqueThing, 0x4, 0x4);

struct tMultiScript
{
    i32 StartOfScriptIndex;
};
CHECKSIZE(tMultiScript, 0x4, 0x4);

struct tScriptBrain
{
    i16 StreamedScriptIndex;
    i8 TypeOfBrain;
    i8 ObjectGroupingID;
    u8 bBrainActive;
    float ObjectBrainActivationRange;
    union
    {
        struct
        {
            i16 PedModelOrPedGeneratorIndex;
            u16 PercentageChance;
        } RandomPedData;
        char ScriptName[8];
    };
};
CHECKSIZE(tScriptBrain, 0x14, 0x14);

struct tScriptSwitchCase
{
    i32 Value;
    i32 Address;
};
CHECKSIZE(tScriptSwitchCase, 0x8, 0x8);

struct tUpsideDownCar
{
    i32 CarID;
    u32 UpsideDownTimer;
};
CHECKSIZE(tUpsideDownCar, 0x8, 0x8);

struct tStuckCar
{
    i32 CarID;
    CVector LastPos;
    i32 LastChecked;
    float StuckRadius;
    i32 CheckTime;
    u8 bStuck;
    u8 bWarpCar;
    u8 bWarpIfStuckFlag;
    u8 bWarpIfUpsideDownFlag;
    u8 bWarpIfInWaterFlag;
    i8 NumberOfNodesToCheck;
};
CHECKSIZE(tStuckCar, 0x24, 0x24);

DECL_CLASS(CUpsideDownCarCheck)
    // Member functions
    DECL_THISCALL_NAMED_HEAD(IsCarUpsideDown1, IsCarUpsideDown, _ZN19CUpsideDownCarCheck15IsCarUpsideDownEi, u8, i32 CarToCheckID)
    DECL_THISCALL_TAIL(IsCarUpsideDown1, CarToCheckID)
    DECL_THISCALL_NAMED_HEAD(IsCarUpsideDown2, IsCarUpsideDown, _ZN19CUpsideDownCarCheck15IsCarUpsideDownEPK8CVehicle, u8, CVehicle const* arg1)
    DECL_THISCALL_TAIL(IsCarUpsideDown2, arg1)
    DECL_THISCALL_SIMPLE(Init, _ZN19CUpsideDownCarCheck4InitEv, void);
    DECL_THISCALL_SIMPLE(UpdateTimers, _ZN19CUpsideDownCarCheck12UpdateTimersEv, void);
    DECL_THISCALL_SIMPLE(AreAnyCarsUpsideDown, _ZN19CUpsideDownCarCheck20AreAnyCarsUpsideDownEv, u8);
    DECL_THISCALL_HEAD(AddCarToCheck, _ZN19CUpsideDownCarCheck13AddCarToCheckEi, void, i32 NewCarID)
    DECL_THISCALL_TAIL(AddCarToCheck, NewCarID)
    DECL_THISCALL_HEAD(RemoveCarFromCheck, _ZN19CUpsideDownCarCheck18RemoveCarFromCheckEi, void, i32 RemoveCarID)
    DECL_THISCALL_TAIL(RemoveCarFromCheck, RemoveCarID)
    DECL_THISCALL_HEAD(HasCarBeenUpsideDownForAWhile, _ZN19CUpsideDownCarCheck29HasCarBeenUpsideDownForAWhileEi, u8, i32 CheckCarID)
    DECL_THISCALL_TAIL(HasCarBeenUpsideDownForAWhile, CheckCarID)

    // Member values
    tUpsideDownCar Cars[6];
DECL_CLASS_END()
CHECKSIZE(CUpsideDownCarCheck, 0x30, 0x30);

DECL_CLASS(CStuckCarCheck)
    // Member functions
    DECL_THISCALL_HEAD(ResetArrayElement, _ZN14CStuckCarCheck17ResetArrayElementEt, void, u16 Index)
    DECL_THISCALL_TAIL(ResetArrayElement, Index)
    DECL_THISCALL_HEAD(AttemptToWarpVehicle, _ZN14CStuckCarCheck20AttemptToWarpVehicleEP8CVehicleR7CVectorf, bool, CVehicle* pVehicle, CVector& NewCoords, float NewHeading)
    DECL_THISCALL_TAIL(AttemptToWarpVehicle, pVehicle, NewCoords, NewHeading)
    DECL_THISCALL_SIMPLE(Init, _ZN14CStuckCarCheck4InitEv, void);
    DECL_THISCALL_SIMPLE(Process, _ZN14CStuckCarCheck7ProcessEv, void);
    DECL_THISCALL_HEAD(AddCarToCheck, _ZN14CStuckCarCheck13AddCarToCheckEifjhhhha, void, i32 NewCarID, float StuckRad, u32 CheckEvery, u8 bWarpCar, u8 bStuckFlag, u8 bUpsideDownFlag, u8 bInWaterFlag, i8 NumberOfNodesToCheck)
    DECL_THISCALL_TAIL(AddCarToCheck, NewCarID, StuckRad, CheckEvery, bWarpCar, bStuckFlag, bUpsideDownFlag, bInWaterFlag, NumberOfNodesToCheck)
    DECL_THISCALL_HEAD(RemoveCarFromCheck, _ZN14CStuckCarCheck18RemoveCarFromCheckEi, void, i32 RemoveCarID)
    DECL_THISCALL_TAIL(RemoveCarFromCheck, RemoveCarID)
    DECL_THISCALL_HEAD(HasCarBeenStuckForAWhile, _ZN14CStuckCarCheck24HasCarBeenStuckForAWhileEi, u8, i32 CheckCarID)
    DECL_THISCALL_TAIL(HasCarBeenStuckForAWhile, CheckCarID)
    DECL_THISCALL_HEAD(ClearStuckFlagForCar, _ZN14CStuckCarCheck20ClearStuckFlagForCarEi, void, i32 CheckCarID)
    DECL_THISCALL_TAIL(ClearStuckFlagForCar, CheckCarID)
    DECL_THISCALL_HEAD(IsCarInStuckCarArray, _ZN14CStuckCarCheck20IsCarInStuckCarArrayEi, u8, i32 CheckCarID)
    DECL_THISCALL_TAIL(IsCarInStuckCarArray, CheckCarID)

    // Member values
    tStuckCar Cars[16];
DECL_CLASS_END()
CHECKSIZE(CStuckCarCheck, 0x240, 0x240);

DECL_CLASS(CScriptsForBrains)
    enum
    {
        PED_STREAMED = 0,
        OBJECT_STREAMED = 1,
        PED_GENERATOR_STREAMED = 2,
        CODE_PED = 3,
        CODE_OBJECT = 4,
        CODE_ATTRACTOR_PED = 5,
    };

    // Construct/Deconstruct functions
    DECL_CTORCALL(CScriptsForBrains, _ZN17CScriptsForBrainsC2Ev);

    // Member functions
    DECL_THISCALL_SIMPLE(Init, _ZN17CScriptsForBrains4InitEv, void);
    DECL_THISCALL_HEAD(SwitchAllObjectBrainsWithThisID, _ZN17CScriptsForBrains31SwitchAllObjectBrainsWithThisIDEab, void, i8 object_grouping_id, bool bBrainOn)
    DECL_THISCALL_TAIL(SwitchAllObjectBrainsWithThisID, object_grouping_id, bBrainOn)
    DECL_THISCALL_HEAD(AddNewScriptBrain, _ZN17CScriptsForBrains17AddNewScriptBrainEsstaaf, void, i16 StreamedScriptIndex, i16 PedModelOrPedGeneratorIndex, u16 Percentage, i8 BrainType, i8 object_grouping_id, float ObjectActivationRange)
    DECL_THISCALL_TAIL(AddNewScriptBrain, StreamedScriptIndex, PedModelOrPedGeneratorIndex, Percentage, BrainType, object_grouping_id, ObjectActivationRange)
    DECL_THISCALL_HEAD(AddNewStreamedScriptBrainForCodeUse, _ZN17CScriptsForBrains35AddNewStreamedScriptBrainForCodeUseEsPca, void, i16 StreamedScriptIndex, char* pScriptName, i8 BrainType)
    DECL_THISCALL_TAIL(AddNewStreamedScriptBrainForCodeUse, StreamedScriptIndex, pScriptName, BrainType)
    DECL_THISCALL_HEAD(StartOrRequestNewStreamedScriptBrain, _ZN17CScriptsForBrains36StartOrRequestNewStreamedScriptBrainEhP7CEntityah, void, u8 ScriptBrainIndex, CEntity* pEntity, i8 BrainType, u8 bFirstTime)
    DECL_THISCALL_TAIL(StartOrRequestNewStreamedScriptBrain, ScriptBrainIndex, pEntity, BrainType, bFirstTime)
    DECL_THISCALL_HEAD(StartNewStreamedScriptBrain, _ZN17CScriptsForBrains27StartNewStreamedScriptBrainEhP7CEntityh, void, u8 ScriptBrainIndex, CEntity* pEntity, u8 bPedCreatedAtAttractor)
    DECL_THISCALL_TAIL(StartNewStreamedScriptBrain, ScriptBrainIndex, pEntity, bPedCreatedAtAttractor)
    DECL_THISCALL_HEAD(CheckIfNewEntityNeedsScript, _ZN17CScriptsForBrains27CheckIfNewEntityNeedsScriptEP7CEntityaP13CPedGenerator, void, CEntity* pNewEntity, i8 BrainType, CPedGenerator* pPedGen)
    DECL_THISCALL_TAIL(CheckIfNewEntityNeedsScript, pNewEntity, BrainType, pPedGen)
    DECL_THISCALL_HEAD(GetIndexOfScriptBrainWithThisName, _ZN17CScriptsForBrains33GetIndexOfScriptBrainWithThisNameEPKca, i16, char const* pScriptName, i8 const BrainType)
    DECL_THISCALL_TAIL(GetIndexOfScriptBrainWithThisName, pScriptName, BrainType)
    DECL_THISCALL_HEAD(StartOrRequestNewStreamedScriptBrainWithThisName, _ZN17CScriptsForBrains48StartOrRequestNewStreamedScriptBrainWithThisNameEPKcP7CEntitya, void, char const* pScriptName, CEntity* pEntity, i8 BrainType)
    DECL_THISCALL_TAIL(StartOrRequestNewStreamedScriptBrainWithThisName, pScriptName, pEntity, BrainType)
    DECL_THISCALL_HEAD(RequestAttractorScriptBrainWithThisName, _ZN17CScriptsForBrains39RequestAttractorScriptBrainWithThisNameEPKc, void, char const* pScriptName)
    DECL_THISCALL_TAIL(RequestAttractorScriptBrainWithThisName, pScriptName)
    DECL_THISCALL_HEAD(MarkAttractorScriptBrainWithThisNameAsNoLongerNeeded, _ZN17CScriptsForBrains52MarkAttractorScriptBrainWithThisNameAsNoLongerNeededEPKc, void, char const* pScriptName)
    DECL_THISCALL_TAIL(MarkAttractorScriptBrainWithThisNameAsNoLongerNeeded, pScriptName)
    DECL_THISCALL_HEAD(HasAttractorScriptBrainWithThisNameLoaded, _ZN17CScriptsForBrains41HasAttractorScriptBrainWithThisNameLoadedEPKc, u8, char const* pScriptName)
    DECL_THISCALL_TAIL(HasAttractorScriptBrainWithThisNameLoaded, pScriptName)
    DECL_THISCALL_HEAD(StartAttractorScriptBrainWithThisName, _ZN17CScriptsForBrains37StartAttractorScriptBrainWithThisNameEPKcP7CEntityh, void, char const* pScriptName, CEntity* pEntity, u8 bPedCreatedAtAttractor)
    DECL_THISCALL_TAIL(StartAttractorScriptBrainWithThisName, pScriptName, pEntity, bPedCreatedAtAttractor)
    DECL_THISCALL_HEAD(IsObjectWithinBrainActivationRange, _ZN17CScriptsForBrains34IsObjectWithinBrainActivationRangeEP7CObjectRK7CVector, u8, CObject* pObject, CVector const& vecCentrePoint)
    DECL_THISCALL_TAIL(IsObjectWithinBrainActivationRange, pObject, vecCentrePoint)

    // Member values
    tScriptBrain ScriptBrainArray[70];
DECL_CLASS_END()
CHECKSIZE(CScriptsForBrains, 0x578, 0x578);

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
    DECL_OBJECT_PLT(CUpsideDownCarCheck, UpsideDownCars, BYBIT(0x677538, 0x84CAA8));
    DECL_OBJECT_PLT(CStuckCarCheck, StuckCars, BYBIT(0x678FA0, 0x84FF68));
    DECL_OBJECT_PLT(CScriptsForBrains, ScriptsForBrains, BYBIT(0x67763C, 0x84CCA8));
    DECL_OBJECT_ARRAY_PLT(tUsedObject, UsedObjectArray, BYBIT(0x679FBC, 0x851F88));
    DECL_OBJECT_ARRAY_PLT(tScriptText, IntroTextLines, BYBIT(0x676C78, 0x84B938));
    DECL_OBJECT_ARRAY_PLT(tScriptRectangle, IntroRectangles, BYBIT(0x67915C, 0x8502E0));
    DECL_OBJECT_ARRAY_PLT(tMultiScript, MultiScriptArray, BYBIT(0x677E6C, 0x84DCF8));
    DECL_OBJECT_ARRAY_PLT(tScriptUniqueThing, ScriptSequenceTaskArray, BYBIT(0x6792F0, 0x8505F8));
    DECL_OBJECT_ARRAY_PLT(tScriptSwitchCase, SwitchJumpTable, BYBIT(0x676660, 0x84AD18));
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
