#ifndef __AML_PSDK_RWLINKS_H
#define __AML_PSDK_RWLINKS_H

#include "RwBase.h"

struct RwLLLink
{
    RwLLLink *next;
    RwLLLink *prev;
};
struct RwLinkList
{
    RwLLLink link;
};

struct RwFreeList
{
    RwUInt32 entrySize;
    RwUInt32 entriesPerBlock;
    RwUInt32 heapSize;
    RwUInt32 alignment;
    RwLinkList blockList;
    RwUInt32 flags;
    RwLLLink link;
};
CHECKSIZE(RwFreeList, 0x24, 0x38);

#endif // __AML_PSDK_RWLINKS_H