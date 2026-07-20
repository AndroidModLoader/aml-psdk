#ifndef __AML_PSDK_SACAMERA_H
#define __AML_PSDK_SACAMERA_H

#include "Placeable.h"
#include "../engine/Cam.h"

struct RwCamera;
struct CGarage;
struct CPed;
struct CVehicle;
struct CPlayerPed;
struct CEntity;
struct CRect;

struct CQueuedMode
{
    unsigned short m_nMode;
    float          m_fDuration;
    unsigned short m_nMinZoom;
    unsigned short m_nMaxZoom;
};

struct CCamPathSplines
{
    float *m_pArrPathData;
};

DECL_CLASS_BASED(CCamera, CPlaceable)
    // Construct/Deconstruct functions
    DECL_CTORCALL(CCamera, _ZN7CCameraC2Ev)
    DECL_DTORCALL(CCamera, _ZN7CCameraD0Ev);

    // Member functions
    DECL_THISCALL_SIMPLE(GetCamDirectlyBehind, _ZN7CCamera20GetCamDirectlyBehindEv, bool);
    DECL_THISCALL_SIMPLE(Find3rdPersonQuickAimPitch, _ZN7CCamera26Find3rdPersonQuickAimPitchEv, float);
    DECL_THISCALL_SIMPLE(GetFading, _ZN7CCamera9GetFadingEv, u8);
    DECL_THISCALL_SIMPLE(GetFadingDirection, _ZN7CCamera18GetFadingDirectionEv, int);
    DECL_THISCALL_SIMPLE(InitCameraVehicleTweaks, _ZN7CCamera23InitCameraVehicleTweaksEv, void);
    DECL_THISCALL_SIMPLE(CamControl, _ZN7CCamera10CamControlEv, void);
    DECL_THISCALL_SIMPLE(Restore, _ZN7CCamera7RestoreEv, void);
    DECL_THISCALL_SIMPLE(SetWideScreenOff, _ZN7CCamera16SetWideScreenOffEv, void);
    DECL_THISCALL_SIMPLE(Using1stPersonWeaponMode, _ZN7CCamera24Using1stPersonWeaponModeEv, bool);
    DECL_THISCALL_SIMPLE(IsTargetingActive, _ZN7CCamera17IsTargetingActiveEv, bool);
    DECL_THISCALL_SIMPLE(ClearPlayerWeaponMode, _ZN7CCamera21ClearPlayerWeaponModeEv, void);
    DECL_THISCALL_SIMPLE(SetCameraDirectlyBehindForFollowPed_CamOnAString, _ZN7CCamera48SetCameraDirectlyBehindForFollowPed_CamOnAStringEv, void);
    DECL_THISCALL_SIMPLE(ProcessObbeCinemaCameraPlane, _ZN7CCamera28ProcessObbeCinemaCameraPlaneEv, void);
    DECL_THISCALL_SIMPLE(ProcessObbeCinemaCameraHeli, _ZN7CCamera27ProcessObbeCinemaCameraHeliEv, void);
    DECL_THISCALL_SIMPLE(ProcessObbeCinemaCameraBoat, _ZN7CCamera27ProcessObbeCinemaCameraBoatEv, void);
    DECL_THISCALL_SIMPLE(ProcessObbeCinemaCameraTrain, _ZN7CCamera28ProcessObbeCinemaCameraTrainEv, void);
    DECL_THISCALL_SIMPLE(ProcessObbeCinemaCameraCar, _ZN7CCamera26ProcessObbeCinemaCameraCarEv, void);
    DECL_THISCALL_SIMPLE(DontProcessObbeCinemaCamera, _ZN7CCamera27DontProcessObbeCinemaCameraEv, void);
    DECL_THISCALL_SIMPLE(RestoreWithJumpCut, _ZN7CCamera18RestoreWithJumpCutEv, void);
    DECL_THISCALL_SIMPLE(DrawBordersForWideScreen, _ZN7CCamera24DrawBordersForWideScreenEv, void);
    DECL_THISCALL_SIMPLE(GetCutsceneBarHeight, _ZN7CCamera20GetCutsceneBarHeightEv, float);
    DECL_THISCALL_SIMPLE(Enable1rstPersonCamCntrlsScript, _ZN7CCamera31Enable1rstPersonCamCntrlsScriptEv, void);
    DECL_THISCALL_SIMPLE(Enable1rstPersonWeaponsCamera, _ZN7CCamera29Enable1rstPersonWeaponsCameraEv, void);
    DECL_THISCALL_SIMPLE(FinishCutscene, _ZN7CCamera14FinishCutsceneEv, void);
    DECL_THISCALL_SIMPLE(FindCamFOV, _ZN7CCamera10FindCamFOVEv, float);
    DECL_THISCALL_SIMPLE(GetCutSceneFinishTime, _ZN7CCamera21GetCutSceneFinishTimeEv, u32);
    DECL_THISCALL_SIMPLE(Get_Just_Switched_Status, _ZN7CCamera24Get_Just_Switched_StatusEv, u8);
    DECL_THISCALL_SIMPLE(GetScreenFadeStatus, _ZN7CCamera19GetScreenFadeStatusEv, int);
    DECL_THISCALL_SIMPLE(GetGameCamPosition, _ZN7CCamera18GetGameCamPositionEv, CVector*);
    DECL_THISCALL_SIMPLE(GetLookingLRBFirstPerson, _ZN7CCamera24GetLookingLRBFirstPersonEv, bool);
    DECL_THISCALL_SIMPLE(GetLookDirection, _ZN7CCamera16GetLookDirectionEv, int);
    DECL_THISCALL_SIMPLE(GetLookingForwardFirstPerson, _ZN7CCamera28GetLookingForwardFirstPersonEv, bool);
    DECL_THISCALL_SIMPLE(GetPositionAlongSpline, _ZN7CCamera22GetPositionAlongSplineEv, float);
    DECL_THISCALL_SIMPLE(InitialiseCameraForDebugMode, _ZN7CCamera28InitialiseCameraForDebugModeEv, void);
    DECL_THISCALL_SIMPLE(Process, _ZN7CCamera7ProcessEv, void);
    DECL_THISCALL_SIMPLE(UpdateTargetEntity, _ZN7CCamera18UpdateTargetEntityEv, void);
    DECL_THISCALL_SIMPLE(ProcessScriptedCommands, _ZN7CCamera23ProcessScriptedCommandsEv, void);
    DECL_THISCALL_SIMPLE(ProcessFade, _ZN7CCamera11ProcessFadeEv, void);
    DECL_THISCALL_SIMPLE(ProcessMusicFade, _ZN7CCamera16ProcessMusicFadeEv, void);
    DECL_THISCALL_SIMPLE(ProcessWideScreenOn, _ZN7CCamera19ProcessWideScreenOnEv, void);
    DECL_THISCALL_SIMPLE(ProcessShake, _ZN7CCamera12ProcessShakeEv, void);
    DECL_THISCALL_SIMPLE(UpdateSoundDistances, _ZN7CCamera20UpdateSoundDistancesEv, void);
    DECL_THISCALL_SIMPLE(SetCameraUpForMirror, _ZN7CCamera20SetCameraUpForMirrorEv, void);
    DECL_THISCALL_SIMPLE(RestoreCameraAfterMirror, _ZN7CCamera24RestoreCameraAfterMirrorEv, void);
    DECL_THISCALL_SIMPLE(ProcessObbeCinemaCameraPed, _ZN7CCamera26ProcessObbeCinemaCameraPedEv, void);
    DECL_THISCALL_SIMPLE(RenderMotionBlur, _ZN7CCamera16RenderMotionBlurEv, void);
    DECL_THISCALL_SIMPLE(SetCameraDirectlyInFrontForFollowPed_CamOnAString, _ZN7CCamera49SetCameraDirectlyInFrontForFollowPed_CamOnAStringEv, void);
    DECL_THISCALL_SIMPLE(SetWideScreenOn, _ZN7CCamera15SetWideScreenOnEv, void);
    DECL_THISCALL_SIMPLE(StartCooperativeCamMode, _ZN7CCamera23StartCooperativeCamModeEv, void);
    DECL_THISCALL_SIMPLE(StopCooperativeCamMode, _ZN7CCamera22StopCooperativeCamModeEv, void);
    DECL_THISCALL_SIMPLE(ProcessVectorTrackLinear, _ZN7CCamera24ProcessVectorTrackLinearEv, void);
    DECL_THISCALL_SIMPLE(ProcessVectorMoveLinear, _ZN7CCamera23ProcessVectorMoveLinearEv, void);
    DECL_THISCALL_SIMPLE(ProcessFOVLerp, _ZN7CCamera14ProcessFOVLerpEv, void);
    DECL_THISCALL_SIMPLE(GetRoughDistanceToGround, _ZN7CCamera24GetRoughDistanceToGroundEv, float);
    DECL_THISCALL_SIMPLE(ShouldPedControlsBeRelative, _ZN7CCamera27ShouldPedControlsBeRelativeEv, u8);
    DECL_THISCALL_SIMPLE(DeleteCutSceneCamDataMemory, _ZN7CCamera27DeleteCutSceneCamDataMemoryEv, void);
    DECL_THISCALL_SIMPLE(Init, _ZN7CCamera4InitEv, void);
    // ---- added: unique thiscalls via DECL_THISCALL ----
    DECL_THISCALL(AddShake, _ZN7CCamera8AddShakeEfffff, void, float, float, float, float, float);
    DECL_THISCALL(AddShakeSimple, _ZN7CCamera14AddShakeSimpleEfif, void, float, i32, float);
    DECL_THISCALL(AllowShootingWith2PlayersInCar, _ZN7CCamera30AllowShootingWith2PlayersInCarEb, void, bool);
    DECL_THISCALL(ApplyVehicleCameraTweaks, _ZN7CCamera24ApplyVehicleCameraTweaksEP8CVehicle, void, CVehicle*);
    DECL_THISCALL(AvoidTheGeometry, _ZN7CCamera16AvoidTheGeometryERK7CVectorS2_RS0_f, void, const CVector*, const CVector*, CVector*, float);
    DECL_THISCALL(CalculateDerivedValues, _ZN7CCamera22CalculateDerivedValuesEbb, void, bool, bool);
    DECL_THISCALL(CalculateFrustumPlanes, _ZN7CCamera22CalculateFrustumPlanesEb, void, bool);
    DECL_THISCALL(CalculateGroundHeight, _ZN7CCamera21CalculateGroundHeightEj, float, u32);
    DECL_THISCALL(CalculateMirroredMatrix, _ZN7CCamera23CalculateMirroredMatrixE7CVectorfP7CMatrixS2_, void, CVector, float, CMatrix*, CMatrix*);
    DECL_THISCALL(CamShake, _ZN7CCamera8CamShakeEffff, void, float, float, float, float);
    DECL_THISCALL(CameraColDetAndReact, _ZN7CCamera20CameraColDetAndReactEP7CVectorS1_, bool, CVector*, CVector*);
    DECL_THISCALL(CameraGenericModeSpecialCases, _ZN7CCamera29CameraGenericModeSpecialCasesEP4CPed, void, CPed*);
    DECL_THISCALL(CameraPedAimModeSpecialCases, _ZN7CCamera28CameraPedAimModeSpecialCasesEP4CPed, void, CPed*);
    DECL_THISCALL(CameraPedModeSpecialCases, _ZN7CCamera25CameraPedModeSpecialCasesEP4CPed, void, CPed*);
    DECL_THISCALL(CameraVehicleModeSpecialCases, _ZN7CCamera29CameraVehicleModeSpecialCasesEP8CVehicle, void, CVehicle*);
    DECL_THISCALL(ConeCastCollisionResolve, _ZN7CCamera24ConeCastCollisionResolveEP7CVectorS1_S1_ffPf, bool, CVector*, CVector*, CVector*, float, float, float*);
    DECL_THISCALL(ConsiderPedAsDucking, _ZN7CCamera20ConsiderPedAsDuckingEP4CPed, bool, CPed*);
    DECL_THISCALL(CopyCameraMatrixToRWCam, _ZN7CCamera23CopyCameraMatrixToRWCamEb, void, bool);
    DECL_THISCALL(DealWithMirrorBeforeConstructRenderList, _ZN7CCamera39DealWithMirrorBeforeConstructRenderListEb7CVectorfP7CMatrix, void, bool, CVector, float, CMatrix*);
    DECL_THISCALL(Fade, _ZN7CCamera4FadeEfs, void, float, i16);
    DECL_THISCALL(Find3rdPersonCamTargetVector, _ZN7CCamera28Find3rdPersonCamTargetVectorEf7CVectorRS0_S1_, bool, float, CVector, CVector*, CVector*);
    DECL_THISCALL(GetArrPosForVehicleType, _ZN7CCamera23GetArrPosForVehicleTypeEiRi, bool, int, int*);
    DECL_THISCALL(GetScreenRect, _ZN7CCamera13GetScreenRectER5CRect, void, CRect*);
    DECL_THISCALL(HandleCameraMotionForDucking, _ZN7CCamera28HandleCameraMotionForDuckingEP4CPedP7CVectorS3_b, void, CPed*, CVector*, CVector*, bool);
    DECL_THISCALL(HandleCameraMotionForDuckingDuringAim, _ZN7CCamera37HandleCameraMotionForDuckingDuringAimEP4CPedP7CVectorS3_b, void, CPed*, CVector*, CVector*, bool);
    DECL_THISCALL(ImproveNearClip, _ZN7CCamera15ImproveNearClipEP8CVehicleP4CPedP7CVectorS5_, void, CVehicle*, CPed*, CVector*, CVector*);
    DECL_THISCALL(InitialiseScriptableComponents, _ZN7CCamera30InitialiseScriptableComponentsEv, void);
    DECL_THISCALL(IsExtraEntityToIgnore, _ZN7CCamera21IsExtraEntityToIgnoreEP7CEntity, bool, CEntity*);
    DECL_THISCALL(IsItTimeForNewcam, _ZN7CCamera17IsItTimeForNewcamEii, bool, i32, i32);
    DECL_THISCALL(IsSphereVisible, _ZN7CCamera15IsSphereVisibleERK7CVectorf, bool, const CVector*, float);
    DECL_THISCALL(LerpFOV, _ZN7CCamera7LerpFOVEfffb, void, float, float, float, bool);
    DECL_THISCALL(LoadPathSplines, _ZN7CCamera15LoadPathSplinesEy, void, u64);
    DECL_THISCALL(ResetDuckingSystem, _ZN7CCamera18ResetDuckingSystemEP4CPed, void, CPed*);
    DECL_THISCALL(SetCamCutSceneOffSet, _ZN7CCamera20SetCamCutSceneOffSetERK7CVector, void, const CVector*);
    DECL_THISCALL(SetCamPositionForFixedMode, _ZN7CCamera26SetCamPositionForFixedModeERK7CVectorS2_, void, const CVector*, const CVector*);
    DECL_THISCALL(SetCameraDirectlyBehindForFollowPed_ForAPed_CamOnAString, _ZN7CCamera56SetCameraDirectlyBehindForFollowPed_ForAPed_CamOnAStringEP4CPed, void, CPed*);
    DECL_THISCALL(SetCameraDirectlyInFrontForFollowPed_ForAPed_CamOnAString, _ZN7CCamera57SetCameraDirectlyInFrontForFollowPed_ForAPed_CamOnAStringEP4CPed, void, CPed*);
    DECL_THISCALL(SetFadeColour, _ZN7CCamera13SetFadeColourEhhh, void, u8, u8, u8);
    DECL_THISCALL(SetMotionBlur, _ZN7CCamera13SetMotionBlurEiiiii, void, int, int, int, int, int);
    DECL_THISCALL(SetMotionBlurAlpha, _ZN7CCamera18SetMotionBlurAlphaEi, void, int);
    DECL_THISCALL(SetNearClipBasedOnPedCollision, _ZN7CCamera30SetNearClipBasedOnPedCollisionEf, void, float);
    DECL_THISCALL(SetNearClipScript, _ZN7CCamera17SetNearClipScriptEf, void, float);
    DECL_THISCALL(SetNewPlayerWeaponMode, _ZN7CCamera22SetNewPlayerWeaponModeEsss, void, i16, i16, i16);
    DECL_THISCALL(SetParametersForScriptInterpolation, _ZN7CCamera35SetParametersForScriptInterpolationEffj, void, float, float, u32);
    DECL_THISCALL(SetPercentAlongCutScene, _ZN7CCamera23SetPercentAlongCutSceneEf, void, float);
    DECL_THISCALL(SetRwCamera, _ZN7CCamera11SetRwCameraEP8RwCamera, void, RwCamera*);
    DECL_THISCALL(SetToSphereMap, _ZN7CCamera14SetToSphereMapEf, void, float);
    DECL_THISCALL(SetZoomValueCamStringScript, _ZN7CCamera27SetZoomValueCamStringScriptEs, void, i16);
    DECL_THISCALL(SetZoomValueFollowPedScript, _ZN7CCamera27SetZoomValueFollowPedScriptEs, void, i16);
    DECL_THISCALL(StartTransition, _ZN7CCamera15StartTransitionEs, void, i16);
    DECL_THISCALL(StartTransitionWhenNotFinishedInter, _ZN7CCamera35StartTransitionWhenNotFinishedInterEs, void, i16);
    DECL_THISCALL(StoreValuesDuringInterPol, _ZN7CCamera25StoreValuesDuringInterPolER7CVectorS1_S1_Rf, void, CVector*, CVector*, CVector*, float*);
    DECL_THISCALL(TakeControl, _ZN7CCamera11TakeControlEP7CEntityssi, void, CEntity*, i16, i16, int);
    DECL_THISCALL(TakeControlAttachToEntity, _ZN7CCamera25TakeControlAttachToEntityEP7CEntityS1_R7CVectorS3_fsi, void, CEntity*, CEntity*, CVector*, CVector*, float, i16, int);
    DECL_THISCALL(TakeControlNoEntity, _ZN7CCamera19TakeControlNoEntityERK7CVectorsi, void, const CVector*, i16, int);
    DECL_THISCALL(TakeControlWithSpline, _ZN7CCamera21TakeControlWithSplineEs, void, i16);
    DECL_THISCALL(TryToStartNewCamMode, _ZN7CCamera20TryToStartNewCamModeEi, bool, i32);
    DECL_THISCALL(UpdateAimingCoors, _ZN7CCamera17UpdateAimingCoorsERK7CVector, void, const CVector*);
    DECL_THISCALL(VectorMoveLinear, _ZN7CCamera16VectorMoveLinearEP7CVectorS1_fb, void, CVector*, CVector*, float, bool);
    DECL_THISCALL(VectorTrackLinear, _ZN7CCamera17VectorTrackLinearEP7CVectorS1_fb, void, CVector*, CVector*, float, bool);

    // ---- added: static members ----
    DECL_FASTCALL_SIMPLE(SetCamCollisionVarDataSet, _ZN7CCamera25SetCamCollisionVarDataSetEi, void, i32);
    DECL_FASTCALL_SIMPLE(SetColVarsAimWeapon, _ZN7CCamera19SetColVarsAimWeaponEi, void, i32);
    DECL_FASTCALL_SIMPLE(SetColVarsPed, _ZN7CCamera13SetColVarsPedEii, void, i32, i32);
    DECL_FASTCALL_SIMPLE(SetColVarsVehicle, _ZN7CCamera17SetColVarsVehicleEii, void, i32, i32);

    // ---- added: overloads (share a name -> HEAD/TAIL) ----
    DECL_THISCALL_NAMED_HEAD(IsTargetingActive1, IsTargetingActive, _ZN7CCamera17IsTargetingActiveEP10CPlayerPed, bool, CPlayerPed* pPlayerPed)
    DECL_THISCALL_TAIL(IsTargetingActive1, pPlayerPed)
    DECL_THISCALL_NAMED_HEAD(ProcessFOVLerp1, ProcessFOVLerp, _ZN7CCamera14ProcessFOVLerpEf, void, float t)
    DECL_THISCALL_TAIL(ProcessFOVLerp1, t)
    DECL_THISCALL_NAMED_HEAD(ProcessShake1, ProcessShake, _ZN7CCamera12ProcessShakeEf, void, float time)
    DECL_THISCALL_TAIL(ProcessShake1, time)
    DECL_THISCALL_NAMED_HEAD(ProcessVectorMoveLinear1, ProcessVectorMoveLinear, _ZN7CCamera23ProcessVectorMoveLinearEf, void, float t)
    DECL_THISCALL_TAIL(ProcessVectorMoveLinear1, t)
    DECL_THISCALL_NAMED_HEAD(ProcessVectorTrackLinear1, ProcessVectorTrackLinear, _ZN7CCamera24ProcessVectorTrackLinearEf, void, float t)
    DECL_THISCALL_TAIL(ProcessVectorTrackLinear1, t)

    // Helper functions
    inline unsigned char GetActiveCamNum()
    {
        return m_nActiveCam;
    }
    inline CCam& GetActiveCam()
    {
        return m_aCams[m_nActiveCam];
    }
    inline eCamMode GetActiveMode()
    {
        return GetActiveCam().m_nMode;
    }
    inline void SetActiveMode(eCamMode mode)
    {
        GetActiveCam().m_nMode = mode;
    }

    // Member values
    bool m_bAboveGroundTrainNodesLoaded;
    bool m_bBelowGroundTrainNodesLoaded;
    bool m_bCamDirectlyBehind;
    bool m_bCamDirectlyInFront;
    bool m_bCameraJustRestored;
    bool m_bcutsceneFinished;
    bool m_bCullZoneChecksOn;
    bool m_bIdleOn;
    bool m_bInATunnelAndABigVehicle;
    bool m_bInitialNodeFound;
    bool m_bInitialNoNodeStaticsSet;
    bool m_bIgnoreFadingStuffForMusic;
    bool m_bPlayerIsInGarage;
    bool m_bPlayerWasOnBike;
    bool m_bJustCameOutOfGarage;
    bool m_bJustInitalised;
    bool m_bJust_Switched;
    bool m_bLookingAtPlayer;
    bool m_bLookingAtVector;
    bool m_bMoveCamToAvoidGeom;
    bool m_bObbeCinematicPedCamOn;
    bool m_bObbeCinematicCarCamOn;
    bool m_bRestoreByJumpCut;
    bool m_bUseNearClipScript;
    bool m_bStartInterScript;
    bool m_bStartingSpline;
    bool m_bTargetJustBeenOnTrain;
    bool m_bTargetJustCameOffTrain;
    bool m_bUseSpecialFovTrain;
    bool m_bUseTransitionBeta;
    bool m_bUseScriptZoomValuePed;
    bool m_bUseScriptZoomValueCar;
    bool m_bWaitForInterpolToFinish;
    bool m_bItsOkToLookJustAtThePlayer;
    bool m_bWantsToSwitchWidescreenOff;
    bool m_bWideScreenOn;
    bool m_b1rstPersonRunCloseToAWall;
    bool m_bHeadBob;
    bool m_bVehicleSuspenHigh;
    bool m_bEnable1rstPersonCamCntrlsScript;
    bool m_bAllow1rstPersonWeaponsCamera;
    bool m_bCooperativeCamMode;
    bool m_bAllowShootingWith2PlayersInCar;
    bool m_bDisableFirstPersonInCar;
    unsigned short m_nModeForTwoPlayersSeparateCars;
    unsigned short m_nModeForTwoPlayersSameCarShootingAllowed;
    unsigned short m_nModeForTwoPlayersSameCarShootingNotAllowed;
    unsigned short m_nModeForTwoPlayersNotBothInCar;
    bool m_bGarageFixedCamPositionSet;
    bool m_bDoingSpecialInterPolation;
    bool m_bScriptParametersSetForInterPol;
    bool m_bFading;
    bool m_bMusicFading;
    bool m_bMusicFadedOut;
    bool m_bFailedCullZoneTestPreviously;
    bool m_bFadeTargetIsSplashScreen;
    bool m_bWorldViewerBeingUsed;
    bool m_bTransitionJUSTStarted;
    bool m_bTransitionState;
    unsigned char m_nActiveCam;
    unsigned int m_nCamShakeStart;
    unsigned int m_nFirstPersonCamLastInputTime;
    unsigned int m_nLongestTimeInMill;
    unsigned int m_nNumberOfTrainCamNodes;
    unsigned int m_nTimeLastChange;
    unsigned int m_nTimeWeLeftIdle_StillNoInput;
    unsigned int m_nTimeWeEnteredIdle;
    unsigned int m_nTimeTransitionStart;
    unsigned int m_nTransitionDuration;
    unsigned int m_nTransitionDurationTargetCoors;
    unsigned int m_nBlurBlue;
    unsigned int m_nBlurGreen;
    unsigned int m_nBlurRed;
    unsigned int m_nBlurType;
    unsigned int m_nWorkOutSpeedThisNumFrames;
    unsigned int m_nNumFramesSoFar;
    unsigned int m_nCurrentTrainCamNode;
    unsigned int m_nMotionBlur;
    unsigned int m_nMotionBlurAddAlpha;
    unsigned int m_nCheckCullZoneThisNumFrames;
    unsigned int m_nZoneCullFrameNumWereAt;
    unsigned int m_nWhoIsInControlOfTheCamera;
    unsigned int m_nCarZoom;
    float m_fCarZoomBase;
    float m_fCarZoomTotal;
    float m_fCarZoomSmoothed;
    float m_fCarZoomValueScript;
    unsigned int m_nPedZoom;
    float m_fPedZoomBase;
    float m_fPedZoomTotal;
    float m_fPedZoomSmoothed;
    float m_fPedZoomValueScript;
    float m_fCamFrontXNorm;
    float m_fCamFrontYNorm;
    float m_fDistanceToWater;
    float m_fHeightOfNearestWater;
    float m_fFOVDuringInter;
    float m_fLODDistMultiplier;
    float m_fGenerationDistMultiplier;
    float m_fAlphaSpeedAtStartInter;
    float m_fAlphaWhenInterPol;
    float m_fAlphaDuringInterPol;
    float m_fBetaDuringInterPol;
    float m_fBetaSpeedAtStartInter;
    float m_fBetaWhenInterPol;
    float m_fFOVWhenInterPol;
    float m_fFOVSpeedAtStartInter;
    float m_fStartingBetaForInterPol;
    float m_fStartingAlphaForInterPol;
    float m_fPedOrientForBehindOrInFront;
    float m_fCameraAverageSpeed;
    float m_fCameraSpeedSoFar;
    float m_fCamShakeForce;
    float m_fFovForTrain;
    float m_fFOV_Wide_Screen;
    float m_fNearClipScript;
    float m_fOldBetaDiff;
    float m_fPositionAlongSpline;
    float m_fScreenReductionPercentage;
    float m_fScreenReductionSpeed;
    float m_fAlphaForPlayerAnim1rstPerson;
    float m_fOrientation;
    float m_fPlayerExhaustion;
    float m_fSoundDistUp;
    float m_fSoundDistUpAsRead;
    float m_fSoundDistUpAsReadOld;
    float m_fAvoidTheGeometryProbsTimer;
    unsigned short m_nAvoidTheGeometryProbsDirn;
    float m_fWideScreenReductionAmount;
    float m_fStartingFOVForInterPol;
    CCam m_aCams[3];
    CGarage *m_pToGarageWeAreIn;
    CGarage *m_pToGarageWeAreInForHackAvoidFirstPerson;
    CQueuedMode m_PlayerMode;
    CQueuedMode m_PlayerWeaponMode;
    CVector m_vecPreviousCameraPosition;
    CVector m_vecRealPreviousCameraPosition;
    CVector m_vecAimingTargetCoors;
    CVector m_vecFixedModeVector;
    CVector m_vecFixedModeSource;
    CVector m_vecFixedModeUpOffSet;
    CVector m_vecCutSceneOffset;
    CVector m_vecStartingSourceForInterPol;
    CVector m_vecStartingTargetForInterPol;
    CVector m_vecStartingUpForInterPol;
    CVector m_vecSourceSpeedAtStartInter;
    CVector m_vecTargetSpeedAtStartInter;
    CVector m_vecUpSpeedAtStartInter;
    CVector m_vecSourceWhenInterPol;
    CVector m_vecTargetWhenInterPol;
    CVector m_vecUpWhenInterPol;
    CVector m_vecClearGeometryVec;
    CVector m_vecGameCamPos;
    CVector m_vecSourceDuringInter;
    CVector m_vecTargetDuringInter;
    CVector m_vecUpDuringInter;
    CVector m_vecAttachedCamOffset;
    CVector m_vecAttachedCamLookAt;
    float m_fAttachedCamAngle;
    RwCamera *m_pRwCamera;
    CEntity *m_pTargetEntity;
    CEntity *m_pAttachedEntity;
    CCamPathSplines m_aPathArray[4];
    bool m_bMirrorActive;
    bool m_bResetOldMatrix;
    float m_fSphereMapRadius; // MOBILE STUFF
    CMatrix m_mCameraMatrix;
    CMatrix m_mCameraMatrixOld;
    CMatrix m_mViewMatrix;
    CMatrix m_mMatInverse;
    CMatrix m_mMatMirrorInverse;
    CMatrix m_mMatMirror;
    CVector m_avecFrustumNormals[4];
    CVector m_avecFrustumWorldNormals[4];
    CVector m_avecFrustumWorldNormals_Mirror[4];
    float m_fFrustumPlaneOffsets[4];
    float m_fFrustumPlaneOffsets_Mirror[4];
    CVector m_vecRightFrustumNormal; //!< unused?
    CVector m_vecBottomFrustumNormal; //!< unused?
    CVector m_vecTopFrustumNormal; //!< unused?
    float m_fOldFOVForInter; //!< unused?
    float m_fFadeAlpha;
    float m_fEffectsFaderScalingFactor;
    float m_fFadeDuration;
    float m_fTimeToFadeMusic;
    float m_fTimeToWaitToFadeMusic;
    float m_fFractionInterToStopMoving;
    float m_fFractionInterToStopCatchUp;
    float m_fFractionInterToStopMovingTarget;
    float m_fFractionInterToStopCatchUpTarget;
    float m_fGaitSwayBuffer;
    float m_fScriptPercentageInterToStopMoving;
    float m_fScriptPercentageInterToCatchUp;
    unsigned int m_nScriptTimeForInterPolation;
    unsigned short m_nFadeInOutFlag;
    int m_nModeObbeCamIsInForCar;
    short m_nModeToGoTo;    // see eCamMode
    short m_nMusicFadingDirection;
    short m_nTypeOfSwitch; // see eSwitchType
    unsigned int m_nFadeStartTime;
    unsigned int m_nFadeTimeStartedMusic;
    int m_nExtraEntitiesCount;
    CEntity *m_pExtraEntity[2];
    float m_fDuckCamMotionFactor;
    float m_fDuckAimCamMotionFactor;
    float m_fTrackLinearStartTime;
    float m_fTrackLinearEndTime;
    CVector m_vecTrackLinearEndPoint;
    CVector m_vecTrackLinearStartPoint;
    bool m_bTrackLinearWithEase;
    CVector m_vecTrackLinear;
    bool m_bVecTrackLinearProcessed;
    float m_fShakeIntensity;
    float m_fStartShakeTime;
    float m_fEndShakeTime;
    bool m_bShakeScript;
    int m_nShakeType;
    float m_fStartZoomTime;
    float m_fEndZoomTime;
    float m_fZoomInFactor;
    float m_fZoomOutFactor;
    unsigned char m_nZoomMode;
    bool m_bFOVLerpProcessed;
    float m_fFOVNew;
    float m_vectorMoveStartTime;
    float m_vectorMoveEndTime;
    CVector m_vecMoveLinearPosnStart;
    CVector m_vecMoveLinearPosnEnd;
    bool m_bMoveLinearWithEase;
    CVector m_vecMoveLinear;
    bool m_bVecMoveLinearProcessed;
    bool m_bBlockZoom;
    bool m_bCameraPersistPosition;
    bool m_bCameraPersistTrack;
    bool m_bCinemaCamera;
    struct
    {
        int m_nModelIndex;
        float m_fDistance;
        float m_fAltitude;
        float m_fAngle;
    } m_aCamTweak[5];
    bool m_bCameraVehicleTweaksInitialized;
    float m_fCurrentTweakDistance;
    float m_fCurrentTweakAltitude;
    float m_fCurrentTweakAngle;
    int m_nCurrentTweakModelIndex;
    float m_fTimeStartFOVLO;
    float m_fTimeEndFOVLO;
    float m_fFOVStartFOVLO;
    CVector m_vecStartPositionFOVLO;
    float m_fFOVTargetFOVLO;
    bool m_bSmoothLerpFOVLO;
    bool m_bInitLockOnCam;
DECL_CLASS_END()
CHECKSIZE(CCamera, 0xD00, 0xDB0);

DECL_OBJECT_PLT_GLOBAL(CCamera, TheCamera, BYBIT(0x679B8C, 0x851738) );
#define TheCamera TheCamera()

#endif // __AML_PSDK_SACAMERA_H