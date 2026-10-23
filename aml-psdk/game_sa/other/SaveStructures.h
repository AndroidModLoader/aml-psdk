#ifndef __AML_PSDK_SASAVESTRUCTURES_H
#define __AML_PSDK_SASAVESTRUCTURES_H

#include "../plugin.h"
#include "../base/EntityFlags.h"
#include "../base/Matrix.h"
#include "../base/CompressedMatrix.h"
#include "../base/Lists.h"
#include "../entity/Weapon.h"
#include "../engine/Garages.h"
#include "Clothes.h"
#include "../../renderware/RwRGBA.h"
#include "../../gta_base/RGBA.h"

struct CVehicle;
struct CObject;
struct CPed;
struct CPlayerInfo;
struct CPlayerPedData;

enum eCarLockState : i32
{
    CARLOCK_NONE = 0,
    CARLOCK_UNLOCKED = 1,
    CARLOCK_LOCKED = 2,
    CARLOCK_LOCKOUT_PLAYER_ONLY = 3,
    CARLOCK_LOCKED_PLAYER_INSIDE = 4,
    CARLOCK_LOCKED_INITIALLY = 5,
    CARLOCK_FORCE_SHUT_DOORS = 6,
    CARLOCK_LOCKED_BUT_CAN_BE_DAMAGED = 7,
};

DECL_CLASS(CVehicleSaveStructure)
    // Member functions
    DECL_THISCALL_HEAD(Construct, _ZN21CVehicleSaveStructure9ConstructEP8CVehicle, void, CVehicle* source)
    DECL_THISCALL_TAIL(Construct, source)
    DECL_THISCALL_HEAD(Extract, _ZN21CVehicleSaveStructure7ExtractEP8CVehicle, void, CVehicle* destination)
    DECL_THISCALL_TAIL(Extract, destination)

    // Member values
    CMatrixSerialize m_Matrix;
    u8 m_VehicleCreatedBy;
    u8 m_Colour1;
    u8 m_Colour2;
    u8 m_Colour3;
    u8 m_Colour4;
    u16 m_CarAlarmState;
    u8 m_nMaxPassengers;
    float m_fSteerAngle;
    float m_fGasPedal;
    float m_fBrakePedal;
    CVehicleFlags m_nVehicleFlags;
    float m_nHealth;
    eCarLockState m_eDoorLockState;
    CPhysicalFlags m_nPhysicalFlags;
    float m_fMass;
    float m_fTurnMass;
    float m_fBuoyancyConstant;
DECL_CLASS_END()
CHECKSIZE(CVehicleSaveStructure, 0x80, 0x80);

#pragma pack(push, 2)
DECL_CLASS(CObjectSaveStructure)
    // Member functions
    DECL_THISCALL_HEAD(Construct, _ZN20CObjectSaveStructure9ConstructEP7CObject, void, CObject* source)
    DECL_THISCALL_TAIL(Construct, source)
    DECL_THISCALL_HEAD(Extract, _ZN20CObjectSaveStructure7ExtractEP7CObject, void, CObject* destination)
    DECL_THISCALL_TAIL(Extract, destination)

    // Member values
    CCompressedMatrix m_CompressedMatrix;
    u8 m_ObjMessage;
    u16 m_ObjMessageAmount;
    u32 m_nEndOfLifeTime;
    CFlags m_nEntityFlags;
    u8 : 8;
    CObjectFlags m_nObjectFlags;
    u8 m_ObjectCreatedBy;
    u8 m_CollisionDamageEffect;
    u8 m_StoredCollisionDamageEffect;
    u8 m_FlagsNeededByScripts;
    i16 StreamedScriptBrainToLoad;
DECL_CLASS_END()
CHECKSIZE(CObjectSaveStructure, 0x34, 0x34);
#pragma pack(pop)

DECL_CLASS(CPedSaveStructure)
    // Member functions
    DECL_THISCALL_HEAD(Construct, _ZN17CPedSaveStructure9ConstructEP4CPed, void, CPed* source)
    DECL_THISCALL_TAIL(Construct, source)
    DECL_THISCALL_HEAD(Extract, _ZN17CPedSaveStructure7ExtractEP4CPed, void, CPed* destination)
    DECL_THISCALL_TAIL(Extract, destination)

    // Member values
    CVector m_Position;
    float m_heading;
    float m_nHealth;
    float m_nArmour;
    CWeaponSaveStructure m_WeaponSlots[13];
    u8 m_CharCreatedBy;
    i8 m_nCurrentWeapon;
    u8 m_nAreaCode;
    i32 m_lastEntryExit;
    u8 m_nExtraMeleeCombo;
    u8 m_nExtraMeleeComboFlags;
    CPedFlags m_nPedFlags;
    CPhysicalFlags m_nPhysicalFlags;
DECL_CLASS_END()
CHECKSIZE(CPedSaveStructure, 0x1A4, 0x1A4);

DECL_CLASS(CPlayerInfoSaveStructure)
    // Member functions
    DECL_THISCALL_HEAD(Construct, _ZN24CPlayerInfoSaveStructure9ConstructEP11CPlayerInfo, void, CPlayerInfo* source)
    DECL_THISCALL_TAIL(Construct, source)
    DECL_THISCALL_HEAD(Extract, _ZN24CPlayerInfoSaveStructure7ExtractEP11CPlayerInfo, void, CPlayerInfo* destination)
    DECL_THISCALL_TAIL(Extract, destination)

    // Member values
    i32 m_Score;
    u16 m_CarDensityForCurrentZone;
    u8 m_PlayerState;
    float m_RoadDensityAroundPlayer;
    i32 m_DisplayScore;
    u8 m_TimeLastEaten;
    i32 m_CollectablesPickedUp;
    i32 m_TotalNumCollectables;
    bool m_DoesNotGetTired;
    bool m_FastReload;
    bool m_FireProof;
    u8 m_MaxHealth;
    u8 m_MaxArmour;
    bool m_bGetOutOfJailFree;
    bool m_bFreeHealthCare;
    bool m_bCanDoDriveBy;
    u8 m_nBustedAudioStatus;
    u16 m_nLastBustMessageNumber;
DECL_CLASS_END()
CHECKSIZE(CPlayerInfoSaveStructure, 0x28, 0x28);

DECL_CLASS(CPlayerPedDataSaveStructure)
    // Member functions
    DECL_THISCALL_HEAD(Construct, _ZN27CPlayerPedDataSaveStructure9ConstructEP14CPlayerPedData, void, CPlayerPedData* source)
    DECL_THISCALL_TAIL(Construct, source)
    DECL_THISCALL_HEAD(Extract, _ZN27CPlayerPedDataSaveStructure7ExtractEP14CPlayerPedData, void, CPlayerPedData* destination)
    DECL_THISCALL_TAIL(Extract, destination)

    // Member values
    i32 m_nWantedLevel;
    u8 m_WantedLevel;
    CPedClothesDesc m_Clothes;
    i8 m_nChosenWeapon;
    float m_fMultiplier;
DECL_CLASS_END()
CHECKSIZE(CPlayerPedDataSaveStructure, 0x88, 0x88);

DECL_CLASS(CPostEffectsSaveStructure)
    // Member functions
    DECL_THISCALL_HEAD(CopyValues, _ZN25CPostEffectsSaveStructure10CopyValuesEb, void, bool load)
    DECL_THISCALL_TAIL(CopyValues, load)

    // Member values
    float m_colour1Multiplier;
    float m_colour2Multiplier;
    float m_extraMultiplier;
    float SCREEN_EXTRA_MULT_CHANGE_RATE;
    float SCREEN_EXTRA_MULT_BASE_CAP;
    float SCREEN_EXTRA_MULT_BASE_MULT;
    i32 m_colourLeftUOffset;
    i32 m_colourRightUOffset;
    i32 m_colourTopVOffset;
    i32 m_colourBottomVOffset;
    bool m_bSeamRemover;
    bool m_bSeamRemoverSeamSearchMode;
    bool m_bSeamRemoverDebugMode;
    i32 m_SeamRemoverMode;
    i32 m_SeamRemoverShiftTopLeft;
    i32 m_SeamRemoverShiftBottomRight;
    bool m_smokeyEnable;
    i32 m_smokeyStrength;
    i32 m_smokeyDistance;
    bool m_waterEnable;
    float m_VisionFXDayNightBalance;
    bool m_bHeatHazeFX;
    bool m_bHeatHazeMaskModeTest;
    i32 m_HeatHazeFXHourOfDayStart;
    i32 m_HeatHazeFXHourOfDayEnd;
    float m_fHeatHazeFXFadeSpeed;
    float m_fHeatHazeFXInsideBuildingFadeSpeed;
    i32 m_HeatHazeFXType;
    i32 m_HeatHazeFXTypeLast;
    i32 m_HeatHazeFXIntensity;
    i32 m_HeatHazeFXRandomShift;
    i32 m_HeatHazeFXSpeedMin;
    i32 m_HeatHazeFXSpeedMax;
    i32 m_HeatHazeFXScanSizeX;
    i32 m_HeatHazeFXScanSizeY;
    i32 m_HeatHazeFXRenderSizeX;
    i32 m_HeatHazeFXRenderSizeY;
    bool m_bDarknessFilter;
    i32 m_DarknessFilterAlpha;
    i32 m_DarknessFilterAlphaDefault;
    i32 m_DarknessFilterRadiosityIntensityLimit;
    bool m_bCCTV;
    CRGBA m_CCTVcol;
    bool m_bFog;
    bool m_bSpeedFX;
    bool m_bSpeedFXTestMode;
    i32 m_SpeedFXAlpha;
    bool m_bSpeedFXUserFlag;
    bool m_bSpeedFXUserFlagCurrentFrame;
    float m_fSpeedFXManualSpeedCurrentFrame;
    bool m_bInCutscene;
    bool m_bNightVision;
    i32 m_NightVisionGrainStrength;
    CRGBA m_NightVisionMainCol;
    float m_fNightVisionSwitchOnFXTime;
    float m_fNightVisionSwitchOnFXCount;
    float m_fInfraredVisionSwitchOnFXCount;
    bool m_bInfraredVision;
    i32 m_InfraredVisionGrainStrength;
    float m_fInfraredVisionFilterRadius;
    RwRGBAReal m_fInfraredVisionHeatObjectCol;
    CRGBA m_InfraredVisionCol;
    CRGBA m_InfraredVisionMainCol;
    bool m_bRadiosity;
    bool m_bRadiosityLinearFilter;
    bool m_bRadiosityStripCopyMode;
    i32 m_RadiosityPixelsX;
    i32 m_RadiosityPixelsY;
    i32 m_RadiosityFilterPasses;
    i32 m_RadiosityRenderPasses;
    i32 m_RadiosityIntensityLimit;
    i32 m_RadiosityIntensity;
    i32 m_RadiosityFilterUCorrection;
    i32 m_RadiosityFilterVCorrection;
    bool m_bRadiosityDebug;
    bool m_bRadiosityBypassTimeCycleIntensityLimit;
    bool m_bDisableAllPostEffect;
    bool m_bSavePhotoFromScript;
    bool m_bGrainEnable;
    i32 m_grainStrength;
    bool m_bHilightEnable;
    i32 m_hilightStrength;
    i32 m_hilightScale;
    i32 m_hilightOffset;
    bool m_hilightMblur;
    i32 m_waterStrength;
    float m_xoffset;
    float m_yoffset;
    float m_waterSpeed;
    float m_waterFreq;
    CRGBA m_waterCol;
    bool m_bWaterDepthDarkness;
    float m_fWaterFullDarknessDepth;
    float m_fWaterFXStartUnderWaterness;
    bool m_bRainEnable;
    bool m_bColorEnable;
    i32 m_defScreenXPosn;
    i32 m_defScreenYPosn;
DECL_CLASS_END()
CHECKSIZE(CPostEffectsSaveStructure, 0x15C, 0x15C);

DECL_CLASS(CGangWarsSaveStructure)
    // Member functions
    DECL_THISCALL_SIMPLE(Construct, _ZN22CGangWarsSaveStructure9ConstructEv, void);
    DECL_THISCALL_SIMPLE(Extract, _ZN22CGangWarsSaveStructure7ExtractEv, void);

    // Member values
    bool m_bGangWarsActive;
    i32 m_State;
    u32 m_TimeStarted;
    i32 m_ZoneInfoToFightOver;
    i32 m_ZoneToFightOver;
    CVector m_CoorsOfPlayerAtStartOfWar;
    i32 m_Gang1;
    i32 m_Gang2;
    i32 m_WarFerocity;
    u32 m_LastTimeInArea;
    i32 m_State2;
    float m_TimeTillNextAttack;
    CVector m_PointOfAttack;
    i32 m_FightTimer;
    i32 m_RadarBlip;
    bool m_bPlayerIsCloseby;
    float m_TerritoryUnderControlPercentage;
    float m_Difficulty;
    bool m_CanTriggerGangWarWhenOnAMission;
    bool m_bTrainingMission;
    i32 m_ZoneInfoForTraining;
DECL_CLASS_END()
CHECKSIZE(CGangWarsSaveStructure, 0x60, 0x60);

DECL_CLASS(CSaveGarage)
    // Member functions
    DECL_THISCALL_HEAD(CopyGarageIntoSaveGarage, _ZN11CSaveGarage24CopyGarageIntoSaveGarageEP7CGarage, void, CGarage* garage)
    DECL_THISCALL_TAIL(CopyGarageIntoSaveGarage, garage)
    DECL_THISCALL_HEAD(CopyGarageOutOfSaveGarage, _ZN11CSaveGarage25CopyGarageOutOfSaveGarageEP7CGarage, void, CGarage* garage)
    DECL_THISCALL_TAIL(CopyGarageOutOfSaveGarage, garage)

    // Member values
    u8 Type;
    u8 State;
    CGarageFlags Flags;
    float BaseX;
    float BaseY;
    float BaseZ;
    float Delta1X;
    float Delta1Y;
    float Delta2X;
    float Delta2Y;
    float CeilingZ;
    float Delta1Length;
    float Delta2Length;
    float MinX;
    float MaxX;
    float MinY;
    float MaxY;
    float Openness;
    u32 TimeOfNextEvent;
    char Name[8];
    u8 OriginalType;
DECL_CLASS_END()
CHECKSIZE(CSaveGarage, 0x50, 0x50);

// Serialized pointer slots stay 32-bit on both ABIs.
DECL_CLASS(CPickupSerialize)
    // Member values
    float CurrentValue;
    u32 pObject;
    i32 MonetaryValue;
    u32 RegenerationTime;
    i16 CoorsX;
    i16 CoorsY;
    i16 CoorsZ;
    u16 MoneyPerDay;
    u16 MI;
    u16 ReferenceIndex;
    u8 Type;
    u8 State : 1;
    u8 bNoAmmo : 1;
    u8 bHelpMessageDisplayed : 1;
    u8 bIsPickupNearby : 1;
    u8 TextIndex : 3;
DECL_CLASS_END()
CHECKSIZE(CPickupSerialize, 0x20, 0x20);

DECL_CLASS(CPathNodeSerialize)
    // Member values
    u32 pNext;
    u32 pPrevious;
    i16 CoorsX;
    i16 CoorsY;
    i16 CoorsZ;
    i16 DistanceToTarget;
    i16 IndexAdjacentNodes;
    CNodeAddress Address;
    u8 Width;
    u8 Group;
    u8 NumberAdjNodes : 4;
    u8 OnDeadEnd : 1;
    u8 SwitchedOff : 1;
    u8 RoadBlock : 1;
    u8 WaterNode : 1;
    u8 SwitchedOffOriginal : 1;
    u8 AlreadyFound : 1;
    u8 DontWanderHere : 1;
    u8 InteriorNode : 1;
    u8 Speed : 2;
    u8 : 2;
    u8 Density : 4;
    u8 SpecialFunction : 4;
DECL_CLASS_END()
CHECKSIZE(CPathNodeSerialize, 0x1C, 0x1C);

DECL_CLASS(CRunningScriptSerialize)
    // Member values
    u32 pNext;
    u32 pPrevious;
    char ScriptName[8];
    u32 BaseAddressOfThisScript;
    u32 PCPointer;
    u32 PCStack[8];
    u16 StackDepth;
    i32 Locals[42];
    u8 bActive;
    u8 CmpFlag;
    u8 IsThisAMissionScript;
    u8 bIsThisAStreamedScript;
    u8 bIsThisAMiniGameScript;
    i8 ScriptBrainType;
    u32 ActivateTime;
    u16 AndOrState;
    u8 NotForLatestExpression;
    u8 DeatharrestCheckEnabled;
    u8 DoneDeatharrest;
    i32 EndOfScriptedCutscenePC;
    u8 ThisMustBeTheOnlyMissionRunning;
DECL_CLASS_END()
CHECKSIZE(CRunningScriptSerialize, 0x100, 0x100);

#endif // __AML_PSDK_SASAVESTRUCTURES_H
