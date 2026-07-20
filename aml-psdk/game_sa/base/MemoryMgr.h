#ifndef __AML_PSDK_SAMEMORYMGR_H
#define __AML_PSDK_SAMEMORYMGR_H

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/game_sa/base/Lists.h>

// These are enums/typedefs and cannot be forward declared -- make
// sure an #include above provides them:
//   CStack, size_t

DECL_CLASS(CMemoryMgr)
    // Functions
    DECL_FASTCALL_SIMPLE(Init, _ZN10CMemoryMgr4InitEv, void);
    DECL_FASTCALL_SIMPLE(Shutdown, _ZN10CMemoryMgr8ShutdownEv, void);
    DECL_FASTCALL_SIMPLE(InternalMalloc, BYBIT(_ZN10CMemoryMgr14InternalMallocEj, _ZN10CMemoryMgr14InternalMallocEm), void*, size_t size);
    DECL_FASTCALL_SIMPLE(InternalRealloc, BYBIT(_ZN10CMemoryMgr15InternalReallocEPvj, _ZN10CMemoryMgr15InternalReallocEPvm), void*, void* pMem, size_t size);
    DECL_FASTCALL_SIMPLE(Free, _ZN10CMemoryMgr4FreeEPv, void, void* pMem);
    DECL_FASTCALL_SIMPLE(Malloc, BYBIT(_ZN10CMemoryMgr6MallocEj, _ZN10CMemoryMgr6MallocEm), void*, size_t size);
    DECL_FASTCALL_SIMPLE(Realloc, BYBIT(_ZN10CMemoryMgr7ReallocEPvj, _ZN10CMemoryMgr7ReallocEPvm), void*, void* pMem, size_t size);
    DECL_FASTCALL_SIMPLE(Calloc, BYBIT(_ZN10CMemoryMgr6CallocEjj, _ZN10CMemoryMgr6CallocEmm), void*, size_t numObj, size_t sizeObj);
    DECL_FASTCALL_SIMPLE(InitScratchPad, _ZN10CMemoryMgr14InitScratchPadEv, void);
    DECL_FASTCALL_SIMPLE(MallocFromScratchPad, BYBIT(_ZN10CMemoryMgr20MallocFromScratchPadEj, _ZN10CMemoryMgr20MallocFromScratchPadEm), void*, size_t size);
    DECL_FASTCALL_SIMPLE(RegisterMalloc, _ZN10CMemoryMgr14RegisterMallocEPv, void, void* pMem);
    DECL_FASTCALL_SIMPLE(MallocAlignFromScratchPad, BYBIT(_ZN10CMemoryMgr25MallocAlignFromScratchPadEjj, _ZN10CMemoryMgr25MallocAlignFromScratchPadEmm), void*, size_t size, size_t align);
    DECL_FASTCALL_SIMPLE(LockScratchPad, _ZN10CMemoryMgr14LockScratchPadEv, void);
    DECL_FASTCALL_SIMPLE(ReleaseScratchPad, _ZN10CMemoryMgr17ReleaseScratchPadEv, void);
    DECL_FASTCALL_SIMPLE(MallocAlign, BYBIT(_ZN10CMemoryMgr11MallocAlignEjj, _ZN10CMemoryMgr11MallocAlignEmm), void*, size_t size, size_t align);
    DECL_FASTCALL_SIMPLE(FreeAlign, _ZN10CMemoryMgr9FreeAlignEPv, void, void* pMem);
    DECL_FASTCALL_SIMPLE(MoveMemory, _ZN10CMemoryMgr10MoveMemoryEPv, void*, void* pMem);
    DECL_FASTCALL_SIMPLE(MoveMemory1, _ZN10CMemoryMgr10MoveMemoryEPvPS0_i, void*, void* pMem, void** pMemAlign, i32 align);
    DECL_FASTCALL_SIMPLE(SetRestrictMemoryMove, _ZN10CMemoryMgr21SetRestrictMemoryMoveEb, void, bool bRestrict);
    DECL_FASTCALL_SIMPLE(GetLargestFreeBlock, _ZN10CMemoryMgr19GetLargestFreeBlockEv, u32);
    DECL_FASTCALL_SIMPLE(GetSizeOfHoles, _ZN10CMemoryMgr14GetSizeOfHolesEv, u32);
    DECL_FASTCALL_SIMPLE(PrintFrequencies, _ZN10CMemoryMgr16PrintFrequenciesEv, void);
    DECL_FASTCALL_SIMPLE(InitMemoryTracking, _ZN10CMemoryMgr18InitMemoryTrackingEi, void, i32 numIds);
    DECL_FASTCALL_SIMPLE(PushMemId, _ZN10CMemoryMgr9PushMemIdEi, void, i32 id);
    DECL_FASTCALL_SIMPLE(PopMemId, _ZN10CMemoryMgr8PopMemIdEv, void);
    DECL_FASTCALL_SIMPLE(RegisterFree, _ZN10CMemoryMgr12RegisterFreeEPv, void, void* pMem);
    DECL_FASTCALL_SIMPLE(GetMemoryUsed, _ZN10CMemoryMgr13GetMemoryUsedEi, i32, i32 id);
    DECL_FASTCALL_SIMPLE(GetBlocksUsed, _ZN10CMemoryMgr13GetBlocksUsedEi, i32, i32 id);

    // Static values
    DECL_VALUE_PLT_I32(m_memUsed, BYBIT(0x67920C, 0x850438));
    DECL_VALUE_ADDR_BOOL(m_bMallocHintDebugging, BYBIT(0xA83E50, 0xD284DC));  // no .got slot: addressed PC-relatively
    DECL_VALUE_ADDR_U32(m_minLargeAllocation, BYBIT(0xA83E54, 0xD284E0));  // no .got slot: addressed PC-relatively
    DECL_VALUE_ADDR_U32(m_largeAllocation, BYBIT(0xA83E58, 0xD284E4));  // no .got slot: addressed PC-relatively
    typedef CStack<int,16> tm_idStack;
    DECL_OBJECT_PLT(tm_idStack, m_idStack, BYBIT(0x6773AC, 0x84C790));
    DECL_VALUE_PLT_I32(m_id, BYBIT(0x677290, 0x84C558));
    DECL_OBJECT_PLT(i32*, m_pMemUsedArray, BYBIT(0x678848, 0x84F0B0));
    DECL_VALUE_PLT_I32(m_blocksUsed, BYBIT(0x677494, 0x84C960));
    DECL_OBJECT_PLT(i32*, m_pBlockArray, BYBIT(0x67703C, 0x84C0B0));
    DECL_VALUE_ADDR_I32(m_idCapture, BYBIT(0xA83EB0, 0xD28548));  // no .got slot: addressed PC-relatively
DECL_CLASS_END()

#define m_memUsed m_memUsed()
#define m_bMallocHintDebugging m_bMallocHintDebugging()
#define m_minLargeAllocation m_minLargeAllocation()
#define m_largeAllocation m_largeAllocation()
#define m_idStack m_idStack()
#define m_id m_id()
#define m_pMemUsedArray m_pMemUsedArray()
#define m_blocksUsed m_blocksUsed()
#define m_pBlockArray m_pBlockArray()
#define m_idCapture m_idCapture()

#endif // __AML_PSDK_SAMEMORYMGR_H
