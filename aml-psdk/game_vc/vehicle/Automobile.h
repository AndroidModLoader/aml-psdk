#ifndef __AML_PSDK_VCAUTOMOBILE_H
#define __AML_PSDK_VCAUTOMOBILE_H

#include "Vehicle.h"
#include "Door.h"
#include "DamageManager.h"

struct RwFrame;
struct CObject;

enum eCarNodes : u32
{
    CAR_NODE_NONE = 0,
    CAR_WHEEL_RF = 1,
    CAR_WHEEL_RM = 2,
    CAR_WHEEL_RB = 3,
    CAR_WHEEL_LF = 4,
    CAR_WHEEL_LM = 5,
    CAR_WHEEL_LB = 6,
    CAR_BUMP_FRONT = 7,
    CAR_BUMP_REAR = 8,
    CAR_WING_RF = 9,
    CAR_WING_RR = 10,
    CAR_DOOR_RF = 11,
    CAR_DOOR_RR = 12,
    CAR_WING_LF = 13,
    CAR_WING_LR = 14,
    CAR_DOOR_LF = 15,
    CAR_DOOR_LR = 16,
    CAR_BONNET = 17,
    CAR_BOOT = 18,
    CAR_WINDSCREEN = 19,
    CAR_NUM_NODES = 20
};

DECL_CLASS_BASED(CAutomobile, CVehicle)
    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CAutomobile, _ZN11CAutomobileC2Eih, i32 modelIndex, u8 createdBy)
    DECL_CTORCALL_ARG_TAIL(modelIndex, createdBy)
    DECL_DTORCALL_VIRTUAL_SLOT(CAutomobile, _ZN11CAutomobileD2Ev, _ZN11CAutomobile, _ZTV11CAutomobile, 2);
    CAutomobile(CAutomobile const&) = delete;
    CAutomobile& operator=(CAutomobile const&) = delete;

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(CAutomobile, SetModelIndex, _ZTV11CAutomobile, 4, void, u32 modelIndex)
    DECL_VIRTUALCALL_TAIL(modelIndex)
    DECL_VIRTUALCALL_HEAD(CAutomobile, ProcessControl, _ZTV11CAutomobile, 9, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CAutomobile, Teleport, _ZTV11CAutomobile, 12, void, CVector destination)
    DECL_VIRTUALCALL_TAIL(destination)
    DECL_VIRTUALCALL_HEAD(CAutomobile, PreRender, _ZTV11CAutomobile, 13, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CAutomobile, Render, _ZTV11CAutomobile, 14, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CAutomobile, ProcessEntityCollision, _ZTV11CAutomobile, 18, i32, CEntity* entity, CColPoint* colPoints)
    DECL_VIRTUALCALL_TAIL(entity, colPoints)
    DECL_VIRTUALCALL_HEAD(CAutomobile, ProcessControlInputs, _ZTV11CAutomobile, 19, void, u8 playerNum)
    DECL_VIRTUALCALL_TAIL(playerNum)
    DECL_VIRTUALCALL_HEAD(CAutomobile, GetComponentWorldPosition, _ZTV11CAutomobile, 20, void, i32 componentId, CVector& position)
    DECL_VIRTUALCALL_TAIL(componentId, position)
    DECL_VIRTUALCALL_HEAD(CAutomobile, IsComponentPresent, _ZTV11CAutomobile, 21, bool, i32 componentId)
    DECL_VIRTUALCALL_TAIL(componentId)
    DECL_VIRTUALCALL_HEAD(CAutomobile, SetComponentRotation, _ZTV11CAutomobile, 22, void, i32 componentId, CVector rotation)
    DECL_VIRTUALCALL_TAIL(componentId, rotation)
    DECL_VIRTUALCALL_HEAD(CAutomobile, OpenDoor, _ZTV11CAutomobile, 23, void, i32 componentId, eDoors door, float ratio)
    DECL_VIRTUALCALL_TAIL(componentId, door, ratio)
    DECL_VIRTUALCALL_HEAD(CAutomobile, ProcessOpenDoor, _ZTV11CAutomobile, 24, void, u32 animId, u32 door, float time)
    DECL_VIRTUALCALL_TAIL(animId, door, time)
    DECL_VIRTUALCALL_HEAD(CAutomobile, IsDoorReady, _ZTV11CAutomobile, 25, bool, eDoors door)
    DECL_VIRTUALCALL_TAIL(door)
    DECL_VIRTUALCALL_HEAD(CAutomobile, IsDoorFullyOpen, _ZTV11CAutomobile, 26, bool, eDoors door)
    DECL_VIRTUALCALL_TAIL(door)
    DECL_VIRTUALCALL_HEAD(CAutomobile, IsDoorClosed, _ZTV11CAutomobile, 27, bool, eDoors door)
    DECL_VIRTUALCALL_TAIL(door)
    DECL_VIRTUALCALL_HEAD(CAutomobile, IsDoorMissing, _ZTV11CAutomobile, 28, bool, eDoors door)
    DECL_VIRTUALCALL_TAIL(door)
    DECL_VIRTUALCALL_HEAD(CAutomobile, IsDoorReady, _ZTV11CAutomobile, 29, bool, u32 door)
    DECL_VIRTUALCALL_TAIL(door)
    DECL_VIRTUALCALL_HEAD(CAutomobile, IsDoorMissing, _ZTV11CAutomobile, 30, bool, u32 door)
    DECL_VIRTUALCALL_TAIL(door)
    DECL_VIRTUALCALL_HEAD(CAutomobile, IsOpenTopCar, _ZTV11CAutomobile, 31, bool)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CAutomobile, RemoveRefsToVehicle, _ZTV11CAutomobile, 32, void, CEntity* entity)
    DECL_VIRTUALCALL_TAIL(entity)
    DECL_VIRTUALCALL_HEAD(CAutomobile, BlowUpCar, _ZTV11CAutomobile, 33, void, CEntity* damager)
    DECL_VIRTUALCALL_TAIL(damager)
    DECL_VIRTUALCALL_HEAD(CAutomobile, SetUpWheelColModel, _ZTV11CAutomobile, 34, bool, CColModel* colModel)
    DECL_VIRTUALCALL_TAIL(colModel)
    DECL_VIRTUALCALL_HEAD(CAutomobile, BurstTyre, _ZTV11CAutomobile, 35, void, u8 tyreId, bool applyForces)
    DECL_VIRTUALCALL_TAIL(tyreId, applyForces)
    DECL_VIRTUALCALL_HEAD(CAutomobile, IsRoomForPedToLeaveCar, _ZTV11CAutomobile, 36, bool, u32 componentId, CVector* forcedDoorPosition)
    DECL_VIRTUALCALL_TAIL(componentId, forcedDoorPosition)
    DECL_VIRTUALCALL_HEAD(CAutomobile, GetHeightAboveRoad, _ZTV11CAutomobile, 38, float)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CAutomobile, PlayCarHorn, _ZTV11CAutomobile, 39, void)
    DECL_VIRTUALCALL_TAIL()

    // Static functions
    DECL_FASTCALL_SIMPLE(SetAllTaxiLights, _ZN11CAutomobile16SetAllTaxiLightsEb, void, bool enable);

    // Member functions
    DECL_THISCALL_SIMPLE(AddDamagedVehicleParticles, _ZN11CAutomobile26AddDamagedVehicleParticlesEv, void);
    DECL_THISCALL_SIMPLE(BlowUpCarsInPath, _ZN11CAutomobile16BlowUpCarsInPathEv, void);
    DECL_THISCALL_SIMPLE(ClearHeliOrientation, _ZN11CAutomobile20ClearHeliOrientationEv, void);
    DECL_THISCALL_SIMPLE(CloseBoot, _ZN11CAutomobile9CloseBootEv, void);
    DECL_THISCALL_SIMPLE(CloseAllDoors, _ZN11CAutomobile13CloseAllDoorsEv, void);
    DECL_THISCALL_SIMPLE(DebugCode, _ZN11CAutomobile9DebugCodeEv, void);
    DECL_THISCALL_SIMPLE(DoDriveByShootings, _ZN11CAutomobile18DoDriveByShootingsEv, void);
    DECL_THISCALL_SIMPLE(DoHoverSuspensionRatios, _ZN11CAutomobile23DoHoverSuspensionRatiosEv, void);
    DECL_THISCALL_SIMPLE(FireTruckControl, _ZN11CAutomobile16FireTruckControlEv, void);
    DECL_THISCALL_SIMPLE(Fix, _ZN11CAutomobile3FixEv, void);
    DECL_THISCALL_SIMPLE(GetAllWheelsOffGround, _ZN11CAutomobile21GetAllWheelsOffGroundEv, bool);
    DECL_THISCALL_SIMPLE(HasCarStoppedBecauseOfLight, _ZN11CAutomobile27HasCarStoppedBecauseOfLightEv, bool);
    DECL_THISCALL_SIMPLE(HideAllComps, _ZN11CAutomobile12HideAllCompsEv, void);
    DECL_THISCALL_SIMPLE(HydraulicControl, _ZN11CAutomobile16HydraulicControlEv, void);
    DECL_THISCALL_SIMPLE(Linkup, _ZN11CAutomobile6LinkupEv, void);
    DECL_THISCALL_SIMPLE(PlaceOnRoadProperly, _ZN11CAutomobile19PlaceOnRoadProperlyEv, void);
    DECL_THISCALL_SIMPLE(PlayHornIfNecessary, _ZN11CAutomobile19PlayHornIfNecessaryEv, void);
    DECL_THISCALL_SIMPLE(PopBoot, _ZN11CAutomobile7PopBootEv, void);
    DECL_THISCALL_SIMPLE(PopBootUsingPhysics, _ZN11CAutomobile19PopBootUsingPhysicsEv, void);
    DECL_THISCALL_SIMPLE(ProcessAutoBusDoors, _ZN11CAutomobile19ProcessAutoBusDoorsEv, void);
    DECL_THISCALL_SIMPLE(ProcessBuoyancy, _ZN11CAutomobile15ProcessBuoyancyEv, void);
    DECL_THISCALL_SIMPLE(RcbanditCheckHitWheels, _ZN11CAutomobile22RcbanditCheckHitWheelsEv, i16);
    DECL_THISCALL_SIMPLE(ReduceHornCounter, _ZN11CAutomobile17ReduceHornCounterEv, void);
    DECL_THISCALL_SIMPLE(RemoveBonnetInPedCollision, _ZN11CAutomobile26RemoveBonnetInPedCollisionEv, CObject*);
    DECL_THISCALL_SIMPLE(ResetSuspension, _ZN11CAutomobile15ResetSuspensionEv, void);
    DECL_THISCALL_SIMPLE(ScanForCrimes, _ZN11CAutomobile13ScanForCrimesEv, void);
    DECL_THISCALL_SIMPLE(SetupDamageAfterLoad, _ZN11CAutomobile20SetupDamageAfterLoadEv, void);
    DECL_THISCALL_SIMPLE(SetupModelNodes, _ZN11CAutomobile15SetupModelNodesEv, void);
    DECL_THISCALL_SIMPLE(SetupSuspensionLines, _ZN11CAutomobile20SetupSuspensionLinesEv, void);
    DECL_THISCALL_SIMPLE(ShowAllComps, _ZN11CAutomobile12ShowAllCompsEv, void);
    DECL_THISCALL_SIMPLE(TankControl, _ZN11CAutomobile11TankControlEv, void);
    DECL_THISCALL_HEAD(AddWheelDirtAndWater, _ZN11CAutomobile20AddWheelDirtAndWaterER9CColPointj, i32, CColPoint& colPoint, u32 wheel)
    DECL_THISCALL_TAIL(AddWheelDirtAndWater, colPoint, wheel)
    DECL_THISCALL_HEAD(dmgDrawCarCollidingParticles, _ZN11CAutomobile28dmgDrawCarCollidingParticlesERK7CVectorf, void, CVector const& position, float force)
    DECL_THISCALL_TAIL(dmgDrawCarCollidingParticles, position, force)
    DECL_THISCALL_HEAD(KnockPedOutCar, _ZN11CAutomobile14KnockPedOutCarE11eWeaponTypetP4CPed, CPed*, eWeaponType weapon, u16 door, CPed* ped)
    DECL_THISCALL_TAIL(KnockPedOutCar, weapon, door, ped)
    DECL_THISCALL_HEAD(ProcessSwingingDoor, _ZN11CAutomobile19ProcessSwingingDoorEi6eDoors, void, i32 nodeIndex, eDoors door)
    DECL_THISCALL_TAIL(ProcessSwingingDoor, nodeIndex, door)
    DECL_THISCALL_HEAD(RcbanditCheck1CarWheels, _ZN11CAutomobile23RcbanditCheck1CarWheelsER8CPtrList, i16, CPtrList& list)
    DECL_THISCALL_TAIL(RcbanditCheck1CarWheels, list)
    DECL_THISCALL_HEAD(SetBumperDamage, _ZN11CAutomobile15SetBumperDamageEi7ePanelsb, void, i32 nodeIndex, ePanels panel, bool withoutVisualEffect)
    DECL_THISCALL_TAIL(SetBumperDamage, nodeIndex, panel, withoutVisualEffect)
    DECL_THISCALL_HEAD(SetBusDoorTimer, _ZN11CAutomobile15SetBusDoorTimerEjh, void, u32 time, u8 type)
    DECL_THISCALL_TAIL(SetBusDoorTimer, time, type)
    DECL_THISCALL_HEAD(SetComponentVisibility, _ZN11CAutomobile22SetComponentVisibilityEP7RwFramej, void, RwFrame* frame, u32 flags)
    DECL_THISCALL_TAIL(SetComponentVisibility, frame, flags)
    DECL_THISCALL_HEAD(SetDoorDamage, _ZN11CAutomobile13SetDoorDamageEi6eDoorsb, void, i32 nodeIndex, eDoors door, bool withoutVisualEffect)
    DECL_THISCALL_TAIL(SetDoorDamage, nodeIndex, door, withoutVisualEffect)
    DECL_THISCALL_HEAD(SetHeliOrientation, _ZN11CAutomobile18SetHeliOrientationEf, void, float angle)
    DECL_THISCALL_TAIL(SetHeliOrientation, angle)
    DECL_THISCALL_HEAD(SetPanelDamage, _ZN11CAutomobile14SetPanelDamageEi7ePanelsb, void, i32 nodeIndex, ePanels panel, bool createWindowGlass)
    DECL_THISCALL_TAIL(SetPanelDamage, nodeIndex, panel, createWindowGlass)
    DECL_THISCALL_HEAD(SetTaxiLight, _ZN11CAutomobile12SetTaxiLightEb, void, bool enable)
    DECL_THISCALL_TAIL(SetTaxiLight, enable)
    DECL_THISCALL_HEAD(SpawnFlyingComponent, _ZN11CAutomobile20SpawnFlyingComponentEij, CObject*, i32 nodeIndex, u32 collisionType)
    DECL_THISCALL_TAIL(SpawnFlyingComponent, nodeIndex, collisionType)
    DECL_THISCALL_HEAD(TellHeliToGoToCoors, _ZN11CAutomobile19TellHeliToGoToCoorsEfffh, void, float x, float y, float z, u8 speed)
    DECL_THISCALL_TAIL(TellHeliToGoToCoors, x, y, z, speed)
    DECL_THISCALL_HEAD(TellPlaneToGoToCoors, _ZN11CAutomobile20TellPlaneToGoToCoorsEfffh, void, float x, float y, float z, u8 speed)
    DECL_THISCALL_TAIL(TellPlaneToGoToCoors, x, y, z, speed)
    DECL_THISCALL_HEAD(VehicleDamage, _ZN11CAutomobile13VehicleDamageEft, void, float intensity, u16 damagedPiece)
    DECL_THISCALL_TAIL(VehicleDamage, intensity, damagedPiece)

    // Static values
    DECL_VALUE_PLT_BOOL(m_sAllTaxiLights, BYBIT(0x395454, 0x578910));
    DECL_OBJECT_PLT(CVector, vecHunterGunPos, BYBIT(0x396D60, 0x57BAC0));

    // Member values
    CDamageManager m_carDamage;
    u8 bDamSwitch;
    CDoor m_aDoors[6];
    RwFrame* m_aCarNodes[CAR_NUM_NODES];
    CColPoint m_aWheelColPoints[4];
    float m_aSuspensionSpringRatio[4];
    float m_aSuspensionSpringRatioPrev[4];
    float m_aWheelTimer[4];
    float m_fUnknownValue;
    u32 m_aWheelSkidmarkType[4];
    bool m_aWheelSkidmarkBloody[4];
    bool m_aWheelSkidmarkUnk[4];
    float m_aWheelRotation[4];
    float m_aWheelPosition[4];
    float m_aWheelSpeed[4];
    u8 m_nUnknownValue;
    u8 bTaxiLight : 1;
    u8 bFixedColour : 1;
    u8 bBigWheels : 1;
    u8 bWaterTight : 1;
    u8 bNotDamagedUpsideDown : 1;
    u8 bMoreResistantToDamage : 1;
    u8 bTankDetonateCars : 1;
    u8 bStuckInSand : 1;
    u8 bHeliDestroyed : 1;
    i16 m_nDoingBurnout;
    u16 m_nHydraulicState;
    u32 m_nBusDoorTimerEnd;
    u32 m_nBusDoorTimerStart;
    float m_aSuspensionSpringLength[4];
    float m_aSuspensionLineLength[4];
    float m_fHeightAboveRoad;
    float m_fTraction;
    float m_fTireTemperature;
    float m_fOrientation;
    float m_fPlaneSteer;
    float m_fVelocityChangeForAudio;
    float m_afRandomValues[6];
    float m_fFireBlowUpTimer;
    CPhysical* m_aGroundPhysical[4];
    CVector m_aGroundOffset[4];
    CEntity* m_pSetOnFireEntity;
    float m_fWeaponDoorTimerLeft;
    float m_fWeaponDoorTimerRight;
    float m_fCarGunLR;
    float m_fCarGunUD;
    float m_fHeliOrientation;
    float m_fPropellerRotation;
    u32 uUnusedX;
    u8 m_nWheelsOnGround;
    u8 m_nDriveWheelsOnGround;
    u8 m_nDriveWheelsOnGroundPrev;
    float m_fGasPedalAudio;
    tWheelState m_aWheelState[4];
DECL_CLASS_END()
CHECKSIZE(CAutomobile, 0x5E0, 0x6F8);

#endif // __AML_PSDK_VCAUTOMOBILE_H
