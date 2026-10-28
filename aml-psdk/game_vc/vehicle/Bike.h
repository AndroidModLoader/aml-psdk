#ifndef __AML_PSDK_VCBIKE_H
#define __AML_PSDK_VCBIKE_H

#include "Vehicle.h"

struct RwFrame;
struct tBikeHandlingData;

enum eBikeNodes : u32
{
    BIKE_NODE_NONE = 0,
    BIKE_CHASSIS = 1,
    BIKE_FORKS_FRONT = 2,
    BIKE_FORKS_REAR = 3,
    BIKE_WHEEL_FRONT = 4,
    BIKE_WHEEL_REAR = 5,
    BIKE_MUDGUARD = 6,
    BIKE_HANDLEBARS = 7,
    BIKE_NUM_NODES = 8
};

DECL_CLASS_BASED(CBike, CVehicle)
    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CBike, _ZN5CBikeC2Eih, i32 modelIndex, u8 createdBy)
    DECL_CTORCALL_ARG_TAIL(modelIndex, createdBy)
    DECL_DTORCALL_VIRTUAL_SLOT(CBike, _ZN5CBikeD2Ev, _ZN5CBike, _ZTV5CBike, 2);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(CBike, SetModelIndex, _ZTV5CBike, 4, void, u32 modelIndex)
    DECL_VIRTUALCALL_TAIL(modelIndex)
    DECL_VIRTUALCALL_HEAD(CBike, ProcessControl, _ZTV5CBike, 9, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CBike, Teleport, _ZTV5CBike, 12, void, CVector position)
    DECL_VIRTUALCALL_TAIL(position)
    DECL_VIRTUALCALL_HEAD(CBike, PreRender, _ZTV5CBike, 13, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CBike, Render, _ZTV5CBike, 14, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CBike, ProcessEntityCollision, _ZTV5CBike, 18, i32, CEntity* entity, CColPoint* points)
    DECL_VIRTUALCALL_TAIL(entity, points)
    DECL_VIRTUALCALL_HEAD(CBike, ProcessControlInputs, _ZTV5CBike, 19, void, u8 playerNum)
    DECL_VIRTUALCALL_TAIL(playerNum)
    DECL_VIRTUALCALL_HEAD(CBike, GetComponentWorldPosition, _ZTV5CBike, 20, void, i32 componentId, CVector& position)
    DECL_VIRTUALCALL_TAIL(componentId, position)
    DECL_VIRTUALCALL_HEAD(CBike, IsComponentPresent, _ZTV5CBike, 21, bool, i32 componentId)
    DECL_VIRTUALCALL_TAIL(componentId)
    DECL_VIRTUALCALL_HEAD(CBike, SetComponentRotation, _ZTV5CBike, 22, void, i32 componentId, CVector rotation)
    DECL_VIRTUALCALL_TAIL(componentId, rotation)
    DECL_VIRTUALCALL_HEAD(CBike, IsDoorReady, _ZTV5CBike, 25, bool, eDoors door)
    DECL_VIRTUALCALL_TAIL(door)
    DECL_VIRTUALCALL_HEAD(CBike, IsDoorFullyOpen, _ZTV5CBike, 26, bool, eDoors door)
    DECL_VIRTUALCALL_TAIL(door)
    DECL_VIRTUALCALL_HEAD(CBike, IsDoorClosed, _ZTV5CBike, 27, bool, eDoors door)
    DECL_VIRTUALCALL_TAIL(door)
    DECL_VIRTUALCALL_HEAD(CBike, IsDoorMissing, _ZTV5CBike, 28, bool, eDoors door)
    DECL_VIRTUALCALL_TAIL(door)
    DECL_VIRTUALCALL_HEAD(CBike, RemoveRefsToVehicle, _ZTV5CBike, 32, void, CEntity* entity)
    DECL_VIRTUALCALL_TAIL(entity)
    DECL_VIRTUALCALL_HEAD(CBike, BlowUpCar, _ZTV5CBike, 33, void, CEntity* damager)
    DECL_VIRTUALCALL_TAIL(damager)
    DECL_VIRTUALCALL_HEAD(CBike, SetUpWheelColModel, _ZTV5CBike, 34, bool, CColModel* colModel)
    DECL_VIRTUALCALL_TAIL(colModel)
    DECL_VIRTUALCALL_HEAD(CBike, BurstTyre, _ZTV5CBike, 35, void, u8 tyreId, bool applyForces)
    DECL_VIRTUALCALL_TAIL(tyreId, applyForces)
    DECL_VIRTUALCALL_HEAD(CBike, IsRoomForPedToLeaveCar, _ZTV5CBike, 36, bool, u32 componentId, CVector* forcedDoorPosition)
    DECL_VIRTUALCALL_TAIL(componentId, forcedDoorPosition)
    DECL_VIRTUALCALL_HEAD(CBike, GetHeightAboveRoad, _ZTV5CBike, 38, float)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CBike, PlayCarHorn, _ZTV5CBike, 39, void)
    DECL_VIRTUALCALL_TAIL()
    using CVehicle::IsDoorReady;
    using CVehicle::IsDoorMissing;

    // Member functions
    DECL_THISCALL_SIMPLE(PlaceOnRoadProperly, _ZN5CBike19PlaceOnRoadProperlyEv, void);
    DECL_THISCALL_SIMPLE(ProcessBuoyancy, _ZN5CBike15ProcessBuoyancyEv, void);
    DECL_THISCALL_SIMPLE(VehicleDamage, _ZN5CBike13VehicleDamageEv, void);
    DECL_THISCALL_SIMPLE(DoDriveByShootings, _ZN5CBike18DoDriveByShootingsEv, void);
    DECL_THISCALL_SIMPLE(SetupSuspensionLines, _ZN5CBike20SetupSuspensionLinesEv, void);
    DECL_THISCALL_SIMPLE(SetupModelNodes, _ZN5CBike15SetupModelNodesEv, void);
    DECL_THISCALL_SIMPLE(CalculateLeanMatrix, _ZN5CBike19CalculateLeanMatrixEv, void);
    DECL_THISCALL_SIMPLE(PlayHornIfNecessary, _ZN5CBike19PlayHornIfNecessaryEv, void);
    DECL_THISCALL_SIMPLE(ResetSuspension, _ZN5CBike15ResetSuspensionEv, void);
    DECL_THISCALL_SIMPLE(Fix, _ZN5CBike3FixEv, void);
    DECL_THISCALL_SIMPLE(GetAllWheelsOffGround, _ZN5CBike21GetAllWheelsOffGroundEv, bool);
    DECL_THISCALL_SIMPLE(ReduceHornCounter, _ZN5CBike17ReduceHornCounterEv, void);
    DECL_THISCALL_SIMPLE(AddDamagedVehicleParticles, _ZN5CBike26AddDamagedVehicleParticlesEv, void);
    DECL_THISCALL_HEAD(GetCorrectedWorldDoorPosition, _ZN5CBike29GetCorrectedWorldDoorPositionER7CVectorS0_S0_, void, CVector& out, CVector position, CVector offset)
    DECL_THISCALL_TAIL(GetCorrectedWorldDoorPosition, out, position, offset)
    DECL_THISCALL_HEAD(SetRemoveAnimFlags, _ZN5CBike18SetRemoveAnimFlagsEP4CPed, void, CPed* ped)
    DECL_THISCALL_TAIL(SetRemoveAnimFlags, ped)
    DECL_THISCALL_HEAD(SetComponentVisibility, _ZN5CBike22SetComponentVisibilityEP7RwFramej, void, RwFrame* frame, u32 visibility)
    DECL_THISCALL_TAIL(SetComponentVisibility, frame, visibility)
    DECL_THISCALL_HEAD(KnockOffRider, _ZN5CBike13KnockOffRiderE11eWeaponTypehP4CPedb, void, eWeaponType weapon, u8 direction, CPed* ped, bool getBackOn)
    DECL_THISCALL_TAIL(KnockOffRider, weapon, direction, ped, getBackOn)
    DECL_THISCALL_HEAD(AddWheelDirtAndWater, _ZN5CBike20AddWheelDirtAndWaterER9CColPointj, bool, CColPoint& colPoint, u32 belowEffectSpeed)
    DECL_THISCALL_TAIL(AddWheelDirtAndWater, colPoint, belowEffectSpeed)

    // Member values
    RwFrame* m_aBikeNodes[BIKE_NUM_NODES];
    bool m_bLeanMatrixCalculated;
    CMatrix m_mLeanMatrix;
    CVector m_vecAveGroundNormal;
    CVector m_vecGroundRight;
    tBikeHandlingData* pBikeHandling;
    i32 nBikeAnimGroup;
    u8 tireStatus[2];
    CColPoint m_anWheelColPoint[4];
    float m_aWheelRatios[4];
    float m_aRatioHistory[4];
    float m_aWheelCounts[4];
    float m_fBrakeCount;
    i32 m_anWheelSurfaceType[2];
    bool m_aBloodyWheel[2];
    bool m_aMoreSkidmarks[2];
    float m_afWheelRotationX[2];
    float m_fWheelSpeed[2];
    float m_fSuspensionHeights[2];
    float m_fOriginalWheelHeights[2];
    float m_fSuspensionLengths[4];
    float m_fLineLengths[4];
    float m_fHeightAboveRoad;
    float m_fCarTraction;
    float m_fSwingArm;
    float m_fForkYOff;
    float m_fForkZOff;
    float m_fSteerAngleTan;
    float m_fWheelAngle;
    float m_fLeanLRAngle;
    float m_fLeanLRAngle2;
    float m_fLeanInput;
    float m_fPedLeanAmountLR;
    float m_fPedLeanAmountUD;
    u8 m_nUnknownBikeValue;
    u32 : 0;
    union
    {
        u8 m_nDamageFlags;
        struct
        {
            u8 bBikeFlag01 : 1;
            u8 bBikeFlag02 : 1;
            u8 bWaterTight : 1;
            u8 bGettingPickedUp : 1;
            u8 bOnSideStand : 1;
            u8 bPlayerBoost : 1;
            u8 bEngineOnFire : 1;
            u8 bWheelieForCamera : 1;
        };
    };
    i16 m_nBrakes;
    float m_fTyreTemp;
    float m_fBrakingSliding;
    float m_fPreviousSpeed;
    float m_fBurningTimer;
    CPhysical* m_apWheelCollisionEntity[4];
    CVector m_avTouchPointsLocalSpace[4];
    CEntity* m_pDamager;
    u8 m_nNumContactWheels;
    u8 m_nNumWheelsOnGround;
    u8 m_nPrevNumWheelsOnGround;
    float m_fGasPedalAudioRevs;
    tWheelState m_anWheelState[2];
DECL_CLASS_END()
CHECKSIZE(CBike, 0x4F0, 0x5E8);

#endif // __AML_PSDK_VCBIKE_H
