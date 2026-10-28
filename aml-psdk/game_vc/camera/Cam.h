#ifndef __AML_PSDK_VCCAM_H
#define __AML_PSDK_VCCAM_H

#include <aml-psdk/game_vc/plugin.h>
#include <aml-psdk/gta_base/Vector.h>

struct CEntity;
struct CPed;
struct CAutomobile;

enum eCamMode : i16
{
	MODE_NONE = 0,
	MODE_TOP_DOWN,
	MODE_GTA_CLASSIC,
	MODE_BEHIND_CAR,
	MODE_FOLLOW_PED,
	MODE_AIMING,
	MODE_DEBUG,
	MODE_SNIPER,
	MODE_ROCKET_LAUNCHER,
	MODE_MODEL_VIEW,
	MODE_BILL,
	MODE_SYPHON,
	MODE_CIRCLE,
	MODE_CHEESY_ZOOM,
	MODE_WHEEL_CAM,
	MODE_FIXED,
	MODE_1ST_PERSON,
	MODE_FLYBY,
	MODE_CAM_ON_A_STRING,
	MODE_REACTION,
	MODE_FOLLOW_PED_WITH_BIND,
	MODE_CHRIS,
	MODE_BEHIND_BOAT,
	MODE_PLAYER_FALLEN_WATER,
	MODE_CAM_ON_TRAIN_ROOF,
	MODE_CAM_RUNNING_SIDE_TRAIN,
	MODE_BLOOD_ON_THE_TRACKS,
	MODE_IM_THE_PASSENGER_WOOWOO,
	MODE_SYPHON_CRIM_IN_FRONT,
	MODE_PED_DEAD_BABY,
	MODE_PILLOWS_PAPS,
	MODE_LOOK_AT_CARS,
	MODE_ARREST_CAM_ONE,
	MODE_ARREST_CAM_TWO,
	MODE_M16_1ST_PERSON,
	MODE_SPECIAL_FIXED_FOR_SYPHON,
	MODE_FIGHT_CAM,
	MODE_TOP_DOWN_PED,
	MODE_LIGHT_HOUSE,
	MODE_SNIPER_RUNABOUT,
	MODE_ROCKET_LAUNCHER_RUNABOUT,
	MODE_1ST_PERSON_RUNABOUT,
	MODE_M16_1ST_PERSON_RUNABOUT,
	MODE_FIGHT_CAM_RUNABOUT,
	MODE_EDITOR,
	MODE_HELI_CANNON_1ST_PERSON,
	MODE_CAMERA,
};

DECL_CLASS(CCam)
    CCam() { Init(); }

    // Member functions
    DECL_THISCALL_SIMPLE(Init, _ZN4CCam4InitEv, void);
    DECL_THISCALL_SIMPLE(Process, _ZN4CCam7ProcessEv, void);
    DECL_THISCALL_SIMPLE(Using3rdPersonMouseCam, _ZN4CCam22Using3rdPersonMouseCamEv, bool);
    DECL_THISCALL_SIMPLE(GetWeaponFirstPersonOn, _ZN4CCam22GetWeaponFirstPersonOnEv, bool);
    DECL_THISCALL_SIMPLE(GetVectorsReadyForRW, _ZN4CCam20GetVectorsReadyForRWEv, void);
    DECL_THISCALL_SIMPLE(LookBehind, _ZN4CCam10LookBehindEv, void);
    DECL_THISCALL_SIMPLE(LookLeft, _ZN4CCam8LookLeftEv, void);
    DECL_THISCALL_SIMPLE(LookRight, _ZN4CCam9LookRightEv, void);
    DECL_THISCALL_SIMPLE(ProcessArrestCamOne, _ZN4CCam19ProcessArrestCamOneEv, bool);
    DECL_THISCALL_SIMPLE(ProcessArrestCamTwo, _ZN4CCam19ProcessArrestCamTwoEv, bool);
    DECL_THISCALL_SIMPLE(ProcessPedsDeadBaby, _ZN4CCam19ProcessPedsDeadBabyEv, void);
    DECL_THISCALL_SIMPLE(ProcessSpecialHeightRoutines, _ZN4CCam28ProcessSpecialHeightRoutinesEv, void);
    DECL_THISCALL_SIMPLE(ClipIfPedInFrontOfPlayer, _ZN4CCam24ClipIfPedInFrontOfPlayerEv, void);
    DECL_THISCALL_HEAD(LookOffsetAngle, _ZN4CCam15LookOffsetAngleEf, void, float angle)
    DECL_THISCALL_TAIL(LookOffsetAngle, angle)
    DECL_THISCALL_HEAD(IsTargetInWater, _ZN4CCam15IsTargetInWaterERK7CVector, bool, CVector const& target)
    DECL_THISCALL_TAIL(IsTargetInWater, target)
    DECL_THISCALL_HEAD(DoAverageOnVector, _ZN4CCam17DoAverageOnVectorERK7CVector, CVector, CVector const& vector)
    DECL_THISCALL_TAIL(DoAverageOnVector, vector)
    DECL_THISCALL_HEAD(FixCamWhenObscuredByVehicle, _ZN4CCam27FixCamWhenObscuredByVehicleERK7CVector, void, CVector const& target)
    DECL_THISCALL_TAIL(FixCamWhenObscuredByVehicle, target)
    DECL_THISCALL_HEAD(GetBoatLook_L_R_HeightOffset, _ZN4CCam28GetBoatLook_L_R_HeightOffsetERf, bool, float& heightOffset)
    DECL_THISCALL_TAIL(GetBoatLook_L_R_HeightOffset, heightOffset)
    DECL_THISCALL_HEAD(NeedsTracking, _ZN4CCam13NeedsTrackingEP7CEntity, bool, CEntity* entity)
    DECL_THISCALL_TAIL(NeedsTracking, entity)
    DECL_THISCALL_HEAD(RotCamIfInFrontCar, _ZN4CCam18RotCamIfInFrontCarERK7CVectorf, bool, CVector const& target, float orientation)
    DECL_THISCALL_TAIL(RotCamIfInFrontCar, target, orientation)
    DECL_THISCALL_HEAD(Cam_On_A_String_Unobscured, _ZN4CCam26Cam_On_A_String_UnobscuredERK7CVectorf, void, CVector const& target, float height)
    DECL_THISCALL_TAIL(Cam_On_A_String_Unobscured, target, height)
    DECL_THISCALL_HEAD(WorkOutCamHeight, _ZN4CCam16WorkOutCamHeightERK7CVectorff, void, CVector const& target, float orientation, float topHeight)
    DECL_THISCALL_TAIL(WorkOutCamHeight, target, orientation, topHeight)
    DECL_THISCALL_HEAD(KeepTrackOfTheSpeed, _ZN4CCam19KeepTrackOfTheSpeedERK7CVectorS2_S2_RKfS4_S4_, void, CVector const& source, CVector const& target, CVector const& up, float const& alpha, float const& beta, float const& fov)
    DECL_THISCALL_TAIL(KeepTrackOfTheSpeed, source, target, up, alpha, beta, fov)
    DECL_THISCALL_HEAD(Process_1stPerson, _ZN4CCam17Process_1stPersonERK7CVectorfff, void, CVector const& target, float orientation, float speed, float desiredSpeed)
    DECL_THISCALL_TAIL(Process_1stPerson, target, orientation, speed, desiredSpeed)
    DECL_THISCALL_HEAD(Process_M16_1stPerson, _ZN4CCam21Process_M16_1stPersonERK7CVectorfff, void, CVector const& target, float orientation, float speed, float desiredSpeed)
    DECL_THISCALL_TAIL(Process_M16_1stPerson, target, orientation, speed, desiredSpeed)
    DECL_THISCALL_HEAD(Process_Rocket, _ZN4CCam14Process_RocketERK7CVectorfff, void, CVector const& target, float orientation, float speed, float desiredSpeed)
    DECL_THISCALL_TAIL(Process_Rocket, target, orientation, speed, desiredSpeed)
    DECL_THISCALL_HEAD(Process_Sniper, _ZN4CCam14Process_SniperERK7CVectorfff, void, CVector const& target, float orientation, float speed, float desiredSpeed)
    DECL_THISCALL_TAIL(Process_Sniper, target, orientation, speed, desiredSpeed)
    DECL_THISCALL_HEAD(Process_FollowPed, _ZN4CCam17Process_FollowPedERK7CVectorfff, void, CVector const& target, float orientation, float speed, float desiredSpeed)
    DECL_THISCALL_TAIL(Process_FollowPed, target, orientation, speed, desiredSpeed)
    DECL_THISCALL_HEAD(Process_FollowPedWithMouse, _ZN4CCam26Process_FollowPedWithMouseERK7CVectorfff, void, CVector const& target, float orientation, float speed, float desiredSpeed)
    DECL_THISCALL_TAIL(Process_FollowPedWithMouse, target, orientation, speed, desiredSpeed)
    DECL_THISCALL_HEAD(Process_Fight_Cam, _ZN4CCam17Process_Fight_CamERK7CVectorfff, void, CVector const& target, float orientation, float speed, float desiredSpeed)
    DECL_THISCALL_TAIL(Process_Fight_Cam, target, orientation, speed, desiredSpeed)
    DECL_THISCALL_HEAD(Process_Fixed, _ZN4CCam13Process_FixedERK7CVectorfff, void, CVector const& target, float orientation, float speed, float desiredSpeed)
    DECL_THISCALL_TAIL(Process_Fixed, target, orientation, speed, desiredSpeed)
    DECL_THISCALL_HEAD(Process_LightHouse, _ZN4CCam18Process_LightHouseERK7CVectorfff, void, CVector const& target, float orientation, float speed, float desiredSpeed)
    DECL_THISCALL_TAIL(Process_LightHouse, target, orientation, speed, desiredSpeed)
    DECL_THISCALL_HEAD(Process_Syphon, _ZN4CCam14Process_SyphonERK7CVectorfff, void, CVector const& target, float orientation, float speed, float desiredSpeed)
    DECL_THISCALL_TAIL(Process_Syphon, target, orientation, speed, desiredSpeed)
    DECL_THISCALL_HEAD(Process_Syphon_Crim_In_Front, _ZN4CCam28Process_Syphon_Crim_In_FrontERK7CVectorfff, void, CVector const& target, float orientation, float speed, float desiredSpeed)
    DECL_THISCALL_TAIL(Process_Syphon_Crim_In_Front, target, orientation, speed, desiredSpeed)
    DECL_THISCALL_HEAD(Process_Editor, _ZN4CCam14Process_EditorERK7CVectorfff, void, CVector const& target, float orientation, float speed, float desiredSpeed)
    DECL_THISCALL_TAIL(Process_Editor, target, orientation, speed, desiredSpeed)
    DECL_THISCALL_HEAD(Process_1rstPersonPedOnPC, _ZN4CCam25Process_1rstPersonPedOnPCERK7CVectorfff, void, CVector const& target, float orientation, float speed, float desiredSpeed)
    DECL_THISCALL_TAIL(Process_1rstPersonPedOnPC, target, orientation, speed, desiredSpeed)
    DECL_THISCALL_HEAD(Process_FlyBy, _ZN4CCam13Process_FlyByERK7CVectorfff, void, CVector const& target, float orientation, float speed, float desiredSpeed)
    DECL_THISCALL_TAIL(Process_FlyBy, target, orientation, speed, desiredSpeed)
    DECL_THISCALL_HEAD(Process_BehindCar, _ZN4CCam17Process_BehindCarERK7CVectorfff, void, CVector const& target, float orientation, float speed, float desiredSpeed)
    DECL_THISCALL_TAIL(Process_BehindCar, target, orientation, speed, desiredSpeed)
    DECL_THISCALL_HEAD(Process_BehindBoat, _ZN4CCam18Process_BehindBoatERK7CVectorfff, void, CVector const& target, float orientation, float speed, float desiredSpeed)
    DECL_THISCALL_TAIL(Process_BehindBoat, target, orientation, speed, desiredSpeed)
    DECL_THISCALL_HEAD(Process_Player_Fallen_Water, _ZN4CCam27Process_Player_Fallen_WaterERK7CVectorfff, void, CVector const& target, float orientation, float speed, float desiredSpeed)
    DECL_THISCALL_TAIL(Process_Player_Fallen_Water, target, orientation, speed, desiredSpeed)
    DECL_THISCALL_HEAD(Process_SpecialFixedForSyphon, _ZN4CCam29Process_SpecialFixedForSyphonERK7CVectorfff, void, CVector const& target, float orientation, float speed, float desiredSpeed)
    DECL_THISCALL_TAIL(Process_SpecialFixedForSyphon, target, orientation, speed, desiredSpeed)
    DECL_THISCALL_HEAD(Process_Cam_On_A_String, _ZN4CCam23Process_Cam_On_A_StringERK7CVectorfff, void, CVector const& target, float orientation, float speed, float desiredSpeed)
    DECL_THISCALL_TAIL(Process_Cam_On_A_String, target, orientation, speed, desiredSpeed)
    DECL_THISCALL_HEAD(Process_WheelCam, _ZN4CCam16Process_WheelCamERK7CVectorfff, bool, CVector const& target, float orientation, float speed, float desiredSpeed)
    DECL_THISCALL_TAIL(Process_WheelCam, target, orientation, speed, desiredSpeed)
    DECL_THISCALL_HEAD(GetLookOverShoulderPos, _ZN4CCam22GetLookOverShoulderPosEP7CEntityP4CPedR7CVectorS5_, bool, CEntity* targetEntity, CPed* cop, CVector& target, CVector& source)
    DECL_THISCALL_TAIL(GetLookOverShoulderPos, targetEntity, cop, target, source)
    DECL_THISCALL_HEAD(GetLookAlongGroundPos, _ZN4CCam21GetLookAlongGroundPosEP7CEntityP4CPedR7CVectorS5_, bool, CEntity* targetEntity, CPed* cop, CVector& target, CVector& source)
    DECL_THISCALL_TAIL(GetLookAlongGroundPos, targetEntity, cop, target, source)
    DECL_THISCALL_HEAD(GetLookFromLampPostPos, _ZN4CCam22GetLookFromLampPostPosEP7CEntityP4CPedR7CVectorS5_, bool, CEntity* targetEntity, CPed* cop, CVector& target, CVector& source)
    DECL_THISCALL_TAIL(GetLookFromLampPostPos, targetEntity, cop, target, source)

    // Member values
    bool m_bBelowMinDist;
    bool m_bBehindPlayerDesired;
    bool m_bCamLookingAtVector;
    bool m_bCollisionChecksOn;
    bool m_bFixingBeta;
    bool m_bLookBehindCamWasInFront;
    bool m_bLookingBehind;
    bool m_bLookingLeft;
    bool m_bLookingRight;
    bool m_bResetStatics;
    bool m_bRotating;
    eCamMode m_nCamMode;
    u32 m_nFinishTime;
    i32 m_nDoCollisionChecksOnFrameNum;
    i32 m_nDoCollisionCheckEveryNumOfFrames;
    i32 m_nFrameNumWereAt;
    i32 m_nRunningVectorArrayPos;
    i32 m_nRunningVectorCounter;
    i32 DirectionWasLooking;
    float m_fMaxRoleAngle;
    float m_fRoll;
    float m_fRollSpeed;
    float m_fSyphonModeTargetZOffSet;
    float m_fAmountFractionObscured;
    float m_fAlphaSpeedOverOneFrame;
    float m_fBetaSpeedOverOneFrame;
    float m_fBufferedTargetBeta;
    float m_fBufferedTargetOrientation;
    float m_fBufferedTargetOrientationSpeed;
    float m_fCamBufferedHeight;
    float m_fCamBufferedHeightSpeed;
    float m_fCloseInPedHeightOffset;
    float m_fCloseInPedHeightOffsetSpeed;
    float m_fCloseInCarHeightOffset;
    float m_fCloseInCarHeightOffsetSpeed;
    float m_fDimensionOfHighestNearCar;
    float m_fDistanceBeforeChanges;
    float m_fFovSpeedOverOneFrame;
    float m_fMinDistAwayFromCamWhenInterPolating;
    float m_fPedBetweenCameraHeightOffset;
    float m_fPlayerInFrontSyphonAngleOffSet;
    float m_fRadiusForDead;
    float m_fRealGroundDist;
    float m_fTargetBeta;
    float m_fTimeElapsedFloat;
    float m_fTilt;
    float m_fTiltSpeed;
    float m_fTransitionBeta;
    float m_fTrueBeta;
    float m_fTrueAlpha;
    float m_fInitialPlayerOrientation;
    float m_fVerticalAngle;
    float m_fAlphaSpeed;
    float m_fFOV;
    float m_fFOVSpeed;
    float m_fHorizontalAngle;
    float m_fBetaSpeed;
    float m_fDistance;
    float m_fCA_MIN_DISTANCE;
    float m_fCA_MAX_DISTANCE;
    float m_fSpeedVar;
    float m_fTargetZoomGroundOne;
    float m_fTargetZoomGroundTwo;
    float m_fTargetZoomGroundThree;
    float m_fTargetZoomOneZExtra;
    float m_fTargetZoomTwoZExtra;
    float m_fTargetZoomThreeZExtra;
    float m_fTargetZoomZCloseIn;
    float m_fMinRealGroundDist;
    float m_fTargetCloseInDist;
    CVector m_vecSourceSpeedOverOneFrame;
    CVector m_vecTargetSpeedOverOneFrame;
    CVector m_vecUpOverOneFrame;
    CVector m_vecTargetCoorsForFudgeInter;
    CVector m_vecCamFixedModeVector;
    CVector m_vecCamFixedModeSource;
    CVector m_vecCamFixedModeUpOffSet;
    CVector m_vecLastAboveWaterCamPosition;
    CVector m_vecBufferedPlayerBodyOffset;
    CVector m_vecFront;
    CVector m_vecSource;
    CVector m_vecSourceBeforeLookBehind;
    CVector m_vecUp;
    CVector m_arrPreviousVectors[2];
    CEntity* m_pCamTargetEntity;
    float m_fCameraDistance;
    float m_fIdealAlpha;
    float m_fPlayerVelocity;
    CAutomobile* m_pLastCarEntered;
    CPed* m_pLastPedLookedAt;
    bool m_bFirstPersonRunAboutActive;
DECL_CLASS_END()
CHECKSIZE(CCam, 0x1C8, 0x1E0);

#endif // __AML_PSDK_VCCAM_H
