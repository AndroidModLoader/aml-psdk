#ifndef __AML_PSDK_SADECISIONMAKER_H
#define __AML_PSDK_SADECISIONMAKER_H

#include "../plugin.h"
#include "../enum/TaskType.h"

DECL_CLASS(CDecision)
    // Construct/Deconstruct functions
    DECL_CTORCALL(CDecision, _ZN9CDecisionC2Ev);
    // Member functions
    DECL_THISCALL_NAMED_HEAD(Assign, operator=, _ZN9CDecisionaSERKS_, CDecision&, CDecision const& src)
    DECL_THISCALL_TAIL(Assign, src)
    DECL_THISCALL_HEAD(Set, _ZN9CDecision3SetEPiPA4_fPA2_iPA6_f, void, int* pTasks, float (*probs)[4], int (*bools)[2], float (*facialProbs)[6])
    DECL_THISCALL_TAIL(Set, pTasks, probs, bools, facialProbs)
    DECL_THISCALL_HEAD(Add, _ZN9CDecision3AddEiPfPi, void, int const iTaskType, float* pProbs, int* pBools)
    DECL_THISCALL_TAIL(Add, iTaskType, pProbs, pBools)
    DECL_THISCALL_SIMPLE(SetDefault, _ZN9CDecision10SetDefaultEv, void);
    DECL_THISCALL_SIMPLE(HasResponse, _ZNK9CDecision11HasResponseEv, bool);
    DECL_THISCALL_HEAD(MakeDecision, _ZNK9CDecision12MakeDecisionEibiiiiRsS0_, void, int const iEventSourceType, bool const bInVehicle, int const iTaskTypeToReject1, int const iTaskTypeToReject2, int const iTaskTypeToReject3, int const iTaskTypeToSeek, i16& iTask, i16& iFacialTask)
    DECL_THISCALL_TAIL(MakeDecision, iEventSourceType, bInVehicle, iTaskTypeToReject1, iTaskTypeToReject2, iTaskTypeToReject3, iTaskTypeToSeek, iTask, iFacialTask)

    // Member values
    eTaskType m_tasks[6];
    u8 m_probs[6][4];
    bool m_bools[6][2];
DECL_CLASS_END()
CHECKSIZE(CDecision, 0x3C, 0x3C);

DECL_CLASS(CDecisionMaker)
    // Construct/Deconstruct functions
    DECL_CTORCALL(CDecisionMaker, _ZN14CDecisionMakerC2Ev);

    // Member values
    CDecision m_decisions[41];
DECL_CLASS_END()
CHECKSIZE(CDecisionMaker, 0x99C, 0x99C);

DECL_CLASS(CDecisionSimple)
    // Member functions
    DECL_THISCALL_HEAD(Set, _ZN15CDecisionSimple3SetEPiPhi, void, int* pTasks, u8* pProbs, int const iSize)
    DECL_THISCALL_TAIL(Set, pTasks, pProbs, iSize)
    DECL_THISCALL_SIMPLE(SetDefault, _ZN15CDecisionSimple10SetDefaultEv, void);
    DECL_THISCALL_HEAD(MakeDecision, _ZNK15CDecisionSimple12MakeDecisionEiRsRi, void, int const iTaskTypeToSeek, i16& iTaskType, int& index)
    DECL_THISCALL_TAIL(MakeDecision, iTaskTypeToSeek, iTaskType, index)

    // Member values
    eTaskType m_tasks[6];
    float m_probs[6];
    int m_iSize;
DECL_CLASS_END()
CHECKSIZE(CDecisionSimple, 0x34, 0x34);

#endif // __AML_PSDK_SADECISIONMAKER_H
