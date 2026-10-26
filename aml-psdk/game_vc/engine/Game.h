#ifndef __AML_PSDK_VCGAME_H
#define __AML_PSDK_VCGAME_H

#include <aml-psdk/game_vc/plugin.h>

DECL_CLASS(CGame)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(InitialiseOnceBeforeRW, _ZN5CGame22InitialiseOnceBeforeRWEv, bool);
    DECL_FASTCALL_SIMPLE(InitialiseRenderWare, _ZN5CGame20InitialiseRenderWareEv, bool);
    DECL_FASTCALL_SIMPLE(ShutdownRenderWare, _ZN5CGame18ShutdownRenderWareEv, void);
    DECL_FASTCALL_SIMPLE(InitialiseOnceAfterRW, _ZN5CGame21InitialiseOnceAfterRWEv, bool);
    DECL_FASTCALL_SIMPLE(FinalShutdown, _ZN5CGame13FinalShutdownEv, void);
    DECL_FASTCALL_SIMPLE(InitAfterLostFocus, _ZN5CGame18InitAfterLostFocusEv, void);
    DECL_FASTCALL_SIMPLE(Initialise, _ZN5CGame10InitialiseEPKc, bool, const char* pDatFile);
    DECL_FASTCALL_SIMPLE(Shutdown, _ZN5CGame8ShutdownEv, bool);
    DECL_FASTCALL_SIMPLE(ReInitGameObjectVariables, _ZN5CGame25ReInitGameObjectVariablesEv, void);
    DECL_FASTCALL_SIMPLE(ShutDownForRestart, _ZN5CGame18ShutDownForRestartEv, void);
    DECL_FASTCALL_SIMPLE(InitialiseWhenRestarting, _ZN5CGame24InitialiseWhenRestartingEv, void);
    DECL_FASTCALL_SIMPLE(Process, _ZN5CGame7ProcessEv, void);
    DECL_FASTCALL_SIMPLE(CanSeeOutSideFromCurrArea, _ZN5CGame25CanSeeOutSideFromCurrAreaEv, bool);
    DECL_FASTCALL_SIMPLE(CanSeeWaterFromCurrArea, _ZN5CGame23CanSeeWaterFromCurrAreaEv, bool);

    // STATIC values
    DECL_VALUE_PLT_I32(currLevel, BYBIT(0x396cbc, 0x57b988));
    DECL_VALUE_PLT_I32(currArea, BYBIT(0x395f08, 0x579e40));
    DECL_VALUE_PLT_BOOL(germanGame, BYBIT(0x394984, 0x5773f0));
    DECL_VALUE_PLT_BOOL(frenchGame, BYBIT(0x3962cc, 0x57a5a0));
    DECL_VALUE_PLT_BOOL(lessNastyGame, BYBIT(0x394ca8, 0x577a20));
    DECL_VALUE_PLT_BOOL(nastyGame, BYBIT(0x395434, 0x5788c0));
    DECL_VALUE_PLT_BOOL(noProstitutes, BYBIT(0x3963ec, 0x57a7c0));
    DECL_VALUE_PLT_BOOL(playingIntro, BYBIT(0x395e9c, 0x579d68));
    DECL_VALUE_PLT_BOOL(bDemoMode, BYBIT(0x394d14, 0x577ae0));
DECL_CLASS_END()

#define currLevel currLevel()
#define currArea currArea()
#define germanGame germanGame()
#define frenchGame frenchGame()
#define lessNastyGame lessNastyGame()
#define nastyGame nastyGame()
#define noProstitutes noProstitutes()
#define playingIntro playingIntro()
#define bDemoMode bDemoMode()

DECL_VALUE_PLT_I32_GLOBAL(gGameState, BYBIT(0x396768, 0x57aed0));
#define gGameState ( gGameState() )

#endif // __AML_PSDK_VCGAME_H
