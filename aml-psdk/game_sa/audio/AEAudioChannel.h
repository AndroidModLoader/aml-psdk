#ifndef __AML_PSDK_SAAEAUDIOCHANNEL_H
#define __AML_PSDK_SAAEAUDIOCHANNEL_H

#include "../plugin.h"
#include <aml-psdk/gta_base/Vector.h>

struct OALSource;
struct OALBuffer;
struct CAEStreamingDecoder;

DECL_CLASS_VTABLE(CAEAudioChannel)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CAEAudioChannel, _ZN15CAEAudioChannelC2Etjt, u16 channelID, u32 nSamplesPerSec, u16 wBitsPerSample);
    DECL_DTORCALL_PROXY(CAEAudioChannel, _ZN15CAEAudioChannelD2Ev);

    // Virtual functions
    virtual void Service();
    virtual u8 IsSoundPlaying();
    virtual long int GetPlayTime();
    virtual long int GetLength();
    virtual void Play(i16 StartOffsetMs, i8 SoundFlags, float fScalingFactor);
    virtual void SynchPlayback();
    virtual void Stop();
    virtual void SetFrequencyScalingFactor(float fScalingFactor);

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
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CAEStaticChannel, _ZN16CAEStaticChannelC2Etjt, u16 channelID, u32 nSamplesPerSec, u16 wBitsPerSample);
    DECL_DTORCALL_PROXY(CAEStaticChannel, _ZN16CAEStaticChannelD2Ev);

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
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CAEStreamingChannel, _ZN19CAEStreamingChannelC2Et, u16 channelID);
    DECL_DTORCALL_PROXY(CAEStreamingChannel, _ZN19CAEStreamingChannelD2Ev);

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

    virtual void Stop();
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
