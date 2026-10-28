#ifndef __AML_PSDK_VCPED_H
#define __AML_PSDK_VCPED_H

#include "../entity/Physical.h"
#include "../other/Weapon.h"
#include "../other/PedStats.h"
#include "../anim/PedIK.h"
#include "../anim/AnimBlendFrameData.h"
#include "PathNode.h"
#include "PedEnums.h"

struct CVehicle;
struct CPedAttractor;
struct CAccident;
struct CFire;
struct CAnimBlendAssociation;
enum ePedStats : u32;
enum eEventType : u32;
enum ePedPieceTypes : u32;
enum AnimationId : u32;

DECL_CLASS_BASED(CPed, CPhysical)
    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CPed, _ZN4CPedC2Ej, ePedType type)
    DECL_CTORCALL_ARG_TAIL(type)
    DECL_DTORCALL_VIRTUAL_SLOT(CPed, _ZN4CPedD2Ev, _ZN4CPed, _ZTV4CPed, 2);
    CPed(CPed const&) = delete;
    CPed& operator=(CPed const&) = delete;
    DECL_NEWCALL(CPed, BYBIT(_ZN4CPednwEj, _ZN4CPednwEm));
    DECL_DLCALL(CPed, _ZN4CPeddlEPv);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(CPed, SetModelIndex, _ZTV4CPed, 4, void, u32 modelIndex)
    DECL_VIRTUALCALL_TAIL(modelIndex)
    DECL_VIRTUALCALL_HEAD(CPed, DeleteRwObject, _ZTV4CPed, 7, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CPed, ProcessControl, _ZTV4CPed, 9, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CPed, Teleport, _ZTV4CPed, 12, void, CVector destination)
    DECL_VIRTUALCALL_TAIL(destination)
    DECL_VIRTUALCALL_HEAD(CPed, PreRender, _ZTV4CPed, 13, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CPed, Render, _ZTV4CPed, 14, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CPed, SetupLighting, _ZTV4CPed, 15, bool)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CPed, RemoveLighting, _ZTV4CPed, 16, void, bool resetWorldColors)
    DECL_VIRTUALCALL_TAIL(resetWorldColors)
    DECL_VIRTUALCALL_HEAD(CPed, FlagToDestroyWhenNextProcessed, _ZTV4CPed, 17, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CPed, ProcessEntityCollision, _ZTV4CPed, 18, i32, CEntity* entity, CColPoint* colPoints)
    DECL_VIRTUALCALL_TAIL(entity, colPoints)
    DECL_VIRTUALCALL_HEAD(CPed, SetMoveAnim, _ZTV4CPed, 19, void)
    DECL_VIRTUALCALL_TAIL()

    // STATIC functions
    DECL_FASTCALL_SIMPLE(Initialise, _ZN4CPed10InitialiseEv, void);
    DECL_FASTCALL_SIMPLE(LoadFightData, _ZN4CPed13LoadFightDataEv, void);

    // STATIC values
    DECL_VALUE_PLT_BOOL(bFannyMagnetCheat, BYBIT(0x3943F0, 0x576930));
    DECL_VALUE_PLT_BOOL(bNastyLimbsCheat, BYBIT(0x394F30, 0x577ED8));
    DECL_VALUE_PLT_BOOL(bPedCheat3, BYBIT(0x395444, 0x5788E8));
    DECL_VALUE_PLT_U32(nCloseBlockedLosWaitTime, BYBIT(0x394824, 0x577180));
    DECL_VALUE_PLT_U32(nFarBlockedLosWaitTime, BYBIT(0x39654C, 0x57AA88));
    DECL_OBJECT_PLT(CVector2D, ms_vec2DFleePosition, BYBIT(0x395CE0, 0x5799D8));

    // Member functions
    inline bool IsPlayer() const
    {
        static auto func = GetMainLibrarySymbol<bool(*)(CPed const*)>("_ZNK4CPed8IsPlayerEv");
        return func(this);
    }
    inline bool IsGangMember() const
    {
        static auto func = GetMainLibrarySymbol<bool(*)(CPed const*)>("_ZNK4CPed12IsGangMemberEv");
        return func(this);
    }
    DECL_THISCALL_SIMPLE(CanPedReturnToState, _ZN4CPed19CanPedReturnToStateEv, bool);
    DECL_THISCALL_SIMPLE(IsPedInControl, _ZN4CPed14IsPedInControlEv, bool);
    DECL_THISCALL_SIMPLE(IsPedDoingDriveByShooting, _ZN4CPed25IsPedDoingDriveByShootingEv, bool);
    DECL_THISCALL_SIMPLE(IsPedShootable, _ZN4CPed14IsPedShootableEv, bool);
    DECL_THISCALL_SIMPLE(CanBeDeleted, _ZN4CPed12CanBeDeletedEv, bool);
    DECL_THISCALL_SIMPLE(CanBeDeletedEvenInVehicle, _ZN4CPed25CanBeDeletedEvenInVehicleEv, bool);
    DECL_THISCALL_SIMPLE(CanPedDriveOff, _ZN4CPed14CanPedDriveOffEv, bool);
    DECL_THISCALL_SIMPLE(IsRoomToBeCarJacked, _ZN4CPed19IsRoomToBeCarJackedEv, bool);
    DECL_THISCALL_SIMPLE(CanStrafeOrMouseControl, _ZN4CPed23CanStrafeOrMouseControlEv, bool);
    DECL_THISCALL_SIMPLE(IsPointerValid, _ZN4CPed14IsPointerValidEv, bool);
    DECL_THISCALL_SIMPLE(CanSetPedState, _ZN4CPed14CanSetPedStateEv, bool);
    DECL_THISCALL_SIMPLE(CanBeArrested, _ZN4CPed13CanBeArrestedEv, bool);
    DECL_THISCALL_SIMPLE(CanUseTorsoWhenLooking, _ZN4CPed22CanUseTorsoWhenLookingEv, bool);
    DECL_THISCALL_SIMPLE(CanWeRunAndFireWithWeapon, _ZN4CPed25CanWeRunAndFireWithWeaponEv, bool);
    DECL_THISCALL_SIMPLE(CheckIfInTheAir, _ZN4CPed15CheckIfInTheAirEv, bool);
    DECL_THISCALL_SIMPLE(TurnBody, _ZN4CPed8TurnBodyEv, bool);
    DECL_THISCALL_SIMPLE(Seek, _ZN4CPed4SeekEv, bool);
    DECL_THISCALL_SIMPLE(MakePhonecall, _ZN4CPed13MakePhonecallEv, bool);
    DECL_THISCALL_SIMPLE(FacePhone, _ZN4CPed9FacePhoneEv, bool);
    DECL_THISCALL_SIMPLE(PlacePedOnDryLand, _ZN4CPed17PlacePedOnDryLandEv, bool);
    DECL_THISCALL_SIMPLE(PositionPedOutOfCollision, _ZN4CPed25PositionPedOutOfCollisionEv, bool);
    DECL_THISCALL_SIMPLE(PositionAnyPedOutOfCollision, _ZN4CPed28PositionAnyPedOutOfCollisionEv, bool);
    DECL_THISCALL_SIMPLE(UseGroundColModel, _ZN4CPed17UseGroundColModelEv, bool);
    DECL_THISCALL_SIMPLE(ClearWeapons, _ZN4CPed12ClearWeaponsEv, void);
    DECL_THISCALL_SIMPLE(ClearAimFlag, _ZN4CPed12ClearAimFlagEv, void);
    DECL_THISCALL_SIMPLE(ClearLookFlag, _ZN4CPed13ClearLookFlagEv, void);
    DECL_THISCALL_SIMPLE(ClearAll, _ZN4CPed8ClearAllEv, void);
    DECL_THISCALL_SIMPLE(ClearAttack, _ZN4CPed11ClearAttackEv, void);
    DECL_THISCALL_SIMPLE(ClearAttackByRemovingAnim, _ZN4CPed25ClearAttackByRemovingAnimEv, void);
    DECL_THISCALL_SIMPLE(ClearPointGunAt, _ZN4CPed15ClearPointGunAtEv, void);
    DECL_THISCALL_SIMPLE(ClearChat, _ZN4CPed9ClearChatEv, void);
    DECL_THISCALL_SIMPLE(ClearSeek, _ZN4CPed9ClearSeekEv, void);
    DECL_THISCALL_SIMPLE(ClearWaitState, _ZN4CPed14ClearWaitStateEv, void);
    DECL_THISCALL_SIMPLE(ClearFlee, _ZN4CPed9ClearFleeEv, void);
    DECL_THISCALL_SIMPLE(ClearFall, _ZN4CPed9ClearFallEv, void);
    DECL_THISCALL_SIMPLE(ClearFollowPath, _ZN4CPed15ClearFollowPathEv, void);
    DECL_THISCALL_SIMPLE(ClearLeader, _ZN4CPed11ClearLeaderEv, void);
    DECL_THISCALL_SIMPLE(ClearObjective, _ZN4CPed14ClearObjectiveEv, void);
    DECL_THISCALL_SIMPLE(ClearInvestigateEvent, _ZN4CPed21ClearInvestigateEventEv, void);
    DECL_THISCALL_SIMPLE(ClearAnswerMobile, _ZN4CPed17ClearAnswerMobileEv, void);
    DECL_THISCALL_SIMPLE(RestoreGunPosition, _ZN4CPed18RestoreGunPositionEv, void);
    DECL_THISCALL_SIMPLE(RestoreHeadPosition, _ZN4CPed19RestoreHeadPositionEv, void);
    DECL_THISCALL_SIMPLE(RestoreHeadingRate, _ZN4CPed18RestoreHeadingRateEv, void);
    DECL_THISCALL_SIMPLE(RestorePreviousObjective, _ZN4CPed24RestorePreviousObjectiveEv, void);
    DECL_THISCALL_SIMPLE(RestorePreviousState, _ZN4CPed20RestorePreviousStateEv, void);
    DECL_THISCALL_SIMPLE(SetStoredState, _ZN4CPed14SetStoredStateEv, void);
    DECL_THISCALL_SIMPLE(SetStoredObjective, _ZN4CPed18SetStoredObjectiveEv, void);
    DECL_THISCALL_SIMPLE(SetIdle, _ZN4CPed7SetIdleEv, void);
    DECL_THISCALL_SIMPLE(SetDead, _ZN4CPed7SetDeadEv, void);
    DECL_THISCALL_SIMPLE(SetGetUp, _ZN4CPed8SetGetUpEv, void);
    DECL_THISCALL_SIMPLE(SetInTheAir, _ZN4CPed11SetInTheAirEv, void);
    DECL_THISCALL_SIMPLE(SetJump, _ZN4CPed7SetJumpEv, void);
    DECL_THISCALL_SIMPLE(SetLanding, _ZN4CPed10SetLandingEv, void);
    DECL_THISCALL_SIMPLE(SetPedPositionInCar, _ZN4CPed19SetPedPositionInCarEv, void);
    DECL_THISCALL_SIMPLE(CalculateNewOrientation, _ZN4CPed23CalculateNewOrientationEv, void);
    DECL_THISCALL_SIMPLE(CalculateNewVelocity, _ZN4CPed20CalculateNewVelocityEv, void);
    DECL_THISCALL_SIMPLE(UpdatePosition, _ZN4CPed14UpdatePositionEv, void);
    DECL_THISCALL_SIMPLE(Update, _ZN4CPed6UpdateEv, void);
    DECL_THISCALL_SIMPLE(BuildPedLists, _ZN4CPed13BuildPedListsEv, void);
    DECL_THISCALL_SIMPLE(PlayFootSteps, _ZN4CPed13PlayFootStepsEv, void);
    DECL_THISCALL_SIMPLE(RequestDelayedWeapon, _ZN4CPed20RequestDelayedWeaponEv, void);
    DECL_THISCALL_SIMPLE(RemoveWeaponWhenEnteringVehicle, _ZN4CPed31RemoveWeaponWhenEnteringVehicleEv, void);
    DECL_THISCALL_SIMPLE(ReplaceWeaponWhenExitingVehicle, _ZN4CPed31ReplaceWeaponWhenExitingVehicleEv, void);
    DECL_THISCALL_SIMPLE(RestartNonPartialAnims, _ZN4CPed22RestartNonPartialAnimsEv, void);
    DECL_THISCALL_SIMPLE(StopNonPartialAnims, _ZN4CPed19StopNonPartialAnimsEv, void);
    DECL_THISCALL_SIMPLE(ProcessBuoyancy, _ZN4CPed15ProcessBuoyancyEv, void);
    DECL_THISCALL_SIMPLE(ProcessObjective, _ZN4CPed16ProcessObjectiveEv, void);
    DECL_THISCALL_SIMPLE(QuitEnteringCar, _ZN4CPed15QuitEnteringCarEv, void);
    DECL_THISCALL_SIMPLE(SetRadioStation, _ZN4CPed15SetRadioStationEv, void);
    DECL_THISCALL_SIMPLE(AnswerMobile, _ZN4CPed12AnswerMobileEv, void);
    DECL_THISCALL_SIMPLE(SetAnswerMobile, _ZN4CPed15SetAnswerMobileEv, void);
    DECL_THISCALL_SIMPLE(ServiceTalking, _ZN4CPed14ServiceTalkingEv, void);
    DECL_THISCALL_SIMPLE(ScanForInterestingStuff, _ZN4CPed23ScanForInterestingStuffEv, void);
    DECL_THISCALL_SIMPLE(ScanForThreats, _ZN4CPed14ScanForThreatsEv, void);
    DECL_THISCALL_SIMPLE(ScanForDelayedResponseThreats, _ZN4CPed29ScanForDelayedResponseThreatsEv, void);
    DECL_THISCALL_SIMPLE(MoveHeadToLook, _ZN4CPed14MoveHeadToLookEv, void);
    DECL_THISCALL_SIMPLE(GetNextPointOnRoute, _ZN4CPed19GetNextPointOnRouteEv, i16);
    DECL_THISCALL_SIMPLE(CheckThreatValidity, _ZN4CPed19CheckThreatValidityEv, void);
    DECL_THISCALL_SIMPLE(GetFormationPosition, _ZN4CPed20GetFormationPositionEv, CVector);
    DECL_THISCALL_SIMPLE(CheckForGunShots, _ZN4CPed16CheckForGunShotsEv, CPed*);
    DECL_THISCALL_SIMPLE(CheckForDeadPeds, _ZN4CPed16CheckForDeadPedsEv, CPed*);
    DECL_THISCALL_HEAD(GiveWeapon, _ZN4CPed10GiveWeaponE11eWeaponTypejb, i32, eWeaponType type, u32 ammo, bool unused)
    DECL_THISCALL_TAIL(GiveWeapon, type, ammo, unused)
    DECL_THISCALL_HEAD(GiveDelayedWeapon, _ZN4CPed17GiveDelayedWeaponE11eWeaponTypej, void, eWeaponType type, u32 ammo)
    DECL_THISCALL_TAIL(GiveDelayedWeapon, type, ammo)
    DECL_THISCALL_HEAD(GrantAmmo, _ZN4CPed9GrantAmmoE11eWeaponTypej, void, eWeaponType type, u32 ammo)
    DECL_THISCALL_TAIL(GrantAmmo, type, ammo)
    DECL_THISCALL_HEAD(SetAmmo, _ZN4CPed7SetAmmoE11eWeaponTypej, void, eWeaponType type, u32 ammo)
    DECL_THISCALL_TAIL(SetAmmo, type, ammo)
    DECL_THISCALL_HEAD(GetWeaponSlot, _ZN4CPed13GetWeaponSlotE11eWeaponType, i32, eWeaponType type)
    DECL_THISCALL_TAIL(GetWeaponSlot, type)
    DECL_THISCALL_HEAD(SetCurrentWeapon, _ZN4CPed16SetCurrentWeaponE11eWeaponType, void, eWeaponType type)
    DECL_THISCALL_TAIL(SetCurrentWeapon, type)
    DECL_THISCALL_NAMED_HEAD(SetCurrentWeapon1, SetCurrentWeapon, _ZN4CPed16SetCurrentWeaponEi, void, i32 slot)
    DECL_THISCALL_TAIL(SetCurrentWeapon1, slot)
    DECL_THISCALL_HEAD(AddWeaponModel, _ZN4CPed14AddWeaponModelEi, void, i32 modelIndex)
    DECL_THISCALL_TAIL(AddWeaponModel, modelIndex)
    DECL_THISCALL_HEAD(RemoveWeaponModel, _ZN4CPed17RemoveWeaponModelEi, void, i32 modelIndex)
    DECL_THISCALL_TAIL(RemoveWeaponModel, modelIndex)
    DECL_THISCALL_HEAD(SetMoveState, _ZN4CPed12SetMoveStateE10eMoveState, void, eMoveState moveState)
    DECL_THISCALL_TAIL(SetMoveState, moveState)
    DECL_THISCALL_HEAD(SetLookFlag, _ZN4CPed11SetLookFlagEP7CEntitybb, void, CEntity* entity, bool keepTryingToLook, bool cancelPrevious)
    DECL_THISCALL_TAIL(SetLookFlag, entity, keepTryingToLook, cancelPrevious)
    DECL_THISCALL_NAMED_HEAD(SetLookFlag1, SetLookFlag, _ZN4CPed11SetLookFlagEfbb, void, float heading, bool keepTryingToLook, bool cancelPrevious)
    DECL_THISCALL_TAIL(SetLookFlag1, heading, keepTryingToLook, cancelPrevious)
    DECL_THISCALL_HEAD(SetAimFlag, _ZN4CPed10SetAimFlagEP7CEntity, void, CEntity* entity)
    DECL_THISCALL_TAIL(SetAimFlag, entity)
    DECL_THISCALL_NAMED_HEAD(SetAimFlag1, SetAimFlag, _ZN4CPed10SetAimFlagEf, void, float heading)
    DECL_THISCALL_TAIL(SetAimFlag1, heading)
    DECL_THISCALL_HEAD(SetPointGunAt, _ZN4CPed13SetPointGunAtEP7CEntity, void, CEntity* entity)
    DECL_THISCALL_TAIL(SetPointGunAt, entity)
    DECL_THISCALL_HEAD(SetAttack, _ZN4CPed9SetAttackEP7CEntity, void, CEntity* entity)
    DECL_THISCALL_TAIL(SetAttack, entity)
    DECL_THISCALL_HEAD(SetLeader, _ZN4CPed9SetLeaderEPS_, void, CPed* leader)
    DECL_THISCALL_TAIL(SetLeader, leader)
    DECL_THISCALL_HEAD(SetDuck, _ZN4CPed7SetDuckEjb, void, u32 time, bool crouchWhenShooting)
    DECL_THISCALL_TAIL(SetDuck, time, crouchWhenShooting)
    DECL_THISCALL_HEAD(ClearDuck, _ZN4CPed9ClearDuckEb, void, bool clearCrouchWhenShooting)
    DECL_THISCALL_TAIL(ClearDuck, clearCrouchWhenShooting)
    DECL_THISCALL_HEAD(SetSeek, _ZN4CPed7SetSeekEP7CEntityf, void, CEntity* entity, float distance)
    DECL_THISCALL_TAIL(SetSeek, entity, distance)
    DECL_THISCALL_NAMED_HEAD(SetSeek1, SetSeek, _ZN4CPed7SetSeekE7CVectorf, void, CVector position, float distance)
    DECL_THISCALL_TAIL(SetSeek1, position, distance)
    DECL_THISCALL_HEAD(SetFlee, _ZN4CPed7SetFleeEP7CEntityi, void, CEntity* entity, i32 time)
    DECL_THISCALL_TAIL(SetFlee, entity, time)
    DECL_THISCALL_NAMED_HEAD(SetFlee1, SetFlee, _ZN4CPed7SetFleeERK9CVector2Di, void, CVector2D const& position, i32 time)
    DECL_THISCALL_TAIL(SetFlee1, position, time)
    DECL_THISCALL_HEAD(SetObjective, _ZN4CPed12SetObjectiveE10eObjective, void, eObjective objective)
    DECL_THISCALL_TAIL(SetObjective, objective)
    DECL_THISCALL_NAMED_HEAD(SetObjective1, SetObjective, _ZN4CPed12SetObjectiveE10eObjectivePv, void, eObjective objective, void* target)
    DECL_THISCALL_TAIL(SetObjective1, objective, target)
    DECL_THISCALL_NAMED_HEAD(SetObjective2, SetObjective, _ZN4CPed12SetObjectiveE10eObjective7CVector, void, eObjective objective, CVector position)
    DECL_THISCALL_TAIL(SetObjective2, objective, position)
    DECL_THISCALL_NAMED_HEAD(SetObjective3, SetObjective, _ZN4CPed12SetObjectiveE10eObjectivess, void, eObjective objective, i16 route, i16 direction)
    DECL_THISCALL_TAIL(SetObjective3, objective, route, direction)
    DECL_THISCALL_NAMED_HEAD(SetObjective4, SetObjective, _ZN4CPed12SetObjectiveE10eObjectivefRK7CVector, void, eObjective objective, float heading, CVector const& position)
    DECL_THISCALL_TAIL(SetObjective4, objective, heading, position)
    DECL_THISCALL_NAMED_HEAD(SetObjective5, SetObjective, _ZN4CPed12SetObjectiveE10eObjective7CVectorf, void, eObjective objective, CVector position, float heading)
    DECL_THISCALL_TAIL(SetObjective5, objective, position, heading)
    DECL_THISCALL_HEAD(SetWaitState, _ZN4CPed12SetWaitStateE10eWaitStatePv, void, eWaitState state, void* time)
    DECL_THISCALL_TAIL(SetWaitState, state, time)
    DECL_THISCALL_HEAD(SetEnterCar, _ZN4CPed11SetEnterCarEP8CVehiclej, void, CVehicle* vehicle, u32 door)
    DECL_THISCALL_TAIL(SetEnterCar, vehicle, door)
    DECL_THISCALL_HEAD(SetExitCar, _ZN4CPed10SetExitCarEP8CVehiclej, void, CVehicle* vehicle, u32 door)
    DECL_THISCALL_TAIL(SetExitCar, vehicle, door)
    DECL_THISCALL_HEAD(SetSeekCar, _ZN4CPed10SetSeekCarEP8CVehiclej, void, CVehicle* vehicle, u32 door)
    DECL_THISCALL_TAIL(SetSeekCar, vehicle, door)
    DECL_THISCALL_HEAD(SetCarJack, _ZN4CPed10SetCarJackEP8CVehicle, void, CVehicle* vehicle)
    DECL_THISCALL_TAIL(SetCarJack, vehicle)
    DECL_THISCALL_HEAD(WarpPedIntoCar, _ZN4CPed14WarpPedIntoCarEP8CVehicle, void, CVehicle* vehicle)
    DECL_THISCALL_TAIL(WarpPedIntoCar, vehicle)
    DECL_THISCALL_HEAD(SetExitBoat, _ZN4CPed11SetExitBoatEP8CVehicle, void, CVehicle* vehicle)
    DECL_THISCALL_TAIL(SetExitBoat, vehicle)
    DECL_THISCALL_HEAD(SetSeekBoatPosition, _ZN4CPed19SetSeekBoatPositionEP8CVehicle, void, CVehicle* vehicle)
    DECL_THISCALL_TAIL(SetSeekBoatPosition, vehicle)
    DECL_THISCALL_HEAD(CanSeeEntity, _ZN4CPed12CanSeeEntityEP7CEntityf, bool, CEntity* entity, float limitAngle)
    DECL_THISCALL_TAIL(CanSeeEntity, entity, limitAngle)
    DECL_THISCALL_HEAD(OurPedCanSeeThisOne, _ZN4CPed19OurPedCanSeeThisOneEP7CEntityb, bool, CEntity* entity, bool shootablesDoBlock)
    DECL_THISCALL_TAIL(OurPedCanSeeThisOne, entity, shootablesDoBlock)
    DECL_THISCALL_HEAD(CanBeDamagedByThisGangMember, _ZN4CPed28CanBeDamagedByThisGangMemberEPS_, bool, CPed* ped)
    DECL_THISCALL_TAIL(CanBeDamagedByThisGangMember, ped)
    DECL_THISCALL_HEAD(CanPedJumpThis, _ZN4CPed14CanPedJumpThisEP7CEntityP7CVector, bool, CEntity* entity, CVector* position)
    DECL_THISCALL_TAIL(CanPedJumpThis, entity, position)
    DECL_THISCALL_HEAD(GetHeadAndFootPositions, _ZN4CPed23GetHeadAndFootPositionsER7CVectorS1_b, void, CVector& head, CVector& foot, bool adjustForCamera)
    DECL_THISCALL_TAIL(GetHeadAndFootPositions, head, foot, adjustForCamera)
    DECL_THISCALL_HEAD(ReactToAttack, _ZN4CPed13ReactToAttackEP7CEntity, void, CEntity* attacker)
    DECL_THISCALL_TAIL(ReactToAttack, attacker)
    DECL_THISCALL_HEAD(InformMyGangOfAttack, _ZN4CPed20InformMyGangOfAttackEP7CEntity, void, CEntity* attacker)
    DECL_THISCALL_TAIL(InformMyGangOfAttack, attacker)
    DECL_THISCALL_HEAD(RegisterThreatWithGangPeds, _ZN4CPed26RegisterThreatWithGangPedsEP7CEntity, void, CEntity* threat)
    DECL_THISCALL_TAIL(RegisterThreatWithGangPeds, threat)
    DECL_THISCALL_HEAD(Say, _ZN4CPed3SayEt, void, u16 sound)
    DECL_THISCALL_TAIL(Say, sound)
    DECL_THISCALL_NAMED_HEAD(Say1, Say, _ZN4CPed3SayEti, void, u16 sound, i32 time)
    DECL_THISCALL_TAIL(Say1, sound, time)
    DECL_THISCALL_HEAD(WorkOutHeadingForMovingFirstPerson, _ZN4CPed34WorkOutHeadingForMovingFirstPersonEf, float, float heading)
    DECL_THISCALL_TAIL(WorkOutHeadingForMovingFirstPerson, heading)
    DECL_THISCALL_HEAD(SetLookTimer, _ZN4CPed12SetLookTimerEj, void, u32 time)
    DECL_THISCALL_TAIL(SetLookTimer, time)
    DECL_THISCALL_HEAD(SetAttackTimer, _ZN4CPed14SetAttackTimerEj, void, u32 time)
    DECL_THISCALL_TAIL(SetAttackTimer, time)
    DECL_THISCALL_HEAD(SetObjectiveTimer, _ZN4CPed17SetObjectiveTimerEj, void, u32 time)
    DECL_THISCALL_TAIL(SetObjectiveTimer, time)
    DECL_THISCALL_HEAD(SetShootTimer, _ZN4CPed13SetShootTimerEj, void, u32 time)
    DECL_THISCALL_TAIL(SetShootTimer, time)
    DECL_THISCALL_HEAD(Undress, _ZN4CPed7UndressEPKc, void, char const* modelName)
    DECL_THISCALL_TAIL(Undress, modelName)
    DECL_THISCALL_HEAD(SetPedStats, _ZN4CPed11SetPedStatsE9ePedStats, void, ePedStats stats)
    DECL_THISCALL_TAIL(SetPedStats, stats)

    DECL_THISCALL_HEAD(InflictDamage, _ZN4CPed13InflictDamageEPv11eWeaponTypef14ePedPieceTypesh, bool, void* damager, eWeaponType weapon, float damage, ePedPieceTypes piece, u8 direction)
    DECL_THISCALL_TAIL(InflictDamage, damager, weapon, damage, piece, direction)
    DECL_THISCALL_HEAD(ApplyHeadShot, _ZN4CPed13ApplyHeadShotE11eWeaponType7CVectorh, void, eWeaponType weapon, CVector position, u8 force)
    DECL_THISCALL_TAIL(ApplyHeadShot, weapon, position, force)
    DECL_THISCALL_HEAD(RemoveBodyPart, _ZN4CPed14RemoveBodyPartEia, void, i32 node, i8 direction)
    DECL_THISCALL_TAIL(RemoveBodyPart, node, direction)
    DECL_THISCALL_HEAD(SetDie, _ZN4CPed6SetDieE11AnimationIdff, void, AnimationId anim, float blendDelta, float speed)
    DECL_THISCALL_TAIL(SetDie, anim, blendDelta, speed)
    DECL_THISCALL_HEAD(SetFall, _ZN4CPed7SetFallEi11AnimationIdh, void, i32 extraTime, AnimationId anim, u8 evenIfNotInControl)
    DECL_THISCALL_TAIL(SetFall, extraTime, anim, evenIfNotInControl)
    DECL_THISCALL_HEAD(SetWanderPath, _ZN4CPed13SetWanderPathEa, bool, i8 direction)
    DECL_THISCALL_TAIL(SetWanderPath, direction)
    DECL_THISCALL_HEAD(SetFollowPath, _ZN4CPed13SetFollowPathERK7CVectorf10eMoveStateP7CEntityS5_i, bool, CVector const& destination, float distance, eMoveState moveState, CEntity* walkAround, CEntity* target, i32 time)
    DECL_THISCALL_TAIL(SetFollowPath, destination, distance, moveState, walkAround, target, time)
    DECL_THISCALL_HEAD(SetFormation, _ZN4CPed12SetFormationE10eFormation, void, eFormation formation)
    DECL_THISCALL_TAIL(SetFormation, formation)
    DECL_THISCALL_HEAD(SetNewAttraction, _ZN4CPed16SetNewAttractionEP13CPedAttractorRK7CVectorffi, void, CPedAttractor* attractor, CVector const& position, float heading, float distance, i32 queuePosition)
    DECL_THISCALL_TAIL(SetNewAttraction, attractor, position, heading, distance, queuePosition)
    DECL_THISCALL_HEAD(AttachPedToEntity, _ZN4CPed17AttachPedToEntityEP7CEntity7CVectortf11eWeaponType, void, CEntity* entity, CVector offset, u16 attachType, float rotation, eWeaponType weapon)
    DECL_THISCALL_TAIL(AttachPedToEntity, entity, offset, attachType, rotation, weapon)
    DECL_THISCALL_SIMPLE(DettachPedFromEntity, _ZN4CPed20DettachPedFromEntityEv, void);
    DECL_THISCALL_HEAD(StartFightAttack, _ZN4CPed16StartFightAttackEh, void, u8 buttonPressure)
    DECL_THISCALL_TAIL(StartFightAttack, buttonPressure)
    DECL_THISCALL_HEAD(StartFightDefend, _ZN4CPed16StartFightDefendEhhh, void, u8 direction, u8 hitLevel, u8 strength)
    DECL_THISCALL_TAIL(StartFightDefend, direction, hitLevel, strength)
    DECL_THISCALL_HEAD(EndFight, _ZN4CPed8EndFightEh, void, u8 endType)
    DECL_THISCALL_TAIL(EndFight, endType)
    DECL_THISCALL_HEAD(FightStrike, _ZN4CPed11FightStrikeER7CVectorb, bool, CVector& touchPoint, bool useWeapon)
    DECL_THISCALL_TAIL(FightStrike, touchPoint, useWeapon)
    DECL_THISCALL_HEAD(FightHitPed, _ZN4CPed11FightHitPedEPS_R7CVectorS2_s, void, CPed* ped, CVector& touchPoint, CVector& direction, i16 piece)
    DECL_THISCALL_TAIL(FightHitPed, ped, touchPoint, direction, piece)
    DECL_THISCALL_SIMPLE(SetFollowPathStatic, _ZN4CPed19SetFollowPathStaticEv, bool);
    DECL_THISCALL_SIMPLE(SetFollowPathDynamic, _ZN4CPed20SetFollowPathDynamicEv, bool);

    // Helper functions
    inline CWeapon* GetWeapon() { return &m_aWeapons[m_nCurrentWeapon]; }
    inline CWeapon const* GetWeapon() const { return &m_aWeapons[m_nCurrentWeapon]; }

    // Member values
    CStoredCollPoly m_polyColliding;
    float m_fCollisionSpeed;
    union
    {
        u8 m_nPedFlags[14];
        struct
        {
            u8 bIsStanding : 1;
            u8 bWasStanding : 1;
            u8 bIsAttacking : 1;
            u8 bIsPointingGunAt : 1;
            u8 bIsLooking : 1;
            u8 bKeepTryingToLook : 1;
            u8 bIsRestoringLook : 1;
            u8 bIsAimingGun : 1;
            u8 bIsRestoringGun : 1;
            u8 bCanPointGunAtTarget : 1;
            u8 bIsTalking : 1;
            u8 bIsInTheAir : 1;
            u8 bIsLanding : 1;
            u8 bIsRunning : 1;
            u8 bHitSomethingLastFrame : 1;
            u8 bVehEnterDoorIsBlocked : 1;
            u8 bCanPedEnterSeekedCar : 1;
            u8 bRespondsToThreats : 1;
            u8 bRenderPedInCar : 1;
            u8 bChangedSeat : 1;
            u8 bUpdateAnimHeading : 1;
            u8 bBodyPartJustCameOff : 1;
            u8 bFiringWeapon : 1;
            u8 bFindNewNodeAfterStateRestore : 1;
            u8 bHasACamera : 1;
            u8 bGonnaInvestigateEvent : 1;
            u8 bPedIsBleeding : 1;
            u8 bStopAndShoot : 1;
            u8 bIsPedDieAnimPlaying : 1;
            u8 bUsePedNodeSeek : 1;
            u8 bHasObjectiveCompleted : 1;
            u8 bScriptObjectiveCompleted : 1;
            u8 bKindaStayInSamePlace : 1;
            u8 bBeingChasedByPolice : 1;
            u8 bNotAllowedToDuck : 1;
            u8 bCrouchWhenShooting : 1;
            u8 bIsDucking : 1;
            u8 bGetUpAnimStarted : 1;
            u8 bDoBloodyFootprints : 1;
            u8 bFleeAfterExitingCar : 1;
            u8 bWanderPathAfterExitingCar : 1;
            u8 bIsLeader : 1;
            u8 bDontDragMeOutCar : 1;
            u8 bPedFlag44 : 1;
            u8 bWillBeQuickJacked : 1;
            u8 bCancelEnteringCar : 1;
            u8 bObstacleShowedUpDuringKillObjective : 1;
            u8 bDuckAndCover : 1;
            u8 bStillOnValidPoly : 1;
            u8 bAllowMedicsToReviveMe : 1;
            u8 bResetWalkAnims : 1;
            u8 bStartWanderPathOnFoot : 1;
            u8 bOnBoat : 1;
            u8 bBusJacked : 1;
            u8 bGonnaKillTheCarJacker : 1;
            u8 bFadeOut : 1;
            u8 bKnockedUpIntoAir : 1;
            u8 bHitSteepSlope : 1;
            u8 bCullExtraFarAway : 1;
            u8 bClearObjective : 1;
            u8 bTryingToReachDryLand : 1;
            u8 bCollidedWithMyVehicle : 1;
            u8 bRichFromMugging : 1;
            u8 bChrisCriminal : 1;
            u8 bShakeFist : 1;
            u8 bNoCriticalHits : 1;
            u8 bVehExitWillBeInstant : 1;
            u8 bHasAlreadyBeenRecorded : 1;
            u8 bFallenDown : 1;
            u8 bUpdateMatricesRequired : 1;
            u8 bReachedAttractorHeadingTarget : 1;
            u8 bTurnedAroundOnAttractor : 1;
            u8 bHasAlreadyUsedAttractor : 1;
            u8 bHasAlreadyStoleACar : 1;
            u8 bCarPassenger : 1;
            u8 bFleeWhenStanding : 1;
            u8 bGotUpOfMyOwnAccord : 1;
            u8 bMiamiViceCop : 1;
            u8 bMoneyHasBeenGivenByScript : 1;
            u8 bHasBeenPhotographed : 1;
            u8 bIsDrowning : 1;
            u8 bDrownsInWater : 1;
            u8 bStayBehindIfLeaderTooFar : 1;
            u8 bHeldHostageInCar : 1;
            u8 bScriptPedIsPlayerAlly : 1;
            u8 bHeadStuckInCollision : 1;
            u8 bDeadPedInFrontOfCar : 1;
            u8 bStayInCarOnJack : 1;
            u8 bDontFight : 1;
            u8 bDoomAim : 1;
            u8 bCanBeShotInVehicle : 1;
            u8 bCanGiveUpSunbathing : 1;
            u8 bMakeFleeScream : 1;
            u8 bPushedAlongByCar : 1;
            u8 bRemoveMeWhenIGotIntoCar : 1;
            u8 bIgnoreThreatsBehindObjects : 1;
            u8 bNeverEverTargetThisPed : 1;
            u8 bCrouchWhenScared : 1;
            u8 bKnockedOffBike : 1;
            u8 bPedFlag100 : 1;
            u8 bCollectBusFare : 1;
            u8 bBoughtIceCream : 1;
            u8 bPedWasSetOutOfCollision : 1;
            u8 bCanAttackPlayerWithCops : 1;
            u8 bAutoAimPriority : 1;
            u8 : 7;
        };
    };
    u8 m_nGangFlags;
    u16 : 0;
    u8 m_nPedStatus;
    eObjective m_nObjective;
    eObjective m_nPrevObjective;
    CEntity *m_pObjectiveEntity;
    CVehicle *m_pObjectiveVehicle;
    CVector m_vecObjective;
    float m_fObjectiveAngle;
    CPed *m_pGangLeader;
    eFormation m_nPedFormation;
    u32 m_nFearFlags;
    CEntity *m_pThreatEntity;
    CVector2D m_EventOrThreatPos;
    eEventType m_nEventType;
    CEntity *m_pEventEntity;
    float m_fAngleToEvent;
    AnimBlendFrameData* m_apFrames[18];
    RpAtomic *m_pCurWeaponAtomic;
    i32 m_nAnimGroupId;
    CAnimBlendAssociation* m_pVehicleAnim;
    CVector2D m_vecAnimMoveDelta;
    CVector m_vecOffsetSeek;
    CPedIK m_PedIK;
    CVector2D m_ActionPos;
    u32 m_nActionTimer;
    ePedState m_ePedState;
    ePedState m_eLastPedState;
    eMoveState m_eMoveState;
    eMoveState m_eStoredMoveState;
    eMoveState m_ePrevActionState;
    eWaitState m_nWaitState;
    u32 m_nWaitTimer;
    CPathNode *m_apPathNodesStates[8];
    u16 m_wPathNodes;
    i16 m_wCurPathNode;
    CEntity *m_pPathRelEntity;
    CEntity *m_pNextNodeEntity;
    u32 m_nPathNodeTimer;
    CPathNode m_aPathNodeStates[8];
    CPathNode *m_pCurNodeState;
    i8 m_nPathState;
    CPathNode *m_pLastPathNode;
    CPathNode *m_pNextPathNode;
    CVector m_vecPathNextNode;
    float m_fPathNextNodeDir;
    u32 m_nPathNodeType;
    float m_fHealth;
    float m_fArmour;
    u32 m_nShadowUpdateTimer;
    i16 wRouteLastPoint;
    u16 wRoutePoints;
    i16 wRoutePos;
    i16 wRouteType;
    i16 wRouteCurDir;
    CVector2D m_vecAnimMovingShift;
    float m_fHeadingCurrent;
    float m_fHeadingGoal;
    float m_fHeadingChangeRate;
    u16 m_nEnterType;
    i16 m_nWalkAroundType;
    CPhysical *m_pCurPhysSurface;
    CVector m_vecOffsetFromPhysSurface;
    CEntity *m_pCurSurface;
    CVector vecSeekVehicle;
    CEntity *m_pSeekTarget;
    CVehicle *m_pVehicle;
    bool m_bInVehicle;
    float m_fSeatPrecisionX;
    float m_fSeatPrecisionY;
    CVehicle *m_pFromVehicle;
    CPedAttractor* m_pSeat;
    i32 m_nSeatType;
    bool m_bHasPhone;
    i16 m_wPhoneId;
    i32 m_nLookingForPhone;
    u32 m_nPhoneTalkTimer;
    CAccident* m_pLastAccident;
    ePedType m_nPedType;
    CPedStats *m_pPedStats;
    float m_fFleeFromPosX;
    float m_fFleeFromPosY;
    CEntity *m_pFleeFrom;
    u32 m_nFleeTimer;
    CEntity *m_pThreatEx;
    CEntity *m_pLastThreatAt;
    u32 m_nLastThreatTimer;
    CVehicle *m_pVehicleColliding;
    u8 m_nStateUnused;
    i32 m_nTimerUnused;
    void *m_pTargetUnused;
    CWeapon m_aWeapons[10];
    i32 m_nAtchStoredWep;
    i32 m_nStoredGiveWep;
    i32 m_nStoredGiveAmmo;
    i8 m_nCurrentWeapon;
    u8 m_nMaxWeaponTypeAllowed;
    u8 m_nWepSkills;
    u8 m_nWeaponAccuracy;
    CEntity *m_pPointGunAt;
    float m_fWeaponLockOnTimer;
    CVector m_vecHitLastPos;
    u32 m_nCurrentFightMove;
    u32 m_nLastFightMove;
    u8 m_nFightFlags1;
    i8 m_nFightFlags2;
    u8 m_nFightFlags3; 
    u8 m_nBleedCounter;
    CFire *m_pPedFire;
    CEntity* m_pLookTarget;
    float m_fLookDirection;
    i32 m_nWepModelID;
    u32 m_nLeaveCarTimer;
    u32 m_nGetUpTimer;
    u32 m_nLookTimer;
    u32 m_nStandardTimer;
    u32 m_nAttackTimer;
    u32 m_nLastHitTime;
    u32 m_nHitRecoverTimer;
    u32 m_nObjectiveTimer;
    u32 m_nDuckTimer;
    u32 m_nDuckAndCoverTimer;
    u32 m_nBloodyTimer;
    u32 m_nShotTime;
    u32 m_nShotTimeAdd;
    u8 m_nPanicCounter;
    u8 m_nDeadBleeding;
    i8 m_nBodyPartBleeding;
    CPed *m_apNearPeds[10];
    u16 m_nNumNearPeds;
    u16 m_nPedMoney;
    i8 m_nLastDamWep;
    CEntity *m_pLastDamEntity;
    CEntity *m_pAttachedTo;
    CVector m_vecAttachOffset;
    u16 m_nAttachType;
    float m_fAttachRot;
    u32 m_nAttachWepAmmo;
    u32 m_nThreatFlags;
    u32 m_nThreatCheck;
    u32 m_nLastThreatCheck;
    i32 m_nSayType;
    u32 m_nSayTimer;
    u32 m_nTalkTimerLast;
    u32 m_nTalkTimer;
    i16 m_wTalkTypeLast;
    u16 m_wTalkType;
    bool m_bCanPedTalk;
    i32 m_nPedLastComment;
    CVector m_vecSeekPosEx;
    float m_fSeekExAngle;

DECL_CLASS_END()
CHECKSIZE(CPed, 0x5F8, 0x788);

#define ms_vec2DFleePosition ms_vec2DFleePosition()

#endif // __AML_PSDK_VCPED_H
