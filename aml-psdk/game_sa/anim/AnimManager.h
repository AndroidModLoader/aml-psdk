#ifndef __AML_PSDK_SAANIMMANAGER_H
#define __AML_PSDK_SAANIMMANAGER_H

#include "AnimBlendAssocGroup.h"
#include "../enum/AnimationId.h"
#include "../base/Lists.h"
#include <aml-psdk/renderware/RwStream.h>

DECL_CLASS(CAnimManager)
    struct AnimDescriptor
    {
        AnimationId m_nAnimId;
        u32 m_nFlags;
    };

    struct AnimAssocDefinition
    {
        char m_szGroupName[16];
        char m_szBlockName[16];
        i32 m_nModelIndex;
        u32 m_nNumAnims;
        const char **m_pAnimNames;
        AnimDescriptor *m_pAnimDescriptors;
    };

    // STATIC functions
    DECL_FASTCALL_SIMPLE(Initialise, _ZN12CAnimManager10InitialiseEv, void);
    DECL_FASTCALL_SIMPLE(Shutdown, _ZN12CAnimManager8ShutdownEv, void);
    DECL_FASTCALL_SIMPLE(LoadAnimFiles, _ZN12CAnimManager13LoadAnimFilesEv, void);
    DECL_FASTCALL_SIMPLE(RegisterAnimBlock, _ZN12CAnimManager17RegisterAnimBlockEPKc, i32, char const* name);
    DECL_FASTCALL_SIMPLE(LoadAnimFile1, _ZN12CAnimManager12LoadAnimFileEPKc, void, char const* filename);
    inline static void LoadAnimFile(char const* filename)
    {
        return LoadAnimFile1(filename);
    }
    DECL_FASTCALL_SIMPLE(LoadAnimFile2, _ZN12CAnimManager12LoadAnimFileEP8RwStreambPA32_Kc, void, RwStream* stream, bool compress, char const (*uncompressedAnims)[32]);
    inline static void LoadAnimFile(RwStream* stream, bool compress, char const (*uncompressedAnims)[32])
    {
        return LoadAnimFile2(stream, compress, uncompressedAnims);
    }
    DECL_FASTCALL_SIMPLE(RemoveLastAnimFile, _ZN12CAnimManager18RemoveLastAnimFileEv, void);
    DECL_FASTCALL_SIMPLE(RemoveAnimBlock, _ZN12CAnimManager15RemoveAnimBlockEi, void, i32 index);
    DECL_FASTCALL_SIMPLE(AddAnimAssocDefinition, _ZN12CAnimManager22AddAnimAssocDefinitionEPKcS1_jjPNS_14AnimDescriptorE, AnimAssocDefinition*, char const* groupName, char const* blockName, u32 modelIndex, u32 numAnims, AnimDescriptor* descriptors);
    DECL_FASTCALL_SIMPLE(AddAnimToAssocDefinition, _ZN12CAnimManager24AddAnimToAssocDefinitionEPNS_19AnimAssocDefinitionEPKc, void, AnimAssocDefinition* definition, char const* animName);
    DECL_FASTCALL_SIMPLE(ReadAnimAssociationDefinitions, _ZN12CAnimManager30ReadAnimAssociationDefinitionsEv, void);
    DECL_FASTCALL_SIMPLE(CreateAnimAssocGroups, _ZN12CAnimManager21CreateAnimAssocGroupsEv, void);
    DECL_FASTCALL_SIMPLE(CreateAnimAssociation, _ZN12CAnimManager21CreateAnimAssociationE12AssocGroupId11AnimationId, CAnimBlendAssociation*, AssocGroupId groupId, AnimationId animId);
    DECL_FASTCALL_SIMPLE(GetAnimAssociation1, _ZN12CAnimManager18GetAnimAssociationE12AssocGroupId11AnimationId, CAnimBlendStaticAssociation*, AssocGroupId groupId, AnimationId animId);
    inline static CAnimBlendStaticAssociation* GetAnimAssociation(AssocGroupId groupId, AnimationId animId)
    {
        return GetAnimAssociation1(groupId, animId);
    }
    DECL_FASTCALL_SIMPLE(GetAnimAssociation2, _ZN12CAnimManager18GetAnimAssociationE12AssocGroupIdPKc, CAnimBlendStaticAssociation*, AssocGroupId groupId, char const* animName);
    inline static CAnimBlendStaticAssociation* GetAnimAssociation(AssocGroupId groupId, char const* animName)
    {
        return GetAnimAssociation2(groupId, animName);
    }
    DECL_FASTCALL_SIMPLE(AddAnimation1, _ZN12CAnimManager12AddAnimationEP7RpClump12AssocGroupId11AnimationId, CAnimBlendAssociation*, RpClump* clump, AssocGroupId groupId, AnimationId animId);
    inline static CAnimBlendAssociation* AddAnimation(RpClump* clump, AssocGroupId groupId, AnimationId animId)
    {
        return AddAnimation1(clump, groupId, animId);
    }
    DECL_FASTCALL_SIMPLE(AddAnimation2, _ZN12CAnimManager12AddAnimationEP7RpClumpP19CAnimBlendHierarchyi, CAnimBlendAssociation*, RpClump* clump, CAnimBlendHierarchy* hierarchy, i32 flags);
    inline static CAnimBlendAssociation* AddAnimation(RpClump* clump, CAnimBlendHierarchy* hierarchy, i32 flags)
    {
        return AddAnimation2(clump, hierarchy, flags);
    }
    DECL_FASTCALL_SIMPLE(BlendAnimation1, _ZN12CAnimManager14BlendAnimationEP7RpClump12AssocGroupId11AnimationIdf, CAnimBlendAssociation*, RpClump* clump, AssocGroupId groupId, AnimationId animId, float blendDelta);
    inline static CAnimBlendAssociation* BlendAnimation(RpClump* clump, AssocGroupId groupId, AnimationId animId, float blendDelta)
    {
        return BlendAnimation1(clump, groupId, animId, blendDelta);
    }
    DECL_FASTCALL_SIMPLE(BlendAnimation2, _ZN12CAnimManager14BlendAnimationEP7RpClumpP19CAnimBlendHierarchyif, CAnimBlendAssociation*, RpClump* clump, CAnimBlendHierarchy* hierarchy, i32 flags, float blendDelta);
    inline static CAnimBlendAssociation* BlendAnimation(RpClump* clump, CAnimBlendHierarchy* hierarchy, i32 flags, float blendDelta)
    {
        return BlendAnimation2(clump, hierarchy, flags, blendDelta);
    }
    DECL_FASTCALL_SIMPLE(GetAnimGroupName, _ZN12CAnimManager16GetAnimGroupNameE12AssocGroupId, char const*, AssocGroupId groupId);
    DECL_FASTCALL_SIMPLE(GetAnimBlockName, _ZN12CAnimManager16GetAnimBlockNameE12AssocGroupId, char const*, AssocGroupId groupId);
    DECL_FASTCALL_SIMPLE(UncompressAnimation, _ZN12CAnimManager19UncompressAnimationEP19CAnimBlendHierarchy, void, CAnimBlendHierarchy* hierarchy);
    DECL_FASTCALL_SIMPLE(RemoveFromUncompressedCache, _ZN12CAnimManager27RemoveFromUncompressedCacheEP19CAnimBlendHierarchy, void, CAnimBlendHierarchy* hierarchy);
    DECL_FASTCALL_SIMPLE(GetAnimationBlock1, _ZN12CAnimManager17GetAnimationBlockEPKc, CAnimBlock*, char const* name);
    inline static CAnimBlock* GetAnimationBlock(char const* name) { return GetAnimationBlock1(name); }
    DECL_FASTCALL_SIMPLE(GetAnimationBlockIndex, _ZN12CAnimManager22GetAnimationBlockIndexEPKc, i32, char const* name);
    DECL_FASTCALL_SIMPLE(GetFirstAssocGroup, _ZN12CAnimManager18GetFirstAssocGroupEPKc, AssocGroupId, char const* blockName);
    DECL_FASTCALL_SIMPLE(GetAnimation1, _ZN12CAnimManager12GetAnimationEPKcPK10CAnimBlock, CAnimBlendHierarchy*, char const* animName, CAnimBlock const* block);
    inline static CAnimBlendHierarchy* GetAnimation(char const* animName, CAnimBlock const* block)
    {
        return GetAnimation1(animName, block);
    }
    DECL_FASTCALL_SIMPLE(GetAnimation2, _ZN12CAnimManager12GetAnimationEjPK10CAnimBlock, CAnimBlendHierarchy*, u32 hash, CAnimBlock const* block);
    inline static CAnimBlendHierarchy* GetAnimation(u32 hash, CAnimBlock const* block)
    {
        return GetAnimation2(hash, block);
    }
    DECL_FASTCALL_SIMPLE(AddAnimBlockRef, _ZN12CAnimManager15AddAnimBlockRefEi, void, i32 index);
    DECL_FASTCALL_SIMPLE(RemoveAnimBlockRef, _ZN12CAnimManager18RemoveAnimBlockRefEi, void, i32 index);
    DECL_FASTCALL_SIMPLE(RemoveAnimBlockRefWithoutDelete, _ZN12CAnimManager31RemoveAnimBlockRefWithoutDeleteEi, void, i32 index);
    DECL_FASTCALL_SIMPLE(GetNumRefsToAnimBlock, _ZN12CAnimManager21GetNumRefsToAnimBlockEi, i32, i32 index);
    DECL_FASTCALL_SIMPLE(AddAnimationAndSync, _ZN12CAnimManager19AddAnimationAndSyncEP7RpClumpP21CAnimBlendAssociation12AssocGroupId11AnimationId, CAnimBlendAssociation*, RpClump* clump, CAnimBlendAssociation* association, AssocGroupId groupId, AnimationId animId);

    // STATIC values
    DECL_OBJECT_ARRAY_PLT(CAnimBlock, ms_aAnimBlocks, BYBIT(0x6793B4, 0x850780));
    DECL_OBJECT_ARRAY_PLT(CAnimBlendHierarchy, ms_aAnimations, BYBIT(0x6771D0, 0x84C3D8));
    DECL_VALUE_PLT_I32(ms_numAnimations, BYBIT(0x677EF0, 0x84DE00));
    DECL_VALUE_PLT_I32(ms_numAnimBlocks, BYBIT(0x678A48, 0x84F4B0));
    DECL_OBJECT_PLT(CAnimBlendAssocGroup*, ms_aAnimAssocGroups, BYBIT(0x677F88, 0x84DF30));
    DECL_OBJECT_ARRAY_PLT(AnimAssocDefinition, ms_aAnimAssocDefinitions, BYBIT(0x67877C, 0x84EF20));
    DECL_VALUE_PLT_I32(ms_numAnimAssocDefinitions, BYBIT(0x678510, 0x84EA38));
    DECL_OBJECT_PLT(CLinkList<CAnimBlendHierarchy*>, ms_animCache, BYBIT(0x678BDC, 0x84F7E0));

    // Helper functions
    inline static i32 GetNumAnimAssocDefinitions() { return ms_numAnimAssocDefinitions(); }
    inline static CAnimBlendHierarchy* GetAnimation(i32 index) { return &ms_aAnimations()[index]; }
    inline static CAnimBlock* GetAnimationBlock(i32 index) { return &ms_aAnimBlocks()[index]; }
    inline static CAnimBlendAssocGroup* GetAnimBlendAssoc(AssocGroupId groupId) { return &ms_aAnimAssocGroups()[groupId]; }
DECL_CLASS_END()
CHECKSIZE(CAnimManager, 0x1, 0x1);
CHECKSIZE(CAnimManager::AnimDescriptor, 0x8, 0x8);
CHECKSIZE(CAnimManager::AnimAssocDefinition, 0x30, 0x38);

#define ms_aAnimBlocks ms_aAnimBlocks()
#define ms_aAnimations ms_aAnimations()
#define ms_numAnimations ms_numAnimations()
#define ms_numAnimBlocks ms_numAnimBlocks()
#define ms_aAnimAssocGroups ms_aAnimAssocGroups()
#define ms_aAnimAssocDefinitions ms_aAnimAssocDefinitions()
#define ms_numAnimAssocDefinitions ms_numAnimAssocDefinitions()
#define ms_animCache ms_animCache()

#endif // __AML_PSDK_SAANIMMANAGER_H
