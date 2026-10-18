#ifndef __AML_PSDK_SAVEHICLE_H
#define __AML_PSDK_SAVEHICLE_H

#include "Physical.h"
#include "Weapon.h"
#include "../audio/AEAudioEntity.h"
#include "../enum/Handling.h"
#include "../enum/CarMission.h"
#include "../enum/Vehicles.h"

struct CPed;
struct CVehicle;
struct tHandlingData;
struct tFlyingHandlingData;
struct CFire;
struct RwTexture;
struct RwObject;
struct RwFrame;
struct RpMaterial;
struct RpAtomic;
struct CAutomobile;
struct CMonsterTruck;
struct CQuadBike;
struct CHeli;
struct CPlane;
struct CBoat;
struct CTrain;
struct CBike;
struct CBmx;
struct CTrailer;
struct tBoatHandlingData;
struct CVehicleModelInfo;
struct CBaseModelInfo;
struct UpgradePosnDesc;

enum eCarWeapon
{
    CAR_WEAPON_NOT_USED,
    CAR_WEAPON_HEAVY_GUN,
    CAR_WEAPON_FREEFALL_BOMB,
    CAR_WEAPON_LOCK_ON_ROCKET,
    CAR_WEAPON_DOUBLE_ROCKET
};

enum eDoorLock : unsigned int
{
    DOORLOCK_NOT_USED,
    DOORLOCK_UNLOCKED,
    DOORLOCK_LOCKED,
    DOORLOCK_LOCKOUT_PLAYER_ONLY,
    DOORLOCK_LOCKED_PLAYER_INSIDE,
    DOORLOCK_COP_CAR,
    DOORLOCK_FORCE_SHUT_DOORS,
    DOORLOCK_SKIP_SHUT_DOORS
};

enum eVehicleApperance
{
    VEHICLE_APPEARANCE_AUTOMOBILE = 1,
    VEHICLE_APPEARANCE_BIKE,
    VEHICLE_APPEARANCE_HELI,
    VEHICLE_APPEARANCE_BOAT,
    VEHICLE_APPEARANCE_PLANE,
};

enum eVehicleLightsFlags
{
    VEHICLE_LIGHTS_TWIN = 1,
    VEHICLE_LIGHTS_IGNORE_DAMAGE = 4,
    VEHICLE_LIGHTS_DISABLE_FRONT = 16,
    VEHICLE_LIGHTS_DISABLE_REAR = 32
};

enum eVehicleCreatedBy
{
    RANDOM_VEHICLE = 1,
    MISSION_VEHICLE = 2,
    PARKED_VEHICLE = 3,
    PERMANENT_VEHICLE = 4
};

enum eBombState
{
    BOMB_TIMED_NOT_ACTIVATED = 1,
    BOMB_IGNITION = 2,
    BOMB_STICKY = 3,
    BOMB_TIMED_ACTIVATED = 4,
    BOMB_IGNITION_ACTIVATED = 5
};

enum eDoors : int
{
    BONNET = 0x0,
    BOOT = 0x1,
    FRONT_LEFT_DOOR = 0x2,
    FRONT_RIGHT_DOOR = 0x3,
    REAR_LEFT_DOOR = 0x4,
    REAR_RIGHT_DOOR = 0x5,
    MAX_DOORS = 0x6,
};

enum eCarDrivingStyle : signed char
{
    DRIVINGSTYLE_STOP_FOR_CARS,
    DRIVINGSTYLE_SLOW_DOWN_FOR_CARS,
    DRIVINGSTYLE_AVOID_CARS,
    DRIVINGSTYLE_PLOUGH_THROUGH,
    DRIVINGSTYLE_STOP_FOR_CARS_IGNORE_LIGHTS
};

enum eDoorState : unsigned char
{
    DOOR_NOTHING,
    DOOR_HIT_MAX_END,
    DOOR_HIT_MIN_END,
    DOOR_POP_OPEN,
    DOOR_SLAM_SHUT
};

DECL_CLASS(CRideAnimData)
    // Construct/Deconstruct functions
    DECL_CTORCALL(CRideAnimData, _ZN13CRideAnimDataC2Ev);
    DECL_DTORCALL(CRideAnimData, _ZN13CRideAnimDataD2Ev);

    unsigned int m_nAnimGroup;
    float        m_fSteerAngle;
    float        m_fAnimLean;
    float        m_fDesiredAnimLean;
    float        m_fLeanFwd;
    union
    {
        float m_fAnimLeanLeft;
        float    m_fHandlebarsAngle;
    };
    union
    {
        float    m_fAnimLeanFwd;
        float    m_fAnimPercentageState;
    };
DECL_CLASS_END()

DECL_CLASS(CDoor)
    // STATIC values
    DECL_VALUE_PLT_FLT(DOOR_SPEED_MAX_CAPPED, BYBIT(0x677BC8, 0x84D7B0));

    // Member functions
    DECL_THISCALL_SIMPLE(GetAngleOpenRatio, _ZNK5CDoor17GetAngleOpenRatioEv, float);
    DECL_THISCALL_SIMPLE(IsClosed, _ZNK5CDoor8IsClosedEv, bool);
    DECL_THISCALL_SIMPLE(IsFullyOpen, _ZNK5CDoor11IsFullyOpenEv, bool);

    DECL_THISCALL_HEAD(Process, _ZN5CDoor7ProcessEP8CVehicleR7CVectorS3_S3_, bool, CVehicle *pVehicle, CVector &vecOldMoveSpeed, CVector &vecOldTurnSpeed, CVector &vecOffset)
    DECL_THISCALL_TAIL(Process, pVehicle, vecOldMoveSpeed, vecOldTurnSpeed, vecOffset)

    DECL_THISCALL_HEAD(ProcessImpact, _ZN5CDoor13ProcessImpactEP8CVehicleR7CVectorS3_S3_, bool, CVehicle *pVehicle, CVector &vecOldMoveSpeed, CVector &vecOldTurnSpeed, CVector &vecOffset)
    DECL_THISCALL_TAIL(ProcessImpact, pVehicle, vecOldMoveSpeed, vecOldTurnSpeed, vecOffset)

    DECL_THISCALL_HEAD(Open, _ZN5CDoor4OpenEf, void, float fAngRatio)
    DECL_THISCALL_TAIL(Open, fAngRatio)

    // Member values
    float         m_fOpenAngle;
    float         m_fClosedAngle;
    unsigned short m_nDirn;
    unsigned char m_nAxis;
    eDoorState m_nDoorState;
    float         m_fAngle;
    float         m_fPrevAngle;
    float         m_fAngVel;
DECL_CLASS_END()

DECL_CLASS(CAutoPilot)
    // Member functions
    DECL_THISCALL_HEAD(ModifySpeed, _ZN10CAutoPilot11ModifySpeedEf, void, float arg1)
    DECL_THISCALL_TAIL(ModifySpeed, arg1)
    DECL_THISCALL_SIMPLE(RemoveOnePathNode, _ZN10CAutoPilot17RemoveOnePathNodeEv, void);

    CNodeAddress         m_currentAddress;
    CNodeAddress         m_startingRouteNode;
    CNodeAddress         m_preStartingRouteNode;
    int                  m_nStartSpeedScaleFactor;
    int                  m_nSpeedScaleFactor;
    CCarPathLinkAddress  m_nCurrentPathNodeInfo;
    CCarPathLinkAddress  m_nNextPathNodeInfo;
    CCarPathLinkAddress  m_nPreviousPathNodeInfo;
    unsigned int         m_nTimeToStartMission;
    unsigned int         m_nTimeSwitchedToRealPhysics;
    signed char          _smthPreCurr;
    signed char          _smthCurr;
    signed char          _smthNext;
    signed char          m_nCurrentLane;
    signed char          m_nNextLane;
    eCarDrivingStyle     m_nCarDrivingStyle;
    eCarMission          m_nCarMission;
    signed char          m_nTempAction;
    unsigned int         m_nTempActionTime;
    unsigned int         _someStartTime;
    unsigned char        m_nReverseType;
    unsigned char        m_nTimesWantToChangeNode;
    float                m_fActualTrafficSpeed;
    float                m_fMaxTrafficSpeed;
    unsigned char        m_nCruiseSpeed;
    signed char          m_nSpeedFromNodes;
    float                m_fSpeedMult;
    unsigned char        m_nHooverDistFromTarget;
    signed char          heliThrustPower;
    signed char          m_nMoveAheadOfTarget;
    union
    {
        unsigned char    m_nCarCtrlFlags;
        struct
        {
            unsigned char SlowingDownForCar : 1;
            unsigned char SlowingDownForPed : 1;
            unsigned char AvoidLevelTransitions : 1;
            unsigned char bAlwaysInFastLane : 1;
            unsigned char bAlwaysInSlowLane : 1;
            unsigned char bWarnTargetEntity : 1;
            unsigned char bDontGoAgainstTraffic : 1;
            unsigned char bLeaveAfterAWhile : 1;
            unsigned char bWaitForValidNodes : 1;
            unsigned char bCarHasToReverseFirst : 1;
        };
    };
    unsigned char        m_nSwitchToStraightLineDistance;
    unsigned char        m_nStraightLineDistance;
    unsigned char        m_nTargetReachedDistance;
    signed char          m_nLaneChangeCounter;
    signed char          m_nFloatingFrames;
    short                m_nAreaConstrainX[2];
    short                m_nAreaConstrainY[2];
    CVector              m_vecDestinationCoors;
    CNodeAddress         m_aPathFindNodesInfo[8];
    short                m_nPathFindNodesCount;
    CEntity             *m_pTargetCar;
    CEntity             *m_pCarWeMakingSlowDownFor;
    signed char          m_nRecordingId;
    signed char          m_nDiversion;
DECL_CLASS_END()



DECL_CLASS_BASED(CVehicle, CPhysical)
    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CVehicle, _ZN8CVehicleC2Eh, u8 createdBy)
    DECL_CTORCALL_ARG_TAIL(createdBy)
    DECL_DTORCALL_VIRTUAL(CVehicle, _ZN8CVehicleD2Ev, _ZN8CVehicle, _ZTV8CVehicle);
    DECL_NEWCALL(CVehicle, BYBIT(_ZN8CVehiclenwEj, _ZN8CVehiclenwEm) );
    DECL_DLCALL(CVehicle, _ZN8CVehicledlEPv);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(CVehicle, ProcessControlCollisionCheck, _ZTV8CVehicle, 24, void, bool arg1)
    DECL_VIRTUALCALL_TAIL(arg1)
    DECL_VIRTUALCALL_HEAD(CVehicle, ProcessControlInputs, _ZTV8CVehicle, 25, void, unsigned char arg1)
    DECL_VIRTUALCALL_TAIL(arg1)
    DECL_VIRTUALCALL_HEAD(CVehicle, GetComponentWorldPosition, _ZTV8CVehicle, 26, void, int arg1, CVector & arg2)
    DECL_VIRTUALCALL_TAIL(arg1, arg2)
    DECL_VIRTUALCALL_CONST_HEAD(CVehicle, IsComponentPresent, _ZTV8CVehicle, 27, bool, int arg1)
    DECL_VIRTUALCALL_TAIL(arg1)
    DECL_VIRTUALCALL_HEAD(CVehicle, OpenDoor, _ZTV8CVehicle, 28, void, CPed * arg1, int arg2, eDoors arg3, float arg4, bool arg5)
    DECL_VIRTUALCALL_TAIL(arg1, arg2, arg3, arg4, arg5)
    DECL_VIRTUALCALL_HEAD(CVehicle, ProcessOpenDoor, _ZTV8CVehicle, 29, void, CPed * arg1, unsigned int arg2, unsigned int arg3, unsigned int arg4, float arg5)
    DECL_VIRTUALCALL_TAIL(arg1, arg2, arg3, arg4, arg5)
    DECL_VIRTUALCALL_CONST_HEAD(CVehicle, GetDooorAngleOpenRatio, _ZTV8CVehicle, 30, float, eDoors arg1)
    DECL_VIRTUALCALL_TAIL(arg1)
    DECL_VIRTUALCALL_CONST_HEAD(CVehicle, IsDoorReady, _ZTV8CVehicle, 31, bool, eDoors arg1)
    DECL_VIRTUALCALL_TAIL(arg1)
    DECL_VIRTUALCALL_CONST_HEAD(CVehicle, IsDoorFullyOpen, _ZTV8CVehicle, 32, bool, eDoors arg1)
    DECL_VIRTUALCALL_TAIL(arg1)
    DECL_VIRTUALCALL_CONST_HEAD(CVehicle, IsDoorClosed, _ZTV8CVehicle, 33, bool, eDoors arg1)
    DECL_VIRTUALCALL_TAIL(arg1)
    DECL_VIRTUALCALL_CONST_HEAD(CVehicle, IsDoorMissing, _ZTV8CVehicle, 34, bool, eDoors arg1)
    DECL_VIRTUALCALL_TAIL(arg1)
    DECL_VIRTUALCALL_CONST_HEAD(CVehicle, GetDooorAngleOpenRatio, _ZTV8CVehicle, 35, float, unsigned int arg1)
    DECL_VIRTUALCALL_TAIL(arg1)
    DECL_VIRTUALCALL_CONST_HEAD(CVehicle, IsDoorReady, _ZTV8CVehicle, 36, bool, unsigned int arg1)
    DECL_VIRTUALCALL_TAIL(arg1)
    DECL_VIRTUALCALL_CONST_HEAD(CVehicle, IsDoorFullyOpen, _ZTV8CVehicle, 37, bool, unsigned int arg1)
    DECL_VIRTUALCALL_TAIL(arg1)
    DECL_VIRTUALCALL_CONST_HEAD(CVehicle, IsDoorClosed, _ZTV8CVehicle, 38, bool, unsigned int arg1)
    DECL_VIRTUALCALL_TAIL(arg1)
    DECL_VIRTUALCALL_CONST_HEAD(CVehicle, IsDoorMissing, _ZTV8CVehicle, 39, bool, unsigned int arg1)
    DECL_VIRTUALCALL_TAIL(arg1)
    DECL_VIRTUALCALL_CONST_HEAD(CVehicle, IsOpenTopCar, _ZTV8CVehicle, 40, bool)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CVehicle, RemoveRefsToVehicle, _ZTV8CVehicle, 41, void, CEntity * arg1)
    DECL_VIRTUALCALL_TAIL(arg1)
    DECL_VIRTUALCALL_HEAD(CVehicle, BlowUpCar, _ZTV8CVehicle, 42, void, CEntity * arg1, unsigned char arg2)
    DECL_VIRTUALCALL_TAIL(arg1, arg2)
    DECL_VIRTUALCALL_HEAD(CVehicle, BlowUpCarCutSceneNoExtras, _ZTV8CVehicle, 43, void, bool arg1, bool arg2, bool arg3, bool arg4)
    DECL_VIRTUALCALL_TAIL(arg1, arg2, arg3, arg4)
    DECL_VIRTUALCALL_HEAD(CVehicle, SetUpWheelColModel, _ZTV8CVehicle, 44, bool, CColModel * arg1)
    DECL_VIRTUALCALL_TAIL(arg1)
    DECL_VIRTUALCALL_HEAD(CVehicle, BurstTyre, _ZTV8CVehicle, 45, bool, unsigned char arg1, bool arg2)
    DECL_VIRTUALCALL_TAIL(arg1, arg2)
    DECL_VIRTUALCALL_HEAD(CVehicle, IsRoomForPedToLeaveCar, _ZTV8CVehicle, 46, bool, unsigned int arg1, CVector * arg2)
    DECL_VIRTUALCALL_TAIL(arg1, arg2)
    DECL_VIRTUALCALL_HEAD(CVehicle, ProcessDrivingAnims, _ZTV8CVehicle, 47, void, CPed * arg1, unsigned char arg2)
    DECL_VIRTUALCALL_TAIL(arg1, arg2)
    DECL_VIRTUALCALL_HEAD(CVehicle, GetRideAnimData, _ZTV8CVehicle, 48, CRideAnimData*)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CVehicle, SetupSuspensionLines, _ZTV8CVehicle, 49, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CVehicle, AddMovingCollisionSpeed, _ZTV8CVehicle, 50, CVector, CVector & arg1)
    DECL_VIRTUALCALL_TAIL(arg1)
    DECL_VIRTUALCALL_HEAD(CVehicle, Fix, _ZTV8CVehicle, 51, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CVehicle, SetupDamageAfterLoad, _ZTV8CVehicle, 52, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CVehicle, DoBurstAndSoftGroundRatios, _ZTV8CVehicle, 53, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CVehicle, GetHeightAboveRoad, _ZTV8CVehicle, 54, float)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CVehicle, PlayCarHorn, _ZTV8CVehicle, 55, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CVehicle, GetNumContactWheels, _ZTV8CVehicle, 56, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CVehicle, VehicleDamage, _ZTV8CVehicle, 57, void, float arg1, unsigned short arg2, CEntity * arg3, CVector * arg4, CVector * arg5, eWeaponType arg6)
    DECL_VIRTUALCALL_TAIL(arg1, arg2, arg3, arg4, arg5, arg6)
    DECL_VIRTUALCALL_CONST_HEAD(CVehicle, CanPedStepOutCar, _ZTV8CVehicle, 58, bool, bool arg1)
    DECL_VIRTUALCALL_TAIL(arg1)
    DECL_VIRTUALCALL_CONST_HEAD(CVehicle, CanPedJumpOutCar, _ZTV8CVehicle, 59, bool, CPed * arg1)
    DECL_VIRTUALCALL_TAIL(arg1)
    DECL_VIRTUALCALL_HEAD(CVehicle, GetTowHitchPos, _ZTV8CVehicle, 60, bool, CVector & arg1, bool arg2, CVehicle* arg3)
    DECL_VIRTUALCALL_TAIL(arg1, arg2, arg3)
    DECL_VIRTUALCALL_HEAD(CVehicle, GetTowBarPos, _ZTV8CVehicle, 61, bool, CVector & arg1, bool arg2, CVehicle* arg3)
    DECL_VIRTUALCALL_TAIL(arg1, arg2, arg3)
    DECL_VIRTUALCALL_HEAD(CVehicle, SetTowLink, _ZTV8CVehicle, 62, bool, CVehicle* arg1, bool arg2)
    DECL_VIRTUALCALL_TAIL(arg1, arg2)
    DECL_VIRTUALCALL_HEAD(CVehicle, BreakTowLink, _ZTV8CVehicle, 63, bool)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CVehicle, FindWheelWidth, _ZTV8CVehicle, 64, float, bool arg1)
    DECL_VIRTUALCALL_TAIL(arg1)
    DECL_VIRTUALCALL_HEAD(CVehicle, Save, _ZTV8CVehicle, 65, bool)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CVehicle, Load, _ZTV8CVehicle, 66, bool)
    DECL_VIRTUALCALL_TAIL()

    // STATIC functions
    DECL_FASTCALL_SIMPLE(Shutdown, _ZN8CVehicle8ShutdownEv, void);
    DECL_FASTCALL_SIMPLE(SetComponentAtomicAlpha, _ZN8CVehicle23SetComponentAtomicAlphaEP8RpAtomici, void, RpAtomic* atomic, i32 alpha);
    DECL_FASTCALL_SIMPLE(SetTappedGasTankVehicle, _ZN8CVehicle23SetTappedGasTankVehicleEP7CEntity, void, CEntity* pTappedGasTankVehicle);

    // STATIC values
    DECL_VALUE_PLT_FLT(WHEELSPIN_TARGET_RATE, BYBIT(0x677194, 0x84C358));
    DECL_VALUE_PLT_FLT(WHEELSPIN_INAIR_TARGET_RATE, BYBIT(0x677000, 0x84C038));
    DECL_VALUE_PLT_FLT(WHEELSPIN_RISE_RATE, BYBIT(0x67811C, 0x84E250));
    DECL_VALUE_PLT_FLT(WHEELSPIN_FALL_RATE, BYBIT(0x676BF0, 0x84B828));
    DECL_VALUE_PLT_U8(ms_forceVehicleLightsOff, BYBIT(0x679D90, 0x851B38));
    DECL_VALUE_PLT_BOOL(s_bPlaneGunsEjectShellCasings, BYBIT(0x676740, 0x84AED8));
    DECL_VALUE_PLT_FLT(m_fAirResistanceMult, BYBIT(0x678FAC, 0x84FF80));
    DECL_VALUE_PLT_FLT(ms_fRailTrackResistance, BYBIT(0x6787AC, 0x84EF80));
    DECL_VALUE_PLT_FLT(ms_fRailTrackResistanceDefault, BYBIT(0x679A78, 0x851510));
    DECL_VALUE_PLT_BOOL(bDisableRemoteDetonation, BYBIT(0x677384, 0x84C740));
    DECL_VALUE_PLT_BOOL(bDisableRemoteDetonationOnContact, BYBIT(0x676F18, 0x84BE70));
    DECL_VALUE_PLT_BOOL(m_bEnableMouseSteering, BYBIT(0x676FEC, 0x84C010));
    DECL_VALUE_PLT_BOOL(m_bEnableMouseFlying, BYBIT(0x677014, 0x84C060));
    DECL_OBJECT_ARRAY_PLT(CColModel, m_aSpecialColModel, BYBIT(0x675F1C, 0x849EA8));
    DECL_OBJECT_ARRAY_PLT(CVehicle*, m_aSpecialColVehicle, BYBIT(0x677D90, 0x84DB40));
    DECL_OBJECT_PLT(CEntity*, m_pTappedGasTankVehicle, BYBIT(0x67951C, 0x850A48));

    // Member functions
    DECL_THISCALL_SIMPLE(GetHasDualExhausts, _ZN8CVehicle18GetHasDualExhaustsEv, bool);
    DECL_THISCALL_SIMPLE(GetNewSteeringAmt, _ZN8CVehicle17GetNewSteeringAmtEv, float);
    DECL_THISCALL_SIMPLE(SetupRender, _ZN8CVehicle11SetupRenderEv, void);
    DECL_THISCALL_SIMPLE(ResetAfterRender, _ZN8CVehicle16ResetAfterRenderEv, void);
    DECL_THISCALL_SIMPLE(CanBeDeleted, _ZNK8CVehicle12CanBeDeletedEv, u8);
    DECL_THISCALL_HEAD(SetRemapTexDictionary, _ZN8CVehicle21SetRemapTexDictionaryEPKc, void, char const* txdId)
    DECL_THISCALL_TAIL(SetRemapTexDictionary, txdId)
    DECL_THISCALL_SIMPLE(GetRemapIndex, _ZN8CVehicle13GetRemapIndexEv, i32);
    DECL_THISCALL_HEAD(SetRemap, _ZN8CVehicle8SetRemapEi, void, i32 remapIndex)
    DECL_THISCALL_TAIL(SetRemap, remapIndex)
    DECL_THISCALL_SIMPLE(DoDriveByShootings, _ZN8CVehicle18DoDriveByShootingsEv, void);
    DECL_THISCALL_SIMPLE(UpdateClumpAlpha, _ZN8CVehicle16UpdateClumpAlphaEv, void);
    DECL_THISCALL_SIMPLE(KillPedsInVehicle, _ZN8CVehicle17KillPedsInVehicleEv, void);
    DECL_THISCALL_SIMPLE(KillPedsGettingInVehicle, _ZN8CVehicle24KillPedsGettingInVehicleEv, void);
    DECL_THISCALL_SIMPLE(ActivateBomb, _ZN8CVehicle12ActivateBombEv, void);
    DECL_THISCALL_SIMPLE(ActivateBombWhenEntered, _ZN8CVehicle23ActivateBombWhenEnteredEv, void);
    DECL_THISCALL_SIMPLE(ProcessDelayedExplosion, _ZN8CVehicle23ProcessDelayedExplosionEv, void);
    DECL_THISCALL_HEAD(SetGettingInFlags, _ZN8CVehicle17SetGettingInFlagsEh, void, u8 doorId)
    DECL_THISCALL_TAIL(SetGettingInFlags, doorId)
    DECL_THISCALL_HEAD(SetGettingOutFlags, _ZN8CVehicle18SetGettingOutFlagsEh, void, u8 doorId)
    DECL_THISCALL_TAIL(SetGettingOutFlags, doorId)
    DECL_THISCALL_HEAD(ClearGettingInFlags, _ZN8CVehicle19ClearGettingInFlagsEh, void, u8 doorId)
    DECL_THISCALL_TAIL(ClearGettingInFlags, doorId)
    DECL_THISCALL_HEAD(ClearGettingOutFlags, _ZN8CVehicle20ClearGettingOutFlagsEh, void, u8 doorId)
    DECL_THISCALL_TAIL(ClearGettingOutFlags, doorId)
    DECL_THISCALL_NAMED_HEAD(AddPassenger1, AddPassenger, _ZN8CVehicle12AddPassengerEP4CPed, bool, CPed* passenger)
    DECL_THISCALL_TAIL(AddPassenger1, passenger)
    DECL_THISCALL_NAMED_HEAD(AddPassenger2, AddPassenger, _ZN8CVehicle12AddPassengerEP4CPedh, bool, CPed* passenger, u8 seatNumber)
    DECL_THISCALL_TAIL(AddPassenger2, passenger, seatNumber)
    DECL_THISCALL_HEAD(RemovePassenger, _ZN8CVehicle15RemovePassengerEP4CPed, void, CPed* passenger)
    DECL_THISCALL_TAIL(RemovePassenger, passenger)
    DECL_THISCALL_HEAD(SetDriver, _ZN8CVehicle9SetDriverEP4CPed, void, CPed* driver)
    DECL_THISCALL_TAIL(SetDriver, driver)
    DECL_THISCALL_HEAD(RemoveDriver, _ZN8CVehicle12RemoveDriverEb, void, bool arg0)
    DECL_THISCALL_TAIL(RemoveDriver, arg0)
    DECL_THISCALL_HEAD(SetUpDriver, _ZN8CVehicle11SetUpDriverEibb, CPed*, i32 pedType, bool arg1, bool arg2)
    DECL_THISCALL_TAIL(SetUpDriver, pedType, arg1, arg2)
    DECL_THISCALL_HEAD(SetupPassenger, _ZN8CVehicle14SetupPassengerEiibb, CPed*, i32 seatNumber, i32 pedType, bool arg2, bool arg3)
    DECL_THISCALL_TAIL(SetupPassenger, seatNumber, pedType, arg2, arg3)
    DECL_THISCALL_HEAD(FillVehicleWithPeds, _ZN8CVehicle19FillVehicleWithPedsEb, void, bool bSetClothesToAfro)
    DECL_THISCALL_TAIL(FillVehicleWithPeds, bSetClothesToAfro)
    DECL_THISCALL_NAMED_HEAD(IsPassenger1, IsPassenger, _ZNK8CVehicle11IsPassengerEPK4CPed, bool, CPed const* pCPed1)
    DECL_THISCALL_TAIL(IsPassenger1, pCPed1)
    DECL_THISCALL_NAMED_HEAD(IsPassenger2, IsPassenger, _ZNK8CVehicle11IsPassengerEi, bool, i32 iModelIndex)
    DECL_THISCALL_TAIL(IsPassenger2, iModelIndex)
    DECL_THISCALL_NAMED_HEAD(IsDriver1, IsDriver, _ZNK8CVehicle8IsDriverEPK4CPed, bool, CPed const* pCPed1)
    DECL_THISCALL_TAIL(IsDriver1, pCPed1)
    DECL_THISCALL_NAMED_HEAD(IsDriver2, IsDriver, _ZNK8CVehicle8IsDriverEi, bool, i32 iModelIndex)
    DECL_THISCALL_TAIL(IsDriver2, iModelIndex)
    DECL_THISCALL_SIMPLE(UpdatePassengerList, _ZN8CVehicle19UpdatePassengerListEv, void);
    DECL_THISCALL_SIMPLE(PickRandomPassenger, _ZN8CVehicle19PickRandomPassengerEv, CPed*);
    DECL_THISCALL_HEAD(ProcessWheelRotation, _ZN8CVehicle20ProcessWheelRotationE11tWheelStateRK7CVectorS3_f, float, tWheelState wheelState, CVector const& arg1, CVector const& arg2, float arg3)
    DECL_THISCALL_TAIL(ProcessWheelRotation, wheelState, arg1, arg2, arg3)
    DECL_THISCALL_HEAD(SetCollisionLighting, _ZN8CVehicle20SetCollisionLightingEh, void, u8 lighting)
    DECL_THISCALL_TAIL(SetCollisionLighting, lighting)
    DECL_THISCALL_SIMPLE(UpdateLightingFromStoredPolys, _ZN8CVehicle29UpdateLightingFromStoredPolysEv, void);
    DECL_THISCALL_SIMPLE(CalculateLightingFromCollision, _ZN8CVehicle30CalculateLightingFromCollisionEv, void);
    DECL_THISCALL_HEAD(FindTyreNearestPoint, _ZN8CVehicle20FindTyreNearestPointEff, u32, float x, float y)
    DECL_THISCALL_TAIL(FindTyreNearestPoint, x, y)
    DECL_THISCALL_HEAD(ReduceVehicleDamage, _ZN8CVehicle19ReduceVehicleDamageERf, void, float& fDamage)
    DECL_THISCALL_TAIL(ReduceVehicleDamage, fDamage)
    DECL_THISCALL_SIMPLE(CanUseCameraHeightSetting, _ZN8CVehicle25CanUseCameraHeightSettingEv, bool);
    DECL_THISCALL_HEAD(CanVehicleBeDamaged, _ZN8CVehicle19CanVehicleBeDamagedEP7CEntity11eWeaponTypePh, u8, CEntity* damager, eWeaponType weapon, u8* arg2)
    DECL_THISCALL_TAIL(CanVehicleBeDamaged, damager, weapon, arg2)
    DECL_THISCALL_SIMPLE(IsUpsideDown, _ZNK8CVehicle12IsUpsideDownEv, u8);
    DECL_THISCALL_SIMPLE(IsOnItsSide, _ZNK8CVehicle11IsOnItsSideEv, u8);
    DECL_THISCALL_SIMPLE(UsesSiren, _ZNK8CVehicle9UsesSirenEv, u8);
    DECL_THISCALL_SIMPLE(CarHasRoof, _ZNK8CVehicle10CarHasRoofEv, u8);
    DECL_THISCALL_HEAD(CanPedOpenLocks, _ZNK8CVehicle15CanPedOpenLocksEPK4CPed, u8, CPed const* ped)
    DECL_THISCALL_TAIL(CanPedOpenLocks, ped)
    DECL_THISCALL_SIMPLE(CanDoorsBeDamaged, _ZNK8CVehicle17CanDoorsBeDamagedEv, u8);
    DECL_THISCALL_SIMPLE(CanPedEnterCar, _ZNK8CVehicle14CanPedEnterCarEv, bool);
    DECL_THISCALL_HEAD(IsSphereTouchingVehicle, _ZN8CVehicle23IsSphereTouchingVehicleEffff, bool, float x, float y, float z, float radius)
    DECL_THISCALL_TAIL(IsSphereTouchingVehicle, x, y, z, radius)
    DECL_THISCALL_SIMPLE(ProcessCarAlarm, _ZN8CVehicle15ProcessCarAlarmEv, void);
    DECL_THISCALL_SIMPLE(DoFixedMachineGuns, _ZN8CVehicle18DoFixedMachineGunsEv, void);
    DECL_THISCALL_SIMPLE(IsVehicleNormal, _ZNK8CVehicle15IsVehicleNormalEv, bool);
    DECL_THISCALL_HEAD(ChangeLawEnforcerState, _ZN8CVehicle22ChangeLawEnforcerStateEh, void, u8 state)
    DECL_THISCALL_TAIL(ChangeLawEnforcerState, state)
    DECL_THISCALL_SIMPLE(IsLawEnforcementVehicle, _ZNK8CVehicle23IsLawEnforcementVehicleEv, u8);
    DECL_THISCALL_SIMPLE(ShufflePassengersToMakeSpace, _ZN8CVehicle28ShufflePassengersToMakeSpaceEv, bool);
    DECL_THISCALL_SIMPLE(ExtinguishCarFire, _ZN8CVehicle17ExtinguishCarFireEv, void);
    DECL_THISCALL_HEAD(FlyingControl, _ZN8CVehicle13FlyingControlE12eFlightModelffff, void, eFlightModel flightModel, float arg1, float arg2, float arg3, float arg4)
    DECL_THISCALL_TAIL(FlyingControl, flightModel, arg1, arg2, arg3, arg4)
    DECL_THISCALL_HEAD(HeightAboveCeiling, _ZN8CVehicle18HeightAboveCeilingEf12eFlightModel, float, float arg0, eFlightModel arg1)
    DECL_THISCALL_TAIL(HeightAboveCeiling, arg0, arg1)
    DECL_THISCALL_HEAD(DoBladeCollision, _ZN8CVehicle16DoBladeCollisionE7CVectorR7CMatrixsff, bool, CVector arg0, CMatrix& matrix, i16 arg2, float arg3, float arg4)
    DECL_THISCALL_TAIL(DoBladeCollision, arg0, matrix, arg2, arg3, arg4)
    DECL_THISCALL_HEAD(BladeColSectorList, _ZN8CVehicle18BladeColSectorListER8CPtrListR9CColModelR7CMatrixsf, bool, CPtrList& ptrList, CColModel& colModel, CMatrix& matrix, i16 arg3, float arg4)
    DECL_THISCALL_TAIL(BladeColSectorList, ptrList, colModel, matrix, arg3, arg4)
    DECL_THISCALL_HEAD(SetComponentVisibility, _ZN8CVehicle22SetComponentVisibilityEP7RwFramej, void, RwFrame* component, u32 visibilityState)
    DECL_THISCALL_TAIL(SetComponentVisibility, component, visibilityState)
    DECL_THISCALL_HEAD(SetComponentRotation, _ZN8CVehicle20SetComponentRotationEP7RwFrameifb, void, RwFrame* component, i32 axis, float angle, bool bResetPosition)
    DECL_THISCALL_TAIL(SetComponentRotation, component, axis, angle, bResetPosition)
    DECL_THISCALL_HEAD(SetTransmissionRotation, _ZN8CVehicle23SetTransmissionRotationEP7RwFrameff7CVectorb, void, RwFrame* component, float arg1, float arg2, CVector posn, bool isFront)
    DECL_THISCALL_TAIL(SetTransmissionRotation, component, arg1, arg2, posn, isFront)
    DECL_THISCALL_HEAD(ProcessBoatControl, _ZN8CVehicle18ProcessBoatControlEP17tBoatHandlingDataRfbb, void, tBoatHandlingData* boatHandling, float& arg1, bool arg2, bool arg3)
    DECL_THISCALL_TAIL(ProcessBoatControl, boatHandling, arg1, arg2, arg3)
    DECL_THISCALL_HEAD(ApplyBoatWaterResistance, _ZN8CVehicle24ApplyBoatWaterResistanceEP17tBoatHandlingDataf, void, tBoatHandlingData* boatHandling, float arg1)
    DECL_THISCALL_TAIL(ApplyBoatWaterResistance, boatHandling, arg1)
    DECL_THISCALL_HEAD(DoBoatSplashes, _ZN8CVehicle14DoBoatSplashesEf, void, float arg0)
    DECL_THISCALL_TAIL(DoBoatSplashes, arg0)
    DECL_THISCALL_SIMPLE(FireFixedMachineGuns, _ZN8CVehicle20FireFixedMachineGunsEv, void);
    DECL_THISCALL_SIMPLE(DoSunGlare, _ZN8CVehicle10DoSunGlareEv, void);
    DECL_THISCALL_SIMPLE(GetVehicleAppearance, _ZNK8CVehicle20GetVehicleAppearanceEv, eVehicleApperance);
    DECL_THISCALL_SIMPLE(AddDamagedVehicleParticles, _ZN8CVehicle26AddDamagedVehicleParticlesEv, void);
    DECL_THISCALL_HEAD(MakeDirty, _ZN8CVehicle9MakeDirtyER9CColPoint, void, CColPoint& colPoint)
    DECL_THISCALL_TAIL(MakeDirty, colPoint)
    DECL_THISCALL_HEAD(AddWheelDirtAndWater, _ZN8CVehicle20AddWheelDirtAndWaterER9CColPointjhh, u32, CColPoint& colPoint, u32 arg1, u8 arg2, u8 arg3)
    DECL_THISCALL_TAIL(AddWheelDirtAndWater, colPoint, arg1, arg2, arg3)
    DECL_THISCALL_SIMPLE(AddWaterSplashParticles, _ZN8CVehicle23AddWaterSplashParticlesEv, void);
    DECL_THISCALL_SIMPLE(AddExhaustParticles, _ZN8CVehicle19AddExhaustParticlesEv, void);
    DECL_THISCALL_HEAD(AddSingleWheelParticles, _ZN8CVehicle23AddSingleWheelParticlesE11tWheelStatejffP9CColPointP7CVectorfijPbj, u32, tWheelState arg0, u32 arg1, float arg2, float arg3, CColPoint* arg4, CVector* arg5, float arg6, i32 arg7, u32 surfaceType, bool* bloodState, u32 arg10)
    DECL_THISCALL_TAIL(AddSingleWheelParticles, arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, surfaceType, bloodState, arg10)
    DECL_THISCALL_SIMPLE(GetVehicleLightsStatus, _ZN8CVehicle22GetVehicleLightsStatusEv, u8);
    DECL_THISCALL_HEAD(DoHeadLightEffect, _ZN8CVehicle17DoHeadLightEffectEiR7CMatrixhh, u8, i32 dummyId, CMatrix& vehicleMatrix, u8 lightId, u8 lightState)
    DECL_THISCALL_TAIL(DoHeadLightEffect, dummyId, vehicleMatrix, lightId, lightState)
    DECL_THISCALL_HEAD(DoHeadLightBeam, _ZN8CVehicle15DoHeadLightBeamEiR7CMatrixh, void, i32 arg0, CMatrix& matrix, u8 arg2)
    DECL_THISCALL_TAIL(DoHeadLightBeam, arg0, matrix, arg2)
    DECL_THISCALL_HEAD(DoHeadLightReflectionSingle, _ZN8CVehicle27DoHeadLightReflectionSingleER7CMatrixh, void, CMatrix& matrix, u8 lightId)
    DECL_THISCALL_TAIL(DoHeadLightReflectionSingle, matrix, lightId)
    DECL_THISCALL_HEAD(DoHeadLightReflectionTwin, _ZN8CVehicle25DoHeadLightReflectionTwinER7CMatrix, void, CMatrix& matrix)
    DECL_THISCALL_TAIL(DoHeadLightReflectionTwin, matrix)
    DECL_THISCALL_HEAD(DoHeadLightReflection, _ZN8CVehicle21DoHeadLightReflectionER7CMatrixjhh, void, CMatrix& matrix, u32 flags, u8 left, u8 right)
    DECL_THISCALL_TAIL(DoHeadLightReflection, matrix, flags, left, right)
    DECL_THISCALL_HEAD(DoTailLightEffect, _ZN8CVehicle17DoTailLightEffectEiR7CMatrixhhjh, u8, i32 lightId, CMatrix& matrix, u8 arg2, u8 arg3, u32 arg4, u8 arg5)
    DECL_THISCALL_TAIL(DoTailLightEffect, lightId, matrix, arg2, arg3, arg4, arg5)
    DECL_THISCALL_HEAD(DoReverseLightEffect, _ZN8CVehicle20DoReverseLightEffectEiR7CMatrixhhjh, void, i32 lightId, CMatrix& matVehicle, u8 isRight, u8 forcedOff, u32 nLightFlags, u8 lightsOn)
    DECL_THISCALL_TAIL(DoReverseLightEffect, lightId, matVehicle, isRight, forcedOff, nLightFlags, lightsOn)
    DECL_THISCALL_HEAD(DoVehicleLights, _ZN8CVehicle15DoVehicleLightsER7CMatrixj, void, CMatrix& matrix, u32 flags)
    DECL_THISCALL_TAIL(DoVehicleLights, matrix, flags)
    DECL_THISCALL_SIMPLE(GetSpecialColModel, _ZN8CVehicle18GetSpecialColModelEv, bool);
    DECL_THISCALL_HEAD(AddVehicleUpgrade, _ZN8CVehicle17AddVehicleUpgradeEi, i32, i32 modelId)
    DECL_THISCALL_TAIL(AddVehicleUpgrade, modelId)
    DECL_THISCALL_HEAD(RemoveVehicleUpgrade, _ZN8CVehicle20RemoveVehicleUpgradeEi, void, i32 upgradeModelIndex)
    DECL_THISCALL_TAIL(RemoveVehicleUpgrade, upgradeModelIndex)
    DECL_THISCALL_SIMPLE(RemoveAllUpgrades, _ZN8CVehicle17RemoveAllUpgradesEv, void);
    DECL_THISCALL_SIMPLE(SetupUpgradesAfterLoad, _ZN8CVehicle22SetupUpgradesAfterLoadEv, void);
    DECL_THISCALL_HEAD(GetUpgrade, _ZN8CVehicle10GetUpgradeEi, i32, i32 upgradeId)
    DECL_THISCALL_TAIL(GetUpgrade, upgradeId)
    DECL_THISCALL_HEAD(GetReplacementUpgrade, _ZN8CVehicle21GetReplacementUpgradeEi, i32, i32 nodeId)
    DECL_THISCALL_TAIL(GetReplacementUpgrade, nodeId)
    DECL_THISCALL_HEAD(SetWindowOpenFlag, _ZN8CVehicle17SetWindowOpenFlagEh, void, u8 doorId)
    DECL_THISCALL_TAIL(SetWindowOpenFlag, doorId)
    DECL_THISCALL_HEAD(ClearWindowOpenFlag, _ZN8CVehicle19ClearWindowOpenFlagEh, void, u8 doorId)
    DECL_THISCALL_TAIL(ClearWindowOpenFlag, doorId)
    DECL_THISCALL_SIMPLE(GetSpareHasslePosId, _ZN8CVehicle19GetSpareHasslePosIdEv, i32);
    DECL_THISCALL_HEAD(SetHasslePosId, _ZN8CVehicle14SetHasslePosIdEib, void, i32 hasslePos, bool enable)
    DECL_THISCALL_TAIL(SetHasslePosId, hasslePos, enable)
    DECL_THISCALL_HEAD(InitWinch, _ZN8CVehicle9InitWinchEi, void, i32 arg0)
    DECL_THISCALL_TAIL(InitWinch, arg0)
    DECL_THISCALL_SIMPLE(UpdateWinch, _ZN8CVehicle11UpdateWinchEv, void);
    DECL_THISCALL_SIMPLE(RemoveWinch, _ZN8CVehicle11RemoveWinchEv, void);
    DECL_THISCALL_SIMPLE(ReleasePickedUpEntityWithWinch, _ZN8CVehicle30ReleasePickedUpEntityWithWinchEv, void);
    DECL_THISCALL_HEAD(PickUpEntityWithWinch, _ZN8CVehicle21PickUpEntityWithWinchEP7CEntity, void, CEntity* arg0)
    DECL_THISCALL_TAIL(PickUpEntityWithWinch, arg0)
    DECL_THISCALL_SIMPLE(QueryPickedUpEntityWithWinch, _ZN8CVehicle28QueryPickedUpEntityWithWinchEv, CPhysical*);
    DECL_THISCALL_SIMPLE(GetRopeHeightForHeli, _ZN8CVehicle20GetRopeHeightForHeliEv, float);
    DECL_THISCALL_HEAD(SetRopeHeightForHeli, _ZN8CVehicle20SetRopeHeightForHeliEf, void, float height)
    DECL_THISCALL_TAIL(SetRopeHeightForHeli, height)
    DECL_THISCALL_SIMPLE(RenderDriverAndPassengers, _ZN8CVehicle25RenderDriverAndPassengersEv, void);
    DECL_THISCALL_SIMPLE(PreRenderDriverAndPassengers, _ZN8CVehicle28PreRenderDriverAndPassengersEv, void);
    DECL_THISCALL_SIMPLE(ProcessWeapons, _ZN8CVehicle14ProcessWeaponsEv, void);
    DECL_THISCALL_HEAD(GetPlaneWeaponFiringStatus, _ZN8CVehicle26GetPlaneWeaponFiringStatusERbR13eOrdnanceType, CEntity*, bool& status, eOrdnanceType& ordnanceType)
    DECL_THISCALL_TAIL(GetPlaneWeaponFiringStatus, status, ordnanceType)
    DECL_THISCALL_HEAD(SelectPlaneWeapon, _ZN8CVehicle17SelectPlaneWeaponEb13eOrdnanceType, void, bool bChange, eOrdnanceType ordnanceType)
    DECL_THISCALL_TAIL(SelectPlaneWeapon, bChange, ordnanceType)
    DECL_THISCALL_HEAD(DoPlaneGunFireFX, _ZN8CVehicle16DoPlaneGunFireFXEP7CWeaponR7CVectorS3_i, void, CWeapon* weapon, CVector& particlePos, CVector& gunshellPos, i32 particleIndex)
    DECL_THISCALL_TAIL(DoPlaneGunFireFX, weapon, particlePos, gunshellPos, particleIndex)
    DECL_THISCALL_SIMPLE(FirePlaneGuns, _ZN8CVehicle13FirePlaneGunsEv, void);
    DECL_THISCALL_HEAD(FireUnguidedMissile, _ZN8CVehicle19FireUnguidedMissileE13eOrdnanceTypeb, void, eOrdnanceType ordnanceType, bool bCheckTime)
    DECL_THISCALL_TAIL(FireUnguidedMissile, ordnanceType, bCheckTime)
    DECL_THISCALL_HEAD(ScanAndMarkTargetForHeatSeekingMissile, _ZN8CVehicle38ScanAndMarkTargetForHeatSeekingMissileEP7CEntity, CEntity*, CEntity* entity)
    DECL_THISCALL_TAIL(ScanAndMarkTargetForHeatSeekingMissile, entity)
    DECL_THISCALL_HEAD(FireHeatSeakingMissile, _ZN8CVehicle22FireHeatSeakingMissileEP7CEntity13eOrdnanceTypeb, void, CEntity* targetEntity, eOrdnanceType ordnanceType, bool arg2)
    DECL_THISCALL_TAIL(FireHeatSeakingMissile, targetEntity, ordnanceType, arg2)
    DECL_THISCALL_HEAD(PossiblyDropFreeFallBombForPlayer, _ZN8CVehicle33PossiblyDropFreeFallBombForPlayerE13eOrdnanceTypeb, void, eOrdnanceType ordnanceType, bool arg1)
    DECL_THISCALL_TAIL(PossiblyDropFreeFallBombForPlayer, ordnanceType, arg1)
    DECL_THISCALL_SIMPLE(GetPlaneNumGuns, _ZN8CVehicle15GetPlaneNumGunsEv, i32);
    DECL_THISCALL_SIMPLE(GetPlaneGunsAutoAimAngle, _ZN8CVehicle24GetPlaneGunsAutoAimAngleEv, float);
    DECL_THISCALL_SIMPLE(GetPlaneGunsRateOfFire, _ZN8CVehicle22GetPlaneGunsRateOfFireEv, u32);
    DECL_THISCALL_HEAD(GetPlaneGunsPosition, _ZN8CVehicle20GetPlaneGunsPositionEi, CVector, i32 gunId)
    DECL_THISCALL_TAIL(GetPlaneGunsPosition, gunId)
    DECL_THISCALL_HEAD(GetPlaneOrdnanceRateOfFire, _ZN8CVehicle26GetPlaneOrdnanceRateOfFireE13eOrdnanceType, u32, eOrdnanceType ordnanceType)
    DECL_THISCALL_TAIL(GetPlaneOrdnanceRateOfFire, ordnanceType)
    DECL_THISCALL_HEAD(GetPlaneOrdnancePosition, _ZN8CVehicle24GetPlaneOrdnancePositionE13eOrdnanceType, CVector, eOrdnanceType ordnanceType)
    DECL_THISCALL_TAIL(GetPlaneOrdnancePosition, ordnanceType)
    DECL_THISCALL_HEAD(SetFiringRateMultiplier, _ZN8CVehicle23SetFiringRateMultiplierEf, void, float multiplier)
    DECL_THISCALL_TAIL(SetFiringRateMultiplier, multiplier)
    DECL_THISCALL_SIMPLE(GetFiringRateMultiplier, _ZN8CVehicle23GetFiringRateMultiplierEv, float);
    DECL_THISCALL_SIMPLE(CanBeDriven, _ZNK8CVehicle11CanBeDrivenEv, bool);
    DECL_THISCALL_HEAD(UpdateTrailerLink, _ZN8CVehicle17UpdateTrailerLinkEbb, void, bool arg0, bool arg1)
    DECL_THISCALL_TAIL(UpdateTrailerLink, arg0, arg1)
    DECL_THISCALL_HEAD(UpdateTractorLink, _ZN8CVehicle17UpdateTractorLinkEbb, void, bool arg0, bool arg1)
    DECL_THISCALL_TAIL(UpdateTractorLink, arg0, arg1)
    DECL_THISCALL_HEAD(ReactToVehicleDamage, _ZN8CVehicle20ReactToVehicleDamageEP4CPed, void, CPed* ped)
    DECL_THISCALL_TAIL(ReactToVehicleDamage, ped)
    DECL_THISCALL_HEAD(ProcessSirenAndHorn, _ZN8CVehicle19ProcessSirenAndHornEb, void, bool arg0)
    DECL_THISCALL_TAIL(ProcessSirenAndHorn, arg0)
    DECL_THISCALL_HEAD(SetVehicleCreatedBy, _ZN8CVehicle19SetVehicleCreatedByEib, void, i32 NewVehicleCreatedBy, bool DontAdd)
    DECL_THISCALL_TAIL(SetVehicleCreatedBy, NewVehicleCreatedBy, DontAdd)
    DECL_THISCALL_HEAD(CanPedLeanOut, _ZNK8CVehicle13CanPedLeanOutEP4CPed, bool, CPed* ped)
    DECL_THISCALL_TAIL(CanPedLeanOut, ped)
    DECL_THISCALL_SIMPLE(GetGasTankPosition, _ZN8CVehicle18GetGasTankPositionEv, CVector);
    DECL_THISCALL_HEAD(CustomCarPlate_TextureCreate, _ZN8CVehicle28CustomCarPlate_TextureCreateEP17CVehicleModelInfo, u8, CVehicleModelInfo* model)
    DECL_THISCALL_TAIL(CustomCarPlate_TextureCreate, model)
    DECL_THISCALL_SIMPLE(CustomCarPlate_TextureDestroy, _ZN8CVehicle29CustomCarPlate_TextureDestroyEv, void);
    DECL_THISCALL_HEAD(ProcessWheel, _ZN8CVehicle12ProcessWheelER7CVectorS1_S1_S1_ifffcPfP11tWheelStatet, void, CVector& arg0, CVector& arg1, CVector& arg2, CVector& arg3, i32 arg4, float arg5, float arg6, float arg7, char arg8, float* arg9, tWheelState* arg10, u16 arg11)
    DECL_THISCALL_TAIL(ProcessWheel, arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11)
    DECL_THISCALL_HEAD(ProcessBikeWheel, _ZN8CVehicle16ProcessBikeWheelER7CVectorS1_S1_S1_iffffcPfP11tWheelState17eBikeWheelSpecialt, void, CVector& arg0, CVector& arg1, CVector& arg2, CVector& arg3, i32 arg4, float arg5, float arg6, float arg7, float arg8, char arg9, float* arg10, tWheelState* arg11, eBikeWheelSpecial arg12, u16 arg13)
    DECL_THISCALL_TAIL(ProcessBikeWheel, arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13)
    DECL_THISCALL_HEAD(CreateUpgradeAtomic, _ZN8CVehicle19CreateUpgradeAtomicEP14CBaseModelInfoPK15UpgradePosnDescP7RwFrameb, RpAtomic*, CBaseModelInfo* model, UpgradePosnDesc const* upgradePosn, RwFrame* parentComponent, bool isDamaged)
    DECL_THISCALL_TAIL(CreateUpgradeAtomic, model, upgradePosn, parentComponent, isDamaged)
    DECL_THISCALL_HEAD(CreateReplacementAtomic, _ZN8CVehicle23CreateReplacementAtomicEP14CBaseModelInfoP7RwFrameibb, RpAtomic*, CBaseModelInfo* model, RwFrame* component, i32 arg2, bool bDamaged, bool bIsWheel)
    DECL_THISCALL_TAIL(CreateReplacementAtomic, model, component, arg2, bDamaged, bIsWheel)
    DECL_THISCALL_HEAD(AddUpgrade, _ZN8CVehicle10AddUpgradeEii, void, i32 modelIndex, i32 upgradeIndex)
    DECL_THISCALL_TAIL(AddUpgrade, modelIndex, upgradeIndex)
    DECL_THISCALL_HEAD(RemoveUpgrade, _ZN8CVehicle13RemoveUpgradeEi, void, i32 upgradeId)
    DECL_THISCALL_TAIL(RemoveUpgrade, upgradeId)
    DECL_THISCALL_HEAD(AddReplacementUpgrade, _ZN8CVehicle21AddReplacementUpgradeEii, void, i32 modelIndex, i32 nodeId)
    DECL_THISCALL_TAIL(AddReplacementUpgrade, modelIndex, nodeId)
    DECL_THISCALL_HEAD(RemoveReplacementUpgrade, _ZN8CVehicle24RemoveReplacementUpgradeEi, void, i32 nodeId)
    DECL_THISCALL_TAIL(RemoveReplacementUpgrade, nodeId)
    DECL_THISCALL_HEAD(SetVehicleUpgradeFlags, _ZN8CVehicle22SetVehicleUpgradeFlagsEiiRi, bool, i32 upgradeModelIndex, i32 componentIndex, i32& resultModelIndex)
    DECL_THISCALL_TAIL(SetVehicleUpgradeFlags, upgradeModelIndex, componentIndex, resultModelIndex)
    DECL_THISCALL_HEAD(ClearVehicleUpgradeFlags, _ZN8CVehicle24ClearVehicleUpgradeFlagsEii, bool, i32 arg0, i32 componentIndex)
    DECL_THISCALL_TAIL(ClearVehicleUpgradeFlags, arg0, componentIndex)

    // Helper functions
    inline bool IsVehicleTypeValid()     const { return m_nVehicleClass != -1; }
    inline bool IsAutomobile()           const { return m_nVehicleClass == VEHICLE_AUTOMOBILE; }
    inline bool IsMonsterTruck()         const { return m_nVehicleClass == VEHICLE_MTRUCK; }
    inline bool IsQuad()                 const { return m_nVehicleClass == VEHICLE_QUAD; }
    inline bool IsHeli()                 const { return m_nVehicleClass == VEHICLE_HELI; }
    inline bool IsPlane()                const { return m_nVehicleClass == VEHICLE_PLANE; }
    inline bool IsBoat()                 const { return m_nVehicleClass == VEHICLE_BOAT; }
    inline bool IsTrain()                const { return m_nVehicleClass == VEHICLE_TRAIN; }
    inline bool IsFakeAircraft()         const { return m_nVehicleClass == VEHICLE_FHELI || m_nVehicleClass == VEHICLE_FPLANE; }
    inline bool IsBike()                 const { return m_nVehicleClass == VEHICLE_BIKE; }
    inline bool IsBMX()                  const { return m_nVehicleClass == VEHICLE_BMX; }
    inline bool IsTrailer()              const { return m_nVehicleClass == VEHICLE_TRAILER; }
    inline bool IsSubVehicleTypeValid()  const { return m_nVehicleSubClass != -1; }
    inline bool IsSubAutomobile()        const { return m_nVehicleSubClass == VEHICLE_AUTOMOBILE; }
    inline bool IsSubMonsterTruck()      const { return m_nVehicleSubClass == VEHICLE_MTRUCK; }
    inline bool IsSubQuad()              const { return m_nVehicleSubClass == VEHICLE_QUAD; }
    inline bool IsSubHeli()              const { return m_nVehicleSubClass == VEHICLE_HELI; }
    inline bool IsSubPlane()             const { return m_nVehicleSubClass == VEHICLE_PLANE; }
    inline bool IsSubBoat()              const { return m_nVehicleSubClass == VEHICLE_BOAT; }
    inline bool IsSubTrain()             const { return m_nVehicleSubClass == VEHICLE_TRAIN; }
    inline bool IsSubFakeAircraft()      const { return m_nVehicleSubClass == VEHICLE_FHELI || m_nVehicleSubClass == VEHICLE_FPLANE; }
    inline bool IsSubBike()              const { return m_nVehicleSubClass == VEHICLE_BIKE; }
    inline bool IsSubBMX()               const { return m_nVehicleSubClass == VEHICLE_BMX; }
    inline bool IsSubTrailer()           const { return m_nVehicleSubClass == VEHICLE_TRAILER; }
    inline CAutomobile* AsAutomobile()         { return (CAutomobile*)this; }
    inline CMonsterTruck* AsMonsterTruck()     { return (CMonsterTruck*)this; }
    inline CQuadBike* AsQuadBike()             { return (CQuadBike*)this; }
    inline CHeli* AsHeli()                     { return (CHeli*)this; }
    inline CPlane* AsPlane()                   { return (CPlane*)this; }
    inline CBoat* AsBoat()                     { return (CBoat*)this; }
    inline CTrain* AsTrain()                   { return (CTrain*)this; }
    inline CBike* AsBike()                     { return (CBike*)this; }
    inline CBmx* AsBmx()                       { return (CBmx*)this; }
    inline CTrailer* AsTrailer()               { return (CTrailer*)this; }

    // Member values
    CAEVehicleAudioEntity m_vehicleAudio;
    tHandlingData* m_pHandlingData;
    tFlyingHandlingData* m_pFlyingHandlingData;
    union {
        eVehicleHandlingFlags  m_nHandlingFlagsIntValue;
        struct {
            unsigned int b1gBoost : 1;
            unsigned int b2gBoost : 1;
            unsigned int bNpcAntiRoll : 1;
            unsigned int bNpcNeutralHandl : 1;
            unsigned int bNoHandbrake : 1;
            unsigned int bSteerRearwheels : 1;
            unsigned int bHbRearwheelSteer : 1;
            unsigned int bAltSteerOpt : 1;
            unsigned int bWheelFNarrow2 : 1;
            unsigned int bWheelFNarrow : 1;
            unsigned int bWheelFWide : 1;
            unsigned int bWheelFWide2 : 1;
            unsigned int bWheelRNarrow2 : 1;
            unsigned int bWheelRNarrow : 1;
            unsigned int bWheelRWide : 1;
            unsigned int bWheelRWide2 : 1;
            unsigned int bHydraulicGeom : 1;
            unsigned int bHydraulicInst : 1;
            unsigned int bHydraulicNone : 1;
            unsigned int bNosInst : 1;
            unsigned int bOffroadAbility : 1;
            unsigned int bOffroadAbility2 : 1;
            unsigned int bHalogenLights : 1;
            unsigned int bProcRearwheelFirst : 1;
            unsigned int bUseMaxspLimit : 1;
            unsigned int bLowRider : 1;
            unsigned int bStreetRacer : 1;
            unsigned int bUnused1 : 1;
            unsigned int bSwingingChassis : 1;
        } m_nHandlingFlags;
    };
    CAutoPilot    m_autoPilot;
    unsigned char bIsLawEnforcer : 1; // Is this guy chasing the player at the moment
    unsigned char bIsAmbulanceOnDuty : 1; // Ambulance trying to get to an accident
    unsigned char bIsFireTruckOnDuty : 1; // Firetruck trying to get to a fire
    unsigned char bIsLocked : 1; // Is this guy locked by the script (cannot be removed)
    unsigned char bEngineOn : 1; // For sound purposes. Parked cars have their engines switched off (so do destroyed cars)
    unsigned char bIsHandbrakeOn : 1; // How's the handbrake doing ?
    unsigned char bLightsOn : 1; // Are the lights switched on ?
    unsigned char bFreebies : 1; // Any freebies left in this vehicle ?

    unsigned char bIsVan : 1; // Is this vehicle a van (doors at back of vehicle)
    unsigned char bIsBus : 1; // Is this vehicle a bus
    unsigned char bIsBig : 1; // Is this vehicle a bus
    unsigned char bLowVehicle : 1; // Need this for sporty type cars to use low getting-in/out anims
    unsigned char bComedyControls : 1; // Will make the car hard to control (hopefully in a funny way)
    unsigned char bWarnedPeds : 1; // Has scan and warn peds of danger been processed?
    unsigned char bCraneMessageDone : 1; // A crane message has been printed for this car allready
    unsigned char bTakeLessDamage : 1; // This vehicle is stronger (takes about 1/4 of damage)

    unsigned char bIsDamaged : 1; // This vehicle has been damaged and is displaying all its components
    unsigned char bHasBeenOwnedByPlayer : 1;// To work out whether stealing it is a crime
    unsigned char bFadeOut : 1; // Fade vehicle out
    unsigned char bIsBeingCarJacked : 1; // Fade vehicle out
    unsigned char bCreateRoadBlockPeds : 1;// If this vehicle gets close enough we will create peds (coppers or gang members) round it
    unsigned char bCanBeDamaged : 1; // Set to FALSE during cut scenes to avoid explosions
    unsigned char bOccupantsHaveBeenGenerated : 1; // Is true if the occupants have already been generated. (Shouldn't happen again)
    unsigned char bGunSwitchedOff : 1; // Level designers can use this to switch off guns on boats

    unsigned char bVehicleColProcessed : 1;// Has ProcessEntityCollision been processed for this car?
    unsigned char bIsCarParkVehicle : 1; // Car has been created using the special CAR_PARK script command
    unsigned char bHasAlreadyBeenRecorded : 1; // Used for replays
    unsigned char bPartOfConvoy : 1;
    unsigned char bHeliMinimumTilt : 1; // This heli should have almost no tilt really
    unsigned char bAudioChangingGear : 1; // sounds like vehicle is changing gear
    unsigned char bIsDrowning : 1; // is vehicle occupants taking damage in water (i.e. vehicle is dead in water)
    unsigned char bTyresDontBurst : 1; // If this is set the tyres are invincible

    unsigned char bCreatedAsPoliceVehicle : 1;// True if this guy was created as a police vehicle (enforcer, policecar, miamivice car etc)
    unsigned char bRestingOnPhysical : 1; // Dont go static cause car is sitting on a physical object that might get removed
    unsigned char bParking : 1;
    unsigned char bCanPark : 1;
    unsigned char bFireGun : 1; // Does the ai of this vehicle want to fire it's gun?
    unsigned char bDriverLastFrame : 1; // Was there a driver present last frame ?
    unsigned char bNeverUseSmallerRemovalRange : 1;// Some vehicles (like planes) we don't want to remove just behind the camera.
    unsigned char bIsRCVehicle : 1; // Is this a remote controlled (small) vehicle. True whether the player or AI controls it.

    unsigned char bAlwaysSkidMarks : 1; // This vehicle leaves skidmarks regardless of the wheels' states.
    unsigned char bEngineBroken : 1; // Engine doesn't work. Player can get in but the vehicle won't drive
    unsigned char bVehicleCanBeTargetted : 1;// The ped driving this vehicle can be targetted, (for Torenos plane mission)
    unsigned char bPartOfAttackWave : 1; // This car is used in an attack during a gang war
    unsigned char bWinchCanPickMeUp : 1; // This car cannot be picked up by any ropes.
    unsigned char bImpounded : 1; // Has this vehicle been in a police impounding garage
    unsigned char bVehicleCanBeTargettedByHS : 1;// Heat seeking missiles will not target this vehicle.
    unsigned char bSirenOrAlarm : 1; // Set to TRUE if siren or alarm active, else FALSE

    unsigned char bHasGangLeaningOn : 1;
    unsigned char bGangMembersForRoadBlock : 1;// Will generate gang members if NumPedsForRoadBlock > 0
    unsigned char bDoesProvideCover : 1; // If this is false this particular vehicle can not be used to take cover behind.
    unsigned char bMadDriver : 1; // This vehicle is driving like a lunatic
    unsigned char bUpgradedStereo : 1; // This vehicle has an upgraded stereo
    unsigned char bConsideredByPlayer : 1; // This vehicle is considered by the player to enter
    unsigned char bPetrolTankIsWeakPoint : 1;// If false shootong the petrol tank will NOT Blow up the car
    unsigned char bDisableParticles : 1; // Disable particles from this car. Used in garage.

    unsigned char bHasBeenResprayed : 1; // Has been resprayed in a respray garage. Reset after it has been checked.
    unsigned char bUseCarCheats : 1; // If this is true will set the car cheat stuff up in ProcessControl()
    unsigned char bDontSetColourWhenRemapping : 1;// If the texture gets remapped we don't want to change the colour with it.

    unsigned int   m_nCreationTime;
    unsigned char  m_nPrimaryColor;
    unsigned char  m_nSecondaryColor;
    unsigned char  m_nTertiaryColor;
    unsigned char  m_nQuaternaryColor;
    signed char    m_anExtras[2];
    short          m_anUpgrades[15];
    float          m_fWheelScale;
    unsigned short m_nAlarmState;
    unsigned short m_nForcedRandomRouteSeed; // if this is non-zero the random wander gets deterministic
    CPed*          m_pDriver;
    CPed*          m_apPassengers[8];
    unsigned char  m_nNumPassengers;
    unsigned char  m_nNumGettingIn;
    unsigned char  m_nGettingInFlags;
    unsigned char  m_nGettingOutFlags;
    unsigned char  m_nMaxPassengers;
    unsigned char  m_nWindowsOpenFlags; // initialised, but not used?
    signed char    m_nNitroBoosts;
    signed char    m_nSpecialColModel;
    CEntity       *m_pEntityWeAreOn; // we get it from CWorld::ProcessVerticalLine or ProcessEntityCollision, it's entity under us, 
    //only static entities (buildings or roads)
    CFire         *m_pFire;
    float          m_fSteerAngle;
    float          m_f2ndSteerAngle; // used for steering 2nd set of wheels or elevators etc..
    float          m_fGasPedal;
    float          m_fBreakPedal;
    unsigned char  m_nCreatedBy; // see eVehicleCreatedBy

    float          cachedTotalSteer; // MOBILE STUFF.

    short          m_nExtendedRemovalRange; // when game wants to delete a vehicle, it gets min(m_wExtendedRemovalRange, 170.0)
    unsigned char  m_nBombOnBoard : 3; // 0 = None
    // 1 = Timed
    // 2 = On ignition
    // 3 = remotely set ?
    // 4 = Timed Bomb has been activated
    // 5 = On ignition has been activated
    unsigned char  m_nOverrideLights : 2; // uses enum NO_CAR_LIGHT_OVERRIDE, FORCE_CAR_LIGHTS_OFF, FORCE_CAR_LIGHTS_ON
    unsigned char  m_nWinchType : 2; // Does this vehicle use a winch?
    unsigned char  m_nGunsCycleIndex : 2; // Cycle through alternate gun hardpoints on planes/helis
    unsigned char  m_nOrdnanceCycleIndex : 2; // Cycle through alternate ordnance hardpoints on planes/helis
    unsigned char  m_nUsedForCover; // Has n number of cops hiding/attempting to hid behind it
    unsigned char  m_nAmmoInClip; // Used to make the guns on boat do a reload (20 by default).
    unsigned char  m_nPacMansCollected; // initialised, but not used?
    unsigned char  m_nPedsPositionForRoadBlock; // 0, 1 or 2
    unsigned char  m_nNumCopsForRoadBlock;
    float          m_fDirtLevel; // Dirt level of vehicle body texture: 0.0f=fully clean, 15.0f=maximum dirt visible
    unsigned char  m_nCurrentGear;
    float          m_fGearChangeCount; // used as parameter for cTransmission::CalculateDriveAcceleration, but doesn't change
    float          m_fWheelSpinForAudio;
    float          m_fHealth; // 1000.0f = full health. 0 -> explode
    CVehicle      *m_pTractor;
    CVehicle      *m_pTrailer;

    bool           m_bFireAutoFlare; // MOBILE STUFF.

    CEntity*       m_pWhoInstalledBombOnMe;
    unsigned int   m_nTimeTillWeNeedThisCar; // game won't try to delete this car while this time won't reach
    unsigned int   m_nGunFiringTime; // last time when gun on vehicle was fired (used on boats)
    unsigned int   m_nTimeWhenBlowedUp; // game will delete vehicle when 60 seconds after this time will expire
    unsigned short m_nCopsInCarTimer; // timer for police car (which is following player) occupants to stay in car. If this timer reachs
                                      // some value, they will leave a car. The timer increases each frame if player is stopped in car, 
                                      // otherway it resets
    unsigned short m_wBombTimer;     // goes down with each frame
    CEntity       *m_pWhoDetonatedMe; // if vehicle was detonated, game copies m_pWhoInstalledBombOnMe here
    float          m_fVehicleFrontGroundZ; // we get these values from CCollision::IsStoredPolyStillValidVerticalLine
    float          m_fVehicleRearGroundZ;  // 
    unsigned char  m_nOilSpills;
    float          m_fLastOilSpillX;
    float          m_fLastOilSpillY;
    eDoorLock      m_eDoorLock;
    unsigned int   m_nProjectileWeaponFiringTime; // manual-aimed projectiles for hunter, lock-on projectile for hydra
    unsigned int   m_nAdditionalProjectileWeaponFiringTime; // manual-aimed projectiles for hydra
    unsigned int   m_nTimeForMinigunFiring; // minigun on hunter
    signed char    m_nLastWeaponDamageType; // see eWeaponType, -1 if no damage
    CEntity       *m_pLastDamageEntity;
    unsigned char  m_nRadioStation; // not used?
    unsigned char  m_nRainHitCount; // initialised, but not used?
    unsigned char  m_nSoundIndex; // initialised, but not used?
    unsigned char  m_nVehicleWeaponInUse; // see enum eCarWeapon
    unsigned int   m_nHornCounter;
    unsigned char  m_nHornPattern; // random id related to siren
    unsigned char  m_nNoHornCounter; // car horn related
    unsigned char  m_nComedyControlsStatus;
    unsigned char  m_nHasslePosId;
    CStoredCollPoly m_FrontCollPoly; // poly which is under front part of car
    CStoredCollPoly m_RearCollPoly; // poly which is under rear part of car
    unsigned char  m_anCollisionLighting[4]; // left front, left rear, right front, right rear
    FxSystem_c    *m_pOverheatParticle;
    FxSystem_c    *m_pFireParticle;
    FxSystem_c    *m_pDustParticle;
    union {
        unsigned char     m_nRenderLightsFlags;
        struct {
            unsigned char m_bRightFront : 1;
            unsigned char m_bLeftFront : 1;
            unsigned char m_bRightRear : 1;
            unsigned char m_bLeftRear : 1;
        } m_renderLights;
    };
    RwTexture     *m_pCustomCarPlate;
    float          m_fSteer;
    int            m_nVehicleClass; // see enum eVehicleClass
    int            m_nVehicleSubClass;
    const char    *m_szPreviousRemapTxdName;
    const char    *m_szRemapTxdName;
    RwTexture     *m_pRemapTexture;
DECL_CLASS_END()
CHECKSIZE(CVehicle, 0x5B4, 0x758);

DECL_FASTCALL_SIMPLE_GLO(DestroyVehicleAndDriverAndPassengers, _Z36DestroyVehicleAndDriverAndPassengersP8CVehicle, void, CVehicle* pVehicle);
DECL_FASTCALL_SIMPLE_GLO(IsVehiclePointerValid, _Z21IsVehiclePointerValidP8CVehicle, bool, CVehicle* pVehicle);
DECL_FASTCALL_SIMPLE_GLO(IsVehiclePointerValid_NotInWorld, _Z32IsVehiclePointerValid_NotInWorldP8CVehicle, bool, CVehicle* pVehicle);
DECL_FASTCALL_SIMPLE_GLO(SetVehicleAtomicVisibility, _Z28SetVehicleAtomicVisibilityCBP8RwObjectPv, RwObject*, RwObject* pObject, void* pData);
DECL_FASTCALL_SIMPLE_GLO(SetVehicleAtomicVisibility_RwFrame, _Z28SetVehicleAtomicVisibilityCBP7RwFramePv, RwFrame*, RwFrame* pFrame, void* pData);
DECL_FASTCALL_SIMPLE_GLO(SetCompAlphaCB, _Z14SetCompAlphaCBP10RpMaterialPv, RpMaterial*, RpMaterial* pMaterial, void* pData);
DECL_FASTCALL_SIMPLE_GLO(RemoveUpgradeCB, _Z15RemoveUpgradeCBP8RpAtomicPv, RpAtomic*, RpAtomic* pAtomic, void* pData);
DECL_FASTCALL_SIMPLE_GLO(FindUpgradeCB, _Z13FindUpgradeCBP8RpAtomicPv, RpAtomic*, RpAtomic* pAtomic, void* pData);

#define DOOR_SPEED_MAX_CAPPED DOOR_SPEED_MAX_CAPPED()

#define WHEELSPIN_TARGET_RATE WHEELSPIN_TARGET_RATE()
#define WHEELSPIN_INAIR_TARGET_RATE WHEELSPIN_INAIR_TARGET_RATE()
#define WHEELSPIN_RISE_RATE WHEELSPIN_RISE_RATE()
#define WHEELSPIN_FALL_RATE WHEELSPIN_FALL_RATE()
#define ms_forceVehicleLightsOff ms_forceVehicleLightsOff()
#define s_bPlaneGunsEjectShellCasings s_bPlaneGunsEjectShellCasings()
#define m_fAirResistanceMult m_fAirResistanceMult()
#define ms_fRailTrackResistance ms_fRailTrackResistance()
#define ms_fRailTrackResistanceDefault ms_fRailTrackResistanceDefault()
#define bDisableRemoteDetonation bDisableRemoteDetonation()
#define bDisableRemoteDetonationOnContact bDisableRemoteDetonationOnContact()
#define m_bEnableMouseSteering m_bEnableMouseSteering()
#define m_bEnableMouseFlying m_bEnableMouseFlying()
#define m_aSpecialColModel m_aSpecialColModel()
#define m_aSpecialColVehicle m_aSpecialColVehicle()
#define m_pTappedGasTankVehicle m_pTappedGasTankVehicle()

#endif // __AML_PSDK_SAVEHICLE_H
