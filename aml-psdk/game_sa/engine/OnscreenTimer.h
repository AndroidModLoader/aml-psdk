#ifndef __AML_PSDK_SAONSCREENTIMER_H
#define __AML_PSDK_SAONSCREENTIMER_H

#include <aml-psdk/game_sa/plugin.h>

struct CZone;
struct CVehicle;

DECL_CLASS(COnscreenTimerEntry)
    u32 ClockIndex;
    char ClockTextKey[10];
    char ClockString[42];
    bool Clock;
    bool bCountDown;
    u32 SecsToStartBeeping;

    DECL_THISCALL_SIMPLE(ProcessForDisplayClock, _ZN19COnscreenTimerEntry22ProcessForDisplayClockEv, void);
    DECL_THISCALL_SIMPLE(Process, _ZN19COnscreenTimerEntry7ProcessEv, void);
DECL_CLASS_END()
CHECKSIZE(COnscreenTimerEntry, 0x40, 0x40);

DECL_CLASS(COnscreenCounterEntry)
    u32 CounterIndex;
    u32 CounterIndex2;
    char CounterTextKey[10];
    u16 CounterDisplayMethod;
    char CounterString[42];
    u8 Counter;
    u8 bFlashWhenFirstDisplayed;
    u8 iColour_id;

    DECL_THISCALL(ProcessForDisplayCounter, _ZN21COnscreenCounterEntry24ProcessForDisplayCounterEt, void, u16 counterType);
    DECL_THISCALL(SetColourID, _ZN21COnscreenCounterEntry11SetColourIDEh, void, u8 colourId);
    inline u8 GetColourID() { return iColour_id; }
DECL_CLASS_END()
CHECKSIZE(COnscreenCounterEntry, 0x44, 0x44);

DECL_CLASS(COnscreenTimer)
    COnscreenTimerEntry TimerEntry[1];
    COnscreenCounterEntry CounterEntry[4];
    u8 ClockOrCountersToDisplay;
    u8 FreezeTimers;

    DECL_THISCALL_SIMPLE(Init, _ZN14COnscreenTimer4InitEv, void);
    DECL_THISCALL_SIMPLE(ProcessForDisplay, _ZN14COnscreenTimer17ProcessForDisplayEv, void);
    DECL_THISCALL_SIMPLE(Process, _ZN14COnscreenTimer7ProcessEv, void);
    DECL_THISCALL(AddClock, _ZN14COnscreenTimer8AddClockEjPcb, void, u32 clockIndex, char* pTextKey, bool bCountDown);
    DECL_THISCALL(AddCounter, _ZN14COnscreenTimer10AddCounterEjtPct, void, u32 counterIndex, u16 counterType, char* pTextKey, u16 line);
    DECL_THISCALL(AddCounterCounter, _ZN14COnscreenTimer17AddCounterCounterEjjPct, void, u32 counterIndex, u32 maxCounterIndex, char* pTextKey, u16 line);
    DECL_THISCALL(ClearClock, _ZN14COnscreenTimer10ClearClockEj, void, u32 clockIndex);
    DECL_THISCALL(ClearCounter, _ZN14COnscreenTimer12ClearCounterEj, void, u32 counterIndex);
    DECL_THISCALL(SetCounterFlashWhenFirstDisplayed, _ZN14COnscreenTimer33SetCounterFlashWhenFirstDisplayedEjh, void, u32 counterIndex, u8 bFlash);
    DECL_THISCALL(SetClockBeepCountdownSecs, _ZN14COnscreenTimer25SetClockBeepCountdownSecsEjj, void, u32 clockIndex, u32 seconds);
    DECL_THISCALL(SetCounterColourID, _ZN14COnscreenTimer18SetCounterColourIDEjh, void, u32 counterIndex, u8 colourId);
    DECL_THISCALL_SIMPLE(Save, _ZN14COnscreenTimer4SaveEv, void);
    DECL_THISCALL_SIMPLE(Load, _ZN14COnscreenTimer4LoadEv, void);
DECL_CLASS_END()
CHECKSIZE(COnscreenTimer, 0x154, 0x154);

DECL_CLASS(CPlaceName)
    CZone* pNavZone;
    u16 Timer;

    DECL_CTORCALL(CPlaceName, _ZN10CPlaceNameC2Ev);
    DECL_THISCALL_SIMPLE(Init, _ZN10CPlaceName4InitEv, void);
    DECL_THISCALL(GetForMap, _ZN10CPlaceName9GetForMapEff, u16*, float x, float y);
    DECL_THISCALL_SIMPLE(Process, _ZN10CPlaceName7ProcessEv, void);
    DECL_THISCALL_SIMPLE(ProcessAfterFrontEndShutDown, _ZN10CPlaceName28ProcessAfterFrontEndShutDownEv, void);
    DECL_THISCALL_SIMPLE(Display, _ZN10CPlaceName7DisplayEv, void);
DECL_CLASS_END()
CHECKSIZE(CPlaceName, 0x8, 0x10);

DECL_CLASS(CCurrentVehicle)
    CVehicle* pCurrentVehicle;

    DECL_CTORCALL(CCurrentVehicle, _ZN15CCurrentVehicleC2Ev);
    DECL_THISCALL_SIMPLE(Init, _ZN15CCurrentVehicle4InitEv, void);
    DECL_THISCALL_SIMPLE(Process, _ZN15CCurrentVehicle7ProcessEv, void);
    DECL_THISCALL_SIMPLE(Display, _ZN15CCurrentVehicle7DisplayEv, void);
DECL_CLASS_END()
CHECKSIZE(CCurrentVehicle, 0x4, 0x8);

DECL_CLASS(CUserDisplay)
    DECL_FASTCALL_SIMPLE(Init, _ZN12CUserDisplay4InitEv, void);
    DECL_FASTCALL_SIMPLE(Process, _ZN12CUserDisplay7ProcessEv, void);

    DECL_OBJECT_SYM(CPlaceName, PlaceName, _ZN12CUserDisplay9PlaceNameE);
    DECL_OBJECT_SYM(COnscreenTimer, OnscnTimer, _ZN12CUserDisplay10OnscnTimerE);
    DECL_OBJECT_SYM(CCurrentVehicle, CurrentVehicle, _ZN12CUserDisplay14CurrentVehicleE);
DECL_CLASS_END()

#define PlaceName PlaceName()
#define OnscnTimer OnscnTimer()
#define CurrentVehicle CurrentVehicle()

#endif // __AML_PSDK_SAONSCREENTIMER_H
