#ifndef __AML_PSDK_SAAEFRONTENDAUDIOENTITY_H
#define __AML_PSDK_SAAEFRONTENDAUDIOENTITY_H

#include "AEAudioEntity.h"

DECL_CLASS(CAEFrontendAudioEntity)
    // Member functions
    DECL_THISCALL_SIMPLE(Initialise, _ZN22CAEFrontendAudioEntity10InitialiseEv, void);
    DECL_THISCALL_SIMPLE(Terminate, _ZN22CAEFrontendAudioEntity9TerminateEv, void);
    DECL_THISCALL_SIMPLE(Reset, _ZN22CAEFrontendAudioEntity5ResetEv, void);
    DECL_THISCALL_SIMPLE(IsLoadingTuneActive, _ZN22CAEFrontendAudioEntity19IsLoadingTuneActiveEv, u8);
    DECL_THISCALL_HEAD(AddAudioEvent, _ZN22CAEFrontendAudioEntity13AddAudioEventEiff, void, i32 AudioEvent, float fVolumeOffsetdB, float fFrequencyScaling)
    DECL_THISCALL_TAIL(AddAudioEvent, AudioEvent, fVolumeOffsetdB, fFrequencyScaling)
    DECL_THISCALL_SIMPLE(IsRadioTuneSoundActive, _ZN22CAEFrontendAudioEntity22IsRadioTuneSoundActiveEv, u8);

    CAEAudioEntity audio;
    unsigned char m_bWakeupAmplifierEventTriggered;
    signed char m_nLoadingTrackIndex;
    short m_nLastRetuneSoundID;
    short m_nNumBulletSounds;
    short bankId;
    unsigned int m_LastPickupEventFrame;
    unsigned int m_LastPartMissionCompleteEventFrame;
    unsigned int m_LastBulletPassEventFrame;
    unsigned int m_nResprayStartTimeMs;
    unsigned int m_nLastFrontendTimerCountTimeMs;
    CAESound *m_pWakeupAmplifierSound;
    CAETwinLoopSoundEntity m_RadioTuneSound;
    CAETwinLoopSoundEntity m_RadioTuneSoundInPause;
DECL_CLASS_END()
CHECKSIZE(CAEFrontendAudioEntity, 0x1EC, 0x248);

#endif // __AML_PSDK_SAAEFRONTENDAUDIOENTITY_H