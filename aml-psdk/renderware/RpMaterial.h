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

DECL_FASTCALL_SIMPLE_GLO(RpMaterialCreateMultiTexture, _Z28RpMaterialCreateMultiTextureP10RpMaterial12RwPlatformIDj, RpMaterial*, RpMaterial* material, RwPlatformID platformID, RwUInt32 numTextures);
DECL_FASTCALL_SIMPLE_GLO(RpMaterialDestroyMultiTexture, _Z29RpMaterialDestroyMultiTextureP10RpMaterial12RwPlatformID, RpMaterial*, RpMaterial* material, RwPlatformID platformID);
DECL_FASTCALL_SIMPLE_GLO(RpMaterialGetMultiTexture, _Z25RpMaterialGetMultiTexturePK10RpMaterial12RwPlatformID, RpMultiTexture*, const RpMaterial* material, RwPlatformID platformID);
DECL_FASTCALL_SIMPLE_GLO(RpMaterialQueryMultiTexturePlatform, _Z35RpMaterialQueryMultiTexturePlatform12RwPlatformID, RwBool, RwPlatformID platformID);

#endif // __AML_PSDK_RPMATERIAL_H