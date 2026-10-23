#ifndef __AML_PSDK_SAHELICAMSETTINGS_H
#define __AML_PSDK_SAHELICAMSETTINGS_H

#include "../plugin.h"
#include "../../gta_base/Vector.h"

DECL_CLASS(CHeliCamSettings)
    // Member functions
    DECL_THISCALL_SIMPLE(SetDefault, _ZN16CHeliCamSettings10SetDefaultEv, void);
    DECL_THISCALL_SIMPLE(Reset, _ZN16CHeliCamSettings5ResetEv, void);
    DECL_THISCALL_SIMPLE(RandomiseABit, _ZN16CHeliCamSettings13RandomiseABitEv, void);

    // Member values
    CVector heliMoveTo;
    CVector heliMoveFrom;
    float heliSpeed;
    float behindStart;
    float heliHeight;
    float heliOutSideOfVehicle;
    float zoomInTime;
    float zoomFOVStart;
    float zoomFOVEnd;
    float heliSpeedLookInFrontMul;
    float heliRollScale;
    float heliClip;
    bool gbLockDest;
    i32 gLockDestTimeOut;
    i32 gLockDestHeliTimeoutDefault;
    CVector gLockedDest;
    i32 numAttemptsToFindAValidOne;
    bool gbHeliCollided;
    i32 gDefaultFramesOutOfSightBeforeWeLoseTheCar;
    i32 gFramesBeenOutOfSight;
    float gHeliDistFOVZoomMore;
    float gHeliDistFOVZoomMoreMax;
    float gLessFOV;
    float gLenToCarToPushCameraOut;
    float gRadiusOfSphereAroundHeli;
    float gZoomOutFOV;
    bool gbWeLostTheCar;
    bool gbNoZoom;
    float gFOVZoomBackOutFrom;
    bool gZoomBackOut;
    i32 gZoomBackOutTimeStart;
    i32 gZoomBackOutTimeEnd;
    float timeToZoomOut;
    i32 gZoomBackOutSpeed;
DECL_CLASS_END()
CHECKSIZE(CHeliCamSettings, 0x9C, 0x9C);

#endif // __AML_PSDK_SAHELICAMSETTINGS_H
