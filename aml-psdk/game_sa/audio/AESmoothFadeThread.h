#ifndef __AML_PSDK_SAAESMOOTHFADETHREAD_H
#define __AML_PSDK_SAAESMOOTHFADETHREAD_H

#include <aml-psdk/game_sa/plugin.h>

struct OALSource;

enum AE_FADE_STATE
{
    AE_FADE_STATE_IDLE = 0,
    AE_FADE_STATE_ACTIVE = 1,
    AE_FADE_STATE_CANCELLED = 2
};


DECL_CLASS(FadeRequest)
    // Member values
    OALSource* oalSource;
    float startVol;
    float finishVol;
    float volDiff;
    float currentVol;
    bool shouldStop;
    u16 duration;
    AE_FADE_STATE state;
    u32 timeRequested;
DECL_CLASS_END()
CHECKSIZE(FadeRequest, 0x20, 0x28);

DECL_CLASS(CAESmoothFadeThread)
    // Construct/Deconstruct functions
    DECL_CTORCALL(CAESmoothFadeThread, _ZN19CAESmoothFadeThreadC2Ev);
    DECL_DTORCALL(CAESmoothFadeThread, _ZN19CAESmoothFadeThreadD2Ev);

    // STATIC functions
    DECL_FASTCALL_SIMPLE(SmoothFadeProc, _ZN19CAESmoothFadeThread14SmoothFadeProcEPv, u32, void* data);

    // Member functions
    DECL_THISCALL_SIMPLE(Initialise, _ZN19CAESmoothFadeThread10InitialiseEv, bool);
    DECL_THISCALL_SIMPLE(WaitForExit, _ZN19CAESmoothFadeThread11WaitForExitEv, void);
    DECL_THISCALL_SIMPLE(Start, _ZN19CAESmoothFadeThread5StartEv, void);
    DECL_THISCALL_SIMPLE(Stop, _ZN19CAESmoothFadeThread4StopEv, void);
    DECL_THISCALL_HEAD(RequestFade, _ZN19CAESmoothFadeThread11RequestFadeEP9OALSourcefsb, bool, OALSource* source, float volume, i16 duration, bool stopAfterFade)
    DECL_THISCALL_TAIL(RequestFade, source, volume, duration, stopAfterFade)
    DECL_THISCALL_HEAD(CancelFade, _ZN19CAESmoothFadeThread10CancelFadeEP9OALSource, void, OALSource* source)
    DECL_THISCALL_TAIL(CancelFade, source)
    DECL_THISCALL_HEAD(SetBufferVolume, _ZN19CAESmoothFadeThread15SetBufferVolumeEP9OALSourcef, void, OALSource* source, float volume)
    DECL_THISCALL_TAIL(SetBufferVolume, source, volume)
    DECL_THISCALL_SIMPLE(InitialiseRequestSlots, _ZN19CAESmoothFadeThread22InitialiseRequestSlotsEv, void);
    DECL_THISCALL_SIMPLE(Service, _ZN19CAESmoothFadeThread7ServiceEv, void);

    // Member values
    void* m_Thread;
    FadeRequest m_fadeRequests[64];
    bool m_bInitialised;
    bool m_bActive;
    u16 m_numRequests;
    u16 m_lastRequest;
    u16 m_oldestRequest;
    u32 m_currentTime;
    bool m_bSmoothFadesDisabled;
    i32 m_nSmoothFades;
DECL_CLASS_END()
CHECKSIZE(CAESmoothFadeThread, 0x818, 0xa20);

DECL_OBJECT_PLT_GLOBAL(CAESmoothFadeThread, AESmoothFadeThread, BYBIT(0x677770, 0x84cf08));

#endif // __AML_PSDK_SAAESMOOTHFADETHREAD_H
