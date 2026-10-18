#ifndef __AML_PSDK_SAAESTREAMTHREAD_H
#define __AML_PSDK_SAAESTREAMTHREAD_H

#include "../engine/OS.h"

struct CAEStreamingChannel;
struct CAEMP3TrackLoader;

DECL_CLASS(CAEStreamThread)
    // Construct/Deconstruct functions
    DECL_DTORCALL(CAEStreamThread, _ZN15CAEStreamThreadD2Ev);
    DECL_CTORCALL(CAEStreamThread, _ZN15CAEStreamThreadC2Ev);

    // STATIC functions
    DECL_FASTCALL_SIMPLE(MainLoop, _ZN15CAEStreamThread8MainLoopEPv, unsigned int, void* pData);

    // Member functions
    DECL_THISCALL_HEAD(Initialise, _ZN15CAEStreamThread10InitialiseEP19CAEStreamingChannel, bool, CAEStreamingChannel* pStreamingChannel)
    DECL_THISCALL_TAIL(Initialise, pStreamingChannel)
    DECL_THISCALL_SIMPLE(Start, _ZN15CAEStreamThread5StartEv, void);
    DECL_THISCALL_SIMPLE(Resume, _ZN15CAEStreamThread6ResumeEv, void);
    DECL_THISCALL_SIMPLE(Pause, _ZN15CAEStreamThread5PauseEv, void);
    DECL_THISCALL_SIMPLE(Stop, _ZN15CAEStreamThread4StopEv, void);
    DECL_THISCALL_SIMPLE(WaitForExit, _ZN15CAEStreamThread11WaitForExitEv, void);
    DECL_THISCALL_HEAD(PlayTrack, _ZN15CAEStreamThread9PlayTrackEjijcbb, void, unsigned int TrackID, int NextTrackID, unsigned int StartOffsetMs, char TrackFlags, bool bUserTrack, bool bUserNextTrack)
    DECL_THISCALL_TAIL(PlayTrack, TrackID, NextTrackID, StartOffsetMs, TrackFlags, bUserTrack, bUserNextTrack)
    DECL_THISCALL_SIMPLE(StopTrack, _ZN15CAEStreamThread9StopTrackEv, void);
    DECL_THISCALL_SIMPLE(GetTrackPlayTime, _ZN15CAEStreamThread16GetTrackPlayTimeEv, long int);
    DECL_THISCALL_SIMPLE(GetTrackLengthMs, _ZN15CAEStreamThread16GetTrackLengthMsEv, int);
    DECL_THISCALL_SIMPLE(GetActiveTrackID, _ZN15CAEStreamThread16GetActiveTrackIDEv, int);
    DECL_THISCALL_SIMPLE(GetPlayingTrackID, _ZN15CAEStreamThread17GetPlayingTrackIDEv, int);
    DECL_THISCALL_SIMPLE(Check, _ZN15CAEStreamThread5CheckEv, void);
    DECL_THISCALL_SIMPLE(IsUserTrack, _ZN15CAEStreamThread11IsUserTrackEv, bool);
    DECL_THISCALL_SIMPLE(Service, _ZN15CAEStreamThread7ServiceEv, void);

    // Member values
    OSThreadHandle m_thread;
    OSMutex m_mutex;
    OSSemaphore m_sem;
    OSMutex m_pauseMutex;
    CAEStreamingChannel* m_pStreamingChannel;
    CAEMP3TrackLoader* m_pTrackLoader;
    bool m_bInitialised;
    bool m_bActive;
    bool m_bNeedService;
    bool m_bUserTrack;
    bool m_bUserNextTrack;
    bool m_bInvalidTrack;
    bool m_bShouldStop;
    unsigned int m_trackID;
    unsigned int m_startOffsetMs;
    int m_nextTrackID;
    char m_trackFlags;
    int m_playTime;
    int m_trackLengthMs;
    int m_activeTrackID;
    int m_playingTrackID;
DECL_CLASS_END()
CHECKSIZE(CAEStreamThread, 0x40, 0x58);

#endif // __AML_PSDK_SAAESTREAMTHREAD_H
