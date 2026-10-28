#ifndef __AML_PSDK_VCLISTS_H
#define __AML_PSDK_VCLISTS_H

#include <aml-psdk/game_vc/plugin.h>

struct CSector;
struct CPtrList;

DECL_CLASS(CPtrNode)
    // Construct/Deconstruct functions
    CPtrNode() {}
    explicit CPtrNode(void* item) : m_pVoid(item) {}
    DECL_NEWCALL(CPtrNode, BYBIT(_ZN8CPtrNodenwEj, _ZN8CPtrNodenwEm));
    DECL_DLCALL(CPtrNode, _ZN8CPtrNodedlEPv);

    // Member values
    void* m_pVoid;
    CPtrNode* m_pNext;
    CPtrNode* m_pPrev;
DECL_CLASS_END()
CHECKSIZE(CPtrNode, 0xC, 0x18);

DECL_CLASS(CPtrList)
    // Construct/Deconstruct functions
    CPtrList() : m_pHead(nullptr) {}
    DECL_DTORCALL(CPtrList, _ZN8CPtrListD2Ev);
    CPtrList(CPtrList const&) = delete;
    CPtrList& operator=(CPtrList const&) = delete;

    // Member functions
    DECL_THISCALL_SIMPLE(Flush, _ZN8CPtrList5FlushEv, void);

    inline void Add(CPtrNode* node)
    {
        node->m_pNext = nullptr;
        node->m_pPrev = m_pHead;
        if(m_pHead) m_pHead->m_pNext = node;
        m_pHead = node;
    }
    inline void Remove(CPtrNode* node)
    {
        if(m_pHead == node) m_pHead = node->m_pPrev;
        if(node->m_pNext) node->m_pNext->m_pPrev = node->m_pPrev;
        if(node->m_pPrev) node->m_pPrev->m_pNext = node->m_pNext;
    }
    inline CPtrNode* GetNode() const { return m_pHead; }

    // Member values
    CPtrNode* m_pHead;
DECL_CLASS_END()
CHECKSIZE(CPtrList, 0x4, 0x8);

DECL_CLASS(CEntryInfoNode)
    // Construct/Deconstruct functions
    CEntryInfoNode() {}
    CEntryInfoNode(CPtrList* list, CPtrNode* node, CSector* sector)
        : m_pPtrList(list), m_pPtrNode(node), m_pSector(sector) {}
    DECL_NEWCALL(CEntryInfoNode, BYBIT(_ZN14CEntryInfoNodenwEj, _ZN14CEntryInfoNodenwEm));
    DECL_DLCALL(CEntryInfoNode, _ZN14CEntryInfoNodedlEPv);

    // Member values
    CPtrList* m_pPtrList;
    CPtrNode* m_pPtrNode;
    CSector* m_pSector;
    CEntryInfoNode* m_pNext;
    CEntryInfoNode* m_pPrev;
DECL_CLASS_END()
CHECKSIZE(CEntryInfoNode, 0x14, 0x28);

DECL_CLASS(CEntryInfoList)
    // Construct/Deconstruct functions
    CEntryInfoList() : m_pLastEntry(nullptr) {}
    ~CEntryInfoList() { Flush(); }
    CEntryInfoList(CEntryInfoList const&) = delete;
    CEntryInfoList& operator=(CEntryInfoList const&) = delete;

    // Member functions
    DECL_THISCALL_SIMPLE(Flush, _ZN14CEntryInfoList5FlushEv, void);

    inline void Add(CEntryInfoNode* node)
    {
        node->m_pNext = nullptr;
        node->m_pPrev = m_pLastEntry;
        if(m_pLastEntry) m_pLastEntry->m_pNext = node;
        m_pLastEntry = node;
    }
    inline void Remove(CEntryInfoNode* node)
    {
        if(m_pLastEntry == node) m_pLastEntry = node->m_pPrev;
        if(node->m_pNext) node->m_pNext->m_pPrev = node->m_pPrev;
        if(node->m_pPrev) node->m_pPrev->m_pNext = node->m_pNext;
    }

    // Member values
    CEntryInfoNode* m_pLastEntry;
DECL_CLASS_END()
CHECKSIZE(CEntryInfoList, 0x4, 0x8);

#endif // __AML_PSDK_VCLISTS_H
