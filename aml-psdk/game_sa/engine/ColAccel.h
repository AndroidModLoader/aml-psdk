#ifndef __AML_PSDK_SACOLACCEL_H
#define __AML_PSDK_SACOLACCEL_H

#include "../plugin.h"
#include "../base/ColModel.h"
#include "ColStore.h"
#include "IplStore.h"

struct CColAccelItem
{
    CBoundingBox m_bounds;
    i32 m_iModelIndex;
    u16 m_level : 8;
    u16 m_hasCollisionVols : 8;
};
CHECKSIZE(CColAccelItem, 0x30, 0x30);

struct CIplAccelItem
{
    i32 m_iIndex;
    i32 m_iLodIndex;
    i32 m_iModelIndex;
    i32 m_iLodModelIndex;
    i32 m_iActions;
};
CHECKSIZE(CIplAccelItem, 0x14, 0x14);

struct CColDefAccelItem
{
    CRect bb;
    i16 firstModel;
    i16 lastModel;
    bool inMemoryAlways;
    bool interior;
};
CHECKSIZE(CColDefAccelItem, 0x18, 0x18);

DECL_CLASS(CColAccel)
    enum CacheState
    {
        STATE_NONE = 0,
        STATE_SAVING = 1,
        STATE_LOADING = 2,
    };

    enum
    {
        MAX_IPLDEFS = 256,
    };

    // STATIC functions
    DECL_FASTCALL_SIMPLE(isCacheLoading, _ZN9CColAccel14isCacheLoadingEv, bool);
    DECL_FASTCALL_SIMPLE(startCache, _ZN9CColAccel10startCacheEv, void);
    DECL_FASTCALL_SIMPLE(endCache, _ZN9CColAccel8endCacheEv, void);
    DECL_FASTCALL_SIMPLE(cacheLoadCol, _ZN9CColAccel12cacheLoadColEv, void);
    DECL_FASTCALL_SIMPLE(addCacheCol, _ZN9CColAccel11addCacheColEiRK9CColModel, void, i32 iModelIndex, CColModel const& r_colModel);
    DECL_FASTCALL_SIMPLE(cacheIPLSection, _ZN9CColAccel15cacheIPLSectionEPP7CEntityi, void, CEntity** ppListIn, i32 iListSize);
    DECL_FASTCALL_SIMPLE(addIPLEntity, _ZN9CColAccel12addIPLEntityEPP7CEntityii, void, CEntity** ppListIn, i32 iListSize, i32 iEntityIndex);
    DECL_FASTCALL_SIMPLE(setIplDef, _ZN9CColAccel9setIplDefEi6IplDef, void, i32 index, IplDef rect);
    DECL_FASTCALL_SIMPLE(getIplDef, _ZN9CColAccel9getIplDefEi, IplDef, i32 index);
    DECL_FASTCALL_SIMPLE(addColDef, _ZN9CColAccel9addColDefE6ColDef, void, ColDef colDef);
    DECL_FASTCALL_SIMPLE(getColDef, _ZN9CColAccel9getColDefER6ColDef, void, ColDef& colDef);

    // STATIC values
    DECL_OBJECT_PLT(CColAccel::CacheState, m_iCacheState, BYBIT(0x677C00, 0x84D820));
    DECL_OBJECT_PLT(char*, mp_cCacheName, BYBIT(0x676BFC, 0x84B840));
    DECL_OBJECT_PLT(CColAccelItem*, mp_caccColItems, BYBIT(0x679474, 0x850900));
    DECL_VALUE_PLT_I32(m_iNumColItems, BYBIT(0x677320, 0x84C678));
    DECL_VALUE_PLT_I32(m_iCachingColSize, BYBIT(0x67681C, 0x84B090));
    DECL_OBJECT_PLT(CIplAccelItem*, mp_caccIPLItems, BYBIT(0x679C90, 0x851938));
    DECL_VALUE_PLT_I32(m_iNumIPLItems, BYBIT(0x67969C, 0x850D48));
    DECL_VALUE_PLT_I32(m_iCachingIPLSize, BYBIT(0x677B68, 0x84D6F0));
    DECL_OBJECT_PLT(i32*, m_iSectionSize, BYBIT(0x675F94, 0x849F98));
    DECL_VALUE_PLT_I32(m_iNumSections, BYBIT(0x6786C0, 0x84EDA8));
    DECL_OBJECT_PLT(IplDef*, m_iplDefs, BYBIT(0x67618C, 0x84A378));
    DECL_OBJECT_PLT(CColDefAccelItem*, m_colBounds, BYBIT(0x6777FC, 0x84D020));
    DECL_VALUE_PLT_I32(m_iNumColBounds, BYBIT(0x678ED8, 0x84FDD8));
DECL_CLASS_END()

#endif // __AML_PSDK_SACOLACCEL_H
