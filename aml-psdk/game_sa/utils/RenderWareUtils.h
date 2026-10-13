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
};

#endif // __AML_PSDK_SARENDERWAREUTILS_H
