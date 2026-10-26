#ifndef __AML_PSDK_VCWEATHER_H
#define __AML_PSDK_VCWEATHER_H

#include <aml-psdk/game_vc/plugin.h>

DECL_CLASS(CWeather)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(Init, _ZN8CWeather4InitEv, void);
    DECL_FASTCALL_SIMPLE(Update, _ZN8CWeather6UpdateEv, void);
    DECL_FASTCALL_SIMPLE(ForceWeather, _ZN8CWeather12ForceWeatherEs, void, i16 type);
    DECL_FASTCALL_SIMPLE(ForceWeatherNow, _ZN8CWeather15ForceWeatherNowEs, void, i16 type);
    DECL_FASTCALL_SIMPLE(ReleaseWeather, _ZN8CWeather14ReleaseWeatherEv, void);
    DECL_FASTCALL_SIMPLE(AddRain, _ZN8CWeather7AddRainEv, void);
    DECL_FASTCALL_SIMPLE(RenderRainStreaks, _ZN8CWeather17RenderRainStreaksEv, void);
    DECL_FASTCALL_SIMPLE(AddStreamAfterRain, _ZN8CWeather18AddStreamAfterRainEv, void);
    DECL_FASTCALL_SIMPLE(AddSplashesDuringHurricane, _ZN8CWeather26AddSplashesDuringHurricaneEv, void);
    DECL_FASTCALL_SIMPLE(AddHeatHaze, _ZN8CWeather11AddHeatHazeEv, void);
    DECL_FASTCALL_SIMPLE(AddBeastie, _ZN8CWeather10AddBeastieEv, void);

    // STATIC values
    DECL_VALUE_PLT_I16(OldWeatherType, BYBIT(0x3967E0, 0x57AFC0));
    DECL_VALUE_PLT_I16(NewWeatherType, BYBIT(0x395B68, 0x5796F0));
    DECL_VALUE_PLT_I16(ForcedWeatherType, BYBIT(0x394AF0, 0x5776C8));
    DECL_VALUE_PLT_I32(WeatherTypeInList, BYBIT(0x394598, 0x576C88));
    DECL_VALUE_PLT_FLT(InterpolationValue, BYBIT(0x394A54, 0x577598));
    DECL_VALUE_PLT_FLT(WetRoads, BYBIT(0x3959D4, 0x5793E0));
    DECL_VALUE_PLT_FLT(CloudCoverage, BYBIT(0x39571C, 0x578EB8));
    DECL_VALUE_PLT_FLT(Foggyness, BYBIT(0x395DD0, 0x579BD0));
    DECL_VALUE_PLT_FLT(ExtraSunnyness, BYBIT(0x394E78, 0x577D70));
    DECL_VALUE_PLT_FLT(Rain, BYBIT(0x395574, 0x578B48));
    DECL_VALUE_PLT_FLT(Wind, BYBIT(0x394818, 0x577168));
    DECL_VALUE_PLT_FLT(WindClipped, BYBIT(0x39448C, 0x576A68));
    DECL_VALUE_PLT_FLT(Rainbow, BYBIT(0x394F54, 0x577F18));
    DECL_VALUE_PLT_FLT(SunGlare, BYBIT(0x395D2C, 0x579A70));
    DECL_VALUE_PLT_BOOL(LightningBurst, BYBIT(0x395998, 0x579370));
    DECL_VALUE_PLT_BOOL(LightningFlash, BYBIT(0x394D20, 0x577AF8));
    DECL_VALUE_PLT_U32(LightningStart, BYBIT(0x3943A8, 0x5768A0));
    DECL_VALUE_PLT_U32(LightningDuration, BYBIT(0x39461C, 0x576D98));
    DECL_VALUE_PLT_U32(WhenToPlayLightningSound, BYBIT(0x395FB4, 0x579F88));
    DECL_VALUE_PLT_U32(LightningFlashLastChange, BYBIT(0x3968C0, 0x57B170));
    DECL_VALUE_PLT_BOOL(bScriptsForceRain, BYBIT(0x3950C4, 0x5781E8));
    DECL_VALUE_PLT_FLT(TrafficLightsBrightness, BYBIT(0x395024, 0x5780B8));
    DECL_VALUE_PLT_I32(SoundHandle, BYBIT(0x394CEC, 0x577AA8));
    DECL_VALUE_PLT_I32(StreamAfterRainTimer, BYBIT(0x396E98, 0x57BD28));
DECL_CLASS_END()

#define OldWeatherType OldWeatherType()
#define NewWeatherType NewWeatherType()
#define ForcedWeatherType ForcedWeatherType()
#define WeatherTypeInList WeatherTypeInList()
#define InterpolationValue InterpolationValue()
#define WetRoads WetRoads()
#define CloudCoverage CloudCoverage()
#define Foggyness Foggyness()
#define ExtraSunnyness ExtraSunnyness()
#define Rain Rain()
#define Wind Wind()
#define WindClipped WindClipped()
#define Rainbow Rainbow()
#define SunGlare SunGlare()
#define LightningBurst LightningBurst()
#define LightningFlash LightningFlash()
#define LightningStart LightningStart()
#define LightningDuration LightningDuration()
#define WhenToPlayLightningSound WhenToPlayLightningSound()
#define LightningFlashLastChange LightningFlashLastChange()
#define bScriptsForceRain bScriptsForceRain()
#define TrafficLightsBrightness TrafficLightsBrightness()
#define SoundHandle SoundHandle()
#define StreamAfterRainTimer StreamAfterRainTimer()

#endif // __AML_PSDK_VCWEATHER_H
