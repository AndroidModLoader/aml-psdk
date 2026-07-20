#ifndef __AML_PSDK_RWCAMERA_H
#define __AML_PSDK_RWCAMERA_H

#include <aml-psdk/sdk_base.h>
#include "RwBase.h"
#include "RwLinks.h"
#include "RwObject.h"
#include "RwMatrix.h"
#include "RwVector.h"
#include "RwRGBA.h"

struct RwRaster;

enum RwFrustumTestResult : RwInt32
{
    rwSPHEREOUTSIDE = 0x0,
    rwSPHEREBOUNDARY = 0x1,
    rwSPHEREINSIDE = 0x2,
};

enum RwCameraProjection : RwInt32
{
    rwNACAMERAPROJECTION = 0x0,
    rwPERSPECTIVE = 0x1,
    rwPARALLEL = 0x2,
};

enum RwCameraClearMode : RwInt32
{
    rwCAMERACLEARIMAGE = 0x1,
    rwCAMERACLEARZ = 0x2,
    rwCAMERACLEARSTENCIL = 0x4,
};

typedef RwCamera *(*RwCameraBeginUpdateFunc)(RwCamera *camera);
typedef RwCamera *(*RwCameraEndUpdateFunc)(RwCamera *camera);

/* A frustum plane plus the index of the bounding box corner nearest to it,
 * which is what makes the box/frustum test cheap. */
struct RwFrustumPlane
{
    RwPlane plane;
    RwUInt8 closestX;
    RwUInt8 closestY;
    RwUInt8 closestZ;
    RwUInt8 pad;
};

struct RwCamera
{
    RwObjectHasFrame        object;
    RwCameraProjection      projectionType;
    RwCameraBeginUpdateFunc beginUpdate;
    RwCameraEndUpdateFunc   endUpdate;
    RwMatrix                viewMatrix;
    RwRaster               *frameBuffer;
    RwRaster               *zBuffer;
    RwV2d                   viewWindow;
    RwV2d                   recipViewWindow;
    RwV2d                   viewOffset;
    RwReal                  nearPlane;
    RwReal                  farPlane;
    RwReal                  fogPlane;
    RwReal                  zScale;      /* Used for generating screen z */
    RwReal                  zShift;      /* Used for generating screen z */
    RwUInt16                renderFrame;
    RwUInt16                pad;
    RwFrustumPlane          frustumPlanes[6];
    RwBBox                  frustumBoundBox;
    RwV3d                   frustumCorners[8];
};

/* Header of a camera chunk in a stream. RenderWare spells the struct
 * rwStreamCamera and typedefs it; both names are kept here. */
struct rwStreamCamera
{
    RwV2d    viewWindow;
    RwV2d    viewOffset;
    RwReal   nearPlane;
    RwReal   farPlane;
    RwReal   fogPlane;
    RwUInt32 projection;
};
typedef rwStreamCamera RwCameraChunkInfo;

CHECKSIZE(RwFrustumPlane, 0x14, 0x14);
CHECKSIZE(RwCamera, 0x188, 0x1B0);
CHECKSIZE(rwStreamCamera, 0x20, 0x20);

DECL_FASTCALL_SIMPLE_GLO(_rwCameraClose, _Z14_rwCameraClosePvii, void*, void* instance, RwInt32 offset, RwInt32 size);
DECL_FASTCALL_SIMPLE_GLO(_rwCameraOpen, _Z13_rwCameraOpenPvii, void*, void* instance, RwInt32 offset, RwInt32 size);
DECL_FASTCALL_SIMPLE_GLO(_rwCameraValClose, _Z17_rwCameraValClosev, void);
DECL_FASTCALL_SIMPLE_GLO(_rwCameraValOpen, _Z16_rwCameraValOpenv, void);
DECL_FASTCALL_SIMPLE_GLO(_rwCameraValRender, _Z18_rwCameraValRenderP8RwCamera, void, RwCamera* camera);
DECL_FASTCALL_SIMPLE_GLO(RwCameraBeginUpdate, _Z19RwCameraBeginUpdateP8RwCamera, RwCamera*, RwCamera* camera);
DECL_FASTCALL_SIMPLE_GLO(RwCameraChunkInfoRead, _Z21RwCameraChunkInfoReadP8RwStreamP14rwStreamCameraPi, RwCameraChunkInfo*, RwStream* stream, RwCameraChunkInfo* cameraChunkInfo, RwInt32* bytesRead);
DECL_FASTCALL_SIMPLE_GLO(RwCameraClear, _Z13RwCameraClearP8RwCameraP6RwRGBAi, RwCamera*, RwCamera* camera, RwRGBA* color, RwInt32 clearMode);
DECL_FASTCALL_SIMPLE_GLO(RwCameraClone, _Z13RwCameraCloneP8RwCamera, RwCamera*, RwCamera* camera);
DECL_FASTCALL_SIMPLE_GLO(RwCameraCreate, _Z14RwCameraCreatev, RwCamera*);
DECL_FASTCALL_SIMPLE_GLO(RwCameraDestroy, _Z15RwCameraDestroyP8RwCamera, RwBool, RwCamera* camera);
DECL_FASTCALL_SIMPLE_GLO(RwCameraEndUpdate, _Z17RwCameraEndUpdateP8RwCamera, RwCamera*, RwCamera* camera);
DECL_FASTCALL_SIMPLE_GLO(RwCameraForAllClumpsInFrustum, _Z29RwCameraForAllClumpsInFrustumP8RwCameraPv, RwCamera*, RwCamera* camera, void* data);
DECL_FASTCALL_SIMPLE_GLO(RwCameraForAllClumpsNotInFrustum, _Z32RwCameraForAllClumpsNotInFrustumP8RwCameraiPv, RwCamera*, RwCamera* camera, RwInt32 numClumps, void* data);
DECL_FASTCALL_SIMPLE_GLO(RwCameraForAllSectorsInFrustum, _Z30RwCameraForAllSectorsInFrustumP8RwCameraPFP13RpWorldSectorS2_PvES3_, RwCamera*, RwCamera* camera, RpWorldSectorCallBack callback, void* data);
DECL_FASTCALL_SIMPLE_GLO(RwCameraFrustumTestSphere, _Z25RwCameraFrustumTestSpherePK8RwCameraPK8RwSphere, RwFrustumTestResult, const RwCamera* camera, const RwSphere* sphere);
DECL_FASTCALL_SIMPLE_GLO(RwCameraGetClump, _Z16RwCameraGetClumpPK8RwCamera, RpClump*, const RwCamera* camera);
DECL_FASTCALL_SIMPLE_GLO(RwCameraGetPluginOffset, _Z23RwCameraGetPluginOffsetj, RwInt32, RwUInt32 pluginID);
DECL_FASTCALL_SIMPLE_GLO(RwCameraGetWorld, _Z16RwCameraGetWorldPK8RwCamera, RpWorld*, const RwCamera* camera);
DECL_FASTCALL_SIMPLE_GLO(RwCameraRegisterPlugin, _Z22RwCameraRegisterPluginijPFPvS_iiES1_PFS_S_PKviiE, RwInt32, RwInt32 size, RwUInt32 pluginID, RwPluginObjectConstructor constructCB, RwPluginObjectDestructor destructCB, RwPluginObjectCopy copyCB);
DECL_FASTCALL_SIMPLE_GLO(RwCameraRegisterPluginStream, _Z28RwCameraRegisterPluginStreamjPFP8RwStreamS0_iPviiEPFS0_S0_iPKviiEPFiS5_iiE, RwInt32, RwUInt32 pluginID, RwPluginDataChunkReadCallBack readCB, RwPluginDataChunkWriteCallBack writeCB, RwPluginDataChunkGetSizeCallBack getSizeCB);
DECL_FASTCALL_SIMPLE_GLO(RwCameraSetFarClipPlane, _Z23RwCameraSetFarClipPlaneP8RwCameraf, RwCamera*, RwCamera* camera, RwReal farClip);
DECL_FASTCALL_SIMPLE_GLO(RwCameraSetFreeListCreateParams, _Z31RwCameraSetFreeListCreateParamsii, void, RwInt32 blockSize, RwInt32 numBlocksToPrealloc);
DECL_FASTCALL_SIMPLE_GLO(RwCameraSetNearClipPlane, _Z24RwCameraSetNearClipPlaneP8RwCameraf, RwCamera*, RwCamera* camera, RwReal nearClip);
DECL_FASTCALL_SIMPLE_GLO(RwCameraSetProjection, _Z21RwCameraSetProjectionP8RwCamera18RwCameraProjection, RwCamera*, RwCamera* camera, RwCameraProjection projection);
DECL_FASTCALL_SIMPLE_GLO(RwCameraSetStreamAlwaysCallBack, _Z31RwCameraSetStreamAlwaysCallBackjPFiPviiE, RwInt32, RwUInt32 pluginID, RwPluginDataChunkAlwaysCallBack alwaysCB);
DECL_FASTCALL_SIMPLE_GLO(RwCameraSetViewOffset, _Z21RwCameraSetViewOffsetP8RwCameraPK5RwV2d, RwCamera*, RwCamera* camera, const RwV2d* offset);
DECL_FASTCALL_SIMPLE_GLO(RwCameraSetViewWindow, _Z21RwCameraSetViewWindowP8RwCameraPK5RwV2d, RwCamera*, RwCamera* camera, const RwV2d* viewWindow);
DECL_FASTCALL_SIMPLE_GLO(RwCameraShowRaster, _Z18RwCameraShowRasterP8RwCameraPvj, RwCamera*, RwCamera* camera, void* dev, RwUInt32 flags);
DECL_FASTCALL_SIMPLE_GLO(RwCameraStreamGetSize, _Z21RwCameraStreamGetSizePK8RwCamera, RwUInt32, const RwCamera* camera);
DECL_FASTCALL_SIMPLE_GLO(RwCameraStreamRead, _Z18RwCameraStreamReadP8RwStream, RwCamera*, RwStream* stream);
DECL_FASTCALL_SIMPLE_GLO(RwCameraStreamWrite, _Z19RwCameraStreamWritePK8RwCameraP8RwStream, const RwCamera*, const RwCamera* camera, RwStream* stream);
DECL_FASTCALL_SIMPLE_GLO(RwCameraValidatePlugins, _Z23RwCameraValidatePluginsPK8RwCamera, RwBool, const RwCamera* camera);

#endif // __AML_PSDK_RWCAMERA_H
