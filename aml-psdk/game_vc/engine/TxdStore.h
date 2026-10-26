#ifndef __AML_PSDK_VCTXDSTORE_H
#define __AML_PSDK_VCTXDSTORE_H

#include <aml-psdk/game_vc/plugin.h>

struct RwStream;
struct RwTexDictionary;

DECL_CLASS(CTxdStore)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(AddTxdSlot, _ZN9CTxdStore10AddTxdSlotEPKc, i32, const char* name);
    DECL_FASTCALL_SIMPLE(RemoveTxdSlot, _ZN9CTxdStore13RemoveTxdSlotEi, void, i32 index);
    DECL_FASTCALL_SIMPLE(FindTxdSlot, _ZN9CTxdStore11FindTxdSlotEPKc, i32, const char* name);
    DECL_FASTCALL_SIMPLE(GetTxdName, _ZN9CTxdStore10GetTxdNameEi, char*, i32 index);
    DECL_FASTCALL_SIMPLE(LoadTxd, _ZN9CTxdStore7LoadTxdEiPKc, bool, i32 index, const char* filename);
    DECL_FASTCALL_SIMPLE(LoadTxdStream, _ZN9CTxdStore7LoadTxdEiP8RwStream, bool, i32 index, RwStream* stream);
    DECL_FASTCALL_SIMPLE(StartLoadTxd, _ZN9CTxdStore12StartLoadTxdEiP8RwStream, bool, i32 index, RwStream* stream);
    DECL_FASTCALL_SIMPLE(FinishLoadTxd, _ZN9CTxdStore13FinishLoadTxdEiP8RwStream, bool, i32 index, RwStream* stream);
    DECL_FASTCALL_SIMPLE(Create, _ZN9CTxdStore6CreateEi, void, i32 index);
    DECL_FASTCALL_SIMPLE(RemoveTxd, _ZN9CTxdStore9RemoveTxdEi, void, i32 index);
    DECL_FASTCALL_SIMPLE(SetCurrentTxd, _ZN9CTxdStore13SetCurrentTxdEi, void, i32 index);
    DECL_FASTCALL_SIMPLE(PushCurrentTxd, _ZN9CTxdStore14PushCurrentTxdEv, void);
    DECL_FASTCALL_SIMPLE(PopCurrentTxd, _ZN9CTxdStore13PopCurrentTxdEv, void);
    DECL_FASTCALL_SIMPLE(AddRef, _ZN9CTxdStore6AddRefEi, void, i32 index);
    DECL_FASTCALL_SIMPLE(RemoveRef, _ZN9CTxdStore9RemoveRefEi, void, i32 index);
    DECL_FASTCALL_SIMPLE(RemoveRefWithoutDelete, _ZN9CTxdStore22RemoveRefWithoutDeleteEi, void, i32 index);
    DECL_FASTCALL_SIMPLE(GetNumRefs, _ZN9CTxdStore10GetNumRefsEi, i32, i32 index);

    // STATIC values
    DECL_OBJECT_PLT(RwTexDictionary*, ms_pStoredTxd, BYBIT(0x396DF0, 0x57BBD8));
DECL_CLASS_END()

#define ms_pStoredTxd ms_pStoredTxd()

#endif // __AML_PSDK_VCTXDSTORE_H
