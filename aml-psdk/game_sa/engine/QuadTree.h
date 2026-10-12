#ifndef __AML_PSDK_SAQUADTREE_H
#define __AML_PSDK_SAQUADTREE_H

/*
    Plugin-SDK (Grand Theft Auto San Andreas) header file
    Authors: GTA Community. See more here
    https://github.com/DK22Pac/plugin-sdk
    Do not delete this comment block. Respect others' work!
*/

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/game_sa/base/Lists.h>
#include <aml-psdk/gta_base/Rect.h>

struct CQuadTreeNode;
template<class A, class B> struct CPool;
typedef CPool<CQuadTreeNode, CQuadTreeNode> CQuadTreeNodePool;

DECL_CLASS(CQuadTreeNode)
    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CQuadTreeNode, _ZN13CQuadTreeNodeC2ERK5CRecti, CRect const& rect, i32 startLevel)
    DECL_CTORCALL_ARG_TAIL(rect, startLevel)
    DECL_DTORCALL(CQuadTreeNode, _ZN13CQuadTreeNodeD2Ev);
    DECL_NEWCALL(CQuadTreeNode, BYBIT(_ZN13CQuadTreeNodenwEj, _ZN13CQuadTreeNodenwEm));
    DECL_DLCALL(CQuadTreeNode, _ZN13CQuadTreeNodedlEPv);

    // STATIC functions
    DECL_FASTCALL_SIMPLE(InitPool, _ZN13CQuadTreeNode8InitPoolEv, void);

    // Member functions
    DECL_THISCALL_HEAD(AddItem, _ZN13CQuadTreeNode7AddItemEPvRK5CRect, void, void *item, CRect const& rect)
    DECL_THISCALL_TAIL(AddItem, item, rect)

    DECL_THISCALL_NAMED_HEAD(DeleteItem1, DeleteItem, _ZN13CQuadTreeNode10DeleteItemEPv, void, void *item)
    DECL_THISCALL_TAIL(DeleteItem1, item)

    DECL_THISCALL_NAMED_HEAD(DeleteItem2, DeleteItem, _ZN13CQuadTreeNode10DeleteItemEPvRK5CRect, void, void *item, CRect const& rect)
    DECL_THISCALL_TAIL(DeleteItem2, item, rect)

    DECL_THISCALL_NAMED_HEAD(FindSector1, FindSector, _ZN13CQuadTreeNode10FindSectorERK5CRect, i32, CRect const& rect)
    DECL_THISCALL_TAIL(FindSector1, rect)

    DECL_THISCALL_NAMED_HEAD(FindSector2, FindSector, _ZN13CQuadTreeNode10FindSectorERK9CVector2D, i32, CVector2D const& posn)
    DECL_THISCALL_TAIL(FindSector2, posn)

    DECL_THISCALL_NAMED_HEAD(ForAllMatching1, ForAllMatching, _ZN13CQuadTreeNode14ForAllMatchingERK5CRectPFvS2_PvE, void,
        CRect const& rect, void (*callback)(CRect const&, void*))
    DECL_THISCALL_TAIL(ForAllMatching1, rect, callback)

    DECL_THISCALL_NAMED_HEAD(ForAllMatching2, ForAllMatching, _ZN13CQuadTreeNode14ForAllMatchingERK9CVector2DPFvS2_PvE, void,
        CVector2D const& posn, void (*callback)(CVector2D const&, void*))
    DECL_THISCALL_TAIL(ForAllMatching2, posn, callback)

    DECL_THISCALL_HEAD(GetAll, _ZN13CQuadTreeNode6GetAllER18CPtrListSingleLink, void, CPtrListSingleLink& list)
    DECL_THISCALL_TAIL(GetAll, list)

    DECL_THISCALL_NAMED_HEAD(GetAllMatching1, GetAllMatching, _ZN13CQuadTreeNode14GetAllMatchingERK5CRectR18CPtrListSingleLink, void,
        CRect const& rect, CPtrListSingleLink& list)
    DECL_THISCALL_TAIL(GetAllMatching1, rect, list)

    DECL_THISCALL_NAMED_HEAD(GetAllMatching2, GetAllMatching, _ZN13CQuadTreeNode14GetAllMatchingERK9CVector2DR18CPtrListSingleLink, void,
        CVector2D const& posn, CPtrListSingleLink& list)
    DECL_THISCALL_TAIL(GetAllMatching2, posn, list)

    DECL_THISCALL_HEAD(InSector, _ZN13CQuadTreeNode8InSectorERK5CRecti, bool, CRect const& rect, i32 sector)
    DECL_THISCALL_TAIL(InSector, rect, sector)

    // STATIC values
    DECL_OBJECT_PLT(CQuadTreeNodePool*, ms_pQuadTreeNodePool, BYBIT(0x679570, 0x850AF0));

    // Member values
    CRect              rect;
    CPtrListSingleLink itemList;
    CQuadTreeNode     *childrens[4];
    i32                level;
DECL_CLASS_END()
CHECKSIZE(CQuadTreeNode, 0x28, 0x40);

#define ms_pQuadTreeNodePool ms_pQuadTreeNodePool()

#endif // __AML_PSDK_SAQUADTREE_H
