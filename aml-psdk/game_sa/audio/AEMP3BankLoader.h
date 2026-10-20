#ifndef __AML_PSDK_SAAEMP3BANKLOADER_H
#define __AML_PSDK_SAAEMP3BANKLOADER_H

#include <aml-psdk/game_sa/audio/AEBankLoader.h>
#include <aml-psdk/game_sa/base/Lists.h>

struct ZIPFile;
struct OALBuffer;
struct tVirtualChannelSettings;

DECL_CLASS(SoundData)
    // Member values
    OALBuffer* buffer;
    u32 frequency;
    u32 channels;
    u32 length;
    tSound info;
DECL_CLASS_END()
CHECKSIZE(SoundData, 0x1c, 0x20);

DECL_CLASS_BASED(CAEMP3BankLoader, CAEBankLoader)
    DECL_CLASS(LoadedBankData)
        // Member values
        u16 Bank;
        OSArray<SoundData> sounds;
        u16 singleSound;
    DECL_CLASS_END()

    // Construct/Deconstruct functions
    DECL_CTORCALL(CAEMP3BankLoader, _ZN16CAEMP3BankLoaderC2Ev);

    // Virtual functions
    DECL_DTORCALL_VIRTUAL(CAEMP3BankLoader, _ZN16CAEMP3BankLoaderD2Ev, _ZN16CAEMP3BankLoader, _ZTV16CAEMP3BankLoader);

    // Member functions
    DECL_THISCALL_SIMPLE(Initialise, _ZN16CAEMP3BankLoader10InitialiseEv, u8);
    DECL_THISCALL_HEAD(LoadSoundBank, _ZN16CAEMP3BankLoader13LoadSoundBankEts, void, u16 bankId, i16 slotId)
    DECL_THISCALL_TAIL(LoadSoundBank, bankId, slotId)
    DECL_THISCALL_HEAD(IsSoundBankLoaded, _ZN16CAEMP3BankLoader17IsSoundBankLoadedEts, u8, u16 bankId, i16 slotId)
    DECL_THISCALL_TAIL(IsSoundBankLoaded, bankId, slotId)
    DECL_THISCALL_HEAD(GetSoundHeadroom, _ZN16CAEMP3BankLoader16GetSoundHeadroomEts, float, u16 soundId, i16 slotId)
    DECL_THISCALL_TAIL(GetSoundHeadroom, soundId, slotId)
    DECL_THISCALL_HEAD(GetSoundBankLoadingStatus, _ZN16CAEMP3BankLoader25GetSoundBankLoadingStatusEts, u8, u16 bankId, i16 slotId)
    DECL_THISCALL_TAIL(GetSoundBankLoadingStatus, bankId, slotId)
    DECL_THISCALL_HEAD(LoadSound, _ZN16CAEMP3BankLoader9LoadSoundEtts, void, u16 bankId, u16 soundId, i16 slotId)
    DECL_THISCALL_TAIL(LoadSound, bankId, soundId, slotId)
    DECL_THISCALL_HEAD(IsSoundLoaded, _ZN16CAEMP3BankLoader13IsSoundLoadedEtts, u8, u16 bankId, u16 soundId, i16 slotId)
    DECL_THISCALL_TAIL(IsSoundLoaded, bankId, soundId, slotId)
    DECL_THISCALL_HEAD(GetSoundLoadingStatus, _ZN16CAEMP3BankLoader21GetSoundLoadingStatusEtts, u8, u16 bankId, u16 soundId, i16 slotId)
    DECL_THISCALL_TAIL(GetSoundLoadingStatus, bankId, soundId, slotId)
    DECL_THISCALL_HEAD(GetSoundBuffer, _ZN16CAEMP3BankLoader14GetSoundBufferEtsPt, OALBuffer*, u16 soundId, i16 slotId, u16* loopStart)
    DECL_THISCALL_TAIL(GetSoundBuffer, soundId, slotId, loopStart)
    DECL_THISCALL_HEAD(GetLoopOffset, _ZN16CAEMP3BankLoader13GetLoopOffsetEts, i32, u16 soundId, i16 slotId)
    DECL_THISCALL_TAIL(GetLoopOffset, soundId, slotId)
    DECL_THISCALL_HEAD(UpdateVirtualChannels, _ZN16CAEMP3BankLoader21UpdateVirtualChannelsEP23tVirtualChannelSettingsPsS2_, void, tVirtualChannelSettings* settings, i16* lengths, i16* loopStarts)
    DECL_THISCALL_TAIL(UpdateVirtualChannels, settings, lengths, loopStarts)
    DECL_THISCALL_SIMPLE(Service, _ZN16CAEMP3BankLoader7ServiceEv, void);
    DECL_THISCALL_HEAD(LoadRequest, _ZN16CAEMP3BankLoader11LoadRequestEP7ZIPFileiii, void, ZIPFile* file, i32 bankId, i32 soundId, i32 slotId)
    DECL_THISCALL_TAIL(LoadRequest, file, bankId, soundId, slotId)

    // Member values
    bool bankIsLoading;
    OSArray<ZIPFile *> zipFiles;
    OSArray<CAEMP3BankLoader::LoadedBankData> bankSlots;
DECL_CLASS_END()
CHECKSIZE(CAEMP3BankLoader, 0x34, 0x50);

CHECKSIZE(CAEMP3BankLoader::LoadedBankData, 0x14, 0x20);

#endif // __AML_PSDK_SAAEMP3BANKLOADER_H
