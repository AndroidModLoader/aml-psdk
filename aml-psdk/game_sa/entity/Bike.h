#ifndef __AML_PSDK_SABIKE_H
#define __AML_PSDK_SABIKE_H

#include "Vehicle.h"

struct tBikeHandlingData;
struct CAnimBlendAssociation;

enum eBikeNodes
{
    BIKE_NODE_NONE = 0,
    BIKE_CHASSIS = 1,
    BIKE_FORKS_FRONT = 2,
    BIKE_FORKS_REAR = 3,
    BIKE_WHEEL_FRONT = 4,
    BIKE_WHEEL_REAR = 5,
    BIKE_MUDGUARD = 6,
    BIKE_HANDLEBARS = 7,
    BIKE_MISC_A = 8,
    BIKE_MISC_B = 9,
    BIKE_NUM_NODES
};

enum eBmxNodes
{
    BMX_NODE_NONE = 0,
    BMX_CHASSIS = 1,
    BMX_FORKS_FRONT = 2,
    BMX_FORKS_REAR = 3,
    BMX_WHEEL_FRONT = 4,
    BMX_WHEEL_REAR = 5,
    BMX_HANDLEBARS = 6,
    BMX_CHAINSET = 7,
    BMX_PEDAL_R = 8,
    BMX_PEDAL_L = 9,
    BMX_NUM_NODES
};

DECL_CLASS_BASED(CBike, CVehicle)
    // Construct/Deconstruct functions
    CBike(){}
    DECL_CTORCALL_PROXY(CBike, _ZN5CBikeC2Eih, int modelIdx, u8 createdBy);
    DECL_DTORCALL_PROXY(CBike, _ZN5CBikeD2Ev);

    // Virtual functions
    virtual bool ProcessAI(unsigned int &);
    

    // STATIC functions
    DECL_FASTCALL_SIMPLE(ProcessRiderAnims, _ZN5CBike17ProcessRiderAnimsEP4CPedP8CVehicleP13CRideAnimDataP17tBikeHandlingDatas, void, CPed* pPed, CVehicle* pVehicle, CRideAnimData* pRideData, tBikeHandlingData* pBikeHandData, i16 nFlags);
    DECL_FASTCALL_SIMPLE(DamageKnockOffRider, _ZN5CBike19DamageKnockOffRiderEP8CVehicleftP7CEntityR7CVectorS5_, bool, CVehicle* arg0, float arg1, u16 arg2, CEntity* arg3, CVector& arg4, CVector& arg5);

    // Member functions
    DECL_THISCALL_SIMPLE(GetAllWheelsOffGround, _ZN5CBike21GetAllWheelsOffGroundEv, u8);
    DECL_THISCALL_SIMPLE(ReduceHornCounter, _ZN5CBike17ReduceHornCounterEv, void);
    DECL_THISCALL_SIMPLE(PlayHornIfNecessary, _ZN5CBike19PlayHornIfNecessaryEv, void);
    DECL_THISCALL_SIMPLE(ProcessBuoyancy, _ZN5CBike15ProcessBuoyancyEv, void);
    DECL_THISCALL_SIMPLE(ResetSuspension, _ZN5CBike15ResetSuspensionEv, void);
    DECL_THISCALL_HEAD(DoSoftGroundResistance, _ZN5CBike22DoSoftGroundResistanceERj, void, u32& arg0)
    DECL_THISCALL_TAIL(DoSoftGroundResistance, arg0)
    DECL_THISCALL_HEAD(FixHandsToBars, _ZN5CBike14FixHandsToBarsEP4CPed, void, CPed* rider)
    DECL_THISCALL_TAIL(FixHandsToBars, rider)
    DECL_THISCALL_SIMPLE(CalculateLeanMatrix, _ZN5CBike19CalculateLeanMatrixEv, void);
    DECL_THISCALL_HEAD(KnockOffRider, _ZN5CBike13KnockOffRiderE11eWeaponTypehP4CPedb, CPed*, eWeaponType arg0, u8 arg1, CPed* arg2, bool arg3)
    DECL_THISCALL_TAIL(KnockOffRider, arg0, arg1, arg2, arg3)
    DECL_THISCALL_HEAD(SetRemoveAnimFlags, _ZN5CBike18SetRemoveAnimFlagsEP4CPed, void, CPed* ped)
    DECL_THISCALL_TAIL(SetRemoveAnimFlags, ped)
    DECL_THISCALL_SIMPLE(PlaceOnRoadProperly, _ZN5CBike19PlaceOnRoadProperlyEv, void);
    DECL_THISCALL_HEAD(GetCorrectedWorldDoorPosition, _ZN5CBike29GetCorrectedWorldDoorPositionER7CVectorS0_S0_, void, CVector& out, CVector arg1, CVector arg2)
    DECL_THISCALL_TAIL(GetCorrectedWorldDoorPosition, out, arg1, arg2)
    DECL_THISCALL_SIMPLE(SetupModelNodes, _ZN5CBike15SetupModelNodesEv, void);
    DECL_THISCALL_SIMPLE(DebugCode, _ZN5CBike9DebugCodeEv, void);
    DECL_THISCALL_HEAD(dmgDrawCarCollidingParticles, _ZN5CBike28dmgDrawCarCollidingParticlesERK7CVectorf11eWeaponType, void, CVector const& position, float power, eWeaponType weaponType)
    DECL_THISCALL_TAIL(dmgDrawCarCollidingParticles, position, power, weaponType)

    // Member values
    RwFrame       *m_aBikeNodes[BIKE_NUM_NODES];
    bool           m_bLeanMatrixCalculated;
    CMatrix        m_mLeanMatrix;
    union
    {
        unsigned char  m_nDamageFlags;
        struct
        {
            unsigned char bShouldNotChangeColour : 1;
            unsigned char bPanelsAreThougher : 1;
            unsigned char bWaterTight : 1;
            unsigned char bGettingPickedUp : 1;
            unsigned char bOnSideStand : 1;
            unsigned char bPlayerBoost : 1;
            unsigned char bEngineOnFire : 1;
            unsigned char bWheelieForCamera : 1;
        };
    };
    CVector m_vecAveGroundNormal;
    CVector m_vecGroundRight;
    CVector m_vecOldSpeedForPlayback;
    tBikeHandlingData *m_pBikeHandlingData;
    CRideAnimData  m_rideAnimData;
    unsigned char  m_anWheelDamageState[2];
    CColPoint      m_anWheelColPoint[4];
    float m_aWheelRatios[4];
    float m_aRatioHistory[4];
    float m_aWheelCounts[4];
    float m_fBrakeCount;
    int            m_anWheelSurfaceType[2];
    bool m_aBloodyWheel[2];
    bool m_aMoreSkidmarks[2];
    float          m_afWheelRotationX[2];
    float m_fWheelSpeed[2];
    float m_fSuspensionHeights[2];
    float m_fOriginalWheelHeights[2];
    float m_fSuspensionLengths[4];
    float m_fLineLengths[4];
    float          m_fHeightAboveRoad;
    float          m_fCarTraction;
    float m_fSwingArm;
    float m_fForkYOff;
    float m_fForkZOff;
    float m_fSteerAngleTan;
    unsigned short m_nBrakes;
    float m_fTyreTemp;
    float m_fBrakingSliding;
    unsigned char  m_bPedLeftHandFixed;
    unsigned char  m_bPedRightHandFixed;
    unsigned char  m_bTestPedCol;
    float m_fPreviousSpeed;
    float m_fBurningTimer; // starts when vehicle health is lower than 250.0, bike blows up when it hits 5000.0
    CPhysical     *m_apWheelCollisionEntity[4];
    CVector        m_avTouchPointsLocalSpace[4];
    CEntity       *m_pDamager;
    unsigned char  m_nNumContactWheels;
    unsigned char  m_nNumWheelsOnGround;
    unsigned char  m_nPrevNumWheelsOnGround;
    float m_fGasPedalAudioRevs;
    unsigned int   m_anWheelState[2]; // enum tWheelState
DECL_CLASS_END()
CHECKSIZE(CBike, 0x828, 0xA18);

DECL_CLASS_BASED(CBmx, CBike)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CBmx, _ZN4CBmxC2Eih, int modelIdx, u8 createdBy);
    DECL_DTORCALL_PROXY(CBmx, _ZN4CBmxD2Ev);
    

    // STATIC functions
    DECL_FASTCALL_SIMPLE(LaunchBunnyHopCB, _ZN4CBmx16LaunchBunnyHopCBEP21CAnimBlendAssociationPv, void, CAnimBlendAssociation* blendAssoc, void* data);

    // Member functions
    DECL_THISCALL_SIMPLE(ProcessBunnyHop, _ZN4CBmx15ProcessBunnyHopEv, void);
    DECL_THISCALL_HEAD(GetFrameOffset, _ZN4CBmx14GetFrameOffsetERfS0_, void, float& arg0, float& arg1)
    DECL_THISCALL_TAIL(GetFrameOffset, arg0, arg1)

    // Member values
    float m_fBunnyHopCharge;
    float m_fPedallingCharge;
    float m_fSprintLeanAngle;
    float m_fCrankAngle;
    float m_fPedalAngleL;
    float m_fPedalAngleR;
    float m_fDistanceBetweenWheels;
    float m_fWheelsBalance;
    bool m_bFreewheeling;
DECL_CLASS_END()

#endif // __AML_PSDK_SABIKE_H
