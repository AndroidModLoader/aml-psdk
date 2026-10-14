#ifndef __AML_PSDK_SAPEDINTELLIGENCE_H
#define __AML_PSDK_SAPEDINTELLIGENCE_H

#include <aml-psdk/gta_base/Vector.h>
#include <aml-psdk/game_sa/enum/DecisionMaker.h>
#include <aml-psdk/game_sa/enum/WeaponType.h>
#include "TaskManager.h"
#include "TaskTimer.h"
#include "Event.h"
#include "Scanner.h"

struct CPed;
struct CEntity;
struct CTask;
struct CTaskSimple;
struct CEvent;
struct CEventDamage;
struct CTaskSimpleHoldEntity;
struct CTaskSimpleSwim;
struct CTaskSimpleJetPack;
struct CTaskSimpleClimb;
struct CTaskSimpleFight;
struct CTaskSimpleUseGun;
struct CTaskSimpleThrowProjectile;
struct CTaskSimpleInAir;
struct CTaskSimpleDuck;
struct C2dEffect;
struct CVehicle;

DECL_CLASS(CEventHandlerHistory)
    // Construct/Deconstruct functions
    DECL_DTORCALL(CEventHandlerHistory, _ZN20CEventHandlerHistoryD2Ev);

    CTask *m_pAbortedTask;
    CEvent *m_pCurrentEventActive;
    CEvent *m_pCurrentEventPassive;
    CEvent *m_pStoredEventActive;
    CTaskTimer m_storeTimer;

    // Member functions
    DECL_THISCALL_SIMPLE(Flush, _ZN20CEventHandlerHistory5FlushEv, void);
    DECL_THISCALL_HEAD(RecordCurrentEvent, _ZN20CEventHandlerHistory18RecordCurrentEventEP4CPedRK6CEvent, void, CPed* pCPed1, CEvent const& arg2)
    DECL_THISCALL_TAIL(RecordCurrentEvent, pCPed1, arg2)
    DECL_THISCALL_SIMPLE(ClearAllEvents, _ZN20CEventHandlerHistory14ClearAllEventsEv, void);
    DECL_THISCALL_SIMPLE(ClearTempEvent, _ZN20CEventHandlerHistory14ClearTempEventEv, void);
    DECL_THISCALL_SIMPLE(ClearNonTempEvent, _ZN20CEventHandlerHistory17ClearNonTempEventEv, void);
    DECL_THISCALL_SIMPLE(GetCurrentEventPriority, _ZNK20CEventHandlerHistory23GetCurrentEventPriorityEv, i32);
    DECL_THISCALL_SIMPLE(GetCurrentEvent, _ZNK20CEventHandlerHistory15GetCurrentEventEv, CEvent*);
    DECL_THISCALL_SIMPLE(GetStoredActiveEvent, _ZNK20CEventHandlerHistory20GetStoredActiveEventEv, CEvent*);
    DECL_THISCALL_HEAD(IsRespondingToEvent, _ZNK20CEventHandlerHistory19IsRespondingToEventEi, bool, i32 arg1)
    DECL_THISCALL_TAIL(IsRespondingToEvent, arg1)
    DECL_THISCALL_HEAD(TickStoredEvent, _ZN20CEventHandlerHistory15TickStoredEventEP4CPed, void, CPed* pCPed1)
    DECL_THISCALL_TAIL(TickStoredEvent, pCPed1)
    DECL_THISCALL_HEAD(TakesPriorityOverCurrentEvent, _ZN20CEventHandlerHistory29TakesPriorityOverCurrentEventERK6CEvent, bool, CEvent const& arg1)
    DECL_THISCALL_TAIL(TakesPriorityOverCurrentEvent, arg1)
    DECL_THISCALL_SIMPLE(StoreActiveEvent, _ZN20CEventHandlerHistory16StoreActiveEventEv, void);
DECL_CLASS_END()

DECL_CLASS(CEventHandler)
    // Construct/Deconstruct functions
    CEventHandler(){}
    DECL_CTORCALL_ARG_HEAD(CEventHandler, _ZN13CEventHandlerC2EP4CPed, CPed* pCPed1)
    DECL_CTORCALL_ARG_TAIL(pCPed1)
    DECL_DTORCALL(CEventHandler, _ZN13CEventHandlerD2Ev);

    CPed *m_pPed;
    CEventHandlerHistory m_history;
    CTask *m_pTaskPhysResponse;
    CTask *m_pTaskEventResponse;
    CTaskSimple *m_pTaskSecondaryAim;
    CTaskSimple *m_pTaskSecondarySay;
    CTaskSimple *m_pTaskSecondaryPartialAnim;

    // STATIC functions
    DECL_FASTCALL_SIMPLE(ComputeEventResponseTask1, _ZN13CEventHandler24ComputeEventResponseTaskERK4CPedRK6CEvent, CTask*, CPed const& arg1, CEvent const& arg2);
    DECL_FASTCALL_SIMPLE(IsTemporaryEvent, _ZN13CEventHandler16IsTemporaryEventERK6CEvent, bool, CEvent const& arg1);
    DECL_FASTCALL_SIMPLE(IsKillTaskAppropriate, _ZN13CEventHandler21IsKillTaskAppropriateEP4CPedS1_RK6CEvent, bool, CPed* pCPed1, CPed* pCPed2, CEvent const& arg3);
    DECL_FASTCALL_SIMPLE(RegisterKill, _ZN13CEventHandler12RegisterKillEPK4CPedPK7CEntity11eWeaponTypeb, void, CPed const* pCPed1, CEntity const* pCEntity2, eWeaponType arg3, bool arg4);

    // Member functions
    DECL_THISCALL_SIMPLE(GetCurrentEventType, _ZNK13CEventHandler19GetCurrentEventTypeEv, i32);
    DECL_THISCALL_SIMPLE(Flush, _ZN13CEventHandler5FlushEv, void);
    DECL_THISCALL_SIMPLE(FlushImmediately, _ZN13CEventHandler16FlushImmediatelyEv, void);
    DECL_THISCALL_SIMPLE(HandleEvents, _ZN13CEventHandler12HandleEventsEv, void);
    DECL_THISCALL_HEAD(RecordActiveEvent, _ZN13CEventHandler17RecordActiveEventERK6CEvent, void, CEvent const& arg1)
    DECL_THISCALL_TAIL(RecordActiveEvent, arg1)
    DECL_THISCALL_HEAD(RecordPassiveEvent, _ZN13CEventHandler18RecordPassiveEventERK6CEvent, void, CEvent const& arg1)
    DECL_THISCALL_TAIL(RecordPassiveEvent, arg1)
    DECL_THISCALL_NAMED_HEAD(ComputeEventResponseTask2, ComputeEventResponseTask, _ZN13CEventHandler24ComputeEventResponseTaskEP6CEventP5CTask, void, CEvent* pCEvent1, CTask* pCTask2)
    DECL_THISCALL_TAIL(ComputeEventResponseTask2, pCEvent1, pCTask2)
    DECL_THISCALL_HEAD(ComputeDraggedOutCarResponse, _ZN13CEventHandler28ComputeDraggedOutCarResponseEP6CEventP5CTaskS3_, void, CEvent* pCEvent1, CTask* pCTask2, CTask* pCTask3)
    DECL_THISCALL_TAIL(ComputeDraggedOutCarResponse, pCEvent1, pCTask2, pCTask3)
    DECL_THISCALL_HEAD(ComputeVehicleCollisionResponse, _ZN13CEventHandler31ComputeVehicleCollisionResponseEP6CEventP5CTaskS3_, void, CEvent* pCEvent1, CTask* pCTask2, CTask* pCTask3)
    DECL_THISCALL_TAIL(ComputeVehicleCollisionResponse, pCEvent1, pCTask2, pCTask3)
    DECL_THISCALL_HEAD(ComputePedCollisionWithPedResponse, _ZN13CEventHandler34ComputePedCollisionWithPedResponseEP6CEventP5CTaskS3_, void, CEvent* pCEvent1, CTask* pCTask2, CTask* pCTask3)
    DECL_THISCALL_TAIL(ComputePedCollisionWithPedResponse, pCEvent1, pCTask2, pCTask3)
    DECL_THISCALL_HEAD(ComputePedCollisionWithPlayerResponse, _ZN13CEventHandler37ComputePedCollisionWithPlayerResponseEP6CEventP5CTaskS3_, void, CEvent* pCEvent1, CTask* pCTask2, CTask* pCTask3)
    DECL_THISCALL_TAIL(ComputePedCollisionWithPlayerResponse, pCEvent1, pCTask2, pCTask3)
    DECL_THISCALL_HEAD(ComputePlayerCollisionWithPedResponse, _ZN13CEventHandler37ComputePlayerCollisionWithPedResponseEP6CEventP5CTaskS3_, void, CEvent* pCEvent1, CTask* pCTask2, CTask* pCTask3)
    DECL_THISCALL_TAIL(ComputePlayerCollisionWithPedResponse, pCEvent1, pCTask2, pCTask3)
    DECL_THISCALL_HEAD(ComputeBuildingCollisionResponse, _ZN13CEventHandler32ComputeBuildingCollisionResponseEP6CEventP5CTaskS3_, void, CEvent* pCEvent1, CTask* pCTask2, CTask* pCTask3)
    DECL_THISCALL_TAIL(ComputeBuildingCollisionResponse, pCEvent1, pCTask2, pCTask3)
    DECL_THISCALL_HEAD(ComputeObjectCollisionResponse, _ZN13CEventHandler30ComputeObjectCollisionResponseEP6CEventP5CTaskS3_, void, CEvent* pCEvent1, CTask* pCTask2, CTask* pCTask3)
    DECL_THISCALL_TAIL(ComputeObjectCollisionResponse, pCEvent1, pCTask2, pCTask3)
    DECL_THISCALL_HEAD(ComputePersonalityResponseToDamage, _ZN13CEventHandler34ComputePersonalityResponseToDamageEP12CEventDamageP7CEntity, void, CEventDamage* pCEventDamage1, CEntity* pCEntity2)
    DECL_THISCALL_TAIL(ComputePersonalityResponseToDamage, pCEventDamage1, pCEntity2)
    DECL_THISCALL_HEAD(ComputeDamageResponse, _ZN13CEventHandler21ComputeDamageResponseEP6CEventP5CTaskS3_S3_, void, CEvent* pCEvent1, CTask* pCTask2, CTask* pCTask3, CTask* pCTask4)
    DECL_THISCALL_TAIL(ComputeDamageResponse, pCEvent1, pCTask2, pCTask3, pCTask4)
    DECL_THISCALL_HEAD(ComputeDeathResponse, _ZN13CEventHandler20ComputeDeathResponseEP6CEventP5CTaskS3_, void, CEvent* pCEvent1, CTask* pCTask2, CTask* pCTask3)
    DECL_THISCALL_TAIL(ComputeDeathResponse, pCEvent1, pCTask2, pCTask3)
    DECL_THISCALL_HEAD(ComputeDeadPedResponse, _ZN13CEventHandler22ComputeDeadPedResponseEP6CEventP5CTaskS3_, void, CEvent* pCEvent1, CTask* pCTask2, CTask* pCTask3)
    DECL_THISCALL_TAIL(ComputeDeadPedResponse, pCEvent1, pCTask2, pCTask3)
    DECL_THISCALL_HEAD(ComputeVehiclePotentialCollisionResponse, _ZN13CEventHandler40ComputeVehiclePotentialCollisionResponseEP6CEventP5CTaskS3_, void, CEvent* pCEvent1, CTask* pCTask2, CTask* pCTask3)
    DECL_THISCALL_TAIL(ComputeVehiclePotentialCollisionResponse, pCEvent1, pCTask2, pCTask3)
    DECL_THISCALL_HEAD(ComputeVehiclePotentialPassiveCollisionResponse, _ZN13CEventHandler47ComputeVehiclePotentialPassiveCollisionResponseEP6CEventP5CTaskS3_, void, CEvent* pCEvent1, CTask* pCTask2, CTask* pCTask3)
    DECL_THISCALL_TAIL(ComputeVehiclePotentialPassiveCollisionResponse, pCEvent1, pCTask2, pCTask3)
    DECL_THISCALL_HEAD(ComputeVehicleHitAndRunResponse, _ZN13CEventHandler31ComputeVehicleHitAndRunResponseEP6CEventP5CTaskS3_, void, CEvent* pCEvent1, CTask* pCTask2, CTask* pCTask3)
    DECL_THISCALL_TAIL(ComputeVehicleHitAndRunResponse, pCEvent1, pCTask2, pCTask3)
    DECL_THISCALL_HEAD(ComputeShotFiredResponse, _ZN13CEventHandler24ComputeShotFiredResponseEP6CEventP5CTaskS3_, void, CEvent* pCEvent1, CTask* pCTask2, CTask* pCTask3)
    DECL_THISCALL_TAIL(ComputeShotFiredResponse, pCEvent1, pCTask2, pCTask3)
    DECL_THISCALL_HEAD(ComputePedEnteredVehicleResponse, _ZN13CEventHandler32ComputePedEnteredVehicleResponseEP6CEventP5CTaskS3_, void, CEvent* pCEvent1, CTask* pCTask2, CTask* pCTask3)
    DECL_THISCALL_TAIL(ComputePedEnteredVehicleResponse, pCEvent1, pCTask2, pCTask3)
    DECL_THISCALL_HEAD(ComputeReviveResponse, _ZN13CEventHandler21ComputeReviveResponseEP6CEventP5CTaskS3_, void, CEvent* pCEvent1, CTask* pCTask2, CTask* pCTask3)
    DECL_THISCALL_TAIL(ComputeReviveResponse, pCEvent1, pCTask2, pCTask3)
    DECL_THISCALL_HEAD(ComputeChatPartnerResponse, _ZN13CEventHandler26ComputeChatPartnerResponseEP6CEventP5CTaskS3_, void, CEvent* pCEvent1, CTask* pCTask2, CTask* pCTask3)
    DECL_THISCALL_TAIL(ComputeChatPartnerResponse, pCEvent1, pCTask2, pCTask3)
    DECL_THISCALL_HEAD(ComputeSexyPedResponse, _ZN13CEventHandler22ComputeSexyPedResponseEP6CEventP5CTaskS3_, void, CEvent* pCEvent1, CTask* pCTask2, CTask* pCTask3)
    DECL_THISCALL_TAIL(ComputeSexyPedResponse, pCEvent1, pCTask2, pCTask3)
    DECL_THISCALL_HEAD(ComputeSexyVehicleResponse, _ZN13CEventHandler26ComputeSexyVehicleResponseEP6CEventP5CTaskS3_, void, CEvent* pCEvent1, CTask* pCTask2, CTask* pCTask3)
    DECL_THISCALL_TAIL(ComputeSexyVehicleResponse, pCEvent1, pCTask2, pCTask3)
    DECL_THISCALL_HEAD(ComputePedToChaseResponse, _ZN13CEventHandler25ComputePedToChaseResponseEP6CEventP5CTaskS3_, void, CEvent* pCEvent1, CTask* pCTask2, CTask* pCTask3)
    DECL_THISCALL_TAIL(ComputePedToChaseResponse, pCEvent1, pCTask2, pCTask3)
    DECL_THISCALL_HEAD(ComputePedToFleeResponse, _ZN13CEventHandler24ComputePedToFleeResponseEP6CEventP5CTaskS3_, void, CEvent* pCEvent1, CTask* pCTask2, CTask* pCTask3)
    DECL_THISCALL_TAIL(ComputePedToFleeResponse, pCEvent1, pCTask2, pCTask3)
    DECL_THISCALL_HEAD(ComputeAttractorResponse, _ZN13CEventHandler24ComputeAttractorResponseEP6CEventP5CTaskS3_, void, CEvent* pCEvent1, CTask* pCTask2, CTask* pCTask3)
    DECL_THISCALL_TAIL(ComputeAttractorResponse, pCEvent1, pCTask2, pCTask3)
    DECL_THISCALL_HEAD(ComputePotentialPedCollideResponse, _ZN13CEventHandler34ComputePotentialPedCollideResponseEP6CEventP5CTaskS3_, void, CEvent* pCEvent1, CTask* pCTask2, CTask* pCTask3)
    DECL_THISCALL_TAIL(ComputePotentialPedCollideResponse, pCEvent1, pCTask2, pCTask3)
    DECL_THISCALL_HEAD(ComputeVehicleToStealResponse, _ZN13CEventHandler29ComputeVehicleToStealResponseEP6CEventP5CTaskS3_, void, CEvent* pCEvent1, CTask* pCTask2, CTask* pCTask3)
    DECL_THISCALL_TAIL(ComputeVehicleToStealResponse, pCEvent1, pCTask2, pCTask3)
    DECL_THISCALL_HEAD(ComputeKnockOffBikeResponse, _ZN13CEventHandler27ComputeKnockOffBikeResponseEP6CEventP5CTaskS3_, void, CEvent* pCEvent1, CTask* pCTask2, CTask* pCTask3)
    DECL_THISCALL_TAIL(ComputeKnockOffBikeResponse, pCEvent1, pCTask2, pCTask3)
    DECL_THISCALL_HEAD(ComputeGunAimedAtResponse, _ZN13CEventHandler25ComputeGunAimedAtResponseEP6CEventP5CTaskS3_, void, CEvent* pCEvent1, CTask* pCTask2, CTask* pCTask3)
    DECL_THISCALL_TAIL(ComputeGunAimedAtResponse, pCEvent1, pCTask2, pCTask3)
    DECL_THISCALL_HEAD(ComputeScriptCommandResponse, _ZN13CEventHandler28ComputeScriptCommandResponseEP6CEventP5CTaskS3_, void, CEvent* pCEvent1, CTask* pCTask2, CTask* pCTask3)
    DECL_THISCALL_TAIL(ComputeScriptCommandResponse, pCEvent1, pCTask2, pCTask3)
    DECL_THISCALL_HEAD(ComputeVehicleDiedResponse, _ZN13CEventHandler26ComputeVehicleDiedResponseEP6CEventP5CTaskS3_, void, CEvent* pCEvent1, CTask* pCTask2, CTask* pCTask3)
    DECL_THISCALL_TAIL(ComputeVehicleDiedResponse, pCEvent1, pCTask2, pCTask3)
    DECL_THISCALL_HEAD(ComputePedFriendResponse, _ZN13CEventHandler24ComputePedFriendResponseEP6CEventP5CTaskS3_, void, CEvent* pCEvent1, CTask* pCTask2, CTask* pCTask3)
    DECL_THISCALL_TAIL(ComputePedFriendResponse, pCEvent1, pCTask2, pCTask3)
    DECL_THISCALL_HEAD(ComputePedThreatResponse, _ZN13CEventHandler24ComputePedThreatResponseEP6CEventP5CTaskS3_, void, CEvent* pCEvent1, CTask* pCTask2, CTask* pCTask3)
    DECL_THISCALL_TAIL(ComputePedThreatResponse, pCEvent1, pCTask2, pCTask3)
    DECL_THISCALL_HEAD(ComputePedThreatBadlyLitResponse, _ZN13CEventHandler32ComputePedThreatBadlyLitResponseEP6CEventP5CTaskS3_, void, CEvent* pCEvent1, CTask* pCTask2, CTask* pCTask3)
    DECL_THISCALL_TAIL(ComputePedThreatBadlyLitResponse, pCEvent1, pCTask2, pCTask3)
    DECL_THISCALL_HEAD(ComputePedSoundQuietResponse, _ZN13CEventHandler28ComputePedSoundQuietResponseEP6CEventP5CTaskS3_, void, CEvent* pCEvent1, CTask* pCTask2, CTask* pCTask3)
    DECL_THISCALL_TAIL(ComputePedSoundQuietResponse, pCEvent1, pCTask2, pCTask3)
    DECL_THISCALL_HEAD(ComputeLowHealthResponse, _ZN13CEventHandler24ComputeLowHealthResponseEP6CEventP5CTaskS3_, void, CEvent* pCEvent1, CTask* pCTask2, CTask* pCTask3)
    DECL_THISCALL_TAIL(ComputeLowHealthResponse, pCEvent1, pCTask2, pCTask3)
    DECL_THISCALL_HEAD(ComputeReallyLowHealthResponse, _ZN13CEventHandler30ComputeReallyLowHealthResponseEP6CEventP5CTaskS3_, void, CEvent* pCEvent1, CTask* pCTask2, CTask* pCTask3)
    DECL_THISCALL_TAIL(ComputeReallyLowHealthResponse, pCEvent1, pCTask2, pCTask3)
    DECL_THISCALL_HEAD(ComputeLowAngerAtPlayerResponse, _ZN13CEventHandler31ComputeLowAngerAtPlayerResponseEP6CEventP5CTaskS3_, void, CEvent* pCEvent1, CTask* pCTask2, CTask* pCTask3)
    DECL_THISCALL_TAIL(ComputeLowAngerAtPlayerResponse, pCEvent1, pCTask2, pCTask3)
    DECL_THISCALL_HEAD(ComputeHighAngerAtPlayerResponse, _ZN13CEventHandler32ComputeHighAngerAtPlayerResponseEP6CEventP5CTaskS3_, void, CEvent* pCEvent1, CTask* pCTask2, CTask* pCTask3)
    DECL_THISCALL_TAIL(ComputeHighAngerAtPlayerResponse, pCEvent1, pCTask2, pCTask3)
    DECL_THISCALL_HEAD(ComputeOnFireResponse, _ZN13CEventHandler21ComputeOnFireResponseEP6CEventP5CTaskS3_, void, CEvent* pCEvent1, CTask* pCTask2, CTask* pCTask3)
    DECL_THISCALL_TAIL(ComputeOnFireResponse, pCEvent1, pCTask2, pCTask3)
    DECL_THISCALL_HEAD(ComputeBuildingCollisionPassiveResponse, _ZN13CEventHandler39ComputeBuildingCollisionPassiveResponseEP6CEventP5CTaskS3_, void, CEvent* pCEvent1, CTask* pCTask2, CTask* pCTask3)
    DECL_THISCALL_TAIL(ComputeBuildingCollisionPassiveResponse, pCEvent1, pCTask2, pCTask3)
    DECL_THISCALL_HEAD(ComputeWaterCannonResponse, _ZN13CEventHandler26ComputeWaterCannonResponseEP6CEventP5CTaskS3_, void, CEvent* pCEvent1, CTask* pCTask2, CTask* pCTask3)
    DECL_THISCALL_TAIL(ComputeWaterCannonResponse, pCEvent1, pCTask2, pCTask3)
    DECL_THISCALL_HEAD(ComputeInWaterResponse, _ZN13CEventHandler22ComputeInWaterResponseEP6CEventP5CTaskS3_, void, CEvent* pCEvent1, CTask* pCTask2, CTask* pCTask3)
    DECL_THISCALL_TAIL(ComputeInWaterResponse, pCEvent1, pCTask2, pCTask3)
    DECL_THISCALL_HEAD(ComputeInteriorUseInfoResponse, _ZN13CEventHandler30ComputeInteriorUseInfoResponseEP6CEventP5CTaskS3_, void, CEvent* pCEvent1, CTask* pCTask2, CTask* pCTask3)
    DECL_THISCALL_TAIL(ComputeInteriorUseInfoResponse, pCEvent1, pCTask2, pCTask3)
    DECL_THISCALL_HEAD(ComputeSignalAtPedResponse, _ZN13CEventHandler26ComputeSignalAtPedResponseEP6CEventP5CTaskS3_, void, CEvent* pCEvent1, CTask* pCTask2, CTask* pCTask3)
    DECL_THISCALL_TAIL(ComputeSignalAtPedResponse, pCEvent1, pCTask2, pCTask3)
    DECL_THISCALL_HEAD(ComputePassObjectResponse, _ZN13CEventHandler25ComputePassObjectResponseEP6CEventP5CTaskS3_, void, CEvent* pCEvent1, CTask* pCTask2, CTask* pCTask3)
    DECL_THISCALL_TAIL(ComputePassObjectResponse, pCEvent1, pCTask2, pCTask3)
    DECL_THISCALL_HEAD(ComputeCreatePartnerTaskResponse, _ZN13CEventHandler32ComputeCreatePartnerTaskResponseEP6CEventP5CTaskS3_, void, CEvent* pCEvent1, CTask* pCTask2, CTask* pCTask3)
    DECL_THISCALL_TAIL(ComputeCreatePartnerTaskResponse, pCEvent1, pCTask2, pCTask3)
    DECL_THISCALL_HEAD(ComputePlayerWantedLevelResponse, _ZN13CEventHandler32ComputePlayerWantedLevelResponseEP6CEventP5CTaskS3_, void, CEvent* pCEvent1, CTask* pCTask2, CTask* pCTask3)
    DECL_THISCALL_TAIL(ComputePlayerWantedLevelResponse, pCEvent1, pCTask2, pCTask3)
    DECL_THISCALL_HEAD(ComputeVehicleOnFireResponse, _ZN13CEventHandler28ComputeVehicleOnFireResponseEP6CEventP5CTaskS3_, void, CEvent* pCEvent1, CTask* pCTask2, CTask* pCTask3)
    DECL_THISCALL_TAIL(ComputeVehicleOnFireResponse, pCEvent1, pCTask2, pCTask3)
    DECL_THISCALL_HEAD(ComputeCopCarBeingStolenResponse, _ZN13CEventHandler32ComputeCopCarBeingStolenResponseEP6CEventP5CTaskS3_, void, CEvent* pCEvent1, CTask* pCTask2, CTask* pCTask3)
    DECL_THISCALL_TAIL(ComputeCopCarBeingStolenResponse, pCEvent1, pCTask2, pCTask3)
    DECL_THISCALL_HEAD(ComputeVehicleDamageResponse, _ZN13CEventHandler28ComputeVehicleDamageResponseEP6CEventP5CTaskS3_, void, CEvent* pCEvent1, CTask* pCTask2, CTask* pCTask3)
    DECL_THISCALL_TAIL(ComputeVehicleDamageResponse, pCEvent1, pCTask2, pCTask3)
    DECL_THISCALL_HEAD(ComputeSpecialResponse, _ZN13CEventHandler22ComputeSpecialResponseEP6CEventP5CTaskS3_, void, CEvent* pCEvent1, CTask* pCTask2, CTask* pCTask3)
    DECL_THISCALL_TAIL(ComputeSpecialResponse, pCEvent1, pCTask2, pCTask3)
    DECL_THISCALL_HEAD(ComputeGotKnockedOverByCarResponse, _ZN13CEventHandler34ComputeGotKnockedOverByCarResponseEP6CEventP5CTaskS3_, void, CEvent* pCEvent1, CTask* pCTask2, CTask* pCTask3)
    DECL_THISCALL_TAIL(ComputeGotKnockedOverByCarResponse, pCEvent1, pCTask2, pCTask3)
    DECL_THISCALL_HEAD(ComputeObjectCollisionPassiveResponse, _ZN13CEventHandler37ComputeObjectCollisionPassiveResponseEP6CEventP5CTaskS3_, void, CEvent* pCEvent1, CTask* pCTask2, CTask* pCTask3)
    DECL_THISCALL_TAIL(ComputeObjectCollisionPassiveResponse, pCEvent1, pCTask2, pCTask3)
    DECL_THISCALL_HEAD(ComputeCarUpsideDownResponse, _ZN13CEventHandler28ComputeCarUpsideDownResponseEP6CEventP5CTaskS3_, void, CEvent* pCEvent1, CTask* pCTask2, CTask* pCTask3)
    DECL_THISCALL_TAIL(ComputeCarUpsideDownResponse, pCEvent1, pCTask2, pCTask3)
    DECL_THISCALL_HEAD(ComputePotentialWalkIntoFireResponse, _ZN13CEventHandler36ComputePotentialWalkIntoFireResponseEP6CEventP5CTaskS3_, void, CEvent* pCEvent1, CTask* pCTask2, CTask* pCTask3)
    DECL_THISCALL_TAIL(ComputePotentialWalkIntoFireResponse, pCEvent1, pCTask2, pCTask3)
    DECL_THISCALL_HEAD(ComputeShotFiredWhizzedByResponse, _ZN13CEventHandler33ComputeShotFiredWhizzedByResponseEP6CEventP5CTaskS3_, void, CEvent* pCEvent1, CTask* pCTask2, CTask* pCTask3)
    DECL_THISCALL_TAIL(ComputeShotFiredWhizzedByResponse, pCEvent1, pCTask2, pCTask3)
    DECL_THISCALL_HEAD(ComputeSeenPanickedPedResponse, _ZN13CEventHandler30ComputeSeenPanickedPedResponseEP6CEventP5CTaskS3_, void, CEvent* pCEvent1, CTask* pCTask2, CTask* pCTask3)
    DECL_THISCALL_TAIL(ComputeSeenPanickedPedResponse, pCEvent1, pCTask2, pCTask3)
    DECL_THISCALL_HEAD(ComputeAreaCodesResponse, _ZN13CEventHandler24ComputeAreaCodesResponseEP6CEventP5CTaskS3_, void, CEvent* pCEvent1, CTask* pCTask2, CTask* pCTask3)
    DECL_THISCALL_TAIL(ComputeAreaCodesResponse, pCEvent1, pCTask2, pCTask3)
    DECL_THISCALL_HEAD(ComputeFireNearbyResponse, _ZN13CEventHandler25ComputeFireNearbyResponseEP6CEventP5CTaskS3_, void, CEvent* pCEvent1, CTask* pCTask2, CTask* pCTask3)
    DECL_THISCALL_TAIL(ComputeFireNearbyResponse, pCEvent1, pCTask2, pCTask3)
    DECL_THISCALL_HEAD(ComputeSeenCopResponse, _ZN13CEventHandler22ComputeSeenCopResponseEP6CEventP5CTaskS3_, void, CEvent* pCEvent1, CTask* pCTask2, CTask* pCTask3)
    DECL_THISCALL_TAIL(ComputeSeenCopResponse, pCEvent1, pCTask2, pCTask3)
    DECL_THISCALL_HEAD(ComputeOnEscalatorResponse, _ZN13CEventHandler26ComputeOnEscalatorResponseEP6CEventP5CTaskS3_, void, CEvent* pCEvent1, CTask* pCTask2, CTask* pCTask3)
    DECL_THISCALL_TAIL(ComputeOnEscalatorResponse, pCEvent1, pCTask2, pCTask3)
    DECL_THISCALL_HEAD(ComputeDangerResponse, _ZN13CEventHandler21ComputeDangerResponseEP6CEventP5CTaskS3_, void, CEvent* pCEvent1, CTask* pCTask2, CTask* pCTask3)
    DECL_THISCALL_TAIL(ComputeDangerResponse, pCEvent1, pCTask2, pCTask3)
    DECL_THISCALL_HEAD(ComputeDontJoinGroupResponse, _ZN13CEventHandler28ComputeDontJoinGroupResponseEP6CEventP5CTaskS3_, void, CEvent* pCEvent1, CTask* pCTask2, CTask* pCTask3)
    DECL_THISCALL_TAIL(ComputeDontJoinGroupResponse, pCEvent1, pCTask2, pCTask3)
    DECL_THISCALL_HEAD(SetEventResponseTask, _ZNK13CEventHandler20SetEventResponseTaskERK6CEvent, void, CEvent const& arg1)
    DECL_THISCALL_TAIL(SetEventResponseTask, arg1)
DECL_CLASS_END()

DECL_CLASS(CPedStuckChecker)
    // Construct/Deconstruct functions
    DECL_CTORCALL(CPedStuckChecker, _ZN16CPedStuckCheckerC2Ev);

    CVector m_vecPreviousPos;
    unsigned short m_nStuckCounter;
    unsigned short m_nStuck;

    // Member functions
    DECL_THISCALL_HEAD(TestPedStuck, _ZN16CPedStuckChecker12TestPedStuckEP4CPedP11CEventGroup, bool, CPed* ped, CEventGroup* eventGroup)
    DECL_THISCALL_TAIL(TestPedStuck, ped, eventGroup)
DECL_CLASS_END()

DECL_CLASS(CMentalState)
    // Member functions
    DECL_THISCALL_HEAD(Process, _ZN12CMentalState7ProcessERK4CPed, void, CPed const& arg1)
    DECL_THISCALL_TAIL(Process, arg1)

    unsigned char m_AngerAtPlayer;
    unsigned char m_LastAngerAtPlayer;
    CTaskTimer m_AngerTimer;
    unsigned short m_pedHealth;
    unsigned short m_oldPedHealth;
    unsigned short m_vehicleHealth;
    unsigned short m_oldVehicleHealth;
    unsigned char m_bInCarLastTime;
DECL_CLASS_END()

DECL_CLASS(CPedIntelligence)
    // Construct/Deconstruct functions
    CPedIntelligence(){}
    DECL_CTORCALL_ARG_HEAD(CPedIntelligence, _ZN16CPedIntelligenceC2EP4CPed, CPed *pPed)
    DECL_CTORCALL_ARG_TAIL(pPed)
    DECL_DTORCALL(CPedIntelligence, _ZN16CPedIntelligenceD2Ev);
    DECL_NEWCALL(CPedIntelligence, BYBIT(_ZN16CPedIntelligencenwEj, _ZN16CPedIntelligencenwEm) );
    DECL_DLCALL(CPedIntelligence, _ZN16CPedIntelligencedlEPv);

    // STATIC functions
    DECL_FASTCALL_SIMPLE(AreFriends, _ZN16CPedIntelligence10AreFriendsERK4CPedS2_, bool, CPed const& ped1, CPed const& ped2);

    // STATIC values
    DECL_OBJECT_PLT(float const, ms_fSenseRangeOfMissionPeds, BYBIT(0x679188, 0x850338));
    DECL_VALUE_PLT_I32(ms_iDesiredMoveState, BYBIT(0x676F38, 0x84BEB0));
    DECL_OBJECT_PLT(i32 const, ms_iStaticCounterStuckCount, BYBIT(0x67625C, 0x84A518));

    // Member functions
    DECL_THISCALL_HEAD(SetPedDecisionMakerType, _ZN16CPedIntelligence23SetPedDecisionMakerTypeEi, void, i32 dm)
    DECL_THISCALL_TAIL(SetPedDecisionMakerType, dm)
    DECL_THISCALL_HEAD(SetPedDecisionMakerTypeInGroup, _ZN16CPedIntelligence30SetPedDecisionMakerTypeInGroupEi, void, i32 dm)
    DECL_THISCALL_TAIL(SetPedDecisionMakerTypeInGroup, dm)
    DECL_THISCALL_HEAD(AddTaskPhysResponse, _ZN16CPedIntelligence19AddTaskPhysResponseEP5CTaskb, void, CTask* task, bool arg2)
    DECL_THISCALL_TAIL(AddTaskPhysResponse, task, arg2)
    DECL_THISCALL_HEAD(AddTaskEventResponseTemp, _ZN16CPedIntelligence24AddTaskEventResponseTempEP5CTaskb, void, CTask* task, bool arg2)
    DECL_THISCALL_TAIL(AddTaskEventResponseTemp, task, arg2)
    DECL_THISCALL_HEAD(AddTaskEventResponseNonTemp, _ZN16CPedIntelligence27AddTaskEventResponseNonTempEP5CTaskb, void, CTask* task, bool arg2)
    DECL_THISCALL_TAIL(AddTaskEventResponseNonTemp, task, arg2)
    DECL_THISCALL_HEAD(AddTaskPrimaryMaybeInGroup, _ZN16CPedIntelligence26AddTaskPrimaryMaybeInGroupEP5CTaskb, void, CTask* task, bool arg2)
    DECL_THISCALL_TAIL(AddTaskPrimaryMaybeInGroup, task, arg2)
    DECL_THISCALL_HEAD(FindTaskByType, _ZNK16CPedIntelligence14FindTaskByTypeEi, CTask*, i32 type)
    DECL_THISCALL_TAIL(FindTaskByType, type)
    DECL_THISCALL_HEAD(GetTaskHold, _ZNK16CPedIntelligence11GetTaskHoldEb, CTaskSimpleHoldEntity*, bool arg1)
    DECL_THISCALL_TAIL(GetTaskHold, arg1)
    DECL_THISCALL_HEAD(GetTaskDuck, _ZNK16CPedIntelligence11GetTaskDuckEb, CTaskSimpleDuck*, bool arg1)
    DECL_THISCALL_TAIL(GetTaskDuck, arg1)
    DECL_THISCALL_HEAD(SetTaskDuckSecondary, _ZN16CPedIntelligence20SetTaskDuckSecondaryEt, void, u16 arg1)
    DECL_THISCALL_TAIL(SetTaskDuckSecondary, arg1)
    DECL_THISCALL_HEAD(ClearTasks, _ZN16CPedIntelligence10ClearTasksEbb, void, bool arg1, bool arg2)
    DECL_THISCALL_TAIL(ClearTasks, arg1, arg2)
    DECL_THISCALL_HEAD(FlushImmediately, _ZN16CPedIntelligence16FlushImmediatelyEb, void, bool arg1)
    DECL_THISCALL_TAIL(FlushImmediately, arg1)
    DECL_THISCALL_HEAD(IsFriendlyWith, _ZNK16CPedIntelligence14IsFriendlyWithERK4CPed, bool, CPed const& ped)
    DECL_THISCALL_TAIL(IsFriendlyWith, ped)
    DECL_THISCALL_HEAD(IsThreatenedBy, _ZNK16CPedIntelligence14IsThreatenedByERK4CPed, bool, CPed const& ped)
    DECL_THISCALL_TAIL(IsThreatenedBy, ped)
    DECL_THISCALL_HEAD(Respects, _ZNK16CPedIntelligence8RespectsERK4CPed, bool, CPed const& ped)
    DECL_THISCALL_TAIL(Respects, ped)
    DECL_THISCALL_HEAD(IsRespondingToEvent, _ZNK16CPedIntelligence19IsRespondingToEventEi, bool, i32 event)
    DECL_THISCALL_TAIL(IsRespondingToEvent, event)
    DECL_THISCALL_HEAD(SetEffectInUse, _ZN16CPedIntelligence14SetEffectInUseEP9C2dEffect, void, C2dEffect* arg1)
    DECL_THISCALL_TAIL(SetEffectInUse, arg1)
    DECL_THISCALL_HEAD(SetHearingRange, _ZN16CPedIntelligence15SetHearingRangeEf, void, float range)
    DECL_THISCALL_TAIL(SetHearingRange, range)
    DECL_THISCALL_HEAD(SetSeeingRange, _ZN16CPedIntelligence14SetSeeingRangeEf, void, float range)
    DECL_THISCALL_TAIL(SetSeeingRange, range)
    DECL_THISCALL_HEAD(IsInHearingRange, _ZNK16CPedIntelligence16IsInHearingRangeERK7CVector, bool, CVector const& posn)
    DECL_THISCALL_TAIL(IsInHearingRange, posn)
    DECL_THISCALL_NAMED_HEAD(IsInSeeingRange1, IsInSeeingRange, _ZNK16CPedIntelligence15IsInSeeingRangeERK7CVector, bool, CVector const& posn)
    DECL_THISCALL_TAIL(IsInSeeingRange1, posn)
    DECL_THISCALL_NAMED_HEAD(IsInSeeingRange2, IsInSeeingRange, _ZNK16CPedIntelligence15IsInSeeingRangeEP7CEntity, bool, CEntity* posn)
    DECL_THISCALL_TAIL(IsInSeeingRange2, posn)
    DECL_THISCALL_HEAD(CanSeeEntityWithLights, _ZNK16CPedIntelligence22CanSeeEntityWithLightsEPK7CEntityb, float, CEntity const* pEntity, bool arg2)
    DECL_THISCALL_TAIL(CanSeeEntityWithLights, pEntity, arg2)
    DECL_THISCALL_HEAD(TestForStealthKill, _ZN16CPedIntelligence18TestForStealthKillEP4CPedb, bool, CPed* pPed, bool arg2)
    DECL_THISCALL_TAIL(TestForStealthKill, pPed, arg2)
    DECL_THISCALL_HEAD(RecordEventForScript, _ZN16CPedIntelligence20RecordEventForScriptEii, void, i32 EventID, i32 EventPriority)
    DECL_THISCALL_TAIL(RecordEventForScript, EventID, EventPriority)
    DECL_THISCALL_HEAD(IsInterestingEntity, _ZN16CPedIntelligence19IsInterestingEntityEP7CEntity, u8, CEntity* pEntity)
    DECL_THISCALL_TAIL(IsInterestingEntity, pEntity)
    DECL_THISCALL_HEAD(AddInterestingEntity, _ZN16CPedIntelligence20AddInterestingEntityEP7CEntity, void, CEntity* pCEntity1)
    DECL_THISCALL_TAIL(AddInterestingEntity, pCEntity1)
    DECL_THISCALL_HEAD(RemoveInterestingEntity, _ZN16CPedIntelligence23RemoveInterestingEntityEP7CEntity, u8, CEntity* pCEntity1)
    DECL_THISCALL_TAIL(RemoveInterestingEntity, pCEntity1)
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
    DECL_FASTCALL_SIMPLE(SortAndStaggerAllPedsEventScannerTimers, _ZN16CPedIntelligence39SortAndStaggerAllPedsEventScannerTimersEv, void);
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

#define ms_fSenseRangeOfMissionPeds ms_fSenseRangeOfMissionPeds()
#define ms_iDesiredMoveState ms_iDesiredMoveState()
#define ms_iStaticCounterStuckCount ms_iStaticCounterStuckCount()

#endif // __AML_PSDK_SAPEDINTELLIGENCE_H
