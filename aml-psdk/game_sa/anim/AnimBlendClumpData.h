#ifndef __AML_PSDK_SAANIMBLENDCLUMPDATA_H
#define __AML_PSDK_SAANIMBLENDCLUMPDATA_H

/*
    Plugin-SDK (Grand Theft Auto San Andreas) header file
    Authors: GTA Community. See more here
    https://github.com/DK22Pac/plugin-sdk
    Do not delete this comment block. Respect others' work!
*/

#include "../plugin.h"
#include <aml-psdk/gta_base/Vector.h>
#include <aml-psdk/renderware/RwLinks.h>
#include <aml-psdk/renderware/RpHAnim.h>

struct RpClump;
struct CAnimBlendAssociation;
struct CAnimBlendHierarchy;
struct CAnimBlendNode;

struct ListLink
{
    ListLink *pNext;
    ListLink *pPrev;
};
CHECKSIZE(ListLink, 0x8, 0x10);

struct AnimBlendFrameData
{
    i8 m_nFlags;
    union
    {
        CVector m_vecOffset;
        RwV3d m_vecBonePosition;
    };
    union
    {
        RwFrame *m_pFrame;
        RpHAnimBlendInterpFrame *m_pStdKeyFrame;
    };
    i32 m_nNodeId;
};
CHECKSIZE(AnimBlendFrameData, 0x18, 0x20);

typedef void (*AnimBlendFrameCallback)(AnimBlendFrameData*, void*);

DECL_CLASS(CAnimBlendClumpData)
    // Construct/Deconstruct functions
    DECL_CTORCALL(CAnimBlendClumpData, _ZN19CAnimBlendClumpDataC2Ev);
    DECL_DTORCALL(CAnimBlendClumpData, _ZN19CAnimBlendClumpDataD2Ev);

    // Member functions
    DECL_THISCALL_HEAD(SetNumberOfBones, _ZN19CAnimBlendClumpData16SetNumberOfBonesEi, void, i32 numBones)
    DECL_THISCALL_TAIL(SetNumberOfBones, numBones)
    DECL_THISCALL_HEAD(ForAllFrames, _ZN19CAnimBlendClumpData12ForAllFramesEPFvP18AnimBlendFrameDataPvES2_, void, AnimBlendFrameCallback callback, void* data)
    DECL_THISCALL_TAIL(ForAllFrames, callback, data)
    DECL_THISCALL_SIMPLE(LoadFramesIntoSPR, _ZN19CAnimBlendClumpData17LoadFramesIntoSPREv, void);
    DECL_THISCALL_HEAD(ForAllFramesInSPR, _ZN19CAnimBlendClumpData17ForAllFramesInSPREPFvP18AnimBlendFrameDataPvES2_j, void,
        AnimBlendFrameCallback callback, void* data, u32 frame)
    DECL_THISCALL_TAIL(ForAllFramesInSPR, callback, data, frame)

    // Helper functions
    inline i32 GetNumberOfBones() { return m_nNumBones; }
    inline i32 GetNumberOfFrames() { return m_nNumFrames; }
    inline void SetNumberOfFrames(i32 numFrames) { SetNumberOfBones(numFrames); }
    inline AnimBlendFrameData* GetFrameDataArray() { return m_pFrames; }
    inline void SetVelocityPtr(float* velocity) { m_pVelocity = velocity; }
    inline float* GetVelocityPtr() { return m_pVelocity; }
    inline ListLink* GetList() { return &m_associationsList; }

    // Member values
    ListLink m_associationsList;
    union
    {
        i32 m_nNumFrames;
        i32 m_nNumBones;
    };
    float *m_pVelocity;
    AnimBlendFrameData *m_pFrames;
DECL_CLASS_END()
CHECKSIZE(CAnimBlendClumpData, 0x14, 0x28);

struct AnimBlendUpdateData
{
    i32 includePartial;
    CAnimBlendNode* apAnimBlendNodeArrays[12];
};
CHECKSIZE(AnimBlendUpdateData, 0x34, 0x68);

DECL_FASTCALL_SIMPLE_GLO(RpAnimBlendClumpFindFrame, _Z25RpAnimBlendClumpFindFrameP7RpClumpPKc, AnimBlendFrameData*, RpClump* clump, const char* name);
DECL_FASTCALL_SIMPLE_GLO(RpAnimBlendClumpFindFrameFromHashKey, _Z36RpAnimBlendClumpFindFrameFromHashKeyP7RpClumpj, AnimBlendFrameData*, RpClump* clump, u32 key);
DECL_FASTCALL_SIMPLE_GLO(RpAnimBlendClumpFindBone, _Z24RpAnimBlendClumpFindBoneP7RpClumpj, AnimBlendFrameData*, RpClump* clump, u32 boneTag);
DECL_FASTCALL_SIMPLE_GLO(RpAnimBlendClumpIsInitialized, _Z29RpAnimBlendClumpIsInitializedP7RpClump, bool, RpClump* clump);
DECL_FASTCALL_SIMPLE_GLO(RpAnimBlendClumpUpdateAnimations, _Z32RpAnimBlendClumpUpdateAnimationsP7RpClumpfb, void, RpClump* pClump, float fTimeStep, bool bOnScreen);
DECL_FASTCALL_SIMPLE_GLO(RpAnimBlendClumpGetFirstAssociation1, _Z35RpAnimBlendClumpGetFirstAssociationP7RpClump, CAnimBlendAssociation*, RpClump* pClump);
inline CAnimBlendAssociation* RpAnimBlendClumpGetFirstAssociation(RpClump* pClump)
{
    return RpAnimBlendClumpGetFirstAssociation1(pClump);
}
DECL_FASTCALL_SIMPLE_GLO(RpAnimBlendFrameSetName, _Z23RpAnimBlendFrameSetNameP7RwFramePc, RwFrame*, RwFrame* pFrame, char* pName);
DECL_FASTCALL_SIMPLE_GLO(RpAnimBlendCreateAnimationForHierarchy, _Z38RpAnimBlendCreateAnimationForHierarchyP16RpHAnimHierarchy, RpHAnimAnimation*, RpHAnimHierarchy* pHierarchy);
DECL_FASTCALL_SIMPLE_GLO(RpAnimBlendKeyFrameInterpolate, _Z30RpAnimBlendKeyFrameInterpolatePvS_S_fS_, void, void* pVoidOut, void* pVoidIn1, void* pVoidIn2, RwReal time, void* customData);
DECL_FASTCALL_SIMPLE_GLO(RtAnimBlendKeyFrameApply, _Z24RtAnimBlendKeyFrameApplyPvS_, void, void* result, void* voidIFrame);
DECL_FASTCALL_SIMPLE_GLO(RpAnimBlendAllocateData, _Z23RpAnimBlendAllocateDataP7RpClump, void, RpClump* pClump);
DECL_FASTCALL_SIMPLE_GLO(RpAnimBlendPluginAttach, _Z23RpAnimBlendPluginAttachv, RwBool);
DECL_FASTCALL_SIMPLE_GLO(RpAnimBlendFrameGetName, _Z23RpAnimBlendFrameGetNameP7RwFrame, char const*, RwFrame* pFrame);
DECL_FASTCALL_SIMPLE_GLO(RpAnimBlendClumpGetFirstAssociation2, _Z35RpAnimBlendClumpGetFirstAssociationP7RpClumpj, CAnimBlendAssociation*, RpClump* pClump, u32 flag);
inline CAnimBlendAssociation* RpAnimBlendClumpGetFirstAssociation(RpClump* pClump, u32 flag)
{
    return RpAnimBlendClumpGetFirstAssociation2(pClump, flag);
}
DECL_FASTCALL_SIMPLE_GLO(RpAnimBlendClumpPauseAllAnimations, _Z34RpAnimBlendClumpPauseAllAnimationsP7RpClump, void, RpClump* pClump);
DECL_FASTCALL_SIMPLE_GLO(RpAnimBlendClumpSetBlendDeltas, _Z30RpAnimBlendClumpSetBlendDeltasP7RpClumpjf, void, RpClump* pClump, u32 flag, float delta);
DECL_FASTCALL_SIMPLE_GLO(RpAnimBlendClumpGetMainAssociation_N, _Z36RpAnimBlendClumpGetMainAssociation_NP7RpClumpi, CAnimBlendAssociation*, RpClump* pClump, i32 N);
DECL_FASTCALL_SIMPLE_GLO(RpAnimBlendClumpGiveAssociations, _Z32RpAnimBlendClumpGiveAssociationsP7RpClumpP21CAnimBlendAssociation, void, RpClump* pClump, CAnimBlendAssociation* pAssociations);
DECL_FASTCALL_SIMPLE_GLO(RpAnimBlendClumpGetNumAssociations, _Z34RpAnimBlendClumpGetNumAssociationsP7RpClump, i32, RpClump* pClump);
DECL_FASTCALL_SIMPLE_GLO(RpAnimBlendClumpGetAssociation1, _Z30RpAnimBlendClumpGetAssociationP7RpClumpbP19CAnimBlendHierarchy, CAnimBlendAssociation*, RpClump* pClump, bool bStopFunctionConfusion, CAnimBlendHierarchy* pHierarchy);
inline CAnimBlendAssociation* RpAnimBlendClumpGetAssociation(RpClump* pClump, bool bStopFunctionConfusion, CAnimBlendHierarchy* pHierarchy)
{
    return RpAnimBlendClumpGetAssociation1(pClump, bStopFunctionConfusion, pHierarchy);
}
DECL_FASTCALL_SIMPLE_GLO(RpAnimBlendClumpGetNumPartialAssociations, _Z41RpAnimBlendClumpGetNumPartialAssociationsP7RpClump, i32, RpClump* pClump);
DECL_FASTCALL_SIMPLE_GLO(RpAnimBlendClumpGetMainPartialAssociation, _Z41RpAnimBlendClumpGetMainPartialAssociationP7RpClump, CAnimBlendAssociation*, RpClump* pClump);
DECL_FASTCALL_SIMPLE_GLO(RpAnimBlendClumpInit, _Z20RpAnimBlendClumpInitP7RpClump, void, RpClump* pClump);
DECL_FASTCALL_SIMPLE_GLO(RpAnimBlendClumpRemoveAllAssociations, _Z37RpAnimBlendClumpRemoveAllAssociationsP7RpClump, void, RpClump* pClump);
DECL_FASTCALL_SIMPLE_GLO(RpAnimBlendClumpGetNumNonPartialAssociations, _Z44RpAnimBlendClumpGetNumNonPartialAssociationsP7RpClump, i32, RpClump* pClump);
DECL_FASTCALL_SIMPLE_GLO(RpAnimBlendGetNextAssociation1, _Z29RpAnimBlendGetNextAssociationP21CAnimBlendAssociationj, CAnimBlendAssociation*, CAnimBlendAssociation* pAssociation, u32 flag);
inline CAnimBlendAssociation* RpAnimBlendGetNextAssociation(CAnimBlendAssociation* pAssociation, u32 flag)
{
    return RpAnimBlendGetNextAssociation1(pAssociation, flag);
}
DECL_FASTCALL_SIMPLE_GLO(RpAnimBlendClumpGetMainPartialAssociation_N, _Z43RpAnimBlendClumpGetMainPartialAssociation_NP7RpClumpi, CAnimBlendAssociation*, RpClump* pClump, i32 N);
DECL_FASTCALL_SIMPLE_GLO(RpAnimBlendClumpRemoveAssociations, _Z34RpAnimBlendClumpRemoveAssociationsP7RpClumpj, void, RpClump* pClump, u32 flag);
DECL_FASTCALL_SIMPLE_GLO(RpAnimBlendClumpGetMainAssociation, _Z34RpAnimBlendClumpGetMainAssociationP7RpClumpPP21CAnimBlendAssociationPf, CAnimBlendAssociation*, RpClump* pClump, CAnimBlendAssociation** pp2ndAnim, float* pBlendVal2nd);
DECL_FASTCALL_SIMPLE_GLO(RpAnimBlendClumpAddAssociation, _Z30RpAnimBlendClumpAddAssociationP7RpClumpP21CAnimBlendAssociationjff, CAnimBlendAssociation*, RpClump* pClump, CAnimBlendAssociation* pAssociation, u32 PlayFlags, float fStartTime, float fBlendAmount);
DECL_FASTCALL_SIMPLE_GLO(RpAnimBlendClumpExtractAssociations, _Z35RpAnimBlendClumpExtractAssociationsP7RpClump, CAnimBlendAssociation*, RpClump* pClump);
DECL_FASTCALL_SIMPLE_GLO(RpAnimBlendClumpUnPauseAllAnimations, _Z36RpAnimBlendClumpUnPauseAllAnimationsP7RpClump, void, RpClump* pClump);
DECL_FASTCALL_SIMPLE_GLO(RpAnimBlendClumpFillFrameArray, _Z30RpAnimBlendClumpFillFrameArrayP7RpClumpPP18AnimBlendFrameData, void, RpClump* pClump, AnimBlendFrameData** ppFrameArray);
DECL_FASTCALL_SIMPLE_GLO(RpAnimBlendClumpGetAssociation2, _Z30RpAnimBlendClumpGetAssociationP7RpClumpPKc, CAnimBlendAssociation*, RpClump* pClump, char const* pName);
inline CAnimBlendAssociation* RpAnimBlendClumpGetAssociation(RpClump* pClump, char const* pName)
{
    return RpAnimBlendClumpGetAssociation2(pClump, pName);
}
DECL_FASTCALL_SIMPLE_GLO(RpAnimBlendClumpGetAssociation3, _Z30RpAnimBlendClumpGetAssociationP7RpClumpj, CAnimBlendAssociation*, RpClump* pClump, u32 id);
inline CAnimBlendAssociation* RpAnimBlendClumpGetAssociation(RpClump* pClump, u32 id)
{
    return RpAnimBlendClumpGetAssociation3(pClump, id);
}
DECL_FASTCALL_SIMPLE_GLO(RpAnimBlendGetNextAssociation2, _Z29RpAnimBlendGetNextAssociationP21CAnimBlendAssociation, CAnimBlendAssociation*, CAnimBlendAssociation* pAssociation);
inline CAnimBlendAssociation* RpAnimBlendGetNextAssociation(CAnimBlendAssociation* pAssociation)
{
    return RpAnimBlendGetNextAssociation2(pAssociation);
}

DECL_VALUE_PLT_I32_GLOBAL(ClumpOffset, BYBIT(0x676878, 0x84B148));

inline CAnimBlendClumpData* RpAnimBlendClumpGetData(RpClump* clump)
{
    return *(CAnimBlendClumpData**)((u8*)clump + ClumpOffset());
}

#define ClumpOffset ClumpOffset()

#endif // __AML_PSDK_SAANIMBLENDCLUMPDATA_H
