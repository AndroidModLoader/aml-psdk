#ifndef __AML_PSDK_RPMATERIAL_H
#define __AML_PSDK_RPMATERIAL_H

#include <aml-psdk/sdk_base.h>
#include "RwBase.h"
#include "RwObject.h"
#include "RwTexture.h"
#include "RwRGBA.h"

#include "RxPipeline.h"

#define rpMULTITEXTURE_MAXTEXTURES 8

struct rpMultiTextureRegEntry;
struct RpMTEffect;

struct RwSurfaceProperties
{
    RwReal ambient;
    RwReal specular;
    RwReal diffuse;
};

struct RpMaterial
{
    RwTexture          *texture;
    RwRGBA              color;
    RxPipeline         *pipeline;
    RwSurfaceProperties surfaceProps;
    RwInt16             refCount;
};

struct RpMaterialList
{
    RpMaterial     **materials;
    RwInt32        numMaterials;
    RwInt32        space;
};

/* Extra textures hung off a material by the multi-texture plugin. Reachable
 * with RpMaterialGetMultiTexture(). */
struct RpMultiTexture
{
    rpMultiTextureRegEntry *regEntry;
    RwUInt32                numTextures;
    RwTexture              *textures[rpMULTITEXTURE_MAXTEXTURES];
    RwUInt8                 coordMap[rpMULTITEXTURE_MAXTEXTURES]; /* Tex coord set per texture */
    RpMTEffect             *effect;
    void                   *extension;
};


CHECKSIZE(RwSurfaceProperties, 0xC, 0xC);
CHECKSIZE(RpMultiTexture, 0x38, 0x68);

DECL_FASTCALL_SIMPLE_GLO(RpMaterialSetTexture, _Z20RpMaterialSetTextureP10RpMaterialP9RwTexture, RpMaterial*, RpMaterial* material, RwTexture* texture);

DECL_FASTCALL_SIMPLE_GLO(RpMaterialCreateMultiTexture, _Z28RpMaterialCreateMultiTextureP10RpMaterial12RwPlatformIDj, RpMaterial*, RpMaterial* material, RwPlatformID platformID, RwUInt32 numTextures);
DECL_FASTCALL_SIMPLE_GLO(RpMaterialDestroyMultiTexture, _Z29RpMaterialDestroyMultiTextureP10RpMaterial12RwPlatformID, RpMaterial*, RpMaterial* material, RwPlatformID platformID);
DECL_FASTCALL_SIMPLE_GLO(RpMaterialGetMultiTexture, _Z25RpMaterialGetMultiTexturePK10RpMaterial12RwPlatformID, RpMultiTexture*, const RpMaterial* material, RwPlatformID platformID);
DECL_FASTCALL_SIMPLE_GLO(RpMaterialQueryMultiTexturePlatform, _Z35RpMaterialQueryMultiTexturePlatform12RwPlatformID, RwBool, RwPlatformID platformID);

DECL_FASTCALL_SIMPLE_GLO(RpMaterialClone, _Z15RpMaterialCloneP10RpMaterial, RpMaterial*, RpMaterial* material);
DECL_FASTCALL_SIMPLE_GLO(RpMaterialCreate, _Z16RpMaterialCreatev, RpMaterial*);
DECL_FASTCALL_SIMPLE_GLO(RpMaterialSetStreamAlwaysCallBack, _Z33RpMaterialSetStreamAlwaysCallBackjPFiPviiE, RwInt32, RwUInt32 pluginID, RwPluginDataChunkAlwaysCallBack alwaysCB);
DECL_FASTCALL_SIMPLE_GLO(RpMaterialRegisterPlugin, _Z24RpMaterialRegisterPluginijPFPvS_iiES1_PFS_S_PKviiE, RwInt32, RwInt32 size, RwUInt32 pluginID, RwPluginObjectConstructor constructCB, RwPluginObjectDestructor destructCB, RwPluginObjectCopy copyCB);
DECL_FASTCALL_SIMPLE_GLO(RpMaterialStreamWrite, _Z21RpMaterialStreamWritePK10RpMaterialP8RwStream, RpMaterial const*, RpMaterial const* material, RwStream* stream);
DECL_FASTCALL_SIMPLE_GLO(RpMaterialSetStreamRightsCallBack, _Z33RpMaterialSetStreamRightsCallBackjPFiPviijE, RwInt32, RwUInt32 pluginID, RwPluginDataChunkRightsCallBack rightsCB);
DECL_FASTCALL_SIMPLE_GLO(RpMaterialSetFreeListCreateParams, _Z33RpMaterialSetFreeListCreateParamsii, void, RwInt32 blockSize, RwInt32 numBlocksToPrealloc);
DECL_FASTCALL_SIMPLE_GLO(RpMaterialGetPluginOffset, _Z25RpMaterialGetPluginOffsetj, RwInt32, RwUInt32 pluginID);
DECL_FASTCALL_SIMPLE_GLO(RpMaterialRegisterPluginStream, _Z30RpMaterialRegisterPluginStreamjPFP8RwStreamS0_iPviiEPFS0_S0_iPKviiEPFiS5_iiE, RwInt32, RwUInt32 pluginID, RwPluginDataChunkReadCallBack readCB, RwPluginDataChunkWriteCallBack writeCB, RwPluginDataChunkGetSizeCallBack getSizeCB);
DECL_FASTCALL_SIMPLE_GLO(RpMaterialStreamGetSize, _Z23RpMaterialStreamGetSizePK10RpMaterial, RwUInt32, RpMaterial const* material);
DECL_FASTCALL_SIMPLE_GLO(RpMaterialStreamRead, _Z20RpMaterialStreamReadP8RwStream, RpMaterial*, RwStream* stream);
DECL_FASTCALL_SIMPLE_GLO(RpMaterialDestroy, _Z17RpMaterialDestroyP10RpMaterial, RwBool, RpMaterial* material);
DECL_FASTCALL_SIMPLE_GLO(RpMaterialValidatePlugins, _Z25RpMaterialValidatePluginsPK10RpMaterial, RwBool, RpMaterial const* material);
DECL_FASTCALL_SIMPLE_GLO(RpMaterialSetDefaultPipeline, _Z28RpMaterialSetDefaultPipelineP10RxPipeline, RxPipeline*, RxPipeline* pipeline);

#endif // __AML_PSDK_RPMATERIAL_H
