#ifndef __AML_PSDK_SAANIMATIONUTILS_H
#define __AML_PSDK_SAANIMATIONUTILS_H

#include "../anim/AnimManager.h"
#include "../entity/Ped.h"
#include <cstring>

struct AnimationUtils
{
private:
    static inline bool ReadIFPInfo(RwStream* stream, char (&name)[24], u32& numAnims)
    {
        struct ChunkHeader
        {
            char id[4];
            u32 size;
        } header;

        if(RwStreamRead(stream, &header, sizeof(header)) != sizeof(header)) return false;
        if(!memcmp(header.id, "ANP2", 4) || !memcmp(header.id, "ANP3", 4))
        {
            return RwStreamRead(stream, name, sizeof(name)) == sizeof(name) &&
                RwStreamRead(stream, &numAnims, sizeof(numAnims)) == sizeof(numAnims);
        }
        if(memcmp(header.id, "ANPK", 4)) return false;
        if(RwStreamRead(stream, &header, sizeof(header)) != sizeof(header) || memcmp(header.id, "INFO", 4)) return false;
        if(header.size <= sizeof(numAnims) || header.size > sizeof(numAnims) + sizeof(name)) return false;
        u32 nameSize = header.size - sizeof(numAnims);
        return RwStreamRead(stream, &numAnims, sizeof(numAnims)) == sizeof(numAnims) &&
            RwStreamRead(stream, name, nameSize) == nameSize;
    }

public:
    // Call on the game thread after CAnimManager is initialised. Keep the returned block until UnloadIFP succeeds.
    // A reload must use a block returned here, with the same internal name and animation count.
    static inline CAnimBlock* LoadIFP(const char* filename, bool compress = true, CAnimBlock* reload = NULL)
    {
        if(!filename || !*filename || (reload && (reload->bLoaded || reload->usRefs))) return NULL;
        RwStream* stream = RwStreamOpen(rwSTREAMFILENAME, rwSTREAMREAD, filename);
        if(!stream) return NULL;
        char name[24] = {};
        u32 numAnims = 0;
        bool valid = ReadIFPInfo(stream, name, numAnims);
        RwStreamClose(stream, NULL);
        if(!valid || !*name || !memchr(name, 0, sizeof(CAnimBlock::szName)) || !numAnims) return NULL;

        CAnimBlock* block = CAnimManager::GetAnimationBlock(name);
        if(block != reload || (reload && numAnims != (u32)reload->animationCount)) return NULL;
        // Stock manager capacities; existing blocks are never overwritten.
        if(!reload && (CAnimManager::ms_numAnimBlocks >= 180 || numAnims > 2500 ||
            CAnimManager::ms_numAnimations > 2500 - (i32)numAnims)) return NULL;

        stream = RwStreamOpen(rwSTREAMFILENAME, rwSTREAMREAD, filename);
        if(!stream) return NULL;
        CAnimManager::LoadAnimFile(stream, compress, NULL);
        RwStreamClose(stream, NULL);
        block = CAnimManager::GetAnimationBlock(name);
        if(!block || !block->bLoaded) return NULL;
        CAnimManager::AddAnimBlockRef(CAnimManager::GetAnimationBlockIndex(name));
        return block;
    }

    static inline CAnimBlendHierarchy* FindAnimation(CAnimBlock* block, const char* name)
    {
        return block && block->bLoaded && name && *name ? CAnimManager::GetAnimation(name, block) : NULL;
    }

    // A model clump needs a compatible skeleton and RpAnimBlendClumpInit before playing.
    static inline CAnimBlendAssociation* Play(RpClump* clump, CAnimBlock* block, const char* name,
        float blendDelta = 4.0f, i32 flags = ANIMATION_STARTED | ANIMATION_FINISH_AUTO_REMOVE)
    {
        if(!clump || !RpAnimBlendClumpIsInitialized(clump) || !(blendDelta > 0.0f)) return NULL;
        CAnimBlendHierarchy* hierarchy = FindAnimation(block, name);
        if(!hierarchy) return NULL;
        return CAnimManager::BlendAnimation(clump, hierarchy, flags & ~ANIMATION_BLOCK_REFERENCED, blendDelta);
    }

    static inline CAnimBlendAssociation* Play(CPed* ped, CAnimBlock* block, const char* name,
        float blendDelta = 4.0f, i32 flags = ANIMATION_STARTED | ANIMATION_FINISH_AUTO_REMOVE)
    {
        return ped ? Play(ped->m_pRwClump, block, name, blendDelta, flags) : NULL;
    }

    static inline void FadeOut(CAnimBlendAssociation* association, float blendDelta = 4.0f)
    {
        if(!association || !(blendDelta > 0.0f)) return;
        association->m_nFlags |= ANIMATION_BLEND_AUTO_REMOVE;
        association->m_fBlendDelta = -blendDelta;
    }

    // Returns false while associations still reference this block. The game keeps its slots reserved for reload.
    static inline bool UnloadIFP(CAnimBlock* block)
    {
        if(!block || !block->bLoaded) return false;
        i32 index = CAnimManager::GetAnimationBlockIndex(block->szName);
        if(index < 0 || CAnimManager::GetAnimationBlock(index) != block || CAnimManager::GetNumRefsToAnimBlock(index) != 1) return false;
        CAnimManager::RemoveAnimBlock(index);
        return true;
    }
};

#endif // __AML_PSDK_SAANIMATIONUTILS_H
