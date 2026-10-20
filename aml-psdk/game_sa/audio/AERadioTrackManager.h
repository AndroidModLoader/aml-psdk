#ifndef __AML_PSDK_SAAERADIOTRACKMANAGER_H
#define __AML_PSDK_SAAERADIOTRACKMANAGER_H

#include <aml-psdk/game_sa/plugin.h>

struct tVehicleAudioSettings;

DECL_CLASS(tRadioSettings)
    // Member values
    i32 TrackIDs[5];
    i32 PlayingTrackID;
    i32 PreviousTrackID;
    i32 PlayTime;
    i32 TrackLengthMs;
    char TrackFlags;
    i8 StationID;
    i8 BassSetting;
    float BassFactor;
    i8 TrackTypes[5];
    i8 PlayingTrackType;
    i8 PreviousTrackType;
    i8 MusicTrackIndices[5];
    i8 PlayingTrackMusicTrackIndex;
    i8 PreviousMusicTrackIndex;
DECL_CLASS_END()
CHECKSIZE(tRadioSettings, 0x3c, 0x3c);

DECL_CLASS(tRadioStationTracking)
    // Member values
    i32 TrackingPeriodsMs[3];
    i32 GameTimeWhenStartedMs;
    i32 GameTimeWhenStoppedMs;
    i32 OldPlayTimeMs;
    i32 OldTrackIDs[3];
    i8 OldTrackTypes[3];
    i8 GameClockDaysWhenStopped;
    i8 GameClockHoursWhenStopped;
DECL_CLASS_END()
CHECKSIZE(tRadioStationTracking, 0x2c, 0x2c);

DECL_CLASS(CAERadioTrackManager)
    typedef i32 DJBanterEntry[2];

    // STATIC functions
    DECL_FASTCALL_SIMPLE(Save, _ZN20CAERadioTrackManager4SaveEv, bool);
    DECL_FASTCALL_SIMPLE(Load, _ZN20CAERadioTrackManager4LoadEv, bool);

    // STATIC values
    DECL_OBJECT_PLT(i8, m_nSpecialDJBanterPending, BYBIT(0x6780fc, 0x84e210));
    DECL_OBJECT_PLT(i8, m_nSpecialDJBanterIndex, BYBIT(0x678c08, 0x84f838));
    DECL_OBJECT_PLT(i8, m_nStatsCitiesPassed, BYBIT(0x677eb4, 0x84dd88));
    DECL_OBJECT_PLT(i8, m_nStatsLastHitGameClockDays, BYBIT(0x6789f8, 0x84f410));
    DECL_OBJECT_PLT(i8, m_nStatsLastHitGameClockHours, BYBIT(0x676570, 0x84ab38));
    DECL_OBJECT_PLT(u8, m_nStatsLastHitTimeOutHours, BYBIT(0x679b38, 0x851690));
    DECL_OBJECT_PLT(i8, m_nStatsPassedCasino3, BYBIT(0x6780cc, 0x84e1b0));
    DECL_OBJECT_PLT(i8, m_nStatsPassedCasino6, BYBIT(0x6792e4, 0x8505e0));
    DECL_OBJECT_PLT(i8, m_nStatsPassedCasino10, BYBIT(0x6771d4, 0x84c3e0));
    DECL_OBJECT_PLT(i8, m_nStatsPassedCat1, BYBIT(0x6770e0, 0x84c1f8));
    DECL_OBJECT_PLT(i8, m_nStatsPassedDesert1, BYBIT(0x67907c, 0x850120));
    DECL_OBJECT_PLT(i8, m_nStatsPassedDesert3, BYBIT(0x678784, 0x84ef30));
    DECL_OBJECT_PLT(i8, m_nStatsPassedDesert5, BYBIT(0x677b70, 0x84d700));
    DECL_OBJECT_PLT(i8, m_nStatsPassedDesert8, BYBIT(0x677d70, 0x84db00));
    DECL_OBJECT_PLT(i8, m_nStatsPassedDesert10, BYBIT(0x678418, 0x84e848));
    DECL_OBJECT_PLT(i8, m_nStatsPassedFarlie3, BYBIT(0x6784b0, 0x84e978));
    DECL_OBJECT_PLT(i8, m_nStatsPassedLAFin2, BYBIT(0x677880, 0x84d128));
    DECL_OBJECT_PLT(i8, m_nStatsPassedMansion2, BYBIT(0x679034, 0x850090));
    DECL_OBJECT_PLT(i8, m_nStatsPassedRyder2, BYBIT(0x676978, 0x84b340));
    DECL_OBJECT_PLT(i8, m_nStatsPassedRiot1, BYBIT(0x67702c, 0x84c090));
    DECL_OBJECT_PLT(i8, m_nStatsPassedSCrash1, BYBIT(0x677074, 0x84c120));
    DECL_OBJECT_PLT(i8, m_nStatsPassedStrap4, BYBIT(0x676678, 0x84ad48));
    DECL_OBJECT_PLT(i8, m_nStatsPassedSweet2, BYBIT(0x676f34, 0x84bea8));
    DECL_OBJECT_PLT(i8, m_nStatsPassedTruth2, BYBIT(0x679b7c, 0x851718));
    DECL_OBJECT_PLT(i8, m_nStatsPassedVCrash2, BYBIT(0x6779b4, 0x84d398));
    DECL_OBJECT_PLT(i8, m_nStatsStartedBadlands, BYBIT(0x675ed0, 0x849e10));
    DECL_OBJECT_PLT(i8, m_nStatsStartedCat2, BYBIT(0x678be4, 0x84f7f0));
    DECL_OBJECT_PLT(i8, m_nStatsStartedCrash1, BYBIT(0x679e88, 0x851d20));
    typedef i8 m_nMusicTrackIndexHistory_t[20];
    DECL_OBJECT_ARRAY_PLT(m_nMusicTrackIndexHistory_t, m_nMusicTrackIndexHistory, BYBIT(0x679b2c, 0x851678));
    typedef i32 m_nIdentIndexHistory_t[8];
    DECL_OBJECT_ARRAY_PLT(m_nIdentIndexHistory_t, m_nIdentIndexHistory, BYBIT(0x6785d0, 0x84ebb8));
    typedef i32 m_nAdvertIndexHistory_t[40];
    DECL_OBJECT_ARRAY_PLT(m_nAdvertIndexHistory_t, m_nAdvertIndexHistory, BYBIT(0x679b08, 0x851630));
    typedef i32 m_nDJBanterIndexHistory_t[15];
    DECL_OBJECT_ARRAY_PLT(m_nDJBanterIndexHistory_t, m_nDJBanterIndexHistory, BYBIT(0x678134, 0x84e280));

    // Member functions
    DECL_THISCALL_HEAD(Initialise, _ZN20CAERadioTrackManager10InitialiseEi, u8, i32 clientHandle)
    DECL_THISCALL_TAIL(Initialise, clientHandle)
    DECL_THISCALL_HEAD(Service, _ZN20CAERadioTrackManager7ServiceEi, void, i32 playTime)
    DECL_THISCALL_TAIL(Service, playTime)
    DECL_THISCALL_SIMPLE(Reset, _ZN20CAERadioTrackManager5ResetEv, void);
    DECL_THISCALL_SIMPLE(ResetStatistics, _ZN20CAERadioTrackManager15ResetStatisticsEv, void);
    DECL_THISCALL_NAMED_HEAD(StartRadio1, StartRadio, _ZN20CAERadioTrackManager10StartRadioEaafh, void, i8 stationId, i8 bassSetting, float bassFactor, u8 stopped)
    DECL_THISCALL_TAIL(StartRadio1, stationId, bassSetting, bassFactor, stopped)
    DECL_THISCALL_NAMED_HEAD(StartRadio2, StartRadio, _ZN20CAERadioTrackManager10StartRadioEP21tVehicleAudioSettings, void, tVehicleAudioSettings* settings)
    DECL_THISCALL_TAIL(StartRadio2, settings)
    DECL_THISCALL_HEAD(StopRadio, _ZN20CAERadioTrackManager9StopRadioEP21tVehicleAudioSettingsh, void, tVehicleAudioSettings* settings, u8 pause)
    DECL_THISCALL_TAIL(StopRadio, settings, pause)
    DECL_THISCALL_HEAD(RetuneRadio, _ZN20CAERadioTrackManager11RetuneRadioEa, void, i8 stationId)
    DECL_THISCALL_TAIL(RetuneRadio, stationId)
    DECL_THISCALL_HEAD(SetRadioAutoRetuneOnOff, _ZN20CAERadioTrackManager23SetRadioAutoRetuneOnOffEh, void, u8 enabled)
    DECL_THISCALL_TAIL(SetRadioAutoRetuneOnOff, enabled)
    DECL_THISCALL_HEAD(SetBassEnhanceOnOff, _ZN20CAERadioTrackManager19SetBassEnhanceOnOffEh, void, u8 enabled)
    DECL_THISCALL_TAIL(SetBassEnhanceOnOff, enabled)
    DECL_THISCALL_HEAD(SetBassSetting, _ZN20CAERadioTrackManager14SetBassSettingEaf, void, i8 setting, float factor)
    DECL_THISCALL_TAIL(SetBassSetting, setting, factor)
    DECL_THISCALL_HEAD(InitialiseRadioStationID, _ZN20CAERadioTrackManager24InitialiseRadioStationIDEa, void, i8 stationId)
    DECL_THISCALL_TAIL(InitialiseRadioStationID, stationId)
    DECL_THISCALL_SIMPLE(IsRadioOn, _ZN20CAERadioTrackManager9IsRadioOnEv, u8);
    DECL_THISCALL_SIMPLE(HasRadioRetuneJustStarted, _ZN20CAERadioTrackManager25HasRadioRetuneJustStartedEv, u8);
    DECL_THISCALL_HEAD(GetRadioStationName, _ZN20CAERadioTrackManager19GetRadioStationNameEa, u16*, i8 stationId)
    DECL_THISCALL_TAIL(GetRadioStationName, stationId)
    DECL_THISCALL_HEAD(GetRadioStationNameKey, _ZN20CAERadioTrackManager22GetRadioStationNameKeyEaPc, void, i8 stationId, char* key)
    DECL_THISCALL_TAIL(GetRadioStationNameKey, stationId, key)
    DECL_THISCALL_SIMPLE(GetRadioStationListenTimes, _ZN20CAERadioTrackManager26GetRadioStationListenTimesEv, i32*);
    DECL_THISCALL_SIMPLE(DisplayRadioStationName, _ZN20CAERadioTrackManager23DisplayRadioStationNameEv, void);
    DECL_THISCALL_SIMPLE(GetCurrentRadioStationID, _ZN20CAERadioTrackManager24GetCurrentRadioStationIDEv, i8);
    DECL_THISCALL_HEAD(PlayRadioAnnouncement, _ZN20CAERadioTrackManager21PlayRadioAnnouncementEj, void, u32 announcementId)
    DECL_THISCALL_TAIL(PlayRadioAnnouncement, announcementId)
    DECL_THISCALL_SIMPLE(IsVehicleRadioActive, _ZN20CAERadioTrackManager20IsVehicleRadioActiveEv, u8);
    DECL_THISCALL_SIMPLE(StartTrackPlayback, _ZN20CAERadioTrackManager18StartTrackPlaybackEv, void);
    DECL_THISCALL_SIMPLE(UpdateRadioVolumes, _ZN20CAERadioTrackManager18UpdateRadioVolumesEv, void);
    DECL_THISCALL_SIMPLE(CheckForMissionStatsChanges, _ZN20CAERadioTrackManager27CheckForMissionStatsChangesEv, void);
    DECL_THISCALL_SIMPLE(CheckForStationRetune, _ZN20CAERadioTrackManager21CheckForStationRetuneEv, void);
    DECL_THISCALL_SIMPLE(CheckForStationRetuneDuringPause, _ZN20CAERadioTrackManager32CheckForStationRetuneDuringPauseEv, void);
    DECL_THISCALL_HEAD(TrackRadioStation, _ZN20CAERadioTrackManager17TrackRadioStationEah, u8, i8 stationId, u8 started)
    DECL_THISCALL_TAIL(TrackRadioStation, stationId, started)
    DECL_THISCALL_HEAD(ChooseTracksForStation, _ZN20CAERadioTrackManager22ChooseTracksForStationEa, void, i8 stationId)
    DECL_THISCALL_TAIL(ChooseTracksForStation, stationId)
    DECL_THISCALL_HEAD(QueueUpTracksForStation, _ZN20CAERadioTrackManager23QueueUpTracksForStationEaPaaP14tRadioSettings, u8, i8 stationId, i8* trackTypes, i8 numTracks, tRadioSettings* settings)
    DECL_THISCALL_TAIL(QueueUpTracksForStation, stationId, trackTypes, numTracks, settings)
    DECL_THISCALL_SIMPLE(CheckForTrackConcatenation, _ZN20CAERadioTrackManager26CheckForTrackConcatenationEv, void);
    DECL_THISCALL_HEAD(ChooseMusicTrackIndex, _ZN20CAERadioTrackManager21ChooseMusicTrackIndexEa, i8, i8 stationId)
    DECL_THISCALL_TAIL(ChooseMusicTrackIndex, stationId)
    DECL_THISCALL_SIMPLE(ChooseTalkRadioShow, _ZN20CAERadioTrackManager19ChooseTalkRadioShowEv, i8);
    DECL_THISCALL_HEAD(ChooseIdentIndex, _ZN20CAERadioTrackManager16ChooseIdentIndexEa, i32, i8 stationId)
    DECL_THISCALL_TAIL(ChooseIdentIndex, stationId)
    DECL_THISCALL_HEAD(ChooseAdvertIndex, _ZN20CAERadioTrackManager17ChooseAdvertIndexEa, i32, i8 stationId)
    DECL_THISCALL_TAIL(ChooseAdvertIndex, stationId)
    DECL_THISCALL_HEAD(ChooseDJBanterIndex, _ZN20CAERadioTrackManager19ChooseDJBanterIndexEa, i32, i8 stationId)
    DECL_THISCALL_TAIL(ChooseDJBanterIndex, stationId)
    DECL_THISCALL_HEAD(ChooseDJBanterIndexFromList, _ZN20CAERadioTrackManager27ChooseDJBanterIndexFromListEaPA2_i, i32, i8 stationId, CAERadioTrackManager::DJBanterEntry* list)
    DECL_THISCALL_TAIL(ChooseDJBanterIndexFromList, stationId, list)
    DECL_THISCALL_HEAD(AddMusicTrackIndexToHistory, _ZN20CAERadioTrackManager27AddMusicTrackIndexToHistoryEaa, void, i8 stationId, i8 trackIndex)
    DECL_THISCALL_TAIL(AddMusicTrackIndexToHistory, stationId, trackIndex)
    DECL_THISCALL_HEAD(AddIdentIndexToHistory, _ZN20CAERadioTrackManager22AddIdentIndexToHistoryEai, void, i8 stationId, i32 identIndex)
    DECL_THISCALL_TAIL(AddIdentIndexToHistory, stationId, identIndex)
    DECL_THISCALL_HEAD(AddAdvertIndexToHistory, _ZN20CAERadioTrackManager23AddAdvertIndexToHistoryEai, void, i8 stationId, i32 advertIndex)
    DECL_THISCALL_TAIL(AddAdvertIndexToHistory, stationId, advertIndex)
    DECL_THISCALL_HEAD(AddDJBanterIndexToHistory, _ZN20CAERadioTrackManager25AddDJBanterIndexToHistoryEai, void, i8 stationId, i32 banterIndex)
    DECL_THISCALL_TAIL(AddDJBanterIndexToHistory, stationId, banterIndex)
    DECL_THISCALL_SIMPLE(CheckForPause, _ZN20CAERadioTrackManager13CheckForPauseEv, void);

    // Member values
    u8 m_bStationChangePending;
    u8 m_bDisplayNewStationName;
    u8 m_bReadyToRetune;
    u8 m_bPlayRadioDuringPause;
    u8 m_bUseBassEnhance;
    u8 m_bPausedLastFrame;
    u8 m_bRetuneStartedThisFrame;
    u8 m_bUseRadioAutoRetune;
    i8 m_nTracksSinceLastAdvertOrDJList[14];
    i8 m_nLastVehicleExitGameClockDays;
    i8 m_nLastVehicleExitGameClockHours;
    i32 m_nStationListenTimes[14];
    u32 m_nLastRetuneTimeMs;
    u32 m_nStationNameDisplayEndTimeMs;
    u32 m_nLastVehicleExitTimeMs;
    u32 m_nRetuneTimeMs;
    u32 m_nLastPlayStartTimeMs;
    i32 m_nHardwareClientHandle;
    i32 m_nRadioStatus;
    i32 m_nRetunesPending;
    i32 m_nPreviousRetunesPending;
    i32 m_nLastVehicleStationID;
    i32 m_nRetuneStationID;
    i32 m_nScriptRetuneStationID;
    float m_fDialogueRadioDuckingVolume;
    float m_fDialogueRadioDuckingReleaseStep;
    tRadioSettings m_RequestedSettings;
    tRadioSettings m_ActiveSettings;
    tRadioStationTracking m_StationTrackingList[14];
    u32 m_numInvalidTracks;
    i8 m_lastRadioMode;
DECL_CLASS_END()
CHECKSIZE(CAERadioTrackManager, 0x370, 0x370);

DECL_OBJECT_PLT_GLOBAL(CAERadioTrackManager, AERadioTrackManager, BYBIT(0x677fa0, 0x84df60));

#endif // __AML_PSDK_SAAERADIOTRACKMANAGER_H
