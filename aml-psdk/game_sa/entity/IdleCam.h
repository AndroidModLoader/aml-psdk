#ifndef __AML_PSDK_SAIDLECAM_H
#define __AML_PSDK_SAIDLECAM_H

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/gta_base/Vector.h>

struct CEntity;
struct CCam;

DECL_CLASS(CIdleCam)
    enum
    {
        ZOOMING_IN = 0,
        ZOOMING_OUT = 1,
        ZOOMED_IN = 2,
        ZOOMED_OUT = 3
    };

    // Member functions
    DECL_THISCALL_SIMPLE(Init, _ZN8CIdleCam4InitEv, void);
    DECL_THISCALL_HEAD(Reset, _ZN8CIdleCam5ResetEb, void, bool resetTarget)
    DECL_THISCALL_TAIL(Reset, resetTarget)
    DECL_THISCALL_SIMPLE(IdleCamGeneralProcess, _ZN8CIdleCam21IdleCamGeneralProcessEv, void);
    DECL_THISCALL_SIMPLE(Process, _ZN8CIdleCam7ProcessEv, bool);
    DECL_THISCALL_SIMPLE(Run, _ZN8CIdleCam3RunEv, void);
    DECL_THISCALL_SIMPLE(ProcessTargetSelection, _ZN8CIdleCam22ProcessTargetSelectionEv, void);
    DECL_THISCALL_HEAD(ProcessSlerp, _ZN8CIdleCam12ProcessSlerpEPfS0_, float, float* rotX, float* rotZ)
    DECL_THISCALL_TAIL(ProcessSlerp, rotX, rotZ)
    DECL_THISCALL_HEAD(ProcessFOVZoom, _ZN8CIdleCam14ProcessFOVZoomEf, void, float timeStep)
    DECL_THISCALL_TAIL(ProcessFOVZoom, timeStep)
    DECL_THISCALL_SIMPLE(IsItTimeForIdleCam, _ZN8CIdleCam18IsItTimeForIdleCamEv, bool);
    DECL_THISCALL_HEAD(GetLookAtPositionOnTarget, _ZN8CIdleCam25GetLookAtPositionOnTargetEP7CEntityP7CVector, void, CEntity* target, CVector* pos)
    DECL_THISCALL_TAIL(GetLookAtPositionOnTarget, target, pos)
    DECL_THISCALL_SIMPLE(SetTargetPlayer, _ZN8CIdleCam15SetTargetPlayerEv, void);
    DECL_THISCALL_HEAD(SetTarget, _ZN8CIdleCam9SetTargetEP7CEntity, void, CEntity* target)
    DECL_THISCALL_TAIL(SetTarget, target)
    DECL_THISCALL_HEAD(FinaliseIdleCamera, _ZN8CIdleCam18FinaliseIdleCameraEfff, void, float rotX, float rotZ, float distance)
    DECL_THISCALL_TAIL(FinaliseIdleCamera, rotX, rotZ, distance)
    DECL_THISCALL_HEAD(VectorToAnglesRotXRotZ, _ZN8CIdleCam22VectorToAnglesRotXRotZEP7CVectorPfS2_, void, CVector* direction, float* rotX, float* rotZ)
    DECL_THISCALL_TAIL(VectorToAnglesRotXRotZ, direction, rotX, rotZ)
    DECL_THISCALL_HEAD(IsTargetValid, _ZN8CIdleCam13IsTargetValidEP7CEntity, bool, CEntity* target)
    DECL_THISCALL_TAIL(IsTargetValid, target)
    DECL_THISCALL_SIMPLE(ProcessIdleCamTicker, _ZN8CIdleCam20ProcessIdleCamTickerEv, void);

    // Member values
    CEntity* pTarget;
    CVector positionToSlerpFrom;
    float timeSlerpStarted;
    float slerpDuration;
    CVector lastIdlePos;
    float slerpTime;
    float timeControlsIdleForIdleToKickIn;
    float timeIdleCamStarted;
    i32 lastFrameProcessed;
    float timeLastTargetSelected;
    float timeMinimumToLookAtSomething;
    float timeTargetEntityWasLastVisible;
    float timeToConsiderNonVisibleEntityAsOccluded;
    float distTooClose;
    float distStartFOVZoom;
    float distTooFar;
    i32 targetLOSFramestoReject;
    i32 targetLOSCounter;
    i32 zoomState;
    float zoomFrom;
    float zoomTo;
    float timeZoomStarted;
    float zoomNearest;
    float zoomFarthest;
    float curFOV;
    float durationFOVZoom;
    bool bForceAZoomOut;
    bool bHasZoomedIn;
    float timeBeforeNewZoomIn;
    float timeLastZoomIn;
    float increaseMinimumTimeFactorforZoomedIn;
    float degreeShakeIdleCam;
    float shakeBuildUpTime;
    i32 lastTimePadTouched;
    i32 idleTickerFrames;
    CCam* pCam;
DECL_CLASS_END()
CHECKSIZE(CIdleCam, 0x9c, 0xa8);

DECL_OBJECT_PLT_GLOBAL(CIdleCam, gIdleCam, BYBIT(0x6781e0, 0x84e3d8));

#endif // __AML_PSDK_SAIDLECAM_H
