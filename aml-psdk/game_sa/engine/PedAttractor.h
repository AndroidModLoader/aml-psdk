#ifndef __AML_PSDK_SAPEDATTRACTOR_H
#define __AML_PSDK_SAPEDATTRACTOR_H

#include <aml-psdk/game_sa/ai/PedGroup.h>
#include <aml-psdk/gta_base/Vector.h>

struct CPed;
struct CEntity;
struct C2dEffect;
struct CMatrix;

DECL_CLASS(CPedAttractor)
    // Virtual functions
    virtual int GetType() const = 0;
    DECL_DTORCALL_VIRTUAL_SLOT(CPedAttractor, _ZN13CPedAttractorD2Ev, _ZN13CPedAttractor, _ZTV13CPedAttractor, 1);
    inline void BaseDestructor() { ((void(*)(CPedAttractor*))(*(uptr**)this)[1])(this); }
    inline void BaseDeletingDestructor() { ((void(*)(CPedAttractor*))(*(uptr**)this)[2])(this); }
    DECL_VIRTUALCALL_CONST_HEAD(CPedAttractor, IsAtHeadOfQueue, _ZTV13CPedAttractor, 3, bool, CPed* pPed)
    DECL_VIRTUALCALL_TAIL(pPed)
    DECL_VIRTUALCALL_CONST_HEAD(CPedAttractor, ComputeAttractPos, _ZTV13CPedAttractor, 4, void, int const slot, CVector& pos)
    DECL_VIRTUALCALL_TAIL(slot, pos)
    DECL_VIRTUALCALL_CONST_HEAD(CPedAttractor, ComputeAttractHeading, _ZTV13CPedAttractor, 5, void, int const slot, float& heading)
    DECL_VIRTUALCALL_TAIL(slot, heading)
    DECL_VIRTUALCALL_HEAD(CPedAttractor, BroadcastDeparture, _ZTV13CPedAttractor, 6, bool, CPed* pPed)
    DECL_VIRTUALCALL_TAIL(pPed)

    // Member functions
    DECL_CTORCALL_ARG_HEAD(CPedAttractor, _ZN13CPedAttractorC2EP9C2dEffectP7CEntityiifffffff, C2dEffect* pEffect, CEntity* pEntity, int const iMoveState, int const iMaxNoOfPeds, float const fSpacing, float const fAchieveQueueTime, float const fAchieveQueueShuffleTime, float const fArriveRange, float const fHeadingRange, float const fDeltaPos, float const fDeltaHeading)
    DECL_CTORCALL_ARG_TAIL(pEffect, pEntity, iMoveState, iMaxNoOfPeds, fSpacing, fAchieveQueueTime, fAchieveQueueShuffleTime, fArriveRange, fHeadingRange, fDeltaPos, fDeltaHeading)
    DECL_NEWCALL(CPedAttractor, BYBIT(_ZN13CPedAttractornwEj, _ZN13CPedAttractornwEm));
    DECL_DLCALL(CPedAttractor, _ZN13CPedAttractordlEPv);
    DECL_THISCALL_HEAD(GetTaskForPed, _ZNK13CPedAttractor13GetTaskForPedEP4CPed, CTask*, CPed* pPed)
    DECL_THISCALL_TAIL(GetTaskForPed, pPed)
    DECL_THISCALL_SIMPLE(AbortPedTasks, _ZN13CPedAttractor13AbortPedTasksEv, void);
    DECL_THISCALL_SIMPLE(GetHeadOfQueue, _ZNK13CPedAttractor14GetHeadOfQueueEv, CPed*);
    DECL_THISCALL_SIMPLE(GetTailOfQueue, _ZNK13CPedAttractor14GetTailOfQueueEv, CPed*);
    DECL_THISCALL_HEAD(GetQueueSlot, _ZNK13CPedAttractor12GetQueueSlotEPK4CPed, int, CPed const* pPed)
    DECL_THISCALL_TAIL(GetQueueSlot, pPed)
    DECL_THISCALL_SIMPLE(GetNoOfRegisteredPeds, _ZNK13CPedAttractor21GetNoOfRegisteredPedsEv, int);
    DECL_THISCALL_HEAD(ComputeAttractTime, _ZNK13CPedAttractor18ComputeAttractTimeEibRf, void, int const iSlot, bool bHasArrived, float& fAttractTime)
    DECL_THISCALL_TAIL(ComputeAttractTime, iSlot, bHasArrived, fAttractTime)
    DECL_THISCALL_SIMPLE(ComputeFreeSlot, _ZNK13CPedAttractor15ComputeFreeSlotEv, int);
    DECL_THISCALL_SIMPLE(ComputeDeltaPos, _ZNK13CPedAttractor15ComputeDeltaPosEv, float);
    DECL_THISCALL_SIMPLE(ComputeDeltaHeading, _ZNK13CPedAttractor19ComputeDeltaHeadingEv, float);
    DECL_THISCALL_HEAD(RegisterPed, _ZN13CPedAttractor11RegisterPedEP4CPed, bool, CPed* pPed)
    DECL_THISCALL_TAIL(RegisterPed, pPed)
    DECL_THISCALL_HEAD(DeRegisterPed, _ZN13CPedAttractor13DeRegisterPedEP4CPed, bool, CPed* pPed)
    DECL_THISCALL_TAIL(DeRegisterPed, pPed)
    DECL_THISCALL_HEAD(BroadcastArrival, _ZN13CPedAttractor16BroadcastArrivalEP4CPed, bool, CPed* pPed)
    DECL_THISCALL_TAIL(BroadcastArrival, pPed)
    DECL_THISCALL_HEAD(IsRegisteredWithPed, _ZNK13CPedAttractor19IsRegisteredWithPedEPK4CPed, bool, CPed const* pPed)
    DECL_THISCALL_TAIL(IsRegisteredWithPed, pPed)
    DECL_THISCALL_HEAD(SetTaskForPed, _ZN13CPedAttractor13SetTaskForPedEP4CPedP5CTask, void, CPed* pPed, CTask* pTask)
    DECL_THISCALL_TAIL(SetTaskForPed, pPed, pTask)

    // STATIC values
    DECL_OBJECT_PLT(SArray<const CTask*>, ms_tasks, BYBIT(0x6787E0, 0x84EFE8));

    // Member values
    C2dEffect* m_pEffect;
    CEntity* m_pEntity;
    SArray<CPed *> m_attractPeds;
    SArray<CPed *> m_arrivedPeds;
    SArray<CPedTaskPair> m_pedTaskPairs;
    int m_iMaxNoOfPeds;
    float m_fSpacing;
    float m_fAchieveQueueTime;
    float m_fAchieveQueueShuffleTime;
    float m_fArriveRange;
    float m_fHeadingRange;
    float m_fDeltaPos;
    float m_fDeltaHeading;
    CVector m_vPos;
    CVector m_vQueueDir;
    CVector m_vUseDir;
    int m_iMoveState;
    char m_scriptName[64];
DECL_CLASS_END()
CHECKSIZE(CPedAttractor, 0xB8, 0xD0);

DECL_CLASS(CPedAttractorPedPlacer)
    // Member functions
    DECL_FASTCALL_SIMPLE(PlacePedAtEffect, _ZN22CPedAttractorPedPlacer16PlacePedAtEffectERK9C2dEffectP7CEntityP4CPedf, void, C2dEffect const& effect, CEntity* pEntity, CPed* pPed, float dist);

    // Member values
    float m_dist;
DECL_CLASS_END()
CHECKSIZE(CPedAttractorPedPlacer, 0x4, 0x4);

DECL_CLASS(CPedAttractorManager)
    // Member functions
    DECL_THISCALL_HEAD(RegisterPedWithAttractor, _ZN20CPedAttractorManager24RegisterPedWithAttractorEP4CPedP9C2dEffectP7CEntityi, CPedAttractor*, CPed* pPed, C2dEffect* pEffect, CEntity* pEntity, int const iMoveState)
    DECL_THISCALL_TAIL(RegisterPedWithAttractor, pPed, pEffect, pEntity, iMoveState)
    DECL_THISCALL_HEAD(BroadcastArrival, _ZN20CPedAttractorManager16BroadcastArrivalEP4CPedP13CPedAttractor, bool, CPed* pPed, CPedAttractor* pAttractor)
    DECL_THISCALL_TAIL(BroadcastArrival, pPed, pAttractor)
    DECL_THISCALL_HEAD(BroadcastDeparture, _ZN20CPedAttractorManager18BroadcastDepartureEP4CPedP13CPedAttractor, bool, CPed* pPed, CPedAttractor* pAttractor)
    DECL_THISCALL_TAIL(BroadcastDeparture, pPed, pAttractor)
    DECL_THISCALL_HEAD(IsPedRegisteredWithEffect, _ZNK20CPedAttractorManager25IsPedRegisteredWithEffectEP4CPed, bool, CPed* pPed)
    DECL_THISCALL_TAIL(IsPedRegisteredWithEffect, pPed)
    DECL_THISCALL_NAMED_HEAD(IsPedRegisteredWithEffect2, IsPedRegisteredWithEffect, _ZNK20CPedAttractorManager25IsPedRegisteredWithEffectEP4CPedPK9C2dEffectPK7CEntity, bool, CPed* arg1, C2dEffect const* arg2, CEntity const* arg3)
    DECL_THISCALL_TAIL(IsPedRegisteredWithEffect2, arg1, arg2, arg3)
    DECL_THISCALL_HEAD(HasEmptySlot, _ZNK20CPedAttractorManager12HasEmptySlotEPK9C2dEffectPK7CEntity, bool, C2dEffect const* pEffect, CEntity const* pEntity)
    DECL_THISCALL_TAIL(HasEmptySlot, pEffect, pEntity)
    DECL_THISCALL_HEAD(DeRegisterPed, _ZN20CPedAttractorManager13DeRegisterPedEP4CPedP13CPedAttractor, bool, CPed* arg1, CPedAttractor* arg2)
    DECL_THISCALL_TAIL(DeRegisterPed, arg1, arg2)
    DECL_THISCALL_HEAD(RemoveEffect, _ZNK20CPedAttractorManager12RemoveEffectEPK9C2dEffect, bool, C2dEffect const* pEffect)
    DECL_THISCALL_TAIL(RemoveEffect, pEffect)
    DECL_THISCALL_HEAD(HasQueueTailArrivedAtSlot, _ZN20CPedAttractorManager25HasQueueTailArrivedAtSlotEPK9C2dEffectPK7CEntity, bool, C2dEffect const* pEffect, CEntity const* pEntity)
    DECL_THISCALL_TAIL(HasQueueTailArrivedAtSlot, pEffect, pEntity)
    DECL_FASTCALL_SIMPLE(ComputeEffectPos, _ZN20CPedAttractorManager16ComputeEffectPosEPK9C2dEffectRK7CMatrixR7CVector, void, C2dEffect const* pEffect, CMatrix const& mat, CVector& vPos);
    DECL_FASTCALL_SIMPLE(ComputeEffectQueueDir, _ZN20CPedAttractorManager21ComputeEffectQueueDirEPK9C2dEffectRK7CMatrixR7CVector, void, C2dEffect const* pEffect, CMatrix const& mat, CVector& vQueueDir);
    DECL_FASTCALL_SIMPLE(ComputeEffectUseDir, _ZN20CPedAttractorManager19ComputeEffectUseDirEPK9C2dEffectRK7CMatrixR7CVector, void, C2dEffect const* pEffect, CMatrix const& mat, CVector& vUseDir);
    DECL_FASTCALL_SIMPLE(ComputeEffectForwardDir, _ZN20CPedAttractorManager23ComputeEffectForwardDirEPK9C2dEffectRK7CMatrixR7CVector, void, C2dEffect const* pEffect, CMatrix const& mat, CVector& vForwardDir);
    DECL_FASTCALL_SIMPLE(IsApproachable, _ZN20CPedAttractorManager14IsApproachableEP9C2dEffectRK7CMatrixiP4CPed, bool, C2dEffect* pEffect, CMatrix const& mat, int const iSlot, CPed* pPed);
    DECL_THISCALL_HEAD(GetPedUsingEffect, _ZN20CPedAttractorManager17GetPedUsingEffectEPK9C2dEffectPK7CEntity, CPed*, C2dEffect const* pEffect, CEntity const* pEntity)
    DECL_THISCALL_TAIL(GetPedUsingEffect, pEffect, pEntity)
    DECL_THISCALL_HEAD(GetRelevantAttractor, _ZNK20CPedAttractorManager20GetRelevantAttractorEPK4CPedPK9C2dEffectPK7CEntity, CPedAttractor const*, CPed const* pPed, C2dEffect const* pEffect, CEntity const* pEntity)
    DECL_THISCALL_TAIL(GetRelevantAttractor, pPed, pEffect, pEntity)
    DECL_THISCALL_SIMPLE(RestoreStuffFromMem, _ZN20CPedAttractorManager19RestoreStuffFromMemEv, void);
    DECL_THISCALL_HEAD(FindAssociatedAttractor, _ZNK20CPedAttractorManager23FindAssociatedAttractorEPK9C2dEffectPK7CEntityRK6SArrayIP13CPedAttractorE, CPedAttractor*, C2dEffect const* pEffect, CEntity const* pEntity, SArray<CPedAttractor *> const& attractors)
    DECL_THISCALL_TAIL(FindAssociatedAttractor, pEffect, pEntity, attractors)
    DECL_THISCALL_HEAD(IsPedRegistered, _ZNK20CPedAttractorManager15IsPedRegisteredEP4CPedRK6SArrayIP13CPedAttractorE, bool, CPed* pPed, SArray<CPedAttractor *> const& attractors)
    DECL_THISCALL_TAIL(IsPedRegistered, pPed, attractors)
    DECL_THISCALL_NAMED_HEAD(IsPedRegisteredWithEffect3, IsPedRegisteredWithEffect, _ZNK20CPedAttractorManager25IsPedRegisteredWithEffectEP4CPedPK9C2dEffectPK7CEntityRK6SArrayIP13CPedAttractorE, bool, CPed* arg1, C2dEffect const* arg2, CEntity const* arg3, SArray<CPedAttractor *> const& arg4)
    DECL_THISCALL_TAIL(IsPedRegisteredWithEffect3, arg1, arg2, arg3, arg4)
    DECL_THISCALL_HEAD(RegisterPed, _ZN20CPedAttractorManager11RegisterPedEP4CPedP9C2dEffectP7CEntityiR6SArrayIP13CPedAttractorE, CPedAttractor*, CPed* pPed, C2dEffect* pEffect, CEntity* pEntity, int const iMoveState, SArray<CPedAttractor *>& attractors)
    DECL_THISCALL_TAIL(RegisterPed, pPed, pEffect, pEntity, iMoveState, attractors)
    DECL_THISCALL_NAMED_HEAD(BroadcastArrival2, BroadcastArrival, _ZN20CPedAttractorManager16BroadcastArrivalEP4CPedP13CPedAttractorR6SArrayIS3_E, bool, CPed* arg1, CPedAttractor* arg2, SArray<CPedAttractor *>& arg3)
    DECL_THISCALL_TAIL(BroadcastArrival2, arg1, arg2, arg3)
    DECL_THISCALL_NAMED_HEAD(BroadcastDeparture2, BroadcastDeparture, _ZN20CPedAttractorManager18BroadcastDepartureEP4CPedP13CPedAttractorR6SArrayIS3_E, bool, CPed* arg1, CPedAttractor* arg2, SArray<CPedAttractor *>& arg3)
    DECL_THISCALL_TAIL(BroadcastDeparture2, arg1, arg2, arg3)
    DECL_THISCALL_NAMED_HEAD(DeRegisterPed2, DeRegisterPed, _ZN20CPedAttractorManager13DeRegisterPedEP4CPedP13CPedAttractorR6SArrayIS3_E, bool, CPed* pPed, CPedAttractor* pInputAttractor, SArray<CPedAttractor *>& attractors)
    DECL_THISCALL_TAIL(DeRegisterPed2, pPed, pInputAttractor, attractors)
    DECL_THISCALL_NAMED_HEAD(RemoveEffect2, RemoveEffect, _ZNK20CPedAttractorManager12RemoveEffectEPK9C2dEffectRK6SArrayIP13CPedAttractorE, bool, C2dEffect const* arg1, SArray<CPedAttractor *> const& arg2)
    DECL_THISCALL_TAIL(RemoveEffect2, arg1, arg2)
    DECL_THISCALL_NAMED_HEAD(GetPedUsingEffect2, GetPedUsingEffect, _ZN20CPedAttractorManager17GetPedUsingEffectEPK9C2dEffectPK7CEntityRK6SArrayIP13CPedAttractorE, CPed*, C2dEffect const* arg1, CEntity const* arg2, SArray<CPedAttractor *> const& arg3)
    DECL_THISCALL_TAIL(GetPedUsingEffect2, arg1, arg2, arg3)
    DECL_THISCALL_NAMED_HEAD(GetRelevantAttractor2, GetRelevantAttractor, _ZNK20CPedAttractorManager20GetRelevantAttractorEPK4CPedPK9C2dEffectPK7CEntityRK6SArrayIP13CPedAttractorE, CPedAttractor const*, CPed const* arg1, C2dEffect const* arg2, CEntity const* arg3, SArray<CPedAttractor *> const& arg4)
    DECL_THISCALL_TAIL(GetRelevantAttractor2, arg1, arg2, arg3, arg4)

    // STATIC values
    DECL_OBJECT_PLT(float const, ms_fSearchDistance, BYBIT(0x678DE0, 0x84FBE8));

    // Member values
    SArray<CPedAttractor *> m_seats;
    SArray<CPedAttractor *> m_atms;
    SArray<CPedAttractor *> m_stops;
    SArray<CPedAttractor *> m_pizzas;
    SArray<CPedAttractor *> m_shelters;
    SArray<CPedAttractor *> m_triggerScripts;
    SArray<CPedAttractor *> m_lookAts;
    SArray<CPedAttractor *> m_scripted;
    SArray<CPedAttractor *> m_parks;
    SArray<CPedAttractor *> m_steps;
DECL_CLASS_END()
CHECKSIZE(CPedAttractorManager, 0x78, 0xA0);

DECL_CLASS_BASED(CPedPizzaAttractor, CPedAttractor)
    DECL_NEWCALL(CPedPizzaAttractor, BYBIT(_ZN13CPedAttractornwEj, _ZN13CPedAttractornwEm));

    // Construct/Deconstruct functions
    CPedPizzaAttractor(C2dEffect* effect, CEntity* entity, i32 const moveState) : CPedAttractor(effect, entity, moveState, ms_iMaxSlots(), ms_fSpacing(), ms_fAchieveQueueTime(), ms_fAchieveQueueShuffleTime(), ms_fArriveRange(), ms_fHeadingRange(), ms_fDeltaPos(), ms_fDeltaHeading()) {}

    // Virtual functions
    DECL_VIRTUALCALL_CONST_HEAD(CPedPizzaAttractor, GetType, _ZTV18CPedPizzaAttractor, 0, i32)
    DECL_VIRTUALCALL_TAIL()
    DECL_DTORCALL_VIRTUAL_VTABLE_SLOT(CPedPizzaAttractor, _ZN18CPedPizzaAttractor, _ZTV18CPedPizzaAttractor, 1);
    DECL_VIRTUALCALL_HEAD(CPedPizzaAttractor, GetHeadOfQueueWaitTime, _ZTV18CPedPizzaAttractor, 7, float)
    DECL_VIRTUALCALL_TAIL()

    // STATIC values
    DECL_OBJECT_SYM(i32 const, ms_iMaxSlots, _ZN18CPedPizzaAttractor12ms_iMaxSlotsE);
    DECL_OBJECT_SYM(float const, ms_fSpacing, _ZN18CPedPizzaAttractor11ms_fSpacingE);
    DECL_OBJECT_SYM(float const, ms_fAchieveQueueTime, _ZN18CPedPizzaAttractor20ms_fAchieveQueueTimeE);
    DECL_OBJECT_SYM(float const, ms_fAchieveQueueShuffleTime, _ZN18CPedPizzaAttractor27ms_fAchieveQueueShuffleTimeE);
    DECL_OBJECT_SYM(float const, ms_fArriveRange, _ZN18CPedPizzaAttractor15ms_fArriveRangeE);
    DECL_OBJECT_SYM(float const, ms_fHeadingRange, _ZN18CPedPizzaAttractor16ms_fHeadingRangeE);
    DECL_OBJECT_SYM(float const, ms_fDeltaPos, _ZN18CPedPizzaAttractor12ms_fDeltaPosE);
    DECL_OBJECT_SYM(float const, ms_fDeltaHeading, _ZN18CPedPizzaAttractor16ms_fDeltaHeadingE);
    DECL_OBJECT_SYM(float const, ms_fPizzaOrderTime, _ZN18CPedPizzaAttractor18ms_fPizzaOrderTimeE);

    DECL_THISCALL_SIMPLE(Delete, _ZN18CPedPizzaAttractorD0Ev, void);
DECL_CLASS_END()
CHECKSIZE(CPedPizzaAttractor, 0xb8, 0xd0);

DECL_CLASS_BASED(CPedShelterAttractor, CPedAttractor)
    DECL_NEWCALL(CPedShelterAttractor, BYBIT(_ZN13CPedAttractornwEj, _ZN13CPedAttractornwEm));

    // Construct/Deconstruct functions
    CPedShelterAttractor(C2dEffect* effect, CEntity* entity, i32 const moveState) : CPedAttractor(effect, entity, moveState, ms_iMaxSlots(), ms_fSpacing(), ms_fAchieveQueueTime(), ms_fAchieveQueueShuffleTime(), ms_fArriveRange(), ms_fHeadingRange(), ms_fDeltaPos(), ms_fDeltaHeading()) {}

    // Virtual functions
    DECL_VIRTUALCALL_CONST_HEAD(CPedShelterAttractor, GetType, _ZTV20CPedShelterAttractor, 0, i32)
    DECL_VIRTUALCALL_TAIL()
    DECL_DTORCALL_VIRTUAL_VTABLE_SLOT(CPedShelterAttractor, _ZN20CPedShelterAttractor, _ZTV20CPedShelterAttractor, 1);
    DECL_VIRTUALCALL_CONST_HEAD(CPedShelterAttractor, IsAtHeadOfQueue, _ZTV20CPedShelterAttractor, 3, bool, CPed* ped)
    DECL_VIRTUALCALL_TAIL(ped)
    DECL_VIRTUALCALL_CONST_HEAD(CPedShelterAttractor, ComputeAttractPos, _ZTV20CPedShelterAttractor, 4, void, int const slot, CVector& pos)
    DECL_VIRTUALCALL_TAIL(slot, pos)
    DECL_VIRTUALCALL_CONST_HEAD(CPedShelterAttractor, ComputeAttractHeading, _ZTV20CPedShelterAttractor, 5, void, int const slot, float& heading)
    DECL_VIRTUALCALL_TAIL(slot, heading)
    DECL_VIRTUALCALL_HEAD(CPedShelterAttractor, BroadcastDeparture, _ZTV20CPedShelterAttractor, 6, bool, CPed* ped)
    DECL_VIRTUALCALL_TAIL(ped)

    // STATIC functions
    DECL_FASTCALL_SIMPLE(GetDisplacement, _ZN20CPedShelterAttractor15GetDisplacementEi, CVector const&, int const iSlot);

    // STATIC values
    DECL_OBJECT_SYM(i32 const, ms_iMaxSlots, _ZN20CPedShelterAttractor12ms_iMaxSlotsE);
    DECL_OBJECT_SYM(float const, ms_fSpacing, _ZN20CPedShelterAttractor11ms_fSpacingE);
    DECL_OBJECT_SYM(float const, ms_fAchieveQueueTime, _ZN20CPedShelterAttractor20ms_fAchieveQueueTimeE);
    DECL_OBJECT_SYM(float const, ms_fAchieveQueueShuffleTime, _ZN20CPedShelterAttractor27ms_fAchieveQueueShuffleTimeE);
    DECL_OBJECT_SYM(float const, ms_fArriveRange, _ZN20CPedShelterAttractor15ms_fArriveRangeE);
    DECL_OBJECT_SYM(float const, ms_fHeadingRange, _ZN20CPedShelterAttractor16ms_fHeadingRangeE);
    DECL_OBJECT_SYM(float const, ms_fDeltaPos, _ZN20CPedShelterAttractor12ms_fDeltaPosE);
    DECL_OBJECT_SYM(float const, ms_fDeltaHeading, _ZN20CPedShelterAttractor16ms_fDeltaHeadingE);
    DECL_OBJECT_PLT(SArray<CVector>, ms_displacements, BYBIT(0x678170, 0x84e2f8));

    DECL_THISCALL_SIMPLE(Delete, _ZN20CPedShelterAttractorD0Ev, void);
DECL_CLASS_END()
CHECKSIZE(CPedShelterAttractor, 0xb8, 0xd0);

DECL_CLASS_BASED(CPedAtmAttractor, CPedAttractor)
    DECL_NEWCALL(CPedAtmAttractor, BYBIT(_ZN13CPedAttractornwEj, _ZN13CPedAttractornwEm));

    // Construct/Deconstruct functions
    CPedAtmAttractor(C2dEffect* effect, CEntity* entity, i32 const moveState) : CPedAttractor(effect, entity, moveState, ms_iMaxSlots(), ms_fSpacing(), ms_fAchieveQueueTime(), ms_fAchieveQueueShuffleTime(), ms_fArriveRange(), ms_fHeadingRange(), ms_fDeltaPos(), ms_fDeltaHeading()) {}

    // Virtual functions
    DECL_VIRTUALCALL_CONST_HEAD(CPedAtmAttractor, GetType, _ZTV16CPedAtmAttractor, 0, i32)
    DECL_VIRTUALCALL_TAIL()
    DECL_DTORCALL_VIRTUAL_VTABLE_SLOT(CPedAtmAttractor, _ZN16CPedAtmAttractor, _ZTV16CPedAtmAttractor, 1);

    // STATIC values
    DECL_OBJECT_SYM(i32 const, ms_iMaxSlots, _ZN16CPedAtmAttractor12ms_iMaxSlotsE);
    DECL_OBJECT_SYM(float const, ms_fSpacing, _ZN16CPedAtmAttractor11ms_fSpacingE);
    DECL_OBJECT_SYM(float const, ms_fAchieveQueueTime, _ZN16CPedAtmAttractor20ms_fAchieveQueueTimeE);
    DECL_OBJECT_SYM(float const, ms_fAchieveQueueShuffleTime, _ZN16CPedAtmAttractor27ms_fAchieveQueueShuffleTimeE);
    DECL_OBJECT_SYM(float const, ms_fArriveRange, _ZN16CPedAtmAttractor15ms_fArriveRangeE);
    DECL_OBJECT_SYM(float const, ms_fHeadingRange, _ZN16CPedAtmAttractor16ms_fHeadingRangeE);
    DECL_OBJECT_SYM(float const, ms_fDeltaPos, _ZN16CPedAtmAttractor12ms_fDeltaPosE);
    DECL_OBJECT_SYM(float const, ms_fDeltaHeading, _ZN16CPedAtmAttractor16ms_fDeltaHeadingE);

DECL_CLASS_END()
CHECKSIZE(CPedAtmAttractor, 0xb8, 0xd0);

DECL_CLASS_BASED(CPedLookAtAttractor, CPedAttractor)
    DECL_NEWCALL(CPedLookAtAttractor, BYBIT(_ZN13CPedAttractornwEj, _ZN13CPedAttractornwEm));

    // Construct/Deconstruct functions
    CPedLookAtAttractor(C2dEffect* effect, CEntity* entity, i32 const moveState) : CPedAttractor(effect, entity, moveState, ms_iMaxSlots(), ms_fSpacing(), ms_fAchieveQueueTime(), ms_fAchieveQueueShuffleTime(), ms_fArriveRange(), ms_fHeadingRange(), ms_fDeltaPos(), ms_fDeltaHeading()) {}

    // Virtual functions
    DECL_VIRTUALCALL_CONST_HEAD(CPedLookAtAttractor, GetType, _ZTV19CPedLookAtAttractor, 0, i32)
    DECL_VIRTUALCALL_TAIL()
    DECL_DTORCALL_VIRTUAL_VTABLE_SLOT(CPedLookAtAttractor, _ZN19CPedLookAtAttractor, _ZTV19CPedLookAtAttractor, 1);

    // STATIC values
    DECL_OBJECT_SYM(i32 const, ms_iMaxSlots, _ZN19CPedLookAtAttractor12ms_iMaxSlotsE);
    DECL_OBJECT_SYM(float const, ms_fSpacing, _ZN19CPedLookAtAttractor11ms_fSpacingE);
    DECL_OBJECT_SYM(float const, ms_fAchieveQueueTime, _ZN19CPedLookAtAttractor20ms_fAchieveQueueTimeE);
    DECL_OBJECT_SYM(float const, ms_fAchieveQueueShuffleTime, _ZN19CPedLookAtAttractor27ms_fAchieveQueueShuffleTimeE);
    DECL_OBJECT_SYM(float const, ms_fArriveRange, _ZN19CPedLookAtAttractor15ms_fArriveRangeE);
    DECL_OBJECT_SYM(float const, ms_fHeadingRange, _ZN19CPedLookAtAttractor16ms_fHeadingRangeE);
    DECL_OBJECT_SYM(float const, ms_fDeltaPos, _ZN19CPedLookAtAttractor12ms_fDeltaPosE);
    DECL_OBJECT_SYM(float const, ms_fDeltaHeading, _ZN19CPedLookAtAttractor16ms_fDeltaHeadingE);

DECL_CLASS_END()
CHECKSIZE(CPedLookAtAttractor, 0xb8, 0xd0);

DECL_CLASS_BASED(CPedParkAttractor, CPedAttractor)
    DECL_NEWCALL(CPedParkAttractor, BYBIT(_ZN13CPedAttractornwEj, _ZN13CPedAttractornwEm));

    // Construct/Deconstruct functions
    CPedParkAttractor(C2dEffect* effect, CEntity* entity, i32 const moveState) : CPedAttractor(effect, entity, moveState, ms_iMaxSlots(), ms_fSpacing(), ms_fAchieveQueueTime(), ms_fAchieveQueueShuffleTime(), ms_fArriveRange(), ms_fHeadingRange(), ms_fDeltaPos(), ms_fDeltaHeading()) {}

    // Virtual functions
    DECL_VIRTUALCALL_CONST_HEAD(CPedParkAttractor, GetType, _ZTV17CPedParkAttractor, 0, i32)
    DECL_VIRTUALCALL_TAIL()
    DECL_DTORCALL_VIRTUAL_VTABLE_SLOT(CPedParkAttractor, _ZN17CPedParkAttractor, _ZTV17CPedParkAttractor, 1);

    // STATIC values
    DECL_OBJECT_SYM(i32 const, ms_iMaxSlots, _ZN17CPedParkAttractor12ms_iMaxSlotsE);
    DECL_OBJECT_SYM(float const, ms_fSpacing, _ZN17CPedParkAttractor11ms_fSpacingE);
    DECL_OBJECT_SYM(float const, ms_fAchieveQueueTime, _ZN17CPedParkAttractor20ms_fAchieveQueueTimeE);
    DECL_OBJECT_SYM(float const, ms_fAchieveQueueShuffleTime, _ZN17CPedParkAttractor27ms_fAchieveQueueShuffleTimeE);
    DECL_OBJECT_SYM(float const, ms_fArriveRange, _ZN17CPedParkAttractor15ms_fArriveRangeE);
    DECL_OBJECT_SYM(float const, ms_fHeadingRange, _ZN17CPedParkAttractor16ms_fHeadingRangeE);
    DECL_OBJECT_SYM(float const, ms_fDeltaPos, _ZN17CPedParkAttractor12ms_fDeltaPosE);
    DECL_OBJECT_SYM(float const, ms_fDeltaHeading, _ZN17CPedParkAttractor16ms_fDeltaHeadingE);

DECL_CLASS_END()
CHECKSIZE(CPedParkAttractor, 0xb8, 0xd0);

DECL_CLASS_BASED(CPedScriptedAttractor, CPedAttractor)
    DECL_NEWCALL(CPedScriptedAttractor, BYBIT(_ZN13CPedAttractornwEj, _ZN13CPedAttractornwEm));

    // Construct/Deconstruct functions
    CPedScriptedAttractor(C2dEffect* effect, CEntity* entity, i32 const moveState) : CPedAttractor(effect, entity, moveState, ms_iMaxSlots(), ms_fSpacing(), ms_fAchieveQueueTime(), ms_fAchieveQueueShuffleTime(), ms_fArriveRange(), ms_fHeadingRange(), ms_fDeltaPos(), ms_fDeltaHeading()) {}

    // Virtual functions
    DECL_VIRTUALCALL_CONST_HEAD(CPedScriptedAttractor, GetType, _ZTV21CPedScriptedAttractor, 0, i32)
    DECL_VIRTUALCALL_TAIL()
    DECL_DTORCALL_VIRTUAL_VTABLE_SLOT(CPedScriptedAttractor, _ZN21CPedScriptedAttractor, _ZTV21CPedScriptedAttractor, 1);

    // STATIC values
    DECL_OBJECT_SYM(i32 const, ms_iMaxSlots, _ZN21CPedScriptedAttractor12ms_iMaxSlotsE);
    DECL_OBJECT_SYM(float const, ms_fSpacing, _ZN21CPedScriptedAttractor11ms_fSpacingE);
    DECL_OBJECT_SYM(float const, ms_fAchieveQueueTime, _ZN21CPedScriptedAttractor20ms_fAchieveQueueTimeE);
    DECL_OBJECT_SYM(float const, ms_fAchieveQueueShuffleTime, _ZN21CPedScriptedAttractor27ms_fAchieveQueueShuffleTimeE);
    DECL_OBJECT_SYM(float const, ms_fArriveRange, _ZN21CPedScriptedAttractor15ms_fArriveRangeE);
    DECL_OBJECT_SYM(float const, ms_fHeadingRange, _ZN21CPedScriptedAttractor16ms_fHeadingRangeE);
    DECL_OBJECT_SYM(float const, ms_fDeltaPos, _ZN21CPedScriptedAttractor12ms_fDeltaPosE);
    DECL_OBJECT_SYM(float const, ms_fDeltaHeading, _ZN21CPedScriptedAttractor16ms_fDeltaHeadingE);

DECL_CLASS_END()
CHECKSIZE(CPedScriptedAttractor, 0xb8, 0xd0);

DECL_CLASS_BASED(CPedSeatAttractor, CPedAttractor)
    DECL_NEWCALL(CPedSeatAttractor, BYBIT(_ZN13CPedAttractornwEj, _ZN13CPedAttractornwEm));

    // Construct/Deconstruct functions
    CPedSeatAttractor(C2dEffect* effect, CEntity* entity, i32 const moveState) : CPedAttractor(effect, entity, moveState, ms_iMaxSlots(), ms_fSpacing(), ms_fAchieveQueueTime(), ms_fAchieveQueueShuffleTime(), ms_fArriveRange(), ms_fHeadingRange(), ms_fDeltaPos(), ms_fDeltaHeading()) {}

    // Virtual functions
    DECL_VIRTUALCALL_CONST_HEAD(CPedSeatAttractor, GetType, _ZTV17CPedSeatAttractor, 0, i32)
    DECL_VIRTUALCALL_TAIL()
    DECL_DTORCALL_VIRTUAL_VTABLE_SLOT(CPedSeatAttractor, _ZN17CPedSeatAttractor, _ZTV17CPedSeatAttractor, 1);

    // STATIC values
    DECL_OBJECT_SYM(i32 const, ms_iMaxSlots, _ZN17CPedSeatAttractor12ms_iMaxSlotsE);
    DECL_OBJECT_SYM(float const, ms_fSpacing, _ZN17CPedSeatAttractor11ms_fSpacingE);
    DECL_OBJECT_SYM(float const, ms_fAchieveQueueTime, _ZN17CPedSeatAttractor20ms_fAchieveQueueTimeE);
    DECL_OBJECT_SYM(float const, ms_fAchieveQueueShuffleTime, _ZN17CPedSeatAttractor27ms_fAchieveQueueShuffleTimeE);
    DECL_OBJECT_SYM(float const, ms_fArriveRange, _ZN17CPedSeatAttractor15ms_fArriveRangeE);
    DECL_OBJECT_SYM(float const, ms_fHeadingRange, _ZN17CPedSeatAttractor16ms_fHeadingRangeE);
    DECL_OBJECT_SYM(float const, ms_fDeltaPos, _ZN17CPedSeatAttractor12ms_fDeltaPosE);
    DECL_OBJECT_SYM(float const, ms_fDeltaHeading, _ZN17CPedSeatAttractor16ms_fDeltaHeadingE);

DECL_CLASS_END()
CHECKSIZE(CPedSeatAttractor, 0xb8, 0xd0);

DECL_CLASS_BASED(CPedStepAttractor, CPedAttractor)
    DECL_NEWCALL(CPedStepAttractor, BYBIT(_ZN13CPedAttractornwEj, _ZN13CPedAttractornwEm));

    // Construct/Deconstruct functions
    CPedStepAttractor(C2dEffect* effect, CEntity* entity, i32 const moveState) : CPedAttractor(effect, entity, moveState, ms_iMaxSlots(), ms_fSpacing(), ms_fAchieveQueueTime(), ms_fAchieveQueueShuffleTime(), ms_fArriveRange(), ms_fHeadingRange(), ms_fDeltaPos(), ms_fDeltaHeading()) {}

    // Virtual functions
    DECL_VIRTUALCALL_CONST_HEAD(CPedStepAttractor, GetType, _ZTV17CPedStepAttractor, 0, i32)
    DECL_VIRTUALCALL_TAIL()
    DECL_DTORCALL_VIRTUAL_VTABLE_SLOT(CPedStepAttractor, _ZN17CPedStepAttractor, _ZTV17CPedStepAttractor, 1);

    // STATIC values
    DECL_OBJECT_SYM(i32 const, ms_iMaxSlots, _ZN17CPedStepAttractor12ms_iMaxSlotsE);
    DECL_OBJECT_SYM(float const, ms_fSpacing, _ZN17CPedStepAttractor11ms_fSpacingE);
    DECL_OBJECT_SYM(float const, ms_fAchieveQueueTime, _ZN17CPedStepAttractor20ms_fAchieveQueueTimeE);
    DECL_OBJECT_SYM(float const, ms_fAchieveQueueShuffleTime, _ZN17CPedStepAttractor27ms_fAchieveQueueShuffleTimeE);
    DECL_OBJECT_SYM(float const, ms_fArriveRange, _ZN17CPedStepAttractor15ms_fArriveRangeE);
    DECL_OBJECT_SYM(float const, ms_fHeadingRange, _ZN17CPedStepAttractor16ms_fHeadingRangeE);
    DECL_OBJECT_SYM(float const, ms_fDeltaPos, _ZN17CPedStepAttractor12ms_fDeltaPosE);
    DECL_OBJECT_SYM(float const, ms_fDeltaHeading, _ZN17CPedStepAttractor16ms_fDeltaHeadingE);

DECL_CLASS_END()
CHECKSIZE(CPedStepAttractor, 0xb8, 0xd0);

DECL_CLASS_BASED(CPedStopAttractor, CPedAttractor)
    DECL_NEWCALL(CPedStopAttractor, BYBIT(_ZN13CPedAttractornwEj, _ZN13CPedAttractornwEm));

    // Construct/Deconstruct functions
    CPedStopAttractor(C2dEffect* effect, CEntity* entity, i32 const moveState) : CPedAttractor(effect, entity, moveState, ms_iMaxSlots(), ms_fSpacing(), ms_fAchieveQueueTime(), ms_fAchieveQueueShuffleTime(), ms_fArriveRange(), ms_fHeadingRange(), ms_fDeltaPos(), ms_fDeltaHeading()) {}

    // Virtual functions
    DECL_VIRTUALCALL_CONST_HEAD(CPedStopAttractor, GetType, _ZTV17CPedStopAttractor, 0, i32)
    DECL_VIRTUALCALL_TAIL()
    DECL_DTORCALL_VIRTUAL_VTABLE_SLOT(CPedStopAttractor, _ZN17CPedStopAttractor, _ZTV17CPedStopAttractor, 1);

    // STATIC values
    DECL_OBJECT_SYM(i32 const, ms_iMaxSlots, _ZN17CPedStopAttractor12ms_iMaxSlotsE);
    DECL_OBJECT_SYM(float const, ms_fSpacing, _ZN17CPedStopAttractor11ms_fSpacingE);
    DECL_OBJECT_SYM(float const, ms_fAchieveQueueTime, _ZN17CPedStopAttractor20ms_fAchieveQueueTimeE);
    DECL_OBJECT_SYM(float const, ms_fAchieveQueueShuffleTime, _ZN17CPedStopAttractor27ms_fAchieveQueueShuffleTimeE);
    DECL_OBJECT_SYM(float const, ms_fArriveRange, _ZN17CPedStopAttractor15ms_fArriveRangeE);
    DECL_OBJECT_SYM(float const, ms_fHeadingRange, _ZN17CPedStopAttractor16ms_fHeadingRangeE);
    DECL_OBJECT_SYM(float const, ms_fDeltaPos, _ZN17CPedStopAttractor12ms_fDeltaPosE);
    DECL_OBJECT_SYM(float const, ms_fDeltaHeading, _ZN17CPedStopAttractor16ms_fDeltaHeadingE);

DECL_CLASS_END()
CHECKSIZE(CPedStopAttractor, 0xb8, 0xd0);

DECL_CLASS_BASED(CPedTriggerScriptAttractor, CPedAttractor)
    DECL_NEWCALL(CPedTriggerScriptAttractor, BYBIT(_ZN13CPedAttractornwEj, _ZN13CPedAttractornwEm));

    // Construct/Deconstruct functions
    CPedTriggerScriptAttractor(C2dEffect* effect, CEntity* entity, i32 const moveState) : CPedAttractor(effect, entity, moveState, ms_iMaxSlots(), ms_fSpacing(), ms_fAchieveQueueTime(), ms_fAchieveQueueShuffleTime(), ms_fArriveRange(), ms_fHeadingRange(), ms_fDeltaPos(), ms_fDeltaHeading()) {}

    // Virtual functions
    DECL_VIRTUALCALL_CONST_HEAD(CPedTriggerScriptAttractor, GetType, _ZTV26CPedTriggerScriptAttractor, 0, i32)
    DECL_VIRTUALCALL_TAIL()
    DECL_DTORCALL_VIRTUAL_VTABLE_SLOT(CPedTriggerScriptAttractor, _ZN26CPedTriggerScriptAttractor, _ZTV26CPedTriggerScriptAttractor, 1);

    // STATIC values
    DECL_OBJECT_SYM(i32 const, ms_iMaxSlots, _ZN26CPedTriggerScriptAttractor12ms_iMaxSlotsE);
    DECL_OBJECT_SYM(float const, ms_fSpacing, _ZN26CPedTriggerScriptAttractor11ms_fSpacingE);
    DECL_OBJECT_SYM(float const, ms_fAchieveQueueTime, _ZN26CPedTriggerScriptAttractor20ms_fAchieveQueueTimeE);
    DECL_OBJECT_SYM(float const, ms_fAchieveQueueShuffleTime, _ZN26CPedTriggerScriptAttractor27ms_fAchieveQueueShuffleTimeE);
    DECL_OBJECT_SYM(float const, ms_fArriveRange, _ZN26CPedTriggerScriptAttractor15ms_fArriveRangeE);
    DECL_OBJECT_SYM(float const, ms_fHeadingRange, _ZN26CPedTriggerScriptAttractor16ms_fHeadingRangeE);
    DECL_OBJECT_SYM(float const, ms_fDeltaPos, _ZN26CPedTriggerScriptAttractor12ms_fDeltaPosE);
    DECL_OBJECT_SYM(float const, ms_fDeltaHeading, _ZN26CPedTriggerScriptAttractor16ms_fDeltaHeadingE);

DECL_CLASS_END()
CHECKSIZE(CPedTriggerScriptAttractor, 0xb8, 0xd0);

DECL_FASTCALL_SIMPLE_GLO(GetPedAttractorManager, _Z22GetPedAttractorManagerv, CPedAttractorManager*);

#endif // __AML_PSDK_SAPEDATTRACTOR_H
