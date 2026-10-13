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

DECL_FASTCALL_SIMPLE_GLO(RpAnimBlendClumpFindFrame, _Z25RpAnimBlendClumpFindFrameP7RpClumpPKc, AnimBlendFrameData*, RpClump* clump, const char* name);
DECL_FASTCALL_SIMPLE_GLO(RpAnimBlendClumpFindFrameFromHashKey, _Z36RpAnimBlendClumpFindFrameFromHashKeyP7RpClumpj, AnimBlendFrameData*, RpClump* clump, u32 key);
DECL_FASTCALL_SIMPLE_GLO(RpAnimBlendClumpFindBone, _Z24RpAnimBlendClumpFindBoneP7RpClumpj, AnimBlendFrameData*, RpClump* clump, u32 boneTag);
DECL_FASTCALL_SIMPLE_GLO(RpAnimBlendClumpIsInitialized, _Z29RpAnimBlendClumpIsInitializedP7RpClump, bool, RpClump* clump);
DECL_VALUE_PLT_I32_GLOBAL(ClumpOffset, BYBIT(0x676878, 0x84B148));

#define ClumpOffset ClumpOffset()

#endif // __AML_PSDK_SAANIMBLENDCLUMPDATA_H
