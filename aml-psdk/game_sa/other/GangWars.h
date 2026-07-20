#ifndef __AML_PSDK_SAGANGWARS_H
#define __AML_PSDK_SAGANGWARS_H

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/game_sa/enum/WeaponType.h>
#include <aml-psdk/gta_base/Vector.h>

struct CVector;
struct CZone;
struct CZoneInfo;

DECL_CLASS(CGangInfo)
    // Member values
    i8                                 PedModelOverride;
    eWeaponType                        FirstWeapon;
    eWeaponType                        SecondWeapon;
    eWeaponType                        ThirdWeapon;

    // Functions
    DECL_CTORCALL(CGangInfo, _ZN9CGangInfoC2Ev);
    DECL_DTORCALL(CGangInfo, _ZN9CGangInfoD2Ev);

DECL_CLASS_END()
CHECKSIZE(CGangInfo, 0x10, 0x10);  // 64-bit from the IDB; 32-bit measured from this layout

DECL_CLASS(CGangWars)
    // Functions
    DECL_FASTCALL_SIMPLE(InitAtStartOfGame, _ZN9CGangWars17InitAtStartOfGameEv, void);
    DECL_FASTCALL_SIMPLE(StartOffensiveGangWar, _ZN9CGangWars21StartOffensiveGangWarEv, void);
    DECL_FASTCALL_SIMPLE(CanPlayerStartAGangWarHere, _ZN9CGangWars26CanPlayerStartAGangWarHereEP9CZoneInfo, bool, CZoneInfo* pZoneToTest);
    DECL_FASTCALL_SIMPLE(ClearTheStreets, _ZN9CGangWars15ClearTheStreetsEv, void);
    DECL_FASTCALL_SIMPLE(TellGangMembersTo, _ZN9CGangWars17TellGangMembersToEi, void, i32 ToDoWhat);
    DECL_FASTCALL_SIMPLE(StartDefensiveGangWar, _ZN9CGangWars21StartDefensiveGangWarEv, void);
    DECL_FASTCALL_SIMPLE(PickZoneToAttack, _ZN9CGangWars16PickZoneToAttackEv, bool);
    DECL_FASTCALL_SIMPLE(CalculateTimeTillNextAttack, _ZN9CGangWars27CalculateTimeTillNextAttackEv, u32);
    DECL_FASTCALL_SIMPLE(DoStuffWhenPlayerVictorious, _ZN9CGangWars27DoStuffWhenPlayerVictoriousEv, void);
    DECL_FASTCALL_SIMPLE(ReleasePedsInAttackWave, _ZN9CGangWars23ReleasePedsInAttackWaveEbb, i32, bool bKillAllBlips, const bool bMakePedsWanderAway);
    DECL_FASTCALL_SIMPLE(ReleaseCarsInAttackWave, _ZN9CGangWars23ReleaseCarsInAttackWaveEv, void);
    DECL_FASTCALL_SIMPLE(CheerVictory, _ZN9CGangWars12CheerVictoryEv, void);
    DECL_FASTCALL_SIMPLE(Update, _ZN9CGangWars6UpdateEv, void);
    DECL_FASTCALL_SIMPLE(EndGangWar, _ZN9CGangWars10EndGangWarEb, void, const bool bMakePedsWanderAway);
    DECL_FASTCALL_SIMPLE(UpdateTerritoryUnderControlPercentage, _ZN9CGangWars37UpdateTerritoryUnderControlPercentageEv, void);
    DECL_FASTCALL_SIMPLE(CreateAttackWave, _ZN9CGangWars16CreateAttackWaveEii, bool, i32 Ferocity, i32 Number);
    DECL_FASTCALL_SIMPLE(AttackWaveOvercome, _ZN9CGangWars18AttackWaveOvercomeEv, bool);
    DECL_FASTCALL_SIMPLE(MakePlayerGainInfluenceInZone, _ZN9CGangWars29MakePlayerGainInfluenceInZoneEf, bool, float Perc);
    DECL_FASTCALL_SIMPLE(CreateDefendingGroup, _ZN9CGangWars20CreateDefendingGroupEi, bool, i32 Ferocity);
    DECL_FASTCALL_SIMPLE(MakeEnemyGainInfluenceInZone, _ZN9CGangWars28MakeEnemyGainInfluenceInZoneEii, void, i32 Gang, i32 Points);
    DECL_FASTCALL_SIMPLE(StrengthenPlayerInfluenceInZone, _ZN9CGangWars31StrengthenPlayerInfluenceInZoneEi, void, i32 Amount);
    DECL_FASTCALL_SIMPLE(AddKillToProvocation, _ZN9CGangWars20AddKillToProvocationEi, void, i32 PedType);
    DECL_FASTCALL_SIMPLE(DontCreateCivilians, _ZN9CGangWars19DontCreateCiviliansEv, bool);
    DECL_FASTCALL_SIMPLE(PedStreamedInForThisGang, _ZN9CGangWars24PedStreamedInForThisGangEi, bool, i32 Gang);
    DECL_FASTCALL_SIMPLE(PickStreamedInPedForThisGang, _ZN9CGangWars28PickStreamedInPedForThisGangEiPi, bool, i32 Gang, i32* pMI);
    DECL_FASTCALL_SIMPLE(SetGangWarsActive, _ZN9CGangWars17SetGangWarsActiveEb, void, bool bActive);
    DECL_FASTCALL_SIMPLE(SwitchGangWarsActive, _ZN9CGangWars20SwitchGangWarsActiveEv, void);
    DECL_FASTCALL_SIMPLE(GangWarGoingOn, _ZN9CGangWars14GangWarGoingOnEv, bool);
    DECL_FASTCALL_SIMPLE(GangWarFightingGoingOn, _ZN9CGangWars22GangWarFightingGoingOnEv, bool);
    DECL_FASTCALL_SIMPLE(DoesPlayerControlThisZone, _ZN9CGangWars25DoesPlayerControlThisZoneEP9CZoneInfo, bool, CZoneInfo* pZoneInfo);
    DECL_FASTCALL_SIMPLE(TellStreamingWhichGangsAreNeeded, _ZN9CGangWars32TellStreamingWhichGangsAreNeededEPi, void, i32* pRequiredGangs);
    DECL_FASTCALL_SIMPLE(ClearSpecificZonesToTriggerGangWar, _ZN9CGangWars34ClearSpecificZonesToTriggerGangWarEv, void);
    DECL_FASTCALL_SIMPLE(SetSpecificZoneToTriggerGangWar, _ZN9CGangWars31SetSpecificZoneToTriggerGangWarEi, void, i32 Zone);
    DECL_FASTCALL_SIMPLE(Save, _ZN9CGangWars4SaveEv, bool);
    DECL_FASTCALL_SIMPLE(Load, _ZN9CGangWars4LoadEv, bool);

    // Static values
    DECL_VALUE_PLT_I32(ZoneInfoForTraining, BYBIT(0x678814, 0x84F048));
    DECL_VALUE_PLT_BOOL(bGangWarsActive, BYBIT(0x678764, 0x84EEF0));
    DECL_VALUE_PLT_BOOL(bTrainingMission, BYBIT(0x6788EC, 0x84F1F8));
    DECL_OBJECT_PLT(CZoneInfo*, pZoneInfoToFightOver, BYBIT(0x6795A4, 0x850B58));
    DECL_OBJECT_PLT(CZone*, pZoneToFightOver, BYBIT(0x6795A0, 0x850B50));
    DECL_VALUE_PLT_I32(Gang1, BYBIT(0x678B78, 0x84F718));
    DECL_VALUE_PLT_BOOL(bPlayerIsCloseby, BYBIT(0x676944, 0x84B2D8));
    DECL_VALUE_PLT_BOOL(bCanTriggerGangWarWhenOnAMission, BYBIT(0x6784BC, 0x84E990));
    DECL_VALUE_PLT_FLT(Difficulty, BYBIT(0x679718, 0x850E40));
    DECL_VALUE_PLT_I32(NumSpecificZones, BYBIT(0x67955C, 0x850AC8));
    DECL_OBJECT_ARRAY_PLT(i32, aSpecificZones, BYBIT(0x676DC0, 0x84BBC8));
    DECL_VALUE_PLT_I32(State, BYBIT(0x678838, 0x84F090));
    DECL_VALUE_PLT_U32(TimeStarted, BYBIT(0x679B44, 0x8516A8));
    DECL_VALUE_PLT_FLT(Provocation, BYBIT(0x675FB0, 0x849FD0));
    DECL_OBJECT_PLT(CVector, CoorsOfPlayerAtStartOfWar, BYBIT(0x67734C, 0x84C6D0));
    DECL_VALUE_PLT_I32(WarFerocity, BYBIT(0x6775A4, 0x84CB88));
    DECL_VALUE_PLT_U32(LastTimeInArea, BYBIT(0x677EAC, 0x84DD78));
    DECL_VALUE_PLT_I32(Gang2, BYBIT(0x67961C, 0x850C48));
    DECL_VALUE_PLT_I32(State2, BYBIT(0x677D54, 0x84DAC8));
    DECL_VALUE_PLT_FLT(TimeTillNextAttack, BYBIT(0x675F34, 0x849ED8));
    DECL_OBJECT_PLT(CVector, PointOfAttack, BYBIT(0x6772A4, 0x84C580));
    DECL_VALUE_PLT_I32(FightTimer, BYBIT(0x6771CC, 0x84C3D0));
    DECL_VALUE_PLT_I32(RadarBlip, BYBIT(0x6761F4, 0x84A448));
    DECL_OBJECT_ARRAY_PLT(i32, GangRatings, BYBIT(0x6760F8, 0x84A250));
    DECL_OBJECT_ARRAY_PLT(i32, GangRatingStrength, BYBIT(0x678268, 0x84E4E8));
    DECL_VALUE_PLT_FLT(TerritoryUnderControlPercentage, BYBIT(0x677934, 0x84D290));
    DECL_VALUE_PLT_BOOL(bIsPlayerOnAMission, BYBIT(0x676298, 0x84A590));
DECL_CLASS_END()

#define ZoneInfoForTraining ZoneInfoForTraining()
#define bGangWarsActive bGangWarsActive()
#define bTrainingMission bTrainingMission()
#define pZoneInfoToFightOver pZoneInfoToFightOver()
#define pZoneToFightOver pZoneToFightOver()
#define Gang1 Gang1()
#define bPlayerIsCloseby bPlayerIsCloseby()
#define bCanTriggerGangWarWhenOnAMission bCanTriggerGangWarWhenOnAMission()
#define Difficulty Difficulty()
#define NumSpecificZones NumSpecificZones()
#define aSpecificZones aSpecificZones()
// #define State State()  -- omitted: collides with an instance field elsewhere; use CGangInfo::State() instead
#define TimeStarted TimeStarted()
#define Provocation Provocation()
#define CoorsOfPlayerAtStartOfWar CoorsOfPlayerAtStartOfWar()
#define WarFerocity WarFerocity()
#define LastTimeInArea LastTimeInArea()
#define Gang2 Gang2()
#define State2 State2()
#define TimeTillNextAttack TimeTillNextAttack()
#define PointOfAttack PointOfAttack()
#define FightTimer FightTimer()
#define RadarBlip RadarBlip()
#define GangRatings GangRatings()
#define GangRatingStrength GangRatingStrength()
#define TerritoryUnderControlPercentage TerritoryUnderControlPercentage()
#define bIsPlayerOnAMission bIsPlayerOnAMission()

#endif // __AML_PSDK_SAGANGWARS_H
