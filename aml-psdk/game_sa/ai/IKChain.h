#ifndef __AML_PSDK_SAIKCHAIN_H
#define __AML_PSDK_SAIKCHAIN_H

#include <aml-psdk/game_sa/base/Lists.h>
#include <aml-psdk/renderware/RpHAnim.h>

struct CPed;
struct CEntity;
struct AnimBlendFrameData;

DECL_CLASS(BoneInfo_t)
    // Member values
    i16 boneTag;
    i16 parentBoneTag;
    float poseRots[3];
    float xLimits[2];
    float yLimits[2];
    float zLimits[2];
DECL_CLASS_END()
CHECKSIZE(BoneInfo_t, 0x28, 0x28);

DECL_CLASS_BASED(BoneNode_c, ListItem_c)
    // Construct/Deconstruct functions
    DECL_CTORCALL(BoneNode_c, _ZN10BoneNode_cC2Ev);
    DECL_DTORCALL(BoneNode_c, _ZN10BoneNode_cD2Ev);

    // Member functions
    DECL_THISCALL_HEAD(Init, _ZN10BoneNode_c4InitEiP23RpHAnimBlendInterpFrame, u8, i32 boneTag, RpHAnimBlendInterpFrame* pAnimKeyFrame)
    DECL_THISCALL_TAIL(Init, boneTag, pAnimKeyFrame)
    DECL_THISCALL_HEAD(AddChild, _ZN10BoneNode_c8AddChildEPS_, void, BoneNode_c* pChildBoneNode)
    DECL_THISCALL_TAIL(AddChild, pChildBoneNode)
    DECL_THISCALL_SIMPLE(InitLimits, _ZN10BoneNode_c10InitLimitsEv, void);
    DECL_THISCALL_HEAD(ClampLimitsCurrent, _ZN10BoneNode_c18ClampLimitsCurrentEhhh, void, u8 xAxis, u8 yAxis, u8 zAxis)
    DECL_THISCALL_TAIL(ClampLimitsCurrent, xAxis, yAxis, zAxis)
    DECL_THISCALL_HEAD(ClampLimitsDefault, _ZN10BoneNode_c18ClampLimitsDefaultEhhh, void, u8 xAxis, u8 yAxis, u8 zAxis)
    DECL_THISCALL_TAIL(ClampLimitsDefault, xAxis, yAxis, zAxis)
    DECL_THISCALL_HEAD(GetLimits, _ZN10BoneNode_c9GetLimitsEiPfS0_, void, i32 axis, float* min, float* max)
    DECL_THISCALL_TAIL(GetLimits, axis, min, max)
    DECL_THISCALL_HEAD(SetLimits, _ZN10BoneNode_c9SetLimitsEiff, void, i32 axis, float min, float max)
    DECL_THISCALL_TAIL(SetLimits, axis, min, max)
    DECL_THISCALL_HEAD(Limit, _ZN10BoneNode_c5LimitEf, void, float blend)
    DECL_THISCALL_TAIL(Limit, blend)
    DECL_THISCALL_SIMPLE(GetSpeed, _ZN10BoneNode_c8GetSpeedEv, float);
    DECL_THISCALL_HEAD(SetSpeed, _ZN10BoneNode_c8SetSpeedEf, void, float speed)
    DECL_THISCALL_TAIL(SetSpeed, speed)
    DECL_THISCALL_HEAD(CalcWldMat, _ZN10BoneNode_c10CalcWldMatEP11RwMatrixTag, void, RwMatrix* pParentMat)
    DECL_THISCALL_TAIL(CalcWldMat, pParentMat)
    DECL_THISCALL_HEAD(BlendKeyframe, _ZN10BoneNode_c13BlendKeyframeEf, void, float blend)
    DECL_THISCALL_TAIL(BlendKeyframe, blend)
    DECL_FASTCALL_SIMPLE(QuatToEuler, _ZN10BoneNode_c11QuatToEulerEP6RtQuatP5RwV3d, void, RtQuat* quat, RwV3d* euler);
    DECL_FASTCALL_SIMPLE(EulerToQuat, _ZN10BoneNode_c11EulerToQuatEP5RwV3dP6RtQuat, void, RwV3d* euler, RtQuat* quat);
    DECL_FASTCALL_SIMPLE(GetIdFromBoneTag, _ZN10BoneNode_c16GetIdFromBoneTagEi, i32, i32 boneTag);

    // Member values
    i32 m_boneTag;
    RpHAnimBlendInterpFrame* m_pAnimKeyFrame;
    RtQuat m_keyFrameQuat;
    RwV3d m_keyFrameTrans;
    BoneNode_c* m_parent;
    List_c m_childList;
    RwMatrix m_wldMat;
    RwV3d m_minLimit;
    RwV3d m_maxLimit;
    float m_speed;
DECL_CLASS_END()
CHECKSIZE(BoneNode_c, 0x98, 0xC0);

DECL_CLASS(BoneNodeManager_c)
    // Construct/Deconstruct functions
    DECL_CTORCALL(BoneNodeManager_c, _ZN17BoneNodeManager_cC2Ev);
    DECL_DTORCALL(BoneNodeManager_c, _ZN17BoneNodeManager_cD2Ev);

    // Member functions
    DECL_THISCALL_SIMPLE(Init, _ZN17BoneNodeManager_c4InitEv, u8);
    DECL_THISCALL_SIMPLE(Exit, _ZN17BoneNodeManager_c4ExitEv, void);
    DECL_THISCALL_SIMPLE(Reset, _ZN17BoneNodeManager_c5ResetEv, void);
    DECL_THISCALL_SIMPLE(GetBoneNode, _ZN17BoneNodeManager_c11GetBoneNodeEv, BoneNode_c*);
    DECL_THISCALL_HEAD(ReturnBoneNode, _ZN17BoneNodeManager_c14ReturnBoneNodeEP10BoneNode_c, void, BoneNode_c* pBoneNode)
    DECL_THISCALL_TAIL(ReturnBoneNode, pBoneNode)
    DECL_THISCALL_SIMPLE(GetNumBoneNodesLeft, _ZN17BoneNodeManager_c19GetNumBoneNodesLeftEv, i32);

    // STATIC values
    DECL_OBJECT_ARRAY_PLT(BoneInfo_t, ms_boneInfos, BYBIT(0x67912C, 0x850280));

    // Member values
    BoneNode_c m_boneNodes[128];
    List_c m_boneNodePool;
DECL_CLASS_END()
CHECKSIZE(BoneNodeManager_c, 0x4C0C, 0x6018);

DECL_CLASS_BASED(IKChain_c, ListItem_c)
    // Construct/Deconstruct functions
    DECL_CTORCALL(IKChain_c, _ZN9IKChain_cC2Ev);
    DECL_DTORCALL(IKChain_c, _ZN9IKChain_cD2Ev);

    // Member functions
    DECL_THISCALL_HEAD(Init, _ZN9IKChain_c4InitEPciP4CPedi5RwV3diP7CEntityiS3_fi, u8, char* idString, i32 slotId, CPed* pPed, i32 effectorBoneTag, RwV3d effectorVec, i32 pivotBoneTag, CEntity* pEntity, i32 offsetBoneTag, RwV3d offsetPos, float speed, i32 priority)
    DECL_THISCALL_TAIL(Init, idString, slotId, pPed, effectorBoneTag, effectorVec, pivotBoneTag, pEntity, offsetBoneTag, offsetPos, speed, priority)
    DECL_THISCALL_SIMPLE(Exit, _ZN9IKChain_c4ExitEv, void);
    DECL_THISCALL_HEAD(Update, _ZN9IKChain_c6UpdateEf, void, float deltaTime)
    DECL_THISCALL_TAIL(Update, deltaTime)
    DECL_THISCALL_HEAD(SetBlend, _ZN9IKChain_c8SetBlendEf, void, float blend)
    DECL_THISCALL_TAIL(SetBlend, blend)
    DECL_THISCALL_HEAD(SetOffsetBoneTag, _ZN9IKChain_c16SetOffsetBoneTagEi, void, i32 offsetBoneTag)
    DECL_THISCALL_TAIL(SetOffsetBoneTag, offsetBoneTag)
    DECL_THISCALL_HEAD(SetOffsetPos, _ZN9IKChain_c12SetOffsetPosE5RwV3d, void, RwV3d offsetPos)
    DECL_THISCALL_TAIL(SetOffsetPos, offsetPos)
    DECL_THISCALL_HEAD(ClampLimits, _ZN9IKChain_c11ClampLimitsEihhhi, void, i32 boneTag, u8 xAxis, u8 yAxis, u8 zAxis, i32 current)
    DECL_THISCALL_TAIL(ClampLimits, boneTag, xAxis, yAxis, zAxis, current)
    DECL_THISCALL_HEAD(GetLimits, _ZN9IKChain_c9GetLimitsEiiPfS0_, void, i32 boneTag, i32 axis, float* min, float* max)
    DECL_THISCALL_TAIL(GetLimits, boneTag, axis, min, max)
    DECL_THISCALL_HEAD(SetLimits, _ZN9IKChain_c9SetLimitsEiiff, void, i32 boneTag, i32 axis, float min, float max)
    DECL_THISCALL_TAIL(SetLimits, boneTag, axis, min, max)
    DECL_THISCALL_HEAD(GetBoneSpeed, _ZN9IKChain_c12GetBoneSpeedEi, float, i32 boneTag)
    DECL_THISCALL_TAIL(GetBoneSpeed, boneTag)
    DECL_THISCALL_HEAD(SetBoneSpeed, _ZN9IKChain_c12SetBoneSpeedEif, void, i32 boneTag, float speed)
    DECL_THISCALL_TAIL(SetBoneSpeed, boneTag, speed)
    DECL_THISCALL_SIMPLE(GetPriority, _ZN9IKChain_c11GetPriorityEv, i32);
    DECL_THISCALL_HEAD(UpdateEntity, _ZN9IKChain_c12UpdateEntityEP7CEntity, void, CEntity* pEntity)
    DECL_THISCALL_TAIL(UpdateEntity, pEntity)
    DECL_THISCALL_HEAD(UpdateOffset, _ZN9IKChain_c12UpdateOffsetEi5RwV3d, void, i32 offsetBoneTag, RwV3d offsetPos)
    DECL_THISCALL_TAIL(UpdateOffset, offsetBoneTag, offsetPos)
    DECL_THISCALL_HEAD(UpdateTarget, _ZN9IKChain_c12UpdateTargetEh, void, u8 update)
    DECL_THISCALL_TAIL(UpdateTarget, update)
    DECL_THISCALL_SIMPLE(IsFacingTarget, _ZN9IKChain_c14IsFacingTargetEv, u8);
    DECL_THISCALL_HEAD(IsAtTarget, _ZN9IKChain_c10IsAtTargetEfPf, u8, float range, float* dist)
    DECL_THISCALL_TAIL(IsAtTarget, range, dist)
    DECL_THISCALL_HEAD(SetupBones, _ZN9IKChain_c10SetupBonesEi5RwV3diP18AnimBlendFrameData, void, i32 effectorBoneTag, RwV3d effectorVec, i32 pivotBoneTag, AnimBlendFrameData* frameData)
    DECL_THISCALL_TAIL(SetupBones, effectorBoneTag, effectorVec, pivotBoneTag, frameData)
    DECL_THISCALL_SIMPLE(MoveBonesToTarget, _ZN9IKChain_c17MoveBonesToTargetEv, void);
    DECL_THISCALL_HEAD(GetBoneNodeFromTag, _ZN9IKChain_c18GetBoneNodeFromTagEi, BoneNode_c*, i32 boneTag)
    DECL_THISCALL_TAIL(GetBoneNodeFromTag, boneTag)

    // Helper functions
    inline CPed* GetParentPed() { return m_pPed; }

    // Member values
    CPed* m_pPed;
    i32 m_numBoneNodes;
    BoneNode_c** m_ppBoneNodes;
    RwMatrix* m_pPivotWldMat;
    float m_blend;
    i16 m_effectorBoneTag;
    RwV3d m_effectorVec;
    i16 m_pivotBoneTag;
    CEntity* m_pEntity;
    i32 m_offsetBoneTag;
    RwV3d m_offsetPos;
    float m_speed;
    RwV3d m_targetPos;
    u8 m_updateTarget;
    u8 m_slotId;
    i8 m_priority;
DECL_CLASS_END()
CHECKSIZE(IKChain_c, 0x58, 0x78);

DECL_CLASS(IKChainManager_c)
    // Construct/Deconstruct functions
    DECL_CTORCALL(IKChainManager_c, _ZN16IKChainManager_cC2Ev);
    DECL_DTORCALL(IKChainManager_c, _ZN16IKChainManager_cD2Ev);

    // Member functions
    DECL_THISCALL_SIMPLE(Init, _ZN16IKChainManager_c4InitEv, u8);
    DECL_THISCALL_SIMPLE(Exit, _ZN16IKChainManager_c4ExitEv, void);
    DECL_THISCALL_SIMPLE(Reset, _ZN16IKChainManager_c5ResetEv, void);
    DECL_THISCALL_HEAD(Update, _ZN16IKChainManager_c6UpdateEf, void, float deltaTime)
    DECL_THISCALL_TAIL(Update, deltaTime)
    DECL_THISCALL_HEAD(AddIKChain, _ZN16IKChainManager_c10AddIKChainEPciP4CPedi5RwV3diP7CEntityiS3_fi, IKChain_c*, char* idString, i32 slotId, CPed* pPed, i32 effectorBoneTag, RwV3d effectorVec, i32 pivotBoneTag, CEntity* pEntity, i32 offsetBoneTag, RwV3d offsetPos, float speed, i32 priority)
    DECL_THISCALL_TAIL(AddIKChain, idString, slotId, pPed, effectorBoneTag, effectorVec, pivotBoneTag, pEntity, offsetBoneTag, offsetPos, speed, priority)
    DECL_THISCALL_HEAD(RemoveIKChain, _ZN16IKChainManager_c13RemoveIKChainEP9IKChain_c, void, IKChain_c* pIKChain)
    DECL_THISCALL_TAIL(RemoveIKChain, pIKChain)
    DECL_THISCALL_HEAD(CanAccept, _ZN16IKChainManager_c9CanAcceptEP4CPedf, u8, CPed* pPed, float range)
    DECL_THISCALL_TAIL(CanAccept, pPed, range)
    DECL_THISCALL_HEAD(CanAcceptLookAt, _ZN16IKChainManager_c15CanAcceptLookAtEP4CPed, u8, CPed* pPed)
    DECL_THISCALL_TAIL(CanAcceptLookAt, pPed)
    DECL_THISCALL_HEAD(LookAt, _ZN16IKChainManager_c6LookAtEPcP4CPedP7CEntityiiP5RwV3dhfiih, void, char* idString, CPed* pPed, CEntity* pEntity, i32 time, i32 offsetBoneTag, RwV3d* pOffsetPos, u8 useTorso, float speed, i32 blendTime, i32 priority, u8 fromScript)
    DECL_THISCALL_TAIL(LookAt, idString, pPed, pEntity, time, offsetBoneTag, pOffsetPos, useTorso, speed, blendTime, priority, fromScript)
    DECL_THISCALL_HEAD(IsLooking, _ZN16IKChainManager_c9IsLookingEP4CPed, u8, CPed* pPed)
    DECL_THISCALL_TAIL(IsLooking, pPed)
    DECL_THISCALL_HEAD(GetLookAtEntity, _ZN16IKChainManager_c15GetLookAtEntityEP4CPed, CEntity*, CPed* pPed)
    DECL_THISCALL_TAIL(GetLookAtEntity, pPed)
    DECL_THISCALL_HEAD(GetLookAtOffset, _ZN16IKChainManager_c15GetLookAtOffsetEP4CPedP7CVector, void, CPed* pPed, CVector* pOffset)
    DECL_THISCALL_TAIL(GetLookAtOffset, pPed, pOffset)
    DECL_THISCALL_HEAD(AbortLookAt, _ZN16IKChainManager_c11AbortLookAtEP4CPedi, void, CPed* pPed, i32 blendTime)
    DECL_THISCALL_TAIL(AbortLookAt, pPed, blendTime)
    DECL_THISCALL_HEAD(PointArm, _ZN16IKChainManager_c8PointArmEPciP4CPedP7CEntityiP5RwV3dfif, void, char* idString, i32 armId, CPed* pPed, CEntity* pEntity, i32 offsetBoneTag, RwV3d* pOffsetPos, float speed, i32 blendTime, float cullDist)
    DECL_THISCALL_TAIL(PointArm, idString, armId, pPed, pEntity, offsetBoneTag, pOffsetPos, speed, blendTime, cullDist)
    DECL_THISCALL_HEAD(IsArmPointing, _ZN16IKChainManager_c13IsArmPointingEiP4CPed, u8, i32 armId, CPed* pPed)
    DECL_THISCALL_TAIL(IsArmPointing, armId, pPed)
    DECL_THISCALL_HEAD(AbortPointArm, _ZN16IKChainManager_c13AbortPointArmEiP4CPedi, void, i32 armId, CPed* pPed, i32 blendTime)
    DECL_THISCALL_TAIL(AbortPointArm, armId, pPed, blendTime)
    DECL_THISCALL_HEAD(IsFacingTarget, _ZN16IKChainManager_c14IsFacingTargetEP4CPedi, u8, CPed* pPed, i32 slotId)
    DECL_THISCALL_TAIL(IsFacingTarget, pPed, slotId)

    // Member values
    IKChain_c m_ikChains[32];
    List_c m_ikChainList;
    List_c m_ikChainPool;
DECL_CLASS_END()
CHECKSIZE(IKChainManager_c, 0xB18, 0xF30);

DECL_OBJECT_PLT_GLOBAL(BoneNodeManager_c, g_boneNodeMan, BYBIT(0x679FC8, 0x851FA0));
DECL_OBJECT_PLT_GLOBAL(IKChainManager_c, g_ikChainMan, BYBIT(0x6785B4, 0x84EB80));

#endif // __AML_PSDK_SAIKCHAIN_H
