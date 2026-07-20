#ifndef __AML_PSDK_SAHUD_H
#define __AML_PSDK_SAHUD_H

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/game_sa/engine/Sprite2d.h>
#include <aml-psdk/gta_base/RGBA.h>
#include <aml-psdk/gta_base/GxtChar.h>

#define MAX_HUD_SPRITES        6
#define MAX_BIG_MESSAGES       8
#define MAX_BIG_MESSAGE_LENGTH 128
#define MAX_HUD_MESSAGE_LENGTH 400
#define MAX_HUD_COLOURS        16

typedef GxtChar tBigMessageLine[MAX_BIG_MESSAGE_LENGTH];

// Texture order comes straight out of CHud::Initialise().
enum eHudSprite
{
    HUD_SPRITE_FIST = 0,        // "fist"
    HUD_SPRITE_SITEM16,         // "siteM16"
    HUD_SPRITE_SITEROCKET,      // "siterocket"
    HUD_SPRITE_RADARDISC,       // "radardisc"
    HUD_SPRITE_RADARRINGPLANE,  // "radarRingPlane"
    HUD_SPRITE_SKIPICON,        // "skipicon"
    HUD_SPRITE_COUNT
};

// Passed to CHud::DrawFadeState. Named after the binary's own enum.
enum DRAW_FADE_STATE
{
    DS_WANTED = 0,
    DS_ENERGY_LOST,
    DS_DISPLAY_SCORE,
    DS_WEAPON
};

enum eHudColour
{
    HUD_COLOUR_RED = 0,      // 180,  25,  29
    HUD_COLOUR_GREEN,        //  54, 104,  44
    HUD_COLOUR_DARK_BLUE,    //  50,  60, 127
    HUD_COLOUR_LIGHT_BLUE,   // 172, 203, 241
    HUD_COLOUR_BLUE,         // 100, 156, 204
    HUD_COLOUR_WHITE,        // 255, 255, 255
    HUD_COLOUR_BLACK,        //   0,   0,   0
    HUD_COLOUR_BROWN,        // 144,  98,  16
    HUD_COLOUR_PURPLE,       // 168, 110, 252
    HUD_COLOUR_GREY,         // 150, 150, 150
    HUD_COLOUR_DARK_RED,     // 104,  15,  17
    HUD_COLOUR_DARK_GREEN,   //  38,  71,  31
    HUD_COLOUR_SAND,         // 226, 192,  99
    HUD_COLOUR_SLATE,        //  74,  90, 107
    HUD_COLOUR_PURE_BLUE,    //  20,  25, 200
    HUD_COLOUR_YELLOW,       // 255, 255,   0
    HUD_COLOUR_COUNT
};

DECL_CLASS(CHudColours)
    CRGBA value[MAX_HUD_COLOURS];

    // Construct/Deconstruct functions
    DECL_CTORCALL(CHudColours, _ZN11CHudColoursC2Ev);
    DECL_DTORCALL(CHudColours, _ZN11CHudColoursD2Ev);

    // Functions
    DECL_THISCALL_HEAD(SetRGBAValue, _ZN11CHudColours12SetRGBAValueEhhhhh, void, u8 colour_id, u8 r, u8 g, u8 b, u8 a)
    DECL_THISCALL_TAIL(SetRGBAValue, colour_id, r, g, b, a)
    DECL_THISCALL_HEAD(GetRGBA, _ZN11CHudColours7GetRGBAEh, CRGBA, u8 colour_id)
    DECL_THISCALL_TAIL(GetRGBA, colour_id)
    DECL_THISCALL_HEAD(GetRGB, _ZN11CHudColours6GetRGBEhh, CRGBA, u8 colour_id, u8 alpha)
    DECL_THISCALL_TAIL(GetRGB, colour_id, alpha)
    DECL_THISCALL_HEAD(GetIntColour, _ZN11CHudColours12GetIntColourEh, u32, u8 colour_id)
    DECL_THISCALL_TAIL(GetIntColour, colour_id)

    // Helper functions
    inline CRGBA& operator[](int colour_id) { return value[colour_id]; }
DECL_CLASS_END()
CHECKSIZE(CHudColours, 0x40, 0x40);

DECL_CLASS(CHud)
    // Functions
    DECL_FASTCALL_SIMPLE(Initialise, _ZN4CHud10InitialiseEv, void);
    DECL_FASTCALL_SIMPLE(ReInitialise, _ZN4CHud12ReInitialiseEv, void);
    DECL_FASTCALL_SIMPLE(Shutdown, _ZN4CHud8ShutdownEv, void);
    DECL_FASTCALL_SIMPLE(GetRidOfAllHudMessages, _ZN4CHud22GetRidOfAllHudMessagesEh, void, u8 bIgnoreMissionTitle);
    DECL_FASTCALL_SIMPLE(GetYPosBasedOnHealth, _ZN4CHud20GetYPosBasedOnHealthEhfa, float, u8 player, float initial_pos, i8 adjuster);
    DECL_FASTCALL_SIMPLE(SetZoneName, _ZN4CHud11SetZoneNameEPth, void, GxtChar* pZoneName, u8 forced);
    DECL_FASTCALL_SIMPLE(SetHelpMessage, _ZN4CHud14SetHelpMessageEPKcPtbbbj, void, const char* helpLabel, GxtChar* pHelpMsg, bool bQuick, bool bDisplayForever, bool bAddToBrief, u32 nConditionFlag);
    DECL_FASTCALL_SIMPLE(SetHelpMessageStatUpdate, _ZN4CHud24SetHelpMessageStatUpdateEhtff, void, u8 bIncrement, u16 nStatID, float fValue, float fMaxValue);
    DECL_FASTCALL_SIMPLE(SetVehicleName, _ZN4CHud14SetVehicleNameEPt, void, GxtChar* pVehName);
    DECL_FASTCALL_SIMPLE(SetMessage1, _ZN4CHud10SetMessageEPt, void, GxtChar* pMessage);
    DECL_FASTCALL_SIMPLE(SetBigMessage1, _ZN4CHud13SetBigMessageEPtt, void, GxtChar* pMessage, u16 Row);
    DECL_FASTCALL_SIMPLE(ResetWastedText, _ZN4CHud15ResetWastedTextEv, void);
    DECL_FASTCALL_SIMPLE(DrawCrossHairs, _ZN4CHud14DrawCrossHairsEv, void);
    DECL_FASTCALL_SIMPLE(DrawVitalStats, _ZN4CHud14DrawVitalStatsEv, void);
    DECL_FASTCALL_SIMPLE(DrawRadar, _ZN4CHud9DrawRadarEv, void);
    DECL_FASTCALL_SIMPLE(DrawAreaName, _ZN4CHud12DrawAreaNameEv, void);
    DECL_FASTCALL_SIMPLE(DrawVehicleName, _ZN4CHud15DrawVehicleNameEv, void);
    DECL_FASTCALL_SIMPLE(DrawMissionTimers, _ZN4CHud17DrawMissionTimersEv, void);
    DECL_FASTCALL_SIMPLE(DrawHelpText, _ZN4CHud12DrawHelpTextEv, void);
    DECL_FASTCALL_SIMPLE(DrawScriptText, _ZN4CHud14DrawScriptTextEh, void, u8 bBeforeFade);
    DECL_FASTCALL_SIMPLE(DrawSubtitles, _ZN4CHud13DrawSubtitlesEv, void);
    DECL_FASTCALL_SIMPLE(DrawSuccessFailedMessage, _ZN4CHud24DrawSuccessFailedMessageEv, void);
    DECL_FASTCALL_SIMPLE(DrawBustedWastedMessage, _ZN4CHud23DrawBustedWastedMessageEv, void);
    DECL_FASTCALL_SIMPLE(DrawOddJobMessage, _ZN4CHud17DrawOddJobMessageEh, void, u8 bBeforeFade);
    DECL_FASTCALL_SIMPLE(DrawMissionTitle, _ZN4CHud16DrawMissionTitleEv, void);
    DECL_FASTCALL_SIMPLE(Draw, _ZN4CHud4DrawEv, void);
    DECL_FASTCALL_SIMPLE(DrawAfterFade, _ZN4CHud13DrawAfterFadeEv, void);
    DECL_FASTCALL_SIMPLE(DrawFadeState, _ZN4CHud13DrawFadeStateE15DRAW_FADE_STATEi, float, DRAW_FADE_STATE flag, i32 change);

    // Helper functions
    static inline GxtChar tmpString[MAX_HUD_MESSAGE_LENGTH];
    static inline void SetMessage(GxtChar* pMessage)
    {
        SetMessage1(pMessage);
    }
    static inline void SetMessage(const char* txt)
    {
        AsciiToGxtChar(txt, &tmpString[0]);
        SetMessage1(&tmpString[0]);
    }
    static inline void SetBigMessage(GxtChar* pMessage, u16 row)
    {
        SetBigMessage1(pMessage, row);
    }
    static inline void SetBigMessage(const char* txt, u16 row)
    {
        AsciiToGxtChar(txt, &tmpString[0]);
        SetBigMessage1(&tmpString[0], row);
    }

    // STATIC values
    DECL_VALUE_PLT_I16(m_ItemToFlash, BYBIT(0x677888, 0x84D138));
    DECL_OBJECT_ARRAY_PLT(CSprite2d, Sprites, BYBIT(0x678FF8, 0x850018));
    DECL_OBJECT_PLT(GxtChar*, m_pZoneName, BYBIT(0x6766E8, 0x84AE28));
    DECL_OBJECT_PLT(GxtChar*, m_pLastZoneName, BYBIT(0x679A8C, 0x851538));
    DECL_OBJECT_PLT(GxtChar*, m_ZoneToPrint, BYBIT(0x6764AC, 0x84A9B0));
    DECL_OBJECT_ARRAY_PLT(GxtChar, m_Message, BYBIT(0x6763DC, 0x84A810));               // [MAX_HUD_MESSAGE_LENGTH]
    DECL_OBJECT_ARRAY_PLT(tBigMessageLine, m_BigMessage, BYBIT(0x67606C, 0x84A148));    // [MAX_BIG_MESSAGES][MAX_BIG_MESSAGE_LENGTH]
    DECL_VALUE_PLT_I32(m_ZoneNameTimer, BYBIT(0x676044, 0x84A0F8));
    DECL_VALUE_PLT_I32(m_ZoneFadeTimer, BYBIT(0x679050, 0x8500C8));
    DECL_VALUE_PLT_I32(m_ZoneState, BYBIT(0x676430, 0x84A8B8));
    DECL_VALUE_PLT_BOOL(m_Wants_To_Draw_Hud, BYBIT(0x6772FC, 0x84C630));
    DECL_VALUE_PLT_BOOL(m_Wants_To_Draw_3dMarkers, BYBIT(0x679C38, 0x851888));
    DECL_VALUE_PLT_U8(bDrawingVitalStats, BYBIT(0x6764F8, 0x84AA48));
    DECL_OBJECT_PLT(GxtChar*, m_pVehicleName, BYBIT(0x677F08, 0x84DE30));
    DECL_OBJECT_PLT(GxtChar*, m_pLastVehicleName, BYBIT(0x67809C, 0x84E150));
    DECL_VALUE_PLT_I32(m_VehicleNameTimer, BYBIT(0x675F28, 0x849EC0));
    DECL_VALUE_PLT_I32(m_VehicleFadeTimer, BYBIT(0x677010, 0x84C058));
    DECL_VALUE_PLT_I32(m_VehicleState, BYBIT(0x679C80, 0x851918));
    DECL_OBJECT_PLT(GxtChar*, m_pVehicleNameToPrint, BYBIT(0x676FA0, 0x84BF80));
    DECL_VALUE_PLT_I32(m_LastTimeEnergyLost, BYBIT(0x678570, 0x84EAF8));
    DECL_VALUE_PLT_I32(m_EnergyLostTimer, BYBIT(0x676ADC, 0x84B600));
    DECL_VALUE_PLT_I32(m_EnergyLostFadeTimer, BYBIT(0x678F48, 0x84FEB8));
    DECL_VALUE_PLT_I32(m_EnergyLostState, BYBIT(0x6792EC, 0x8505F0));
    DECL_VALUE_PLT_I32(m_LastDisplayScore, BYBIT(0x67888C, 0x84F138));
    DECL_VALUE_PLT_I32(m_DisplayScoreTimer, BYBIT(0x677080, 0x84C138));
    DECL_VALUE_PLT_I32(m_DisplayScoreFadeTimer, BYBIT(0x676098, 0x84A1A0));
    DECL_VALUE_PLT_I32(m_DisplayScoreState, BYBIT(0x677C58, 0x84D8D0));
    DECL_VALUE_PLT_I32(m_LastWanted, BYBIT(0x679DD0, 0x851BB8));
    DECL_VALUE_PLT_I32(m_WantedTimer, BYBIT(0x6769DC, 0x84B400));
    DECL_VALUE_PLT_I32(m_WantedFadeTimer, BYBIT(0x678110, 0x84E238));
    DECL_VALUE_PLT_I32(m_WantedState, BYBIT(0x677134, 0x84C2A0));
    DECL_VALUE_PLT_I32(m_LastWeapon, BYBIT(0x678CA8, 0x84F978));
    DECL_VALUE_PLT_I32(m_WeaponTimer, BYBIT(0x6775CC, 0x84CBC8));
    DECL_VALUE_PLT_I32(m_WeaponFadeTimer, BYBIT(0x677730, 0x84CE88));
    DECL_VALUE_PLT_I32(m_WeaponState, BYBIT(0x679D68, 0x851AE8));
    DECL_VALUE_PLT_U32(m_LastBreathTime, BYBIT(0x679110, 0x850248));
    DECL_VALUE_PLT_U8(bScriptDontDisplayRadar, BYBIT(0x677DAC, 0x84DB78));
    DECL_VALUE_PLT_U8(bScriptForceDisplayWithCounters, BYBIT(0x67677C, 0x84AF50));
    DECL_VALUE_PLT_U8(bScriptDontDisplayVehicleName, BYBIT(0x679F68, 0x851EE0));
    DECL_VALUE_PLT_U8(bScriptDontDisplayAreaName, BYBIT(0x678684, 0x84ED30));
DECL_CLASS_END()

// The global HUD palette. Prefer HudColour.GetRGBA(HUD_COLOUR_*).
DECL_OBJECT_PLT_GLOBAL(CHudColours, HudColour, BYBIT(0x677368, 0x84C708));

DECL_OBJECT_ARRAY_PLT_GLOBAL(tBigMessageLine, LastBigMessage, BYBIT(0x679360, 0x8506D8));
DECL_OBJECT_ARRAY_PLT_GLOBAL(float, BigMessageInUse, BYBIT(0x677864, 0x84D0F0));
DECL_OBJECT_ARRAY_PLT_GLOBAL(float, BigMessageX, BYBIT(0x676BAC, 0x84B7A0));
DECL_OBJECT_ARRAY_PLT_GLOBAL(float, BigMessageAlpha, BYBIT(0x679AAC, 0x851578));
DECL_OBJECT_PLT_GLOBAL(i16, OddJob2On, BYBIT(0x678CA4, 0x84F970));          // no DECL_VALUE_PLT_I16_GLOBAL in sdk_base.h
DECL_OBJECT_PLT_GLOBAL(i16, OddJob2Timer, BYBIT(0x676C74, 0x84B930));       // ditto
DECL_VALUE_PLT_FLT_GLOBAL(OddJob2XOffset, BYBIT(0x678F60, 0x84FEE8));
DECL_VALUE_PLT_FLT_GLOBAL(OddJob2OffTimer, BYBIT(0x6783E0, 0x84E7D8));

#define m_ItemToFlash m_ItemToFlash()
#define Sprites Sprites()
#define m_pZoneName m_pZoneName()
#define m_pLastZoneName m_pLastZoneName()
#define m_ZoneToPrint m_ZoneToPrint()
#define m_Message m_Message()
#define m_BigMessage m_BigMessage()
#define m_ZoneNameTimer m_ZoneNameTimer()
#define m_ZoneFadeTimer m_ZoneFadeTimer()
#define m_ZoneState m_ZoneState()
#define m_Wants_To_Draw_Hud m_Wants_To_Draw_Hud()
#define m_Wants_To_Draw_3dMarkers m_Wants_To_Draw_3dMarkers()
#define bDrawingVitalStats bDrawingVitalStats()
#define m_pVehicleName m_pVehicleName()
#define m_pLastVehicleName m_pLastVehicleName()
#define m_VehicleNameTimer m_VehicleNameTimer()
#define m_VehicleFadeTimer m_VehicleFadeTimer()
#define m_VehicleState m_VehicleState()
#define m_pVehicleNameToPrint m_pVehicleNameToPrint()
#define m_LastTimeEnergyLost m_LastTimeEnergyLost()
#define m_EnergyLostTimer m_EnergyLostTimer()
#define m_EnergyLostFadeTimer m_EnergyLostFadeTimer()
#define m_EnergyLostState m_EnergyLostState()
#define m_LastDisplayScore m_LastDisplayScore()
#define m_DisplayScoreTimer m_DisplayScoreTimer()
#define m_DisplayScoreFadeTimer m_DisplayScoreFadeTimer()
#define m_DisplayScoreState m_DisplayScoreState()
#define m_LastWanted m_LastWanted()
#define m_WantedTimer m_WantedTimer()
#define m_WantedFadeTimer m_WantedFadeTimer()
#define m_WantedState m_WantedState()
#define m_LastWeapon m_LastWeapon()
#define m_WeaponTimer m_WeaponTimer()
#define m_WeaponFadeTimer m_WeaponFadeTimer()
#define m_WeaponState m_WeaponState()
#define m_LastBreathTime m_LastBreathTime()
#define bScriptDontDisplayRadar bScriptDontDisplayRadar()
#define bScriptForceDisplayWithCounters bScriptForceDisplayWithCounters()
#define bScriptDontDisplayVehicleName bScriptDontDisplayVehicleName()
#define bScriptDontDisplayAreaName bScriptDontDisplayAreaName()
#define HudColour HudColour()
#define LastBigMessage LastBigMessage()
#define BigMessageInUse BigMessageInUse()
#define BigMessageX BigMessageX()
#define BigMessageAlpha BigMessageAlpha()
#define OddJob2On OddJob2On()
#define OddJob2Timer OddJob2Timer()
#define OddJob2XOffset OddJob2XOffset()
#define OddJob2OffTimer OddJob2OffTimer()

#endif // __AML_PSDK_SAHUD_H
