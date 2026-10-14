#ifndef __AML_PSDK_SAANIMBLENDNODE_H
#define __AML_PSDK_SAANIMBLENDNODE_H

/*
    Plugin-SDK (Grand Theft Auto San Andreas) header file
    Authors: GTA Community. See more here
    https://github.com/DK22Pac/plugin-sdk
    Do not delete this comment block. Respect others' work!
*/

#include "../plugin.h"
#include "AnimBlendSequence.h"
#include "../base/Quaternion.h"
struct CAnimBlendAssociation;

DECL_CLASS(CAnimBlendNode)
    // Member functions
    DECL_THISCALL_SIMPLE(Init, _ZN14CAnimBlendNode4InitEv, void);
    DECL_THISCALL_HEAD(FindKeyFrame, _ZN14CAnimBlendNode12FindKeyFrameEf, bool, float time)
    DECL_THISCALL_TAIL(FindKeyFrame, time)
    DECL_THISCALL_HEAD(GetEndTranslation, _ZN14CAnimBlendNode17GetEndTranslationER7CVectorf, void, CVector& translation, float blendWeight)
    DECL_THISCALL_TAIL(GetEndTranslation, translation, blendWeight)
    DECL_THISCALL_HEAD(GetCurrentTranslation, _ZN14CAnimBlendNode21GetCurrentTranslationER7CVectorf, void, CVector& translation, float blendWeight)
    DECL_THISCALL_TAIL(GetCurrentTranslation, translation, blendWeight)
    DECL_THISCALL_HEAD(Update, _ZN14CAnimBlendNode6UpdateER7CVectorR11CQuaternionf, bool, CVector& translation, CQuaternion& rotation, float blendWeight)
    DECL_THISCALL_TAIL(Update, translation, rotation, blendWeight)
    DECL_THISCALL_SIMPLE(UpdateTime, _ZN14CAnimBlendNode10UpdateTimeEv, bool);
    DECL_THISCALL_SIMPLE(CalcDeltas, _ZN14CAnimBlendNode10CalcDeltasEv, void);
    DECL_THISCALL_HEAD(UpdateCompressed, _ZN14CAnimBlendNode16UpdateCompressedER7CVectorR11CQuaternionf, bool, CVector& translation, CQuaternion& rotation, float blendWeight)
    DECL_THISCALL_TAIL(UpdateCompressed, translation, rotation, blendWeight)
    DECL_THISCALL_SIMPLE(CalcDeltasCompressed, _ZN14CAnimBlendNode20CalcDeltasCompressedEv, void);
    DECL_THISCALL_HEAD(GetEndTranslationCompressed, _ZN14CAnimBlendNode27GetEndTranslationCompressedER7CVectorf, void, CVector& translation, float blendWeight)
    DECL_THISCALL_TAIL(GetEndTranslationCompressed, translation, blendWeight)
    DECL_THISCALL_HEAD(GetCurrentTranslationCompressed, _ZN14CAnimBlendNode31GetCurrentTranslationCompressedER7CVectorf, void, CVector& translation, float blendWeight)
    DECL_THISCALL_TAIL(GetCurrentTranslationCompressed, translation, blendWeight)
    DECL_THISCALL_SIMPLE(SetupKeyFrameCompressed, _ZN14CAnimBlendNode23SetupKeyFrameCompressedEv, bool);
    DECL_THISCALL_SIMPLE(NextKeyFrame, _ZN14CAnimBlendNode12NextKeyFrameEv, bool);
    DECL_THISCALL_SIMPLE(NextKeyFrameNoCalc, _ZN14CAnimBlendNode18NextKeyFrameNoCalcEv, bool);
    DECL_THISCALL_SIMPLE(NextKeyFrameCompressed, _ZN14CAnimBlendNode22NextKeyFrameCompressedEv, bool);

    // Member values
    float m_fTheta;
    float m_fOOSinTheta;
    i16 m_nCurrentFrame;
    i16 m_nPreviousFrame;
    float m_fTimeRemaining;
    CAnimBlendSequence *m_pSequence;
    CAnimBlendAssociation *m_pAnimBlendAssociation;
DECL_CLASS_END()
CHECKSIZE(CAnimBlendNode, 0x18, 0x20);

#endif // __AML_PSDK_SAANIMBLENDNODE_H
