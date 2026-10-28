#ifndef __AML_PSDK_VCPLAYERPED_H
#define __AML_PSDK_VCPLAYERPED_H

#include "Ped.h"

struct CWanted;
struct CCopPed;
struct CPad;
struct CPlayerInfo;

DECL_CLASS_BASED(CPlayerPed, CPed)
    // Construct/Deconstruct functions
    DECL_CTORCALL(CPlayerPed, _ZN10CPlayerPedC2Ev);
    DECL_DTORCALL_VIRTUAL_SLOT(CPlayerPed, _ZN10CPlayerPedD2Ev, _ZN10CPlayerPed, _ZTV10CPlayerPed, 2);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(CPlayerPed, ProcessControl, _ZTV10CPlayerPed, 9, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CPlayerPed, SetMoveAnim, _ZTV10CPlayerPed, 19, void)
    DECL_VIRTUALCALL_TAIL()

    // STATIC functions
    DECL_FASTCALL_SIMPLE(SetupPlayerPed, _ZN10CPlayerPed14SetupPlayerPedEi, void, i32 playerId);
    DECL_FASTCALL_SIMPLE(RemovePlayerPed, _ZN10CPlayerPed15RemovePlayerPedEi, void, i32 playerId);
    DECL_FASTCALL_SIMPLE(DeactivatePlayerPed, _ZN10CPlayerPed19DeactivatePlayerPedEi, void, i32 playerId);
    DECL_FASTCALL_SIMPLE(ReactivatePlayerPed, _ZN10CPlayerPed19ReactivatePlayerPedEi, void, i32 playerId);

    // STATIC values
    DECL_VALUE_PLT_BOOL(bDontAllowWeaponChange, BYBIT(0x3949D4, 0x577490));

    // Member functions
    DECL_THISCALL_SIMPLE(SetInitialState, _ZN10CPlayerPed15SetInitialStateEv, void);
    DECL_THISCALL_SIMPLE(SetRealMoveAnim, _ZN10CPlayerPed15SetRealMoveAnimEv, void);
    DECL_THISCALL_SIMPLE(ReApplyMoveAnims, _ZN10CPlayerPed16ReApplyMoveAnimsEv, void);
    DECL_THISCALL_HEAD(SetWantedLevel, _ZN10CPlayerPed14SetWantedLevelEi, void, i32 level)
    DECL_THISCALL_TAIL(SetWantedLevel, level)
    DECL_THISCALL_HEAD(SetWantedLevelNoDrop, _ZN10CPlayerPed20SetWantedLevelNoDropEi, void, i32 level)
    DECL_THISCALL_TAIL(SetWantedLevelNoDrop, level)
    DECL_THISCALL_SIMPLE(Busted, _ZN10CPlayerPed6BustedEv, void);
    DECL_THISCALL_SIMPLE(FindNewAttackPoints, _ZN10CPlayerPed19FindNewAttackPointsEv, void);
    DECL_THISCALL_SIMPLE(UpdateMeleeAttackers, _ZN10CPlayerPed20UpdateMeleeAttackersEv, void);
    DECL_THISCALL_SIMPLE(SetNearbyPedsToInteractWithPlayer, _ZN10CPlayerPed33SetNearbyPedsToInteractWithPlayerEv, void);
    DECL_THISCALL_HEAD(RestoreSprintEnergy, _ZN10CPlayerPed19RestoreSprintEnergyEf, void, float amount)
    DECL_THISCALL_TAIL(RestoreSprintEnergy, amount)
    DECL_THISCALL_SIMPLE(UseSprintEnergy, _ZN10CPlayerPed15UseSprintEnergyEv, void);
    DECL_THISCALL_SIMPLE(ClearWeaponTarget, _ZN10CPlayerPed17ClearWeaponTargetEv, void);
    DECL_THISCALL_HEAD(RunningLand, _ZN10CPlayerPed11RunningLandEP4CPad, void, CPad* pad)
    DECL_THISCALL_TAIL(RunningLand, pad)
    DECL_THISCALL_HEAD(PlayerControlM16, _ZN10CPlayerPed16PlayerControlM16EP4CPad, void, CPad* pad)
    DECL_THISCALL_TAIL(PlayerControlM16, pad)
    DECL_THISCALL_HEAD(PlayerControlSniper, _ZN10CPlayerPed19PlayerControlSniperEP4CPad, void, CPad* pad)
    DECL_THISCALL_TAIL(PlayerControlSniper, pad)
    DECL_THISCALL_HEAD(PlayerControl1stPersonRunAround, _ZN10CPlayerPed31PlayerControl1stPersonRunAroundEP4CPad, void, CPad* pad)
    DECL_THISCALL_TAIL(PlayerControl1stPersonRunAround, pad)
    DECL_THISCALL_HEAD(PlayerControlFighter, _ZN10CPlayerPed20PlayerControlFighterEP4CPad, void, CPad* pad)
    DECL_THISCALL_TAIL(PlayerControlFighter, pad)
    DECL_THISCALL_HEAD(PlayerControlZelda, _ZN10CPlayerPed18PlayerControlZeldaEP4CPad, void, CPad* pad)
    DECL_THISCALL_TAIL(PlayerControlZelda, pad)
    DECL_THISCALL_HEAD(ProcessPlayerWeapon, _ZN10CPlayerPed19ProcessPlayerWeaponEP4CPad, void, CPad* pad)
    DECL_THISCALL_TAIL(ProcessPlayerWeapon, pad)
    DECL_THISCALL_HEAD(ProcessWeaponSwitch, _ZN10CPlayerPed19ProcessWeaponSwitchEP4CPad, void, CPad* pad)
    DECL_THISCALL_TAIL(ProcessWeaponSwitch, pad)
    DECL_THISCALL_SIMPLE(ProcessAnimGroups, _ZN10CPlayerPed17ProcessAnimGroupsEv, void);
    DECL_THISCALL_SIMPLE(DoWeaponSmoothSpray, _ZN10CPlayerPed19DoWeaponSmoothSprayEv, float);
    DECL_THISCALL_SIMPLE(MovementDisabledBecauseOfTargeting, _ZN10CPlayerPed34MovementDisabledBecauseOfTargetingEv, bool);
    DECL_THISCALL_SIMPLE(GetPlayerInfoForThisPlayerPed, _ZN10CPlayerPed29GetPlayerInfoForThisPlayerPedEv, CPlayerInfo*);
    DECL_THISCALL_HEAD(PlayIdleAnimations, _ZN10CPlayerPed18PlayIdleAnimationsEP4CPad, void, CPad* pad)
    DECL_THISCALL_TAIL(PlayIdleAnimations, pad)
    DECL_THISCALL_HEAD(DoesPlayerWantNewWeapon, _ZN10CPlayerPed23DoesPlayerWantNewWeaponE11eWeaponTypeb, bool, eWeaponType type, bool enable)
    DECL_THISCALL_TAIL(DoesPlayerWantNewWeapon, type, enable)
    DECL_THISCALL_SIMPLE(FindWeaponLockOnTarget, _ZN10CPlayerPed22FindWeaponLockOnTargetEv, bool);
    DECL_THISCALL_HEAD(DoesTargetHaveToBeBroken, _ZN10CPlayerPed24DoesTargetHaveToBeBrokenE7CVectorP7CWeapon, bool, CVector position, CWeapon* weapon)
    DECL_THISCALL_TAIL(DoesTargetHaveToBeBroken, position, weapon)
    DECL_THISCALL_SIMPLE(RotatePlayerToTrackTarget, _ZN10CPlayerPed25RotatePlayerToTrackTargetEv, void);
    DECL_THISCALL_HEAD(FindNextWeaponLockOnTarget, _ZN10CPlayerPed26FindNextWeaponLockOnTargetEP7CEntityb, bool, CEntity* target, bool next)
    DECL_THISCALL_TAIL(FindNextWeaponLockOnTarget, target, next)
    DECL_THISCALL_HEAD(UpdateCameraWeaponModes, _ZN10CPlayerPed23UpdateCameraWeaponModesEP4CPad, void, CPad* pad)
    DECL_THISCALL_TAIL(UpdateCameraWeaponModes, pad)
    DECL_THISCALL_HEAD(CanIKReachThisTarget, _ZN10CPlayerPed20CanIKReachThisTargetE7CVectorP7CWeaponb, bool, CVector position, CWeapon* weapon, bool useArm)
    DECL_THISCALL_TAIL(CanIKReachThisTarget, position, weapon, useArm)
    DECL_THISCALL_HEAD(EvaluateTarget, _ZN10CPlayerPed14EvaluateTargetEP7CEntityPS1_Pfffbb, void, CEntity* target, CEntity** bestTarget, float* bestPriority, float maxDistance, float referenceHeading, bool priority, bool preferSimilarHeight)
    DECL_THISCALL_TAIL(EvaluateTarget, target, bestTarget, bestPriority, maxDistance, referenceHeading, priority, preferSimilarHeight)
    DECL_THISCALL_HEAD(IsThisPedAnAimingPriority, _ZN10CPlayerPed25IsThisPedAnAimingPriorityEP4CPed, bool, CPed* ped)
    DECL_THISCALL_TAIL(IsThisPedAnAimingPriority, ped)
    DECL_THISCALL_HEAD(HandleTapToTarget, _ZN10CPlayerPed17HandleTapToTargetEffb, void, float x, float y, bool tapped)
    DECL_THISCALL_TAIL(HandleTapToTarget, x, y, tapped)
    DECL_THISCALL_HEAD(GetClosestPedToCenter, _ZN10CPlayerPed21GetClosestPedToCenterEffRfS0_, bool, float maxDistance, float radius, float& x, float& y)
    DECL_THISCALL_TAIL(GetClosestPedToCenter, maxDistance, radius, x, y)
    DECL_THISCALL_HEAD(EvaluateNeighbouringTarget, _ZN10CPlayerPed26EvaluateNeighbouringTargetEP7CEntityPS1_Pfffbbb, void, CEntity* target, CEntity** bestTarget, float* bestPriority, float maxDistance, float referenceHeading, bool next, bool arg6, bool arg7)
    DECL_THISCALL_TAIL(EvaluateNeighbouringTarget, target, bestTarget, bestPriority, maxDistance, referenceHeading, next, arg6, arg7)
    DECL_THISCALL_SIMPLE(DebugMarkVisiblePeds, _ZN10CPlayerPed20DebugMarkVisiblePedsEv, void);
    DECL_THISCALL_HEAD(MakeObjectTargettable, _ZN10CPlayerPed21MakeObjectTargettableEib, void, i32 objectHandle, bool targettable)
    DECL_THISCALL_TAIL(MakeObjectTargettable, objectHandle, targettable)
    DECL_THISCALL_SIMPLE(KeepAreaAroundPlayerClear, _ZN10CPlayerPed25KeepAreaAroundPlayerClearEv, void);
    DECL_THISCALL_SIMPLE(DoStuffToGoOnFire, _ZN10CPlayerPed17DoStuffToGoOnFireEv, void);
    DECL_THISCALL_HEAD(AnnoyPlayerPed, _ZN10CPlayerPed14AnnoyPlayerPedEb, void, bool annoyed)
    DECL_THISCALL_TAIL(AnnoyPlayerPed, annoyed)
    DECL_THISCALL_SIMPLE(ClearAdrenaline, _ZN10CPlayerPed15ClearAdrenalineEv, void);
    DECL_THISCALL_HEAD(GetMeleeAttackCoords, _ZN10CPlayerPed20GetMeleeAttackCoordsER7CVectoraf, void, CVector& position, i8 attackPoint, float distance)
    DECL_THISCALL_TAIL(GetMeleeAttackCoords, position, attackPoint, distance)
    DECL_THISCALL_HEAD(FindMeleeAttackPoint, _ZN10CPlayerPed20FindMeleeAttackPointEP4CPedR7CVectorRj, i16, CPed* ped, CVector& position, u32& time)
    DECL_THISCALL_TAIL(FindMeleeAttackPoint, ped, position, time)
    DECL_THISCALL_HEAD(RemovePedFromMeleeList, _ZN10CPlayerPed22RemovePedFromMeleeListEP4CPed, void, CPed* ped)
    DECL_THISCALL_TAIL(RemovePedFromMeleeList, ped)
    DECL_THISCALL_HEAD(AdvanceMeleeListAttackTimers, _ZN10CPlayerPed28AdvanceMeleeListAttackTimersEP4CPed, void, CPed* ped)
    DECL_THISCALL_TAIL(AdvanceMeleeListAttackTimers, ped)
    DECL_THISCALL_HEAD(MakeChangesForNewWeapon, _ZN10CPlayerPed23MakeChangesForNewWeaponE11eWeaponType, void, eWeaponType type)
    DECL_THISCALL_TAIL(MakeChangesForNewWeapon, type)
    DECL_THISCALL_NAMED_HEAD(MakeChangesForNewWeapon1, MakeChangesForNewWeapon, _ZN10CPlayerPed23MakeChangesForNewWeaponEi, void, i32 weaponSlot)
    DECL_THISCALL_TAIL(MakeChangesForNewWeapon1, weaponSlot)

    // Helper functions
    inline CWanted* GetWanted() { return m_pWanted; }
    inline CWanted const* GetWanted() const { return m_pWanted; }

    // Member values
    CWanted* m_pWanted;
    CCopPed* m_pArrestingCop;
    float m_fMoveSpeed;
    float m_fCurrentStamina;
    float m_fMaxStamina;
    float m_fStaminaProgress;
    i8 m_nSelectedWepSlot;
    bool m_bStoppedMoving;
    bool m_bShouldEvade;
    u32 m_nStandStillTimer;
    i32 m_nShotDelay;
    float m_fAttackButtonCounter;
    bool m_bHaveTargetSelected;
    CEntity* m_pEvadingFrom;
    i32 m_nTargettableObjects[25];
    u32 m_nAdrenalineEndTime;
    u8 m_nDrunkenness;
    u8 m_nFadeDrunkenness;
    u8 m_nDrunkCountdown;
    bool m_bAdrenaline;
    bool m_bHasLockOnTarget;
    bool m_bDrunkVisualsWearOff;
    bool m_checkPlayerFlag;
    CVector m_vecSafePos[6];
    CPed* m_pPedAtSafePos[6];
    CPed* m_pCheckPlayers[6];
    i16 m_nCheckPlayersIndex;
    float m_fWalkAngle;
    float m_fFPSMoveHeading;
    RpAtomic* m_pMinigunTopAtomic;
    float m_fGunSpinSpeed;
    float m_fGunSpinAngle;
    u32 m_nPadDownPressedInMilliseconds;
    u32 m_nLastBusFareCollected;
DECL_CLASS_END()
CHECKSIZE(CPlayerPed, 0x730, 0x908);

#define bDontAllowWeaponChange bDontAllowWeaponChange()

#endif // __AML_PSDK_VCPLAYERPED_H
