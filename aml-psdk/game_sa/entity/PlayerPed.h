#ifndef __AML_PSDK_SAPLAYERPED_H
#define __AML_PSDK_SAPLAYERPED_H

#include "Ped.h"

struct CPad;
struct CPlayerInfo;
struct CEventDamage;

enum eSprintType
{
    SPRINT_ON_FOOT = 0,
    SPRINT_ON_BMX = 1,
    SPRINT_ON_WATER = 2,
    SPRINT_UNDER_WATER = 3,
};

DECL_CLASS_BASED(CPlayerPed, CPed)
    // Construct/Deconstruct functions
    CPlayerPed(){}
    DECL_CTORCALL_ARG_HEAD(CPlayerPed, _ZN10CPlayerPedC2Eib, i32 nPlayerInfoIndex, bool bForReplay)
    DECL_CTORCALL_ARG_TAIL(nPlayerInfoIndex, bForReplay)
    DECL_DTORCALL(CPlayerPed, _ZN10CPlayerPedD2Ev)

    // STATIC functions
    DECL_FASTCALL_SIMPLE(SetupPlayerPed, _ZN10CPlayerPed14SetupPlayerPedEi, void, i32 nPlayerNum);
    DECL_FASTCALL_SIMPLE(RemovePlayerPed, _ZN10CPlayerPed15RemovePlayerPedEi, void, i32 nPlayerNum);
    DECL_FASTCALL_SIMPLE(DeactivatePlayerPed, _ZN10CPlayerPed19DeactivatePlayerPedEi, void, i32 nPlayerNum);
    DECL_FASTCALL_SIMPLE(ReactivatePlayerPed, _ZN10CPlayerPed19ReactivatePlayerPedEi, void, i32 nPlayerNum);
    DECL_FASTCALL_SIMPLE(PedCanBeTargettedVehicleWise, _ZN10CPlayerPed28PedCanBeTargettedVehicleWiseEP4CPed, bool, CPed* pPed);

    // Member functions
    DECL_THISCALL_HEAD(SetInitialState, _ZN10CPlayerPed15SetInitialStateEb, void, bool bReplay)
    DECL_THISCALL_TAIL(SetInitialState, bReplay)

    DECL_THISCALL_SIMPLE(ReApplyMoveAnims, _ZN10CPlayerPed16ReApplyMoveAnimsEv, void);
    DECL_THISCALL_SIMPLE(SetRealMoveAnim, _ZN10CPlayerPed15SetRealMoveAnimEv, void);
    DECL_THISCALL_SIMPLE(ResetSprintEnergy, _ZN10CPlayerPed17ResetSprintEnergyEv, void);
    DECL_THISCALL_HEAD(HandleSprintEnergy, _ZN10CPlayerPed18HandleSprintEnergyEbf, bool, bool bSprint, float fRate)
    DECL_THISCALL_TAIL(HandleSprintEnergy, bSprint, fRate)

    DECL_THISCALL_HEAD(ControlButtonSprint, _ZN10CPlayerPed19ControlButtonSprintE11eSprintType, float, eSprintType nSprintType)
    DECL_THISCALL_TAIL(ControlButtonSprint, nSprintType)

    DECL_THISCALL_HEAD(GetButtonSprintResults, _ZN10CPlayerPed22GetButtonSprintResultsE11eSprintType, float, eSprintType nSprintType)
    DECL_THISCALL_TAIL(GetButtonSprintResults, nSprintType)

    DECL_THISCALL_SIMPLE(ResetPlayerBreath, _ZN10CPlayerPed17ResetPlayerBreathEv, void);
    DECL_THISCALL_HEAD(HandlePlayerBreath, _ZN10CPlayerPed18HandlePlayerBreathEbf, void, bool bUnderwater, float fRate)
    DECL_THISCALL_TAIL(HandlePlayerBreath, bUnderwater, fRate)

    DECL_THISCALL_HEAD(ProcessPlayerWeapon, _ZN10CPlayerPed19ProcessPlayerWeaponEP4CPad, void, CPad* pPad)
    DECL_THISCALL_TAIL(ProcessPlayerWeapon, pPad)

    DECL_THISCALL_HEAD(ProcessWeaponSwitch, _ZN10CPlayerPed19ProcessWeaponSwitchEP4CPad, void, CPad* pPad)
    DECL_THISCALL_TAIL(ProcessWeaponSwitch, pPad)

    DECL_THISCALL_SIMPLE(PickWeaponAllowedFor2Player, _ZN10CPlayerPed27PickWeaponAllowedFor2PlayerEv, void);
    DECL_THISCALL_NAMED_HEAD(MakeChangesForNewWeapon1, MakeChangesForNewWeapon, _ZN10CPlayerPed23MakeChangesForNewWeaponEi, void, i32 NewWeaponType)
    DECL_THISCALL_TAIL(MakeChangesForNewWeapon1, NewWeaponType)

    DECL_THISCALL_NAMED_HEAD(MakeChangesForNewWeapon2, MakeChangesForNewWeapon, _ZN10CPlayerPed23MakeChangesForNewWeaponE11eWeaponType, void, eWeaponType NewWeaponType)
    DECL_THISCALL_TAIL(MakeChangesForNewWeapon2, NewWeaponType)

    DECL_THISCALL_HEAD(DoesPlayerWantNewWeapon, _ZN10CPlayerPed23DoesPlayerWantNewWeaponE11eWeaponTypeb, bool, eWeaponType newWeapon, bool bInCar)
    DECL_THISCALL_TAIL(DoesPlayerWantNewWeapon, newWeapon, bInCar)

    DECL_THISCALL_SIMPLE(ProcessAnimGroups, _ZN10CPlayerPed17ProcessAnimGroupsEv, void);
    DECL_THISCALL_SIMPLE(FindWeaponLockOnTarget, _ZN10CPlayerPed22FindWeaponLockOnTargetEv, bool);
    DECL_THISCALL_SIMPLE(FindSprayableBuilding, _ZN10CPlayerPed21FindSprayableBuildingEv, CEntity*);
    DECL_THISCALL_SIMPLE(RotatePlayerToTrackTarget, _ZN10CPlayerPed25RotatePlayerToTrackTargetEv, void);
    DECL_THISCALL_SIMPLE(MovementDisabledBecauseOfTargeting, _ZN10CPlayerPed34MovementDisabledBecauseOfTargetingEv, bool);
    DECL_THISCALL_HEAD(FindNextWeaponLockOnTarget, _ZN10CPlayerPed26FindNextWeaponLockOnTargetEP7CEntityb, bool, CEntity* pOldTarget, bool bDirection)
    DECL_THISCALL_TAIL(FindNextWeaponLockOnTarget, pOldTarget, bDirection)

    DECL_THISCALL_HEAD(FindTargetPriority, _ZN10CPlayerPed18FindTargetPriorityEP7CEntity, float, CEntity* pTarget)
    DECL_THISCALL_TAIL(FindTargetPriority, pTarget)

    DECL_THISCALL_HEAD(HandleTapToTarget, _ZN10CPlayerPed17HandleTapToTargetEffb, void, float fTapX, float fTapY, bool bShowDebug)
    DECL_THISCALL_TAIL(HandleTapToTarget, fTapX, fTapY, bShowDebug)

    DECL_THISCALL_SIMPLE(HandleMeleeTargeting, _ZN10CPlayerPed20HandleMeleeTargetingEv, void);
    DECL_THISCALL_HEAD(EvaluateTarget, _ZN10CPlayerPed14EvaluateTargetEP7CEntityPS1_Pfffb, void, CEntity* pTarget, CEntity** ppOldTarget, float* pOldTargetValue, float fWeaponRange, float fLookOrientation, bool bTargetMustBeOnScreen)
    DECL_THISCALL_TAIL(EvaluateTarget, pTarget, ppOldTarget, pOldTargetValue, fWeaponRange, fLookOrientation, bTargetMustBeOnScreen)

    DECL_THISCALL_HEAD(EvaluateNeighbouringTarget, _ZN10CPlayerPed26EvaluateNeighbouringTargetEP7CEntityPS1_Pfffb, void, CEntity* pTarget, CEntity** ppOldTarget, float* pOldTargetValue, float fWeaponRange, float OrientationToTarget, bool bDirection)
    DECL_THISCALL_TAIL(EvaluateNeighbouringTarget, pTarget, ppOldTarget, pOldTargetValue, fWeaponRange, OrientationToTarget, bDirection)

    DECL_THISCALL_HEAD(UpdateCameraWeaponModes, _ZN10CPlayerPed23UpdateCameraWeaponModesEP4CPad, void, CPad* pPad)
    DECL_THISCALL_TAIL(UpdateCameraWeaponModes, pPad)

    DECL_THISCALL_SIMPLE(ClearWeaponTarget, _ZN10CPlayerPed17ClearWeaponTargetEv, void);
    DECL_THISCALL_HEAD(Compute3rdPersonMouseTarget, _ZN10CPlayerPed27Compute3rdPersonMouseTargetEb, void, bool bUseCrosshair)
    DECL_THISCALL_TAIL(Compute3rdPersonMouseTarget, bUseCrosshair)

    DECL_THISCALL_SIMPLE(Clear3rdPersonMouseTarget, _ZN10CPlayerPed25Clear3rdPersonMouseTargetEv, void);
    DECL_THISCALL_SIMPLE(DrawTriangleForMouseRecruitPed, _ZNK10CPlayerPed30DrawTriangleForMouseRecruitPedEv, void);
    DECL_THISCALL_SIMPLE(GetWeaponRadiusOnScreen, _ZN10CPlayerPed23GetWeaponRadiusOnScreenEv, float);
    DECL_THISCALL_SIMPLE(Busted, _ZN10CPlayerPed6BustedEv, void);
    DECL_THISCALL_HEAD(SetWantedLevel, _ZN10CPlayerPed14SetWantedLevelEi, void, i32 NewLevel)
    DECL_THISCALL_TAIL(SetWantedLevel, NewLevel)

    DECL_THISCALL_HEAD(CheatWantedLevel, _ZN10CPlayerPed16CheatWantedLevelEi, void, i32 NewLevel)
    DECL_THISCALL_TAIL(CheatWantedLevel, NewLevel)

    DECL_THISCALL_HEAD(SetWantedLevelNoDrop, _ZN10CPlayerPed20SetWantedLevelNoDropEi, void, i32 NewLevel)
    DECL_THISCALL_TAIL(SetWantedLevelNoDrop, NewLevel)

    DECL_THISCALL_HEAD(DoesTargetHaveToBeBroken, _ZN10CPlayerPed24DoesTargetHaveToBeBrokenEP7CEntityP7CWeapon, bool, CEntity* pTargetEnt, CWeapon* pWeapon)
    DECL_THISCALL_TAIL(DoesTargetHaveToBeBroken, pTargetEnt, pWeapon)

    DECL_THISCALL_HEAD(CanIKReachThisTarget, _ZN10CPlayerPed20CanIKReachThisTargetE7CVectorP7CWeaponb, bool, CVector Target, CWeapon* pWeapon, bool bTestYaw)
    DECL_THISCALL_TAIL(CanIKReachThisTarget, Target, pWeapon, bTestYaw)

    DECL_THISCALL_SIMPLE(KeepAreaAroundPlayerClear, _ZN10CPlayerPed25KeepAreaAroundPlayerClearEv, void);
    DECL_THISCALL_SIMPLE(GetPlayerInfoForThisPlayerPed, _ZN10CPlayerPed29GetPlayerInfoForThisPlayerPedEv, CPlayerInfo*);
    DECL_THISCALL_SIMPLE(DoStuffToGoOnFire, _ZN10CPlayerPed17DoStuffToGoOnFireEv, void);
    DECL_THISCALL_HEAD(AnnoyPlayerPed, _ZN10CPlayerPed14AnnoyPlayerPedEb, void, bool bUsingVees)
    DECL_THISCALL_TAIL(AnnoyPlayerPed, bUsingVees)

    DECL_THISCALL_SIMPLE(ClearAdrenaline, _ZN10CPlayerPed15ClearAdrenalineEv, void);
    DECL_THISCALL_HEAD(SetPlayerMoveBlendRatio, _ZN10CPlayerPed23SetPlayerMoveBlendRatioEP7CVector, void, CVector* pvecTarget)
    DECL_THISCALL_TAIL(SetPlayerMoveBlendRatio, pvecTarget)

    DECL_THISCALL_SIMPLE(GetPadFromPlayer, _ZN10CPlayerPed16GetPadFromPlayerEv, CPad*);
    DECL_THISCALL_SIMPLE(CanPlayerStartMission, _ZN10CPlayerPed21CanPlayerStartMissionEv, u8);
    DECL_THISCALL_SIMPLE(FindPedToAttack, _ZN10CPlayerPed15FindPedToAttackEv, CPed*);
    DECL_THISCALL_HEAD(ProcessGroupBehaviour, _ZN10CPlayerPed21ProcessGroupBehaviourEP4CPad, void, CPad* pPad)
    DECL_THISCALL_TAIL(ProcessGroupBehaviour, pPad)

    DECL_THISCALL_HEAD(ForceGroupToAlwaysFollow, _ZN10CPlayerPed24ForceGroupToAlwaysFollowEb, void, bool bOn)
    DECL_THISCALL_TAIL(ForceGroupToAlwaysFollow, bOn)

    DECL_THISCALL_HEAD(ForceGroupToNeverFollow, _ZN10CPlayerPed23ForceGroupToNeverFollowEb, void, bool bOn)
    DECL_THISCALL_TAIL(ForceGroupToNeverFollow, bOn)

    DECL_THISCALL_SIMPLE(DisbandPlayerGroup, _ZN10CPlayerPed18DisbandPlayerGroupEv, void);
    DECL_THISCALL_HEAD(MakeThisPedJoinOurGroup, _ZN10CPlayerPed23MakeThisPedJoinOurGroupEP4CPed, void, CPed* pCandidate)
    DECL_THISCALL_TAIL(MakeThisPedJoinOurGroup, pCandidate)

    DECL_THISCALL_SIMPLE(PlayerHasJustAttackedSomeone, _ZN10CPlayerPed28PlayerHasJustAttackedSomeoneEv, void);
    DECL_THISCALL_SIMPLE(PlayerWantsToAttack, _ZN10CPlayerPed19PlayerWantsToAttackEv, void);
    DECL_THISCALL_HEAD(MakeGroupRespondToPlayerTakingDamage, _ZN10CPlayerPed36MakeGroupRespondToPlayerTakingDamageERK12CEventDamage, void, CEventDamage const& eventDamage)
    DECL_THISCALL_TAIL(MakeGroupRespondToPlayerTakingDamage, eventDamage)

    DECL_THISCALL_HEAD(TellGroupToStartFollowingPlayer, _ZN10CPlayerPed31TellGroupToStartFollowingPlayerEbbb, void, bool bFollow, bool bPlaySound, bool bChangeFollowEvenWhenEmpty)
    DECL_THISCALL_TAIL(TellGroupToStartFollowingPlayer, bFollow, bPlaySound, bChangeFollowEvenWhenEmpty)

    DECL_THISCALL_SIMPLE(MakePlayerGroupDisappear, _ZN10CPlayerPed24MakePlayerGroupDisappearEv, void);
    DECL_THISCALL_SIMPLE(MakePlayerGroupReappear, _ZN10CPlayerPed23MakePlayerGroupReappearEv, void);
    DECL_THISCALL_SIMPLE(Save, _ZN10CPlayerPed4SaveEv, bool);
    DECL_THISCALL_SIMPLE(Load, _ZN10CPlayerPed4LoadEv, bool);
    DECL_THISCALL_SIMPLE(DisplayTargettingDebug, _ZN10CPlayerPed22DisplayTargettingDebugEv, void);
    DECL_THISCALL_SIMPLE(IsHidden, _ZNK10CPlayerPed8IsHiddenEv, bool);

    // STATIC values
    DECL_OBJECT_PLT(bool, bDebugPlayerInvincible, BYBIT(0x676A3C, 0x84B4C0));
    DECL_OBJECT_PLT(bool, bDebugTargetting, BYBIT(0x6761FC, 0x84A458));
    DECL_OBJECT_PLT(bool, bDebugTapToTarget, BYBIT(0x6760D4, 0x84A218));
    DECL_OBJECT_PLT(bool, bSwipeTargetHeads, BYBIT(0x676794, 0x84AF80));
    DECL_OBJECT_PLT(bool, bHasDisplayedPlayerQuitEnterCarHelpText, BYBIT(0x67661C, 0x84AC90));

    // Member values
    CPed *m_pPlayerTargettedPed;
    int m_iMouseLockOnRecruitTimer;
DECL_CLASS_END()
CHECKSIZE(CPlayerPed, 0x7AC, 0x998);

DECL_FASTCALL_SIMPLE_GLO(FindPlayerPed, _Z13FindPlayerPedi, CPlayerPed*, int PlayerNum);
DECL_FASTCALL_SIMPLE_GLO(FindPlayerSpeed, _Z15FindPlayerSpeedi, CVector const&, int PlayerNum);
DECL_FASTCALL_SIMPLE_GLO(FindPlayerVehicle, _Z17FindPlayerVehicleib, CVehicle*, int PlayerNum, bool bReturnRemoteVehicle);
DECL_FASTCALL_SIMPLE_GLO(FindPlayerTrain, _Z15FindPlayerTraini, CVehicle*, int PlayerNum);
DECL_FASTCALL_SIMPLE_GLO(IsPlayerRemotePlane, _Z19IsPlayerRemotePlanev, bool);
DECL_FASTCALL_SIMPLE_GLO(FindPlayerEntity, _Z16FindPlayerEntityi, CEntity*, int PlayerNum);
DECL_FASTCALL_SIMPLE_GLO(FindPlayerWanted, _Z16FindPlayerWantedi, CWanted*, int PlayerNum);
DECL_FASTCALL_SIMPLE_GLO(FindPlayerCentreOfWorld, _Z23FindPlayerCentreOfWorldi, CVector const&, int PlayerNum);
DECL_FASTCALL_SIMPLE_GLO(FindPlayerCentreOfWorld_NoSniperShift, _Z37FindPlayerCentreOfWorld_NoSniperShifti, CVector const&, int PlayerNum);
DECL_FASTCALL_SIMPLE_GLO(FindPlayerCentreOfWorldForMap, _Z29FindPlayerCentreOfWorldForMapi, CVector, int PlayerNum);
DECL_FASTCALL_SIMPLE_GLO(FindPlayerHeading, _Z17FindPlayerHeadingi, float, int PlayerNum);
DECL_FASTCALL_SIMPLE_GLO(FindPlayerHeight, _Z16FindPlayerHeightv, float);
DECL_FASTCALL_SIMPLE_GLO(FindPlayerCoors, _Z15FindPlayerCoorsi, CVector, int PlayerNum);

#endif // __AML_PSDK_SAPLAYERPED_H
