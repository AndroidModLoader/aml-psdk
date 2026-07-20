#ifndef __AML_PSDK_SALOADINGSCREEN_H
#define __AML_PSDK_SALOADINGSCREEN_H

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/game_sa/engine/Sprite2d.h>

struct CSprite2d;

DECL_CLASS(CLoadingScreen)
    // Functions
    DECL_FASTCALL_SIMPLE(Init, _ZN14CLoadingScreen4InitEbb, void, bool bLegalScreen, bool dont_reload);
    DECL_FASTCALL_SIMPLE(LoadSplashes, _ZN14CLoadingScreen12LoadSplashesEhh, void, u8 use_splash_id, u8 id);
    DECL_FASTCALL_SIMPLE(GetClockTime, _ZN14CLoadingScreen12GetClockTimeEb, float, bool bRealTime);
    DECL_FASTCALL_SIMPLE(Shutdown, _ZN14CLoadingScreen8ShutdownEb, void, bool bForce);
    DECL_FASTCALL_SIMPLE(Pause, _ZN14CLoadingScreen5PauseEv, void);
    DECL_FASTCALL_SIMPLE(Continue, _ZN14CLoadingScreen8ContinueEv, void);
    DECL_FASTCALL_SIMPLE(NewChunkLoaded, _ZN14CLoadingScreen14NewChunkLoadedEv, void);
    DECL_FASTCALL_SIMPLE(DisplayPCScreen, _ZN14CLoadingScreen15DisplayPCScreenEv, void);
    DECL_FASTCALL_SIMPLE(RenderSplash, _ZN14CLoadingScreen12RenderSplashEv, void);
    DECL_FASTCALL_SIMPLE(DoPCTitleFadeIn, _ZN14CLoadingScreen15DoPCTitleFadeInEv, void);
    DECL_FASTCALL_SIMPLE(DoPCTitleFadeOut, _ZN14CLoadingScreen16DoPCTitleFadeOutEv, void);
    DECL_FASTCALL_SIMPLE(SetChunksToLoad, _ZN14CLoadingScreen15SetChunksToLoadEib, void, int num, bool AddTo);
    DECL_FASTCALL_SIMPLE(DoPCScreenChange, _ZN14CLoadingScreen16DoPCScreenChangeEjj, void, u32 bLastOne, u32 change);
    DECL_FASTCALL_SIMPLE(RenderLoadingBar, _ZN14CLoadingScreen16RenderLoadingBarEv, void);
    DECL_FASTCALL_SIMPLE(DisplayNextSplash, _ZN14CLoadingScreen17DisplayNextSplashEv, void);
    DECL_FASTCALL_SIMPLE(DisplayMessage, _ZN14CLoadingScreen14DisplayMessageEPKc, void, const char* pMsg);
    DECL_FASTCALL_SIMPLE(SetLoadingBarMsg, _ZN14CLoadingScreen16SetLoadingBarMsgEPKcS1_, void, const char* pMsg, const char* pMsg2);
    DECL_FASTCALL_SIMPLE(Update, _ZN14CLoadingScreen6UpdateEv, void);
    DECL_FASTCALL_SIMPLE(StartFading, _ZN14CLoadingScreen11StartFadingEv, void);

    // Static values
    DECL_VALUE_PLT_I32(m_currDisplayedSplash, BYBIT(0x67675C, 0x84AF10));
    DECL_VALUE_PLT_I32(m_numChunksLoaded, BYBIT(0x676DB8, 0x84BBB8));
    DECL_VALUE_PLT_I32(m_nChunksToLoad, BYBIT(0x676B38, 0x84B6B8));
    DECL_VALUE_PLT_I32(m_chunkBarAppeared, BYBIT(0x679984, 0x851320));
    DECL_VALUE_PLT_BOOL(m_bActive, BYBIT(0x679D2C, 0x851A70));
    DECL_VALUE_PLT_BOOL(m_bWantToPause, BYBIT(0x676438, 0x84A8C8));
    DECL_VALUE_PLT_BOOL(m_bPaused, BYBIT(0x6768D8, 0x84B208));
    DECL_VALUE_ADDR_BOOL(m_bForceShutdown, BYBIT(0x9920A3, 0xC20EDB));  // no .got slot: addressed PC-relatively
    DECL_OBJECT_ARRAY_PLT(CSprite2d, m_aSplashes, BYBIT(0x676354, 0x84A700));
    DECL_VALUE_PLT_BOOL(m_bFading, BYBIT(0x679CD4, 0x8519C0));
    DECL_VALUE_PLT_BOOL(m_bLegalScreen, BYBIT(0x67611C, 0x84A298));
    DECL_VALUE_PLT_BOOL(m_bFadeInNextSplashFromBlack, BYBIT(0x677F98, 0x84DF50));
    DECL_VALUE_PLT_BOOL(m_bFadeOutCurrSplashToBlack, BYBIT(0x678B64, 0x84F6F0));
    DECL_VALUE_PLT_U8(m_FadeAlpha, BYBIT(0x678F64, 0x84FEF0));
    DECL_VALUE_PLT_FLT(m_StartFadeTime, BYBIT(0x679688, 0x850D20));
    DECL_VALUE_PLT_FLT(m_ClockTimeOnPause, BYBIT(0x676534, 0x84AAC0));
    DECL_VALUE_PLT_FLT(m_PauseTime, BYBIT(0x679A88, 0x851530));
    DECL_VALUE_PLT_FLT(m_PercentLoaded, BYBIT(0x677FA8, 0x84DF70));
    DECL_VALUE_PLT_FLT(m_TimeStartedLoading, BYBIT(0x678314, 0x84E640));
    DECL_VALUE_PLT_FLT(m_TimeBarAppeared, BYBIT(0x678240, 0x84E498));
    DECL_OBJECT_ARRAY_PLT(GxtChar, m_LoadingGxtMsg1, BYBIT(0x678564, 0x84EAE0));
    DECL_OBJECT_ARRAY_PLT(GxtChar, m_LoadingGxtMsg2, BYBIT(0x677B48, 0x84D6B0));
    DECL_OBJECT_ARRAY_PLT(char, m_PopUpMessage, BYBIT(0x679494, 0x850940));
    DECL_VALUE_PLT_BOOL(m_bSignalDelete, BYBIT(0x679EC8, 0x851DA0));
    DECL_VALUE_PLT_BOOL(m_bReadyToDelete, BYBIT(0x6769BC, 0x84B3C0));
    DECL_VALUE_PLT_FLT(m_timeSinceLastScreen, BYBIT(0x677920, 0x84D268));
DECL_CLASS_END()

#define m_currDisplayedSplash m_currDisplayedSplash()
#define m_numChunksLoaded m_numChunksLoaded()
#define m_nChunksToLoad m_nChunksToLoad()
#define m_chunkBarAppeared m_chunkBarAppeared()
// #define m_bActive m_bActive()  -- omitted: collides with an instance field elsewhere; use CLoadingScreen::m_bActive() instead
#define m_bWantToPause m_bWantToPause()
#define m_bPaused m_bPaused()
#define m_bForceShutdown m_bForceShutdown()
#define m_aSplashes m_aSplashes()
// #define m_bFading m_bFading()  -- omitted: collides with an instance field elsewhere; use CLoadingScreen::m_bFading() instead
#define m_bLegalScreen m_bLegalScreen()
#define m_bFadeInNextSplashFromBlack m_bFadeInNextSplashFromBlack()
#define m_bFadeOutCurrSplashToBlack m_bFadeOutCurrSplashToBlack()
#define m_FadeAlpha m_FadeAlpha()
#define m_StartFadeTime m_StartFadeTime()
#define m_ClockTimeOnPause m_ClockTimeOnPause()
#define m_PauseTime m_PauseTime()
#define m_PercentLoaded m_PercentLoaded()
#define m_TimeStartedLoading m_TimeStartedLoading()
#define m_TimeBarAppeared m_TimeBarAppeared()
#define m_LoadingGxtMsg1 m_LoadingGxtMsg1()
#define m_LoadingGxtMsg2 m_LoadingGxtMsg2()
#define m_PopUpMessage m_PopUpMessage()
#define m_bSignalDelete m_bSignalDelete()
#define m_bReadyToDelete m_bReadyToDelete()
#define m_timeSinceLastScreen m_timeSinceLastScreen()

#endif // __AML_PSDK_SALOADINGSCREEN_H
