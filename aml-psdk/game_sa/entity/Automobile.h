#ifndef __AML_PSDK_SAAUTOMOBILE_H
#define __AML_PSDK_SAAUTOMOBILE_H

#include "Vehicle.h"

struct FxSystem_c;

enum eDamageState
{
    DAMSTATE_OK = 0,
    DAMSTATE_OPENED = 1,
    DAMSTATE_DAMAGED = 2,
    DAMSTATE_OPENED_DAMAGED = 3,
    DAMSTATE_NOTPRESENT = 4
};

enum tComponent
{
    COMPONENT_WHEEL_LF = 1,
    COMPONENT_WHEEL_RF = 2,
    COMPONENT_WHEEL_LR = 3,
    COMPONENT_WHEEL_RR = 4,
    COMPONENT_BONNET = 5,
    COMPONENT_BOOT = 6,
    COMPONENT_DOOR_LF = 7,
    COMPONENT_DOOR_RF = 8,
    COMPONENT_DOOR_LR = 9,
    COMPONENT_DOOR_RR = 10,
    COMPONENT_WING_LF = 11,
    COMPONENT_WING_RF = 12,
    COMPONENT_WING_LR = 13,
    COMPONENT_WING_RR = 14,
    COMPONENT_WINDSCREEN = 15,
    COMPONENT_BUMP_FRONT = 16,
    COMPONENT_BUMP_REAR = 17
};

enum tComponentGroup
{
    COMPGROUP_PANEL = 0,
    COMPGROUP_WHEEL = 1,
    COMPGROUP_DOOR = 2,
    COMPGROUP_BONNET = 3,
    COMPGROUP_BOOT = 4,
    COMPGROUP_LIGHT = 5,
    COMPGROUP_NA = 6
};

enum eWheels
{
    WHEEL_FRONT_LEFT = 0,
    WHEEL_REAR_LEFT = 1,
    WHEEL_FRONT_RIGHT = 2,
    WHEEL_REAR_RIGHT = 3
};

enum ePanels
{
    WING_FRONT_LEFT = 0,
    WING_FRONT_RIGHT = 1,
    WING_REAR_LEFT = 2,
    WING_REAR_RIGHT = 3,
    WINDSCREEN = 4,
    BUMP_FRONT = 5,
    BUMP_REAR = 6
};

enum eLights
{
    LIGHT_FRONT_LEFT = 0,
    LIGHT_FRONT_RIGHT = 1,
    LIGHT_REAR_RIGHT = 2,
    LIGHT_REAR_LEFT = 3
};

enum eCarNodes
{
    CAR_NODE_NONE = 0,
    CAR_CHASSIS = 1,
    CAR_WHEEL_RF = 2,
    CAR_WHEEL_RM = 3,
    CAR_WHEEL_RB = 4,
    CAR_WHEEL_LF = 5,
    CAR_WHEEL_LM = 6,
    CAR_WHEEL_LB = 7,
    CAR_DOOR_RF = 8,
    CAR_DOOR_RR = 9,
    CAR_DOOR_LF = 10,
    CAR_DOOR_LR = 11,
    CAR_BUMP_FRONT = 12,
    CAR_BUMP_REAR = 13,
    CAR_WING_RF = 14,
    CAR_WING_LF = 15,
    CAR_BONNET = 16,
    CAR_BOOT = 17,
    CAR_WINDSCREEN = 18,
    CAR_EXHAUST = 19,
    CAR_MISC_A = 20,
    CAR_MISC_B = 21,
    CAR_MISC_C = 22,
    CAR_MISC_D = 23,
    CAR_MISC_E = 24,
    CAR_NUM_NODES
};

DECL_CLASS(CBouncingPanel)
    // STATIC values
    DECL_VALUE_PLT_FLT(BOUNCE_SPRING_DAMP_MULT, BYBIT(0x678E60, 0x84FCE8));
    DECL_VALUE_PLT_FLT(BOUNCE_SPRING_RETURN_MULT, BYBIT(0x6787EC, 0x84F000));
    DECL_VALUE_PLT_FLT(BOUNCE_VEL_CHANGE_LIMIT, BYBIT(0x6779B0, 0x84D390));
    DECL_VALUE_PLT_FLT(BOUNCE_HANGING_DAMP_MULT, BYBIT(0x67789C, 0x84D160));
    DECL_VALUE_PLT_FLT(BOUNCE_HANGING_RETURN_MULT, BYBIT(0x676B54, 0x84B6F0));

    // Member functions
    DECL_THISCALL_SIMPLE(ResetPanel, _ZN14CBouncingPanel10ResetPanelEv, void);
    DECL_THISCALL_HEAD(SetPanel, _ZN14CBouncingPanel8SetPanelEssf, void, i16 frameId, i16 axis, float angleLimit)
    DECL_THISCALL_TAIL(SetPanel, frameId, axis, angleLimit)
    DECL_THISCALL_HEAD(ProcessPanel, _ZN14CBouncingPanel12ProcessPanelEP8CVehicleP7RwFrame7CVectorS4_ff, void, CVehicle* vehicle, RwFrame* frame, CVector arg2, CVector arg3, float arg4, float arg5)
    DECL_THISCALL_TAIL(ProcessPanel, vehicle, frame, arg2, arg3, arg4, arg5)

    short m_nFrameId;
    short m_nAxis;
    float          m_fAngleLimit;
    CVector        m_vecRotation;
    CVector        m_vecPos;
DECL_CLASS_END()

DECL_CLASS(CDamageManager)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(GetCarNodeIndexFromPanel, _ZN14CDamageManager24GetCarNodeIndexFromPanelE7ePanels, i32, ePanels panel);
    DECL_FASTCALL_SIMPLE(GetCarNodeIndexFromDoor, _ZN14CDamageManager23GetCarNodeIndexFromDoorE6eDoors, i32, eDoors door);

    float m_fWheelDamageEffect;
    unsigned char m_nEngineStatus;
    union
    {
        unsigned char m_anWheelsStatus[4];
        struct
        {
            unsigned char m_nRightRearWheelsStatus;
            unsigned char m_nRightFrontWheelsStatus;
            unsigned char m_nLeftRearWheelsStatus;
            unsigned char m_nLeftFrontWheelsStatus;
        };
    };
    union
    {
        unsigned char m_anDoorsStatus[6];
        struct
        {
            unsigned char m_nBonnetStatus;
            unsigned char m_nBootStatus;
            unsigned char m_nLeftFrontDoorStatus;
            unsigned char m_nRightFrontDoorStatus;
            unsigned char m_nLeftRearDoorStatus;
            unsigned char m_nRightRearDoorStatus;
        };
    };
    union
    {
        unsigned int m_nLightsStatus;
        struct
        {
            unsigned int m_nLeftFrontLightStatus : 2;
            unsigned int m_nRightFrontLightStatus : 2;
            unsigned int m_nRightRearLightStatus : 2;
            unsigned int m_nLeftRearLightStatus : 2;
        };
    };
    unsigned int m_nPanelsStatus;

    // Member functions
    DECL_THISCALL_HEAD(GetComponentGroup, _ZN14CDamageManager17GetComponentGroupE10tComponentP15tComponentGroupPh, bool, tComponent component, tComponentGroup* group, u8* damageCompId)
    DECL_THISCALL_TAIL(GetComponentGroup, component, group, damageCompId)
    DECL_THISCALL_HEAD(ProgressEngineDamage, _ZN14CDamageManager20ProgressEngineDamageEf, bool, float arg0)
    DECL_THISCALL_TAIL(ProgressEngineDamage, arg0)
    DECL_THISCALL_HEAD(ProgressDoorDamage, _ZN14CDamageManager18ProgressDoorDamageEhP11CAutomobile, bool, u8 damageCompId, CAutomobile* car)
    DECL_THISCALL_TAIL(ProgressDoorDamage, damageCompId, car)
    DECL_THISCALL_HEAD(ProgressPanelDamage, _ZN14CDamageManager19ProgressPanelDamageEh, bool, u8 panel)
    DECL_THISCALL_TAIL(ProgressPanelDamage, panel)
    DECL_THISCALL_HEAD(ProgressWheelDamage, _ZN14CDamageManager19ProgressWheelDamageEh, bool, u8 wheel)
    DECL_THISCALL_TAIL(ProgressWheelDamage, wheel)
    DECL_THISCALL_HEAD(ProgressAeroplaneDamage, _ZN14CDamageManager23ProgressAeroplaneDamageEh, bool, u8 component)
    DECL_THISCALL_TAIL(ProgressAeroplaneDamage, component)
    DECL_THISCALL_SIMPLE(ResetDamageStatus, _ZN14CDamageManager17ResetDamageStatusEv, void);
    DECL_THISCALL_HEAD(SetLightStatus, _ZN14CDamageManager14SetLightStatusE7eLightsj, void, eLights light, u32 status)
    DECL_THISCALL_TAIL(SetLightStatus, light, status)
    DECL_THISCALL_HEAD(GetLightStatus, _ZNK14CDamageManager14GetLightStatusE7eLights, u32, eLights light)
    DECL_THISCALL_TAIL(GetLightStatus, light)
    DECL_THISCALL_HEAD(SetPanelStatus, _ZN14CDamageManager14SetPanelStatusEij, void, i32 panel, u32 status)
    DECL_THISCALL_TAIL(SetPanelStatus, panel, status)
    DECL_THISCALL_HEAD(GetPanelStatus, _ZNK14CDamageManager14GetPanelStatusEi, u32, i32 arg0)
    DECL_THISCALL_TAIL(GetPanelStatus, arg0)
    DECL_THISCALL_HEAD(SetWheelStatus, _ZN14CDamageManager14SetWheelStatusEij, void, i32 wheel, u32 status)
    DECL_THISCALL_TAIL(SetWheelStatus, wheel, status)
    DECL_THISCALL_HEAD(GetWheelStatus, _ZNK14CDamageManager14GetWheelStatusEi, u32, i32 wheel)
    DECL_THISCALL_TAIL(GetWheelStatus, wheel)
    DECL_THISCALL_NAMED_HEAD(SetDoorStatus1, SetDoorStatus, _ZN14CDamageManager13SetDoorStatusE6eDoorsj, void, eDoors arg1, u32 arg2)
    DECL_THISCALL_TAIL(SetDoorStatus1, arg1, arg2)
    DECL_THISCALL_NAMED_HEAD(SetDoorStatus2, SetDoorStatus, _ZN14CDamageManager13SetDoorStatusEij, void, i32 iDoorIndex, u32 Status)
    DECL_THISCALL_TAIL(SetDoorStatus2, iDoorIndex, Status)
    DECL_THISCALL_NAMED_HEAD(GetDoorStatus1, GetDoorStatus, _ZNK14CDamageManager13GetDoorStatusEi, u32, i32 iDoorIndex)
    DECL_THISCALL_TAIL(GetDoorStatus1, iDoorIndex)
    DECL_THISCALL_NAMED_HEAD(GetDoorStatus2, GetDoorStatus, _ZNK14CDamageManager13GetDoorStatusE6eDoors, u32, eDoors arg1)
    DECL_THISCALL_TAIL(GetDoorStatus2, arg1)
    DECL_THISCALL_HEAD(SetEngineStatus, _ZN14CDamageManager15SetEngineStatusEj, void, u32 status)
    DECL_THISCALL_TAIL(SetEngineStatus, status)
    DECL_THISCALL_SIMPLE(GetEngineStatus, _ZNK14CDamageManager15GetEngineStatusEv, u32);
    DECL_THISCALL_HEAD(SetAeroplaneCompStatus, _ZN14CDamageManager22SetAeroplaneCompStatusEij, void, i32 component, u32 status)
    DECL_THISCALL_TAIL(SetAeroplaneCompStatus, component, status)
    DECL_THISCALL_HEAD(GetAeroplaneCompStatus, _ZNK14CDamageManager22GetAeroplaneCompStatusEi, u32, i32 component)
    DECL_THISCALL_TAIL(GetAeroplaneCompStatus, component)
    DECL_THISCALL_HEAD(ApplyDamage, _ZN14CDamageManager11ApplyDamageEP11CAutomobile10tComponentff, bool, CAutomobile* car, tComponent component, float intensity, float arg3)
    DECL_THISCALL_TAIL(ApplyDamage, car, component, intensity, arg3)
    DECL_THISCALL_HEAD(FuckCarCompletely, _ZN14CDamageManager17FuckCarCompletelyEb, void, bool skipWheels)
    DECL_THISCALL_TAIL(FuckCarCompletely, skipWheels)
DECL_CLASS_END()



DECL_CLASS_BASED(CAutomobile, CVehicle)
    // Construct/Deconstruct functions
    CAutomobile(){}
    DECL_CTORCALL_ARG_HEAD(CAutomobile, _ZN11CAutomobileC2Eihh, int modelIdx, u8 createdBy, u8 suspensionLines)
    DECL_CTORCALL_ARG_TAIL(modelIdx, createdBy, suspensionLines)
    DECL_DTORCALL(CAutomobile, _ZN11CAutomobileD2Ev);

    // Virtual functions
    virtual bool ProcessAI(unsigned int &);
    virtual void ResetSuspension(void);
    virtual void ProcessFlyingCarStuff(void);
    virtual void DoHoverSuspensionRatios(void);
    virtual void ProcessSuspension(void);
    

    // STATIC functions
    DECL_FASTCALL_SIMPLE(GetJackedCounter, _ZN11CAutomobile16GetJackedCounterEv, i32);
    DECL_FASTCALL_SIMPLE(SetAllTaxiLights, _ZN11CAutomobile16SetAllTaxiLightsEb, void, bool arg0);

    // STATIC values
    DECL_VALUE_PLT_U8(m_sAllTaxiLights, BYBIT(0x679FA4, 0x851F58));
    DECL_OBJECT_PLT(CVector, vecHunterGunPos, BYBIT(0x676E34, 0x84BCB0));

    // Member functions
    DECL_THISCALL_SIMPLE(GetAllWheelsOffGround, _ZNK11CAutomobile21GetAllWheelsOffGroundEv, u8);
    DECL_THISCALL_SIMPLE(ReduceHornCounter, _ZN11CAutomobile17ReduceHornCounterEv, void);
    DECL_THISCALL_SIMPLE(PlayHornIfNecessary, _ZN11CAutomobile19PlayHornIfNecessaryEv, void);
    DECL_THISCALL_SIMPLE(RcbanditCheckHitWheels, _ZNK11CAutomobile22RcbanditCheckHitWheelsEv, u16);
    DECL_THISCALL_HEAD(RcbanditCheck1CarWheels, _ZNK11CAutomobile23RcbanditCheck1CarWheelsER8CPtrList, u16, CPtrList& ptrlist)
    DECL_THISCALL_TAIL(RcbanditCheck1CarWheels, ptrlist)
    DECL_THISCALL_SIMPLE(HydraulicControl, _ZN11CAutomobile16HydraulicControlEv, void);
    DECL_THISCALL_HEAD(UpdateMovingCollision, _ZN11CAutomobile21UpdateMovingCollisionEf, bool, float angle)
    DECL_THISCALL_TAIL(UpdateMovingCollision, angle)
    DECL_THISCALL_SIMPLE(GetMovingCollisionOffset, _ZN11CAutomobile24GetMovingCollisionOffsetEv, float);
    DECL_THISCALL_SIMPLE(ProcessBuoyancy, _ZN11CAutomobile15ProcessBuoyancyEv, void);
    DECL_THISCALL_HEAD(UpdateWheelMatrix, _ZN11CAutomobile17UpdateWheelMatrixEii, void, i32 nodeIndex, i32 flags)
    DECL_THISCALL_TAIL(UpdateWheelMatrix, nodeIndex, flags)
    DECL_THISCALL_SIMPLE(ShowAllComps, _ZN11CAutomobile12ShowAllCompsEv, void);
    DECL_THISCALL_SIMPLE(HideAllComps, _ZN11CAutomobile12HideAllCompsEv, void);
    DECL_THISCALL_HEAD(SetBumperDamage, _ZN11CAutomobile15SetBumperDamageE7ePanelsb, void, ePanels panel, bool withoutVisualEffect)
    DECL_THISCALL_TAIL(SetBumperDamage, panel, withoutVisualEffect)
    DECL_THISCALL_HEAD(SetPanelDamage, _ZN11CAutomobile14SetPanelDamageE7ePanelsb, void, ePanels panel, bool createWindowGlass)
    DECL_THISCALL_TAIL(SetPanelDamage, panel, createWindowGlass)
    DECL_THISCALL_HEAD(SetDoorDamage, _ZN11CAutomobile13SetDoorDamageE6eDoorsb, void, eDoors door, bool withoutVisualEffect)
    DECL_THISCALL_TAIL(SetDoorDamage, door, withoutVisualEffect)
    DECL_THISCALL_HEAD(SetRandomDamage, _ZN11CAutomobile15SetRandomDamageEb, void, bool arg0)
    DECL_THISCALL_TAIL(SetRandomDamage, arg0)
    DECL_THISCALL_HEAD(SetTotalDamage, _ZN11CAutomobile14SetTotalDamageEb, void, bool arg0)
    DECL_THISCALL_TAIL(SetTotalDamage, arg0)
    DECL_THISCALL_HEAD(FixTyre, _ZN11CAutomobile7FixTyreE7eWheels, void, eWheels wheel)
    DECL_THISCALL_TAIL(FixTyre, wheel)
    DECL_THISCALL_HEAD(FixDoor, _ZN11CAutomobile7FixDoorEi6eDoors, void, i32 nodeIndex, eDoors door)
    DECL_THISCALL_TAIL(FixDoor, nodeIndex, door)
    DECL_THISCALL_HEAD(PopDoor, _ZN11CAutomobile7PopDoorEi6eDoorsb, void, i32 nodeIndex, eDoors door, bool showVisualEffect)
    DECL_THISCALL_TAIL(PopDoor, nodeIndex, door, showVisualEffect)
    DECL_THISCALL_HEAD(FixPanel, _ZN11CAutomobile8FixPanelEi7ePanels, void, i32 nodeIndex, ePanels panel)
    DECL_THISCALL_TAIL(FixPanel, nodeIndex, panel)
    DECL_THISCALL_HEAD(PopPanel, _ZN11CAutomobile8PopPanelEi7ePanelsb, void, i32 nodeIndex, ePanels panel, bool showVisualEffect)
    DECL_THISCALL_TAIL(PopPanel, nodeIndex, panel, showVisualEffect)
    DECL_THISCALL_HEAD(ProcessSwingingDoor, _ZN11CAutomobile19ProcessSwingingDoorEi6eDoors, void, i32 nodeIndex, eDoors door)
    DECL_THISCALL_TAIL(ProcessSwingingDoor, nodeIndex, door)
    DECL_THISCALL_HEAD(SpawnFlyingComponent, _ZN11CAutomobile20SpawnFlyingComponentEij, CPhysical*, i32 nodeIndex, u32 collisionType)
    DECL_THISCALL_TAIL(SpawnFlyingComponent, nodeIndex, collisionType)
    DECL_THISCALL_SIMPLE(RemoveBonnetInPedCollision, _ZN11CAutomobile26RemoveBonnetInPedCollisionEv, CPhysical*);
    DECL_THISCALL_HEAD(SetTaxiLight, _ZN11CAutomobile12SetTaxiLightEb, void, bool enable)
    DECL_THISCALL_TAIL(SetTaxiLight, enable)
    DECL_THISCALL_SIMPLE(HasCarStoppedBecauseOfLight, _ZNK11CAutomobile27HasCarStoppedBecauseOfLightEv, bool);
    DECL_THISCALL_SIMPLE(ScanForCrimes, _ZN11CAutomobile13ScanForCrimesEv, void);
    DECL_THISCALL_HEAD(FireTruckControl, _ZN11CAutomobile16FireTruckControlEP5CFire, void, CFire* arg0)
    DECL_THISCALL_TAIL(FireTruckControl, arg0)
    DECL_THISCALL_SIMPLE(TankControl, _ZN11CAutomobile11TankControlEv, void);
    DECL_THISCALL_SIMPLE(BlowUpCarsInPath, _ZN11CAutomobile16BlowUpCarsInPathEv, void);
    DECL_THISCALL_SIMPLE(BoostJumpControl, _ZN11CAutomobile16BoostJumpControlEv, void);
    DECL_THISCALL_HEAD(NitrousControl, _ZN11CAutomobile14NitrousControlEa, void, i8 boost)
    DECL_THISCALL_TAIL(NitrousControl, boost)
    DECL_THISCALL_SIMPLE(StopNitroEffect, _ZN11CAutomobile15StopNitroEffectEv, void);
    DECL_THISCALL_HEAD(DoNitroEffect, _ZN11CAutomobile13DoNitroEffectEf, void, float state)
    DECL_THISCALL_TAIL(DoNitroEffect, state)
    DECL_THISCALL_SIMPLE(TowTruckControl, _ZN11CAutomobile15TowTruckControlEv, void);
    DECL_THISCALL_HEAD(SetBusDoorTimer, _ZN11CAutomobile15SetBusDoorTimerEjh, void, u32 time, u8 arg1)
    DECL_THISCALL_TAIL(SetBusDoorTimer, time, arg1)
    DECL_THISCALL_SIMPLE(ProcessAutoBusDoors, _ZN11CAutomobile19ProcessAutoBusDoorsEv, void);
    DECL_THISCALL_SIMPLE(PlaceOnRoadProperly, _ZN11CAutomobile19PlaceOnRoadProperlyEv, void);
    DECL_THISCALL_HEAD(ProcessCarOnFireAndExplode, _ZN11CAutomobile26ProcessCarOnFireAndExplodeEh, void, u8 arg0)
    DECL_THISCALL_TAIL(ProcessCarOnFireAndExplode, arg0)
    DECL_THISCALL_HEAD(TellHeliToGoToCoors, _ZN11CAutomobile19TellHeliToGoToCoorsEfffff, void, float x, float y, float z, float altitudeMin, float altitudeMax)
    DECL_THISCALL_TAIL(TellHeliToGoToCoors, x, y, z, altitudeMin, altitudeMax)
    DECL_THISCALL_HEAD(SetHeliOrientation, _ZN11CAutomobile18SetHeliOrientationEf, void, float angle)
    DECL_THISCALL_TAIL(SetHeliOrientation, angle)
    DECL_THISCALL_SIMPLE(ClearHeliOrientation, _ZN11CAutomobile20ClearHeliOrientationEv, void);
    DECL_THISCALL_HEAD(TellPlaneToGoToCoors, _ZN11CAutomobile20TellPlaneToGoToCoorsEfffff, void, float x, float y, float z, float altitudeMin, float altitudeMax)
    DECL_THISCALL_TAIL(TellPlaneToGoToCoors, x, y, z, altitudeMin, altitudeMax)
    DECL_THISCALL_HEAD(KnockPedOutCar, _ZN11CAutomobile14KnockPedOutCarE11eWeaponTypetP4CPed, CPed*, eWeaponType arg0, u16 arg1, CPed* arg2)
    DECL_THISCALL_TAIL(KnockPedOutCar, arg0, arg1, arg2)
    DECL_THISCALL_SIMPLE(PopBoot, _ZN11CAutomobile7PopBootEv, void);
    DECL_THISCALL_SIMPLE(PopBootUsingPhysics, _ZN11CAutomobile19PopBootUsingPhysicsEv, void);
    DECL_THISCALL_SIMPLE(CloseBoot, _ZN11CAutomobile9CloseBootEv, void);
    DECL_THISCALL_SIMPLE(CloseAllDoors, _ZN11CAutomobile13CloseAllDoorsEv, void);
    DECL_THISCALL_HEAD(DoSoftGroundResistance, _ZN11CAutomobile22DoSoftGroundResistanceERj, void, u32& arg0)
    DECL_THISCALL_TAIL(DoSoftGroundResistance, arg0)
    DECL_THISCALL_HEAD(ProcessCarWheelPair, _ZN11CAutomobile19ProcessCarWheelPairEiifP7CVectorS1_fffb, void, i32 arg0, i32 arg1, float arg2, CVector* arg3, CVector* arg4, float arg5, float arg6, float arg7, bool arg8)
    DECL_THISCALL_TAIL(ProcessCarWheelPair, arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8)
    DECL_THISCALL_SIMPLE(GetCarRoll, _ZN11CAutomobile10GetCarRollEv, float);
    DECL_THISCALL_SIMPLE(GetCarPitch, _ZN11CAutomobile11GetCarPitchEv, float);
    DECL_THISCALL_SIMPLE(ProcessHarvester, _ZN11CAutomobile16ProcessHarvesterEv, void);
    DECL_THISCALL_SIMPLE(SetupModelNodes, _ZN11CAutomobile15SetupModelNodesEv, void);
    DECL_THISCALL_SIMPLE(DebugCode, _ZN11CAutomobile9DebugCodeEv, void);
    DECL_THISCALL_HEAD(dmgDrawCarCollidingParticles, _ZN11CAutomobile28dmgDrawCarCollidingParticlesERK7CVectorf11eWeaponType, void, CVector const& DamagePosition, float fImpulse, eWeaponType weaponType)
    DECL_THISCALL_TAIL(dmgDrawCarCollidingParticles, DamagePosition, fImpulse, weaponType)
    DECL_THISCALL_HEAD(DoHeliDustEffect, _ZN11CAutomobile16DoHeliDustEffectEff, void, float arg0, float arg1)
    DECL_THISCALL_TAIL(DoHeliDustEffect, arg0, arg1)
    DECL_THISCALL_HEAD(CustomCarPlate_BeforeRenderingStart, _ZN11CAutomobile35CustomCarPlate_BeforeRenderingStartEP17CVehicleModelInfo, void, CVehicleModelInfo* model)
    DECL_THISCALL_TAIL(CustomCarPlate_BeforeRenderingStart, model)
    DECL_THISCALL_HEAD(CustomCarPlate_AfterRenderingStop, _ZN11CAutomobile33CustomCarPlate_AfterRenderingStopEP17CVehicleModelInfo, void, CVehicleModelInfo* model)
    DECL_THISCALL_TAIL(CustomCarPlate_AfterRenderingStop, model)
    DECL_THISCALL_SIMPLE(IsInAir, _ZN11CAutomobile7IsInAirEv, u8);

    // Member values
    CDamageManager m_damageManager;
    CDoor m_doors[6];
    RwFrame *m_aCarNodes[CAR_NUM_NODES];
    CBouncingPanel m_panels[3];
    CDoor m_swingingChassis;
    CColPoint m_wheelColPoint[4];
    float wheelsDistancesToGround1[4];
    float wheelsDistancesToGround2[4];
    float wheelsCounts[4];
    float m_fBrakeCount;
    float m_fEngineRevs;
    float m_fEngineForce;
    int m_aSkidmarkType[4]; // see eSkidmarkType
    bool m_bBloodyWheel[4];
    bool m_bMoreSkidmarks[4];
    float m_fWheelRotation[4];
    float m_fSuspensionHeights[4];
    float m_fWheelSpeed[4];
    float m_fWheelLongtitudeSlip[4];
    union
    {
        char taxiAvaliable;
        char m_nAutomobileFlags;
        struct
        {
            unsigned char bTaxiLight : 1;
            unsigned char bShouldNotChangeColour : 1;
            unsigned char bWaterTight : 1;
            unsigned char bDoesNotGetDamageUpsideDown : 1;
            unsigned char bCanBeVisiblyDamaged : 1;
            unsigned char bTankExplodesCars : 1;
            unsigned char bIsBoggedDownInSand : 1;
            unsigned char bIsMonsterTruck : 1;
        };
    };
    unsigned short m_nBrakesOn;
    unsigned short m_wMiscComponentAngle;
    unsigned short m_wVoodooSuspension;
    unsigned int m_dwBusDoorTimerEnd;
    unsigned int m_dwBusDoorTimerStart;
    float wheelOffsetZ[4];
    float lineLength[4];
    float m_fFrontHeightAboveRoad;
    float m_fRearHeightAboveRoad;
    float m_fCarTraction;
    float m_fNitroValue;
    float m_fRotation;
    float m_fRotationBalance; // used in CHeli::TestSniperCollision
    float m_fMoveDirection;
    CVector m_vecOldMoveSpeed;
    CVector m_vecOldTurnSpeed;
    float m_aDoorRotation[6];
    float m_fBurningTimer; // starts when vehicle health is lower than 250.0, car blows up when it hits 5000.0
    CPhysical *m_pWheelCollisionEntity[4];
    CVector m_vWheelCollisionPos[4];
    CEntity* m_pAttacker;
    float m_fTransformPos;
    short m_nTransformState;
    float m_fBasePositions[4];
    float m_fLeftDoorDrivebyOpen;
    float m_fRightDoorDrivebyOpen;
    float m_fDoomVerticalRotation;
    float m_fDoomHorizontalRotation;
    float m_fForcedOrientation;
    float m_fUpDownLightAngle[2];
    unsigned char m_nNumContactWheels;
    unsigned char m_nWheelsOnGround;
    unsigned char m_nWheelsOnGroundPrev;
    float m_fGasPedalAudioRevs;
    unsigned int m_aWheelState[4]; // enum tWheelState
    void *pNitroParticle[2];
    unsigned char m_nHarvesterTimer;
    unsigned char m_nBlownEngineStatus;
    float m_fHeliDustRatio;
DECL_CLASS_END()
CHECKSIZE(CAutomobile, 0x99C, 0xBC8);



enum eMonsterTruckNodes
{
    MONSTER_NODE_NONE = 0,
    MONSTER_CHASSIS = 1,
    MONSTER_WHEEL_RF = 2,
    MONSTER_WHEEL_RM = 3,
    MONSTER_WHEEL_RB = 4,
    MONSTER_WHEEL_LF = 5,
    MONSTER_WHEEL_LM = 6,
    MONSTER_WHEEL_LB = 7,
    MONSTER_DOOR_RF = 8,
    MONSTER_DOOR_RR = 9,
    MONSTER_DOOR_LF = 10,
    MONSTER_DOOR_LR = 11,
    MONSTER_BUMP_FRONT = 12,
    MONSTER_BUMP_REAR = 13,
    MONSTER_WING_RF = 14,
    MONSTER_WING_LF = 15,
    MONSTER_BONNET = 16,
    MONSTER_BOOT = 17,
    MONSTER_WINDSCREEN = 18,
    MONSTER_TRANSMISSION_F = 19,
    MONSTER_TRANSMISSION_R = 20,
    MONSTER_LOADBAY = 21,
    MONSTER_MISC_A = 22,
    MONSTER_NUM_NODES
};
DECL_CLASS_BASED(CMonsterTruck, CAutomobile)
    // Construct/Deconstruct functions
    CMonsterTruck(){}
    DECL_CTORCALL_ARG_HEAD(CMonsterTruck, _ZN13CMonsterTruckC2Eih, int modelIdx, u8 createdBy)
    DECL_CTORCALL_ARG_TAIL(modelIdx, createdBy)
    DECL_DTORCALL(CMonsterTruck, _ZN13CMonsterTruckD2Ev);

    // STATIC values
    DECL_VALUE_PLT_FLT(DUMPER_COL_ANGLEMULT, BYBIT(0x676FA8, 0x84BF88));

    // Member functions
    DECL_THISCALL_SIMPLE(ExtendSuspension, _ZN13CMonsterTruck16ExtendSuspensionEv, void);

    // Member values
    float m_fTyreCompression[4];
    float m_fWheelRadius;
DECL_CLASS_END()



enum eTrailerNodes
{
    TRAILER_NODE_NONE = 0,
    TRAILER_CHASSIS = 1,
    TRAILER_WHEEL_RF = 2,
    TRAILER_WHEEL_RM = 3,
    TRAILER_WHEEL_RB = 4,
    TRAILER_WHEEL_LF = 5,
    TRAILER_WHEEL_LM = 6,
    TRAILER_WHEEL_LB = 7,
    TRAILER_DOOR_RF = 8,
    TRAILER_DOOR_RR = 9,
    TRAILER_DOOR_LF = 10,
    TRAILER_DOOR_LR = 11,
    TRAILER_BUMP_FRONT = 12,
    TRAILER_BUMP_REAR = 13,
    TRAILER_WING_RF = 14,
    TRAILER_WING_LF = 15,
    TRAILER_BONNET = 16,
    TRAILER_BOOT = 17,
    TRAILER_WINDSCREEN = 18,
    TRAILER_EXHAUST = 19,
    TRAILER_MISC_A = 20,
    TRAILER_MISC_B = 21,
    TRAILER_MISC_C = 22,
    TRAILER_NUM_NODES
};
DECL_CLASS_BASED(CTrailer, CAutomobile)
    // Construct/Deconstruct functions
    CTrailer(){}
    DECL_CTORCALL_ARG_HEAD(CTrailer, _ZN8CTrailerC2Eih, int modelIdx, u8 createdBy)
    DECL_CTORCALL_ARG_TAIL(modelIdx, createdBy)
    DECL_DTORCALL(CTrailer, _ZN8CTrailerD2Ev);

    // STATIC values
    DECL_VALUE_PLT_FLT(m_fTrailerSuspensionForce, BYBIT(0x677F00, 0x84DE20));
    DECL_VALUE_PLT_FLT(m_fTrailerDampingForce, BYBIT(0x6799FC, 0x851410));

    // Member functions
    DECL_THISCALL_SIMPLE(ScanForTowLink, _ZN8CTrailer14ScanForTowLinkEv, void);

    // Member values
    CColPoint m_aSupportCols[2];
    float m_fSupportRatios[2];
    float m_fSupportStartZ;
    float m_fSupportExtension;
    float m_fSupportMinRatio;
DECL_CLASS_END()



enum eQuadBikeNodes
{
    QUAD_NODE_NONE = 0,
    QUAD_CHASSIS = 1,
    QUAD_WHEEL_RF = 2,
    QUAD_WHEEL_RM = 3,
    QUAD_WHEEL_RB = 4,
    QUAD_WHEEL_LF = 5,
    QUAD_WHEEL_LM = 6,
    QUAD_WHEEL_LB = 7,
    QUAD_DOOR_RF = 8,
    QUAD_DOOR_RR = 9,
    QUAD_DOOR_LF = 10,
    QUAD_DOOR_LR = 11,
    QUAD_BODY_FRONT = 12,
    QUAD_BODY_REAR = 13,
    QUAD_SUSPENSION_RF = 14,
    QUAD_SUSPENSION_LF = 15,
    QUAD_REAR_AXLE = 16,
    QUAD_HANDLEBARS = 17,
    QUAD_MISC_A = 18,
    QUAD_MISC_B = 19,
    QUAD_NUM_NODES
};
DECL_CLASS_BASED(CQuadBike, CAutomobile)
    // Construct/Deconstruct functions
    CQuadBike(){}
    DECL_CTORCALL_ARG_HEAD(CQuadBike, _ZN9CQuadBikeC2Eih, int modelIdx, u8 createdBy)
    DECL_CTORCALL_ARG_TAIL(modelIdx, createdBy)
    DECL_DTORCALL(CQuadBike, _ZN9CQuadBikeD2Ev);

    // Member values
    void          *m_pHandling;
    CRideAnimData  m_rideAnimData;
    float          m_fLeftArmSwing;
    float          m_fForkYOff;
    float          m_fForkZOff;
    float          m_fSteerAngleTan;
    union
    {
        unsigned char m_nQuadFlags;
        unsigned char m_bWheelieForCamera : 1;
    };
DECL_CLASS_END()



enum eHeliNodes
{
    HELI_NODE_NONE = 0,
    HELI_CHASSIS = 1,
    HELI_WHEEL_RF = 2,
    HELI_WHEEL_RM = 3,
    HELI_WHEEL_RB = 4,
    HELI_WHEEL_LF = 5,
    HELI_WHEEL_LM = 6,
    HELI_WHEEL_LB = 7,
    HELI_DOOR_RF = 8,
    HELI_DOOR_RR = 9,
    HELI_DOOR_LF = 10,
    HELI_DOOR_LR = 11,
    HELI_STATIC_ROTOR = 12,
    HELI_MOVING_ROTOR = 13,
    HELI_STATIC_ROTOR2 = 14,
    HELI_MOVING_ROTOR2 = 15,
    HELI_RUDDER = 16,
    HELI_ELEVATORS = 17,
    HELI_MISC_A = 18,
    HELI_MISC_B = 19,
    HELI_MISC_C = 20,
    HELI_MISC_D = 21,
    HELI_NUM_NODES
};

struct tHeliLight
{
    CVector m_vecOrigin;
    CVector m_vecTarget;
    float m_fTargetRadius;
    float m_fPower;
    unsigned int m_nCoronaIndex;
    unsigned char m_bClipIfColliding;
    unsigned char m_bDrawShadow;
    CVector m_vecEllipseCentre;
    CVector m_vecEllipseForward;
    CVector m_vecEllipseSide;
};

DECL_CLASS_BASED(CHeli, CAutomobile)
    // Construct/Deconstruct functions
    CHeli(){}
    DECL_CTORCALL_ARG_HEAD(CHeli, _ZN5CHeliC2Eih, int modelIdx, u8 createdBy)
    DECL_CTORCALL_ARG_TAIL(modelIdx, createdBy)
    DECL_DTORCALL(CHeli, _ZN5CHeliD2Ev);

    // STATIC functions
    DECL_FASTCALL_SIMPLE(InitHelis, _ZN5CHeli9InitHelisEv, void);
    DECL_FASTCALL_SIMPLE(UpdateHelis, _ZN5CHeli11UpdateHelisEv, void);
    DECL_FASTCALL_SIMPLE(AddHeliSearchLight, _ZN5CHeli18AddHeliSearchLightERK7CVectorS2_ffjhh, void, CVector const& origin, CVector const& target, float targetRadius, float power, u32 coronaIndex, u8 unknownFlag, u8 drawShadow);
    DECL_FASTCALL_SIMPLE(SearchLightCone, _ZN5CHeli15SearchLightConeEi7CVectorS0_ffhhPS0_S1_S1_bffff, void, i32 UniqueID, CVector position, CVector targetPos, float radius, float brightness, u8 clipIfColliding, u8 doGroundLight, CVector* pVecEllipseCentre, CVector* pVecEllipseForward, CVector* pVecEllipseSide, bool bFromScript, float topRadius, float normalX, float normalY, float normalZ);
    DECL_FASTCALL_SIMPLE(Pre_SearchLightCone, _ZN5CHeli19Pre_SearchLightConeEv, void);
    DECL_FASTCALL_SIMPLE(Post_SearchLightCone, _ZN5CHeli20Post_SearchLightConeEv, void);
    DECL_FASTCALL_SIMPLE(RenderAllHeliSearchLights, _ZN5CHeli25RenderAllHeliSearchLightsEv, void);
    DECL_FASTCALL_SIMPLE(GenerateHeli, _ZN5CHeli12GenerateHeliEP4CPedb, CHeli*, CPed* target, bool newsHeli);
    DECL_FASTCALL_SIMPLE(TestSniperCollision, _ZN5CHeli19TestSniperCollisionEP7CVectorS1_, bool, CVector* origin, CVector* target);
    DECL_FASTCALL_SIMPLE(SwitchPoliceHelis, _ZN5CHeli17SwitchPoliceHelisEb, void, bool enable);

    // STATIC values
    DECL_OBJECT_ARRAY_PLT(CHeli*, pHelis, BYBIT(0x677D60, 0x84DAE0));
    DECL_VALUE_PLT_U32(NumberOfSearchLights, BYBIT(0x678A88, 0x84F538));
    DECL_VALUE_PLT_U32(TestForNewRandomHelisTimer, BYBIT(0x676A04, 0x84B450));
    DECL_VALUE_PLT_BOOL(bPoliceHelisAllowed, BYBIT(0x6760B0, 0x84A1D0));
    DECL_VALUE_PLT_BOOL(bHeliControlsCheat, BYBIT(0x6789B4, 0x84F388));

    // Member functions
    DECL_THISCALL_SIMPLE(SendDownSwat, _ZN5CHeli12SendDownSwatEv, bool);
    DECL_THISCALL_HEAD(FindSwatPositionRelativeToHeli, _ZN5CHeli30FindSwatPositionRelativeToHeliEi, CVector, i32 swatNumber)
    DECL_THISCALL_TAIL(FindSwatPositionRelativeToHeli, swatNumber)

    // Member values
    union
    {
        char            m_nHeliFlags;
        struct
        {
            char        m_bStopFlyingForAWhileFlag : 1;
            char        m_bUseSearchLightOnTarget : 1;
            char        m_bWarnTarger : 1;
        };
    };
    float               m_fLeftRightSkid;
    float               m_fSteeringUpDown;
    float               m_fSteeringLeftRight;
    float               m_fAccelerationBreakStatus;
    float               m_fEngineSpeed;
    float               m_fRotorZ;
    float               m_fSecondRotorZ;
    float               m_fMaxAltitude;
    float               m_fDesiredHeight;
    float               m_fMinAltitude;
    float               m_fFlightDirection;
    bool                m_bStopFlyingForAWhile;
    unsigned char       m_nNumSwatOccupants;
    unsigned char       m_anSwatIDs[4];
    float               m_afOldSearchLightX[6];
    float               m_afOldSearchLightY[6];
    u32                 m_nLastSearchLightSample;
    CVector             m_vecSearchLightTarget;
    float               m_fSearchLightIntensity;
    u32                 m_nLastTimeSearchLightWasTooFarAwayToShoot;
    u32                 m_nNextTalkTimer;
    FxSystem_c        **m_ppGunflashFx;
    unsigned char                m_nFiringMultiplier;
    unsigned char       m_bSearchLightEnabled;
    float               m_fCrashAndBurnTurnSpeed;
DECL_CLASS_END()
CHECKSIZE(CHeli, 0xA2C, 0xC60);



enum ePlaneNodes
{
    PLANE_NODE_NONE = 0,
    PLANE_CHASSIS = 1,
    PLANE_WHEEL_RF = 2,
    PLANE_WHEEL_RM = 3,
    PLANE_WHEEL_RB = 4,
    PLANE_WHEEL_LF = 5,
    PLANE_WHEEL_LM = 6,
    PLANE_WHEEL_LB = 7,
    PLANE_DOOR_RF = 8,
    PLANE_DOOR_RR = 9,
    PLANE_DOOR_LF = 10,
    PLANE_DOOR_LR = 11,
    PLANE_STATIC_PROP = 12,
    PLANE_MOVING_PROP = 13,
    PLANE_STATIC_PROP2 = 14,
    PLANE_MOVING_PROP2 = 15,
    PLANE_RUDDER = 16,
    PLANE_ELEVATOR_L = 17,
    PLANE_ELEVATOR_R = 18,
    PLANE_AILERON_L = 19,
    PLANE_AILERON_R = 20,
    PLANE_GEAR_L = 21,
    PLANE_GEAR_R = 22,
    PLANE_MISC_A = 23,
    PLANE_MISC_B = 24,
    PLANE_NUM_NODES
};

DECL_CLASS_BASED(CPlane, CAutomobile)
    // Construct/Deconstruct functions
    CPlane(){}
    DECL_CTORCALL_ARG_HEAD(CPlane, _ZN6CPlaneC2Eih, int modelIdx, u8 createdBy)
    DECL_CTORCALL_ARG_TAIL(modelIdx, createdBy)
    DECL_DTORCALL(CPlane, _ZN6CPlaneD2Ev);

    // STATIC functions
    DECL_FASTCALL_SIMPLE(FindPlaneCreationCoors, _ZN6CPlane22FindPlaneCreationCoorsEP7CVectorS1_PfS2_b, void, CVector* arg0, CVector* arg1, float* arg2, float* arg3, bool arg4);
    DECL_FASTCALL_SIMPLE(CountPlanesAndHelis, _ZN6CPlane19CountPlanesAndHelisEv, i32);
    DECL_FASTCALL_SIMPLE(AreWeInNoPlaneZone, _ZN6CPlane18AreWeInNoPlaneZoneEv, bool);
    DECL_FASTCALL_SIMPLE(AreWeInNoBigPlaneZone, _ZN6CPlane21AreWeInNoBigPlaneZoneEv, bool);
    DECL_FASTCALL_SIMPLE(DoPlaneGenerationAndRemoval, _ZN6CPlane27DoPlaneGenerationAndRemovalEv, void);
    DECL_FASTCALL_SIMPLE(InitPlaneGenerationAndRemoval, _ZN6CPlane29InitPlaneGenerationAndRemovalEv, void);
    DECL_FASTCALL_SIMPLE(SwitchAmbientPlanes, _ZN6CPlane19SwitchAmbientPlanesEb, void, bool enable);

    // STATIC values
    DECL_VALUE_PLT_I32(GenPlane_Status, BYBIT(0x678C30, 0x84F888));
    DECL_VALUE_PLT_I32(GenPlane_ModelIndex, BYBIT(0x67771C, 0x84CE60));
    DECL_VALUE_PLT_U32(GenPlane_LastTimeGenerated, BYBIT(0x6795B8, 0x850B80));
    DECL_VALUE_PLT_BOOL(GenPlane_Active, BYBIT(0x676650, 0x84ACF8));
    DECL_VALUE_PLT_FLT(ANDROM_COL_ANGLE_MULT, BYBIT(0x679730, 0x850E68));
    DECL_VALUE_PLT_I16(HARRIER_NOZZLE_ROTATE_LIMIT, BYBIT(0x6785BC, 0x84EB90));
    DECL_VALUE_PLT_I16(HARRIER_NOZZLE_SWITCH_LIMIT, BYBIT(0x677774, 0x84CF10));
    DECL_VALUE_PLT_FLT(PLANE_MIN_PROP_SPEED, BYBIT(0x6797A8, 0x850F58));
    DECL_VALUE_PLT_FLT(PLANE_STD_PROP_SPEED, BYBIT(0x677C1C, 0x84D858));
    DECL_VALUE_PLT_FLT(PLANE_MAX_PROP_SPEED, BYBIT(0x677798, 0x84CF58));
    DECL_VALUE_PLT_FLT(PLANE_ROC_PROP_SPEED, BYBIT(0x677B50, 0x84D6C0));

    // Member functions
    DECL_THISCALL_SIMPLE(IsAlreadyFlying, _ZN6CPlane15IsAlreadyFlyingEv, void);
    DECL_THISCALL_SIMPLE(SetGearUp, _ZN6CPlane9SetGearUpEv, void);
    DECL_THISCALL_SIMPLE(SetGearDown, _ZN6CPlane11SetGearDownEv, void);

    // Member values
    float           m_fYawControl;
    float           m_fPitchControl;
    float           m_fRollControl;
    float           m_fThrottleControl;
    float           m_fScriptThrottleControl;
    float           m_fPreviousRoll;
    uint32_t        m_nStallCounter;
    float           m_fTakeOffDirection;
    float           m_fLowestFlightHeight;
    float           m_fDesiredHeight;
    float           m_fMinHeightAboveTerrain;
    float           m_fFlightDirection;
    float           m_fFlightDirectionAvoidingTerrain;
    float           m_fOldTilt;
    uint32_t        m_nStartedFlyingTime;
    float           m_fEngineSpeed;
    float           m_fPropellerAngle;
    float           m_fLandingGearStatus;
    uint32_t        m_nDamageControlWaveCounter;
    FxSystem_c    **m_pGunParticles;
    uint8_t         m_nFiringMultiplier;
    uint32_t        m_FireMissilePressedTime;
    CEntity        *m_pLastMissileTarget;
    uint32_t        m_nLastHSMissileLOSTime : 31;
    uint32_t        m_bLastHSMissileLOS : 1;
    FxSystem_c     *m_apJettrusParticles[4];
    FxSystem_c     *m_pSmokeParticle;
    int32_t         m_nSmokeTimer;
    unsigned char   m_bSmokeEjectorEnabled;
DECL_CLASS_END()
CHECKSIZE(CPlane, 0xA18, 0xC68);

#define m_sAllTaxiLights m_sAllTaxiLights()
#define vecHunterGunPos vecHunterGunPos()

#define DUMPER_COL_ANGLEMULT DUMPER_COL_ANGLEMULT()

#define m_fTrailerSuspensionForce m_fTrailerSuspensionForce()
#define m_fTrailerDampingForce m_fTrailerDampingForce()

#define pHelis pHelis()
#define NumberOfSearchLights NumberOfSearchLights()
#define TestForNewRandomHelisTimer TestForNewRandomHelisTimer()
#define bPoliceHelisAllowed bPoliceHelisAllowed()
#define bHeliControlsCheat bHeliControlsCheat()

#define GenPlane_Status GenPlane_Status()
#define GenPlane_ModelIndex GenPlane_ModelIndex()
#define GenPlane_LastTimeGenerated GenPlane_LastTimeGenerated()
#define GenPlane_Active GenPlane_Active()
#define ANDROM_COL_ANGLE_MULT ANDROM_COL_ANGLE_MULT()
#define HARRIER_NOZZLE_ROTATE_LIMIT HARRIER_NOZZLE_ROTATE_LIMIT()
#define HARRIER_NOZZLE_SWITCH_LIMIT HARRIER_NOZZLE_SWITCH_LIMIT()
#define PLANE_MIN_PROP_SPEED PLANE_MIN_PROP_SPEED()
#define PLANE_STD_PROP_SPEED PLANE_STD_PROP_SPEED()
#define PLANE_MAX_PROP_SPEED PLANE_MAX_PROP_SPEED()
#define PLANE_ROC_PROP_SPEED PLANE_ROC_PROP_SPEED()

#define BOUNCE_SPRING_DAMP_MULT BOUNCE_SPRING_DAMP_MULT()
#define BOUNCE_SPRING_RETURN_MULT BOUNCE_SPRING_RETURN_MULT()
#define BOUNCE_VEL_CHANGE_LIMIT BOUNCE_VEL_CHANGE_LIMIT()
#define BOUNCE_HANGING_DAMP_MULT BOUNCE_HANGING_DAMP_MULT()
#define BOUNCE_HANGING_RETURN_MULT BOUNCE_HANGING_RETURN_MULT()

#endif // __AML_PSDK_SAAUTOMOBILE_H
