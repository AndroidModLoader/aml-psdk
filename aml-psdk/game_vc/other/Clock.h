#ifndef __AML_PSDK_VCCLOCK_H
#define __AML_PSDK_VCCLOCK_H

#include <aml-psdk/game_vc/plugin.h>

DECL_CLASS(CClock)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(Initialise, _ZN6CClock10InitialiseEj, void, u32 msPerGameMinute);
    DECL_FASTCALL_SIMPLE(SetGameClock, _ZN6CClock12SetGameClockEhh, void, u8 hour, u8 min);
    DECL_FASTCALL_SIMPLE(NormaliseGameClock, _ZN6CClock18NormaliseGameClockEv, void);
    DECL_FASTCALL_SIMPLE(GetGameClockMinutesUntil, _ZN6CClock24GetGameClockMinutesUntilEhh, u32, u8 hour, u8 min);
    DECL_FASTCALL_SIMPLE(GetIsTimeInRange, _ZN6CClock16GetIsTimeInRangeEhh, bool, u8 startHour, u8 endHour);
    DECL_FASTCALL_SIMPLE(Update, _ZN6CClock6UpdateEv, void);
    DECL_FASTCALL_SIMPLE(StoreClock, _ZN6CClock10StoreClockEv, void);
    DECL_FASTCALL_SIMPLE(RestoreClock, _ZN6CClock12RestoreClockEv, void);

    // STATIC values
    DECL_VALUE_PLT_U32(ms_nMillisecondsPerGameMinute, BYBIT(0x395924, 0x579290));
    DECL_VALUE_PLT_U32(ms_nLastClockTick, BYBIT(0x396634, 0x57AC70));
    DECL_VALUE_PLT_U8(ms_nGameClockHours, BYBIT(0x3959E0, 0x5793F8));
    DECL_VALUE_PLT_U8(ms_nGameClockMinutes, BYBIT(0x39474C, 0x576FE8));
    DECL_VALUE_PLT_U16(ms_nGameClockSeconds, BYBIT(0x3969FC, 0x57B408));
    DECL_VALUE_PLT_U8(ms_Stored_nGameClockHours, BYBIT(0x395128, 0x5782B8));
    DECL_VALUE_PLT_U8(ms_Stored_nGameClockMinutes, BYBIT(0x394864, 0x577200));
    DECL_VALUE_PLT_U16(ms_Stored_nGameClockSeconds, BYBIT(0x3954F0, 0x578A48));
    DECL_VALUE_PLT_BOOL(bClockHasBeenStored, BYBIT(0x396790, 0x57AF20));
DECL_CLASS_END()

#define ms_nMillisecondsPerGameMinute ms_nMillisecondsPerGameMinute()
#define ms_nLastClockTick ms_nLastClockTick()
#define ms_nGameClockHours ms_nGameClockHours()
#define ms_nGameClockMinutes ms_nGameClockMinutes()
#define ms_nGameClockSeconds ms_nGameClockSeconds()
#define ms_Stored_nGameClockHours ms_Stored_nGameClockHours()
#define ms_Stored_nGameClockMinutes ms_Stored_nGameClockMinutes()
#define ms_Stored_nGameClockSeconds ms_Stored_nGameClockSeconds()
#define bClockHasBeenStored bClockHasBeenStored()

#endif // __AML_PSDK_VCCLOCK_H
