#ifndef __AML_PSDK_SATXDSTORE_H
#define __AML_PSDK_SATXDSTORE_H

#include <aml-psdk/game_sa/other/Pools.h>



struct TextureDatabaseRuntime;
struct RwTexture;
struct RwTexDictionary;
struct RwStream;

struct TxdDef
{
    RwTexDictionary *m_pRwDictionary;
    int16_t          m_wRefsCount;
    int16_t          m_wParentIndex;
    uint32_t         m_hash;
    char             m_szName[20];
    char             m_szDBName[20];
    bool             m_bKeepCPU;
};

typedef CPool<TxdDef,TxdDef> CTxdPool;

DECL_CLASS(CTxdStore)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(LoadTxd1, _ZN9CTxdStore7LoadTxdEiPKc, bool, i32 arg1, char const* pchar2);
    DECL_FASTCALL_SIMPLE(LoadTxd2, _ZN9CTxdStore7LoadTxdEiP8RwStream, bool, i32 index, RwStream* pStream);
    DECL_FASTCALL_SIMPLE(FinishLoadTxd, _ZN9CTxdStore13FinishLoadTxdEiP8RwStream, bool, i32 index, RwStream* stream);

    // Functions
    DECL_FASTCALL_SIMPLE(Initialise, _ZN9CTxdStore10InitialiseEv, void);
    DECL_FASTCALL_SIMPLE(AddTxdSlot, _ZN9CTxdStore10AddTxdSlotEPKcS1_b, i32, const char *pName, const char *dbName, bool keepCPU);
    DECL_FASTCALL_SIMPLE(TxdStoreFindCB, _ZN9CTxdStore14TxdStoreFindCBEPKc, RwTexture*, const char *pTexname);
    DECL_FASTCALL_SIMPLE(PluginAttach, _ZN9CTxdStore12PluginAttachEv, bool);
    DECL_FASTCALL_SIMPLE(Shutdown, _ZN9CTxdStore8ShutdownEv, void);
    DECL_FASTCALL_SIMPLE(GameShutdown, _ZN9CTxdStore12GameShutdownEv, void);
    DECL_FASTCALL_SIMPLE(GetNumRefs, _ZN9CTxdStore10GetNumRefsEi, i32, i32 index);
    DECL_FASTCALL_SIMPLE(RemoveTxdSlot, _ZN9CTxdStore13RemoveTxdSlotEi, void, i32 index);
    DECL_FASTCALL_SIMPLE(FindTxdSlot, _ZN9CTxdStore11FindTxdSlotEPKc, i32, const char *pName);
    DECL_FASTCALL_SIMPLE(FindTxdSlotFromHashKey, _ZN9CTxdStore22FindTxdSlotFromHashKeyEi, i32, const i32 hashKey);
    DECL_FASTCALL_SIMPLE(LoadTxd, _ZN9CTxdStore7LoadTxdEiPKc, bool, i32 index, const char *pFilename);
    DECL_FASTCALL_SIMPLE(SetupTxdParent, _ZN9CTxdStore14SetupTxdParentEi, void, i32 index);
    DECL_FASTCALL_SIMPLE(SetTxdParent, _ZN9CTxdStore12SetTxdParentEP15RwTexDictionaryS1_, void, RwTexDictionary *pTxd, RwTexDictionary *pParent);
    DECL_FASTCALL_SIMPLE(AddRef, _ZN9CTxdStore6AddRefEi, void, i32 index);
    //DECL_FASTCALL_SIMPLE(LoadTxd, _ZN9CTxdStore7LoadTxdEiP8RwStream, void, i32 index, RwStream *pStream);
    DECL_FASTCALL_SIMPLE(StartLoadTxd, _ZN9CTxdStore12StartLoadTxdEiP8RwStream, bool, i32 index, RwStream *pStream);
    DECL_FASTCALL_SIMPLE(Create, _ZN9CTxdStore6CreateEi, void, i32 index);
    DECL_FASTCALL_SIMPLE(RemoveTxd, _ZN9CTxdStore9RemoveTxdEi, void, i32 index);
    DECL_FASTCALL_SIMPLE(RemoveRef, _ZN9CTxdStore9RemoveRefEi, void, i32 index);
    DECL_FASTCALL_SIMPLE(SetCurrentTxd, _ZN9CTxdStore13SetCurrentTxdEiPKc, void, i32 index, const char *dbOverride);
    DECL_FASTCALL_SIMPLE(PushCurrentTxd, _ZN9CTxdStore14PushCurrentTxdEv, void);
    DECL_FASTCALL_SIMPLE(PopCurrentTxd, _ZN9CTxdStore13PopCurrentTxdEv, void);
    DECL_FASTCALL_SIMPLE(RemoveRefWithoutDelete, _ZN9CTxdStore22RemoveRefWithoutDeleteEi, void, i32 index);
    DECL_FASTCALL_SIMPLE(GetSpecialTxdSlot, _ZN9CTxdStore17GetSpecialTxdSlotEi, i32, i32 index);
    DECL_FASTCALL_SIMPLE(GetTxdParent, _ZN9CTxdStore12GetTxdParentEP15RwTexDictionary, RwTexDictionary*, RwTexDictionary *pTxd);

    // STATIC Values
    DECL_OBJECT_PLT(CTxdPool*, ms_pTxdPool, BYBIT(0x679A64, 0x8514E8));
    DECL_OBJECT_PLT(TextureDatabaseRuntime*, ms_curDB, BYBIT(0x6775FC, 0x84CC28));
    DECL_OBJECT_PLT(TextureDatabaseRuntime*, ms_storedDB, BYBIT(0x678EF8, 0x84FE18));
    DECL_VALUE_PLT_CHAR(ms_curName, BYBIT(0x6796C4, 0x850D98));
    DECL_VALUE_PLT_CHAR(ms_storedName, BYBIT(0x6795D4, 0x850BB8));
    DECL_VALUE_PLT_I32(ms_lastSlotFound, BYBIT(0x678140, 0x84E298));
DECL_CLASS_END()

#define ms_pTxdPool ms_pTxdPool()
#define ms_curDB ms_curDB()
#define ms_storedDB ms_storedDB()
#define ms_curName ms_curName()
#define ms_storedName ms_storedName()
#define ms_lastSlotFound ms_lastSlotFound()

DECL_VALUE_ADDR_I32_GLOBAL(ms_txdPluginOffset, BYBIT(0xA83F5C, 0xD28604) );
#define ms_txdPluginOffset ms_txdPluginOffset()

#endif // __AML_PSDK_SATXDSTORE_H
