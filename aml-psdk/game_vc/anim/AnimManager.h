#ifndef __AML_PSDK_VCANIMMANAGER_H
#define __AML_PSDK_VCANIMMANAGER_H

#include <aml-psdk/game_vc/plugin.h>
#include "AnimBlock.h"
#include "AnimBlendAssociation.h"

struct CAnimBlendAssocGroup;
struct RwStream;

DECL_CLASS(CAnimManager)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(Initialise, _ZN12CAnimManager10InitialiseEv, void);
    DECL_FASTCALL_SIMPLE(Shutdown, _ZN12CAnimManager8ShutdownEv, void);
    DECL_FASTCALL_SIMPLE(GetAnimationBlock, _ZN12CAnimManager17GetAnimationBlockEPKc, CAnimBlock*, char const* name);
    DECL_FASTCALL_SIMPLE(GetAnimationBlockIndex, _ZN12CAnimManager22GetAnimationBlockIndexEPKc, i32, char const* name);
    DECL_FASTCALL_SIMPLE(RegisterAnimBlock, _ZN12CAnimManager17RegisterAnimBlockEPKc, i32, char const* name);
    DECL_FASTCALL_SIMPLE(GetAnimation, _ZN12CAnimManager12GetAnimationEPKcP10CAnimBlock, CAnimBlendHierarchy*, char const* name, CAnimBlock* block);
    DECL_FASTCALL_SIMPLE(GetAnimGroupName, _ZN12CAnimManager16GetAnimGroupNameE12AssocGroupId, char const*, i32 groupId);
    DECL_FASTCALL_SIMPLE(CreateAnimAssociation, _ZN12CAnimManager21CreateAnimAssociationE12AssocGroupId11AnimationId, CAnimBlendAssociation*, i32 groupId, i32 animationId);
    DECL_FASTCALL_SIMPLE(AddAnimation, _ZN12CAnimManager12AddAnimationEP7RpClump12AssocGroupId11AnimationId, CAnimBlendAssociation*, RpClump* clump, i32 groupId, i32 animationId);
    DECL_FASTCALL_SIMPLE(AddAnimationAndSync, _ZN12CAnimManager19AddAnimationAndSyncEP7RpClumpP21CAnimBlendAssociation12AssocGroupId11AnimationId, CAnimBlendAssociation*, RpClump* clump, CAnimBlendAssociation* sync, i32 groupId, i32 animationId);
    DECL_FASTCALL_SIMPLE(BlendAnimation, _ZN12CAnimManager14BlendAnimationEP7RpClump12AssocGroupId11AnimationIdf, CAnimBlendAssociation*, RpClump* clump, i32 groupId, i32 animationId, float blendDelta);
    DECL_FASTCALL_SIMPLE(UncompressAnimation, _ZN12CAnimManager19UncompressAnimationEP19CAnimBlendHierarchy, void, CAnimBlendHierarchy* hierarchy);
    DECL_FASTCALL_SIMPLE(RemoveFromUncompressedCache, _ZN12CAnimManager27RemoveFromUncompressedCacheEP19CAnimBlendHierarchy, void, CAnimBlendHierarchy* hierarchy);
    DECL_FASTCALL_SIMPLE(CreateAnimAssocGroups, _ZN12CAnimManager21CreateAnimAssocGroupsEv, void);
    DECL_FASTCALL_SIMPLE(LoadAnimFiles, _ZN12CAnimManager13LoadAnimFilesEv, void);
    DECL_FASTCALL_SIMPLE(RemoveLastAnimFile, _ZN12CAnimManager18RemoveLastAnimFileEv, void);
    DECL_FASTCALL_SIMPLE(RemoveAnimBlock, _ZN12CAnimManager15RemoveAnimBlockEi, void, i32 index);
    DECL_FASTCALL_SIMPLE(AddAnimBlockRef, _ZN12CAnimManager15AddAnimBlockRefEi, void, i32 index);
    DECL_FASTCALL_SIMPLE(RemoveAnimBlockRef, _ZN12CAnimManager18RemoveAnimBlockRefEi, void, i32 index);
    DECL_FASTCALL_SIMPLE(RemoveAnimBlockRefWithoutDelete, _ZN12CAnimManager31RemoveAnimBlockRefWithoutDeleteEi, void, i32 index);
    DECL_FASTCALL_SIMPLE(GetNumRefsToAnimBlock, _ZN12CAnimManager21GetNumRefsToAnimBlockEi, i32, i32 index);

    inline static CAnimBlendAssociation* GetAnimAssociation(i32 groupId, i32 animationId)
    {
        static auto native = GetMainLibrarySymbol<CAnimBlendAssociation*(*)(i32 groupId, i32 animationId)>("_ZN12CAnimManager18GetAnimAssociationE12AssocGroupId11AnimationId");
        return native(groupId, animationId);
    }

    inline static CAnimBlendAssociation* GetAnimAssociation(i32 groupId, char const* name)
    {
        static auto native = GetMainLibrarySymbol<CAnimBlendAssociation*(*)(i32 groupId, char const* name)>("_ZN12CAnimManager18GetAnimAssociationE12AssocGroupIdPKc");
        return native(groupId, name);
    }

    inline static void LoadAnimFile(char const* filename)
    {
        static auto native = GetMainLibrarySymbol<void(*)(char const* filename)>("_ZN12CAnimManager12LoadAnimFileEPKc");
        return native(filename);
    }

    inline static void LoadAnimFile(RwStream* stream, bool compressed, char const (*uncompressedAnimations)[32])
    {
        static auto native = GetMainLibrarySymbol<void(*)(RwStream* stream, bool compressed, char const (*uncompressedAnimations)[32])>("_ZN12CAnimManager12LoadAnimFileEP8RwStreambPA32_Kc");
        return native(stream, compressed, uncompressedAnimations);
    }

    // STATIC values
    DECL_VALUE_PLT_I32(ms_numAnimations, BYBIT(0x3949fc, 0x5774e8));
    DECL_VALUE_PLT_I32(ms_numAnimBlocks, BYBIT(0x396ac4, 0x57b588));
    DECL_OBJECT_ARRAY_PLT(CAnimBlendHierarchy, ms_aAnimations, BYBIT(0x395cec, 0x5799f0));
    DECL_OBJECT_ARRAY_PLT(CAnimBlock, ms_aAnimBlocks, BYBIT(0x395efc, 0x579e28));
    DECL_OBJECT_PLT(CAnimBlendAssocGroup*, ms_aAnimAssocGroups, BYBIT(0x395810, 0x579078));
DECL_CLASS_END()

#define ms_numAnimations ms_numAnimations()
#define ms_numAnimBlocks ms_numAnimBlocks()
#define ms_aAnimations ms_aAnimations()
#define ms_aAnimBlocks ms_aAnimBlocks()
#define ms_aAnimAssocGroups ms_aAnimAssocGroups()

#endif // __AML_PSDK_VCANIMMANAGER_H
