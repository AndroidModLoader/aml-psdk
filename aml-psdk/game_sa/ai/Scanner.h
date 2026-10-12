#ifndef __AML_PSDK_SAENTITYSCANNER_H
#define __AML_PSDK_SAENTITYSCANNER_H

#include <aml-psdk/game_sa/plugin.h>
#include "TaskTimer.h"

struct CEntity;
struct C2dEffect;

struct CPed;

DECL_CLASS(CEntityScanner)
    // Construct/Deconstruct functions
    DECL_CTORCALL(CEntityScanner, _ZN14CEntityScannerC2Ev);
    DECL_DTORCALL(CEntityScanner, _ZN14CEntityScannerD2Ev);

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

struct CPedScanner : CEntityScanner {};
struct CVehicleScanner : CEntityScanner {};
struct CCollisionEventScanner
{
    bool m_bAlreadyHitByCar;
};


DECL_CLASS(CAttractorScanner)
    // Construct/Deconstruct functions
    DECL_CTORCALL(CAttractorScanner, _ZN17CAttractorScannerC2Ev);
    DECL_DTORCALL(CAttractorScanner, _ZN17CAttractorScannerD2Ev);

    // Member functions
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

    // Member functions
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

#endif // __AML_PSDK_SAEVENT_H
