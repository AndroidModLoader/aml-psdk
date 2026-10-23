#ifndef __AML_PSDK_SACONTROLLERCONFIG_H
#define __AML_PSDK_SACONTROLLERCONFIG_H

#include "Pad.h"
#include "../enum/HID.h"
#include "../../gta_base/GxtChar.h"

DECL_CLASS(CKeyboardState)
    // Member functions
    DECL_THISCALL_SIMPLE(Clear, _ZN14CKeyboardState5ClearEv, void);

    // Member values
    i16 kFunc[12];
    i16 kAscii[256];
    i16 kESC;
    i16 kINS;
    i16 kDEL;
    i16 kHOME;
    i16 kEND;
    i16 kPGUP;
    i16 kPGDN;
    i16 kUP;
    i16 kDOWN;
    i16 kLEFT;
    i16 kRIGHT;
    i16 kSCROLL_LOCK;
    i16 kPAUSE_BREAK;
    i16 kNUMPAD_NUMLOCK;
    i16 kNUMPAD_DIVIDE;
    i16 kNUMPAD_TIMES;
    i16 kNUMPAD_MINUS;
    i16 kNUMPAD_PLUS;
    i16 kNUMPAD_ENTER;
    i16 kNUMPAD_DOT;
    i16 kNUMPAD_ONE;
    i16 kNUMPAD_TWO;
    i16 kNUMPAD_THREE;
    i16 kNUMPAD_FOUR;
    i16 kNUMPAD_FIVE;
    i16 kNUMPAD_SIX;
    i16 kNUMPAD_SEVEN;
    i16 kNUMPAD_EIGHT;
    i16 kNUMPAD_NINE;
    i16 kNUMPAD_ZERO;
    i16 kBACKSP;
    i16 kTAB;
    i16 kCAPSLK;
    i16 kENTER;
    i16 kLSHIFT;
    i16 kRSHIFT;
    i16 k98_SHIFT;
    i16 kLCTRL;
    i16 kRCTRL;
    i16 kLALT;
    i16 kRALT;
    i16 kLEFT_WINDOW_KEY;
    i16 kRIGHT_WINDOW_KEY;
    i16 kWINDOW_RIGHT_CLICK_KEY;
DECL_CLASS_END()
CHECKSIZE(CKeyboardState, 0x270, 0x270);

DECL_CLASS(CMousePointerStateHelper)
    // Member functions
    DECL_THISCALL_SIMPLE(GetMouseSetUp, _ZN24CMousePointerStateHelper13GetMouseSetUpEv, CMouseControllerState);

    // Member values
    bool m_bLeftAndRightInverted;
    bool m_bUpAndDownInverted;
DECL_CLASS_END()
CHECKSIZE(CMousePointerStateHelper, 0x2, 0x2);

DECL_CLASS(CControllerConfig)
    // Member values
    u32 m_uiActionInitiator;
    eContSetOrder m_uiSetOrder;
DECL_CLASS_END()
CHECKSIZE(CControllerConfig, 0x8, 0x8);

DECL_CLASS(JoyStruct)
    // Member values
    u32 wDeviceID;
    bool bJoyAttachedToPort;
    bool bZAxisPresent;
    bool bZRotPresent;
    u32 wVendorID;
    u32 wProductID;
DECL_CLASS_END()
CHECKSIZE(JoyStruct, 0x10, 0x10);

DECL_CLASS(CJoySticks)
    // Construct/Deconstruct functions
    DECL_CTORCALL(CJoySticks, _ZN10CJoySticksC2Ev);

    // Member functions
    DECL_THISCALL_HEAD(ClearJoyInfo, _ZN10CJoySticks12ClearJoyInfoEi, void, int joystick)
    DECL_THISCALL_TAIL(ClearJoyInfo, joystick)

    // Member values
    JoyStruct JoyStickNum[2];
DECL_CLASS_END()
CHECKSIZE(CJoySticks, 0x20, 0x20);

DECL_CLASS(CControllerConfigManager)
    // Member functions
    DECL_THISCALL_SIMPLE(GetJoyButtonJustUp, _ZN24CControllerConfigManager18GetJoyButtonJustUpEv, eJOY_BUTTONS);
    DECL_THISCALL_SIMPLE(GetJoyButtonJustDown, _ZN24CControllerConfigManager20GetJoyButtonJustDownEv, eJOY_BUTTONS);
    DECL_THISCALL_SIMPLE(InitDefaultControlConfiguration, _ZN24CControllerConfigManager31InitDefaultControlConfigurationEv, void);
    DECL_THISCALL_HEAD(InitDefaultControlConfigMouse, _ZN24CControllerConfigManager29InitDefaultControlConfigMouseERK21CMouseControllerStateb, void, CMouseControllerState const& state, bool initialise)
    DECL_THISCALL_TAIL(InitDefaultControlConfigMouse, state, initialise)
    DECL_THISCALL_HEAD(InitDefaultControlConfigJoyPad, _ZN24CControllerConfigManager30InitDefaultControlConfigJoyPadEj, void, u32 numButtons)
    DECL_THISCALL_TAIL(InitDefaultControlConfigJoyPad, numButtons)
    DECL_THISCALL_SIMPLE(InitialiseControllerActionNameArray, _ZN24CControllerConfigManager35InitialiseControllerActionNameArrayEv, void);
    DECL_THISCALL_HEAD(StoreMouseButtonState, _ZN24CControllerConfigManager21StoreMouseButtonStateE13eMouseButtonsb, void, eMouseButtons button, bool pressed)
    DECL_THISCALL_TAIL(StoreMouseButtonState, button, pressed)
    DECL_THISCALL_HEAD(UpdateJoyInConfigMenus_ButtonDown, _ZN24CControllerConfigManager33UpdateJoyInConfigMenus_ButtonDownEii, void, i32 button, int padId)
    DECL_THISCALL_TAIL(UpdateJoyInConfigMenus_ButtonDown, button, padId)
    DECL_THISCALL_HEAD(AffectControllerStateOn_ButtonDown, _ZN24CControllerConfigManager34AffectControllerStateOn_ButtonDownEi15eControllerType, void, i32 value1, eControllerType controller)
    DECL_THISCALL_TAIL(AffectControllerStateOn_ButtonDown, value1, controller)
    DECL_THISCALL_HEAD(AffectControllerStateOn_ButtonDown_Driving, _ZN24CControllerConfigManager42AffectControllerStateOn_ButtonDown_DrivingEi15eControllerTypeR16CControllerState, void, i32 value1, eControllerType controller, CControllerState& state)
    DECL_THISCALL_TAIL(AffectControllerStateOn_ButtonDown_Driving, value1, controller, state)
    DECL_THISCALL_HEAD(AffectControllerStateOn_ButtonDown_FirstPersonOnly, _ZN24CControllerConfigManager50AffectControllerStateOn_ButtonDown_FirstPersonOnlyEi15eControllerTypeR16CControllerState, void, i32 value1, eControllerType controller, CControllerState& state)
    DECL_THISCALL_TAIL(AffectControllerStateOn_ButtonDown_FirstPersonOnly, value1, controller, state)
    DECL_THISCALL_HEAD(AffectControllerStateOn_ButtonDown_ThirdPersonOnly, _ZN24CControllerConfigManager50AffectControllerStateOn_ButtonDown_ThirdPersonOnlyEi15eControllerTypeR16CControllerState, void, i32 value1, eControllerType controller, CControllerState& state)
    DECL_THISCALL_TAIL(AffectControllerStateOn_ButtonDown_ThirdPersonOnly, value1, controller, state)
    DECL_THISCALL_HEAD(AffectControllerStateOn_ButtonDown_FirstAndThirdPersonOnly, _ZN24CControllerConfigManager58AffectControllerStateOn_ButtonDown_FirstAndThirdPersonOnlyEi15eControllerTypeR16CControllerState, void, i32 value1, eControllerType controller, CControllerState& state)
    DECL_THISCALL_TAIL(AffectControllerStateOn_ButtonDown_FirstAndThirdPersonOnly, value1, controller, state)
    DECL_THISCALL_HEAD(AffectControllerStateOn_ButtonDown_VehicleAndThirdPersonOnly, _ZN24CControllerConfigManager60AffectControllerStateOn_ButtonDown_VehicleAndThirdPersonOnlyEi15eControllerTypeR16CControllerState, void, i32 value1, eControllerType controller, CControllerState& state)
    DECL_THISCALL_TAIL(AffectControllerStateOn_ButtonDown_VehicleAndThirdPersonOnly, value1, controller, state)
    DECL_THISCALL_HEAD(AffectControllerStateOn_ButtonDown_DebugStuff, _ZN24CControllerConfigManager45AffectControllerStateOn_ButtonDown_DebugStuffEi15eControllerType, void, i32 value1, eControllerType controller)
    DECL_THISCALL_TAIL(AffectControllerStateOn_ButtonDown_DebugStuff, value1, controller)
    DECL_THISCALL_HEAD(AffectControllerStateOn_ButtonDown_AllStates, _ZN24CControllerConfigManager44AffectControllerStateOn_ButtonDown_AllStatesEi15eControllerTypeR16CControllerState, void, i32 value1, eControllerType controller, CControllerState& state)
    DECL_THISCALL_TAIL(AffectControllerStateOn_ButtonDown_AllStates, value1, controller, state)
    DECL_THISCALL_SIMPLE(ClearSimButtonPressCheckers, _ZN24CControllerConfigManager27ClearSimButtonPressCheckersEv, void);
    DECL_THISCALL_HEAD(GetFirstKeyboardControllerText, _ZN24CControllerConfigManager30GetFirstKeyboardControllerTextE18e_ControllerAction, GxtChar*, e_ControllerAction action)
    DECL_THISCALL_TAIL(GetFirstKeyboardControllerText, action)
    DECL_THISCALL_HEAD(GetActionType, _ZN24CControllerConfigManager13GetActionTypeE18e_ControllerAction, eACTION_TYPE, e_ControllerAction action)
    DECL_THISCALL_TAIL(GetActionType, action)
    DECL_THISCALL_HEAD(UpdateJoyInConfigMenus_ButtonUp, _ZN24CControllerConfigManager31UpdateJoyInConfigMenus_ButtonUpEii, void, i32 button, int padId)
    DECL_THISCALL_TAIL(UpdateJoyInConfigMenus_ButtonUp, button, padId)
    DECL_THISCALL_HEAD(AffectControllerStateOn_ButtonUp, _ZN24CControllerConfigManager32AffectControllerStateOn_ButtonUpEi15eControllerType, void, i32 value1, eControllerType controller)
    DECL_THISCALL_TAIL(AffectControllerStateOn_ButtonUp, value1, controller)
    DECL_THISCALL_HEAD(AffectControllerStateOn_ButtonUp_All_Player_States, _ZN24CControllerConfigManager50AffectControllerStateOn_ButtonUp_All_Player_StatesEi15eControllerTypeR16CControllerState, void, i32 value1, eControllerType controller, CControllerState& state)
    DECL_THISCALL_TAIL(AffectControllerStateOn_ButtonUp_All_Player_States, value1, controller, state)
    DECL_THISCALL_HEAD(AffectControllerStateOn_ButtonUp_DebugStuff, _ZN24CControllerConfigManager43AffectControllerStateOn_ButtonUp_DebugStuffEi15eControllerType, void, i32 value1, eControllerType controller)
    DECL_THISCALL_TAIL(AffectControllerStateOn_ButtonUp_DebugStuff, value1, controller)
    DECL_THISCALL_HEAD(ClearSettingsAssociatedWithAction, _ZN24CControllerConfigManager33ClearSettingsAssociatedWithActionE18e_ControllerAction15eControllerType, void, e_ControllerAction action, eControllerType controller)
    DECL_THISCALL_TAIL(ClearSettingsAssociatedWithAction, action, controller)
    DECL_THISCALL_SIMPLE(MakeControllerActionsBlank, _ZN24CControllerConfigManager26MakeControllerActionsBlankEv, void);
    DECL_THISCALL_SIMPLE(ReinitControls, _ZN24CControllerConfigManager14ReinitControlsEv, void);
    DECL_THISCALL_HEAD(GetIsActionAButtonCombo, _ZN24CControllerConfigManager23GetIsActionAButtonComboE18e_ControllerAction, bool, e_ControllerAction action)
    DECL_THISCALL_TAIL(GetIsActionAButtonCombo, action)
    DECL_THISCALL_HEAD(GetButtonComboText, _ZN24CControllerConfigManager18GetButtonComboTextE18e_ControllerAction, GxtChar*, e_ControllerAction action)
    DECL_THISCALL_TAIL(GetButtonComboText, action)
    DECL_THISCALL_HEAD(GetControllerSettingTextKeyBoard, _ZN24CControllerConfigManager32GetControllerSettingTextKeyBoardE18e_ControllerAction15eControllerType, GxtChar*, e_ControllerAction action, eControllerType controller)
    DECL_THISCALL_TAIL(GetControllerSettingTextKeyBoard, action, controller)
    DECL_THISCALL_HEAD(GetControllerSettingTextMouse, _ZN24CControllerConfigManager29GetControllerSettingTextMouseE18e_ControllerAction, GxtChar*, e_ControllerAction action)
    DECL_THISCALL_TAIL(GetControllerSettingTextMouse, action)
    DECL_THISCALL_HEAD(GetControllerSettingTextJoystick, _ZN24CControllerConfigManager32GetControllerSettingTextJoystickE18e_ControllerAction, GxtChar*, e_ControllerAction action)
    DECL_THISCALL_TAIL(GetControllerSettingTextJoystick, action)
    DECL_THISCALL_HEAD(UpdateJoyButtonState, _ZN24CControllerConfigManager20UpdateJoyButtonStateEi, void, int padId)
    DECL_THISCALL_TAIL(UpdateJoyButtonState, padId)
    DECL_THISCALL_HEAD(GetNumOfSettingsForAction, _ZN24CControllerConfigManager25GetNumOfSettingsForActionE18e_ControllerAction, u32, e_ControllerAction action)
    DECL_THISCALL_TAIL(GetNumOfSettingsForAction, action)
    DECL_THISCALL_HEAD(GetGxtStringOfCommandKeys, _ZN24CControllerConfigManager25GetGxtStringOfCommandKeysEtPtt, void, u16 key, GxtChar* text, u16 maxLength)
    DECL_THISCALL_TAIL(GetGxtStringOfCommandKeys, key, text, maxLength)
    DECL_THISCALL_HEAD(GetControllerSettingTextWithOrderNumber, _ZN24CControllerConfigManager39GetControllerSettingTextWithOrderNumberE18e_ControllerAction13eContSetOrder, GxtChar*, e_ControllerAction action, eContSetOrder order)
    DECL_THISCALL_TAIL(GetControllerSettingTextWithOrderNumber, action, order)
    DECL_THISCALL_HEAD(SetControllerKeyAssociatedWithAction, _ZN24CControllerConfigManager36SetControllerKeyAssociatedWithActionE18e_ControllerActioni15eControllerType, void, e_ControllerAction action, i32 value2, eControllerType controller)
    DECL_THISCALL_TAIL(SetControllerKeyAssociatedWithAction, action, value2, controller)
    DECL_THISCALL_HEAD(GetControllerKeyAssociatedWithAction, _ZN24CControllerConfigManager36GetControllerKeyAssociatedWithActionE18e_ControllerAction15eControllerType, i32, e_ControllerAction action, eControllerType controller)
    DECL_THISCALL_TAIL(GetControllerKeyAssociatedWithAction, action, controller)
    DECL_THISCALL_HEAD(SetMouseButtonAssociatedWithAction, _ZN24CControllerConfigManager34SetMouseButtonAssociatedWithActionE18e_ControllerActioni, void, e_ControllerAction action, i32 value2)
    DECL_THISCALL_TAIL(SetMouseButtonAssociatedWithAction, action, value2)
    DECL_THISCALL_HEAD(GetMouseButtonAssociatedWithAction, _ZN24CControllerConfigManager34GetMouseButtonAssociatedWithActionE18e_ControllerAction, i32, e_ControllerAction action)
    DECL_THISCALL_TAIL(GetMouseButtonAssociatedWithAction, action)
    DECL_THISCALL_HEAD(DeleteMatchingActionInitiators, _ZN24CControllerConfigManager30DeleteMatchingActionInitiatorsE18e_ControllerActioni15eControllerType, void, e_ControllerAction action, i32 value2, eControllerType controller)
    DECL_THISCALL_TAIL(DeleteMatchingActionInitiators, action, value2, controller)
    DECL_THISCALL_SIMPLE(AffectPadFromKeyBoard, _ZN24CControllerConfigManager21AffectPadFromKeyBoardEv, void);
    DECL_THISCALL_SIMPLE(AffectPadFromMouse, _ZN24CControllerConfigManager18AffectPadFromMouseEv, void);
    DECL_THISCALL_HEAD(GetIsKeyboardKeyDown, _ZN24CControllerConfigManager20GetIsKeyboardKeyDownE10RsKeyCodes, bool, RsKeyCodes key)
    DECL_THISCALL_TAIL(GetIsKeyboardKeyDown, key)
    DECL_THISCALL_HEAD(GetIsMouseButtonJustUp, _ZN24CControllerConfigManager22GetIsMouseButtonJustUpE10RsKeyCodes, bool, RsKeyCodes key)
    DECL_THISCALL_TAIL(GetIsMouseButtonJustUp, key)
    DECL_THISCALL_HEAD(GetIsMouseButtonDown, _ZN24CControllerConfigManager20GetIsMouseButtonDownE10RsKeyCodes, bool, RsKeyCodes key)
    DECL_THISCALL_TAIL(GetIsMouseButtonDown, key)
    DECL_THISCALL_HEAD(GetIsMouseButtonUp, _ZN24CControllerConfigManager18GetIsMouseButtonUpE10RsKeyCodes, bool, RsKeyCodes key)
    DECL_THISCALL_TAIL(GetIsMouseButtonUp, key)
    DECL_THISCALL_HEAD(ResetSettingOrder, _ZN24CControllerConfigManager17ResetSettingOrderE18e_ControllerAction, void, e_ControllerAction action)
    DECL_THISCALL_TAIL(ResetSettingOrder, action)
    DECL_THISCALL_HEAD(SaveSettings, _ZN24CControllerConfigManager12SaveSettingsEi, void, int file)
    DECL_THISCALL_TAIL(SaveSettings, file)
    DECL_THISCALL_HEAD(LoadSettings, _ZN24CControllerConfigManager12LoadSettingsEi, bool, int file)
    DECL_THISCALL_TAIL(LoadSettings, file)
    DECL_THISCALL_HEAD(DeleteMatchingCommonControls, _ZN24CControllerConfigManager28DeleteMatchingCommonControlsE18e_ControllerActioni15eControllerType, void, e_ControllerAction action, i32 value2, eControllerType controller)
    DECL_THISCALL_TAIL(DeleteMatchingCommonControls, action, value2, controller)
    DECL_THISCALL_HEAD(DeleteMatching3rdPersonControls, _ZN24CControllerConfigManager31DeleteMatching3rdPersonControlsE18e_ControllerActioni15eControllerType, void, e_ControllerAction action, i32 value2, eControllerType controller)
    DECL_THISCALL_TAIL(DeleteMatching3rdPersonControls, action, value2, controller)
    DECL_THISCALL_HEAD(DeleteMatchingVehicleControls, _ZN24CControllerConfigManager29DeleteMatchingVehicleControlsE18e_ControllerActioni15eControllerType, void, e_ControllerAction action, i32 value2, eControllerType controller)
    DECL_THISCALL_TAIL(DeleteMatchingVehicleControls, action, value2, controller)
    DECL_THISCALL_HEAD(DeleteMatchingVehicle_3rdPersonControls, _ZN24CControllerConfigManager39DeleteMatchingVehicle_3rdPersonControlsE18e_ControllerActioni15eControllerType, void, e_ControllerAction action, i32 value2, eControllerType controller)
    DECL_THISCALL_TAIL(DeleteMatchingVehicle_3rdPersonControls, action, value2, controller)
    DECL_THISCALL_HEAD(DeleteMatching1rstPersonControls, _ZN24CControllerConfigManager32DeleteMatching1rstPersonControlsE18e_ControllerActioni15eControllerType, void, e_ControllerAction action, i32 value2, eControllerType controller)
    DECL_THISCALL_TAIL(DeleteMatching1rstPersonControls, action, value2, controller)
    DECL_THISCALL_HEAD(DeleteMatching1rst3rdPersonControls, _ZN24CControllerConfigManager35DeleteMatching1rst3rdPersonControlsE18e_ControllerActioni15eControllerType, void, e_ControllerAction action, i32 value2, eControllerType controller)
    DECL_THISCALL_TAIL(DeleteMatching1rst3rdPersonControls, action, value2, controller)
    DECL_THISCALL_HEAD(GetIsKeyBlank, _ZN24CControllerConfigManager13GetIsKeyBlankEi15eControllerType, bool, i32 value1, eControllerType controller)
    DECL_THISCALL_TAIL(GetIsKeyBlank, value1, controller)
    DECL_THISCALL_HEAD(GetIsKeyboardKeyJustDown, _ZN24CControllerConfigManager24GetIsKeyboardKeyJustDownE10RsKeyCodes, bool, RsKeyCodes key)
    DECL_THISCALL_TAIL(GetIsKeyboardKeyJustDown, key)

    // Member values
    bool m_bJoyJustInitialised;
    int m_OldJoyState;
    int m_NewJoyState;
    GxtChar m_arrControllerActionName[182][40];
    bool m_arrJoyButtonState[2][17];
    CControllerConfig ConfigurationForAction[182][4];
    bool m_bStickL_X_Rgh_Lft_MovementBothDown[4];
    bool m_bStickL_Up_Dwn_MovementBothDown[4];
    bool m_bStickR_X_Rgh_Lft_MovementBothDown[4];
    bool m_bStickR_Up_Dwn_MovementBothDown[4];
    bool MouseFoundInitSet;
DECL_CLASS_END()
CHECKSIZE(CControllerConfigManager, 0x4fe4, 0x4fe4);

DECL_OBJECT_PLT_GLOBAL(CControllerConfigManager, ControlsManager, BYBIT(0x6760A0, 0x84A1B0));
DECL_OBJECT_PLT_GLOBAL(CMousePointerStateHelper, MousePointerStateHelper, BYBIT(0x679510, 0x850A30));

#define ControlsManager ControlsManager()
#define MousePointerStateHelper MousePointerStateHelper()

#endif // __AML_PSDK_SACONTROLLERCONFIG_H
