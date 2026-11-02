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

#define rwFREELISTFLAG_STATIC 0x1
#define rwFREELISTFLAG_FREEBLOCKS 0x2

typedef void (*RwFreeListCallBack)(void* memory, void* data);

DECL_FASTCALL_SIMPLE_GLO(RwFreeListCreate, _Z16RwFreeListCreateiii, RwFreeList*, RwInt32 entrySize, RwInt32 entriesPerBlock, RwInt32 alignment);
DECL_FASTCALL_SIMPLE_GLO(RwFreeListCreateAndPreallocateSpace, _Z35RwFreeListCreateAndPreallocateSpaceiiiiP10RwFreeList, RwFreeList*, RwInt32 entrySize, RwInt32 entriesPerBlock, RwInt32 alignment, RwInt32 numBlocksToPreallocate, RwFreeList* inPlaceSpace);
DECL_FASTCALL_SIMPLE_GLO(RwFreeListDestroy, _Z17RwFreeListDestroyP10RwFreeList, RwBool, RwFreeList* freeList);
DECL_FASTCALL_SIMPLE_GLO(RwFreeListGetFlags, _Z18RwFreeListGetFlagsP10RwFreeList, RwUInt32, RwFreeList* freeList);
DECL_FASTCALL_SIMPLE_GLO(RwFreeListSetFlags, _Z18RwFreeListSetFlagsP10RwFreeListj, void, RwFreeList* freeList, RwUInt32 flags);
DECL_FASTCALL_SIMPLE_GLO(RwFreeListPurge, _Z15RwFreeListPurgeP10RwFreeList, RwInt32, RwFreeList* freeList);
DECL_FASTCALL_SIMPLE_GLO(RwFreeListPurgeAllFreeLists, _Z27RwFreeListPurgeAllFreeListsv, RwInt32);
DECL_FASTCALL_SIMPLE_GLO(RwFreeListForAllUsed, _Z20RwFreeListForAllUsedP10RwFreeListPFvPvS1_ES1_, RwFreeList*, RwFreeList* freeList, RwFreeListCallBack callback, void* data);
DECL_FASTCALL_SIMPLE_GLO(_rwFreeListAllocReal, _Z20_rwFreeListAllocRealP10RwFreeList, void*, RwFreeList* freeList);
DECL_FASTCALL_SIMPLE_GLO(_rwFreeListFreeReal, _Z19_rwFreeListFreeRealP10RwFreeListPv, RwFreeList*, RwFreeList* freeList, void* memory);
#endif // __AML_PSDK_RWRESOURCE_H
