#ifndef __AML_PSDK_VCVEHICLE_H
#define __AML_PSDK_VCVEHICLE_H

#include "../entity/Physical.h"
#include "../other/Weapon.h"
#include "AutoPilot.h"

struct CPed;
struct CPlayerPed;
struct CCopPed;
struct CFire;
struct tHandlingData;
struct tFlyingHandlingData;

enum eVehicleCreatedBy : u8
{
    RANDOM_VEHICLE = 1,
    MISSION_VEHICLE = 2,
    PARKED_VEHICLE = 3,
    PERMANENT_VEHICLE = 4
};

enum eVehicleType : u32
{
    VEHICLE_TYPE_AUTOMOBILE = 0,
    VEHICLE_TYPE_BOAT = 1,
    VEHICLE_TYPE_TRAIN = 2,
    VEHICLE_TYPE_HELI = 3,
    VEHICLE_TYPE_PLANE = 4,
    VEHICLE_TYPE_BIKE = 5
};

enum eVehicleApperance : u32
{
    VEHICLE_APPEARANCE_NONE = 0,
    VEHICLE_APPEARANCE_AUTOMOBILE = 1,
    VEHICLE_APPEARANCE_BIKE = 2,
    VEHICLE_APPEARANCE_HELI = 3,
    VEHICLE_APPEARANCE_BOAT = 4,
    VEHICLE_APPEARANCE_PLANE = 5
};

enum eDoorLock : u32
{
    DOORLOCK_NOT_USED = 0,
    DOORLOCK_UNLOCKED = 1,
    DOORLOCK_LOCKED = 2,
    DOORLOCK_LOCKOUT_PLAYER_ONLY = 3,
    DOORLOCK_LOCKED_PLAYER_INSIDE = 4,
    DOORLOCK_COP_CAR = 5,
    DOORLOCK_FORCE_SHUT_DOORS = 6,
    DOORLOCK_SKIP_SHUT_DOORS = 7
};

enum eDoors : u32
{
    DOOR_BONNET = 0,
    DOOR_BOOT = 1,
    DOOR_FRONT_LEFT = 2,
    DOOR_FRONT_RIGHT = 3,
    DOOR_REAR_LEFT = 4,
    DOOR_REAR_RIGHT = 5
};

enum eBombState : u8
{
    BOMB_NONE = 0,
    BOMB_TIMED_NOT_ACTIVATED = 1,
    BOMB_IGNITION = 2,
    BOMB_REMOTE = 3,
    BOMB_TIMED_ACTIVATED = 4,
    BOMB_IGNITION_ACTIVATED = 5
};

enum tWheelState : u32
{
    WHEEL_STATE_NORMAL = 0,
    WHEEL_STATE_SPINNING = 1,
    WHEEL_STATE_SKIDDING = 2,
    WHEEL_STATE_FIXED = 3
};

enum eFlightModel : u32
{
    FLIGHT_MODEL_DODO = 0,
    FLIGHT_MODEL_RCPLANE = 1,
    FLIGHT_MODEL_RCHELI = 2,
    FLIGHT_MODEL_SEAPLANE = 3,
    FLIGHT_MODEL_PLANE_UNUSED = 4,
    FLIGHT_MODEL_PLANE = 5,
    FLIGHT_MODEL_HELI = 6
};

enum eBikeWheelSpecial : u32
{
    BIKE_WHEELSPEC_0 = 0,
    BIKE_WHEELSPEC_1 = 1,
    BIKE_WHEELSPEC_2 = 2,
    BIKE_WHEELSPEC_3 = 3
};

DECL_CLASS_BASED(CVehicle, CPhysical)
    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CVehicle, _ZN8CVehicleC2Eh, u8 createdBy)
    DECL_CTORCALL_ARG_TAIL(createdBy)
    DECL_DTORCALL_VIRTUAL_SLOT(CVehicle, _ZN8CVehicleD2Ev, _ZN8CVehicle, _ZTV8CVehicle, 2);
    DECL_NEWCALL(CVehicle, BYBIT(_ZN8CVehiclenwEj, _ZN8CVehiclenwEm));
    DECL_DLCALL(CVehicle, _ZN8CVehicledlEPv);
    CVehicle(CVehicle const&) = delete;
    CVehicle& operator=(CVehicle const&) = delete;

    inline static void* operator new(size_t size, i32 poolRef) noexcept
    {
        static auto func = GetMainLibrarySymbol<void*(*)(size_t, i32)>(PSDK_STRINGIFY(BYBIT(_ZN8CVehiclenwEji, _ZN8CVehiclenwEmi)));
        return func(size, poolRef);
    }
    inline static void operator delete(void* memory, i32 poolRef) noexcept
    {
        static auto func = GetMainLibrarySymbol<void(*)(void*, i32)>("_ZN8CVehicledlEPvi");
        func(memory, poolRef);
    }

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(CVehicle, SetModelIndex, _ZTV8CVehicle, 4, void, u32 modelIndex)
    DECL_VIRTUALCALL_TAIL(modelIndex)
    DECL_VIRTUALCALL_HEAD(CVehicle, SetupLighting, _ZTV8CVehicle, 15, bool)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CVehicle, RemoveLighting, _ZTV8CVehicle, 16, void, bool resetWorldColors)
    DECL_VIRTUALCALL_TAIL(resetWorldColors)
    DECL_VIRTUALCALL_HEAD(CVehicle, FlagToDestroyWhenNextProcessed, _ZTV8CVehicle, 17, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CVehicle, ProcessControlInputs, _ZTV8CVehicle, 19, void, u8 playerNum)
    DECL_VIRTUALCALL_TAIL(playerNum)
    DECL_VIRTUALCALL_HEAD(CVehicle, GetComponentWorldPosition, _ZTV8CVehicle, 20, void, i32 componentId, CVector& position)
    DECL_VIRTUALCALL_TAIL(componentId, position)
    DECL_VIRTUALCALL_HEAD(CVehicle, IsComponentPresent, _ZTV8CVehicle, 21, bool, i32 componentId)
    DECL_VIRTUALCALL_TAIL(componentId)
    DECL_VIRTUALCALL_HEAD(CVehicle, SetComponentRotation, _ZTV8CVehicle, 22, void, i32 componentId, CVector rotation)
    DECL_VIRTUALCALL_TAIL(componentId, rotation)
    DECL_VIRTUALCALL_HEAD(CVehicle, OpenDoor, _ZTV8CVehicle, 23, void, i32 componentId, eDoors door, float ratio)
    DECL_VIRTUALCALL_TAIL(componentId, door, ratio)
    DECL_VIRTUALCALL_HEAD(CVehicle, ProcessOpenDoor, _ZTV8CVehicle, 24, void, u32 animId, u32 door, float time)
    DECL_VIRTUALCALL_TAIL(animId, door, time)
    DECL_VIRTUALCALL_HEAD(CVehicle, IsDoorReady, _ZTV8CVehicle, 25, bool, eDoors door)
    DECL_VIRTUALCALL_TAIL(door)
    DECL_VIRTUALCALL_HEAD(CVehicle, IsDoorFullyOpen, _ZTV8CVehicle, 26, bool, eDoors door)
    DECL_VIRTUALCALL_TAIL(door)
    DECL_VIRTUALCALL_HEAD(CVehicle, IsDoorClosed, _ZTV8CVehicle, 27, bool, eDoors door)
    DECL_VIRTUALCALL_TAIL(door)
    DECL_VIRTUALCALL_HEAD(CVehicle, IsDoorMissing, _ZTV8CVehicle, 28, bool, eDoors door)
    DECL_VIRTUALCALL_TAIL(door)
    DECL_VIRTUALCALL_HEAD(CVehicle, IsDoorReady, _ZTV8CVehicle, 29, bool, u32 door)
    DECL_VIRTUALCALL_TAIL(door)
    DECL_VIRTUALCALL_HEAD(CVehicle, IsDoorMissing, _ZTV8CVehicle, 30, bool, u32 door)
    DECL_VIRTUALCALL_TAIL(door)
    DECL_VIRTUALCALL_HEAD(CVehicle, IsOpenTopCar, _ZTV8CVehicle, 31, bool)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CVehicle, RemoveRefsToVehicle, _ZTV8CVehicle, 32, void, CEntity* entity)
    DECL_VIRTUALCALL_TAIL(entity)
    DECL_VIRTUALCALL_HEAD(CVehicle, BlowUpCar, _ZTV8CVehicle, 33, void, CEntity* damager)
    DECL_VIRTUALCALL_TAIL(damager)
    DECL_VIRTUALCALL_HEAD(CVehicle, SetUpWheelColModel, _ZTV8CVehicle, 34, bool, CColModel* colModel)
    DECL_VIRTUALCALL_TAIL(colModel)
    DECL_VIRTUALCALL_HEAD(CVehicle, BurstTyre, _ZTV8CVehicle, 35, void, u8 tyreId, bool applyForces)
    DECL_VIRTUALCALL_TAIL(tyreId, applyForces)
    DECL_VIRTUALCALL_HEAD(CVehicle, IsRoomForPedToLeaveCar, _ZTV8CVehicle, 36, bool, u32 componentId, CVector* forcedDoorPosition)
    DECL_VIRTUALCALL_TAIL(componentId, forcedDoorPosition)
    DECL_VIRTUALCALL_HEAD(CVehicle, IsClearToDriveAway, _ZTV8CVehicle, 37, bool)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CVehicle, GetHeightAboveRoad, _ZTV8CVehicle, 38, float)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CVehicle, PlayCarHorn, _ZTV8CVehicle, 39, void)
    DECL_VIRTUALCALL_TAIL()

    // Member functions
    DECL_THISCALL_SIMPLE(CanBeDeleted, _ZN8CVehicle12CanBeDeletedEv, bool);
    DECL_THISCALL_SIMPLE(CanDoorsBeDamaged, _ZN8CVehicle17CanDoorsBeDamagedEv, bool);
    DECL_THISCALL_SIMPLE(CanPedEnterCar, _ZN8CVehicle14CanPedEnterCarEv, bool);
    DECL_THISCALL_SIMPLE(CanPedJumpOffBike, _ZN8CVehicle17CanPedJumpOffBikeEv, bool);
    DECL_THISCALL_SIMPLE(CanPedJumpOutCar, _ZN8CVehicle16CanPedJumpOutCarEv, bool);
    DECL_THISCALL_SIMPLE(CarHasRoof, _ZN8CVehicle10CarHasRoofEv, bool);
    DECL_THISCALL_SIMPLE(DoFixedMachineGuns, _ZN8CVehicle18DoFixedMachineGunsEv, void);
    DECL_THISCALL_SIMPLE(DoSunGlare, _ZN8CVehicle10DoSunGlareEv, void);
    DECL_THISCALL_SIMPLE(ExtinguishCarFire, _ZN8CVehicle17ExtinguishCarFireEv, void);
    DECL_THISCALL_SIMPLE(FireFixedMachineGuns, _ZN8CVehicle20FireFixedMachineGunsEv, void);
    DECL_THISCALL_SIMPLE(GetVehicleAppearance, _ZN8CVehicle20GetVehicleAppearanceEv, eVehicleApperance);
    DECL_THISCALL_SIMPLE(IsLawEnforcementVehicle, _ZN8CVehicle23IsLawEnforcementVehicleEv, bool);
    DECL_THISCALL_SIMPLE(IsOnItsSide, _ZN8CVehicle11IsOnItsSideEv, bool);
    DECL_THISCALL_SIMPLE(IsVehicleNormal, _ZN8CVehicle15IsVehicleNormalEv, bool);
    DECL_THISCALL_SIMPLE(KillPedsInVehicle, _ZN8CVehicle17KillPedsInVehicleEv, void);
    DECL_THISCALL_SIMPLE(ProcessCarAlarm, _ZN8CVehicle15ProcessCarAlarmEv, void);
    DECL_THISCALL_SIMPLE(ProcessDelayedExplosion, _ZN8CVehicle23ProcessDelayedExplosionEv, void);
    DECL_THISCALL_SIMPLE(RemoveDriver, _ZN8CVehicle12RemoveDriverEv, void);
    DECL_THISCALL_SIMPLE(SetUpDriver, _ZN8CVehicle11SetUpDriverEv, CPed*);
    DECL_THISCALL_SIMPLE(ShufflePassengersToMakeSpace, _ZN8CVehicle28ShufflePassengersToMakeSpaceEv, bool);
    DECL_THISCALL_SIMPLE(UpdateClumpAlpha, _ZN8CVehicle16UpdateClumpAlphaEv, void);
    DECL_THISCALL_SIMPLE(UpdatePassengerList, _ZN8CVehicle19UpdatePassengerListEv, void);
    DECL_THISCALL_SIMPLE(UsesSiren, _ZN8CVehicle9UsesSirenEv, bool);
    DECL_THISCALL_SIMPLE(ActivateBomb, BYBIT(_ZN8CVehicle12ActivateBombEv, _ZN8CVehicle15ActivateCarBombEv), void);
    DECL_THISCALL_SIMPLE(ActivateBombWhenEntered, _ZN8CVehicle23ActivateBombWhenEnteredEv, void);
    DECL_THISCALL_HEAD(AddPassenger, _ZN8CVehicle12AddPassengerEP4CPed, bool, CPed* passenger)
    DECL_THISCALL_TAIL(AddPassenger, passenger)
    DECL_THISCALL_NAMED_HEAD(AddPassenger1, AddPassenger, _ZN8CVehicle12AddPassengerEP4CPedh, bool, CPed* passenger, u8 seat)
    DECL_THISCALL_TAIL(AddPassenger1, passenger, seat)
    DECL_THISCALL_HEAD(CanPedExitCar, _ZN8CVehicle13CanPedExitCarEb, bool, bool jumpOut)
    DECL_THISCALL_TAIL(CanPedExitCar, jumpOut)
    DECL_THISCALL_HEAD(CanPedOpenLocks, _ZN8CVehicle15CanPedOpenLocksEPK4CPed, bool, CPed const* ped)
    DECL_THISCALL_TAIL(CanPedOpenLocks, ped)
    DECL_THISCALL_HEAD(ChangeLawEnforcerState, _ZN8CVehicle22ChangeLawEnforcerStateEh, void, u8 state)
    DECL_THISCALL_TAIL(ChangeLawEnforcerState, state)
    DECL_THISCALL_HEAD(FindTyreNearestPoint, _ZN8CVehicle20FindTyreNearestPointEff, i32, float x, float y)
    DECL_THISCALL_TAIL(FindTyreNearestPoint, x, y)
    DECL_THISCALL_HEAD(FlyingControl, _ZN8CVehicle13FlyingControlE12eFlightModel, void, eFlightModel flightModel)
    DECL_THISCALL_TAIL(FlyingControl, flightModel)
    DECL_THISCALL_HEAD(InflictDamage, _ZN8CVehicle13InflictDamageEP7CEntity11eWeaponTypef7CVector, void, CEntity* damager, eWeaponType weapon, float intensity, CVector position)
    DECL_THISCALL_TAIL(InflictDamage, damager, weapon, intensity, position)
    DECL_THISCALL_HEAD(IsDriver, _ZN8CVehicle8IsDriverEP4CPed, bool, CPed* ped)
    DECL_THISCALL_TAIL(IsDriver, ped)
    DECL_THISCALL_NAMED_HEAD(IsDriver1, IsDriver, _ZN8CVehicle8IsDriverEi, bool, i32 modelIndex)
    DECL_THISCALL_TAIL(IsDriver1, modelIndex)
    DECL_THISCALL_HEAD(IsPassenger, _ZN8CVehicle11IsPassengerEP4CPed, bool, CPed* ped)
    DECL_THISCALL_TAIL(IsPassenger, ped)
    DECL_THISCALL_NAMED_HEAD(IsPassenger1, IsPassenger, _ZN8CVehicle11IsPassengerEi, bool, i32 modelIndex)
    DECL_THISCALL_TAIL(IsPassenger1, modelIndex)
    DECL_THISCALL_HEAD(IsSphereTouchingVehicle, _ZN8CVehicle23IsSphereTouchingVehicleEffff, bool, float x, float y, float z, float radius)
    DECL_THISCALL_TAIL(IsSphereTouchingVehicle, x, y, z, radius)
    DECL_THISCALL_HEAD(MakeNonDraggedPedsLeaveVehicle, _ZN8CVehicle30MakeNonDraggedPedsLeaveVehicleEP4CPedS1_RP10CPlayerPedRP7CCopPed, void, CPed* ped1, CPed* ped2, CPlayerPed*& player, CCopPed*& cop)
    DECL_THISCALL_TAIL(MakeNonDraggedPedsLeaveVehicle, ped1, ped2, player, cop)
    DECL_THISCALL_HEAD(RemovePassenger, _ZN8CVehicle15RemovePassengerEP4CPed, void, CPed* passenger)
    DECL_THISCALL_TAIL(RemovePassenger, passenger)
    DECL_THISCALL_HEAD(SetComponentAtomicAlpha, _ZN8CVehicle23SetComponentAtomicAlphaEP8RpAtomici, void, RpAtomic* atomic, i32 alpha)
    DECL_THISCALL_TAIL(SetComponentAtomicAlpha, atomic, alpha)
    DECL_THISCALL_HEAD(SetDriver, _ZN8CVehicle9SetDriverEP4CPed, void, CPed* driver)
    DECL_THISCALL_TAIL(SetDriver, driver)
    DECL_THISCALL_HEAD(SetupPassenger, _ZN8CVehicle14SetupPassengerEi, CPed*, i32 seat)
    DECL_THISCALL_TAIL(SetupPassenger, seat)
    DECL_THISCALL_HEAD(ProcessWheelRotation, _ZN8CVehicle20ProcessWheelRotationE11tWheelStateRK7CVectorS3_f, float, tWheelState wheelState, CVector const& forward, CVector const& speed, float radius)
    DECL_THISCALL_TAIL(ProcessWheelRotation, wheelState, forward, speed, radius)
    DECL_THISCALL_HEAD(ProcessWheel, _ZN8CVehicle12ProcessWheelER7CVectorS1_S1_S1_ifffcPfP11tWheelStatet, void, CVector& forward, CVector& right, CVector& contactSpeed, CVector& contactPoint, i32 wheelsOnGround, float thrust, float brake, float adhesion, char wheelId, float* wheelSpeed, tWheelState* wheelState, u16 wheelStatus)
    DECL_THISCALL_TAIL(ProcessWheel, forward, right, contactSpeed, contactPoint, wheelsOnGround, thrust, brake, adhesion, wheelId, wheelSpeed, wheelState, wheelStatus)
    DECL_THISCALL_HEAD(ProcessBikeWheel, _ZN8CVehicle16ProcessBikeWheelER7CVectorS1_S1_S1_iffffcPfP11tWheelState17eBikeWheelSpecialt, void, CVector& forward, CVector& right, CVector& contactSpeed, CVector& contactPoint, i32 wheelsOnGround, float thrust, float brake, float adhesion, float destabilization, char wheelId, float* wheelSpeed, tWheelState* wheelState, eBikeWheelSpecial special, u16 wheelStatus)
    DECL_THISCALL_TAIL(ProcessBikeWheel, forward, right, contactSpeed, contactPoint, wheelsOnGround, thrust, brake, adhesion, destabilization, wheelId, wheelSpeed, wheelState, special, wheelStatus)
    DECL_THISCALL_HEAD(DoBladeCollision, _ZN8CVehicle16DoBladeCollisionE7CVectorR7CMatrixsff, bool, CVector position, CMatrix& matrix, i16 rotorType, float radius, float damageMultiplier)
    DECL_THISCALL_TAIL(DoBladeCollision, position, matrix, rotorType, radius, damageMultiplier)
    DECL_THISCALL_HEAD(BladeColSectorList, _ZN8CVehicle18BladeColSectorListER8CPtrListR9CColModelR7CMatrixsf, bool, CPtrList& list, CColModel& colModel, CMatrix& matrix, i16 rotorType, float damageMultiplier)
    DECL_THISCALL_TAIL(BladeColSectorList, list, colModel, matrix, rotorType, damageMultiplier)
    inline bool IsUpsideDown() const
    {
        static auto func = GetMainLibrarySymbol<bool(*)(CVehicle const*)>("_ZNK8CVehicle12IsUpsideDownEv");
        return func(this);
    }

    // STATIC functions
    DECL_FASTCALL_SIMPLE(HeliDustGenerate, _ZN8CVehicle16HeliDustGenerateEP7CEntityffi, void, CEntity* entity, float radius, float intensity, i32 type);

    // Helper functions
    inline bool IsAutomobile() const { return m_nVehicleClass == VEHICLE_TYPE_AUTOMOBILE; }
    inline bool IsBoat() const { return m_nVehicleClass == VEHICLE_TYPE_BOAT; }
    inline bool IsTrain() const { return m_nVehicleClass == VEHICLE_TYPE_TRAIN; }
    inline bool IsHeli() const { return m_nVehicleClass == VEHICLE_TYPE_HELI; }
    inline bool IsPlane() const { return m_nVehicleClass == VEHICLE_TYPE_PLANE; }
    inline bool IsBike() const { return m_nVehicleClass == VEHICLE_TYPE_BIKE; }

    // STATIC values
    DECL_VALUE_PLT_BOOL(bDisableRemoteDetonation, BYBIT(0x394B44, 0x577770));
    DECL_VALUE_PLT_BOOL(bCheat9, BYBIT(0x394B9C, 0x577810));
    DECL_VALUE_PLT_BOOL(bAllDodosCheat, BYBIT(0x394CBC, 0x577A48));
    DECL_VALUE_PLT_BOOL(bDisableRemoteDetonationOnContact, BYBIT(0x3951A4, 0x5783A0));
    DECL_VALUE_PLT_BOOL(bHoverCheat, BYBIT(0x3953B8, 0x5787D0));
    DECL_VALUE_PLT_BOOL(bCheat8, BYBIT(0x3953CC, 0x5787F8));
    DECL_VALUE_PLT_BOOL(bCheat5, BYBIT(0x3955C4, 0x578BF0));
    DECL_VALUE_PLT_BOOL(bAllTaxisHaveNitro, BYBIT(0x395E68, 0x579D08));
    DECL_VALUE_PLT_BOOL(m_bDisableMouseSteering, BYBIT(0x396404, 0x57A7F0));
    DECL_VALUE_PLT_BOOL(bCheat3, BYBIT(0x3966EC, 0x57ADE0));
    DECL_VALUE_PLT_BOOL(bWheelsOnlyCheat, BYBIT(0x396B8C, 0x57B710));

    // Member values
    tHandlingData* m_pHandlingData;
    tFlyingHandlingData* m_pFlyingHandling;
    CAutoPilot m_autoPilot;
    u8 m_nPrimaryColor;
    u8 m_nSecondaryColor;
    i8 m_anExtras[2];
    u16 m_nAlarmState;
    u16 m_nRouteSeed;
    CPed* m_pDriver;
    CPed* m_passengers[8];
    u8 m_nNumPassengers;
    u8 m_nNumGettingIn;
    u8 m_nGettingInFlags;
    u8 m_nGettingOutFlags;
    u8 m_nMaxPassengers;
    u32 m_nUnknownValue;
    CVector m_vecUnknownValue;
    CEntity* m_pEntityWeAreOn;
    CFire* m_pFire;
    float m_fSteerAngle;
    float m_fGasPedal;
    float m_fBreakPedal;
    eVehicleCreatedBy m_nCreatedBy;

    u8 bIsLawEnforcementVeh : 1;
    u8 bIsAmbulanceOnDuty : 1;
    u8 bIsFireTruckOnDuty : 1;
    u8 bIsLocked : 1;
    u8 bEngineOn : 1;
    u8 bIsHandbrakeOn : 1;
    u8 bLightsOn : 1;
    u8 bFreebies : 1;
    u8 bIsVan : 1;
    u8 bIsBus : 1;
    u8 bIsBig : 1;
    u8 bLowVehicle : 1;
    u8 bComedyControls : 1;
    u8 bWarnedPeds : 1;
    u8 bCraneMessageDone : 1;
    u8 bExtendedRange : 1;
    u8 bTakeLessDamage : 1;
    u8 bIsDamaged : 1;
    u8 bHasBeenOwnedByPlayer : 1;
    u8 bFadeOut : 1;
    u8 bIsBeingCarJacked : 1;
    u8 bSpawnCops : 1;
    u8 bCanBeDamaged : 1;
    u8 bUsePlayerColModel : 1;
    u8 bOccupantsHaveBeenGenerated : 1;
    u8 bGunSwitchedOff : 1;
    u8 bVehicleColProcessed : 1;
    u8 bIsCarParkVehicle : 1;
    u8 bHasAlreadyBeenRecorded : 1;
    u8 bPartOfConvoy : 1;
    u8 bHeliMinimumTilt : 1;
    u8 bAudioChangingGear : 1;
    u8 bIsDrowning : 1;
    u8 bCarTiresInvulnerable : 1;
    u8 bCreatedAsPoliceVehicle : 1;
    u8 bRestingOnPhysical : 1;
    u8 bParking : 1;
    u8 bCanPark : 1;
    u8 : 2;
    u8 m_nBombType : 3;
    u8 bDriverLastFrame : 1;
    u8 : 4;

    i8 m_nPedsUsingAsCover;
    u8 m_nAmmoInClip;
    i8 m_nPacManPickupsCarried;
    u8 m_nRoadblockType;
    float m_fHealth;
    u8 m_nCurrentGear;
    float m_fChangeGearTime;
    CEntity* m_pBombRigger;
    u32 m_nTimeTillWeNeedThisCar;
    u32 m_nGunFiringTime;
    u32 m_nTimeOfDeath;
    u16 m_nTimeBlocked;
    u16 m_wBombTimer;
    CEntity* m_pBlowUpEntity;
    float m_fMapObjectHeightAhead;
    float m_fMapObjectHeightBehind;
    eDoorLock m_eDoorLock;
    i8 m_nLastWeaponDamage;
    CEntity* pLastDamEntity;
    u8 m_nRadioStation;
    u8 m_nRainAudioCounter;
    u8 m_nRainSamplesCounter;
    u32 m_nCarHornTimer;
    u8 m_nCarHornPattern;
    bool m_nSirenOrAlarm;
    u8 m_nSirenExtra;
    i8 m_nComedyControlState;
    CStoredCollPoly m_frontCollPoly;
    CStoredCollPoly m_rearCollPoly;
    float m_fSteerRatio;
    eVehicleType m_nVehicleClass;
DECL_CLASS_END()
CHECKSIZE(CVehicle, 0x2A4, 0x358);

#define bDisableRemoteDetonation bDisableRemoteDetonation()
#define bCheat9 bCheat9()
#define bAllDodosCheat bAllDodosCheat()
#define bDisableRemoteDetonationOnContact bDisableRemoteDetonationOnContact()
#define bHoverCheat bHoverCheat()
#define bCheat8 bCheat8()
#define bCheat5 bCheat5()
#define bAllTaxisHaveNitro bAllTaxisHaveNitro()
#define m_bDisableMouseSteering m_bDisableMouseSteering()
#define bCheat3 bCheat3()
#define bWheelsOnlyCheat bWheelsOnlyCheat()

#endif // __AML_PSDK_VCVEHICLE_H
