#ifndef __AML_PSDK_SAPOPCYCLE_H
#define __AML_PSDK_SAPOPCYCLE_H

/*
    Plugin-SDK (Grand Theft Auto San Andreas) header file
    Authors: GTA Community. See more here
    https://github.com/DK22Pac/plugin-sdk
    Do not delete this comment block. Respect others' work!
*/

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/game_sa/enum/PedEnums.h>

struct CZoneInfo;
struct CZone;

typedef u8 tPopCycleTable[2][20];
typedef u8 tPopCycleGroupTable[2][20][18];

DECL_CLASS(CPopCycle)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(Initialise, _ZN9CPopCycle10InitialiseEv, void);
    DECL_FASTCALL_SIMPLE(Update, _ZN9CPopCycle6UpdateEv, void);
    DECL_FASTCALL_SIMPLE(Display, _ZN9CPopCycle7DisplayEv, void);
    DECL_FASTCALL_SIMPLE(PickGangToCreateMembersOf, _ZN9CPopCycle25PickGangToCreateMembersOfEv, ePedType);
    DECL_FASTCALL_SIMPLE(FindNewPedType, _ZN9CPopCycle14FindNewPedTypeEP8ePedTypePibb, bool, ePedType* pedType, i32* modelIndex, bool arg2, bool arg3);
    DECL_FASTCALL_SIMPLE(UpdatePercentages, _ZN9CPopCycle17UpdatePercentagesEv, void);
    DECL_FASTCALL_SIMPLE(PickPedMIToStreamInForCurrentZone, _ZN9CPopCycle33PickPedMIToStreamInForCurrentZoneEv, i32);
    DECL_FASTCALL_SIMPLE(IsPedAppropriateForCurrentZone, _ZN9CPopCycle30IsPedAppropriateForCurrentZoneEi, bool, i32 modelIndex);
    DECL_FASTCALL_SIMPLE(IsPedInGroup, _ZN9CPopCycle12IsPedInGroupEii, bool, i32 modelIndex, i32 groupId);
    DECL_FASTCALL_SIMPLE(GetCurrentMaxNumPeds, _ZN9CPopCycle20GetCurrentMaxNumPedsEv, i32);
    DECL_FASTCALL_SIMPLE(GetCurrentMaxNumCars, _ZN9CPopCycle20GetCurrentMaxNumCarsEv, i32);
    DECL_FASTCALL_SIMPLE(GetCurrentPercDealers, _ZN9CPopCycle21GetCurrentPercDealersEv, i32);
    DECL_FASTCALL_SIMPLE(GetCurrentPercGangs, _ZN9CPopCycle19GetCurrentPercGangsEv, i32);
    DECL_FASTCALL_SIMPLE(GetCurrentPercCops, _ZN9CPopCycle18GetCurrentPercCopsEv, i32);
    DECL_FASTCALL_SIMPLE(GetCurrentPercOther_Peds, _ZN9CPopCycle24GetCurrentPercOther_PedsEv, i32);
    DECL_FASTCALL_SIMPLE(GetCurrentPercOther_Cars, _ZN9CPopCycle24GetCurrentPercOther_CarsEv, i32);
    DECL_FASTCALL_SIMPLE(GetCurrentPercTypeGroup, _ZN9CPopCycle23GetCurrentPercTypeGroupEi, i32, i32 groupId);
    DECL_FASTCALL_SIMPLE(PickARandomGroupOfOtherPeds, _ZN9CPopCycle27PickARandomGroupOfOtherPedsEv, i32);
    DECL_FASTCALL_SIMPLE(PlayerKilledADealer, _ZN9CPopCycle19PlayerKilledADealerEv, void);
    DECL_FASTCALL_SIMPLE(UpdateDealerStrengths, _ZN9CPopCycle21UpdateDealerStrengthsEv, void);
    DECL_FASTCALL_SIMPLE(UpdateAreaDodgyness, _ZN9CPopCycle19UpdateAreaDodgynessEv, void);
    DECL_FASTCALL_SIMPLE(UpdateIsGangArea, _ZN9CPopCycle16UpdateIsGangAreaEv, void);
    DECL_FASTCALL_SIMPLE(PedIsAcceptableInCurrentZone, _ZN9CPopCycle28PedIsAcceptableInCurrentZoneEi, bool, i32 modelIndex);

    // STATIC values
    DECL_OBJECT_ARRAY_PLT(tPopCycleTable, m_nMaxNumPeds, BYBIT(0x6789D0, 0x84F3C0));
    DECL_OBJECT_ARRAY_PLT(tPopCycleTable, m_nMaxNumCars, BYBIT(0x679348, 0x8506A8));
    DECL_OBJECT_ARRAY_PLT(tPopCycleTable, m_nPercDealers, BYBIT(0x6767E0, 0x84B018));
    DECL_OBJECT_ARRAY_PLT(tPopCycleTable, m_nPercGang, BYBIT(0x6797DC, 0x850FC0));
    DECL_OBJECT_ARRAY_PLT(tPopCycleTable, m_nPercCops, BYBIT(0x676BB8, 0x84B7B8));
    DECL_OBJECT_ARRAY_PLT(tPopCycleTable, m_nPercOther, BYBIT(0x677410, 0x84C858));
    DECL_OBJECT_ARRAY_PLT(tPopCycleGroupTable, m_nPercTypeGroup, BYBIT(0x677898, 0x84D158));
    DECL_VALUE_PLT_I32(m_nCurrentTimeIndex, BYBIT(0x676634, 0x84ACC0));
    DECL_VALUE_PLT_I32(m_nCurrentTimeOfWeek, BYBIT(0x677B58, 0x84D6D0));
    DECL_VALUE_PLT_I32(m_nCurrentZoneType, BYBIT(0x678ADC, 0x84F5E0));
    DECL_VALUE_PLT_FLT(m_fCurrentZoneDodgyness, BYBIT(0x675EF8, 0x849E60));
    DECL_VALUE_PLT_BOOL(m_bCurrentZoneIsGangArea, BYBIT(0x67776C, 0x84CF00));
    DECL_OBJECT_PLT(CZoneInfo*, m_pCurrZoneInfo, BYBIT(0x676780, 0x84AF58));
    DECL_OBJECT_PLT(CZone*, m_pCurrZone, BYBIT(0x677764, 0x84CEF0));
    DECL_VALUE_PLT_FLT(m_fPercDealers, BYBIT(0x6785C4, 0x84EBA0));
    DECL_VALUE_PLT_FLT(m_fPercGangs, BYBIT(0x679370, 0x8506F8));
    DECL_VALUE_PLT_FLT(m_fPercCops, BYBIT(0x679118, 0x850258));
    DECL_VALUE_PLT_FLT(m_fPercOther, BYBIT(0x679258, 0x8504C8));
    DECL_VALUE_PLT_FLT(m_NumDealers_Peds, BYBIT(0x677B74, 0x84D708));
    DECL_VALUE_PLT_FLT(m_NumGangs_Peds, BYBIT(0x677C28, 0x84D870));
    DECL_VALUE_PLT_FLT(m_NumCops_Peds, BYBIT(0x678FCC, 0x84FFC0));
    DECL_VALUE_PLT_FLT(m_NumOther_Peds, BYBIT(0x679640, 0x850C90));
    DECL_VALUE_PLT_FLT(m_NumDealers_Cars, BYBIT(0x678F94, 0x84FF50));
    DECL_VALUE_PLT_FLT(m_NumGangs_Cars, BYBIT(0x678DF4, 0x84FC10));
    DECL_VALUE_PLT_FLT(m_NumCops_Cars, BYBIT(0x679BCC, 0x8517B8));
    DECL_VALUE_PLT_FLT(m_NumOther_Cars, BYBIT(0x677350, 0x84C6D8));
DECL_CLASS_END()
CHECKSIZE(CPopCycle, 0x1, 0x1);

#define m_nMaxNumPeds m_nMaxNumPeds()
#define m_nMaxNumCars m_nMaxNumCars()
#define m_nPercDealers m_nPercDealers()
#define m_nPercGang m_nPercGang()
#define m_nPercCops m_nPercCops()
#define m_nPercOther m_nPercOther()
#define m_nPercTypeGroup m_nPercTypeGroup()
#define m_nCurrentTimeIndex m_nCurrentTimeIndex()
#define m_nCurrentTimeOfWeek m_nCurrentTimeOfWeek()
#define m_nCurrentZoneType m_nCurrentZoneType()
#define m_fCurrentZoneDodgyness m_fCurrentZoneDodgyness()
#define m_bCurrentZoneIsGangArea m_bCurrentZoneIsGangArea()
#define m_pCurrZoneInfo m_pCurrZoneInfo()
#define m_pCurrZone m_pCurrZone()
#define m_fPercDealers m_fPercDealers()
#define m_fPercGangs m_fPercGangs()
#define m_fPercCops m_fPercCops()
#define m_fPercOther m_fPercOther()
#define m_NumDealers_Peds m_NumDealers_Peds()
#define m_NumGangs_Peds m_NumGangs_Peds()
#define m_NumCops_Peds m_NumCops_Peds()
#define m_NumOther_Peds m_NumOther_Peds()
#define m_NumDealers_Cars m_NumDealers_Cars()
#define m_NumGangs_Cars m_NumGangs_Cars()
#define m_NumCops_Cars m_NumCops_Cars()
#define m_NumOther_Cars m_NumOther_Cars()

#endif // __AML_PSDK_SAPOPCYCLE_H
