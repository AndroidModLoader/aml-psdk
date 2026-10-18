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

    // Virtual functions
    DECL_VIRTUALCALL_CONST_HEAD(CPedPizzaAttractor, GetType, _ZTV18CPedPizzaAttractor, 0, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CPedPizzaAttractor, GetHeadOfQueueWaitTime, _ZTV18CPedPizzaAttractor, 7, float)
    DECL_VIRTUALCALL_TAIL()

    // Member functions
    DECL_THISCALL_SIMPLE(Delete, _ZN18CPedPizzaAttractorD0Ev, void);
DECL_CLASS_END()
CHECKSIZE(CPedPizzaAttractor, 0xB8, 0xD0);

DECL_CLASS_BASED(CPedShelterAttractor, CPedAttractor)
    DECL_NEWCALL(CPedShelterAttractor, BYBIT(_ZN13CPedAttractornwEj, _ZN13CPedAttractornwEm));

    // Virtual functions
    DECL_VIRTUALCALL_CONST_HEAD(CPedShelterAttractor, GetType, _ZTV20CPedShelterAttractor, 0, int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CPedShelterAttractor, IsAtHeadOfQueue, _ZTV20CPedShelterAttractor, 3, bool, CPed* pPed)
    DECL_VIRTUALCALL_TAIL(pPed)
    DECL_VIRTUALCALL_CONST_HEAD(CPedShelterAttractor, ComputeAttractPos, _ZTV20CPedShelterAttractor, 4, void, int const slot, CVector& pos)
    DECL_VIRTUALCALL_TAIL(slot, pos)
    DECL_VIRTUALCALL_CONST_HEAD(CPedShelterAttractor, ComputeAttractHeading, _ZTV20CPedShelterAttractor, 5, void, int const slot, float& heading)
    DECL_VIRTUALCALL_TAIL(slot, heading)
    DECL_VIRTUALCALL_HEAD(CPedShelterAttractor, BroadcastDeparture, _ZTV20CPedShelterAttractor, 6, bool, CPed* pPed)
    DECL_VIRTUALCALL_TAIL(pPed)

    // Member functions
    DECL_THISCALL_SIMPLE(Delete, _ZN20CPedShelterAttractorD0Ev, void);
    DECL_FASTCALL_SIMPLE(GetDisplacement, _ZN20CPedShelterAttractor15GetDisplacementEi, CVector const&, int const iSlot);

    // STATIC values
    DECL_OBJECT_PLT(SArray<CVector>, ms_displacements, BYBIT(0x678170, 0x84E2F8));
DECL_CLASS_END()
CHECKSIZE(CPedShelterAttractor, 0xB8, 0xD0);

DECL_FASTCALL_SIMPLE_GLO(GetPedAttractorManager, _Z22GetPedAttractorManagerv, CPedAttractorManager*);

#endif // __AML_PSDK_SAPEDATTRACTOR_H
