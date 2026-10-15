#ifndef __AML_PSDK_SAPEDSTATS_H
#define __AML_PSDK_SAPEDSTATS_H

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/game_sa/enum/PedEnums.h>

DECL_CLASS(CPedStats)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(Initialise, _ZN9CPedStats10InitialiseEv, void);
    DECL_FASTCALL_SIMPLE(Shutdown, _ZN9CPedStats8ShutdownEv, void);
    DECL_FASTCALL_SIMPLE(LoadPedStats, _ZN9CPedStats12LoadPedStatsEv, void);
    DECL_FASTCALL_SIMPLE(GetPedStatInfo1, _ZN9CPedStats14GetPedStatInfoEPc, CPedStats*, char* pString);
    inline static CPedStats* GetPedStatInfo(char* pString) { return GetPedStatInfo1(pString); }
    inline static CPedStats* GetPedStatInfo(i32 nStatType) { return &ms_apPedStats()[nStatType]; }
    DECL_FASTCALL_SIMPLE(GetPedStatType, _ZN9CPedStats14GetPedStatTypeEPc, ePedStats, char* pString);
    DECL_FASTCALL_SIMPLE(FindIndexWithPedStat, _ZN9CPedStats20FindIndexWithPedStatEPS_, i32, CPedStats* pTestPointer);

    // STATIC values
    DECL_OBJECT_PLT(CPedStats*, ms_apPedStats, BYBIT(0x678EC0, 0x84FDA8));

    // Member values
    ePedStats m_ePedStatType;
    char m_sPedStatName[24];
    float m_fFleeDistance;
    float m_fMaxHeadingChange;
    i8 m_nFear;
    i8 m_nTemper;
    i8 m_nLawfulness;
    i8 m_nSexiness;
    float m_fAttackMult;
    float m_fDefendMult;
    u16 m_nStatFlags;
    i8 m_iDefaultDecisionMaker;
DECL_CLASS_END()
CHECKSIZE(CPedStats, 0x34, 0x34);

#endif // __AML_PSDK_SAPEDSTATS_H
