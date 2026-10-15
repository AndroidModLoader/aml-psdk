#ifndef __AML_PSDK_SAWATERCANNONS_H
#define __AML_PSDK_SAWATERCANNONS_H

#include <aml-psdk/game_sa/audio/AEAudioEntity.h>

struct CWaterCannon;

DECL_CLASS(tWaterCannonSound)
    // Member values
    CAESound* SoundPtr;
DECL_CLASS_END()
CHECKSIZE(tWaterCannonSound, 0x4, 0x8);

DECL_CLASS_BASED(CAEWaterCannonAudioEntity, CAEAudioEntity)
    // Virtual functions
    virtual void UpdateParameters(CAESound* pSound, i16 PlayTime) override;

    // Member functions
    DECL_FASTCALL_SIMPLE(StaticInitialise, _ZN25CAEWaterCannonAudioEntity16StaticInitialiseEv, void);
    DECL_THISCALL_HEAD(Initialise, _ZN25CAEWaterCannonAudioEntity10InitialiseEP12CWaterCannon, void, CWaterCannon* pWaterCannon)
    DECL_THISCALL_TAIL(Initialise, pWaterCannon)
    DECL_THISCALL_SIMPLE(Terminate, _ZN25CAEWaterCannonAudioEntity9TerminateEv, void);
    DECL_THISCALL_HEAD(AddAudioEvent, _ZN25CAEWaterCannonAudioEntity13AddAudioEventEiR7CVector, void, i32 AudioEvent, CVector& vPosition)
    DECL_THISCALL_TAIL(AddAudioEvent, AudioEvent, vPosition)
    DECL_THISCALL_SIMPLE(Service, _ZN25CAEWaterCannonAudioEntity7ServiceEv, void);
    DECL_THISCALL_HEAD(SetSplashInfo, _ZN25CAEWaterCannonAudioEntity13SetSplashInfoE7CVectorf, void, CVector vPosition, float fStrength)
    DECL_THISCALL_TAIL(SetSplashInfo, vPosition, fStrength)
    DECL_THISCALL_SIMPLE(ClearSplashInfo, _ZN25CAEWaterCannonAudioEntity15ClearSplashInfoEv, void);
    DECL_THISCALL_HEAD(UpdateGenericWaterCannonSound, _ZN25CAEWaterCannonAudioEntity29UpdateGenericWaterCannonSoundEhsssff7CVectorf, void, u8 bPlaying, i16 SoundType, i16 SlotID, i16 SoundID, float fFrequency, float fVolume, CVector vPosition, float fRollOff)
    DECL_THISCALL_TAIL(UpdateGenericWaterCannonSound, bPlaying, SoundType, SlotID, SoundID, fFrequency, fVolume, vPosition, fRollOff)

    // Member values
    u8 m_bInitialised;
    u8 m_bCurrentlySplashing;
    CVector m_vSplashPosition;
    float m_fSplashStrength;
    tWaterCannonSound m_WaterCannonSounds[4];
DECL_CLASS_END()
CHECKSIZE(CAEWaterCannonAudioEntity, 0xA0, 0xC8);

DECL_CLASS(CWaterCannon)
    // Member functions
    DECL_THISCALL_SIMPLE(Init, _ZN12CWaterCannon4InitEv, void);
    DECL_THISCALL_HEAD(Update_OncePerFrame, _ZN12CWaterCannon19Update_OncePerFrameEs, void, i16 StreamNumber)
    DECL_THISCALL_TAIL(Update_OncePerFrame, StreamNumber)
    DECL_THISCALL_HEAD(Update_NewInput, _ZN12CWaterCannon15Update_NewInputEP7CVectorS1_, void, CVector* pCoors, CVector* pSpeed)
    DECL_THISCALL_TAIL(Update_NewInput, pCoors, pSpeed)
    DECL_THISCALL_SIMPLE(Render, _ZN12CWaterCannon6RenderEv, void);
    DECL_THISCALL_SIMPLE(PushPeds, _ZN12CWaterCannon8PushPedsEv, void);

    // Member values
    u32 ID;
    i16 PointClosestToOrigin;
    u32 LastTimeElementStored;
    CVector aPoints[32];
    CVector aSpeed[32];
    bool aPointsUsed[32];
    CAEWaterCannonAudioEntity m_AEWaterCannonAudioEntity;
DECL_CLASS_END()
CHECKSIZE(CWaterCannon, 0x3CC, 0x3F8);

DECL_CLASS(CWaterCannons)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(Init, _ZN13CWaterCannons4InitEv, void);
    DECL_FASTCALL_SIMPLE(UpdateOne, _ZN13CWaterCannons9UpdateOneEjP7CVectorS1_, void, u32 ID, CVector* pCoors, CVector* pSpeed);
    DECL_FASTCALL_SIMPLE(Update, _ZN13CWaterCannons6UpdateEv, void);
    DECL_FASTCALL_SIMPLE(Render, _ZN13CWaterCannons6RenderEv, void);

    // STATIC values
    DECL_OBJECT_ARRAY_PLT(CWaterCannon, aCannons, BYBIT(0x679710, 0x850E30));

DECL_CLASS_END()
CHECKSIZE(CWaterCannons, 0x1, 0x1);

#endif // __AML_PSDK_SAWATERCANNONS_H
