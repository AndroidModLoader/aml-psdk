#ifndef __AML_PSDK_SAMENUMANAGER_H
#define __AML_PSDK_SAMENUMANAGER_H

#include <aml-psdk/game_sa/engine/Sprite2d.h>
#include <aml-psdk/game_sa/enum/HID.h>
#include <aml-psdk/gta_base/Rect.h>

struct RwRaster;

enum LANGUAGE
{
    LANGUAGE_ENGLISH = 0,
    LANGUAGE_FRENCH = 1,
    LANGUAGE_GERMAN = 2,
    LANGUAGE_ITALIAN = 3,
    LANGUAGE_SPANISH = 4,
    LANGUAGE_RUSSIAN = 5,
    LANGUAGE_JAPANESE = 6,
    LANGUAGE_KOREAN = 7
};


DECL_CLASS(CMenuManager)
    DECL_CLASS(MissionPackStruct)
        // Member values
        u8 id;
        char name[260];
    DECL_CLASS_END()

    // Construct/Deconstruct functions
    DECL_CTORCALL(CMenuManager, _ZN12CMenuManagerC2Ev);
    DECL_DTORCALL(CMenuManager, _ZN12CMenuManagerD2Ev);

    // Member functions
    DECL_THISCALL_SIMPLE(Process, _ZN12CMenuManager7ProcessEv, void);
    DECL_THISCALL_SIMPLE(DrawFrontEnd, _ZN12CMenuManager12DrawFrontEndEv, void);
    DECL_THISCALL_SIMPLE(LoadAllTextures, _ZN12CMenuManager15LoadAllTexturesEv, void);
    DECL_THISCALL_SIMPLE(UnloadTextures, _ZN12CMenuManager14UnloadTexturesEv, void);
    DECL_THISCALL_HEAD(MessageScreen, _ZN12CMenuManager13MessageScreenEPcbb, void, char* text, bool blackBackground, bool cameraUpdate)
    DECL_THISCALL_TAIL(MessageScreen, text, blackBackground, cameraUpdate)
    DECL_THISCALL_HEAD(DrawWindow, _ZN12CMenuManager10DrawWindowERK5CRectPch5CRGBAhh, void, CRect const& rect, char* title, u8 background, CRGBA color, u8 unused1, u8 unused2)
    DECL_THISCALL_TAIL(DrawWindow, rect, title, background, color, unused1, unused2)
    DECL_THISCALL_HEAD(DrawWindowedText, _ZN12CMenuManager16DrawWindowedTextEfffPcS0_h, void, float x, float y, float width, char* title, char* text, u8 alignment)
    DECL_THISCALL_TAIL(DrawWindowedText, x, y, width, title, text, alignment)
    DECL_THISCALL_SIMPLE(CheckFrontEndUpInput, _ZN12CMenuManager20CheckFrontEndUpInputEv, u8);
    DECL_THISCALL_SIMPLE(CheckFrontEndDownInput, _ZN12CMenuManager22CheckFrontEndDownInputEv, u8);
    DECL_THISCALL_SIMPLE(CheckFrontEndLeftInput, _ZN12CMenuManager22CheckFrontEndLeftInputEv, u8);
    DECL_THISCALL_SIMPLE(CheckFrontEndRightInput, _ZN12CMenuManager23CheckFrontEndRightInputEv, u8);
    DECL_THISCALL_SIMPLE(HasLanguageChanged, _ZN12CMenuManager18HasLanguageChangedEv, u8);
    DECL_THISCALL_SIMPLE(CheckMissionPackValidMenu, _ZN12CMenuManager25CheckMissionPackValidMenuEv, u8);
    DECL_THISCALL_HEAD(ChangeLanguage, _ZN12CMenuManager14ChangeLanguageEa, void, i8 language)
    DECL_THISCALL_TAIL(ChangeLanguage, language)
    DECL_THISCALL_SIMPLE(LoadSettings, _ZN12CMenuManager12LoadSettingsEv, void);
    DECL_THISCALL_SIMPLE(ProcessMissionPackNewGame, _ZN12CMenuManager25ProcessMissionPackNewGameEv, void);
    DECL_THISCALL_SIMPLE(UserInput, _ZN12CMenuManager9UserInputEv, void);
    DECL_THISCALL_HEAD(DisplaySlider, _ZN12CMenuManager13DisplaySliderEffffffi, i32, float x, float y, float width, float height, float left, float right, i32 value)
    DECL_THISCALL_TAIL(DisplaySlider, x, y, width, height, left, right, value)
    DECL_THISCALL_SIMPLE(SwitchMenuOnAndOff, _ZN12CMenuManager18SwitchMenuOnAndOffEv, void);
    DECL_THISCALL_SIMPLE(DrawBackground, _ZN12CMenuManager14DrawBackgroundEv, void);
    DECL_THISCALL_HEAD(DrawStandardMenus, _ZN12CMenuManager17DrawStandardMenusEh, void, u8 drawSelected)
    DECL_THISCALL_TAIL(DrawStandardMenus, drawSelected)
    DECL_THISCALL_SIMPLE(PrintRadioStationList, _ZN12CMenuManager21PrintRadioStationListEv, void);
    DECL_THISCALL_SIMPLE(PrintStats, _ZN12CMenuManager10PrintStatsEv, void);
    DECL_THISCALL_HEAD(SwapTexturesRound, _ZN12CMenuManager17SwapTexturesRoundEh, void, u8 loaded)
    DECL_THISCALL_TAIL(SwapTexturesRound, loaded)
    DECL_THISCALL_SIMPLE(PrintMap, _ZN12CMenuManager8PrintMapEv, void);
    DECL_THISCALL_SIMPLE(PrintBrief, _ZN12CMenuManager10PrintBriefEv, void);
    DECL_THISCALL_SIMPLE(DoSettingsBeforeStartingAGame, _ZN12CMenuManager29DoSettingsBeforeStartingAGameEv, void);
    DECL_THISCALL_HEAD(ScrollRadioStations, _ZN12CMenuManager19ScrollRadioStationsEa, void, i8 direction)
    DECL_THISCALL_TAIL(ScrollRadioStations, direction)
    DECL_THISCALL_HEAD(AdditionalOptionInput, _ZN12CMenuManager21AdditionalOptionInputEPhS0_, void, u8* accept, u8* exit)
    DECL_THISCALL_TAIL(AdditionalOptionInput, accept, exit)
    DECL_THISCALL_HEAD(ProcessUserInput, _ZN12CMenuManager16ProcessUserInputEhhhha, void, u8 left, u8 right, u8 accept, u8 exit, i8 direction)
    DECL_THISCALL_TAIL(ProcessUserInput, left, right, accept, exit, direction)
    DECL_THISCALL_HEAD(ProcessStreaming, _ZN12CMenuManager16ProcessStreamingEh, void, u8 streaming)
    DECL_THISCALL_TAIL(ProcessStreaming, streaming)
    DECL_THISCALL_SIMPLE(ProcessFileActions, _ZN12CMenuManager18ProcessFileActionsEv, void);
    DECL_THISCALL_HEAD(JumpToGenericMessageScreen, _ZN12CMenuManager26JumpToGenericMessageScreenEaPKcS1_, void, i8 screen, char const* title, char const* text)
    DECL_THISCALL_TAIL(JumpToGenericMessageScreen, screen, title, text)
    DECL_THISCALL_SIMPLE(Initialise, _ZN12CMenuManager10InitialiseEv, void);
    DECL_THISCALL_HEAD(StretchX, _ZN12CMenuManager8StretchXEf, float, float x)
    DECL_THISCALL_TAIL(StretchX, x)
    DECL_THISCALL_HEAD(StretchY, _ZN12CMenuManager8StretchYEf, float, float y)
    DECL_THISCALL_TAIL(StretchY, y)
    DECL_THISCALL_HEAD(SmallMessageScreen, _ZN12CMenuManager18SmallMessageScreenEPKc, void, char const* text)
    DECL_THISCALL_TAIL(SmallMessageScreen, text)
    DECL_THISCALL_HEAD(SwitchToNewScreen, _ZN12CMenuManager17SwitchToNewScreenEa, void, i8 screen)
    DECL_THISCALL_TAIL(SwitchToNewScreen, screen)
    DECL_THISCALL_HEAD(ProcessMenuOptions, _ZN12CMenuManager18ProcessMenuOptionsEaPhh, void, i8 direction, u8* accept, u8 cancel)
    DECL_THISCALL_TAIL(ProcessMenuOptions, direction, accept, cancel)
    DECL_THISCALL_HEAD(CheckSliderMovement, _ZN12CMenuManager19CheckSliderMovementEa, void, i8 direction)
    DECL_THISCALL_TAIL(CheckSliderMovement, direction)
    DECL_THISCALL_HEAD(InitialiseChangedLanguageSettings, _ZN12CMenuManager33InitialiseChangedLanguageSettingsEb, void, bool reinitialise)
    DECL_THISCALL_TAIL(InitialiseChangedLanguageSettings, reinitialise)
    DECL_THISCALL_SIMPLE(GetNumberOfMenuOptions, _ZN12CMenuManager22GetNumberOfMenuOptionsEv, u8);
    DECL_THISCALL_SIMPLE(SetFrontEndRenderStates, _ZN12CMenuManager23SetFrontEndRenderStatesEv, void);
    DECL_THISCALL_SIMPLE(SaveSettings, _ZN12CMenuManager12SaveSettingsEv, void);
    DECL_THISCALL_HEAD(SetDefaultPreferences, _ZN12CMenuManager21SetDefaultPreferencesEa, void, i8 screen)
    DECL_THISCALL_TAIL(SetDefaultPreferences, screen)
    DECL_THISCALL_SIMPLE(CheckRedefineControlInput, _ZN12CMenuManager25CheckRedefineControlInputEv, u8);
    DECL_THISCALL_HEAD(ProcessPCMenuOptions, _ZN12CMenuManager20ProcessPCMenuOptionsEah, u8, i8 direction, u8 accept)
    DECL_THISCALL_TAIL(ProcessPCMenuOptions, direction, accept)
    DECL_THISCALL_SIMPLE(DrawControllerSetupScreen, _ZN12CMenuManager25DrawControllerSetupScreenEv, void);
    DECL_THISCALL_HEAD(DrawContollerScreenExtraText, _ZN12CMenuManager28DrawContollerScreenExtraTextEi, void, i32 controlType)
    DECL_THISCALL_TAIL(DrawContollerScreenExtraText, controlType)
    DECL_THISCALL_HEAD(DrawControllerBound, _ZN12CMenuManager19DrawControllerBoundEtb, void, u16 action, bool selected)
    DECL_THISCALL_TAIL(DrawControllerBound, action, selected)
    DECL_THISCALL_HEAD(CheckCodesForControls, _ZN12CMenuManager21CheckCodesForControlsEi, void, i32 keyCode)
    DECL_THISCALL_TAIL(CheckCodesForControls, keyCode)
    DECL_THISCALL_HEAD(RedefineScreenUserInput, _ZN12CMenuManager23RedefineScreenUserInputEPhS0_, void, u8* accept, u8* exit)
    DECL_THISCALL_TAIL(RedefineScreenUserInput, accept, exit)
    DECL_THISCALL_SIMPLE(SaveLoadFileError_SetUpErrorScreen, _ZN12CMenuManager34SaveLoadFileError_SetUpErrorScreenEv, void);
    DECL_THISCALL_SIMPLE(CentreMousePointer, _ZN12CMenuManager18CentreMousePointerEv, void);
    DECL_THISCALL_HEAD(SetHelperText, _ZN12CMenuManager13SetHelperTextEi, void, i32 textId)
    DECL_THISCALL_TAIL(SetHelperText, textId)
    DECL_THISCALL_SIMPLE(ResetHelperText, _ZN12CMenuManager15ResetHelperTextEv, void);
    DECL_THISCALL_HEAD(DisplayHelperText, _ZN12CMenuManager17DisplayHelperTextEPc, void, char* text)
    DECL_THISCALL_TAIL(DisplayHelperText, text)
    DECL_THISCALL_HEAD(CheckHover, _ZN12CMenuManager10CheckHoverEiiii, u8, i32 left, i32 right, i32 top, i32 bottom)
    DECL_THISCALL_TAIL(CheckHover, left, right, top, bottom)
    DECL_THISCALL_SIMPLE(SaveStatsToFile, _ZN12CMenuManager15SaveStatsToFileEv, void);
    DECL_THISCALL_SIMPLE(DrawQuitGameScreen, _ZN12CMenuManager18DrawQuitGameScreenEv, void);

    // Member values
    u8 BriefDisplay;
    i32 CurrentGallerySelected;
    i32 CurrentMaxGalleryImages;
    i32 CurrentMaxRealPhotos;
    i32 CurrentSelectedRealPhoto;
    u32 ReloadImageTime;
    u8 m_PrefsUseVibration;
    u8 m_PrefsDisplayHud;
    i32 waypoint_blip;
    u8 m_DisplayControllerOnFoot;
    u8 bPauseWhenInWidescreen;
    u8 m_bEnteredViaGallery;
    u8 m_bFakeEnteredViaGallery;
    i32 m_KeyPressedCode;
    float m_PrefsLOD;
    u8 m_PrefsShowSubtitles;
    u8 m_PrefsShowLegend;
    u8 m_PrefsUseWideScreen;
    u8 m_PrefsFrameLimiter;
    u8 m_PrefsAutoRetune;
    i8 m_PrefsAudioOutputMode;
    i8 m_PrefsSfxVolume;
    i8 m_PrefsMusicVolume;
    u8 m_PrefsUseBass;
    i8 m_PrefsRadioStation;
    u8 recheckNumPhotos;
    i32 CurrentOption;
    u8 ExitToOS;
    u8 InOptionsMenu;
    i32 OS_Language;
    LANGUAGE m_PrefsKeyboardLanguage;
    i8 m_PrefsLanguage;
    i8 m_previousLanguage;
    LANGUAGE m_SystemLanguage;
    u8 LoadedLanguage;
    i32 ListSelection;
    i32 RenderScreenOnce;
    char* gallery_image_buffer;
    RwRaster* gpJpgTex;
    u8 m_bStartUpFrontEndRequestedForPads;
    i32 ScreenXOffset;
    i32 ScreenYOffset;
    u32 m_PrefsLastUserTrackID;
    i8 m_PrefsPlayMode;
    bool m_PrefsJoyLeftXInvert;
    bool m_PrefsJoyLeftYInvert;
    bool m_PrefsJoyRightXInvert;
    bool m_PrefsJoyRightYInvert;
    bool m_PrefsJoyLeftAxisInvert;
    bool m_PrefsJoyRightAxisInvert;
    u8 RedefiningControls;
    u8 DisplayTheMouse;
    i32 MousePosX;
    i32 MousePosY;
    bool m_PrefsMipMap;
    bool m_PrefsAutoMediaScan;
    i32 m_PrefsAntiAliasing;
    i32 m_PrefsAntiAliasingDisp;
    i8 m_ControlMethod;
    i32 m_PrefsResolution;
    i32 m_PrefsResolutionDisp;
    i32 m_PrefsSubSystem;
    i32 WinMousePosX;
    i32 WinMousePosY;
    bool m_PrefsSavePhotosToGallery;
    u8 m_MainMenu;
    u8 m_PrefsMarketing;
    i32 m_PrefsMobileEffects;
    u8 m_UseDebugScripts;
    u8 m_PrefsShowFPS;
    u8 CurrentPadInUse;
    u8 bFrontEnd_ReloadObrTxtGxt;
    i32* pControlEdit;
    CSprite2d FrontEndSprites[25];
    u8 TexturesLoaded;
    i8 CurrentScreen;
    i8 PreviousScreen;
    u8 CurrentSelectedMissionPack;
    MissionPackStruct MissionPack[25];
    eMouseButtons MouseButtonJustClicked;
    eJOY_BUTTONS JoyButtonJustClicked;
    u8 MenuIsAbleToQuit;
    i8 DisplayWarningScreenForUnboundControls;
    bool DisplayWarningScreenForUserTrackScanning;
    i32 DefaultsFadeCounter;
    u8 key_pressed[5];
    i32 oldMousePosX;
    i32 oldMousePosY;
    i32 MouseInBounds;
    i32 CurrentMouseOption;
    bool m_bJustEnteredOption;
    u8 m_EditingControlOptions;
    u8 m_DeleteAllBoundControls;
    u8 m_DeleteAllNextDefine;
    i32 OptionToChange;
    i32 OptionProcessing;
    u8 CanBeDefined;
    u8 JustExitedRedefine;
    i32 CurrentHelperMessage;
    u32 TimeToStopPadShaking;
DECL_CLASS_END()
CHECKSIZE(CMenuManager, 0x1ae4, 0x1b60);

CHECKSIZE(CMenuManager::MissionPackStruct, 0x105, 0x105);

DECL_OBJECT_PLT_GLOBAL(CMenuManager, FrontEndMenuManager, BYBIT(0x678a34, 0x84f488));

#endif // __AML_PSDK_SAMENUMANAGER_H
