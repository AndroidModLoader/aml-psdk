#ifndef __AML_PSDK_SAPEDANIMATIONUTILS_H
#define __AML_PSDK_SAPEDANIMATIONUTILS_H

#include "AnimationUtils.h"
#include "../../renderware/RpClump.h"
#include <unordered_map>
#include <cfloat>

struct PedAnimationUtils
{
private:
    struct PedAnimations
    {
        CPed* ped;
        CAnimBlock* original;
        CAnimBlock* replacement;
        i32 originalIndex;
        i32 replacementIndex;
    };

    static inline std::unordered_map<RpClump*, PedAnimations> m_peds;
    static inline bool m_bInstalled = false;
    static inline u32 m_nUpdateDepth = 0;

    static inline PedAnimations* Find(RpClump* clump)
    {
        if(m_peds.empty()) return NULL;
        auto it = m_peds.find(clump);
        return it != m_peds.end() ? &it->second : NULL;
    }

    static inline CAnimBlendHierarchy* FindReplacement(RpClump* clump, CAnimBlendHierarchy* hierarchy)
    {
        PedAnimations* anims = Find(clump);
        if(!anims || !hierarchy || hierarchy->m_nAnimBlockId != anims->originalIndex) return hierarchy;
        CAnimBlendHierarchy* replacement = CAnimManager::GetAnimation(hierarchy->m_hashKey, anims->replacement);
        return replacement ? replacement : hierarchy;
    }

    static inline void Rebind(RpClump* clump, CAnimBlendAssociation* association, CAnimBlendHierarchy* hierarchy)
    {
        if(!association || !hierarchy || association->m_pHierarchy == hierarchy) return;
        CAnimBlendHierarchy* original = association->m_pHierarchy;
        float phase = original && original->m_fTotalTime > 0.0f ? association->m_fCurrentTime / original->m_fTotalTime : 0.0f;
        if(!(phase >= 0.0f)) phase = 0.0f;
        if(phase > 1.0f) phase = 1.0f;

        CAnimManager::UncompressAnimation(hierarchy);
        CAnimBlendAssociation replacement(clump, hierarchy);
        replacement.m_nFlags = association->m_nFlags & ~ANIMATION_BLOCK_REFERENCED;
        if(hierarchy->m_fTotalTime > 0.0f) replacement.SetCurrentTime(phase * hierarchy->m_fTotalTime);

        // Keep the live association: tasks and callbacks can hold its address.
        CAnimBlendNode* nodes = association->m_pNodeArray;
        association->m_pNodeArray = replacement.m_pNodeArray;
        replacement.m_pNodeArray = nodes;
        association->m_nNumBlendNodes = replacement.m_nNumBlendNodes;
        association->m_fCurrentTime = replacement.m_fCurrentTime;
        association->m_pHierarchy = hierarchy;
        for(i32 i = 0; i < association->m_nNumBlendNodes; ++i)
            association->m_pNodeArray[i].m_pAnimBlendAssociation = association;

        bool referenced = association->m_nFlags & ANIMATION_BLOCK_REFERENCED;
        association->m_nFlags &= ~ANIMATION_BLOCK_REFERENCED;
        association->ReferenceAnimBlock();
        if(referenced && original) CAnimManager::RemoveAnimBlockRef(original->m_nAnimBlockId);
    }

    static inline CAnimBlendAssociation* Replace(RpClump* clump, CAnimBlendAssociation* association)
    {
        if(association) Rebind(clump, association, FindReplacement(clump, association->m_pHierarchy));
        return association;
    }

    static inline void ReplaceAll(RpClump* clump)
    {
        PedAnimations* anims = Find(clump);
        if(!anims) return;
        for(CAnimBlendAssociation* association = RpAnimBlendClumpGetFirstAssociation(clump); association;
            association = RpAnimBlendGetNextAssociation(association))
        {
            CAnimBlendHierarchy* hierarchy = association->m_pHierarchy;
            if(hierarchy && hierarchy->m_nAnimBlockId == anims->originalIndex)
                Rebind(clump, association, CAnimManager::GetAnimation(hierarchy->m_hashKey, anims->replacement));
        }
    }

    static inline decltype(CAnimManager::AddAnimation1) m_pAddAnimation = NULL;
    static CAnimBlendAssociation* AddAnimation(RpClump* clump, AssocGroupId group, AnimationId id)
    {
        return Replace(clump, m_pAddAnimation(clump, group, id));
    }

    static inline decltype(CAnimManager::BlendAnimation1) m_pBlendAnimation = NULL;
    static CAnimBlendAssociation* BlendAnimation(RpClump* clump, AssocGroupId group, AnimationId id, float delta)
    {
        return Replace(clump, m_pBlendAnimation(clump, group, id, delta));
    }

    static inline decltype(CAnimManager::AddAnimationAndSync) m_pAddAnimationAndSync = NULL;
    static CAnimBlendAssociation* AddAnimationAndSync(RpClump* clump, CAnimBlendAssociation* sync, AssocGroupId group, AnimationId id)
    {
        return Replace(clump, m_pAddAnimationAndSync(clump, sync, group, id));
    }

    static inline decltype(CAnimManager::AddAnimation2) m_pAddHierarchy = NULL;
    static CAnimBlendAssociation* AddHierarchy(RpClump* clump, CAnimBlendHierarchy* hierarchy, i32 flags)
    {
        return m_pAddHierarchy(clump, FindReplacement(clump, hierarchy), flags);
    }

    static inline decltype(CAnimManager::BlendAnimation2) m_pBlendHierarchy = NULL;
    static CAnimBlendAssociation* BlendHierarchy(RpClump* clump, CAnimBlendHierarchy* hierarchy, i32 flags, float delta)
    {
        return m_pBlendHierarchy(clump, FindReplacement(clump, hierarchy), flags, delta);
    }

    static inline decltype(RpAnimBlendClumpGiveAssociations) m_pGiveAssociations = NULL;
    static void GiveAssociations(RpClump* clump, CAnimBlendAssociation* association)
    {
        m_pGiveAssociations(clump, association);
        ReplaceAll(clump);
    }

    static inline decltype(RpAnimBlendClumpUpdateAnimations) m_pUpdateAnimations = NULL;
    static void UpdateAnimations(RpClump* clump, float timeStep, bool onScreen)
    {
        ++m_nUpdateDepth;
        ReplaceAll(clump);
        m_pUpdateAnimations(clump, timeStep, onScreen);
        --m_nUpdateDepth;
    }

    static inline decltype(RpClumpDestroy) m_pClumpDestroy = NULL;
    static RwBool ClumpDestroy(RpClump* clump)
    {
        auto it = m_peds.find(clump);
        if(it != m_peds.end())
        {
            CAnimManager::RemoveAnimBlockRef(it->second.replacementIndex);
            CAnimManager::RemoveAnimBlockRef(it->second.originalIndex);
            m_peds.erase(it);
        }
        return m_pClumpDestroy(clump);
    }

    static inline decltype(CAnimManager::Shutdown) m_pShutdown = NULL;
    static void Shutdown()
    {
        for(auto& entry : m_peds)
        {
            CAnimManager::RemoveAnimBlockRef(entry.second.replacementIndex);
            CAnimManager::RemoveAnimBlockRef(entry.second.originalIndex);
        }
        m_peds.clear();
        m_pShutdown();
    }

    template<typename Fn>
    static inline bool Hook(Fn& original, Fn detour, const char* symbol)
    {
        if(original) return true;
        void* address = GetMainLibrarySymbol(symbol);
        void* trampoline = NULL;
        if(!address || !aml->Hook(address, (void*)detour, &trampoline)) return false;
        original = (Fn)trampoline;
        return original != NULL;
    }

    static inline bool Install()
    {
        if(m_bInstalled) return true;
        if(!Hook(m_pClumpDestroy, ClumpDestroy, "_Z14RpClumpDestroyP7RpClump") ||
            !Hook(m_pShutdown, Shutdown, "_ZN12CAnimManager8ShutdownEv") ||
            !Hook(m_pAddAnimation, AddAnimation, "_ZN12CAnimManager12AddAnimationEP7RpClump12AssocGroupId11AnimationId") ||
            !Hook(m_pBlendAnimation, BlendAnimation, "_ZN12CAnimManager14BlendAnimationEP7RpClump12AssocGroupId11AnimationIdf") ||
            !Hook(m_pAddAnimationAndSync, AddAnimationAndSync, "_ZN12CAnimManager19AddAnimationAndSyncEP7RpClumpP21CAnimBlendAssociation12AssocGroupId11AnimationId") ||
            !Hook(m_pAddHierarchy, AddHierarchy, "_ZN12CAnimManager12AddAnimationEP7RpClumpP19CAnimBlendHierarchyi") ||
            !Hook(m_pBlendHierarchy, BlendHierarchy, "_ZN12CAnimManager14BlendAnimationEP7RpClumpP19CAnimBlendHierarchyif") ||
            !Hook(m_pGiveAssociations, GiveAssociations, "_Z32RpAnimBlendClumpGiveAssociationsP7RpClumpP21CAnimBlendAssociation") ||
            !Hook(m_pUpdateAnimations, UpdateAnimations, "_Z32RpAnimBlendClumpUpdateAnimationsP7RpClumpfb")) return false;
        m_bInstalled = true;
        return true;
    }

public:
    // Game thread, outside animation callbacks. The block needs every ped.ifp clip, with its original name.
    // Hooks are installed on first use. Deleting the clump clears the override.
    static inline bool Set(CPed* ped, CAnimBlock* block)
    {
        if(m_nUpdateDepth || !ped || !ped->m_pRwClump || !block || !block->bLoaded || !RpAnimBlendClumpIsInitialized(ped->m_pRwClump)) return false;
        CAnimBlock* original = CAnimManager::GetAnimationBlock("ped");
        if(!original || !original->bLoaded || original == block || original->animationCount <= 0) return false;
        i32 originalIndex = CAnimManager::GetAnimationBlockIndex("ped");
        i32 index = CAnimManager::GetAnimationBlockIndex(block->szName);
        if(originalIndex < 0 || index < 0 || CAnimManager::GetAnimationBlock(index) != block) return false;
        PedAnimations* active = Find(ped->m_pRwClump);
        if(active && active->ped != ped) return false;
        if(active && active->replacement == block) return true;
        for(i32 i = 0; i < original->animationCount; ++i)
        {
            CAnimBlendHierarchy* hierarchy = CAnimManager::GetAnimation(original->startAnimation + i);
            CAnimBlendHierarchy* replacement = CAnimManager::GetAnimation(hierarchy->m_hashKey, block);
            if(!replacement || !(replacement->m_fTotalTime > 0.0f) || replacement->m_fTotalTime > FLT_MAX) return false;
        }
        if(!Install()) return false;
        Reset(ped);
        CAnimManager::AddAnimBlockRef(index);
        CAnimManager::AddAnimBlockRef(originalIndex);
        m_peds.emplace(ped->m_pRwClump, PedAnimations{ped, original, block, originalIndex, index});
        ReplaceAll(ped->m_pRwClump);
        return true;
    }

    // Restores active clips and future requests. Returns false inside an animation update.
    // The loaded IFP remains owned by the caller.
    static inline bool Reset(CPed* ped)
    {
        if(m_nUpdateDepth) return false;
        for(auto it = m_peds.begin(); it != m_peds.end(); ++it)
        {
            PedAnimations& anims = it->second;
            if(anims.ped != ped) continue;
            for(CAnimBlendAssociation* association = RpAnimBlendClumpGetFirstAssociation(it->first); association;
                association = RpAnimBlendGetNextAssociation(association))
            {
                CAnimBlendHierarchy* hierarchy = association->m_pHierarchy;
                if(hierarchy && hierarchy->m_nAnimBlockId == anims.replacementIndex)
                    Rebind(it->first, association, CAnimManager::GetAnimation(hierarchy->m_hashKey, anims.original));
            }
            CAnimManager::RemoveAnimBlockRef(anims.replacementIndex);
            CAnimManager::RemoveAnimBlockRef(anims.originalIndex);
            m_peds.erase(it);
            return true;
        }
        return true;
    }
};

#endif // __AML_PSDK_SAPEDANIMATIONUTILS_H
