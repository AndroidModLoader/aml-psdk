#ifndef __AML_PSDK_SAAEPEDLESSSPEECHAUDIOENTITY_H
#define __AML_PSDK_SAAEPEDLESSSPEECHAUDIOENTITY_H

#include "AEAudioEntity.h"

struct CEntity;

DECL_CLASS(CAEPedlessSpeechAudioEntity)
    // Construct/Deconstruct functions
    DECL_CTORCALL(CAEPedlessSpeechAudioEntity, _ZN27CAEPedlessSpeechAudioEntityC2Ev);

    CAEPedSpeechAudioEntity pedSpeech;
    CAESound *SoundPtrs[5];
    CEntity *m_pEntityAttachedTo;

    // Member functions
    DECL_THISCALL_HEAD(AddSayEvent, _ZN27CAEPedlessSpeechAudioEntity11AddSayEventEisP7CEntityjfhhh, i16, i32 AudioEvent, i16 GlobalSpeechContext, CEntity* pEntityAttachedTo, u32 StartTimeDelay, float Probability, u8 OverideSilence, u8 bForceAudible, u8 bFrontEnd)
    DECL_THISCALL_TAIL(AddSayEvent, AudioEvent, GlobalSpeechContext, pEntityAttachedTo, StartTimeDelay, Probability, OverideSilence, bForceAudible, bFrontEnd)
    DECL_THISCALL_SIMPLE(Initialise, _ZN27CAEPedlessSpeechAudioEntity10InitialiseEv, void);
    DECL_THISCALL_SIMPLE(StopCurrentSpeech, _ZN27CAEPedlessSpeechAudioEntity17StopCurrentSpeechEv, void);
DECL_CLASS_END()

#endif // __AML_PSDK_SAAEPEDLESSSPEECHAUDIOENTITY_H
