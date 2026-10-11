#ifndef __AML_PSDK_SACHEAT_H
#define __AML_PSDK_SACHEAT_H

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/game_sa/enum/Cheats.h>

struct CVehicle;

typedef void (*tCheatFunction)();

DECL_CLASS(CCheat)
    enum eCheat : i32;

    // STATIC functions
    DECL_FASTCALL_SIMPLE(WeaponCheat1, _ZN6CCheat12WeaponCheat1Ev, void);
    DECL_FASTCALL_SIMPLE(WeaponCheat2, _ZN6CCheat12WeaponCheat2Ev, void);
    DECL_FASTCALL_SIMPLE(WeaponCheat3, _ZN6CCheat12WeaponCheat3Ev, void);
    DECL_FASTCALL_SIMPLE(WeaponCheat4, _ZN6CCheat12WeaponCheat4Ev, void);
    DECL_FASTCALL_SIMPLE(TimeTravelCheat, _ZN6CCheat15TimeTravelCheatEv, void);
    DECL_FASTCALL_SIMPLE(ScriptBypassCheat, _ZN6CCheat17ScriptBypassCheatEv, void);
    DECL_FASTCALL_SIMPLE(ShowMappingsCheat, _ZN6CCheat17ShowMappingsCheatEv, void);
    DECL_FASTCALL_SIMPLE(TogglePlayerInvincibility, _ZN6CCheat25TogglePlayerInvincibilityEv, void);
    DECL_FASTCALL_SIMPLE(ToggleShowTapToTarget, _ZN6CCheat21ToggleShowTapToTargetEv, void);
    DECL_FASTCALL_SIMPLE(ToggleShowTargeting, _ZN6CCheat19ToggleShowTargetingEv, void);
    DECL_FASTCALL_SIMPLE(MoneyArmourHealthCheat, _ZN6CCheat22MoneyArmourHealthCheatEv, void);
    DECL_FASTCALL_SIMPLE(WantedLevelUpCheat, _ZN6CCheat18WantedLevelUpCheatEv, void);
    DECL_FASTCALL_SIMPLE(WantedLevelDownCheat, _ZN6CCheat20WantedLevelDownCheatEv, void);
    DECL_FASTCALL_SIMPLE(SunnyWeatherCheat, _ZN6CCheat17SunnyWeatherCheatEv, void);
    DECL_FASTCALL_SIMPLE(ExtraSunnyWeatherCheat, _ZN6CCheat22ExtraSunnyWeatherCheatEv, void);
    DECL_FASTCALL_SIMPLE(CloudyWeatherCheat, _ZN6CCheat18CloudyWeatherCheatEv, void);
    DECL_FASTCALL_SIMPLE(RainyWeatherCheat, _ZN6CCheat17RainyWeatherCheatEv, void);
    DECL_FASTCALL_SIMPLE(FoggyWeatherCheat, _ZN6CCheat17FoggyWeatherCheatEv, void);
    DECL_FASTCALL_SIMPLE(FastTimeCheat, _ZN6CCheat13FastTimeCheatEv, void);
    DECL_FASTCALL_SIMPLE(SlowTimeCheat, _ZN6CCheat13SlowTimeCheatEv, void);
    DECL_FASTCALL_SIMPLE(MayhemCheat, _ZN6CCheat11MayhemCheatEv, void);
    DECL_FASTCALL_SIMPLE(EverybodyAttacksPlayerCheat, _ZN6CCheat27EverybodyAttacksPlayerCheatEv, void);
    DECL_FASTCALL_SIMPLE(TankCheat, _ZN6CCheat9TankCheatEv, void);
    DECL_FASTCALL_SIMPLE(StockCarCheat, _ZN6CCheat13StockCarCheatEv, void);
    DECL_FASTCALL_SIMPLE(StockCar2Cheat, _ZN6CCheat14StockCar2CheatEv, void);
    DECL_FASTCALL_SIMPLE(StockCar3Cheat, _ZN6CCheat14StockCar3CheatEv, void);
    DECL_FASTCALL_SIMPLE(StockCar4Cheat, _ZN6CCheat14StockCar4CheatEv, void);
    DECL_FASTCALL_SIMPLE(HearseCheat, _ZN6CCheat11HearseCheatEv, void);
    DECL_FASTCALL_SIMPLE(LovefistCheat, _ZN6CCheat13LovefistCheatEv, void);
    DECL_FASTCALL_SIMPLE(TrashmasterCheat, _ZN6CCheat16TrashmasterCheatEv, void);
    DECL_FASTCALL_SIMPLE(GolfcartCheat, _ZN6CCheat13GolfcartCheatEv, void);
    DECL_FASTCALL_SIMPLE(BlowUpCarsCheat, _ZN6CCheat15BlowUpCarsCheatEv, void);
    DECL_FASTCALL_SIMPLE(SuicideCheat, _ZN6CCheat12SuicideCheatEv, void);
    DECL_FASTCALL_SIMPLE(PinkCarsCheat, _ZN6CCheat13PinkCarsCheatEv, void);
    DECL_FASTCALL_SIMPLE(BlackCarsCheat, _ZN6CCheat14BlackCarsCheatEv, void);
    DECL_FASTCALL_SIMPLE(FatCheat, _ZN6CCheat8FatCheatEv, void);
    DECL_FASTCALL_SIMPLE(MuscleCheat, _ZN6CCheat11MuscleCheatEv, void);
    DECL_FASTCALL_SIMPLE(TheGamblerCheat, _ZN6CCheat15TheGamblerCheatEv, void);
    DECL_FASTCALL_SIMPLE(SkinnyCheat, _ZN6CCheat11SkinnyCheatEv, void);
    DECL_FASTCALL_SIMPLE(ElvisLivesCheat, _ZN6CCheat15ElvisLivesCheatEv, void);
    DECL_FASTCALL_SIMPLE(VillagePeopleCheat, _ZN6CCheat18VillagePeopleCheatEv, void);
    DECL_FASTCALL_SIMPLE(BeachPartyCheat, _ZN6CCheat15BeachPartyCheatEv, void);
    DECL_FASTCALL_SIMPLE(GangsCheat, _ZN6CCheat10GangsCheatEv, void);
    DECL_FASTCALL_SIMPLE(GangLandCheat, _ZN6CCheat13GangLandCheatEv, void);
    DECL_FASTCALL_SIMPLE(NinjaCheat, _ZN6CCheat10NinjaCheatEv, void);
    DECL_FASTCALL_SIMPLE(LoveConquersAllCheat, _ZN6CCheat20LoveConquersAllCheatEv, void);
    DECL_FASTCALL_SIMPLE(AllCarsAreShitCheat, _ZN6CCheat19AllCarsAreShitCheatEv, void);
    DECL_FASTCALL_SIMPLE(AllCarsAreGreatCheat, _ZN6CCheat20AllCarsAreGreatCheatEv, void);
    DECL_FASTCALL_SIMPLE(FlyboyCheat, _ZN6CCheat11FlyboyCheatEv, void);
    DECL_FASTCALL_SIMPLE(VortexCheat, _ZN6CCheat11VortexCheatEv, void);
    DECL_FASTCALL_SIMPLE(MidnightCheat, _ZN6CCheat13MidnightCheatEv, void);
    DECL_FASTCALL_SIMPLE(DuskCheat, _ZN6CCheat9DuskCheatEv, void);
    DECL_FASTCALL_SIMPLE(StormCheat, _ZN6CCheat10StormCheatEv, void);
    DECL_FASTCALL_SIMPLE(SandstormCheat, _ZN6CCheat14SandstormCheatEv, void);
    DECL_FASTCALL_SIMPLE(PredatorCheat, _ZN6CCheat13PredatorCheatEv, void);
    DECL_FASTCALL_SIMPLE(ParachuteCheat, _ZN6CCheat14ParachuteCheatEv, void);
    DECL_FASTCALL_SIMPLE(JetpackCheat, _ZN6CCheat12JetpackCheatEv, void);
    DECL_FASTCALL_SIMPLE(NotWantedCheat, _ZN6CCheat14NotWantedCheatEv, void);
    DECL_FASTCALL_SIMPLE(WantedCheat, _ZN6CCheat11WantedCheatEv, void);
    DECL_FASTCALL_SIMPLE(RiotCheat, _ZN6CCheat9RiotCheatEv, void);
    DECL_FASTCALL_SIMPLE(FunhouseCheat, _ZN6CCheat13FunhouseCheatEv, void);
    DECL_FASTCALL_SIMPLE(AdrenalineCheat, _ZN6CCheat15AdrenalineCheatEv, void);
    DECL_FASTCALL_SIMPLE(DrivebyCheat, _ZN6CCheat12DrivebyCheatEv, void);
    DECL_FASTCALL_SIMPLE(CountrysideInvasionCheat, _ZN6CCheat24CountrysideInvasionCheatEv, void);
    DECL_FASTCALL_SIMPLE(StaminaCheat, _ZN6CCheat12StaminaCheatEv, void);
    DECL_FASTCALL_SIMPLE(WeaponSkillsCheat, _ZN6CCheat17WeaponSkillsCheatEv, void);
    DECL_FASTCALL_SIMPLE(VehicleSkillsCheat, _ZN6CCheat18VehicleSkillsCheatEv, void);
    DECL_FASTCALL_SIMPLE(ApacheCheat, _ZN6CCheat11ApacheCheatEv, void);
    DECL_FASTCALL_SIMPLE(QuadCheat, _ZN6CCheat9QuadCheatEv, void);
    DECL_FASTCALL_SIMPLE(TankerCheat, _ZN6CCheat11TankerCheatEv, void);
    DECL_FASTCALL_SIMPLE(DozerCheat, _ZN6CCheat10DozerCheatEv, void);
    DECL_FASTCALL_SIMPLE(StuntPlaneCheat, _ZN6CCheat15StuntPlaneCheatEv, void);
    DECL_FASTCALL_SIMPLE(MonsterTruckCheat, _ZN6CCheat17MonsterTruckCheatEv, void);
    DECL_FASTCALL_SIMPLE(WeaponSlotCheat, _ZN6CCheat15WeaponSlotCheatEv, void);
    DECL_FASTCALL_SIMPLE(xboxHelperCheat, _ZN6CCheat15xboxHelperCheatEv, void);
    DECL_FASTCALL_SIMPLE(FindCheatIndex, _ZN6CCheat14FindCheatIndexEPKc, i32, char const* pCheatString);
    DECL_FASTCALL_SIMPLE(DoCheats, _ZN6CCheat8DoCheatsEv, void);
    DECL_FASTCALL_SIMPLE(AddToCheatString, _ZN6CCheat16AddToCheatStringEc, void, char LastPressedKey);
    DECL_FASTCALL_SIMPLE(ResetCheats, _ZN6CCheat11ResetCheatsEv, void);
    DECL_FASTCALL_SIMPLE(HealthCheat, _ZN6CCheat11HealthCheatEv, void);
    DECL_FASTCALL_SIMPLE(VehicleCheat, _ZN6CCheat12VehicleCheatEi, CVehicle*, i32 vehicleModelId);
    DECL_FASTCALL_SIMPLE(StartPause, _ZN6CCheat10StartPauseEv, void);
    DECL_FASTCALL_SIMPLE(ClearMissionSkip, _ZN6CCheat16ClearMissionSkipEv, void);
    DECL_FASTCALL_SIMPLE(EndPause, _ZN6CCheat8EndPauseEv, void);
    DECL_FASTCALL_SIMPLE(ClearGameCheatsList, _ZN6CCheat19ClearGameCheatsListEv, void);
    DECL_FASTCALL_SIMPLE(HandleGameCheats, _ZN6CCheat16HandleGameCheatsEv, void);
    DECL_FASTCALL_SIMPLE(HandleCarCheat, _ZN6CCheat14HandleCarCheatEv, void);
    DECL_FASTCALL_SIMPLE(HandleMissionJump, _ZN6CCheat17HandleMissionJumpEbi, void, bool bPressed, i32 mission);
    DECL_FASTCALL_SIMPLE(HandleCheatMenu, _ZN6CCheat15HandleCheatMenuEb, void, bool bPressed);
    DECL_FASTCALL_SIMPLE(ProcessAllCheats, _ZN6CCheat16ProcessAllCheatsEv, void);
    DECL_FASTCALL_SIMPLE(HandleAllCheats, _ZN6CCheat15HandleAllCheatsEv, void);
    DECL_FASTCALL_SIMPLE(ProcessDebugCarCheats, _ZN6CCheat21ProcessDebugCarCheatsEv, void);
    DECL_FASTCALL_SIMPLE(ProcessDebugMissionSkip, _ZN6CCheat23ProcessDebugMissionSkipEv, void);
    DECL_FASTCALL_SIMPLE(ProcessCheatMenu, _ZN6CCheat16ProcessCheatMenuEv, void);
    DECL_FASTCALL_SIMPLE(ProcessCheats, _ZN6CCheat13ProcessCheatsEv, bool);
    DECL_FASTCALL_SIMPLE(ProcessWeaponSlotCheats, _ZN6CCheat23ProcessWeaponSlotCheatsEv, void);
    DECL_FASTCALL_SIMPLE(ClearVehiclePopulationCheats, _ZN6CCheat28ClearVehiclePopulationCheatsENS_6eCheatE, void, CCheat::eCheat cheat);

    // STATIC values
    DECL_OBJECT_ARRAY_PLT(const char*, CheatLabel, BYBIT(0x679ECC, 0x851DA8));
    DECL_OBJECT_ARRAY_PLT(tCheatFunction, m_aCheatFunctions, BYBIT(0x6781E8, 0x84E3E8));
    DECL_OBJECT_ARRAY_PLT(u32, m_aCheatHashKeys, BYBIT(0x678830, 0x84F080));
    DECL_OBJECT_ARRAY_SYM(const char*, m_aCheatStrings, _ZN6CCheat15m_aCheatStringsE);
    DECL_OBJECT_ARRAY_PLT(u8, m_aCheatsActive, BYBIT(0x6790B4, 0x850190));
    DECL_VALUE_PLT_U8(m_bHasPlayerCheated, BYBIT(0x678CFC, 0x84FA20));
    DECL_VALUE_PLT_I32(m_nLastScriptBypasstime, BYBIT(0x6780E0, 0x84E1D8));
    DECL_OBJECT_ARRAY_PLT(char, m_CheatString, BYBIT(0x679048, 0x8500B8));
    DECL_VALUE_PLT_BOOL(m_bShowMappings, BYBIT(0x676A0C, 0x84B460));
DECL_CLASS_END()

#define CheatLabel CheatLabel()
#define m_aCheatFunctions m_aCheatFunctions()
#define m_aCheatHashKeys m_aCheatHashKeys()
#define m_aCheatStrings m_aCheatStrings()
#define m_aCheatsActive m_aCheatsActive()
#define m_bHasPlayerCheated m_bHasPlayerCheated()
#define m_nLastScriptBypasstime m_nLastScriptBypasstime()
#define m_CheatString m_CheatString()
#define m_bShowMappings m_bShowMappings()

#endif // __AML_PSDK_SACHEAT_H
