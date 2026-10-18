#ifndef __AML_PSDK_SAAEAUDIOCHANNEL_H
#define __AML_PSDK_SAAEAUDIOCHANNEL_H

#include "../plugin.h"
#include <aml-psdk/gta_base/Vector.h>

struct OALSource;
struct OALBuffer;
struct CAEStreamingDecoder;

DECL_CLASS_VTABLE(CAEAudioChannel)
    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CAEAudioChannel, _ZN15CAEAudioChannelC2Etjt, u16 channelID, u32 nSamplesPerSec, u16 wBitsPerSample)
    DECL_CTORCALL_ARG_TAIL(channelID, nSamplesPerSec, wBitsPerSample)
    DECL_DTORCALL_VIRTUAL(CAEAudioChannel, _ZN15CAEAudioChannelD2Ev, _ZN15CAEAudioChannel, _ZTV15CAEAudioChannel);

    // Virtual functions
    virtual void Service() = 0;
    virtual u8 IsSoundPlaying() = 0;
    virtual long int GetPlayTime() = 0;
    virtual long int GetLength() = 0;
    virtual void Play(i16 StartOffsetMs, i8 SoundFlags, float fScalingFactor) = 0;
    virtual void SynchPlayback() = 0;
    virtual void Stop() = 0;
    DECL_VIRTUALCALL_HEAD(CAEAudioChannel, SetFrequencyScalingFactor, _ZTV15CAEAudioChannel, 9, void, float fScalingFactor)
    DECL_VIRTUALCALL_TAIL(fScalingFactor)

    // Member functions
    DECL_THISCALL_SIMPLE(IsBufferPlaying, _ZN15CAEAudioChannel15IsBufferPlayingEv, u8);
    DECL_THISCALL_HEAD(SetVolume, _ZN15CAEAudioChannel9SetVolumeEf, void, float fVolume)
    DECL_THISCALL_TAIL(SetVolume, fVolume)
    DECL_THISCALL_SIMPLE(GetVolume, _ZN15CAEAudioChannel9GetVolumeEv, float);
    DECL_THISCALL_HEAD(SetPosition, _ZN15CAEAudioChannel11SetPositionEP7CVector, void, CVector* pPosition)
    DECL_THISCALL_TAIL(SetPosition, pPosition)
    DECL_THISCALL_HEAD(SetFrequency, _ZN15CAEAudioChannel12SetFrequencyEj, void, u32 frequency)
    DECL_THISCALL_TAIL(SetFrequency, frequency)
    DECL_THISCALL_HEAD(SetOriginalFrequency, _ZN15CAEAudioChannel20SetOriginalFrequencyEj, void, u32 frequency)
    DECL_THISCALL_TAIL(SetOriginalFrequency, frequency)
    DECL_THISCALL_SIMPLE(UpdateStatus, _ZN15CAEAudioChannel12UpdateStatusEv, void);
    DECL_THISCALL_HEAD(ConvertFromBytesToMS, _ZN15CAEAudioChannel20ConvertFromBytesToMSEj, i16, u32 dwBytes)
    DECL_THISCALL_TAIL(ConvertFromBytesToMS, dwBytes)
    DECL_THISCALL_HEAD(ConvertFromMsToBytes, _ZN15CAEAudioChannel20ConvertFromMsToBytesEj, i32, u32 dwMs)
    DECL_THISCALL_TAIL(ConvertFromMsToBytes, dwMs)
    DECL_THISCALL_SIMPLE(GetCurrentPlaybackPosition, _ZN15CAEAudioChannel26GetCurrentPlaybackPositionEv, u32);

    // Member values
    OALSource* oalSource;
    u32 m_dwTotalBufferBytes;
    u32 m_dwFlags;
    u32 m_dwBufSize;
    u32 m_dwStopTime;
    float m_fVol;
    u8 m_bPaused;
    u16 m_channelID;
    u32 m_frequency;
    u32 m_originalFrequency;
    u8 m_bLooping;
    u8 m_bShouldStop;
    u8 m_bShouldPlay;
DECL_CLASS_END()
CHECKSIZE(CAEAudioChannel, 0x2C, 0x38);

DECL_CLASS_BASED(CAEStaticChannel, CAEAudioChannel)
    DECL_VIRTUALCALL_HEAD(CAEStaticChannel, Service, _ZTV16CAEStaticChannel, 2, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CAEStaticChannel, IsSoundPlaying, _ZTV16CAEStaticChannel, 3, u8)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CAEStaticChannel, GetPlayTime, _ZTV16CAEStaticChannel, 4, long int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CAEStaticChannel, GetLength, _ZTV16CAEStaticChannel, 5, long int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CAEStaticChannel, Play, _ZTV16CAEStaticChannel, 6, void, i16 StartOffsetMs, i8 SoundFlags, float fScalingFactor)
    DECL_VIRTUALCALL_TAIL(StartOffsetMs, SoundFlags, fScalingFactor)
    DECL_VIRTUALCALL_HEAD(CAEStaticChannel, SynchPlayback, _ZTV16CAEStaticChannel, 7, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CAEStaticChannel, Stop, _ZTV16CAEStaticChannel, 8, void)
    DECL_VIRTUALCALL_TAIL()

    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CAEStaticChannel, _ZN16CAEStaticChannelC2Etjt, u16 channelID, u32 nSamplesPerSec, u16 wBitsPerSample)
    DECL_CTORCALL_ARG_TAIL(channelID, nSamplesPerSec, wBitsPerSample)
    DECL_DTORCALL_VIRTUAL(CAEStaticChannel, _ZN16CAEStaticChannelD2Ev, _ZN16CAEStaticChannel, _ZTV16CAEStaticChannel);

    // Member functions
    DECL_THISCALL_HEAD(SetAudioData, _ZN16CAEStaticChannel12SetAudioDataEPvjtsst, u8, void* buffer, u32 numBytes, u16 SoundID, i16 BankSlotID, i16 loopStartOffset, u16 SampleRate)
    DECL_THISCALL_TAIL(SetAudioData, buffer, numBytes, SoundID, BankSlotID, loopStartOffset, SampleRate)
    DECL_THISCALL_HEAD(SetAudioBuffer, _ZN16CAEStaticChannel14SetAudioBufferEP9OALBuffertsst, u8, OALBuffer* buffer, u16 SoundID, i16 BankSlotID, i16 loopStartOffset, u16 SampleRate)
    DECL_THISCALL_TAIL(SetAudioBuffer, buffer, SoundID, BankSlotID, loopStartOffset, SampleRate)

    // Member values
    u8 m_bNeedData;
    u8 m_bNeedFade;
    u8 m_bShouldPlay;
    u32 m_dwLoopStart;
    u32 m_dwLoopEnd;
    u32 m_dwLoopSlots;
    u32 m_dwPlayStartTime;
    u32 m_dwPreLoopTime;
    u32 m_plOffset;
    u32 m_dwLoopLength;
    u16 m_preLoopSlots;
    void* m_pAudioData;
    u16 m_soundID;
    u8 m_bHardwareMixing;
    i16 m_bankSlotID;
DECL_CLASS_END()
CHECKSIZE(CAEStaticChannel, 0x5C, 0x68);

DECL_CLASS_BASED(CAEStreamingChannel, CAEAudioChannel)
    DECL_VIRTUALCALL_HEAD(CAEStreamingChannel, Service, _ZTV19CAEStreamingChannel, 2, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CAEStreamingChannel, IsSoundPlaying, _ZTV19CAEStreamingChannel, 3, u8)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CAEStreamingChannel, GetPlayTime, _ZTV19CAEStreamingChannel, 4, long int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CAEStreamingChannel, GetLength, _ZTV19CAEStreamingChannel, 5, long int)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CAEStreamingChannel, Play, _ZTV19CAEStreamingChannel, 6, void, i16 StartOffsetMs, i8 SoundFlags, float fScalingFactor)
    DECL_VIRTUALCALL_TAIL(StartOffsetMs, SoundFlags, fScalingFactor)
    DECL_VIRTUALCALL_HEAD(CAEStreamingChannel, SynchPlayback, _ZTV19CAEStreamingChannel, 7, void)
    DECL_VIRTUALCALL_TAIL()

    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CAEStreamingChannel, _ZN19CAEStreamingChannelC2Et, u16 channelID)
    DECL_CTORCALL_ARG_TAIL(channelID)
    DECL_DTORCALL_VIRTUAL(CAEStreamingChannel, _ZN19CAEStreamingChannelD2Ev, _ZN19CAEStreamingChannel, _ZTV19CAEStreamingChannel);

    // Member functions
    DECL_THISCALL_SIMPLE(UpdatePlayTime, _ZN19CAEStreamingChannel14UpdatePlayTimeEv, long int);
    DECL_THISCALL_SIMPLE(GetActiveTrackID, _ZN19CAEStreamingChannel16GetActiveTrackIDEv, int);
    DECL_THISCALL_SIMPLE(GetPlayingTrackID, _ZN19CAEStreamingChannel17GetPlayingTrackIDEv, int);
    DECL_THISCALL_SIMPLE(Pause, _ZN19CAEStreamingChannel5PauseEv, void);
    DECL_THISCALL_SIMPLE(Initialise, _ZN19CAEStreamingChannel10InitialiseEv, bool);
    DECL_THISCALL_HEAD(PrepareStream, _ZN19CAEStreamingChannel13PrepareStreamEP19CAEStreamingDecoderab, int, CAEStreamingDecoder* stream, i8 SoundFlags, bool bNeedStop)
    DECL_THISCALL_TAIL(PrepareStream, stream, SoundFlags, bNeedStop)
    DECL_THISCALL_HEAD(SetNextStream, _ZN19CAEStreamingChannel13SetNextStreamEP19CAEStreamingDecoder, int, CAEStreamingDecoder* stream)
    DECL_THISCALL_TAIL(SetNextStream, stream)
    DECL_THISCALL_SIMPLE(SetReady, _ZN19CAEStreamingChannel8SetReadyEv, void);
    DECL_THISCALL_HEAD(SetBassEQ, _ZN19CAEStreamingChannel9SetBassEQEaf, void, i8 mode, float fScalingFactor)
    DECL_THISCALL_TAIL(SetBassEQ, mode, fScalingFactor)
    DECL_THISCALL_HEAD(FillBuffer, _ZN19CAEStreamingChannel10FillBufferEPvm, long unsigned int, void* pBuf, long unsigned int dwSize)
    DECL_THISCALL_TAIL(FillBuffer, pBuf, dwSize)
    DECL_THISCALL_SIMPLE(InitialiseSilence, _ZN19CAEStreamingChannel17InitialiseSilenceEv, void);

    DECL_VIRTUALCALL_HEAD(CAEStreamingChannel, Stop, _ZTV19CAEStreamingChannel, 8, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_THISCALL_NAMED_HEAD(Stop1, Stop, _ZN19CAEStreamingChannel4StopEb, void, bool arg1)
    DECL_THISCALL_TAIL(Stop1, arg1)

    // Member values
    bool m_bInitialised;
    bool m_bLoopTrack;
    bool m_bNeedSwitch;
    bool m_bSilenced;
    bool m_bNeedToFinish;
    bool m_bEQEnabled;
    char m_lastSlot;
    char m_lastWrittenSlot;
    char numBuffered;
    void* m_pReadBuffer;
    char m_ReadBuffer[147456];
    CAEStreamingDecoder* m_pCurrentStream;
    CAEStreamingDecoder* m_pNextStream;
    int m_trackStatus;
    long int m_lStreamTime;
    long int m_lPlayTime;
    long int m_lLastTimer;
    long int m_lStoppingFrameCount;
    u64 m_timeLastUpdate;
    bool m_isSmallStream;
    float m_fEQScaleFactor;
DECL_CLASS_END()
CHECKSIZE(CAEStreamingChannel, 0x24068, 0x24090);

#endif // __AML_PSDK_SAAEAUDIOCHANNEL_H
