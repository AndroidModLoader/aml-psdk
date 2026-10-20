#ifndef __AML_PSDK_SAAEBANKLOADER_H
#define __AML_PSDK_SAAEBANKLOADER_H

#include <aml-psdk/game_sa/plugin.h>

DECL_CLASS(tSound)
    // Member values
    i32 BankOffset;
    i32 LoopStartOffset;
    u16 Frequency;
    i16 Headroom;
DECL_CLASS_END()
CHECKSIZE(tSound, 0xc, 0xc);

DECL_CLASS(tBankSlot)
    // Member values
    u32 SRAMAddress;
    u32 NumBytes;
    i32 LoadSemaID;
    i32 PlaySemaID;
    i16 Bank;
    i16 NumSounds;
    tSound Sounds[400];
DECL_CLASS_END()
CHECKSIZE(tBankSlot, 0x12d4, 0x12d4);

DECL_CLASS(tBankLookup)
    // Member values
    u8 PackFile;
    u32 FileOffset;
    u32 NumBytes;
DECL_CLASS_END()
CHECKSIZE(tBankLookup, 0xc, 0xc);

DECL_CLASS(tSfxPackFile)
    // Member values
    char BaseFilename[9];
    u32 FileCopyLSNs[10];
DECL_CLASS_END()
CHECKSIZE(tSfxPackFile, 0x34, 0x34);

DECL_CLASS(CAEBankLoader)
    // Construct/Deconstruct functions
    DECL_CTORCALL(CAEBankLoader, _ZN13CAEBankLoaderC2Ev);
    DECL_DTORCALL(CAEBankLoader, _ZN13CAEBankLoaderD2Ev);

    // Member functions
    DECL_THISCALL_SIMPLE(Initialise, _ZN13CAEBankLoader10InitialiseEv, u8);
    DECL_THISCALL_HEAD(GetBankLookup, _ZN13CAEBankLoader13GetBankLookupEt, tBankLookup*, u16 bankId)
    DECL_THISCALL_TAIL(GetBankLookup, bankId)
    DECL_THISCALL_SIMPLE(LoadBankSlotFile, _ZN13CAEBankLoader16LoadBankSlotFileEv, u8);
    DECL_THISCALL_SIMPLE(LoadBankLookupFile, _ZN13CAEBankLoader18LoadBankLookupFileEv, u8);
    DECL_THISCALL_SIMPLE(LoadSFXPakLookupFile, _ZN13CAEBankLoader20LoadSFXPakLookupFileEv, u8);

    // Member values
    tBankSlot* m_pBankSlotData;
    tBankLookup* m_pBankLookupData;
    tSfxPackFile* m_pSfxPakLookupData;
    i16 m_nBankSlotCount;
    i16 m_nBankCount;
    i16 m_nSfxPakCount;
    i16 m_lastBankSlotLoaded;
    u8 m_bInitialised;
DECL_CLASS_END()
CHECKSIZE(CAEBankLoader, 0x18, 0x28);

#endif // __AML_PSDK_SAAEBANKLOADER_H
