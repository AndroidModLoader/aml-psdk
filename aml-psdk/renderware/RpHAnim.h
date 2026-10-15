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

struct RtQuat
{
    RwV3d imag;
    RwReal real;
};
CHECKSIZE(RtQuat, 0x10, 0x10);

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
DECL_FASTCALL_SIMPLE_GLO(RpHAnimKeyFrameStreamGetSize, _Z28RpHAnimKeyFrameStreamGetSizePK15RtAnimAnimation, RwInt32, RtAnimAnimation const* animation);
DECL_FASTCALL_SIMPLE_GLO(RpHAnimKeyFrameMulRecip, _Z23RpHAnimKeyFrameMulRecipPvS_, void, void* pVoidFrame, void* pVoidStart);
DECL_FASTCALL_SIMPLE_GLO(RpHAnimKeyFrameBlend, _Z20RpHAnimKeyFrameBlendPvS_S_f, void, void* pVoidOut, void* pVoidIn1, void* pVoidIn2, RwReal fAlpha);
DECL_FASTCALL_SIMPLE_GLO(RpHAnimKeyFrameApply, _Z20RpHAnimKeyFrameApplyPvS_, void, void* pMatrix, void* pVoidIFrame);
DECL_FASTCALL_SIMPLE_GLO(RpHAnimKeyFrameInterpolate, _Z26RpHAnimKeyFrameInterpolatePvS_S_fS_, void, void* pVoidOut, void* pVoidIn1, void* pVoidIn2, RwReal time, void* customData);
DECL_FASTCALL_SIMPLE_GLO(RpHAnimKeyFrameStreamWrite, _Z26RpHAnimKeyFrameStreamWritePK15RtAnimAnimationP8RwStream, RwBool, RtAnimAnimation const* pAnimation, RwStream* stream);
DECL_FASTCALL_SIMPLE_GLO(RpHAnimKeyFrameStreamRead, _Z25RpHAnimKeyFrameStreamReadP8RwStreamP15RtAnimAnimation, RtAnimAnimation*, RwStream* stream, RtAnimAnimation* pAnimation);
DECL_FASTCALL_SIMPLE_GLO(RpHAnimKeyFrameAdd, _Z18RpHAnimKeyFrameAddPvS_S_, void, void* pVoidOut, void* pVoidIn1, void* pVoidIn2);

DECL_OBJECT_PLT_GLOBAL(RpHAnimAtomicGlobalVars, RpHAnimAtomicGlobals, BYBIT(0x676C5C, 0x84B900));

#endif // __AML_PSDK_RPHANIM_H
