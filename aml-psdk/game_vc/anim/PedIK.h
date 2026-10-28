#ifndef __AML_PSDK_VCPEDIK_H
#define __AML_PSDK_VCPEDIK_H

#include <aml-psdk/game_vc/plugin.h>
#include <aml-psdk/renderware/RwMatrix.h>
#include "AnimBlendFrameData.h"

struct CPed;
struct RwFrame;

enum MoveLimbResult : i32
{
    CANT_REACH_TARGET = 0,
    HAVENT_REACHED_TARGET = 1,
    REACHED_TARGET = 2
};

struct LimbOrientation
{
    float m_fYaw;
    float m_fPitch;
};
CHECKSIZE(LimbOrientation, 0x8, 0x8);

struct LimbMovementInfo
{
    float maxYaw;
    float minYaw;
    float yawD;
    float maxPitch;
    float minPitch;
    float pitchD;
};
CHECKSIZE(LimbMovementInfo, 0x18, 0x18);

DECL_CLASS(CPedIK)
    // Construct/Deconstruct functions
    DECL_CTORCALL(CPedIK, _ZN6CPedIKC2Ev);

    // STATIC functions
    DECL_FASTCALL_SIMPLE(GetWorldMatrix, _ZN6CPedIK14GetWorldMatrixEP7RwFrameP11RwMatrixTag, void, RwFrame* frame, RwMatrix* matrix);

    // STATIC values
    DECL_OBJECT_PLT(LimbMovementInfo, ms_headInfo, BYBIT(0x396E7C, 0x57BCF0));
    DECL_OBJECT_PLT(LimbMovementInfo, ms_headRestoreInfo, BYBIT(0x394430, 0x5769B0));
    DECL_OBJECT_PLT(LimbMovementInfo, ms_torsoInfo, BYBIT(0x395C28, 0x579868));
    DECL_OBJECT_PLT(LimbMovementInfo, ms_upperArmInfo, BYBIT(0x394E90, 0x577D98));
    DECL_OBJECT_PLT(LimbMovementInfo, ms_lowerArmInfo, BYBIT(0x3951D4, 0x578400));

    // Member functions
    DECL_THISCALL_HEAD(MoveLimb, _ZN6CPedIK8MoveLimbER15LimbOrientationffR16LimbMovementInfo, MoveLimbResult, LimbOrientation& limb, float yaw, float pitch, LimbMovementInfo& moveInfo)
    DECL_THISCALL_TAIL(MoveLimb, limb, yaw, pitch, moveInfo)
    DECL_THISCALL_HEAD(GetComponentPosition, _ZN6CPedIK20GetComponentPositionER5RwV3dj, void, RwV3d& position, u32 boneIndex)
    DECL_THISCALL_TAIL(GetComponentPosition, position, boneIndex)
    DECL_THISCALL_HEAD(ExtractYawAndPitchWorld, _ZN6CPedIK23ExtractYawAndPitchWorldEP11RwMatrixTagRfS2_, void, RwMatrix* matrix, float& yaw, float& pitch)
    DECL_THISCALL_TAIL(ExtractYawAndPitchWorld, matrix, yaw, pitch)
    DECL_THISCALL_HEAD(ExtractYawAndPitchLocal, _ZN6CPedIK23ExtractYawAndPitchLocalEP11RwMatrixTagRfS2_, void, RwMatrix* matrix, float& yaw, float& pitch)
    DECL_THISCALL_TAIL(ExtractYawAndPitchLocal, matrix, yaw, pitch)
    DECL_THISCALL_HEAD(ExtractYawAndPitchLocalSkinned, _ZN6CPedIK30ExtractYawAndPitchLocalSkinnedEP18AnimBlendFrameDataRfS2_, void, AnimBlendFrameData* frame, float& yaw, float& pitch)
    DECL_THISCALL_TAIL(ExtractYawAndPitchLocalSkinned, frame, yaw, pitch)
    DECL_THISCALL_HEAD(PointGunAtPosition, _ZN6CPedIK18PointGunAtPositionERK7CVector, bool, CVector const& position)
    DECL_THISCALL_TAIL(PointGunAtPosition, position)
    DECL_THISCALL_HEAD(PointGunInDirection, _ZN6CPedIK19PointGunInDirectionEff, bool, float yaw, float pitch)
    DECL_THISCALL_TAIL(PointGunInDirection, yaw, pitch)
    DECL_THISCALL_HEAD(PointGunInDirectionUsingArm, _ZN6CPedIK27PointGunInDirectionUsingArmEff, bool, float yaw, float pitch)
    DECL_THISCALL_TAIL(PointGunInDirectionUsingArm, yaw, pitch)
    DECL_THISCALL_SIMPLE(RestoreGunPosn, _ZN6CPedIK14RestoreGunPosnEv, bool);
    DECL_THISCALL_HEAD(LookAtPosition, _ZN6CPedIK14LookAtPositionERK7CVector, bool, CVector const& position)
    DECL_THISCALL_TAIL(LookAtPosition, position)
    DECL_THISCALL_HEAD(LookInDirection, _ZN6CPedIK15LookInDirectionEff, bool, float yaw, float pitch)
    DECL_THISCALL_TAIL(LookInDirection, yaw, pitch)
    DECL_THISCALL_SIMPLE(RestoreLookAt, _ZN6CPedIK13RestoreLookAtEv, bool);
    DECL_THISCALL_HEAD(RotateTorso, _ZN6CPedIK11RotateTorsoEP18AnimBlendFrameDataR15LimbOrientationb, void, AnimBlendFrameData* frame, LimbOrientation& rotation, bool changeRoll)
    DECL_THISCALL_TAIL(RotateTorso, frame, rotation, changeRoll)

    // Member values
    // The native constructor leaves this pointer for CPed to assign.
    CPed* m_pPed;
    LimbOrientation m_sHead;
    LimbOrientation m_sTorso;
    LimbOrientation m_sUpperArm;
    LimbOrientation m_sLowerArm;
    union
    {
        u32 m_nFlags;
        struct
        {
            u32 bGunPointedSuccessfully : 1;
            u32 bLookaroundHeadOnly : 1;
            u32 bAimsWithArm : 1;
            u32 : 29;
        };
    };
DECL_CLASS_END()
CHECKSIZE(CPedIK, 0x28, 0x30);

#define ms_headInfo ms_headInfo()
#define ms_headRestoreInfo ms_headRestoreInfo()
#define ms_torsoInfo ms_torsoInfo()
#define ms_upperArmInfo ms_upperArmInfo()
#define ms_lowerArmInfo ms_lowerArmInfo()

#endif // __AML_PSDK_VCPEDIK_H
