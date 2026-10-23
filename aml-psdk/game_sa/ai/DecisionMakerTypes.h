#ifndef __AML_PSDK_SADECISIONMAKERTYPES_H
#define __AML_PSDK_SADECISIONMAKERTYPES_H

#include "DecisionMaker.h"

struct CPed;
struct CPedGroup;

DECL_CLASS(CDecisionMakerTypes)
    // Construct/Deconstruct functions
    DECL_CTORCALL(CDecisionMakerTypes, _ZN19CDecisionMakerTypesC2Ev);

    // Member functions
    DECL_THISCALL_HEAD(AddDecisionMaker, _ZN19CDecisionMakerTypes16AddDecisionMakerERK14CDecisionMakerhhi, i32,
        CDecisionMaker const& decisionMaker, u8 type, b8 mission, i32 referenceIndex)
    DECL_THISCALL_TAIL(AddDecisionMaker, decisionMaker, type, mission, referenceIndex)
    DECL_THISCALL_HEAD(RemoveDecisionMaker, _ZN19CDecisionMakerTypes19RemoveDecisionMakerEi, void, i32 index)
    DECL_THISCALL_TAIL(RemoveDecisionMaker, index)
    DECL_THISCALL_HEAD(CopyDecisionMaker, _ZN19CDecisionMakerTypes17CopyDecisionMakerEiih, i32, i32 source, i32 destination, b8 mission)
    DECL_THISCALL_TAIL(CopyDecisionMaker, source, destination, mission)
    DECL_THISCALL_HEAD(FlushDecisionMakerEventResponse, _ZN19CDecisionMakerTypes31FlushDecisionMakerEventResponseEii, void, i32 index, i32 eventType)
    DECL_THISCALL_TAIL(FlushDecisionMakerEventResponse, index, eventType)
    DECL_THISCALL_HEAD(AddEventResponse, _ZN19CDecisionMakerTypes16AddEventResponseEiiiPfPi, void,
        i32 index, i32 eventType, i32 taskType, float* probabilities, i32* flags)
    DECL_THISCALL_TAIL(AddEventResponse, index, eventType, taskType, probabilities, flags)
    DECL_THISCALL_NAMED_HEAD(MakeDecision1, MakeDecision, _ZNK19CDecisionMakerTypes12MakeDecisionERK4CPediibiiiibRsS3_, void,
        CPed const& ped, i32 eventType, i32 sourceType, bool inVehicle, i32 rejectTask1, i32 rejectTask2, i32 rejectTask3, i32 seekTask, bool groupDecision, i16& taskType, i16& facialTaskType)
    DECL_THISCALL_TAIL(MakeDecision1, ped, eventType, sourceType, inVehicle, rejectTask1, rejectTask2, rejectTask3, seekTask, groupDecision, taskType, facialTaskType)
    DECL_THISCALL_NAMED_HEAD(MakeDecision2, MakeDecision, _ZNK19CDecisionMakerTypes12MakeDecisionERK9CPedGroupiibiiii, i32,
        CPedGroup const& group, i32 eventType, i32 sourceType, bool inVehicle, i32 rejectTask1, i32 rejectTask2, i32 rejectTask3, i32 seekTask)
    DECL_THISCALL_TAIL(MakeDecision2, group, eventType, sourceType, inVehicle, rejectTask1, rejectTask2, rejectTask3, seekTask)
    DECL_THISCALL_HEAD(HasResponse, _ZNK19CDecisionMakerTypes11HasResponseERK4CPedPKii, bool, CPed const& ped, i32 const* eventTypes, i32 numEvents)
    DECL_THISCALL_TAIL(HasResponse, ped, eventTypes, numEvents)
    DECL_THISCALL_NAMED_HEAD(LoadEventIndices1, LoadEventIndices, _ZN19CDecisionMakerTypes16LoadEventIndicesEv, void)
    DECL_THISCALL_TAIL(LoadEventIndices1)
    DECL_THISCALL_NAMED_HEAD(LoadEventIndices2, LoadEventIndices, _ZN19CDecisionMakerTypes16LoadEventIndicesEPiPKc, void, i32* indices, char const* filename)
    DECL_THISCALL_TAIL(LoadEventIndices2, indices, filename)

    // STATIC functions
    DECL_FASTCALL_SIMPLE(Save, _ZN19CDecisionMakerTypes4SaveEv, void);
    DECL_FASTCALL_SIMPLE(Load, _ZN19CDecisionMakerTypes4LoadEv, void);

    // STATIC values
    DECL_OBJECT_ARRAY_PLT(bool, m_bIsActive, BYBIT(0x6793D8, 0x8507C8));
    DECL_OBJECT_ARRAY_PLT(u16, ScriptReferenceIndex, BYBIT(0x676C00, 0x84B848));
    DECL_OBJECT_ARRAY_PLT(u8, m_types, BYBIT(0x679438, 0x850888));
    DECL_OBJECT_PLT(CDecisionMakerTypes*, m_pPedDecisionTypes, BYBIT(0x6798D8, 0x8511D0));

    // Member values
    i32 m_iNoOfDecisionMakers;
    CDecisionMaker m_decisionMakers[20];
    i32 m_eventIndices[96];
    CDecisionMaker m_defaultRandomPedDecisionMaker;
    CDecisionMaker m_defaultMissionPedDecisionMaker;
    CDecisionMaker m_defaultPlayerPedDecisionMaker;
    CDecisionMaker m_defaultRandomPedGroupDecisionMaker;
    CDecisionMaker m_defaultMissionPedGroupDecisionMaker;
DECL_CLASS_END()
CHECKSIZE(CDecisionMakerTypes, 0xF1C0, 0xF1C0);

DECL_CLASS(CDecisionMakerTypesFileLoader)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(LoadDefaultDecisionMaker, _ZN29CDecisionMakerTypesFileLoader24LoadDefaultDecisionMakerEv, void);
    DECL_FASTCALL_SIMPLE(LoadDecisionMaker1, _ZN29CDecisionMakerTypesFileLoader17LoadDecisionMakerEPKchhi, i32, char const* filename, u8 type, b8 mission, i32 referenceIndex);
    DECL_FASTCALL_SIMPLE(LoadDecisionMaker2, _ZN29CDecisionMakerTypesFileLoader17LoadDecisionMakerEPKcR14CDecisionMaker, bool, char const* filename, CDecisionMaker& decisionMaker);
    DECL_FASTCALL_SIMPLE(UnloadDecisionMaker, _ZN29CDecisionMakerTypesFileLoader19UnloadDecisionMakerEi, void, i32 index);
    DECL_FASTCALL_SIMPLE(ReStart, _ZN29CDecisionMakerTypesFileLoader7ReStartEv, void);
    DECL_FASTCALL_SIMPLE(GetPedDMName, _ZN29CDecisionMakerTypesFileLoader12GetPedDMNameEiPc, void, i32 index, char* name);
    DECL_FASTCALL_SIMPLE(GetGrpDMName, _ZN29CDecisionMakerTypesFileLoader12GetGrpDMNameEiPc, void, i32 index, char* name);

    static inline i32 LoadDecisionMaker(char const* filename, u8 type, b8 mission, i32 referenceIndex)
    {
        return LoadDecisionMaker1(filename, type, mission, referenceIndex);
    }
    static inline bool LoadDecisionMaker(char const* filename, CDecisionMaker& decisionMaker)
    {
        return LoadDecisionMaker2(filename, decisionMaker);
    }

    // STATIC values
    DECL_OBJECT_ARRAY_PLT(char*, ms_ped_DM_Names, BYBIT(0x6788F4, 0x84F208));
    DECL_OBJECT_ARRAY_PLT(char*, ms_grp_DM_Names, BYBIT(0x676274, 0x84A548));
DECL_CLASS_END()

#define ScriptReferenceIndex ScriptReferenceIndex()
#define m_pPedDecisionTypes m_pPedDecisionTypes()
#define ms_ped_DM_Names ms_ped_DM_Names()
#define ms_grp_DM_Names ms_grp_DM_Names()

#endif // __AML_PSDK_SADECISIONMAKERTYPES_H
