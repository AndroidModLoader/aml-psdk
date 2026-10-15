#ifndef __AML_PSDK_SAENTITYSCANNER_H
#define __AML_PSDK_SAENTITYSCANNER_H

#include <aml-psdk/game_sa/plugin.h>
#include "TaskTimer.h"
#include <aml-psdk/gta_base/Vector.h>

struct CEntity;
struct C2dEffect;
struct CVehicle;
struct CPtrList;
struct CEventGroup;

struct CPed;

DECL_CLASS(CEntityScanner)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CEntityScanner, _ZN14CEntityScannerC2Ev);
    DECL_DTORCALL_PROXY(CEntityScanner, _ZN14CEntityScannerD2Ev);

    // Virtual functions
    virtual void ScanForEntitiesInRange(const int iScanType, const CPed &ped);

    // Member functions
    DECL_THISCALL_SIMPLE(Clear, _ZN14CEntityScanner5ClearEv, void);

    // Member values
    unsigned int   m_nCount;
    unsigned int   m_nPeriod;
    CEntity       *m_apEntities[16];
    CEntity       *m_pClosestEntity;
DECL_CLASS_END()

DECL_CLASS_BASED(CPedScanner, CEntityScanner)
    // Member functions
    DECL_THISCALL_HEAD(ScanForPedsInRange, _ZN11CPedScanner18ScanForPedsInRangeERK4CPed, void, CPed const& ped)
    DECL_THISCALL_TAIL(ScanForPedsInRange, ped)
    DECL_THISCALL_SIMPLE(GetClosestPedInRange, _ZNK11CPedScanner20GetClosestPedInRangeEv, CPed*);

DECL_CLASS_END()
DECL_CLASS_BASED(CVehicleScanner, CEntityScanner)
    // Member functions
    DECL_THISCALL_HEAD(ScanForVehiclesInRange, _ZN15CVehicleScanner22ScanForVehiclesInRangeERK4CPed, void, CPed const& ped)
    DECL_THISCALL_TAIL(ScanForVehiclesInRange, ped)
    DECL_THISCALL_SIMPLE(GetClosestVehicleInRange, _ZNK15CVehicleScanner24GetClosestVehicleInRangeEv, CVehicle*);

DECL_CLASS_END()
DECL_CLASS(CCollisionEventScanner)
    // Member functions
    DECL_THISCALL_HEAD(ScanForCollisionEvents, _ZN22CCollisionEventScanner22ScanForCollisionEventsER4CPedP11CEventGroup, void, CPed& victim, CEventGroup* eventGroup)
    DECL_THISCALL_TAIL(ScanForCollisionEvents, victim, eventGroup)

    bool m_bAlreadyHitByCar;
DECL_CLASS_END()


DECL_CLASS(CAttractorScanner)
    // Construct/Deconstruct functions
    DECL_CTORCALL(CAttractorScanner, _ZN17CAttractorScannerC2Ev);
    DECL_DTORCALL(CAttractorScanner, _ZN17CAttractorScannerD2Ev);

    // STATIC functions
    DECL_FASTCALL_SIMPLE(GetClosestAttractorOfType, _ZN17CAttractorScanner25GetClosestAttractorOfTypeERK7CVectorfiiPKcbPK9C2dEffectRPS5_RP7CEntity, bool, CVector const& arg1, float arg2, i32 arg3, i32 arg4, char const* pchar5, bool arg6, C2dEffect const* pC2dEffect7, C2dEffect*& pC2dEffect8, CEntity*& pCEntity9);
    DECL_FASTCALL_SIMPLE(GetNearestPedNotUsingAttractor, _ZN17CAttractorScanner30GetNearestPedNotUsingAttractorERK9C2dEffect, CPed*, C2dEffect const& arg1);

    // Member functions
    DECL_THISCALL_HEAD(ScanForAttractorsInRange, _ZN17CAttractorScanner24ScanForAttractorsInRangeERK4CPed, void, CPed const& arg1)
    DECL_THISCALL_TAIL(ScanForAttractorsInRange, arg1)
    DECL_THISCALL_HEAD(ScanForAttractorsInPtrList, _ZN17CAttractorScanner26ScanForAttractorsInPtrListER8CPtrListRK4CPed, void, CPtrList& arg1, CPed const& arg2)
    DECL_THISCALL_TAIL(ScanForAttractorsInPtrList, arg1, arg2)
    DECL_THISCALL_HEAD(AddEffect, _ZN17CAttractorScanner9AddEffectEP9C2dEffectP7CEntityRK4CPed, void, C2dEffect* pC2dEffect1, CEntity* pCEntity2, CPed const& arg3)
    DECL_THISCALL_TAIL(AddEffect, pC2dEffect1, pCEntity2, arg3)
    DECL_THISCALL_HEAD(GetNearestAttractorInRange, _ZNK17CAttractorScanner26GetNearestAttractorInRangeERP9C2dEffectRP7CEntity, void, C2dEffect*& pC2dEffect1, CEntity*& pCEntity2)
    DECL_THISCALL_TAIL(GetNearestAttractorInRange, pC2dEffect1, pCEntity2)
    DECL_THISCALL_SIMPLE(Clear, _ZN17CAttractorScanner5ClearEv, void);

    // Member values
    bool m_bActivated;
    CTaskTimer m_timer;
    C2dEffect *m_pEffectInUse;
    CEntity *m_pPreviousEntity;
    CEntity *m_ppEntities[10];
    C2dEffect *m_ppEffects[10];
    float m_pfMinDistanceSquared[10];
DECL_CLASS_END()

DECL_CLASS(CPedAcquaintanceScanner)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(CanJoinLARiot, _ZN23CPedAcquaintanceScanner13CanJoinLARiotERK4CPedS2_, bool, CPed const& arg1, CPed const& arg2);

    // STATIC values
    DECL_VALUE_PLT_I32(ms_iAcquaintanceScanPeriod, BYBIT(0x677430, 0x84C898));
    DECL_VALUE_PLT_I32(ms_iAcquaintanceLatencyPeriodDefinite, BYBIT(0x677B9C, 0x84D758));
    DECL_VALUE_PLT_I32(ms_iAcquaintanceLatencyPeriodMaybe, BYBIT(0x676C6C, 0x84B920));
    DECL_VALUE_PLT_FLT(ms_fThresholdDotProduct, BYBIT(0x67871C, 0x84EE60));

    // Member functions
    DECL_THISCALL_HEAD(ScanForPedAcquaintanceEvents, _ZN23CPedAcquaintanceScanner28ScanForPedAcquaintanceEventsER4CPedPP7CEntityi, void, CPed& arg1, CEntity** pCEntity2, i32 arg3)
    DECL_THISCALL_TAIL(ScanForPedAcquaintanceEvents, arg1, pCEntity2, arg3)
    DECL_THISCALL_HEAD(FindClosestAcquaintance, _ZN23CPedAcquaintanceScanner23FindClosestAcquaintanceER4CPediPP7CEntityiRPS0_Ri, void, CPed& arg1, i32 arg2, CEntity** pCEntity3, i32 arg4, CPed*& pCPed5, i32& arg6)
    DECL_THISCALL_TAIL(FindClosestAcquaintance, arg1, arg2, pCEntity3, arg4, pCPed5, arg6)
    DECL_THISCALL_HEAD(SetTimer, _ZN23CPedAcquaintanceScanner8SetTimerEi, void, i32 arg1)
    DECL_THISCALL_TAIL(SetTimer, arg1)
    DECL_THISCALL_HEAD(ScanAcquaintanceTypes, _ZN23CPedAcquaintanceScanner21ScanAcquaintanceTypesERK4CPediiPS0_RS3_Ri, i32, CPed const& arg1, i32 arg2, i32 arg3, CPed* pCPed4, CPed*& pCPed5, i32& arg6)
    DECL_THISCALL_TAIL(ScanAcquaintanceTypes, arg1, arg2, arg3, pCPed4, pCPed5, arg6)
    DECL_THISCALL_HEAD(AddAcquaintanceEvent, _ZN23CPedAcquaintanceScanner20AddAcquaintanceEventERK4CPediPS0_, bool, CPed const& arg1, i32 arg2, CPed* pCPed3)
    DECL_THISCALL_TAIL(AddAcquaintanceEvent, arg1, arg2, pCPed3)
    DECL_THISCALL_HEAD(IsScanPermitted, _ZNK23CPedAcquaintanceScanner15IsScanPermittedERK4CPed, bool, CPed const& arg1)
    DECL_THISCALL_TAIL(IsScanPermitted, arg1)

    // Member values
    CTaskTimer m_timer;
    bool m_bActivatedEverywhere;
    bool m_bActivatedInVehicle;
    bool m_bActivatedDuringScriptCommands;
DECL_CLASS_END()

DECL_CLASS(CEventScanner)
    // Construct/Deconstruct functions
    DECL_CTORCALL(CEventScanner, _ZN13CEventScannerC2Ev);
    DECL_DTORCALL(CEventScanner, _ZN13CEventScannerD2Ev);

    // STATIC values
    DECL_VALUE_PLT_U32(m_sDeadPedWalkingTimer, BYBIT(0x679798, 0x850F38));

    // Member functions
    DECL_THISCALL_HEAD(ScanForEvents, _ZN13CEventScanner13ScanForEventsER4CPed, void, CPed& arg1)
    DECL_THISCALL_TAIL(ScanForEvents, arg1)
    DECL_THISCALL_HEAD(ScanForEventsNow, _ZN13CEventScanner16ScanForEventsNowERK4CPedi, void, CPed const& arg1, i32 arg2)
    DECL_THISCALL_TAIL(ScanForEventsNow, arg1, arg2)
    DECL_THISCALL_SIMPLE(Clear, _ZN13CEventScanner5ClearEv, void);

    // Member values
    int m_nStartTime;
    CTaskTimer m_vehicleCollisionTimer;
    CTaskTimer m_objectCollisionTimer;
    CAttractorScanner m_attractorScanner;
    CPedAcquaintanceScanner m_pedAcquaScanner;
    CTaskTimer m_sexyPedTimer;
    CTaskTimer m_fireTimer;
DECL_CLASS_END()

#define ms_iAcquaintanceScanPeriod ms_iAcquaintanceScanPeriod()
#define ms_iAcquaintanceLatencyPeriodDefinite ms_iAcquaintanceLatencyPeriodDefinite()
#define ms_iAcquaintanceLatencyPeriodMaybe ms_iAcquaintanceLatencyPeriodMaybe()
#define ms_fThresholdDotProduct ms_fThresholdDotProduct()

#define m_sDeadPedWalkingTimer m_sDeadPedWalkingTimer()

#endif // __AML_PSDK_SAEVENT_H
