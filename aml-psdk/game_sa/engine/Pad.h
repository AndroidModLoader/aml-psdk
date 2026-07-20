#ifndef __AML_PSDK_SAPAD_H
#define __AML_PSDK_SAPAD_H

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/gta_base/Vector.h>

struct CControllerState
{
    i16                                LeftStickX;
    i16                                LeftStickY;
    i16                                RightStickX;
    i16                                RightStickY;
    i16                                LeftShoulder1;
    i16                                LeftShoulder2;
    i16                                RightShoulder1;
    i16                                RightShoulder2;
    i16                                DPadUp;
    i16                                DPadDown;
    i16                                DPadLeft;
    i16                                DPadRight;
    i16                                Start;
    i16                                Select;
    i16                                ButtonSquare;
    i16                                ButtonTriangle;
    i16                                ButtonCross;
    i16                                ButtonCircle;
    i16                                ShockButtonL;
    i16                                ShockButtonR;
    i16                                m_bChatIndicated;
    i16                                m_bPedWalk;
    i16                                m_bVehicleMouseLook;
    i16                                m_bRadioTrackSkip;
};
CHECKSIZE(CControllerState, 0x30, 0x30);  // 64-bit from the IDB; 32-bit measured from this layout

struct CMouseControllerState
{
    u8                                 m_bLeftButton;
    u8                                 m_bRightButton;
    u8                                 m_bMiddleButton;
    u8                                 m_bWheelMovedUp;
    u8                                 m_bWheelMovedDown;
    u8                                 m_bMsFirstXButton;
    u8                                 m_bMsSecondXButton;
    float                              m_fWheelMoved;
    RwV2d                              m_AmountMoved;
};
CHECKSIZE(CMouseControllerState, 0x14, 0x14);  // 64-bit from the IDB; 32-bit measured from this layout

struct CAutomobile;
struct CPed;
struct CVector;
struct CVector2D;
struct CVehicle;

DECL_CLASS(CPad)
    // Member values
    CControllerState                   NewState;
    CControllerState                   OldState;
    int                                currentPadId;
    i16                                SteeringLeftRightBuffer[10];
    i32                                DrunkDrivingBufferUsed;
    CControllerState                   PCTempKeyState;
    CControllerState                   PCTempJoyState;
    CControllerState                   PCTempMouseState;
    u8                                 Phase;
    i16                                ShakeDur;
    u16                                DisablePlayerControls;
    u8                                 ShakeFreq;
    u8                                 JustOutOfFrontEnd;
    float                              fCruisingSpeed;
    u8                                 bRhythm;
    u8                                 bWheelie;
    u8                                 bStoppie;
    u8                                 bApplyGas;
    u8                                 bApplyBrake;
    u8                                 bLaneCorrection;
    u8                                 bUsingDebugCamera;
    u8                                 bUsingDebugPlayerFreeze;
    u8                                 bHasCheated;
    u8                                 bDisableForbiddenTerr;
    u8                                 bStopRhythmSprites;
    u8                                 bDoorsLocked;
    u8                                 bRegainControl;
    float                              fBikeStickY;
    u8                                 bApplyBrakes;
    u8                                 bDisablePlayerEnterCar;
    u8                                 bDisablePlayerDuck;
    u8                                 bDisablePlayerFireWeapon;
    u8                                 bDisablePlayerFireWeaponWithL1;
    u8                                 bDisablePlayerCycleWeapon;
    u8                                 bDisablePlayerJump;
    u8                                 bDisablePlayerDisplayVitalStats;
    u32                                LastTimeTouched;
    i32                                AverageWeapon;
    i32                                AverageEntries;
    u32                                NoShakeBeforeThis;
    u8                                 NoShakeFreq;
    u8                                 bHasJetPack;
    u8                                 bRocketLocked;
    u8                                 bTrainPassenger;
    u8                                 bSavedForTrain;
    u8                                 bSetSteeringMode;
    u8                                 bSetTouchLayout;
    float                              m_fAccelX;
    float                              m_fAccelY;
    float                              m_fAccelZ;

    // Functions
    DECL_FASTCALL_SIMPLE(Initialise, _ZN4CPad10InitialiseEv, void);
    DECL_THISCALL_HEAD(Clear, _ZN4CPad5ClearEbb, void, bool bOkToClearTheDisableFlag, bool bReinit)
    DECL_THISCALL_TAIL(Clear, bOkToClearTheDisableFlag, bReinit)
    DECL_FASTCALL_SIMPLE(ClearKeyBoardHistory, _ZN4CPad20ClearKeyBoardHistoryEv, void);
    DECL_THISCALL_SIMPLE(ClearMouseHistory, _ZN4CPad17ClearMouseHistoryEv, void);
    DECL_THISCALL_SIMPLE(UpdateMouse, _ZN4CPad11UpdateMouseEv, void);
    DECL_THISCALL_HEAD(ReconcileTwoControllersInput, _ZN4CPad28ReconcileTwoControllersInputERK16CControllerStateS2_, i64, const CControllerState* a1, const CControllerState* a2)
    DECL_THISCALL_TAIL(ReconcileTwoControllersInput, a1, a2)
    DECL_THISCALL_HEAD(SetDrunkInputDelay, _ZN4CPad18SetDrunkInputDelayEi, void, i32 FrameDelay)
    DECL_THISCALL_TAIL(SetDrunkInputDelay, FrameDelay)
    DECL_THISCALL_HEAD(StartShake, _ZN4CPad10StartShakeEshj, void, i16 Duration, u8 Frequency, u32 DelayAfterThisOne)
    DECL_THISCALL_TAIL(StartShake, Duration, Frequency, DelayAfterThisOne)
    DECL_THISCALL_HEAD(StartShake_Distance, _ZN4CPad19StartShake_DistanceEshfff, void, i16 Duration, u8 Frequency, float X, float Y, float Z)
    DECL_THISCALL_TAIL(StartShake_Distance, Duration, Frequency, X, Y, Z)
    DECL_FASTCALL_SIMPLE(UpdatePads, _ZN4CPad10UpdatePadsEv, void);
    DECL_FASTCALL_SIMPLE(GetPad, _ZN4CPad6GetPadEi, CPad*, i32 nPadNumber);
    DECL_THISCALL_HEAD(Update, _ZN4CPad6UpdateEs, void, i16 PadNum)
    DECL_THISCALL_TAIL(Update, PadNum)
    DECL_THISCALL_SIMPLE(ProcessPCSpecificStuff, _ZN4CPad22ProcessPCSpecificStuffEv, void);
    DECL_THISCALL_HEAD(ProcessWheelie, _ZN4CPad14ProcessWheelieEf, void, float fSpeed)
    DECL_THISCALL_TAIL(ProcessWheelie, fSpeed)
    DECL_THISCALL_SIMPLE(ProcessStoppie, _ZN4CPad14ProcessStoppieEv, void);
    DECL_FASTCALL_SIMPLE(CheckPointSave, _ZN4CPad14CheckPointSaveEv, void);
    DECL_THISCALL_HEAD(GetCarGunFired, _ZN4CPad14GetCarGunFiredEbb, i16, bool bCanShootFwd, bool bAir)
    DECL_THISCALL_TAIL(GetCarGunFired, bCanShootFwd, bAir)
    DECL_FASTCALL_SIMPLE(FixPadsAfterSave, _ZN4CPad16FixPadsAfterSaveEv, void);
    DECL_FASTCALL_SIMPLE(StopPadsShaking, _ZN4CPad15StopPadsShakingEv, void);
    DECL_THISCALL_HEAD(StopShaking, _ZN4CPad11StopShakingEs, void, i16 PadNum)
    DECL_THISCALL_TAIL(StopShaking, PadNum)
    DECL_THISCALL_SIMPLE(IsFlyingRCVehicle, _ZN4CPad17IsFlyingRCVehicleEv, bool);
    DECL_THISCALL_SIMPLE(GetSteeringMode, _ZN4CPad15GetSteeringModeEv, i32);
    DECL_THISCALL_SIMPLE(GetSteeringLeftRight, _ZN4CPad20GetSteeringLeftRightEv, i16);
    DECL_THISCALL_SIMPLE(GetSteeringUpDown, _ZN4CPad17GetSteeringUpDownEv, i16);
    DECL_THISCALL_HEAD(GetCarGunUpDown, _ZN4CPad15GetCarGunUpDownEbP11CAutomobilefb, i64, bool bCheckHydraulics, CAutomobile* pAutomobile, float fLimit, bool bPoop)
    DECL_THISCALL_TAIL(GetCarGunUpDown, bCheckHydraulics, pAutomobile, fLimit, bPoop)
    DECL_THISCALL_HEAD(GetCarGunLeftRight, _ZN4CPad18GetCarGunLeftRightEbb, i16, bool bCheckHydraulics, bool bPoop)
    DECL_THISCALL_TAIL(GetCarGunLeftRight, bCheckHydraulics, bPoop)
    DECL_THISCALL_HEAD(GetLeftAnalogue, _ZN4CPad15GetLeftAnalogueEP9CVector2D, void, CVector2D* pVecOut)
    DECL_THISCALL_TAIL(GetLeftAnalogue, pVecOut)
    DECL_THISCALL_HEAD(GetRightAnalogue, _ZN4CPad16GetRightAnalogueEP9CVector2D, void, CVector2D* pVecOut)
    DECL_THISCALL_TAIL(GetRightAnalogue, pVecOut)
    DECL_THISCALL_SIMPLE(GetPedWalkLeftRight, _ZN4CPad19GetPedWalkLeftRightEv, i16);
    DECL_THISCALL_SIMPLE(GetPedWalkUpDown, _ZN4CPad16GetPedWalkUpDownEv, i16);
    DECL_THISCALL_HEAD(GetLookLeft, _ZN4CPad11GetLookLeftEb, bool, bool bCheckWidget)
    DECL_THISCALL_TAIL(GetLookLeft, bCheckWidget)
    DECL_THISCALL_HEAD(GetLookRight, _ZN4CPad12GetLookRightEb, bool, bool bCheckWidget)
    DECL_THISCALL_TAIL(GetLookRight, bCheckWidget)
    DECL_THISCALL_SIMPLE(GetTurretLeft, _ZN4CPad13GetTurretLeftEv, bool);
    DECL_THISCALL_SIMPLE(GetTurretRight, _ZN4CPad14GetTurretRightEv, bool);
    DECL_THISCALL_SIMPLE(GetJetpackHover, _ZN4CPad15GetJetpackHoverEv, bool);
    DECL_THISCALL_SIMPLE(GetLookBehindForCar, _ZN4CPad19GetLookBehindForCarEv, bool);
    DECL_THISCALL_SIMPLE(GetLookBehindForPed, _ZN4CPad19GetLookBehindForPedEv, bool);
    DECL_THISCALL_HEAD(GetHorn, _ZN4CPad7GetHornEb, bool, bool bEnableTouch)
    DECL_THISCALL_TAIL(GetHorn, bEnableTouch)
    DECL_THISCALL_SIMPLE(HornJustDown, _ZN4CPad12HornJustDownEv, bool);
    DECL_THISCALL_SIMPLE(GetHydraulicJump, _ZN4CPad16GetHydraulicJumpEv, bool);
    DECL_THISCALL_SIMPLE(GetNitroFired, _ZN4CPad13GetNitroFiredEv, i16);
    DECL_THISCALL_SIMPLE(CarGunJustDown, _ZN4CPad14CarGunJustDownEv, i16);
    DECL_THISCALL_SIMPLE(FlareJustDown, _ZN4CPad13FlareJustDownEv, bool);
    DECL_THISCALL_SIMPLE(CraneReleaseJustDown, _ZN4CPad20CraneReleaseJustDownEv, i16);
    DECL_THISCALL_SIMPLE(UseBomb, _ZN4CPad7UseBombEv, bool);
    DECL_THISCALL_SIMPLE(UseRocket, _ZN4CPad9UseRocketEv, bool);
    DECL_THISCALL_SIMPLE(GetHandBrake, _ZN4CPad12GetHandBrakeEv, i16);
    DECL_THISCALL_SIMPLE(GetBrake, _ZN4CPad8GetBrakeEv, i16);
    DECL_THISCALL_SIMPLE(GetExitVehicle, _ZN4CPad14GetExitVehicleEv, bool);
    DECL_THISCALL_HEAD(ExitVehicleJustDown, _ZN4CPad19ExitVehicleJustDownEbP8CVehiclebRK7CVector, bool, bool bCheckTouch, CVehicle* pVehicle, bool bEntering, const CVector* vecVehicle)
    DECL_THISCALL_TAIL(ExitVehicleJustDown, bCheckTouch, pVehicle, bEntering, vecVehicle)
    DECL_THISCALL_SIMPLE(DropItemJustDown, _ZN4CPad16DropItemJustDownEv, bool);
    DECL_THISCALL_HEAD(GetWeapon, _ZN4CPad9GetWeaponEP4CPedb, i32, CPed* pPed, bool bShoulderPossible)
    DECL_THISCALL_TAIL(GetWeapon, pPed, bShoulderPossible)
    DECL_FASTCALL_SIMPLE(WeaponUsesAttackButton, _ZN4CPad22WeaponUsesAttackButtonEP4CPed, int, CPed* pPlayerPed);
    DECL_FASTCALL_SIMPLE(WeaponUsesTargetingButton, _ZN4CPad25WeaponUsesTargetingButtonEv, bool);
    DECL_THISCALL_HEAD(WeaponJustDown, _ZN4CPad14WeaponJustDownEP4CPedbb, bool, CPed* pPed, bool bShoulderPossible, bool bEnableTouch)
    DECL_THISCALL_TAIL(WeaponJustDown, pPed, bShoulderPossible, bEnableTouch)
    DECL_THISCALL_SIMPLE(GetMeleeAttack, _ZN4CPad14GetMeleeAttackEv, i8);
    DECL_THISCALL_SIMPLE(MeleeAttackJustDown, _ZN4CPad19MeleeAttackJustDownEv, i8);
    DECL_THISCALL_SIMPLE(CycleWeaponLeftJustDown, _ZN4CPad23CycleWeaponLeftJustDownEv, bool);
    DECL_THISCALL_SIMPLE(CycleWeaponRightJustDown, _ZN4CPad24CycleWeaponRightJustDownEv, bool);
    DECL_THISCALL_SIMPLE(GetBlock, _ZN4CPad8GetBlockEv, bool);
    DECL_THISCALL_SIMPLE(GetAccelerate, _ZN4CPad13GetAccelerateEv, i16);
    DECL_THISCALL_SIMPLE(GetAccelerateJustDown, _ZN4CPad21GetAccelerateJustDownEv, bool);
    DECL_THISCALL_SIMPLE(CycleCameraModeDownJustDown, _ZN4CPad27CycleCameraModeDownJustDownEv, bool);
    DECL_THISCALL_SIMPLE(NextStationJustUp, _ZN4CPad17NextStationJustUpEv, bool);
    DECL_THISCALL_SIMPLE(LastStationJustUp, _ZN4CPad17LastStationJustUpEv, bool);
    DECL_FASTCALL_SIMPLE(WillBulletHitSomething, _ZN4CPad22WillBulletHitSomethingEP4CPed, bool, CPed* pPed);
    DECL_THISCALL_SIMPLE(GetEnterTargeting, _ZN4CPad17GetEnterTargetingEv, int);
    DECL_THISCALL_HEAD(GetTarget, _ZN4CPad9GetTargetEb, bool, bool bCheckWidget)
    DECL_THISCALL_TAIL(GetTarget, bCheckWidget)
    DECL_THISCALL_SIMPLE(GetExitTargeting, _ZN4CPad16GetExitTargetingEv, bool);
    DECL_THISCALL_SIMPLE(ShiftTargetLeftJustDown, _ZN4CPad23ShiftTargetLeftJustDownEv, bool);
    DECL_THISCALL_SIMPLE(ShiftTargetRightJustDown, _ZN4CPad24ShiftTargetRightJustDownEv, bool);
    DECL_THISCALL_SIMPLE(GetDuck, _ZN4CPad7GetDuckEv, bool);
    DECL_THISCALL_HEAD(DuckJustDown, _ZN4CPad12DuckJustDownEP4CPed, bool, CPed* pPed)
    DECL_THISCALL_TAIL(DuckJustDown, pPed)
    DECL_THISCALL_SIMPLE(GetAutoClimb, _ZN4CPad12GetAutoClimbEv, bool);
    DECL_THISCALL_SIMPLE(GetAbortClimb, _ZN4CPad13GetAbortClimbEv, bool);
    DECL_THISCALL_SIMPLE(GetBunnyHop, _ZN4CPad11GetBunnyHopEv, bool);
    DECL_THISCALL_SIMPLE(GetBunnyHopDown, _ZN4CPad15GetBunnyHopDownEv, bool);
    DECL_THISCALL_SIMPLE(GetJump, _ZN4CPad7GetJumpEv, bool);
    DECL_THISCALL_SIMPLE(JumpJustDown, _ZN4CPad12JumpJustDownEv, bool);
    DECL_THISCALL_SIMPLE(DiveJustDown, _ZN4CPad12DiveJustDownEv, bool);
    DECL_THISCALL_SIMPLE(SwimJumpJustDown, _ZN4CPad16SwimJumpJustDownEv, bool);
    DECL_THISCALL_HEAD(GetSprint, _ZN4CPad9GetSprintEi, bool, int nSprintType)
    DECL_THISCALL_TAIL(GetSprint, nSprintType)
    DECL_THISCALL_SIMPLE(SprintJustDown, _ZN4CPad14SprintJustDownEv, bool);
    DECL_THISCALL_SIMPLE(GetDisplayScreenRecord, _ZN4CPad22GetDisplayScreenRecordEv, i16);
    DECL_THISCALL_HEAD(GetDisplayVitalStats, _ZN4CPad20GetDisplayVitalStatsEP4CPed, i16, CPed* pPed)
    DECL_THISCALL_TAIL(GetDisplayVitalStats, pPed)
    DECL_THISCALL_SIMPLE(CollectPickupJustDown, _ZN4CPad21CollectPickupJustDownEv, bool);
    DECL_THISCALL_SIMPLE(GetForceCameraBehindPlayer, _ZN4CPad26GetForceCameraBehindPlayerEv, bool);
    DECL_THISCALL_SIMPLE(SniperZoomIn, _ZN4CPad12SniperZoomInEv, bool);
    DECL_THISCALL_SIMPLE(SniperZoomOut, _ZN4CPad13SniperZoomOutEv, bool);
    DECL_THISCALL_SIMPLE(CinemaCamera, _ZN4CPad12CinemaCameraEv, i16);
    DECL_THISCALL_SIMPLE(LookAroundLeftRight, _ZN4CPad19LookAroundLeftRightEv, i16);
    DECL_THISCALL_SIMPLE(LookAroundUpDown, _ZN4CPad16LookAroundUpDownEv, i16);
    DECL_THISCALL_HEAD(AimWeaponLeftRight, _ZN4CPad18AimWeaponLeftRightEP4CPedPb, float, CPed* pPed, bool* pbTouchInputX)
    DECL_THISCALL_TAIL(AimWeaponLeftRight, pPed, pbTouchInputX)
    DECL_THISCALL_HEAD(GetFreeAimAssistance, _ZN4CPad20GetFreeAimAssistanceEP4CPed, CVector2D, CPed* pPlayerPed)
    DECL_THISCALL_TAIL(GetFreeAimAssistance, pPlayerPed)
    DECL_THISCALL_HEAD(AimWeaponUpDown, _ZN4CPad15AimWeaponUpDownEP4CPedPb, i16, CPed* pPed, bool* pbTouchInputY)
    DECL_THISCALL_TAIL(AimWeaponUpDown, pPed, pbTouchInputY)
    DECL_FASTCALL_SIMPLE(DebugFreeAim, _ZN4CPad12DebugFreeAimEv, void);
    DECL_THISCALL_SIMPLE(ConversationYesJustDown, _ZN4CPad23ConversationYesJustDownEv, bool);
    DECL_THISCALL_SIMPLE(ConversationNoJustDown, _ZN4CPad22ConversationNoJustDownEv, bool);
    DECL_THISCALL_HEAD(GetGroupControlForward, _ZN4CPad22GetGroupControlForwardEbb, bool, bool bCheckWidget, bool bCheckAlt)
    DECL_THISCALL_TAIL(GetGroupControlForward, bCheckWidget, bCheckAlt)
    DECL_THISCALL_HEAD(GetGroupControlBack, _ZN4CPad19GetGroupControlBackEbb, bool, bool bCheckWidget, bool bCheckAlt)
    DECL_THISCALL_TAIL(GetGroupControlBack, bCheckWidget, bCheckAlt)
    DECL_THISCALL_HEAD(GroupControlForwardJustDown, _ZN4CPad27GroupControlForwardJustDownEb, bool, bool bCheckWidget)
    DECL_THISCALL_TAIL(GroupControlForwardJustDown, bCheckWidget)
    DECL_THISCALL_HEAD(GroupControlBackJustDown, _ZN4CPad24GroupControlBackJustDownEb, bool, bool bCheckWidget)
    DECL_THISCALL_TAIL(GroupControlBackJustDown, bCheckWidget)
    DECL_FASTCALL_SIMPLE(EditString, _ZN4CPad10EditStringEPci, char*, char* pString, i32 MaxStringLength);
    DECL_FASTCALL_SIMPLE(EditCodesForControls, _ZN4CPad20EditCodesForControlsEPii, RwInt32*, RwInt32* pRwKeyCode, i32 MaxCodeLength);
    DECL_FASTCALL_SIMPLE(UpdatePadsTillStable, _ZN4CPad20UpdatePadsTillStableEv, bool);
    DECL_THISCALL_SIMPLE(GetEscapeJustDown, _ZN4CPad17GetEscapeJustDownEv, bool);

    // Static values
    DECL_VALUE_ADDR_U8(bSniperAimWithRightStick, BYBIT(0x6AAD0E, 0x88631A));  // no .got slot: addressed PC-relatively
    DECL_VALUE_PLT_FLT(m_fLastCarCheatScroll, BYBIT(0x67761C, 0x84CC68));
    DECL_VALUE_PLT_FLT(m_fLastMissionSkipScroll, BYBIT(0x676B14, 0x84B670));
    DECL_VALUE_PLT_FLT(m_fLastCheatScroll, BYBIT(0x6762F0, 0x84A640));
    DECL_VALUE_PLT_U8(m_bMapPadOneToPadTwo, BYBIT(0x679924, 0x851268));
    DECL_VALUE_PLT_U8(m_bDebugCamPCOn, BYBIT(0x6767F4, 0x84B040));
    DECL_VALUE_ADDR_U8(bSniperAllowMovement, BYBIT(0x959ACE, 0xBC2992));  // no .got slot: addressed PC-relatively
    DECL_OBJECT_PLT(CVector2D, vecMouseDelta, BYBIT(0x678348, 0x84E6A8));
    DECL_OBJECT_PLT(CVector2D, vecLastMouse, BYBIT(0x679F90, 0x851F30));
    DECL_OBJECT_PLT(CMouseControllerState, PCTempMouseControllerState, BYBIT(0x678E0C, 0x84FC40));
    DECL_OBJECT_PLT(CMouseControllerState, NewMouseControllerState, BYBIT(0x678C58, 0x84F8D8));
    DECL_OBJECT_PLT(CMouseControllerState, OldMouseControllerState, BYBIT(0x6772D4, 0x84C5E0));
DECL_CLASS_END()
CHECKSIZE(CPad, 0x158, 0x158);  // 64-bit from the IDB; 32-bit measured from this layout

#define bSniperAimWithRightStick bSniperAimWithRightStick()
#define m_fLastCarCheatScroll m_fLastCarCheatScroll()
#define m_fLastMissionSkipScroll m_fLastMissionSkipScroll()
#define m_fLastCheatScroll m_fLastCheatScroll()
#define m_bMapPadOneToPadTwo m_bMapPadOneToPadTwo()
#define m_bDebugCamPCOn m_bDebugCamPCOn()
#define bSniperAllowMovement bSniperAllowMovement()
#define vecMouseDelta vecMouseDelta()
#define vecLastMouse vecLastMouse()
#define PCTempMouseControllerState PCTempMouseControllerState()
#define NewMouseControllerState NewMouseControllerState()
#define OldMouseControllerState OldMouseControllerState()

#endif // __AML_PSDK_SAPAD_H
