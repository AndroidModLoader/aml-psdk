#ifndef __AML_PSDK_GTALISTS_H
#define __AML_PSDK_GTALISTS_H

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/gta_base/Vector.h>
#include <aml-psdk/game_sa/anim/AnimBlock.h>

struct CPtrNode
{
    void *m_pVoid;
    CPtrNode *m_pNext;
};

DECL_CLASS_BASED(CPtrNodeSingleLink, CPtrNode)
    // Construct/Deconstruct functions
    CPtrNodeSingleLink(){}
    explicit CPtrNodeSingleLink(void* item) { m_pVoid = item; }
    DECL_NEWCALL(CPtrNodeSingleLink, BYBIT(_ZN18CPtrNodeSingleLinknwEj, _ZN18CPtrNodeSingleLinknwEm));
    DECL_DLCALL(CPtrNodeSingleLink, _ZN18CPtrNodeSingleLinkdlEPv);
DECL_CLASS_END()

DECL_CLASS_BASED(CPtrNodeDoubleLink, CPtrNode)
    // Construct/Deconstruct functions
    CPtrNodeDoubleLink(){}
    explicit CPtrNodeDoubleLink(void* item) { m_pVoid = item; }
    DECL_NEWCALL(CPtrNodeDoubleLink, BYBIT(_ZN18CPtrNodeDoubleLinknwEj, _ZN18CPtrNodeDoubleLinknwEm));
    DECL_DLCALL(CPtrNodeDoubleLink, _ZN18CPtrNodeDoubleLinkdlEPv);

    CPtrNodeDoubleLink *m_pPrevious;
DECL_CLASS_END()

DECL_CLASS(CPtrList)
    // Member functions
    DECL_THISCALL_SIMPLE(CountElements, _ZN8CPtrList13CountElementsEv, i32);
    DECL_THISCALL_HEAD(IsMemberOfList, _ZN8CPtrList14IsMemberOfListEPv, bool, void* data)
    DECL_THISCALL_TAIL(IsMemberOfList, data)

    CPtrNode *m_pHead;
DECL_CLASS_END()

DECL_CLASS_BASED(CPtrListDoubleLink, CPtrList)
    // Construct/Deconstruct functions
    DECL_DTORCALL(CPtrListDoubleLink, _ZN18CPtrListDoubleLinkD2Ev);

    // Member functions
    DECL_THISCALL_SIMPLE(Flush, _ZN18CPtrListDoubleLink5FlushEv, void);
DECL_CLASS_END()

DECL_CLASS_BASED(CPtrListSingleLink, CPtrList)
    // Member functions
    DECL_THISCALL_SIMPLE(Flush, _ZN18CPtrListSingleLink5FlushEv, void);

DECL_CLASS_END()

struct CSector
{
    CPtrListSingleLink m_buildingPtrListArray;
    CPtrListDoubleLink m_dummyPtrListArray;
};

struct CRepeatSector
{
    CPtrListDoubleLink m_ptrListArray[3];
};

template <class T, int N> struct CStore
{
    int m_nCount;
    T m_objects[N];
};

DECL_CLASS(CEntryInfoNode)
    // Construct/Deconstruct functions
    DECL_NEWCALL(CEntryInfoNode, BYBIT(_ZN14CEntryInfoNodenwEj, _ZN14CEntryInfoNodenwEm));
    DECL_DLCALL(CEntryInfoNode, _ZN14CEntryInfoNodedlEPv);

    CPtrListDoubleLink *m_pList;
    CPtrNodeDoubleLink *m_pNode;
    union
    {
        CSector *m_pStandardSector;
        CRepeatSector *m_pRepeatSector;
    };
    CEntryInfoNode *m_pPrevious;
    CEntryInfoNode *m_pNext;
DECL_CLASS_END()

DECL_CLASS(CEntryInfoList)
    // Member functions
    DECL_THISCALL_SIMPLE(Flush, _ZN14CEntryInfoList5FlushEv, void);

    CEntryInfoNode *m_pHead;
DECL_CLASS_END()

struct CNodeAddress
{
    unsigned short m_nAreaId;
    unsigned short m_nNodeId;

    inline CNodeAddress() {
        Clear();
    }

    inline CNodeAddress(unsigned short areaId, unsigned short nodeId) {
        Set(areaId, nodeId);
    }

    inline void Set(unsigned short areaId, unsigned short nodeId) {
        m_nAreaId = areaId;
        m_nNodeId = nodeId;
    }

    inline bool IsEmpty() const {
        return m_nAreaId == 0xFFFF || m_nNodeId == 0xFFFF;
    }

    inline void Clear() {
        m_nAreaId = -1;
        m_nNodeId = -1;
    }

    inline bool operator==(CNodeAddress const &rhs) const {
        return m_nAreaId == rhs.m_nAreaId && m_nNodeId == rhs.m_nNodeId;
    }

    inline bool operator!=(CNodeAddress const &rhs) const {
        return m_nAreaId != rhs.m_nAreaId || m_nNodeId != rhs.m_nNodeId;
    }
};

struct CCarPathLinkAddress
{
    short m_nCarPathLinkId : 10;
    short m_nAreaId : 6;
};

DECL_CLASS(CNodeRoute)
    // Construct/Deconstruct functions
    CNodeRoute() : m_iRouteSize(0) {}
    DECL_NEWCALL(CNodeRoute, BYBIT(_ZN10CNodeRoutenwEj, _ZN10CNodeRoutenwEm));
    DECL_DLCALL(CNodeRoute, _ZN10CNodeRoutedlEPv);

    int m_iRouteSize;
    CNodeAddress m_routePoints[8];
DECL_CLASS_END()

DECL_CLASS(CPointRoute)
    // Construct/Deconstruct functions
    CPointRoute() : m_iRouteSize(0) {}
    DECL_NEWCALL(CPointRoute, BYBIT(_ZN11CPointRoutenwEj, _ZN11CPointRoutenwEm));
    DECL_DLCALL(CPointRoute, _ZN11CPointRoutedlEPv);

    int m_iRouteSize;
    CVector m_routePoints[8];
DECL_CLASS_END()
CHECKSIZE(CPointRoute, 0x64, 0x64);

DECL_CLASS(CPatrolRoute)
    // Construct/Deconstruct functions
    CPatrolRoute() : m_iRouteSize(0) {}
    DECL_DTORCALL(CPatrolRoute, _ZN12CPatrolRouteD2Ev);
    DECL_NEWCALL(CPatrolRoute, BYBIT(_ZN12CPatrolRoutenwEj, _ZN12CPatrolRoutenwEm));
    DECL_DLCALL(CPatrolRoute, _ZN12CPatrolRoutedlEPv);

    // Member functions
    DECL_THISCALL_SIMPLE(Reverse, _ZN12CPatrolRoute7ReverseEv, void);

    // Member values
    int m_iRouteSize;
    CAnimNameDescriptor m_anims[8];
    CVector m_routePoints[8];
DECL_CLASS_END()
CHECKSIZE(CPatrolRoute, 0x1A4, 0x1A4);

// Doubly-linked list node. The game preallocates a fixed pool of these and
// moves them between the used list and the free list, which is why the list
// head below carries four sentinel links rather than two.
template <class T> struct CLink
{
    T        item;
    CLink<T> *m_pPrev;
    CLink<T> *m_pNext;

    inline void Insert(CLink<T> *pTarget)
    {
        m_pNext = pTarget->m_pNext;
        m_pPrev = pTarget;
        pTarget->m_pNext->m_pPrev = this;
        pTarget->m_pNext = this;
    }
    inline void Remove()
    {
        m_pNext->m_pPrev = m_pPrev;
        m_pPrev->m_pNext = m_pNext;
    }
};

template <class T> struct CLinkList
{
    CLink<T>  m_firstLink;
    CLink<T>  m_lastLink;
    CLink<T>  m_firstFreeLink;
    CLink<T>  m_lastFreeLink;
    CLink<T> *m_pStore;

    inline CLink<T>* GetHead() { return m_firstLink.m_pNext; }
    inline CLink<T>* GetTail() { return m_lastLink.m_pPrev; }
    inline bool      IsEmpty() { return m_firstLink.m_pNext == &m_lastLink; }
};

// Fixed-capacity stack. N is a value template parameter, so the type spells
// out as e.g. CStack<int, 16>.
template <class T, int N> struct CStack
{
    T   m_array[N];
    i32 m_posn;

    inline void Push(const T& v) { m_array[m_posn++] = v; }
    inline T&   Pop()            { return m_array[--m_posn]; }
    inline T&   Top()            { return m_array[m_posn - 1]; }
    inline bool IsEmpty()        { return m_posn <= 0; }
};

template <class T> struct OSArray
{
    unsigned int numAlloced;
    unsigned int numEntries;
    T *data;

    inline unsigned int& Count() { return numEntries; }
    inline unsigned int& AllocatedCount() { return numAlloced; }
    inline unsigned int AllocatedMem() { return numAlloced * sizeof(T); }
    inline T* Element(unsigned int i) { return &data[i]; }
    inline bool IsFull()
    {
        return numAlloced <= numEntries;
    }
    inline T* AllocNew()
    {
        T* container = data;
        if(IsFull())
        {
            uint32_t reallocCount = 4 * (numEntries + 1) / 3u + 3;
            container = (T*)malloc(sizeof(T) * reallocCount);
            if(data)
            {
                T* oldContainer = data;
                memcpy(container, data, sizeof(T) * numEntries);
                free(oldContainer);
            }
            numAlloced = reallocCount;
            data = container;
        }
        return &container[numEntries++];
    }
    inline void RemoveAt(unsigned int idx)
    {
        if(idx >= numEntries) return;
        if(idx + 1 < numEntries)
        {
            memmove(&data[idx], &data[idx+1], sizeof(T) * (numEntries - idx - 1));
        }
        --numEntries;
    }
    inline T& operator[](unsigned int idx)
    {
        return data[idx];
    }
};
#define TDBArray OSArray
#define SArray OSArray

DECL_CLASS(ListItem_c)
    // Construct/Deconstruct functions
    DECL_DTORCALL(ListItem_c, _ZN10ListItem_cD2Ev);

    ListItem_c() { next = NULL; prev = NULL; }
    ListItem_c *next;
    ListItem_c *prev;
DECL_CLASS_END()

DECL_CLASS(List_c)
    // Construct/Deconstruct functions
    DECL_DTORCALL(List_c, _ZN6List_cD2Ev);

    List_c() { last = NULL; first = NULL; count = 0; }
    ListItem_c *first;
    ListItem_c *last;
    int count;

    inline void AddItem(ListItem_c *pItem)
    {
        ListItem_c* oldHead = first;

        first = pItem;
        pItem->prev = NULL;
        pItem->next = oldHead;
        if(oldHead)
        {
            oldHead->prev = pItem;
        }
        else
        {
            last = pItem;
        }
        ++count;
    }
    inline void RemoveItem(ListItem_c *pItem)
    {
        if(pItem->next)
        {
            pItem->next->prev = pItem->prev;
        }
        else
        {
            last = pItem->prev;
        }

        if (pItem->prev)
        {
            pItem->prev->next = pItem->next;
        }
        else
        {
            first = pItem->next;
        }
        --count;
    }
    inline ListItem_c *GetHead(void) { return first; }
    inline ListItem_c *RemoveHead(void)
    {
        ListItem_c* oldHead = first;
        if(oldHead)
        {
            first = oldHead->next;
            if(first)
            {
                first->prev = NULL;
            }
            else
            {
                last = NULL;
            }
            oldHead->next = NULL;
            oldHead->prev = NULL;
            --count;
        }
        return oldHead;
    }
    inline ListItem_c *GetNext(ListItem_c *pItem) { return pItem->next; }
    inline ListItem_c *GetPrev(ListItem_c *pItem) { return pItem->prev; }
    inline ListItem_c *GetItemOffset(bool bFromHead, int iOffset)
    {
        ListItem_c* ret;
        if(bFromHead)
        {
            ret = first;
            if(iOffset > 0)
            {
                for(int i = 0; i < iOffset; ++i)
                {
                    if(!ret) break;
                    ret = ret->next;
                }
            }
        }
        else
        {
            ret = last;
            if(iOffset > 0)
            {
                for(int i = 0; i < iOffset; ++i)
                {
                    if(!ret) break;
                    ret = ret->prev;
                }
            }
        }
        return ret;
    }

    // Member functions
    DECL_THISCALL_SIMPLE(RemoveAll, _ZN6List_c9RemoveAllEv, i32);
    DECL_THISCALL_SIMPLE(GetNumItems, _ZN6List_c11GetNumItemsEv, i32);
    DECL_THISCALL_HEAD(AppendItem, _ZN6List_c10AppendItemEP10ListItem_c, i32, ListItem_c* pListItem_c1)
    DECL_THISCALL_TAIL(AppendItem, pListItem_c1)
    DECL_THISCALL_HEAD(InsertAfterItem, _ZN6List_c15InsertAfterItemEP10ListItem_cS1_, i32, ListItem_c* pListItem_c1, ListItem_c* pListItem_c2)
    DECL_THISCALL_TAIL(InsertAfterItem, pListItem_c1, pListItem_c2)
    DECL_THISCALL_HEAD(InsertBeforeItem, _ZN6List_c16InsertBeforeItemEP10ListItem_cS1_, i32, ListItem_c* pListItem_c1, ListItem_c* pListItem_c2)
    DECL_THISCALL_TAIL(InsertBeforeItem, pListItem_c1, pListItem_c2)
    DECL_THISCALL_SIMPLE(RemoveTail, _ZN6List_c10RemoveTailEv, ListItem_c*);
    DECL_THISCALL_SIMPLE(GetTail, _ZN6List_c7GetTailEv, ListItem_c*);
DECL_CLASS_END()

template <typename ItemType>
struct TList_c : public List_c
{
    inline ItemType *GetHead(void)
    {
        return (ItemType*)(List_c::GetHead());
    }

    inline ItemType *RemoveHead(void)
    {
        return (ItemType*)(List_c::RemoveHead());
    }

    inline ItemType *GetNext(ItemType * pItem)
    {
        return (ItemType*)(List_c::GetNext(pItem));
    }

    inline ItemType *GetPrev(ItemType * pItem)
    {
        return (ItemType*)(List_c::GetPrev(pItem));
    }

    inline ItemType *GetItemOffset(bool bFromHead, int iOffset)
    {
        return (ItemType*)(List_c::GetItemOffset(bFromHead, iOffset));
    }
};

#endif
