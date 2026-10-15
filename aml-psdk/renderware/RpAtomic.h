
#ifndef __AML_PSDK_RPATOMIC_H
#define __AML_PSDK_RPATOMIC_H

#include <aml-psdk/sdk_base.h>
#include "RwObject.h"
#include "RpGeometry.h"
#include "RpMaterial.h"
#include "RpClump.h"
#include "RwMatrix.h"
#include "RwFrame.h"
#include "RwVector.h"
#include "RwResource.h"
#include "RxPipeline.h"
#include "RpWorld.h"

struct RpAtomic;

enum RpAtomicFlag : RwInt32
{
    rpATOMICCOLLISIONTEST = 0x1, /**< Collision testing is enabled */
    rpATOMICRENDER = 0x4,        /**< The atomic is rendered */
};

enum RpAtomicSetGeomFlag : RwInt32
{
    rpATOMICSAMEBOUNDINGSPHERE = 0x1, /**< Skip recomputing the bounding sphere */
};

enum RpInterpolatorFlag : RwInt32
{
    rpINTERPOLATORDIRTYINSTANCE = 0x1,
    rpINTERPOLATORDIRTYSPHERE = 0x2,
    rpINTERPOLATORNOFRAMEDIRTY = 0x4,
};

struct RpInterpolator
{
    RwInt32 flags;
    RwInt16 startMorphTarget;
    RwInt16 endMorphTarget;
    RwReal  time;
    RwReal  recipTime;
    RwReal  position;
};

typedef RpAtomic *(*RpAtomicCallBackRender)(RpAtomic *);
struct RpAtomic
{
    RwObjectHasFrame        object;
    RwResEntry             *repEntry;
    RpGeometry             *geometry;
    RwSphere                boundingSphere;
    RwSphere                worldBoundingSphere;
    RpClump                *clump;
    RwLLLink                inClumpLink;
    RpAtomicCallBackRender  renderCallBack;
    RpInterpolator          interpolator;
    RwUInt16                renderFrame;
    RwUInt16                pad;
    RwLinkList              llWorldSectorsInAtomic;
    RxPipeline             *pipeline;
};

DECL_FASTCALL_SIMPLE_GLO(AtomicDefaultRenderCallBack, _Z27AtomicDefaultRenderCallBackP8RpAtomic, RpAtomic*, RpAtomic* atomic);
DECL_FASTCALL_SIMPLE_GLO(_rpAtomicResyncInterpolatedSphere, _Z33_rpAtomicResyncInterpolatedSphereP8RpAtomic, void, RpAtomic* atomic);
DECL_FASTCALL_SIMPLE_GLO(RpAtomicGetWorldBoundingSphere, _Z30RpAtomicGetWorldBoundingSphereP8RpAtomic, const RwSphere*, RpAtomic* atomic);
DECL_FASTCALL_SIMPLE_GLO(RpAtomicSetFreeListCreateParams, _Z31RpAtomicSetFreeListCreateParamsii, void, RwInt32 blockSize, RwInt32 numBlocksToPrealloc);
DECL_FASTCALL_SIMPLE_GLO(RpAtomicCreate, _Z14RpAtomicCreatev, RpAtomic*, void);
DECL_FASTCALL_SIMPLE_GLO(RpAtomicDestroy, _Z15RpAtomicDestroyP8RpAtomic, RwBool, RpAtomic* atomic);
DECL_FASTCALL_SIMPLE_GLO(RpAtomicSetFrame, _Z16RpAtomicSetFrameP8RpAtomicP7RwFrame, RpAtomic*, RpAtomic* atomic, RwFrame* frame);
DECL_FASTCALL_SIMPLE_GLO(RpAtomicSetGeometry, _Z19RpAtomicSetGeometryP8RpAtomicP10RpGeometryj, RpAtomic*, RpAtomic* atomic, RpGeometry* geometry, RwUInt32 flags);
DECL_FASTCALL_SIMPLE_GLO(RpAtomicClone, _Z13RpAtomicCloneP8RpAtomic, RpAtomic*, RpAtomic* atomic);
DECL_FASTCALL_SIMPLE_GLO(RpAtomicStreamGetSize, _Z21RpAtomicStreamGetSizeP8RpAtomic, RwUInt32, RpAtomic* atomic);
DECL_FASTCALL_SIMPLE_GLO(RpAtomicStreamWrite, _Z19RpAtomicStreamWriteP8RpAtomicP8RwStream, RpAtomic*, RpAtomic* atomic, RwStream* stream);
DECL_FASTCALL_SIMPLE_GLO(RpAtomicStreamRead, _Z18RpAtomicStreamReadP8RwStream, RpAtomic*, RwStream* stream);
DECL_FASTCALL_SIMPLE_GLO(RpAtomicRegisterPlugin, _Z22RpAtomicRegisterPluginijPFPvS_iiES1_PFS_S_PKviiE, RwInt32, RwInt32 size, RwUInt32 pluginID, RwPluginObjectConstructor constructCB, RwPluginObjectDestructor destructCB, RwPluginObjectCopy copyCB);
DECL_FASTCALL_SIMPLE_GLO(RpAtomicRegisterPluginStream, _Z28RpAtomicRegisterPluginStreamjPFP8RwStreamS0_iPviiEPFS0_S0_iPKviiEPFiS5_iiE, RwInt32, RwUInt32 pluginID, RwPluginDataChunkReadCallBack readCB, RwPluginDataChunkWriteCallBack writeCB, RwPluginDataChunkGetSizeCallBack getSizeCB);
DECL_FASTCALL_SIMPLE_GLO(RpAtomicSetStreamAlwaysCallBack, _Z31RpAtomicSetStreamAlwaysCallBackjPFiPviiE, RwInt32, RwUInt32 pluginID, RwPluginDataChunkAlwaysCallBack alwaysCB);
DECL_FASTCALL_SIMPLE_GLO(RpAtomicSetStreamRightsCallBack, _Z31RpAtomicSetStreamRightsCallBackjPFiPviijE, RwInt32, RwUInt32 pluginID, RwPluginDataChunkRightsCallBack rightsCB);
DECL_FASTCALL_SIMPLE_GLO(RpAtomicGetPluginOffset, _Z23RpAtomicGetPluginOffsetj, RwInt32, RwUInt32 pluginID);
DECL_FASTCALL_SIMPLE_GLO(RpAtomicValidatePlugins, _Z23RpAtomicValidatePluginsPK8RpAtomic, RwBool, const RpAtomic* atomic);
DECL_FASTCALL_SIMPLE_GLO(RpAtomicInstance, _Z16RpAtomicInstanceP8RpAtomic, RwBool, RpAtomic* atomic);
DECL_FASTCALL_SIMPLE_GLO(RpAtomicGetWorld, _Z16RpAtomicGetWorldPK8RpAtomic, RpWorld*, const RpAtomic* atomic);
DECL_FASTCALL_SIMPLE_GLO(RpAtomicForAllWorldSectors, _Z26RpAtomicForAllWorldSectorsP8RpAtomicPFP13RpWorldSectorS2_PvES3_, RpAtomic*, RpAtomic* atomic, RpWorldSectorCallBack callback, void* data);
DECL_FASTCALL_SIMPLE_GLO(RpAtomicSetDefaultPipeline, _Z26RpAtomicSetDefaultPipelineP10RxPipeline, RxPipeline*, RxPipeline* pipeline);
DECL_FASTCALL_SIMPLE_GLO(RpAtomicConvertGeometryToTL, _Z27RpAtomicConvertGeometryToTLP8RpAtomic, u8, RpAtomic* pAtomic);
DECL_FASTCALL_SIMPLE_GLO(RpAtomicConvertGeometryToTS, _Z27RpAtomicConvertGeometryToTSP8RpAtomic, u8, RpAtomic* pAtomic);

inline RpGeometry* RpAtomicGetGeometry(const RpAtomic* atomic)
{
    return atomic->geometry;
}

inline RpClump* RpAtomicGetClump(const RpAtomic* atomic)
{
    return atomic->clump;
}

inline RwFrame* RpAtomicGetFrame(const RpAtomic* atomic)
{
    return atomic->object.object.frame;
}

inline RwUInt32 RpAtomicGetFlags(const RpAtomic* atomic)
{
    return atomic->object.object.flags;
}

inline RpAtomicCallBackRender RpAtomicGetRenderCallBack(const RpAtomic* atomic)
{
    return atomic->renderCallBack;
}

inline RpAtomic* RpAtomicSetFlags(RpAtomic* atomic, RwUInt32 flags)
{
    atomic->object.object.flags = (RwUInt8)flags;
    return atomic;
}

inline RpAtomic* RpAtomicRender(RpAtomic* atomic)
{
    return atomic->renderCallBack(atomic);
}

inline void RpAtomicSetRenderCallBack(RpAtomic* atomic, RpAtomicCallBackRender callback)
{
    atomic->renderCallBack = callback ? callback : AtomicDefaultRenderCallBack;
}

inline RpInterpolator* RpAtomicGetInterpolator(RpAtomic* atomic)
{
    return &atomic->interpolator;
}

inline RwSphere* RpAtomicGetBoundingSphere(RpAtomic* atomic)
{
    if(atomic->interpolator.flags & rpINTERPOLATORDIRTYSPHERE) _rpAtomicResyncInterpolatedSphere(atomic);
    return &atomic->boundingSphere;
}

inline RwInt32 RpInterpolatorGetStartMorphTarget(const RpInterpolator* interpolator)
{
    return interpolator->startMorphTarget;
}

inline RwInt32 RpInterpolatorGetEndMorphTarget(const RpInterpolator* interpolator)
{
    return interpolator->endMorphTarget;
}

inline RwReal RpInterpolatorGetValue(const RpInterpolator* interpolator)
{
    return interpolator->position;
}

inline RwReal RpInterpolatorGetScale(const RpInterpolator* interpolator)
{
    return interpolator->time;
}

inline RpInterpolator* RpInterpolatorSetStartMorphTarget(RpInterpolator* interpolator, RwInt32 target, RpAtomic* atomic)
{
    interpolator->startMorphTarget = (RwInt16)target;
    interpolator->flags |= rpINTERPOLATORDIRTYINSTANCE | rpINTERPOLATORDIRTYSPHERE;
    if(!(interpolator->flags & rpINTERPOLATORNOFRAMEDIRTY))
    {
        RwFrame* frame = RpAtomicGetFrame(atomic);
        if(frame) RwFrameUpdateObjects(frame);
    }
    return interpolator;
}

inline RpInterpolator* RpInterpolatorSetEndMorphTarget(RpInterpolator* interpolator, RwInt32 target, RpAtomic* atomic)
{
    interpolator->endMorphTarget = (RwInt16)target;
    interpolator->flags |= rpINTERPOLATORDIRTYINSTANCE | rpINTERPOLATORDIRTYSPHERE;
    if(!(interpolator->flags & rpINTERPOLATORNOFRAMEDIRTY))
    {
        RwFrame* frame = RpAtomicGetFrame(atomic);
        if(frame) RwFrameUpdateObjects(frame);
    }
    return interpolator;
}

inline RpInterpolator* RpInterpolatorSetValue(RpInterpolator* interpolator, RwReal value, RpAtomic* atomic)
{
    interpolator->position = value;
    interpolator->flags |= rpINTERPOLATORDIRTYINSTANCE | rpINTERPOLATORDIRTYSPHERE;
    if(!(interpolator->flags & rpINTERPOLATORNOFRAMEDIRTY))
    {
        RwFrame* frame = RpAtomicGetFrame(atomic);
        if(frame) RwFrameUpdateObjects(frame);
    }
    return interpolator;
}

inline RpInterpolator* RpInterpolatorSetScale(RpInterpolator* interpolator, RwReal scale, RpAtomic* atomic)
{
    interpolator->time = scale;
    interpolator->recipTime = 1.0f / scale;
    interpolator->flags |= rpINTERPOLATORDIRTYINSTANCE | rpINTERPOLATORDIRTYSPHERE;
    if(!(interpolator->flags & rpINTERPOLATORNOFRAMEDIRTY))
    {
        RwFrame* frame = RpAtomicGetFrame(atomic);
        if(frame) RwFrameUpdateObjects(frame);
    }
    return interpolator;
}

inline RpAtomic* RpAtomicSetPipeline(RpAtomic* atomic, RxPipeline* pipeline)
{
    atomic->pipeline = pipeline;
    return atomic;
}

inline const RpAtomic* RpAtomicGetPipeline(const RpAtomic* atomic, RxPipeline** pipeline)
{
    *pipeline = atomic->pipeline;
    return atomic;
}

#endif // __AML_PSDK_RPATOMIC_H