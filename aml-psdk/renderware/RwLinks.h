#ifndef __AML_PSDK_RWLINKS_H
#define __AML_PSDK_RWLINKS_H

struct RwLLLink
{
    RwLLLink *next;
    RwLLLink *prev;
};
struct RwLinkList
{
    RwLLLink link;
};

#endif // __AML_PSDK_RWLINKS_H