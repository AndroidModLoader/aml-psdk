#ifndef __AML_PSDK_SABOAT_H
#define __AML_PSDK_SABOAT_H

#include "Vehicle.h"

struct tBoatHandlingData;

enum eBoatNodes
{
    BOAT_NODE_NONE = 0,
    BOAT_MOVING = 1,
    BOAT_WINDSCREEN = 2,
    BOAT_RUDDER = 3,
    BOAT_FLAP_LEFT = 4,
    BOAT_FLAP_RIGHT = 5,
    BOAT_REARFLAP_LEFT = 6,
    BOAT_REARFLAP_RIGHT = 7,
    BOAT_STATIC_PROP = 8,
    BOAT_MOVING_PROP = 9,
    BOAT_STATIC_PROP_2 = 10,
    BOAT_MOVING_PROP_2 = 11,
    BOAT_NUM_NODES
};

DECL_CLASS_BASED(CBoat, CVehicle)
    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CBoat, _ZN5CBoatC2Eih, int modelIdx, u8 createdBy)
    DECL_CTORCALL_ARG_TAIL(modelIdx, createdBy)
    DECL_DTORCALL_VIRTUAL(CBoat, _ZN5CBoatD2Ev, _ZN5CBoat, _ZTV5CBoat);
    

    // STATIC functions
    DECL_FASTCALL_SIMPLE(FillBoatList, _ZN5CBoat12FillBoatListEv, void);
    DECL_FASTCALL_SIMPLE(IsSectorAffectedByWake, _ZN5CBoat22IsSectorAffectedByWakeE9CVector2DfPPS_, bool, CVector2D arg0, float arg1, CBoat** arg2);
    DECL_FASTCALL_SIMPLE(IsVertexAffectedByWake, _ZN5CBoat22IsVertexAffectedByWakeE7CVectorPS_sb, float, CVector arg0, CBoat* arg1, i16 arg2, bool arg3);
    DECL_FASTCALL_SIMPLE(CheckForSkippingCalculations, _ZN5CBoat28CheckForSkippingCalculationsEv, void);

    // STATIC values
    DECL_OBJECT_ARRAY_PLT(CBoat*, apFrameWakeGeneratingBoats, BYBIT(0x67854C, 0x84EAB0));
    DECL_VALUE_PLT_FLT(MIN_WAKE_INTERVAL, BYBIT(0x6780E4, 0x84E1E0));
    DECL_VALUE_PLT_FLT(WAKE_LIFETIME, BYBIT(0x676F8C, 0x84BF58));

    // Member functions
    DECL_THISCALL_SIMPLE(SetupModelNodes, _ZN5CBoat15SetupModelNodesEv, void);
    DECL_THISCALL_SIMPLE(DisplayHandlingData, _ZN5CBoat19DisplayHandlingDataEv, void);
    DECL_THISCALL_HEAD(ModifyHandlingValue, _ZN5CBoat19ModifyHandlingValueERKb, void, bool const& arg0)
    DECL_THISCALL_TAIL(ModifyHandlingValue, arg0)
    DECL_THISCALL_SIMPLE(DebugCode, _ZN5CBoat9DebugCodeEv, void);
    DECL_THISCALL_SIMPLE(PruneWakeTrail, _ZN5CBoat14PruneWakeTrailEv, void);
    DECL_THISCALL_HEAD(AddWakePoint, _ZN5CBoat12AddWakePointE7CVector, void, CVector posn)
    DECL_THISCALL_TAIL(AddWakePoint, posn)

    // Member values
    float              m_fMovingHiRotation; // works as counter also
    float              m_fPropSpeed; // propeller speed
    float              m_fPropRotation; // propeller rotation (radians)
    struct {
        unsigned char bOnWater : 1; // is placed on water
        unsigned char bMovingOnWater : 1;
        unsigned char bAnchored : 1; // is anchored
    } m_nBoatFlags;
    unsigned char      m_nCurrentLOD;
    RwFrame           *m_aBoatNodes[BOAT_NUM_NODES];
    CDoor              m_boatFlap; // for marquis model
    tBoatHandlingData *m_pBoatHandling;
    float              m_fAnchoredAngle; // radians, initialised with -9999.99
    unsigned int       m_nAttackPlayerTime;
    unsigned int       m_nLastParticleTime; // initialised with 0, not used
    float              m_fBurningTimer; // starts when vehicle health is lower than 250.0, boat blows up when it hits 5000.0
    CEntity           *m_pWhoDestroyedMe;
    CVector            m_vecBoatMoveForce; // m_vecBoatMoveForce = m_vecMoveForce + m_vecFrictionMoveForce
    CVector            m_vecBoatTurnForce; // m_vecBoatTurnForce = m_vecTurnForce + m_vecFrictionTurnForce
    FxSystem_c        *m_apPropSplashFx[2];
    CVector            m_vecWaterDamping; // { 0.0f, 0.0f, DampingPower }
    unsigned char      m_nCurrentField; // initialised with 0
    unsigned char      m_nPadNumber; // 0 - 3
    float              m_fWaterResistance; // initialised with 7.0f, 0.0f - not in water
    unsigned short     m_nNumWaterTrailPoints;
    CVector2D          m_avecWakePoints[32];
    float              m_afWakePointLifeTime[32];
    unsigned char      m_anWakePointIntensity[32]; // m_anWakePointIntensity[i] = boat->m_vecMoveForce.Magnitude() * 100.0f;
DECL_CLASS_END()
CHECKSIZE(CBoat, 0x7FC, 0x9E0);

#define apFrameWakeGeneratingBoats apFrameWakeGeneratingBoats()
#define MIN_WAKE_INTERVAL MIN_WAKE_INTERVAL()
#define WAKE_LIFETIME WAKE_LIFETIME()

#endif // __AML_PSDK_SABOAT_H
