#ifndef __AML_PSDK_SAWANTED_H
#define __AML_PSDK_SAWANTED_H

#include "../plugin.h"
#include "../audio/AEAudioEntity.h"

struct CCopPed;

enum eWantedLevel
{
    WANTED_CLEAN = 0,
    WANTED_LEVEL1 = 1,
    WANTED_LEVEL2 = 2,
    WANTED_LEVEL3 = 3,
    WANTED_LEVEL4 = 4,
    WANTED_LEVEL5 = 5,
    WANTED_LEVEL6 = 6,
};

struct CCrimeBeingQd
{
    eCrimeType m_nCrimeType;
    uptr m_nCrimeId;
    u32 m_nStartTime;
    CVector m_vecCoors;
    bool m_bAlreadyReported;
    bool m_bPoliceDontReallyCare;
};
CHECKSIZE(CCrimeBeingQd, 0x1C, 0x28);

DECL_CLASS(CWanted)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(InitialiseStaticVariables, _ZN7CWanted25InitialiseStaticVariablesEv, void);
    DECL_FASTCALL_SIMPLE(SetMaximumWantedLevel, _ZN7CWanted21SetMaximumWantedLevelEi, void, i32 NewMaxLev);
    DECL_FASTCALL_SIMPLE(WorkOutPolicePresence, _ZN7CWanted21WorkOutPolicePresenceE7CVectorf, i32, CVector Coors, float Radius);
    DECL_FASTCALL_SIMPLE(UpdateEachFrame, _ZN7CWanted15UpdateEachFrameEv, void);
    DECL_FASTCALL_SIMPLE(CanCopJoinPursuit1, _ZN7CWanted17CanCopJoinPursuitEP7CCopPedhPS1_Rh, bool, CCopPed* cop, u8 const count, CCopPed** cops, u8& numCops);
    inline static bool CanCopJoinPursuit(CCopPed* cop, u8 count, CCopPed** cops, u8& numCops) { return CanCopJoinPursuit1(cop, count, cops, numCops); }
    DECL_FASTCALL_SIMPLE(ComputePursuitCopToDisplace, _ZN7CWanted27ComputePursuitCopToDisplaceEP7CCopPedPS1_, CCopPed*, CCopPed* pCopPed, CCopPed** ppCopsInPursuit);
    DECL_FASTCALL_SIMPLE(RemovePursuitCop1, _ZN7CWanted16RemovePursuitCopEP7CCopPedPS1_Rh, void, CCopPed* cop, CCopPed** cops, u8& numCops);
    inline static void RemovePursuitCop(CCopPed* cop, CCopPed** cops, u8& numCops) { RemovePursuitCop1(cop, cops, numCops); }

    // STATIC values
    DECL_OBJECT_PLT(eWantedLevel, MaximumWantedLevel, BYBIT(0x679880, 0x851118));
    DECL_VALUE_PLT_I32(nMaximumWantedLevel, BYBIT(0x6772C4, 0x84C5C0));
    DECL_VALUE_PLT_BOOL(bUseNewsHeliInAdditionToPolice, BYBIT(0x679B10, 0x851640));

    // Member functions
    DECL_THISCALL_SIMPLE(Initialise, _ZN7CWanted10InitialiseEv, void);
    DECL_THISCALL_SIMPLE(Reset, _ZN7CWanted5ResetEv, void);
    DECL_THISCALL_SIMPLE(Update, _ZN7CWanted6UpdateEv, void);
    DECL_THISCALL_SIMPLE(UpdateWantedLevel, _ZN7CWanted17UpdateWantedLevelEv, void);
    DECL_THISCALL_HEAD(RegisterCrime, BYBIT(_ZN7CWanted13RegisterCrimeE10eCrimeTypeRK7CVectorjb, _ZN7CWanted13RegisterCrimeE10eCrimeTypeRK7CVectoryb), void, eCrimeType CrimeType, CVector const& Pos, uptr IDKey, bool bPoliceDontReallyCare)
    DECL_THISCALL_TAIL(RegisterCrime, CrimeType, Pos, IDKey, bPoliceDontReallyCare)
    DECL_THISCALL_HEAD(RegisterCrime_Immediately, BYBIT(_ZN7CWanted25RegisterCrime_ImmediatelyE10eCrimeTypeRK7CVectorjb, _ZN7CWanted25RegisterCrime_ImmediatelyE10eCrimeTypeRK7CVectoryb), void, eCrimeType CrimeType, CVector const& Pos, uptr IDKey, bool bPoliceDontReallyCare)
    DECL_THISCALL_TAIL(RegisterCrime_Immediately, CrimeType, Pos, IDKey, bPoliceDontReallyCare)
    DECL_THISCALL_HEAD(SetWantedLevel, _ZN7CWanted14SetWantedLevelEi, void, i32 NewLev)
    DECL_THISCALL_TAIL(SetWantedLevel, NewLev)
    DECL_THISCALL_HEAD(CheatWantedLevel, _ZN7CWanted16CheatWantedLevelEi, void, i32 NewLev)
    DECL_THISCALL_TAIL(CheatWantedLevel, NewLev)
    DECL_THISCALL_HEAD(SetWantedLevelNoDrop, _ZN7CWanted20SetWantedLevelNoDropEi, void, i32 NewLev)
    DECL_THISCALL_TAIL(SetWantedLevelNoDrop, NewLev)
    DECL_THISCALL_SIMPLE(ClearWantedLevelAndGoOnParole, _ZN7CWanted29ClearWantedLevelAndGoOnParoleEv, void);
    DECL_THISCALL_SIMPLE(AreMiamiViceRequired, _ZN7CWanted20AreMiamiViceRequiredEv, bool);
    DECL_THISCALL_SIMPLE(AreSwatRequired, _ZN7CWanted15AreSwatRequiredEv, bool);
    DECL_THISCALL_SIMPLE(AreFbiRequired, _ZN7CWanted14AreFbiRequiredEv, bool);
    DECL_THISCALL_SIMPLE(AreArmyRequired, _ZN7CWanted15AreArmyRequiredEv, bool);
    DECL_THISCALL_SIMPLE(NumOfHelisRequired, _ZN7CWanted18NumOfHelisRequiredEv, i32);
    DECL_THISCALL_SIMPLE(ResetPolicePursuit, _ZN7CWanted18ResetPolicePursuitEv, void);
    DECL_THISCALL_SIMPLE(ClearQdCrimes, _ZN7CWanted13ClearQdCrimesEv, void);
    DECL_THISCALL_HEAD(AddCrimeToQ, BYBIT(_ZN7CWanted11AddCrimeToQE10eCrimeTypejRK7CVectorbb, _ZN7CWanted11AddCrimeToQE10eCrimeTypeyRK7CVectorbb), bool, eCrimeType ArgCrimeType, uptr ArgCrimeID, CVector const& Coors, bool bArgAlreadyReported, bool bArgPoliceDontReallyCare)
    DECL_THISCALL_TAIL(AddCrimeToQ, ArgCrimeType, ArgCrimeID, Coors, bArgAlreadyReported, bArgPoliceDontReallyCare)
    DECL_THISCALL_SIMPLE(UpdateCrimesQ, _ZN7CWanted13UpdateCrimesQEv, void);
    DECL_THISCALL_HEAD(ReportCrimeNow, _ZN7CWanted14ReportCrimeNowE10eCrimeTypeRK7CVectorb, void, eCrimeType CrimeType, CVector const& Coors, bool bPoliceDontReallyCare)
    DECL_THISCALL_TAIL(ReportCrimeNow, CrimeType, Coors, bPoliceDontReallyCare)
    DECL_THISCALL_HEAD(CanCopJoinPursuit, _ZNK7CWanted17CanCopJoinPursuitEP7CCopPed, bool, CCopPed* pCopPed)
    DECL_THISCALL_TAIL(CanCopJoinPursuit, pCopPed)
    DECL_THISCALL_HEAD(SetPursuitCop, _ZN7CWanted13SetPursuitCopEP7CCopPed, bool, CCopPed* pCopPed)
    DECL_THISCALL_TAIL(SetPursuitCop, pCopPed)
    DECL_THISCALL_HEAD(RemovePursuitCop, _ZN7CWanted16RemovePursuitCopEP7CCopPed, void, CCopPed* pCopPed)
    DECL_THISCALL_TAIL(RemovePursuitCop, pCopPed)
    DECL_THISCALL_HEAD(IsInPursuit, _ZN7CWanted11IsInPursuitEP7CCopPed, bool, CCopPed* pCopPed)
    DECL_THISCALL_TAIL(IsInPursuit, pCopPed)
    DECL_THISCALL_SIMPLE(RemoveExcessPursuitCops, _ZN7CWanted23RemoveExcessPursuitCopsEv, void);
    DECL_THISCALL_HEAD(IsClosestCop, _ZNK7CWanted12IsClosestCopEP4CPedi, bool, CPed* pPed, int const iClosest)
    DECL_THISCALL_TAIL(IsClosestCop, pPed, iClosest)

    // Helper functions
    inline eWantedLevel GetWantedLevel() { return m_nWantedLevel; }

    // Member values
    i32 m_nChaosLevel;
    i32 m_nChaosLevelBeforeParole;
    u32 m_LastTimeWantedDecreased;
    u32 m_LastTimeWantedLevelChanged;
    u32 m_TimeOfParole;
    float m_fMultiplier;
    u8 m_nCopsInPursuit;
    u8 m_nMaxCopsInPursuit;
    u8 m_nMaxCopCarsInPursuit;
    u8 m_nCopsBeatingSuspect;
    u16 m_nChanceOnRoadBlock;
    u8 m_PoliceBackOff : 1;
    u8 m_PoliceBackOffGarage : 1;
    u8 m_EverybodyBackOff : 1;
    u8 m_swatRequired : 1;
    u8 m_fbiRequired : 1;
    u8 m_armyRequired : 1;
    u32 current_chase_time;
    u32 current_chase_time_counter;
    u8 m_bTimeCounting;
    eWantedLevel m_nWantedLevel;
    eWantedLevel m_nWantedLevelBeforeParole;
    CCrimeBeingQd CrimesBeingQd[16];
    CCopPed* m_pCopsInPursuit[10];
    CAEPoliceScannerAudioEntity m_PoliceScannerAudioEntity;
    bool m_bStoredPoliceBackOff;
DECL_CLASS_END()
CHECKSIZE(CWanted, 0x29C, 0x3A0);

#endif // __AML_PSDK_SAWANTED_H
