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


struct RpMaterialChunkInfo
{
    RwInt32 flags;
    RwRGBA color;
    RwInt32 unused;
    RwBool textured;
    RwSurfaceProperties surfaceProps;
};
CHECKSIZE(RpMaterial, 0x1C, 0x28);
CHECKSIZE(RpMaterialList, 0xC, 0x10);
CHECKSIZE(RpMaterialChunkInfo, 0x1C, 0x1C);

DECL_FASTCALL_SIMPLE_GLO(_rpMaterialSetDefaultSurfaceProperties, _Z38_rpMaterialSetDefaultSurfacePropertiesPK19RwSurfaceProperties, void, RwSurfaceProperties const* properties);
DECL_FASTCALL_SIMPLE_GLO(_rpMaterialOpen, _Z15_rpMaterialOpenPvii, void*, void* instance, RwInt32 offset, RwInt32 size);
DECL_FASTCALL_SIMPLE_GLO(_rpMaterialClose, _Z16_rpMaterialClosePvii, void*, void* instance, RwInt32 offset, RwInt32 size);
DECL_FASTCALL_SIMPLE_GLO(_rpMaterialRegisterMultiTexturePlugin, _Z37_rpMaterialRegisterMultiTexturePlugin12RwPlatformIDjj, RwBool, RwPlatformID platformID, RwUInt32 pluginID, RwUInt32 extensionSize);
DECL_FASTCALL_SIMPLE_GLO(_rpMaterialChunkInfoRead, _Z24_rpMaterialChunkInfoReadP8RwStreamP19RpMaterialChunkInfoPi, RpMaterialChunkInfo*, RwStream* stream, RpMaterialChunkInfo* info, RwInt32* bytesRead);
DECL_FASTCALL_SIMPLE_GLO(_rpMaterialListInitialize, _Z25_rpMaterialListInitializeP14RpMaterialList, RpMaterialList*, RpMaterialList* list);
DECL_FASTCALL_SIMPLE_GLO(_rpMaterialListDeinitialize, _Z27_rpMaterialListDeinitializeP14RpMaterialList, RpMaterialList*, RpMaterialList* list);
DECL_FASTCALL_SIMPLE_GLO(_rpMaterialListAlloc, _Z20_rpMaterialListAllocj, RpMaterial**, RwUInt32 count);
DECL_FASTCALL_SIMPLE_GLO(_rpMaterialListGetMaterial, _Z26_rpMaterialListGetMaterialPK14RpMaterialListi, RpMaterial*, RpMaterialList const* list, RwInt32 index);
DECL_FASTCALL_SIMPLE_GLO(_rpMaterialListSetSize, _Z22_rpMaterialListSetSizeP14RpMaterialListi, RpMaterialList*, RpMaterialList* list, RwInt32 size);
DECL_FASTCALL_SIMPLE_GLO(_rpMaterialListCopy, _Z19_rpMaterialListCopyP14RpMaterialListPKS_, RpMaterialList*, RpMaterialList* dest, RpMaterialList const* source);
DECL_FASTCALL_SIMPLE_GLO(_rpMaterialListAppendMaterial, _Z29_rpMaterialListAppendMaterialP14RpMaterialListP10RpMaterial, RwInt32, RpMaterialList* list, RpMaterial* material);
DECL_FASTCALL_SIMPLE_GLO(_rpMaterialListFindMaterialIndex, _Z32_rpMaterialListFindMaterialIndexPK14RpMaterialListPK10RpMaterial, RwInt32, RpMaterialList const* list, RpMaterial const* material);
DECL_FASTCALL_SIMPLE_GLO(_rpMaterialListStreamGetSize, _Z28_rpMaterialListStreamGetSizePK14RpMaterialList, RwUInt32, RpMaterialList const* list);
DECL_FASTCALL_SIMPLE_GLO(_rpMaterialListStreamRead, _Z25_rpMaterialListStreamReadP8RwStreamP14RpMaterialList, RpMaterialList*, RwStream* stream, RpMaterialList* list);
DECL_FASTCALL_SIMPLE_GLO(_rpMaterialListStreamWrite, _Z26_rpMaterialListStreamWritePK14RpMaterialListP8RwStream, RpMaterialList const*, RpMaterialList const* list, RwStream* stream);

inline RpMaterial* RpMaterialAddRef(RpMaterial* material)
{
    ++material->refCount;
    return material;
}

inline RwTexture* RpMaterialGetTexture(RpMaterial const* material)
{
    return material->texture;
}

inline RwRGBA const* RpMaterialGetColor(RpMaterial const* material)
{
    return &material->color;
}

inline RpMaterial* RpMaterialSetColor(RpMaterial* material, RwRGBA const* color)
{
    material->color = *color;
    return material;
}

inline RwSurfaceProperties const* RpMaterialGetSurfaceProperties(RpMaterial const* material)
{
    return &material->surfaceProps;
}

inline RpMaterial* RpMaterialSetSurfaceProperties(RpMaterial* material, RwSurfaceProperties const* properties)
{
    material->surfaceProps = *properties;
    return material;
}

inline RpMaterial* RpMaterialSetPipeline(RpMaterial* material, RxPipeline* pipeline)
{
    material->pipeline = pipeline;
    return material;
}

inline RpMaterial* RpMaterialGetPipeline(RpMaterial* material, RxPipeline** pipeline)
{
    *pipeline = material->pipeline;
    return material;
}
#endif // __AML_PSDK_RPMATERIAL_H
