#ifndef __AML_PSDK_SATRAIN_H
#define __AML_PSDK_SATRAIN_H

#include "Vehicle.h"

enum eTrainNodes
{
    TRAIN_NODE_NONE = 0,
    TRAIN_DOOR_LF = 1,
    TRAIN_DOOR_RF = 2,
    TRAIN_WHEEL_RF1 = 3,
    TRAIN_WHEEL_RF2 = 4,
    TRAIN_WHEEL_RF3 = 5,
    TRAIN_WHEEL_RB1 = 6,
    TRAIN_WHEEL_RB2 = 7,
    TRAIN_WHEEL_RB3 = 8,
    TRAIN_WHEEL_LF1 = 9,
    TRAIN_WHEEL_LF2 = 10,
    TRAIN_WHEEL_LF3 = 11,
    TRAIN_WHEEL_LB1 = 12,
    TRAIN_WHEEL_LB2 = 13,
    TRAIN_WHEEL_LB3 = 14,
    TRAIN_BOGIE_FRONT = 15,
    TRAIN_BOGIE_REAR = 16,
    TRAIN_NUM_NODES
};

enum eTrainPassengersGenerationState
{
    TRAIN_PASSENGERS_QUERY_NUM_PASSENGERS_TO_LEAVE = 0,
    TRAIN_PASSENGERS_TELL_PASSENGERS_TO_LEAVE = 1,
    TRAIN_PASSENGERS_QUERY_NUM_PASSENGERS_TO_ENTER = 2,
    TRAIN_PASSENGERS_TELL_PASSENGERS_TO_ENTER = 3,
    TRAIN_PASSENGERS_GENERATION_FINISHED = 4
};

DECL_CLASS_BASED(CTrain, CVehicle)
    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CTrain, _ZN6CTrainC2Eih, int modelIdx, u8 createdBy)
    DECL_CTORCALL_ARG_TAIL(modelIdx, createdBy)
    DECL_DTORCALL(CTrain, _ZN6CTrainD2Ev);

    // Member values
    unsigned short    m_nNodeIndex;
    float             m_fTrainSpeed; // 1.0 - train derails
    float             m_fCurrentRailDistance;
    float             m_fLength;
    float             m_fTrainGas; // gas pedal pressed: 255.0, moving forward: 0.0, moving back: -255.0
    float             m_fTrainBrake; // 255.0 - braking
    struct {
        unsigned char bDoorsReady : 1; // initialised with 1
        unsigned char bStoppedAtStation : 1;
        unsigned char bPassengersCanEnterAndLeave : 1;
        unsigned char bIsFrontCarriage : 1;
        unsigned char bIsLastCarriage : 1;
        unsigned char bMissionTrain : 1;
        unsigned char bClockwiseDirection : 1;
        unsigned char bStopsAtStations : 1;
        unsigned char bNotOnARailRoad : 1;
        unsigned char bForceSlowDown : 1;
        unsigned char bIsStreakModel : 1;
    } m_nTrainFlags;
    unsigned int      m_nTimeWhenStoppedAtStation;
    unsigned char     m_nTrackId;
    unsigned int      m_nTimeWhenCreated;
    short m_nDoorsState; // initialized with 0, not referenced
    unsigned char     m_nPassengersGenerationState; // see eTrainPassengersGenerationState
    unsigned char     m_nNumPassengersToLeave : 4; // 0 to 4
    unsigned char     m_nNumPassengersToEnter : 4; // 0 to 4
    CPed             *m_pTemporaryPassenger; // we tell peds to enter train and then delete them
    CTrain           *m_pPrevCarriage;
    CTrain           *m_pNextCarriage;
    CDoor             m_aDoors[6];
    RwFrame          *m_aTrainNodes[TRAIN_NUM_NODES];
DECL_CLASS_END()
CHECKSIZE(CTrain, 0x6C0, 0x8B8);

#endif // __AML_PSDK_SATRAIN_H
