#ifndef __AML_PSDK_SAIPLSTORE_H
#define __AML_PSDK_SAIPLSTORE_H

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

struct CEntity;
struct CQuadTreeNode;
template<class A, class B> struct CPool;

struct IplDef
{
    CRect m_boundBox;
    char m_szName[18];
    i16 m_nMinBuildingId;
    i16 m_nMaxBuildingId;
    i16 m_nMinDummyId;
    i16 m_nMaxDummyId;
    i16 m_nRelatedIpl;
    bool m_bInterior;
    bool m_bLoaded;
    bool m_bLoadRequest;
    bool m_bDisableDynamicStreaming;
    bool m_bIgnoreWhenDeleted;
    bool m_bLargeIpl;
};
CHECKSIZE(IplDef, 0x34, 0x34);

typedef CPool<IplDef, IplDef> CIplPool;

DECL_CLASS(CIplStore)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(Initialise, _ZN9CIplStore10InitialiseEv, void);
    DECL_FASTCALL_SIMPLE(AddIplSlot, _ZN9CIplStore10AddIplSlotEPKc, i32, char const* name);
    DECL_FASTCALL_SIMPLE(Shutdown, _ZN9CIplStore8ShutdownEv, void);
    DECL_FASTCALL_SIMPLE(RemoveAllIpls, _ZN9CIplStore13RemoveAllIplsEv, void);
    DECL_FASTCALL_SIMPLE(RemoveIplSlot, _ZN9CIplStore13RemoveIplSlotEi, void, i32 iplSlotIndex);
    DECL_FASTCALL_SIMPLE(RemoveIpl, _ZN9CIplStore9RemoveIplEi, void, i32 iplSlotIndex);
    DECL_FASTCALL_SIMPLE(GetIplName, _ZN9CIplStore10GetIplNameEi, const char*, i32 iplSlotIndex);
    DECL_FASTCALL_SIMPLE(SetIsInterior, _ZN9CIplStore13SetIsInteriorEib, void, i32 iplSlotIndex, bool isInterior);
    DECL_FASTCALL_SIMPLE(FindIplSlot, _ZN9CIplStore11FindIplSlotEPKc, i32, char const* name);
    DECL_FASTCALL_SIMPLE(LoadIpl, _ZN9CIplStore7LoadIplEiPhi, bool, i32 iplSlotIndex, u8* data, i32 dataSize);
    DECL_FASTCALL_SIMPLE(LoadIplBoundingBox, _ZN9CIplStore18LoadIplBoundingBoxEiPhi, bool, i32 iplSlotIndex, u8* data, i32 dataSize);
    DECL_FASTCALL_SIMPLE(GetIplEntityIndexArray, _ZN9CIplStore22GetIplEntityIndexArrayEi, CEntity**, i32 arrayIndex);
    DECL_FASTCALL_SIMPLE(IncludeEntity, _ZN9CIplStore13IncludeEntityEiP7CEntity, void, i32 iplSlotIndex, CEntity* entity);
    DECL_FASTCALL_SIMPLE(GetBoundingBox, _ZN9CIplStore14GetBoundingBoxEi, CRect&, i32 iplSlotIndex);
    DECL_FASTCALL_SIMPLE(AddIplsNeededAtPosn, _ZN9CIplStore19AddIplsNeededAtPosnERK7CVector, void, CVector const& posn);
    DECL_FASTCALL_SIMPLE(ClearIplsNeededAtPosn, _ZN9CIplStore21ClearIplsNeededAtPosnEv, void);
    DECL_FASTCALL_SIMPLE(EnableDynamicStreaming, _ZN9CIplStore22EnableDynamicStreamingEib, void, i32 iplSlotIndex, bool enable);
    DECL_FASTCALL_SIMPLE(FindRelatedIplSlot, _ZN9CIplStore18FindRelatedIplSlotEPKc, i32, char const* pName);
    DECL_FASTCALL_SIMPLE(SetupRelatedIpls, _ZN9CIplStore16SetupRelatedIplsEPKciPP7CEntity, i32, char const* iplName, i32 entityArraysIndex, CEntity** instances);
    DECL_FASTCALL_SIMPLE(RemoveRelatedIpls, _ZN9CIplStore17RemoveRelatedIplsEi, void, i32 entityArraysIndex);
    DECL_FASTCALL_SIMPLE(SetIplsRequired, _ZN9CIplStore15SetIplsRequiredERK7CVectori, void, CVector const& posn, i32 playerNumber);
    DECL_FASTCALL_SIMPLE(LoadIpls, _ZN9CIplStore8LoadIplsE7CVectorb, void, CVector posn, bool bAvoidLoadInPlayerVehicleMovingDirection);
    DECL_FASTCALL_SIMPLE(EnsureIplsAreInMemory, _ZN9CIplStore21EnsureIplsAreInMemoryERK7CVector, void, CVector const& posn);
    DECL_FASTCALL_SIMPLE(RequestIpls, _ZN9CIplStore11RequestIplsERK7CVectori, void, CVector const& posn, i32 playerNumber);
    DECL_FASTCALL_SIMPLE(HaveIplsLoaded, _ZN9CIplStore14HaveIplsLoadedERK7CVectori, bool, CVector const& coords, i32 playerNumber);
    DECL_FASTCALL_SIMPLE(LoadAllRemainingIpls, _ZN9CIplStore20LoadAllRemainingIplsEv, void);
    DECL_FASTCALL_SIMPLE(RequestIplAndIgnore, _ZN9CIplStore19RequestIplAndIgnoreEi, void, i32 iplSlotIndex);
    DECL_FASTCALL_SIMPLE(RemoveIplAndIgnore, _ZN9CIplStore18RemoveIplAndIgnoreEi, void, i32 iplSlotIndex);
    DECL_FASTCALL_SIMPLE(RemoveIplWhenFarAway, _ZN9CIplStore20RemoveIplWhenFarAwayEi, void, i32 iplSlotIndex);
    DECL_FASTCALL_SIMPLE(GetNewIplEntityIndexArray, _ZN9CIplStore25GetNewIplEntityIndexArrayEi, i32, i32 entitiesCount);
    DECL_FASTCALL_SIMPLE(Save, _ZN9CIplStore4SaveEv, bool);
    DECL_FASTCALL_SIMPLE(Load, _ZN9CIplStore4LoadEv, bool);

    // STATIC values
    DECL_OBJECT_PLT(CIplPool*, ms_pPool, BYBIT(0x6770B8, 0x84C1A8));
    DECL_VALUE_SYM_BOOL(m_bOnlyIplBoundingBoxes, _ZN9CIplStore8m_onlyBBE);
    DECL_OBJECT_PLT(CQuadTreeNode*, ms_pQuadTree, BYBIT(0x678D10, 0x84FA48));
DECL_CLASS_END()

#define ms_pPool ms_pPool()
#define m_bOnlyIplBoundingBoxes m_bOnlyIplBoundingBoxes()
#pragma pop_macro("ms_pQuadTree")
#ifndef ms_pQuadTree
#define ms_pQuadTree ms_pQuadTree()
#endif

#endif // __AML_PSDK_SAIPLSTORE_H
