#ifndef __AML_PSDK_SAAESCRIPTAUDIOENTITY_H
#define __AML_PSDK_SAAESCRIPTAUDIOENTITY_H

#include "AEDoorAudioEntity.h"

struct CEntity;
struct CPhysical;

struct CAudioLink
{
    CVector m_vPosition;
    CPhysical* m_pEntity;
    CAESound *pSound;
    int m_nAudioEvent;
    int m_nBankId;
    int m_nBankSlotId;
};

DECL_CLASS_BASED(CAEExplosionAudioEntity, CAEAudioEntity)
    CAEExplosionAudioEntity() = delete;

    // STATIC functions
    DECL_FASTCALL_SIMPLE(StaticInitialise, _ZN23CAEExplosionAudioEntity16StaticInitialiseEv, void);

    signed char m_nLastExplosionFrequencyIndex;

    // Member functions
    DECL_THISCALL_HEAD(AddAudioEvent, _ZN23CAEExplosionAudioEntity13AddAudioEventEiR7CVectorf, void, i32 AudioEvent, CVector& vPosition, float fVolumeOffsetdB)
    DECL_THISCALL_TAIL(AddAudioEvent, AudioEvent, vPosition, fVolumeOffsetdB)
DECL_CLASS_END()

DECL_CLASS(CAEScriptAudioEntity)
    CAEScriptAudioEntity() = delete;

    // Member functions
    DECL_THISCALL_SIMPLE(Initialise, _ZN20CAEScriptAudioEntity10InitialiseEv, void);
    DECL_THISCALL_SIMPLE(Reset, _ZN20CAEScriptAudioEntity5ResetEv, void);
    DECL_THISCALL_SIMPLE(Service, _ZN20CAEScriptAudioEntity7ServiceEv, void);
    DECL_THISCALL_HEAD(AddAudioEvent, _ZN20CAEScriptAudioEntity13AddAudioEventEi, void, i32 AudioEvent)
    DECL_THISCALL_TAIL(AddAudioEvent, AudioEvent)
    DECL_THISCALL_HEAD(PreloadMissionAudio, _ZN20CAEScriptAudioEntity19PreloadMissionAudioEhi, void, u8 Slot, i32 ScriptSlotAudioEvent)
    DECL_THISCALL_TAIL(PreloadMissionAudio, Slot, ScriptSlotAudioEvent)
    DECL_THISCALL_HEAD(GetMissionAudioLoadingStatus, _ZN20CAEScriptAudioEntity28GetMissionAudioLoadingStatusEh, u8, u8 Slot)
    DECL_THISCALL_TAIL(GetMissionAudioLoadingStatus, Slot)
    DECL_THISCALL_HEAD(PlayLoadedMissionAudio, _ZN20CAEScriptAudioEntity22PlayLoadedMissionAudioEh, void, u8 Slot)
    DECL_THISCALL_TAIL(PlayLoadedMissionAudio, Slot)
    DECL_THISCALL_HEAD(IsMissionAudioSampleFinished, _ZN20CAEScriptAudioEntity28IsMissionAudioSampleFinishedEh, u8, u8 Slot)
    DECL_THISCALL_TAIL(IsMissionAudioSampleFinished, Slot)
    DECL_THISCALL_HEAD(GetMissionAudioEvent, _ZN20CAEScriptAudioEntity20GetMissionAudioEventEh, i32, u8 Slot)
    DECL_THISCALL_TAIL(GetMissionAudioEvent, Slot)
    DECL_THISCALL_HEAD(GetMissionAudioPosition, _ZN20CAEScriptAudioEntity23GetMissionAudioPositionEh, CVector*, u8 Slot)
    DECL_THISCALL_TAIL(GetMissionAudioPosition, Slot)
    DECL_THISCALL_HEAD(ClearMissionAudio, _ZN20CAEScriptAudioEntity17ClearMissionAudioEh, void, u8 Slot)
    DECL_THISCALL_TAIL(ClearMissionAudio, Slot)
    DECL_THISCALL_HEAD(SetMissionAudioPosition, _ZN20CAEScriptAudioEntity23SetMissionAudioPositionEhR7CVector, void, u8 Slot, CVector& vPosition)
    DECL_THISCALL_TAIL(SetMissionAudioPosition, Slot, vPosition)
    DECL_THISCALL_HEAD(AttachMissionAudioToPhysical, _ZN20CAEScriptAudioEntity28AttachMissionAudioToPhysicalEhP9CPhysical, void, u8 Slot, CPhysical* pPhysical)
    DECL_THISCALL_TAIL(AttachMissionAudioToPhysical, Slot, pPhysical)
    DECL_THISCALL_NAMED_HEAD(ReportMissionAudioEvent1, ReportMissionAudioEvent, _ZN20CAEScriptAudioEntity23ReportMissionAudioEventEtR7CVector, void, u16 arg1, CVector& arg2)
    DECL_THISCALL_TAIL(ReportMissionAudioEvent1, arg1, arg2)
    DECL_THISCALL_NAMED_HEAD(ReportMissionAudioEvent2, ReportMissionAudioEvent, _ZN20CAEScriptAudioEntity23ReportMissionAudioEventEtP9CPhysicalff, void, u16 Event, CPhysical* pPhysical, float fVolumeOffsetdB, float fFrequencyScaling)
    DECL_THISCALL_TAIL(ReportMissionAudioEvent2, Event, pPhysical, fVolumeOffsetdB, fFrequencyScaling)
    DECL_THISCALL_HEAD(ProcessMissionAudioEvent, _ZN20CAEScriptAudioEntity24ProcessMissionAudioEventEtR7CVectorP9CPhysicalff, void, u16 Event, CVector& vPosition, CPhysical* pPhysical, float fVolumeOffsetdB, float fFrequencyScaling)
    DECL_THISCALL_TAIL(ProcessMissionAudioEvent, Event, vPosition, pPhysical, fVolumeOffsetdB, fFrequencyScaling)
    DECL_THISCALL_HEAD(PlayResidentSoundEvent, _ZN20CAEScriptAudioEntity22PlayResidentSoundEventEssstR7CVectorP9CPhysicalffsf, void, i16 BankSlotID, i16 BankID, i16 SoundID, u16 Event, CVector& vPosition, CPhysical* pPhysical, float fVolumeOffsetdB, float fFrequencyScaling, i16 StartPercentage, float fRolloff)
    DECL_THISCALL_TAIL(PlayResidentSoundEvent, BankSlotID, BankID, SoundID, Event, vPosition, pPhysical, fVolumeOffsetdB, fFrequencyScaling, StartPercentage, fRolloff)
    DECL_THISCALL_HEAD(PlayMissionBankSound, _ZN20CAEScriptAudioEntity20PlayMissionBankSoundEtR7CVectorP9CPhysicalshhfff, void, u16 Event, CVector& vPosition, CPhysical* pPhysical, i16 SoundID, u8 Slot, u8 bInhibitOverlap, float fVolumeOffsetdB, float fRolloff, float fFrequencyScaling)
    DECL_THISCALL_TAIL(PlayMissionBankSound, Event, vPosition, pPhysical, SoundID, Slot, bInhibitOverlap, fVolumeOffsetdB, fRolloff, fFrequencyScaling)

    CAEAudioEntity audio;
    unsigned char m_bMiniGameOneShotTriggered;
    unsigned char m_bInACrane;
    signed char m_nMeshGateTriggerCount;
    unsigned int m_dwLastTimeHornPlayed;
    float m_fCraneVolume;
    float m_fCraneFrequencyScaling;
    float m_fMissionSoundEnvelopePhase;
    CAudioLink wavLinks[4];
    CPhysical *m_pCrane;
    CAEDoorAudioEntity m_doorAudio;
    CAEExplosionAudioEntity m_explosionAudio;
DECL_CLASS_END()
CHECKSIZE(CAEScriptAudioEntity, 0x21C, 0x2A8);

#endif // __AML_PSDK_SAAESCRIPTAUDIOENTITY_H
