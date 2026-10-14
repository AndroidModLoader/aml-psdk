#ifndef __AML_PSDK_SAAEDOORAUDIOENTITY_H
#define __AML_PSDK_SAAEDOORAUDIOENTITY_H

#include "AEAudioEntity.h"

DECL_CLASS(CAEDoorAudioEntity)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(StaticInitialise, _ZN18CAEDoorAudioEntity16StaticInitialiseEv, void);

    CAEAudioEntity audio;
    unsigned int m_nTime;
    unsigned int m_nLastEntryExitDoorEventTimeMs;
    float m_fDoorTurnSpeedLastFrame;

    // Member functions
    DECL_THISCALL_SIMPLE(Reset, _ZN18CAEDoorAudioEntity5ResetEv, void);
    DECL_THISCALL_NAMED_HEAD(AddAudioEvent1, AddAudioEvent, _ZN18CAEDoorAudioEntity13AddAudioEventEiR7CVectorff, void, i32 arg1, CVector& arg2, float arg3, float arg4)
    DECL_THISCALL_TAIL(AddAudioEvent1, arg1, arg2, arg3, arg4)
    DECL_THISCALL_NAMED_HEAD(AddAudioEvent2, AddAudioEvent, _ZN18CAEDoorAudioEntity13AddAudioEventEiP9CPhysical, void, i32 AudioEvent, CPhysical* pPhysical)
    DECL_THISCALL_TAIL(AddAudioEvent2, AudioEvent, pPhysical)
    DECL_THISCALL_HEAD(PlayDoorSound, _ZN18CAEDoorAudioEntity13PlayDoorSoundEsiR7CVectorff, void, i16 SoundID, i32 AudioEvent, CVector& vPosition, float fVolumeOffsetdB, float fFrequencyScaling)
    DECL_THISCALL_TAIL(PlayDoorSound, SoundID, AudioEvent, vPosition, fVolumeOffsetdB, fFrequencyScaling)
DECL_CLASS_END()

#endif // __AML_PSDK_SAAEDOORAUDIOENTITY_H