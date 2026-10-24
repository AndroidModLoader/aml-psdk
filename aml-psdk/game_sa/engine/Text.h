#ifndef __AML_PSDK_SATEXT_H
#define __AML_PSDK_SATEXT_H

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/gta_base/GxtChar.h>

struct ChunkHeader
{
    char Type[4];
    u32  Size;
};

DECL_CLASS(CText__TDat)
    // Member functions
    DECL_THISCALL_HEAD(Load, BYBIT(_ZN5CData4LoadEjjPjh, _ZN5CData4LoadEjyPjh), u8, u32 blockSize, uintptr_t file, u32* offset, u8 skipRead)
    DECL_THISCALL_TAIL(Load, blockSize, file, offset, skipRead)
    DECL_THISCALL_SIMPLE(Unload, _ZN5CData6UnloadEv, void);

    // Member values
    GxtChar* data;
    int size;
DECL_CLASS_END()
CHECKSIZE(CText__TDat, 0x8, 0x10);
struct CText__TablEntry
{
    char name[8];
    unsigned int offset;
};
struct CText__Tabl
{
    CText__TablEntry data[200];
    unsigned short size;
    short __pad;
};
struct tGXT_VERSION_2_TKEY_item
{
    uintptr_t Position; // Native text pointer after loading
    unsigned int KeyHash;
};
DECL_CLASS(CText__TKey)
    // Member functions
    DECL_THISCALL_HEAD(Load, BYBIT(_ZN9CKeyArray4LoadEjjPjh, _ZN9CKeyArray4LoadEjyPjh), u8, u32 blockSize, uintptr_t file, u32* offset, u8 skipRead)
    DECL_THISCALL_TAIL(Load, blockSize, file, offset, skipRead)
    DECL_THISCALL_SIMPLE(Unload, _ZN9CKeyArray6UnloadEv, void);
    DECL_THISCALL_HEAD(Update, _ZN9CKeyArray6UpdateEPt, void, GxtChar* text)
    DECL_THISCALL_TAIL(Update, text)
    DECL_THISCALL_HEAD(Search, _ZN9CKeyArray6SearchEPKcPh, GxtChar*, char const* key, u8* found)
    DECL_THISCALL_TAIL(Search, key, found)
    DECL_THISCALL_HEAD(BinarySearch, _ZN9CKeyArray12BinarySearchEjP9CKeyEntryss, tGXT_VERSION_2_TKEY_item*, u32 key, tGXT_VERSION_2_TKEY_item* entries, i16 first, i16 last)
    DECL_THISCALL_TAIL(BinarySearch, key, entries, first, last)

    // Member values
    tGXT_VERSION_2_TKEY_item* data;
    unsigned int size;
DECL_CLASS_END()
CHECKSIZE(CText__TKey, 0x8, 0x10);

DECL_CLASS(CText)
    // Construct/Deconstruct functions
    DECL_CTORCALL(CText, _ZN5CTextC2Ev);
    DECL_DTORCALL(CText, _ZN5CTextD2Ev);

    // Member functions
    DECL_THISCALL_SIMPLE(LoadMissionPackText, _ZN5CText19LoadMissionPackTextEv, void);

    DECL_THISCALL_HEAD(GetUpperCase, _ZN5CText12GetUpperCaseEt, GxtChar, const GxtChar C)
    DECL_THISCALL_TAIL(GetUpperCase, C)

    DECL_THISCALL_HEAD(ReadChunkHeader, BYBIT(_ZN5CText15ReadChunkHeaderEP11ChunkHeaderjPjh, _ZN5CText15ReadChunkHeaderEP11ChunkHeaderyPjh), u8, ChunkHeader *pHead, uintptr_t FileId, u32 *pNumCharsRead, u8 LoadFromMemoryCard)
    DECL_THISCALL_TAIL(ReadChunkHeader, pHead, FileId, pNumCharsRead, LoadFromMemoryCard)

    DECL_THISCALL_HEAD(Load, _ZN5CText4LoadEh, void, u8 bKeepMissionText)
    DECL_THISCALL_TAIL(Load, bKeepMissionText)

    DECL_THISCALL_HEAD(Unload, _ZN5CText6UnloadEh, void, u8 bKeepMissionText)
    DECL_THISCALL_TAIL(Unload, bKeepMissionText)

    DECL_THISCALL_HEAD(Get, _ZN5CText3GetEPKc, GxtChar*, const char *Ident)
    DECL_THISCALL_TAIL(Get, Ident)

    DECL_THISCALL_HEAD(GetNameOfLoadedMissionText, _ZN5CText26GetNameOfLoadedMissionTextEPc, void, char *pStringToFill)
    DECL_THISCALL_TAIL(GetNameOfLoadedMissionText, pStringToFill)

    DECL_THISCALL_HEAD(LoadMissionText, _ZN5CText15LoadMissionTextEPc, void, char *pMissionTextStem)
    DECL_THISCALL_TAIL(LoadMissionText, pMissionTextStem)

    // Member values
    CText__TKey tkeyMain;
    CText__TDat tdatMain;
    CText__TKey tkeyMission;
    CText__TDat tdatMission;
    char        encoding;
    unsigned char haveTabl;
    unsigned char cderrorInitialized;
    unsigned char missionTableLoaded;
    char        missionTableName[8];
    char        cderrorText[255];
    CText__Tabl tabl;
DECL_CLASS_END()
CHECKSIZE(CText, 0xA90, 0xAB0);

DECL_OBJECT_PLT_GLOBAL(CText, TheText, BYBIT(0x6770B4, 0x84C1A0) );
#define TheText TheText()

#endif // __AML_PSDK_SATEXT_H
