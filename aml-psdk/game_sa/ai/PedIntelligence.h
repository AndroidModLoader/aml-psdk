#ifndef __AML_PSDK_SAPEDINTELLIGENCE_H
#define __AML_PSDK_SAPEDINTELLIGENCE_H

#include <aml-psdk/gta_base/Vector.h>
#include <aml-psdk/game_sa/enum/DecisionMaker.h>
#include "TaskManager.h"
#include "TaskTimer.h"
#include "Event.h"
#include "Scanner.h"

struct CPed;
struct CEntity;
struct CTask;
struct CTaskSimple;
struct CEvent;
struct CTaskSimpleSwim;
struct CTaskSimpleJetPack;
struct CTaskSimpleClimb;
struct CTaskSimpleFight;
struct CTaskSimpleUseGun;
struct CTaskSimpleThrowProjectile;
struct CTaskSimpleInAir;
struct C2dEffect;
struct CVehicle;

struct CEventHandlerHistory
{
    CTask *m_pAbortedTask;
    CEvent *m_pCurrentEventActive;
    CEvent *m_pCurrentEventPassive;
    CEvent *m_pStoredEventActive;
    CTaskTimer m_storeTimer;
};

struct CEventHandler
{
    CPed *m_pPed;
    CEventHandlerHistory m_history;
    CTask *m_pTaskPhysResponse;
    CTask *m_pTaskEventResponse;
    CTaskSimple *m_pTaskSecondaryAim;
    CTaskSimple *m_pTaskSecondarySay;
    CTaskSimple *m_pTaskSecondaryPartialAnim;
};

struct CPedStuckChecker
{
    CVector m_vecPreviousPos;
    unsigned short m_nStuckCounter;
    unsigned short m_nStuck;
};

struct CMentalState
{
    unsigned char m_AngerAtPlayer;
    unsigned char m_LastAngerAtPlayer;
    CTaskTimer m_AngerTimer;
    unsigned short m_pedHealth;
    unsigned short m_oldPedHealth;
    unsigned short m_vehicleHealth;
    unsigned short m_oldVehicleHealth;
    unsigned char m_bInCarLastTime;
};

DECL_CLASS(CPedIntelligence)
    // Construct/Deconstruct functions
    CPedIntelligence(){}
    DECL_CTORCALL_ARG_HEAD(CPedIntelligence, _ZN16CPedIntelligenceC2EP4CPed, CPed *pPed)
    DECL_CTORCALL_ARG_TAIL(pPed)
    DECL_DTORCALL(CPedIntelligence, _ZN16CPedIntelligenceD2Ev);
    DECL_NEWCALL(CPedIntelligence, BYBIT(_ZN16CPedIntelligencenwEj, _ZN16CPedIntelligencenwEm) );
    DECL_DLCALL(CPedIntelligence, _ZN16CPedIntelligencedlEPv);

    // Member functions
    DECL_THISCALL_SIMPLE(Save, _ZN16CPedIntelligence4SaveEv, void);
    DECL_THISCALL_SIMPLE(Load, _ZN16CPedIntelligence4LoadEv, void);
    DECL_THISCALL_SIMPLE(GetTaskSwim, _ZNK16CPedIntelligence11GetTaskSwimEv, CTaskSimpleSwim*);
    DECL_THISCALL_SIMPLE(GetTaskJetPack, _ZNK16CPedIntelligence14GetTaskJetPackEv, CTaskSimpleJetPack*);
    DECL_THISCALL_SIMPLE(GetTaskClimb, _ZNK16CPedIntelligence12GetTaskClimbEv, CTaskSimpleClimb*);
    DECL_THISCALL_SIMPLE(GetMoveStateFromGoToTask, _ZNK16CPedIntelligence24GetMoveStateFromGoToTaskEv, int);
    DECL_THISCALL_SIMPLE(FindRespectedFriendInInformRange, _ZN16CPedIntelligence32FindRespectedFriendInInformRangeEv, bool);
    DECL_THISCALL_SIMPLE(RestorePedDecisionMakerType, _ZN16CPedIntelligence27RestorePedDecisionMakerTypeEv, void);
    DECL_THISCALL_SIMPLE(GetTaskFighting, _ZNK16CPedIntelligence15GetTaskFightingEv, CTaskSimpleFight*);
    DECL_THISCALL_SIMPLE(GetTaskUseGun, _ZNK16CPedIntelligence13GetTaskUseGunEv, CTaskSimpleUseGun*);
    DECL_THISCALL_SIMPLE(GetTaskThrow, _ZNK16CPedIntelligence12GetTaskThrowEv, CTaskSimpleThrowProjectile*);
    DECL_THISCALL_SIMPLE(GetTaskInAir, _ZNK16CPedIntelligence12GetTaskInAirEv, CTaskSimpleInAir*);
    DECL_THISCALL_SIMPLE(GetUsingParachute, _ZNK16CPedIntelligence17GetUsingParachuteEv, bool);
    DECL_THISCALL_SIMPLE(ClearTaskDuckSecondary, _ZN16CPedIntelligence22ClearTaskDuckSecondaryEv, void);
    DECL_THISCALL_SIMPLE(GetEffectInUse, _ZNK16CPedIntelligence14GetEffectInUseEv, C2dEffect*);
    DECL_THISCALL_SIMPLE(ProcessFirst, _ZN16CPedIntelligence12ProcessFirstEv, void);
    DECL_THISCALL_SIMPLE(ProcessStaticCounter, _ZN16CPedIntelligence20ProcessStaticCounterEv, void);
    DECL_THISCALL_SIMPLE(Process, _ZN16CPedIntelligence7ProcessEv, void);
    DECL_THISCALL_SIMPLE(LookAtInterestingEntities, _ZN16CPedIntelligence25LookAtInterestingEntitiesEv, void);
    DECL_THISCALL_SIMPLE(ProcessAfterProcCol, _ZN16CPedIntelligence19ProcessAfterProcColEv, void);
    DECL_THISCALL_SIMPLE(ProcessAfterPreRender, _ZN16CPedIntelligence21ProcessAfterPreRenderEv, void);
    DECL_THISCALL_SIMPLE(ProcessEventHandler, _ZN16CPedIntelligence19ProcessEventHandlerEv, void);
    DECL_THISCALL_SIMPLE(IsInACarOrEnteringOne, _ZN16CPedIntelligence21IsInACarOrEnteringOneEv, CVehicle*);
    DECL_THISCALL_SIMPLE(IsPedGoingSomewhereOnFoot, _ZNK16CPedIntelligence25IsPedGoingSomewhereOnFootEv, bool);
    DECL_THISCALL_SIMPLE(FlushIntelligence, _ZN16CPedIntelligence17FlushIntelligenceEv, void);
    DECL_THISCALL_SIMPLE(HasInterestingEntites, _ZN16CPedIntelligence21HasInterestingEntitesEv, u8);
    DECL_THISCALL_SIMPLE(RemoveAllInterestingEntities, _ZN16CPedIntelligence28RemoveAllInterestingEntitiesEv, void);
    DECL_THISCALL_SIMPLE(IsPedGoingForCarDoor, _ZN16CPedIntelligence20IsPedGoingForCarDoorEv, bool);
    DECL_THISCALL_SIMPLE(SortAndStaggerAllPedsEventScannerTimers, _ZN16CPedIntelligence39SortAndStaggerAllPedsEventScannerTimersEv, void);
    // TODO:

    // Member values
    CPed*              m_pPed;
    CTaskManager       m_TaskMgr;
    CEventHandler      m_eventHandler;
    CEventGroup        m_eventGroup;
    eDecisionMakerType m_nDecisionMakerType;
    eDecisionMakerType m_nDecisionMakerTypeInGroup;
    float              m_fHearingRange;
    float              m_fSeeingRange;
    int                m_nDmNumPedsToScan;
    float              m_fDmRadius;
    float              m_FollowNodeThresholdDistance;
    signed char        m_NextEventResponseSequence;
    unsigned char      m_nEventId;
    unsigned char      m_nEventPriority;
    CEntityScanner     m_vehicleScanner;
    CEntityScanner     m_pedScanner;
    CMentalState       m_mentalState;
    CEventScanner      m_eventScanner;
    CCollisionEventScanner m_collisionScanner;
    CPedStuckChecker   m_pedStuckChecker;
    int                m_AnotherStaticCounter;
    unsigned int       m_StaticCounter;
    CVector            m_vecLastPedPosDuringDamageEntity;
    CEntity*           m_apInterestingEntities[3];
DECL_CLASS_END()
CHECKSIZE(CPedIntelligence, 0x298, 0x440);

#endif // __AML_PSDK_SAPEDINTELLIGENCE_H