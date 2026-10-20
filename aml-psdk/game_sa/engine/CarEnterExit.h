#ifndef __AML_PSDK_SACARENTEREXIT_H
#define __AML_PSDK_SACARENTEREXIT_H

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/gta_base/Vector.h>

struct CPed;
struct CVehicle;
struct CEntity;
struct CTask;

DECL_CLASS(CCarEnterExit)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(GetNearestCarPassengerDoor, _ZN13CCarEnterExit26GetNearestCarPassengerDoorERK4CPedRK8CVehicleR7CVectorRibbb, bool, CPed const& ped, CVehicle const& vehicle, CVector& outPos, i32& doorId, bool const checkTandemSeats, bool const checkOccupiedSeats, bool const checkDoorInUse);
    DECL_FASTCALL_SIMPLE(GetNearestCarDoor, _ZN13CCarEnterExit17GetNearestCarDoorERK4CPedRK8CVehicleR7CVectorRi, bool, CPed const& ped, CVehicle const& vehicle, CVector& outPos, i32& doorId);
    DECL_FASTCALL_SIMPLE(ComputeDoorFlag, _ZN13CCarEnterExit15ComputeDoorFlagERK8CVehicleib, i32, CVehicle const& vehicle, i32 const doorId, bool const checkVehicleType);
    DECL_FASTCALL_SIMPLE(ComputeOppositeDoorFlag, _ZN13CCarEnterExit23ComputeOppositeDoorFlagERK8CVehicleib, i32, CVehicle const& vehicle, i32 const doorId, bool const checkVehicleType);
    DECL_FASTCALL_SIMPLE(IsDriverDoorFlag, _ZN13CCarEnterExit16IsDriverDoorFlagERK8CVehiclehb, bool, CVehicle const& vehicle, u8 const doorFlag, bool const checkVehicleType);
    DECL_FASTCALL_SIMPLE(IsRoomForPedToLeaveCar, _ZN13CCarEnterExit22IsRoomForPedToLeaveCarERK8CVehicleiP7CVector, bool, CVehicle const& vehicle, i32 const doorId, CVector* pos);
    DECL_FASTCALL_SIMPLE(GetPositionToOpenCarDoor, _ZN13CCarEnterExit24GetPositionToOpenCarDoorERK8CVehiclei, CVector, CVehicle const& vehicle, i32 const doorId);
    DECL_FASTCALL_SIMPLE(IsCarDoorInUse, _ZN13CCarEnterExit14IsCarDoorInUseERK8CVehicleii, bool, CVehicle const& vehicle, i32 const door1Id, i32 const door2Id);
    DECL_FASTCALL_SIMPLE(IsCarDoorReady, _ZN13CCarEnterExit14IsCarDoorReadyERK8CVehiclei, bool, CVehicle const& vehicle, i32 const doorId);
    DECL_FASTCALL_SIMPLE(CarHasDoorToOpen, _ZN13CCarEnterExit16CarHasDoorToOpenERK8CVehiclei, bool, CVehicle const& vehicle, i32 const doorId);
    DECL_FASTCALL_SIMPLE(CarHasDoorToClose, _ZN13CCarEnterExit17CarHasDoorToCloseERK8CVehiclei, bool, CVehicle const& vehicle, i32 const doorId);
    DECL_FASTCALL_SIMPLE(CarHasOpenableDoor, _ZN13CCarEnterExit18CarHasOpenableDoorERK8CVehicleiRK4CPed, bool, CVehicle const& vehicle, i32 const doorId, CPed const& ped);
    DECL_FASTCALL_SIMPLE(CarHasPartiallyOpenDoor, _ZN13CCarEnterExit23CarHasPartiallyOpenDoorERK8CVehiclei, bool, CVehicle const& vehicle, i32 const doorId);
    DECL_FASTCALL_SIMPLE(IsVehicleHealthy, _ZN13CCarEnterExit16IsVehicleHealthyERK8CVehicle, bool, CVehicle const& vehicle);
    DECL_FASTCALL_SIMPLE(IsPedHealthy, _ZN13CCarEnterExit12IsPedHealthyERK4CPed, bool, CPed const& ped);
    DECL_FASTCALL_SIMPLE(IsCarQuickJackPossible, _ZN13CCarEnterExit22IsCarQuickJackPossibleERK8CVehicleiRK4CPed, bool, CVehicle const& vehicle, i32 const doorId, CPed const& ped);
    DECL_FASTCALL_SIMPLE(IsCarSlowJackRequired, _ZN13CCarEnterExit21IsCarSlowJackRequiredERK8CVehicleiRK4CPed, bool, CVehicle const& vehicle, i32 const doorId, CPed const& ped);
    DECL_FASTCALL_SIMPLE(ComputeQuickJackedPed, _ZN13CCarEnterExit21ComputeQuickJackedPedERK8CVehiclei, CPed*, CVehicle const& vehicle, i32 const doorId);
    DECL_FASTCALL_SIMPLE(ComputeSlowJackedPed, _ZN13CCarEnterExit20ComputeSlowJackedPedERK8CVehiclei, CPed*, CVehicle const& vehicle, i32 const doorId);
    DECL_FASTCALL_SIMPLE(IsVehicleStealable, _ZN13CCarEnterExit18IsVehicleStealableERK8CVehicleRK4CPed, bool, CVehicle const& vehicle, CPed const& ped);
    DECL_FASTCALL_SIMPLE(IsClearToDriveAway, _ZN13CCarEnterExit18IsClearToDriveAwayERK8CVehicle, bool, CVehicle const& vehicle);
    DECL_FASTCALL_SIMPLE(ComputeTargetDoorToExit, _ZN13CCarEnterExit23ComputeTargetDoorToExitERK8CVehicleRK4CPed, i32, CVehicle const& vehicle, CPed const& ped);
    DECL_FASTCALL_SIMPLE(ComputeTargetDoorToEnterAsPassenger, _ZN13CCarEnterExit35ComputeTargetDoorToEnterAsPassengerERK8CVehiclei, i32, CVehicle const& vehicle, i32 const passengerNum);
    DECL_FASTCALL_SIMPLE(ComputePassengerIndexFromCarDoor, _ZN13CCarEnterExit32ComputePassengerIndexFromCarDoorERK8CVehiclei, i32, CVehicle const& vehicle, i32 const doorId);
    DECL_FASTCALL_SIMPLE(IsPlayerToQuitCarEnter, _ZN13CCarEnterExit22IsPlayerToQuitCarEnterERK4CPedRK8CVehicleiP5CTask, bool, CPed const& ped, CVehicle const& vehicle, i32 const startTime, CTask* task);
    DECL_FASTCALL_SIMPLE(IsPathToDoorBlockedByVehicleCollisionModel, _ZN13CCarEnterExit42IsPathToDoorBlockedByVehicleCollisionModelERK4CPedR8CVehicleRK7CVector, bool, CPed const& ped, CVehicle& vehicle, CVector const& pos);
    DECL_FASTCALL_SIMPLE(MakeUndraggedPassengerPedsLeaveCar, _ZN13CCarEnterExit34MakeUndraggedPassengerPedsLeaveCarERK8CVehiclePK4CPedS5_, void, CVehicle const& vehicle, CPed const* draggedPed, CPed const* ped);
    DECL_FASTCALL_SIMPLE(MakeUndraggedDriverPedLeaveCar, _ZN13CCarEnterExit30MakeUndraggedDriverPedLeaveCarERK8CVehicleRK4CPed, void, CVehicle const& vehicle, CPed const& ped);
    DECL_FASTCALL_SIMPLE(RemoveCarSitAnim, _ZN13CCarEnterExit16RemoveCarSitAnimERK4CPed, void, CPed const& ped);
    DECL_FASTCALL_SIMPLE(RemoveGetInAnims, _ZN13CCarEnterExit16RemoveGetInAnimsERK4CPed, void, CPed const& ped);
    DECL_FASTCALL_SIMPLE(AddInCarAnim, _ZN13CCarEnterExit12AddInCarAnimERK8CVehicleP4CPedb, void, CVehicle const& vehicle, CPed* ped, bool asDriver);
    DECL_FASTCALL_SIMPLE(SetAnimOffsetForEnterOrExitVehicle, _ZN13CCarEnterExit34SetAnimOffsetForEnterOrExitVehicleEv, void);
    DECL_FASTCALL_SIMPLE(QuitEnteringCar, _ZN13CCarEnterExit15QuitEnteringCarEP4CPedP8CVehicleib, void, CPed* ped, CVehicle* vehicle, i32 const doorId, bool carWasBeingJacked);
    DECL_FASTCALL_SIMPLE(SetPedInCarDirect, _ZN13CCarEnterExit17SetPedInCarDirectEP4CPedP8CVehicleib, bool, CPed* ped, CVehicle* vehicle, i32 const seatNumber, bool asDriver);

    // STATIC values
    DECL_OBJECT_PLT(CVector, ms_vecPedGetUpAnimOffset, BYBIT(0x678cf4, 0x84fa10));
    DECL_OBJECT_PLT(CVector, ms_vecPedQuickDraggedOutCarAnimOffset, BYBIT(0x677e84, 0x84dd28));
    DECL_OBJECT_PLT(bool, ms_bPedOffsetsCalculated, BYBIT(0x676868, 0x84b128));
    DECL_OBJECT_PLT(CVector, ms_vecPedBedLAnimOffset, BYBIT(0x677fb8, 0x84df90));
    DECL_OBJECT_PLT(CVector, ms_vecPedBedRAnimOffset, BYBIT(0x677414, 0x84c860));
    DECL_OBJECT_PLT(CVector, ms_vecPedDeskAnimOffset, BYBIT(0x677834, 0x84d090));
    DECL_OBJECT_PLT(CVector, ms_vecPedChairAnimOffset, BYBIT(0x676b08, 0x84b658));
    DECL_OBJECT_SYM(float const, ms_fSmallTurnAmount, _ZN13CCarEnterExit19ms_fSmallTurnAmountE);
    DECL_OBJECT_SYM(float const, ms_fMinSpeedPlayerCanStepOutCar, _ZN13CCarEnterExit31ms_fMinSpeedPlayerCanStepOutCarE);
    DECL_OBJECT_SYM(float const, ms_fMinSpeedPlayerCanJumpOutCar, _ZN13CCarEnterExit31ms_fMinSpeedPlayerCanJumpOutCarE);
    DECL_OBJECT_PLT(float const, ms_fMaxSpeed_CanDragPedOut, BYBIT(0x679be0, 0x8517e0));
    DECL_OBJECT_PLT(float const, ms_fMaxSpeed_PlayerCanDragPedOut, BYBIT(0x678578, 0x84eb08));
    DECL_OBJECT_PLT(float, ms_fPlayerMinQuitTime, BYBIT(0x676ec0, 0x84bdc0));
DECL_CLASS_END()
CHECKSIZE(CCarEnterExit, 0x1, 0x1);

#endif // __AML_PSDK_SACARENTEREXIT_H
