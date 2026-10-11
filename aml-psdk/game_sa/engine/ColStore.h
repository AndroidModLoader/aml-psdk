#ifndef __AML_PSDK_SACOLSTORE_H
#define __AML_PSDK_SACOLSTORE_H

/*
    Plugin-SDK (Grand Theft Auto San Andreas) header file
    Authors: GTA Community. See more here
    https://github.com/DK22Pac/plugin-sdk
    Do not delete this comment block. Respect others' work!
*/

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/gta_base/Vector.h>
#include <aml-psdk/gta_base/Rect.h>

#pragma push_macro("ms_pQuadTree")
#undef ms_pQuadTree

struct CQuadTreeNode;
template<class A, class B> struct CPool;

struct ColDef
{
    CRect m_Area;
    char name[18];
    i16 m_nModelIdStart;
    i16 m_nModelIdEnd;
    i16 m_nRefCount;
    bool m_bActive;
    bool m_bCollisionIsRequired;
    bool m_bProcedural;
    bool m_bInterior;
};
CHECKSIZE(ColDef, 0x2C, 0x2C);

typedef CPool<ColDef, ColDef> CColPool;

DECL_CLASS(CColStore)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(Initialise, _ZN9CColStore10InitialiseEv, void);
    DECL_FASTCALL_SIMPLE(AddColSlot, _ZN9CColStore10AddColSlotEPKc, i32, char const* name);
    DECL_FASTCALL_SIMPLE(Shutdown, _ZN9CColStore8ShutdownEv, void);
    DECL_FASTCALL_SIMPLE(RemoveColSlot, _ZN9CColStore13RemoveColSlotEi, void, i32 colSlot);
    DECL_FASTCALL_SIMPLE(RemoveCol, _ZN9CColStore9RemoveColEi, void, i32 colSlot);
    DECL_FASTCALL_SIMPLE(FindColSlot, _ZN9CColStore11FindColSlotEPKc, i32, char const* name);
    DECL_FASTCALL_SIMPLE(LoadCol1, _ZN9CColStore7LoadColEiPKc, void, i32 colSlot, char const* filename);
    DECL_FASTCALL_SIMPLE(LoadCol2, _ZN9CColStore7LoadColEiPhi, bool, i32 colSlot, u8* data, i32 dataSize);
    DECL_FASTCALL_SIMPLE(AddRef, _ZN9CColStore6AddRefEi, void, i32 colNum);
    DECL_FASTCALL_SIMPLE(RemoveRef, _ZN9CColStore9RemoveRefEi, void, i32 colNum);
    DECL_FASTCALL_SIMPLE(GetBoundingBox, _ZN9CColStore14GetBoundingBoxEi, CRect&, i32 colSlot);
    DECL_FASTCALL_SIMPLE(IncludeModelIndex, _ZN9CColStore17IncludeModelIndexEii, void, i32 colSlot, i32 modelId);
    DECL_FASTCALL_SIMPLE(AddCollisionNeededAtPosn, _ZN9CColStore24AddCollisionNeededAtPosnERK7CVector, void, CVector const& pos);
    DECL_FASTCALL_SIMPLE(SetCollisionRequired, _ZN9CColStore20SetCollisionRequiredERK7CVectori, void, CVector const& pos, i32 areaCode);
    DECL_FASTCALL_SIMPLE(LoadCollision, _ZN9CColStore13LoadCollisionE7CVectorb, void, CVector pos, bool bIgnorePlayerVeh);
    DECL_FASTCALL_SIMPLE(EnsureCollisionIsInMemory, _ZN9CColStore25EnsureCollisionIsInMemoryERK7CVector, void, CVector const& pos);
    DECL_FASTCALL_SIMPLE(RequestCollision, _ZN9CColStore16RequestCollisionERK7CVectori, void, CVector const& pos, i32 areaCode);
    DECL_FASTCALL_SIMPLE(HasCollisionLoaded, _ZN9CColStore18HasCollisionLoadedERK7CVectori, bool, CVector const& pos, i32 areaCode);
    DECL_FASTCALL_SIMPLE(RemoveAllCollision, _ZN9CColStore18RemoveAllCollisionEv, void);
    DECL_FASTCALL_SIMPLE(LoadAllBoundingBoxes, _ZN9CColStore20LoadAllBoundingBoxesEv, void);
    DECL_FASTCALL_SIMPLE(LoadAllCollision, _ZN9CColStore16LoadAllCollisionEv, void);
    DECL_FASTCALL_SIMPLE(BoundingBoxesPostProcess, _ZN9CColStore24BoundingBoxesPostProcessEv, void);

    // Helper functions
    static void LoadCol(i32 colSlot, char const* filename)
    {
        return LoadCol1(colSlot, filename);
    }
    static bool LoadCol(i32 colSlot, u8* data, i32 dataSize)
    {
        return LoadCol2(colSlot, data, dataSize);
    }

    // STATIC values
    DECL_OBJECT_PLT(CColPool*, ms_pColPool, BYBIT(0x679660, 0x850CD0));
    DECL_VALUE_SYM_BOOL(m_bOnlyColBoundingBoxes, _ZN9CColStore8m_onlyBBE);
    DECL_OBJECT_PLT(CQuadTreeNode*, ms_pQuadTree, BYBIT(0x679F4C, 0x851EA0));
DECL_CLASS_END()

#define ms_pColPool ms_pColPool()
#define m_bOnlyColBoundingBoxes m_bOnlyColBoundingBoxes()
#pragma pop_macro("ms_pQuadTree")
#ifndef ms_pQuadTree
#define ms_pQuadTree ms_pQuadTree()
#endif

#endif // __AML_PSDK_SACOLSTORE_H
