#ifndef __AML_PSDK_SARENDERWAREUTILS_H
#define __AML_PSDK_SARENDERWAREUTILS_H

#include "../plugin.h"
#include <aml-psdk/renderware/RpClump.h>
#include <aml-psdk/renderware/RpAtomic.h>
#include <aml-psdk/renderware/RpGeometry.h>
#include <aml-psdk/renderware/RpHAnim.h>
#include "../anim/AnimBlendClumpData.h"
#include <cstring>

struct RenderWareUtils
{
    static inline RwFrame* FindFrame(RwFrame* root, const char* name)
    {
        if(!root || !name) return NULL;
        const char* frameName = GetFrameNodeName(root);
        if(frameName && !strcmp(frameName, name)) return root;
        for(RwFrame* child = root->child; child; child = child->next)
        {
            RwFrame* frame = FindFrame(child, name);
            if(frame) return frame;
        }
        return NULL;
    }

    static inline RpHAnimHierarchy* FindHierarchy(RwFrame* root)
    {
        if(!root) return NULL;
        RpHAnimHierarchy* hierarchy = RpHAnimFrameGetHierarchy(root);
        if(hierarchy) return hierarchy;
        for(RwFrame* child = root->child; child; child = child->next)
        {
            hierarchy = FindHierarchy(child);
            if(hierarchy) return hierarchy;
        }
        return NULL;
    }

    static inline RwMatrix* GetBoneMatrix(RpHAnimHierarchy* hierarchy, i32 boneId)
    {
        if(!hierarchy || hierarchy->numNodes <= 0 || !hierarchy->pNodeInfo) return NULL;
        i32 index = RpHAnimIDGetIndex(hierarchy, boneId);
        if(index < 0 || index >= hierarchy->numNodes) return NULL;
        RwMatrix* matrices = RpHAnimHierarchyGetMatrixArray(hierarchy);
        return matrices ? &matrices[index] : NULL;
    }

    static inline CAnimBlendClumpData* GetAnimData(RpClump* clump)
    {
        if(!clump) return NULL;
        i32 offset = ClumpOffset;
        return offset >= (i32)sizeof(RpClump) ? *(CAnimBlendClumpData**)((u8*)clump + offset) : NULL;
    }

    template<typename Fn>
    static inline void ForEachFrame(RwFrame* root, Fn&& fn)
    {
        if(!root) return;
        fn(root);
        for(RwFrame* child = root->child; child; child = child->next) ForEachFrame(child, fn);
    }

    template<typename Fn>
    static inline void ForEachAtomic(RpClump* clump, Fn fn)
    {
        if(!clump) return;
        RpClumpForAllAtomics(clump, [](RpAtomic* atomic, void* data) -> RpAtomic*
        {
            (*(Fn*)data)(atomic);
            return atomic;
        }, &fn);
    }

    template<typename Fn>
    static inline void ForEachMaterial(RpGeometry* geometry, Fn fn)
    {
        if(!geometry) return;
        RpGeometryForAllMaterials(geometry, [](RpMaterial* material, void* data) -> RpMaterial*
        {
            (*(Fn*)data)(material);
            return material;
        }, &fn);
    }

    template<typename Fn>
    static inline void ForEachMaterial(RpClump* clump, Fn fn)
    {
        ForEachAtomic(clump, [&fn](RpAtomic* atomic)
        {
            if(atomic) ForEachMaterial(atomic->geometry, [&fn](RpMaterial* material) { fn(material); });
        });
    }

    static inline u32 ReplaceTexture(RpGeometry* geometry, RwTexture* texture, RwTexture* replacement)
    {
        if(texture == replacement) return 0;
        u32 count = 0;
        ForEachMaterial(geometry, [&](RpMaterial* material)
        {
            if(material && material->texture == texture && RpMaterialSetTexture(material, replacement)) ++count;
        });
        return count;
    }

    static inline u32 ReplaceTexture(RpClump* clump, RwTexture* texture, RwTexture* replacement)
    {
        u32 count = 0;
        ForEachAtomic(clump, [&](RpAtomic* atomic)
        {
            if(atomic) count += ReplaceTexture(atomic->geometry, texture, replacement);
        });
        return count;
    }

    static inline u32 ReplaceTexture(RpGeometry* geometry, const char* name, RwTexture* replacement)
    {
        if(!name) return 0;
        char textureName[rwTEXTUREBASENAMELENGTH];
        strncpy(textureName, name, sizeof(textureName));
        u32 count = 0;
        ForEachMaterial(geometry, [&](RpMaterial* material)
        {
            if(material && material->texture && material->texture != replacement &&
               !strncmp(material->texture->name, textureName, sizeof(textureName)) &&
               RpMaterialSetTexture(material, replacement)) ++count;
        });
        return count;
    }

    static inline u32 ReplaceTexture(RpClump* clump, const char* name, RwTexture* replacement)
    {
        if(!name) return 0;
        char textureName[rwTEXTUREBASENAMELENGTH];
        strncpy(textureName, name, sizeof(textureName));
        u32 count = 0;
        ForEachAtomic(clump, [&](RpAtomic* atomic)
        {
            if(atomic) count += ReplaceTexture(atomic->geometry, textureName, replacement);
        });
        return count;
    }

    static inline void SetMaterialColor(RpGeometry* geometry, const RwRGBA& color)
    {
        if(!geometry) return;
        RpGeometrySetFlags(geometry, geometry->flags | rpGEOMETRYMODULATEMATERIALCOLOR);
        ForEachMaterial(geometry, [&](RpMaterial* material)
        {
            if(material) material->color = color;
        });
    }

    static inline void SetMaterialColor(RpClump* clump, const RwRGBA& color)
    {
        ForEachAtomic(clump, [&](RpAtomic* atomic)
        {
            if(atomic) SetMaterialColor(atomic->geometry, color);
        });
    }

    static inline void SetMaterialAlpha(RpGeometry* geometry, u8 alpha)
    {
        if(!geometry) return;
        RpGeometrySetFlags(geometry, geometry->flags | rpGEOMETRYMODULATEMATERIALCOLOR);
        ForEachMaterial(geometry, [alpha](RpMaterial* material)
        {
            if(material) material->color.alpha = alpha;
        });
    }

    static inline void SetMaterialAlpha(RpClump* clump, u8 alpha)
    {
        ForEachAtomic(clump, [alpha](RpAtomic* atomic)
        {
            if(atomic) SetMaterialAlpha(atomic->geometry, alpha);
        });
    }
};

#endif // __AML_PSDK_SARENDERWAREUTILS_H
