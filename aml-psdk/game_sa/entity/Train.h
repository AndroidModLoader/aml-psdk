#ifndef __AML_PSDK_SATRAIN_H
#define __AML_PSDK_SATRAIN_H

#include "Vehicle.h"

DECL_CLASS(CTrainNode)
    DECL_THISCALL_SIMPLE(GetLightingFromCollision, _ZN10CTrainNode24GetLightingFromCollisionEv, u8);

    inline void SetX(float x) { CoorX = (i16)(i32)(x * 8.0f); }
    inline void SetY(float y) { CoorY = (i16)(i32)(y * 8.0f); }
    inline void SetZ(float z) { CoorZ = (i16)(i32)(z * 8.0f); }
    inline float GetX() const { return CoorX * 0.125f; }
    inline float GetY() const { return CoorY * 0.125f; }
    inline float GetZ() const { return CoorZ * 0.125f; }
    inline CVector GetPosn() const { return { GetX(), GetY(), GetZ() }; }
    inline void SetDistanceFromStart(float distance) { LengthFromStart = (u16)(u32)(distance * 3.0f); }
    inline float GetDistanceFromStart() const { return LengthFromStart / 3.0f; }

    i16 CoorX;
    i16 CoorY;
    i16 CoorZ;
    u16 LengthFromStart;
    u8 lighting;
    bool bLightingHasBeenCalculated;
DECL_CLASS_END()
CHECKSIZE(CTrainNode, 0xA, 0xA);

DECL_CLASS(CTrainDoor)
    // Member functions
    DECL_THISCALL_HEAD(Open, _ZN10CTrainDoor4OpenEf, void, float ratio)
    DECL_THISCALL_TAIL(Open, ratio)
    DECL_THISCALL_SIMPLE(IsClosed, _ZNK10CTrainDoor8IsClosedEv, bool);
    DECL_THISCALL_SIMPLE(IsFullyOpen, _ZNK10CTrainDoor11IsFullyOpenEv, bool);
    DECL_THISCALL_SIMPLE(IsInUse, _ZN10CTrainDoor7IsInUseEv, bool);
    DECL_THISCALL_SIMPLE(RetTranslationWhenClosed, _ZNK10CTrainDoor24RetTranslationWhenClosedEv, float);
    DECL_THISCALL_SIMPLE(RetTranslationWhenOpen, _ZNK10CTrainDoor22RetTranslationWhenOpenEv, float);

    inline float RetDoorTransVel() const { return m_fTransVel; }
    inline float RetDoorTrans() const { return m_fTrans; }
    inline u8 RetAxes() const { return m_nAxis; }
    inline u8 RetDoorState() const { return m_nDoorState; }

    // Member values
    float m_fMaxTrans;
    float m_fMinTrans;
    bool m_bPositive;
    u8 m_nDoorState;
    u8 m_nAxis;
    float m_fTrans;
    float m_fPrevTrans;
    float m_fTransVel;
DECL_CLASS_END()
CHECKSIZE(CTrainDoor, 0x18, 0x18);


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
    DECL_DTORCALL_VIRTUAL(CTrain, _ZN6CTrainD2Ev, _ZN6CTrain, _ZTV6CTrain);

    // STATIC functions
    DECL_FASTCALL_SIMPLE(ReadAndInterpretTrackFile, _ZN6CTrain25ReadAndInterpretTrackFileEPcPP10CTrainNodePiPfi, void, char* filename, CTrainNode** nodes, i32* lineCount, float* totalDist, i32 skipStations);
    DECL_FASTCALL_SIMPLE(InitTrains, _ZN6CTrain10InitTrainsEv, void);
    DECL_FASTCALL_SIMPLE(Shutdown, _ZN6CTrain8ShutdownEv, void);
    DECL_FASTCALL_SIMPLE(UpdateTrains, _ZN6CTrain12UpdateTrainsEv, void);
    DECL_FASTCALL_SIMPLE(DisableRandomTrains, _ZN6CTrain19DisableRandomTrainsEb, void, bool disable);
    DECL_FASTCALL_SIMPLE(CreateMissionTrain, _ZN6CTrain18CreateMissionTrainE7CVectorbjPPS_S2_iib, void, CVector posn, bool clockwiseDirection, u32 trainType, CTrain** outFirstCarriage, CTrain** outLastCarriage, i32 nodeIndex, i32 trackId, bool isMissionTrain);
    DECL_FASTCALL_SIMPLE(RemoveMissionTrains, _ZN6CTrain19RemoveMissionTrainsEv, void);
    DECL_FASTCALL_SIMPLE(ReleaseMissionTrains, _ZN6CTrain20ReleaseMissionTrainsEv, void);
    DECL_FASTCALL_SIMPLE(ReleaseOneMissionTrain, _ZN6CTrain22ReleaseOneMissionTrainEPS_, void, CTrain* train);
    DECL_FASTCALL_SIMPLE(RemoveOneMissionTrain, _ZN6CTrain21RemoveOneMissionTrainEPS_, void, CTrain* train);
    DECL_FASTCALL_SIMPLE(RemoveAllTrains, _ZN6CTrain15RemoveAllTrainsEv, void);
    DECL_FASTCALL_SIMPLE(SetTrainSpeed, _ZN6CTrain13SetTrainSpeedEPS_f, void, CTrain* train, float speed);
    DECL_FASTCALL_SIMPLE(SetTrainCruiseSpeed, _ZN6CTrain19SetTrainCruiseSpeedEPS_f, void, CTrain* arg0, float cruiseSpeed);
    DECL_FASTCALL_SIMPLE(FindCaboose, _ZN6CTrain11FindCabooseEPS_, CTrain*, CTrain* train);
    DECL_FASTCALL_SIMPLE(FindEngine, _ZN6CTrain10FindEngineEPS_, CTrain*, CTrain* train);
    DECL_FASTCALL_SIMPLE(FindCarriage, _ZN6CTrain12FindCarriageEPS_h, CTrain*, CTrain* train, u8 carriage);
    DECL_FASTCALL_SIMPLE(FindCoorsFromPositionOnTrack, _ZN6CTrain28FindCoorsFromPositionOnTrackEfiP7CVector, void, float railDistance, i32 trackId, CVector* outCoors);
    DECL_FASTCALL_SIMPLE(FindClosestTrackNode, _ZN6CTrain20FindClosestTrackNodeE7CVectorPi, i32, CVector posn, i32* outTrackId);
    DECL_FASTCALL_SIMPLE(FindNearestTrain, _ZN6CTrain16FindNearestTrainE7CVectorb, CTrain*, CVector posn, bool mustBeMainTrain);
    DECL_FASTCALL_SIMPLE(SetNewTrainPosition, _ZN6CTrain19SetNewTrainPositionEPS_7CVector, void, CTrain* train, CVector posn);
    DECL_FASTCALL_SIMPLE(IsNextStationAllowed, _ZN6CTrain20IsNextStationAllowedEPS_, bool, CTrain* train);
    DECL_FASTCALL_SIMPLE(SkipToNextAllowedStation, _ZN6CTrain24SkipToNextAllowedStationEPS_, void, CTrain* train);
    DECL_FASTCALL_SIMPLE(FindNextStationPositionInDirection, _ZN6CTrain34FindNextStationPositionInDirectionEbfPfPi, void, bool clockwiseDirection, float distance, float* distanceToStation, i32* numStations);
    DECL_FASTCALL_SIMPLE(DoTrainGenerationAndRemoval, _ZN6CTrain27DoTrainGenerationAndRemovalEv, void);

    // STATIC values
    DECL_OBJECT_ARRAY_PLT(CVector, aStationCoors, BYBIT(0x6779FC, 0x84D420));
    DECL_VALUE_PLT_BOOL(bDisableRandomTrains, BYBIT(0x6779D0, 0x84D3C8));
    DECL_VALUE_PLT_I32(GenTrain_Status, BYBIT(0x679220, 0x850460));
    DECL_VALUE_PLT_I32(GenTrain_GenerationNode, BYBIT(0x679F80, 0x851F10));
    DECL_VALUE_PLT_BOOL(GenTrain_Direction, BYBIT(0x6786CC, 0x84EDC0));
    DECL_VALUE_PLT_U32(GenTrain_TrainConfig, BYBIT(0x679E00, 0x851C10));
    DECL_VALUE_PLT_I32(GenTrain_Track, BYBIT(0x6789A8, 0x84F370));

    // Member functions
    DECL_THISCALL_HEAD(AddPassenger, _ZN6CTrain12AddPassengerEP4CPed, void, CPed* ped)
    DECL_THISCALL_TAIL(AddPassenger, ped)
    DECL_THISCALL_HEAD(RemovePassenger, _ZN6CTrain15RemovePassengerEP4CPed, void, CPed* ped)
    DECL_THISCALL_TAIL(RemovePassenger, ped)
    DECL_THISCALL_SIMPLE(RemoveRandomPassenger, _ZN6CTrain21RemoveRandomPassengerEv, void);
    DECL_THISCALL_SIMPLE(AddNearbyPedAsRandomPassenger, _ZN6CTrain29AddNearbyPedAsRandomPassengerEv, void);
    DECL_THISCALL_SIMPLE(IsInTunnel, _ZN6CTrain10IsInTunnelEv, bool);
    DECL_THISCALL_HEAD(OpenTrainDoor, _ZN6CTrain13OpenTrainDoorEf, void, float state)
    DECL_THISCALL_TAIL(OpenTrainDoor, state)
    DECL_THISCALL_HEAD(FindMaximumSpeedToStopAtStations, _ZN6CTrain32FindMaximumSpeedToStopAtStationsEPf, bool, float* speed)
    DECL_THISCALL_TAIL(FindMaximumSpeedToStopAtStations, speed)
    DECL_THISCALL_SIMPLE(FindNumCarriagesPulled, _ZN6CTrain22FindNumCarriagesPulledEv, i32);
    DECL_THISCALL_SIMPLE(FindPositionOnTrackFromCoors, _ZN6CTrain28FindPositionOnTrackFromCoorsEv, void);
    DECL_THISCALL_SIMPLE(FindSideStationIsOn, _ZN6CTrain19FindSideStationIsOnEv, bool);

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

DECL_FASTCALL_SIMPLE_GLO(TrainHitStuff, _Z13TrainHitStuffR8CPtrListP7CEntity, void, CPtrList& list, CEntity* exception);
DECL_FASTCALL_SIMPLE_GLO(MarkSurroundingEntitiesForCollisionWithTrain, _Z44MarkSurroundingEntitiesForCollisionWithTrain7CVectorfP7CEntityb, void, CVector center, float size, CEntity* exception, bool onlyVehicles);

DECL_OBJECT_ARRAY_PLT_GLOBAL(i32, NumTrackNodes, BYBIT(0x6789BC, 0x84F398));
DECL_OBJECT_ARRAY_PLT_GLOBAL(CTrainNode*, pTrackNodes, BYBIT(0x679FB8, 0x851F80));
DECL_OBJECT_ARRAY_PLT_GLOBAL(float, StationDist, BYBIT(0x675EE4, 0x849E38));

#define NumTrackNodes NumTrackNodes()
#define pTrackNodes pTrackNodes()
#define StationDist StationDist()

#define aStationCoors aStationCoors()
#define bDisableRandomTrains bDisableRandomTrains()
#define GenTrain_Status GenTrain_Status()
#define GenTrain_GenerationNode GenTrain_GenerationNode()
#define GenTrain_Direction GenTrain_Direction()
#define GenTrain_TrainConfig GenTrain_TrainConfig()
#define GenTrain_Track GenTrain_Track()

#endif // __AML_PSDK_SATRAIN_H
