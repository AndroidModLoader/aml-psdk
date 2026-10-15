#ifndef __AML_PSDK_SAEVENTTYPES_H
#define __AML_PSDK_SAEVENTTYPES_H

#include "EventEditableResponse.h"
#include "../enum/WeaponType.h"
#include "../enum/PedEnums.h"
#include "../enum/AnimGroup.h"
#include "../enum/AnimationId.h"

struct CVehicle;
struct CBuilding;
struct CObject;
struct CTask;
struct C2dEffect;
struct CAnimBlendAssociation;

DECL_CLASS(CPedDamageResponse)
    // Member values
    float m_fHealthLost;
    float m_fArmourLost;
    bool m_bKilled;
    bool m_bInstantKill;
    bool m_bDamageCalculated;
    bool m_bAffectsPed;
DECL_CLASS_END()
CHECKSIZE(CPedDamageResponse, 0xC, 0xC);

DECL_CLASS_BASED(CEventDamage, CEventEditableResponse)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CEventDamage1, _ZN12CEventDamageC2EP7CEntityj11eWeaponType14ePedPieceTypeshbb, CEntity* arg2, u32 const arg3, eWeaponType const arg4, ePedPieceTypes const arg5, u8 const arg6, bool const arg7, bool const arg8);
    DECL_CTORCALL_PROXY(CEventDamage, _ZN12CEventDamageC2ERKS_, CEventDamage const& src);
    DECL_DTORCALL_PROXY(CEventDamage, _ZN12CEventDamageD2Ev);
    DECL_NEWCALL(CEventDamage, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // Member functions
    DECL_THISCALL_NAMED_HEAD(Assign, operator=, _ZN12CEventDamageaSERKS_, CEventDamage&, CEventDamage const& src)
    DECL_THISCALL_TAIL(Assign, src)
    DECL_THISCALL_HEAD(IsSameEventForAI, _ZN12CEventDamage16IsSameEventForAIEPS_, bool, CEventDamage* pEvent)
    DECL_THISCALL_TAIL(IsSameEventForAI, pEvent)
    DECL_THISCALL_HEAD(ComputeDeathAnim, _ZN12CEventDamage16ComputeDeathAnimEP4CPedb, void, CPed* pPed, bool bAtGenerateEventStage)
    DECL_THISCALL_TAIL(ComputeDeathAnim, pPed, bAtGenerateEventStage)
    DECL_THISCALL_HEAD(ComputeDamageAnim, _ZN12CEventDamage17ComputeDamageAnimEP4CPedb, void, CPed* pPed, bool bAtGenerateEventStage)
    DECL_THISCALL_TAIL(ComputeDamageAnim, pPed, bAtGenerateEventStage)
    DECL_THISCALL_HEAD(ComputeHeadShot, _ZNK12CEventDamage15ComputeHeadShotERb, void, bool& bHeadShot)
    DECL_THISCALL_TAIL(ComputeHeadShot, bHeadShot)
    DECL_THISCALL_HEAD(ComputeBodyPartToRemove, _ZNK12CEventDamage23ComputeBodyPartToRemoveERi, void, int& iBodyPartToRemove)
    DECL_THISCALL_TAIL(ComputeBodyPartToRemove, iBodyPartToRemove)
    DECL_THISCALL_HEAD(ProcessDamage, _ZNK12CEventDamage13ProcessDamageEP4CPed, void, CPed* pPed)
    DECL_THISCALL_TAIL(ProcessDamage, pPed)

    // Member values
    CEntity* m_pInflictor;
    u32 m_nDamageTime;
    eWeaponType m_eWeaponUsed;
    ePedPieceTypes m_eHitZone;
    u8 m_iPedHitDir;
    u8 m_bJumpedOutOfMovingCar : 1;
    u8 m_bFallDown : 1;
    u8 m_bAnimAdded : 1;
    u8 m_bWitnessedInVehicle : 1;
    u8 m_bStealthMode : 1;
    AssocGroupId m_nAnimGroup;
    AnimationId m_nAnimId;
    float m_fAnimBlendSpeed;
    float m_fAnimPlaySpeed;
    CPedDamageResponse m_pedDamageResponse;
DECL_CLASS_END()
CHECKSIZE(CEventDamage, 0x40, 0x50);

DECL_CLASS_BASED(CEventGunShot, CEventEditableResponse)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CEventGunShot, _ZN13CEventGunShotC2EP7CEntity7CVectorS2_b, CEntity* pFiringEntity, CVector ShotOrigin, CVector ShotTarget, bool bSilent);
    DECL_DTORCALL_PROXY(CEventGunShot, _ZN13CEventGunShotD2Ev);
    DECL_NEWCALL(CEventGunShot, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // STATIC values
    DECL_VALUE_PLT_FLT(ms_fGunShotSenseRangeForRiot2, BYBIT(0x677348, 0x84C6C8));

    // Member values
    CEntity* m_pFiringEntity;
    CVector m_vShotOrigin;
    CVector m_vShotTarget;
    bool m_bSilent;
DECL_CLASS_END()
CHECKSIZE(CEventGunShot, 0x30, 0x40);

DECL_CLASS_BASED(CEventDeath, CEvent)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CEventDeath, _ZN11CEventDeathC2Eb, bool const bHasDrowned);
    DECL_CTORCALL_PROXY(CEventDeath1, _ZN11CEventDeathC2Ebi, bool const bHasDrowned, int const timeOfDeath);
    DECL_DTORCALL_PROXY(CEventDeath, _ZN11CEventDeathD2Ev);
    DECL_NEWCALL(CEventDeath, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // Member values
    bool m_bHasDrowned;
    int m_iTimeOfDeath;
DECL_CLASS_END()
CHECKSIZE(CEventDeath, 0x10, 0x18);

DECL_CLASS_BASED(CEventOnFire, CEvent)
    // Construct/Deconstruct functions
    DECL_THISCALL_SIMPLE(Delete, _ZN12CEventOnFireD0Ev, void);
    DECL_NEWCALL(CEventOnFire, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));
DECL_CLASS_END()
CHECKSIZE(CEventOnFire, 0xC, 0x10);

DECL_CLASS_BASED(CEventVehicleDamage, CEventEditableResponse)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CEventVehicleDamage, _ZN19CEventVehicleDamageC2EP8CVehicleP7CEntity11eWeaponType, CVehicle* pVehicle, CEntity* pInflictor, eWeaponType const weaponUsed);
    DECL_DTORCALL_PROXY(CEventVehicleDamage, _ZN19CEventVehicleDamageD2Ev);
    DECL_NEWCALL(CEventVehicleDamage, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // Member values
    CVehicle* m_pVehicle;
    CEntity* m_pInflictor;
    eWeaponType m_eWeaponUsed;
DECL_CLASS_END()
CHECKSIZE(CEventVehicleDamage, 0x1C, 0x30);

DECL_CLASS_BASED(CEventGunAimedAt, CEventEditableResponse)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CEventGunAimedAt, _ZN16CEventGunAimedAtC2EP4CPed, CPed* pAggressorPed);
    DECL_DTORCALL_PROXY(CEventGunAimedAt, _ZN16CEventGunAimedAtD2Ev);
    DECL_NEWCALL(CEventGunAimedAt, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // STATIC functions
    DECL_FASTCALL_SIMPLE(AddGunAimedAtEventToVehicleOccupants, _ZN16CEventGunAimedAt36AddGunAimedAtEventToVehicleOccupantsERK8CVehicleP4CPed, void, CVehicle const& vehicle, CPed* pAggressorPed);

    // Member values
    CPed* m_pAggressorPed;
DECL_CLASS_END()
CHECKSIZE(CEventGunAimedAt, 0x14, 0x20);

DECL_CLASS_BASED(CEventScriptCommand, CEvent)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CEventScriptCommand, _ZN19CEventScriptCommandC2EiP5CTaskb, int const iTaskPriority, CTask* pTask, bool const bAcceptWhenDead);
    DECL_DTORCALL_PROXY(CEventScriptCommand, _ZN19CEventScriptCommandD2Ev);
    DECL_NEWCALL(CEventScriptCommand, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // Virtual functions
    virtual CTask* CloneScriptTask() const;

    // Member values
    int m_iTaskPriority;
    CTask* m_pTask;
    bool m_bAcceptWhenDead;
DECL_CLASS_END()
CHECKSIZE(CEventScriptCommand, 0x18, 0x28);

DECL_CLASS_BASED(CEventVehicleOnFire, CEventEditableResponse)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CEventVehicleOnFire, _ZN19CEventVehicleOnFireC2EP8CVehicle, CVehicle* pVehicleOnFire);
    DECL_DTORCALL_PROXY(CEventVehicleOnFire, _ZN19CEventVehicleOnFireD2Ev);
    DECL_NEWCALL(CEventVehicleOnFire, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // Member values
    CVehicle* m_pVehicleOnFire;
DECL_CLASS_END()
CHECKSIZE(CEventVehicleOnFire, 0x14, 0x20);

DECL_CLASS_BASED(CEventVehicleDied, CEvent)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CEventVehicleDied, _ZN17CEventVehicleDiedC2EP8CVehicle, CVehicle* pDeadVehicle);
    DECL_DTORCALL_PROXY(CEventVehicleDied, _ZN17CEventVehicleDiedD2Ev);
    DECL_NEWCALL(CEventVehicleDied, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // Member values
    CVehicle* m_pDeadVehicle;
    bool m_bLeavingVehicle;
DECL_CLASS_END()
CHECKSIZE(CEventVehicleDied, 0x14, 0x20);

DECL_CLASS_BASED(CEventDeadPed, CEventEditableResponse)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CEventDeadPed, _ZN13CEventDeadPedC2EP4CPedbi, CPed* pDeadPed, bool const bHasDrowned, int const iTimeOfDeath);
    DECL_DTORCALL_PROXY(CEventDeadPed, _ZN13CEventDeadPedD2Ev);
    DECL_NEWCALL(CEventDeadPed, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // Member values
    CPed* m_pDeadPed;
    bool m_bHasDrowned;
    int m_iTimeOfDeath;
DECL_CLASS_END()
CHECKSIZE(CEventDeadPed, 0x1C, 0x28);

DECL_CLASS_BASED(CEventDanger, CEventEditableResponse)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CEventDanger, _ZN12CEventDangerC2EP7CEntityf, CEntity* pDangerousEntity, float dangerRadius);
    DECL_DTORCALL_PROXY(CEventDanger, _ZN12CEventDangerD2Ev);
    DECL_NEWCALL(CEventDanger, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // Member values
    CEntity* m_pDangerousEntity;
    float m_dangerRadius;
DECL_CLASS_END()
CHECKSIZE(CEventDanger, 0x18, 0x28);

DECL_CLASS_BASED(CEventPedToFlee, CEvent)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CEventPedToFlee, _ZN15CEventPedToFleeC2EP4CPed, CPed* pPedToFlee);
    DECL_DTORCALL_PROXY(CEventPedToFlee, _ZN15CEventPedToFleeD2Ev);
    DECL_NEWCALL(CEventPedToFlee, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // Member values
    CPed* m_pPedToFlee;
DECL_CLASS_END()
CHECKSIZE(CEventPedToFlee, 0x10, 0x18);

DECL_CLASS_BASED(CEventVehicleThreat, CEventEditableResponse)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CEventVehicleThreat, _ZN19CEventVehicleThreatC2EP8CVehicle, CVehicle* pThreatVehicle);
    DECL_DTORCALL_PROXY(CEventVehicleThreat, _ZN19CEventVehicleThreatD2Ev);
    DECL_NEWCALL(CEventVehicleThreat, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // Member values
    CVehicle* m_pThreatVehicle;
DECL_CLASS_END()
CHECKSIZE(CEventVehicleThreat, 0x14, 0x20);

DECL_CLASS_BASED(CEventPotentialGetRunOver, CEventEditableResponse)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CEventPotentialGetRunOver, _ZN25CEventPotentialGetRunOverC2EP8CVehicle, CVehicle* pThreatVehicle);
    DECL_DTORCALL_PROXY(CEventPotentialGetRunOver, _ZN25CEventPotentialGetRunOverD2Ev);
    DECL_NEWCALL(CEventPotentialGetRunOver, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // Member values
    CVehicle* m_pThreatVehicle;
DECL_CLASS_END()
CHECKSIZE(CEventPotentialGetRunOver, 0x14, 0x20);

DECL_CLASS_BASED(CEventPedCollisionWithPed, CEvent)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CEventPedCollisionWithPed, _ZN25CEventPedCollisionWithPedC2EtfPK4CPedRK7CVectorS5_ii, u16 const nPieceType, float const fImpulseMagnitude, CPed const* pPed, CVector const& vNormal, CVector const& vPos, int const iPedMoveState, int const iOtherPedMoveState);
    DECL_DTORCALL_PROXY(CEventPedCollisionWithPed, _ZN25CEventPedCollisionWithPedD2Ev);
    DECL_NEWCALL(CEventPedCollisionWithPed, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // STATIC values
    DECL_OBJECT_PLT(float const, ms_fPedBrushKnockdown, BYBIT(0x677FD8, 0x84DFD0));

    // Member values
    u16 m_iPieceType;
    float m_fImpulseMagnitude;
    CPed* m_pOtherPed;
    CVector m_vNormal;
    CVector m_vPos;
    i16 m_iPedMoveState;
    i16 m_iOtherPedMoveState;
DECL_CLASS_END()
CHECKSIZE(CEventPedCollisionWithPed, 0x30, 0x40);

DECL_CLASS_BASED(CEventBuildingCollision, CEvent)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CEventBuildingCollision, _ZN23CEventBuildingCollisionC2EtfPK9CBuildingRK7CVectorS5_i, u16 const nPieceType, float const fImpulseMagnitude, CBuilding const* pBuilding, CVector const& vNormal, CVector const& vPos, int const iMoveState);
    DECL_DTORCALL_PROXY(CEventBuildingCollision, _ZN23CEventBuildingCollisionD2Ev);
    DECL_NEWCALL(CEventBuildingCollision, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // STATIC functions
    DECL_FASTCALL_SIMPLE(CanTreatBuildingAsObject, _ZN23CEventBuildingCollision24CanTreatBuildingAsObjectERK9CBuilding, bool, CBuilding const& building);

    // Member functions
    DECL_THISCALL_HEAD(IsHeadOnCollision, _ZNK23CEventBuildingCollision17IsHeadOnCollisionERK4CPed, bool, CPed const& ped)
    DECL_THISCALL_TAIL(IsHeadOnCollision, ped)

    // Member values
    u16 m_iPieceType;
    i16 m_iMoveState;
    float m_fImpulseMagnitude;
    CBuilding* m_pBuilding;
    CVector m_vNormal;
    CVector m_vPos;
DECL_CLASS_END()
CHECKSIZE(CEventBuildingCollision, 0x30, 0x38);

DECL_CLASS_BASED(CEventObjectCollision, CEvent)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CEventObjectCollision, _ZN21CEventObjectCollisionC2EtfPK7CObjectRK7CVectorS5_i, u16 const nPieceType, float const fImpulseMagnitude, CObject const* pObject, CVector const& vNormal, CVector const& vPos, int const iMoveState);
    DECL_DTORCALL_PROXY(CEventObjectCollision, _ZN21CEventObjectCollisionD2Ev);
    DECL_NEWCALL(CEventObjectCollision, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // Member functions
    DECL_THISCALL_HEAD(IsHeadOnCollision, _ZNK21CEventObjectCollision17IsHeadOnCollisionERK4CPed, bool, CPed const& ped)
    DECL_THISCALL_TAIL(IsHeadOnCollision, ped)

    // Member values
    u16 m_iPieceType;
    i16 m_iMoveState;
    float m_fImpulseMagnitude;
    CObject* m_pObject;
    CVector m_vNormal;
    CVector m_vPos;
DECL_CLASS_END()
CHECKSIZE(CEventObjectCollision, 0x30, 0x38);

DECL_CLASS_BASED(CEventAcquaintancePed, CEventEditableResponse)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CEventAcquaintancePed, _ZN21CEventAcquaintancePedC2EP4CPed, CPed* pAcquaintancePed);
    DECL_DTORCALL_PROXY(CEventAcquaintancePed, _ZN21CEventAcquaintancePedD2Ev);
    DECL_NEWCALL(CEventAcquaintancePed, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // Member values
    CPed* m_pAcquaintancePed;
DECL_CLASS_END()
CHECKSIZE(CEventAcquaintancePed, 0x14, 0x20);

DECL_CLASS_BASED(CEventAcquaintancePedHate, CEventAcquaintancePed)
    // Construct/Deconstruct functions
    DECL_THISCALL_SIMPLE(Delete, _ZN25CEventAcquaintancePedHateD0Ev, void);
    DECL_NEWCALL(CEventAcquaintancePedHate, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));
DECL_CLASS_END()
CHECKSIZE(CEventAcquaintancePedHate, 0x14, 0x20);

DECL_CLASS_BASED(CEventPlayerCommandToGroup, CEventEditableResponse)
    enum
    {
        GROUP_COMMAND_ATTACK = 0,
        GROUP_COMMAND_RETREAT = 1,
        GROUP_COMMAND_GATHER = 2,
    };

    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CEventPlayerCommandToGroup, _ZN26CEventPlayerCommandToGroupC2EiP4CPed, int const iType, CPed* pPed);
    DECL_DTORCALL_PROXY(CEventPlayerCommandToGroup, _ZN26CEventPlayerCommandToGroupD2Ev);
    DECL_NEWCALL(CEventPlayerCommandToGroup, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // Member values
    int m_iType;
    CPed* m_pPed;
DECL_CLASS_END()
CHECKSIZE(CEventPlayerCommandToGroup, 0x18, 0x20);

DECL_CLASS_BASED(CEventPlayerCommandToGroupAttack, CEventPlayerCommandToGroup)
    // Construct/Deconstruct functions
    DECL_THISCALL_SIMPLE(Delete, _ZN32CEventPlayerCommandToGroupAttackD0Ev, void);
    DECL_NEWCALL(CEventPlayerCommandToGroupAttack, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));
DECL_CLASS_END()
CHECKSIZE(CEventPlayerCommandToGroupAttack, 0x18, 0x20);

DECL_CLASS_BASED(CEventDraggedOutCar, CEventEditableResponse)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CEventDraggedOutCar, _ZN19CEventDraggedOutCarC2EPK8CVehiclePK4CPedb, CVehicle const* pVehicle, CPed const* pDraggingPed, bool const bIsDriver);
    DECL_DTORCALL_PROXY(CEventDraggedOutCar, _ZN19CEventDraggedOutCarD2Ev);
    DECL_NEWCALL(CEventDraggedOutCar, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // Member values
    CPed* m_pDraggingPed;
    CVehicle* m_pVehicle;
    bool m_bWasDriver;
DECL_CLASS_END()
CHECKSIZE(CEventDraggedOutCar, 0x1C, 0x30);

DECL_CLASS_BASED(CEventGotKnockedOverByCar, CEventEditableResponse)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CEventGotKnockedOverByCar, _ZN25CEventGotKnockedOverByCarC2EP8CVehicle, CVehicle* pVehicle);
    DECL_DTORCALL_PROXY(CEventGotKnockedOverByCar, _ZN25CEventGotKnockedOverByCarD2Ev);
    DECL_NEWCALL(CEventGotKnockedOverByCar, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // Member values
    CVehicle* m_pVehicle;
DECL_CLASS_END()
CHECKSIZE(CEventGotKnockedOverByCar, 0x14, 0x20);

DECL_CLASS_BASED(CEventKnockOffBike, CEvent)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CEventKnockOffBike2, _ZN18CEventKnockOffBikeC2EP8CVehicleRK7CVectorS4_ff11eWeaponTypeaiP4CPedbb, CVehicle* arg2, CVector const& arg3, CVector const& arg4, float arg5, float arg6, eWeaponType arg7, i8 arg8, int const arg9, CPed* arg10, bool const arg11, bool const arg12);
    DECL_CTORCALL_PROXY(CEventKnockOffBike, _ZN18CEventKnockOffBikeC2Ev);
    DECL_CTORCALL_PROXY(CEventKnockOffBike1, _ZN18CEventKnockOffBikeC2ERKS_, CEventKnockOffBike const& src);
    DECL_DTORCALL_PROXY(CEventKnockOffBike, _ZN18CEventKnockOffBikeD2Ev);
    DECL_NEWCALL(CEventKnockOffBike, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // Member functions
    DECL_THISCALL_NAMED_HEAD(Assign, operator=, _ZN18CEventKnockOffBikeaSERKS_, CEventKnockOffBike&, CEventKnockOffBike const& src)
    DECL_THISCALL_TAIL(Assign, src)
    DECL_THISCALL_HEAD(SetPedOutCar, _ZN18CEventKnockOffBike12SetPedOutCarEP4CPed, void, CPed* pPed)
    DECL_THISCALL_TAIL(SetPedOutCar, pPed)
    DECL_THISCALL_HEAD(CalcForcesAndAnims, _ZN18CEventKnockOffBike18CalcForcesAndAnimsEP4CPed, AnimationId, CPed* pPed)
    DECL_THISCALL_TAIL(CalcForcesAndAnims, pPed)
    DECL_THISCALL_HEAD(SetPedSafePosition, _ZN18CEventKnockOffBike18SetPedSafePositionEP4CPed, bool, CPed* pPed)
    DECL_THISCALL_TAIL(SetPedSafePosition, pPed)

    // Member values
    CVector m_vecColSpeed;
    CVector m_vecColNormal;
    float m_fCollisionImpulse;
    float m_fPedDamage;
    int m_nDownTime;
    CPed* m_pDraggingPed;
    i8 m_nDirn;
    u8 m_bWasDriver : 1;
    u8 m_bForce : 1;
    i8 m_eWeaponUsed;
    i8 m_nExitDoor;
    CVehicle* m_pVehicle;
DECL_CLASS_END()
CHECKSIZE(CEventKnockOffBike, 0x3C, 0x50);

DECL_CLASS_BASED(CEventAttractor, CEventEditableResponse)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CEventAttractor, _ZN15CEventAttractorC2EP9C2dEffectP7CEntityh, C2dEffect* pEffect, CEntity* pEntity, u8 forceUse);
    DECL_DTORCALL_PROXY(CEventAttractor, _ZN15CEventAttractorD2Ev);
    DECL_NEWCALL(CEventAttractor, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // STATIC functions
    DECL_FASTCALL_SIMPLE(IsEffectActive, _ZN15CEventAttractor14IsEffectActiveEPK7CEntityPK9C2dEffect, bool, CEntity const* pEntity, C2dEffect const* pEffect);

    // Member values
    C2dEffect* m_pEffect;
    CEntity* m_pEntity;
    u8 m_forceUse;
DECL_CLASS_END()
CHECKSIZE(CEventAttractor, 0x1C, 0x30);

DECL_CLASS_BASED(CEventSoundLoud, CEventEditableResponse)
    DECL_NEWCALL(CEventSoundLoud, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // Member values
    CEntity* m_pEntityMakingSound;
    float m_Volume;
DECL_CLASS_END()
CHECKSIZE(CEventSoundLoud, 0x18, 0x28);

DECL_CLASS_BASED(CEventSoundQuiet, CEventEditableResponse)
    // Construct/Deconstruct functions
    DECL_DTORCALL_PROXY(CEventSoundQuiet, _ZN16CEventSoundQuietD2Ev);
    DECL_NEWCALL(CEventSoundQuiet, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // Member values
    CEntity* m_pEntityMakingSound;
    float m_Volume;
    int m_iTimeHeard;
    CVector m_vTargetPosAtHeardTime;
DECL_CLASS_END()
CHECKSIZE(CEventSoundQuiet, 0x28, 0x38);

DECL_CLASS_BASED(CEventVehicleHitAndRun, CEvent)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CEventVehicleHitAndRun, _ZN22CEventVehicleHitAndRunC2EP4CPedP8CVehicle, CPed* pKnockedDownPed, CVehicle* pInflictor);
    DECL_DTORCALL_PROXY(CEventVehicleHitAndRun, _ZN22CEventVehicleHitAndRunD2Ev);
    DECL_NEWCALL(CEventVehicleHitAndRun, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // Member values
    CPed* m_pKnockedDownPed;
    CVehicle* m_pInflictor;
DECL_CLASS_END()
CHECKSIZE(CEventVehicleHitAndRun, 0x14, 0x20);

DECL_CLASS_BASED(CEventGroupEvent, CEvent)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CEventGroupEvent, _ZN16CEventGroupEventC2EP4CPedP6CEvent, CPed* pDistressedPed, CEvent* pEvent);
    DECL_DTORCALL_PROXY(CEventGroupEvent, _ZN16CEventGroupEventD2Ev);
    DECL_NEWCALL(CEventGroupEvent, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // Member functions
    DECL_THISCALL_HEAD(BaseEventTakesPriorityOverBaseEvent, _ZNK16CEventGroupEvent35BaseEventTakesPriorityOverBaseEventERKS_, bool, CEventGroupEvent const& other)
    DECL_THISCALL_TAIL(BaseEventTakesPriorityOverBaseEvent, other)

    // Member values
    CPed* m_pDistressedPed;
    CEvent* m_pEvent;
DECL_CLASS_END()
CHECKSIZE(CEventGroupEvent, 0x14, 0x20);

struct InteriorInfo_t;
struct Interior_c;
struct CEntryExit;

DECL_CLASS_BASED(CEventLeaderEnteredCarAsDriver, CEventEditableResponse)
    // Construct/Deconstruct functions
    DECL_DTORCALL_PROXY(CEventLeaderEnteredCarAsDriver, _ZN30CEventLeaderEnteredCarAsDriverD2Ev);
    DECL_NEWCALL(CEventLeaderEnteredCarAsDriver, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // Member values
    CVehicle* m_pVehicle;
DECL_CLASS_END()
CHECKSIZE(CEventLeaderEnteredCarAsDriver, 0x14, 0x20);

DECL_CLASS_BASED(CEventStuckInAir, CEvent)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CEventStuckInAir, _ZN16CEventStuckInAirC2EP4CPed, CPed* pPed);
    DECL_DTORCALL_PROXY(CEventStuckInAir, _ZN16CEventStuckInAirD2Ev);
    DECL_NEWCALL(CEventStuckInAir, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // Member values
    CPed* m_pPed;
DECL_CLASS_END()
CHECKSIZE(CEventStuckInAir, 0x10, 0x18);

DECL_CLASS_BASED(CEventPotentialWalkIntoFire, CEventEditableResponse)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CEventPotentialWalkIntoFire, _ZN27CEventPotentialWalkIntoFireC2ERK7CVectorfi, CVector const& vFirePos, float const fStrength, int const iMoveState);
    DECL_DTORCALL_PROXY(CEventPotentialWalkIntoFire, _ZN27CEventPotentialWalkIntoFireD2Ev);
    DECL_NEWCALL(CEventPotentialWalkIntoFire, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // Member values
    CVector m_vFirePos;
    float m_fStrength;
    float m_fFireRadius;
    int m_iMoveState;
DECL_CLASS_END()
CHECKSIZE(CEventPotentialWalkIntoFire, 0x28, 0x30);

DECL_CLASS_BASED(CEventLeaderExitedCarAsDriver, CEventEditableResponse)
    // Construct/Deconstruct functions
    DECL_THISCALL_SIMPLE(Delete, _ZN29CEventLeaderExitedCarAsDriverD0Ev, void);
    DECL_NEWCALL(CEventLeaderExitedCarAsDriver, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));
DECL_CLASS_END()
CHECKSIZE(CEventLeaderExitedCarAsDriver, 0x10, 0x18);

DECL_CLASS_BASED(CEventCopCarBeingStolen, CEvent)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CEventCopCarBeingStolen, _ZN23CEventCopCarBeingStolenC2EP4CPedP8CVehicle, CPed* pCriminal, CVehicle* pTargetVehicle);
    DECL_DTORCALL_PROXY(CEventCopCarBeingStolen, _ZN23CEventCopCarBeingStolenD2Ev);
    DECL_NEWCALL(CEventCopCarBeingStolen, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // Member values
    CPed* m_pCriminal;
    CVehicle* m_pTargetVehicle;
DECL_CLASS_END()
CHECKSIZE(CEventCopCarBeingStolen, 0x14, 0x20);

DECL_CLASS_BASED(CEventVehicleToSteal, CEvent)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CEventVehicleToSteal, _ZN20CEventVehicleToStealC2EP8CVehicle, CVehicle* pVehicle);
    DECL_DTORCALL_PROXY(CEventVehicleToSteal, _ZN20CEventVehicleToStealD2Ev);
    DECL_NEWCALL(CEventVehicleToSteal, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // Member values
    CVehicle* m_pVehicle;
DECL_CLASS_END()
CHECKSIZE(CEventVehicleToSteal, 0x10, 0x18);

DECL_CLASS_BASED(CEventHealthReallyLow, CEventEditableResponse)
    // Construct/Deconstruct functions
    DECL_THISCALL_SIMPLE(Delete, _ZN21CEventHealthReallyLowD0Ev, void);
    DECL_NEWCALL(CEventHealthReallyLow, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));
DECL_CLASS_END()
CHECKSIZE(CEventHealthReallyLow, 0x10, 0x18);

DECL_CLASS_BASED(CEventRevived, CEvent)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CEventRevived, _ZN13CEventRevivedC2Ev);
    DECL_DTORCALL_PROXY(CEventRevived, _ZN13CEventRevivedD2Ev);
    DECL_NEWCALL(CEventRevived, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));
DECL_CLASS_END()
CHECKSIZE(CEventRevived, 0xC, 0x10);

DECL_CLASS_BASED(CEventSexyPed, CEventEditableResponse)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CEventSexyPed, _ZN13CEventSexyPedC2EP4CPed, CPed* pSexyPed);
    DECL_DTORCALL_PROXY(CEventSexyPed, _ZN13CEventSexyPedD2Ev);
    DECL_NEWCALL(CEventSexyPed, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // Member values
    CPed* m_pSexyPed;
DECL_CLASS_END()
CHECKSIZE(CEventSexyPed, 0x14, 0x20);

DECL_CLASS_BASED(CEventLowAngerAtPlayer, CEventEditableResponse)
    // Construct/Deconstruct functions
    DECL_THISCALL_SIMPLE(Delete, _ZN22CEventLowAngerAtPlayerD0Ev, void);
    DECL_NEWCALL(CEventLowAngerAtPlayer, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));
DECL_CLASS_END()
CHECKSIZE(CEventLowAngerAtPlayer, 0x10, 0x18);

DECL_CLASS_BASED(CEventPotentialWalkIntoBuilding, CEventBuildingCollision)
    // Construct/Deconstruct functions
    DECL_NEWCALL(CEventPotentialWalkIntoBuilding, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));
DECL_CLASS_END()
CHECKSIZE(CEventPotentialWalkIntoBuilding, 0x30, 0x38);

DECL_CLASS_BASED(CEventSeenCop, CEventAcquaintancePed)
    // Construct/Deconstruct functions
    DECL_THISCALL_SIMPLE(Delete, _ZN13CEventSeenCopD0Ev, void);
    DECL_NEWCALL(CEventSeenCop, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));
DECL_CLASS_END()
CHECKSIZE(CEventSeenCop, 0x14, 0x20);

DECL_CLASS_BASED(CEventLeaderQuitEnteringCarAsDriver, CEvent)
    // Construct/Deconstruct functions
    DECL_THISCALL_SIMPLE(Delete, _ZN35CEventLeaderQuitEnteringCarAsDriverD0Ev, void);
    DECL_NEWCALL(CEventLeaderQuitEnteringCarAsDriver, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));
DECL_CLASS_END()
CHECKSIZE(CEventLeaderQuitEnteringCarAsDriver, 0xC, 0x10);

DECL_CLASS_BASED(CEventAreaCodes, CEvent)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CEventAreaCodes, _ZN15CEventAreaCodesC2EP4CPed, CPed* pTargetPed);
    DECL_DTORCALL_PROXY(CEventAreaCodes, _ZN15CEventAreaCodesD2Ev);
    DECL_NEWCALL(CEventAreaCodes, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // Member values
    CPed* m_pTargetPed;
DECL_CLASS_END()
CHECKSIZE(CEventAreaCodes, 0x10, 0x18);

DECL_CLASS_BASED(CEventGunShotWhizzedBy, CEventGunShot)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CEventGunShotWhizzedBy, _ZN22CEventGunShotWhizzedByC2EP7CEntityRK7CVectorS4_b, CEntity* pFiringEntity, CVector const& vShotOrigin, CVector const& vShotTarget, bool const bIsSilent);
    DECL_DTORCALL_PROXY(CEventGunShotWhizzedBy, _ZN22CEventGunShotWhizzedByD2Ev);
    DECL_NEWCALL(CEventGunShotWhizzedBy, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // STATIC values
    DECL_OBJECT_PLT(float, ms_fThresholdDist, BYBIT(0x677230, 0x84C498));
DECL_CLASS_END()
CHECKSIZE(CEventGunShotWhizzedBy, 0x30, 0x40);

DECL_CLASS_BASED(CEventLeaderEntryExit, CEventAreaCodes)
    // Construct/Deconstruct functions
    DECL_THISCALL_SIMPLE(Delete, _ZN21CEventLeaderEntryExitD0Ev, void);
    DECL_NEWCALL(CEventLeaderEntryExit, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));
DECL_CLASS_END()
CHECKSIZE(CEventLeaderEntryExit, 0x10, 0x18);

DECL_CLASS_BASED(CEventSignalAtPed, CEvent)
    // Construct/Deconstruct functions
    DECL_NEWCALL(CEventSignalAtPed, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // Member values
    CPed* m_pPed;
    i32 m_initialPause;
    u8 m_playAnimAtEnd;
DECL_CLASS_END()
CHECKSIZE(CEventSignalAtPed, 0x18, 0x20);

DECL_CLASS_BASED(CEventEscalator, CEvent)
    // Construct/Deconstruct functions
    DECL_THISCALL_SIMPLE(Delete, _ZN15CEventEscalatorD0Ev, void);
    DECL_NEWCALL(CEventEscalator, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));
DECL_CLASS_END()
CHECKSIZE(CEventEscalator, 0xC, 0x10);

DECL_CLASS_BASED(CEventPotentialWalkIntoVehicle, CEventEditableResponse)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CEventPotentialWalkIntoVehicle, _ZN30CEventPotentialWalkIntoVehicleC2EP8CVehiclei, CVehicle* pThreatVehicle, int const iMoveState);
    DECL_DTORCALL_PROXY(CEventPotentialWalkIntoVehicle, _ZN30CEventPotentialWalkIntoVehicleD2Ev);
    DECL_NEWCALL(CEventPotentialWalkIntoVehicle, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // Member values
    CVehicle* m_pThreatVehicle;
    int m_iMoveState;
DECL_CLASS_END()
CHECKSIZE(CEventPotentialWalkIntoVehicle, 0x18, 0x28);

DECL_CLASS_BASED(CEventSpecial, CEventEditableResponse)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CEventSpecial, _ZN13CEventSpecialC2Ev);
    DECL_DTORCALL_PROXY(CEventSpecial, _ZN13CEventSpecialD2Ev);
    DECL_NEWCALL(CEventSpecial, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));
DECL_CLASS_END()
CHECKSIZE(CEventSpecial, 0x10, 0x18);

DECL_CLASS_BASED(CEventPotentialWalkIntoObject, CEventEditableResponse)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CEventPotentialWalkIntoObject, _ZN29CEventPotentialWalkIntoObjectC2EP7CObjecti, CObject* pObject, int const iMoveState);
    DECL_DTORCALL_PROXY(CEventPotentialWalkIntoObject, _ZN29CEventPotentialWalkIntoObjectD2Ev);
    DECL_NEWCALL(CEventPotentialWalkIntoObject, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // Member values
    CObject* m_pObject;
    int m_iMoveState;
DECL_CLASS_END()
CHECKSIZE(CEventPotentialWalkIntoObject, 0x18, 0x28);

DECL_CLASS_BASED(CEventPedEnteredMyVehicle, CEventEditableResponse)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CEventPedEnteredMyVehicle, _ZN25CEventPedEnteredMyVehicleC2EPK4CPedPK8CVehiclei, CPed const* pPedThatEnteredVehicle, CVehicle const* pVehicle, int const iTargetDoor);
    DECL_DTORCALL_PROXY(CEventPedEnteredMyVehicle, _ZN25CEventPedEnteredMyVehicleD2Ev);
    DECL_NEWCALL(CEventPedEnteredMyVehicle, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // Member values
    CPed* m_pPedThatEnteredVehicle;
    CVehicle* m_pVehicle;
    int m_iTargetDoor;
DECL_CLASS_END()
CHECKSIZE(CEventPedEnteredMyVehicle, 0x1C, 0x30);

DECL_CLASS_BASED(CEventLeanOnVehicle, CEvent)
    // Construct/Deconstruct functions
    DECL_DTORCALL_PROXY(CEventLeanOnVehicle, _ZN19CEventLeanOnVehicleD2Ev);
    DECL_NEWCALL(CEventLeanOnVehicle, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // Member values
    CVehicle* m_pVehicle;
    i32 m_time;
DECL_CLASS_END()
CHECKSIZE(CEventLeanOnVehicle, 0x14, 0x20);

DECL_CLASS_BASED(CEventHighAngerAtPlayer, CEventEditableResponse)
    // Construct/Deconstruct functions
    DECL_THISCALL_SIMPLE(Delete, _ZN23CEventHighAngerAtPlayerD0Ev, void);
    DECL_NEWCALL(CEventHighAngerAtPlayer, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));
DECL_CLASS_END()
CHECKSIZE(CEventHighAngerAtPlayer, 0x10, 0x18);

DECL_CLASS_BASED(CEventHitByWaterCannon, CEvent)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CEventHitByWaterCannon, _ZN22CEventHitByWaterCannonC2ERK7CVectorS2_, CVector const& vPos, CVector const& vVel);
    DECL_DTORCALL_PROXY(CEventHitByWaterCannon, _ZN22CEventHitByWaterCannonD2Ev);
    DECL_NEWCALL(CEventHitByWaterCannon, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // Member values
    CVector m_vPos;
    CVector m_vVel;
DECL_CLASS_END()
CHECKSIZE(CEventHitByWaterCannon, 0x24, 0x28);

DECL_CLASS_BASED(CEventHealthLow, CEventEditableResponse)
    // Construct/Deconstruct functions
    DECL_THISCALL_SIMPLE(Delete, _ZN15CEventHealthLowD0Ev, void);
    DECL_NEWCALL(CEventHealthLow, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));
DECL_CLASS_END()
CHECKSIZE(CEventHealthLow, 0x10, 0x18);

DECL_CLASS_BASED(CEventCarUpsideDown, CEvent)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CEventCarUpsideDown, _ZN19CEventCarUpsideDownC2EP8CVehicle, CVehicle* pVehicle);
    DECL_DTORCALL_PROXY(CEventCarUpsideDown, _ZN19CEventCarUpsideDownD2Ev);
    DECL_NEWCALL(CEventCarUpsideDown, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // Member values
    CVehicle* m_pVehicle;
DECL_CLASS_END()
CHECKSIZE(CEventCarUpsideDown, 0x10, 0x18);

DECL_CLASS_BASED(CEventChatPartner, CEvent)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CEventChatPartner, _ZN17CEventChatPartnerC2EbP4CPed, bool const bIsLeader, CPed* pOtherPed);
    DECL_DTORCALL_PROXY(CEventChatPartner, _ZN17CEventChatPartnerD2Ev);
    DECL_NEWCALL(CEventChatPartner, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // Member values
    bool m_bIsLeader;
    CPed* m_pOtherPed;
DECL_CLASS_END()
CHECKSIZE(CEventChatPartner, 0x10, 0x18);

DECL_CLASS_BASED(CEventSexyVehicle, CEvent)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CEventSexyVehicle, _ZN17CEventSexyVehicleC2EP8CVehicle, CVehicle* pSexyVehicle);
    DECL_DTORCALL_PROXY(CEventSexyVehicle, _ZN17CEventSexyVehicleD2Ev);
    DECL_NEWCALL(CEventSexyVehicle, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // Member values
    CVehicle* m_pSexyVehicle;
DECL_CLASS_END()
CHECKSIZE(CEventSexyVehicle, 0x10, 0x18);

DECL_CLASS_BASED(CEventPassObject, CEvent)
    // Construct/Deconstruct functions
    DECL_DTORCALL_PROXY(CEventPassObject, _ZN16CEventPassObjectD2Ev);
    DECL_NEWCALL(CEventPassObject, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // Member values
    CPed* m_pPed;
    u8 m_isPasser;
DECL_CLASS_END()
CHECKSIZE(CEventPassObject, 0x14, 0x20);

DECL_CLASS_BASED(CEventPotentialWalkIntoPed, CEventEditableResponse)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CEventPotentialWalkIntoPed, _ZN26CEventPotentialWalkIntoPedC2EP4CPedRK7CVectori, CPed* pOtherPed, CVector const& vTarget, int const iMoveState);
    DECL_DTORCALL_PROXY(CEventPotentialWalkIntoPed, _ZN26CEventPotentialWalkIntoPedD2Ev);
    DECL_NEWCALL(CEventPotentialWalkIntoPed, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // Member values
    CVector m_vTarget;
    CPed* m_pOtherPed;
    int m_iMoveState;
DECL_CLASS_END()
CHECKSIZE(CEventPotentialWalkIntoPed, 0x24, 0x30);

DECL_CLASS_BASED(CEventFireNearby, CEventEditableResponse)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CEventFireNearby, _ZN16CEventFireNearbyC2ERK7CVector, CVector const& vFirePos);
    DECL_DTORCALL_PROXY(CEventFireNearby, _ZN16CEventFireNearbyD2Ev);
    DECL_NEWCALL(CEventFireNearby, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // Member values
    CVector m_vFirePos;
DECL_CLASS_END()
CHECKSIZE(CEventFireNearby, 0x1C, 0x20);

DECL_CLASS_BASED(CEventInteriorUseInfo, CEvent)
    // Construct/Deconstruct functions
    DECL_THISCALL_SIMPLE(Delete, _ZN21CEventInteriorUseInfoD0Ev, void);
    DECL_NEWCALL(CEventInteriorUseInfo, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // Member values
    InteriorInfo_t* m_pInteriorInfo;
    Interior_c* m_pInterior;
    i32 m_duration;
    u8 m_doInstantly;
DECL_CLASS_END()
CHECKSIZE(CEventInteriorUseInfo, 0x1C, 0x28);

DECL_CLASS_BASED(CEventAcquaintancePedHateBadlyLit, CEventAcquaintancePed)
    // Construct/Deconstruct functions
    DECL_THISCALL_SIMPLE(Delete, _ZN33CEventAcquaintancePedHateBadlyLitD0Ev, void);
    DECL_NEWCALL(CEventAcquaintancePedHateBadlyLit, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // Member values
    int m_iTimeSpotted;
    CVector m_vTargetPosAtSpotTime;
DECL_CLASS_END()
CHECKSIZE(CEventAcquaintancePedHateBadlyLit, 0x24, 0x30);

DECL_CLASS_BASED(CEventSeenPanickedPed, CEventEditableResponse)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CEventSeenPanickedPed, _ZN21CEventSeenPanickedPedC2EP4CPed, CPed* pPanickedPed);
    DECL_DTORCALL_PROXY(CEventSeenPanickedPed, _ZN21CEventSeenPanickedPedD2Ev);
    DECL_NEWCALL(CEventSeenPanickedPed, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // Member values
    CPed* m_pPanickedPed;
DECL_CLASS_END()
CHECKSIZE(CEventSeenPanickedPed, 0x14, 0x20);

DECL_CLASS_BASED(CEventPedToChase, CEvent)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CEventPedToChase, _ZN16CEventPedToChaseC2EP4CPed, CPed* pPedToChase);
    DECL_DTORCALL_PROXY(CEventPedToChase, _ZN16CEventPedToChaseD2Ev);
    DECL_NEWCALL(CEventPedToChase, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // Member values
    CPed* m_pPedToChase;
DECL_CLASS_END()
CHECKSIZE(CEventPedToChase, 0x10, 0x18);

DECL_CLASS_BASED(CEventVehicleCollision, CEvent)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CEventVehicleCollision, _ZN22CEventVehicleCollisionC2EtfPK8CVehicleRK7CVectorS5_it, u16 const nPieceType, float const fImpulseMagnitude, CVehicle const* pVehicle, CVector const& vNormal, CVector const& vPos, int const iMoveState, u16 nForceReaction);
    DECL_DTORCALL_PROXY(CEventVehicleCollision, _ZN22CEventVehicleCollisionD2Ev);
    DECL_NEWCALL(CEventVehicleCollision, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // STATIC values
    DECL_OBJECT_PLT(float const, ms_fDamageThresholdSpeed, BYBIT(0x6766B0, 0x84ADB8));
    DECL_OBJECT_PLT(float const, ms_fMaxPlayerImpulse, BYBIT(0x677E74, 0x84DD08));

    // Member values
    u16 m_iPieceType;
    u16 m_nForceReaction;
    float m_fImpulseMagnitude;
    CVehicle* m_pVehicle;
    CVector m_vNormal;
    CVector m_vPos;
    i8 m_iMoveState;
    i8 m_iDirectionToWalkRoundCar;
DECL_CLASS_END()
CHECKSIZE(CEventVehicleCollision, 0x34, 0x40);

DECL_CLASS_BASED(CEventInAir, CEvent)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CEventInAir, _ZN11CEventInAirC2Ev);
    DECL_DTORCALL_PROXY(CEventInAir, _ZN11CEventInAirD2Ev);
    DECL_NEWCALL(CEventInAir, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));
DECL_CLASS_END()
CHECKSIZE(CEventInAir, 0xC, 0x10);

DECL_CLASS_BASED(CEventInWater, CEvent)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CEventInWater, _ZN13CEventInWaterC2Ef, float fBuoyancyFraction);
    DECL_DTORCALL_PROXY(CEventInWater, _ZN13CEventInWaterD2Ev);
    DECL_NEWCALL(CEventInWater, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // Member values
    float m_fBuoyancyFraction;
DECL_CLASS_END()
CHECKSIZE(CEventInWater, 0x10, 0x18);

DECL_CLASS_BASED(CEventCreatePartnerTask, CEvent)
    // Construct/Deconstruct functions
    DECL_DTORCALL_PROXY(CEventCreatePartnerTask, _ZN23CEventCreatePartnerTaskD2Ev);
    DECL_NEWCALL(CEventCreatePartnerTask, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // Member values
    i32 m_type;
    CPed* m_pPartner;
    u8 m_isLeader;
    float m_meetDist;
DECL_CLASS_END()
CHECKSIZE(CEventCreatePartnerTask, 0x1C, 0x28);

DECL_CLASS_BASED(CEventNewGangMember, CEvent)
    // Construct/Deconstruct functions
    DECL_DTORCALL_PROXY(CEventNewGangMember, _ZN19CEventNewGangMemberD2Ev);
    DECL_NEWCALL(CEventNewGangMember, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // Member values
    CPed* m_pPed;
DECL_CLASS_END()
CHECKSIZE(CEventNewGangMember, 0x10, 0x18);

DECL_CLASS_BASED(CEventScriptedAttractor, CEventAttractor)
    // Construct/Deconstruct functions
    DECL_THISCALL_SIMPLE(Delete, _ZN23CEventScriptedAttractorD0Ev, void);
    DECL_NEWCALL(CEventScriptedAttractor, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));
DECL_CLASS_END()
CHECKSIZE(CEventScriptedAttractor, 0x1C, 0x30);

DECL_CLASS_BASED(CEventAcquaintancePedRespect, CEventAcquaintancePed)
    // Construct/Deconstruct functions
    DECL_THISCALL_SIMPLE(Delete, _ZN28CEventAcquaintancePedRespectD0Ev, void);
    DECL_NEWCALL(CEventAcquaintancePedRespect, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));
DECL_CLASS_END()
CHECKSIZE(CEventAcquaintancePedRespect, 0x14, 0x20);

DECL_CLASS_BASED(CEventPlayerCollisionWithPed, CEventPedCollisionWithPed)
    // Construct/Deconstruct functions
    DECL_THISCALL_SIMPLE(Delete, _ZN28CEventPlayerCollisionWithPedD0Ev, void);
    DECL_NEWCALL(CEventPlayerCollisionWithPed, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));
DECL_CLASS_END()
CHECKSIZE(CEventPlayerCollisionWithPed, 0x30, 0x40);

DECL_CLASS_BASED(CEventAcquaintancePedDislike, CEventAcquaintancePed)
    // Construct/Deconstruct functions
    DECL_THISCALL_SIMPLE(Delete, _ZN28CEventAcquaintancePedDislikeD0Ev, void);
    DECL_NEWCALL(CEventAcquaintancePedDislike, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));
DECL_CLASS_END()
CHECKSIZE(CEventAcquaintancePedDislike, 0x14, 0x20);

DECL_CLASS_BASED(CEventPedCollisionWithPlayer, CEventPedCollisionWithPed)
    // Construct/Deconstruct functions
    DECL_THISCALL_SIMPLE(Delete, _ZN28CEventPedCollisionWithPlayerD0Ev, void);
    DECL_NEWCALL(CEventPedCollisionWithPlayer, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));
DECL_CLASS_END()
CHECKSIZE(CEventPedCollisionWithPlayer, 0x30, 0x40);

DECL_CLASS_BASED(CEventAcquaintancePedLike, CEventAcquaintancePed)
    // Construct/Deconstruct functions
    DECL_THISCALL_SIMPLE(Delete, _ZN25CEventAcquaintancePedLikeD0Ev, void);
    DECL_NEWCALL(CEventAcquaintancePedLike, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));
DECL_CLASS_END()
CHECKSIZE(CEventAcquaintancePedLike, 0x14, 0x20);

DECL_CLASS_BASED(CEventDontJoinPlayerGroup, CEvent)
    // Construct/Deconstruct functions
    DECL_DTORCALL_PROXY(CEventDontJoinPlayerGroup, _ZN25CEventDontJoinPlayerGroupD2Ev);
    DECL_NEWCALL(CEventDontJoinPlayerGroup, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // Member values
    CPed* m_pPed;
DECL_CLASS_END()
CHECKSIZE(CEventDontJoinPlayerGroup, 0x10, 0x18);

DECL_CLASS_BASED(CEventPlayerCommandToGroupGather, CEventPlayerCommandToGroup)
    // Construct/Deconstruct functions
    DECL_THISCALL_SIMPLE(Delete, _ZN32CEventPlayerCommandToGroupGatherD0Ev, void);
    DECL_NEWCALL(CEventPlayerCommandToGroupGather, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));
DECL_CLASS_END()
CHECKSIZE(CEventPlayerCommandToGroupGather, 0x18, 0x20);

DECL_CLASS_BASED(CEventVehicleDamageWeapon, CEventVehicleDamage)
    // Construct/Deconstruct functions
    DECL_THISCALL_SIMPLE(Delete, _ZN25CEventVehicleDamageWeaponD0Ev, void);
    DECL_NEWCALL(CEventVehicleDamageWeapon, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));
DECL_CLASS_END()
CHECKSIZE(CEventVehicleDamageWeapon, 0x1C, 0x30);

DECL_CLASS_BASED(CEventVehicleDamageCollision, CEventVehicleDamage)
    // Construct/Deconstruct functions
    DECL_THISCALL_SIMPLE(Delete, _ZN28CEventVehicleDamageCollisionD0Ev, void);
    DECL_NEWCALL(CEventVehicleDamageCollision, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));
DECL_CLASS_END()
CHECKSIZE(CEventVehicleDamageCollision, 0x1C, 0x30);

#endif // __AML_PSDK_SAEVENTTYPES_H
