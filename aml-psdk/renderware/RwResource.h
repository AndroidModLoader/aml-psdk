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

#endif // __AML_PSDK_RWRESOURCE_H
