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
    DECL_DTORCALL(CTask, _ZN5CTaskD2Ev);
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

    // Member values
    CTask *m_pParentTask;
DECL_CLASS_END()

DECL_CLASS_BASED(CTaskSimple, CTask)
    virtual bool ProcessPed(CPed *);
    virtual bool SetPedPosition(CPed *);
DECL_CLASS_END()

#endif // __AML_PSDK_SATASK_H
