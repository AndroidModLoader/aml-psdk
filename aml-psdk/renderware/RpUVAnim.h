#ifndef __AML_PSDK_RPUVANIM_H
#define __AML_PSDK_RPUVANIM_H

#include "RtAnim.h"
#include "RwMatrix.h"
#include "RpMaterial.h"

typedef RtAnimAnimation RpUVAnim;

enum RpUVAnimKeyFrameType
{
    rpUVANIMLINEARKEYFRAMES = 0,
    rpUVANIMPARAMKEYFRAMES = 1,
    rpUVANIMFORCEENUMSIZEINT = 2147483647,
};

struct RpUVAnimLinearKeyFrameData
{
    RwReal uv[6];
};
CHECKSIZE(RpUVAnimLinearKeyFrameData, 0x18, 0x18);

struct RpUVAnimParamKeyFrameData
{
    RwReal theta;
    RwReal s0;
    RwReal s1;
    RwReal skew;
    RwReal x;
    RwReal y;
};
CHECKSIZE(RpUVAnimParamKeyFrameData, 0x18, 0x18);

union RpUVAnimKeyFrameData
{
    RpUVAnimLinearKeyFrameData linear;
    RpUVAnimParamKeyFrameData param;
};
CHECKSIZE(RpUVAnimKeyFrameData, 0x18, 0x18);

struct RpUVAnimKeyFrame
{
    RpUVAnimKeyFrame* prevFrame;
    RwReal time;
    RpUVAnimKeyFrameData data;
};
CHECKSIZE(RpUVAnimKeyFrame, 0x20, 0x28);

struct RpUVAnimInterpFrame
{
    RpUVAnimKeyFrame* keyFrame1;
    RpUVAnimKeyFrame* keyFrame2;
    RpUVAnimKeyFrameData data;
};
CHECKSIZE(RpUVAnimInterpFrame, 0x20, 0x28);

DECL_FASTCALL_SIMPLE_GLO(RpUVAnimLinearKeyFrameMulRecip, _Z30RpUVAnimLinearKeyFrameMulRecipPvS_, void, void* pVoidFrame, void* pVoidStart);
DECL_FASTCALL_SIMPLE_GLO(RpUVAnimLinearKeyFrameBlend, _Z27RpUVAnimLinearKeyFrameBlendPvS_S_f, void, void* pVoidOut, void* pVoidIn1, void* pVoidIn2, RwReal fAlpha);
DECL_FASTCALL_SIMPLE_GLO(RpUVAnimLinearKeyFrameApply, _Z27RpUVAnimLinearKeyFrameApplyPvS_, void, void* pMatrix, void* pVoidIFrame);
DECL_FASTCALL_SIMPLE_GLO(RpUVAnimLinearKeyFrameInterpolate, _Z33RpUVAnimLinearKeyFrameInterpolatePvS_S_fS_, void, void* pVoidOut, void* pVoidIn1, void* pVoidIn2, RwReal time, void* customData);
DECL_FASTCALL_SIMPLE_GLO(RpUVAnimLinearKeyFrameDataInitFromMatrix, _Z40RpUVAnimLinearKeyFrameDataInitFromMatrixP26RpUVAnimLinearKeyFrameDataPK11RwMatrixTag, RpUVAnimLinearKeyFrameData*, RpUVAnimLinearKeyFrameData* data, RwMatrix const* matrix);
DECL_FASTCALL_SIMPLE_GLO(RpUVAnimLinearKeyFrameAdd, _Z25RpUVAnimLinearKeyFrameAddPvS_S_, void, void* pVoidOut, void* pVoidIn1, void* pVoidIn2);
DECL_FASTCALL_SIMPLE_GLO(RpUVAnimParamKeyFrameAdd, _Z24RpUVAnimParamKeyFrameAddPvS_S_, void, void* pVoidOut, void* pVoidIn1, void* pVoidIn2);
DECL_FASTCALL_SIMPLE_GLO(RpUVAnimParamKeyFrameDataInitFromMatrix, _Z39RpUVAnimParamKeyFrameDataInitFromMatrixP25RpUVAnimParamKeyFrameDataPK11RwMatrixTag, RpUVAnimParamKeyFrameData*, RpUVAnimParamKeyFrameData* data, RwMatrix const* matrix);
DECL_FASTCALL_SIMPLE_GLO(RpUVAnimParamKeyFrameMulRecip, _Z29RpUVAnimParamKeyFrameMulRecipPvS_, void, void* pVoidFrame, void* pVoidStart);
DECL_FASTCALL_SIMPLE_GLO(RpUVAnimParamKeyFrameApply, _Z26RpUVAnimParamKeyFrameApplyPvS_, void, void* pMatrix, void* pVoidIFrame);
DECL_FASTCALL_SIMPLE_GLO(RpUVAnimParamKeyFrameInterpolate, _Z32RpUVAnimParamKeyFrameInterpolatePvS_S_fS_, void, void* pVoidOut, void* pVoidIn1, void* pVoidIn2, RwReal time, void* customData);
DECL_FASTCALL_SIMPLE_GLO(RpUVAnimParamKeyFrameBlend, _Z26RpUVAnimParamKeyFrameBlendPvS_S_f, void, void* pVoidOut, void* pVoidIn1, void* pVoidIn2, RwReal fAlpha);
DECL_FASTCALL_SIMPLE_GLO(RpUVAnimSetFreeListCreateParams, _Z31RpUVAnimSetFreeListCreateParamsii, void, RwInt32 blockSize, RwInt32 numBlocksToPrealloc);
DECL_FASTCALL_SIMPLE_GLO(RpUVAnimPluginAttach, _Z20RpUVAnimPluginAttachv, RwBool);
DECL_FASTCALL_SIMPLE_GLO(RpUVAnimCreate, _Z14RpUVAnimCreatePKcjjfPj20RpUVAnimKeyFrameType, RpUVAnim*, RwChar const* name, RwUInt32 numNodes, RwUInt32 numFrames, RwReal duration, RwUInt32* nodeIndexToUVChannelMap, RpUVAnimKeyFrameType keyframeType);
DECL_FASTCALL_SIMPLE_GLO(RpUVAnimGetName, _Z15RpUVAnimGetNamePK15RtAnimAnimation, RwChar const*, RpUVAnim const* anim);
DECL_FASTCALL_SIMPLE_GLO(RpUVAnimAddRef, _Z14RpUVAnimAddRefP15RtAnimAnimation, RpUVAnim*, RpUVAnim* anim);
DECL_FASTCALL_SIMPLE_GLO(RpUVAnimDestroy, _Z15RpUVAnimDestroyP15RtAnimAnimation, RwBool, RpUVAnim* anim);
DECL_FASTCALL_SIMPLE_GLO(RpUVAnimKeyFrameStreamGetSize, _Z29RpUVAnimKeyFrameStreamGetSizePK15RtAnimAnimation, RwInt32, RtAnimAnimation const* animation);
DECL_FASTCALL_SIMPLE_GLO(RpUVAnimKeyFrameInit, _Z20RpUVAnimKeyFrameInitPK15RtAnimAnimationP16RpUVAnimKeyFrameS3_fPK11RwMatrixTag, RpUVAnimKeyFrame*, RtAnimAnimation const* animation, RpUVAnimKeyFrame* keyFrame, RpUVAnimKeyFrame* prevFrame, RwReal time, RwMatrix const* matrix);
DECL_FASTCALL_SIMPLE_GLO(RpUVAnimKeyFrameStreamWrite, _Z27RpUVAnimKeyFrameStreamWritePK15RtAnimAnimationP8RwStream, RwBool, RtAnimAnimation const* pAnimation, RwStream* stream);
DECL_FASTCALL_SIMPLE_GLO(RpUVAnimKeyFrameStreamRead, _Z26RpUVAnimKeyFrameStreamReadP8RwStreamP15RtAnimAnimation, RtAnimAnimation*, RwStream* stream, RtAnimAnimation* pAnimation);

typedef RtAnimInterpolator RpUVAnimInterpolator;

struct RpUVAnimMaterialGlobalVars
{
    RwInt32 engineOffset;
};

CHECKSIZE(RpUVAnimMaterialGlobalVars, 0x4, 0x4);
struct RpUVAnimMaterialExtension
{
    RwMatrix* uv[2];
    RtAnimInterpolator* interp[8];
};

CHECKSIZE(RpUVAnimMaterialExtension, 0x28, 0x50);
DECL_FASTCALL_SIMPLE_GLO(RpMaterialUVAnimGetInterpolator, _Z31RpMaterialUVAnimGetInterpolatorP10RpMaterialj, RpUVAnimInterpolator*, RpMaterial* material, RwUInt32 slot);
DECL_FASTCALL_SIMPLE_GLO(RpMaterialUVAnimExists, _Z22RpMaterialUVAnimExistsPK10RpMaterial, RwBool, RpMaterial const* material);
DECL_FASTCALL_SIMPLE_GLO(RpMaterialUVAnimAddAnimTime, _Z27RpMaterialUVAnimAddAnimTimeP10RpMaterialf, RpMaterial*, RpMaterial* material, RwReal deltaTime);
DECL_FASTCALL_SIMPLE_GLO(RpMaterialUVAnimApplyUpdate, _Z27RpMaterialUVAnimApplyUpdateP10RpMaterial, RpMaterial*, RpMaterial* material);
DECL_FASTCALL_SIMPLE_GLO(RpMaterialSetUVAnim, _Z19RpMaterialSetUVAnimP10RpMaterialP15RtAnimAnimationj, RpMaterial*, RpMaterial* material, RpUVAnim* anim, RwUInt32 slot);
DECL_FASTCALL_SIMPLE_GLO(RpMaterialUVAnimSetInterpolator, _Z31RpMaterialUVAnimSetInterpolatorP10RpMaterialP18RtAnimInterpolatorj, RpMaterial*, RpMaterial* material, RpUVAnimInterpolator* interp, RwUInt32 slot);
DECL_FASTCALL_SIMPLE_GLO(RpMaterialUVAnimSubAnimTime, _Z27RpMaterialUVAnimSubAnimTimeP10RpMaterialf, RpMaterial*, RpMaterial* material, RwReal deltaTime);
DECL_FASTCALL_SIMPLE_GLO(RpMaterialUVAnimSetCurrentTime, _Z30RpMaterialUVAnimSetCurrentTimeP10RpMaterialf, RpMaterial*, RpMaterial* material, RwReal time);

DECL_OBJECT_PLT_GLOBAL(RpUVAnimMaterialGlobalVars, RpUVAnimMaterialGlobals, BYBIT(0x678478, 0x84E908));
DECL_OBJECT_PLT_GLOBAL(RtAnimInterpolatorInfo, _rpUVAnimLinearInterpolatorInfo, BYBIT(0x678360, 0x84E6D8));
DECL_OBJECT_PLT_GLOBAL(RtAnimInterpolatorInfo, _rpUVAnimParamInterpolatorInfo, BYBIT(0x6792B4, 0x850580));
DECL_OBJECT_PLT_GLOBAL(const RwV3d, rpUVAnimPivot, BYBIT(0x679184, 0x850330));

#endif // __AML_PSDK_RPUVANIM_H
