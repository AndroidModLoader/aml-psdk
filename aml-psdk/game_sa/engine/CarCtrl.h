#ifndef __AML_PSDK_SACARCTRL_H
#define __AML_PSDK_SACARCTRL_H

/*
    Plugin-SDK (Grand Theft Auto San Andreas) header file
    Authors: GTA Community. See more here
    https://github.com/DK22Pac/plugin-sdk
    Do not delete this comment block. Respect others' work!
*/

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/game_sa/engine/PathFind.h>

struct CEntity;
struct CPhysical;
struct CVehicle;
struct CAutomobile;
struct CPlane;
struct CHeli;

DECL_CLASS(CCarCtrl)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(GenerateRandomCars, _ZN8CCarCtrl18GenerateRandomCarsEv, void);
    DECL_FASTCALL_SIMPLE(GenerateOneRandomCar, _ZN8CCarCtrl20GenerateOneRandomCarEv, void);
    DECL_FASTCALL_SIMPLE(SetUpDriverAndPassengersForVehicle, _ZN8CCarCtrl34SetUpDriverAndPassengersForVehicleEP8CVehicleiibbi, void,
        CVehicle* pVehicle, i32 arg2, i32 arg3, bool arg4, bool arg5, i32 passengersNum);
    DECL_FASTCALL_SIMPLE(CreateCarForScript, _ZN8CCarCtrl18CreateCarForScriptEi7CVectorh, CVehicle*, i32 modelid, CVector posn, u8 MissionCleanUpFlag);
    DECL_FASTCALL_SIMPLE(SetCoordsOfScriptCar, _ZN8CCarCtrl20SetCoordsOfScriptCarEP8CVehiclefffhh, void,
        CVehicle* pVehicle, float x, float y, float z, u8 arg5, u8 arg6);
    DECL_FASTCALL_SIMPLE(ChooseModel, _ZN8CCarCtrl11ChooseModelEPi, i32, i32* arg1);
    DECL_FASTCALL_SIMPLE(RemoveDistantCars, _ZN8CCarCtrl17RemoveDistantCarsEv, void);
    DECL_FASTCALL_SIMPLE(RemoveCarsIfThePoolGetsFull, _ZN8CCarCtrl27RemoveCarsIfThePoolGetsFullEv, void);
    DECL_FASTCALL_SIMPLE(PossiblyRemoveVehicle, _ZN8CCarCtrl21PossiblyRemoveVehicleEP8CVehicle, void, CVehicle* pVehicle);
    DECL_FASTCALL_SIMPLE(UpdateCarOnRails, _ZN8CCarCtrl16UpdateCarOnRailsEP8CVehicle, void, CVehicle* pVehicle);
    DECL_FASTCALL_SIMPLE(FindMaximumSpeedForThisCarInTraffic, _ZN8CCarCtrl35FindMaximumSpeedForThisCarInTrafficEP8CVehicle, float, CVehicle* pVehicle);
    DECL_FASTCALL_SIMPLE(ScanForPedDanger, _ZN8CCarCtrl16ScanForPedDangerEP8CVehicle, void, CVehicle* pVehicle);
    DECL_FASTCALL_SIMPLE(SlowCarOnRailsDownForTrafficAndLights, _ZN8CCarCtrl37SlowCarOnRailsDownForTrafficAndLightsEP8CVehicle, void, CVehicle* pVehicle);
    DECL_FASTCALL_SIMPLE(SlowCarDownForPedsSectorList, _ZN8CCarCtrl28SlowCarDownForPedsSectorListER8CPtrListP8CVehicleffffPff, void,
        CPtrList& PtrList, CVehicle* pVehicle, float arg3, float arg4, float arg5, float arg6, float* arg7, float arg8);
    DECL_FASTCALL_SIMPLE(SlowCarDownForCarsSectorList, _ZN8CCarCtrl28SlowCarDownForCarsSectorListER8CPtrListP8CVehicleffffPff, void,
        CPtrList& PtrList, CVehicle* pVehicle, float arg3, float arg4, float arg5, float arg6, float* arg7, float arg8);
    DECL_FASTCALL_SIMPLE(SlowCarDownForOtherCar, _ZN8CCarCtrl22SlowCarDownForOtherCarEP7CEntityP8CVehiclePff, void,
        CEntity* pCar1, CVehicle* pCar2, float* arg3, float arg4);
    DECL_FASTCALL_SIMPLE(TestCollisionBetween2MovingRects, _ZN8CCarCtrl32TestCollisionBetween2MovingRectsEP8CVehicleS1_ffP7CVectorS3_, float,
        CVehicle* pVehicle1, CVehicle* pVehicle2, float arg3, float arg4, CVector* pVector1, CVector* pVector2);
    DECL_FASTCALL_SIMPLE(TestCollisionBetween2MovingRects_OnlyFrontBumper, _ZN8CCarCtrl48TestCollisionBetween2MovingRects_OnlyFrontBumperEP8CVehicleS1_ffP7CVectorS3_, float,
        CVehicle* pVehicle1, CVehicle* pVehicle2, float arg3, float arg4, CVector* pVector1, CVector* pVector2);
    DECL_FASTCALL_SIMPLE(SlowCarDownForObjectsSectorList, _ZN8CCarCtrl31SlowCarDownForObjectsSectorListER8CPtrListP8CVehicleffffPff, void,
        CPtrList& PtrList, CVehicle* pVehicle, float arg3, float arg4, float arg5, float arg6, float* arg7, float arg8);
    DECL_FASTCALL_SIMPLE(SlowCarDownForObject, _ZN8CCarCtrl20SlowCarDownForObjectEP7CEntityP8CVehiclePff, void,
        CEntity* pEntity, CVehicle* pVehicle, float* arg3, float arg4);
    DECL_FASTCALL_SIMPLE(FindAngleToWeaveThroughTraffic, _ZN8CCarCtrl30FindAngleToWeaveThroughTrafficEP8CVehicleP9CPhysicalfff, float,
        CVehicle* pVehicle, CPhysical* pPhysical, float arg3, float arg4, float arg5);
    DECL_FASTCALL_SIMPLE(WeaveThroughCarsSectorList, _ZN8CCarCtrl26WeaveThroughCarsSectorListER8CPtrListP8CVehicleP9CPhysicalffffPfS6_, void,
        CPtrList& PtrList, CVehicle* pVehicle, CPhysical* pPhysical, float arg4, float arg5, float arg6, float arg7, float* arg8, float* arg9);
    DECL_FASTCALL_SIMPLE(WeaveForOtherCar, _ZN8CCarCtrl16WeaveForOtherCarEP7CEntityP8CVehiclePfS4_, void,
        CEntity* pEntity, CVehicle* pVehicle, float* arg3, float* arg4);
    DECL_FASTCALL_SIMPLE(WeaveThroughPedsSectorList, _ZN8CCarCtrl26WeaveThroughPedsSectorListER8CPtrListP8CVehicleP9CPhysicalffffPfS6_, void,
        CPtrList& PtrList, CVehicle* pVehicle, CPhysical* pPhysical, float arg4, float arg5, float arg6, float arg7, float* arg8, float* arg9);
    DECL_FASTCALL_SIMPLE(WeaveForPed, _ZN8CCarCtrl11WeaveForPedEP7CEntityP8CVehiclePfS4_, void, CEntity* pEntity, CVehicle* pVehicle, float* pLeft, float* pRight);
    DECL_FASTCALL_SIMPLE(WeaveThroughObjectsSectorList, _ZN8CCarCtrl29WeaveThroughObjectsSectorListER8CPtrListP8CVehicleffffPfS4_, void,
        CPtrList& PtrList, CVehicle* pVehicle, float arg3, float arg4, float arg5, float arg6, float* arg7, float* arg8);
    DECL_FASTCALL_SIMPLE(WeaveForObject, _ZN8CCarCtrl14WeaveForObjectEP7CEntityP8CVehiclePfS4_, void,
        CEntity* pEntity, CVehicle* pVehicle, float* arg3, float* arg4);
    DECL_FASTCALL_SIMPLE(PickNextNodeAccordingStrategy, _ZN8CCarCtrl29PickNextNodeAccordingStrategyEP8CVehicle, bool, CVehicle* pVehicle);
    DECL_FASTCALL_SIMPLE(IsThisAnAppropriateNode, _ZN8CCarCtrl23IsThisAnAppropriateNodeEP8CVehicle12CNodeAddressS2_S2_bb, bool,
        CVehicle* pVehicle, CNodeAddress NodeAddress1, CNodeAddress NodeAddress2, CNodeAddress NodeAddress3, bool arg5, bool arg6);
    DECL_FASTCALL_SIMPLE(PickNextNodeForPlayer, _ZN8CCarCtrl21PickNextNodeForPlayerEP8CVehicle, void, CVehicle* pVehicle);
    DECL_FASTCALL_SIMPLE(PickNextNodeRandomly, _ZN8CCarCtrl20PickNextNodeRandomlyEP8CVehicle, void, CVehicle* pVehicle);
    DECL_FASTCALL_SIMPLE(ThisVehicleShouldTryNotToTurn, _ZN8CCarCtrl29ThisVehicleShouldTryNotToTurnEP8CVehicle, bool, CVehicle* pVehicle);
    DECL_FASTCALL_SIMPLE(FindPathDirection, _ZN8CCarCtrl17FindPathDirectionE12CNodeAddressS0_S0_Pb, u8,
        CNodeAddress NodeAddress1, CNodeAddress NodeAddress2, CNodeAddress NodeAddress3, bool* arg4);
    DECL_FASTCALL_SIMPLE(PickNextNodeToChaseCar, _ZN8CCarCtrl22PickNextNodeToChaseCarEP8CVehiclefffS1_, bool,
        CVehicle* pVehicle, float x_dest, float y_dest, float z_dest, CVehicle* arg5);
    DECL_FASTCALL_SIMPLE(PickNextNodeToFollowPath, _ZN8CCarCtrl24PickNextNodeToFollowPathEP8CVehicle, bool, CVehicle* pVehicle);
    DECL_FASTCALL_SIMPLE(Init, _ZN8CCarCtrl4InitEv, void);
    DECL_FASTCALL_SIMPLE(ReInit, _ZN8CCarCtrl6ReInitEv, void);
    DECL_FASTCALL_SIMPLE(SwitchBetweenPhysicsAndGhost, _ZN8CCarCtrl28SwitchBetweenPhysicsAndGhostEP8CVehicle, void, CVehicle* pVehicle);
    DECL_FASTCALL_SIMPLE(FindGhostRoadHeight, _ZN8CCarCtrl19FindGhostRoadHeightEP8CVehicle, float, CVehicle* pVehicle);
    DECL_FASTCALL_SIMPLE(DragCarToPoint, _ZN8CCarCtrl14DragCarToPointEP8CVehicleP7CVector, void, CVehicle* pVehicle, CVector* pVector);
    DECL_FASTCALL_SIMPLE(FindSpeedMultiplier, _ZN8CCarCtrl19FindSpeedMultiplierEffff, float, float arg1, float arg2, float arg3, float arg4);
    DECL_FASTCALL_SIMPLE(JoinCarWithRoadAccordingToMission, _ZN8CCarCtrl33JoinCarWithRoadAccordingToMissionEP8CVehicle, void, CVehicle* pVehicle);
    DECL_FASTCALL_SIMPLE(SteerAICarWithPhysics, _ZN8CCarCtrl21SteerAICarWithPhysicsEP8CVehicle, void, CVehicle* pVehicle);
    DECL_FASTCALL_SIMPLE(SteerAICarWithPhysics_OnlyMission, _ZN8CCarCtrl33SteerAICarWithPhysics_OnlyMissionEP8CVehiclePfS2_S2_Pb, void,
        CVehicle* pVehicle, float* arg2, float* arg3, float* arg4, bool* arg5);
    DECL_FASTCALL_SIMPLE(FindMaxSteerAngle, _ZN8CCarCtrl17FindMaxSteerAngleEP8CVehicle, float, CVehicle* pVehicle);
    DECL_FASTCALL_SIMPLE(StopCarIfNodesAreInvalid, _ZN8CCarCtrl24StopCarIfNodesAreInvalidEP8CVehicle, bool, CVehicle* pVehicle);
    DECL_FASTCALL_SIMPLE(SteerAICarWithPhysicsFollowPath, _ZN8CCarCtrl31SteerAICarWithPhysicsFollowPathEP8CVehiclePfS2_S2_Pb, void,
        CVehicle* pVehicle, float* arg2, float* arg3, float* arg4, bool* arg5);
    DECL_FASTCALL_SIMPLE(SteerPlayerWhilstCruising, _ZN8CCarCtrl25SteerPlayerWhilstCruisingEP8CVehiclePfS2_S2_Pb, void,
        CVehicle* pVehicle, float* arg2, float* arg3, float* arg4, bool* arg5);
    DECL_FASTCALL_SIMPLE(SteerAICarWithPhysicsFollowPath_Racing, _ZN8CCarCtrl38SteerAICarWithPhysicsFollowPath_RacingEP8CVehiclePfS2_S2_Pb, void,
        CVehicle* pVehicle, float* arg2, float* arg3, float* arg4, bool* arg5);
    DECL_FASTCALL_SIMPLE(DealWithBend_Racing, _ZN8CCarCtrl19DealWithBend_RacingEP8CVehicle12CLinkAddressS2_S2_S2_aaaafPfS3_S3_S3_P7CVector, bool,
        CVehicle* pVehicle, CLinkAddress LinkAddress1, CLinkAddress LinkAddress2, CLinkAddress LinkAddress3, CLinkAddress LinkAddress4, i8 arg6, i8 arg7, i8 arg8, i8 arg9, float arg10, float* arg11, float* arg12, float* arg13, float* arg14, CVector* pVector);
    DECL_FASTCALL_SIMPLE(FindPercDependingOnDistToLink, _ZN8CCarCtrl29FindPercDependingOnDistToLinkEP8CVehicle12CLinkAddress, float,
        CVehicle* pVehicle, CLinkAddress LinkAddress);
    DECL_FASTCALL_SIMPLE(FindIntersection2Lines, _ZN8CCarCtrl22FindIntersection2LinesEffffffffPfS0_, void,
        float arg1, float arg2, float arg3, float arg4, float arg5, float arg6, float arg7, float arg8, float* arg9, float* arg10);
    DECL_FASTCALL_SIMPLE(ClipTargetOrientationToLink, _ZN8CCarCtrl27ClipTargetOrientationToLinkEP8CVehicle12CLinkAddressaPfff, void,
        CVehicle* pVehicle, CLinkAddress arg2, i8 arg3, float* arg4, float arg5, float arg6);
    DECL_FASTCALL_SIMPLE(SteerAICarWithPhysicsFollowPreRecordedPath, _ZN8CCarCtrl42SteerAICarWithPhysicsFollowPreRecordedPathEP8CVehiclePfS2_S2_Pb, void,
        CVehicle* pVehicle, float* arg2, float* arg3, float* arg4, bool* arg5);
    DECL_FASTCALL_SIMPLE(SteerAICarWithPhysicsHeadingForTarget, _ZN8CCarCtrl37SteerAICarWithPhysicsHeadingForTargetEP8CVehicleP9CPhysicalffPfS4_S4_Pb, void,
        CVehicle* pVehicle, CPhysical* pTarget, float arg3, float arg4, float* arg5, float* arg6, float* arg7, bool* arg8);
    DECL_FASTCALL_SIMPLE(SteerAICarWithPhysicsTryingToBlockTarget, _ZN8CCarCtrl40SteerAICarWithPhysicsTryingToBlockTargetEP8CVehicleP7CEntityffffPfS4_S4_Pb, void,
        CVehicle* pVehicle, CEntity* Unusued, float arg3, float arg4, float arg5, float arg6, float* arg7, float* arg8, float* arg9, bool* arg10);
    DECL_FASTCALL_SIMPLE(SteerAICarWithPhysicsTryingToBlockTarget_Stop, _ZN8CCarCtrl45SteerAICarWithPhysicsTryingToBlockTarget_StopEP8CVehicleffffPfS2_S2_Pb, void,
        CVehicle* pVehicle, float x, float y, float arg4, float arg5, float* arg6, float* arg7, float* arg8, bool* arg9);
    DECL_FASTCALL_SIMPLE(SteerAICarBlockingPlayerForwardAndBack, _ZN8CCarCtrl38SteerAICarBlockingPlayerForwardAndBackEP8CVehiclePfS2_S2_Pb, void,
        CVehicle* pVehicle, float* arg2, float* arg3, float* arg4, bool* arg5);
    DECL_FASTCALL_SIMPLE(SteerAICarTowardsPointInEscort, _ZN8CCarCtrl30SteerAICarTowardsPointInEscortEP8CVehicleS1_ffPfS2_S2_Pb, void,
        CVehicle* pVehicle1, CVehicle* pVehicle2, float arg3, float arg4, float* arg5, float* arg6, float* arg7, bool* arg8);
    DECL_FASTCALL_SIMPLE(SteerAICarParkParallel, _ZN8CCarCtrl22SteerAICarParkParallelEP8CVehiclePfS2_S2_Pb, void,
        CVehicle* pVehicle, float* arg2, float* arg3, float* arg4, bool* arg5);
    DECL_FASTCALL_SIMPLE(SteerAICarParkPerpendicular, _ZN8CCarCtrl27SteerAICarParkPerpendicularEP8CVehiclePfS2_S2_Pb, void,
        CVehicle* pVehicle, float* arg2, float* arg3, float* arg4, bool* arg5);
    DECL_FASTCALL_SIMPLE(SteerAIBoatWithPhysicsHeadingForTarget, _ZN8CCarCtrl38SteerAIBoatWithPhysicsHeadingForTargetEP8CVehicleffPfS2_S2_, void,
        CVehicle* pVehicle, float arg2, float arg3, float* arg4, float* arg5, float* arg6);
    DECL_FASTCALL_SIMPLE(SteerAIBoatWithPhysicsAttackingPlayer, _ZN8CCarCtrl37SteerAIBoatWithPhysicsAttackingPlayerEP8CVehiclePfS2_S2_Pb, void,
        CVehicle* pVehicle, float* arg2, float* arg3, float* arg4, bool* arg5);
    DECL_FASTCALL_SIMPLE(SteerAIBoatWithPhysicsCirclingPlayer, _ZN8CCarCtrl36SteerAIBoatWithPhysicsCirclingPlayerEP8CVehiclePfS2_S2_Pb, void,
        CVehicle* pVehicle, float* arg2, float* arg3, float* arg4, bool* arg5);
    DECL_FASTCALL_SIMPLE(FlyAIPlaneInCertainDirection, _ZN8CCarCtrl28FlyAIPlaneInCertainDirectionEP6CPlane, void, CPlane* pPlane);
    DECL_FASTCALL_SIMPLE(TriggerDogFightMoves, _ZN8CCarCtrl20TriggerDogFightMovesEP8CVehicleS1_, void, CVehicle* pVehicle1, CVehicle* pVehicle2);
    DECL_FASTCALL_SIMPLE(TestWhetherToFirePlaneGuns, _ZN8CCarCtrl26TestWhetherToFirePlaneGunsEP8CVehicleP7CEntity, void, CVehicle* pVehicle, CEntity* pTarget);
    DECL_FASTCALL_SIMPLE(PossiblyFireHSMissile, _ZN8CCarCtrl21PossiblyFireHSMissileEP8CVehicleP7CEntity, void, CVehicle* pEntityLauncher, CEntity* pTargetEntity);
    DECL_FASTCALL_SIMPLE(SteerAIPlaneTowardsTargetCoors, _ZN8CCarCtrl30SteerAIPlaneTowardsTargetCoorsEP11CAutomobile, void, CAutomobile* pAutomobile);
    DECL_FASTCALL_SIMPLE(GetAIPlaneToAttackPlayer, _ZN8CCarCtrl24GetAIPlaneToAttackPlayerEP11CAutomobile, void, CAutomobile* pAutomobile);
    DECL_FASTCALL_SIMPLE(GetAIPlaneToDoDogFightAgainstPlayer, _ZN8CCarCtrl35GetAIPlaneToDoDogFightAgainstPlayerEP11CAutomobile, void, CAutomobile* pAutomobile);
    DECL_FASTCALL_SIMPLE(GetAIPlaneToDoDogFight, _ZN8CCarCtrl22GetAIPlaneToDoDogFightEP11CAutomobile, void, CAutomobile* pAutomobile);
    DECL_FASTCALL_SIMPLE(GetAIPlaneToFlyInDirection, _ZN8CCarCtrl26GetAIPlaneToFlyInDirectionEP11CAutomobile, void, CAutomobile* pAutomobile);
    DECL_FASTCALL_SIMPLE(SteerAIPlaneToFollowEntity, _ZN8CCarCtrl26SteerAIPlaneToFollowEntityEP11CAutomobile, void, CAutomobile* pAutomobile);
    DECL_FASTCALL_SIMPLE(SteerAIPlaneToCrashAndBurn, _ZN8CCarCtrl26SteerAIPlaneToCrashAndBurnEP11CAutomobile, void, CAutomobile* pAutomobile);
    DECL_FASTCALL_SIMPLE(SteerAIHeliToCrashAndBurn, _ZN8CCarCtrl25SteerAIHeliToCrashAndBurnEP11CAutomobile, void, CAutomobile* pAutomobile);
    DECL_FASTCALL_SIMPLE(FlyAIHeliInCertainDirection, _ZN8CCarCtrl27FlyAIHeliInCertainDirectionEP5CHeliffb, void, CHeli* pHeli, float arg2, float arg3, bool arg4);
    DECL_FASTCALL_SIMPLE(FlyAIHeliToTarget_FixedOrientation, _ZN8CCarCtrl34FlyAIHeliToTarget_FixedOrientationEP5CHelif7CVectorb, void,
        CHeli* pHeli, float Orientation, CVector posn, bool arg4);
    DECL_FASTCALL_SIMPLE(SteerAIHeliTowardsTargetCoors, _ZN8CCarCtrl29SteerAIHeliTowardsTargetCoorsEP11CAutomobile, void, CAutomobile* pAutomobile);
    DECL_FASTCALL_SIMPLE(GetAIHeliToAttackPlayer, _ZN8CCarCtrl23GetAIHeliToAttackPlayerEP11CAutomobile, void, CAutomobile* pAutomobile);
    DECL_FASTCALL_SIMPLE(GetAIHeliToFlyInDirection, _ZN8CCarCtrl25GetAIHeliToFlyInDirectionEP11CAutomobile, void, CAutomobile* pAutomobile);
    DECL_FASTCALL_SIMPLE(SteerAIHeliToFollowEntity, _ZN8CCarCtrl25SteerAIHeliToFollowEntityEP11CAutomobile, void, CAutomobile* pAutomobile);
    DECL_FASTCALL_SIMPLE(SteerAIHeliAsPoliceHeli, _ZN8CCarCtrl23SteerAIHeliAsPoliceHeliEP11CAutomobile, void, CAutomobile* pAutomobile);
    DECL_FASTCALL_SIMPLE(SteerAIHeliFlyingAwayFromPlayer, _ZN8CCarCtrl31SteerAIHeliFlyingAwayFromPlayerEP11CAutomobile, void, CAutomobile* pAutomobile);
    DECL_FASTCALL_SIMPLE(SteerAIHeliToLand, _ZN8CCarCtrl17SteerAIHeliToLandEP11CAutomobile, void, CAutomobile* pAutomobile);
    DECL_FASTCALL_SIMPLE(SteerAIHeliToKeepEntityInView, _ZN8CCarCtrl29SteerAIHeliToKeepEntityInViewEP11CAutomobile, void, CAutomobile* pAutomobile);
    DECL_FASTCALL_SIMPLE(FireHeliRocketsAtTarget, _ZN8CCarCtrl23FireHeliRocketsAtTargetEP11CAutomobileP7CEntity, void,
        CAutomobile* pEntityLauncher, CEntity* pEntity);
    DECL_FASTCALL_SIMPLE(RegisterVehicleOfInterest, _ZN8CCarCtrl25RegisterVehicleOfInterestEP8CVehicle, void, CVehicle* pVehicle);
    DECL_FASTCALL_SIMPLE(IsThisVehicleInteresting, _ZN8CCarCtrl24IsThisVehicleInterestingEP8CVehicle, u8, CVehicle* pVehicle);
    DECL_FASTCALL_SIMPLE(RemoveFromInterestingVehicleList, _ZN8CCarCtrl32RemoveFromInterestingVehicleListEP8CVehicle, void, CVehicle* pVehicle);
    DECL_FASTCALL_SIMPLE(ClearInterestingVehicleList, _ZN8CCarCtrl27ClearInterestingVehicleListEv, void);
    DECL_FASTCALL_SIMPLE(PruneVehiclesOfInterest, _ZN8CCarCtrl23PruneVehiclesOfInterestEv, void);
    DECL_FASTCALL_SIMPLE(IsThisVehicleOnRadar, _ZN8CCarCtrl20IsThisVehicleOnRadarEP8CVehiclePi, u8, CVehicle* pVehicle, i32* pRadarId);
    DECL_FASTCALL_SIMPLE(SwitchVehicleToRealPhysics, _ZN8CCarCtrl26SwitchVehicleToRealPhysicsEP8CVehicle, void, CVehicle* pVehicle);
    DECL_FASTCALL_SIMPLE(JoinCarWithRoadSystem, _ZN8CCarCtrl21JoinCarWithRoadSystemEP8CVehicle, void, CVehicle* pVehicle);
    DECL_FASTCALL_SIMPLE(JoinCarWithRoadSystemGotoCoors, _ZN8CCarCtrl30JoinCarWithRoadSystemGotoCoorsEP8CVehicleRK7CVectorbb, u8,
        CVehicle* pVehicle, CVector const& posn, bool unused, bool bIsBoat);
    DECL_FASTCALL_SIMPLE(FindLinksToGoWithTheseNodes, _ZN8CCarCtrl27FindLinksToGoWithTheseNodesEP8CVehicle, void, CVehicle* pVehicle);
    DECL_FASTCALL_SIMPLE(ChooseCarModelToLoad, _ZN8CCarCtrl20ChooseCarModelToLoadEi, i32, i32 arg1);
    DECL_FASTCALL_SIMPLE(ChooseBoatModel, _ZN8CCarCtrl15ChooseBoatModelEv, i32);
    DECL_FASTCALL_SIMPLE(ChoosePoliceCarModel, _ZN8CCarCtrl20ChoosePoliceCarModelEj, i32, u32 arg0);
    DECL_FASTCALL_SIMPLE(ChooseGangCarModel, _ZN8CCarCtrl18ChooseGangCarModelEi, i32, i32 arg1);
    DECL_FASTCALL_SIMPLE(GenerateEmergencyServicesCar, _ZN8CCarCtrl28GenerateEmergencyServicesCarEv, void);
    DECL_FASTCALL_SIMPLE(GenerateOneEmergencyServicesCar, _ZN8CCarCtrl31GenerateOneEmergencyServicesCarEj7CVector, CAutomobile*, u32 modelID, CVector posn);
    DECL_FASTCALL_SIMPLE(ScriptGenerateOneEmergencyServicesCar, _ZN8CCarCtrl37ScriptGenerateOneEmergencyServicesCarEj7CVector, bool, u32 modelID, CVector posn);
    DECL_FASTCALL_SIMPLE(UpdateCarCount, _ZN8CCarCtrl14UpdateCarCountEP8CVehicleh, void, CVehicle* pVehicle, u8 bDecrease);
    DECL_FASTCALL_SIMPLE(ThisRoadObjectCouldMove, _ZN8CCarCtrl23ThisRoadObjectCouldMoveEj, bool, u32 modelId);
    DECL_FASTCALL_SIMPLE(MapCouldMoveInThisArea, _ZN8CCarCtrl22MapCouldMoveInThisAreaEff, bool, float x, float y);
    DECL_FASTCALL_SIMPLE(BoatWithTallMast, _ZN8CCarCtrl16BoatWithTallMastEj, bool, u32 modelId);
    DECL_FASTCALL_SIMPLE(GetNewVehicleDependingOnCarModel, _ZN8CCarCtrl32GetNewVehicleDependingOnCarModelEih, CVehicle*, i32 modelID, u8 createdBy);
    DECL_FASTCALL_SIMPLE(InitSequence, _ZN8CCarCtrl12InitSequenceEi, void, i32 SequenceElements);
    DECL_FASTCALL_SIMPLE(FindSequenceElement, _ZN8CCarCtrl19FindSequenceElementEi, i32, i32 arg1);
    DECL_FASTCALL_SIMPLE(GenerateCarCreationCoors2, _ZN8CCarCtrl25GenerateCarCreationCoors2E7CVectorfffbffPS0_P12CNodeAddressS3_Pfbb, bool,
        CVector posn, float radius, float arg3, float arg4, bool arg5, float arg6, float arg7, CVector* pOrigin, CNodeAddress* pNodeAddress1, CNodeAddress* pNodeAddress12, float* arg11, bool arg12, bool arg13);
    DECL_FASTCALL_SIMPLE(ReconsiderRoute, _ZN8CCarCtrl15ReconsiderRouteEP8CVehicle, void, CVehicle* pVehicle);
    DECL_FASTCALL_SIMPLE(FindNodesThisCarIsNearestTo, _ZN8CCarCtrl27FindNodesThisCarIsNearestToEP8CVehicleR12CNodeAddressS3_, void,
        CVehicle* pVehicle, CNodeAddress& NodeAddress1, CNodeAddress& NodeAddress2);
    DECL_FASTCALL_SIMPLE(IsAnyoneParking, _ZN8CCarCtrl15IsAnyoneParkingEv, bool);
    DECL_FASTCALL_SIMPLE(CreatePoliceChase, _ZN8CCarCtrl17CreatePoliceChaseEP8CVehiclei12CNodeAddress, bool,
        CVehicle* pVehicle, i32 arg2, CNodeAddress NodeAddress);
    DECL_FASTCALL_SIMPLE(CreateConvoy, _ZN8CCarCtrl12CreateConvoyEP8CVehiclei, bool, CVehicle* pVehicle, i32 arg2);
    DECL_FASTCALL_SIMPLE(IsPoliceVehicleInPursuit, _ZN8CCarCtrl24IsPoliceVehicleInPursuitEi, bool, i32 maxDistance);
    DECL_FASTCALL_SIMPLE(FindSpeedMultiplierWithSpeedFromNodes, _ZN8CCarCtrl37FindSpeedMultiplierWithSpeedFromNodesEa, float, i8 arg1);

    // STATIC values
    DECL_OBJECT_PLT(float, CarDensityMultiplier, BYBIT(0x678D18, 0x84FA58));
    DECL_OBJECT_PLT(i32, NumRandomCars, BYBIT(0x676658, 0x84AD08));
    DECL_OBJECT_PLT(i32, NumLawEnforcerCars, BYBIT(0x679550, 0x850AB0));
    DECL_OBJECT_PLT(i32, NumMissionCars, BYBIT(0x678174, 0x84E300));
    DECL_OBJECT_PLT(i32, NumParkedCars, BYBIT(0x677AB8, 0x84D598));
    DECL_OBJECT_PLT(i32, NumPermanentVehicles, BYBIT(0x679B78, 0x851710));
    DECL_OBJECT_PLT(i32, NumAmbulancesOnDuty, BYBIT(0x676608, 0x84AC68));
    DECL_OBJECT_PLT(i32, NumFireTrucksOnDuty, BYBIT(0x677018, 0x84C068));
    DECL_OBJECT_PLT(u32, LastTimeAmbulanceCreated, BYBIT(0x677DB4, 0x84DB88));
    DECL_OBJECT_PLT(u32, LastTimeFireTruckCreated, BYBIT(0x676240, 0x84A4E0));
    DECL_OBJECT_PLT(u32, LastTimeLawEnforcerCreated, BYBIT(0x678B58, 0x84F6D8));
    DECL_OBJECT_PLT(float, TimeNextMadDriverChaseCreated, BYBIT(0x678120, 0x84E258));
    DECL_OBJECT_PLT(u8, CountDownToCarsAtStart, BYBIT(0x6765C0, 0x84ABD8));
    DECL_OBJECT_PLT(bool, bCarsGeneratedAroundCamera, BYBIT(0x677A3C, 0x84D4A0));
    DECL_OBJECT_PLT(i32, MaxNumberOfCarsInUse, BYBIT(0x677054, 0x84C0E0));
    DECL_OBJECT_SYM(i32, MiamiViceCycle, _ZN8CCarCtrl14MiamiViceCycleE);
    DECL_OBJECT_SYM(u32, LastTimeMiamiViceGenerated, _ZN8CCarCtrl26LastTimeMiamiViceGeneratedE);
    DECL_OBJECT_PLT(bool, bAllowEmergencyServicesToBeCreated, BYBIT(0x677D84, 0x84DB28));
    DECL_OBJECT_PLT(bool, bCarIsBeingCreated, BYBIT(0x676550, 0x84AAF8));
DECL_CLASS_END()
CHECKSIZE(CCarCtrl, 0x1, 0x1);

#define CarDensityMultiplier CarDensityMultiplier()
#define NumRandomCars NumRandomCars()
#define NumLawEnforcerCars NumLawEnforcerCars()
#define NumMissionCars NumMissionCars()
#define NumParkedCars NumParkedCars()
#define NumPermanentVehicles NumPermanentVehicles()
#define NumAmbulancesOnDuty NumAmbulancesOnDuty()
#define NumFireTrucksOnDuty NumFireTrucksOnDuty()
#define LastTimeAmbulanceCreated LastTimeAmbulanceCreated()
#define LastTimeFireTruckCreated LastTimeFireTruckCreated()
#define LastTimeLawEnforcerCreated LastTimeLawEnforcerCreated()
#define TimeNextMadDriverChaseCreated TimeNextMadDriverChaseCreated()
#define CountDownToCarsAtStart CountDownToCarsAtStart()
#define bCarsGeneratedAroundCamera bCarsGeneratedAroundCamera()
#define MaxNumberOfCarsInUse MaxNumberOfCarsInUse()
#define MiamiViceCycle MiamiViceCycle()
#define LastTimeMiamiViceGenerated LastTimeMiamiViceGenerated()
#define bAllowEmergencyServicesToBeCreated bAllowEmergencyServicesToBeCreated()
#define bCarIsBeingCreated bCarIsBeingCreated()

#endif // __AML_PSDK_SACARCTRL_H
