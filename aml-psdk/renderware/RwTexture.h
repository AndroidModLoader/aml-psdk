#ifndef __AML_PSDK_RWTEXTURE_H
#define __AML_PSDK_RWTEXTURE_H

#include <aml-psdk/sdk_base.h>
#include "RwBase.h"
#include "RwLinks.h"
#include "RwRender.h"

#define rwTEXTUREBASENAMELENGTH 32

#include "RwObject.h"

struct RwRaster;
struct RwStream;
struct RwImage;

struct RwTexDictionary
{
    RwObject   object;
    RwLinkList texturesInDict;
    RwLLLink   lInInstance; /* Node in the global list of dictionaries */
};

struct RwTexture
{
    RwRaster           *raster; /** pointer to RwRaster with data */
    RwTexDictionary    *dict;   /* Dictionary this texture is in */
    RwLLLink            lInDictionary; /* List of textures in this dictionary */

    char                name[rwTEXTUREBASENAMELENGTH];  /* Name of the texture */
    char                mask[rwTEXTUREBASENAMELENGTH];  /* Name of the textures mask */

    /* 31 [xxxxxxxx xxxxxxxx vvvvuuuu ffffffff] 0 */
    RwUInt32            filterAddressing; /* Filtering & addressing mode flags */

    RwInt32             refCount; /* Reference count, surprisingly enough */
};

typedef RwTexture *(*RwTextureCallBackFind)(const char *);
typedef RwRaster *(*RwTextureCallBackMipmapGeneration)(RwRaster *, RwImage *);
typedef RwBool (*RwTextureCallBackMipmapName)(RwChar *, RwChar *, RwUInt8, RwInt32);
typedef RwTexture *(*RwTextureCallBackRead)(const char *, const char *);
typedef RwTexture *(*RwTextureCallBack)(RwTexture *, void *);
typedef RwTexDictionary *(*RwTexDictionaryCallBack)(RwTexDictionary *, void *);

DECL_FASTCALL_SIMPLE_GLO(RwTextureCreate, _Z15RwTextureCreateP8RwRaster, RwTexture*, RwRaster *);
DECL_FASTCALL_SIMPLE_GLO(RwTextureDestroy, _Z16RwTextureDestroyP9RwTexture, RwBool, RwTexture *);
DECL_FASTCALL_SIMPLE_GLO(RwTextureGenerateMipmapName, _Z27RwTextureGenerateMipmapNamePcS_hi, RwBool, char *,char *,u8,int);
DECL_FASTCALL_SIMPLE_GLO(RwTextureGetAutoMipmapping, _Z26RwTextureGetAutoMipmappingv, RwBool);
DECL_FASTCALL_SIMPLE_GLO(RwTextureGetFindCallBack, _Z24RwTextureGetFindCallBackv, RwTextureCallBackFind);
DECL_FASTCALL_SIMPLE_GLO(RwTextureGetMipmapGenerationCallBack, _Z36RwTextureGetMipmapGenerationCallBackv, RwTextureCallBackMipmapGeneration);
DECL_FASTCALL_SIMPLE_GLO(RwTextureGetMipmapNameCallBack, _Z30RwTextureGetMipmapNameCallBackv, RwTextureCallBackMipmapName);
DECL_FASTCALL_SIMPLE_GLO(RwTextureGetMipmapping, _Z22RwTextureGetMipmappingv, RwBool);
DECL_FASTCALL_SIMPLE_GLO(RwTextureGetPluginOffset, _Z24RwTextureGetPluginOffsetj, RwInt32, uint);
DECL_FASTCALL_SIMPLE_GLO(RwTextureGetReadCallBack, _Z24RwTextureGetReadCallBackv, RwTextureCallBackRead);
DECL_FASTCALL_SIMPLE_GLO(RwTextureGtaStreamRead, _Z22RwTextureGtaStreamReadP8RwStream, RwTexture*, RwStream *);
DECL_FASTCALL_SIMPLE_GLO(RwTextureRasterGenerateMipmaps, _Z30RwTextureRasterGenerateMipmapsP8RwRasterP7RwImage, RwBool, RwRaster *,RwImage *);
DECL_FASTCALL_SIMPLE_GLO(RwTextureRead, _Z13RwTextureReadPKcS0_, RwTexture*, char const*, char const*);
DECL_FASTCALL_SIMPLE_GLO(RwTextureRegisterPlugin, _Z23RwTextureRegisterPluginijPFPvS_iiES1_PFS_S_PKviiE, RwInt32,
    int, uint, RwPluginObjectConstructor, RwPluginObjectDestructor, RwPluginObjectCopy);
DECL_FASTCALL_SIMPLE_GLO(RwTextureRegisterPluginStream, _Z29RwTextureRegisterPluginStreamjPFP8RwStreamS0_iPviiEPFS0_S0_iPKviiEPFiS5_iiE, RwInt32,
    uint, RwPluginDataChunkReadCallBack, RwPluginDataChunkWriteCallBack, RwPluginDataChunkGetSizeCallBack);
DECL_FASTCALL_SIMPLE_GLO(RwTextureSetAutoMipmapping, _Z26RwTextureSetAutoMipmappingi, RwBool, int);
DECL_FASTCALL_SIMPLE_GLO(RwTextureSetFindCallBack, _Z24RwTextureSetFindCallBackPFP9RwTexturePKcE, RwBool, RwTextureCallBackFind);
DECL_FASTCALL_SIMPLE_GLO(RwTextureSetFreeListCreateParams, _Z32RwTextureSetFreeListCreateParamsii, void, int,int);
DECL_FASTCALL_SIMPLE_GLO(RwTextureSetMaskName, _Z20RwTextureSetMaskNameP9RwTexturePKc, RwTexture*, RwTexture *,char const*);
DECL_FASTCALL_SIMPLE_GLO(RwTextureSetMipmapGenerationCallBack, _Z36RwTextureSetMipmapGenerationCallBackPFP8RwRasterS0_P7RwImageE, RwBool, RwTextureCallBackMipmapGeneration);
DECL_FASTCALL_SIMPLE_GLO(RwTextureSetMipmapNameCallBack, _Z30RwTextureSetMipmapNameCallBackPFiPcS_hiE, RwBool, RwTextureCallBackMipmapName);
DECL_FASTCALL_SIMPLE_GLO(RwTextureSetMipmapping, _Z22RwTextureSetMipmappingi, RwBool, int);
DECL_FASTCALL_SIMPLE_GLO(RwTextureSetName, _Z16RwTextureSetNameP9RwTexturePKc, RwTexture*, RwTexture *,char const*);
DECL_FASTCALL_SIMPLE_GLO(RwTextureSetRaster, _Z18RwTextureSetRasterP9RwTextureP8RwRaster, RwTexture*, RwTexture *,RwRaster *);
DECL_FASTCALL_SIMPLE_GLO(RwTextureSetReadCallBack, _Z24RwTextureSetReadCallBackPFP9RwTexturePKcS2_E, RwBool, RwTextureCallBackRead);
DECL_FASTCALL_SIMPLE_GLO(RwTextureSetStreamAlwaysCallBack, _Z32RwTextureSetStreamAlwaysCallBackjPFiPviiE, RwInt32, uint, RwPluginDataChunkAlwaysCallBack);
DECL_FASTCALL_SIMPLE_GLO(RwTextureStreamGetSize, _Z22RwTextureStreamGetSizePK9RwTexture, RwUInt32, RwTexture const*);
DECL_FASTCALL_SIMPLE_GLO(RwTextureStreamRead, _Z19RwTextureStreamReadP8RwStream, RwTexture*, RwStream *);
DECL_FASTCALL_SIMPLE_GLO(RwTextureStreamWrite, _Z20RwTextureStreamWritePK9RwTextureP8RwStream, const RwTexture*, RwTexture const*,RwStream *);
DECL_FASTCALL_SIMPLE_GLO(RwTextureValidatePlugins, _Z24RwTextureValidatePluginsPK9RwTexture, RwBool, RwTexture const*);

DECL_FASTCALL_SIMPLE_GLO(RwTexDictionaryCreate, _Z21RwTexDictionaryCreatev, RwTexDictionary*);
DECL_FASTCALL_SIMPLE_GLO(RwTexDictionaryDestroy, _Z22RwTexDictionaryDestroyP15RwTexDictionary, RwBool, RwTexDictionary* dict);
DECL_FASTCALL_SIMPLE_GLO(RwTexDictionaryAddTexture, _Z25RwTexDictionaryAddTextureP15RwTexDictionaryP9RwTexture, RwTexture*, RwTexDictionary* dict, RwTexture* texture);
DECL_FASTCALL_SIMPLE_GLO(RwTexDictionaryRemoveTexture, _Z28RwTexDictionaryRemoveTextureP9RwTexture, RwTexture*, RwTexture* texture);
DECL_FASTCALL_SIMPLE_GLO(RwTexDictionaryFindNamedTexture, _Z31RwTexDictionaryFindNamedTextureP15RwTexDictionaryPKc, RwTexture*, RwTexDictionary* dict, const char* name);
DECL_FASTCALL_SIMPLE_GLO(RwTexDictionaryFindHashNamedTexture, _Z35RwTexDictionaryFindHashNamedTextureP15RwTexDictionaryj, RwTexture*, RwTexDictionary* dict, RwUInt32 key);
DECL_FASTCALL_SIMPLE_GLO(RwTexDictionaryGetNumTextures, _Z29RwTexDictionaryGetNumTexturesP15RwTexDictionary, RwInt32, RwTexDictionary* dict);
DECL_FASTCALL_SIMPLE_GLO(RwTexDictionaryGetTextureByIndex, _Z32RwTexDictionaryGetTextureByIndexP15RwTexDictionaryi, RwTexture*, RwTexDictionary* dict, RwInt32 index);
DECL_FASTCALL_SIMPLE_GLO(RwTexDictionaryGetCurrent, _Z25RwTexDictionaryGetCurrentv, RwTexDictionary*);
DECL_FASTCALL_SIMPLE_GLO(RwTexDictionarySetCurrent, _Z25RwTexDictionarySetCurrentP15RwTexDictionary, RwTexDictionary*, RwTexDictionary* dict);
DECL_FASTCALL_SIMPLE_GLO(RwTexDictionaryForAllTextures, _Z29RwTexDictionaryForAllTexturesPK15RwTexDictionaryPFP9RwTextureS3_PvES4_, const RwTexDictionary*,
    const RwTexDictionary* dict, RwTextureCallBack callback, void* data);
DECL_FASTCALL_SIMPLE_GLO(RwTexDictionaryForAllTexDictionaries, _Z36RwTexDictionaryForAllTexDictionariesPFP15RwTexDictionaryS0_PvES1_, RwBool,
    RwTexDictionaryCallBack callback, void* data);
DECL_FASTCALL_SIMPLE_GLO(RwTexDictionaryStreamRead, _Z25RwTexDictionaryStreamReadP8RwStream, RwTexDictionary*, RwStream* stream);
DECL_FASTCALL_SIMPLE_GLO(RwTexDictionaryStreamWrite, _Z26RwTexDictionaryStreamWritePK15RwTexDictionaryP8RwStream, const RwTexDictionary*, const RwTexDictionary* dict, RwStream* stream);
DECL_FASTCALL_SIMPLE_GLO(RwTexDictionaryStreamGetSize, _Z28RwTexDictionaryStreamGetSizePK15RwTexDictionary, RwUInt32, const RwTexDictionary* dict);
DECL_FASTCALL_SIMPLE_GLO(RwTexDictionaryGtaStreamRead, _Z28RwTexDictionaryGtaStreamReadP8RwStream, RwTexDictionary*, RwStream* stream);

DECL_FASTCALL_SIMPLE_GLO(RwTexDictionaryRegisterPluginStream, _Z35RwTexDictionaryRegisterPluginStreamjPFP8RwStreamS0_iPviiEPFS0_S0_iPKviiEPFiS5_iiE, RwInt32, RwUInt32 pluginID, RwPluginDataChunkReadCallBack readCB, RwPluginDataChunkWriteCallBack writeCB, RwPluginDataChunkGetSizeCallBack getSizeCB);

DECL_FASTCALL_SIMPLE_GLO(RwTexDictionarySetStreamAlwaysCallBack, _Z38RwTexDictionarySetStreamAlwaysCallBackjPFiPviiE, RwInt32, RwUInt32 pluginID, RwPluginDataChunkAlwaysCallBack alwaysCB);

DECL_FASTCALL_SIMPLE_GLO(RwTexDictionaryGetPluginOffset, _Z30RwTexDictionaryGetPluginOffsetj, RwInt32, RwUInt32 pluginID);

DECL_FASTCALL_SIMPLE_GLO(RwTexDictionaryRegisterPlugin, _Z29RwTexDictionaryRegisterPluginijPFPvS_iiES1_PFS_S_PKviiE, RwInt32, RwInt32 size, RwUInt32 pluginID, RwPluginObjectConstructor constructCB, RwPluginObjectDestructor destructCB, RwPluginObjectCopy copyCB);

DECL_FASTCALL_SIMPLE_GLO(RwTexDictionarySetFreeListCreateParams, _Z38RwTexDictionarySetFreeListCreateParamsii, void, RwInt32 blockSize, RwInt32 numBlocksToPrealloc);

DECL_FASTCALL_SIMPLE_GLO(RwTexDictionaryValidatePlugins, _Z30RwTexDictionaryValidatePluginsPK15RwTexDictionary, RwBool, RwTexDictionary const* dict);

DECL_FASTCALL_SIMPLE_GLO(RwTexDictionaryGtaStreamRead1, _Z29RwTexDictionaryGtaStreamRead1P8RwStream, RwTexDictionary*, RwStream* pStream);

DECL_FASTCALL_SIMPLE_GLO(RwTexDictionaryGtaStreamRead2, _Z29RwTexDictionaryGtaStreamRead2P8RwStreamP15RwTexDictionary, RwTexDictionary*, RwStream* pStream, RwTexDictionary* texDict);

inline RwRaster* RwTextureGetRaster(const RwTexture* texture)
{
    return texture->raster;
}

inline RwChar* RwTextureGetName(RwTexture* texture)
{
    return texture->name;
}

inline RwChar* RwTextureGetMaskName(RwTexture* texture)
{
    return texture->mask;
}

inline RwTexDictionary* RwTextureGetDictionary(RwTexture* texture)
{
    return texture->dict;
}

inline RwTexture* RwTextureAddRef(RwTexture* texture)
{
    ++texture->refCount;
    return texture;
}

inline RwTexture* RwTextureSetFilterMode(RwTexture* texture, RwTextureFilterMode filter)
{
    texture->filterAddressing = (texture->filterAddressing & ~0xFFU) | ((RwUInt32)filter & 0xFFU);
    return texture;
}

inline RwTextureFilterMode RwTextureGetFilterMode(const RwTexture* texture)
{
    return (RwTextureFilterMode)(texture->filterAddressing & 0xFFU);
}

inline RwTexture* RwTextureSetAddressingU(RwTexture* texture, RwTextureAddressMode address)
{
    texture->filterAddressing = (texture->filterAddressing & ~0xF00U) | (((RwUInt32)address << 8) & 0xF00U);
    return texture;
}

inline RwTextureAddressMode RwTextureGetAddressingU(const RwTexture* texture)
{
    return (RwTextureAddressMode)((texture->filterAddressing >> 8) & 0xFU);
}

inline RwTexture* RwTextureSetAddressingV(RwTexture* texture, RwTextureAddressMode address)
{
    texture->filterAddressing = (texture->filterAddressing & ~0xF000U) | (((RwUInt32)address << 12) & 0xF000U);
    return texture;
}

inline RwTextureAddressMode RwTextureGetAddressingV(const RwTexture* texture)
{
    return (RwTextureAddressMode)((texture->filterAddressing >> 12) & 0xFU);
}

inline RwTexture* RwTextureSetAddressing(RwTexture* texture, RwTextureAddressMode address)
{
    texture->filterAddressing = (texture->filterAddressing & ~0xFF00U) | (((RwUInt32)address << 8) & 0xF00U) | (((RwUInt32)address << 12) & 0xF000U);
    return texture;
}

inline RwTextureAddressMode RwTextureGetAddressing(const RwTexture* texture)
{
    RwTextureAddressMode addressU = RwTextureGetAddressingU(texture);
    return addressU == RwTextureGetAddressingV(texture) ? addressU : rwTEXTUREADDRESSNATEXTUREADDRESS;
}

#endif // __AML_PSDK_RWTEXTURE_H
