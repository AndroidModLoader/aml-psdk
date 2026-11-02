#ifndef __AML_PSDK_RTANIM_H
#define __AML_PSDK_RTANIM_H

#include "RwStream.h"
#include "RwLinks.h"

struct RtAnimAnimation;
struct RtAnimInterpolator;

typedef void (*RtAnimKeyFrameApplyCallBack)(void*, void*);
typedef void (*RtAnimKeyFrameBlendCallBack)(void*, void*, void*, RwReal);
#ifdef GTAVC
typedef void (*RtAnimKeyFrameInterpolateCallBack)(void*, void*, void*, RwReal);
#else
typedef void (*RtAnimKeyFrameInterpolateCallBack)(void*, void*, void*, RwReal, void*);
#endif
typedef void (*RtAnimKeyFrameAddCallBack)(void*, void*, void*);
typedef void (*RtAnimKeyFrameMulRecipCallBack)(void*, void*);
typedef RtAnimAnimation* (*RtAnimKeyFrameStreamReadCallBack)(RwStream*, RtAnimAnimation*);
#ifdef GTAVC
typedef RwBool (*RtAnimKeyFrameStreamWriteCallBack)(RtAnimAnimation*, RwStream*);
#else
typedef RwBool (*RtAnimKeyFrameStreamWriteCallBack)(const RtAnimAnimation*, RwStream*);
#endif
#ifdef GTAVC
typedef RwInt32 (*RtAnimKeyFrameStreamGetSizeCallBack)(RtAnimAnimation*);
#else
typedef RwInt32 (*RtAnimKeyFrameStreamGetSizeCallBack)(const RtAnimAnimation*);
#endif
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
    #ifdef GTASA
    RwInt32 animKeyFrameSize;
    #endif
    RtAnimKeyFrameApplyCallBack keyFrameApplyCB;
    RtAnimKeyFrameBlendCallBack keyFrameBlendCB;
    RtAnimKeyFrameInterpolateCallBack keyFrameInterpolateCB;
    RtAnimKeyFrameAddCallBack keyFrameAddCB;
    RtAnimKeyFrameMulRecipCallBack keyFrameMulRecipCB;
    RtAnimKeyFrameStreamReadCallBack keyFrameStreamReadCB;
    RtAnimKeyFrameStreamWriteCallBack keyFrameStreamWriteCB;
    RtAnimKeyFrameStreamGetSizeCallBack keyFrameStreamGetSizeCB;
    #ifdef GTASA
    RwInt32 customDataSize;
    #endif
};
#ifdef GTAVC
CHECKSIZE(RtAnimInterpolatorInfo, 0x28, 0x48);
#else
CHECKSIZE(RtAnimInterpolatorInfo, 0x30, 0x58);
#endif

struct RtAnimAnimation
{
    RtAnimInterpolatorInfo* interpInfo;
    RwInt32 numFrames;
    RwInt32 flags;
    RwReal duration;
    void* pFrames;
    #ifdef GTASA
    void* customData;
    #endif
};
#ifdef GTAVC
CHECKSIZE(RtAnimAnimation, 0x14, 0x20);
#else
CHECKSIZE(RtAnimAnimation, 0x18, 0x28);
#endif

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
    #ifdef GTASA
    RwInt32 currentAnimKeyFrameSize;
    #endif
    RwInt32 numNodes;
    RwBool isSubInterpolator;
    RwInt32 offsetInParent;
    RtAnimInterpolator* parentAnimation;
    RtAnimKeyFrameApplyCallBack keyFrameApplyCB;
    RtAnimKeyFrameBlendCallBack keyFrameBlendCB;
    RtAnimKeyFrameInterpolateCallBack keyFrameInterpolateCB;
    RtAnimKeyFrameAddCallBack keyFrameAddCB;
};
#ifdef GTAVC
CHECKSIZE(RtAnimInterpolator, 0x48, 0x80);
#else
CHECKSIZE(RtAnimInterpolator, 0x4C, 0x80);
#endif

inline RwInt32 RtAnimAnimationGetTypeID(RtAnimAnimation* animation) { return animation->interpInfo->typeID; }
inline RtAnimAnimation* RtAnimInterpolatorGetCurrentAnim(RtAnimInterpolator* animI) { return animI->pCurrentAnim; }

DECL_FASTCALL_SIMPLE_GLO(RtAnimAnimationFreeListCreateParams, _Z35RtAnimAnimationFreeListCreateParamsii, void, RwInt32 blockSize, RwInt32 numBlocksToPrealloc);
DECL_FASTCALL_SIMPLE_GLO(RtAnimInterpolatorAddSubInterpolator, _Z36RtAnimInterpolatorAddSubInterpolatorP18RtAnimInterpolatorS0_S0_, RwBool, RtAnimInterpolator* outAnim, RtAnimInterpolator* mainAnim, RtAnimInterpolator* subAnim);
DECL_FASTCALL_SIMPLE_GLO(RtAnimInterpolatorSetAnimLoopCallBack, _Z37RtAnimInterpolatorSetAnimLoopCallBackP18RtAnimInterpolatorPFS0_S0_PvES1_, void, RtAnimInterpolator* anim, RtAnimCallBack callBack, void* data);
DECL_FASTCALL_SIMPLE_GLO(RtAnimInterpolatorCopy, _Z22RtAnimInterpolatorCopyP18RtAnimInterpolatorS0_, RwBool, RtAnimInterpolator* outAnim, RtAnimInterpolator* inAnim);
DECL_FASTCALL_SIMPLE_GLO(RtAnimInterpolatorSetCurrentTime, _Z32RtAnimInterpolatorSetCurrentTimeP18RtAnimInterpolatorf, RwBool, RtAnimInterpolator* anim, RwReal time);
DECL_FASTCALL_SIMPLE_GLO(RtAnimInterpolatorSetKeyFrameCallBacks, _Z38RtAnimInterpolatorSetKeyFrameCallBacksP18RtAnimInterpolatori, RwBool, RtAnimInterpolator* anim, RwInt32 keyFrameTypeID);
#ifdef GTAVC
DECL_FASTCALL_SIMPLE_GLO(RtAnimAnimationStreamGetSize, _Z28RtAnimAnimationStreamGetSizeP15RtAnimAnimation, RwInt32, RtAnimAnimation* animation);
#else
DECL_FASTCALL_SIMPLE_GLO(RtAnimAnimationStreamGetSize, _Z28RtAnimAnimationStreamGetSizePK15RtAnimAnimation, RwInt32, RtAnimAnimation const* animation);
#endif
DECL_FASTCALL_SIMPLE_GLO(RtAnimAnimationStreamRead, _Z25RtAnimAnimationStreamReadP8RwStream, RtAnimAnimation*, RwStream* stream);
DECL_FASTCALL_SIMPLE_GLO(RtAnimAnimationDestroy, _Z22RtAnimAnimationDestroyP15RtAnimAnimation, RwBool, RtAnimAnimation* animation);
DECL_FASTCALL_SIMPLE_GLO(RtAnimInterpolatorAddTogether, _Z29RtAnimInterpolatorAddTogetherP18RtAnimInterpolatorS0_S0_, RwBool, RtAnimInterpolator* outAnim, RtAnimInterpolator* inAnim1, RtAnimInterpolator* inAnim2);
DECL_FASTCALL_SIMPLE_GLO(RtAnimGetInterpolatorInfo, _Z25RtAnimGetInterpolatorInfoi, RtAnimInterpolatorInfo*, RwInt32 typeID);
DECL_FASTCALL_SIMPLE_GLO(RtAnimInterpolatorSetAnimCallBack, _Z33RtAnimInterpolatorSetAnimCallBackP18RtAnimInterpolatorPFS0_S0_PvEfS1_, void, RtAnimInterpolator* anim, RtAnimCallBack callBack, RwReal time, void* data);
DECL_FASTCALL_SIMPLE_GLO(RtAnimAnimationCreate, _Z21RtAnimAnimationCreateiiif, RtAnimAnimation*, RwInt32 typeID, RwInt32 numFrames, RwInt32 flags, RwReal duration);
DECL_FASTCALL_SIMPLE_GLO(RtAnimInterpolatorAddAnimTime, _Z29RtAnimInterpolatorAddAnimTimeP18RtAnimInterpolatorf, RwBool, RtAnimInterpolator* interp, RwReal time);
DECL_FASTCALL_SIMPLE_GLO(RtAnimInterpolatorSubAnimTime, _Z29RtAnimInterpolatorSubAnimTimeP18RtAnimInterpolatorf, RwBool, RtAnimInterpolator* interp, RwReal time);
DECL_FASTCALL_SIMPLE_GLO(RtAnimInterpolatorCreate, _Z24RtAnimInterpolatorCreateii, RtAnimInterpolator*, RwInt32 numNodes, RwInt32 maxInterpKeyFrameSize);
#ifdef GTAVC
DECL_FASTCALL_SIMPLE_GLO(RtAnimAnimationStreamWrite, _Z26RtAnimAnimationStreamWriteP15RtAnimAnimationP8RwStream, RwBool, RtAnimAnimation* animation, RwStream* stream);
#else
DECL_FASTCALL_SIMPLE_GLO(RtAnimAnimationStreamWrite, _Z26RtAnimAnimationStreamWritePK15RtAnimAnimationP8RwStream, RwBool, RtAnimAnimation const* animation, RwStream* stream);
#endif
DECL_FASTCALL_SIMPLE_GLO(RtAnimInterpolatorBlendSubInterpolator, _Z38RtAnimInterpolatorBlendSubInterpolatorP18RtAnimInterpolatorS0_S0_f, RwBool, RtAnimInterpolator* outAnim, RtAnimInterpolator* inAnim1, RtAnimInterpolator* inAnim2, RwReal alpha);
DECL_FASTCALL_SIMPLE_GLO(RtAnimAnimationRead, _Z19RtAnimAnimationReadPKc, RtAnimAnimation*, RwChar const* filename);
DECL_FASTCALL_SIMPLE_GLO(RtAnimInterpolatorSetCurrentAnim, _Z32RtAnimInterpolatorSetCurrentAnimP18RtAnimInterpolatorP15RtAnimAnimation, RwBool, RtAnimInterpolator* animI, RtAnimAnimation* anim);
DECL_FASTCALL_SIMPLE_GLO(RtAnimRegisterInterpolationScheme, _Z33RtAnimRegisterInterpolationSchemeP22RtAnimInterpolatorInfo, RwBool, RtAnimInterpolatorInfo* interpInfo);
DECL_FASTCALL_SIMPLE_GLO(RtAnimInterpolatorCreateSubInterpolator, _Z39RtAnimInterpolatorCreateSubInterpolatorP18RtAnimInterpolatoriii, RtAnimInterpolator*, RtAnimInterpolator* parentAnim, RwInt32 startNode, RwInt32 numNodes, RwInt32 maxInterpKeyFrameSize);
DECL_FASTCALL_SIMPLE_GLO(RtAnimAnimationMakeDelta, _Z24RtAnimAnimationMakeDeltaP15RtAnimAnimationif, RwBool, RtAnimAnimation* animation, RwInt32 numNodes, RwReal time);
#ifdef GTAVC
DECL_FASTCALL_SIMPLE_GLO(RtAnimAnimationGetNumNodes, _Z26RtAnimAnimationGetNumNodesP15RtAnimAnimation, RwUInt32, RtAnimAnimation* animation);
#else
DECL_FASTCALL_SIMPLE_GLO(RtAnimAnimationGetNumNodes, _Z26RtAnimAnimationGetNumNodesPK15RtAnimAnimation, RwUInt32, RtAnimAnimation const* animation);
#endif
#ifdef GTAVC
DECL_FASTCALL_SIMPLE_GLO(RtAnimAnimationWrite, _Z20RtAnimAnimationWriteP15RtAnimAnimationPKc, RwBool, RtAnimAnimation* animation, RwChar const* filename);
#else
DECL_FASTCALL_SIMPLE_GLO(RtAnimAnimationWrite, _Z20RtAnimAnimationWritePK15RtAnimAnimationPKc, RwBool, RtAnimAnimation const* animation, RwChar const* filename);
#endif
DECL_FASTCALL_SIMPLE_GLO(RtAnimInterpolatorDestroy, _Z25RtAnimInterpolatorDestroyP18RtAnimInterpolator, void, RtAnimInterpolator* anim);
DECL_FASTCALL_SIMPLE_GLO(RtAnimInterpolatorBlend, _Z23RtAnimInterpolatorBlendP18RtAnimInterpolatorS0_S0_f, RwBool, RtAnimInterpolator* outAnim, RtAnimInterpolator* inAnim1, RtAnimInterpolator* inAnim2, RwReal alpha);
DECL_FASTCALL_SIMPLE_GLO(RtAnimInitialize, _Z16RtAnimInitializev, RwBool);

#ifdef GTAVC
DECL_OBJECT_PLT_GLOBAL(RwFreeList*, RtAnimAnimationFreeList, BYBIT(0x3963b8, 0x57a768));
#else
DECL_OBJECT_PLT_GLOBAL(RwFreeList*, RtAnimAnimationFreeList, BYBIT(0x676398, 0x84A788));
#endif

#ifdef GTAVC
DECL_OBJECT_PLT_GLOBAL(RwFreeList, RtAnimAnimationFreeListSpace, BYBIT(0x396704, 0x57ae18));
#else
DECL_OBJECT_PLT_GLOBAL(RwFreeList, RtAnimAnimationFreeListSpace, BYBIT(0x6766EC, 0x84AE30));
#endif

#ifdef GTAVC
DECL_OBJECT_ARRAY_PLT_GLOBAL(RtAnimInterpolatorInfo, RtAnimInterpolatorInfoBlock, BYBIT(0x3957fc, 0x579058));
#else
DECL_OBJECT_ARRAY_PLT_GLOBAL(RtAnimInterpolatorInfo, RtAnimInterpolatorInfoBlock, BYBIT(0x677A24, 0x84D470));
#endif

#ifdef GTAVC
DECL_OBJECT_PLT_GLOBAL(RwInt32, RtAnimInterpolatorInfoBlockNumEntries, BYBIT(0x3962f4, 0x57a5f0));
#else
DECL_OBJECT_PLT_GLOBAL(RwInt32, RtAnimInterpolatorInfoBlockNumEntries, BYBIT(0x67946C, 0x8508F0));
#endif

inline RwReal RtAnimAnimationGetDuration(const RtAnimAnimation* animation) { return animation->duration; }
inline RwInt32 RtAnimAnimationGetNumFrames(const RtAnimAnimation* animation) { return animation->numFrames; }
inline void* RtAnimAnimationGetKeyFrames(RtAnimAnimation* animation) { return animation->pFrames; }
inline RwReal RtAnimInterpolatorGetCurrentTime(const RtAnimInterpolator* animI) { return animI->currentTime; }
inline RwInt32 RtAnimInterpolatorGetNumNodes(const RtAnimInterpolator* animI) { return animI->numNodes; }
inline void* RtAnimInterpolatorGetKeyFrame(RtAnimInterpolator* animI, RwInt32 nodeIndex)
{
    return reinterpret_cast<RwUInt8*>(animI + 1) + nodeIndex * animI->currentInterpKeyFrameSize;
}
#endif // __AML_PSDK_RTANIM_H
