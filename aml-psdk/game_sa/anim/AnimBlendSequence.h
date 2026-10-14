#ifndef __AML_PSDK_SAANIMBLENDSEQUENCE_H
#define __AML_PSDK_SAANIMBLENDSEQUENCE_H

/*
    Plugin-SDK (Grand Theft Auto San Andreas) header file
    Authors: GTA Community. See more here
    https://github.com/DK22Pac/plugin-sdk
    Do not delete this comment block. Respect others' work!
*/

#include "../plugin.h"

DECL_CLASS(CAnimBlendSequence)
    // Construct/Deconstruct functions
    DECL_CTORCALL(CAnimBlendSequence, _ZN18CAnimBlendSequenceC2Ev);
    DECL_DTORCALL(CAnimBlendSequence, _ZN18CAnimBlendSequenceD2Ev);

    // Member functions
    DECL_THISCALL_HEAD(GetDataSize, _ZN18CAnimBlendSequence11GetDataSizeEb, u32, bool compressed)
    DECL_THISCALL_TAIL(GetDataSize, compressed)
    DECL_THISCALL_HEAD(SetName, _ZN18CAnimBlendSequence7SetNameEPKc, void, const char* name)
    DECL_THISCALL_TAIL(SetName, name)
    DECL_THISCALL_HEAD(SetNumFrames, _ZN18CAnimBlendSequence12SetNumFramesEibbPh, void, i32 numFrames, bool isRoot, bool compressed, u8* memory)
    DECL_THISCALL_TAIL(SetNumFrames, numFrames, isRoot, compressed, memory)
    DECL_THISCALL_HEAD(SetBoneTag, _ZN18CAnimBlendSequence10SetBoneTagEi, void, i32 boneTag)
    DECL_THISCALL_TAIL(SetBoneTag, boneTag)
    DECL_THISCALL_SIMPLE(RemoveQuaternionFlips, _ZN18CAnimBlendSequence21RemoveQuaternionFlipsEv, void);
    DECL_THISCALL_HEAD(Uncompress, _ZN18CAnimBlendSequence10UncompressEPh, void, u8* memory)
    DECL_THISCALL_TAIL(Uncompress, memory)
    DECL_THISCALL_HEAD(RemoveUncompressedData, _ZN18CAnimBlendSequence22RemoveUncompressedDataEPh, void, u8* memory)
    DECL_THISCALL_TAIL(RemoveUncompressedData, memory)
    DECL_THISCALL_HEAD(CompressKeyframes, _ZN18CAnimBlendSequence17CompressKeyframesEPh, void, u8* memory)
    DECL_THISCALL_TAIL(CompressKeyframes, memory)
    DECL_THISCALL_SIMPLE(Print, _ZN18CAnimBlendSequence5PrintEv, void);
    DECL_THISCALL_SIMPLE(MoveMemory, _ZN18CAnimBlendSequence10MoveMemoryEv, bool);

    // Member values
    union
    {
        u32 m_nHash;
        i16 m_nBoneTag;
    };
    u16 m_nFlags;
    i16 m_nFrameCount;
    u8 *m_pFrames;
DECL_CLASS_END()
CHECKSIZE(CAnimBlendSequence, 0xC, 0x10);

#endif // __AML_PSDK_SAANIMBLENDSEQUENCE_H
