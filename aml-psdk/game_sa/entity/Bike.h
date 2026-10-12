#ifndef __AML_PSDK_SABIKE_H
#define __AML_PSDK_SABIKE_H

#include "Vehicle.h"

struct tBikeHandlingData;

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
    DECL_CTORCALL_ARG_HEAD(CBike, _ZN5CBikeC2Eih, int modelIdx, u8 createdBy)
    DECL_CTORCALL_ARG_TAIL(modelIdx, createdBy)
    DECL_DTORCALL(CBike, _ZN5CBikeD2Ev);

    // Virtual functions
    virtual bool ProcessAI(unsigned int &);
    
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
    DECL_CTORCALL_ARG_HEAD(CBmx, _ZN4CBmxC2Eih, int modelIdx, u8 createdBy)
    DECL_CTORCALL_ARG_TAIL(modelIdx, createdBy)
    DECL_DTORCALL(CBmx, _ZN4CBmxD2Ev);
    
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
