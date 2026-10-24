#ifndef __AML_PSDK_RTANIM_H
#define __AML_PSDK_RTANIM_H

#include "RwStream.h"
#include "RwLinks.h"

struct RtAnimAnimation;
struct RtAnimInterpolator;

typedef void (*RtAnimKeyFrameApplyCallBack)(void*, void*);
typedef void (*RtAnimKeyFrameBlendCallBack)(void*, void*, void*, RwReal);
typedef void (*RtAnimKeyFrameInterpolateCallBack)(void*, void*, void*, RwReal, void*);
typedef void (*RtAnimKeyFrameAddCallBack)(void*, void*, void*);
typedef void (*RtAnimKeyFrameMulRecipCallBack)(void*, void*);
typedef RtAnimAnimation* (*RtAnimKeyFrameStreamReadCallBack)(RwStream*, RtAnimAnimation*);
typedef RwBool (*RtAnimKeyFrameStreamWriteCallBack)(const RtAnimAnimation*, RwStream*);
typedef RwInt32 (*RtAnimKeyFrameStreamGetSizeCallBack)(const RtAnimAnimation*);
typedef RtAnimInterpolator* (*RtAnimCallBack)(RtAnimInterpolator*, void*);

struct RtAnimKeyFrameHeader
{
    void* prevFrame;
    RwReal time;
};
CHECKSIZE(RtAnimKeyFrameHeader, 0x8, 0x10);

struct RtAnimInterpFrameHeader
{
    RtAnimKeyFrameHeader* keyFrame1;
    RtAnimKeyFrameHeader* keyFrame2;
};
CHECKSIZE(RtAnimInterpFrameHeader, 0x8, 0x10);

struct RtAnimInterpolatorInfo
{
    RwInt32 typeID;
    RwInt32 interpKeyFrameSize;
    RwInt32 animKeyFrameSize;
    RtAnimKeyFrameApplyCallBack keyFrameApplyCB;
    RtAnimKeyFrameBlendCallBack keyFrameBlendCB;
    RtAnimKeyFrameInterpolateCallBack keyFrameInterpolateCB;
    RtAnimKeyFrameAddCallBack keyFrameAddCB;
    RtAnimKeyFrameMulRecipCallBack keyFrameMulRecipCB;
    RtAnimKeyFrameStreamReadCallBack keyFrameStreamReadCB;
    RtAnimKeyFrameStreamWriteCallBack keyFrameStreamWriteCB;
    RtAnimKeyFrameStreamGetSizeCallBack keyFrameStreamGetSizeCB;
    RwInt32 customDataSize;
};
CHECKSIZE(RtAnimInterpolatorInfo, 0x30, 0x58);

struct RtAnimAnimation
{
    RtAnimInterpolatorInfo* interpInfo;
    RwInt32 numFrames;
    RwInt32 flags;
    RwReal duration;
    void* pFrames;
    void* customData;
};
CHECKSIZE(RtAnimAnimation, 0x18, 0x28);

struct RtAnimInterpolator
{
    RtAnimAnimation* pCurrentAnim;
    RwReal currentTime;
    void* pNextFrame;
    RtAnimCallBack pAnimCallBack;
    void* pAnimCallBackData;
    RwReal animCallBackTime;
    RtAnimCallBack pAnimLoopCallBack;
    void* pAnimLoopCallBackData;
    RwInt32 maxInterpKeyFrameSize;
    RwInt32 currentInterpKeyFrameSize;
    RwInt32 currentAnimKeyFrameSize;
    RwInt32 numNodes;
    RwBool isSubInterpolator;
    RwInt32 offsetInParent;
    RtAnimInterpolator* parentAnimation;
    RtAnimKeyFrameApplyCallBack keyFrameApplyCB;
    RtAnimKeyFrameBlendCallBack keyFrameBlendCB;
    RtAnimKeyFrameInterpolateCallBack keyFrameInterpolateCB;
    RtAnimKeyFrameAddCallBack keyFrameAddCB;
};
CHECKSIZE(RtAnimInterpolator, 0x4C, 0x80);

inline RwInt32 RtAnimAnimationGetTypeID(RtAnimAnimation* animation) { return animation->interpInfo->typeID; }
inline RtAnimAnimation* RtAnimInterpolatorGetCurrentAnim(RtAnimInterpolator* animI) { return animI->pCurrentAnim; }

DECL_FASTCALL_SIMPLE_GLO(RtAnimAnimationFreeListCreateParams, _Z35RtAnimAnimationFreeListCreateParamsii, void, RwInt32 blockSize, RwInt32 numBlocksToPrealloc);
DECL_FASTCALL_SIMPLE_GLO(RtAnimInterpolatorAddSubInterpolator, _Z36RtAnimInterpolatorAddSubInterpolatorP18RtAnimInterpolatorS0_S0_, RwBool, RtAnimInterpolator* outAnim, RtAnimInterpolator* mainAnim, RtAnimInterpolator* subAnim);
DECL_FASTCALL_SIMPLE_GLO(RtAnimInterpolatorSetAnimLoopCallBack, _Z37RtAnimInterpolatorSetAnimLoopCallBackP18RtAnimInterpolatorPFS0_S0_PvES1_, void, RtAnimInterpolator* anim, RtAnimCallBack callBack, void* data);
DECL_FASTCALL_SIMPLE_GLO(RtAnimInterpolatorCopy, _Z22RtAnimInterpolatorCopyP18RtAnimInterpolatorS0_, RwBool, RtAnimInterpolator* outAnim, RtAnimInterpolator* inAnim);
DECL_FASTCALL_SIMPLE_GLO(RtAnimInterpolatorSetCurrentTime, _Z32RtAnimInterpolatorSetCurrentTimeP18RtAnimInterpolatorf, RwBool, RtAnimInterpolator* anim, RwReal time);
DECL_FASTCALL_SIMPLE_GLO(RtAnimInterpolatorSetKeyFrameCallBacks, _Z38RtAnimInterpolatorSetKeyFrameCallBacksP18RtAnimInterpolatori, RwBool, RtAnimInterpolator* anim, RwInt32 keyFrameTypeID);
DECL_FASTCALL_SIMPLE_GLO(RtAnimAnimationStreamGetSize, _Z28RtAnimAnimationStreamGetSizePK15RtAnimAnimation, RwInt32, RtAnimAnimation const* animation);
DECL_FASTCALL_SIMPLE_GLO(RtAnimAnimationStreamRead, _Z25RtAnimAnimationStreamReadP8RwStream, RtAnimAnimation*, RwStream* stream);
DECL_FASTCALL_SIMPLE_GLO(RtAnimAnimationDestroy, _Z22RtAnimAnimationDestroyP15RtAnimAnimation, RwBool, RtAnimAnimation* animation);
DECL_FASTCALL_SIMPLE_GLO(RtAnimInterpolatorAddTogether, _Z29RtAnimInterpolatorAddTogetherP18RtAnimInterpolatorS0_S0_, RwBool, RtAnimInterpolator* outAnim, RtAnimInterpolator* inAnim1, RtAnimInterpolator* inAnim2);
DECL_FASTCALL_SIMPLE_GLO(RtAnimGetInterpolatorInfo, _Z25RtAnimGetInterpolatorInfoi, RtAnimInterpolatorInfo*, RwInt32 typeID);
DECL_FASTCALL_SIMPLE_GLO(RtAnimInterpolatorSetAnimCallBack, _Z33RtAnimInterpolatorSetAnimCallBackP18RtAnimInterpolatorPFS0_S0_PvEfS1_, void, RtAnimInterpolator* anim, RtAnimCallBack callBack, RwReal time, void* data);
DECL_FASTCALL_SIMPLE_GLO(RtAnimAnimationCreate, _Z21RtAnimAnimationCreateiiif, RtAnimAnimation*, RwInt32 typeID, RwInt32 numFrames, RwInt32 flags, RwReal duration);
DECL_FASTCALL_SIMPLE_GLO(RtAnimInterpolatorAddAnimTime, _Z29RtAnimInterpolatorAddAnimTimeP18RtAnimInterpolatorf, RwBool, RtAnimInterpolator* interp, RwReal time);
DECL_FASTCALL_SIMPLE_GLO(RtAnimInterpolatorSubAnimTime, _Z29RtAnimInterpolatorSubAnimTimeP18RtAnimInterpolatorf, RwBool, RtAnimInterpolator* interp, RwReal time);
DECL_FASTCALL_SIMPLE_GLO(RtAnimInterpolatorCreate, _Z24RtAnimInterpolatorCreateii, RtAnimInterpolator*, RwInt32 numNodes, RwInt32 maxInterpKeyFrameSize);
DECL_FASTCALL_SIMPLE_GLO(RtAnimAnimationStreamWrite, _Z26RtAnimAnimationStreamWritePK15RtAnimAnimationP8RwStream, RwBool, RtAnimAnimation const* animation, RwStream* stream);
DECL_FASTCALL_SIMPLE_GLO(RtAnimInterpolatorBlendSubInterpolator, _Z38RtAnimInterpolatorBlendSubInterpolatorP18RtAnimInterpolatorS0_S0_f, RwBool, RtAnimInterpolator* outAnim, RtAnimInterpolator* inAnim1, RtAnimInterpolator* inAnim2, RwReal alpha);
DECL_FASTCALL_SIMPLE_GLO(RtAnimAnimationRead, _Z19RtAnimAnimationReadPKc, RtAnimAnimation*, RwChar const* filename);
DECL_FASTCALL_SIMPLE_GLO(RtAnimInterpolatorSetCurrentAnim, _Z32RtAnimInterpolatorSetCurrentAnimP18RtAnimInterpolatorP15RtAnimAnimation, RwBool, RtAnimInterpolator* animI, RtAnimAnimation* anim);
DECL_FASTCALL_SIMPLE_GLO(RtAnimRegisterInterpolationScheme, _Z33RtAnimRegisterInterpolationSchemeP22RtAnimInterpolatorInfo, RwBool, RtAnimInterpolatorInfo* interpInfo);
DECL_FASTCALL_SIMPLE_GLO(RtAnimInterpolatorCreateSubInterpolator, _Z39RtAnimInterpolatorCreateSubInterpolatorP18RtAnimInterpolatoriii, RtAnimInterpolator*, RtAnimInterpolator* parentAnim, RwInt32 startNode, RwInt32 numNodes, RwInt32 maxInterpKeyFrameSize);
DECL_FASTCALL_SIMPLE_GLO(RtAnimAnimationMakeDelta, _Z24RtAnimAnimationMakeDeltaP15RtAnimAnimationif, RwBool, RtAnimAnimation* animation, RwInt32 numNodes, RwReal time);
DECL_FASTCALL_SIMPLE_GLO(RtAnimAnimationGetNumNodes, _Z26RtAnimAnimationGetNumNodesPK15RtAnimAnimation, RwUInt32, RtAnimAnimation const* animation);
DECL_FASTCALL_SIMPLE_GLO(RtAnimAnimationWrite, _Z20RtAnimAnimationWritePK15RtAnimAnimationPKc, RwBool, RtAnimAnimation const* animation, RwChar const* filename);
DECL_FASTCALL_SIMPLE_GLO(RtAnimInterpolatorDestroy, _Z25RtAnimInterpolatorDestroyP18RtAnimInterpolator, void, RtAnimInterpolator* anim);
DECL_FASTCALL_SIMPLE_GLO(RtAnimInterpolatorBlend, _Z23RtAnimInterpolatorBlendP18RtAnimInterpolatorS0_S0_f, RwBool, RtAnimInterpolator* outAnim, RtAnimInterpolator* inAnim1, RtAnimInterpolator* inAnim2, RwReal alpha);
DECL_FASTCALL_SIMPLE_GLO(RtAnimInitialize, _Z16RtAnimInitializev, RwBool);

DECL_OBJECT_PLT_GLOBAL(RwFreeList*, RtAnimAnimationFreeList, BYBIT(0x676398, 0x84A788));

DECL_OBJECT_PLT_GLOBAL(RwFreeList, RtAnimAnimationFreeListSpace, BYBIT(0x6766EC, 0x84AE30));

DECL_OBJECT_ARRAY_PLT_GLOBAL(RtAnimInterpolatorInfo, RtAnimInterpolatorInfoBlock, BYBIT(0x677A24, 0x84D470));

DECL_OBJECT_PLT_GLOBAL(RwInt32, RtAnimInterpolatorInfoBlockNumEntries, BYBIT(0x67946C, 0x8508F0));

#endif // __AML_PSDK_RTANIM_H
