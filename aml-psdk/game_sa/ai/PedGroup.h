#ifndef __AML_PSDK_SAPEDGROUP_H
#define __AML_PSDK_SAPEDGROUP_H

#include "tasks/Task.h"
#include "../base/Lists.h"

struct CPed;
struct CPedGroup;
struct CEvent;
struct CEventGroupEvent;
struct CPedGroupDefaultTaskAllocator;
struct CTaskAllocator;
struct CObject;
struct CVehicle;

DECL_CLASS(CPedTaskPair)
    // Member functions
    DECL_THISCALL_SIMPLE(Flush, _ZN12CPedTaskPair5FlushEv, void);

    // Member values
    CPed* m_pPed;
    CTask* m_pTask;
    int m_iSlot;
    int m_matchID;
    bool m_bUsedTask;
DECL_CLASS_END()
CHECKSIZE(CPedTaskPair, 0x14, 0x20);

DECL_CLASS(CPedGroupMembership)
    // Construct/Deconstruct functions
    DECL_CTORCALL_NAMED_ARG_HEAD(CPedGroupMembership1, CPedGroupMembership, _ZN19CPedGroupMembershipC2ERKS_, CPedGroupMembership const& src)
    DECL_CTORCALL_ARG_TAIL(src)
    DECL_CTORCALL(CPedGroupMembership, _ZN19CPedGroupMembershipC2Ev);
    DECL_DTORCALL(CPedGroupMembership, _ZN19CPedGroupMembershipD2Ev);

    // STATIC functions
    DECL_FASTCALL_SIMPLE(GetObjectForPedToHold, _ZN19CPedGroupMembership21GetObjectForPedToHoldEv, i32);

    // STATIC values
    DECL_OBJECT_PLT(float const, ms_fPlayerGroupMaxSeparation, BYBIT(0x678D1C, 0x84FA60));

    // Member functions
    DECL_THISCALL_SIMPLE(Flush, _ZN19CPedGroupMembership5FlushEv, void);
    DECL_THISCALL_HEAD(From, _ZN19CPedGroupMembership4FromERKS_, void, CPedGroupMembership const& src)
    DECL_THISCALL_TAIL(From, src)
    DECL_THISCALL_HEAD(RemoveAllFollowers, _ZN19CPedGroupMembership18RemoveAllFollowersEb, void, bool bLeaveMissionPeds)
    DECL_THISCALL_TAIL(RemoveAllFollowers, bLeaveMissionPeds)
    DECL_THISCALL_HEAD(RemoveNFollowers, _ZN19CPedGroupMembership16RemoveNFollowersEi, void, i32 N)
    DECL_THISCALL_TAIL(RemoveNFollowers, N)
    DECL_THISCALL_HEAD(SetLeader, _ZN19CPedGroupMembership9SetLeaderEP4CPed, void, CPed* pLeader)
    DECL_THISCALL_TAIL(SetLeader, pLeader)
    DECL_THISCALL_HEAD(AddFollower, _ZN19CPedGroupMembership11AddFollowerEP4CPed, void, CPed* pFollower)
    DECL_THISCALL_TAIL(AddFollower, pFollower)
    DECL_THISCALL_NAMED_HEAD(RemoveMember1, RemoveMember, _ZN19CPedGroupMembership12RemoveMemberEP4CPed, void, CPed* arg1)
    DECL_THISCALL_TAIL(RemoveMember1, arg1)
    DECL_THISCALL_SIMPLE(GetLeader, _ZNK19CPedGroupMembership9GetLeaderEv, CPed*);
    DECL_THISCALL_HEAD(GetMember, _ZNK19CPedGroupMembership9GetMemberEi, CPed*, int const i)
    DECL_THISCALL_TAIL(GetMember, i)
    DECL_THISCALL_HEAD(IsLeader, _ZNK19CPedGroupMembership8IsLeaderEPK4CPed, bool, CPed const* pLeader)
    DECL_THISCALL_TAIL(IsLeader, pLeader)
    DECL_THISCALL_HEAD(IsFollower, _ZNK19CPedGroupMembership10IsFollowerEPK4CPed, bool, CPed const* pFollower)
    DECL_THISCALL_TAIL(IsFollower, pFollower)
    DECL_THISCALL_HEAD(IsMember, _ZNK19CPedGroupMembership8IsMemberEPK4CPed, bool, CPed const* pMember)
    DECL_THISCALL_TAIL(IsMember, pMember)
    DECL_THISCALL_SIMPLE(CountMembers, _ZNK19CPedGroupMembership12CountMembersEv, int);
    DECL_THISCALL_SIMPLE(CountMembersExcludingLeader, _ZNK19CPedGroupMembership27CountMembersExcludingLeaderEv, int);
    DECL_THISCALL_SIMPLE(Process, _ZN19CPedGroupMembership7ProcessEv, void);
    DECL_THISCALL_SIMPLE(AppointNewLeader, _ZN19CPedGroupMembership16AppointNewLeaderEv, void);
    DECL_THISCALL_HEAD(AddMember, _ZN19CPedGroupMembership9AddMemberEP4CPedi, void, CPed* pPed, int const iSlot)
    DECL_THISCALL_TAIL(AddMember, pPed, iSlot)
    DECL_THISCALL_NAMED_HEAD(RemoveMember2, RemoveMember, _ZN19CPedGroupMembership12RemoveMemberEi, void, int const iSlot)
    DECL_THISCALL_TAIL(RemoveMember2, iSlot)

    // Member values
    CPedGroup* m_pPedGroup;
    CPed* m_pMembers[8];
    float m_fMaxSeparation;
DECL_CLASS_END()
CHECKSIZE(CPedGroupMembership, 0x28, 0x50);

DECL_CLASS(CPedGroupIntelligence)
    // Construct/Deconstruct functions
    DECL_CTORCALL(CPedGroupIntelligence, _ZN21CPedGroupIntelligenceC2Ev);
    DECL_DTORCALL(CPedGroupIntelligence, _ZN21CPedGroupIntelligenceD2Ev);

    // Member functions
    DECL_THISCALL_SIMPLE(Flush, _ZN21CPedGroupIntelligence5FlushEv, void);
    DECL_THISCALL_HEAD(AddEvent, _ZN21CPedGroupIntelligence8AddEventER6CEvent, bool, CEvent& rEvent)
    DECL_THISCALL_TAIL(AddEvent, rEvent)
    DECL_THISCALL_SIMPLE(Process, _ZN21CPedGroupIntelligence7ProcessEv, void);
    DECL_THISCALL_HEAD(SetEventResponseTask, _ZN21CPedGroupIntelligence20SetEventResponseTaskEP4CPedbRK5CTaskbS4_i, void, CPed* pPed, bool const bMain, CTask const& TaskMain, bool const bSecondary, CTask const& TaskSecondary, int const iSlot)
    DECL_THISCALL_TAIL(SetEventResponseTask, pPed, bMain, TaskMain, bSecondary, TaskSecondary, iSlot)
    DECL_THISCALL_HEAD(SetScriptCommandTask, _ZN21CPedGroupIntelligence20SetScriptCommandTaskEP4CPedRK5CTask, void, CPed* pPed, CTask const& Task)
    DECL_THISCALL_TAIL(SetScriptCommandTask, pPed, Task)
    DECL_THISCALL_HEAD(SetDefaultTask, _ZN21CPedGroupIntelligence14SetDefaultTaskEP4CPedRK5CTask, void, CPed* pPed, CTask const& Task)
    DECL_THISCALL_TAIL(SetDefaultTask, pPed, Task)
    DECL_THISCALL_HEAD(GetTaskMain, _ZNK21CPedGroupIntelligence11GetTaskMainEP4CPed, CTask const*, CPed* pPed)
    DECL_THISCALL_TAIL(GetTaskMain, pPed)
    DECL_THISCALL_HEAD(GetTaskSecondary, _ZNK21CPedGroupIntelligence16GetTaskSecondaryEP4CPed, CTask const*, CPed* pPed)
    DECL_THISCALL_TAIL(GetTaskSecondary, pPed)
    DECL_THISCALL_HEAD(GetTaskDefault, _ZNK21CPedGroupIntelligence14GetTaskDefaultEP4CPed, CTask const*, CPed* pPed)
    DECL_THISCALL_TAIL(GetTaskDefault, pPed)
    DECL_THISCALL_HEAD(GetTaskSecondarySlot, _ZNK21CPedGroupIntelligence20GetTaskSecondarySlotEP4CPed, int, CPed* pPed)
    DECL_THISCALL_TAIL(GetTaskSecondarySlot, pPed)
    DECL_THISCALL_HEAD(GetTaskScriptCommand, _ZNK21CPedGroupIntelligence20GetTaskScriptCommandEP4CPed, CTask const*, CPed* pPed)
    DECL_THISCALL_TAIL(GetTaskScriptCommand, pPed)
    DECL_THISCALL_NAMED_HEAD(ReportFinishedTask1, ReportFinishedTask, _ZN21CPedGroupIntelligence18ReportFinishedTaskEPK4CPedRK5CTask, bool, CPed const* pPed, CTask const& finishedTask)
    DECL_THISCALL_TAIL(ReportFinishedTask1, pPed, finishedTask)
    DECL_THISCALL_NAMED_HEAD(ReportAllTasksFinished1, ReportAllTasksFinished, _ZN21CPedGroupIntelligence22ReportAllTasksFinishedEv, void)
    DECL_THISCALL_TAIL(ReportAllTasksFinished1)
    DECL_THISCALL_SIMPLE(ReportAllBarScriptTasksFinished, _ZN21CPedGroupIntelligence31ReportAllBarScriptTasksFinishedEv, void);
    DECL_THISCALL_HEAD(SetGroupDecisionMakerType, _ZN21CPedGroupIntelligence25SetGroupDecisionMakerTypeEi, void, int const iDecisionMaker)
    DECL_THISCALL_TAIL(SetGroupDecisionMakerType, iDecisionMaker)
    DECL_THISCALL_HEAD(SetDefaultTaskAllocatorType, _ZN21CPedGroupIntelligence27SetDefaultTaskAllocatorTypeEi, void, int const iType)
    DECL_THISCALL_TAIL(SetDefaultTaskAllocatorType, iType)
    DECL_THISCALL_HEAD(SetDefaultTaskAllocator, _ZN21CPedGroupIntelligence23SetDefaultTaskAllocatorEPK29CPedGroupDefaultTaskAllocator, void, CPedGroupDefaultTaskAllocator const* p)
    DECL_THISCALL_TAIL(SetDefaultTaskAllocator, p)
    DECL_THISCALL_HEAD(SetPrimaryTaskAllocator, _ZN21CPedGroupIntelligence23SetPrimaryTaskAllocatorEP14CTaskAllocator, void, CTaskAllocator* p)
    DECL_THISCALL_TAIL(SetPrimaryTaskAllocator, p)
    DECL_THISCALL_HEAD(SetEventResponseTaskAllocator, _ZN21CPedGroupIntelligence29SetEventResponseTaskAllocatorEP14CTaskAllocator, void, CTaskAllocator* p)
    DECL_THISCALL_TAIL(SetEventResponseTaskAllocator, p)
    DECL_THISCALL_HEAD(ComputeDefaultTasks, _ZN21CPedGroupIntelligence19ComputeDefaultTasksEP4CPed, void, CPed* pPed)
    DECL_THISCALL_TAIL(ComputeDefaultTasks, pPed)
    DECL_THISCALL_SIMPLE(ComputeScriptCommandTasks, _ZN21CPedGroupIntelligence25ComputeScriptCommandTasksEv, void);
    DECL_THISCALL_SIMPLE(ComputeEventResponseTasks, _ZN21CPedGroupIntelligence25ComputeEventResponseTasksEv, CTaskAllocator*);
    DECL_THISCALL_HEAD(FlushTasks, _ZN21CPedGroupIntelligence10FlushTasksEP12CPedTaskPairP4CPed, void, CPedTaskPair* a, CPed* pPed)
    DECL_THISCALL_TAIL(FlushTasks, a, pPed)
    DECL_THISCALL_SIMPLE(IsGroupResponding, _ZNK21CPedGroupIntelligence17IsGroupRespondingEv, bool);
    DECL_THISCALL_SIMPLE(IsCurrentEventValid, _ZNK21CPedGroupIntelligence19IsCurrentEventValidEv, bool);
    DECL_THISCALL_NAMED_HEAD(SetTask1, SetTask, _ZN21CPedGroupIntelligence7SetTaskEP4CPedRK5CTaskP12CPedTaskPairib, void, CPed* arg1, CTask const& arg2, CPedTaskPair* arg3, int const arg4, bool const arg5)
    DECL_THISCALL_TAIL(SetTask1, arg1, arg2, arg3, arg4, arg5)
    DECL_THISCALL_NAMED_HEAD(SetTask2, SetTask, _ZN21CPedGroupIntelligence7SetTaskEiRK5CTaskP12CPedTaskPairib, void, i32 Index, CTask const& Task, CPedTaskPair* p, int const iSlot, bool const bForce)
    DECL_THISCALL_TAIL(SetTask2, Index, Task, p, iSlot, bForce)
    DECL_THISCALL_HEAD(GetTask, _ZNK21CPedGroupIntelligence7GetTaskEP4CPedPK12CPedTaskPair, CTask*, CPed* pPed, CPedTaskPair const* p)
    DECL_THISCALL_TAIL(GetTask, pPed, p)
    DECL_THISCALL_HEAD(GetTaskSlot, _ZNK21CPedGroupIntelligence11GetTaskSlotEP4CPedPK12CPedTaskPair, int, CPed* pPed, CPedTaskPair const* p)
    DECL_THISCALL_TAIL(GetTaskSlot, pPed, p)
    DECL_THISCALL_NAMED_HEAD(ReportFinishedTask2, ReportFinishedTask, _ZN21CPedGroupIntelligence18ReportFinishedTaskEPK4CPedRK5CTaskP12CPedTaskPair, bool, CPed const* arg1, CTask const& arg2, CPedTaskPair* arg3)
    DECL_THISCALL_TAIL(ReportFinishedTask2, arg1, arg2, arg3)
    DECL_THISCALL_NAMED_HEAD(ReportAllTasksFinished2, ReportAllTasksFinished, _ZN21CPedGroupIntelligence22ReportAllTasksFinishedEP12CPedTaskPair, void, CPedTaskPair* pPedTaskPairs)
    DECL_THISCALL_TAIL(ReportAllTasksFinished2, pPedTaskPairs)
    DECL_THISCALL_SIMPLE(ProcessIgnorePlayerGroup, _ZN21CPedGroupIntelligence24ProcessIgnorePlayerGroupEv, void);

    // Member values
    CPedGroup* m_pPedGroup;
    CEventGroupEvent* m_pCurrentEvent;
    CEventGroupEvent* m_pHighestPriorityEvent;
    CPedTaskPair m_pedTaskPairs[8];
    CPedTaskPair m_secondaryPedTaskPairs[8];
    CPedTaskPair m_scriptCommandPedTaskPairs[8];
    CPedTaskPair m_defaultPedTaskPairs[8];
    CPedGroupDefaultTaskAllocator const* m_pDefaultTaskAllocator;
    CTaskAllocator* m_pPrimaryTaskAllocator;
    CTaskAllocator* m_pEventResponseTaskAllocator;
    int m_iDecisionMaker;
    int m_iSequenceTaskID;
DECL_CLASS_END()
CHECKSIZE(CPedGroupIntelligence, 0x2A0, 0x438);

DECL_CLASS(CPedGroup)
    // Construct/Deconstruct functions
    DECL_DTORCALL(CPedGroup, _ZN9CPedGroupD2Ev);
    DECL_CTORCALL(CPedGroup, _ZN9CPedGroupC2Ev);
    // Member functions
    DECL_THISCALL_SIMPLE(Process, _ZN9CPedGroup7ProcessEv, void);
    DECL_THISCALL_SIMPLE(Flush, _ZN9CPedGroup5FlushEv, void);
    DECL_THISCALL_SIMPLE(RemoveAllFollowers, _ZN9CPedGroup18RemoveAllFollowersEv, void);
    DECL_THISCALL_HEAD(Teleport, _ZN9CPedGroup8TeleportERK7CVector, void, CVector const& vNewPos)
    DECL_THISCALL_TAIL(Teleport, vNewPos)
    DECL_THISCALL_HEAD(PlayerGaveCommand_Attack, _ZN9CPedGroup24PlayerGaveCommand_AttackEP4CPedS1_, void, CPed* pOriginatorPed, CPed* pAttackedPed)
    DECL_THISCALL_TAIL(PlayerGaveCommand_Attack, pOriginatorPed, pAttackedPed)
    DECL_THISCALL_HEAD(PlayerGaveCommand_Gather, _ZN9CPedGroup24PlayerGaveCommand_GatherEP4CPed, void, CPed* pOriginatorPed)
    DECL_THISCALL_TAIL(PlayerGaveCommand_Gather, pOriginatorPed)
    DECL_THISCALL_HEAD(GetClosestGroupPed, _ZN9CPedGroup18GetClosestGroupPedEP4CPedPf, CPed*, CPed* pPed, float* retDistSqr)
    DECL_THISCALL_TAIL(GetClosestGroupPed, pPed, retDistSqr)
    DECL_THISCALL_HEAD(IsAnyoneUsingCar, _ZNK9CPedGroup16IsAnyoneUsingCarERK8CVehicle, bool, CVehicle const& vehicle)
    DECL_THISCALL_TAIL(IsAnyoneUsingCar, vehicle)
    DECL_THISCALL_SIMPLE(FindDistanceToFurthestMember, _ZN9CPedGroup28FindDistanceToFurthestMemberEv, float);
    DECL_THISCALL_HEAD(FindDistanceToNearestMember, _ZN9CPedGroup27FindDistanceToNearestMemberEPP4CPed, float, CPed** ppNearestPed)
    DECL_THISCALL_TAIL(FindDistanceToNearestMember, ppNearestPed)

    // Member values
    CPed* m_lastPedRespondedTo;
    u8 m_followLeader;
    CPedGroupMembership m_membership;
    CPedGroupIntelligence m_intelligence;
    i8 m_iGroupCreatedBy;
DECL_CLASS_END()
CHECKSIZE(CPedGroup, 0x2D4, 0x4A0);

#endif // __AML_PSDK_SAPEDGROUP_H
