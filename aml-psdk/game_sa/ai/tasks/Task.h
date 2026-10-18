#ifndef __AML_PSDK_SATASK_H
#define __AML_PSDK_SATASK_H

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/game_sa/enum/TaskType.h>

struct CEvent;
struct CPed;

enum eAbortPriority
{
    ABORT_PRIORITY_LEISURE = 0,
    ABORT_PRIORITY_URGENT,
    ABORT_PRIORITY_IMMEDIATE
};

DECL_CLASS_VTABLE(CTask)
    // Construct/Deconstruct functions
    DECL_CTORCALL(CTask, _ZN5CTaskC2Ev);
    DECL_DTORCALL_VIRTUAL(CTask, _ZN5CTaskD2Ev, _ZN5CTask, _ZTV5CTask);
    DECL_NEWCALL(CTask, BYBIT(_ZN5CTasknwEj, _ZN5CTasknwEm) );
    DECL_DLCALL(CTask, _ZN5CTaskdlEPv);

    // Virtual functions
    virtual CTask* Clone() const = 0;
    virtual CTask* GetSubTask() const = 0;
    virtual bool IsSimple() const = 0;
    virtual eTaskType GetTaskType() const = 0;
    DECL_VIRTUALCALL_HEAD(CTask, StopTimer, _ZTV5CTask, 6, void, const CEvent* event)
    DECL_VIRTUALCALL_TAIL(event)
    virtual bool MakeAbortable(CPed* ped, eAbortPriority priority, const CEvent* event) = 0;
    DECL_VIRTUALCALL_HEAD(CTask, Serialize, _ZTV5CTask, 8, void)
    DECL_VIRTUALCALL_TAIL()

    // STATIC functions
    DECL_FASTCALL_SIMPLE(IsTaskPtr, _ZN5CTask9IsTaskPtrEPv, bool, void* pData);
    DECL_FASTCALL_SIMPLE(IsGoToTask, _ZN5CTask10IsGoToTaskEPKS_, u8, CTask const* pTask);
    DECL_FASTCALL_SIMPLE(CreateTask, _ZN5CTask10CreateTaskEv, CTask*);

    // Member values
    CTask *m_pParentTask;
DECL_CLASS_END()

DECL_CLASS_BASED(CTaskSimple, CTask)
    DECL_VIRTUALCALL_CONST_HEAD(CTaskSimple, GetSubTask, _ZTV11CTaskSimple, 3, CTask*)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CTaskSimple, IsSimple, _ZTV11CTaskSimple, 4, bool)
    DECL_VIRTUALCALL_TAIL()

    // Construct/Deconstruct functions
    DECL_CTORCALL(CTaskSimple, _ZN11CTaskSimpleC2Ev);
    DECL_DTORCALL_VIRTUAL(CTaskSimple, _ZN11CTaskSimpleD2Ev, _ZN11CTaskSimple, _ZTV11CTaskSimple);

    virtual bool ProcessPed(CPed * arg1) = 0;
    DECL_VIRTUALCALL_HEAD(CTaskSimple, SetPedPosition, _ZTV11CTaskSimple, 10, bool, CPed * arg1)
    DECL_VIRTUALCALL_TAIL(arg1)
DECL_CLASS_END()

DECL_CLASS_BASED(CTaskComplex, CTask)
    DECL_VIRTUALCALL_CONST_HEAD(CTaskComplex, GetSubTask, _ZTV12CTaskComplex, 3, CTask*)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_CONST_HEAD(CTaskComplex, IsSimple, _ZTV12CTaskComplex, 4, bool)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CTaskComplex, MakeAbortable, _ZTV12CTaskComplex, 7, bool, CPed* ped, eAbortPriority priority, const CEvent* event)
    DECL_VIRTUALCALL_TAIL(ped, priority, event)

    // Construct/Deconstruct functions
    DECL_CTORCALL(CTaskComplex, _ZN12CTaskComplexC2Ev);
    DECL_DTORCALL_VIRTUAL(CTaskComplex, _ZN12CTaskComplexD2Ev, _ZN12CTaskComplex, _ZTV12CTaskComplex);
    DECL_NEWCALL(CTaskComplex, BYBIT(_ZN5CTasknwEj, _ZN5CTasknwEm));

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(CTaskComplex, SetSubTask, _ZTV12CTaskComplex, 9, void, CTask* arg1)
    DECL_VIRTUALCALL_TAIL(arg1)
    virtual CTask* CreateNextSubTask(CPed* arg1) = 0;
    virtual CTask* CreateFirstSubTask(CPed* arg1) = 0;
    virtual CTask* ControlSubTask(CPed* arg1) = 0;

    // Member values
    CTask* m_pSubTask;
DECL_CLASS_END()
CHECKSIZE(CTaskComplex, 0xC, 0x18);

#endif // __AML_PSDK_SATASK_H
