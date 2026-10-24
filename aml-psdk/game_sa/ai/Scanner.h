#ifndef __AML_PSDK_SAENTITYSCANNER_H
#define __AML_PSDK_SAENTITYSCANNER_H

#include <aml-psdk/game_sa/plugin.h>
#include "TaskTimer.h"
#include <aml-psdk/gta_base/Vector.h>

struct CEntity;
struct CObject;
struct C2dEffect;
struct CVehicle;
struct CPtrList;
struct CEventGroup;

struct CPed;

DECL_CLASS(CEntityScanner)
    // Construct/Deconstruct functions
    DECL_CTORCALL(CEntityScanner, _ZN14CEntityScannerC2Ev);
    DECL_DTORCALL(CEntityScanner, _ZN14CEntityScannerD2Ev);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(CEntityScanner, ScanForEntitiesInRange, _ZTV14CEntityScanner, 0, void, const int iScanType, const CPed &ped)
    DECL_VIRTUALCALL_TAIL(iScanType, ped)

    // Member functions
    DECL_THISCALL_SIMPLE(Clear, _ZN14CEntityScanner5ClearEv, void);

    // Member values
    unsigned int   m_nCount;
    unsigned int   m_nPeriod;
    CEntity       *m_apEntities[16];
    CEntity       *m_pClosestEntity;
DECL_CLASS_END()

DECL_CLASS_BASED(CPedScanner, CEntityScanner)
    CPedScanner() = delete;
    // Member functions
    DECL_THISCALL_HEAD(ScanForPedsInRange, _ZN11CPedScanner18ScanForPedsInRangeERK4CPed, void, CPed const& ped)
    DECL_THISCALL_TAIL(ScanForPedsInRange, ped)
    DECL_THISCALL_SIMPLE(GetClosestPedInRange, _ZNK11CPedScanner20GetClosestPedInRangeEv, CPed*);

DECL_CLASS_END()
DECL_CLASS_BASED(CVehicleScanner, CEntityScanner)
    CVehicleScanner() = delete;
    // Member functions
    DECL_THISCALL_HEAD(ScanForVehiclesInRange, _ZN15CVehicleScanner22ScanForVehiclesInRangeERK4CPed, void, CPed const& ped)
    DECL_THISCALL_TAIL(ScanForVehiclesInRange, ped)
    DECL_THISCALL_SIMPLE(GetClosestVehicleInRange, _ZNK15CVehicleScanner24GetClosestVehicleInRangeEv, CVehicle*);

DECL_CLASS_END()
DECL_CLASS_BASED(CObjectScanner, CEntityScanner)
    CObjectScanner() = delete;
    // Member functions
    DECL_THISCALL_HEAD(ScanForObjectsInRange, _ZN14CObjectScanner21ScanForObjectsInRangeERK4CPed, void, CPed const& ped)
    DECL_THISCALL_TAIL(ScanForObjectsInRange, ped)
    DECL_THISCALL_SIMPLE(GetClosestObjectInRange, _ZNK14CObjectScanner23GetClosestObjectInRangeEv, CObject*);

DECL_CLASS_END()
CHECKSIZE(CObjectScanner, 0x50, 0x98);

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

DECL_CLASS(CObjectPotentialCollisionScanner)
    // Member functions
    DECL_THISCALL_HEAD(ScanForObjectPotentialCollisionEvents, _ZN32CObjectPotentialCollisionScanner37ScanForObjectPotentialCollisionEventsERK4CPed, void, CPed const& ped)
    DECL_THISCALL_TAIL(ScanForObjectPotentialCollisionEvents, ped)

    inline CTaskTimer* GetTimer() { return &m_timer; }

    // STATIC values
    DECL_OBJECT_PLT(float const, ms_fObjectAvoidDistance, BYBIT(0x679D94, 0x851B40));
    DECL_OBJECT_SYM(float const, ms_fMinIntersectionLength, _ZN32CObjectPotentialCollisionScanner25ms_fMinIntersectionLengthE);
    DECL_OBJECT_SYM(i32 const, ms_iPeriod, _ZN32CObjectPotentialCollisionScanner10ms_iPeriodE);

    // Member values
    CTaskTimer m_timer;
DECL_CLASS_END()
CHECKSIZE(CObjectPotentialCollisionScanner, 0xC, 0xC);

DECL_CLASS(CVehiclePotentialCollisionScanner)
    // Member functions
    DECL_THISCALL_HEAD(ScanForVehiclePotentialCollisionEvents, _ZN33CVehiclePotentialCollisionScanner38ScanForVehiclePotentialCollisionEventsERK4CPedPP7CEntityi, void, CPed const& ped, CEntity** entities, i32 count)
    DECL_THISCALL_TAIL(ScanForVehiclePotentialCollisionEvents, ped, entities, count)

    inline CTaskTimer* GetTimer() { return &m_timer; }

    // STATIC values
    DECL_OBJECT_SYM(float const, ms_fVehiclePotentialRunOverDistance, _ZN33CVehiclePotentialCollisionScanner35ms_fVehiclePotentialRunOverDistanceE);
    DECL_OBJECT_PLT(float const, ms_fVehicleThreatMultiplier, BYBIT(0x678758, 0x84EED8));
    DECL_OBJECT_PLT(float const, ms_fMinAvoidSpeed, BYBIT(0x678F98, 0x84FF58));
    DECL_OBJECT_PLT(float const, ms_fMinAvoidScaredSpeed, BYBIT(0x675F3C, 0x849EE8));
    DECL_OBJECT_SYM(float const, ms_fSlowDiveDist, _ZN33CVehiclePotentialCollisionScanner16ms_fSlowDiveDistE);
    DECL_OBJECT_SYM(float const, ms_fFastDiveDist, _ZN33CVehiclePotentialCollisionScanner16ms_fFastDiveDistE);
    DECL_OBJECT_SYM(float const, ms_fVehicleAvoidDistance, _ZN33CVehiclePotentialCollisionScanner24ms_fVehicleAvoidDistanceE);
    DECL_OBJECT_SYM(float const, ms_fMinIntersectionLength, _ZN33CVehiclePotentialCollisionScanner25ms_fMinIntersectionLengthE);
    DECL_OBJECT_SYM(i32 const, ms_iPeriod, _ZN33CVehiclePotentialCollisionScanner10ms_iPeriodE);

    // Member values
    CTaskTimer m_timer;
DECL_CLASS_END()
CHECKSIZE(CVehiclePotentialCollisionScanner, 0xC, 0xC);

DECL_CLASS(CPedPotentialCollisionScanner)
    // Member functions
    DECL_THISCALL_HEAD(ScanForPedPotentialCollisionEvents, _ZNK29CPedPotentialCollisionScanner34ScanForPedPotentialCollisionEventsERK4CPedPS0_, void, CPed const& ped, CPed* otherPed)
    DECL_THISCALL_TAIL(ScanForPedPotentialCollisionEvents, ped, otherPed)

    // STATIC values
    DECL_OBJECT_PLT(float const, ms_fPedAvoidDistance, BYBIT(0x679888, 0x851128));
DECL_CLASS_END()
CHECKSIZE(CPedPotentialCollisionScanner, 0x1, 0x1);

DECL_CLASS(CNearbyFireScanner)
    // Member functions
    DECL_THISCALL_HEAD(ScanForNearbyFires, _ZN18CNearbyFireScanner18ScanForNearbyFiresERK4CPed, void, CPed const& ped)
    DECL_THISCALL_TAIL(ScanForNearbyFires, ped)

    inline CTaskTimer* GetTimer() { return &m_timer; }

    // STATIC values
    DECL_OBJECT_SYM(i32 const, ms_iLatencyPeriod, _ZN18CNearbyFireScanner17ms_iLatencyPeriodE);
    DECL_OBJECT_PLT(float const, ms_fNearbyFireRange, BYBIT(0x67712C, 0x84C290));
    DECL_OBJECT_SYM(float const, ms_fPotentialWalkIntoFireRange, _ZN18CNearbyFireScanner30ms_fPotentialWalkIntoFireRangeE);

    // Member values
    CTaskTimer m_timer;
DECL_CLASS_END()
CHECKSIZE(CNearbyFireScanner, 0xC, 0xC);

DECL_CLASS(CSexyPedScanner)
    // Member functions
    DECL_THISCALL_HEAD(ScanForSexyPedEvents, _ZN15CSexyPedScanner20ScanForSexyPedEventsERK4CPedPP7CEntityi, void, CPed const& ped, CEntity** entities, i32 count)
    DECL_THISCALL_TAIL(ScanForSexyPedEvents, ped, entities, count)
    DECL_THISCALL_HEAD(IsScanPermitted, _ZNK15CSexyPedScanner15IsScanPermittedERK4CPed, bool, CPed const& ped)
    DECL_THISCALL_TAIL(IsScanPermitted, ped)

    inline CTaskTimer* GetTimer() { return &m_timer; }

    // STATIC values
    DECL_OBJECT_SYM(i32 const, ms_fSexyPedRange, _ZN15CSexyPedScanner16ms_fSexyPedRangeE);
    DECL_OBJECT_SYM(i32 const, ms_iScanPeriod, _ZN15CSexyPedScanner14ms_iScanPeriodE);
    DECL_OBJECT_SYM(i32 const, ms_iSexyPedLatencyPeriod, _ZN15CSexyPedScanner24ms_iSexyPedLatencyPeriodE);

    // Member values
    CTaskTimer m_timer;
DECL_CLASS_END()
CHECKSIZE(CSexyPedScanner, 0xC, 0xC);

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
