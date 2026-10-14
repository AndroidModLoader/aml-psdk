#ifndef __AML_PSDK_SAAUDIOENGINE_H
#define __AML_PSDK_SAAUDIOENGINE_H

#include <aml-psdk/game_sa/plugin.h>
#include "AEFrontendAudioEntity.h"
#include "AEScriptAudioEntity.h"
#include "AECollisionAudioEntity.h"
#include "AEPedlessSpeechAudioEntity.h"

struct CAEGlobalWeaponAudioEntity;
struct CObject;

struct tBeatInfoBeat
{
    int Time;
    int Type;
};

struct tBeatInfo
{
    tBeatInfoBeat BeatWindow[20];
    int bBeatInfoPresent;
    int BeatTypeThisFrame;
    int BeatNumber;
};

DECL_CLASS(CAudioEngine)
    // Construct/Deconstruct functions
    DECL_DTORCALL(CAudioEngine, _ZN12CAudioEngineD2Ev);

    // Member functions
    DECL_THISCALL_SIMPLE(Initialise, _ZN12CAudioEngine10InitialiseEv, u8);
    DECL_THISCALL_SIMPLE(Service, _ZN12CAudioEngine7ServiceEv, void);
    DECL_THISCALL_HEAD(ServiceLoadingTune, _ZN12CAudioEngine18ServiceLoadingTuneEf, void, float fade)
    DECL_THISCALL_TAIL(ServiceLoadingTune, fade)
    DECL_THISCALL_SIMPLE(IsLoadingTuneActive, _ZN12CAudioEngine19IsLoadingTuneActiveEv, u8);
    DECL_THISCALL_SIMPLE(InitialisePostLoading, _ZN12CAudioEngine21InitialisePostLoadingEv, void);
    DECL_THISCALL_SIMPLE(Reset, _ZN12CAudioEngine5ResetEv, void);
    DECL_THISCALL_SIMPLE(ResetSoundEffects, _ZN12CAudioEngine17ResetSoundEffectsEv, void);
    DECL_THISCALL_SIMPLE(ResetStatistics, _ZN12CAudioEngine15ResetStatisticsEv, void);
    DECL_THISCALL_SIMPLE(Restart, _ZN12CAudioEngine7RestartEv, void);
    DECL_THISCALL_SIMPLE(Shutdown, _ZN12CAudioEngine8ShutdownEv, void);
    DECL_THISCALL_HEAD(SetMusicMasterVolume, _ZN12CAudioEngine20SetMusicMasterVolumeEa, void, i8 volume)
    DECL_THISCALL_TAIL(SetMusicMasterVolume, volume)
    DECL_THISCALL_HEAD(SetEffectsMasterVolume, _ZN12CAudioEngine22SetEffectsMasterVolumeEa, void, i8 volume)
    DECL_THISCALL_TAIL(SetEffectsMasterVolume, volume)
    DECL_THISCALL_HEAD(SetMusicFaderScalingFactor, _ZN12CAudioEngine26SetMusicFaderScalingFactorEf, void, float value)
    DECL_THISCALL_TAIL(SetMusicFaderScalingFactor, value)
    DECL_THISCALL_HEAD(SetEffectsFaderScalingFactor, _ZN12CAudioEngine28SetEffectsFaderScalingFactorEf, void, float value)
    DECL_THISCALL_TAIL(SetEffectsFaderScalingFactor, value)
    DECL_THISCALL_HEAD(SetStreamFaderScalingFactor, _ZN12CAudioEngine27SetStreamFaderScalingFactorEf, void, float arg1)
    DECL_THISCALL_TAIL(SetStreamFaderScalingFactor, arg1)
    DECL_THISCALL_HEAD(SetNonStreamFaderScalingFactor, _ZN12CAudioEngine30SetNonStreamFaderScalingFactorEf, void, float arg1)
    DECL_THISCALL_TAIL(SetNonStreamFaderScalingFactor, arg1)
    DECL_THISCALL_SIMPLE(DisableEffectsLoading, _ZN12CAudioEngine21DisableEffectsLoadingEv, void);
    DECL_THISCALL_SIMPLE(EnableEffectsLoading, _ZN12CAudioEngine20EnableEffectsLoadingEv, void);
    DECL_THISCALL_HEAD(ReportFrontendAudioEvent, _ZN12CAudioEngine24ReportFrontendAudioEventEiff, void, i32 id, float volume, float speed)
    DECL_THISCALL_TAIL(ReportFrontendAudioEvent, id, volume, speed)
    DECL_THISCALL_HEAD(ReportCollision, _ZN12CAudioEngine15ReportCollisionEP7CEntityS1_hhR7CVectorPS2_ffhh, void, CEntity* pCEntity1, CEntity* pCEntity2, u8 arg3, u8 arg4, CVector& arg5, CVector* pCVector6, float arg7, float arg8, u8 arg9, u8 arg10)
    DECL_THISCALL_TAIL(ReportCollision, pCEntity1, pCEntity2, arg3, arg4, arg5, pCVector6, arg7, arg8, arg9, arg10)
    DECL_THISCALL_HEAD(ReportBulletHit, _ZN12CAudioEngine15ReportBulletHitEP7CEntityhR7CVectorf, void, CEntity* pCEntity1, u8 arg2, CVector& arg3, float arg4)
    DECL_THISCALL_TAIL(ReportBulletHit, pCEntity1, arg2, arg3, arg4)
    DECL_THISCALL_HEAD(ReportObjectDestruction, _ZN12CAudioEngine23ReportObjectDestructionEP7CEntity, void, CEntity* pCEntity1)
    DECL_THISCALL_TAIL(ReportObjectDestruction, pCEntity1)
    DECL_THISCALL_HEAD(ReportGlassCollisionEvent, _ZN12CAudioEngine25ReportGlassCollisionEventEiR7CVector, void, i32 arg1, CVector& arg2)
    DECL_THISCALL_TAIL(ReportGlassCollisionEvent, arg1, arg2)
    DECL_THISCALL_NAMED_HEAD(ReportWaterSplash1, ReportWaterSplash, _ZN12CAudioEngine17ReportWaterSplashEP9CPhysicalfh, void, CPhysical* pCPhysical1, float arg2, u8 arg3)
    DECL_THISCALL_TAIL(ReportWaterSplash1, pCPhysical1, arg2, arg3)
    DECL_THISCALL_NAMED_HEAD(ReportWaterSplash2, ReportWaterSplash, _ZN12CAudioEngine17ReportWaterSplashE7CVectorf, void, CVector arg1, float arg2)
    DECL_THISCALL_TAIL(ReportWaterSplash2, arg1, arg2)
    DECL_THISCALL_HEAD(ReportWeaponEvent, _ZN12CAudioEngine17ReportWeaponEventEi11eWeaponTypeP9CPhysical, void, i32 arg1, eWeaponType arg2, CPhysical* pCPhysical3)
    DECL_THISCALL_TAIL(ReportWeaponEvent, arg1, arg2, pCPhysical3)
    DECL_THISCALL_HEAD(ReportDoorMovement, _ZN12CAudioEngine18ReportDoorMovementEP9CPhysical, void, CPhysical* pCPhysical1)
    DECL_THISCALL_TAIL(ReportDoorMovement, pCPhysical1)
    DECL_THISCALL_NAMED_HEAD(StartRadio1, StartRadio, _ZN12CAudioEngine10StartRadioEaa, void, i8 radioStation, i8 arg)
    DECL_THISCALL_TAIL(StartRadio1, radioStation, arg)
    DECL_THISCALL_NAMED_HEAD(StartRadio2, StartRadio, _ZN12CAudioEngine10StartRadioEP21tVehicleAudioSettings, void, tVehicleAudioSettings* ptVehicleAudioSettings1)
    DECL_THISCALL_TAIL(StartRadio2, ptVehicleAudioSettings1)
    DECL_THISCALL_HEAD(StopRadio, _ZN12CAudioEngine9StopRadioEP21tVehicleAudioSettingsh, void, tVehicleAudioSettings* settings, u8 arg)
    DECL_THISCALL_TAIL(StopRadio, settings, arg)
    DECL_THISCALL_HEAD(RetuneRadio, _ZN12CAudioEngine11RetuneRadioEa, void, i8 stationId)
    DECL_THISCALL_TAIL(RetuneRadio, stationId)
    DECL_THISCALL_HEAD(SetRadioAutoRetuneOnOff, _ZN12CAudioEngine23SetRadioAutoRetuneOnOffEh, void, u8 on)
    DECL_THISCALL_TAIL(SetRadioAutoRetuneOnOff, on)
    DECL_THISCALL_HEAD(SetBassEnhanceOnOff, _ZN12CAudioEngine19SetBassEnhanceOnOffEh, void, u8 on)
    DECL_THISCALL_TAIL(SetBassEnhanceOnOff, on)
    DECL_THISCALL_HEAD(SetRadioBassSetting, _ZN12CAudioEngine19SetRadioBassSettingEa, void, i8 arg1)
    DECL_THISCALL_TAIL(SetRadioBassSetting, arg1)
    DECL_THISCALL_HEAD(InitialiseRadioStationID, _ZN12CAudioEngine24InitialiseRadioStationIDEa, void, i8 arg1)
    DECL_THISCALL_TAIL(InitialiseRadioStationID, arg1)
    DECL_THISCALL_SIMPLE(IsRadioOn, _ZN12CAudioEngine9IsRadioOnEv, u8);
    DECL_THISCALL_SIMPLE(HasRadioRetuneJustStarted, _ZN12CAudioEngine25HasRadioRetuneJustStartedEv, u8);
    DECL_THISCALL_SIMPLE(IsRadioRetuneInProgress, _ZN12CAudioEngine23IsRadioRetuneInProgressEv, u8);
    DECL_THISCALL_HEAD(GetRadioStationName, _ZN12CAudioEngine19GetRadioStationNameEa, u16*, i8 arg1)
    DECL_THISCALL_TAIL(GetRadioStationName, arg1)
    DECL_THISCALL_HEAD(GetRadioStationNameKey, _ZN12CAudioEngine22GetRadioStationNameKeyEaPc, void, i8 arg1, char* pchar2)
    DECL_THISCALL_TAIL(GetRadioStationNameKey, arg1, pchar2)
    DECL_THISCALL_SIMPLE(GetRadioStationListenTimes, _ZN12CAudioEngine26GetRadioStationListenTimesEv, i32*);
    DECL_THISCALL_SIMPLE(DisplayRadioStationName, _ZN12CAudioEngine23DisplayRadioStationNameEv, void);
    DECL_THISCALL_SIMPLE(GetCurrentRadioStationID, _ZN12CAudioEngine24GetCurrentRadioStationIDEv, i8);
    DECL_THISCALL_SIMPLE(IsVehicleRadioActive, _ZN12CAudioEngine20IsVehicleRadioActiveEv, u8);
    DECL_THISCALL_HEAD(PlayRadioAnnouncement, _ZN12CAudioEngine21PlayRadioAnnouncementEj, void, u32 arg1)
    DECL_THISCALL_TAIL(PlayRadioAnnouncement, arg1)
    DECL_THISCALL_HEAD(PreloadCutsceneTrack, _ZN12CAudioEngine20PreloadCutsceneTrackEsh, void, i16 arg1, u8 arg2)
    DECL_THISCALL_TAIL(PreloadCutsceneTrack, arg1, arg2)
    DECL_THISCALL_SIMPLE(PlayPreloadedCutsceneTrack, _ZN12CAudioEngine26PlayPreloadedCutsceneTrackEv, void);
    DECL_THISCALL_HEAD(StopCutsceneTrack, _ZN12CAudioEngine17StopCutsceneTrackEh, void, u8 arg1)
    DECL_THISCALL_TAIL(StopCutsceneTrack, arg1)
    DECL_THISCALL_SIMPLE(IsCutsceneTrackActive, _ZN12CAudioEngine21IsCutsceneTrackActiveEv, u8);
    DECL_THISCALL_SIMPLE(GetCutsceneTrackStatus, _ZN12CAudioEngine22GetCutsceneTrackStatusEv, i8);
    DECL_THISCALL_HEAD(PreloadBeatTrack, _ZN12CAudioEngine16PreloadBeatTrackEs, void, i16 arg1)
    DECL_THISCALL_TAIL(PreloadBeatTrack, arg1)
    DECL_THISCALL_SIMPLE(GetBeatTrackStatus, _ZN12CAudioEngine18GetBeatTrackStatusEv, i8);
    DECL_THISCALL_HEAD(PlayPreloadedBeatTrack, _ZN12CAudioEngine22PlayPreloadedBeatTrackEh, void, u8 arg1)
    DECL_THISCALL_TAIL(PlayPreloadedBeatTrack, arg1)
    DECL_THISCALL_SIMPLE(StopBeatTrack, _ZN12CAudioEngine13StopBeatTrackEv, void);
    DECL_THISCALL_SIMPLE(GetBeatInfo, _ZN12CAudioEngine11GetBeatInfoEv, tBeatInfo*);
    DECL_THISCALL_HEAD(PauseBeatTrack, _ZN12CAudioEngine14PauseBeatTrackEh, void, u8 arg1)
    DECL_THISCALL_TAIL(PauseBeatTrack, arg1)
    DECL_THISCALL_SIMPLE(IsBeatInfoPresent, _ZN12CAudioEngine17IsBeatInfoPresentEv, bool);
    DECL_THISCALL_SIMPLE(IsAmbienceTrackActive, _ZN12CAudioEngine21IsAmbienceTrackActiveEv, u8);
    DECL_THISCALL_HEAD(StopAmbienceTrack, _ZN12CAudioEngine17StopAmbienceTrackEh, void, u8 arg1)
    DECL_THISCALL_TAIL(StopAmbienceTrack, arg1)
    DECL_THISCALL_SIMPLE(DoesAmbienceTrackOverrideRadio, _ZN12CAudioEngine30DoesAmbienceTrackOverrideRadioEv, u8);
    DECL_THISCALL_SIMPLE(IsAmbienceRadioActive, _ZN12CAudioEngine21IsAmbienceRadioActiveEv, u8);
    DECL_THISCALL_HEAD(PreloadMissionAudio, _ZN12CAudioEngine19PreloadMissionAudioEhi, void, u8 arg1, i32 arg2)
    DECL_THISCALL_TAIL(PreloadMissionAudio, arg1, arg2)
    DECL_THISCALL_HEAD(GetMissionAudioLoadingStatus, _ZN12CAudioEngine28GetMissionAudioLoadingStatusEh, u8, u8 arg1)
    DECL_THISCALL_TAIL(GetMissionAudioLoadingStatus, arg1)
    DECL_THISCALL_HEAD(PlayLoadedMissionAudio, _ZN12CAudioEngine22PlayLoadedMissionAudioEh, void, u8 arg1)
    DECL_THISCALL_TAIL(PlayLoadedMissionAudio, arg1)
    DECL_THISCALL_HEAD(IsMissionAudioSampleFinished, _ZN12CAudioEngine28IsMissionAudioSampleFinishedEh, u8, u8 arg1)
    DECL_THISCALL_TAIL(IsMissionAudioSampleFinished, arg1)
    DECL_THISCALL_HEAD(GetMissionAudioEvent, _ZN12CAudioEngine20GetMissionAudioEventEh, i32, u8 arg1)
    DECL_THISCALL_TAIL(GetMissionAudioEvent, arg1)
    DECL_THISCALL_HEAD(GetMissionAudioPosition, _ZN12CAudioEngine23GetMissionAudioPositionEh, CVector*, u8 arg1)
    DECL_THISCALL_TAIL(GetMissionAudioPosition, arg1)
    DECL_THISCALL_HEAD(ClearMissionAudio, _ZN12CAudioEngine17ClearMissionAudioEh, void, u8 arg1)
    DECL_THISCALL_TAIL(ClearMissionAudio, arg1)
    DECL_THISCALL_HEAD(SetMissionAudioPosition, _ZN12CAudioEngine23SetMissionAudioPositionEhR7CVector, void, u8 arg1, CVector& arg2)
    DECL_THISCALL_TAIL(SetMissionAudioPosition, arg1, arg2)
    DECL_THISCALL_HEAD(AttachMissionAudioToPed, _ZN12CAudioEngine23AttachMissionAudioToPedEhP4CPed, void, u8 arg1, CPed* pCPed2)
    DECL_THISCALL_TAIL(AttachMissionAudioToPed, arg1, pCPed2)
    DECL_THISCALL_HEAD(AttachMissionAudioToObject, _ZN12CAudioEngine26AttachMissionAudioToObjectEhP7CObject, void, u8 arg1, CObject* pCObject2)
    DECL_THISCALL_TAIL(AttachMissionAudioToObject, arg1, pCObject2)
    DECL_THISCALL_HEAD(AttachMissionAudioToPhysical, _ZN12CAudioEngine28AttachMissionAudioToPhysicalEhP9CPhysical, void, u8 arg1, CPhysical* pCPhysical2)
    DECL_THISCALL_TAIL(AttachMissionAudioToPhysical, arg1, pCPhysical2)
    DECL_THISCALL_NAMED_HEAD(ReportMissionAudioEvent1, ReportMissionAudioEvent, _ZN12CAudioEngine23ReportMissionAudioEventEtR7CVector, void, u16 audioEvent, CVector& coords)
    DECL_THISCALL_TAIL(ReportMissionAudioEvent1, audioEvent, coords)
    DECL_THISCALL_NAMED_HEAD(ReportMissionAudioEvent2, ReportMissionAudioEvent, _ZN12CAudioEngine23ReportMissionAudioEventEtP7CObject, void, u16 audioEvent, CObject* coords)
    DECL_THISCALL_TAIL(ReportMissionAudioEvent2, audioEvent, coords)
    DECL_THISCALL_NAMED_HEAD(ReportMissionAudioEvent3, ReportMissionAudioEvent, _ZN12CAudioEngine23ReportMissionAudioEventEtP4CPed, void, u16 audioEvent, CPed* coords)
    DECL_THISCALL_TAIL(ReportMissionAudioEvent3, audioEvent, coords)
    DECL_THISCALL_NAMED_HEAD(ReportMissionAudioEvent4, ReportMissionAudioEvent, _ZN12CAudioEngine23ReportMissionAudioEventEtP8CVehicle, void, u16 audioEvent, CVehicle* coords)
    DECL_THISCALL_TAIL(ReportMissionAudioEvent4, audioEvent, coords)
    DECL_THISCALL_NAMED_HEAD(ReportMissionAudioEvent5, ReportMissionAudioEvent, _ZN12CAudioEngine23ReportMissionAudioEventEtP9CPhysicalff, void, u16 arg1, CPhysical* pCPhysical2, float arg3, float arg4)
    DECL_THISCALL_TAIL(ReportMissionAudioEvent5, arg1, pCPhysical2, arg3, arg4)
    DECL_THISCALL_HEAD(SayPedless, _ZN12CAudioEngine10SayPedlessEisP7CEntityjfhhh, void, i32 arg1, i16 arg2, CEntity* pCEntity3, u32 arg4, float arg5, u8 arg6, u8 arg7, u8 arg8)
    DECL_THISCALL_TAIL(SayPedless, arg1, arg2, pCEntity3, arg4, arg5, arg6, arg7, arg8)
    DECL_THISCALL_HEAD(DisablePoliceScanner, _ZN12CAudioEngine20DisablePoliceScannerEhh, void, u8 arg1, u8 arg2)
    DECL_THISCALL_TAIL(DisablePoliceScanner, arg1, arg2)
    DECL_THISCALL_SIMPLE(EnablePoliceScanner, _ZN12CAudioEngine19EnablePoliceScannerEv, void);
    DECL_THISCALL_HEAD(StopPoliceScanner, _ZN12CAudioEngine17StopPoliceScannerEh, void, u8 arg1)
    DECL_THISCALL_TAIL(StopPoliceScanner, arg1)
    DECL_THISCALL_SIMPLE(StartLoadingTune, _ZN12CAudioEngine16StartLoadingTuneEv, void);
    DECL_THISCALL_SIMPLE(PauseAllSounds, _ZN12CAudioEngine14PauseAllSoundsEv, void);
    DECL_THISCALL_SIMPLE(ResumeAllSounds, _ZN12CAudioEngine15ResumeAllSoundsEv, void);
    DECL_THISCALL_SIMPLE(Save, _ZN12CAudioEngine4SaveEv, void);
    DECL_THISCALL_SIMPLE(Load, _ZN12CAudioEngine4LoadEv, void);

    // Member values
    unsigned char m_bMissionCompleteActive;
    unsigned char m_bStoppingMissionComplete;
    signed char m_nCurrentRadiostationId;
    int m_nAudioStreamClientHandle;
    tBeatInfo m_BeatInfo;
    CAEFrontendAudioEntity m_FrontendAudio;
    CAEScriptAudioEntity m_scriptAudio;
    CAECollisionAudioEntity m_collisionAudio;
    CAEGlobalWeaponAudioEntity *m_pWeaponAudio;
    CAEPedlessSpeechAudioEntity m_pedlessSpeechAudio;
    CAEDoorAudioEntity m_doorAudio;
DECL_CLASS_END()
CHECKSIZE(CAudioEngine, 0x1FD8, 0x2F50);

DECL_OBJECT_PLT_GLOBAL(CAudioEngine, AudioEngine, BYBIT(0x675F74, 0x849F58) );
#define AudioEngine AudioEngine()

#endif // __AML_PSDK_SAAUDIOENGINE_H
