#ifndef __AML_PSDK_VCPAD_H
#define __AML_PSDK_VCPAD_H

#include <aml-psdk/game_vc/plugin.h>
#include <aml-psdk/gta_base/Vector.h>

DECL_CLASS(CControllerState)
    // Member functions
    DECL_THISCALL_SIMPLE(Clear, _ZN16CControllerState5ClearEv, void);
    // The 64-bit game checks active pad input instead of this state.
    DECL_THISCALL_SIMPLE(CheckForInput, _ZN16CControllerState13CheckForInputEv, bool);

    // Member values
    i16 LeftStickX;
    i16 LeftStickY;
    i16 RightStickX;
    i16 RightStickY;
    i16 LeftShoulder1;
    i16 LeftShoulder2;
    i16 RightShoulder1;
    i16 RightShoulder2;
    i16 DPadUp;
    i16 DPadDown;
    i16 DPadLeft;
    i16 DPadRight;
    i16 Start;
    i16 Select;
    i16 ButtonSquare;
    i16 ButtonTriangle;
    i16 ButtonCross;
    i16 ButtonCircle;
    i16 ShockButtonL;
    i16 ShockButtonR;
    i16 RadioTrackSkip;
DECL_CLASS_END()
CHECKSIZE(CControllerState, 0x2A, 0x2A);

DECL_CLASS(CMouseControllerState)
    // Construct/Deconstruct functions
    DECL_CTORCALL(CMouseControllerState, _ZN21CMouseControllerStateC2Ev);

    // Member functions
    DECL_THISCALL_SIMPLE(Clear, _ZN21CMouseControllerState5ClearEv, void);

    // Member values
    u8 lmb;
    u8 rmb;
    u8 mmb;
    u8 wheelUp;
    u8 wheelDown;
    u8 bmx1;
    u8 bmx2;
    u8 : 8;
    float x;
    float y;
DECL_CLASS_END()
CHECKSIZE(CMouseControllerState, 0x10, 0x10);

DECL_CLASS(CKeyboardState)
    // Member functions
    DECL_THISCALL_SIMPLE(Clear, _ZN14CKeyboardState5ClearEv, void);

    // Member values
    i16 FKeys[12];
    i16 standardKeys[256];
    i16 esc;
    i16 insert;
    i16 del;
    i16 home;
    i16 end;
    i16 pgup;
    i16 pgdn;
    i16 up;
    i16 down;
    i16 left;
    i16 right;
    i16 scroll;
    i16 pause;
    i16 numlock;
    i16 div;
    i16 mul;
    i16 sub;
    i16 add;
    i16 enter;
    i16 decimal;
    i16 num1;
    i16 num2;
    i16 num3;
    i16 num4;
    i16 num5;
    i16 num6;
    i16 num7;
    i16 num8;
    i16 num9;
    i16 num0;
    i16 back;
    i16 tab;
    i16 capslock;
    i16 extenter;
    i16 lshift;
    i16 rshift;
    i16 shift;
    i16 lctrl;
    i16 rctrl;
    i16 lmenu;
    i16 rmenu;
    i16 lwin;
    i16 rwin;
    i16 apps;
DECL_CLASS_END()
CHECKSIZE(CKeyboardState, 0x270, 0x270);

DECL_CLASS(CPad)
    CPad() = delete;

    // STATIC functions
    DECL_FASTCALL_SIMPLE(Initialise, _ZN4CPad10InitialiseEv, void);
    DECL_FASTCALL_SIMPLE(GetPad, _ZN4CPad6GetPadEi, CPad*, i32 padNumber);
    DECL_FASTCALL_SIMPLE(UpdatePads, _ZN4CPad10UpdatePadsEv, void);
    DECL_FASTCALL_SIMPLE(ClearKeyBoardHistory, _ZN4CPad20ClearKeyBoardHistoryEv, void);
    DECL_FASTCALL_SIMPLE(ClearMouseHistory, _ZN4CPad17ClearMouseHistoryEv, void);
    DECL_FASTCALL_SIMPLE(FixPadsAfterSave, _ZN4CPad16FixPadsAfterSaveEv, void);
    DECL_FASTCALL_SIMPLE(ResetCheats, _ZN4CPad11ResetCheatsEv, void);
    DECL_FASTCALL_SIMPLE(EditString, _ZN4CPad10EditStringEPci, char*, char* text, i32 maxLength);
    DECL_FASTCALL_SIMPLE(EditCodesForControls, _ZN4CPad20EditCodesForControlsEPii, i32*, i32* keyCode, i32 maxCodes);

    // Member functions
    DECL_THISCALL_HEAD(Clear, _ZN4CPad5ClearEb, void, bool clearDisableFlag)
    DECL_THISCALL_TAIL(Clear, clearDisableFlag)
    DECL_THISCALL_HEAD(Update, _ZN4CPad6UpdateEs, void, i16 padNumber)
    DECL_THISCALL_TAIL(Update, padNumber)
    DECL_THISCALL_HEAD(ReconcileTwoControllersInput, _ZN4CPad28ReconcileTwoControllersInputERK16CControllerStateS2_, CControllerState, CControllerState const& first, CControllerState const& second)
    DECL_THISCALL_TAIL(ReconcileTwoControllersInput, first, second)
    DECL_THISCALL_HEAD(SetDrunkInputDelay, _ZN4CPad18SetDrunkInputDelayEi, void, i32 frameDelay)
    DECL_THISCALL_TAIL(SetDrunkInputDelay, frameDelay)
    DECL_THISCALL_HEAD(StartShake, _ZN4CPad10StartShakeEsh, void, i16 duration, u8 frequency)
    DECL_THISCALL_TAIL(StartShake, duration, frequency)
    DECL_THISCALL_HEAD(StartShake_Distance, _ZN4CPad19StartShake_DistanceEshfff, void, i16 duration, u8 frequency, float x, float y, float z)
    DECL_THISCALL_TAIL(StartShake_Distance, duration, frequency, x, y, z)
    DECL_THISCALL_HEAD(StartShake_Train, _ZN4CPad16StartShake_TrainEff, void, float x, float y)
    DECL_THISCALL_TAIL(StartShake_Train, x, y)
    DECL_THISCALL_HEAD(AddToPCCheatString, _ZN4CPad18AddToPCCheatStringEc, void, char character)
    DECL_THISCALL_TAIL(AddToPCCheatString, character)
    DECL_THISCALL_SIMPLE(ResetAverageWeapon, _ZN4CPad18ResetAverageWeaponEv, void);
    DECL_THISCALL_SIMPLE(GetAverageWeapon, _ZN4CPad16GetAverageWeaponEv, i32);
    DECL_THISCALL_SIMPLE(InputHowLongAgo, _ZN4CPad15InputHowLongAgoEv, u32);
    DECL_THISCALL_SIMPLE(PadReadyTest, _ZN4CPad12PadReadyTestEv, bool);
    DECL_THISCALL_SIMPLE(GetSteeringLeftRight, _ZN4CPad20GetSteeringLeftRightEv, i16);
    DECL_THISCALL_SIMPLE(GetSteeringUpDown, _ZN4CPad17GetSteeringUpDownEv, i16);
    DECL_THISCALL_SIMPLE(GetAnalogueLeftRight, _ZN4CPad20GetAnalogueLeftRightEv, i16);
    DECL_THISCALL_SIMPLE(GetAnalogueUpDown, _ZN4CPad17GetAnalogueUpDownEv, i16);
    DECL_THISCALL_SIMPLE(GetCarGunLeftRight, _ZN4CPad18GetCarGunLeftRightEv, i16);
    DECL_THISCALL_SIMPLE(GetCarGunUpDown, _ZN4CPad15GetCarGunUpDownEv, i16);
    DECL_THISCALL_SIMPLE(GetAccelerate, _ZN4CPad13GetAccelerateEv, i16);
    DECL_THISCALL_SIMPLE(GetBrake, _ZN4CPad8GetBrakeEv, i16);
    DECL_THISCALL_SIMPLE(GetHandBrake, _ZN4CPad12GetHandBrakeEv, i16);
    DECL_THISCALL_SIMPLE(GetWeapon, _ZN4CPad9GetWeaponEv, i16);
    DECL_THISCALL_SIMPLE(SniperModeLookLeftRight, _ZN4CPad23SniperModeLookLeftRightEv, i16);
    DECL_THISCALL_SIMPLE(SniperModeLookUpDown, _ZN4CPad20SniperModeLookUpDownEv, i16);
    DECL_THISCALL_SIMPLE(LookAroundLeftRight, _ZN4CPad19LookAroundLeftRightEv, i16);
    DECL_THISCALL_SIMPLE(LookAroundUpDown, _ZN4CPad16LookAroundUpDownEv, i16);
    DECL_THISCALL_SIMPLE(GetHorn, _ZN4CPad7GetHornEv, bool);
    DECL_THISCALL_SIMPLE(HornJustDown, _ZN4CPad12HornJustDownEv, bool);
    DECL_THISCALL_SIMPLE(GetCarGunFired, _ZN4CPad14GetCarGunFiredEv, bool);
    DECL_THISCALL_SIMPLE(CarGunJustDown, _ZN4CPad14CarGunJustDownEv, bool);
    DECL_THISCALL_SIMPLE(GetLookLeft, _ZN4CPad11GetLookLeftEv, bool);
    DECL_THISCALL_SIMPLE(GetLookRight, _ZN4CPad12GetLookRightEv, bool);
    DECL_THISCALL_SIMPLE(GetLookBehindForCar, _ZN4CPad19GetLookBehindForCarEv, bool);
    DECL_THISCALL_SIMPLE(GetLookBehindForPed, _ZN4CPad19GetLookBehindForPedEv, bool);
    DECL_THISCALL_SIMPLE(GetExitVehicle, _ZN4CPad14GetExitVehicleEv, bool);
    DECL_THISCALL_SIMPLE(ExitVehicleJustDown, _ZN4CPad19ExitVehicleJustDownEv, bool);
    DECL_THISCALL_SIMPLE(GetTarget, _ZN4CPad9GetTargetEv, bool);
    DECL_THISCALL_SIMPLE(TargetJustDown, _ZN4CPad14TargetJustDownEv, bool);
    DECL_THISCALL_SIMPLE(WeaponJustDown, _ZN4CPad14WeaponJustDownEv, bool);
    DECL_THISCALL_SIMPLE(JumpJustDown, _ZN4CPad12JumpJustDownEv, bool);
    DECL_THISCALL_SIMPLE(DuckJustDown, _ZN4CPad12DuckJustDownEv, bool);
    DECL_THISCALL_SIMPLE(GetSprint, _ZN4CPad9GetSprintEv, bool);
    DECL_THISCALL_SIMPLE(CycleWeaponLeftJustDown, _ZN4CPad23CycleWeaponLeftJustDownEv, bool);
    DECL_THISCALL_SIMPLE(CycleWeaponRightJustDown, _ZN4CPad24CycleWeaponRightJustDownEv, bool);
    DECL_THISCALL_SIMPLE(CycleCameraModeJustDown, _ZN4CPad23CycleCameraModeJustDownEv, bool);
    DECL_THISCALL_SIMPLE(CycleCameraModeUpJustDown, _ZN4CPad25CycleCameraModeUpJustDownEv, bool);
    DECL_THISCALL_SIMPLE(CycleCameraModeDownJustDown, _ZN4CPad27CycleCameraModeDownJustDownEv, bool);
    DECL_THISCALL_SIMPLE(ShiftTargetLeftJustDown, _ZN4CPad23ShiftTargetLeftJustDownEv, bool);
    DECL_THISCALL_SIMPLE(ShiftTargetRightJustDown, _ZN4CPad24ShiftTargetRightJustDownEv, bool);
    DECL_THISCALL_SIMPLE(SniperZoomIn, _ZN4CPad12SniperZoomInEv, bool);
    DECL_THISCALL_SIMPLE(SniperZoomOut, _ZN4CPad13SniperZoomOutEv, bool);
    DECL_THISCALL_SIMPLE(ForceCameraBehindPlayer, _ZN4CPad23ForceCameraBehindPlayerEv, bool);
    DECL_THISCALL_SIMPLE(ChangeStationJustDown, _ZN4CPad21ChangeStationJustDownEv, bool);
    DECL_THISCALL_SIMPLE(GetAnaloguePadUp, _ZN4CPad16GetAnaloguePadUpEv, bool);
    DECL_THISCALL_SIMPLE(GetAnaloguePadDown, _ZN4CPad18GetAnaloguePadDownEv, bool);
    DECL_THISCALL_SIMPLE(GetAnaloguePadLeft, _ZN4CPad18GetAnaloguePadLeftEv, bool);
    DECL_THISCALL_SIMPLE(GetAnaloguePadRight, _ZN4CPad19GetAnaloguePadRightEv, bool);
    DECL_THISCALL_SIMPLE(GetAnaloguePadLeftJustUp, _ZN4CPad24GetAnaloguePadLeftJustUpEv, bool);
    DECL_THISCALL_SIMPLE(GetAnaloguePadRightJustUp, _ZN4CPad25GetAnaloguePadRightJustUpEv, bool);

    // STATIC values
    DECL_OBJECT_PLT(CKeyboardState, NewKeyState, BYBIT(0x3956FC, 0x578E80));
    DECL_OBJECT_PLT(CKeyboardState, OldKeyState, BYBIT(0x394420, 0x576990));
    DECL_OBJECT_PLT(CKeyboardState, TempKeyState, BYBIT(0x3964E0, 0x57A9B8));
    DECL_OBJECT_PLT(CMouseControllerState, PCTempMouseControllerState, BYBIT(0x395D68, 0x579AF0));
    DECL_OBJECT_PLT(CMouseControllerState, NewMouseControllerState, BYBIT(0x395078, 0x578160));
    DECL_OBJECT_PLT(CMouseControllerState, OldMouseControllerState, BYBIT(0x396AC0, 0x57B580));
    DECL_VALUE_PLT_BOOL(m_bMapPadOneToPadTwo, BYBIT(0x395A68, 0x5794F8));
    DECL_VALUE_PLT_BOOL(m_bDebugCamPCOn, BYBIT(0x394528, 0x576BB8));
    DECL_VALUE_PLT_BOOL(bDisplayNoControllerMessage, BYBIT(0x396B3C, 0x57B670));
    DECL_VALUE_PLT_BOOL(bOldDisplayNoControllerMessage, BYBIT(0x396B7C, 0x57B6F0));
    DECL_VALUE_PLT_BOOL(bObsoleteControllerMessage, BYBIT(0x3951A0, 0x578398));
    DECL_VALUE_PLT_BOOL(bInvertLook4Pad, BYBIT(0x395D88, 0x579B40));
    DECL_VALUE_PLT_BOOL(bHasPlayerCheated, BYBIT(0x396F1C, 0x57BE30));
    DECL_OBJECT_ARRAY_PLT(char, KeyBoardCheatString, BYBIT(0x3963FC, 0x57A7E0));

    // Member values
    CControllerState NewState;
    CControllerState OldState;
    i16 SteeringLeftRightBuffer[10];
    i32 DrunkDrivingBufferUsed;
    CControllerState PCTempKeyState;
    CControllerState PCTempJoyState;
    CControllerState PCTempMouseState;
    i16 Phase;
    i16 Mode;
    i16 ShakeDur;
    u16 DisablePlayerControls;
    u8 ShakeFreq;
    bool bHornHistory[5];
    u8 iCurrHornHistory;
    u8 JustOutOfFrontEnd;
    u8 bApplyBrakes;
    char CheatString[12];
    u8 : 8;
    u32 LastTimeTouched;
    i32 AverageWeapon;
    i32 AverageEntries;
DECL_CLASS_END()
CHECKSIZE(CPad, 0x114, 0x114);

DECL_OBJECT_ARRAY_PLT_GLOBAL(CPad, Pads, BYBIT(0x394FC0, 0x578000));

#define NewKeyState NewKeyState()
#define OldKeyState OldKeyState()
#define TempKeyState TempKeyState()
#define PCTempMouseControllerState PCTempMouseControllerState()
#define NewMouseControllerState NewMouseControllerState()
#define OldMouseControllerState OldMouseControllerState()
#define m_bMapPadOneToPadTwo m_bMapPadOneToPadTwo()
#define m_bDebugCamPCOn m_bDebugCamPCOn()
#define bDisplayNoControllerMessage bDisplayNoControllerMessage()
#define bOldDisplayNoControllerMessage bOldDisplayNoControllerMessage()
#define bObsoleteControllerMessage bObsoleteControllerMessage()
#define bInvertLook4Pad bInvertLook4Pad()
#define bHasPlayerCheated bHasPlayerCheated()
#define KeyBoardCheatString KeyBoardCheatString()
#define Pads Pads()

#endif // __AML_PSDK_VCPAD_H
