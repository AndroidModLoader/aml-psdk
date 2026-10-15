#ifndef __AML_PSDK_SAGENERICGAMESTORAGE_H
#define __AML_PSDK_SAGENERICGAMESTORAGE_H

#include "../plugin.h"
#include "../enum/LevelName.h"
#include "../other/Wanted.h"
#include <aml-psdk/gta_base/Vector.h>
#include <aml-psdk/gta_base/GxtChar.h>

DECL_CLASS(EndianBuffer)
    // Member values
    u8* data;
    size_t size;
DECL_CLASS_END()
CHECKSIZE(EndianBuffer, 0x8, 0x10);

DECL_CLASS(CSimpleVariablesSaveStructure)
    // Member functions
    DECL_THISCALL_SIMPLE(Construct, _ZN29CSimpleVariablesSaveStructure9ConstructEv, void);
    DECL_THISCALL_HEAD(Extract, _ZN29CSimpleVariablesSaveStructure7ExtractERj, void, u32& versionNum)
    DECL_THISCALL_TAIL(Extract, versionNum)
    // Member values
    u32 m_VersionNumber;
    GxtChar m_MissionName[100];
    u8 m_MissionPackGame;
    eLevelName m_CurrentLevel;
    CVector m_CameraPosition;
    u32 m_MillisecondsPerGameMinute;
    u32 m_LastClockTick;
    u8 m_GameClockMonths;
    u8 m_GameClockDays;
    u8 m_GameClockHours;
    u8 m_GameClockMinutes;
    u8 m_CurrentDay;
    u8 m_StoredGameClockMonths;
    u8 m_StoredGameClockDays;
    u8 m_StoredGameClockHours;
    u8 m_StoredGameClockMinutes;
    u8 m_ClockStored;
    u16 m_PadMode;
    bool m_bHasCheated;
    u32 m_TimeInMilliseconds;
    float m_TimeScale;
    float m_TimeStep;
    float m_TimeStepNonClipped;
    u32 m_FrameCount;
    u16 m_OldWeatherType;
    u16 m_NewWeatherType;
    u16 m_ForcedWeatherType;
    float m_InterpolationValue;
    i32 m_WeatherTypeInList;
    float m_Rain;
    i32 m_CarZoom;
    i32 m_PedZoom;
    i32 m_CurrArea;
    bool m_InvertLook4Pad;
    i32 m_ExtraColourIndex;
    bool m_ExtraColourOn;
    float m_ExtraColourInterpolation;
    i32 m_ExtraColourWeather;
    i32 m_WaterConfiguration;
    bool m_bLARiots;
    bool m_bLARiots_NoPoliceCars;
    eWantedLevel m_MaximumWantedLevel;
    i32 m_nMaximumWantedLevel;
    u8 m_frenchGame;
    u8 m_germanGame;
    u8 m_nastyGame;
    u32 m_SavedRadioPosition[11];
    i8 m_bCineyCamMessageDisplayed;
    bool m_BlurOn;
    i8 m_PrefsMusicVolume;
    i8 m_PrefsSfxVolume;
    u8 m_PrefsUseVibration;
    i8 m_PrefsRadioStation;
    u8 m_PrefsShowSubtitles;
    i8 m_PrefsLanguage;
    u8 m_PrefsUseWideScreen;
    i32 m_ScreenXOffset;
    i32 m_ScreenYOffset;
    u8 m_PrefsDisplayHud;
    i32 m_PrefsRadarMode;
    u8 m_PrefsUseBass;
    u8 m_PrefsAutoRetune;
    i8 m_PrefsAudioOutputMode;
    i32 m_waypoint_blip;
    bool m_bHasDisplayedPlayerQuitEnterCarHelpText;
    bool m_bTaxiNitroCheat;
    bool m_bPimpCheat;
    int m_CPIndex;
DECL_CLASS_END()
CHECKSIZE(CSimpleVariablesSaveStructure, 0x1AC, 0x1AC);

DECL_CLASS(CGenericGameStorage)
    typedef GxtChar SaveSlotFileName[260];
    typedef GxtChar SaveSlotSaveDate[70];

    enum eBlocks
    {
        BLOCK_SIMPLE_VARIABLES = 0,
        BLOCK_SCRIPTS = 1,
        BLOCK_POOLS = 2,
        BLOCK_GARAGES = 3,
        BLOCK_GAMELOGIC = 4,
        BLOCK_PATHS = 5,
        BLOCK_PICKUPS = 6,
        BLOCK_PHONEINFO = 7,
        BLOCK_RESTART = 8,
        BLOCK_RADAR = 9,
        BLOCK_ZONES = 10,
        BLOCK_GANGS = 11,
        BLOCK_CARGENERATORS = 12,
        BLOCK_PEDGENERATORS = 13,
        BLOCK_AUDIOSCRIPTOBJECT = 14,
        BLOCK_PLAYERINFO = 15,
        BLOCK_STATS = 16,
        BLOCK_SETPIECES = 17,
        BLOCK_STREAMING = 18,
        BLOCK_PEDTYPE = 19,
        BLOCK_TAGS = 20,
        BLOCK_IPLS = 21,
        BLOCK_SHOPPING = 22,
        BLOCK_GANGWARS = 23,
        BLOCK_STUNTJUMPS = 24,
        BLOCK_ENTRYEXIT = 25,
        BLOCK_RADIO = 26,
        BLOCK_USER_3DMARKERS = 27,
        BLOCK_POSTEFFECTS = 28,
        BLOCK_NUMBLOCKS = 29,
    };

    enum eSaveLoadError
    {
        SLERROR_SAVE = 0,
        SLERROR_LOAD = 1,
        SLERROR_SYNC = 2,
    };

    // STATIC functions
    DECL_FASTCALL_SIMPLE(GenericSave, _ZN19CGenericGameStorage11GenericSaveEi, bool, int SlotNum);
    DECL_FASTCALL_SIMPLE(GenericLoad, _ZN19CGenericGameStorage11GenericLoadERb, bool, bool& bWrongVersion);
    DECL_FASTCALL_SIMPLE(CheckDataNotCorrupt, _ZN19CGenericGameStorage19CheckDataNotCorruptEiPc, bool, int SlotNumber, char* FileName);
    DECL_FASTCALL_SIMPLE(GetNameOfSavedGame, _ZN19CGenericGameStorage18GetNameOfSavedGameEi, GxtChar*, int SlotNumber);
    DECL_FASTCALL_SIMPLE(CheckSlotDataValid, _ZN19CGenericGameStorage18CheckSlotDataValidEib, bool, int SlotNumber, bool DeleteRwObjects);
    DECL_FASTCALL_SIMPLE(RestoreForStartLoad, _ZN19CGenericGameStorage19RestoreForStartLoadEv, bool);
    DECL_FASTCALL_SIMPLE(DoGameSpecificStuffBeforeSave, _ZN19CGenericGameStorage29DoGameSpecificStuffBeforeSaveEv, void);
    DECL_FASTCALL_SIMPLE(DoGameSpecificStuffAfterSucessLoad, _ZN19CGenericGameStorage34DoGameSpecificStuffAfterSucessLoadEv, void);
    DECL_FASTCALL_SIMPLE(DoAnytimeSavingStuffAfterSucessLoad, _ZN19CGenericGameStorage35DoAnytimeSavingStuffAfterSucessLoadEv, void);
    DECL_FASTCALL_SIMPLE(MakeValidSaveName, _ZN19CGenericGameStorage17MakeValidSaveNameEi, void, int SlotNumber);
    DECL_FASTCALL_SIMPLE(GetSavedRadioStationPosition, _ZN19CGenericGameStorage28GetSavedRadioStationPositionEi, u32, i32 i);
    DECL_FASTCALL_SIMPLE(GetCurrentVersionNumber, _ZN19CGenericGameStorage23GetCurrentVersionNumberEv, u32);
    DECL_FASTCALL_SIMPLE(GetSavedVersionNumber, _ZN19CGenericGameStorage21GetSavedVersionNumberEj, u32, u32 savedKey);
    DECL_FASTCALL_SIMPLE(OpenFileForReading, _ZN19CGenericGameStorage18OpenFileForReadingEPcj, bool, char* FileName, u32 SlotNumber);
    DECL_FASTCALL_SIMPLE(OpenFileForWriting, _ZN19CGenericGameStorage18OpenFileForWritingEv, bool);
    DECL_FASTCALL_SIMPLE(CloseFile, _ZN19CGenericGameStorage9CloseFileEv, bool);
    DECL_FASTCALL_SIMPLE(SaveWorkBuffer, _ZN19CGenericGameStorage14SaveWorkBufferEb, bool, bool bWithChecksum);
    DECL_FASTCALL_SIMPLE(LoadWorkBuffer, _ZN19CGenericGameStorage14LoadWorkBufferEv, bool);
    DECL_FASTCALL_SIMPLE(ReportError, _ZN19CGenericGameStorage11ReportErrorENS_7eBlocksENS_14eSaveLoadErrorE, void, eBlocks block, eSaveLoadError error);
    DECL_FASTCALL_SIMPLE(_SaveDataToWorkBuffer, _ZN19CGenericGameStorage21_SaveDataToWorkBufferEPvi, bool, void* pData, i32 SizeOfData);
    DECL_FASTCALL_SIMPLE(_LoadDataFromWorkBuffer, _ZN19CGenericGameStorage23_LoadDataFromWorkBufferEPvi, bool, void* pData, i32 SizeOfData);
    // STATIC values
    DECL_VALUE_PLT_I32(m_currentSlotVersionNumber, BYBIT(0x676F00, 0x84BE40));
    DECL_VALUE_PLT_U32(ms_CheckSum, BYBIT(0x6773F8, 0x84C828));
    DECL_OBJECT_ARRAY_PLT(char, ms_LoadFileName, BYBIT(0x677DA4, 0x84DB68));
    DECL_OBJECT_ARRAY_PLT(char, ms_LoadFileNameWithPath, BYBIT(0x679298, 0x850548));
    DECL_OBJECT_ARRAY_PLT(char, ms_ValidSaveName, BYBIT(0x677A44, 0x84D4B0));
    DECL_OBJECT_ARRAY_PLT(char, ms_SaveFileNameJustSaved, BYBIT(0x6771AC, 0x84C388));
    DECL_OBJECT_ARRAY_PLT(char, ms_BlockTagName, BYBIT(0x677D9C, 0x84DB58));
    DECL_OBJECT_ARRAY_PLT(i32, ms_Slots, BYBIT(0x677088, 0x84C148));
    DECL_OBJECT_ARRAY_PLT(SaveSlotFileName, ms_SlotFileName, BYBIT(0x677C54, 0x84D8C8));
    DECL_OBJECT_ARRAY_PLT(SaveSlotSaveDate, ms_SlotSaveDate, BYBIT(0x677F90, 0x84DF40));
    DECL_OBJECT_PLT(EndianBuffer, ms_WorkBuffer, BYBIT(0x6767A8, 0x84AFA8));
    DECL_OBJECT_PLT(u8*, _ms_WorkBuffer, BYBIT(0x679D98, 0x851B48));
    DECL_VALUE_PLT_U32(ms_WorkBufferPos, BYBIT(0x676B84, 0x84B750));
    DECL_VALUE_PLT_U32(ms_WorkBufferSize, BYBIT(0x6776DC, 0x84CDE8));
    DECL_OBJECT_PLT(uptr, ms_FileHandle, BYBIT(0x677968, 0x84D2F8));
    DECL_VALUE_PLT_U32(ms_FilePos, BYBIT(0x677718, 0x84CE58));
    DECL_VALUE_PLT_U32(ms_FileSize, BYBIT(0x679774, 0x850EF0));
    DECL_VALUE_PLT_BOOL(ms_bFailed, BYBIT(0x67980C, 0x851020));
    DECL_VALUE_PLT_BOOL(ms_bLoading, BYBIT(0x677D38, 0x84DA90));
DECL_CLASS_END()

#endif // __AML_PSDK_SAGENERICGAMESTORAGE_H
