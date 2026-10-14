#ifndef __AML_PSDK_SATASKMANAGER_H
#define __AML_PSDK_SATASKMANAGER_H

#include <aml-psdk/game_sa/plugin.h>

struct CTask;
struct CPed;
struct CEvent;

enum ePrimaryTasks //array indexes
{
    TASK_PRIMARY_PHYSICAL_RESPONSE = 0,
    TASK_PRIMARY_EVENT_RESPONSE_TEMP,
    TASK_PRIMARY_EVENT_RESPONSE_NONTEMP,
    TASK_PRIMARY_PRIMARY,
    TASK_PRIMARY_DEFAULT,
    TASK_PRIMARY_MAX
};

enum eSecondaryTasks //array indexes
{
    TASK_SECONDARY_ATTACK = 0,                // want duck to be after attack
    TASK_SECONDARY_DUCK,                    // because attack controls ducking movement
    TASK_SECONDARY_SAY,
    TASK_SECONDARY_FACIAL_COMPLEX,
    TASK_SECONDARY_PARTIAL_ANIM,
    TASK_SECONDARY_IK,
    TASK_SECONDARY_MAX
};

DECL_CLASS(CTaskManager)
    // Construct/Deconstruct functions
    CTaskManager(){}
    DECL_CTORCALL_ARG_HEAD(CTaskManager, _ZN12CTaskManagerC2EP4CPed, CPed *pPed)
    DECL_CTORCALL_ARG_TAIL(pPed)
    DECL_DTORCALL(CTaskManager, _ZN12CTaskManagerD2Ev);

    // Member functions
    DECL_THISCALL_SIMPLE(GetActiveTask, _ZNK12CTaskManager13GetActiveTaskEv, CTask*);
    DECL_THISCALL_SIMPLE(GetSimplestActiveTask, _ZNK12CTaskManager21GetSimplestActiveTaskEv, CTask*);
    DECL_THISCALL_SIMPLE(ClearTaskEventResponse, _ZN12CTaskManager22ClearTaskEventResponseEv, void);
    DECL_THISCALL_SIMPLE(ManageTasks, _ZN12CTaskManager11ManageTasksEv, void);
    DECL_THISCALL_SIMPLE(Flush, _ZN12CTaskManager5FlushEv, void);
    DECL_THISCALL_SIMPLE(FlushImmediately, _ZN12CTaskManager16FlushImmediatelyEv, void);

    DECL_THISCALL_HEAD(SetTask, _ZN12CTaskManager7SetTaskEP5CTaskib, void, CTask *pTask, const int iPriority, const bool bForceNewTask)
    DECL_THISCALL_TAIL(SetTask, pTask, iPriority, bForceNewTask)

    DECL_THISCALL_HEAD(AddSubTasks, _ZN12CTaskManager11AddSubTasksEP5CTask, void, CTask *pTask)
    DECL_THISCALL_TAIL(AddSubTasks, pTask)

    DECL_FASTCALL_SIMPLE(FuncProxy_GetSimplestTask, _ZN12CTaskManager15GetSimplestTaskEP5CTask, CTask*, CTask *pTask);
    static inline CTask* GetSimplestTask(CTask *pTask) { return FuncProxy_GetSimplestTask(pTask); }

    DECL_THISCALL_NAMED_HEAD(GetSimplestTask1, GetSimplestTask, _ZNK12CTaskManager15GetSimplestTaskEi, CTask*, const int iPriority)
    DECL_THISCALL_TAIL(GetSimplestTask1, iPriority)

    DECL_THISCALL_HEAD(FindActiveTaskByType, _ZNK12CTaskManager20FindActiveTaskByTypeEi, CTask*, const int iTaskType)
    DECL_THISCALL_TAIL(FindActiveTaskByType, iTaskType)

    DECL_THISCALL_HEAD(FindTaskByType, _ZNK12CTaskManager14FindTaskByTypeEii, CTask*, const int iPriority, const int iTaskType)
    DECL_THISCALL_TAIL(FindTaskByType, iPriority, iTaskType)

    DECL_THISCALL_HEAD(SetTaskSecondary, _ZN12CTaskManager16SetTaskSecondaryEP5CTaski, void, CTask *pTaskSecondary, const int iType)
    DECL_THISCALL_TAIL(SetTaskSecondary, pTaskSecondary, iType)

    DECL_THISCALL_HEAD(GetTaskSecondary, _ZNK12CTaskManager16GetTaskSecondaryEi, CTask*, const int iType)
    DECL_THISCALL_TAIL(GetTaskSecondary, iType)

    DECL_THISCALL_HEAD(HasTaskSecondary, _ZNK12CTaskManager16HasTaskSecondaryEPK5CTask, bool, const CTask *pTaskSecondary)
    DECL_THISCALL_TAIL(HasTaskSecondary, pTaskSecondary)

    DECL_THISCALL_HEAD(SetNextSubTask, _ZN12CTaskManager14SetNextSubTaskEP5CTask, void, CTask *pTask)
    DECL_THISCALL_TAIL(SetNextSubTask, pTask)

    DECL_THISCALL_HEAD(ParentsControlChildren, _ZN12CTaskManager22ParentsControlChildrenEP5CTask, void, CTask *pTask)
    DECL_THISCALL_TAIL(ParentsControlChildren, pTask)

    DECL_THISCALL_HEAD(StopTimers, _ZN12CTaskManager10StopTimersEPK6CEvent, void, const CEvent *pEvent)
    DECL_THISCALL_TAIL(StopTimers, pEvent)

    // Member values
    CTask *m_aPrimaryTasks[TASK_PRIMARY_MAX];
    CTask *m_aSecondaryTasks[TASK_SECONDARY_MAX];
    CPed *m_pPed;
DECL_CLASS_END()

#endif // __AML_PSDK_SATASKMANAGER_H
