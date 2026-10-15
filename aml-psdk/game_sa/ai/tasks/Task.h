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
    DECL_CTORCALL_PROXY(CTask, _ZN5CTaskC2Ev);
    DECL_DTORCALL_PROXY(CTask, _ZN5CTaskD2Ev);
    DECL_NEWCALL(CTask, BYBIT(_ZN5CTasknwEj, _ZN5CTasknwEm) );
    DECL_DLCALL(CTask, _ZN5CTaskdlEPv);

    // Virtual functions
    virtual CTask* Clone() const;
    virtual CTask* GetSubTask() const;
    virtual bool IsSimple() const;
    virtual eTaskType GetTaskType() const;
    virtual void StopTimer(const CEvent* event);
    virtual bool MakeAbortable(CPed* ped, eAbortPriority priority, const CEvent* event);
    virtual void Serialize();

    // STATIC functions
    DECL_FASTCALL_SIMPLE(IsTaskPtr, _ZN5CTask9IsTaskPtrEPv, bool, void* pData);
    DECL_FASTCALL_SIMPLE(IsGoToTask, _ZN5CTask10IsGoToTaskEPKS_, u8, CTask const* pTask);
    DECL_FASTCALL_SIMPLE(CreateTask, _ZN5CTask10CreateTaskEv, CTask*);

    // Member values
    CTask *m_pParentTask;
DECL_CLASS_END()

DECL_CLASS_BASED(CTaskSimple, CTask)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CTaskSimple, _ZN11CTaskSimpleC2Ev);
    DECL_DTORCALL_PROXY(CTaskSimple, _ZN11CTaskSimpleD2Ev);

    virtual bool ProcessPed(CPed *);
    virtual bool SetPedPosition(CPed *);
DECL_CLASS_END()

DECL_CLASS_BASED(CTaskComplex, CTask)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CTaskComplex, _ZN12CTaskComplexC2Ev);
    DECL_DTORCALL_PROXY(CTaskComplex, _ZN12CTaskComplexD2Ev);
    DECL_NEWCALL(CTaskComplex, BYBIT(_ZN5CTasknwEj, _ZN5CTasknwEm));

    // Virtual functions
    virtual void SetSubTask(CTask* arg1);
    virtual CTask* CreateNextSubTask(CPed* arg1);
    virtual CTask* CreateFirstSubTask(CPed* arg1);
    virtual CTask* ControlSubTask(CPed* arg1);

    // Member values
    CTask* m_pSubTask;
DECL_CLASS_END()
CHECKSIZE(CTaskComplex, 0xC, 0x18);

#endif // __AML_PSDK_SATASK_H
