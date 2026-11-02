#ifndef __AML_PSDK_RPHANIM_H
#define __AML_PSDK_RPHANIM_H

#include "RwFrame.h"
#include "RtAnim.h"

struct RtAnimInterpolator;
struct RwFreeList;

enum RpHAnimHierarchyFlag : RwInt32
{
    rpHANIMHIERARCHYSUBHIERARCHY = 0x1,
    rpHANIMHIERARCHYNOMATRICES = 0x2,
    rpHANIMHIERARCHYUPDATEMODELLINGMATRICES = 0x1000,
    rpHANIMHIERARCHYUPDATELTMS = 0x2000,
    rpHANIMHIERARCHYLOCALSPACEMATRICES = 0x4000,
    rpHANIMHIERARCHYFLAGFORCEENUMSIZEINT = 0x7FFFFFFF
};

#include "RtQuat.h"

struct RpHAnimBlendInterpFrame
{
    RtQuat q;
    RwV3d t;
};
CHECKSIZE(RpHAnimBlendInterpFrame, 0x1C, 0x1C);

struct RpHAnimNodeInfo
{
    RwInt32 nodeID;
    RwInt32 nodeIndex;
    RwInt32 flags;
    RwFrame *pFrame;
};
CHECKSIZE(RpHAnimNodeInfo, 0x10, 0x18);

struct RpHAnimHierarchy
{
    RwInt32 flags;
    RwInt32 numNodes;
    RwMatrix *pMatrixArray;
    void *pMatrixArrayUnaligned;
    RpHAnimNodeInfo *pNodeInfo;
    RwFrame *parentFrame;
    RpHAnimHierarchy *parentHierarchy;
    RwInt32 rootParentOffset;
    RtAnimInterpolator *currentAnim;
};
CHECKSIZE(RpHAnimHierarchy, 0x24, 0x40);

typedef RtAnimAnimation RpHAnimAnimation;

struct RpHAnimKeyFrame
{
    RpHAnimKeyFrame* prevFrame;
    RwReal time;
    alignas(ALIGN_8_4) RtQuat q;
    RwV3d t;
};
CHECKSIZE(RpHAnimKeyFrame, 0x24, 0x30);

struct RpHAnimInterpFrame
{
    RpHAnimKeyFrame* keyFrame1;
    RpHAnimKeyFrame* keyFrame2;
    RtQuat q;
    RwV3d t;
};
CHECKSIZE(RpHAnimInterpFrame, 0x24, 0x30);

struct RpHAnimFrameExtension
{
    RwInt32 id;
    RpHAnimHierarchy* hierarchy;
};
CHECKSIZE(RpHAnimFrameExtension, 0x8, 0x10);

struct RpHAnimAtomicGlobalVars
{
    RwInt32 engineOffset;
    RwFreeList* HAnimFreeList;
};
CHECKSIZE(RpHAnimAtomicGlobalVars, 0x8, 0x10);

DECL_FASTCALL_SIMPLE_GLO(RpHAnimHierarchyCreate, _Z22RpHAnimHierarchyCreateiPjPi20RpHAnimHierarchyFlagi, RpHAnimHierarchy*,
    RwInt32 numNodes, RwUInt32* nodeFlags, RwInt32* nodeIDs, RpHAnimHierarchyFlag flags, RwInt32 maxInterpKeyFrameSize);
DECL_FASTCALL_SIMPLE_GLO(RpHAnimHierarchyDestroy, _Z23RpHAnimHierarchyDestroyP16RpHAnimHierarchy, RpHAnimHierarchy*, RpHAnimHierarchy* hierarchy);
DECL_FASTCALL_SIMPLE_GLO(RpHAnimHierarchyCreateFromHierarchy, _Z35RpHAnimHierarchyCreateFromHierarchyP16RpHAnimHierarchy20RpHAnimHierarchyFlagi, RpHAnimHierarchy*,
    RpHAnimHierarchy* hierarchy, RpHAnimHierarchyFlag flags, RwInt32 maxInterpKeyFrameSize);
DECL_FASTCALL_SIMPLE_GLO(RpHAnimHierarchyCreateSubHierarchy, _Z34RpHAnimHierarchyCreateSubHierarchyP16RpHAnimHierarchyi20RpHAnimHierarchyFlagi, RpHAnimHierarchy*,
    RpHAnimHierarchy* hierarchy, RwInt32 startNode, RpHAnimHierarchyFlag flags, RwInt32 maxInterpKeyFrameSize);
DECL_FASTCALL_SIMPLE_GLO(RpHAnimHierarchyGetMatrixArray, _Z30RpHAnimHierarchyGetMatrixArrayP16RpHAnimHierarchy, RwMatrix*, RpHAnimHierarchy* hierarchy);
DECL_FASTCALL_SIMPLE_GLO(RpHAnimHierarchyUpdateMatrices, _Z30RpHAnimHierarchyUpdateMatricesP16RpHAnimHierarchy, RwBool, RpHAnimHierarchy* hierarchy);
DECL_FASTCALL_SIMPLE_GLO(RpHAnimHierarchyAttach, _Z22RpHAnimHierarchyAttachP16RpHAnimHierarchy, RpHAnimHierarchy*, RpHAnimHierarchy* hierarchy);
DECL_FASTCALL_SIMPLE_GLO(RpHAnimHierarchyDetach, _Z22RpHAnimHierarchyDetachP16RpHAnimHierarchy, RpHAnimHierarchy*, RpHAnimHierarchy* hierarchy);
DECL_FASTCALL_SIMPLE_GLO(RpHAnimHierarchyAttachFrameIndex, _Z32RpHAnimHierarchyAttachFrameIndexP16RpHAnimHierarchyi, RpHAnimHierarchy*, RpHAnimHierarchy* hierarchy, RwInt32 nodeIndex);
DECL_FASTCALL_SIMPLE_GLO(RpHAnimHierarchyDetachFrameIndex, _Z32RpHAnimHierarchyDetachFrameIndexP16RpHAnimHierarchyi, RpHAnimHierarchy*, RpHAnimHierarchy* hierarchy, RwInt32 nodeIndex);
DECL_FASTCALL_SIMPLE_GLO(RpHAnimFrameGetHierarchy, _Z24RpHAnimFrameGetHierarchyP7RwFrame, RpHAnimHierarchy*, RwFrame* frame);
DECL_FASTCALL_SIMPLE_GLO(RpHAnimFrameSetHierarchy, _Z24RpHAnimFrameSetHierarchyP7RwFrameP16RpHAnimHierarchy, RwBool, RwFrame* frame, RpHAnimHierarchy* hierarchy);
DECL_FASTCALL_SIMPLE_GLO(RpHAnimFrameGetID, _Z17RpHAnimFrameGetIDP7RwFrame, RwInt32, RwFrame* frame);
DECL_FASTCALL_SIMPLE_GLO(RpHAnimFrameSetID, _Z17RpHAnimFrameSetIDP7RwFramei, RwBool, RwFrame* frame, RwInt32 id);
DECL_FASTCALL_SIMPLE_GLO(RpHAnimIDGetIndex, _Z17RpHAnimIDGetIndexP16RpHAnimHierarchyi, RwInt32, RpHAnimHierarchy* hierarchy, RwInt32 id);

DECL_FASTCALL_SIMPLE_GLO(RpHAnimPluginAttach, _Z19RpHAnimPluginAttachv, RwBool);
DECL_FASTCALL_SIMPLE_GLO(RpHAnimHierarchySetFreeListCreateParams, _Z39RpHAnimHierarchySetFreeListCreateParamsii, void, RwInt32 blockSize, RwInt32 numBlocksToPrealloc);
#ifdef GTAVC
DECL_FASTCALL_SIMPLE_GLO(RpHAnimKeyFrameStreamGetSize, _Z28RpHAnimKeyFrameStreamGetSizeP15RtAnimAnimation, RwInt32, RtAnimAnimation* animation);
#else
DECL_FASTCALL_SIMPLE_GLO(RpHAnimKeyFrameStreamGetSize, _Z28RpHAnimKeyFrameStreamGetSizePK15RtAnimAnimation, RwInt32, RtAnimAnimation const* animation);
#endif
DECL_FASTCALL_SIMPLE_GLO(RpHAnimKeyFrameMulRecip, _Z23RpHAnimKeyFrameMulRecipPvS_, void, void* pVoidFrame, void* pVoidStart);
DECL_FASTCALL_SIMPLE_GLO(RpHAnimKeyFrameBlend, _Z20RpHAnimKeyFrameBlendPvS_S_f, void, void* pVoidOut, void* pVoidIn1, void* pVoidIn2, RwReal fAlpha);
DECL_FASTCALL_SIMPLE_GLO(RpHAnimKeyFrameApply, _Z20RpHAnimKeyFrameApplyPvS_, void, void* pMatrix, void* pVoidIFrame);
#ifdef GTAVC
DECL_FASTCALL_SIMPLE_GLO(RpHAnimKeyFrameInterpolate, _Z26RpHAnimKeyFrameInterpolatePvS_S_f, void, void* pVoidOut, void* pVoidIn1, void* pVoidIn2, RwReal time);
#else
DECL_FASTCALL_SIMPLE_GLO(RpHAnimKeyFrameInterpolate, _Z26RpHAnimKeyFrameInterpolatePvS_S_fS_, void, void* pVoidOut, void* pVoidIn1, void* pVoidIn2, RwReal time, void* customData);
#endif
#ifdef GTAVC
DECL_FASTCALL_SIMPLE_GLO(RpHAnimKeyFrameStreamWrite, _Z26RpHAnimKeyFrameStreamWriteP15RtAnimAnimationP8RwStream, RwBool, RtAnimAnimation* pAnimation, RwStream* stream);
#else
DECL_FASTCALL_SIMPLE_GLO(RpHAnimKeyFrameStreamWrite, _Z26RpHAnimKeyFrameStreamWritePK15RtAnimAnimationP8RwStream, RwBool, RtAnimAnimation const* pAnimation, RwStream* stream);
#endif
DECL_FASTCALL_SIMPLE_GLO(RpHAnimKeyFrameStreamRead, _Z25RpHAnimKeyFrameStreamReadP8RwStreamP15RtAnimAnimation, RtAnimAnimation*, RwStream* stream, RtAnimAnimation* pAnimation);
DECL_FASTCALL_SIMPLE_GLO(RpHAnimKeyFrameAdd, _Z18RpHAnimKeyFrameAddPvS_S_, void, void* pVoidOut, void* pVoidIn1, void* pVoidIn2);

#ifdef GTAVC
DECL_OBJECT_PLT_GLOBAL(RpHAnimAtomicGlobalVars, RpHAnimAtomicGlobals, BYBIT(0x394c98, 0x577a00));
#else
DECL_OBJECT_PLT_GLOBAL(RpHAnimAtomicGlobalVars, RpHAnimAtomicGlobals, BYBIT(0x676C5C, 0x84B900));
#endif

#ifdef GTAVC
enum RpHAnimHierarchyNodeFlag : RwInt32
{
    rpHANIMPUSHPARENTMATRIX = 0x2,
    rpHANIMPOPPARENTMATRIX = 0x1
};
#endif

inline RpHAnimHierarchyFlag RpHAnimHierarchyGetFlags(const RpHAnimHierarchy* hierarchy) { return static_cast<RpHAnimHierarchyFlag>(hierarchy->flags); }
inline RpHAnimHierarchy* RpHAnimHierarchySetFlags(RpHAnimHierarchy* hierarchy, RpHAnimHierarchyFlag flags)
{
    hierarchy->flags = flags;
    return hierarchy;
}
inline RpHAnimAnimation* RpHAnimHierarchyGetCurrentAnim(RpHAnimHierarchy* hierarchy)
{
    return RtAnimInterpolatorGetCurrentAnim(hierarchy->currentAnim);
}
inline RwBool RpHAnimHierarchySetCurrentAnim(RpHAnimHierarchy* hierarchy, RpHAnimAnimation* animation)
{
    return RtAnimInterpolatorSetCurrentAnim(hierarchy->currentAnim, animation);
}
inline RwBool RpHAnimHierarchySetCurrentAnimTime(RpHAnimHierarchy* hierarchy, RwReal time)
{
    return RtAnimInterpolatorSetCurrentTime(hierarchy->currentAnim, time);
}
inline RwBool RpHAnimHierarchyAddAnimTime(RpHAnimHierarchy* hierarchy, RwReal time)
{
    return RtAnimInterpolatorAddAnimTime(hierarchy->currentAnim, time);
}
inline RwBool RpHAnimHierarchySubAnimTime(RpHAnimHierarchy* hierarchy, RwReal time)
{
    return RtAnimInterpolatorSubAnimTime(hierarchy->currentAnim, time);
}
inline RwBool RpHAnimHierarchyBlend(RpHAnimHierarchy* out, RpHAnimHierarchy* in1, RpHAnimHierarchy* in2, RwReal alpha)
{
    return RtAnimInterpolatorBlend(out->currentAnim, in1->currentAnim, in2->currentAnim, alpha);
}
inline RwBool RpHAnimHierarchyAddTogether(RpHAnimHierarchy* out, RpHAnimHierarchy* in1, RpHAnimHierarchy* in2)
{
    return RtAnimInterpolatorAddTogether(out->currentAnim, in1->currentAnim, in2->currentAnim);
}
inline RwBool RpHAnimHierarchySetKeyFrameCallBacks(RpHAnimHierarchy* hierarchy, RwInt32 keyFrameTypeID)
{
    return RtAnimInterpolatorSetKeyFrameCallBacks(hierarchy->currentAnim, keyFrameTypeID);
}
inline void RpHAnimHierarchySetAnimCallBack(RpHAnimHierarchy* hierarchy, RtAnimCallBack callback, RwReal time, void* data)
{
    RtAnimInterpolatorSetAnimCallBack(hierarchy->currentAnim, callback, time, data);
}
inline void RpHAnimHierarchySetAnimLoopCallBack(RpHAnimHierarchy* hierarchy, RtAnimCallBack callback, void* data)
{
    RtAnimInterpolatorSetAnimLoopCallBack(hierarchy->currentAnim, callback, data);
}
inline RwBool RpHAnimHierarchyBlendSubHierarchy(RpHAnimHierarchy* out, RpHAnimHierarchy* in1, RpHAnimHierarchy* in2, RwReal alpha)
{
    return RtAnimInterpolatorBlendSubInterpolator(out->currentAnim, in1->currentAnim, in2->currentAnim, alpha);
}
inline RwBool RpHAnimHierarchyAddSubHierarchy(RpHAnimHierarchy* out, RpHAnimHierarchy* main, RpHAnimHierarchy* sub)
{
    return RtAnimInterpolatorAddSubInterpolator(out->currentAnim, main->currentAnim, sub->currentAnim);
}
inline RwBool RpHAnimHierarchyCopy(RpHAnimHierarchy* out, RpHAnimHierarchy* in)
{
    return RtAnimInterpolatorCopy(out->currentAnim, in->currentAnim);
}
#endif // __AML_PSDK_RPHANIM_H
