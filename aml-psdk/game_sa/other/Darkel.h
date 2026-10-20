#ifndef __AML_PSDK_SADARKEL_H
#define __AML_PSDK_SADARKEL_H

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/game_sa/enum/WeaponType.h>

struct CPed;
struct CVehicle;

DECL_CLASS(CDarkel)
    enum
    {
        DARKSTAT_INITIALLY = 0,
        DARKSTAT_FRENZYONGOING = 1,
        DARKSTAT_FRENZYPASSED = 2,
        DARKSTAT_FRENZYFAILED = 3,
        DARKSTAT_2PFRENZYONGOING = 4
    };

    // STATIC functions
    DECL_FASTCALL_SIMPLE(Init, _ZN7CDarkel4InitEv, void);
    DECL_FASTCALL_SIMPLE(Update, _ZN7CDarkel6UpdateEv, void);
    DECL_FASTCALL_SIMPLE(DrawMessages, _ZN7CDarkel12DrawMessagesEv, void);
    DECL_FASTCALL_SIMPLE(ReadStatus, _ZN7CDarkel10ReadStatusEv, u16);
    DECL_FASTCALL_SIMPLE(StartFrenzy, _ZN7CDarkel11StartFrenzyE11eWeaponTypeitiPtiiibb, void, eWeaponType weaponType, i32 timeLimit, u16 killsNeeded, i32 modelToKill, u16* startMessage, i32 modelToKill2, i32 modelToKill3, i32 modelToKill4, bool standardSoundAndMessages, bool needHeadshot);
    DECL_FASTCALL_SIMPLE(RegisterKillByPlayer, _ZN7CDarkel20RegisterKillByPlayerEPK4CPed11eWeaponTypebi, void, CPed const* ped, eWeaponType weaponType, bool headshot, i32 playerId);
    DECL_FASTCALL_SIMPLE(RegisterKillNotByPlayer, _ZN7CDarkel23RegisterKillNotByPlayerEPK4CPed11eWeaponType, void, CPed const* ped, eWeaponType weaponType);
    DECL_FASTCALL_SIMPLE(RegisterCarBlownUpByPlayer, _ZN7CDarkel26RegisterCarBlownUpByPlayerEP8CVehiclei, void, CVehicle* vehicle, i32 playerId);
    DECL_FASTCALL_SIMPLE(ThisPedShouldBeKilledForFrenzy, _ZN7CDarkel30ThisPedShouldBeKilledForFrenzyEPK4CPed, bool, CPed const* ped);
    DECL_FASTCALL_SIMPLE(ThisVehicleShouldBeKilledForFrenzy, _ZN7CDarkel34ThisVehicleShouldBeKilledForFrenzyEPK8CVehicle, bool, CVehicle const* vehicle);
    DECL_FASTCALL_SIMPLE(FrenzyOnGoing, _ZN7CDarkel13FrenzyOnGoingEv, bool);
    DECL_FASTCALL_SIMPLE(ResetOnPlayerDeath, _ZN7CDarkel18ResetOnPlayerDeathEv, void);
    DECL_FASTCALL_SIMPLE(FailKillFrenzy, _ZN7CDarkel14FailKillFrenzyEv, void);
    DECL_FASTCALL_SIMPLE(ResetModelsKilledByPlayer, _ZN7CDarkel25ResetModelsKilledByPlayerEi, void, i32 playerId);
    DECL_FASTCALL_SIMPLE(QueryModelsKilledByPlayer, _ZN7CDarkel25QueryModelsKilledByPlayerEii, i16, i32 modelId, i32 playerId);
    DECL_FASTCALL_SIMPLE(FindTotalPedsKilledByPlayer, _ZN7CDarkel27FindTotalPedsKilledByPlayerEi, i32, i32 playerId);
    DECL_FASTCALL_SIMPLE(CalcFade, _ZN7CDarkel8CalcFadeEjjj, u8, u32 time, u32 start, u32 end);
    DECL_FASTCALL_SIMPLE(DealWithWeaponChangeAtEndOfFrenzy, _ZN7CDarkel33DealWithWeaponChangeAtEndOfFrenzyEv, void);
    DECL_FASTCALL_SIMPLE(CheckDamagedWeaponType, _ZN7CDarkel22CheckDamagedWeaponTypeEii, bool, i32 weaponType, i32 damagedWeaponType);

    // STATIC values
    DECL_OBJECT_PLT(u16, Status, BYBIT(0x679950, 0x8512c0));
    DECL_OBJECT_PLT(eWeaponType, WeaponType, BYBIT(0x679a14, 0x851440));
    DECL_OBJECT_PLT(i32, ModelToKill, BYBIT(0x6772c8, 0x84c5c8));
    DECL_OBJECT_PLT(i32, ModelToKill2, BYBIT(0x676d7c, 0x84bb40));
    DECL_OBJECT_PLT(i32, ModelToKill3, BYBIT(0x679c3c, 0x851890));
    DECL_OBJECT_PLT(i32, ModelToKill4, BYBIT(0x6761f8, 0x84a450));
    DECL_OBJECT_PLT(i32, KillsNeeded, BYBIT(0x678c78, 0x84f918));
    DECL_OBJECT_PLT(i32, TimeLimit, BYBIT(0x679860, 0x8510d8));
    DECL_OBJECT_PLT(i32, PreviousTime, BYBIT(0x676abc, 0x84b5c0));
    DECL_OBJECT_PLT(u32, TimeOfFrenzyStart, BYBIT(0x676c34, 0x84b8b0));
    DECL_OBJECT_PLT(eWeaponType, InterruptedWeaponTypeSelected, BYBIT(0x676094, 0x84a198));
    DECL_OBJECT_PLT(eWeaponType, InterruptedWeaponType, BYBIT(0x67954c, 0x850aa8));
    DECL_OBJECT_PLT(i32, AmmoInterruptedWeapon, BYBIT(0x678194, 0x84e340));
    DECL_OBJECT_PLT(u16*, pStartMessage, BYBIT(0x679588, 0x850b20));
    typedef i16 RegisteredKills_t[2];
    DECL_OBJECT_ARRAY_PLT(RegisteredKills_t, RegisteredKills, BYBIT(0x678aac, 0x84f580));
    DECL_OBJECT_PLT(bool, bStandardSoundAndMessages, BYBIT(0x677634, 0x84cc98));
    DECL_OBJECT_PLT(bool, bNeedHeadShot, BYBIT(0x679650, 0x850cb0));
    DECL_OBJECT_PLT(bool, bProperKillFrenzy, BYBIT(0x6798f4, 0x851208));

DECL_CLASS_END()
CHECKSIZE(CDarkel, 0x1, 0x1);

#endif // __AML_PSDK_SADARKEL_H
