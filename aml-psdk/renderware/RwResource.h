#ifndef __AML_PSDK_RWRESOURCE_H
#define __AML_PSDK_RWRESOURCE_H

#include <aml-psdk/sdk_base.h>
#include "RwBase.h"
#include "RwLinks.h"

struct RwResEntry;

typedef void (*RwResEntryDestroyNotify)(RwResEntry *resEntry);

/* An entry in the resource arena -- instanced geometry data that the
 * pipeline may throw away and rebuild on demand. */
struct RwResEntry
{
    RwLLLink                 link;          /* Node in the arena's used/free list */
    RwInt32                  size;          /* Size of this entry, header included */
    void                    *owner;         /* Object this entry belongs to */
    RwResEntry             **ownerRef;      /* Owner's pointer back to this entry */
    RwResEntryDestroyNotify  destroyNotify; /* Called when the entry is evicted */
};

CHECKSIZE(RwResEntry, 0x18, 0x30);

DECL_FASTCALL_SIMPLE_GLO(RwResourcesFreeResEntry, _Z23RwResourcesFreeResEntryP10RwResEntry, RwBool, RwResEntry* entry);
DECL_FASTCALL_SIMPLE_GLO(RwResourcesSetArenaSize, _Z23RwResourcesSetArenaSizej, RwBool, RwUInt32 size);
DECL_FASTCALL_SIMPLE_GLO(RwResourcesEmptyArena, _Z21RwResourcesEmptyArenav, RwBool);
DECL_FASTCALL_SIMPLE_GLO(RwResourcesAllocateResEntry, _Z27RwResourcesAllocateResEntryPvPP10RwResEntryiPFvS1_E, RwResEntry*, void* owner, RwResEntry** ownerRef, RwInt32 size, RwResEntryDestroyNotify destroyNotify);
DECL_FASTCALL_SIMPLE_GLO(RwResourcesGetArenaSize, _Z23RwResourcesGetArenaSizev, RwInt32);
DECL_FASTCALL_SIMPLE_GLO(RwResourcesGetArenaUsage, _Z24RwResourcesGetArenaUsagev, RwInt32);

#endif // __AML_PSDK_RWRESOURCE_H
