#ifndef __AML_PSDK_VCDAMAGEMANAGER_H
#define __AML_PSDK_VCDAMAGEMANAGER_H

#include <aml-psdk/game_vc/plugin.h>

enum eDamageState : u32
{
    DAMSTATE_OK = 0,
    DAMSTATE_DAMAGED = 1,
    DAMSTATE_OPENED_DAMAGED = 2,
    DAMSTATE_NOTPRESENT = 3
};

enum tComponent : u32
{
    COMPONENT_DEFAULT = 0,
    COMPONENT_WHEEL_LF = 1,
    COMPONENT_WHEEL_LR = 2,
    COMPONENT_WHEEL_RF = 3,
    COMPONENT_WHEEL_RR = 4,
    COMPONENT_BONNET = 5,
    COMPONENT_BOOT = 6,
    COMPONENT_DOOR_LF = 7,
    COMPONENT_DOOR_RF = 8,
    COMPONENT_DOOR_LR = 9,
    COMPONENT_DOOR_RR = 10,
    COMPONENT_WING_LF = 11,
    COMPONENT_WING_RF = 12,
    COMPONENT_WING_LR = 13,
    COMPONENT_WING_RR = 14,
    COMPONENT_WINDSCREEN = 15,
    COMPONENT_BUMP_FRONT = 16,
    COMPONENT_BUMP_REAR = 17
};

enum tComponentGroup : u32
{
    COMPGROUP_BUMPER = 0,
    COMPGROUP_WHEEL = 1,
    COMPGROUP_DOOR = 2,
    COMPGROUP_BONNET = 3,
    COMPGROUP_BOOT = 4,
    COMPGROUP_PANEL = 5,
    COMPGROUP_NA = 6
};

enum eWheels : u32
{
    WHEEL_FRONT_LEFT = 0,
    WHEEL_REAR_LEFT = 1,
    WHEEL_FRONT_RIGHT = 2,
    WHEEL_REAR_RIGHT = 3
};

enum ePanels : u32
{
    WING_FRONT_LEFT = 0,
    WING_FRONT_RIGHT = 1,
    WING_REAR_LEFT = 2,
    WING_REAR_RIGHT = 3,
    WINDSCREEN = 4,
    BUMP_FRONT = 5,
    BUMP_REAR = 6
};

enum eLights : u32
{
    LIGHT_FRONT_LEFT = 0,
    LIGHT_FRONT_RIGHT = 1,
    LIGHT_REAR_RIGHT = 2,
    LIGHT_REAR_LEFT = 3
};

DECL_CLASS(CDamageManager)
    // Construct/Deconstruct functions
    CDamageManager() : m_fWheelDamageEffect(0.5f), m_nEngineStatus(0), m_anWheelStatus{}, m_anDoorStatus{}, m_nLightStatus(0), m_nPanelStatus(0) {}

    // Member functions
    DECL_THISCALL_HEAD(ApplyDamage, _ZN14CDamageManager11ApplyDamageE10tComponentff, bool, tComponent component, float intensity, float unused)
    DECL_THISCALL_TAIL(ApplyDamage, component, intensity, unused)
    DECL_THISCALL_SIMPLE(FuckCarCompletely, _ZN14CDamageManager17FuckCarCompletelyEv, void);
    DECL_THISCALL_HEAD(GetComponentGroup, _ZN14CDamageManager17GetComponentGroupE10tComponentP15tComponentGroupPh, bool, tComponent component, tComponentGroup* group, u8* damageComponent)
    DECL_THISCALL_TAIL(GetComponentGroup, component, group, damageComponent)
    DECL_THISCALL_SIMPLE(ResetDamageStatus, _ZN14CDamageManager17ResetDamageStatusEv, void);
    DECL_THISCALL_SIMPLE(GetEngineStatus, _ZN14CDamageManager15GetEngineStatusEv, u32);
    DECL_THISCALL_HEAD(SetEngineStatus, _ZN14CDamageManager15SetEngineStatusEj, void, u32 status)
    DECL_THISCALL_TAIL(SetEngineStatus, status)
    DECL_THISCALL_HEAD(GetDoorStatus, _ZN14CDamageManager13GetDoorStatusEi, u32, i32 door)
    DECL_THISCALL_TAIL(GetDoorStatus, door)
    DECL_THISCALL_HEAD(SetDoorStatus, _ZN14CDamageManager13SetDoorStatusEij, void, i32 door, u32 status)
    DECL_THISCALL_TAIL(SetDoorStatus, door, status)
    DECL_THISCALL_HEAD(GetPanelStatus, _ZN14CDamageManager14GetPanelStatusEi, u32, i32 panel)
    DECL_THISCALL_TAIL(GetPanelStatus, panel)
    DECL_THISCALL_HEAD(SetPanelStatus, _ZN14CDamageManager14SetPanelStatusEij, void, i32 panel, u32 status)
    DECL_THISCALL_TAIL(SetPanelStatus, panel, status)
    DECL_THISCALL_HEAD(GetWheelStatus, _ZN14CDamageManager14GetWheelStatusEi, u32, i32 wheel)
    DECL_THISCALL_TAIL(GetWheelStatus, wheel)
    DECL_THISCALL_HEAD(SetWheelStatus, _ZN14CDamageManager14SetWheelStatusEij, void, i32 wheel, u32 status)
    DECL_THISCALL_TAIL(SetWheelStatus, wheel, status)
    DECL_THISCALL_HEAD(GetLightStatus, _ZN14CDamageManager14GetLightStatusE7eLights, u32, eLights light)
    DECL_THISCALL_TAIL(GetLightStatus, light)
    DECL_THISCALL_HEAD(SetLightStatus, _ZN14CDamageManager14SetLightStatusE7eLightsj, void, eLights light, u32 status)
    DECL_THISCALL_TAIL(SetLightStatus, light, status)
    DECL_THISCALL_HEAD(ProgressDoorDamage, _ZN14CDamageManager18ProgressDoorDamageEh, bool, u8 door)
    DECL_THISCALL_TAIL(ProgressDoorDamage, door)
    DECL_THISCALL_HEAD(ProgressPanelDamage, _ZN14CDamageManager19ProgressPanelDamageEh, bool, u8 panel)
    DECL_THISCALL_TAIL(ProgressPanelDamage, panel)
    DECL_THISCALL_HEAD(ProgressWheelDamage, _ZN14CDamageManager19ProgressWheelDamageEh, bool, u8 wheel)
    DECL_THISCALL_TAIL(ProgressWheelDamage, wheel)
    DECL_THISCALL_HEAD(ProgressEngineDamage, _ZN14CDamageManager20ProgressEngineDamageEf, bool, float intensity)
    DECL_THISCALL_TAIL(ProgressEngineDamage, intensity)

    // Member values
    float m_fWheelDamageEffect;
    u8 m_nEngineStatus;
    u8 m_anWheelStatus[4];
    u8 m_anDoorStatus[6];
    u32 m_nLightStatus;
    u32 m_nPanelStatus;
DECL_CLASS_END()
CHECKSIZE(CDamageManager, 0x18, 0x18);

#endif // __AML_PSDK_VCDAMAGEMANAGER_H
