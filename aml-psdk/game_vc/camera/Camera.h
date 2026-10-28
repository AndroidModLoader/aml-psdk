#ifndef __AML_PSDK_VCCAMERA_H
#define __AML_PSDK_VCCAMERA_H

#include "Cam.h"
#include "../entity/Placeable.h"
#include <aml-psdk/gta_base/Rect.h>

struct RwCamera;
struct CGarage;

struct tQueuedMode
{
    i16 Mode;
    float Duration;
    i16 MinZoom;
    i16 MaxZoom;
};
CHECKSIZE(tQueuedMode, 0xC, 0xC);

struct tCamPathSplines
{
    float* m_arr_PathData;
};
CHECKSIZE(tCamPathSplines, 0x4, 0x8);

DECL_CLASS_BASED(CCamera, CPlaceable)
    // Construct/Deconstruct functions
    CCamera() = delete;
    CCamera(CCamera const&) = delete;
    CCamera& operator=(CCamera const&) = delete;
    DECL_DTORCALL(CCamera, _ZN7CCameraD2Ev);

    // Member functions
    DECL_THISCALL_SIMPLE(Init, _ZN7CCamera4InitEv, void);
    DECL_THISCALL_SIMPLE(Process, _ZN7CCamera7ProcessEv, void);
    DECL_THISCALL_SIMPLE(ProcessFade, _ZN7CCamera11ProcessFadeEv, void);
    DECL_THISCALL_SIMPLE(ProcessMusicFade, _ZN7CCamera16ProcessMusicFadeEv, void);
    DECL_THISCALL_SIMPLE(ProcessWideScreenOn, _ZN7CCamera19ProcessWideScreenOnEv, void);
    DECL_THISCALL_SIMPLE(CalculateDerivedValues, _ZN7CCamera22CalculateDerivedValuesEv, void);
    DECL_THISCALL_SIMPLE(CamControl, _ZN7CCamera10CamControlEv, void);
    DECL_THISCALL_SIMPLE(ClearPlayerWeaponMode, _ZN7CCamera21ClearPlayerWeaponModeEv, void);
    DECL_THISCALL_SIMPLE(DeleteCutSceneCamDataMemory, _ZN7CCamera27DeleteCutSceneCamDataMemoryEv, void);
    DECL_THISCALL_SIMPLE(DrawBordersForWideScreen, _ZN7CCamera24DrawBordersForWideScreenEv, void);
    DECL_THISCALL_SIMPLE(Restore, _ZN7CCamera7RestoreEv, void);
    DECL_THISCALL_SIMPLE(RestoreWithJumpCut, _ZN7CCamera18RestoreWithJumpCutEv, void);
    DECL_THISCALL_SIMPLE(ProcessObbeCinemaCameraCar, _ZN7CCamera26ProcessObbeCinemaCameraCarEv, void);
    DECL_THISCALL_SIMPLE(ProcessObbeCinemaCameraHeli, _ZN7CCamera27ProcessObbeCinemaCameraHeliEv, void);
    DECL_THISCALL_SIMPLE(ProcessObbeCinemaCameraPed, _ZN7CCamera26ProcessObbeCinemaCameraPedEv, void);
    DECL_THISCALL_SIMPLE(UpdateSoundDistances, _ZN7CCamera20UpdateSoundDistancesEv, void);
    DECL_THISCALL_SIMPLE(UpdateTargetEntity, _ZN7CCamera18UpdateTargetEntityEv, void);
    DECL_THISCALL_SIMPLE(SetWideScreenOn, _ZN7CCamera15SetWideScreenOnEv, void);
    DECL_THISCALL_SIMPLE(SetWideScreenOff, _ZN7CCamera16SetWideScreenOffEv, void);
    DECL_THISCALL_SIMPLE(Enable1rstPersonCamCntrlsScript, _ZN7CCamera31Enable1rstPersonCamCntrlsScriptEv, void);
    DECL_THISCALL_SIMPLE(Enable1rstPersonWeaponsCamera, _ZN7CCamera29Enable1rstPersonWeaponsCameraEv, void);
    DECL_THISCALL_SIMPLE(InitialiseCameraForDebugMode, _ZN7CCamera28InitialiseCameraForDebugModeEv, void);
    DECL_THISCALL_SIMPLE(FindCamFOV, _ZN7CCamera10FindCamFOVEv, float);
    DECL_THISCALL_SIMPLE(FindCamFrontVector, _ZN7CCamera18FindCamFrontVectorEv, CVector);
    DECL_THISCALL_SIMPLE(GetGameCamPosition, _ZN7CCamera18GetGameCamPositionEv, CVector*);
    DECL_THISCALL_SIMPLE(GetPositionAlongSpline, _ZN7CCamera22GetPositionAlongSplineEv, float);
    DECL_THISCALL_SIMPLE(GetCutSceneFinishTime, _ZN7CCamera21GetCutSceneFinishTimeEv, i32);
    DECL_THISCALL_SIMPLE(GetLookDirection, _ZN7CCamera16GetLookDirectionEv, i32);
    DECL_THISCALL_SIMPLE(GetScreenFadeStatus, _ZN7CCamera19GetScreenFadeStatusEv, i32);
    DECL_THISCALL_SIMPLE(GetFadingDirection, _ZN7CCamera18GetFadingDirectionEv, i32);
    DECL_THISCALL_SIMPLE(GetFading, _ZN7CCamera9GetFadingEv, bool);
    DECL_THISCALL_SIMPLE(Get_Just_Switched_Status, _ZN7CCamera24Get_Just_Switched_StatusEv, bool);
    DECL_THISCALL_SIMPLE(GetLookingForwardFirstPerson, _ZN7CCamera28GetLookingForwardFirstPersonEv, bool);
    DECL_THISCALL_SIMPLE(GetLookingLRBFirstPerson, _ZN7CCamera24GetLookingLRBFirstPersonEv, bool);
    DECL_THISCALL_SIMPLE(Using1stPersonWeaponMode, _ZN7CCamera24Using1stPersonWeaponModeEv, bool);
    DECL_THISCALL_SIMPLE(ShouldPedControlsBeRelative, _ZN7CCamera27ShouldPedControlsBeRelativeEv, bool);
    DECL_THISCALL_SIMPLE(Find3rdPersonQuickAimPitch, _ZN7CCamera26Find3rdPersonQuickAimPitchEv, float);
    DECL_THISCALL_HEAD(AvoidTheGeometry, _ZN7CCamera16AvoidTheGeometryERK7CVectorS2_RS0_f, void, CVector const& source, CVector const& target, CVector& result, float limit)
    DECL_THISCALL_TAIL(AvoidTheGeometry, source, target, result, limit)
    DECL_THISCALL_HEAD(CamShake, _ZN7CCamera8CamShakeEffff, void, float strength, float x, float y, float z)
    DECL_THISCALL_TAIL(CamShake, strength, x, y, z)
    DECL_THISCALL_HEAD(Fade, _ZN7CCamera4FadeEfs, void, float time, i16 direction)
    DECL_THISCALL_TAIL(Fade, time, direction)
    DECL_THISCALL_HEAD(Find3rdPersonCamTargetVector, _ZN7CCamera28Find3rdPersonCamTargetVectorEf7CVectorRS0_S1_, void, float distance, CVector source, CVector& start, CVector& end)
    DECL_THISCALL_TAIL(Find3rdPersonCamTargetVector, distance, source, start, end)
    DECL_THISCALL_HEAD(GetScreenRect, _ZN7CCamera13GetScreenRectER5CRectb, void, CRect& rect, bool reduceForWideScreen)
    DECL_THISCALL_TAIL(GetScreenRect, rect, reduceForWideScreen)
    DECL_THISCALL_HEAD(IsItTimeForNewcam, _ZN7CCamera17IsItTimeForNewcamEii, bool, i32 sequence, i32 time)
    DECL_THISCALL_TAIL(IsItTimeForNewcam, sequence, time)
    DECL_THISCALL_HEAD(SetCamCutSceneOffSet, _ZN7CCamera20SetCamCutSceneOffSetERK7CVector, void, CVector const& offset)
    DECL_THISCALL_TAIL(SetCamCutSceneOffSet, offset)
    DECL_THISCALL_HEAD(SetCamPositionForFixedMode, _ZN7CCamera26SetCamPositionForFixedModeERK7CVectorS2_, void, CVector const& source, CVector const& upOffset)
    DECL_THISCALL_TAIL(SetCamPositionForFixedMode, source, upOffset)
    DECL_THISCALL_HEAD(SetFadeColour, _ZN7CCamera13SetFadeColourEhhh, void, u8 red, u8 green, u8 blue)
    DECL_THISCALL_TAIL(SetFadeColour, red, green, blue)
    DECL_THISCALL_HEAD(SetNearClipScript, _ZN7CCamera17SetNearClipScriptEf, void, float nearClip)
    DECL_THISCALL_TAIL(SetNearClipScript, nearClip)
    DECL_THISCALL_HEAD(SetNewPlayerWeaponMode, _ZN7CCamera22SetNewPlayerWeaponModeEsss, void, i16 mode, i16 minZoom, i16 maxZoom)
    DECL_THISCALL_TAIL(SetNewPlayerWeaponMode, mode, minZoom, maxZoom)
    DECL_THISCALL_HEAD(SetParametersForScriptInterpolation, _ZN7CCamera35SetParametersForScriptInterpolationEffj, void, float stopMoving, float catchUp, u32 time)
    DECL_THISCALL_TAIL(SetParametersForScriptInterpolation, stopMoving, catchUp, time)
    DECL_THISCALL_HEAD(SetRwCamera, _ZN7CCamera11SetRwCameraEP8RwCamera, void, RwCamera* camera)
    DECL_THISCALL_TAIL(SetRwCamera, camera)
    DECL_THISCALL_HEAD(SetZoomValueCamStringScript, _ZN7CCamera27SetZoomValueCamStringScriptEs, void, i16 zoom)
    DECL_THISCALL_TAIL(SetZoomValueCamStringScript, zoom)
    DECL_THISCALL_HEAD(SetZoomValueFollowPedScript, _ZN7CCamera27SetZoomValueFollowPedScriptEs, void, i16 zoom)
    DECL_THISCALL_TAIL(SetZoomValueFollowPedScript, zoom)
    DECL_THISCALL_HEAD(StartTransition, _ZN7CCamera15StartTransitionEs, void, i16 mode)
    DECL_THISCALL_TAIL(StartTransition, mode)
    DECL_THISCALL_HEAD(StartTransitionWhenNotFinishedInter, _ZN7CCamera35StartTransitionWhenNotFinishedInterEs, void, i16 mode)
    DECL_THISCALL_TAIL(StartTransitionWhenNotFinishedInter, mode)
    DECL_THISCALL_HEAD(StoreValuesDuringInterPol, _ZN7CCamera25StoreValuesDuringInterPolER7CVectorS1_S1_Rf, void, CVector& source, CVector& target, CVector& up, float& fov)
    DECL_THISCALL_TAIL(StoreValuesDuringInterPol, source, target, up, fov)
    DECL_THISCALL_HEAD(TakeControl, _ZN7CCamera11TakeControlEP7CEntityssi, void, CEntity* entity, i16 mode, i16 switchType, i32 controller)
    DECL_THISCALL_TAIL(TakeControl, entity, mode, switchType, controller)
    DECL_THISCALL_HEAD(TakeControlNoEntity, _ZN7CCamera19TakeControlNoEntityERK7CVectorsi, void, CVector const& target, i16 switchType, i32 controller)
    DECL_THISCALL_TAIL(TakeControlNoEntity, target, switchType, controller)
    DECL_THISCALL_HEAD(TakeControlWithSpline, _ZN7CCamera21TakeControlWithSplineEs, void, i16 switchType)
    DECL_THISCALL_TAIL(TakeControlWithSpline, switchType)
    DECL_THISCALL_HEAD(TryToStartNewCamMode, _ZN7CCamera20TryToStartNewCamModeEi, bool, i32 mode)
    DECL_THISCALL_TAIL(TryToStartNewCamMode, mode)
    DECL_THISCALL_HEAD(UpdateAimingCoors, _ZN7CCamera17UpdateAimingCoorsERK7CVector, void, CVector const& target)
    DECL_THISCALL_TAIL(UpdateAimingCoors, target)
    DECL_THISCALL_HEAD(SetPercentAlongCutScene, _ZN7CCamera23SetPercentAlongCutSceneEf, void, float percent)
    DECL_THISCALL_TAIL(SetPercentAlongCutScene, percent)
    DECL_THISCALL_SIMPLE(FinishCutscene, _ZN7CCamera14FinishCutsceneEv, void);
    DECL_THISCALL_SIMPLE(SetCameraDirectlyBehindForFollowPed_CamOnAString, _ZN7CCamera48SetCameraDirectlyBehindForFollowPed_CamOnAStringEv, void);
    DECL_THISCALL_SIMPLE(SetCameraDirectlyInFrontForFollowPed_CamOnAString, _ZN7CCamera49SetCameraDirectlyInFrontForFollowPed_CamOnAStringEv, void);
    DECL_THISCALL_HEAD(GetArrPosForVehicleType, _ZN7CCamera23GetArrPosForVehicleTypeEiRi, bool, i32 vehicleType, i32& arrayPosition)
    DECL_THISCALL_TAIL(GetArrPosForVehicleType, vehicleType, arrayPosition)
    #ifdef AML64
        DECL_THISCALL_HEAD(LoadPathSplines, _ZN7CCamera15LoadPathSplinesEy, void, FILESTREAM file)
        DECL_THISCALL_TAIL(LoadPathSplines, file)
    #else
        DECL_THISCALL_HEAD(LoadPathSplines, _ZN7CCamera15LoadPathSplinesEj, void, FILESTREAM file)
        DECL_THISCALL_TAIL(LoadPathSplines, file)
    #endif

    // STATIC functions
    DECL_FASTCALL_SIMPLE(DontProcessObbeCinemaCamera, _ZN7CCamera27DontProcessObbeCinemaCameraEv, void);

    // STATIC values
    DECL_VALUE_PLT_BOOL(m_bUseMouse3rdPerson, BYBIT(0x394678, 0x576e50));
    DECL_VALUE_PLT_FLT(m_fMouseAccelVertical, BYBIT(0x39496c, 0x5773c0));
    DECL_VALUE_PLT_FLT(m_fMouseAccelHorzntl, BYBIT(0x395e78, 0x579d28));
    DECL_VALUE_PLT_FLT(m_f3rdPersonCHairMultX, BYBIT(0x3947cc, 0x5770d0));
    DECL_VALUE_PLT_FLT(m_f3rdPersonCHairMultY, BYBIT(0x395bf4, 0x579800));

    // Member values
    uptr : 0;
    bool m_bAboveGroundTrainNodesLoaded;
    bool m_bBelowGroundTrainNodesLoaded;
    bool m_bCamDirectlyBehind;
    bool m_bCamDirectlyInFront;
    bool m_bCameraJustRestored;
    bool m_bCutsceneFinished;
    bool m_bCullZoneChecksOn;
    bool m_bFirstPersonBeingUsed;
    bool m_bJustJumpedOutOf1stPersonBecauseOfTarget;
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
    bool m_b1stPersonRunCloseToAWall;
    bool m_bHeadBob;
    bool m_bVehicleSuspenHigh;
    bool m_bEnable1rstPersonCamCntrlsScript;
    bool m_bAllow1rstPersonWeaponsCamera;
    bool m_bFailedCullZoneTestPreviously;
    bool m_bFadeTargetIsSplashScreen;
    bool m_bWorldViewerBeingUsed;
    u8 m_nActiveCam;
    u32 m_nCamShakeStart;
    #ifndef AML64
    u32 m_nFirstPersonCamLastInputTime;
    #endif
    u32 m_nLongestTimeInMill;
    u32 m_nNumberOfTrainCamNodes;
    u8 m_nTransitionJUSTStarted;
    u8 m_nTransitionState;
    u32 m_nTimeLastChange;
    u32 m_nTimeWeLeftIdle_StillNoInput;
    u32 m_nTimeWeEnteredIdle;
    u32 m_nTimeTransitionStart;
    u32 m_nTransitionDuration;
    u32 m_nTransitionDurationTargetCoors;
    i32 m_nBlurBlue;
    i32 m_nBlurGreen;
    i32 m_nBlurRed;
    i32 m_nBlurType;
    i32 m_nWorkOutSpeedThisNumFrames;
    i32 m_nNumFramesSoFar;
    i32 m_nCurrentTrainCamNode;
    i32 m_nMotionBlur;
    i32 m_nMotionBlurAddAlpha;
    i32 m_nCheckCullZoneThisNumFrames;
    i32 m_nZoneCullFrameNumWereAt;
    i32 m_nWhoIsInControlOfTheCamera;
    float m_fCamFrontXNorm, m_fCamFrontYNorm;
    float m_fCarZoomIndicator;
    float m_fCarZoomValue;
    float m_fCarZoomValueSmooth;
    float m_fDistanceToWater;
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
    float m_PedOrientForBehindOrInFront;
    float m_fCameraAverageSpeed;
    float m_fCameraSpeedSoFar;
    float m_fCamShakeForce;
    float m_fCarZoomValueScript;
    float m_fFovForTrain;
    float m_fFOV_Wide_Screen;
    float m_fNearClipScript;
    float m_fOldBetaDiff;
    float m_fPedZoomValue;
    float m_fPedZoomValueSmooth;
    float m_fPedZoomValueScript;
    float m_fPositionAlongSpline;
    float m_fScreenReductionPercentage;
    float m_fScreenReductionSpeed;
    float m_fAlphaForPlayerAnim1rstPerson;
    float m_fOrientation;
    float m_fPedZoomIndicator;
    float m_fPlayerExhaustion;
    float m_fSoundDistUp;
    float m_fSoundDistUpAsRead;
    float m_fSoundDistUpAsReadOld;
    float m_fAvoidTheGeometryProbsTimer;
    i16 m_nAvoidTheGeometryProbsDirn;
    float m_fWideScreenReductionAmount;
    float m_fStartingFOVForInterPol;
    CCam m_asCams[3];
    CGarage* pToGarageWeAreIn;
    CGarage* pToGarageWeAreInForHackAvoidFirstPerson;
    tQueuedMode m_PlayerMode;
    tQueuedMode m_PlayerWeaponMode;
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
    CVector m_vecSourceDuringInter, m_vecTargetDuringInter, m_vecUpDuringInter;
    RwCamera* m_pRwCamera;
    CEntity* m_pTargetEntity;
    tCamPathSplines m_ArrPathArray[4];
    CMatrix m_CameraMatrix;
    bool m_bGarageFixedCamPositionSet;
    bool m_vecDoingSpecialInterPolation;
    bool m_bScriptParametersSetForInterPol;
    bool m_bFading;
    bool m_bMusicFading;
    CMatrix m_ViewMatrix;
    CVector m_vecFrustumNormals[4];
    CVector m_vecOldSourceForInter;
    CVector m_vecOldFrontForInter;
    CVector m_vecOldUpForInter;
    float m_vecOldFOVForInter;
    float m_fFLOATingFade;
    float m_fFLOATingFadeMusic;
    float m_fTimeToFadeOut;
    float m_fTimeToFadeMusic;
    float m_fFractionInterToStopMoving;
    float m_fFractionInterToStopCatchUp;
    float m_fFractionInterToStopMovingTarget;
    float m_fFractionInterToStopCatchUpTarget;
    float m_fGaitSwayBuffer;
    float m_fScriptPercentageInterToStopMoving;
    float m_fScriptPercentageInterToCatchUp;
    u32 m_fScriptTimeForInterPolation;
    i16 m_nFadingDirection;
    i32 m_nModeObbeCamIsInForCar;
    i16 m_nModeToGoTo;
    i16 m_nMusicFadingDirection;
    i16 m_nTypeOfSwitch;
    u32 m_nFadeTimeStarted;
    u32 m_nFadeTimeStartedMusic;
DECL_CLASS_END()
CHECKSIZE(CCamera, 0x94C, 0x9D0);

#define m_bUseMouse3rdPerson m_bUseMouse3rdPerson()
#define m_fMouseAccelVertical m_fMouseAccelVertical()
#define m_fMouseAccelHorzntl m_fMouseAccelHorzntl()
#define m_f3rdPersonCHairMultX m_f3rdPersonCHairMultX()
#define m_f3rdPersonCHairMultY m_f3rdPersonCHairMultY()

DECL_OBJECT_PLT_GLOBAL(CCamera, TheCamera, BYBIT(0x396B28, 0x57B650));
#define TheCamera TheCamera()

#endif // __AML_PSDK_VCCAMERA_H
