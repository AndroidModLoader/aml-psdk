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
    DECL_DTORCALL(CBoat, _ZN5CBoatD2Ev);
    
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

#endif // __AML_PSDK_SABOAT_H
