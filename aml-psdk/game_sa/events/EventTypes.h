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
    DECL_VIRTUALCALL_CONST_HEAD(CEventDamage, GetEventType, _ZTV12CEventDamage, 2, eEventType)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventDamage, GetEventPriority, _ZTV12CEventDamage, 3, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventDamage, GetLifeTime, _ZTV12CEventDamage, 4, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventDamage, CloneEditable, _ZTV12CEventDamage, 17, CEvent*)
    DECL_VIRTUALCALL_TAIL()

    // Construct/Deconstruct functions
    DECL_CTORCALL_NAMED_ARG_HEAD(CEventDamage1, CEventDamage, _ZN12CEventDamageC2EP7CEntityj11eWeaponType14ePedPieceTypeshbb, CEntity* arg2, u32 const arg3, eWeaponType const arg4, ePedPieceTypes const arg5, u8 const arg6, bool const arg7, bool const arg8)
    DECL_CTORCALL_ARG_TAIL(arg2, arg3, arg4, arg5, arg6, arg7, arg8)
    DECL_CTORCALL_ARG_HEAD(CEventDamage, _ZN12CEventDamageC2ERKS_, CEventDamage const& src)
    DECL_CTORCALL_ARG_TAIL(src)
    DECL_DTORCALL_VIRTUAL(CEventDamage, _ZN12CEventDamageD2Ev, _ZN12CEventDamage, _ZTV12CEventDamage);
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
    DECL_VIRTUALCALL_CONST_HEAD(CEventGunShot, GetEventType, _ZTV13CEventGunShot, 2, eEventType)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventGunShot, GetEventPriority, _ZTV13CEventGunShot, 3, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventGunShot, GetLifeTime, _ZTV13CEventGunShot, 4, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventGunShot, CloneEditable, _ZTV13CEventGunShot, 17, CEvent*)
    DECL_VIRTUALCALL_TAIL()

    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CEventGunShot, _ZN13CEventGunShotC2EP7CEntity7CVectorS2_b, CEntity* pFiringEntity, CVector ShotOrigin, CVector ShotTarget, bool bSilent)
    DECL_CTORCALL_ARG_TAIL(pFiringEntity, ShotOrigin, ShotTarget, bSilent)
    DECL_DTORCALL_VIRTUAL(CEventGunShot, _ZN13CEventGunShotD2Ev, _ZN13CEventGunShot, _ZTV13CEventGunShot);
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
    DECL_VIRTUALCALL_CONST_HEAD(CEventDeath, GetEventType, _ZTV11CEventDeath, 2, eEventType)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventDeath, GetEventPriority, _ZTV11CEventDeath, 3, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventDeath, GetLifeTime, _ZTV11CEventDeath, 4, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventDeath, Clone, _ZTV11CEventDeath, 5, CEvent*)
    DECL_VIRTUALCALL_TAIL()

    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CEventDeath, _ZN11CEventDeathC2Eb, bool const bHasDrowned)
    DECL_CTORCALL_ARG_TAIL(bHasDrowned)
    DECL_CTORCALL_NAMED_ARG_HEAD(CEventDeath1, CEventDeath, _ZN11CEventDeathC2Ebi, bool const bHasDrowned, int const timeOfDeath)
    DECL_CTORCALL_ARG_TAIL(bHasDrowned, timeOfDeath)
    DECL_DTORCALL_VIRTUAL(CEventDeath, _ZN11CEventDeathD2Ev, _ZN11CEventDeath, _ZTV11CEventDeath);
    DECL_NEWCALL(CEventDeath, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // Member values
    bool m_bHasDrowned;
    int m_iTimeOfDeath;
DECL_CLASS_END()
CHECKSIZE(CEventDeath, 0x10, 0x18);

DECL_CLASS_BASED(CEventOnFire, CEvent)
    DECL_VIRTUALCALL_CONST_HEAD(CEventOnFire, GetEventType, _ZTV12CEventOnFire, 2, eEventType)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventOnFire, GetEventPriority, _ZTV12CEventOnFire, 3, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventOnFire, GetLifeTime, _ZTV12CEventOnFire, 4, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventOnFire, Clone, _ZTV12CEventOnFire, 5, CEvent*)
    DECL_VIRTUALCALL_TAIL()

    // Construct/Deconstruct functions
    CEventOnFire() = delete;
    DECL_DTORCALL_VIRTUAL_VTABLE(CEventOnFire, _ZN12CEventOnFire, _ZTV12CEventOnFire);
    DECL_THISCALL_SIMPLE(Delete, _ZN12CEventOnFireD0Ev, void);
    DECL_NEWCALL(CEventOnFire, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));
DECL_CLASS_END()
CHECKSIZE(CEventOnFire, 0xC, 0x10);

DECL_CLASS_BASED(CEventVehicleDamage, CEventEditableResponse)
    DECL_VIRTUALCALL_CONST_HEAD(CEventVehicleDamage, GetEventPriority, _ZTV19CEventVehicleDamage, 3, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventVehicleDamage, GetLifeTime, _ZTV19CEventVehicleDamage, 4, int)
    DECL_VIRTUALCALL_TAIL()

    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CEventVehicleDamage, _ZN19CEventVehicleDamageC2EP8CVehicleP7CEntity11eWeaponType, CVehicle* pVehicle, CEntity* pInflictor, eWeaponType const weaponUsed)
    DECL_CTORCALL_ARG_TAIL(pVehicle, pInflictor, weaponUsed)
    DECL_DTORCALL_VIRTUAL(CEventVehicleDamage, _ZN19CEventVehicleDamageD2Ev, _ZN19CEventVehicleDamage, _ZTV19CEventVehicleDamage);
    DECL_NEWCALL(CEventVehicleDamage, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // Member values
    CVehicle* m_pVehicle;
    CEntity* m_pInflictor;
    eWeaponType m_eWeaponUsed;
DECL_CLASS_END()
CHECKSIZE(CEventVehicleDamage, 0x1C, 0x30);

DECL_CLASS_BASED(CEventGunAimedAt, CEventEditableResponse)
    DECL_VIRTUALCALL_CONST_HEAD(CEventGunAimedAt, GetEventType, _ZTV16CEventGunAimedAt, 2, eEventType)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventGunAimedAt, GetEventPriority, _ZTV16CEventGunAimedAt, 3, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventGunAimedAt, GetLifeTime, _ZTV16CEventGunAimedAt, 4, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventGunAimedAt, CloneEditable, _ZTV16CEventGunAimedAt, 17, CEvent*)
    DECL_VIRTUALCALL_TAIL()

    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CEventGunAimedAt, _ZN16CEventGunAimedAtC2EP4CPed, CPed* pAggressorPed)
    DECL_CTORCALL_ARG_TAIL(pAggressorPed)
    DECL_DTORCALL_VIRTUAL(CEventGunAimedAt, _ZN16CEventGunAimedAtD2Ev, _ZN16CEventGunAimedAt, _ZTV16CEventGunAimedAt);
    DECL_NEWCALL(CEventGunAimedAt, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // STATIC functions
    DECL_FASTCALL_SIMPLE(AddGunAimedAtEventToVehicleOccupants, _ZN16CEventGunAimedAt36AddGunAimedAtEventToVehicleOccupantsERK8CVehicleP4CPed, void, CVehicle const& vehicle, CPed* pAggressorPed);

    // Member values
    CPed* m_pAggressorPed;
DECL_CLASS_END()
CHECKSIZE(CEventGunAimedAt, 0x14, 0x20);

DECL_CLASS_BASED(CEventScriptCommand, CEvent)
    DECL_VIRTUALCALL_CONST_HEAD(CEventScriptCommand, GetEventType, _ZTV19CEventScriptCommand, 2, eEventType)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventScriptCommand, GetEventPriority, _ZTV19CEventScriptCommand, 3, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventScriptCommand, GetLifeTime, _ZTV19CEventScriptCommand, 4, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventScriptCommand, Clone, _ZTV19CEventScriptCommand, 5, CEvent*)
    DECL_VIRTUALCALL_TAIL()

    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CEventScriptCommand, _ZN19CEventScriptCommandC2EiP5CTaskb, int const iTaskPriority, CTask* pTask, bool const bAcceptWhenDead)
    DECL_CTORCALL_ARG_TAIL(iTaskPriority, pTask, bAcceptWhenDead)
    DECL_DTORCALL_VIRTUAL(CEventScriptCommand, _ZN19CEventScriptCommandD2Ev, _ZN19CEventScriptCommand, _ZTV19CEventScriptCommand);
    DECL_NEWCALL(CEventScriptCommand, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // Virtual functions
    DECL_VIRTUALCALL_CONST_HEAD(CEventScriptCommand, CloneScriptTask, _ZTV19CEventScriptCommand, 17, CTask*)
    DECL_VIRTUALCALL_TAIL()

    // Member values
    int m_iTaskPriority;
    CTask* m_pTask;
    bool m_bAcceptWhenDead;
DECL_CLASS_END()
CHECKSIZE(CEventScriptCommand, 0x18, 0x28);

DECL_CLASS_BASED(CEventVehicleOnFire, CEventEditableResponse)
    DECL_VIRTUALCALL_CONST_HEAD(CEventVehicleOnFire, GetEventType, _ZTV19CEventVehicleOnFire, 2, eEventType)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventVehicleOnFire, GetEventPriority, _ZTV19CEventVehicleOnFire, 3, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventVehicleOnFire, GetLifeTime, _ZTV19CEventVehicleOnFire, 4, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventVehicleOnFire, CloneEditable, _ZTV19CEventVehicleOnFire, 17, CEvent*)
    DECL_VIRTUALCALL_TAIL()

    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CEventVehicleOnFire, _ZN19CEventVehicleOnFireC2EP8CVehicle, CVehicle* pVehicleOnFire)
    DECL_CTORCALL_ARG_TAIL(pVehicleOnFire)
    DECL_DTORCALL_VIRTUAL(CEventVehicleOnFire, _ZN19CEventVehicleOnFireD2Ev, _ZN19CEventVehicleOnFire, _ZTV19CEventVehicleOnFire);
    DECL_NEWCALL(CEventVehicleOnFire, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // Member values
    CVehicle* m_pVehicleOnFire;
DECL_CLASS_END()
CHECKSIZE(CEventVehicleOnFire, 0x14, 0x20);

DECL_CLASS_BASED(CEventVehicleDied, CEvent)
    DECL_VIRTUALCALL_CONST_HEAD(CEventVehicleDied, GetEventType, _ZTV17CEventVehicleDied, 2, eEventType)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventVehicleDied, GetEventPriority, _ZTV17CEventVehicleDied, 3, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventVehicleDied, GetLifeTime, _ZTV17CEventVehicleDied, 4, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventVehicleDied, Clone, _ZTV17CEventVehicleDied, 5, CEvent*)
    DECL_VIRTUALCALL_TAIL()

    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CEventVehicleDied, _ZN17CEventVehicleDiedC2EP8CVehicle, CVehicle* pDeadVehicle)
    DECL_CTORCALL_ARG_TAIL(pDeadVehicle)
    DECL_DTORCALL_VIRTUAL(CEventVehicleDied, _ZN17CEventVehicleDiedD2Ev, _ZN17CEventVehicleDied, _ZTV17CEventVehicleDied);
    DECL_NEWCALL(CEventVehicleDied, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // Member values
    CVehicle* m_pDeadVehicle;
    bool m_bLeavingVehicle;
DECL_CLASS_END()
CHECKSIZE(CEventVehicleDied, 0x14, 0x20);

DECL_CLASS_BASED(CEventDeadPed, CEventEditableResponse)
    DECL_VIRTUALCALL_CONST_HEAD(CEventDeadPed, GetEventType, _ZTV13CEventDeadPed, 2, eEventType)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventDeadPed, GetEventPriority, _ZTV13CEventDeadPed, 3, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventDeadPed, GetLifeTime, _ZTV13CEventDeadPed, 4, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventDeadPed, CloneEditable, _ZTV13CEventDeadPed, 17, CEvent*)
    DECL_VIRTUALCALL_TAIL()

    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CEventDeadPed, _ZN13CEventDeadPedC2EP4CPedbi, CPed* pDeadPed, bool const bHasDrowned, int const iTimeOfDeath)
    DECL_CTORCALL_ARG_TAIL(pDeadPed, bHasDrowned, iTimeOfDeath)
    DECL_DTORCALL_VIRTUAL(CEventDeadPed, _ZN13CEventDeadPedD2Ev, _ZN13CEventDeadPed, _ZTV13CEventDeadPed);
    DECL_NEWCALL(CEventDeadPed, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // Member values
    CPed* m_pDeadPed;
    bool m_bHasDrowned;
    int m_iTimeOfDeath;
DECL_CLASS_END()
CHECKSIZE(CEventDeadPed, 0x1C, 0x28);

DECL_CLASS_BASED(CEventDanger, CEventEditableResponse)
    DECL_VIRTUALCALL_CONST_HEAD(CEventDanger, GetEventType, _ZTV12CEventDanger, 2, eEventType)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventDanger, GetEventPriority, _ZTV12CEventDanger, 3, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventDanger, GetLifeTime, _ZTV12CEventDanger, 4, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventDanger, CloneEditable, _ZTV12CEventDanger, 17, CEvent*)
    DECL_VIRTUALCALL_TAIL()

    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CEventDanger, _ZN12CEventDangerC2EP7CEntityf, CEntity* pDangerousEntity, float dangerRadius)
    DECL_CTORCALL_ARG_TAIL(pDangerousEntity, dangerRadius)
    DECL_DTORCALL_VIRTUAL(CEventDanger, _ZN12CEventDangerD2Ev, _ZN12CEventDanger, _ZTV12CEventDanger);
    DECL_NEWCALL(CEventDanger, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // Member values
    CEntity* m_pDangerousEntity;
    float m_dangerRadius;
DECL_CLASS_END()
CHECKSIZE(CEventDanger, 0x18, 0x28);

DECL_CLASS_BASED(CEventPedToFlee, CEvent)
    DECL_VIRTUALCALL_CONST_HEAD(CEventPedToFlee, GetEventType, _ZTV15CEventPedToFlee, 2, eEventType)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventPedToFlee, GetEventPriority, _ZTV15CEventPedToFlee, 3, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventPedToFlee, GetLifeTime, _ZTV15CEventPedToFlee, 4, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventPedToFlee, Clone, _ZTV15CEventPedToFlee, 5, CEvent*)
    DECL_VIRTUALCALL_TAIL()

    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CEventPedToFlee, _ZN15CEventPedToFleeC2EP4CPed, CPed* pPedToFlee)
    DECL_CTORCALL_ARG_TAIL(pPedToFlee)
    DECL_DTORCALL_VIRTUAL(CEventPedToFlee, _ZN15CEventPedToFleeD2Ev, _ZN15CEventPedToFlee, _ZTV15CEventPedToFlee);
    DECL_NEWCALL(CEventPedToFlee, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // Member values
    CPed* m_pPedToFlee;
DECL_CLASS_END()
CHECKSIZE(CEventPedToFlee, 0x10, 0x18);

DECL_CLASS_BASED(CEventVehicleThreat, CEventEditableResponse)
    DECL_VIRTUALCALL_CONST_HEAD(CEventVehicleThreat, GetEventType, _ZTV19CEventVehicleThreat, 2, eEventType)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventVehicleThreat, GetEventPriority, _ZTV19CEventVehicleThreat, 3, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventVehicleThreat, GetLifeTime, _ZTV19CEventVehicleThreat, 4, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventVehicleThreat, CloneEditable, _ZTV19CEventVehicleThreat, 17, CEvent*)
    DECL_VIRTUALCALL_TAIL()

    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CEventVehicleThreat, _ZN19CEventVehicleThreatC2EP8CVehicle, CVehicle* pThreatVehicle)
    DECL_CTORCALL_ARG_TAIL(pThreatVehicle)
    DECL_DTORCALL_VIRTUAL(CEventVehicleThreat, _ZN19CEventVehicleThreatD2Ev, _ZN19CEventVehicleThreat, _ZTV19CEventVehicleThreat);
    DECL_NEWCALL(CEventVehicleThreat, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // Member values
    CVehicle* m_pThreatVehicle;
DECL_CLASS_END()
CHECKSIZE(CEventVehicleThreat, 0x14, 0x20);

DECL_CLASS_BASED(CEventPotentialGetRunOver, CEventEditableResponse)
    DECL_VIRTUALCALL_CONST_HEAD(CEventPotentialGetRunOver, GetEventType, _ZTV25CEventPotentialGetRunOver, 2, eEventType)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventPotentialGetRunOver, GetEventPriority, _ZTV25CEventPotentialGetRunOver, 3, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventPotentialGetRunOver, GetLifeTime, _ZTV25CEventPotentialGetRunOver, 4, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventPotentialGetRunOver, CloneEditable, _ZTV25CEventPotentialGetRunOver, 17, CEvent*)
    DECL_VIRTUALCALL_TAIL()

    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CEventPotentialGetRunOver, _ZN25CEventPotentialGetRunOverC2EP8CVehicle, CVehicle* pThreatVehicle)
    DECL_CTORCALL_ARG_TAIL(pThreatVehicle)
    DECL_DTORCALL_VIRTUAL(CEventPotentialGetRunOver, _ZN25CEventPotentialGetRunOverD2Ev, _ZN25CEventPotentialGetRunOver, _ZTV25CEventPotentialGetRunOver);
    DECL_NEWCALL(CEventPotentialGetRunOver, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // Member values
    CVehicle* m_pThreatVehicle;
DECL_CLASS_END()
CHECKSIZE(CEventPotentialGetRunOver, 0x14, 0x20);

DECL_CLASS_BASED(CEventPedCollisionWithPed, CEvent)
    DECL_VIRTUALCALL_CONST_HEAD(CEventPedCollisionWithPed, GetEventType, _ZTV25CEventPedCollisionWithPed, 2, eEventType)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventPedCollisionWithPed, GetEventPriority, _ZTV25CEventPedCollisionWithPed, 3, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventPedCollisionWithPed, GetLifeTime, _ZTV25CEventPedCollisionWithPed, 4, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventPedCollisionWithPed, Clone, _ZTV25CEventPedCollisionWithPed, 5, CEvent*)
    DECL_VIRTUALCALL_TAIL()

    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CEventPedCollisionWithPed, _ZN25CEventPedCollisionWithPedC2EtfPK4CPedRK7CVectorS5_ii, u16 const nPieceType, float const fImpulseMagnitude, CPed const* pPed, CVector const& vNormal, CVector const& vPos, int const iPedMoveState, int const iOtherPedMoveState)
    DECL_CTORCALL_ARG_TAIL(nPieceType, fImpulseMagnitude, pPed, vNormal, vPos, iPedMoveState, iOtherPedMoveState)
    DECL_DTORCALL_VIRTUAL(CEventPedCollisionWithPed, _ZN25CEventPedCollisionWithPedD2Ev, _ZN25CEventPedCollisionWithPed, _ZTV25CEventPedCollisionWithPed);
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
    DECL_VIRTUALCALL_CONST_HEAD(CEventBuildingCollision, GetEventType, _ZTV23CEventBuildingCollision, 2, eEventType)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventBuildingCollision, GetEventPriority, _ZTV23CEventBuildingCollision, 3, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventBuildingCollision, GetLifeTime, _ZTV23CEventBuildingCollision, 4, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventBuildingCollision, Clone, _ZTV23CEventBuildingCollision, 5, CEvent*)
    DECL_VIRTUALCALL_TAIL()

    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CEventBuildingCollision, _ZN23CEventBuildingCollisionC2EtfPK9CBuildingRK7CVectorS5_i, u16 const nPieceType, float const fImpulseMagnitude, CBuilding const* pBuilding, CVector const& vNormal, CVector const& vPos, int const iMoveState)
    DECL_CTORCALL_ARG_TAIL(nPieceType, fImpulseMagnitude, pBuilding, vNormal, vPos, iMoveState)
    DECL_DTORCALL_VIRTUAL(CEventBuildingCollision, _ZN23CEventBuildingCollisionD2Ev, _ZN23CEventBuildingCollision, _ZTV23CEventBuildingCollision);
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
    DECL_VIRTUALCALL_CONST_HEAD(CEventObjectCollision, GetEventType, _ZTV21CEventObjectCollision, 2, eEventType)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventObjectCollision, GetEventPriority, _ZTV21CEventObjectCollision, 3, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventObjectCollision, GetLifeTime, _ZTV21CEventObjectCollision, 4, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventObjectCollision, Clone, _ZTV21CEventObjectCollision, 5, CEvent*)
    DECL_VIRTUALCALL_TAIL()

    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CEventObjectCollision, _ZN21CEventObjectCollisionC2EtfPK7CObjectRK7CVectorS5_i, u16 const nPieceType, float const fImpulseMagnitude, CObject const* pObject, CVector const& vNormal, CVector const& vPos, int const iMoveState)
    DECL_CTORCALL_ARG_TAIL(nPieceType, fImpulseMagnitude, pObject, vNormal, vPos, iMoveState)
    DECL_DTORCALL_VIRTUAL(CEventObjectCollision, _ZN21CEventObjectCollisionD2Ev, _ZN21CEventObjectCollision, _ZTV21CEventObjectCollision);
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
    DECL_VIRTUALCALL_CONST_HEAD(CEventAcquaintancePed, GetLifeTime, _ZTV21CEventAcquaintancePed, 4, int)
    DECL_VIRTUALCALL_TAIL()

    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CEventAcquaintancePed, _ZN21CEventAcquaintancePedC2EP4CPed, CPed* pAcquaintancePed)
    DECL_CTORCALL_ARG_TAIL(pAcquaintancePed)
    DECL_DTORCALL_VIRTUAL(CEventAcquaintancePed, _ZN21CEventAcquaintancePedD2Ev, _ZN21CEventAcquaintancePed, _ZTV21CEventAcquaintancePed);
    DECL_NEWCALL(CEventAcquaintancePed, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // Member values
    CPed* m_pAcquaintancePed;
DECL_CLASS_END()
CHECKSIZE(CEventAcquaintancePed, 0x14, 0x20);

DECL_CLASS_BASED(CEventAcquaintancePedHate, CEventAcquaintancePed)
    DECL_VIRTUALCALL_CONST_HEAD(CEventAcquaintancePedHate, GetEventType, _ZTV25CEventAcquaintancePedHate, 2, eEventType)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventAcquaintancePedHate, GetEventPriority, _ZTV25CEventAcquaintancePedHate, 3, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventAcquaintancePedHate, CloneEditable, _ZTV25CEventAcquaintancePedHate, 17, CEvent*)
    DECL_VIRTUALCALL_TAIL()

    // Construct/Deconstruct functions
    CEventAcquaintancePedHate() = delete;
    DECL_DTORCALL_VIRTUAL_VTABLE(CEventAcquaintancePedHate, _ZN25CEventAcquaintancePedHate, _ZTV25CEventAcquaintancePedHate);
    DECL_THISCALL_SIMPLE(Delete, _ZN25CEventAcquaintancePedHateD0Ev, void);
    DECL_NEWCALL(CEventAcquaintancePedHate, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));
DECL_CLASS_END()
CHECKSIZE(CEventAcquaintancePedHate, 0x14, 0x20);

DECL_CLASS_BASED(CEventPlayerCommandToGroup, CEventEditableResponse)
    DECL_VIRTUALCALL_CONST_HEAD(CEventPlayerCommandToGroup, GetLifeTime, _ZTV26CEventPlayerCommandToGroup, 4, int)
    DECL_VIRTUALCALL_TAIL()

    enum
    {
        GROUP_COMMAND_ATTACK = 0,
        GROUP_COMMAND_RETREAT = 1,
        GROUP_COMMAND_GATHER = 2,
    };

    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CEventPlayerCommandToGroup, _ZN26CEventPlayerCommandToGroupC2EiP4CPed, int const iType, CPed* pPed)
    DECL_CTORCALL_ARG_TAIL(iType, pPed)
    DECL_DTORCALL_VIRTUAL(CEventPlayerCommandToGroup, _ZN26CEventPlayerCommandToGroupD2Ev, _ZN26CEventPlayerCommandToGroup, _ZTV26CEventPlayerCommandToGroup);
    DECL_NEWCALL(CEventPlayerCommandToGroup, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // Member values
    int m_iType;
    CPed* m_pPed;
DECL_CLASS_END()
CHECKSIZE(CEventPlayerCommandToGroup, 0x18, 0x20);

DECL_CLASS_BASED(CEventPlayerCommandToGroupAttack, CEventPlayerCommandToGroup)
    DECL_VIRTUALCALL_CONST_HEAD(CEventPlayerCommandToGroupAttack, GetEventType, _ZTV32CEventPlayerCommandToGroupAttack, 2, eEventType)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventPlayerCommandToGroupAttack, GetEventPriority, _ZTV32CEventPlayerCommandToGroupAttack, 3, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventPlayerCommandToGroupAttack, CloneEditable, _ZTV32CEventPlayerCommandToGroupAttack, 17, CEvent*)
    DECL_VIRTUALCALL_TAIL()

    // Construct/Deconstruct functions
    CEventPlayerCommandToGroupAttack() = delete;
    DECL_DTORCALL_VIRTUAL_VTABLE(CEventPlayerCommandToGroupAttack, _ZN32CEventPlayerCommandToGroupAttack, _ZTV32CEventPlayerCommandToGroupAttack);
    DECL_THISCALL_SIMPLE(Delete, _ZN32CEventPlayerCommandToGroupAttackD0Ev, void);
    DECL_NEWCALL(CEventPlayerCommandToGroupAttack, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));
DECL_CLASS_END()
CHECKSIZE(CEventPlayerCommandToGroupAttack, 0x18, 0x20);

DECL_CLASS_BASED(CEventDraggedOutCar, CEventEditableResponse)
    DECL_VIRTUALCALL_CONST_HEAD(CEventDraggedOutCar, GetEventType, _ZTV19CEventDraggedOutCar, 2, eEventType)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventDraggedOutCar, GetEventPriority, _ZTV19CEventDraggedOutCar, 3, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventDraggedOutCar, GetLifeTime, _ZTV19CEventDraggedOutCar, 4, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventDraggedOutCar, CloneEditable, _ZTV19CEventDraggedOutCar, 17, CEvent*)
    DECL_VIRTUALCALL_TAIL()

    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CEventDraggedOutCar, _ZN19CEventDraggedOutCarC2EPK8CVehiclePK4CPedb, CVehicle const* pVehicle, CPed const* pDraggingPed, bool const bIsDriver)
    DECL_CTORCALL_ARG_TAIL(pVehicle, pDraggingPed, bIsDriver)
    DECL_DTORCALL_VIRTUAL(CEventDraggedOutCar, _ZN19CEventDraggedOutCarD2Ev, _ZN19CEventDraggedOutCar, _ZTV19CEventDraggedOutCar);
    DECL_NEWCALL(CEventDraggedOutCar, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // Member values
    CPed* m_pDraggingPed;
    CVehicle* m_pVehicle;
    bool m_bWasDriver;
DECL_CLASS_END()
CHECKSIZE(CEventDraggedOutCar, 0x1C, 0x30);

DECL_CLASS_BASED(CEventGotKnockedOverByCar, CEventEditableResponse)
    DECL_VIRTUALCALL_CONST_HEAD(CEventGotKnockedOverByCar, GetEventType, _ZTV25CEventGotKnockedOverByCar, 2, eEventType)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventGotKnockedOverByCar, GetEventPriority, _ZTV25CEventGotKnockedOverByCar, 3, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventGotKnockedOverByCar, GetLifeTime, _ZTV25CEventGotKnockedOverByCar, 4, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventGotKnockedOverByCar, CloneEditable, _ZTV25CEventGotKnockedOverByCar, 17, CEvent*)
    DECL_VIRTUALCALL_TAIL()

    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CEventGotKnockedOverByCar, _ZN25CEventGotKnockedOverByCarC2EP8CVehicle, CVehicle* pVehicle)
    DECL_CTORCALL_ARG_TAIL(pVehicle)
    DECL_DTORCALL_VIRTUAL(CEventGotKnockedOverByCar, _ZN25CEventGotKnockedOverByCarD2Ev, _ZN25CEventGotKnockedOverByCar, _ZTV25CEventGotKnockedOverByCar);
    DECL_NEWCALL(CEventGotKnockedOverByCar, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // Member values
    CVehicle* m_pVehicle;
DECL_CLASS_END()
CHECKSIZE(CEventGotKnockedOverByCar, 0x14, 0x20);

DECL_CLASS_BASED(CEventKnockOffBike, CEvent)
    DECL_VIRTUALCALL_CONST_HEAD(CEventKnockOffBike, GetEventType, _ZTV18CEventKnockOffBike, 2, eEventType)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventKnockOffBike, GetEventPriority, _ZTV18CEventKnockOffBike, 3, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventKnockOffBike, GetLifeTime, _ZTV18CEventKnockOffBike, 4, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventKnockOffBike, Clone, _ZTV18CEventKnockOffBike, 5, CEvent*)
    DECL_VIRTUALCALL_TAIL()

    // Construct/Deconstruct functions
    DECL_CTORCALL_NAMED_ARG_HEAD(CEventKnockOffBike2, CEventKnockOffBike, _ZN18CEventKnockOffBikeC2EP8CVehicleRK7CVectorS4_ff11eWeaponTypeaiP4CPedbb, CVehicle* arg2, CVector const& arg3, CVector const& arg4, float arg5, float arg6, eWeaponType arg7, i8 arg8, int const arg9, CPed* arg10, bool const arg11, bool const arg12)
    DECL_CTORCALL_ARG_TAIL(arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12)
    DECL_CTORCALL(CEventKnockOffBike, _ZN18CEventKnockOffBikeC2Ev);
    DECL_CTORCALL_NAMED_ARG_HEAD(CEventKnockOffBike1, CEventKnockOffBike, _ZN18CEventKnockOffBikeC2ERKS_, CEventKnockOffBike const& src)
    DECL_CTORCALL_ARG_TAIL(src)
    DECL_DTORCALL_VIRTUAL(CEventKnockOffBike, _ZN18CEventKnockOffBikeD2Ev, _ZN18CEventKnockOffBike, _ZTV18CEventKnockOffBike);
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
    DECL_VIRTUALCALL_CONST_HEAD(CEventAttractor, GetEventType, _ZTV15CEventAttractor, 2, eEventType)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventAttractor, GetEventPriority, _ZTV15CEventAttractor, 3, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventAttractor, GetLifeTime, _ZTV15CEventAttractor, 4, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventAttractor, CloneEditable, _ZTV15CEventAttractor, 17, CEvent*)
    DECL_VIRTUALCALL_TAIL()

    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CEventAttractor, _ZN15CEventAttractorC2EP9C2dEffectP7CEntityh, C2dEffect* pEffect, CEntity* pEntity, u8 forceUse)
    DECL_CTORCALL_ARG_TAIL(pEffect, pEntity, forceUse)
    DECL_DTORCALL_VIRTUAL(CEventAttractor, _ZN15CEventAttractorD2Ev, _ZN15CEventAttractor, _ZTV15CEventAttractor);
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

    CEventSoundLoud() = delete;
    DECL_VIRTUALCALL_CONST_HEAD(CEventSoundLoud, GetEventType, _ZTV15CEventSoundLoud, 2, eEventType)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventSoundLoud, GetEventPriority, _ZTV15CEventSoundLoud, 3, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventSoundLoud, GetLifeTime, _ZTV15CEventSoundLoud, 4, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventSoundLoud, CloneEditable, _ZTV15CEventSoundLoud, 17, CEvent*)
    DECL_VIRTUALCALL_TAIL()

    DECL_NEWCALL(CEventSoundLoud, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // Member values
    CEntity* m_pEntityMakingSound;
    float m_Volume;
DECL_CLASS_END()
CHECKSIZE(CEventSoundLoud, 0x18, 0x28);

DECL_CLASS_BASED(CEventSoundQuiet, CEventEditableResponse)
    DECL_VIRTUALCALL_CONST_HEAD(CEventSoundQuiet, GetEventType, _ZTV16CEventSoundQuiet, 2, eEventType)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventSoundQuiet, GetEventPriority, _ZTV16CEventSoundQuiet, 3, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventSoundQuiet, GetLifeTime, _ZTV16CEventSoundQuiet, 4, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventSoundQuiet, CloneEditable, _ZTV16CEventSoundQuiet, 17, CEvent*)
    DECL_VIRTUALCALL_TAIL()

    // Construct/Deconstruct functions
    CEventSoundQuiet() = delete;
    DECL_DTORCALL_VIRTUAL(CEventSoundQuiet, _ZN16CEventSoundQuietD2Ev, _ZN16CEventSoundQuiet, _ZTV16CEventSoundQuiet);
    DECL_NEWCALL(CEventSoundQuiet, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // Member values
    CEntity* m_pEntityMakingSound;
    float m_Volume;
    int m_iTimeHeard;
    CVector m_vTargetPosAtHeardTime;
DECL_CLASS_END()
CHECKSIZE(CEventSoundQuiet, 0x28, 0x38);

DECL_CLASS_BASED(CEventVehicleHitAndRun, CEvent)
    DECL_VIRTUALCALL_CONST_HEAD(CEventVehicleHitAndRun, GetEventType, _ZTV22CEventVehicleHitAndRun, 2, eEventType)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventVehicleHitAndRun, GetEventPriority, _ZTV22CEventVehicleHitAndRun, 3, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventVehicleHitAndRun, GetLifeTime, _ZTV22CEventVehicleHitAndRun, 4, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventVehicleHitAndRun, Clone, _ZTV22CEventVehicleHitAndRun, 5, CEvent*)
    DECL_VIRTUALCALL_TAIL()

    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CEventVehicleHitAndRun, _ZN22CEventVehicleHitAndRunC2EP4CPedP8CVehicle, CPed* pKnockedDownPed, CVehicle* pInflictor)
    DECL_CTORCALL_ARG_TAIL(pKnockedDownPed, pInflictor)
    DECL_DTORCALL_VIRTUAL(CEventVehicleHitAndRun, _ZN22CEventVehicleHitAndRunD2Ev, _ZN22CEventVehicleHitAndRun, _ZTV22CEventVehicleHitAndRun);
    DECL_NEWCALL(CEventVehicleHitAndRun, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // Member values
    CPed* m_pKnockedDownPed;
    CVehicle* m_pInflictor;
DECL_CLASS_END()
CHECKSIZE(CEventVehicleHitAndRun, 0x14, 0x20);

DECL_CLASS_BASED(CEventGroupEvent, CEvent)
    DECL_VIRTUALCALL_CONST_HEAD(CEventGroupEvent, GetEventType, _ZTV16CEventGroupEvent, 2, eEventType)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventGroupEvent, GetEventPriority, _ZTV16CEventGroupEvent, 3, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventGroupEvent, GetLifeTime, _ZTV16CEventGroupEvent, 4, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventGroupEvent, Clone, _ZTV16CEventGroupEvent, 5, CEvent*)
    DECL_VIRTUALCALL_TAIL()

    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CEventGroupEvent, _ZN16CEventGroupEventC2EP4CPedP6CEvent, CPed* pDistressedPed, CEvent* pEvent)
    DECL_CTORCALL_ARG_TAIL(pDistressedPed, pEvent)
    DECL_DTORCALL_VIRTUAL(CEventGroupEvent, _ZN16CEventGroupEventD2Ev, _ZN16CEventGroupEvent, _ZTV16CEventGroupEvent);
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
    DECL_VIRTUALCALL_CONST_HEAD(CEventLeaderEnteredCarAsDriver, GetEventType, _ZTV30CEventLeaderEnteredCarAsDriver, 2, eEventType)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventLeaderEnteredCarAsDriver, GetEventPriority, _ZTV30CEventLeaderEnteredCarAsDriver, 3, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventLeaderEnteredCarAsDriver, GetLifeTime, _ZTV30CEventLeaderEnteredCarAsDriver, 4, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventLeaderEnteredCarAsDriver, CloneEditable, _ZTV30CEventLeaderEnteredCarAsDriver, 17, CEvent*)
    DECL_VIRTUALCALL_TAIL()

    // Construct/Deconstruct functions
    CEventLeaderEnteredCarAsDriver() = delete;
    DECL_DTORCALL_VIRTUAL(CEventLeaderEnteredCarAsDriver, _ZN30CEventLeaderEnteredCarAsDriverD2Ev, _ZN30CEventLeaderEnteredCarAsDriver, _ZTV30CEventLeaderEnteredCarAsDriver);
    DECL_NEWCALL(CEventLeaderEnteredCarAsDriver, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // Member values
    CVehicle* m_pVehicle;
DECL_CLASS_END()
CHECKSIZE(CEventLeaderEnteredCarAsDriver, 0x14, 0x20);

DECL_CLASS_BASED(CEventStuckInAir, CEvent)
    DECL_VIRTUALCALL_CONST_HEAD(CEventStuckInAir, GetEventType, _ZTV16CEventStuckInAir, 2, eEventType)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventStuckInAir, GetEventPriority, _ZTV16CEventStuckInAir, 3, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventStuckInAir, GetLifeTime, _ZTV16CEventStuckInAir, 4, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventStuckInAir, Clone, _ZTV16CEventStuckInAir, 5, CEvent*)
    DECL_VIRTUALCALL_TAIL()

    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CEventStuckInAir, _ZN16CEventStuckInAirC2EP4CPed, CPed* pPed)
    DECL_CTORCALL_ARG_TAIL(pPed)
    DECL_DTORCALL_VIRTUAL(CEventStuckInAir, _ZN16CEventStuckInAirD2Ev, _ZN16CEventStuckInAir, _ZTV16CEventStuckInAir);
    DECL_NEWCALL(CEventStuckInAir, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // Member values
    CPed* m_pPed;
DECL_CLASS_END()
CHECKSIZE(CEventStuckInAir, 0x10, 0x18);

DECL_CLASS_BASED(CEventPotentialWalkIntoFire, CEventEditableResponse)
    DECL_VIRTUALCALL_CONST_HEAD(CEventPotentialWalkIntoFire, GetEventType, _ZTV27CEventPotentialWalkIntoFire, 2, eEventType)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventPotentialWalkIntoFire, GetEventPriority, _ZTV27CEventPotentialWalkIntoFire, 3, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventPotentialWalkIntoFire, GetLifeTime, _ZTV27CEventPotentialWalkIntoFire, 4, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventPotentialWalkIntoFire, CloneEditable, _ZTV27CEventPotentialWalkIntoFire, 17, CEvent*)
    DECL_VIRTUALCALL_TAIL()

    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CEventPotentialWalkIntoFire, _ZN27CEventPotentialWalkIntoFireC2ERK7CVectorfi, CVector const& vFirePos, float const fStrength, int const iMoveState)
    DECL_CTORCALL_ARG_TAIL(vFirePos, fStrength, iMoveState)
    DECL_DTORCALL_VIRTUAL(CEventPotentialWalkIntoFire, _ZN27CEventPotentialWalkIntoFireD2Ev, _ZN27CEventPotentialWalkIntoFire, _ZTV27CEventPotentialWalkIntoFire);
    DECL_NEWCALL(CEventPotentialWalkIntoFire, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // Member values
    CVector m_vFirePos;
    float m_fStrength;
    float m_fFireRadius;
    int m_iMoveState;
DECL_CLASS_END()
CHECKSIZE(CEventPotentialWalkIntoFire, 0x28, 0x30);

DECL_CLASS_BASED(CEventLeaderExitedCarAsDriver, CEventEditableResponse)
    DECL_VIRTUALCALL_CONST_HEAD(CEventLeaderExitedCarAsDriver, GetEventType, _ZTV29CEventLeaderExitedCarAsDriver, 2, eEventType)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventLeaderExitedCarAsDriver, GetEventPriority, _ZTV29CEventLeaderExitedCarAsDriver, 3, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventLeaderExitedCarAsDriver, GetLifeTime, _ZTV29CEventLeaderExitedCarAsDriver, 4, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventLeaderExitedCarAsDriver, CloneEditable, _ZTV29CEventLeaderExitedCarAsDriver, 17, CEvent*)
    DECL_VIRTUALCALL_TAIL()

    // Construct/Deconstruct functions
    CEventLeaderExitedCarAsDriver() = delete;
    DECL_DTORCALL_VIRTUAL_VTABLE(CEventLeaderExitedCarAsDriver, _ZN29CEventLeaderExitedCarAsDriver, _ZTV29CEventLeaderExitedCarAsDriver);
    DECL_THISCALL_SIMPLE(Delete, _ZN29CEventLeaderExitedCarAsDriverD0Ev, void);
    DECL_NEWCALL(CEventLeaderExitedCarAsDriver, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));
DECL_CLASS_END()
CHECKSIZE(CEventLeaderExitedCarAsDriver, 0x10, 0x18);

DECL_CLASS_BASED(CEventCopCarBeingStolen, CEvent)
    DECL_VIRTUALCALL_CONST_HEAD(CEventCopCarBeingStolen, GetEventType, _ZTV23CEventCopCarBeingStolen, 2, eEventType)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventCopCarBeingStolen, GetEventPriority, _ZTV23CEventCopCarBeingStolen, 3, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventCopCarBeingStolen, GetLifeTime, _ZTV23CEventCopCarBeingStolen, 4, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventCopCarBeingStolen, Clone, _ZTV23CEventCopCarBeingStolen, 5, CEvent*)
    DECL_VIRTUALCALL_TAIL()

    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CEventCopCarBeingStolen, _ZN23CEventCopCarBeingStolenC2EP4CPedP8CVehicle, CPed* pCriminal, CVehicle* pTargetVehicle)
    DECL_CTORCALL_ARG_TAIL(pCriminal, pTargetVehicle)
    DECL_DTORCALL_VIRTUAL(CEventCopCarBeingStolen, _ZN23CEventCopCarBeingStolenD2Ev, _ZN23CEventCopCarBeingStolen, _ZTV23CEventCopCarBeingStolen);
    DECL_NEWCALL(CEventCopCarBeingStolen, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // Member values
    CPed* m_pCriminal;
    CVehicle* m_pTargetVehicle;
DECL_CLASS_END()
CHECKSIZE(CEventCopCarBeingStolen, 0x14, 0x20);

DECL_CLASS_BASED(CEventVehicleToSteal, CEvent)
    DECL_VIRTUALCALL_CONST_HEAD(CEventVehicleToSteal, GetEventType, _ZTV20CEventVehicleToSteal, 2, eEventType)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventVehicleToSteal, GetEventPriority, _ZTV20CEventVehicleToSteal, 3, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventVehicleToSteal, GetLifeTime, _ZTV20CEventVehicleToSteal, 4, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventVehicleToSteal, Clone, _ZTV20CEventVehicleToSteal, 5, CEvent*)
    DECL_VIRTUALCALL_TAIL()

    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CEventVehicleToSteal, _ZN20CEventVehicleToStealC2EP8CVehicle, CVehicle* pVehicle)
    DECL_CTORCALL_ARG_TAIL(pVehicle)
    DECL_DTORCALL_VIRTUAL(CEventVehicleToSteal, _ZN20CEventVehicleToStealD2Ev, _ZN20CEventVehicleToSteal, _ZTV20CEventVehicleToSteal);
    DECL_NEWCALL(CEventVehicleToSteal, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // Member values
    CVehicle* m_pVehicle;
DECL_CLASS_END()
CHECKSIZE(CEventVehicleToSteal, 0x10, 0x18);

DECL_CLASS_BASED(CEventHealthReallyLow, CEventEditableResponse)
    DECL_VIRTUALCALL_CONST_HEAD(CEventHealthReallyLow, GetEventType, _ZTV21CEventHealthReallyLow, 2, eEventType)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventHealthReallyLow, GetEventPriority, _ZTV21CEventHealthReallyLow, 3, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventHealthReallyLow, GetLifeTime, _ZTV21CEventHealthReallyLow, 4, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventHealthReallyLow, CloneEditable, _ZTV21CEventHealthReallyLow, 17, CEvent*)
    DECL_VIRTUALCALL_TAIL()

    // Construct/Deconstruct functions
    CEventHealthReallyLow() = delete;
    DECL_DTORCALL_VIRTUAL_VTABLE(CEventHealthReallyLow, _ZN21CEventHealthReallyLow, _ZTV21CEventHealthReallyLow);
    DECL_THISCALL_SIMPLE(Delete, _ZN21CEventHealthReallyLowD0Ev, void);
    DECL_NEWCALL(CEventHealthReallyLow, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));
DECL_CLASS_END()
CHECKSIZE(CEventHealthReallyLow, 0x10, 0x18);

DECL_CLASS_BASED(CEventRevived, CEvent)
    DECL_VIRTUALCALL_CONST_HEAD(CEventRevived, GetEventType, _ZTV13CEventRevived, 2, eEventType)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventRevived, GetEventPriority, _ZTV13CEventRevived, 3, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventRevived, GetLifeTime, _ZTV13CEventRevived, 4, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventRevived, Clone, _ZTV13CEventRevived, 5, CEvent*)
    DECL_VIRTUALCALL_TAIL()

    // Construct/Deconstruct functions
    DECL_CTORCALL(CEventRevived, _ZN13CEventRevivedC2Ev);
    DECL_DTORCALL_VIRTUAL(CEventRevived, _ZN13CEventRevivedD2Ev, _ZN13CEventRevived, _ZTV13CEventRevived);
    DECL_NEWCALL(CEventRevived, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));
DECL_CLASS_END()
CHECKSIZE(CEventRevived, 0xC, 0x10);

DECL_CLASS_BASED(CEventSexyPed, CEventEditableResponse)
    DECL_VIRTUALCALL_CONST_HEAD(CEventSexyPed, GetEventType, _ZTV13CEventSexyPed, 2, eEventType)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventSexyPed, GetEventPriority, _ZTV13CEventSexyPed, 3, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventSexyPed, GetLifeTime, _ZTV13CEventSexyPed, 4, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventSexyPed, CloneEditable, _ZTV13CEventSexyPed, 17, CEvent*)
    DECL_VIRTUALCALL_TAIL()

    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CEventSexyPed, _ZN13CEventSexyPedC2EP4CPed, CPed* pSexyPed)
    DECL_CTORCALL_ARG_TAIL(pSexyPed)
    DECL_DTORCALL_VIRTUAL(CEventSexyPed, _ZN13CEventSexyPedD2Ev, _ZN13CEventSexyPed, _ZTV13CEventSexyPed);
    DECL_NEWCALL(CEventSexyPed, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // Member values
    CPed* m_pSexyPed;
DECL_CLASS_END()
CHECKSIZE(CEventSexyPed, 0x14, 0x20);

DECL_CLASS_BASED(CEventLowAngerAtPlayer, CEventEditableResponse)
    DECL_VIRTUALCALL_CONST_HEAD(CEventLowAngerAtPlayer, GetEventType, _ZTV22CEventLowAngerAtPlayer, 2, eEventType)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventLowAngerAtPlayer, GetEventPriority, _ZTV22CEventLowAngerAtPlayer, 3, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventLowAngerAtPlayer, GetLifeTime, _ZTV22CEventLowAngerAtPlayer, 4, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventLowAngerAtPlayer, CloneEditable, _ZTV22CEventLowAngerAtPlayer, 17, CEvent*)
    DECL_VIRTUALCALL_TAIL()

    // Construct/Deconstruct functions
    CEventLowAngerAtPlayer() = delete;
    DECL_DTORCALL_VIRTUAL_VTABLE(CEventLowAngerAtPlayer, _ZN22CEventLowAngerAtPlayer, _ZTV22CEventLowAngerAtPlayer);
    DECL_THISCALL_SIMPLE(Delete, _ZN22CEventLowAngerAtPlayerD0Ev, void);
    DECL_NEWCALL(CEventLowAngerAtPlayer, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));
DECL_CLASS_END()
CHECKSIZE(CEventLowAngerAtPlayer, 0x10, 0x18);

DECL_CLASS_BASED(CEventPotentialWalkIntoBuilding, CEventBuildingCollision)
    // Construct/Deconstruct functions
    CEventPotentialWalkIntoBuilding() = delete;
    DECL_NEWCALL(CEventPotentialWalkIntoBuilding, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));
DECL_CLASS_END()
CHECKSIZE(CEventPotentialWalkIntoBuilding, 0x30, 0x38);

DECL_CLASS_BASED(CEventSeenCop, CEventAcquaintancePed)
    DECL_VIRTUALCALL_CONST_HEAD(CEventSeenCop, GetEventType, _ZTV13CEventSeenCop, 2, eEventType)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventSeenCop, GetEventPriority, _ZTV13CEventSeenCop, 3, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventSeenCop, CloneEditable, _ZTV13CEventSeenCop, 17, CEvent*)
    DECL_VIRTUALCALL_TAIL()

    // Construct/Deconstruct functions
    CEventSeenCop() = delete;
    DECL_DTORCALL_VIRTUAL_VTABLE(CEventSeenCop, _ZN13CEventSeenCop, _ZTV13CEventSeenCop);
    DECL_THISCALL_SIMPLE(Delete, _ZN13CEventSeenCopD0Ev, void);
    DECL_NEWCALL(CEventSeenCop, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));
DECL_CLASS_END()
CHECKSIZE(CEventSeenCop, 0x14, 0x20);

DECL_CLASS_BASED(CEventLeaderQuitEnteringCarAsDriver, CEvent)
    DECL_VIRTUALCALL_CONST_HEAD(CEventLeaderQuitEnteringCarAsDriver, GetEventType, _ZTV35CEventLeaderQuitEnteringCarAsDriver, 2, eEventType)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventLeaderQuitEnteringCarAsDriver, GetEventPriority, _ZTV35CEventLeaderQuitEnteringCarAsDriver, 3, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventLeaderQuitEnteringCarAsDriver, GetLifeTime, _ZTV35CEventLeaderQuitEnteringCarAsDriver, 4, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventLeaderQuitEnteringCarAsDriver, Clone, _ZTV35CEventLeaderQuitEnteringCarAsDriver, 5, CEvent*)
    DECL_VIRTUALCALL_TAIL()

    // Construct/Deconstruct functions
    CEventLeaderQuitEnteringCarAsDriver() = delete;
    DECL_DTORCALL_VIRTUAL_VTABLE(CEventLeaderQuitEnteringCarAsDriver, _ZN35CEventLeaderQuitEnteringCarAsDriver, _ZTV35CEventLeaderQuitEnteringCarAsDriver);
    DECL_THISCALL_SIMPLE(Delete, _ZN35CEventLeaderQuitEnteringCarAsDriverD0Ev, void);
    DECL_NEWCALL(CEventLeaderQuitEnteringCarAsDriver, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));
DECL_CLASS_END()
CHECKSIZE(CEventLeaderQuitEnteringCarAsDriver, 0xC, 0x10);

DECL_CLASS_BASED(CEventAreaCodes, CEvent)
    DECL_VIRTUALCALL_CONST_HEAD(CEventAreaCodes, GetEventType, _ZTV15CEventAreaCodes, 2, eEventType)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventAreaCodes, GetEventPriority, _ZTV15CEventAreaCodes, 3, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventAreaCodes, GetLifeTime, _ZTV15CEventAreaCodes, 4, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventAreaCodes, Clone, _ZTV15CEventAreaCodes, 5, CEvent*)
    DECL_VIRTUALCALL_TAIL()

    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CEventAreaCodes, _ZN15CEventAreaCodesC2EP4CPed, CPed* pTargetPed)
    DECL_CTORCALL_ARG_TAIL(pTargetPed)
    DECL_DTORCALL_VIRTUAL(CEventAreaCodes, _ZN15CEventAreaCodesD2Ev, _ZN15CEventAreaCodes, _ZTV15CEventAreaCodes);
    DECL_NEWCALL(CEventAreaCodes, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // Member values
    CPed* m_pTargetPed;
DECL_CLASS_END()
CHECKSIZE(CEventAreaCodes, 0x10, 0x18);

DECL_CLASS_BASED(CEventGunShotWhizzedBy, CEventGunShot)
    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CEventGunShotWhizzedBy, _ZN22CEventGunShotWhizzedByC2EP7CEntityRK7CVectorS4_b, CEntity* pFiringEntity, CVector const& vShotOrigin, CVector const& vShotTarget, bool const bIsSilent)
    DECL_CTORCALL_ARG_TAIL(pFiringEntity, vShotOrigin, vShotTarget, bIsSilent)
    DECL_DTORCALL_VIRTUAL(CEventGunShotWhizzedBy, _ZN22CEventGunShotWhizzedByD2Ev, _ZN22CEventGunShotWhizzedBy, _ZTV22CEventGunShotWhizzedBy);
    DECL_NEWCALL(CEventGunShotWhizzedBy, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // STATIC values
    DECL_OBJECT_PLT(float, ms_fThresholdDist, BYBIT(0x677230, 0x84C498));
DECL_CLASS_END()
CHECKSIZE(CEventGunShotWhizzedBy, 0x30, 0x40);

DECL_CLASS_BASED(CEventLeaderEntryExit, CEventAreaCodes)
    // Construct/Deconstruct functions
    CEventLeaderEntryExit() = delete;
    DECL_DTORCALL_VIRTUAL_VTABLE(CEventLeaderEntryExit, _ZN21CEventLeaderEntryExit, _ZTV21CEventLeaderEntryExit);
    DECL_THISCALL_SIMPLE(Delete, _ZN21CEventLeaderEntryExitD0Ev, void);
    DECL_NEWCALL(CEventLeaderEntryExit, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));
DECL_CLASS_END()
CHECKSIZE(CEventLeaderEntryExit, 0x10, 0x18);

DECL_CLASS_BASED(CEventSignalAtPed, CEvent)
    DECL_VIRTUALCALL_CONST_HEAD(CEventSignalAtPed, GetEventType, _ZTV17CEventSignalAtPed, 2, eEventType)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventSignalAtPed, GetEventPriority, _ZTV17CEventSignalAtPed, 3, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventSignalAtPed, GetLifeTime, _ZTV17CEventSignalAtPed, 4, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventSignalAtPed, Clone, _ZTV17CEventSignalAtPed, 5, CEvent*)
    DECL_VIRTUALCALL_TAIL()

    // Construct/Deconstruct functions
    CEventSignalAtPed() = delete;
    DECL_NEWCALL(CEventSignalAtPed, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // Member values
    CPed* m_pPed;
    i32 m_initialPause;
    u8 m_playAnimAtEnd;
DECL_CLASS_END()
CHECKSIZE(CEventSignalAtPed, 0x18, 0x20);

DECL_CLASS_BASED(CEventEscalator, CEvent)
    DECL_VIRTUALCALL_CONST_HEAD(CEventEscalator, GetEventType, _ZTV15CEventEscalator, 2, eEventType)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventEscalator, GetEventPriority, _ZTV15CEventEscalator, 3, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventEscalator, GetLifeTime, _ZTV15CEventEscalator, 4, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventEscalator, Clone, _ZTV15CEventEscalator, 5, CEvent*)
    DECL_VIRTUALCALL_TAIL()

    // Construct/Deconstruct functions
    CEventEscalator() = delete;
    DECL_DTORCALL_VIRTUAL_VTABLE(CEventEscalator, _ZN15CEventEscalator, _ZTV15CEventEscalator);
    DECL_THISCALL_SIMPLE(Delete, _ZN15CEventEscalatorD0Ev, void);
    DECL_NEWCALL(CEventEscalator, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));
DECL_CLASS_END()
CHECKSIZE(CEventEscalator, 0xC, 0x10);

DECL_CLASS_BASED(CEventPotentialWalkIntoVehicle, CEventEditableResponse)
    DECL_VIRTUALCALL_CONST_HEAD(CEventPotentialWalkIntoVehicle, GetEventType, _ZTV30CEventPotentialWalkIntoVehicle, 2, eEventType)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventPotentialWalkIntoVehicle, GetEventPriority, _ZTV30CEventPotentialWalkIntoVehicle, 3, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventPotentialWalkIntoVehicle, GetLifeTime, _ZTV30CEventPotentialWalkIntoVehicle, 4, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventPotentialWalkIntoVehicle, CloneEditable, _ZTV30CEventPotentialWalkIntoVehicle, 17, CEvent*)
    DECL_VIRTUALCALL_TAIL()

    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CEventPotentialWalkIntoVehicle, _ZN30CEventPotentialWalkIntoVehicleC2EP8CVehiclei, CVehicle* pThreatVehicle, int const iMoveState)
    DECL_CTORCALL_ARG_TAIL(pThreatVehicle, iMoveState)
    DECL_DTORCALL_VIRTUAL(CEventPotentialWalkIntoVehicle, _ZN30CEventPotentialWalkIntoVehicleD2Ev, _ZN30CEventPotentialWalkIntoVehicle, _ZTV30CEventPotentialWalkIntoVehicle);
    DECL_NEWCALL(CEventPotentialWalkIntoVehicle, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // Member values
    CVehicle* m_pThreatVehicle;
    int m_iMoveState;
DECL_CLASS_END()
CHECKSIZE(CEventPotentialWalkIntoVehicle, 0x18, 0x28);

DECL_CLASS_BASED(CEventSpecial, CEventEditableResponse)
    DECL_VIRTUALCALL_CONST_HEAD(CEventSpecial, GetEventType, _ZTV13CEventSpecial, 2, eEventType)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventSpecial, GetEventPriority, _ZTV13CEventSpecial, 3, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventSpecial, GetLifeTime, _ZTV13CEventSpecial, 4, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventSpecial, CloneEditable, _ZTV13CEventSpecial, 17, CEvent*)
    DECL_VIRTUALCALL_TAIL()

    // Construct/Deconstruct functions
    DECL_CTORCALL(CEventSpecial, _ZN13CEventSpecialC2Ev);
    DECL_DTORCALL_VIRTUAL(CEventSpecial, _ZN13CEventSpecialD2Ev, _ZN13CEventSpecial, _ZTV13CEventSpecial);
    DECL_NEWCALL(CEventSpecial, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));
DECL_CLASS_END()
CHECKSIZE(CEventSpecial, 0x10, 0x18);

DECL_CLASS_BASED(CEventPotentialWalkIntoObject, CEventEditableResponse)
    DECL_VIRTUALCALL_CONST_HEAD(CEventPotentialWalkIntoObject, GetEventType, _ZTV29CEventPotentialWalkIntoObject, 2, eEventType)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventPotentialWalkIntoObject, GetEventPriority, _ZTV29CEventPotentialWalkIntoObject, 3, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventPotentialWalkIntoObject, GetLifeTime, _ZTV29CEventPotentialWalkIntoObject, 4, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventPotentialWalkIntoObject, CloneEditable, _ZTV29CEventPotentialWalkIntoObject, 17, CEvent*)
    DECL_VIRTUALCALL_TAIL()

    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CEventPotentialWalkIntoObject, _ZN29CEventPotentialWalkIntoObjectC2EP7CObjecti, CObject* pObject, int const iMoveState)
    DECL_CTORCALL_ARG_TAIL(pObject, iMoveState)
    DECL_DTORCALL_VIRTUAL(CEventPotentialWalkIntoObject, _ZN29CEventPotentialWalkIntoObjectD2Ev, _ZN29CEventPotentialWalkIntoObject, _ZTV29CEventPotentialWalkIntoObject);
    DECL_NEWCALL(CEventPotentialWalkIntoObject, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // Member values
    CObject* m_pObject;
    int m_iMoveState;
DECL_CLASS_END()
CHECKSIZE(CEventPotentialWalkIntoObject, 0x18, 0x28);

DECL_CLASS_BASED(CEventPedEnteredMyVehicle, CEventEditableResponse)
    DECL_VIRTUALCALL_CONST_HEAD(CEventPedEnteredMyVehicle, GetEventType, _ZTV25CEventPedEnteredMyVehicle, 2, eEventType)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventPedEnteredMyVehicle, GetEventPriority, _ZTV25CEventPedEnteredMyVehicle, 3, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventPedEnteredMyVehicle, GetLifeTime, _ZTV25CEventPedEnteredMyVehicle, 4, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventPedEnteredMyVehicle, CloneEditable, _ZTV25CEventPedEnteredMyVehicle, 17, CEvent*)
    DECL_VIRTUALCALL_TAIL()

    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CEventPedEnteredMyVehicle, _ZN25CEventPedEnteredMyVehicleC2EPK4CPedPK8CVehiclei, CPed const* pPedThatEnteredVehicle, CVehicle const* pVehicle, int const iTargetDoor)
    DECL_CTORCALL_ARG_TAIL(pPedThatEnteredVehicle, pVehicle, iTargetDoor)
    DECL_DTORCALL_VIRTUAL(CEventPedEnteredMyVehicle, _ZN25CEventPedEnteredMyVehicleD2Ev, _ZN25CEventPedEnteredMyVehicle, _ZTV25CEventPedEnteredMyVehicle);
    DECL_NEWCALL(CEventPedEnteredMyVehicle, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // Member values
    CPed* m_pPedThatEnteredVehicle;
    CVehicle* m_pVehicle;
    int m_iTargetDoor;
DECL_CLASS_END()
CHECKSIZE(CEventPedEnteredMyVehicle, 0x1C, 0x30);

DECL_CLASS_BASED(CEventLeanOnVehicle, CEvent)
    DECL_VIRTUALCALL_CONST_HEAD(CEventLeanOnVehicle, GetEventType, _ZTV19CEventLeanOnVehicle, 2, eEventType)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventLeanOnVehicle, GetEventPriority, _ZTV19CEventLeanOnVehicle, 3, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventLeanOnVehicle, GetLifeTime, _ZTV19CEventLeanOnVehicle, 4, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventLeanOnVehicle, Clone, _ZTV19CEventLeanOnVehicle, 5, CEvent*)
    DECL_VIRTUALCALL_TAIL()

    // Construct/Deconstruct functions
    CEventLeanOnVehicle() = delete;
    DECL_DTORCALL_VIRTUAL(CEventLeanOnVehicle, _ZN19CEventLeanOnVehicleD2Ev, _ZN19CEventLeanOnVehicle, _ZTV19CEventLeanOnVehicle);
    DECL_NEWCALL(CEventLeanOnVehicle, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // Member values
    CVehicle* m_pVehicle;
    i32 m_time;
DECL_CLASS_END()
CHECKSIZE(CEventLeanOnVehicle, 0x14, 0x20);

DECL_CLASS_BASED(CEventHighAngerAtPlayer, CEventEditableResponse)
    DECL_VIRTUALCALL_CONST_HEAD(CEventHighAngerAtPlayer, GetEventType, _ZTV23CEventHighAngerAtPlayer, 2, eEventType)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventHighAngerAtPlayer, GetEventPriority, _ZTV23CEventHighAngerAtPlayer, 3, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventHighAngerAtPlayer, GetLifeTime, _ZTV23CEventHighAngerAtPlayer, 4, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventHighAngerAtPlayer, CloneEditable, _ZTV23CEventHighAngerAtPlayer, 17, CEvent*)
    DECL_VIRTUALCALL_TAIL()

    // Construct/Deconstruct functions
    CEventHighAngerAtPlayer() = delete;
    DECL_DTORCALL_VIRTUAL_VTABLE(CEventHighAngerAtPlayer, _ZN23CEventHighAngerAtPlayer, _ZTV23CEventHighAngerAtPlayer);
    DECL_THISCALL_SIMPLE(Delete, _ZN23CEventHighAngerAtPlayerD0Ev, void);
    DECL_NEWCALL(CEventHighAngerAtPlayer, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));
DECL_CLASS_END()
CHECKSIZE(CEventHighAngerAtPlayer, 0x10, 0x18);

DECL_CLASS_BASED(CEventHitByWaterCannon, CEvent)
    DECL_VIRTUALCALL_CONST_HEAD(CEventHitByWaterCannon, GetEventType, _ZTV22CEventHitByWaterCannon, 2, eEventType)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventHitByWaterCannon, GetEventPriority, _ZTV22CEventHitByWaterCannon, 3, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventHitByWaterCannon, GetLifeTime, _ZTV22CEventHitByWaterCannon, 4, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventHitByWaterCannon, Clone, _ZTV22CEventHitByWaterCannon, 5, CEvent*)
    DECL_VIRTUALCALL_TAIL()

    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CEventHitByWaterCannon, _ZN22CEventHitByWaterCannonC2ERK7CVectorS2_, CVector const& vPos, CVector const& vVel)
    DECL_CTORCALL_ARG_TAIL(vPos, vVel)
    DECL_DTORCALL_VIRTUAL(CEventHitByWaterCannon, _ZN22CEventHitByWaterCannonD2Ev, _ZN22CEventHitByWaterCannon, _ZTV22CEventHitByWaterCannon);
    DECL_NEWCALL(CEventHitByWaterCannon, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // Member values
    CVector m_vPos;
    CVector m_vVel;
DECL_CLASS_END()
CHECKSIZE(CEventHitByWaterCannon, 0x24, 0x28);

DECL_CLASS_BASED(CEventHealthLow, CEventEditableResponse)
    DECL_VIRTUALCALL_CONST_HEAD(CEventHealthLow, GetEventType, _ZTV15CEventHealthLow, 2, eEventType)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventHealthLow, GetEventPriority, _ZTV15CEventHealthLow, 3, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventHealthLow, GetLifeTime, _ZTV15CEventHealthLow, 4, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventHealthLow, CloneEditable, _ZTV15CEventHealthLow, 17, CEvent*)
    DECL_VIRTUALCALL_TAIL()

    // Construct/Deconstruct functions
    CEventHealthLow() = delete;
    DECL_DTORCALL_VIRTUAL_VTABLE(CEventHealthLow, _ZN15CEventHealthLow, _ZTV15CEventHealthLow);
    DECL_THISCALL_SIMPLE(Delete, _ZN15CEventHealthLowD0Ev, void);
    DECL_NEWCALL(CEventHealthLow, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));
DECL_CLASS_END()
CHECKSIZE(CEventHealthLow, 0x10, 0x18);

DECL_CLASS_BASED(CEventCarUpsideDown, CEvent)
    DECL_VIRTUALCALL_CONST_HEAD(CEventCarUpsideDown, GetEventType, _ZTV19CEventCarUpsideDown, 2, eEventType)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventCarUpsideDown, GetEventPriority, _ZTV19CEventCarUpsideDown, 3, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventCarUpsideDown, GetLifeTime, _ZTV19CEventCarUpsideDown, 4, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventCarUpsideDown, Clone, _ZTV19CEventCarUpsideDown, 5, CEvent*)
    DECL_VIRTUALCALL_TAIL()

    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CEventCarUpsideDown, _ZN19CEventCarUpsideDownC2EP8CVehicle, CVehicle* pVehicle)
    DECL_CTORCALL_ARG_TAIL(pVehicle)
    DECL_DTORCALL_VIRTUAL(CEventCarUpsideDown, _ZN19CEventCarUpsideDownD2Ev, _ZN19CEventCarUpsideDown, _ZTV19CEventCarUpsideDown);
    DECL_NEWCALL(CEventCarUpsideDown, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // Member values
    CVehicle* m_pVehicle;
DECL_CLASS_END()
CHECKSIZE(CEventCarUpsideDown, 0x10, 0x18);

DECL_CLASS_BASED(CEventChatPartner, CEvent)
    DECL_VIRTUALCALL_CONST_HEAD(CEventChatPartner, GetEventType, _ZTV17CEventChatPartner, 2, eEventType)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventChatPartner, GetEventPriority, _ZTV17CEventChatPartner, 3, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventChatPartner, GetLifeTime, _ZTV17CEventChatPartner, 4, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventChatPartner, Clone, _ZTV17CEventChatPartner, 5, CEvent*)
    DECL_VIRTUALCALL_TAIL()

    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CEventChatPartner, _ZN17CEventChatPartnerC2EbP4CPed, bool const bIsLeader, CPed* pOtherPed)
    DECL_CTORCALL_ARG_TAIL(bIsLeader, pOtherPed)
    DECL_DTORCALL_VIRTUAL(CEventChatPartner, _ZN17CEventChatPartnerD2Ev, _ZN17CEventChatPartner, _ZTV17CEventChatPartner);
    DECL_NEWCALL(CEventChatPartner, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // Member values
    bool m_bIsLeader;
    CPed* m_pOtherPed;
DECL_CLASS_END()
CHECKSIZE(CEventChatPartner, 0x10, 0x18);

DECL_CLASS_BASED(CEventSexyVehicle, CEvent)
    DECL_VIRTUALCALL_CONST_HEAD(CEventSexyVehicle, GetEventType, _ZTV17CEventSexyVehicle, 2, eEventType)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventSexyVehicle, GetEventPriority, _ZTV17CEventSexyVehicle, 3, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventSexyVehicle, GetLifeTime, _ZTV17CEventSexyVehicle, 4, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventSexyVehicle, Clone, _ZTV17CEventSexyVehicle, 5, CEvent*)
    DECL_VIRTUALCALL_TAIL()

    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CEventSexyVehicle, _ZN17CEventSexyVehicleC2EP8CVehicle, CVehicle* pSexyVehicle)
    DECL_CTORCALL_ARG_TAIL(pSexyVehicle)
    DECL_DTORCALL_VIRTUAL(CEventSexyVehicle, _ZN17CEventSexyVehicleD2Ev, _ZN17CEventSexyVehicle, _ZTV17CEventSexyVehicle);
    DECL_NEWCALL(CEventSexyVehicle, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // Member values
    CVehicle* m_pSexyVehicle;
DECL_CLASS_END()
CHECKSIZE(CEventSexyVehicle, 0x10, 0x18);

DECL_CLASS_BASED(CEventPassObject, CEvent)
    DECL_VIRTUALCALL_CONST_HEAD(CEventPassObject, GetEventType, _ZTV16CEventPassObject, 2, eEventType)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventPassObject, GetEventPriority, _ZTV16CEventPassObject, 3, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventPassObject, GetLifeTime, _ZTV16CEventPassObject, 4, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventPassObject, Clone, _ZTV16CEventPassObject, 5, CEvent*)
    DECL_VIRTUALCALL_TAIL()

    // Construct/Deconstruct functions
    CEventPassObject() = delete;
    DECL_DTORCALL_VIRTUAL(CEventPassObject, _ZN16CEventPassObjectD2Ev, _ZN16CEventPassObject, _ZTV16CEventPassObject);
    DECL_NEWCALL(CEventPassObject, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // Member values
    CPed* m_pPed;
    u8 m_isPasser;
DECL_CLASS_END()
CHECKSIZE(CEventPassObject, 0x14, 0x20);

DECL_CLASS_BASED(CEventPotentialWalkIntoPed, CEventEditableResponse)
    DECL_VIRTUALCALL_CONST_HEAD(CEventPotentialWalkIntoPed, GetEventType, _ZTV26CEventPotentialWalkIntoPed, 2, eEventType)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventPotentialWalkIntoPed, GetEventPriority, _ZTV26CEventPotentialWalkIntoPed, 3, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventPotentialWalkIntoPed, GetLifeTime, _ZTV26CEventPotentialWalkIntoPed, 4, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventPotentialWalkIntoPed, CloneEditable, _ZTV26CEventPotentialWalkIntoPed, 17, CEvent*)
    DECL_VIRTUALCALL_TAIL()

    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CEventPotentialWalkIntoPed, _ZN26CEventPotentialWalkIntoPedC2EP4CPedRK7CVectori, CPed* pOtherPed, CVector const& vTarget, int const iMoveState)
    DECL_CTORCALL_ARG_TAIL(pOtherPed, vTarget, iMoveState)
    DECL_DTORCALL_VIRTUAL(CEventPotentialWalkIntoPed, _ZN26CEventPotentialWalkIntoPedD2Ev, _ZN26CEventPotentialWalkIntoPed, _ZTV26CEventPotentialWalkIntoPed);
    DECL_NEWCALL(CEventPotentialWalkIntoPed, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // Member values
    CVector m_vTarget;
    CPed* m_pOtherPed;
    int m_iMoveState;
DECL_CLASS_END()
CHECKSIZE(CEventPotentialWalkIntoPed, 0x24, 0x30);

DECL_CLASS_BASED(CEventFireNearby, CEventEditableResponse)
    DECL_VIRTUALCALL_CONST_HEAD(CEventFireNearby, GetEventType, _ZTV16CEventFireNearby, 2, eEventType)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventFireNearby, GetEventPriority, _ZTV16CEventFireNearby, 3, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventFireNearby, GetLifeTime, _ZTV16CEventFireNearby, 4, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventFireNearby, CloneEditable, _ZTV16CEventFireNearby, 17, CEvent*)
    DECL_VIRTUALCALL_TAIL()

    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CEventFireNearby, _ZN16CEventFireNearbyC2ERK7CVector, CVector const& vFirePos)
    DECL_CTORCALL_ARG_TAIL(vFirePos)
    DECL_DTORCALL_VIRTUAL(CEventFireNearby, _ZN16CEventFireNearbyD2Ev, _ZN16CEventFireNearby, _ZTV16CEventFireNearby);
    DECL_NEWCALL(CEventFireNearby, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // Member values
    CVector m_vFirePos;
DECL_CLASS_END()
CHECKSIZE(CEventFireNearby, 0x1C, 0x20);

DECL_CLASS_BASED(CEventInteriorUseInfo, CEvent)
    DECL_VIRTUALCALL_CONST_HEAD(CEventInteriorUseInfo, GetEventType, _ZTV21CEventInteriorUseInfo, 2, eEventType)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventInteriorUseInfo, GetEventPriority, _ZTV21CEventInteriorUseInfo, 3, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventInteriorUseInfo, GetLifeTime, _ZTV21CEventInteriorUseInfo, 4, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventInteriorUseInfo, Clone, _ZTV21CEventInteriorUseInfo, 5, CEvent*)
    DECL_VIRTUALCALL_TAIL()

    // Construct/Deconstruct functions
    CEventInteriorUseInfo() = delete;
    DECL_DTORCALL_VIRTUAL_VTABLE(CEventInteriorUseInfo, _ZN21CEventInteriorUseInfo, _ZTV21CEventInteriorUseInfo);
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
    DECL_VIRTUALCALL_CONST_HEAD(CEventAcquaintancePedHateBadlyLit, GetEventType, _ZTV33CEventAcquaintancePedHateBadlyLit, 2, eEventType)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventAcquaintancePedHateBadlyLit, GetEventPriority, _ZTV33CEventAcquaintancePedHateBadlyLit, 3, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventAcquaintancePedHateBadlyLit, CloneEditable, _ZTV33CEventAcquaintancePedHateBadlyLit, 17, CEvent*)
    DECL_VIRTUALCALL_TAIL()

    // Construct/Deconstruct functions
    CEventAcquaintancePedHateBadlyLit() = delete;
    DECL_DTORCALL_VIRTUAL_VTABLE(CEventAcquaintancePedHateBadlyLit, _ZN33CEventAcquaintancePedHateBadlyLit, _ZTV33CEventAcquaintancePedHateBadlyLit);
    DECL_THISCALL_SIMPLE(Delete, _ZN33CEventAcquaintancePedHateBadlyLitD0Ev, void);
    DECL_NEWCALL(CEventAcquaintancePedHateBadlyLit, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // Member values
    int m_iTimeSpotted;
    CVector m_vTargetPosAtSpotTime;
DECL_CLASS_END()
CHECKSIZE(CEventAcquaintancePedHateBadlyLit, 0x24, 0x30);

DECL_CLASS_BASED(CEventSeenPanickedPed, CEventEditableResponse)
    DECL_VIRTUALCALL_CONST_HEAD(CEventSeenPanickedPed, GetEventType, _ZTV21CEventSeenPanickedPed, 2, eEventType)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventSeenPanickedPed, GetEventPriority, _ZTV21CEventSeenPanickedPed, 3, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventSeenPanickedPed, GetLifeTime, _ZTV21CEventSeenPanickedPed, 4, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventSeenPanickedPed, CloneEditable, _ZTV21CEventSeenPanickedPed, 17, CEvent*)
    DECL_VIRTUALCALL_TAIL()

    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CEventSeenPanickedPed, _ZN21CEventSeenPanickedPedC2EP4CPed, CPed* pPanickedPed)
    DECL_CTORCALL_ARG_TAIL(pPanickedPed)
    DECL_DTORCALL_VIRTUAL(CEventSeenPanickedPed, _ZN21CEventSeenPanickedPedD2Ev, _ZN21CEventSeenPanickedPed, _ZTV21CEventSeenPanickedPed);
    DECL_NEWCALL(CEventSeenPanickedPed, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // Member values
    CPed* m_pPanickedPed;
DECL_CLASS_END()
CHECKSIZE(CEventSeenPanickedPed, 0x14, 0x20);

DECL_CLASS_BASED(CEventPedToChase, CEvent)
    DECL_VIRTUALCALL_CONST_HEAD(CEventPedToChase, GetEventType, _ZTV16CEventPedToChase, 2, eEventType)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventPedToChase, GetEventPriority, _ZTV16CEventPedToChase, 3, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventPedToChase, GetLifeTime, _ZTV16CEventPedToChase, 4, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventPedToChase, Clone, _ZTV16CEventPedToChase, 5, CEvent*)
    DECL_VIRTUALCALL_TAIL()

    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CEventPedToChase, _ZN16CEventPedToChaseC2EP4CPed, CPed* pPedToChase)
    DECL_CTORCALL_ARG_TAIL(pPedToChase)
    DECL_DTORCALL_VIRTUAL(CEventPedToChase, _ZN16CEventPedToChaseD2Ev, _ZN16CEventPedToChase, _ZTV16CEventPedToChase);
    DECL_NEWCALL(CEventPedToChase, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // Member values
    CPed* m_pPedToChase;
DECL_CLASS_END()
CHECKSIZE(CEventPedToChase, 0x10, 0x18);

DECL_CLASS_BASED(CEventVehicleCollision, CEvent)
    DECL_VIRTUALCALL_CONST_HEAD(CEventVehicleCollision, GetEventType, _ZTV22CEventVehicleCollision, 2, eEventType)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventVehicleCollision, GetEventPriority, _ZTV22CEventVehicleCollision, 3, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventVehicleCollision, GetLifeTime, _ZTV22CEventVehicleCollision, 4, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventVehicleCollision, Clone, _ZTV22CEventVehicleCollision, 5, CEvent*)
    DECL_VIRTUALCALL_TAIL()

    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CEventVehicleCollision, _ZN22CEventVehicleCollisionC2EtfPK8CVehicleRK7CVectorS5_it, u16 const nPieceType, float const fImpulseMagnitude, CVehicle const* pVehicle, CVector const& vNormal, CVector const& vPos, int const iMoveState, u16 nForceReaction)
    DECL_CTORCALL_ARG_TAIL(nPieceType, fImpulseMagnitude, pVehicle, vNormal, vPos, iMoveState, nForceReaction)
    DECL_DTORCALL_VIRTUAL(CEventVehicleCollision, _ZN22CEventVehicleCollisionD2Ev, _ZN22CEventVehicleCollision, _ZTV22CEventVehicleCollision);
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
    DECL_VIRTUALCALL_CONST_HEAD(CEventInAir, GetEventType, _ZTV11CEventInAir, 2, eEventType)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventInAir, GetEventPriority, _ZTV11CEventInAir, 3, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventInAir, GetLifeTime, _ZTV11CEventInAir, 4, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventInAir, Clone, _ZTV11CEventInAir, 5, CEvent*)
    DECL_VIRTUALCALL_TAIL()

    // Construct/Deconstruct functions
    DECL_CTORCALL(CEventInAir, _ZN11CEventInAirC2Ev);
    DECL_DTORCALL_VIRTUAL(CEventInAir, _ZN11CEventInAirD2Ev, _ZN11CEventInAir, _ZTV11CEventInAir);
    DECL_NEWCALL(CEventInAir, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));
DECL_CLASS_END()
CHECKSIZE(CEventInAir, 0xC, 0x10);

DECL_CLASS_BASED(CEventInWater, CEvent)
    DECL_VIRTUALCALL_CONST_HEAD(CEventInWater, GetEventType, _ZTV13CEventInWater, 2, eEventType)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventInWater, GetEventPriority, _ZTV13CEventInWater, 3, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventInWater, GetLifeTime, _ZTV13CEventInWater, 4, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventInWater, Clone, _ZTV13CEventInWater, 5, CEvent*)
    DECL_VIRTUALCALL_TAIL()

    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CEventInWater, _ZN13CEventInWaterC2Ef, float fBuoyancyFraction)
    DECL_CTORCALL_ARG_TAIL(fBuoyancyFraction)
    DECL_DTORCALL_VIRTUAL(CEventInWater, _ZN13CEventInWaterD2Ev, _ZN13CEventInWater, _ZTV13CEventInWater);
    DECL_NEWCALL(CEventInWater, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // Member values
    float m_fBuoyancyFraction;
DECL_CLASS_END()
CHECKSIZE(CEventInWater, 0x10, 0x18);

DECL_CLASS_BASED(CEventCreatePartnerTask, CEvent)
    DECL_VIRTUALCALL_CONST_HEAD(CEventCreatePartnerTask, GetEventType, _ZTV23CEventCreatePartnerTask, 2, eEventType)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventCreatePartnerTask, GetEventPriority, _ZTV23CEventCreatePartnerTask, 3, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventCreatePartnerTask, GetLifeTime, _ZTV23CEventCreatePartnerTask, 4, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventCreatePartnerTask, Clone, _ZTV23CEventCreatePartnerTask, 5, CEvent*)
    DECL_VIRTUALCALL_TAIL()

    // Construct/Deconstruct functions
    CEventCreatePartnerTask() = delete;
    DECL_DTORCALL_VIRTUAL(CEventCreatePartnerTask, _ZN23CEventCreatePartnerTaskD2Ev, _ZN23CEventCreatePartnerTask, _ZTV23CEventCreatePartnerTask);
    DECL_NEWCALL(CEventCreatePartnerTask, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // Member values
    i32 m_type;
    CPed* m_pPartner;
    u8 m_isLeader;
    float m_meetDist;
DECL_CLASS_END()
CHECKSIZE(CEventCreatePartnerTask, 0x1C, 0x28);

DECL_CLASS_BASED(CEventNewGangMember, CEvent)
    DECL_VIRTUALCALL_CONST_HEAD(CEventNewGangMember, GetEventType, _ZTV19CEventNewGangMember, 2, eEventType)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventNewGangMember, GetEventPriority, _ZTV19CEventNewGangMember, 3, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventNewGangMember, GetLifeTime, _ZTV19CEventNewGangMember, 4, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventNewGangMember, Clone, _ZTV19CEventNewGangMember, 5, CEvent*)
    DECL_VIRTUALCALL_TAIL()

    // Construct/Deconstruct functions
    CEventNewGangMember() = delete;
    DECL_DTORCALL_VIRTUAL(CEventNewGangMember, _ZN19CEventNewGangMemberD2Ev, _ZN19CEventNewGangMember, _ZTV19CEventNewGangMember);
    DECL_NEWCALL(CEventNewGangMember, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // Member values
    CPed* m_pPed;
DECL_CLASS_END()
CHECKSIZE(CEventNewGangMember, 0x10, 0x18);

DECL_CLASS_BASED(CEventScriptedAttractor, CEventAttractor)
    // Construct/Deconstruct functions
    CEventScriptedAttractor() = delete;
    DECL_DTORCALL_VIRTUAL_VTABLE(CEventScriptedAttractor, _ZN23CEventScriptedAttractor, _ZTV23CEventScriptedAttractor);
    DECL_THISCALL_SIMPLE(Delete, _ZN23CEventScriptedAttractorD0Ev, void);
    DECL_NEWCALL(CEventScriptedAttractor, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));
DECL_CLASS_END()
CHECKSIZE(CEventScriptedAttractor, 0x1C, 0x30);

DECL_CLASS_BASED(CEventAcquaintancePedRespect, CEventAcquaintancePed)
    DECL_VIRTUALCALL_CONST_HEAD(CEventAcquaintancePedRespect, GetEventType, _ZTV28CEventAcquaintancePedRespect, 2, eEventType)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventAcquaintancePedRespect, GetEventPriority, _ZTV28CEventAcquaintancePedRespect, 3, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventAcquaintancePedRespect, CloneEditable, _ZTV28CEventAcquaintancePedRespect, 17, CEvent*)
    DECL_VIRTUALCALL_TAIL()

    // Construct/Deconstruct functions
    CEventAcquaintancePedRespect() = delete;
    DECL_DTORCALL_VIRTUAL_VTABLE(CEventAcquaintancePedRespect, _ZN28CEventAcquaintancePedRespect, _ZTV28CEventAcquaintancePedRespect);
    DECL_THISCALL_SIMPLE(Delete, _ZN28CEventAcquaintancePedRespectD0Ev, void);
    DECL_NEWCALL(CEventAcquaintancePedRespect, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));
DECL_CLASS_END()
CHECKSIZE(CEventAcquaintancePedRespect, 0x14, 0x20);

DECL_CLASS_BASED(CEventPlayerCollisionWithPed, CEventPedCollisionWithPed)
    // Construct/Deconstruct functions
    CEventPlayerCollisionWithPed() = delete;
    DECL_DTORCALL_VIRTUAL_VTABLE(CEventPlayerCollisionWithPed, _ZN28CEventPlayerCollisionWithPed, _ZTV28CEventPlayerCollisionWithPed);
    DECL_THISCALL_SIMPLE(Delete, _ZN28CEventPlayerCollisionWithPedD0Ev, void);
    DECL_NEWCALL(CEventPlayerCollisionWithPed, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));
DECL_CLASS_END()
CHECKSIZE(CEventPlayerCollisionWithPed, 0x30, 0x40);

DECL_CLASS_BASED(CEventAcquaintancePedDislike, CEventAcquaintancePed)
    DECL_VIRTUALCALL_CONST_HEAD(CEventAcquaintancePedDislike, GetEventType, _ZTV28CEventAcquaintancePedDislike, 2, eEventType)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventAcquaintancePedDislike, GetEventPriority, _ZTV28CEventAcquaintancePedDislike, 3, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventAcquaintancePedDislike, CloneEditable, _ZTV28CEventAcquaintancePedDislike, 17, CEvent*)
    DECL_VIRTUALCALL_TAIL()

    // Construct/Deconstruct functions
    CEventAcquaintancePedDislike() = delete;
    DECL_DTORCALL_VIRTUAL_VTABLE(CEventAcquaintancePedDislike, _ZN28CEventAcquaintancePedDislike, _ZTV28CEventAcquaintancePedDislike);
    DECL_THISCALL_SIMPLE(Delete, _ZN28CEventAcquaintancePedDislikeD0Ev, void);
    DECL_NEWCALL(CEventAcquaintancePedDislike, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));
DECL_CLASS_END()
CHECKSIZE(CEventAcquaintancePedDislike, 0x14, 0x20);

DECL_CLASS_BASED(CEventPedCollisionWithPlayer, CEventPedCollisionWithPed)
    // Construct/Deconstruct functions
    CEventPedCollisionWithPlayer() = delete;
    DECL_DTORCALL_VIRTUAL_VTABLE(CEventPedCollisionWithPlayer, _ZN28CEventPedCollisionWithPlayer, _ZTV28CEventPedCollisionWithPlayer);
    DECL_THISCALL_SIMPLE(Delete, _ZN28CEventPedCollisionWithPlayerD0Ev, void);
    DECL_NEWCALL(CEventPedCollisionWithPlayer, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));
DECL_CLASS_END()
CHECKSIZE(CEventPedCollisionWithPlayer, 0x30, 0x40);

DECL_CLASS_BASED(CEventAcquaintancePedLike, CEventAcquaintancePed)
    DECL_VIRTUALCALL_CONST_HEAD(CEventAcquaintancePedLike, GetEventType, _ZTV25CEventAcquaintancePedLike, 2, eEventType)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventAcquaintancePedLike, GetEventPriority, _ZTV25CEventAcquaintancePedLike, 3, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventAcquaintancePedLike, CloneEditable, _ZTV25CEventAcquaintancePedLike, 17, CEvent*)
    DECL_VIRTUALCALL_TAIL()

    // Construct/Deconstruct functions
    CEventAcquaintancePedLike() = delete;
    DECL_DTORCALL_VIRTUAL_VTABLE(CEventAcquaintancePedLike, _ZN25CEventAcquaintancePedLike, _ZTV25CEventAcquaintancePedLike);
    DECL_THISCALL_SIMPLE(Delete, _ZN25CEventAcquaintancePedLikeD0Ev, void);
    DECL_NEWCALL(CEventAcquaintancePedLike, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));
DECL_CLASS_END()
CHECKSIZE(CEventAcquaintancePedLike, 0x14, 0x20);

DECL_CLASS_BASED(CEventDontJoinPlayerGroup, CEvent)
    DECL_VIRTUALCALL_CONST_HEAD(CEventDontJoinPlayerGroup, GetEventType, _ZTV25CEventDontJoinPlayerGroup, 2, eEventType)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventDontJoinPlayerGroup, GetEventPriority, _ZTV25CEventDontJoinPlayerGroup, 3, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventDontJoinPlayerGroup, GetLifeTime, _ZTV25CEventDontJoinPlayerGroup, 4, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventDontJoinPlayerGroup, Clone, _ZTV25CEventDontJoinPlayerGroup, 5, CEvent*)
    DECL_VIRTUALCALL_TAIL()

    // Construct/Deconstruct functions
    CEventDontJoinPlayerGroup() = delete;
    DECL_DTORCALL_VIRTUAL(CEventDontJoinPlayerGroup, _ZN25CEventDontJoinPlayerGroupD2Ev, _ZN25CEventDontJoinPlayerGroup, _ZTV25CEventDontJoinPlayerGroup);
    DECL_NEWCALL(CEventDontJoinPlayerGroup, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));

    // Member values
    CPed* m_pPed;
DECL_CLASS_END()
CHECKSIZE(CEventDontJoinPlayerGroup, 0x10, 0x18);

DECL_CLASS_BASED(CEventPlayerCommandToGroupGather, CEventPlayerCommandToGroup)
    DECL_VIRTUALCALL_CONST_HEAD(CEventPlayerCommandToGroupGather, GetEventType, _ZTV32CEventPlayerCommandToGroupGather, 2, eEventType)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventPlayerCommandToGroupGather, GetEventPriority, _ZTV32CEventPlayerCommandToGroupGather, 3, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventPlayerCommandToGroupGather, CloneEditable, _ZTV32CEventPlayerCommandToGroupGather, 17, CEvent*)
    DECL_VIRTUALCALL_TAIL()

    // Construct/Deconstruct functions
    CEventPlayerCommandToGroupGather() = delete;
    DECL_DTORCALL_VIRTUAL_VTABLE(CEventPlayerCommandToGroupGather, _ZN32CEventPlayerCommandToGroupGather, _ZTV32CEventPlayerCommandToGroupGather);
    DECL_THISCALL_SIMPLE(Delete, _ZN32CEventPlayerCommandToGroupGatherD0Ev, void);
    DECL_NEWCALL(CEventPlayerCommandToGroupGather, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));
DECL_CLASS_END()
CHECKSIZE(CEventPlayerCommandToGroupGather, 0x18, 0x20);

DECL_CLASS_BASED(CEventVehicleDamageWeapon, CEventVehicleDamage)
    DECL_VIRTUALCALL_CONST_HEAD(CEventVehicleDamageWeapon, GetEventType, _ZTV25CEventVehicleDamageWeapon, 2, eEventType)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventVehicleDamageWeapon, CloneEditable, _ZTV25CEventVehicleDamageWeapon, 17, CEvent*)
    DECL_VIRTUALCALL_TAIL()

    // Construct/Deconstruct functions
    CEventVehicleDamageWeapon() = delete;
    DECL_DTORCALL_VIRTUAL_VTABLE(CEventVehicleDamageWeapon, _ZN25CEventVehicleDamageWeapon, _ZTV25CEventVehicleDamageWeapon);
    DECL_THISCALL_SIMPLE(Delete, _ZN25CEventVehicleDamageWeaponD0Ev, void);
    DECL_NEWCALL(CEventVehicleDamageWeapon, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));
DECL_CLASS_END()
CHECKSIZE(CEventVehicleDamageWeapon, 0x1C, 0x30);

DECL_CLASS_BASED(CEventVehicleDamageCollision, CEventVehicleDamage)
    DECL_VIRTUALCALL_CONST_HEAD(CEventVehicleDamageCollision, GetEventType, _ZTV28CEventVehicleDamageCollision, 2, eEventType)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CEventVehicleDamageCollision, CloneEditable, _ZTV28CEventVehicleDamageCollision, 17, CEvent*)
    DECL_VIRTUALCALL_TAIL()

    // Construct/Deconstruct functions
    CEventVehicleDamageCollision() = delete;
    DECL_DTORCALL_VIRTUAL_VTABLE(CEventVehicleDamageCollision, _ZN28CEventVehicleDamageCollision, _ZTV28CEventVehicleDamageCollision);
    DECL_THISCALL_SIMPLE(Delete, _ZN28CEventVehicleDamageCollisionD0Ev, void);
    DECL_NEWCALL(CEventVehicleDamageCollision, BYBIT(_ZN6CEventnwEj, _ZN6CEventnwEm));
DECL_CLASS_END()
CHECKSIZE(CEventVehicleDamageCollision, 0x1C, 0x30);

#endif // __AML_PSDK_SAEVENTTYPES_H
