#ifndef __AML_PSDK_SASCRIPTEDBRAINTASKSTORE_H
#define __AML_PSDK_SASCRIPTEDBRAINTASKSTORE_H

#include "../plugin.h"

struct CPed;
struct CTask;

struct CScriptedBrainTaskStoreEntry
{
    CPed* m_pPed;
    char m_name[8];
    CTask* m_pTask;
};
CHECKSIZE(CScriptedBrainTaskStoreEntry, 0x10, 0x18);

DECL_CLASS(CScriptedBrainTaskStore)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(Clear1, _ZN23CScriptedBrainTaskStore5ClearEP5CTask, void, CTask* task);
    DECL_FASTCALL_SIMPLE(Clear2, _ZN23CScriptedBrainTaskStore5ClearEP4CPed, void, CPed* ped);
    DECL_FASTCALL_SIMPLE(SetTask, _ZN23CScriptedBrainTaskStore7SetTaskEP4CPedP5CTask, CTask*, CPed* ped, CTask* task);
    DECL_FASTCALL_SIMPLE(GetTask, _ZN23CScriptedBrainTaskStore7GetTaskEPK4CPed, CTask*, CPed const* ped);

    static inline void Clear(CTask* task) { Clear1(task); }
    static inline void Clear(CPed* ped) { Clear2(ped); }

    // STATIC values
    DECL_OBJECT_ARRAY_PLT(CScriptedBrainTaskStoreEntry, ms_entries, BYBIT(0x679F5C, 0x851EC0));
DECL_CLASS_END()

#define ms_entries ms_entries()

#endif // __AML_PSDK_SASCRIPTEDBRAINTASKSTORE_H
