#ifndef __AML_PSDK_VCTIMER_H
#define __AML_PSDK_VCTIMER_H

#include <aml-psdk/game_vc/plugin.h>

DECL_CLASS(CTimer)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(Initialise, _ZN6CTimer10InitialiseEv, void);
    DECL_FASTCALL_SIMPLE(Shutdown, _ZN6CTimer8ShutdownEv, void);
    DECL_FASTCALL_SIMPLE(Update, _ZN6CTimer6UpdateEv, void);
    DECL_FASTCALL_SIMPLE(Suspend, _ZN6CTimer7SuspendEv, void);
    DECL_FASTCALL_SIMPLE(Resume, _ZN6CTimer6ResumeEv, void);
    DECL_FASTCALL_SIMPLE(Stop, _ZN6CTimer4StopEv, void);
    DECL_FASTCALL_SIMPLE(GetCyclesPerMillisecond, _ZN6CTimer23GetCyclesPerMillisecondEv, u32);
    DECL_FASTCALL_SIMPLE(GetCyclesPerFrame, _ZN6CTimer17GetCyclesPerFrameEv, u32);
    DECL_FASTCALL_SIMPLE(GetCurrentTimeInCycles, _ZN6CTimer22GetCurrentTimeInCyclesEv, u32);
    DECL_FASTCALL_SIMPLE(GetIsSlowMotionActive, _ZN6CTimer21GetIsSlowMotionActiveEv, bool);
    DECL_FASTCALL_SIMPLE(StartUserPause, _ZN6CTimer14StartUserPauseEv, void);
    DECL_FASTCALL_SIMPLE(EndUserPause, _ZN6CTimer12EndUserPauseEv, void);
    DECL_FASTCALL_SIMPLE(SetTimeScale, _ZN6CTimer12SetTimeScaleEf, void, float timeScale);
    DECL_FASTCALL_SIMPLE(GetRealTimeScale, _ZN6CTimer16GetRealTimeScaleEv, float);

    // STATIC values
    DECL_VALUE_PLT_U32(m_snTimeInMilliseconds, BYBIT(0x396618, 0x57AC30));
    DECL_VALUE_PLT_U32(m_snTimeInMillisecondsNonClipped, BYBIT(0x396814, 0x57B020));
    DECL_VALUE_PLT_U32(m_snTimeInMillisecondsPauseMode, BYBIT(0x395D04, 0x579A18));
    DECL_VALUE_PLT_U32(m_snPreviousTimeInMilliseconds, BYBIT(0x395CA8, 0x579968));
    DECL_VALUE_PLT_FLT(ms_fTimeScale, BYBIT(0x3965F0, 0x57ABD8));
    DECL_VALUE_PLT_FLT(ms_fTimeStep, BYBIT(0x395FA4, 0x579F68));
    DECL_VALUE_PLT_FLT(ms_fTimeStepNonClipped, BYBIT(0x394E2C, 0x577CD8));
    DECL_VALUE_PLT_U32(m_FrameCounter, BYBIT(0x39460C, 0x576D78));
    DECL_VALUE_PLT_BOOL(m_UserPause, BYBIT(0x395DDC, 0x579BE8));
    DECL_VALUE_PLT_BOOL(m_CodePause, BYBIT(0x3955E8, 0x578C38));

    // Helper functions
    static inline u32 GetTimeInMS()
    {
        return m_snTimeInMilliseconds;
    }
    static inline float GetTimeScale()
    {
        return ms_fTimeScale;
    }
    static inline float GetTimeStep()
    {
        return ms_fTimeStep;
    }
    static inline float GetTimeStepInSeconds()
    {
        return GetTimeStep() / 50.0f;
    }
    static inline bool IsPaused()
    {
        return (m_UserPause() || m_CodePause());
    }
DECL_CLASS_END()

#define m_snTimeInMilliseconds m_snTimeInMilliseconds()
#define m_snTimeInMillisecondsNonClipped m_snTimeInMillisecondsNonClipped()
#define m_snTimeInMillisecondsPauseMode m_snTimeInMillisecondsPauseMode()
#define m_snPreviousTimeInMilliseconds m_snPreviousTimeInMilliseconds()
#define ms_fTimeScale ms_fTimeScale()
#define ms_fTimeStep ms_fTimeStep()
#define ms_fTimeStepNonClipped ms_fTimeStepNonClipped()
#define m_FrameCounter m_FrameCounter()
#define m_UserPause m_UserPause()
#define m_CodePause m_CodePause()

#endif // __AML_PSDK_VCTIMER_H
