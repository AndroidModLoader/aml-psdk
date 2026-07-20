
#ifndef __AML_PSDK_RPATOMIC_H
#define __AML_PSDK_RPATOMIC_H

#include <aml-psdk/sdk_base.h>
#include "RwObject.h"
#include "RpGeometry.h"
#include "RpMaterial.h"
#include "RpClump.h"
#include "RwMatrix.h"
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

#endif // __AML_PSDK_RPATOMIC_H