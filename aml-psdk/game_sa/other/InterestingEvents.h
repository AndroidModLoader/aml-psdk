#ifndef __AML_PSDK_SAINTERESTINGEVENTS_H
#define __AML_PSDK_SAINTERESTINGEVENTS_H

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/gta_base/Vector.h>

struct CEntity;

DECL_CLASS(TInterestingEvent)
    // Member values
    u32 m_eType;
    u32 m_iStartTime;
    CEntity* m_pEntity;
DECL_CLASS_END()
CHECKSIZE(TInterestingEvent, 0xC, 0x10);

DECL_CLASS(CInterestingEvents)
    enum EType
    {
        ENone = 0,
        EPedsChatting = 1,
        EPedSunbathing = 2,
        EPedUsingAttractor = 3,
        EProzzyNearby = 4,
        ECopNearby = 5,
        ECriminalNearby = 6,
        EGangMemberNearby = 7,
        ESexyCar = 8,
        ESexyPed = 9,
        EPlaneFlyby = 10,
        EPedRevived = 11,
        EEmergencyServicesArrived = 12,
        EPanickedPed = 13,
        EMadDriver = 14,
        EPedRunOver = 15,
        EPedKnockedOffBike = 16,
        ECarCrash = 17,
        ERoadRage = 18,
        EFistFight = 19,
        ECarJacking = 20,
        EHelicopterOverhead = 21,
        EGunshotFired = 22,
        EGangAttackingPed = 23,
        EGangFight = 24,
        ECopKillingCriminal = 25,
        ESwatTeamAbseiling = 26,
        EExplosion = 27,
        EPedGotKilled = 28,
        ENumCategories = 29
    };

    // Construct/Deconstruct functions
    DECL_CTORCALL(CInterestingEvents, _ZN18CInterestingEventsC2Ev);
    DECL_DTORCALL(CInterestingEvents, _ZN18CInterestingEventsD2Ev);

    // Member functions
    DECL_THISCALL_SIMPLE(ScanForNearbyEntities, _ZN18CInterestingEvents21ScanForNearbyEntitiesEv, void);
    DECL_THISCALL_SIMPLE(GetInterestingEvent, _ZN18CInterestingEvents19GetInterestingEventEv, TInterestingEvent const*);
    DECL_THISCALL_HEAD(InvalidateEvent, _ZN18CInterestingEvents15InvalidateEventEPK17TInterestingEvent, void, TInterestingEvent const* event)
    DECL_THISCALL_TAIL(InvalidateEvent, event)
    DECL_THISCALL_SIMPLE(InvalidateNonVisibleEvents, _ZN18CInterestingEvents26InvalidateNonVisibleEventsEv, void);
    DECL_THISCALL_HEAD(Add, _ZN18CInterestingEvents3AddENS_5ETypeEP7CEntity, void, EType type, CEntity* entity)
    DECL_THISCALL_TAIL(Add, type, entity)

    // STATIC values
    DECL_OBJECT_SYM(u32 const, ms_iScanFrequency, _ZN18CInterestingEvents17ms_iScanFrequencyE);

    // Member values
    TInterestingEvent m_Events[8];
    u8 m_EventPriorities[29];
    u16 m_EventDurations[29];
    u32 m_NextTimeToAcceptEvents[29];
    u8 m_bIsActive : 1;
    u8 m_bIgnoreEventsBehindPlayer : 1;
    u8 m_bWaitForEventDurationToComplete : 1;
    u8 m_bUseTimeDelayBeforeAddingSimilarEvent : 1;
    u32 m_iCurrentFrameCounter;
    u32 m_iLastScanTime;
    float m_fEventRadius;
    CVector m_ScanOrigin;
    CVector m_ViewVec;
    i8 m_iLookingAtEvent;
DECL_CLASS_END()
CHECKSIZE(CInterestingEvents, 0x158, 0x178);

DECL_OBJECT_PLT_GLOBAL(CInterestingEvents, g_InterestingEvents, BYBIT(0x6768cc, 0x84b1f0));


#endif // __AML_PSDK_SAINTERESTINGEVENTS_H
