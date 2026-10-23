#ifndef __AML_PSDK_SAPEDSCRIPTEDTASKRECORD_H
#define __AML_PSDK_SAPEDSCRIPTEDTASKRECORD_H

#include "../plugin.h"

struct CPed;
struct CTask;
struct CEventScriptCommand;

DECL_CLASS(CPedScriptedTaskRecordData)
    // Construct/Deconstruct functions
    DECL_CTORCALL(CPedScriptedTaskRecordData, _ZN26CPedScriptedTaskRecordDataC2Ev);

    // Member functions
    // Call Flush before destroying a record associated with a ped.
    DECL_THISCALL_SIMPLE(Flush, _ZN26CPedScriptedTaskRecordData5FlushEv, void);
    DECL_THISCALL_NAMED_HEAD(Set1, Set, _ZN26CPedScriptedTaskRecordData3SetEP4CPediPK19CEventScriptCommand, void,
        CPed* ped, i32 commandType, CEventScriptCommand const* event)
    DECL_THISCALL_TAIL(Set1, ped, commandType, event)
    DECL_THISCALL_NAMED_HEAD(Set2, Set, _ZN26CPedScriptedTaskRecordData3SetEP4CPediPK5CTask, void,
        CPed* ped, i32 commandType, CTask const* task)
    DECL_THISCALL_TAIL(Set2, ped, commandType, task)
    DECL_THISCALL_HEAD(SetAsAttractorScriptTask, _ZN26CPedScriptedTaskRecordData24SetAsAttractorScriptTaskEP4CPediPK5CTask, void,
        CPed* ped, i32 commandType, CTask const* task)
    DECL_THISCALL_TAIL(SetAsAttractorScriptTask, ped, commandType, task)
    DECL_THISCALL_HEAD(SetAsGroupTask, _ZN26CPedScriptedTaskRecordData14SetAsGroupTaskEP4CPediPK5CTask, void,
        CPed* ped, i32 commandType, CTask const* task)
    DECL_THISCALL_TAIL(SetAsGroupTask, ped, commandType, task)
    DECL_THISCALL_HEAD(AssociateWithEvent, _ZN26CPedScriptedTaskRecordData18AssociateWithEventEP19CEventScriptCommand, void, CEventScriptCommand* event)
    DECL_THISCALL_TAIL(AssociateWithEvent, event)
    DECL_THISCALL_HEAD(AssociateWithTask, _ZN26CPedScriptedTaskRecordData17AssociateWithTaskEP5CTask, void, CTask* task)
    DECL_THISCALL_TAIL(AssociateWithTask, task)

    // Member values
    i32 m_iCommandType;
    CEventScriptCommand const* m_pEvent;
    CTask const* m_pTask;
    CPed* m_pPed;
    i32 m_iStage;
DECL_CLASS_END()
CHECKSIZE(CPedScriptedTaskRecordData, 0x14, 0x28);

DECL_CLASS(CPedScriptedTaskRecord)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(GetVacantSlot, _ZN22CPedScriptedTaskRecord13GetVacantSlotEv, i32);
    DECL_FASTCALL_SIMPLE(Process, _ZN22CPedScriptedTaskRecord7ProcessEv, void);
    DECL_FASTCALL_SIMPLE(GetStatus1, _ZN22CPedScriptedTaskRecord9GetStatusEPK4CPedi, i32, CPed const* ped, i32 commandType);
    DECL_FASTCALL_SIMPLE(GetStatus2, _ZN22CPedScriptedTaskRecord9GetStatusEPK4CPed, i32, CPed const* ped);
    DECL_FASTCALL_SIMPLE(GetRecordAssociatedWithEvent, _ZN22CPedScriptedTaskRecord28GetRecordAssociatedWithEventEP19CEventScriptCommand, CPedScriptedTaskRecordData*, CEventScriptCommand* event);
    DECL_FASTCALL_SIMPLE(GetRecordAssociatedWithTask, _ZN22CPedScriptedTaskRecord27GetRecordAssociatedWithTaskEP5CTask, CPedScriptedTaskRecordData*, CTask* task);
    DECL_FASTCALL_SIMPLE(Save, _ZN22CPedScriptedTaskRecord4SaveEv, void);
    DECL_FASTCALL_SIMPLE(Load, _ZN22CPedScriptedTaskRecord4LoadEv, void);

    static inline i32 GetStatus(CPed const* ped, i32 commandType) { return GetStatus1(ped, commandType); }
    static inline i32 GetStatus(CPed const* ped) { return GetStatus2(ped); }

    // STATIC values
    DECL_OBJECT_ARRAY_PLT(CPedScriptedTaskRecordData, ms_scriptedTasks, BYBIT(0x679A18, 0x851448));
DECL_CLASS_END()

#define ms_scriptedTasks ms_scriptedTasks()

#endif // __AML_PSDK_SAPEDSCRIPTEDTASKRECORD_H
