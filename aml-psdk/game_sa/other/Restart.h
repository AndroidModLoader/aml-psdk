#ifndef __AML_PSDK_SARESTART_H
#define __AML_PSDK_SARESTART_H

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/gta_base/Vector.h>

DECL_CLASS(CRestart)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(Initialise, _ZN8CRestart10InitialiseEv, void);
    DECL_FASTCALL_SIMPLE(AddHospitalRestartPoint, _ZN8CRestart23AddHospitalRestartPointERK7CVectorfi, void, CVector const& point, float angle, i32 townId);
    DECL_FASTCALL_SIMPLE(AddPoliceRestartPoint, _ZN8CRestart21AddPoliceRestartPointERK7CVectorfi, void, CVector const& point, float angle, i32 townId);
    DECL_FASTCALL_SIMPLE(FindClosestHospitalRestartPoint, _ZN8CRestart31FindClosestHospitalRestartPointE7CVectorPS0_Pf, void, CVector point, CVector* outPos, float* outAngle);
    DECL_FASTCALL_SIMPLE(FindClosestPoliceRestartPoint, _ZN8CRestart29FindClosestPoliceRestartPointE7CVectorPS0_Pf, void, CVector point, CVector* storedPoint, float* outAngle);
    DECL_FASTCALL_SIMPLE(OverrideNextRestart, _ZN8CRestart19OverrideNextRestartERK7CVectorf, void, CVector const& point, float angle);
    DECL_FASTCALL_SIMPLE(CancelOverrideRestart, _ZN8CRestart21CancelOverrideRestartEv, void);
    DECL_FASTCALL_SIMPLE(SetRespawnPointForDurationOfMission, _ZN8CRestart35SetRespawnPointForDurationOfMissionE7CVector, void, CVector point);
    DECL_FASTCALL_SIMPLE(ClearRespawnPointForDurationOfMission, _ZN8CRestart37ClearRespawnPointForDurationOfMissionEv, void);
    DECL_FASTCALL_SIMPLE(Save, _ZN8CRestart4SaveEv, bool);
    DECL_FASTCALL_SIMPLE(Load, _ZN8CRestart4LoadEv, bool);

    // STATIC values
    DECL_OBJECT_ARRAY_PLT(CVector, HospitalRestartPoints, BYBIT(0x679804, 0x851010));
    DECL_OBJECT_ARRAY_PLT(float, HospitalRestartHeadings, BYBIT(0x676E50, 0x84BCE0));
    DECL_OBJECT_ARRAY_PLT(i32, HospitalRestartWhenToUse, BYBIT(0x677D1C, 0x84DA58));
    DECL_OBJECT_ARRAY_PLT(CVector, PoliceRestartPoints, BYBIT(0x6775C4, 0x84CBC0));
    DECL_OBJECT_ARRAY_PLT(float, PoliceRestartHeadings, BYBIT(0x677620, 0x84CC70));
    DECL_OBJECT_ARRAY_PLT(i32, PoliceRestartWhenToUse, BYBIT(0x677E3C, 0x84DC98));
    DECL_VALUE_PLT_U16(NumberOfHospitalRestarts, BYBIT(0x677DDC, 0x84DBD8));
    DECL_VALUE_PLT_U16(NumberOfPoliceRestarts, BYBIT(0x676DBC, 0x84BBC0));
    DECL_VALUE_PLT_U8(bOverrideRestart, BYBIT(0x679D30, 0x851A78));
    DECL_OBJECT_PLT(CVector, OverridePosition, BYBIT(0x6779D8, 0x84D3D8));
    DECL_VALUE_PLT_FLT(OverrideHeading, BYBIT(0x679BBC, 0x851798));
    DECL_VALUE_PLT_U8(bFadeInAfterNextDeath, BYBIT(0x677DCC, 0x84DBB8));
    DECL_VALUE_PLT_U8(bFadeInAfterNextArrest, BYBIT(0x679374, 0x850700));
    DECL_OBJECT_PLT(CVector, ExtraHospitalRestartCoors, BYBIT(0x676A30, 0x84B4A8));
    DECL_VALUE_PLT_FLT(ExtraHospitalRestartRadius, BYBIT(0x676D20, 0x84BA88));
    DECL_VALUE_PLT_FLT(ExtraHospitalRestartHeading, BYBIT(0x6769D0, 0x84B3E8));
    DECL_OBJECT_PLT(CVector, ExtraPoliceStationRestartCoors, BYBIT(0x678324, 0x84E660));
    DECL_VALUE_PLT_FLT(ExtraPoliceStationRestartRadius, BYBIT(0x6797F0, 0x850FE8));
    DECL_VALUE_PLT_FLT(ExtraPoliceStationRestartHeading, BYBIT(0x677044, 0x84C0C0));
    DECL_VALUE_PLT_BOOL(bOverrideRespawnBasePointForMission, BYBIT(0x6783B8, 0x84E788));
    DECL_OBJECT_PLT(CVector, OverrideRespawnBasePointForMission, BYBIT(0x67890C, 0x84F238));
DECL_CLASS_END()

#define HospitalRestartPoints HospitalRestartPoints()
#define HospitalRestartHeadings HospitalRestartHeadings()
#define HospitalRestartWhenToUse HospitalRestartWhenToUse()
#define PoliceRestartPoints PoliceRestartPoints()
#define PoliceRestartHeadings PoliceRestartHeadings()
#define PoliceRestartWhenToUse PoliceRestartWhenToUse()
#define NumberOfHospitalRestarts NumberOfHospitalRestarts()
#define NumberOfPoliceRestarts NumberOfPoliceRestarts()
#define bOverrideRestart bOverrideRestart()
#define OverridePosition OverridePosition()
#define OverrideHeading OverrideHeading()
#define bFadeInAfterNextDeath bFadeInAfterNextDeath()
#define bFadeInAfterNextArrest bFadeInAfterNextArrest()
#define ExtraHospitalRestartCoors ExtraHospitalRestartCoors()
#define ExtraHospitalRestartRadius ExtraHospitalRestartRadius()
#define ExtraHospitalRestartHeading ExtraHospitalRestartHeading()
#define ExtraPoliceStationRestartCoors ExtraPoliceStationRestartCoors()
#define ExtraPoliceStationRestartRadius ExtraPoliceStationRestartRadius()
#define ExtraPoliceStationRestartHeading ExtraPoliceStationRestartHeading()
#define bOverrideRespawnBasePointForMission bOverrideRespawnBasePointForMission()
#define OverrideRespawnBasePointForMission OverrideRespawnBasePointForMission()

#endif // __AML_PSDK_SARESTART_H
