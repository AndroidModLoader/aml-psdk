#ifndef __AML_PSDK_VCPEDSTATS_H
#define __AML_PSDK_VCPEDSTATS_H

#include <aml-psdk/game_vc/plugin.h>

enum ePersonalityType : u32
{
    PERSONALITY_PLAYER = 0,
    PERSONALITY_COP = 1,
    PERSONALITY_MEDIC = 2,
    PERSONALITY_FIREMAN = 3,
    PERSONALITY_GANG1 = 4,
    PERSONALITY_GANG2 = 5,
    PERSONALITY_GANG3 = 6,
    PERSONALITY_GANG4 = 7,
    PERSONALITY_GANG5 = 8,
    PERSONALITY_GANG6 = 9,
    PERSONALITY_GANG7 = 10,
    PERSONALITY_STREET_GUY = 11,
    PERSONALITY_SUIT_GUY = 12,
    PERSONALITY_SENSIBLE_GUY = 13,
    PERSONALITY_GEEK_GUY = 14,
    PERSONALITY_OLD_GUY = 15,
    PERSONALITY_TOUGH_GUY = 16,
    PERSONALITY_STREET_GIRL = 17,
    PERSONALITY_SUIT_GIRL = 18,
    PERSONALITY_SENSIBLE_GIRL = 19,
    PERSONALITY_GEEK_GIRL = 20,
    PERSONALITY_OLD_GIRL = 21,
    PERSONALITY_TOUGH_GIRL = 22,
    PERSONALITY_TRAMP_MALE = 23,
    PERSONALITY_TRAMP_FEMALE = 24,
    PERSONALITY_TOURIST = 25,
    PERSONALITY_PROSTITUTE = 26,
    PERSONALITY_CRIMINAL = 27,
    PERSONALITY_BUSKER = 28,
    PERSONALITY_TAXIDRIVER = 29,
    PERSONALITY_PSYCHO = 30,
    PERSONALITY_STEWARD = 31,
    PERSONALITY_SPORTSFAN = 32,
    PERSONALITY_SHOPPER = 33,
    PERSONALITY_OLDSHOPPER = 34,
    PERSONALITY_BEACH_GUY = 35,
    PERSONALITY_BEACH_GIRL = 36,
    PERSONALITY_SKATER = 37,
    PERSONALITY_STD_MISSION = 38,
    PERSONALITY_COWARD = 39
};

DECL_CLASS(CPedStats)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(Initialise, _ZN9CPedStats10InitialiseEv, void);
    DECL_FASTCALL_SIMPLE(Shutdown, _ZN9CPedStats8ShutdownEv, void);
    DECL_FASTCALL_SIMPLE(LoadPedStats, _ZN9CPedStats12LoadPedStatsEv, void);
    DECL_FASTCALL_SIMPLE(GetPedStatType, _ZN9CPedStats14GetPedStatTypeEPc, ePersonalityType, char* name);
    DECL_FASTCALL_SIMPLE(GetPedStatInfo, _ZN9CPedStats14GetPedStatInfoEPc, CPedStats*, char* name);

    // STATIC values
    DECL_OBJECT_ARRAY_PLT(CPedStats*, ms_apPedStats, BYBIT(0x396534, 0x57AA58));

    // Member values
    ePersonalityType m_Personality;
    char m_aszName[24];
    float m_fFleeDistance;
    float m_fHeadingChangeRate;
    u8 m_nFear;
    u8 m_nTemper;
    u8 m_nLawfullness;
    u8 m_nSexiness;
    float m_fAttackStrength;
    float m_fDefendWeakness;
    union
    {
        u16 m_nFlags;
        struct
        {
            u16 bPunchOnly : 1;
            u16 bCanKneeHead : 1;
            u16 bCanKick : 1;
            u16 bCanRoundHse : 1;
            u16 bNoDive : 1;
            u16 b1HitKnockdown : 1;
            u16 bShoppingBags : 1;
            u16 bGunPanic : 1;
            u16 : 8;
        };
    };
DECL_CLASS_END()
CHECKSIZE(CPedStats, 0x34, 0x34);

#define ms_apPedStats ms_apPedStats()

#endif // __AML_PSDK_VCPEDSTATS_H
