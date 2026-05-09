#ifndef __AML_PSDK_RPCLUMP_H
#define __AML_PSDK_RPCLUMP_H

#include <aml-psdk/sdk_base.h>
#include "RwBase.h"
#include "RwLinks.h"
#include "RwObject.h"

struct RpClump;
struct RpLight;
struct RpWorld;

typedef RpClump* (*RpClumpCallBack)(RpClump* clump, void *data);
struct RpClumpChunkInfo
{
    RwInt32 numAtomics;
    RwInt32 numLights;
    RwInt32 numCameras;
};
struct RpClump
{
    RwObject            object;
    RwLinkList          atomicList;
    RwLinkList          lightList;
    RwLinkList          cameraList;
    RwLLLink            inWorldLink;
    RpClumpCallBack     callback;
};

DECL_FASTCALL_SIMPLE_GLO(_rpClumpClose, _Z13_rpClumpClosePvii, void*, void* instance, RwInt32 offset, RwInt32 size);
DECL_FASTCALL_SIMPLE_GLO(ClumpTidyDestroyClump, _ZL21ClumpTidyDestroyClumpPvS_, void, void* object, void* data);
DECL_FASTCALL_SIMPLE_GLO(ClumpTidyDestroyAtomic, _ZL22ClumpTidyDestroyAtomicPvS_, void, void* object, void* data);
DECL_FASTCALL_SIMPLE_GLO(RpClumpSetFreeListCreateParams, _Z30RpClumpSetFreeListCreateParamsii, void, RwInt32 blockSize, RwInt32 numBlocksToPrealloc);
DECL_FASTCALL_SIMPLE_GLO(_rpClumpOpen, _Z12_rpClumpOpenPvii, void*, void* instance, RwInt32 offset, RwInt32 size);
DECL_FASTCALL_SIMPLE_GLO(_rpClumpRegisterExtensions, _Z26_rpClumpRegisterExtensionsv, RwBool, void);
DECL_FASTCALL_SIMPLE_GLO(ClumpInitCameraExt, _ZL18ClumpInitCameraExtPvii, void*, void* object, RwInt32 offsetInObject, RwInt32 sizeInObject);
DECL_FASTCALL_SIMPLE_GLO(ClumpDeInitCameraExt, _ZL20ClumpDeInitCameraExtPvii, void*, void* object, RwInt32 offsetInObject, RwInt32 sizeInObject);
DECL_FASTCALL_SIMPLE_GLO(ClumpInitLightExt, _ZL17ClumpInitLightExtPvii, void*, void* object, RwInt32 offsetInObject, RwInt32 sizeInObject);
DECL_FASTCALL_SIMPLE_GLO(ClumpDeInitLightExt, _ZL19ClumpDeInitLightExtPvii, void*, void* object, RwInt32 offsetInObject, RwInt32 sizeInObject);
DECL_FASTCALL_SIMPLE_GLO(RpClumpGetNumAtomics, _Z20RpClumpGetNumAtomicsP7RpClump, RwInt32, RpClump* clump);
//DECL_FASTCALL_SIMPLE_GLO(RpClumpForAllAtomics, _Z20RpClumpForAllAtomicsP7RpClumpPFP8RpAtomicS2_PvES3_, RpClump*, RpClump* clump, RpAtomicCallBack callback, void* pData);
DECL_FASTCALL_SIMPLE_GLO(RpClumpGetNumLights, _Z19RpClumpGetNumLightsP7RpClump, RwInt32, RpClump* clump);
//DECL_FASTCALL_SIMPLE_GLO(RpClumpForAllLights, _Z19RpClumpForAllLightsP7RpClumpPFP7RpLightS2_PvES3_, RpClump*, RpClump* clump, RpLightCallBack callback, void* pData);
DECL_FASTCALL_SIMPLE_GLO(RpClumpGetNumCameras, _Z20RpClumpGetNumCamerasP7RpClump, RwInt32, RpClump* clump);
//DECL_FASTCALL_SIMPLE_GLO(RpClumpForAllCameras, _Z20RpClumpForAllCamerasP7RpClumpPFP8RwCameraS2_PvES3_, RpClump*, RpClump* clump, RwCameraCallBack callback, void* pData);
DECL_FASTCALL_SIMPLE_GLO(RpClumpCreateSpace, _Z18RpClumpCreateSpacePK5RwV3df, RpClump*, const RwV3d* position, RwReal radius);
DECL_FASTCALL_SIMPLE_GLO(RpClumpCreate, _Z13RpClumpCreatev, RpClump*, void);
DECL_FASTCALL_SIMPLE_GLO(RpClumpAddAtomic, _Z16RpClumpAddAtomicP7RpClumpP8RpAtomic, RpClump*, RpClump* clump, RpAtomic* atomic);
DECL_FASTCALL_SIMPLE_GLO(RpClumpRender, _Z13RpClumpRenderP7RpClump, RpClump*, RpClump* clump);
DECL_FASTCALL_SIMPLE_GLO(RpClumpClone, _Z12RpClumpCloneP7RpClump, RpClump*, RpClump* clump);
DECL_FASTCALL_SIMPLE_GLO(RpClumpDestroy, _Z14RpClumpDestroyP7RpClump, RwBool, RpClump* clump);
DECL_FASTCALL_SIMPLE_GLO(RpClumpSetCallBack, _Z18RpClumpSetCallBackP7RpClumpPFS0_S0_PvE, RpClump*, RpClump* clump, RpClumpCallBack callback);
DECL_FASTCALL_SIMPLE_GLO(ClumpCallBack, _ZL13ClumpCallBackP7RpClumpPv, RpClump*, RpClump* clump, void* data);
DECL_FASTCALL_SIMPLE_GLO(RpClumpGetCallBack, _Z18RpClumpGetCallBackPK7RpClump, RpClumpCallBack, const RpClump* clump);
DECL_FASTCALL_SIMPLE_GLO(RpClumpRemoveAtomic, _Z19RpClumpRemoveAtomicP7RpClumpP8RpAtomic, RpClump*, RpClump* clump, RpAtomic* atomic);
DECL_FASTCALL_SIMPLE_GLO(RpClumpAddLight, _Z15RpClumpAddLightP7RpClumpP7RpLight, RpClump*, RpClump* clump, RpLight* light);
DECL_FASTCALL_SIMPLE_GLO(RpClumpRemoveLight, _Z18RpClumpRemoveLightP7RpClumpP7RpLight, RpClump*, RpClump* clump, RpLight* light);
DECL_FASTCALL_SIMPLE_GLO(RpClumpAddCamera, _Z16RpClumpAddCameraP7RpClumpP8RwCamera, RpClump*, RpClump* clump, RwCamera* camera);
DECL_FASTCALL_SIMPLE_GLO(RpClumpRemoveCamera, _Z19RpClumpRemoveCameraP7RpClumpP8RwCamera, RpClump*, RpClump* clump, RwCamera* camera);
DECL_FASTCALL_SIMPLE_GLO(RpClumpStreamGetSize, _Z20RpClumpStreamGetSizeP7RpClump, RwUInt32, RpClump* clump);
DECL_FASTCALL_SIMPLE_GLO(RpClumpStreamWrite, _Z18RpClumpStreamWriteP7RpClumpP8RwStream, RpClump*, RpClump* clump, RwStream* stream);
DECL_FASTCALL_SIMPLE_GLO(RpClumpStreamRead, _Z17RpClumpStreamReadP8RwStream, RpClump*, RwStream* stream);
DECL_FASTCALL_SIMPLE_GLO(_rpClumpChunkInfoRead, _Z21_rpClumpChunkInfoReadP8RwStreamP16RpClumpChunkInfoPi, RpClumpChunkInfo*, RwStream* stream, RpClumpChunkInfo* clumpChunkInfo, RwInt32* bytesRead);
DECL_FASTCALL_SIMPLE_GLO(RpClumpRegisterPlugin, _Z21RpClumpRegisterPluginijPFPvS_iiES1_PFS_S_PKviiE, RwInt32, RwInt32 size, RwUInt32 pluginID, RwPluginObjectConstructor constructCB, RwPluginObjectDestructor destructCB, RwPluginObjectCopy copyCB);
DECL_FASTCALL_SIMPLE_GLO(RpClumpRegisterPluginStream, _Z27RpClumpRegisterPluginStreamjPFP8RwStreamS0_iPviiEPFS0_S0_iPKviiEPFiS5_iiE, RwInt32, RwUInt32 pluginID, RwPluginDataChunkReadCallBack readCB, RwPluginDataChunkWriteCallBack writeCB, RwPluginDataChunkGetSizeCallBack getSizeCB);
DECL_FASTCALL_SIMPLE_GLO(RpClumpSetStreamAlwaysCallBack, _Z30RpClumpSetStreamAlwaysCallBackjPFiPviiE, RwInt32, RwUInt32 pluginID, RwPluginDataChunkAlwaysCallBack alwaysCB);
DECL_FASTCALL_SIMPLE_GLO(RpClumpValidatePlugins, _Z22RpClumpValidatePluginsPK7RpClump, RwBool, const RpClump* clump);
DECL_FASTCALL_SIMPLE_GLO(RpClumpGetWorld, _Z15RpClumpGetWorldPK7RpClump, RpWorld*, const RpClump* clump);

#endif // __AML_PSDK_RPCLUMP_H