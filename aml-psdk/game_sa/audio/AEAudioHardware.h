#ifndef __AML_PSDK_SAAEAUDIOHARDWARE_H
#define __AML_PSDK_SAAEAUDIOHARDWARE_H

#include "AudioEngine.h"
#include "AEStreamThread.h"

struct CAEMP3BankLoader;
struct CAEMP3TrackLoader;
struct ALCdevice_struct;
struct ALCcontext_struct;
typedef ALCdevice_struct ALCdevice;
typedef ALCcontext_struct ALCcontext;
struct CAEStreamingChannel;
struct CAEAudioChannel;

DECL_CLASS(tVirtualChannelSettings)

    // Member values
    short BankSlotIDs[300];
    short SoundIDs[300];
DECL_CLASS_END()
CHECKSIZE(tVirtualChannelSettings, 0x4B0, 0x4B0);

DECL_CLASS(CAEAudioHardware)
    // Construct/Deconstruct functions
    DECL_CTORCALL(CAEAudioHardware, _ZN16CAEAudioHardwareC2Ev);
    DECL_DTORCALL(CAEAudioHardware, _ZN16CAEAudioHardwareD2Ev);

    // Member functions
    DECL_THISCALL_SIMPLE(Initialise, _ZN16CAEAudioHardware10InitialiseEv, u8);
    DECL_THISCALL_SIMPLE(Terminate, _ZN16CAEAudioHardware9TerminateEv, void);
    DECL_THISCALL_SIMPLE(Service, _ZN16CAEAudioHardware7ServiceEv, void);
    DECL_THISCALL_SIMPLE(GetNumAvailableChannels, _ZN16CAEAudioHardware23GetNumAvailableChannelsEv, u16);
    DECL_THISCALL_HEAD(AllocateChannels, _ZN16CAEAudioHardware16AllocateChannelsEt, i16, u16 NumChannels)
    DECL_THISCALL_TAIL(AllocateChannels, NumChannels)
    DECL_THISCALL_HEAD(SetMusicMasterScalingFactor, _ZN16CAEAudioHardware27SetMusicMasterScalingFactorEf, void, float fScalingFactor)
    DECL_THISCALL_TAIL(SetMusicMasterScalingFactor, fScalingFactor)
    DECL_THISCALL_HEAD(SetEffectsMasterScalingFactor, _ZN16CAEAudioHardware29SetEffectsMasterScalingFactorEf, void, float fScalingFactor)
    DECL_THISCALL_TAIL(SetEffectsMasterScalingFactor, fScalingFactor)
    DECL_THISCALL_HEAD(SetMusicFaderScalingFactor, _ZN16CAEAudioHardware26SetMusicFaderScalingFactorEf, void, float fScalingFactor)
    DECL_THISCALL_TAIL(SetMusicFaderScalingFactor, fScalingFactor)
    DECL_THISCALL_HEAD(SetEffectsFaderScalingFactor, _ZN16CAEAudioHardware28SetEffectsFaderScalingFactorEf, void, float fScalingFactor)
    DECL_THISCALL_TAIL(SetEffectsFaderScalingFactor, fScalingFactor)
    DECL_THISCALL_SIMPLE(GetEffectsMasterScalingFactor, _ZN16CAEAudioHardware29GetEffectsMasterScalingFactorEv, float);
    DECL_THISCALL_SIMPLE(GetMusicMasterScalingFactor, _ZN16CAEAudioHardware27GetMusicMasterScalingFactorEv, float);
    DECL_THISCALL_SIMPLE(GetEffectsFaderScalingFactor, _ZN16CAEAudioHardware28GetEffectsFaderScalingFactorEv, float);
    DECL_THISCALL_HEAD(SetStreamFaderScalingFactor, _ZN16CAEAudioHardware27SetStreamFaderScalingFactorEf, void, float fScalingFactor)
    DECL_THISCALL_TAIL(SetStreamFaderScalingFactor, fScalingFactor)
    DECL_THISCALL_HEAD(SetNonStreamFaderScalingFactor, _ZN16CAEAudioHardware30SetNonStreamFaderScalingFactorEf, void, float fScalingFactor)
    DECL_THISCALL_TAIL(SetNonStreamFaderScalingFactor, fScalingFactor)
    DECL_THISCALL_HEAD(GetSoundHeadroom, _ZN16CAEAudioHardware16GetSoundHeadroomEts, float, u16 SoundID, i16 BankSlotID)
    DECL_THISCALL_TAIL(GetSoundHeadroom, SoundID, BankSlotID)
    DECL_THISCALL_HEAD(GetChannelPlayTimes, _ZN16CAEAudioHardware19GetChannelPlayTimesEsPs, void, i16 ClientHandle, i16* pPlayTimes)
    DECL_THISCALL_TAIL(GetChannelPlayTimes, ClientHandle, pPlayTimes)
    DECL_THISCALL_HEAD(GetVirtualChannelSoundLengths, _ZN16CAEAudioHardware29GetVirtualChannelSoundLengthsEPs, void, i16* pSoundLengths)
    DECL_THISCALL_TAIL(GetVirtualChannelSoundLengths, pSoundLengths)
    DECL_THISCALL_HEAD(GetVirtualChannelSoundLoopStartTimes, _ZN16CAEAudioHardware36GetVirtualChannelSoundLoopStartTimesEPs, void, i16* pSoundLoopStartTimes)
    DECL_THISCALL_TAIL(GetVirtualChannelSoundLoopStartTimes, pSoundLoopStartTimes)
    DECL_THISCALL_SIMPLE(GetTrackPlayTime, _ZN16CAEAudioHardware16GetTrackPlayTimeEv, long int);
    DECL_THISCALL_SIMPLE(GetTrackLengthMs, _ZN16CAEAudioHardware16GetTrackLengthMsEv, long int);
    DECL_THISCALL_SIMPLE(GetActiveTrackID, _ZN16CAEAudioHardware16GetActiveTrackIDEv, int);
    DECL_THISCALL_SIMPLE(GetPlayingTrackID, _ZN16CAEAudioHardware17GetPlayingTrackIDEv, int);
    DECL_THISCALL_HEAD(GetBeatInfo, _ZN16CAEAudioHardware11GetBeatInfoEP9tBeatInfo, void, tBeatInfo* pComplexBeatInfo)
    DECL_THISCALL_TAIL(GetBeatInfo, pComplexBeatInfo)
    DECL_THISCALL_HEAD(LoadSoundBank, _ZN16CAEAudioHardware13LoadSoundBankEts, void, u16 BankID, i16 BankSlotID)
    DECL_THISCALL_TAIL(LoadSoundBank, BankID, BankSlotID)
    DECL_THISCALL_HEAD(IsSoundBankLoaded, _ZN16CAEAudioHardware17IsSoundBankLoadedEts, u8, u16 BankID, i16 BankSlotID)
    DECL_THISCALL_TAIL(IsSoundBankLoaded, BankID, BankSlotID)
    DECL_THISCALL_HEAD(GetSoundBankLoadingStatus, _ZN16CAEAudioHardware25GetSoundBankLoadingStatusEts, u8, u16 BankID, i16 BankSlotID)
    DECL_THISCALL_TAIL(GetSoundBankLoadingStatus, BankID, BankSlotID)
    DECL_THISCALL_HEAD(LoadSound, _ZN16CAEAudioHardware9LoadSoundEtts, void, u16 BankID, u16 SoundID, i16 BankSlotID)
    DECL_THISCALL_TAIL(LoadSound, BankID, SoundID, BankSlotID)
    DECL_THISCALL_HEAD(IsSoundLoaded, _ZN16CAEAudioHardware13IsSoundLoadedEtts, u8, u16 BankID, u16 SoundID, i16 BankSlotID)
    DECL_THISCALL_TAIL(IsSoundLoaded, BankID, SoundID, BankSlotID)
    DECL_THISCALL_HEAD(GetSoundLoadingStatus, _ZN16CAEAudioHardware21GetSoundLoadingStatusEtts, u8, u16 BankID, u16 SoundID, i16 BankSlotID)
    DECL_THISCALL_TAIL(GetSoundLoadingStatus, BankID, SoundID, BankSlotID)
    DECL_THISCALL_HEAD(PlaySound, _ZN16CAEAudioHardware9PlaySoundEstttssf, void, i16 ClientHandle, u16 Channel, u16 SoundID, u16 BankSlotID, i16 StartOffsetMs, i16 SoundFlags, float FrequencyFac)
    DECL_THISCALL_TAIL(PlaySound, ClientHandle, Channel, SoundID, BankSlotID, StartOffsetMs, SoundFlags, FrequencyFac)
    DECL_THISCALL_HEAD(StopSound, _ZN16CAEAudioHardware9StopSoundEst, void, i16 ClientHandle, u16 Channel)
    DECL_THISCALL_TAIL(StopSound, ClientHandle, Channel)
    DECL_THISCALL_HEAD(SetChannelVolume, _ZN16CAEAudioHardware16SetChannelVolumeEstfh, void, i16 ClientHandle, u16 Channel, float fVolume, u8 bInvertPhase)
    DECL_THISCALL_TAIL(SetChannelVolume, ClientHandle, Channel, fVolume, bInvertPhase)
    DECL_THISCALL_HEAD(SetChannelPosition, _ZN16CAEAudioHardware18SetChannelPositionEstP7CVectorh, void, i16 ClientHandle, u16 Channel, CVector* pPosition, u8 bForceFront)
    DECL_THISCALL_TAIL(SetChannelPosition, ClientHandle, Channel, pPosition, bForceFront)
    DECL_THISCALL_HEAD(SetChannelFrequencyScalingFactor, _ZN16CAEAudioHardware32SetChannelFrequencyScalingFactorEstf, void, i16 ClientHandle, u16 Channel, float fScalingFactor)
    DECL_THISCALL_TAIL(SetChannelFrequencyScalingFactor, ClientHandle, Channel, fScalingFactor)
    DECL_THISCALL_HEAD(RequestVirtualChannelSoundInfo, _ZN16CAEAudioHardware30RequestVirtualChannelSoundInfoEttt, void, u16 VirtualChannel, u16 SoundID, u16 BankSlotID)
    DECL_THISCALL_TAIL(RequestVirtualChannelSoundInfo, VirtualChannel, SoundID, BankSlotID)
    DECL_THISCALL_HEAD(PlayTrack, _ZN16CAEAudioHardware9PlayTrackEjijcbb, void, unsigned int TrackID, int NextTrackID, unsigned int StartOffsetMs, char TrackFlags, bool bUserTrack, bool bUserNextTrack)
    DECL_THISCALL_TAIL(PlayTrack, TrackID, NextTrackID, StartOffsetMs, TrackFlags, bUserTrack, bUserNextTrack)
    DECL_THISCALL_SIMPLE(StopTrack, _ZN16CAEAudioHardware9StopTrackEv, void);
    DECL_THISCALL_SIMPLE(DisableEffectsLoading, _ZN16CAEAudioHardware21DisableEffectsLoadingEv, void);
    DECL_THISCALL_SIMPLE(EnableEffectsLoading, _ZN16CAEAudioHardware20EnableEffectsLoadingEv, void);
    DECL_THISCALL_SIMPLE(StartTrackPlayback, _ZN16CAEAudioHardware18StartTrackPlaybackEv, void);
    DECL_THISCALL_HEAD(SetBassSetting, _ZN16CAEAudioHardware14SetBassSettingEaf, void, i8 bassSetting, float fScalingFactor)
    DECL_THISCALL_TAIL(SetBassSetting, bassSetting, fScalingFactor)
    DECL_THISCALL_HEAD(SetChannelFlags, _ZN16CAEAudioHardware15SetChannelFlagsEsts, void, i16 ClientHandle, u16 Channel, i16 flags)
    DECL_THISCALL_TAIL(SetChannelFlags, ClientHandle, Channel, flags)
    DECL_THISCALL_SIMPLE(DisableBassEq, _ZN16CAEAudioHardware13DisableBassEqEv, void);
    DECL_THISCALL_SIMPLE(EnableBassEq, _ZN16CAEAudioHardware12EnableBassEqEv, void);
    DECL_THISCALL_SIMPLE(IsStreamingFromDVD, _ZN16CAEAudioHardware18IsStreamingFromDVDEv, u8);
    DECL_THISCALL_SIMPLE(GetDVDDriveLetter, _ZN16CAEAudioHardware17GetDVDDriveLetterEv, char);
    DECL_THISCALL_SIMPLE(CheckDVD, _ZN16CAEAudioHardware8CheckDVDEv, u8);
    DECL_THISCALL_SIMPLE(PauseAllSounds, _ZN16CAEAudioHardware14PauseAllSoundsEv, void);
    DECL_THISCALL_SIMPLE(ResumeAllSounds, _ZN16CAEAudioHardware15ResumeAllSoundsEv, void);
    DECL_THISCALL_HEAD(SetHRTF, _ZN16CAEAudioHardware7SetHRTFEi, void, int value)
    DECL_THISCALL_TAIL(SetHRTF, value)
    DECL_THISCALL_HEAD(PauseOpenAL, _ZN16CAEAudioHardware11PauseOpenALEi, void, int value)
    DECL_THISCALL_TAIL(PauseOpenAL, value)
    DECL_THISCALL_SIMPLE(GetActualNumberOfHardwareChannels, _ZN16CAEAudioHardware33GetActualNumberOfHardwareChannelsEv, int);
    DECL_THISCALL_SIMPLE(RescaleChannelVolumes, _ZN16CAEAudioHardware21RescaleChannelVolumesEv, void);
    DECL_THISCALL_SIMPLE(UpdateReverbEnvironment, _ZN16CAEAudioHardware23UpdateReverbEnvironmentEv, void);
    DECL_THISCALL_SIMPLE(InitOpenALListener, _ZN16CAEAudioHardware18InitOpenALListenerEv, void);

    // Member values
    u8 m_bInitialised;
    u8 m_bEffectsLoadingDisabled;
    u8 m_bLoudestFrontendSoundWasSmoothDucking;
    u8 m_bLoudestOverallSoundWasSmoothDucking;
    u8 m_bHardwareMixing;
    i8 m_nReverbEnvironment;
    i16 m_nRequestedChannelSoundFlagsList[30];
    i32 m_nReverbDepth;
    u16 m_nAvailableChannels;
    u16 m_nNumAudioChannels;
    u16 m_ClientChannelAllocationList[30];
    float m_fRequestedChannelVolumeList[30];
    float m_fLinearChannelVolumeList[30];
    float m_fRequestedChannelFrequencyScalingFactors[30];
    float m_fMusicMasterScalingFactor;
    float m_fEffectsMasterScalingFactor;
    float m_fMusicFaderScalingFactor;
    float m_fEffectsFaderScalingFactor;
    float m_fStreamFaderScalingFactor;
    float m_fNonStreamFaderScalingFactor;
    float m_fLoudestFrontendSoundVolumeLastFrame;
    float m_fLoudestOverallSoundVolumeLastFrame;
    tVirtualChannelSettings m_VirtualChannelSettings;
    i16 m_VirtualChannelLoopTimes[300];
    i16 m_VirtualChannelSoundLengths[300];
    int m_nBassSetting;
    float m_fBassFactor;
    CAEMP3BankLoader* m_pBankLoader;
    CAEMP3TrackLoader* m_pTrackLoader;
    ALCdevice* alDevice;
    ALCcontext* alContext;
    CAEStreamingChannel* m_pStreamingChannel;
    CAEStreamThread m_streamThread{};
    CAEAudioChannel* m_pPhysicalAudioChannels[30];
    tBeatInfo gBeatInfo;
    i8 m_cTrackFlags;
DECL_CLASS_END()
CHECKSIZE(CAEAudioHardware, 0xCF4, 0xD98);

DECL_OBJECT_PLT_GLOBAL(CAEAudioHardware, AEAudioHardware, BYBIT(0x676EF8, 0x84BE30));
#define AEAudioHardware AEAudioHardware()

#endif // __AML_PSDK_SAAEAUDIOHARDWARE_H
