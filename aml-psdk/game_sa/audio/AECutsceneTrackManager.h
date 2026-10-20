#ifndef __AML_PSDK_SAAECUTSCENETRACKMANAGER_H
#define __AML_PSDK_SAAECUTSCENETRACKMANAGER_H

#include <aml-psdk/game_sa/plugin.h>

DECL_CLASS(tCutsceneSettings)
    // Member values
    i32 TrackID;
    i32 PlayingTrackID;
    i32 PlayTime;
    i32 TrackLengthMs;
    char TrackFlags;
DECL_CLASS_END()
CHECKSIZE(tCutsceneSettings, 0x14, 0x14);

DECL_CLASS(CAECutsceneTrackManager)
    // Member functions
    DECL_THISCALL_HEAD(Initialise, _ZN23CAECutsceneTrackManager10InitialiseEi, u8, i32 clientHandle)
    DECL_THISCALL_TAIL(Initialise, clientHandle)
    DECL_THISCALL_HEAD(Service, _ZN23CAECutsceneTrackManager7ServiceEi, void, i32 playTime)
    DECL_THISCALL_TAIL(Service, playTime)
    DECL_THISCALL_HEAD(PreloadCutsceneTrack, _ZN23CAECutsceneTrackManager20PreloadCutsceneTrackEsh, void, i16 trackId, u8 wait)
    DECL_THISCALL_TAIL(PreloadCutsceneTrack, trackId, wait)
    DECL_THISCALL_SIMPLE(PlayPreloadedCutsceneTrack, _ZN23CAECutsceneTrackManager26PlayPreloadedCutsceneTrackEv, void);
    DECL_THISCALL_SIMPLE(StopCutsceneTrack, _ZN23CAECutsceneTrackManager17StopCutsceneTrackEv, void);
    DECL_THISCALL_SIMPLE(IsCutsceneTrackActive, _ZN23CAECutsceneTrackManager21IsCutsceneTrackActiveEv, u8);
    DECL_THISCALL_SIMPLE(GetCutsceneTrackStatus, _ZN23CAECutsceneTrackManager22GetCutsceneTrackStatusEv, i8);
    DECL_THISCALL_HEAD(PreloadBeatTrack, _ZN23CAECutsceneTrackManager16PreloadBeatTrackEsh, void, i16 trackId, u8 wait)
    DECL_THISCALL_TAIL(PreloadBeatTrack, trackId, wait)
    DECL_THISCALL_HEAD(PauseTrack, _ZN23CAECutsceneTrackManager10PauseTrackEh, void, u8 paused)
    DECL_THISCALL_TAIL(PauseTrack, paused)
    DECL_THISCALL_SIMPLE(StartTrackPlayback, _ZN23CAECutsceneTrackManager18StartTrackPlaybackEv, void);
    DECL_THISCALL_SIMPLE(CheckForPause, _ZN23CAECutsceneTrackManager13CheckForPauseEv, void);

    // Member values
    u8 m_bStartCutscenePlayback;
    u8 m_bManuallyPauseTrack;
    i32 m_nHardwareClientHandle;
    i32 m_nCutsceneStatus;
    tCutsceneSettings m_RequestedSettings;
    tCutsceneSettings m_ActiveSettings;
DECL_CLASS_END()
CHECKSIZE(CAECutsceneTrackManager, 0x34, 0x34);

DECL_OBJECT_PLT_GLOBAL(CAECutsceneTrackManager, AECutsceneTrackManager, BYBIT(0x679214, 0x850448));

#endif // __AML_PSDK_SAAECUTSCENETRACKMANAGER_H
