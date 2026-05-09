#ifndef __AML_PSDK_RPMATERIAL_H
#define __AML_PSDK_RPMATERIAL_H

#include <aml-psdk/sdk_base.h>
#include "RwBase.h"
#include "RwTexture.h"
#include "RwRGBA.h"

struct RxPipeline;

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

DECL_FASTCALL_SIMPLE_GLO(RpMaterialCreateMultiTexture, _Z28RpMaterialCreateMultiTextureP10RpMaterial12RwPlatformIDj, RpMaterial*, RpMaterial* material, RwPlatformID platformID, RwUInt32 numTextures);
DECL_FASTCALL_SIMPLE_GLO(RpMaterialDestroyMultiTexture, _Z29RpMaterialDestroyMultiTextureP10RpMaterial12RwPlatformID, RpMaterial*, RpMaterial* material, RwPlatformID platformID);
DECL_FASTCALL_SIMPLE_GLO(RpMaterialGetMultiTexture, _Z25RpMaterialGetMultiTexturePK10RpMaterial12RwPlatformID, RpMultiTexture*, const RpMaterial* material, RwPlatformID platformID);
DECL_FASTCALL_SIMPLE_GLO(RpMaterialQueryMultiTexturePlatform, _Z35RpMaterialQueryMultiTexturePlatform12RwPlatformID, RwBool, RwPlatformID platformID);

#endif // __AML_PSDK_RPMATERIAL_H