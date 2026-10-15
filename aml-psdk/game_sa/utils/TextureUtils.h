#ifndef __AML_PSDK_SATEXTUREUTILS_H
#define __AML_PSDK_SATEXTUREUTILS_H

#include "../plugin.h"
#include <aml-psdk/renderware/RwTexture.h>
#include <aml-psdk/renderware/RwImage.h>
#include <aml-psdk/renderware/RwRaster.h>
#include <aml-psdk/renderware/RwRender.h>

struct TextureUtils
{
    static inline void SetFiltering(RwTexture* texture, RwTextureFilterMode filter)
    {
        if(texture) texture->filterAddressing = (texture->filterAddressing & ~0xFFU) | (u32)filter;
    }

    // Call on the render thread. The returned texture owns its raster; the image remains yours.
    static inline RwTexture* CreateFromImage(RwImage* image, const char* name = NULL, RwTextureFilterMode filter = rwFILTERLINEAR)
    {
        if(!image || !image->cpPixels || image->width <= 0 || image->height <= 0) return NULL;
        RwInt32 width, height, depth, format;
        if(!RwImageFindRasterFormat(image, rwRASTERTYPETEXTURE, &width, &height, &depth, &format)) return NULL;
        RwRaster* raster = RwRasterCreate(width, height, depth, format);
        if(!raster) return NULL;
        if(!RwRasterSetFromImage(raster, image))
        {
            RwRasterDestroy(raster);
            return NULL;
        }
        RwTexture* texture = RwTextureCreate(raster);
        if(!texture)
        {
            RwRasterDestroy(raster);
            return NULL;
        }
        if(name) RwTextureSetName(texture, name);
        SetFiltering(texture, filter);
        return texture;
    }

    static inline RwTexture* LoadFromFile(const char* filename, const char* name = NULL, RwTextureFilterMode filter = rwFILTERLINEAR)
    {
        if(!filename || !*filename) return NULL;
        RwImage* image = RwImageRead(filename);
        if(!image) return NULL;
        RwTexture* texture = CreateFromImage(image, name, filter);
        RwImageDestroy(image);
        return texture;
    }

    static inline RwTexture* LoadPNG(const char* filename, const char* name = NULL, RwTextureFilterMode filter = rwFILTERLINEAR)
    {
        if(!filename || !*filename) return NULL;
        RwImage* image = RtPNGImageRead(filename);
        if(!image) return NULL;
        RwTexture* texture = CreateFromImage(image, name, filter);
        RwImageDestroy(image);
        return texture;
    }

    // Call on the render thread. Destroy the returned image with RwImageDestroy.
    static inline RwImage* CreateImage(RwRaster* raster)
    {
        if(!raster || raster->width <= 0 || raster->height <= 0) return NULL;
        RwImage* image = RwImageCreate(raster->width, raster->height, 32);
        if(!image) return NULL;
        if(!RwImageAllocatePixels(image) || !RwImageSetFromRaster(image, raster))
        {
            RwImageDestroy(image);
            return NULL;
        }
        return image;
    }

    static inline RwImage* CreateImage(RwTexture* texture)
    {
        return texture ? CreateImage(texture->raster) : NULL;
    }

    static inline bool SavePNG(RwRaster* raster, const char* filename)
    {
        if(!filename || !*filename) return false;
        RwImage* image = CreateImage(raster);
        if(!image) return false;
        bool saved = RtPNGImageWrite(image, filename) != NULL;
        RwImageDestroy(image);
        return saved;
    }

    static inline bool SavePNG(RwTexture* texture, const char* filename)
    {
        return texture && SavePNG(texture->raster, filename);
    }

    // Dictionary lookups return borrowed textures.
    static inline RwTexture* FindTexture(RwTexDictionary* dict, const char* name)
    {
        return dict && name && *name ? RwTexDictionaryFindNamedTexture(dict, name) : NULL;
    }

    template<typename Fn>
    static inline void ForEachTexture(const RwTexDictionary* dict, Fn fn)
    {
        if(!dict) return;
        RwTexDictionaryForAllTextures(dict, [](RwTexture* texture, void* data) -> RwTexture*
        {
            (*(Fn*)data)(texture);
            return texture;
        }, &fn);
    }
};

#endif // __AML_PSDK_SATEXTUREUTILS_H
