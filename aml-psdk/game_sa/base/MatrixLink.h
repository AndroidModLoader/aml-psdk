#ifndef __AML_PSDK_SAMATRIXLINK_H
#define __AML_PSDK_SAMATRIXLINK_H

#include "Matrix.h"

struct CPlaceable;

DECL_CLASS(CMatrixLink)
    // Member functions
    DECL_THISCALL_HEAD(Insert, _ZN11CMatrixLink6InsertEPS_, void, CMatrixLink* link)
    DECL_THISCALL_TAIL(Insert, link)
    DECL_THISCALL_SIMPLE(Remove, _ZN11CMatrixLink6RemoveEv, void);

    inline CMatrixLink* GetPrevious() const { return m_pPrev; }
    inline CMatrixLink* GetNext() const { return m_pNext; }

    // Member values
    CMatrix matrix;
    CPlaceable* pPlaceable;
    CMatrixLink* m_pPrev;
    CMatrixLink* m_pNext;
DECL_CLASS_END()
CHECKSIZE(CMatrixLink, 0x54, 0x68);

DECL_CLASS(CMatrixLinkList)
    // Construct/Deconstruct functions
    CMatrixLinkList() : m_pStore(NULL) {}
    DECL_DTORCALL(CMatrixLinkList, _ZN15CMatrixLinkListD2Ev);

    // Member functions
    // Call Shutdown before destroying an initialised list.
    DECL_THISCALL_HEAD(Init, _ZN15CMatrixLinkList4InitEi, void, i32 numMatrices)
    DECL_THISCALL_TAIL(Init, numMatrices)
    DECL_THISCALL_SIMPLE(Shutdown, _ZN15CMatrixLinkList8ShutdownEv, void);
    DECL_THISCALL_SIMPLE(AddToList1, _ZN15CMatrixLinkList10AddToList1Ev, CMatrixLink*);
    DECL_THISCALL_SIMPLE(AddToList2, _ZN15CMatrixLinkList10AddToList2Ev, CMatrixLink*);
    DECL_THISCALL_HEAD(MoveToFreeList, _ZN15CMatrixLinkList14MoveToFreeListEP11CMatrixLink, void, CMatrixLink* link)
    DECL_THISCALL_TAIL(MoveToFreeList, link)
    DECL_THISCALL_HEAD(MoveToList1, _ZN15CMatrixLinkList11MoveToList1EP11CMatrixLink, void, CMatrixLink* link)
    DECL_THISCALL_TAIL(MoveToList1, link)
    DECL_THISCALL_HEAD(MoveToList2, _ZN15CMatrixLinkList11MoveToList2EP11CMatrixLink, void, CMatrixLink* link)
    DECL_THISCALL_TAIL(MoveToList2, link)
    DECL_THISCALL_SIMPLE(GetNumFree, _ZN15CMatrixLinkList10GetNumFreeEv, i32);
    DECL_THISCALL_SIMPLE(GetNumUsed1, _ZN15CMatrixLinkList11GetNumUsed1Ev, i32);
    DECL_THISCALL_SIMPLE(GetNumUsed2, _ZN15CMatrixLinkList11GetNumUsed2Ev, i32);

    // Member values
    CMatrixLink m_firstLink1;
    CMatrixLink m_lastLink1;
    CMatrixLink m_firstLink2;
    CMatrixLink m_lastLink2;
    CMatrixLink m_firstFreeLink;
    CMatrixLink m_lastFreeLink;
    CMatrixLink* m_pStore;
DECL_CLASS_END()
CHECKSIZE(CMatrixLinkList, 0x1FC, 0x278);

#endif // __AML_PSDK_SAMATRIXLINK_H
