#ifndef __AML_PSDK_SATASKTYPES_H
#define __AML_PSDK_SATASKTYPES_H

#include "Task.h"
#include "../TaskTimer.h"
#include "../../base/Lists.h"
#include "../../base/ColModel.h"
#include "../../enum/AnimationId.h"
#include "../../enum/PedEnums.h"
#include <aml-psdk/renderware/RwMatrix.h>

enum eMeleeCombo
{
    MCOMBO_IDLE = 0,
    MCOMBO_MOVE = 1,
    MCOMBO_BLOCK = 2,
    MCOMBO_END = 3,
    MCOMBO_UNARMED_1 = 4,
    MCOMBO_UNARMED_2 = 5,
    MCOMBO_UNARMED_3 = 6,
    MCOMBO_UNARMED_4 = 7,
    MCOMBO_BBALLBAT = 8,
    MCOMBO_KNIFE = 9,
    MCOMBO_GOLFCLUB = 10,
    MCOMBO_SWORD = 11,
    MCOMBO_CHAINSAW = 12,
    MCOMBO_DILDO = 13,
    MCOMBO_FLOWERS = 14,
    MCOMBO_KICK_STD = 15,
    MCOMBO_PISTOL_WHIP = 16,
    MCOMBO_NUM = 17,
};

struct CEntity;
struct CObject;
struct RpClump;
struct CVehicle;
struct CPlayerPed;
struct CAnimBlendAssociation;
struct CAnimBlendHierarchy;
struct CWeaponInfo;
struct FxSystem_c;
struct CTaskUtilityLineUpPedWithCar;

struct tMeleeComboSet
{
    AssocGroupId nAnimGroup;
    float fGroupRange;
    float aFireTime[5];
    float aComboTime[5];
    float aRadius[5];
    float aGroundLoopStart;
    float aBlockLoopStart;
    float aBlockLoopEnd;
    u8 aHitLevel[5];
    u8 aDamage[5];
    i32 aHitSound[5];
    i32 aAltHitSound[5];
    u16 nFlags;
};
CHECKSIZE(tMeleeComboSet, 0x88, 0x88);

DECL_CLASS_BASED(CTaskSimpleAnim, CTaskSimple)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CTaskSimpleAnim, _ZN15CTaskSimpleAnimC2Eb, bool const bHoldLastFrame);
    DECL_DTORCALL_PROXY(CTaskSimpleAnim, _ZN15CTaskSimpleAnimD2Ev);
    DECL_NEWCALL(CTaskSimpleAnim, BYBIT(_ZN5CTasknwEj, _ZN5CTasknwEm));

    // STATIC functions
    DECL_FASTCALL_SIMPLE(FinishRunAnimCB, _ZN15CTaskSimpleAnim15FinishRunAnimCBEP21CAnimBlendAssociationPv, void, CAnimBlendAssociation* pAnim, void* pData);

    // Member values
    CAnimBlendAssociation* m_pAnim;
    u8 m_bIsFinished : 1;
    u8 m_bDontInterrupt : 1;
    u8 m_bHoldLastFrame : 1;
    u8 m_bDontBlendOut : 1;
    u8 m_bRunInSequence : 1;
    u8 m_bOffsetAtEnd : 1;
    u8 m_bOffsetAvailable : 1;
DECL_CLASS_END()
CHECKSIZE(CTaskSimpleAnim, 0x10, 0x20);

DECL_CLASS_BASED(CTaskSimpleRunAnim, CTaskSimpleAnim)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CTaskSimpleRunAnim1, _ZN18CTaskSimpleRunAnimC2E12AssocGroupId11AnimationIdfb, AssocGroupId const arg2, AnimationId const arg3, float const arg4, bool const arg5);
    DECL_CTORCALL_PROXY(CTaskSimpleRunAnim, _ZN18CTaskSimpleRunAnimC2E12AssocGroupId11AnimationIdfiPKcb, AssocGroupId const animGroup, AnimationId const animID, float const fBlendDelta, int const iTaskType, char const* pTaskName, bool const bHoldLastFrame);
    DECL_THISCALL_SIMPLE(Delete, _ZN18CTaskSimpleRunAnimD0Ev, void);
    DECL_NEWCALL(CTaskSimpleRunAnim, BYBIT(_ZN5CTasknwEj, _ZN5CTasknwEm));

    // Member functions
    DECL_THISCALL_HEAD(StartAnim, _ZN18CTaskSimpleRunAnim9StartAnimEP4CPed, void, CPed* pPed)
    DECL_THISCALL_TAIL(StartAnim, pPed)

    // Member values
    AssocGroupId m_animGroup;
    AnimationId m_animID;
    float m_fBlendDelta;
    u16 m_iTaskType;
DECL_CLASS_END()
CHECKSIZE(CTaskSimpleRunAnim, 0x20, 0x30);

DECL_CLASS_BASED(CTaskSimpleStandStill, CTaskSimple)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CTaskSimpleStandStill, _ZN21CTaskSimpleStandStillC2Eibbf, int const iDuration, bool const bForever, bool const bTillStopped, float fIdleBlendDelta);
    DECL_DTORCALL_PROXY(CTaskSimpleStandStill, _ZN21CTaskSimpleStandStillD2Ev);
    DECL_NEWCALL(CTaskSimpleStandStill, BYBIT(_ZN5CTasknwEj, _ZN5CTasknwEm));

    // STATIC values
    DECL_OBJECT_PLT(int const, ms_iStandStillTime, BYBIT(0x6797AC, 0x850F60));

    // Member values
    int m_iDuration;
    CTaskTimer m_timer;
    bool m_bForever;
    bool m_bTillStopped;
    float m_fIdleBlendDelta;
DECL_CLASS_END()
CHECKSIZE(CTaskSimpleStandStill, 0x20, 0x28);

DECL_CLASS_BASED(CTaskSimplePause, CTaskSimple)
    // Construct/Deconstruct functions
    DECL_THISCALL_SIMPLE(Delete, _ZN16CTaskSimplePauseD0Ev, void);
    DECL_NEWCALL(CTaskSimplePause, BYBIT(_ZN5CTasknwEj, _ZN5CTasknwEm));

    // Member values
    CTaskTimer m_timer;
    int m_iPauseTime;
DECL_CLASS_END()
CHECKSIZE(CTaskSimplePause, 0x18, 0x20);

DECL_CLASS_BASED(CTaskSimpleUseGun, CTaskSimple)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CTaskSimpleUseGun, _ZN17CTaskSimpleUseGunC2EP7CEntity7CVectorash, CEntity* pTargetEntity, CVector vecTarget, i8 nCommand, i16 nBurstLength, u8 bAimImmediate);
    DECL_NEWCALL(CTaskSimpleUseGun, BYBIT(_ZN5CTasknwEj, _ZN5CTasknwEm));

    // STATIC functions
    DECL_FASTCALL_SIMPLE(RequirePistolWhip, _ZN17CTaskSimpleUseGun17RequirePistolWhipEP4CPedP7CEntity, bool, CPed* pPed, CEntity* pTargetEnt);
    DECL_FASTCALL_SIMPLE(FinishGunAnimCB, _ZN17CTaskSimpleUseGun15FinishGunAnimCBEP21CAnimBlendAssociationPv, void, CAnimBlendAssociation* pAnim, void* pData);
    DECL_FASTCALL_SIMPLE(CreateTask, _ZN17CTaskSimpleUseGun10CreateTaskEv, CTask*);

    // STATIC values
    DECL_VALUE_PLT_FLT(WEAPON_RE_AIM_RATE, BYBIT(0x676AF8, 0x84B638));

    // Member functions
    DECL_THISCALL_HEAD(Reset, _ZN17CTaskSimpleUseGun5ResetEP4CPedP7CEntity7CVectoras, void, CPed* pPed, CEntity* pTargetEntity, CVector vecTarget, i8 nCommand, i16 nBurstLength)
    DECL_THISCALL_TAIL(Reset, pPed, pTargetEntity, vecTarget, nCommand, nBurstLength)
    DECL_THISCALL_HEAD(ControlGun, _ZN17CTaskSimpleUseGun10ControlGunEP4CPedP7CEntitya, bool, CPed* pPed, CEntity* pTargetEntity, i8 nCommand)
    DECL_THISCALL_TAIL(ControlGun, pPed, pTargetEntity, nCommand)
    DECL_THISCALL_SIMPLE(PlayerPassiveControlGun, _ZN17CTaskSimpleUseGun23PlayerPassiveControlGunEv, bool);
    DECL_THISCALL_HEAD(ControlGunMove, _ZN17CTaskSimpleUseGun14ControlGunMoveEP9CVector2D, bool, CVector2D* pMoveVec)
    DECL_THISCALL_TAIL(ControlGunMove, pMoveVec)
    DECL_THISCALL_HEAD(StartCountDown, _ZN17CTaskSimpleUseGun14StartCountDownEhb, void, u8 nNumIdleFrames, bool bMax)
    DECL_THISCALL_TAIL(StartCountDown, nNumIdleFrames, bMax)
    DECL_THISCALL_HEAD(ClearAnim, _ZN17CTaskSimpleUseGun9ClearAnimEP4CPed, void, CPed* pPed)
    DECL_THISCALL_TAIL(ClearAnim, pPed)
    DECL_THISCALL_HEAD(AbortIK, _ZN17CTaskSimpleUseGun7AbortIKEP4CPed, void, CPed* pPed)
    DECL_THISCALL_TAIL(AbortIK, pPed)
    DECL_THISCALL_HEAD(StartAnim, _ZN17CTaskSimpleUseGun9StartAnimEP4CPed, void, CPed* pPed)
    DECL_THISCALL_TAIL(StartAnim, pPed)
    DECL_THISCALL_HEAD(SetMoveAnim, _ZN17CTaskSimpleUseGun11SetMoveAnimEP4CPed, void, CPed* pPed)
    DECL_THISCALL_TAIL(SetMoveAnim, pPed)
    DECL_THISCALL_HEAD(RemoveStanceAnims, _ZN17CTaskSimpleUseGun17RemoveStanceAnimsEP4CPedf, void, CPed* pPed, float fBlendDelta)
    DECL_THISCALL_TAIL(RemoveStanceAnims, pPed, fBlendDelta)
    DECL_THISCALL_HEAD(FireGun, _ZN17CTaskSimpleUseGun7FireGunEP4CPedb, void, CPed* pPed, bool bLHand)
    DECL_THISCALL_TAIL(FireGun, pPed, bLHand)
    DECL_THISCALL_HEAD(AimGun, _ZN17CTaskSimpleUseGun6AimGunEP4CPed, void, CPed* pPed)
    DECL_THISCALL_TAIL(AimGun, pPed)

    // Member values
    bool m_bIsFinished;
    bool m_bIsInControl;
    bool m_bMoveControl;
    bool m_bFiredGun;
    bool m_bBlockedLOS;
    u8 m_nFireGunThisFrame;
    u8 m_bSkipAim;
    i8 m_nNextCommand;
    i8 m_nLastCommand;
    CVector2D m_vecMoveCommand;
    CEntity* m_pTargetEntity;
    CVector m_vecCoords;
    CAnimBlendAssociation* m_pAnim;
    CWeaponInfo* m_pWeaponInfo;
    i16 m_nBurstLength;
    i16 m_nBurstShots;
    u8 m_nCountDownFrames;
    u8 m_armIkInUse;
    u8 m_lookIkInUse;
    u8 m_bAimImmediate;
DECL_CLASS_END()
CHECKSIZE(CTaskSimpleUseGun, 0x3C, 0x58);

DECL_CLASS_BASED(CTaskSimpleDuck, CTaskSimple)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CTaskSimpleDuck, _ZN15CTaskSimpleDuckC2Ehts, u8 nDuckControl, u16 nLengthOfDuck, i16 nUseShotsWhizzingEvents);
    DECL_DTORCALL_PROXY(CTaskSimpleDuck, _ZN15CTaskSimpleDuckD2Ev);
    DECL_NEWCALL(CTaskSimpleDuck, BYBIT(_ZN5CTasknwEj, _ZN5CTasknwEm));

    // STATIC functions
    DECL_FASTCALL_SIMPLE(CanPedDuck, _ZN15CTaskSimpleDuck10CanPedDuckEP4CPed, bool, CPed* pPed);
    DECL_FASTCALL_SIMPLE(CreateTask, _ZN15CTaskSimpleDuck10CreateTaskEv, CTask*);
    DECL_FASTCALL_SIMPLE(DeleteDuckAnimCB, _ZN15CTaskSimpleDuck16DeleteDuckAnimCBEP21CAnimBlendAssociationPv, void, CAnimBlendAssociation* pAnim, void* pData);

    // STATIC values
    DECL_OBJECT_PLT(u16 const, ms_nLengthOfDuck, BYBIT(0x678E74, 0x84FD10));

    // Member functions
    DECL_THISCALL_HEAD(RestartTask, _ZN15CTaskSimpleDuck11RestartTaskEP4CPed, CTask*, CPed* pPed)
    DECL_THISCALL_TAIL(RestartTask, pPed)
    DECL_THISCALL_HEAD(AbortBecauseOfOtherDuck, _ZN15CTaskSimpleDuck23AbortBecauseOfOtherDuckEP4CPed, bool, CPed* pPed)
    DECL_THISCALL_TAIL(AbortBecauseOfOtherDuck, pPed)
    DECL_THISCALL_HEAD(ControlDuckMove, _ZN15CTaskSimpleDuck15ControlDuckMoveE9CVector2D, bool, CVector2D vecMove)
    DECL_THISCALL_TAIL(ControlDuckMove, vecMove)
    DECL_THISCALL_SIMPLE(ForceStopMove, _ZN15CTaskSimpleDuck13ForceStopMoveEv, void);
    DECL_THISCALL_HEAD(StartCountDown, _ZN15CTaskSimpleDuck14StartCountDownEhb, void, u8 nNumIdleFrames, bool bMax)
    DECL_THISCALL_TAIL(StartCountDown, nNumIdleFrames, bMax)
    DECL_THISCALL_HEAD(SetControlType, _ZN15CTaskSimpleDuck14SetControlTypeEh, bool, u8 nType)
    DECL_THISCALL_TAIL(SetControlType, nType)
    DECL_THISCALL_HEAD(SetDuckTimer, _ZN15CTaskSimpleDuck12SetDuckTimerEt, void, u16 nLengthOfDuck)
    DECL_THISCALL_TAIL(SetDuckTimer, nLengthOfDuck)
    DECL_THISCALL_HEAD(SetMoveAnim, _ZN15CTaskSimpleDuck11SetMoveAnimEP4CPed, void, CPed* pPed)
    DECL_THISCALL_TAIL(SetMoveAnim, pPed)

    // Member values
    u32 m_nStartTime;
    u16 m_nLengthOfDuck;
    i16 m_nShotWhizzingCounter;
    CAnimBlendAssociation* m_pDuckAnim;
    CAnimBlendAssociation* m_pMoveAnim;
    bool m_bIsFinished;
    bool m_bIsAborting;
    bool m_bNeedToSetDuckFlag;
    bool m_bIsInControl;
    CVector2D m_vecMoveCommand;
    u8 m_nDuckControlType;
    u8 m_nCountDownFrames;
DECL_CLASS_END()
CHECKSIZE(CTaskSimpleDuck, 0x28, 0x38);

DECL_CLASS_BASED(CTaskSimpleFight, CTaskSimple)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CTaskSimpleFight, _ZN16CTaskSimpleFightC2EP7CEntityij, CEntity* pTargetEntity, int nCommand, u32 nIdlePeriod);
    DECL_DTORCALL_PROXY(CTaskSimpleFight, _ZN16CTaskSimpleFightD2Ev);
    DECL_NEWCALL(CTaskSimpleFight, BYBIT(_ZN5CTasknwEj, _ZN5CTasknwEm));

    // STATIC functions
    DECL_FASTCALL_SIMPLE(GetComboType, _ZN16CTaskSimpleFight12GetComboTypeEPc, eMeleeCombo, char* pComboName);
    DECL_FASTCALL_SIMPLE(FinishMeleeAnimCB, _ZN16CTaskSimpleFight17FinishMeleeAnimCBEP21CAnimBlendAssociationPv, void, CAnimBlendAssociation* pAnim, void* pData);
    DECL_FASTCALL_SIMPLE(LoadMeleeData, _ZN16CTaskSimpleFight13LoadMeleeDataEv, void);
    DECL_FASTCALL_SIMPLE(GetHitLevel, _ZN16CTaskSimpleFight11GetHitLevelEPKc, u8, char const* pString);
    DECL_FASTCALL_SIMPLE(GetHitSound, _ZN16CTaskSimpleFight11GetHitSoundEi, i16, i32 const nHitSound);

    // STATIC values
    DECL_OBJECT_ARRAY_PLT(tMeleeComboSet, m_aComboData, BYBIT(0x6790E8, 0x8501F8));
    DECL_OBJECT_ARRAY_PLT(CVector, m_aHitOffset, BYBIT(0x677840, 0x84D0A8));
    DECL_OBJECT_PLT(CColModel, m_sStrikeColModel, BYBIT(0x677F9C, 0x84DF58));
    DECL_OBJECT_PLT(CCollisionData, m_sStrikeColData, BYBIT(0x677224, 0x84C480));
    DECL_OBJECT_ARRAY_PLT(CColSphere, m_sStrikeSpheres, BYBIT(0x678B68, 0x84F6F8));

    // Member functions
    DECL_THISCALL_HEAD(ControlFight, _ZN16CTaskSimpleFight12ControlFightEP7CEntitya, bool, CEntity* pTargetEntity, i8 nCommand)
    DECL_THISCALL_TAIL(ControlFight, pTargetEntity, nCommand)
    DECL_THISCALL_HEAD(GetStrikeDamage, _ZN16CTaskSimpleFight15GetStrikeDamageEP4CPed, float, CPed* pPed)
    DECL_THISCALL_TAIL(GetStrikeDamage, pPed)
    DECL_THISCALL_SIMPLE(GetRange, _ZNK16CTaskSimpleFight8GetRangeEv, float);
    DECL_THISCALL_HEAD(BeHitWhileBlocking, _ZN16CTaskSimpleFight18BeHitWhileBlockingEP4CPedS1_aa, bool, CPed* pPed, CPed* pAttacker, i8 nAttackCombo, i8 nAttackMove)
    DECL_THISCALL_TAIL(BeHitWhileBlocking, pPed, pAttacker, nAttackCombo, nAttackMove)
    DECL_THISCALL_HEAD(StartAnim, _ZN16CTaskSimpleFight9StartAnimEP4CPedi, void, CPed* pPed, int nNewMove)
    DECL_THISCALL_TAIL(StartAnim, pPed, nNewMove)
    DECL_THISCALL_HEAD(GetAvailableComboSet, _ZN16CTaskSimpleFight20GetAvailableComboSetEP4CPeda, i8, CPed* pPed, i8 nNextCommand)
    DECL_THISCALL_TAIL(GetAvailableComboSet, pPed, nNextCommand)
    DECL_THISCALL_HEAD(SetPlayerMoveAnim, _ZN16CTaskSimpleFight17SetPlayerMoveAnimEP10CPlayerPed, void, CPlayerPed* pPlayerPed)
    DECL_THISCALL_TAIL(SetPlayerMoveAnim, pPlayerPed)
    DECL_THISCALL_HEAD(FightHitPed, _ZN16CTaskSimpleFight11FightHitPedEP4CPedS1_R7CVectorS3_s, CPed*, CPed* pPed, CPed* pHitPed, CVector& vecHitPoint, CVector& vecDelta, i16 nColPieceType)
    DECL_THISCALL_TAIL(FightHitPed, pPed, pHitPed, vecHitPoint, vecDelta, nColPieceType)
    DECL_THISCALL_HEAD(FightHitObj, _ZN16CTaskSimpleFight11FightHitObjEP4CPedP7CObjectR7CVectorS5_sh, void, CPed* pPed, CObject* pHitObj, CVector& vecHitPoint, CVector& vecDelta, i16 nColPieceType, u8 nColSurfaceType)
    DECL_THISCALL_TAIL(FightHitObj, pPed, pHitObj, vecHitPoint, vecDelta, nColPieceType, nColSurfaceType)
    DECL_THISCALL_HEAD(FightStrike, _ZN16CTaskSimpleFight11FightStrikeEP4CPedR7CVector, u8, CPed* pPed, CVector& vec)
    DECL_THISCALL_TAIL(FightStrike, pPed, vec)
    DECL_THISCALL_HEAD(ChooseAttackPlayer, _ZN16CTaskSimpleFight18ChooseAttackPlayerEP4CPed, i16, CPed* pPed)
    DECL_THISCALL_TAIL(ChooseAttackPlayer, pPed)
    DECL_THISCALL_HEAD(ChooseAttackAI, _ZN16CTaskSimpleFight14ChooseAttackAIEP4CPed, i16, CPed* pPed)
    DECL_THISCALL_TAIL(ChooseAttackAI, pPed)
    DECL_THISCALL_HEAD(FindTargetOnGround, _ZN16CTaskSimpleFight18FindTargetOnGroundEP4CPed, bool, CPed* pPed)
    DECL_THISCALL_TAIL(FindTargetOnGround, pPed)
    DECL_THISCALL_HEAD(FightSetUpCol, _ZN16CTaskSimpleFight13FightSetUpColEf, void, float fRadius)
    DECL_THISCALL_TAIL(FightSetUpCol, fRadius)
    DECL_THISCALL_HEAD(FightHitCar, _ZN16CTaskSimpleFight11FightHitCarEP4CPedP8CVehicleR7CVectorS5_sh, void, CPed* pPed, CVehicle* pHitCar, CVector& vecHitPoint, CVector& vecDelta, i16 nColPieceType, u8 nColSurfaceType)
    DECL_THISCALL_TAIL(FightHitCar, pPed, pHitCar, vecHitPoint, vecDelta, nColPieceType, nColSurfaceType)

    // Member values
    bool m_bIsFinished;
    bool m_bIsInControl;
    bool m_bAnimsReferenced;
    AssocGroupId m_nRequiredAnimGroup;
    u16 m_nIdlePeriod;
    u16 m_nIdleCounter;
    i8 m_nContinueStrike;
    i8 m_nChainCounter;
    CEntity* m_pTargetEntity;
    CAnimBlendAssociation* m_pAnim;
    CAnimBlendAssociation* m_pIdleAnim;
    i8 m_nComboSet;
    i8 m_nCurrentMove;
    i8 m_nNextCommand;
    i8 m_nLastCommand;
DECL_CLASS_END()
CHECKSIZE(CTaskSimpleFight, 0x28, 0x40);

DECL_CLASS_BASED(CTaskSimpleHoldEntity, CTaskSimple)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CTaskSimpleHoldEntity2, _ZN21CTaskSimpleHoldEntityC2EP7CEntityPK7CVectorhh11AnimationId12AssocGroupIdb, CEntity* arg2, CVector const* arg3, u8 arg4, u8 arg5, AnimationId arg6, AssocGroupId arg7, bool arg8);
    DECL_CTORCALL_PROXY(CTaskSimpleHoldEntity1, _ZN21CTaskSimpleHoldEntityC2EP7CEntityPK7CVectorhhPKcS6_i, CEntity* pEntity, CVector const* pVecOffset, u8 nBone, u8 nOrientateFlags, char const* pAnimName, char const* pAnimGroupName, i32 nFlags);
    DECL_DTORCALL_PROXY(CTaskSimpleHoldEntity, _ZN21CTaskSimpleHoldEntityD2Ev);
    DECL_CTORCALL_PROXY(CTaskSimpleHoldEntity, _ZN21CTaskSimpleHoldEntityC2EP7CEntityPK7CVectorhhP10CAnimBlockP19CAnimBlendHierarchyi, CEntity* arg2, CVector const* arg3, u8 arg4, u8 arg5, CAnimBlock* arg6, CAnimBlendHierarchy* arg7, i32 arg8);
    DECL_NEWCALL(CTaskSimpleHoldEntity, BYBIT(_ZN5CTasknwEj, _ZN5CTasknwEm));

    // STATIC functions
    DECL_FASTCALL_SIMPLE(FinishAnimHoldEntityCB, _ZN21CTaskSimpleHoldEntity22FinishAnimHoldEntityCBEP21CAnimBlendAssociationPv, void, CAnimBlendAssociation* pAnim, void* pData);

    // STATIC values
    DECL_OBJECT_PLT(int, m_nPutDownTimer, BYBIT(0x678D88, 0x84FB38));

    // Member functions
    DECL_THISCALL_SIMPLE(ReleaseEntity, _ZN21CTaskSimpleHoldEntity13ReleaseEntityEv, void);
    DECL_THISCALL_HEAD(DropEntity, _ZN21CTaskSimpleHoldEntity10DropEntityEP4CPedb, void, CPed* pPed, bool bAtSpeed)
    DECL_THISCALL_TAIL(DropEntity, pPed, bAtSpeed)
    DECL_THISCALL_HEAD(PlayAnim, _ZN21CTaskSimpleHoldEntity8PlayAnimE11AnimationId12AssocGroupId, void, AnimationId nAnimId, AssocGroupId nAnimGroup)
    DECL_THISCALL_TAIL(PlayAnim, nAnimId, nAnimGroup)
    DECL_THISCALL_SIMPLE(CanThrowEntity, _ZN21CTaskSimpleHoldEntity14CanThrowEntityEv, bool);
    DECL_THISCALL_HEAD(ChoosePutDownHeight, _ZN21CTaskSimpleHoldEntity19ChoosePutDownHeightEP4CPed, void, CPed* pPed)
    DECL_THISCALL_TAIL(ChoosePutDownHeight, pPed)
    DECL_THISCALL_HEAD(StartAnim, _ZN21CTaskSimpleHoldEntity9StartAnimEP4CPed, void, CPed* pPed)
    DECL_THISCALL_TAIL(StartAnim, pPed)

    // Member values
    CEntity* m_pHoldEntity;
    CVector m_vecAttachOffset;
    u8 m_nBoneId;
    u8 m_nOrientateFlags;
    float m_fHeadingOffset;
    AnimationId m_nAnimId;
    AssocGroupId m_nAnimGroup;
    i32 m_nAnimFlags;
    CAnimBlock* m_pAnimBlock;
    CAnimBlendHierarchy* m_pAnimHierarchy;
    bool m_bIsFinished;
    bool m_bIsFirstTime;
    bool m_bDontDropWhenAnimDone;
    CAnimBlendAssociation* m_pAnim;
DECL_CLASS_END()
CHECKSIZE(CTaskSimpleHoldEntity, 0x3C, 0x58);

DECL_CLASS_BASED(CTaskSimpleThrowProjectile, CTaskSimple)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CTaskSimpleThrowProjectile, _ZN26CTaskSimpleThrowProjectileC2EP7CEntity7CVector, CEntity* pTargetEntity, CVector vecTargetPos);
    DECL_NEWCALL(CTaskSimpleThrowProjectile, BYBIT(_ZN5CTasknwEj, _ZN5CTasknwEm));

    // STATIC functions
    DECL_FASTCALL_SIMPLE(FinishAnimThrowProjectileCB, _ZN26CTaskSimpleThrowProjectile27FinishAnimThrowProjectileCBEP21CAnimBlendAssociationPv, void, CAnimBlendAssociation* pAnim, void* pData);

    // Member functions
    DECL_THISCALL_HEAD(ControlThrow, _ZN26CTaskSimpleThrowProjectile12ControlThrowEbP7CEntityP7CVector, bool, bool bButtonReleased, CEntity* pEntity, CVector* pVecCoords)
    DECL_THISCALL_TAIL(ControlThrow, bButtonReleased, pEntity, pVecCoords)
    DECL_THISCALL_HEAD(StartAnim, _ZN26CTaskSimpleThrowProjectile9StartAnimEP4CPed, void, CPed* pPed)
    DECL_THISCALL_TAIL(StartAnim, pPed)

    // Member values
    bool m_bIsFinished;
    bool m_bStartThrowFinished;
    bool m_bButtonReleased;
    CAnimBlendAssociation* m_pAnim;
    CEntity* m_pTargetEntity;
    CVector m_vecTargetPos;
    i32 m_nButtonCounter;
DECL_CLASS_END()
CHECKSIZE(CTaskSimpleThrowProjectile, 0x24, 0x38);

DECL_CLASS_BASED(CTaskSimpleInAir, CTaskSimple)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CTaskSimpleInAir, _ZN16CTaskSimpleInAirC2Ebbb, bool bJump, bool bFallingToDeath, bool bTumbleWhilstFalling);
    DECL_DTORCALL_PROXY(CTaskSimpleInAir, _ZN16CTaskSimpleInAirD2Ev);
    DECL_NEWCALL(CTaskSimpleInAir, BYBIT(_ZN5CTasknwEj, _ZN5CTasknwEm));

    // STATIC functions
    DECL_FASTCALL_SIMPLE(DeleteInAirAnimCB, _ZN16CTaskSimpleInAir17DeleteInAirAnimCBEP21CAnimBlendAssociationPv, void, CAnimBlendAssociation* pAnim, void* pData);
    DECL_FASTCALL_SIMPLE(CreateTask, _ZN16CTaskSimpleInAir10CreateTaskEv, CTask*);

    // STATIC values
    DECL_OBJECT_PLT(int, ms_iNumStuckFallingFramesBeforeQuitting, BYBIT(0x678E4C, 0x84FCC0));
    DECL_VALUE_PLT_FLT(ms_fMaxStuckVelocity, BYBIT(0x6769E8, 0x84B418));

    // Member functions
    DECL_THISCALL_HEAD(ApplyRollAndPitch, _ZN16CTaskSimpleInAir17ApplyRollAndPitchEP4CPed, void, CPed* pPed)
    DECL_THISCALL_TAIL(ApplyRollAndPitch, pPed)

    // Member values
    CVector m_vecEdge;
    float m_fEdgeHeading;
    u8 m_nEdgeSurfaceType;
    CAnimBlendAssociation* m_pAnim;
    float m_fFallVel;
    u8 m_bIsJumping : 1;
    u8 m_bIsFallingToDeath : 1;
    u8 m_bTumbleWhilstFalling : 1;
    int m_iNumStuckFrames;
    CTaskTimer m_FallScreamTimer;
    CEntity* m_pClimbEnt;
DECL_CLASS_END()
CHECKSIZE(CTaskSimpleInAir, 0x3C, 0x50);

DECL_CLASS_BASED(CTaskSimpleClimb, CTaskSimple)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CTaskSimpleClimb, _ZN16CTaskSimpleClimbC2EP7CEntityRK7CVectorfhab, CEntity* pClimbEnt, CVector const& vecTarget, float fHeading, u8 nSurfaceType, i8 nHeight, bool const bForceClimb);
    DECL_DTORCALL_PROXY(CTaskSimpleClimb, _ZN16CTaskSimpleClimbD2Ev);
    DECL_NEWCALL(CTaskSimpleClimb, BYBIT(_ZN5CTasknwEj, _ZN5CTasknwEm));

    // STATIC functions
    DECL_FASTCALL_SIMPLE(Shutdown, _ZN16CTaskSimpleClimb8ShutdownEv, void);
    DECL_FASTCALL_SIMPLE(DeleteAnimClimbCB, _ZN16CTaskSimpleClimb17DeleteAnimClimbCBEP21CAnimBlendAssociationPv, void, CAnimBlendAssociation* pAnim, void* pData);
    DECL_FASTCALL_SIMPLE(TestForClimb, _ZN16CTaskSimpleClimb12TestForClimbEP4CPedR7CVectorRfRhb, CEntity*, CPed* pPed, CVector& vecTargetPos, float& fGrabHeading, u8& nSurfaceType, bool bLaunch);
    DECL_FASTCALL_SIMPLE(ScanToGrab, _ZN16CTaskSimpleClimb10ScanToGrabEP4CPedR7CVectorRfRhbbbPS2_, CEntity*, CPed* pPed, CVector& vecTargetPos, float& fGrabHeading, u8& nSurfaceType, bool bLaunch, bool bTestStandup, bool bTestDropOtherSide, CVector* pAbsPos);
    DECL_FASTCALL_SIMPLE(ScanToGrabSectorList, _ZN16CTaskSimpleClimb20ScanToGrabSectorListER8CPtrListP4CPedR7CVectorRfRhbbb, CEntity*, CPtrList& list, CPed* pPed, CVector& vecTargetPos, float& fGrabHeading, u8& nSurfaceType, bool bLaunch, bool bTestStandup, bool bTestDropOtherSide);
    DECL_FASTCALL_SIMPLE(CreateColModel, _ZN16CTaskSimpleClimb14CreateColModelEv, bool);
    DECL_FASTCALL_SIMPLE(CreateTask, _ZN16CTaskSimpleClimb10CreateTaskEv, CTask*);

    // STATIC values
    DECL_VALUE_PLT_FLT(ms_fMinForStretchGrab, BYBIT(0x679624, 0x850C58));
    DECL_VALUE_PLT_FLT(ms_fHangingOffsetHorz, BYBIT(0x67813C, 0x84E290));
    DECL_VALUE_PLT_FLT(ms_fHangingOffsetVert, BYBIT(0x676714, 0x84AE80));
    DECL_VALUE_PLT_FLT(ms_fAtEdgeOffsetHorz, BYBIT(0x67631C, 0x84A690));
    DECL_VALUE_PLT_FLT(ms_fAtEdgeOffsetVert, BYBIT(0x6769A8, 0x84B3A0));
    DECL_VALUE_PLT_FLT(ms_fStandUpOffsetHorz, BYBIT(0x676648, 0x84ACE8));
    DECL_VALUE_PLT_FLT(ms_fStandUpOffsetVert, BYBIT(0x678AE0, 0x84F5E8));
    DECL_VALUE_PLT_FLT(ms_fVaultOffsetHorz, BYBIT(0x6783E8, 0x84E7E8));
    DECL_VALUE_PLT_FLT(ms_fVaultOffsetVert, BYBIT(0x676AC0, 0x84B5C8));
    DECL_OBJECT_PLT(CColModel, ms_ClimbColModel, BYBIT(0x678330, 0x84E678));
    DECL_OBJECT_PLT(CColModel, ms_StandupColModel, BYBIT(0x677A54, 0x84D4D0));
    DECL_OBJECT_PLT(CColModel, ms_VaultColModel, BYBIT(0x676EC8, 0x84BDD0));
    DECL_OBJECT_PLT(CColModel, ms_FindEdgeColModel, BYBIT(0x678048, 0x84E0B0));

    // Member functions
    DECL_THISCALL_HEAD(GetCameraTargetPos, _ZN16CTaskSimpleClimb18GetCameraTargetPosEP4CPedR7CVector, void, CPed* pPed, CVector& vecTarget)
    DECL_THISCALL_TAIL(GetCameraTargetPos, pPed, vecTarget)
    DECL_THISCALL_HEAD(GetCameraStickModifier, _ZN16CTaskSimpleClimb22GetCameraStickModifierEP4CPedRfS2_S2_S2_, void, CPed* pPed, float& fAlpha, float& fBeta, float& fStickAlpha, float& fStickBeta)
    DECL_THISCALL_TAIL(GetCameraStickModifier, pPed, fAlpha, fBeta, fStickAlpha, fStickBeta)
    DECL_THISCALL_HEAD(TestForVault, _ZN16CTaskSimpleClimb12TestForVaultEP4CPedR7CVectorf, bool, CPed* pPed, CVector& vecHoldPos, float fHoldHeading)
    DECL_THISCALL_TAIL(TestForVault, pPed, vecHoldPos, fHoldHeading)
    DECL_THISCALL_HEAD(TestForStandUp, _ZN16CTaskSimpleClimb14TestForStandUpEP4CPedR7CVectorf, bool, CPed* pPed, CVector& vecHoldPos, float fHoldHeading)
    DECL_THISCALL_TAIL(TestForStandUp, pPed, vecHoldPos, fHoldHeading)
    DECL_THISCALL_HEAD(StartAnim, _ZN16CTaskSimpleClimb9StartAnimEP4CPed, void, CPed* pPed)
    DECL_THISCALL_TAIL(StartAnim, pPed)
    DECL_THISCALL_HEAD(StartSpeech, _ZNK16CTaskSimpleClimb11StartSpeechEP4CPed, void, CPed* pPed)
    DECL_THISCALL_TAIL(StartSpeech, pPed)

    // Member values
    bool m_bIsFinished;
    bool m_bChangeAnimation;
    bool m_bChangePosition;
    bool m_bForceClimb;
    bool m_bInvalidClimb;
    i8 m_nHeightForAnim;
    i8 m_nHeightForPos;
    u8 m_nSurfaceType;
    i8 m_nFallAfterVault;
    float m_fHandholdHeading;
    CVector m_vecHandholdPos;
    CEntity* m_pClimbEnt;
    i16 m_nGetToPosCounter;
    CAnimBlendAssociation* m_pAnim;
DECL_CLASS_END()
CHECKSIZE(CTaskSimpleClimb, 0x30, 0x48);

DECL_CLASS_BASED(CTaskSimpleJetPack, CTaskSimple)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CTaskSimpleJetPack, _ZN18CTaskSimpleJetPackC2EPK7CVectorfiP7CEntity, CVector const* pVecTargetPos, float fCruiseHeight, i32 nHoverTime, CEntity* pTargetEnt);
    DECL_NEWCALL(CTaskSimpleJetPack, BYBIT(_ZN5CTasknwEj, _ZN5CTasknwEm));

    // STATIC functions
    DECL_FASTCALL_SIMPLE(CreateTask, _ZN18CTaskSimpleJetPack10CreateTaskEv, CTask*);

    // STATIC values
    DECL_VALUE_PLT_FLT(THRUST_NOMINAL, BYBIT(0x679C0C, 0x851830));
    DECL_VALUE_PLT_FLT(THRUST_FULL, BYBIT(0x67623C, 0x84A4D8));
    DECL_VALUE_PLT_FLT(THRUST_STRAFE, BYBIT(0x679A3C, 0x851490));
    DECL_VALUE_PLT_FLT(THRUST_STOP, BYBIT(0x677C4C, 0x84D8B8));
    DECL_VALUE_PLT_FLT(THRUST_MAX_ANGLE, BYBIT(0x67911C, 0x850260));
    DECL_VALUE_PLT_FLT(THRUST_MOVE_DAMPING, BYBIT(0x678B74, 0x84F710));
    DECL_VALUE_PLT_FLT(JETPACK_TURN_RATE, BYBIT(0x676A70, 0x84B528));
    DECL_VALUE_PLT_FLT(JETPACK_ANGLE_RATE, BYBIT(0x678148, 0x84E2A8));
    DECL_VALUE_PLT_FLT(LEG_SWING_MAX_ANGLE, BYBIT(0x676A38, 0x84B4B8));
    DECL_VALUE_PLT_FLT(LEG_SWING_DELTA_V_MULT, BYBIT(0x679E44, 0x851C98));
    DECL_VALUE_PLT_FLT(LEG_SWING_GRAVITY_MULT, BYBIT(0x678744, 0x84EEB0));
    DECL_VALUE_PLT_FLT(LEG_SWING_DAMP_FRAC, BYBIT(0x679E78, 0x851D00));

    // Member functions
    DECL_THISCALL_HEAD(ApplyRollAndPitch, _ZN18CTaskSimpleJetPack17ApplyRollAndPitchEP4CPed, void, CPed* pPed)
    DECL_THISCALL_TAIL(ApplyRollAndPitch, pPed)
    DECL_THISCALL_HEAD(RenderJetPack, _ZN18CTaskSimpleJetPack13RenderJetPackEP4CPed, void, CPed* pPed)
    DECL_THISCALL_TAIL(RenderJetPack, pPed)
    DECL_THISCALL_HEAD(DropJetPack, _ZN18CTaskSimpleJetPack11DropJetPackEP4CPed, void, CPed* pPed)
    DECL_THISCALL_TAIL(DropJetPack, pPed)
    DECL_THISCALL_HEAD(ProcessControlInput, _ZN18CTaskSimpleJetPack19ProcessControlInputEP10CPlayerPed, void, CPlayerPed* pPlayerPed)
    DECL_THISCALL_TAIL(ProcessControlInput, pPlayerPed)
    DECL_THISCALL_HEAD(ProcessControlAI, _ZN18CTaskSimpleJetPack16ProcessControlAIEP4CPed, void, CPed* pPed)
    DECL_THISCALL_TAIL(ProcessControlAI, pPed)
    DECL_THISCALL_HEAD(ProcessAnims, _ZN18CTaskSimpleJetPack12ProcessAnimsEP4CPed, bool, CPed* pPed)
    DECL_THISCALL_TAIL(ProcessAnims, pPed)
    DECL_THISCALL_HEAD(ProcessThrust, _ZN18CTaskSimpleJetPack13ProcessThrustEP4CPed, void, CPed* pPed)
    DECL_THISCALL_TAIL(ProcessThrust, pPed)
    DECL_THISCALL_HEAD(DoJetPackEffect, _ZN18CTaskSimpleJetPack15DoJetPackEffectEP4CPed, void, CPed* pPed)
    DECL_THISCALL_TAIL(DoJetPackEffect, pPed)
    DECL_THISCALL_SIMPLE(StopJetPackEffect, _ZN18CTaskSimpleJetPack17StopJetPackEffectEv, void);

    // Member values
    u8 m_bIsFinished;
    u8 m_bAddedIdleAnim;
    u8 m_bAnimsReferenced;
    u8 m_bAttackButtonPressed;
    u8 m_bSwitchedWeapons;
    i8 m_nThrustStop;
    i8 m_nThrustFwd;
    float m_fThrustStrafe;
    float m_fThrustAngle;
    float m_fLegSwingFwd;
    float m_fLegSwingSide;
    float m_fLegTwist;
    float m_fLegSwingFwdSpeed;
    float m_fLegSwingSideSpeed;
    float m_fLegTwistSpeed;
    CVector m_vecOldSpeed;
    float m_fOldHeading;
    RpClump* m_pJetPackClump;
    CAnimBlendAssociation* m_pAnim;
    CVector m_vecTargetPos;
    float m_fCruiseHeight;
    i32 m_nHoverTime;
    u32 m_nStartHover;
    CEntity* m_pTargetEnt;
    FxSystem_c* m_pFxSysL;
    FxSystem_c* m_pFxSysR;
    float m_fxKeyTime;
DECL_CLASS_END()
CHECKSIZE(CTaskSimpleJetPack, 0x70, 0x90);

DECL_CLASS_BASED(CTaskSimpleSwim, CTaskSimple)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CTaskSimpleSwim, _ZN15CTaskSimpleSwimC2EPK7CVectorP4CPed, CVector const* pTargetPos, CPed* pTargetPed);
    DECL_NEWCALL(CTaskSimpleSwim, BYBIT(_ZN5CTasknwEj, _ZN5CTasknwEm));

    // STATIC functions
    DECL_FASTCALL_SIMPLE(CreateTask, _ZN15CTaskSimpleSwim10CreateTaskEv, CTask*);

    // STATIC values
    DECL_VALUE_PLT_FLT(SWIM_STOP_TIME, BYBIT(0x677B7C, 0x84D718));
    DECL_VALUE_PLT_FLT(SWIM_DIVE_UNDER_ANGLE, BYBIT(0x67983C, 0x851088));

    // Member functions
    DECL_THISCALL_HEAD(ApplyRollAndPitch, _ZN15CTaskSimpleSwim17ApplyRollAndPitchEP4CPed, void, CPed* pPed)
    DECL_THISCALL_TAIL(ApplyRollAndPitch, pPed)
    DECL_THISCALL_HEAD(ProcessControlInput, _ZN15CTaskSimpleSwim19ProcessControlInputEP10CPlayerPed, void, CPlayerPed* pPlayerPed)
    DECL_THISCALL_TAIL(ProcessControlInput, pPlayerPed)
    DECL_THISCALL_HEAD(ProcessControlAI, _ZN15CTaskSimpleSwim16ProcessControlAIEP4CPed, void, CPed* pPed)
    DECL_THISCALL_TAIL(ProcessControlAI, pPed)
    DECL_THISCALL_HEAD(ProcessSwimAnims, _ZN15CTaskSimpleSwim16ProcessSwimAnimsEP4CPed, void, CPed* pPed)
    DECL_THISCALL_TAIL(ProcessSwimAnims, pPed)
    DECL_THISCALL_HEAD(ProcessSwimmingResistance, _ZN15CTaskSimpleSwim25ProcessSwimmingResistanceEP4CPed, void, CPed* pPed)
    DECL_THISCALL_TAIL(ProcessSwimmingResistance, pPed)
    DECL_THISCALL_HEAD(ProcessEffects, _ZN15CTaskSimpleSwim14ProcessEffectsEP4CPed, void, CPed* pPed)
    DECL_THISCALL_TAIL(ProcessEffects, pPed)
    DECL_THISCALL_HEAD(CreateFxSystem, _ZN15CTaskSimpleSwim14CreateFxSystemEP4CPedP11RwMatrixTag, void, CPed* pPed, RwMatrix* pMat)
    DECL_THISCALL_TAIL(CreateFxSystem, pPed, pMat)
    DECL_THISCALL_SIMPLE(DestroyFxSystem, _ZN15CTaskSimpleSwim15DestroyFxSystemEv, void);

    // Member values
    bool m_bAddedIdleAnim;
    bool m_bAnimsReferenced;
    i16 m_nSwimState;
    AnimationId m_nSwimAnim;
    float m_fControlSpeed;
    CVector m_vecTargetPos;
    CPed* m_pTargetPed;
    float m_fDiveAngle;
    float m_fRollAngle;
    float m_fPitchTorso;
    float m_fRollTorso;
    float m_fDiveSurfaceSpeed;
    int m_nLastParticleTime;
    CEntity* m_pClimbEnt;
    CVector m_vecEdge;
    float m_fEdgeHeading;
    u8 m_nEdgeSurfaceType;
    float fDistanceOffset;
    float m_fStopTimer;
    u32 m_nSwimTimer;
    FxSystem_c* m_pFxSys;
    u8 m_playedDiveSplash;
DECL_CLASS_END()
CHECKSIZE(CTaskSimpleSwim, 0x68, 0x80);

DECL_CLASS_BASED(CTaskComplexFollowPointRoute, CTaskComplex)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CTaskComplexFollowPointRoute, _ZN28CTaskComplexFollowPointRouteC2EiRK11CPointRouteiffbbb, int const iMoveState, CPointRoute const& route, int const iMode, float const fTargetRadius, float const fSlowDownDistance, bool const bMustOvershootTarget, bool const bUseBlending, bool const bStandStillAfterMove);
    enum
    {
        TICKET_SINGLE = 0,
        TICKET_RETURN = 1,
        TICKET_SEASON = 2,
        TICKET_LOOP = 3,
    };

    DECL_DTORCALL_PROXY(CTaskComplexFollowPointRoute, _ZN28CTaskComplexFollowPointRouteD2Ev);
    DECL_NEWCALL(CTaskComplexFollowPointRoute, BYBIT(_ZN5CTasknwEj, _ZN5CTasknwEm));

    // STATIC functions
    DECL_FASTCALL_SIMPLE(CreateTask, _ZN28CTaskComplexFollowPointRoute10CreateTaskEv, CTask*);

    // STATIC values
    DECL_OBJECT_PLT(float const, ms_fTargetRadius, BYBIT(0x678C20, 0x84F868));
    DECL_OBJECT_PLT(float const, ms_fSlowDownDistance, BYBIT(0x677F44, 0x84DEA8));
    DECL_OBJECT_PLT(CPointRoute, ms_pointRoute, BYBIT(0x6781AC, 0x84E370));

    // Member functions
    DECL_THISCALL_HEAD(SetRoute, _ZN28CTaskComplexFollowPointRoute8SetRouteERK11CPointRouteffb, void, CPointRoute const& route, float const fTargetRadius, float const fSlowDownDistance, bool const bForce)
    DECL_THISCALL_TAIL(SetRoute, route, fTargetRadius, fSlowDownDistance, bForce)
    DECL_THISCALL_SIMPLE(GetSubTaskType, _ZN28CTaskComplexFollowPointRoute14GetSubTaskTypeEv, int);
    DECL_THISCALL_HEAD(CreateSubTask, _ZN28CTaskComplexFollowPointRoute13CreateSubTaskEiP4CPed, CTask*, int const iTaskType, CPed* pPed)
    DECL_THISCALL_TAIL(CreateSubTask, iTaskType, pPed)
    DECL_THISCALL_HEAD(CalcGoToTaskType, _ZN28CTaskComplexFollowPointRoute16CalcGoToTaskTypeEP4CPedi, int, CPed* pPed, int iSubTaskType)
    DECL_THISCALL_TAIL(CalcGoToTaskType, pPed, iSubTaskType)
    DECL_THISCALL_HEAD(CalcBlendRatio, _ZN28CTaskComplexFollowPointRoute14CalcBlendRatioEP4CPedb, float, CPed* ped, bool slowing)
    DECL_THISCALL_TAIL(CalcBlendRatio, ped, slowing)
    DECL_THISCALL_HEAD(GetLastWaypoint, _ZN28CTaskComplexFollowPointRoute15GetLastWaypointEP4CPed, CVector, CPed* ped)
    DECL_THISCALL_TAIL(GetLastWaypoint, ped)
    DECL_THISCALL_HEAD(GetNextWaypoint, _ZN28CTaskComplexFollowPointRoute15GetNextWaypointEP4CPed, CVector, CPed* ped)
    DECL_THISCALL_TAIL(GetNextWaypoint, ped)

    // Member values
    int m_iMode;
    int m_iRouteTraversals;
    int m_iMoveState;
    float m_fTargetRadius;
    float m_fSlowDownDistance;
    CPointRoute* m_pRoute;
    int m_iProgress;
    u32 m_bMustOvershootTarget : 1;
    u32 m_bNewRoute : 1;
    u32 m_bStandStillAfterMove : 1;
    u32 m_bUseBlending : 1;
    u32 m_bWillSlowDown : 1;
    u32 m_bSlowingDown : 1;
    u32 m_bSpeedingUp : 1;
    float m_SpeedDecreaseDistance;
    float m_SpeedIncreaseDistance;
    float m_SpeedDecreaseAmt;
    float m_SpeedIncreaseAmt;
DECL_CLASS_END()
CHECKSIZE(CTaskComplexFollowPointRoute, 0x3C, 0x50);

DECL_CLASS_BASED(CTaskComplexWander, CTaskComplex)
    enum
    {
        WANDER_TYPE_STANDARD = 0,
        WANDER_TYPE_COP = 1,
        WANDER_TYPE_MEDIC = 2,
        WANDER_TYPE_CRIMINAL = 3,
        WANDER_TYPE_GANG = 4,
        WANDER_TYPE_SHOP = 5,
        WANDER_TYPE_FLEE = 6,
        WANDER_TYPE_PROSTITUTE = 7,
    };

    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CTaskComplexWander, _ZN18CTaskComplexWanderC2Eihbf, int const iMoveState, u8 const iDir, bool const bWanderSensibly, float targetRadius);
    DECL_NEWCALL(CTaskComplexWander, BYBIT(_ZN5CTasknwEj, _ZN5CTasknwEm));

    // Virtual functions
    virtual int GetWanderType() const;
    virtual void ScanForStuff(CPed* arg1);
    virtual void UpdateDir(CPed const* arg1);
    virtual void UpdatePathNodes(CPed const* arg1, u8 const arg2, CNodeAddress& arg3, CNodeAddress& arg4, u8& arg5);

    // STATIC functions
    DECL_FASTCALL_SIMPLE(GetWanderTaskByPedType1, _ZN18CTaskComplexWander22GetWanderTaskByPedTypeERK4CPed, CTaskComplexWander*, CPed const& arg1);
    inline static CTaskComplexWander* GetWanderTaskByPedType(CPed const& arg1)
    {
        return GetWanderTaskByPedType1(arg1);
    }
    DECL_FASTCALL_SIMPLE(GetWanderTaskByPedType2, _ZN18CTaskComplexWander22GetWanderTaskByPedTypeEi, CTaskComplexWander*, int const pedType);
    inline static CTaskComplexWander* GetWanderTaskByPedType(int const arg1)
    {
        return GetWanderTaskByPedType2(arg1);
    }

    // STATIC values
    DECL_OBJECT_PLT(float const, ms_fTargetRadius, BYBIT(0x678340, 0x84E698));

    // Member functions
    DECL_THISCALL_HEAD(SetDir, _ZN18CTaskComplexWander6SetDirEi, void, int const iDir)
    DECL_THISCALL_TAIL(SetDir, iDir)
    DECL_THISCALL_HEAD(ContinueFrom, _ZN18CTaskComplexWander12ContinueFromERKS_, void, CTaskComplexWander const& taskWander)
    DECL_THISCALL_TAIL(ContinueFrom, taskWander)
    DECL_THISCALL_HEAD(ComputeTargetPos, _ZNK18CTaskComplexWander16ComputeTargetPosEPK4CPedR7CVectorRK12CNodeAddress, void, CPed const* pPed, CVector& vTargetPos, CNodeAddress const& nextNode)
    DECL_THISCALL_TAIL(ComputeTargetPos, pPed, vTargetPos, nextNode)
    DECL_THISCALL_SIMPLE(ValidNodes, _ZNK18CTaskComplexWander10ValidNodesEv, bool);
    DECL_THISCALL_HEAD(ComputeTargetHeading, _ZNK18CTaskComplexWander20ComputeTargetHeadingEPK4CPed, float, CPed const* pPed)
    DECL_THISCALL_TAIL(ComputeTargetHeading, pPed)
    DECL_THISCALL_HEAD(ScanForBlockedNodes, _ZN18CTaskComplexWander19ScanForBlockedNodesEP4CPed, void, CPed* pPed)
    DECL_THISCALL_TAIL(ScanForBlockedNodes, pPed)
    DECL_THISCALL_NAMED_HEAD(ScanForBlockedNode1, ScanForBlockedNode, _ZNK18CTaskComplexWander18ScanForBlockedNodeEP4CPedRK12CNodeAddress, bool, CPed* pPed, CNodeAddress const& nextNode)
    DECL_THISCALL_TAIL(ScanForBlockedNode1, pPed, nextNode)
    DECL_THISCALL_NAMED_HEAD(ScanForBlockedNode2, ScanForBlockedNode, _ZNK18CTaskComplexWander18ScanForBlockedNodeERK7CVectorPK7CEntity, bool, CVector const& arg1, CEntity const* arg2)
    DECL_THISCALL_TAIL(ScanForBlockedNode2, arg1, arg2)
    DECL_THISCALL_HEAD(CreateSubTask, _ZN18CTaskComplexWander13CreateSubTaskEPK4CPedi, CTask*, CPed const* pPed, int const iSubTaskType)
    DECL_THISCALL_TAIL(CreateSubTask, pPed, iSubTaskType)

    // Member values
    int m_iMoveState;
    u8 m_iDir;
    float m_targetRadius;
    CNodeAddress m_LastNode;
    CNodeAddress m_NextNode;
    int m_lastUpdateDirFrameCount;
    u8 m_bWanderSensibly : 1;
    u8 m_bNewDir : 1;
    u8 m_bNewNodes : 1;
    u8 m_bAllNodesBlocked : 1;
DECL_CLASS_END()
CHECKSIZE(CTaskComplexWander, 0x28, 0x38);

DECL_CLASS_BASED(CTaskComplexCarDrive, CTaskComplex)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CTaskComplexCarDrive1, _ZN20CTaskComplexCarDriveC2EP8CVehiclefii, CVehicle* arg2, float const arg3, int const arg4, int const arg5);
    DECL_CTORCALL_PROXY(CTaskComplexCarDrive, _ZN20CTaskComplexCarDriveC2EP8CVehicle, CVehicle* pVehicle);
    DECL_DTORCALL_PROXY(CTaskComplexCarDrive, _ZN20CTaskComplexCarDriveD2Ev);
    DECL_NEWCALL(CTaskComplexCarDrive, BYBIT(_ZN5CTasknwEj, _ZN5CTasknwEm));

    // Virtual functions
    virtual void SetUpCar() const;
    virtual CTask* CreateSubTaskCannotGetInCar(CPed* arg1) const;
    virtual CTask* Drive(CPed* arg1);

    // STATIC functions
    DECL_FASTCALL_SIMPLE(CreateTask, _ZN20CTaskComplexCarDrive10CreateTaskEv, CTask*);

    // Member functions
    DECL_THISCALL_HEAD(CreateSubTask, _ZNK20CTaskComplexCarDrive13CreateSubTaskEiP4CPed, CTask*, int const iSubTaskType, CPed* pPed)
    DECL_THISCALL_TAIL(CreateSubTask, iSubTaskType, pPed)

    // Member values
    CVehicle* m_pVehicle;
    float m_fCruiseSpeed;
    int m_iDesiredCarModel;
    int m_iDrivingStyle;
    bool m_bAsDriver;
    i8 m_origDrivingMode;
    i8 m_origMission;
    u8 m_origCruiseSpeed;
    bool m_bIsCarSetUp;
DECL_CLASS_END()
CHECKSIZE(CTaskComplexCarDrive, 0x24, 0x38);

DECL_CLASS_BASED(CTaskComplexEnterCar, CTaskComplex)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CTaskComplexEnterCar, _ZN20CTaskComplexEnterCarC2EP8CVehiclebbbb, CVehicle* pTargetVehicle, bool const bAsDriver, bool const bQuitAfterOpeningDoor, bool const bQuitAfterDraggingPedOut, bool const bCarryOnAfterFallingOff);
    DECL_DTORCALL_PROXY(CTaskComplexEnterCar, _ZN20CTaskComplexEnterCarD2Ev);
    DECL_NEWCALL(CTaskComplexEnterCar, BYBIT(_ZN5CTasknwEj, _ZN5CTasknwEm));

    // Virtual functions
    virtual CTask* CreateNextSubTask_AfterSimpleCarAlign(CPed* arg1);

    // Member functions
    DECL_THISCALL_SIMPLE(GetTargetPos, _ZN20CTaskComplexEnterCar12GetTargetPosEv, CVector);
    DECL_THISCALL_HEAD(GetCameraStickModifier, _ZN20CTaskComplexEnterCar22GetCameraStickModifierEP4CPedfRfS2_S2_S2_, void, CPed* pPed, float fCamDist, float& fAlpha, float& fBeta, float& fStickAlpha, float& fStickBeta)
    DECL_THISCALL_TAIL(GetCameraStickModifier, pPed, fCamDist, fAlpha, fBeta, fStickAlpha, fStickBeta)
    DECL_THISCALL_SIMPLE(GetCameraAvoidVehicle, _ZN20CTaskComplexEnterCar21GetCameraAvoidVehicleEv, CVehicle*);
    DECL_THISCALL_HEAD(CreateSubTask, _ZN20CTaskComplexEnterCar13CreateSubTaskEiP4CPed, CTask*, int const iSubTaskType, CPed* pPed)
    DECL_THISCALL_TAIL(CreateSubTask, iSubTaskType, pPed)
    DECL_THISCALL_SIMPLE(ComputeTargetDoorOppositeToFlag, _ZN20CTaskComplexEnterCar31ComputeTargetDoorOppositeToFlagEv, int);
    DECL_THISCALL_HEAD(SetVehicleFlags, _ZN20CTaskComplexEnterCar15SetVehicleFlagsEP4CPed, void, CPed* pPed)
    DECL_THISCALL_TAIL(SetVehicleFlags, pPed)
    DECL_THISCALL_HEAD(PrepareVehicleForPedEnter, _ZN20CTaskComplexEnterCar25PrepareVehicleForPedEnterEP4CPed, void, CPed* pPed)
    DECL_THISCALL_TAIL(PrepareVehicleForPedEnter, pPed)
    DECL_THISCALL_HEAD(PreparePedForVehicleEnter, _ZN20CTaskComplexEnterCar25PreparePedForVehicleEnterEP4CPed, void, CPed* pPed)
    DECL_THISCALL_TAIL(PreparePedForVehicleEnter, pPed)
    DECL_THISCALL_HEAD(CreateTaskUtilityLineUpPedWithCar, _ZN20CTaskComplexEnterCar33CreateTaskUtilityLineUpPedWithCarEP4CPed, void, CPed* pPed)
    DECL_THISCALL_TAIL(CreateTaskUtilityLineUpPedWithCar, pPed)

    // Member values
    CVehicle* m_pTargetVehicle;
    u8 m_bAsDriver : 1;
    u8 m_bQuitAfterOpeningDoor : 1;
    u8 m_bQuitAfterDraggingPedOut : 1;
    u8 m_bCarryOnAfterFallingOff : 1;
    int m_iTargetDoor;
    int m_iTargetDoorOppositeToFlag;
    int m_iTargetSeat;
    int m_iDraggedPedDownTime;
    int m_iMoveState;
    u8 m_nNumGettingInSet;
    u8 m_nCamMovementChoice;
    CVector m_vTargetDoorPos;
    CTaskUtilityLineUpPedWithCar* m_pTaskUtilityLineUpPedWithCar;
    bool m_bIsAborting;
    CPed* m_pDraggedPed;
    u8 m_nDoorFlagsSet;
    float m_fCruiseSpeed;
    int m_iEnterCarStartTime;
DECL_CLASS_END()
CHECKSIZE(CTaskComplexEnterCar, 0x50, 0x70);

DECL_CLASS_BASED(CTaskComplexEnterCarAsDriver, CTaskComplexEnterCar)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CTaskComplexEnterCarAsDriver, _ZN28CTaskComplexEnterCarAsDriverC2EP8CVehicle, CVehicle* pTargetVehicle);
    DECL_NEWCALL(CTaskComplexEnterCarAsDriver, BYBIT(_ZN5CTasknwEj, _ZN5CTasknwEm));
DECL_CLASS_END()
CHECKSIZE(CTaskComplexEnterCarAsDriver, 0x50, 0x70);

DECL_CLASS_BASED(CTaskComplexLeaveCar, CTaskComplex)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CTaskComplexLeaveCar, _ZN20CTaskComplexLeaveCarC2EP8CVehicleiibb, CVehicle* pTargetVehicle, int const iTargetDoor, int const iDelayTime, bool const bSensibleLeaveCar, bool const bForceGetOut);
    DECL_DTORCALL_PROXY(CTaskComplexLeaveCar, _ZN20CTaskComplexLeaveCarD2Ev);
    DECL_NEWCALL(CTaskComplexLeaveCar, BYBIT(_ZN5CTasknwEj, _ZN5CTasknwEm));

    // STATIC functions
    DECL_FASTCALL_SIMPLE(CreateTask, _ZN20CTaskComplexLeaveCar10CreateTaskEv, CTask*);

    // Member functions
    DECL_THISCALL_HEAD(CreateSubTask, _ZN20CTaskComplexLeaveCar13CreateSubTaskEiP4CPed, CTask*, int const iSubTaskType, CPed* pPed)
    DECL_THISCALL_TAIL(CreateSubTask, iSubTaskType, pPed)
    DECL_THISCALL_HEAD(ComputeTargetDoor, _ZN20CTaskComplexLeaveCar17ComputeTargetDoorEP4CPed, void, CPed* pPed)
    DECL_THISCALL_TAIL(ComputeTargetDoor, pPed)
    DECL_THISCALL_HEAD(CreateTaskUtilityLineUpPedWithCar, _ZN20CTaskComplexLeaveCar33CreateTaskUtilityLineUpPedWithCarEP4CPed, void, CPed* pPed)
    DECL_THISCALL_TAIL(CreateTaskUtilityLineUpPedWithCar, pPed)
    DECL_THISCALL_HEAD(PrepareVehicleForPedExit, _ZN20CTaskComplexLeaveCar24PrepareVehicleForPedExitEP4CPed, void, CPed* pPed)
    DECL_THISCALL_TAIL(PrepareVehicleForPedExit, pPed)
    DECL_THISCALL_HEAD(PreparePedForVehicleExit, _ZN20CTaskComplexLeaveCar24PreparePedForVehicleExitEP4CPed, void, CPed* pPed)
    DECL_THISCALL_TAIL(PreparePedForVehicleExit, pPed)

    // Member values
    CVehicle* m_pTargetVehicle;
    int m_iTargetDoor;
    int m_iDelayTime;
    bool m_bSensibleLeaveCar;
    bool m_bForceGetOut;
    bool m_bDie;
    CTaskUtilityLineUpPedWithCar* m_pTaskUtilityLineUpPedWithCar;
    u8 m_nDoorFlagsSet;
    u8 m_nNumGettingInSet;
    AnimationId m_dieAnim;
    float m_fDieAnimBlendDelta;
    float m_fDieAnimSpeed;
    u8 m_bIsInAir;
DECL_CLASS_END()
CHECKSIZE(CTaskComplexLeaveCar, 0x34, 0x50);

DECL_CLASS_BASED(CTaskSimpleCarDrive, CTaskSimple)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CTaskSimpleCarDrive, _ZN19CTaskSimpleCarDriveC2EP8CVehicleP28CTaskUtilityLineUpPedWithCarb, CVehicle* pTargetVehicle, CTaskUtilityLineUpPedWithCar* pUtility, bool const bDriveAnyCar);
    DECL_DTORCALL_PROXY(CTaskSimpleCarDrive, _ZN19CTaskSimpleCarDriveD2Ev);
    DECL_NEWCALL(CTaskSimpleCarDrive, BYBIT(_ZN5CTasknwEj, _ZN5CTasknwEm));

    // STATIC functions
    DECL_FASTCALL_SIMPLE(FinishAnimCloseDoorRollingCB, _ZN19CTaskSimpleCarDrive28FinishAnimCloseDoorRollingCBEP21CAnimBlendAssociationPv, void, CAnimBlendAssociation* pAnim, void* pData);

    // Member functions
    DECL_THISCALL_HEAD(TriggerIK, _ZN19CTaskSimpleCarDrive9TriggerIKEP4CPed, void, CPed* pPed)
    DECL_THISCALL_TAIL(TriggerIK, pPed)
    DECL_THISCALL_HEAD(AbortIK, _ZN19CTaskSimpleCarDrive7AbortIKEP4CPed, void, CPed* pPed)
    DECL_THISCALL_TAIL(AbortIK, pPed)
    DECL_THISCALL_HEAD(StartAnimDoorCloseRolling, _ZN19CTaskSimpleCarDrive25StartAnimDoorCloseRollingEPK4CPed, void, CPed const* pPed)
    DECL_THISCALL_TAIL(StartAnimDoorCloseRolling, pPed)
    DECL_THISCALL_HEAD(ProcessBopping, _ZN19CTaskSimpleCarDrive14ProcessBoppingEP4CPedh, void, CPed* pPed, u8 active)
    DECL_THISCALL_TAIL(ProcessBopping, pPed, active)
    DECL_THISCALL_HEAD(GetPedsBopInfo, _ZN19CTaskSimpleCarDrive14GetPedsBopInfoEP4CPedPiS2_, void, CPed* pPed, i32* startTime, i32* bopPhase)
    DECL_THISCALL_TAIL(GetPedsBopInfo, pPed, startTime, bopPhase)
    DECL_THISCALL_SIMPLE(IsBopping, _ZN19CTaskSimpleCarDrive9IsBoppingEv, u8);
    DECL_THISCALL_HEAD(StartBopping, _ZN19CTaskSimpleCarDrive12StartBoppingEP4CPed, void, CPed* pPed)
    DECL_THISCALL_TAIL(StartBopping, pPed)
    DECL_THISCALL_SIMPLE(StopBopping, _ZN19CTaskSimpleCarDrive11StopBoppingEv, void);
    DECL_THISCALL_SIMPLE(UpdateBopping, _ZN19CTaskSimpleCarDrive13UpdateBoppingEv, void);
    DECL_THISCALL_HEAD(ProcessHeadBopping, _ZN19CTaskSimpleCarDrive18ProcessHeadBoppingEP4CPedhf, void, CPed* pPed, u8 active, float distSqr)
    DECL_THISCALL_TAIL(ProcessHeadBopping, pPed, active, distSqr)
    DECL_THISCALL_HEAD(ProcessArmBopping, _ZN19CTaskSimpleCarDrive17ProcessArmBoppingEP4CPedhf, void, CPed* pPed, u8 active, float distSqr)
    DECL_THISCALL_TAIL(ProcessArmBopping, pPed, active, distSqr)

    // Member values
    CVehicle* m_pTargetVehicle;
    CAnimBlendAssociation* m_pAnimCloseDoor;
    CTaskUtilityLineUpPedWithCar* m_pUtility;
    CTaskTimer m_passengerTimer;
    i32 m_bopStartTime;
    i32 m_currBopTime;
    i32 m_bopPhase;
    float m_currBop;
    i32 m_currBopSide;
    i32 m_headBopStartTime;
    i32 m_headBopType;
    float m_currHeadBop;
    float m_headBopDepth;
    float m_headBopBlend;
    i32 m_armBopStartTime;
    u32 m_nUpsideDownCounter;
    CTaskTimer m_broadcastStolenCarTimer;
    u8 m_isHeadBopActive : 1;
    u8 m_isArmBopActive : 1;
    u8 m_bDriveAnyCar : 1;
    u8 m_bFirstTime : 1;
    u8 m_bAddedPassengerAnim : 1;
    u8 m_bSetGettingInFlag : 1;
DECL_CLASS_END()
CHECKSIZE(CTaskSimpleCarDrive, 0x60, 0x78);

struct IKChain_c;
struct CTaskSimpleGunControl;
struct CTaskComplexSequence;

DECL_CLASS_BASED(CTaskSimpleGoTo, CTaskSimple)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CTaskSimpleGoTo, _ZN15CTaskSimpleGoToC2EiRK7CVectorf, int const iMoveState, CVector const& vTarget, float const fTargetRadius);
    DECL_DTORCALL_PROXY(CTaskSimpleGoTo, _ZN15CTaskSimpleGoToD2Ev);
    DECL_NEWCALL(CTaskSimpleGoTo, BYBIT(_ZN5CTasknwEj, _ZN5CTasknwEm));

    // Member functions
    DECL_THISCALL_HEAD(HasCircledTarget, _ZN15CTaskSimpleGoTo16HasCircledTargetEP4CPed, bool, CPed* pPed)
    DECL_THISCALL_TAIL(HasCircledTarget, pPed)
    DECL_THISCALL_HEAD(SetUpIK, _ZN15CTaskSimpleGoTo7SetUpIKEP4CPed, void, CPed* pPed)
    DECL_THISCALL_TAIL(SetUpIK, pPed)
    DECL_THISCALL_HEAD(QuitIK, _ZN15CTaskSimpleGoTo6QuitIKEP4CPed, void, CPed* pPed)
    DECL_THISCALL_TAIL(QuitIK, pPed)

    // STATIC values
    DECL_OBJECT_PLT(float const, ms_fTargetRadius, BYBIT(0x677A74, 0x84D510));

    // Member values
    int m_iMoveState;
    CVector m_vTarget;
    float m_fTargetRadius;
    u8 m_TargetSideFlags : 4;
    u8 m_bDoingIK : 1;
    u8 m_bNewTarget : 1;
DECL_CLASS_END()
CHECKSIZE(CTaskSimpleGoTo, 0x20, 0x28);

DECL_CLASS_BASED(CTaskSimpleGoToPoint, CTaskSimpleGoTo)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CTaskSimpleGoToPoint, _ZN20CTaskSimpleGoToPointC2EiRK7CVectorfbb, int const iMoveState, CVector const& vTarget, float const fTargetRadius, bool const bSlowSmoothlyApproachTarget, bool const bMustOverShootTarget);
    DECL_DTORCALL_PROXY(CTaskSimpleGoToPoint, _ZN20CTaskSimpleGoToPointD2Ev);
    DECL_NEWCALL(CTaskSimpleGoToPoint, BYBIT(_ZN5CTasknwEj, _ZN5CTasknwEm));

    // Member values
    u8 m_bSlowSmoothlyApproachTarget : 1;
    u8 m_bAborting : 1;
    u8 m_bSuccessful : 1;
    u8 m_bMustOverShootTarget : 1;
    u8 m_bDontCompleteThisFrame : 1;
    CVector m_vLastPedPos;
DECL_CLASS_END()
CHECKSIZE(CTaskSimpleGoToPoint, 0x2C, 0x38);

DECL_CLASS_BASED(CTaskSimpleGoToPointFine, CTaskSimpleGoTo)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CTaskSimpleGoToPointFine, _ZN24CTaskSimpleGoToPointFineC2Ef7CVectorfP7CEntity, float moveBlendRatio, CVector targetPos, float targetRadius, CEntity* pEntityWhichMayObscureWaypoint);
    DECL_DTORCALL_PROXY(CTaskSimpleGoToPointFine, _ZN24CTaskSimpleGoToPointFineD2Ev);
    DECL_NEWCALL(CTaskSimpleGoToPointFine, BYBIT(_ZN5CTasknwEj, _ZN5CTasknwEm));

    // STATIC functions
    DECL_FASTCALL_SIMPLE(BaseRatio, _ZN24CTaskSimpleGoToPointFine9BaseRatioE10eMoveState, float, eMoveState movestate);

    // Member functions
    DECL_THISCALL_HEAD(Finish, _ZN24CTaskSimpleGoToPointFine6FinishEP4CPed, void, CPed* pPed)
    DECL_THISCALL_TAIL(Finish, pPed)
    DECL_THISCALL_HEAD(SetTargetPos, _ZN24CTaskSimpleGoToPointFine12SetTargetPosE7CVector, void, CVector targetPos)
    DECL_THISCALL_TAIL(SetTargetPos, targetPos)
    DECL_THISCALL_HEAD(SetMoveRatio, _ZN24CTaskSimpleGoToPointFine12SetMoveRatioEf, void, float moveRatio)
    DECL_THISCALL_TAIL(SetMoveRatio, moveRatio)
    DECL_THISCALL_HEAD(SetBlendedMoveAnim, _ZN24CTaskSimpleGoToPointFine18SetBlendedMoveAnimEP4CPed, void, CPed* pPed)
    DECL_THISCALL_TAIL(SetBlendedMoveAnim, pPed)

    // Member values
    float m_moveBlendRatio;
DECL_CLASS_END()
CHECKSIZE(CTaskSimpleGoToPointFine, 0x24, 0x30);

DECL_CLASS_BASED(CTaskSimpleAchieveHeading, CTaskSimple)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CTaskSimpleAchieveHeading, _ZN25CTaskSimpleAchieveHeadingC2Efff, float const fDesiredHeading, float const fHeadingChangeRateFrac, float const fHeadingTolerance);
    DECL_DTORCALL_PROXY(CTaskSimpleAchieveHeading, _ZN25CTaskSimpleAchieveHeadingD2Ev);
    DECL_NEWCALL(CTaskSimpleAchieveHeading, BYBIT(_ZN5CTasknwEj, _ZN5CTasknwEm));

    // STATIC functions
    DECL_FASTCALL_SIMPLE(CreateTask, _ZN25CTaskSimpleAchieveHeading10CreateTaskEv, CTask*);

    // Member functions
    DECL_THISCALL_HEAD(SetUpIK, _ZN25CTaskSimpleAchieveHeading7SetUpIKEP4CPed, void, CPed* pPed)
    DECL_THISCALL_TAIL(SetUpIK, pPed)
    DECL_THISCALL_HEAD(QuitIK, _ZN25CTaskSimpleAchieveHeading6QuitIKEP4CPed, void, CPed* pPed)
    DECL_THISCALL_TAIL(QuitIK, pPed)

    // STATIC values
    DECL_OBJECT_PLT(float const, ms_fHeadingChangeRateFrac, BYBIT(0x6788C8, 0x84F1B0));
    DECL_OBJECT_PLT(float const, ms_fHeadingTolerance, BYBIT(0x67806C, 0x84E0F8));

    // Member values
    float m_fDesiredHeading;
    float m_fHeadingChangeRateFrac;
    float m_fHeadingTolerance;
    u8 m_bDoingIK : 1;
DECL_CLASS_END()
CHECKSIZE(CTaskSimpleAchieveHeading, 0x18, 0x20);

DECL_CLASS_BASED(CTaskSimpleRunNamedAnim, CTaskSimpleAnim)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CTaskSimpleRunNamedAnim, _ZN23CTaskSimpleRunNamedAnimC2EPKcS1_ifibbbb, char const* pAnimName, char const* pAnimGroupName, i32 const flags, float const fBlendDelta, int const iTime, bool const bDontInterrupt, bool const bRunInSequence, bool const bOffsetPed, bool const bHoldLastFrame);
    DECL_THISCALL_SIMPLE(Delete, _ZN23CTaskSimpleRunNamedAnimD0Ev, void);
    DECL_NEWCALL(CTaskSimpleRunNamedAnim, BYBIT(_ZN5CTasknwEj, _ZN5CTasknwEm));

    // STATIC functions
    DECL_FASTCALL_SIMPLE(CreateTask, _ZN23CTaskSimpleRunNamedAnim10CreateTaskEv, CTask*);
    DECL_FASTCALL_SIMPLE(FinishRunAnimMovePedCB, _ZN23CTaskSimpleRunNamedAnim22FinishRunAnimMovePedCBEP21CAnimBlendAssociationPv, void, CAnimBlendAssociation* pAnim, void* pData);

    // Member functions
    DECL_THISCALL_HEAD(StartAnim, _ZN23CTaskSimpleRunNamedAnim9StartAnimEP4CPed, void, CPed* pPed)
    DECL_THISCALL_TAIL(StartAnim, pPed)
    DECL_THISCALL_HEAD(OffsetPedPosition, _ZN23CTaskSimpleRunNamedAnim17OffsetPedPositionEP4CPed, void, CPed* pPed)
    DECL_THISCALL_TAIL(OffsetPedPosition, pPed)

    // Member values
    char m_animName[24];
    char m_animGroupName[16];
    float m_fBlendDelta;
    CAnimBlendHierarchy* m_pAnimHierarchy;
    int m_iTime;
    CTaskTimer m_timer;
    CVector m_offsetAtEnd;
    i32 m_flags;
    i16 m_animID;
DECL_CLASS_END()
CHECKSIZE(CTaskSimpleRunNamedAnim, 0x64, 0x78);

DECL_CLASS_BASED(CTaskSimpleRunTimedAnim, CTaskSimpleAnim)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CTaskSimpleRunTimedAnim, _ZN23CTaskSimpleRunTimedAnimC2E12AssocGroupId11AnimationIdffib, AssocGroupId const arg2, AnimationId const arg3, float const arg4, float const arg5, int const arg6, bool const arg7);
    DECL_CTORCALL_PROXY(CTaskSimpleRunTimedAnim1, _ZN23CTaskSimpleRunTimedAnimC2E12AssocGroupId11AnimationIdffiiPKcb, AssocGroupId const animGroup, AnimationId const animID, float const fBlendDelta, float const fBlendOutDelta, int const iDuration, int const iTaskType, char const* pTaskName, bool const bHoldLastFrame);
    DECL_THISCALL_SIMPLE(Delete, _ZN23CTaskSimpleRunTimedAnimD0Ev, void);
    DECL_NEWCALL(CTaskSimpleRunTimedAnim, BYBIT(_ZN5CTasknwEj, _ZN5CTasknwEm));

    // Member functions
    DECL_THISCALL_HEAD(StartAnim, _ZN23CTaskSimpleRunTimedAnim9StartAnimEP4CPed, void, CPed* pPed)
    DECL_THISCALL_TAIL(StartAnim, pPed)

    // Member values
    AssocGroupId m_animGroup;
    AnimationId m_animID;
    float m_fBlendDelta;
    float m_fBlendOutDelta;
    int m_iDuration;
    CTaskTimer m_timer;
    u16 m_iTaskType;
DECL_CLASS_END()
CHECKSIZE(CTaskSimpleRunTimedAnim, 0x34, 0x40);

DECL_CLASS_BASED(CTaskSimpleRunAnimLoopedMiddle, CTaskSimpleAnim)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CTaskSimpleRunAnimLoopedMiddle, _ZN30CTaskSimpleRunAnimLoopedMiddleC2E12AssocGroupId11AnimationIdfffib, AssocGroupId const animGroup, AnimationId const animID, float const fBlendDelta, float loopStartRatio, float loopEndRatio, i32 loopTime, bool const bHoldLastFrame);
    DECL_CTORCALL_PROXY(CTaskSimpleRunAnimLoopedMiddle1, _ZN30CTaskSimpleRunAnimLoopedMiddleC2EPKcS1_ifffib, char const* arg2, char const* arg3, i32 const arg4, float const arg5, float arg6, float arg7, i32 arg8, bool const arg9);
    DECL_THISCALL_SIMPLE(Delete, _ZN30CTaskSimpleRunAnimLoopedMiddleD0Ev, void);
    DECL_NEWCALL(CTaskSimpleRunAnimLoopedMiddle, BYBIT(_ZN5CTasknwEj, _ZN5CTasknwEm));

    // Member functions
    DECL_THISCALL_HEAD(StartAnim, _ZN30CTaskSimpleRunAnimLoopedMiddle9StartAnimEP4CPed, void, CPed* pPed)
    DECL_THISCALL_TAIL(StartAnim, pPed)

    // Member values
    AssocGroupId m_animGroup;
    AnimationId m_animID;
    i32 m_flags;
    char m_animName[24];
    char m_animGroupName[16];
    CAnimBlendHierarchy* m_pAnimHierarchy;
    float m_fBlendDelta;
    float m_loopStartRatio;
    float m_loopEndRatio;
    float m_loopStartTime;
    float m_loopEndTime;
    i32 m_loopTime;
    CTaskTimer m_timer;
    u16 m_iTaskType;
DECL_CLASS_END()
CHECKSIZE(CTaskSimpleRunAnimLoopedMiddle, 0x70, 0x80);

DECL_CLASS_BASED(CTaskComplexSequence, CTaskComplex)
    enum
    {
        REPEAT_NOT = 0,
        REPEAT_FOREVER = 1,
    };

    enum
    {
        MAX_SEQUENCE_SIZE = 8,
    };

    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CTaskComplexSequence, _ZN20CTaskComplexSequenceC2Ev);
    DECL_DTORCALL_PROXY(CTaskComplexSequence, _ZN20CTaskComplexSequenceD2Ev);
    DECL_NEWCALL(CTaskComplexSequence, BYBIT(_ZN5CTasknwEj, _ZN5CTasknwEm));

    // Member functions
    DECL_THISCALL_SIMPLE(Flush, _ZN20CTaskComplexSequence5FlushEv, void);
    DECL_THISCALL_NAMED_HEAD(AddTask1, AddTask, _ZN20CTaskComplexSequence7AddTaskEP5CTask, bool, CTask* pTask)
    DECL_THISCALL_TAIL(AddTask1, pTask)
    DECL_THISCALL_NAMED_HEAD(AddTask2, AddTask, _ZN20CTaskComplexSequence7AddTaskEiP5CTask, void, int const arg1, CTask* arg2)
    DECL_THISCALL_TAIL(AddTask2, arg1, arg2)
    DECL_THISCALL_HEAD(Contains, _ZN20CTaskComplexSequence8ContainsEi, bool, int const iTaskType)
    DECL_THISCALL_TAIL(Contains, iTaskType)

    // Member values
    int m_iProgress;
    CTask* m_tasks[8];
    int m_iRepeatMode;
    int m_iRepeatProgress;
    bool m_bCanBeEmptied;
    int m_iRefCount;
DECL_CLASS_END()
CHECKSIZE(CTaskComplexSequence, 0x40, 0x70);

DECL_CLASS_BASED(CTaskComplexUseSequence, CTaskComplex)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CTaskComplexUseSequence, _ZN23CTaskComplexUseSequenceC2Ei, int const id);
    DECL_DTORCALL_PROXY(CTaskComplexUseSequence, _ZN23CTaskComplexUseSequenceD2Ev);
    DECL_NEWCALL(CTaskComplexUseSequence, BYBIT(_ZN5CTasknwEj, _ZN5CTasknwEm));

    // STATIC functions
    DECL_FASTCALL_SIMPLE(CreateTask, _ZN23CTaskComplexUseSequence10CreateTaskEv, CTask*);

    // Member values
    int m_iSequenceId;
    int m_iProgress1;
    int m_iProgress2;
    int m_iRepeatProgress;
DECL_CLASS_END()
CHECKSIZE(CTaskComplexUseSequence, 0x1C, 0x28);

DECL_CLASS_BASED(CTaskComplexGoToPointAndStandStill, CTaskComplex)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CTaskComplexGoToPointAndStandStill, _ZN34CTaskComplexGoToPointAndStandStillC2EiRK7CVectorffbb, int const iMoveState, CVector const& vTarget, float const fTargetRadius, float const fSlowDownDistance, bool const bMustOvershootTarget, bool const bStopExactly);
    DECL_DTORCALL_PROXY(CTaskComplexGoToPointAndStandStill, _ZN34CTaskComplexGoToPointAndStandStillD2Ev);
    DECL_NEWCALL(CTaskComplexGoToPointAndStandStill, BYBIT(_ZN5CTasknwEj, _ZN5CTasknwEm));

    // STATIC functions
    DECL_FASTCALL_SIMPLE(CreateTask, _ZN34CTaskComplexGoToPointAndStandStill10CreateTaskEv, CTask*);

    // Member functions
    DECL_THISCALL_HEAD(SelectMoveState, _ZNK34CTaskComplexGoToPointAndStandStill15SelectMoveStateEP20CTaskSimpleGoToPointP4CPedff, void, CTaskSimpleGoToPoint* pGoToPoint, CPed* pPed, float fRunDistance, float fSprintDistance)
    DECL_THISCALL_TAIL(SelectMoveState, pGoToPoint, pPed, fRunDistance, fSprintDistance)
    DECL_THISCALL_HEAD(CreateSubTask, _ZNK34CTaskComplexGoToPointAndStandStill13CreateSubTaskEiP4CPed, CTask*, int iSubTaskType, CPed* pPed)
    DECL_THISCALL_TAIL(CreateSubTask, iSubTaskType, pPed)

    // STATIC values
    DECL_OBJECT_PLT(float const, ms_fTargetRadius, BYBIT(0x677B98, 0x84D750));
    DECL_OBJECT_PLT(float const, ms_fSlowDownDistance, BYBIT(0x67800C, 0x84E038));

    // Member values
    int m_iMoveState;
    CVector m_vTarget;
    float m_fTargetRadius;
    float m_fSlowDownDistance;
    u8 m_bMustOverShootTarget : 1;
    u8 m_bStopExactly : 1;
    u8 m_bNewTarget : 1;
    u8 m_bTrackingEntity : 1;
    u8 m_bWasSuccessful : 1;
DECL_CLASS_END()
CHECKSIZE(CTaskComplexGoToPointAndStandStill, 0x28, 0x38);

DECL_CLASS_BASED(CTaskComplexGoToPointAndStandStillTimed, CTaskComplexGoToPointAndStandStill)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CTaskComplexGoToPointAndStandStillTimed, _ZN39CTaskComplexGoToPointAndStandStillTimedC2EiRK7CVectorffi, int const iMoveState, CVector const& vTarget, float const fTargetRadius, float const fSlowDownDistance, int const iTime);
    DECL_DTORCALL_PROXY(CTaskComplexGoToPointAndStandStillTimed, _ZN39CTaskComplexGoToPointAndStandStillTimedD2Ev);
    DECL_NEWCALL(CTaskComplexGoToPointAndStandStillTimed, BYBIT(_ZN5CTasknwEj, _ZN5CTasknwEm));

    // STATIC values
    DECL_OBJECT_PLT(int const, ms_iTime, BYBIT(0x67922C, 0x850478));

    // Member values
    int m_iTime;
    CTaskTimer m_timer;
DECL_CLASS_END()
CHECKSIZE(CTaskComplexGoToPointAndStandStillTimed, 0x38, 0x48);

DECL_CLASS_BASED(CTaskComplexGoToPointAndStandStillAndAchieveHeading, CTaskComplex)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CTaskComplexGoToPointAndStandStillAndAchieveHeading, _ZN51CTaskComplexGoToPointAndStandStillAndAchieveHeadingC2EiRK7CVectorffff, int const iMoveState, CVector const& vTarget, float const fDesiredHeading, float const fTargetRadius, float const fHeadingChangeRateFrac, float const fHeadingTolerance);
    DECL_DTORCALL_PROXY(CTaskComplexGoToPointAndStandStillAndAchieveHeading, _ZN51CTaskComplexGoToPointAndStandStillAndAchieveHeadingD2Ev);
    DECL_NEWCALL(CTaskComplexGoToPointAndStandStillAndAchieveHeading, BYBIT(_ZN5CTasknwEj, _ZN5CTasknwEm));

    // STATIC functions
    DECL_FASTCALL_SIMPLE(CreateTask, _ZN51CTaskComplexGoToPointAndStandStillAndAchieveHeading10CreateTaskEv, CTask*);

    // Member functions
    DECL_THISCALL_HEAD(CreateSubTask, _ZN51CTaskComplexGoToPointAndStandStillAndAchieveHeading13CreateSubTaskEi, CTask*, int iSubTaskType)
    DECL_THISCALL_TAIL(CreateSubTask, iSubTaskType)

    // Member values
    int m_iMoveState;
    CVector m_vTarget;
    float m_fTargetRadius;
    float m_fDesiredHeading;
    float m_fHeadingChangeRateFrac;
    float m_fHeadingTolerance;
    u8 m_bNewTarget : 1;
DECL_CLASS_END()
CHECKSIZE(CTaskComplexGoToPointAndStandStillAndAchieveHeading, 0x30, 0x40);

DECL_CLASS_BASED(CTaskComplexFollowNodeRoute, CTaskComplex)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CTaskComplexFollowNodeRoute, _ZN27CTaskComplexFollowNodeRouteC2EiRK7CVectorfffbib, int const iMoveState, CVector const& vTarget, float const fTargetRadius, float const fSlowDownDistance, float const fFollowNodeThresholdHeightChange, bool const bKeepNodesHeadingAwayFromTarget, int const iTime, bool const bUseBlending);
    DECL_DTORCALL_PROXY(CTaskComplexFollowNodeRoute, _ZN27CTaskComplexFollowNodeRouteD2Ev);
    DECL_NEWCALL(CTaskComplexFollowNodeRoute, BYBIT(_ZN5CTasknwEj, _ZN5CTasknwEm));

    // STATIC functions
    DECL_FASTCALL_SIMPLE(CreateTask, _ZN27CTaskComplexFollowNodeRoute10CreateTaskEv, CTask*);
    DECL_FASTCALL_SIMPLE(GetSubTaskType, _ZN27CTaskComplexFollowNodeRoute14GetSubTaskTypeEibRK11CPointRoute, int, int const iProgress, bool const bLastRoutePointIsTarget, CPointRoute const& route);

    // Member functions
    DECL_THISCALL_SIMPLE(GetRouteSize, _ZN27CTaskComplexFollowNodeRoute12GetRouteSizeEv, int);
    DECL_THISCALL_HEAD(SetTarget, _ZN27CTaskComplexFollowNodeRoute9SetTargetEPK4CPedRK7CVectorfffb, void, CPed const* pPed, CVector const& vTarget, float const fTargetRadius, float const fSlowDownDistance, float const fFollowNodeThresholdHeightChange, bool const bForce)
    DECL_THISCALL_TAIL(SetTarget, pPed, vTarget, fTargetRadius, fSlowDownDistance, fFollowNodeThresholdHeightChange, bForce)
    DECL_THISCALL_HEAD(CalcGoToTaskType, _ZN27CTaskComplexFollowNodeRoute16CalcGoToTaskTypeEP4CPedi, int, CPed* pPed, int iSubTaskType)
    DECL_THISCALL_TAIL(CalcGoToTaskType, pPed, iSubTaskType)
    DECL_THISCALL_HEAD(CalcBlendRatio, _ZN27CTaskComplexFollowNodeRoute14CalcBlendRatioEP4CPedb, float, CPed* ped, bool slowing)
    DECL_THISCALL_TAIL(CalcBlendRatio, ped, slowing)
    DECL_THISCALL_HEAD(GetLastWaypoint, _ZN27CTaskComplexFollowNodeRoute15GetLastWaypointEP4CPed, CVector, CPed* ped)
    DECL_THISCALL_TAIL(GetLastWaypoint, ped)
    DECL_THISCALL_HEAD(GetNextWaypoint, _ZN27CTaskComplexFollowNodeRoute15GetNextWaypointEP4CPed, CVector, CPed* ped)
    DECL_THISCALL_TAIL(GetNextWaypoint, ped)
    DECL_THISCALL_HEAD(ComputePathNodes, _ZN27CTaskComplexFollowNodeRoute16ComputePathNodesEPK4CPed, void, CPed const* pPed)
    DECL_THISCALL_TAIL(ComputePathNodes, pPed)
    DECL_THISCALL_SIMPLE(ComputeRoute, _ZN27CTaskComplexFollowNodeRoute12ComputeRouteEv, void);
    DECL_THISCALL_HEAD(CanGoStraightThere, _ZNK27CTaskComplexFollowNodeRoute18CanGoStraightThereERK4CPedRK7CVectorS5_f, bool, CPed const& ped, CVector const& vStart, CVector const& vTarget, float const fFollowNodeThresholdDistance)
    DECL_THISCALL_TAIL(CanGoStraightThere, ped, vStart, vTarget, fFollowNodeThresholdDistance)
    DECL_THISCALL_HEAD(CreateSubTask, _ZNK27CTaskComplexFollowNodeRoute13CreateSubTaskEiP4CPed, CTask*, int const iSubTaskType, CPed* pPed)
    DECL_THISCALL_TAIL(CreateSubTask, iSubTaskType, pPed)

    // STATIC values
    DECL_OBJECT_PLT(float const, ms_fTargetRadius, BYBIT(0x676B6C, 0x84B720));
    DECL_OBJECT_PLT(float const, ms_fSlowDownDistance, BYBIT(0x6774B8, 0x84C9A8));
    DECL_OBJECT_PLT(float const, ms_fFollowNodeThresholdHeightChange, BYBIT(0x6784EC, 0x84E9F0));
    DECL_OBJECT_PLT(int const, ms_iDefaultTime, BYBIT(0x678C54, 0x84F8D0));

    // Member values
    CVector m_vTarget;
    int m_iMoveState;
    float m_fTargetRadius;
    float m_fSlowDownDistance;
    float m_fFollowNodeThresholdHeightChange;
    CNodeAddress m_startNode;
    CNodeRoute* m_pNodeRoute;
    CPointRoute* m_pPointRoute;
    CNodeAddress m_CurrentNode;
    int m_iProgress;
    int m_iTime;
    CTaskTimer m_timer;
    u32 m_bKeepNodesHeadingAwayFromTarget : 1;
    u32 m_bLastRoutePointIsTarget : 1;
    u32 m_bNewTarget : 1;
    u32 m_bUseBlending : 1;
    u32 m_bWillSlowDown : 1;
    u32 m_bSlowingDown : 1;
    u32 m_bSpeedingUp : 1;
    float m_SpeedDecreaseDistance;
    float m_SpeedIncreaseDistance;
    float m_SpeedDecreaseAmt;
    float m_SpeedIncreaseAmt;
DECL_CLASS_END()
CHECKSIZE(CTaskComplexFollowNodeRoute, 0x60, 0x78);

DECL_CLASS_BASED(CTaskComplexFollowPatrolRoute, CTaskComplex)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CTaskComplexFollowPatrolRoute, _ZN29CTaskComplexFollowPatrolRouteC2EiRK12CPatrolRouteiff, int const iMoveState, CPatrolRoute const& route, int const iMode, float const fTargetRadius, float const fSlowDownDistance);
    DECL_DTORCALL_PROXY(CTaskComplexFollowPatrolRoute, _ZN29CTaskComplexFollowPatrolRouteD2Ev);
    DECL_NEWCALL(CTaskComplexFollowPatrolRoute, BYBIT(_ZN5CTasknwEj, _ZN5CTasknwEm));

    // STATIC functions
    DECL_FASTCALL_SIMPLE(CreateTask, _ZN29CTaskComplexFollowPatrolRoute10CreateTaskEv, CTask*);

    // Member functions
    DECL_THISCALL_HEAD(SetRoute, _ZN29CTaskComplexFollowPatrolRoute8SetRouteERK12CPatrolRouteffb, void, CPatrolRoute const& route, float const fTargetRadius, float const fSlowDownDistance, bool const bForce)
    DECL_THISCALL_TAIL(SetRoute, route, fTargetRadius, fSlowDownDistance, bForce)
    DECL_THISCALL_SIMPLE(GetSubTaskType, _ZN29CTaskComplexFollowPatrolRoute14GetSubTaskTypeEv, int);
    DECL_THISCALL_HEAD(CreateSubTask, _ZN29CTaskComplexFollowPatrolRoute13CreateSubTaskEi, CTask*, int const iTaskType)
    DECL_THISCALL_TAIL(CreateSubTask, iTaskType)

    // STATIC values
    DECL_OBJECT_PLT(float const, ms_fTargetRadius, BYBIT(0x6770C0, 0x84C1B8));
    DECL_OBJECT_PLT(float const, ms_fSlowDownDistance, BYBIT(0x678BBC, 0x84F7A0));
    DECL_OBJECT_PLT(CPatrolRoute, ms_patrolRoute, BYBIT(0x678A60, 0x84F4E8));

    // Member values
    i16 m_iMode;
    i16 m_iRouteTraversals;
    i16 m_iMoveState;
    i16 m_iProgress;
    float m_fTargetRadius;
    float m_fSlowDownDistance;
    CPatrolRoute* m_pRoute;
    u32 m_bNewRoute : 1;
    u32 m_bIsAborting : 1;
    CVector m_PedPositionWhenAborted;
DECL_CLASS_END()
CHECKSIZE(CTaskComplexFollowPatrolRoute, 0x30, 0x40);

DECL_CLASS_BASED(CTaskComplexDriveToPoint, CTaskComplexCarDrive)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CTaskComplexDriveToPoint, _ZN24CTaskComplexDriveToPointC2EP8CVehicleRK7CVectorfiifi, CVehicle* pVehicle, CVector const& vTarget, float const fCruiseSpeed, int const iMode, int const iDesiredCarModel, float const fTargetRadius, int const iDrivingStyle);
    DECL_DTORCALL_PROXY(CTaskComplexDriveToPoint, _ZN24CTaskComplexDriveToPointD2Ev);
    DECL_NEWCALL(CTaskComplexDriveToPoint, BYBIT(_ZN5CTasknwEj, _ZN5CTasknwEm));

    // STATIC functions
    DECL_FASTCALL_SIMPLE(CreateTask, _ZN24CTaskComplexDriveToPoint10CreateTaskEv, CTask*);

    // Member functions
    DECL_THISCALL_NAMED_HEAD(IsTargetBlocked1, IsTargetBlocked, _ZNK24CTaskComplexDriveToPoint15IsTargetBlockedEP4CPed, bool, CPed* arg1)
    DECL_THISCALL_TAIL(IsTargetBlocked1, arg1)
    DECL_THISCALL_NAMED_HEAD(IsTargetBlocked2, IsTargetBlocked, _ZNK24CTaskComplexDriveToPoint15IsTargetBlockedEP4CPedPP7CEntityi, bool, CPed* pPed, CEntity** ppEntities, int const N)
    DECL_THISCALL_TAIL(IsTargetBlocked2, pPed, ppEntities, N)

    // Member values
    CVector m_vTarget;
    int m_iMode;
    float m_fTargetRadius;
    bool m_bAchievedTarget;
DECL_CLASS_END()
CHECKSIZE(CTaskComplexDriveToPoint, 0x3C, 0x50);

DECL_CLASS_BASED(CTaskComplexDrivePointRoute, CTaskComplex)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CTaskComplexDrivePointRoute, _ZN27CTaskComplexDrivePointRouteC2EP8CVehicleRK11CPointRoutefiifi, CVehicle* pVehicle, CPointRoute const& route, float const fCruiseSpeed, int const iMode, int const iDesiredCarModel, float const fTargetRadius, int const iDrivingStyle);
    DECL_DTORCALL_PROXY(CTaskComplexDrivePointRoute, _ZN27CTaskComplexDrivePointRouteD2Ev);
    DECL_NEWCALL(CTaskComplexDrivePointRoute, BYBIT(_ZN5CTasknwEj, _ZN5CTasknwEm));

    // STATIC functions
    DECL_FASTCALL_SIMPLE(CreateTask, _ZN27CTaskComplexDrivePointRoute10CreateTaskEv, CTask*);

    // Member values
    CVehicle* m_pVehicle;
    CPointRoute* m_pRoute;
    float m_fCruiseSpeed;
    int m_iMode;
    int m_iDesiredCarModel;
    float m_fTargetRadius;
    int m_iDrivingStyle;
    int m_iProgress;
DECL_CLASS_END()
CHECKSIZE(CTaskComplexDrivePointRoute, 0x2C, 0x40);

DECL_CLASS_BASED(CTaskComplexCarDriveWander, CTaskComplexCarDrive)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CTaskComplexCarDriveWander, _ZN26CTaskComplexCarDriveWanderC2EP8CVehicleif, CVehicle* pVehicle, int const iDrivingStyle, float const fCruiseSpeed);
    DECL_DTORCALL_PROXY(CTaskComplexCarDriveWander, _ZN26CTaskComplexCarDriveWanderD2Ev);
    DECL_NEWCALL(CTaskComplexCarDriveWander, BYBIT(_ZN5CTasknwEj, _ZN5CTasknwEm));

    // STATIC functions
    DECL_FASTCALL_SIMPLE(CreateTask, _ZN26CTaskComplexCarDriveWander10CreateTaskEv, CTask*);
DECL_CLASS_END()
CHECKSIZE(CTaskComplexCarDriveWander, 0x24, 0x38);

DECL_CLASS_BASED(CTaskComplexFleePoint, CTaskComplex)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CTaskComplexFleePoint, _ZN21CTaskComplexFleePointC2ERK7CVectorbfi, CVector const& vFleePos, bool const bScream, float const fSafeDistance, int const iFleeTime);
    DECL_DTORCALL_PROXY(CTaskComplexFleePoint, _ZN21CTaskComplexFleePointD2Ev);
    DECL_NEWCALL(CTaskComplexFleePoint, BYBIT(_ZN5CTasknwEj, _ZN5CTasknwEm));

    // Member functions
    DECL_THISCALL_HEAD(SetFleePosition, _ZN21CTaskComplexFleePoint15SetFleePositionERK7CVectorfb, void, CVector const& vFleePos, float const fSafeDistance, bool const bScream)
    DECL_THISCALL_TAIL(SetFleePosition, vFleePos, fSafeDistance, bScream)
    DECL_THISCALL_HEAD(ComputeTargetPoint, _ZN21CTaskComplexFleePoint18ComputeTargetPointEPK4CPed, void, CPed const* pPed)
    DECL_THISCALL_TAIL(ComputeTargetPoint, pPed)
    DECL_THISCALL_HEAD(CreateSubTask, _ZN21CTaskComplexFleePoint13CreateSubTaskEi, CTask*, int const iSubTaskType)
    DECL_THISCALL_TAIL(CreateSubTask, iSubTaskType)

    // STATIC values
    DECL_OBJECT_PLT(float const, ms_fSafeDistance, BYBIT(0x676800, 0x84B058));
    DECL_OBJECT_PLT(int const, ms_iFleeTime, BYBIT(0x6781A0, 0x84E358));

    // Member values
    CVector m_vFleePos;
    CVector m_vTargetPoint;
    int m_iFleeTime;
    CTaskTimer m_timer;
    float m_fSafeDistance;
    bool m_bScream;
    bool m_bNewFleePoint;
DECL_CLASS_END()
CHECKSIZE(CTaskComplexFleePoint, 0x3C, 0x48);

DECL_CLASS_BASED(CTaskComplexFleeEntity, CTaskComplex)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CTaskComplexFleeEntity, _ZN22CTaskComplexFleeEntityC2EP7CEntitybfiif, CEntity* pFleeEntity, bool const bScream, float const fSafeDistance, int const iFleeTime, int const iEntityPosCheckPeriod, float const fEntityPosChangeThreshold);
    DECL_DTORCALL_PROXY(CTaskComplexFleeEntity, _ZN22CTaskComplexFleeEntityD2Ev);
    DECL_NEWCALL(CTaskComplexFleeEntity, BYBIT(_ZN5CTasknwEj, _ZN5CTasknwEm));

    // Member functions
    DECL_THISCALL_HEAD(CreateSubTask, _ZN22CTaskComplexFleeEntity13CreateSubTaskEi, CTask*, int const iSubTaskType)
    DECL_THISCALL_TAIL(CreateSubTask, iSubTaskType)

    // STATIC values
    DECL_OBJECT_PLT(float const, ms_fSafeDistance, BYBIT(0x676F58, 0x84BEF0));
    DECL_OBJECT_PLT(int const, ms_iFleeTime, BYBIT(0x675EE8, 0x849E40));
    DECL_OBJECT_PLT(int const, ms_iEntityPosCheckPeriod, BYBIT(0x679520, 0x850A50));
    DECL_OBJECT_PLT(float const, ms_fEntityPosChangeThreshold, BYBIT(0x6775F8, 0x84CC20));

    // Member values
    CEntity* m_pFleeEntity;
    CVector m_vFleePos;
    int m_iFleeTime;
    CTaskTimer m_timer;
    float m_fSafeDistance;
    bool m_bScream;
    int m_iEntityPosCheckPeriod;
    float m_fEntityPosChangeThreshold;
DECL_CLASS_END()
CHECKSIZE(CTaskComplexFleeEntity, 0x3C, 0x50);

DECL_CLASS_BASED(CTaskComplexSmartFleePoint, CTaskComplex)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CTaskComplexSmartFleePoint, _ZN26CTaskComplexSmartFleePointC2ERK7CVectorbfi, CVector const& vFleePos, bool const bScream, float const fSafeDistance, int const iFleeTime);
    DECL_DTORCALL_PROXY(CTaskComplexSmartFleePoint, _ZN26CTaskComplexSmartFleePointD2Ev);
    DECL_NEWCALL(CTaskComplexSmartFleePoint, BYBIT(_ZN5CTasknwEj, _ZN5CTasknwEm));

    // Member functions
    DECL_THISCALL_HEAD(SetFleePosition, _ZN26CTaskComplexSmartFleePoint15SetFleePositionERK7CVectorfb, void, CVector const& vFleePos, float const fSafeDistance, bool const bScream)
    DECL_THISCALL_TAIL(SetFleePosition, vFleePos, fSafeDistance, bScream)
    DECL_THISCALL_HEAD(CreateSubTask, _ZN26CTaskComplexSmartFleePoint13CreateSubTaskEiP4CPed, CTask*, int const iSubTaskType, CPed* pPed)
    DECL_THISCALL_TAIL(CreateSubTask, iSubTaskType, pPed)
    DECL_THISCALL_HEAD(ComputeFleeDir, _ZNK26CTaskComplexSmartFleePoint14ComputeFleeDirEP4CPed, u8, CPed* pPed)
    DECL_THISCALL_TAIL(ComputeFleeDir, pPed)
    DECL_THISCALL_HEAD(SetDefaultTaskWanderDir, _ZNK26CTaskComplexSmartFleePoint23SetDefaultTaskWanderDirEP4CPed, void, CPed* pPed)
    DECL_THISCALL_TAIL(SetDefaultTaskWanderDir, pPed)

    // STATIC values
    DECL_OBJECT_PLT(float const, ms_fSafeDistance, BYBIT(0x67717C, 0x84C330));
    DECL_OBJECT_PLT(int const, ms_iFleeTime, BYBIT(0x676EFC, 0x84BE38));

    // Member values
    CVector m_vStartPos;
    CVector m_vFleePos;
    bool m_bScream;
    int m_iFleeTime;
    float m_fSafeDistance;
    int m_iMoveState;
    CTaskTimer m_timer;
    u8 m_iFleeDir;
    bool m_bNewFleePoint;
DECL_CLASS_END()
CHECKSIZE(CTaskComplexSmartFleePoint, 0x44, 0x50);

DECL_CLASS_BASED(CTaskComplexSmartFleeEntity, CTaskComplex)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CTaskComplexSmartFleeEntity, _ZN27CTaskComplexSmartFleeEntityC2EP7CEntitybfiif, CEntity* pFleeEntity, bool const bScream, float const fSafeDistance, int const iFleeTime, int const iEntityPosCheckPeriod, float const fEntityPosChangeThreshold);
    DECL_DTORCALL_PROXY(CTaskComplexSmartFleeEntity, _ZN27CTaskComplexSmartFleeEntityD2Ev);
    DECL_NEWCALL(CTaskComplexSmartFleeEntity, BYBIT(_ZN5CTasknwEj, _ZN5CTasknwEm));

    // STATIC functions
    DECL_FASTCALL_SIMPLE(CreateTask, _ZN27CTaskComplexSmartFleeEntity10CreateTaskEv, CTask*);

    // Member functions
    DECL_THISCALL_HEAD(CreateSubTask, _ZN27CTaskComplexSmartFleeEntity13CreateSubTaskEi, CTask*, int const iSubTaskType)
    DECL_THISCALL_TAIL(CreateSubTask, iSubTaskType)

    // STATIC values
    DECL_OBJECT_PLT(float const, ms_fSafeDistance, BYBIT(0x6774E4, 0x84CA00));
    DECL_OBJECT_PLT(int const, ms_iFleeTime, BYBIT(0x6789EC, 0x84F3F8));
    DECL_OBJECT_PLT(int const, ms_iEntityPosCheckPeriod, BYBIT(0x678004, 0x84E028));
    DECL_OBJECT_PLT(float const, ms_fEntityPosChangeThreshold, BYBIT(0x67958C, 0x850B28));

    // Member values
    CEntity* m_pFleeEntity;
    CVector m_vFleePos;
    int m_iFleeTime;
    float m_fSafeDistance;
    bool m_bScream;
    int m_iEntityPosCheckPeriod;
    float m_fEntityPosChangeThreshold;
    int m_iMoveState;
    CTaskTimer m_timer;
DECL_CLASS_END()
CHECKSIZE(CTaskComplexSmartFleeEntity, 0x40, 0x50);

DECL_CLASS_BASED(CTaskComplexTurnToFaceEntityOrCoord, CTaskComplex)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CTaskComplexTurnToFaceEntityOrCoord, _ZN35CTaskComplexTurnToFaceEntityOrCoordC2EP7CEntityff, CEntity* arg2, float const arg3, float const arg4);
    DECL_CTORCALL_PROXY(CTaskComplexTurnToFaceEntityOrCoord1, _ZN35CTaskComplexTurnToFaceEntityOrCoordC2ERK7CVectorff, CVector const& vTarget, float const fHeadingChangeRateFrac, float const fHeadingTolerance);
    DECL_DTORCALL_PROXY(CTaskComplexTurnToFaceEntityOrCoord, _ZN35CTaskComplexTurnToFaceEntityOrCoordD2Ev);
    DECL_NEWCALL(CTaskComplexTurnToFaceEntityOrCoord, BYBIT(_ZN5CTasknwEj, _ZN5CTasknwEm));

    // STATIC functions
    DECL_FASTCALL_SIMPLE(CreateTask, _ZN35CTaskComplexTurnToFaceEntityOrCoord10CreateTaskEv, CTask*);

    // Member functions
    DECL_THISCALL_HEAD(ComputeTargetHeading, _ZNK35CTaskComplexTurnToFaceEntityOrCoord20ComputeTargetHeadingEP4CPed, float, CPed* pPed)
    DECL_THISCALL_TAIL(ComputeTargetHeading, pPed)

    // Member values
    CEntity* m_pEntity;
    bool m_bFacingEntity;
    CVector m_vTarget;
    float m_fHeadingChangeRateFrac;
    float m_fHeadingTolerance;
DECL_CLASS_END()
CHECKSIZE(CTaskComplexTurnToFaceEntityOrCoord, 0x28, 0x38);

DECL_CLASS_BASED(CTaskSimplePlayerOnFoot, CTaskSimple)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CTaskSimplePlayerOnFoot, _ZN23CTaskSimplePlayerOnFootC2Ev);
    DECL_DTORCALL_PROXY(CTaskSimplePlayerOnFoot, _ZN23CTaskSimplePlayerOnFootD2Ev);
    DECL_NEWCALL(CTaskSimplePlayerOnFoot, BYBIT(_ZN5CTasknwEj, _ZN5CTasknwEm));

    // Member functions
    DECL_THISCALL_HEAD(ProcessPlayerWeapon, _ZN23CTaskSimplePlayerOnFoot19ProcessPlayerWeaponEP10CPlayerPed, void, CPlayerPed* pPlayerPed)
    DECL_THISCALL_TAIL(ProcessPlayerWeapon, pPlayerPed)
    DECL_THISCALL_HEAD(PlayIdleAnimations, _ZN23CTaskSimplePlayerOnFoot18PlayIdleAnimationsEP10CPlayerPed, void, CPlayerPed* pPlayerPed)
    DECL_THISCALL_TAIL(PlayIdleAnimations, pPlayerPed)
    DECL_THISCALL_HEAD(PlayerControlZelda, _ZN23CTaskSimplePlayerOnFoot18PlayerControlZeldaEP10CPlayerPedb, void, CPlayerPed* pPlayerPed, bool const bMoveOnly)
    DECL_THISCALL_TAIL(PlayerControlZelda, pPlayerPed, bMoveOnly)
    DECL_THISCALL_HEAD(PlayerControlZeldaWeapon, _ZN23CTaskSimplePlayerOnFoot24PlayerControlZeldaWeaponEP10CPlayerPed, void, CPlayerPed* pPlayerPed)
    DECL_THISCALL_TAIL(PlayerControlZeldaWeapon, pPlayerPed)
    DECL_THISCALL_HEAD(PlayerControlFighter, _ZN23CTaskSimplePlayerOnFoot20PlayerControlFighterEP10CPlayerPed, void, CPlayerPed* pPlayerPed)
    DECL_THISCALL_TAIL(PlayerControlFighter, pPlayerPed)
    DECL_THISCALL_HEAD(PlayerControlDucked, _ZN23CTaskSimplePlayerOnFoot19PlayerControlDuckedEP10CPlayerPed, void, CPlayerPed* pPlayerPed)
    DECL_THISCALL_TAIL(PlayerControlDucked, pPlayerPed)

    // Member values
    CVector m_vecEdge;
    float m_fEdgeHeading;
    u8 m_nEdgeSurfaceType;
    CEntity* m_pClimbEnt;
    i32 m_nPlayerIdlesAnimBlock;
    u32 m_nLastFrameProcessed;
    u32 m_nFightIdleMoveCount;
    float m_fControlSprint;
    CEntity* m_lastLookAtEntity;
DECL_CLASS_END()
CHECKSIZE(CTaskSimplePlayerOnFoot, 0x34, 0x48);

DECL_CLASS_BASED(CTaskSimpleStealthKill, CTaskSimple)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CTaskSimpleStealthKill, _ZN22CTaskSimpleStealthKillC2EbP4CPed12AssocGroupId, bool bAttacker, CPed* pPed, AssocGroupId nAnimGroup);
    DECL_DTORCALL_PROXY(CTaskSimpleStealthKill, _ZN22CTaskSimpleStealthKillD2Ev);
    DECL_NEWCALL(CTaskSimpleStealthKill, BYBIT(_ZN5CTasknwEj, _ZN5CTasknwEm));

    // STATIC functions
    DECL_FASTCALL_SIMPLE(FinishAnimStealthKillCB, _ZN22CTaskSimpleStealthKill23FinishAnimStealthKillCBEP21CAnimBlendAssociationPv, void, CAnimBlendAssociation* pAnim, void* pData);

    // Member functions
    DECL_THISCALL_HEAD(ManageAnim, _ZN22CTaskSimpleStealthKill10ManageAnimEP4CPed, void, CPed* pPed)
    DECL_THISCALL_TAIL(ManageAnim, pPed)

    // Member values
    bool m_bAttacker;
    CPed* m_pOtherPed;
    AssocGroupId m_nAnimGroup;
    bool m_bIsFinished;
    bool m_bAnimAdded;
    CAnimBlendAssociation* m_pAnim;
    u32 m_nWaitForAnimCounter;
DECL_CLASS_END()
CHECKSIZE(CTaskSimpleStealthKill, 0x20, 0x38);

DECL_CLASS_BASED(CTaskSimpleGangDriveBy, CTaskSimple)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CTaskSimpleGangDriveBy, _ZN22CTaskSimpleGangDriveByC2EP7CEntityPK7CVectorfaab, CEntity* pTargetEntity, CVector const* pVecTarget, float fAbortRange, i8 FrequencyPercentage, i8 nDrivebyStyle, bool bSeatRHS);
    DECL_DTORCALL_PROXY(CTaskSimpleGangDriveBy, _ZN22CTaskSimpleGangDriveByD2Ev);
    DECL_NEWCALL(CTaskSimpleGangDriveBy, BYBIT(_ZN5CTasknwEj, _ZN5CTasknwEm));

    // STATIC functions
    DECL_FASTCALL_SIMPLE(FinishAnimGangDriveByCB, _ZN22CTaskSimpleGangDriveBy23FinishAnimGangDriveByCBEP21CAnimBlendAssociationPv, void, CAnimBlendAssociation* pAnim, void* pData);
    DECL_FASTCALL_SIMPLE(CreateTask, _ZN22CTaskSimpleGangDriveBy10CreateTaskEv, CTask*);

    // Member functions
    DECL_THISCALL_HEAD(FireGun, _ZN22CTaskSimpleGangDriveBy7FireGunEP4CPed, void, CPed* pPed)
    DECL_THISCALL_TAIL(FireGun, pPed)
    DECL_THISCALL_HEAD(LookForTarget, _ZN22CTaskSimpleGangDriveBy13LookForTargetEP4CPed, void, CPed* pPed)
    DECL_THISCALL_TAIL(LookForTarget, pPed)
    DECL_THISCALL_HEAD(PlayerTarget, _ZN22CTaskSimpleGangDriveBy12PlayerTargetEP4CPed, void, CPed* pPed)
    DECL_THISCALL_TAIL(PlayerTarget, pPed)
    DECL_THISCALL_HEAD(ManageAnim, _ZN22CTaskSimpleGangDriveBy10ManageAnimEP4CPed, bool, CPed* pPed)
    DECL_THISCALL_TAIL(ManageAnim, pPed)
    DECL_THISCALL_HEAD(AimGun, _ZN22CTaskSimpleGangDriveBy6AimGunEP4CPed, void, CPed* pPed)
    DECL_THISCALL_TAIL(AimGun, pPed)
    DECL_THISCALL_HEAD(LineOfSightClearForAttack, _ZN22CTaskSimpleGangDriveBy25LineOfSightClearForAttackEP4CPedR7CVector, bool, CPed* pPed, CVector& vecTarget)
    DECL_THISCALL_TAIL(LineOfSightClearForAttack, pPed, vecTarget)

    // STATIC values
    DECL_OBJECT_PLT(float, ANIM_LOOP_START, BYBIT(0x678CDC, 0x84F9E0));
    DECL_OBJECT_PLT(float, ANIM_LOOP_END, BYBIT(0x6780EC, 0x84E1F0));
    DECL_OBJECT_PLT(float, ANIM_LOOP_FIRE, BYBIT(0x675F80, 0x849F70));

    // Member values
    bool m_bIsFinished;
    bool m_bAnimsReferenced;
    bool m_bSeatRHS;
    bool m_bInRangeToShoot;
    bool m_bInWeaponRange;
    bool m_bReachedAbortRange;
    bool m_bFromScriptCommand;
    i8 m_nNextCommand;
    i8 m_nLastCommand;
    i8 m_nBurstShots;
    i8 m_nDrivebyStyle;
    i8 m_nFrequencyPercentage;
    i8 m_nFakeShootDirn;
    i16 m_nAttackTimer;
    u32 m_nLOSCheckTime;
    bool m_nLOSBlocked;
    float m_fAbortRange;
    AnimationId m_nRequiredAnim;
    AssocGroupId m_nRequiredAnimGroup;
    CAnimBlendAssociation* m_pAnim;
    CWeaponInfo* m_pWeaponInfo;
    CEntity* m_pTargetEntity;
    CVector m_vecCoords;
DECL_CLASS_END()
CHECKSIZE(CTaskSimpleGangDriveBy, 0x44, 0x60);

DECL_CLASS_BASED(CTaskSimpleGunControl, CTaskSimple)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CTaskSimpleGunControl, _ZN21CTaskSimpleGunControlC2EP7CEntityPK7CVectorS4_asi, CEntity* pTargetEntity, CVector const* pTargetPos, CVector const* pMoveTarget, i8 nFiringTask, i16 nBurstLength, i32 nMaxDuration);
    DECL_DTORCALL_PROXY(CTaskSimpleGunControl, _ZN21CTaskSimpleGunControlD2Ev);
    DECL_NEWCALL(CTaskSimpleGunControl, BYBIT(_ZN5CTasknwEj, _ZN5CTasknwEm));

    // STATIC functions
    DECL_FASTCALL_SIMPLE(CreateTask, _ZN21CTaskSimpleGunControl10CreateTaskEv, CTask*);

    // Member functions
    DECL_THISCALL_HEAD(ChangeFiringTask, _ZN21CTaskSimpleGunControl16ChangeFiringTaskEaP7CEntityP7CVectorS3_, void, i8 nFiringTask, CEntity* pTargetEntity, CVector* pTargetPos, CVector* pMoveTarget)
    DECL_THISCALL_TAIL(ChangeFiringTask, nFiringTask, pTargetEntity, pTargetPos, pMoveTarget)

    // STATIC values
    DECL_OBJECT_PLT(u32, DEFAULT_GUN_ATTACK_PERIOD, BYBIT(0x677B80, 0x84D720));

    // Member values
    bool m_bIsFinished;
    CEntity* m_pTargetEntity;
    CVector m_vecTargetPos;
    CVector m_vecMoveTarget;
    i32 m_nDuration;
    i16 m_nBurstLength;
    i8 m_nFiringTask;
    float m_fAttackFreq;
    u32 m_nNextAttackTime;
    bool m_bFirstTime;
    bool m_bBlockedLOS;
    u8 m_bAimImmediate;
DECL_CLASS_END()
CHECKSIZE(CTaskSimpleGunControl, 0x3C, 0x50);

DECL_CLASS_BASED(CTaskSimpleDead, CTaskSimple)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CTaskSimpleDead, _ZN15CTaskSimpleDeadC2Eib, int const iTimeOfDeath, bool const bHasDrowned);
    DECL_DTORCALL_PROXY(CTaskSimpleDead, _ZN15CTaskSimpleDeadD2Ev);
    DECL_NEWCALL(CTaskSimpleDead, BYBIT(_ZN5CTasknwEj, _ZN5CTasknwEm));

    // STATIC functions
    DECL_FASTCALL_SIMPLE(CreateTask, _ZN15CTaskSimpleDead10CreateTaskEv, CTask*);

    // Member values
    int m_iTimeOfDeath;
    u8 m_bFirstTime : 1;
    u8 m_bHasDrowned : 1;
    u8 m_bBloodPuddleCreated : 1;
DECL_CLASS_END()
CHECKSIZE(CTaskSimpleDead, 0x10, 0x18);

DECL_CLASS_BASED(CTaskSimpleDie, CTaskSimple)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CTaskSimpleDie, _ZN14CTaskSimpleDieC2EPKcS1_iff, char const* pAnimName, char const* pAnimGroupName, i32 const flags, float const fBlendDelta, float const fAnimSpeed);
    DECL_CTORCALL_PROXY(CTaskSimpleDie1, _ZN14CTaskSimpleDieC2E12AssocGroupId11AnimationIdff, AssocGroupId const arg2, AnimationId const arg3, float const arg4, float const arg5);
    DECL_CTORCALL_PROXY(CTaskSimpleDie2, _ZN14CTaskSimpleDieC2EP19CAnimBlendHierarchyiff, CAnimBlendHierarchy* arg2, i32 const arg3, float const arg4, float const arg5);
    DECL_DTORCALL_PROXY(CTaskSimpleDie, _ZN14CTaskSimpleDieD2Ev);
    DECL_NEWCALL(CTaskSimpleDie, BYBIT(_ZN5CTasknwEj, _ZN5CTasknwEm));

    // STATIC functions
    DECL_FASTCALL_SIMPLE(FinishAnimDieCB, _ZN14CTaskSimpleDie15FinishAnimDieCBEP21CAnimBlendAssociationPv, void, CAnimBlendAssociation* pAnim, void* pData);

    // Member functions
    DECL_THISCALL_HEAD(StartAnim, _ZN14CTaskSimpleDie9StartAnimEP4CPed, void, CPed* pPed)
    DECL_THISCALL_TAIL(StartAnim, pPed)

    // Member values
    AssocGroupId m_animGroup;
    AnimationId m_animID;
    CAnimBlendHierarchy* m_pAnimHierarchy;
    i32 m_flags;
    float m_fBlendDelta;
    float m_fAnimSpeed;
    u8 m_bIsFinished : 1;
    u8 m_bSentDeathEvent : 1;
    CAnimBlendAssociation* m_pAnim;
DECL_CLASS_END()
CHECKSIZE(CTaskSimpleDie, 0x28, 0x38);

DECL_CLASS_BASED(CTaskSimpleFall, CTaskSimple)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CTaskSimpleFall, _ZN15CTaskSimpleFallC2E11AnimationId12AssocGroupIdj, AnimationId const animID, AssocGroupId const animGroup, u32 nPauseTime);
    DECL_DTORCALL_PROXY(CTaskSimpleFall, _ZN15CTaskSimpleFallD2Ev);
    DECL_NEWCALL(CTaskSimpleFall, BYBIT(_ZN5CTasknwEj, _ZN5CTasknwEm));

    // STATIC functions
    DECL_FASTCALL_SIMPLE(FinishAnimFallCB, _ZN15CTaskSimpleFall16FinishAnimFallCBEP21CAnimBlendAssociationPv, void, CAnimBlendAssociation* pAnim, void* pData);

    // Member functions
    DECL_THISCALL_HEAD(StartAnim, _ZN15CTaskSimpleFall9StartAnimEP4CPed, bool, CPed* pPed)
    DECL_THISCALL_TAIL(StartAnim, pPed)
    DECL_THISCALL_HEAD(ProcessFall, _ZN15CTaskSimpleFall11ProcessFallEP4CPed, void, CPed* pPed)
    DECL_THISCALL_TAIL(ProcessFall, pPed)

    // Member values
    bool m_bIsFinished;
    AnimationId m_animID;
    AssocGroupId m_animGroup;
    CAnimBlendAssociation* m_pAnim;
    u32 m_nPauseLength;
    u32 m_nPauseCountdown;
DECL_CLASS_END()
CHECKSIZE(CTaskSimpleFall, 0x20, 0x30);

DECL_CLASS_BASED(CTaskSimpleGetUp, CTaskSimple)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CTaskSimpleGetUp, _ZN16CTaskSimpleGetUpC2Ev);
    DECL_DTORCALL_PROXY(CTaskSimpleGetUp, _ZN16CTaskSimpleGetUpD2Ev);
    DECL_NEWCALL(CTaskSimpleGetUp, BYBIT(_ZN5CTasknwEj, _ZN5CTasknwEm));

    // STATIC functions
    DECL_FASTCALL_SIMPLE(FinishAnimGetUpCB, _ZN16CTaskSimpleGetUp17FinishAnimGetUpCBEP21CAnimBlendAssociationPv, void, CAnimBlendAssociation* pAnim, void* pData);

    // Member functions
    DECL_THISCALL_HEAD(StartAnim, _ZN16CTaskSimpleGetUp9StartAnimEP4CPed, bool, CPed* pPed)
    DECL_THISCALL_TAIL(StartAnim, pPed)

    // Member values
    bool m_bHasPedGotUp;
    bool m_bIsFinished;
    CAnimBlendAssociation* m_pAnim;
DECL_CLASS_END()
CHECKSIZE(CTaskSimpleGetUp, 0x10, 0x20);

DECL_CLASS_BASED(CTaskSimpleLand, CTaskSimple)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CTaskSimpleLand, _ZN15CTaskSimpleLandC2E11AnimationId, AnimationId const anim);
    DECL_DTORCALL_PROXY(CTaskSimpleLand, _ZN15CTaskSimpleLandD2Ev);
    DECL_NEWCALL(CTaskSimpleLand, BYBIT(_ZN5CTasknwEj, _ZN5CTasknwEm));

    // STATIC functions
    DECL_FASTCALL_SIMPLE(FinishAnimLandCB, _ZN15CTaskSimpleLand16FinishAnimLandCBEP21CAnimBlendAssociationPv, void, CAnimBlendAssociation* pAnim, void* pData);

    // Member functions
    DECL_THISCALL_SIMPLE(LeftFootLanded, _ZN15CTaskSimpleLand14LeftFootLandedEv, u8);
    DECL_THISCALL_SIMPLE(RightFootLanded, _ZN15CTaskSimpleLand15RightFootLandedEv, u8);

    // Member values
    CAnimBlendAssociation* m_pAnim;
    AnimationId m_animID;
    u8 m_bIsFinished : 1;
    u8 m_bDontPlayAnim : 1;
    u8 m_bFirstTime : 1;
DECL_CLASS_END()
CHECKSIZE(CTaskSimpleLand, 0x14, 0x20);

DECL_CLASS_BASED(CTaskSimpleJump, CTaskSimple)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CTaskSimpleJump, _ZN15CTaskSimpleJumpC2Eb, bool const bForceEdgeSearch);
    DECL_DTORCALL_PROXY(CTaskSimpleJump, _ZN15CTaskSimpleJumpD2Ev);
    DECL_NEWCALL(CTaskSimpleJump, BYBIT(_ZN5CTasknwEj, _ZN5CTasknwEm));

    // STATIC functions
    DECL_FASTCALL_SIMPLE(FinishAnimLaunchCB, _ZN15CTaskSimpleJump18FinishAnimLaunchCBEP21CAnimBlendAssociationPv, void, CAnimBlendAssociation* pAnim, void* pData);

    // Member functions
    DECL_THISCALL_HEAD(StartLaunchAnim, _ZN15CTaskSimpleJump15StartLaunchAnimEP4CPed, bool, CPed* pPed)
    DECL_THISCALL_TAIL(StartLaunchAnim, pPed)
    DECL_THISCALL_HEAD(Launch, _ZN15CTaskSimpleJump6LaunchEP4CPed, void, CPed* pPed)
    DECL_THISCALL_TAIL(Launch, pPed)
    DECL_THISCALL_HEAD(HasPedHitHead, _ZN15CTaskSimpleJump13HasPedHitHeadEP4CPed, bool, CPed* pPed)
    DECL_THISCALL_TAIL(HasPedHitHead, pPed)

    // Member values
    CVector m_vecEdge;
    float m_fEdgeHeading;
    u8 m_nEdgeSurfaceType;
    CEntity* m_pClimbEnt;
    bool m_bIsFinished;
    bool m_bHasHitHead;
    bool m_bFacingWall;
    bool m_bHasPedJumped;
    bool m_bForceEdgeSearch;
    bool m_bUsePlayerLaunchForce;
    CAnimBlendAssociation* m_pAnim;
DECL_CLASS_END()
CHECKSIZE(CTaskSimpleJump, 0x2C, 0x40);

DECL_CLASS_BASED(CTaskComplexJump, CTaskComplex)
    enum
    {
        CLIMB_DISABLE = -1,
        CLIMB_OK = 0,
        CLIMB_FORCE = 1,
    };

    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CTaskComplexJump, _ZN16CTaskComplexJumpC2Ei, i32 nForceClimb);
    DECL_DTORCALL_PROXY(CTaskComplexJump, _ZN16CTaskComplexJumpD2Ev);
    DECL_NEWCALL(CTaskComplexJump, BYBIT(_ZN5CTasknwEj, _ZN5CTasknwEm));

    // Member functions
    DECL_THISCALL_HEAD(CreateSubTask, _ZN16CTaskComplexJump13CreateSubTaskEiP4CPed, CTask*, int const iSubTaskType, CPed* pPed)
    DECL_THISCALL_TAIL(CreateSubTask, iSubTaskType, pPed)

    // Member values
    i32 m_nForceClimb;
    bool m_bUsePlayerLaunchForce;
DECL_CLASS_END()
CHECKSIZE(CTaskComplexJump, 0x14, 0x20);

DECL_CLASS_BASED(CTaskComplexFallAndGetUp, CTaskComplex)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CTaskComplexFallAndGetUp, _ZN24CTaskComplexFallAndGetUpC2E11AnimationId12AssocGroupIdi, AnimationId const arg2, AssocGroupId const arg3, int const arg4);
    DECL_CTORCALL_PROXY(CTaskComplexFallAndGetUp1, _ZN24CTaskComplexFallAndGetUpC2Eii, int const iDir, int const iDownTime);
    DECL_DTORCALL_PROXY(CTaskComplexFallAndGetUp, _ZN24CTaskComplexFallAndGetUpD2Ev);
    DECL_NEWCALL(CTaskComplexFallAndGetUp, BYBIT(_ZN5CTasknwEj, _ZN5CTasknwEm));

    // STATIC functions
    DECL_FASTCALL_SIMPLE(CreateTask, _ZN24CTaskComplexFallAndGetUp10CreateTaskEv, CTask*);

    // Member functions
    DECL_THISCALL_HEAD(SetDownTime, _ZN24CTaskComplexFallAndGetUp11SetDownTimeEi, void, int const iDownTime)
    DECL_THISCALL_TAIL(SetDownTime, iDownTime)
    DECL_THISCALL_SIMPLE(IsFalling, _ZNK24CTaskComplexFallAndGetUp9IsFallingEv, bool);
    DECL_THISCALL_HEAD(CreateSubTask, _ZN24CTaskComplexFallAndGetUp13CreateSubTaskEi, CTask*, int const iSubTaskType)
    DECL_THISCALL_TAIL(CreateSubTask, iSubTaskType)

    // Member values
    AnimationId m_animID;
    AssocGroupId m_animGroup;
    int m_iDownTime;
DECL_CLASS_END()
CHECKSIZE(CTaskComplexFallAndGetUp, 0x18, 0x28);

DECL_CLASS_BASED(CTaskSimplePickUpEntity, CTaskSimpleHoldEntity)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CTaskSimplePickUpEntity, _ZN23CTaskSimplePickUpEntityC2EP7CEntityPK7CVectorhh11AnimationId12AssocGroupIdf, CEntity* arg2, CVector const* arg3, u8 arg4, u8 arg5, AnimationId arg6, AssocGroupId arg7, float arg8);
    DECL_CTORCALL_PROXY(CTaskSimplePickUpEntity1, _ZN23CTaskSimplePickUpEntityC2EP7CEntityPK7CVectorhhPKcS6_if, CEntity* pEntity, CVector const* pVecOffset, u8 nBone, u8 nOrientateFlags, char const* pAnimName, char const* pAnimGroupName, i32 nFlags, float fTimeToAttach);
    DECL_CTORCALL_PROXY(CTaskSimplePickUpEntity2, _ZN23CTaskSimplePickUpEntityC2EP7CEntityPK7CVectorhhP10CAnimBlockP19CAnimBlendHierarchyif, CEntity* arg2, CVector const* arg3, u8 arg4, u8 arg5, CAnimBlock* arg6, CAnimBlendHierarchy* arg7, i32 arg8, float arg9);
    DECL_THISCALL_SIMPLE(Delete, _ZN23CTaskSimplePickUpEntityD0Ev, void);
    DECL_NEWCALL(CTaskSimplePickUpEntity, BYBIT(_ZN5CTasknwEj, _ZN5CTasknwEm));

    // Member values
    float m_fTimeToAttach;
    CVector m_vecTargetOffset;
DECL_CLASS_END()
CHECKSIZE(CTaskSimplePickUpEntity, 0x4C, 0x68);

DECL_CLASS_BASED(CTaskSimplePutDownEntity, CTaskSimpleHoldEntity)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CTaskSimplePutDownEntity, _ZN24CTaskSimplePutDownEntityC2EP7CEntityPK7CVectorhh11AnimationId12AssocGroupIdf, CEntity* arg2, CVector const* arg3, u8 arg4, u8 arg5, AnimationId arg6, AssocGroupId arg7, float arg8);
    DECL_CTORCALL_PROXY(CTaskSimplePutDownEntity1, _ZN24CTaskSimplePutDownEntityC2EP7CEntityPK7CVectorhhPKcS6_if, CEntity* pEntity, CVector const* pVecOffset, u8 nBone, u8 nOrientateFlags, char const* pAnimName, char const* pAnimGroupName, i32 nFlags, float fTimeToDrop);
    DECL_CTORCALL_PROXY(CTaskSimplePutDownEntity2, _ZN24CTaskSimplePutDownEntityC2EP7CEntityPK7CVectorhhP10CAnimBlockP19CAnimBlendHierarchyif, CEntity* arg2, CVector const* arg3, u8 arg4, u8 arg5, CAnimBlock* arg6, CAnimBlendHierarchy* arg7, i32 arg8, float arg9);
    DECL_CTORCALL_PROXY(CTaskSimplePutDownEntity3, _ZN24CTaskSimplePutDownEntityC2Ev);
    DECL_THISCALL_SIMPLE(Delete, _ZN24CTaskSimplePutDownEntityD0Ev, void);
    DECL_NEWCALL(CTaskSimplePutDownEntity, BYBIT(_ZN5CTasknwEj, _ZN5CTasknwEm));

    // Member values
    float m_fTimeToDrop;
DECL_CLASS_END()
CHECKSIZE(CTaskSimplePutDownEntity, 0x40, 0x60);

DECL_CLASS_BASED(CTaskSimpleArrestPed, CTaskSimple)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CTaskSimpleArrestPed, _ZN20CTaskSimpleArrestPedC2EP4CPed, CPed* pArrestedPed);
    DECL_DTORCALL_PROXY(CTaskSimpleArrestPed, _ZN20CTaskSimpleArrestPedD2Ev);
    DECL_NEWCALL(CTaskSimpleArrestPed, BYBIT(_ZN5CTasknwEj, _ZN5CTasknwEm));

    // STATIC functions
    DECL_FASTCALL_SIMPLE(FinishAnimArrestPedCB, _ZN20CTaskSimpleArrestPed21FinishAnimArrestPedCBEP21CAnimBlendAssociationPv, void, CAnimBlendAssociation* pAnim, void* pData);

    // Member functions
    DECL_THISCALL_HEAD(StartAnim, _ZN20CTaskSimpleArrestPed9StartAnimEP4CPed, void, CPed* pPed)
    DECL_THISCALL_TAIL(StartAnim, pPed)

    // Member values
    CPed* m_pArrestedPed;
    bool m_bIsFinished;
    CAnimBlendAssociation* m_pAnim;
DECL_CLASS_END()
CHECKSIZE(CTaskSimpleArrestPed, 0x14, 0x28);

DECL_CLASS_BASED(CTaskComplexArrestPed, CTaskComplex)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CTaskComplexArrestPed, _ZN21CTaskComplexArrestPedC2EP4CPed, CPed* pTargetPed);
    DECL_DTORCALL_PROXY(CTaskComplexArrestPed, _ZN21CTaskComplexArrestPedD2Ev);
    DECL_NEWCALL(CTaskComplexArrestPed, BYBIT(_ZN5CTasknwEj, _ZN5CTasknwEm));

    // Member functions
    DECL_THISCALL_HEAD(CreateSubTask, _ZN21CTaskComplexArrestPed13CreateSubTaskEiP4CPed, CTask*, int iSubTaskType, CPed* pPed)
    DECL_THISCALL_TAIL(CreateSubTask, iSubTaskType, pPed)

    // Member values
    bool m_bNewTarget;
    CPed* m_pTargetPed;
    float m_fDistanceToTarget;
    float m_fAttackRange;
    float m_fArriveRange;
    CVehicle const* m_pVehicleAttemptedWithLockedDoor;
DECL_CLASS_END()
CHECKSIZE(CTaskComplexArrestPed, 0x24, 0x40);

DECL_CLASS_BASED(CTaskComplexPolicePursuit, CTaskComplex)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CTaskComplexPolicePursuit, _ZN25CTaskComplexPolicePursuitC2Ev);
    DECL_DTORCALL_PROXY(CTaskComplexPolicePursuit, _ZN25CTaskComplexPolicePursuitD2Ev);
    DECL_NEWCALL(CTaskComplexPolicePursuit, BYBIT(_ZN5CTasknwEj, _ZN5CTasknwEm));

    // Member functions
    DECL_THISCALL_HEAD(SetPursuit, _ZN25CTaskComplexPolicePursuit10SetPursuitEP4CPed, bool, CPed* pPed)
    DECL_THISCALL_TAIL(SetPursuit, pPed)
    DECL_THISCALL_HEAD(ClearPursuit, _ZN25CTaskComplexPolicePursuit12ClearPursuitEP4CPed, void, CPed* pPed)
    DECL_THISCALL_TAIL(ClearPursuit, pPed)
    DECL_THISCALL_HEAD(PersistPursuit, _ZN25CTaskComplexPolicePursuit14PersistPursuitEP4CPed, bool, CPed* pPed)
    DECL_THISCALL_TAIL(PersistPursuit, pPed)
    DECL_THISCALL_HEAD(SetWeapon, _ZN25CTaskComplexPolicePursuit9SetWeaponEP4CPed, void, CPed* pPed)
    DECL_THISCALL_TAIL(SetWeapon, pPed)
    DECL_THISCALL_HEAD(CreateSubTask, _ZNK25CTaskComplexPolicePursuit13CreateSubTaskEiP4CPed, CTask*, int const iSubTaskType, CPed* pPed)
    DECL_THISCALL_TAIL(CreateSubTask, iSubTaskType, pPed)

    // Member values
    u8 m_bRoadBlockCop : 1;
    u8 m_bPlayerInCullZone : 1;
    u8 m_bCouldJoinPursuit : 1;
    CPed* m_pCopPed;
    CPlayerPed* m_pClosestPlayer;
DECL_CLASS_END()
CHECKSIZE(CTaskComplexPolicePursuit, 0x18, 0x30);

DECL_CLASS_BASED(CTaskSimpleTriggerEvent, CTaskSimple)
    // Construct/Deconstruct functions
    DECL_DTORCALL_PROXY(CTaskSimpleTriggerEvent, _ZN23CTaskSimpleTriggerEventD2Ev);
    DECL_NEWCALL(CTaskSimpleTriggerEvent, BYBIT(_ZN5CTasknwEj, _ZN5CTasknwEm));

    // Member values
    CEvent* m_pEvent;
DECL_CLASS_END()
CHECKSIZE(CTaskSimpleTriggerEvent, 0xC, 0x18);

DECL_CLASS_BASED(CTaskSimpleSetCharDecisionMaker, CTaskSimple)
    // Construct/Deconstruct functions
    DECL_THISCALL_SIMPLE(Delete, _ZN31CTaskSimpleSetCharDecisionMakerD0Ev, void);
    DECL_NEWCALL(CTaskSimpleSetCharDecisionMaker, BYBIT(_ZN5CTasknwEj, _ZN5CTasknwEm));

    // Member values
    int m_iDM;
DECL_CLASS_END()
CHECKSIZE(CTaskSimpleSetCharDecisionMaker, 0xC, 0x18);

DECL_CLASS_BASED(CTaskSimpleIKChain, CTaskSimple)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CTaskSimpleIKChain, _ZN18CTaskSimpleIKChainC2EPci5RwV3diP7CEntityiS1_fii, char* arg2, i32 arg3, RwV3d arg4, i32 arg5, CEntity* arg6, i32 arg7, RwV3d arg8, float arg9, i32 arg10, i32 arg11);
    DECL_DTORCALL_PROXY(CTaskSimpleIKChain, _ZN18CTaskSimpleIKChainD2Ev);
    DECL_NEWCALL(CTaskSimpleIKChain, BYBIT(_ZN5CTasknwEj, _ZN5CTasknwEm));

    // Virtual functions
    virtual u8 CreateIKChain(CPed* arg1);

    // Member functions
    DECL_THISCALL_HEAD(BlendOut, _ZN18CTaskSimpleIKChain8BlendOutEi, void, i32 blendOutTime)
    DECL_THISCALL_TAIL(BlendOut, blendOutTime)
    DECL_THISCALL_SIMPLE(GetIKChain, _ZN18CTaskSimpleIKChain10GetIKChainEv, IKChain_c*);

    // Member values
    i32 m_time;
    i32 m_blendTime;
    IKChain_c* m_pIKChain;
    i16 m_slotID;
    i16 m_pivotBoneTag;
    i16 m_effectorBoneTag;
    RwV3d m_effectorVec;
    CEntity* m_pEntity;
    i32 m_offsetBoneTag;
    RwV3d m_offsetPos;
    float m_speed;
    u8 m_nonNullEntity;
    float m_blend;
    i32 m_endTime;
    float m_targetBlend;
    i32 m_targetTime;
    i32 m_isBlendingOut;
DECL_CLASS_END()
CHECKSIZE(CTaskSimpleIKChain, 0x58, 0x70);

DECL_CLASS_BASED(CTaskSimpleIKLookAt, CTaskSimpleIKChain)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CTaskSimpleIKLookAt, _ZN19CTaskSimpleIKLookAtC2EPcP7CEntityii5RwV3dhfii, char* idString, CEntity* pEntity, i32 time, i32 offsetBoneTag, RwV3d offsetPos, u8 useTorso, float speed, i32 blendTime, i32 priority);
    DECL_DTORCALL_PROXY(CTaskSimpleIKLookAt, _ZN19CTaskSimpleIKLookAtD2Ev);
    DECL_NEWCALL(CTaskSimpleIKLookAt, BYBIT(_ZN5CTasknwEj, _ZN5CTasknwEm));

    // Member functions
    DECL_THISCALL_HEAD(UpdateLookAtInfo, _ZN19CTaskSimpleIKLookAt16UpdateLookAtInfoEPcP4CPedP7CEntityii5RwV3dhfii, void, char* idString, CPed* pPed, CEntity* pEntity, i32 time, i32 offsetBoneTag, RwV3d offsetPos, u8 useTorso, float speed, i32 blendTime, i32 priority)
    DECL_THISCALL_TAIL(UpdateLookAtInfo, idString, pPed, pEntity, time, offsetBoneTag, offsetPos, useTorso, speed, blendTime, priority)
    DECL_THISCALL_SIMPLE(GetLookAtEntity, _ZN19CTaskSimpleIKLookAt15GetLookAtEntityEv, CEntity*);
    DECL_THISCALL_SIMPLE(GetLookAtOffset, _ZN19CTaskSimpleIKLookAt15GetLookAtOffsetEv, CVector);

    // Member values
    u8 m_useTorso;
    i8 m_priority;
DECL_CLASS_END()
CHECKSIZE(CTaskSimpleIKLookAt, 0x5C, 0x70);

DECL_CLASS_BASED(CTaskSimpleIKPointArm, CTaskSimpleIKChain)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CTaskSimpleIKPointArm, _ZN21CTaskSimpleIKPointArmC2EPciP7CEntityi5RwV3dfi, char* idString, i32 armId, CEntity* pEntity, i32 offsetBoneTag, RwV3d offsetPos, float speed, i32 blendTime);
    DECL_DTORCALL_PROXY(CTaskSimpleIKPointArm, _ZN21CTaskSimpleIKPointArmD2Ev);
    DECL_NEWCALL(CTaskSimpleIKPointArm, BYBIT(_ZN5CTasknwEj, _ZN5CTasknwEm));

    // Member functions
    DECL_THISCALL_HEAD(UpdatePointArmInfo, _ZN21CTaskSimpleIKPointArm18UpdatePointArmInfoEPcP7CEntityi5RwV3dfi, void, char* idString, CEntity* pEntity, i32 offsetBoneTag, RwV3d offsetPos, float speed, i32 blendTime)
    DECL_THISCALL_TAIL(UpdatePointArmInfo, idString, pEntity, offsetBoneTag, offsetPos, speed, blendTime)
    DECL_THISCALL_SIMPLE(GetPointAtEntity, _ZN21CTaskSimpleIKPointArm16GetPointAtEntityEv, CEntity*);

    // Member values
    i32 m_armId;
DECL_CLASS_END()
CHECKSIZE(CTaskSimpleIKPointArm, 0x5C, 0x70);

#endif // __AML_PSDK_SATASKTYPES_H
