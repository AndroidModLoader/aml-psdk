
#ifndef __AML_PSDK_RWFRAME_H
#define __AML_PSDK_RWFRAME_H

#include "RwObject.h"
#include "RwLinks.h"
#include "RwMatrix.h"

struct RwMatrix;

struct RwFrame
{
    RwObject            object;
    RwLLLink            inDirtyListLink;
    RwMatrix            modelling;
    RwMatrix            ltm;
    RwLinkList          objectList;
    RwFrame            *child;
    RwFrame            *next;
    RwFrame            *root;
};

typedef RwFrame *(*RwFrameCallBack)(RwFrame *frame, void *data);

DECL_FASTCALL_SIMPLE_GLO(RwFrameSetFreeListCreateParams, _Z30RwFrameSetFreeListCreateParamsii, void, RwInt32 blockSize, RwInt32 numBlocksToPrealloc);
DECL_FASTCALL_SIMPLE_GLO(_rwFrameOpen, _Z12_rwFrameOpenPvii, void*, void* instance, RwInt32 offset, RwInt32 size);
DECL_FASTCALL_SIMPLE_GLO(_rwFrameClose, _Z13_rwFrameClosePvii, void*, void* instance, RwInt32 offset, RwInt32 size);
DECL_FASTCALL_SIMPLE_GLO(_rwFrameCloneAndLinkClones, _Z26_rwFrameCloneAndLinkClonesP7RwFrame, RwFrame*, RwFrame* root);
DECL_FASTCALL_SIMPLE_GLO(rwFrameCloneRecurse, _ZL19rwFrameCloneRecurseP7RwFrameS0_, RwFrame*, RwFrame* oldFrame, RwFrame* newRoot);
DECL_FASTCALL_SIMPLE_GLO(RwFrameUpdateObjects, _Z20RwFrameUpdateObjectsP7RwFrame, RwFrame*, RwFrame* frame);
DECL_FASTCALL_SIMPLE_GLO(_rwFramePurgeClone, _Z18_rwFramePurgeCloneP7RwFrame, RwFrame*, RwFrame* root);
DECL_FASTCALL_SIMPLE_GLO(rwSetHierarchyRoot, _ZL18rwSetHierarchyRootP7RwFrameS0_, void, RwFrame* frame, RwFrame* root);
DECL_FASTCALL_SIMPLE_GLO(RwFrameCloneHierarchy, _Z21RwFrameCloneHierarchyP7RwFrame, RwFrame*, RwFrame* root);
DECL_FASTCALL_SIMPLE_GLO(RwFrameDirty, _Z12RwFrameDirtyPK7RwFrame, RwBool, const RwFrame* frame);
DECL_FASTCALL_SIMPLE_GLO(_rwFrameInit, _Z12_rwFrameInitP7RwFrame, void, RwFrame* frame);
DECL_FASTCALL_SIMPLE_GLO(RwFrameCreate, _Z13RwFrameCreatev, RwFrame*, );
DECL_FASTCALL_SIMPLE_GLO(RwFrameInit, _Z11RwFrameInitP7RwFrame, RwBool, RwFrame* frame);
DECL_FASTCALL_SIMPLE_GLO(_rwFrameDeInit, _Z14_rwFrameDeInitP7RwFrame, void, RwFrame* frame);
DECL_FASTCALL_SIMPLE_GLO(RwFrameRemoveChild, _Z18RwFrameRemoveChildP7RwFrame, RwFrame*, RwFrame* child);
DECL_FASTCALL_SIMPLE_GLO(RwFrameDestroy, _Z14RwFrameDestroyP7RwFrame, RwBool, RwFrame* frame);
DECL_FASTCALL_SIMPLE_GLO(RwFrameDeInit, _Z13RwFrameDeInitP7RwFrame, RwBool, RwFrame* frame);
DECL_FASTCALL_SIMPLE_GLO(RwFrameDestroyHierarchy, _Z23RwFrameDestroyHierarchyP7RwFrame, RwBool, RwFrame* frame);
DECL_FASTCALL_SIMPLE_GLO(rwFrameDestroyRecurse, _ZL21rwFrameDestroyRecurseP7RwFrame, void, RwFrame* frame);
DECL_FASTCALL_SIMPLE_GLO(RwFrameGetLTM, _Z13RwFrameGetLTMP7RwFrame, RwMatrix*, RwFrame* frame);
DECL_FASTCALL_SIMPLE_GLO(RwFrameGetRoot, _Z14RwFrameGetRootPK7RwFrame, RwFrame*, const RwFrame* frame);
DECL_FASTCALL_SIMPLE_GLO(RwFrameAddChild, _Z15RwFrameAddChildP7RwFrameS0_, RwFrame*, RwFrame* parent, RwFrame* child);
DECL_FASTCALL_SIMPLE_GLO(RwFrameForAllChildren, _Z21RwFrameForAllChildrenP7RwFramePFS0_S0_PvES1_, RwFrame*, RwFrame* frame, RwFrameCallBack callBack, void* data);
DECL_FASTCALL_SIMPLE_GLO(RwFrameCount, _Z12RwFrameCountP7RwFrame, RwInt32, RwFrame* frame);
DECL_FASTCALL_SIMPLE_GLO(RwFrameTranslate, _Z16RwFrameTranslateP7RwFramePK5RwV3d15RwOpCombineType, RwFrame*, RwFrame* frame, const RwV3d* translation, RwOpCombineType combineOp);
DECL_FASTCALL_SIMPLE_GLO(RwFrameScale, _Z12RwFrameScaleP7RwFramePK5RwV3d15RwOpCombineType, RwFrame*, RwFrame* frame, const RwV3d* scale, RwOpCombineType combineOp);
DECL_FASTCALL_SIMPLE_GLO(RwFrameTransform, _Z16RwFrameTransformP7RwFramePK11RwMatrixTag15RwOpCombineType, RwFrame*, RwFrame* frame, const RwMatrix* transform, RwOpCombineType combineOp);
DECL_FASTCALL_SIMPLE_GLO(RwFrameRotate, _Z13RwFrameRotateP7RwFramePK5RwV3df15RwOpCombineType, RwFrame*, RwFrame* frame, const RwV3d* axis, RwReal angle, RwOpCombineType combineOp);
DECL_FASTCALL_SIMPLE_GLO(RwFrameSetIdentity, _Z18RwFrameSetIdentityP7RwFrame, RwFrame*, RwFrame* frame);
DECL_FASTCALL_SIMPLE_GLO(RwFrameOrthoNormalize, _Z21RwFrameOrthoNormalizeP7RwFrame, RwFrame*, RwFrame* frame);
DECL_FASTCALL_SIMPLE_GLO(RwFrameForAllObjects, _Z20RwFrameForAllObjectsP7RwFramePFP8RwObjectS2_PvES3_, RwFrame*, RwFrame* frame, RwObjectCallBack callBack, void* data);
DECL_FASTCALL_SIMPLE_GLO(RwFrameSetStaticPluginsSize, _Z27RwFrameSetStaticPluginsSizei, RwBool, RwInt32 size);
DECL_FASTCALL_SIMPLE_GLO(RwFrameRegisterPlugin, _Z21RwFrameRegisterPluginijPFPvS_iiES1_PFS_S_PKviiE, RwInt32, RwInt32 size, RwUInt32 pluginID, RwPluginObjectConstructor constructCB, RwPluginObjectDestructor destructCB, RwPluginObjectCopy copyCB);
DECL_FASTCALL_SIMPLE_GLO(RwFrameGetPluginOffset, _Z22RwFrameGetPluginOffsetj, RwInt32, RwUInt32 pluginID);
DECL_FASTCALL_SIMPLE_GLO(RwFrameValidatePlugins, _Z22RwFrameValidatePluginsPK7RwFrame, RwBool, const RwFrame* frame);

#endif // __AML_PSDK_RWFRAME_H