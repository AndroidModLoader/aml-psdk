#ifndef __AML_PSDK_VCANIMBLENDSEQUENCE_H
#define __AML_PSDK_VCANIMBLENDSEQUENCE_H

#include <aml-psdk/game_vc/plugin.h>
#include "../base/Quaternion.h"

struct CAnimBlendKeyFrameNoTrans
{
    CQuaternion m_quatRotation;
    float m_fDeltaTime;
};
CHECKSIZE(CAnimBlendKeyFrameNoTrans, 0x14, 0x14);

struct CAnimBlendKeyFrame
{
    CQuaternion m_quatRotation;
    float m_fDeltaTime;
    CVector m_vecTranslation;
};
CHECKSIZE(CAnimBlendKeyFrame, 0x20, 0x20);

DECL_CLASS(CAnimBlendSequence)
    // Construct/Deconstruct functions
    DECL_CTORCALL(CAnimBlendSequence, _ZN18CAnimBlendSequenceC2Ev);
    DECL_DTORCALL_VIRTUAL(CAnimBlendSequence, _ZN18CAnimBlendSequenceD2Ev, _ZN18CAnimBlendSequence, _ZTV18CAnimBlendSequence);

    // Member functions
    DECL_THISCALL_HEAD(SetName, _ZN18CAnimBlendSequence7SetNameEPKc, void, char const* name)
    DECL_THISCALL_TAIL(SetName, name)
    DECL_THISCALL_HEAD(SetBoneTag, _ZN18CAnimBlendSequence10SetBoneTagEi, void, i32 boneTag)
    DECL_THISCALL_TAIL(SetBoneTag, boneTag)
    DECL_THISCALL_HEAD(SetNumFrames, _ZN18CAnimBlendSequence12SetNumFramesEibb, void, i32 frameCount, bool translation, bool compressed)
    DECL_THISCALL_TAIL(SetNumFrames, frameCount, translation, compressed)
    DECL_THISCALL_SIMPLE(RemoveQuaternionFlips, _ZN18CAnimBlendSequence21RemoveQuaternionFlipsEv, void);
    DECL_THISCALL_SIMPLE(Uncompress, _ZN18CAnimBlendSequence10UncompressEv, void);
    DECL_THISCALL_SIMPLE(CompressKeyframes, _ZN18CAnimBlendSequence17CompressKeyframesEv, void);
    DECL_THISCALL_SIMPLE(RemoveUncompressedData, _ZN18CAnimBlendSequence22RemoveUncompressedDataEv, void);

    CAnimBlendSequence(CAnimBlendSequence const&) = delete;
    CAnimBlendSequence& operator=(CAnimBlendSequence const&) = delete;

    // Member values
    u32 m_nFlags;
    char m_szName[24];
    i32 m_nFrameCount;
    i16 m_nBoneTag;
    // Compressed frames retain this layout and store time in animation ticks.
    u8* m_pFrames;
    u8* m_pCompressedFrames;
DECL_CLASS_END()
CHECKSIZE(CAnimBlendSequence, 0x30, 0x40);

#endif // __AML_PSDK_VCANIMBLENDSEQUENCE_H
