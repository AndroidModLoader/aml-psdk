#ifndef __AML_PSDK_SAAEAMBIENCETRACKMANAGER_H
#define __AML_PSDK_SAAEAMBIENCETRACKMANAGER_H

#include <aml-psdk/game_sa/plugin.h>

DECL_CLASS(tAmbienceSettings)
    // Member values
    i32 TrackID;
    i32 PlayingTrackID;
    char TrackFlags;
DECL_CLASS_END()
CHECKSIZE(tAmbienceSettings, 0xc, 0xc);

DECL_CLASS(CAEAmbienceTrackManager)
    // Member functions
    DECL_THISCALL_HEAD(Initialise, _ZN23CAEAmbienceTrackManager10InitialiseEi, u8, i32 clientHandle)
    DECL_THISCALL_TAIL(Initialise, clientHandle)
    DECL_THISCALL_HEAD(Service, _ZN23CAEAmbienceTrackManager7ServiceEi, void, i32 playTime)
    DECL_THISCALL_TAIL(Service, playTime)
    DECL_THISCALL_SIMPLE(Reset, _ZN23CAEAmbienceTrackManager5ResetEv, void);
    DECL_THISCALL_SIMPLE(StopAmbienceTrack, _ZN23CAEAmbienceTrackManager17StopAmbienceTrackEv, void);
    DECL_THISCALL_SIMPLE(IsAmbienceTrackActive, _ZN23CAEAmbienceTrackManager21IsAmbienceTrackActiveEv, u8);
    DECL_THISCALL_SIMPLE(GetAmbienceTrackStatus, _ZN23CAEAmbienceTrackManager22GetAmbienceTrackStatusEv, i8);
    DECL_THISCALL_SIMPLE(IsAmbienceRadioActive, _ZN23CAEAmbienceTrackManager21IsAmbienceRadioActiveEv, u8);
    DECL_THISCALL_HEAD(PlaySpecialMissionAmbienceTrack, _ZN23CAEAmbienceTrackManager31PlaySpecialMissionAmbienceTrackEi, void, i32 trackId)
    DECL_THISCALL_TAIL(PlaySpecialMissionAmbienceTrack, trackId)
    DECL_THISCALL_SIMPLE(StopSpecialMissionAmbienceTrack, _ZN23CAEAmbienceTrackManager31StopSpecialMissionAmbienceTrackEv, void);
    DECL_THISCALL_SIMPLE(UpdateAmbienceTrackAndVolume, _ZN23CAEAmbienceTrackManager28UpdateAmbienceTrackAndVolumeEv, void);
    DECL_THISCALL_SIMPLE(StartTrackPlayback, _ZN23CAEAmbienceTrackManager18StartTrackPlaybackEv, void);
    DECL_THISCALL_SIMPLE(CheckForPause, _ZN23CAEAmbienceTrackManager13CheckForPauseEv, void);

    // Member values
    u8 m_bOverrideRadio;
    u8 m_bLastAmbienceOverrodeRadio;
    u8 m_bStartAmbienceAtBeginning;
    i8 m_nAmbienceRadioStation;
    i32 m_nHardwareClientHandle;
    i32 m_nAmbienceStatus;
    i32 m_nSpecialMissionAmbienceTrackID;
    i32 m_nPreviousAmbiencePlayTimeMs;
    u32 m_nPreviousAmbienceStopTimeMs;
    float m_fAmbienceVolume;
    float m_fAmbienceFrequencyScalingFactor;
    tAmbienceSettings m_RequestedSettings;
    tAmbienceSettings m_ActiveSettings;
DECL_CLASS_END()
CHECKSIZE(CAEAmbienceTrackManager, 0x38, 0x38);

DECL_OBJECT_PLT_GLOBAL(CAEAmbienceTrackManager, AEAmbienceTrackManager, BYBIT(0x67667c, 0x84ad50));

#endif // __AML_PSDK_SAAEAMBIENCETRACKMANAGER_H
