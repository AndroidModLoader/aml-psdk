#ifndef __AML_PSDK_SAAEAUDIOENTITY_H
#define __AML_PSDK_SAAEAUDIOENTITY_H

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/gta_base/Vector.h>
#include <aml-psdk/game_sa/enum/WeaponType.h>
#include <aml-psdk/game_sa/enum/Vehicles.h>
#include <aml-psdk/game_sa/enum/CrimeType.h>

struct tScannerSlot
{
    i16 BankID;
    i16 SoundID;
};
CHECKSIZE(tScannerSlot, 0x4, 0x4);

struct CEntity;
struct CPhysical;
struct CVehicle;
struct CAEAudioEntity;
struct CPed;
struct CPlayerPed;
struct FxSystem_c;
struct cVehicleParams;
struct cTransmission;

enum eSoundEnvironment : unsigned short
{
    SOUND_FRONT_END = 1,
    SOUND_UNCANCELLABLE = 2,
    SOUND_REQUEST_UPDATES = 4,
    SOUND_PLAY_PHYSICALLY = 8,
    SOUND_UNPAUSABLE = 16,
    SOUND_START_PERCENTAGE = 32,
    SOUND_MUSIC_MASTERED = 64,
    SOUND_LIFESPAN_TIED_TO_PHYSICAL_ENTITY = 128,
    SOUND_UNDUCKABLE = 256,
    SOUND_UNCOMPRESSABLE = 512,
    SOUND_ROLLED_OFF = 1024,
    SOUND_SMOOTH_DUCKING = 2048,
    SOUND_FORCED_FRONT = 4096
};

enum eAudioPedType
{
    PED_TYPE_GEN = 0,
    PED_TYPE_EMG = 1,
    PED_TYPE_PLAYER = 2,
    PED_TYPE_GANG = 3,
    PED_TYPE_GFD = 4,
    PED_TYPE_SPC = 5
};

struct CAEPedSpeechAudioEntity;
struct CAESound;

struct tDummyEngineSlot
{
    i16 BankId;
    i16 NumberOfUsers;
};
CHECKSIZE(tDummyEngineSlot, 0x4, 0x4);

struct CAEPedSpeechSlot
{
    i16 m_InUse;
    CAEPedSpeechAudioEntity* m_pAudioEntity;
    CAESound* m_pSound;
    i16 m_SoundID;
    i16 m_BankID;
    u32 m_StartPlaybackTime;
    i16 m_GlobalSpeechContext;
    i16 m_PedType;
    u8 m_bForceAudible;
    u8 m_ReservedForPedConversation;
    u8 m_ReservedForPlayerConversation;
};
CHECKSIZE(CAEPedSpeechSlot, 0x1C, 0x28);

struct cVehicleParams
{
    i32 nSpecificVehicleType;
    i32 nBaseVehicleType;
    u8 bDistanceCalculated;
    float fDistSqr;
    CVehicle* pVehicle;
    cTransmission* pTransmission;
    u32 nModelIndexMinusOffset;
    float fSpeed;
    i16 ThisAccel;
    i16 ThisBrake;
    float fAbsSpeed;
    float fZOverSpeed;
    float fSpeedRatio;
    float* p_fGasPedalAudioRevs;
    float fPrevSpeed;
    u8 RealGear;
    u8 bHandbrakeOn;
    float fRealRevsRatio;
    float fWheelSpin;
    i16 NumGears;
    u8 NumDriveWheelsOnGround;
    u8 NumDriveWheelsOnGroundLastFrame;
    tWheelState* pWheelState;
};
CHECKSIZE(cVehicleParams, 0x4C, 0x60);

DECL_CLASS(CAESound)
    // Construct/Deconstruct functions
    DECL_CTORCALL_NAMED_ARG_HEAD(CAESound1, CAESound, _ZN8CAESoundC2ERS_, CAESound& sound)
    DECL_CTORCALL_ARG_TAIL(sound)
    CAESound() : m_pPhysicalEntity(NULL) {}
    DECL_CTORCALL_ARG_HEAD(CAESound, _ZN8CAESoundC2EssP14CAEAudioEntity7CVectorffffhtf, i16 BankSlotID, i16 SoundID, CAEAudioEntity *pAudioEntity,
                                                                                        CVector Position, float Volume, float RollOffFactor, float RelativeFrequency,
                                                                                        float Doppler, u8 FrameDelay, u16 Environment, float FrequencyVariance)
    DECL_CTORCALL_ARG_TAIL(BankSlotID, SoundID, pAudioEntity, Position, Volume, RollOffFactor, RelativeFrequency, Doppler, FrameDelay, Environment, FrequencyVariance)
    DECL_DTORCALL(CAESound, _ZN8CAESoundD2Ev);

    // Member functions
    DECL_THISCALL_NAMED_HEAD(Assign, operator=, _ZN8CAESoundaSERS_, CAESound&, CAESound &sound)
    DECL_THISCALL_TAIL(Assign, sound)

    DECL_THISCALL_HEAD(SetPosition, _ZN8CAESound11SetPositionE7CVector, void, CVector posn)
    DECL_THISCALL_TAIL(SetPosition, posn)
    DECL_THISCALL_SIMPLE(UnregisterWithPhysicalEntity, _ZN8CAESound28UnregisterWithPhysicalEntityEv, void);
    DECL_THISCALL_SIMPLE(NewVPSLentry, _ZN8CAESound12NewVPSLentryEv, void);
    DECL_THISCALL_SIMPLE(CalculateFrequency, _ZN8CAESound18CalculateFrequencyEv, void);
    DECL_THISCALL_SIMPLE(GetLifespanTiedToPhysicalEntity, _ZN8CAESound31GetLifespanTiedToPhysicalEntityEv, u16);
    DECL_THISCALL_SIMPLE(StopSound, _ZN8CAESound9StopSoundEv, void);
    DECL_THISCALL_SIMPLE(GetRequestUpdates, _ZN8CAESound17GetRequestUpdatesEv, u16);
    DECL_THISCALL_SIMPLE(UpdateFrequency, _ZN8CAESound15UpdateFrequencyEv, void);
    DECL_THISCALL_SIMPLE(StopSoundAndForget, _ZN8CAESound18StopSoundAndForgetEv, void);
    DECL_THISCALL_SIMPLE(GetUncancellable, _ZN8CAESound16GetUncancellableEv, u16);
    DECL_THISCALL_SIMPLE(GetFrontEnd, _ZN8CAESound11GetFrontEndEv, u16);
    DECL_THISCALL_SIMPLE(GetUnpausable, _ZN8CAESound13GetUnpausableEv, u16);
    DECL_THISCALL_SIMPLE(GetPlayPhysically, _ZN8CAESound17GetPlayPhysicallyEv, u16);
    DECL_THISCALL_SIMPLE(GetStartPercentage, _ZN8CAESound18GetStartPercentageEv, u16);
    DECL_THISCALL_SIMPLE(GetMusicMastered, _ZN8CAESound16GetMusicMasteredEv, u16);
    DECL_THISCALL_SIMPLE(GetUnduckable, _ZN8CAESound13GetUnduckableEv, u16);
    DECL_THISCALL_SIMPLE(GetUncompressable, _ZN8CAESound17GetUncompressableEv, u16);
    DECL_THISCALL_SIMPLE(GetRolledOff, _ZN8CAESound12GetRolledOffEv, u16);
    DECL_THISCALL_SIMPLE(GetSmoothDucking, _ZN8CAESound16GetSmoothDuckingEv, u16);
    DECL_THISCALL_SIMPLE(GetForcedFront, _ZN8CAESound14GetForcedFrontEv, u16);
    DECL_THISCALL_SIMPLE(SoundHasFinished, _ZN8CAESound16SoundHasFinishedEv, void);
    DECL_THISCALL_SIMPLE(CalculateVolume, _ZN8CAESound15CalculateVolumeEv, void);
    DECL_THISCALL_SIMPLE(GetRelativePlaybackFrequencyWithDoppler, _ZN8CAESound39GetRelativePlaybackFrequencyWithDopplerEv, float);
    DECL_THISCALL_SIMPLE(GetSlowMoFrequencyScalingFactor, _ZN8CAESound31GetSlowMoFrequencyScalingFactorEv, float);

    DECL_THISCALL_HEAD(Initialise, _ZN8CAESound10InitialiseEssP14CAEAudioEntity7CVectorffffhtfs, void, i16 BankSlotID, i16 SoundID, CAEAudioEntity *pAudioEntity,
                                                                                        CVector Position, float Volume, float RollOffFactor, float RelativeFrequency,
                                                                                        float Doppler, u8 FrameDelay, u16 Environment, float FrequencyVariance, i16 PlayTime)
    DECL_THISCALL_TAIL(Initialise, BankSlotID, SoundID, pAudioEntity, Position, Volume, RollOffFactor, RelativeFrequency, Doppler, FrameDelay, Environment, FrequencyVariance, PlayTime)

    DECL_THISCALL_HEAD(UpdateParameters, _ZN8CAESound16UpdateParametersEs, void, i16 PlayTime)
    DECL_THISCALL_TAIL(UpdateParameters, PlayTime)

    DECL_THISCALL_HEAD(RegisterWithPhysicalEntity, _ZN8CAESound26RegisterWithPhysicalEntityEP7CEntity, void, CEntity *pPhysicalEntity)
    DECL_THISCALL_TAIL(RegisterWithPhysicalEntity, pPhysicalEntity)

    DECL_THISCALL_HEAD(SetIndividualEnvironment, _ZN8CAESound24SetIndividualEnvironmentEtt, void, u16 environment, u16 tf)
    DECL_THISCALL_TAIL(SetIndividualEnvironment, environment, tf)

    DECL_THISCALL_HEAD(UpdatePlayTime, _ZN8CAESound14UpdatePlayTimeEsss, void, i16 VirtualChannelSoundLength, i16 VirtualChannelSoundLoopStartTime, i16 TimeElapsed)
    DECL_THISCALL_TAIL(UpdatePlayTime, VirtualChannelSoundLength, VirtualChannelSoundLoopStartTime, TimeElapsed)

    DECL_THISCALL_HEAD(GetRelativePosition, _ZN8CAESound19GetRelativePositionEP7CVector, void, CVector *pRelativePosition)
    DECL_THISCALL_TAIL(GetRelativePosition, pRelativePosition)

    // Member values
    short                 m_nBankSlotId;
    short                 m_nSoundIdInSlot;
    CAEAudioEntity       *m_pBaseAudio;
    CEntity              *m_pPhysicalEntity;
    int                   m_nEvent;
    float                 m_fMaxVolume;
    float                 m_fVolume;
    float                 m_fSoundDistance;
    float                 m_fSpeed;
    float                 m_FrequencyVariance;
    CVector               m_vecCurrPosn;
    CVector               m_vecPrevPosn;
    unsigned int          m_nLastFrameUpdate;
    unsigned int          m_nCurrTimeUpdate;
    unsigned int          m_nPrevTimeUpdate;
    float                 m_fCurrCamDist;
    float                 m_fPrevCamDist;
    float                 m_fTimeScale;
    unsigned char         m_FrameDelay;
    union
    {
        unsigned short m_nEnvironmentFlags;
        struct
        {
            unsigned short m_bFrontEnd : 1;
            unsigned short m_bUncancellable : 1;
            unsigned short m_bRequestUpdates : 1;
            unsigned short m_bPlayPhysically : 1;
            unsigned short m_bUnpausable : 1;
            unsigned short m_bStartPercentage : 1;
            unsigned short m_bMusicMastered : 1;
            unsigned short m_bLifespanTiedToPhysicalEntity : 1;
            unsigned short m_bUndackable : 1;
            unsigned short m_bUncompressable : 1;
            unsigned short m_bRolledOff : 1;
            unsigned short m_bSmoothDucking : 1;
            unsigned short m_bForcedFront : 1;
        };
    };
    unsigned short        m_nIsUsed;
    unsigned short        m_bAudioHardwareAware;
    short                 m_nCurrentPlayPosition;
    unsigned short        m_bPhysicallyPlaying;
    float                 m_fFinalVolume;
    float                 m_fFrequency;
    unsigned short        m_nPlayingState;
    float                 m_fSoundHeadRoom;
    short                 m_nSoundLength;
DECL_CLASS_END()
CHECKSIZE(CAESound, 0x74, 0x80);



DECL_CLASS(CAEAudioEntity)
    // Construct/Deconstruct functions
    CAEAudioEntity() asm("psdk_ctor_CAEAudioEntity_inline");
    static inline __attribute__((used, visibility("hidden"))) PSDK_LIFETIME_RET(ThisClass) NativeCtor_CAEAudioEntity(ThisClass* _psdkSelf)
        asm("psdk_ctor_CAEAudioEntity_inline")
    {
        *(uptr**)_psdkSelf = GetMainLibrarySymbol<uptr*>("_ZTV14CAEAudioEntity") + 2;
        _psdkSelf->m_tempSound.m_pPhysicalEntity = NULL;
        PSDK_LIFETIME_RETURN(_psdkSelf);
    }
    DECL_DTORCALL(CAEAudioEntity, _ZN14CAEAudioEntityD2Ev);

    CEntity *m_pEntity;
    CAESound m_tempSound;
    DECL_VIRTUALCALL_HEAD(CAEAudioEntity, UpdateParameters, _ZTV14CAEAudioEntity, 0, void, CAESound *pSound, short PlayPosition)
    DECL_VIRTUALCALL_TAIL(pSound, PlayPosition)

    // STATIC values
    DECL_OBJECT_PLT(i8*, m_pAudioEventVolumes, BYBIT(0x67605C, 0x84A128));
DECL_CLASS_END()
CHECKSIZE(CAEAudioEntity, 0x7C, 0x90);



DECL_CLASS_BASED(CAETwinLoopSoundEntity, CAEAudioEntity)
    // Construct/Deconstruct functions
    CAETwinLoopSoundEntity() asm("psdk_ctor_CAETwinLoopSoundEntity_inline");
    static inline __attribute__((used, visibility("hidden"))) PSDK_LIFETIME_RET(ThisClass) NativeCtor_CAETwinLoopSoundEntityDefault(ThisClass* _psdkSelf)
        asm("psdk_ctor_CAETwinLoopSoundEntity_inline")
    {
        *(uptr**)_psdkSelf = GetMainLibrarySymbol<uptr*>("_ZTV22CAETwinLoopSoundEntity") + 2;
        _psdkSelf->m_tempSound.m_pPhysicalEntity = NULL;
        _psdkSelf->m_bIsInitialised = 0;
        _psdkSelf->m_apSounds[0] = NULL;
        _psdkSelf->m_apSounds[1] = NULL;
        PSDK_LIFETIME_RETURN(_psdkSelf);
    }
    DECL_CTORCALL_ARG_HEAD(CAETwinLoopSoundEntity, _ZN22CAETwinLoopSoundEntityC2EsssP14CAEAudioEntityttss, i16 BankSlotID, i16 FirstSoundID, i16 SecondSoundID, CAEAudioEntity* pAudioEntity, u16 MinSwapTime, u16 MaxSwapTime, i16 StartPercentFirst, i16 StartPercentSecond)
    DECL_CTORCALL_ARG_TAIL(BankSlotID, FirstSoundID, SecondSoundID, pAudioEntity, MinSwapTime, MaxSwapTime, StartPercentFirst, StartPercentSecond)
    DECL_DTORCALL(CAETwinLoopSoundEntity, _ZN22CAETwinLoopSoundEntityD2Ev);

    short           m_nBankSlotId;
    short           m_nSoundType[2];
    CAEAudioEntity *m_pBaseAudio;
    unsigned short  m_bIsInitialised;
    short           m_nFirstLength;
    short           m_nSecondLength;
    unsigned short  m_nPlayTimeMin;
    unsigned short  m_nPlayTimeMax;
    unsigned int    m_nTimeToSwapSounds;
    unsigned char   m_bPlayingFirstSound;
    short           m_anStartingPlayPercentage[2];
    CAESound       *m_apSounds[2];

    // Member functions
    DECL_THISCALL_HEAD(Initialise, _ZN22CAETwinLoopSoundEntity10InitialiseEsssP14CAEAudioEntityttss, void, i16 BankSlotID, i16 FirstSoundID, i16 SecondSoundID, CAEAudioEntity* pAudioEntity, u16 MinSwapTime, u16 MaxSwapTime, i16 StartPercentFirst, i16 StartPercentSecond)
    DECL_THISCALL_TAIL(Initialise, BankSlotID, FirstSoundID, SecondSoundID, pAudioEntity, MinSwapTime, MaxSwapTime, StartPercentFirst, StartPercentSecond)
    DECL_THISCALL_SIMPLE(StopSound, _ZN22CAETwinLoopSoundEntity9StopSoundEv, void);
    DECL_THISCALL_SIMPLE(StopSoundAndForget, _ZN22CAETwinLoopSoundEntity18StopSoundAndForgetEv, void);
    DECL_THISCALL_SIMPLE(IsTwinLoopPlaying, _ZN22CAETwinLoopSoundEntity17IsTwinLoopPlayingEv, u8);
    DECL_THISCALL_HEAD(SetEmittedVolume, _ZN22CAETwinLoopSoundEntity16SetEmittedVolumeEf, void, float ev)
    DECL_THISCALL_TAIL(SetEmittedVolume, ev)
    DECL_THISCALL_SIMPLE(GetEmittedVolume, _ZN22CAETwinLoopSoundEntity16GetEmittedVolumeEv, float);
    DECL_THISCALL_HEAD(PlayTwinLoopSound, _ZN22CAETwinLoopSoundEntity17PlayTwinLoopSoundE7CVectorfffft, void, CVector Position, float Volume, float RelativeFrequency, float RollOffFactor, float Doppler, u16 Environment)
    DECL_THISCALL_TAIL(PlayTwinLoopSound, Position, Volume, RelativeFrequency, RollOffFactor, Doppler, Environment)
    DECL_THISCALL_HEAD(UpdateTwinLoopSound, _ZN22CAETwinLoopSoundEntity19UpdateTwinLoopSoundE7CVectorff, void, CVector Position, float Volume, float RelativeFrequency)
    DECL_THISCALL_TAIL(UpdateTwinLoopSound, Position, Volume, RelativeFrequency)
    DECL_THISCALL_SIMPLE(SwapSounds, _ZN22CAETwinLoopSoundEntity10SwapSoundsEv, void);
    DECL_THISCALL_SIMPLE(DoSoundsSwitchThisFrame, _ZN22CAETwinLoopSoundEntity23DoSoundsSwitchThisFrameEv, u8);
DECL_CLASS_END()
CHECKSIZE(CAETwinLoopSoundEntity, 0xA8, 0xC8);



DECL_CLASS_BASED(CAEPedAudioEntity, CAEAudioEntity)
    CAEPedAudioEntity() = delete;

    // STATIC functions
    DECL_FASTCALL_SIMPLE(StaticInitialise, _ZN17CAEPedAudioEntity16StaticInitialiseEv, void);

    unsigned char m_bInitialised;
    short m_nLastSwimSplashSoundId;
    unsigned int m_nLastSwimWakeTriggerTimeMs;
    float m_fCurrentJetPackThrustVolume;
    float m_fCurrentJetPackGasVolume;
    float m_fCurrentJetPackRoarVolume;
    float m_fCurrentJetPackRoarFrequency;
    CPed *m_pPed;
    unsigned char m_bJetpackOn;
    CAESound *m_pJetPackThrustSound;
    CAESound *m_pJetPackGasSound;
    CAESound *m_pJetPackRoarSound;
    CAETwinLoopSoundEntity TwinLoopSoundEntity;
    CAESound *m_pWindRushSound;
    float m_fCurrentWindRushVolume;
    float m_fCurrentShirtFlapVolume;

    // Member functions
    DECL_THISCALL_HEAD(AddAudioEvent, _ZN17CAEPedAudioEntity13AddAudioEventEiffP9CPhysicalhij, void, i32 AudioEvent, float fVolumeOffsetdB, float fRelativeFrequency, CPhysical* pTargetPhysical, u8 TargetSurfaceType, i32 SecondaryAudioEvent, u32 PlayDelayMs)
    DECL_THISCALL_TAIL(AddAudioEvent, AudioEvent, fVolumeOffsetdB, fRelativeFrequency, pTargetPhysical, TargetSurfaceType, SecondaryAudioEvent, PlayDelayMs)
    DECL_THISCALL_SIMPLE(Service, _ZN17CAEPedAudioEntity7ServiceEv, void);
    DECL_THISCALL_SIMPLE(TurnOnJetPack, _ZN17CAEPedAudioEntity13TurnOnJetPackEv, void);
    DECL_THISCALL_SIMPLE(TurnOffJetPack, _ZN17CAEPedAudioEntity14TurnOffJetPackEv, void);
    DECL_THISCALL_HEAD(UpdateJetPack, _ZN17CAEPedAudioEntity13UpdateJetPackEff, void, float fThrust, float fAngle)
    DECL_THISCALL_TAIL(UpdateJetPack, fThrust, fAngle)
    DECL_THISCALL_SIMPLE(StopJetPackSound, _ZN17CAEPedAudioEntity16StopJetPackSoundEv, void);
    DECL_THISCALL_HEAD(Initialise, _ZN17CAEPedAudioEntity10InitialiseEP7CEntity, void, CEntity* pPed)
    DECL_THISCALL_TAIL(Initialise, pPed)
    DECL_THISCALL_SIMPLE(Terminate, _ZN17CAEPedAudioEntity9TerminateEv, void);
    DECL_THISCALL_HEAD(HandleFootstepEvent, _ZN17CAEPedAudioEntity19HandleFootstepEventEiffh, void, i32 AudioEvent, float fVolumeOffsetdB, float fRelativeFrequency, u8 ForcedSurfaceType)
    DECL_THISCALL_TAIL(HandleFootstepEvent, AudioEvent, fVolumeOffsetdB, fRelativeFrequency, ForcedSurfaceType)
    DECL_THISCALL_HEAD(HandleSkateEvent, _ZN17CAEPedAudioEntity16HandleSkateEventEiff, void, i32 AudioEvent, float fVolumeOffsetdB, float fRelativeFrequency)
    DECL_THISCALL_TAIL(HandleSkateEvent, AudioEvent, fVolumeOffsetdB, fRelativeFrequency)
    DECL_THISCALL_HEAD(HandleLandingEvent, _ZN17CAEPedAudioEntity18HandleLandingEventEi, void, i32 AudioEvent)
    DECL_THISCALL_TAIL(HandleLandingEvent, AudioEvent)
    DECL_THISCALL_HEAD(HandlePedSwing, _ZN17CAEPedAudioEntity14HandlePedSwingEiij, void, i32 AudioEvent, i32 SecondaryAudioEvent, u32 PlayDelayMs)
    DECL_THISCALL_TAIL(HandlePedSwing, AudioEvent, SecondaryAudioEvent, PlayDelayMs)
    DECL_THISCALL_HEAD(HandlePedHit, _ZN17CAEPedAudioEntity12HandlePedHitEiP9CPhysicalhfj, void, i32 AudioEvent, CPhysical* pTargetPhysical, u8 TargetSurfaceType, float fVolumeOffsetdB, u32 PlayDelayMs)
    DECL_THISCALL_TAIL(HandlePedHit, AudioEvent, pTargetPhysical, TargetSurfaceType, fVolumeOffsetdB, PlayDelayMs)
    DECL_THISCALL_HEAD(HandlePedJacked, _ZN17CAEPedAudioEntity15HandlePedJackedEi, void, i32 AudioEvent)
    DECL_THISCALL_TAIL(HandlePedJacked, AudioEvent)
    DECL_THISCALL_HEAD(HandleSwimSplash, _ZN17CAEPedAudioEntity16HandleSwimSplashEi, void, i32 AudioEvent)
    DECL_THISCALL_TAIL(HandleSwimSplash, AudioEvent)
    DECL_THISCALL_HEAD(HandleSwimWake, _ZN17CAEPedAudioEntity14HandleSwimWakeEi, void, i32 AudioEvent)
    DECL_THISCALL_TAIL(HandleSwimWake, AudioEvent)
    DECL_THISCALL_HEAD(PlayWindRush, _ZN17CAEPedAudioEntity12PlayWindRushEff, void, float fVolume, float fFrequency)
    DECL_THISCALL_TAIL(PlayWindRush, fVolume, fFrequency)
    DECL_THISCALL_HEAD(PlayShirtFlap, _ZN17CAEPedAudioEntity13PlayShirtFlapEff, void, float fVolume, float fFrequency)
    DECL_THISCALL_TAIL(PlayShirtFlap, fVolume, fFrequency)
DECL_CLASS_END()
CHECKSIZE(CAEPedAudioEntity, 0x15C, 0x1A8);



DECL_CLASS_BASED(CAEPedSpeechAudioEntity, CAEAudioEntity)
    // Construct/Deconstruct functions
    DECL_CTORCALL(CAEPedSpeechAudioEntity, _ZN23CAEPedSpeechAudioEntityC2Ev);
    ~CAEPedSpeechAudioEntity() asm("psdk_dtor_CAEPedSpeechAudioEntity_inline");
    static inline __attribute__((used, visibility("hidden"))) PSDK_LIFETIME_RET(ThisClass) NativeDtor_CAEPedSpeechAudioEntity(ThisClass* _psdkSelf)
        asm("psdk_dtor_CAEPedSpeechAudioEntity_inline")
    {
        CAEAudioEntity::FuncProxy_dtorCAEAudioEntity(_psdkSelf);
        PSDK_LIFETIME_RETURN(_psdkSelf);
    }

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(CAEPedSpeechAudioEntity, AddScriptSayEvent, _ZTV23CAEPedSpeechAudioEntity, 1, void, i32 audioEvent, i32 pedContext, u8 overrideSilence, u8 forceAudible, u8 frontEnd)
    DECL_VIRTUALCALL_TAIL(audioEvent, pedContext, overrideSilence, forceAudible, frontEnd)
    DECL_VIRTUALCALL_HEAD(CAEPedSpeechAudioEntity, Terminate, _ZTV23CAEPedSpeechAudioEntity, 2, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CAEPedSpeechAudioEntity, PlayLoadedSound, _ZTV23CAEPedSpeechAudioEntity, 3, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CAEPedSpeechAudioEntity, GetAllocatedVoice, _ZTV23CAEPedSpeechAudioEntity, 4, i16)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CAEPedSpeechAudioEntity, WillPedChatAboutTopic, _ZTV23CAEPedSpeechAudioEntity, 5, u8, i16 topic)
    DECL_VIRTUALCALL_TAIL(topic)
    DECL_VIRTUALCALL_HEAD(CAEPedSpeechAudioEntity, GetPedType, _ZTV23CAEPedSpeechAudioEntity, 6, i16)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CAEPedSpeechAudioEntity, IsPedFemaleForAudio, _ZTV23CAEPedSpeechAudioEntity, 7, u8)
    DECL_VIRTUALCALL_TAIL()

    // STATIC functions
    DECL_FASTCALL_SIMPLE(StaticInitialise, _ZN23CAEPedSpeechAudioEntity16StaticInitialiseEv, void);
    DECL_FASTCALL_SIMPLE(Service, _ZN23CAEPedSpeechAudioEntity7ServiceEv, void);
    DECL_FASTCALL_SIMPLE(Reset, _ZN23CAEPedSpeechAudioEntity5ResetEv, void);
    DECL_FASTCALL_SIMPLE(RequestPedConversation, _ZN23CAEPedSpeechAudioEntity22RequestPedConversationEP4CPedS1_, u8, CPed* pPed1, CPed* pPed2);
    DECL_FASTCALL_SIMPLE(ReleasePedConversation, _ZN23CAEPedSpeechAudioEntity22ReleasePedConversationEv, void);
    DECL_FASTCALL_SIMPLE(ReservePedConversationSpeechSlots, _ZN23CAEPedSpeechAudioEntity33ReservePedConversationSpeechSlotsEv, u8);
    DECL_FASTCALL_SIMPLE(SetUpConversation, _ZN23CAEPedSpeechAudioEntity17SetUpConversationEv, void);
    DECL_FASTCALL_SIMPLE(RequestPlayerConversation, _ZN23CAEPedSpeechAudioEntity25RequestPlayerConversationEP4CPed, u8, CPed* pPed);
    DECL_FASTCALL_SIMPLE(ReleasePlayerConversation, _ZN23CAEPedSpeechAudioEntity25ReleasePlayerConversationEv, void);
    DECL_FASTCALL_SIMPLE(ReservePlayerConversationSpeechSlot, _ZN23CAEPedSpeechAudioEntity35ReservePlayerConversationSpeechSlotEv, u8);
    DECL_FASTCALL_SIMPLE(GetAudioPedType, _ZN23CAEPedSpeechAudioEntity15GetAudioPedTypeEPc, i16, char* pString);
    DECL_FASTCALL_SIMPLE(GetVoice, _ZN23CAEPedSpeechAudioEntity8GetVoiceEPcs, i16, char* pString, i16 AudioPedType);
    DECL_FASTCALL_SIMPLE(DisableAllPedSpeech, _ZN23CAEPedSpeechAudioEntity19DisableAllPedSpeechEv, void);
    DECL_FASTCALL_SIMPLE(EnableAllPedSpeech, _ZN23CAEPedSpeechAudioEntity18EnableAllPedSpeechEv, void);
    DECL_FASTCALL_SIMPLE(GetCurrentCJMood, _ZN23CAEPedSpeechAudioEntity16GetCurrentCJMoodEv, i16);
    DECL_FASTCALL_SIMPLE(SetCJMood, _ZN23CAEPedSpeechAudioEntity9SetCJMoodEsjsss, void, i16 nBasicMood, u32 nTimeInMilliseconds, i16 nGangBanging, i16 nFat, i16 nWellDressed);
    DECL_FASTCALL_SIMPLE(IsCJDressedInForGangSpeech, _ZN23CAEPedSpeechAudioEntity26IsCJDressedInForGangSpeechEv, u8);

    // STATIC values
    typedef i16 ts_ConversationRow[2];
    DECL_OBJECT_ARRAY_PLT(ts_ConversationRow, s_Conversation, BYBIT(0x6782C4, 0x84E5A0));
    DECL_VALUE_PLT_I16(s_ConversationLength, BYBIT(0x675F2C, 0x849EC8));
    DECL_VALUE_PLT_U8(s_bForceAudible, BYBIT(0x6761AC, 0x84A3B8));
    typedef i16 ts_PhraseMemoryRow[2];
    DECL_OBJECT_ARRAY_PLT(ts_PhraseMemoryRow, s_PhraseMemory, BYBIT(0x678258, 0x84E4C8));
    DECL_VALUE_PLT_I16(s_NextSpeechSlot, BYBIT(0x679308, 0x850628));
    DECL_OBJECT_PLT(CPed*, s_pConversationPed1, BYBIT(0x6770F8, 0x84C228));
    DECL_OBJECT_PLT(CPed*, s_pConversationPed2, BYBIT(0x678F44, 0x84FEB0));
    DECL_VALUE_PLT_I16(s_pConversationPedSlot1, BYBIT(0x676374, 0x84A740));
    DECL_VALUE_PLT_I16(s_pConversationPedSlot2, BYBIT(0x676D9C, 0x84BB80));
    DECL_OBJECT_PLT(CPed*, s_pPlayerConversationPed, BYBIT(0x6766DC, 0x84AE10));
    DECL_VALUE_PLT_U8(s_bPedConversationHappening, BYBIT(0x678928, 0x84F270));
    DECL_VALUE_PLT_U8(s_bPlayerConversationHappening, BYBIT(0x677ADC, 0x84D5E0));
    DECL_VALUE_PLT_U8(s_bAllSpeechDisabled, BYBIT(0x678468, 0x84E8E8));
    DECL_VALUE_PLT_U8(s_bAPlayerSpeaking, BYBIT(0x678390, 0x84E738));
    DECL_VALUE_PLT_U32(s_nCJMoodOverrideTime, BYBIT(0x679138, 0x850298));
    DECL_VALUE_PLT_I16(s_nCJBasicMood, BYBIT(0x6762F8, 0x84A650));
    DECL_VALUE_PLT_I16(s_nCJGangBanging, BYBIT(0x67705C, 0x84C0F0));
    DECL_VALUE_PLT_I16(s_nCJFat, BYBIT(0x679A54, 0x8514C8));
    DECL_VALUE_PLT_I16(s_nCJWellDressed, BYBIT(0x676340, 0x84A6D8));

    // Member functions
    DECL_THISCALL_HEAD(AddSayEvent, _ZN23CAEPedSpeechAudioEntity11AddSayEventEisjfhhh, i16, i32 AudioEvent, i16 GlobalSpeechContext, u32 StartTimeDelay, float Probability, u8 OverideSilence, u8 bForceAudible, u8 bFrontEnd)
    DECL_THISCALL_TAIL(AddSayEvent, AudioEvent, GlobalSpeechContext, StartTimeDelay, Probability, OverideSilence, bForceAudible, bFrontEnd)
    DECL_THISCALL_HEAD(Initialise, _ZN23CAEPedSpeechAudioEntity10InitialiseEP7CEntity, void, CEntity* ped)
    DECL_THISCALL_TAIL(Initialise, ped)
    DECL_THISCALL_SIMPLE(GetPedTalking, _ZN23CAEPedSpeechAudioEntity13GetPedTalkingEv, u8);
    DECL_THISCALL_HEAD(DisablePedSpeech, _ZN23CAEPedSpeechAudioEntity16DisablePedSpeechEs, void, i16 Curtail)
    DECL_THISCALL_TAIL(DisablePedSpeech, Curtail)
    DECL_THISCALL_SIMPLE(EnablePedSpeech, _ZN23CAEPedSpeechAudioEntity15EnablePedSpeechEv, void);
    DECL_THISCALL_HEAD(DisablePedSpeechForScriptSpeech, _ZN23CAEPedSpeechAudioEntity31DisablePedSpeechForScriptSpeechEs, void, i16 Curtail)
    DECL_THISCALL_TAIL(DisablePedSpeechForScriptSpeech, Curtail)
    DECL_THISCALL_SIMPLE(EnablePedSpeechForScriptSpeech, _ZN23CAEPedSpeechAudioEntity30EnablePedSpeechForScriptSpeechEv, void);
    DECL_THISCALL_SIMPLE(CanPedHoldConversation, _ZN23CAEPedSpeechAudioEntity22CanPedHoldConversationEv, u8);
    DECL_THISCALL_SIMPLE(StopCurrentSpeech, _ZN23CAEPedSpeechAudioEntity17StopCurrentSpeechEv, void);
    DECL_THISCALL_HEAD(GetVoiceAndTypeFromModel, _ZN23CAEPedSpeechAudioEntity24GetVoiceAndTypeFromModelEi, u8, i32 iModel)
    DECL_THISCALL_TAIL(GetVoiceAndTypeFromModel, iModel)
    DECL_THISCALL_HEAD(GetVoiceAndTypeForSpecialPed, _ZN23CAEPedSpeechAudioEntity28GetVoiceAndTypeForSpecialPedEj, u8, u32 HashKey)
    DECL_THISCALL_TAIL(GetVoiceAndTypeForSpecialPed, HashKey)
    DECL_THISCALL_HEAD(GetSexFromModel, _ZN23CAEPedSpeechAudioEntity15GetSexFromModelEi, u8, i32 iModel)
    DECL_THISCALL_TAIL(GetSexFromModel, iModel)
    DECL_THISCALL_HEAD(GetSexForSpecialPed, _ZN23CAEPedSpeechAudioEntity19GetSexForSpecialPedEj, u8, u32 HashKey)
    DECL_THISCALL_TAIL(GetSexForSpecialPed, HashKey)
    DECL_THISCALL_HEAD(LoadAndPlaySpeech, _ZN23CAEPedSpeechAudioEntity17LoadAndPlaySpeechEj, void, u32 StartTimeDelay)
    DECL_THISCALL_TAIL(LoadAndPlaySpeech, StartTimeDelay)
    DECL_THISCALL_HEAD(GetSoundAndBankIDs, _ZN23CAEPedSpeechAudioEntity18GetSoundAndBankIDsEsPs, i16, i16 GlobalSpeechContext, i16* pSpecificSpeechContext)
    DECL_THISCALL_TAIL(GetSoundAndBankIDs, GlobalSpeechContext, pSpecificSpeechContext)
    DECL_THISCALL_HEAD(GetSoundAndBankIDsForScriptedSpeech, _ZN23CAEPedSpeechAudioEntity35GetSoundAndBankIDsForScriptedSpeechEi, u8, i32 ScriptID)
    DECL_THISCALL_TAIL(GetSoundAndBankIDsForScriptedSpeech, ScriptID)
    DECL_THISCALL_HEAD(GetSpecificSpeechContext, _ZN23CAEPedSpeechAudioEntity24GetSpecificSpeechContextEss, i16, i16 GlobalSpeechContext, i16 m_PedType)
    DECL_THISCALL_TAIL(GetSpecificSpeechContext, GlobalSpeechContext, m_PedType)
    DECL_THISCALL_HEAD(IsGlobalContextPain, _ZN23CAEPedSpeechAudioEntity19IsGlobalContextPainEs, u8, i16 GlobalSpeechContext)
    DECL_THISCALL_TAIL(IsGlobalContextPain, GlobalSpeechContext)
    DECL_THISCALL_HEAD(IsGlobalContextImportantForStreaming, _ZN23CAEPedSpeechAudioEntity36IsGlobalContextImportantForStreamingEs, u8, i16 GlobalContext)
    DECL_THISCALL_TAIL(IsGlobalContextImportantForStreaming, GlobalContext)
    DECL_THISCALL_HEAD(IsGlobalContextImportantForWidescreen, _ZN23CAEPedSpeechAudioEntity37IsGlobalContextImportantForWidescreenEs, u8, i16 GlobalContext)
    DECL_THISCALL_TAIL(IsGlobalContextImportantForWidescreen, GlobalContext)
    DECL_THISCALL_HEAD(IsGlobalContextImportantForInterupting, _ZN23CAEPedSpeechAudioEntity38IsGlobalContextImportantForInteruptingEs, u8, i16 GlobalContext)
    DECL_THISCALL_TAIL(IsGlobalContextImportantForInterupting, GlobalContext)
    DECL_THISCALL_HEAD(IsGlobalContextUberImportant, _ZN23CAEPedSpeechAudioEntity28IsGlobalContextUberImportantEs, u8, i16 GlobalContext)
    DECL_THISCALL_TAIL(IsGlobalContextUberImportant, GlobalContext)
    DECL_THISCALL_HEAD(GetRepeatTime, _ZN23CAEPedSpeechAudioEntity13GetRepeatTimeEs, i16, i16 GlobalSpeechContext)
    DECL_THISCALL_TAIL(GetRepeatTime, GlobalSpeechContext)
    DECL_THISCALL_HEAD(CanWePlayGlobalSpeechContext, _ZN23CAEPedSpeechAudioEntity28CanWePlayGlobalSpeechContextEs, i16, i16 GlobalSpeechContext)
    DECL_THISCALL_TAIL(CanWePlayGlobalSpeechContext, GlobalSpeechContext)
    DECL_THISCALL_HEAD(CanPedSayGlobalContext, _ZN23CAEPedSpeechAudioEntity22CanPedSayGlobalContextEs, u8, i16 GlobalContext)
    DECL_THISCALL_TAIL(CanPedSayGlobalContext, GlobalContext)
    DECL_THISCALL_SIMPLE(CanWePlayScriptedSpeech, _ZN23CAEPedSpeechAudioEntity23CanWePlayScriptedSpeechEv, i16);
    DECL_THISCALL_HEAD(GetNumSlotsPlayingContext, _ZN23CAEPedSpeechAudioEntity25GetNumSlotsPlayingContextEs, i16, i16 GlobalSpeechContext)
    DECL_THISCALL_TAIL(GetNumSlotsPlayingContext, GlobalSpeechContext)
    DECL_THISCALL_HEAD(GetNextPlayTime, _ZN23CAEPedSpeechAudioEntity15GetNextPlayTimeEs, u32, i16 GlobalSpeechContext)
    DECL_THISCALL_TAIL(GetNextPlayTime, GlobalSpeechContext)
    DECL_THISCALL_HEAD(SetNextPlayTime, _ZN23CAEPedSpeechAudioEntity15SetNextPlayTimeEs, void, i16 GlobalSpeechContext)
    DECL_THISCALL_TAIL(SetNextPlayTime, GlobalSpeechContext)
    DECL_THISCALL_HEAD(GetNextMoodToUse, _ZN23CAEPedSpeechAudioEntity16GetNextMoodToUseEs, i16, i16 LastMood)
    DECL_THISCALL_TAIL(GetNextMoodToUse, LastMood)
    DECL_THISCALL_HEAD(GetVoiceForMood, _ZN23CAEPedSpeechAudioEntity15GetVoiceForMoodEs, i16, i16 Mood)
    DECL_THISCALL_TAIL(GetVoiceForMood, Mood)
    DECL_THISCALL_HEAD(GetSpeechContextVolumeOffset, _ZN23CAEPedSpeechAudioEntity28GetSpeechContextVolumeOffsetEs, float, i16 GlobalSpeechContext)
    DECL_THISCALL_TAIL(GetSpeechContextVolumeOffset, GlobalSpeechContext)

    // Member values
    CAESound* m_aSounds[5];
    unsigned char m_bInitialised;
    short m_nVoiceType; // see eAudioPedType
    short m_nVoiceID;
    short m_nVoiceGender;
    unsigned char m_bTalking;
    unsigned char m_bEnableVocalType;
    unsigned char m_bMuted;
    union
    {
        unsigned char m_bFrontEnd;
        unsigned char m_nVocalEnableFlag;
    };
    unsigned char m_bForceAudible;
    CAESound *m_pSound;
    short m_nSoundId;
    short m_nBankId;
    short m_nPedSpeechSlotIndex;
    float m_fVoiceVolume;
    short m_nCurrentPhraseId;
    unsigned int m_NextTimeCanSayPain[19];
    DECL_OBJECT_ARRAY_PLT(CAEPedSpeechSlot, s_PedSpeechSlots, BYBIT(0x677944, 0x84D2B0));
DECL_CLASS_END()
CHECKSIZE(CAEPedSpeechAudioEntity, 0x100, 0x130);



DECL_CLASS_BASED(CAEWeaponAudioEntity, CAEAudioEntity)
    CAEWeaponAudioEntity() = delete;

    // Member functions
    DECL_THISCALL_SIMPLE(Initialise, _ZN20CAEWeaponAudioEntity10InitialiseEv, void);
    DECL_THISCALL_SIMPLE(Terminate, _ZN20CAEWeaponAudioEntity9TerminateEv, void);
    DECL_THISCALL_SIMPLE(Reset, _ZN20CAEWeaponAudioEntity5ResetEv, void);
    DECL_THISCALL_HEAD(WeaponFire, _ZN20CAEWeaponAudioEntity10WeaponFireE11eWeaponTypeP9CPhysicali, void, eWeaponType weaptype, CPhysical* entity, i32 AudioEventId)
    DECL_THISCALL_TAIL(WeaponFire, weaptype, entity, AudioEventId)
    DECL_THISCALL_HEAD(WeaponReload, _ZN20CAEWeaponAudioEntity12WeaponReloadE11eWeaponTypeP9CPhysicali, void, eWeaponType weaptype, CPhysical* entity, i32 AudioEventId)
    DECL_THISCALL_TAIL(WeaponReload, weaptype, entity, AudioEventId)
    DECL_THISCALL_HEAD(PlayFlameThrowerIdleGasLoop, _ZN20CAEWeaponAudioEntity27PlayFlameThrowerIdleGasLoopEP9CPhysical, void, CPhysical* entity)
    DECL_THISCALL_TAIL(PlayFlameThrowerIdleGasLoop, entity)
    DECL_THISCALL_SIMPLE(StopFlameThrowerIdleGasLoop, _ZN20CAEWeaponAudioEntity27StopFlameThrowerIdleGasLoopEv, void);
    DECL_THISCALL_HEAD(ReportChainsawEvent, _ZN20CAEWeaponAudioEntity19ReportChainsawEventEP9CPhysicali, void, CPhysical* entity, i32 AudioEventId)
    DECL_THISCALL_TAIL(ReportChainsawEvent, entity, AudioEventId)
    DECL_THISCALL_HEAD(ReportStealthKill, _ZN20CAEWeaponAudioEntity17ReportStealthKillE11eWeaponTypeP9CPhysicali, void, eWeaponType weaptype, CPhysical* entity, i32 AudioEventId)
    DECL_THISCALL_TAIL(ReportStealthKill, weaptype, entity, AudioEventId)
    DECL_THISCALL_HEAD(PlayGunSounds, _ZN20CAEWeaponAudioEntity13PlayGunSoundsEP9CPhysicalsssssifff, void, CPhysical* entity, i16 emptySfxId, i16 farSfxId2, i16 highPitchSfxId3, i16 lowPitchSfxId4, i16 echoSfxId5, i32 nAudioEventId, float volumeChange, float speed1, float speed2)
    DECL_THISCALL_TAIL(PlayGunSounds, entity, emptySfxId, farSfxId2, highPitchSfxId3, lowPitchSfxId4, echoSfxId5, nAudioEventId, volumeChange, speed1, speed2)
    DECL_THISCALL_HEAD(PlayFlameThrowerSounds, _ZN20CAEWeaponAudioEntity22PlayFlameThrowerSoundsEP9CPhysicalssiff, void, CPhysical* entity, i16 sfx1, i16 sfx2, i32 AudioEventId, float audability, float speed)
    DECL_THISCALL_TAIL(PlayFlameThrowerSounds, entity, sfx1, sfx2, AudioEventId, audability, speed)
    DECL_THISCALL_HEAD(PlayWeaponLoopSound, _ZN20CAEWeaponAudioEntity19PlayWeaponLoopSoundEP9CPhysicalsiffi, void, CPhysical* arg0, i16 sfxId, i32 AudioEventId, float audability, float speed, i32 finalEvent)
    DECL_THISCALL_TAIL(PlayWeaponLoopSound, arg0, sfxId, AudioEventId, audability, speed, finalEvent)
    DECL_THISCALL_HEAD(PlayCameraSound, _ZN20CAEWeaponAudioEntity15PlayCameraSoundEP9CPhysicalif, void, CPhysical* entity, i32 AudioEventId, float audability)
    DECL_THISCALL_TAIL(PlayCameraSound, entity, AudioEventId, audability)
    DECL_THISCALL_HEAD(PlayMiniGunFireSounds, _ZN20CAEWeaponAudioEntity21PlayMiniGunFireSoundsEP9CPhysicali, void, CPhysical* entity, i32 AudioEventId)
    DECL_THISCALL_TAIL(PlayMiniGunFireSounds, entity, AudioEventId)
    DECL_THISCALL_HEAD(PlayMiniGunStopSound, _ZN20CAEWeaponAudioEntity20PlayMiniGunStopSoundEP9CPhysical, void, CPhysical* entity)
    DECL_THISCALL_TAIL(PlayMiniGunStopSound, entity)
    DECL_THISCALL_HEAD(PlayChainsawStopSound, _ZN20CAEWeaponAudioEntity21PlayChainsawStopSoundEP9CPhysical, void, CPhysical* entity)
    DECL_THISCALL_TAIL(PlayChainsawStopSound, entity)
    DECL_THISCALL_HEAD(PlayGoggleSound, _ZN20CAEWeaponAudioEntity15PlayGoggleSoundEsi, void, i16 sfxId, i32 AudioEventId)
    DECL_THISCALL_TAIL(PlayGoggleSound, sfxId, AudioEventId)

    unsigned char m_bPlayedMiniGunFireSound;
    unsigned char m_bMiniGunFireActive;
    signed char m_nLastWeaponPlaneFrequencyIndex;
    signed char m_nState;
    signed char m_nChainsawSoundState;
    unsigned int m_dwFlameThrowerLastPlayedTime;
    unsigned int m_dwSpraycanLastPlayedTime;
    unsigned int m_dwExtinguisherLastPlayedTime;
    unsigned int m_dwMiniGunFireSoundPlayedTime;
    unsigned int m_dwTimeChainsaw;
    unsigned int m_dwTimeLastFired;
    CAESound *m_pSounds;
DECL_CLASS_END()
CHECKSIZE(CAEWeaponAudioEntity, 0xA0, 0xB8);



DECL_CLASS_BASED(CAEPedWeaponAudioEntity, CAEWeaponAudioEntity)
    CAEPedWeaponAudioEntity() = delete;

    // Member functions
    DECL_THISCALL_HEAD(AddAudioEvent, _ZN23CAEPedWeaponAudioEntity13AddAudioEventEi, void, i32 arg1)
    DECL_THISCALL_TAIL(AddAudioEvent, arg1)
    DECL_THISCALL_HEAD(Initialise, _ZN23CAEPedWeaponAudioEntity10InitialiseEP7CEntity, void, CEntity* pCEntity1)
    DECL_THISCALL_TAIL(Initialise, pCEntity1)
    DECL_THISCALL_SIMPLE(Terminate, _ZN23CAEPedWeaponAudioEntity9TerminateEv, void);
    DECL_THISCALL_SIMPLE(Service, _ZN23CAEPedWeaponAudioEntity7ServiceEv, void);

    unsigned char m_bActive;
    CPed* m_pPed;
DECL_CLASS_END()
CHECKSIZE(CAEPedWeaponAudioEntity, 0xA8, 0xC8);



enum eVehicleSoundType : signed char
{
    VEHICLE_SOUND_CAR = 0x0,
    VEHICLE_SOUND_MOTORCYCLE = 0x1,
    VEHICLE_SOUND_BICYCLE = 0x2,
    VEHICLE_SOUND_BOAT = 0x3,
    VEHICLE_SOUND_HELI = 0x4,
    VEHICLE_SOUND_PLANE = 0x5,
    VEHICLE_SOUND_NON_VEH = 0x6,
    VEHICLE_SOUND_USED_BY_NONE_VEH = 0x7,
    VEHICLE_SOUND_TRAIN = 0x8,
    VEHICLE_SOUND_TRAILER = 0x9,
    VEHICLE_SOUND_SPECIAL = 0xA,
};

enum eRadioType : signed char
{
    RADIO_CIVILIAN = 0x0,
    RADIO_SPECIAL = 0x1,
    RADIO_UNKNOWN = 0x2,
    RADIO_EMERGENCY = 0x3,
    RADIO_DISABLED = -1,
};

enum eRadioID : signed char
{
    RADIO_PLAYBACK_FM=1,
    RADIO_K_ROSE,
    RADIO_K_DST,     
    RADIO_BOUNCE_FM,
    RADIO_SF_UR,
    RADIO_LOS_SANTOS,
    RADIO_RADIO_X,
    RADIO_CSR_103_9,
    RADIO_K_JAH_WEST,
    RADIO_MASTER_SOUNDS_98_3,
    RADIO_WCTR,
    RADIO_USER_TRACKS,
    RADIO_NONE
};

struct tVehicleAudioSettings
{
    eVehicleSoundType  m_nVehicleSoundType;
    short m_nEngineOnSoundBankId;
    short m_nEngineOffSoundBankId;
    signed char m_nBassSetting;   // m_nStereo
    float m_fBassEq;
    float m_fEnginePitch;
    signed char m_bHornTon;   // sfx id
    float m_fHornHigh;
    signed char m_nDoorSound;
    signed char m_nEngineUpgrade;
    eRadioID m_nRadioID;
    eRadioType m_nRadioType;
    signed char vehTypeForAudio;
    float m_fHornVolumeDelta;
};

struct tVehicleSound
{
    short         m_nIndex;
    CAESound     *m_pSound;
};

DECL_CLASS_BASED(CAEVehicleAudioEntity, CAEAudioEntity)
    // Construct/Deconstruct functions
    DECL_CTORCALL(CAEVehicleAudioEntity, _ZN21CAEVehicleAudioEntityC2Ev);
    ~CAEVehicleAudioEntity() asm("psdk_dtor_CAEVehicleAudioEntity_inline");
    static inline __attribute__((used, visibility("hidden"))) PSDK_LIFETIME_RET(ThisClass) NativeDtor_CAEVehicleAudioEntity(ThisClass* _psdkSelf)
        asm("psdk_dtor_CAEVehicleAudioEntity_inline")
    {
        *(uptr**)_psdkSelf = GetMainLibrarySymbol<uptr*>("_ZTV21CAEVehicleAudioEntity") + 2;
        if(_psdkSelf->m_bEnabled) FuncProxy_Terminate(_psdkSelf);
        CAETwinLoopSoundEntity::FuncProxy_dtorCAETwinLoopSoundEntity(&_psdkSelf->m_skidSound);
        CAEAudioEntity::FuncProxy_dtorCAEAudioEntity(_psdkSelf);
        PSDK_LIFETIME_RETURN(_psdkSelf);
    }

    short                   m_nStallCounter;
    tVehicleAudioSettings   m_settings;
    unsigned char           m_bEnabled;
    unsigned char           m_bPlayerDriver;
    unsigned char           m_bPlayerPassenger;
    unsigned char           m_bVehicleRadioPaused;
    unsigned char           m_bSoundsStopped;
    signed char             m_nEngineState;
    unsigned char           m_nAudioGear;
    float                   m_CrzCount;
    unsigned char           m_bInhibitAccForLowSpeed;
    short                   m_nRainDropCounter;
    short                   m_nStalledCounter;
    unsigned int            m_nSwapStalledTime;
    unsigned char           m_bSilentStalled;
    unsigned char           m_bDisableHeliEngineSounds;
    unsigned char           m_bHornOn;
    unsigned char           m_bSirenOrAlarmPlaying;
    unsigned char           m_bHornPlaying;
    float                   m_fSirenVolume;
    unsigned char           m_bModelWithSiren;
    unsigned int            m_nBoatHitWaveLastPlayedTime;
    unsigned int            m_nTimeToInhibitAcc;
    unsigned int            m_nTimeToInhibitCrz;
    float                   m_fGeneralVehicleSoundVolume;
    short                   m_nEngineDecelerateSoundBankId;
    short                   m_nEngineAccelerateSoundBankId;
    short                   m_nEngineBankSlotId;
    tVehicleSound           m_aEngineSounds[12];
    unsigned int            m_TimeLastServiced;
    short                   m_ACPlayPositionThisFrame;
    short                   m_ACPlayPositionLastFrame;
    short                   m_FramesAgoACLooped;
    short                   m_ACPlayPercentWhenStopped;
    unsigned int            m_TimeACStopped;
    short                   m_ACPlayPositionWhenStopped;
    short                   m_nSkidSoundType;
    CAESound               *m_pSurfaceSound;
    short                   m_nRoadNoiseSoundType;
    CAESound               *m_pRoadNoiseSound;
    short                   m_nFlatTyreSoundType;
    CAESound               *m_pFlatTyreSound;
    short                   m_nReverseGearSoundType;
    CAESound               *m_pReverseGearSound;
    short                   m_nHornSoundType;
    CAESound               *m_pHornTonSound;
    CAESound               *m_pSirenSound;
    CAESound               *m_pPoliceSirenSound;
    CAETwinLoopSoundEntity  m_skidSound;
    float                   m_CurrentRotorFrequency;
    float                   m_CurrentDummyEngineVolume;
    float                   m_CurrenytDummyEngineFrequency;
    float                   m_fMovingPartSmoothedSpeed;
    float                   m_fFadeIn;
    float                   m_fFadeOut;
    unsigned char           m_bNitroSoundPresent;
    float                   m_CurrentNitroRadio;

    // STATIC functions
    DECL_FASTCALL_SIMPLE(StaticInitialise, _ZN21CAEVehicleAudioEntity16StaticInitialiseEv, void);
    DECL_FASTCALL_SIMPLE(StaticService, _ZN21CAEVehicleAudioEntity13StaticServiceEv, void);
    DECL_FASTCALL_SIMPLE(StaticGetPlayerVehicleAudioSettingsForRadio, _ZN21CAEVehicleAudioEntity43StaticGetPlayerVehicleAudioSettingsForRadioEv, tVehicleAudioSettings*);
    DECL_FASTCALL_SIMPLE(DisableHelicoptors, _ZN21CAEVehicleAudioEntity18DisableHelicoptorsEv, void);
    DECL_FASTCALL_SIMPLE(EnableHelicoptors, _ZN21CAEVehicleAudioEntity17EnableHelicoptorsEv, void);
    DECL_FASTCALL_SIMPLE(RequestBankSlot, _ZN21CAEVehicleAudioEntity15RequestBankSlotEs, i16, i16 BankId);
    DECL_FASTCALL_SIMPLE(StoppedUsingBankSlot, _ZN21CAEVehicleAudioEntity20StoppedUsingBankSlotEs, void, i16 AbsoluteBankSlotId);
    DECL_FASTCALL_SIMPLE(DoesBankSlotContainThisBank, _ZN21CAEVehicleAudioEntity27DoesBankSlotContainThisBankEss, u8, i16 AbsoluteBankSlotId, i16 DummyEngineBank);
    DECL_FASTCALL_SIMPLE(DemandBankSlot, _ZN21CAEVehicleAudioEntity14DemandBankSlotEs, i16, i16 BankId);

    // STATIC values
    DECL_OBJECT_PLT(CPlayerPed*, s_pPlayerDriver, BYBIT(0x677BDC, 0x84D7D8));
    DECL_OBJECT_PLT(CPlayerPed*, s_pPlayerAttachedForRadio, BYBIT(0x67837C, 0x84E710));
    DECL_OBJECT_PLT(tVehicleAudioSettings*, s_pVehicleAudioSettingsForRadio, BYBIT(0x675FA0, 0x849FB0));
    DECL_VALUE_PLT_I16(s_NextDummyEngineSlot, BYBIT(0x6766C8, 0x84ADE8));
    DECL_VALUE_PLT_U8(s_HelicoptorsDisabled, BYBIT(0x676D74, 0x84BB30));

    // Member functions
    DECL_THISCALL_NAMED_HEAD(AddAudioEvent1, AddAudioEvent, _ZN21CAEVehicleAudioEntity13AddAudioEventEif, void, i32 arg1, float arg2)
    DECL_THISCALL_TAIL(AddAudioEvent1, arg1, arg2)
    DECL_THISCALL_NAMED_HEAD(AddAudioEvent2, AddAudioEvent, _ZN21CAEVehicleAudioEntity13AddAudioEventEiP7CEntity, void, i32 AudioEvent, CEntity* pEntity)
    DECL_THISCALL_TAIL(AddAudioEvent2, AudioEvent, pEntity)
    DECL_THISCALL_HEAD(Initialise, _ZN21CAEVehicleAudioEntity10InitialiseEP7CEntity, void, CEntity* pVehicle)
    DECL_THISCALL_TAIL(Initialise, pVehicle)
    DECL_THISCALL_SIMPLE(Terminate, _ZN21CAEVehicleAudioEntity9TerminateEv, void);
    DECL_THISCALL_SIMPLE(Service, _ZN21CAEVehicleAudioEntity7ServiceEv, void);
    DECL_THISCALL_SIMPLE(GetVehicleTypeForAudio, _ZN21CAEVehicleAudioEntity22GetVehicleTypeForAudioEv, i16);
    DECL_THISCALL_SIMPLE(PlayerAboutToExitVehicleAsDriver, _ZN21CAEVehicleAudioEntity32PlayerAboutToExitVehicleAsDriverEv, void);
    DECL_THISCALL_SIMPLE(DisableHelicoptor, _ZN21CAEVehicleAudioEntity17DisableHelicoptorEv, void);
    DECL_THISCALL_SIMPLE(EnableHelicoptor, _ZN21CAEVehicleAudioEntity16EnableHelicoptorEv, void);
    DECL_THISCALL_SIMPLE(TurnOnRadioForVehicle, _ZN21CAEVehicleAudioEntity21TurnOnRadioForVehicleEv, void);
    DECL_THISCALL_SIMPLE(TurnOffRadioForVehicle, _ZN21CAEVehicleAudioEntity22TurnOffRadioForVehicleEv, void);
    DECL_THISCALL_HEAD(ProcessVehicle, _ZN21CAEVehicleAudioEntity14ProcessVehicleEP9CPhysical, void, CPhysical* pObject)
    DECL_THISCALL_TAIL(ProcessVehicle, pObject)
    DECL_THISCALL_HEAD(ProcessDummyVehicleEngine, _ZN21CAEVehicleAudioEntity25ProcessDummyVehicleEngineER14cVehicleParams, void, cVehicleParams& VehicleParams)
    DECL_THISCALL_TAIL(ProcessDummyVehicleEngine, VehicleParams)
    DECL_THISCALL_HEAD(ProcessPlayerVehicleEngine, _ZN21CAEVehicleAudioEntity26ProcessPlayerVehicleEngineER14cVehicleParams, void, cVehicleParams& vp)
    DECL_THISCALL_TAIL(ProcessPlayerVehicleEngine, vp)
    DECL_THISCALL_HEAD(ProcessDummyStateTransition, _ZN21CAEVehicleAudioEntity27ProcessDummyStateTransitionEsfR14cVehicleParams, void, i16 NewState, float fRatio, cVehicleParams& vp)
    DECL_THISCALL_TAIL(ProcessDummyStateTransition, NewState, fRatio, vp)
    DECL_THISCALL_HEAD(ProcessVehicleSkidding, _ZN21CAEVehicleAudioEntity22ProcessVehicleSkiddingER14cVehicleParams, void, cVehicleParams& VehicleParams)
    DECL_THISCALL_TAIL(ProcessVehicleSkidding, VehicleParams)
    DECL_THISCALL_HEAD(ProcessVehicleRoadNoise, _ZN21CAEVehicleAudioEntity23ProcessVehicleRoadNoiseER14cVehicleParams, void, cVehicleParams& VehicleParams)
    DECL_THISCALL_TAIL(ProcessVehicleRoadNoise, VehicleParams)
    DECL_THISCALL_HEAD(ProcessVehicleFlatTyre, _ZN21CAEVehicleAudioEntity22ProcessVehicleFlatTyreER14cVehicleParams, void, cVehicleParams& VehicleParams)
    DECL_THISCALL_TAIL(ProcessVehicleFlatTyre, VehicleParams)
    DECL_THISCALL_HEAD(ProcessReverseGear, _ZN21CAEVehicleAudioEntity18ProcessReverseGearER14cVehicleParams, void, cVehicleParams& VehicleParams)
    DECL_THISCALL_TAIL(ProcessReverseGear, VehicleParams)
    DECL_THISCALL_HEAD(CancelVehicleEngineSound, _ZN21CAEVehicleAudioEntity24CancelVehicleEngineSoundEs, void, i16 SoundType)
    DECL_THISCALL_TAIL(CancelVehicleEngineSound, SoundType)
    DECL_THISCALL_HEAD(UpdateVehicleEngineSound, _ZN21CAEVehicleAudioEntity24UpdateVehicleEngineSoundEsff, void, i16 SoundType, float Frequency, float VehicleRelativeVolume)
    DECL_THISCALL_TAIL(UpdateVehicleEngineSound, SoundType, Frequency, VehicleRelativeVolume)
    DECL_THISCALL_HEAD(StartVehicleEngineSound, _ZN21CAEVehicleAudioEntity23StartVehicleEngineSoundEsff, void, i16 SoundType, float Frequency, float Volume)
    DECL_THISCALL_TAIL(StartVehicleEngineSound, SoundType, Frequency, Volume)
    DECL_THISCALL_HEAD(GetVolumeForDummyIdle, _ZN21CAEVehicleAudioEntity21GetVolumeForDummyIdleEff, float, float fRatio, float fFadeRatio)
    DECL_THISCALL_TAIL(GetVolumeForDummyIdle, fRatio, fFadeRatio)
    DECL_THISCALL_HEAD(GetFrequencyForDummyIdle, _ZN21CAEVehicleAudioEntity24GetFrequencyForDummyIdleEff, float, float fRatio, float fFadeRatio)
    DECL_THISCALL_TAIL(GetFrequencyForDummyIdle, fRatio, fFadeRatio)
    DECL_THISCALL_HEAD(GetVolumeForDummyRev, _ZN21CAEVehicleAudioEntity20GetVolumeForDummyRevEff, float, float fRatio, float fFadeRatio)
    DECL_THISCALL_TAIL(GetVolumeForDummyRev, fRatio, fFadeRatio)
    DECL_THISCALL_HEAD(GetFrequencyForDummyRev, _ZN21CAEVehicleAudioEntity23GetFrequencyForDummyRevEff, float, float fRatio, float fFadeRatio)
    DECL_THISCALL_TAIL(GetFrequencyForDummyRev, fRatio, fFadeRatio)
    DECL_THISCALL_HEAD(PlaySkidSound, _ZN21CAEVehicleAudioEntity13PlaySkidSoundEsff, void, i16 SurfaceSoundID, float Frequency, float VehicleRelativeVolume)
    DECL_THISCALL_TAIL(PlaySkidSound, SurfaceSoundID, Frequency, VehicleRelativeVolume)
    DECL_THISCALL_HEAD(PlayRoadNoiseSound, _ZN21CAEVehicleAudioEntity18PlayRoadNoiseSoundEsff, void, i16 RoadNoiseSoundID, float Frequency, float VehicleRelativeVolume)
    DECL_THISCALL_TAIL(PlayRoadNoiseSound, RoadNoiseSoundID, Frequency, VehicleRelativeVolume)
    DECL_THISCALL_HEAD(PlayFlatTyreSound, _ZN21CAEVehicleAudioEntity17PlayFlatTyreSoundEsff, void, i16 FlatTyreSoundID, float Frequency, float VehicleRelativeVolume)
    DECL_THISCALL_TAIL(PlayFlatTyreSound, FlatTyreSoundID, Frequency, VehicleRelativeVolume)
    DECL_THISCALL_HEAD(PlayReverseSound, _ZN21CAEVehicleAudioEntity16PlayReverseSoundEsff, void, i16 ReverseSoundID, float Frequency, float VehicleRelativeVolume)
    DECL_THISCALL_TAIL(PlayReverseSound, ReverseSoundID, Frequency, VehicleRelativeVolume)
    DECL_THISCALL_HEAD(UpdateGasPedalAudio, _ZN21CAEVehicleAudioEntity19UpdateGasPedalAudioEP8CVehiclei, void, CVehicle* pVehicle, i32 nVehicleType)
    DECL_THISCALL_TAIL(UpdateGasPedalAudio, pVehicle, nVehicleType)
    DECL_THISCALL_HEAD(RequestNewPlayerCarEngineSound, _ZN21CAEVehicleAudioEntity30RequestNewPlayerCarEngineSoundEsff, i16, i16 SoundType, float Frequency, float VehicleRelativeVolume)
    DECL_THISCALL_TAIL(RequestNewPlayerCarEngineSound, SoundType, Frequency, VehicleRelativeVolume)
    DECL_THISCALL_SIMPLE(JustGotInVehicleAsDriver, _ZN21CAEVehicleAudioEntity24JustGotInVehicleAsDriverEv, void);
    DECL_THISCALL_SIMPLE(JustGotOutOfVehicleAsDriver, _ZN21CAEVehicleAudioEntity27JustGotOutOfVehicleAsDriverEv, void);
    DECL_THISCALL_SIMPLE(JustWreckedVehicle, _ZN21CAEVehicleAudioEntity18JustWreckedVehicleEv, void);
    DECL_THISCALL_SIMPLE(CopHeli, _ZN21CAEVehicleAudioEntity7CopHeliEv, u8);
    DECL_THISCALL_HEAD(GetAccelAndBrake, _ZN21CAEVehicleAudioEntity16GetAccelAndBrakeER14cVehicleParams, void, cVehicleParams& vp)
    DECL_THISCALL_TAIL(GetAccelAndBrake, vp)
    DECL_THISCALL_SIMPLE(JustFinishedAccelerationLoop, _ZN21CAEVehicleAudioEntity28JustFinishedAccelerationLoopEv, u8);
    DECL_THISCALL_HEAD(GetVehicleAudioSettings, _ZN21CAEVehicleAudioEntity23GetVehicleAudioSettingsEs, tVehicleAudioSettings, i16 ModelId)
    DECL_THISCALL_TAIL(GetVehicleAudioSettings, ModelId)
    DECL_THISCALL_HEAD(GetFreqForPlayerEngineSound, _ZN21CAEVehicleAudioEntity27GetFreqForPlayerEngineSoundER14cVehicleParamss, float, cVehicleParams& vp, i16 SoundType)
    DECL_THISCALL_TAIL(GetFreqForPlayerEngineSound, vp, SoundType)
    DECL_THISCALL_HEAD(GetFreqForIdle, _ZN21CAEVehicleAudioEntity14GetFreqForIdleEf, float, float fRatio)
    DECL_THISCALL_TAIL(GetFreqForIdle, fRatio)
    DECL_THISCALL_HEAD(GetVolForPlayerEngineSound, _ZN21CAEVehicleAudioEntity26GetVolForPlayerEngineSoundER14cVehicleParamss, float, cVehicleParams& vp, i16 SoundType)
    DECL_THISCALL_TAIL(GetVolForPlayerEngineSound, vp, SoundType)
    DECL_THISCALL_HEAD(GetVehicleDriveWheelSkidValue, _ZN21CAEVehicleAudioEntity29GetVehicleDriveWheelSkidValueEP8CVehicleifP13cTransmissionf, float, CVehicle* pVehicle, i32 WheelState, float fGasPedalAudioRevs, cTransmission* pTransmission, float fSpeed)
    DECL_THISCALL_TAIL(GetVehicleDriveWheelSkidValue, pVehicle, WheelState, fGasPedalAudioRevs, pTransmission, fSpeed)
    DECL_THISCALL_HEAD(GetVehicleNonDriveWheelSkidValue, _ZN21CAEVehicleAudioEntity32GetVehicleNonDriveWheelSkidValueEP8CVehicleiP13cTransmissionf, float, CVehicle* pVehicle, i32 WheelState, cTransmission* pTransmission, float fSpeed)
    DECL_THISCALL_TAIL(GetVehicleNonDriveWheelSkidValue, pVehicle, WheelState, pTransmission, fSpeed)
    DECL_THISCALL_HEAD(IsAccInhibitedBackwards, _ZN21CAEVehicleAudioEntity23IsAccInhibitedBackwardsER14cVehicleParams, u8, cVehicleParams& vp)
    DECL_THISCALL_TAIL(IsAccInhibitedBackwards, vp)
    DECL_THISCALL_HEAD(IsAccInhibited, _ZN21CAEVehicleAudioEntity14IsAccInhibitedER14cVehicleParams, u8, cVehicleParams& vp)
    DECL_THISCALL_TAIL(IsAccInhibited, vp)
    DECL_THISCALL_HEAD(IsAccInhibitedForLowSpeed, _ZN21CAEVehicleAudioEntity25IsAccInhibitedForLowSpeedER14cVehicleParams, u8, cVehicleParams& vp)
    DECL_THISCALL_TAIL(IsAccInhibitedForLowSpeed, vp)
    DECL_THISCALL_SIMPLE(IsAccInhibitedForTime, _ZN21CAEVehicleAudioEntity21IsAccInhibitedForTimeEv, u8);
    DECL_THISCALL_HEAD(InhibitAccForTime, _ZN21CAEVehicleAudioEntity17InhibitAccForTimeEj, void, u32 Time)
    DECL_THISCALL_TAIL(InhibitAccForTime, Time)
    DECL_THISCALL_SIMPLE(IsCrzInhibitedForTime, _ZN21CAEVehicleAudioEntity21IsCrzInhibitedForTimeEv, u8);
    DECL_THISCALL_HEAD(InhibitCrzForTime, _ZN21CAEVehicleAudioEntity17InhibitCrzForTimeEj, void, u32 Time)
    DECL_THISCALL_TAIL(InhibitCrzForTime, Time)
    DECL_THISCALL_HEAD(ProcessRainOnVehicle, _ZN21CAEVehicleAudioEntity20ProcessRainOnVehicleER14cVehicleParams, void, cVehicleParams& VehicleParams)
    DECL_THISCALL_TAIL(ProcessRainOnVehicle, VehicleParams)
    DECL_THISCALL_HEAD(ProcessNitro, _ZN21CAEVehicleAudioEntity12ProcessNitroER14cVehicleParams, void, cVehicleParams& vp)
    DECL_THISCALL_TAIL(ProcessNitro, vp)
    DECL_THISCALL_HEAD(ProcessAircraft, _ZN21CAEVehicleAudioEntity15ProcessAircraftER14cVehicleParams, void, cVehicleParams& vp)
    DECL_THISCALL_TAIL(ProcessAircraft, vp)
    DECL_THISCALL_SIMPLE(GetAircraftNearPosition, _ZN21CAEVehicleAudioEntity23GetAircraftNearPositionEv, CVector);
    DECL_THISCALL_HEAD(PlayAircraftSound, _ZN21CAEVehicleAudioEntity17PlayAircraftSoundEsssff, void, i16 SoundType, i16 SlotID, i16 SoundID, float Volume, float Frequency)
    DECL_THISCALL_TAIL(PlayAircraftSound, SoundType, SlotID, SoundID, Volume, Frequency)
    DECL_THISCALL_HEAD(ProcessPlayerJet, _ZN21CAEVehicleAudioEntity16ProcessPlayerJetER14cVehicleParams, void, cVehicleParams& vp)
    DECL_THISCALL_TAIL(ProcessPlayerJet, vp)
    DECL_THISCALL_HEAD(ProcessPlayerProp, _ZN21CAEVehicleAudioEntity17ProcessPlayerPropER14cVehicleParams, void, cVehicleParams& vp)
    DECL_THISCALL_TAIL(ProcessPlayerProp, vp)
    DECL_THISCALL_HEAD(ProcessPlayerHeli, _ZN21CAEVehicleAudioEntity17ProcessPlayerHeliER14cVehicleParams, void, cVehicleParams& vp)
    DECL_THISCALL_TAIL(ProcessPlayerHeli, vp)
    DECL_THISCALL_HEAD(ProcessPlayerSeaPlane, _ZN21CAEVehicleAudioEntity21ProcessPlayerSeaPlaneER14cVehicleParams, void, cVehicleParams& vp)
    DECL_THISCALL_TAIL(ProcessPlayerSeaPlane, vp)
    DECL_THISCALL_HEAD(ProcessDummyJet, _ZN21CAEVehicleAudioEntity15ProcessDummyJetER14cVehicleParams, void, cVehicleParams& vp)
    DECL_THISCALL_TAIL(ProcessDummyJet, vp)
    DECL_THISCALL_HEAD(ProcessDummyProp, _ZN21CAEVehicleAudioEntity16ProcessDummyPropER14cVehicleParams, void, cVehicleParams& vp)
    DECL_THISCALL_TAIL(ProcessDummyProp, vp)
    DECL_THISCALL_HEAD(ProcessAIProp, _ZN21CAEVehicleAudioEntity13ProcessAIPropER14cVehicleParams, void, cVehicleParams& vp)
    DECL_THISCALL_TAIL(ProcessAIProp, vp)
    DECL_THISCALL_HEAD(ProcessDummyHeli, _ZN21CAEVehicleAudioEntity16ProcessDummyHeliER14cVehicleParams, void, cVehicleParams& vp)
    DECL_THISCALL_TAIL(ProcessDummyHeli, vp)
    DECL_THISCALL_HEAD(ProcessAIHeli, _ZN21CAEVehicleAudioEntity13ProcessAIHeliER14cVehicleParams, void, cVehicleParams& vp)
    DECL_THISCALL_TAIL(ProcessAIHeli, vp)
    DECL_THISCALL_HEAD(ProcessDummySeaPlane, _ZN21CAEVehicleAudioEntity20ProcessDummySeaPlaneER14cVehicleParams, void, cVehicleParams& vp)
    DECL_THISCALL_TAIL(ProcessDummySeaPlane, vp)
    DECL_THISCALL_HEAD(ProcessGenericJet, _ZN21CAEVehicleAudioEntity17ProcessGenericJetEhR14cVehicleParamsfffff, void, u8 bEngineOn, cVehicleParams& vp, float fEngineSpeed, float fAccelRatio, float fBrakeRatio, float fStalledVolume, float fStalledFrequency)
    DECL_THISCALL_TAIL(ProcessGenericJet, bEngineOn, vp, fEngineSpeed, fAccelRatio, fBrakeRatio, fStalledVolume, fStalledFrequency)
    DECL_THISCALL_HEAD(ProcessPlayerBicycle, _ZN21CAEVehicleAudioEntity20ProcessPlayerBicycleER14cVehicleParams, void, cVehicleParams& vp)
    DECL_THISCALL_TAIL(ProcessPlayerBicycle, vp)
    DECL_THISCALL_HEAD(ProcessDummyBicycle, _ZN21CAEVehicleAudioEntity19ProcessDummyBicycleER14cVehicleParams, void, cVehicleParams& vp)
    DECL_THISCALL_TAIL(ProcessDummyBicycle, vp)
    DECL_THISCALL_HEAD(PlayBicycleSound, _ZN21CAEVehicleAudioEntity16PlayBicycleSoundEsssff, void, i16 SoundType, i16 SlotID, i16 SoundID, float Volume, float Frequency)
    DECL_THISCALL_TAIL(PlayBicycleSound, SoundType, SlotID, SoundID, Volume, Frequency)
    DECL_THISCALL_HEAD(GetBaseVolumeForBicycleTyre, _ZN21CAEVehicleAudioEntity27GetBaseVolumeForBicycleTyreEf, float, float fRatio)
    DECL_THISCALL_TAIL(GetBaseVolumeForBicycleTyre, fRatio)
    DECL_THISCALL_HEAD(GetFlyingMetalVolume, _ZN21CAEVehicleAudioEntity20GetFlyingMetalVolumeEP9CPhysical, float, CPhysical* pPhysical)
    DECL_THISCALL_TAIL(GetFlyingMetalVolume, pPhysical)
    DECL_THISCALL_HEAD(ProcessVehicleSirenAlarmHorn, _ZN21CAEVehicleAudioEntity28ProcessVehicleSirenAlarmHornER14cVehicleParams, void, cVehicleParams& VehicleParams)
    DECL_THISCALL_TAIL(ProcessVehicleSirenAlarmHorn, VehicleParams)
    DECL_THISCALL_HEAD(GetHornState, _ZN21CAEVehicleAudioEntity12GetHornStateEPhR14cVehicleParams, void, u8* pbHornOn, cVehicleParams& VehicleParams)
    DECL_THISCALL_TAIL(GetHornState, pbHornOn, VehicleParams)
    DECL_THISCALL_HEAD(GetSirenState, _ZN21CAEVehicleAudioEntity13GetSirenStateEPhS0_R14cVehicleParams, void, u8* pbSirenOn, u8* pbFastSirenOn, cVehicleParams& VehicleParams)
    DECL_THISCALL_TAIL(GetSirenState, pbSirenOn, pbFastSirenOn, VehicleParams)
    DECL_THISCALL_HEAD(PlayHornOrSiren, _ZN21CAEVehicleAudioEntity15PlayHornOrSirenEhhhR14cVehicleParams, void, u8 bHornOn, u8 bSirenOn, u8 bFastSirenOn, cVehicleParams& VehicleParams)
    DECL_THISCALL_TAIL(PlayHornOrSiren, bHornOn, bSirenOn, bFastSirenOn, VehicleParams)
    DECL_THISCALL_HEAD(ProcessBoatEngine, _ZN21CAEVehicleAudioEntity17ProcessBoatEngineER14cVehicleParams, void, cVehicleParams& VehicleParams)
    DECL_THISCALL_TAIL(ProcessBoatEngine, VehicleParams)
    DECL_THISCALL_HEAD(UpdateBoatSound, _ZN21CAEVehicleAudioEntity15UpdateBoatSoundEsssff, void, i16 SoundType, i16 SlotID, i16 SoundID, float Frequency, float Volume)
    DECL_THISCALL_TAIL(UpdateBoatSound, SoundType, SlotID, SoundID, Frequency, Volume)
    DECL_THISCALL_HEAD(StopGenericEngineSound, _ZN21CAEVehicleAudioEntity22StopGenericEngineSoundEs, void, i16 SoundType)
    DECL_THISCALL_TAIL(StopGenericEngineSound, SoundType)
    DECL_THISCALL_HEAD(ProcessBoatMovingOverWater, _ZN21CAEVehicleAudioEntity26ProcessBoatMovingOverWaterER14cVehicleParams, void, cVehicleParams& VehicleParams)
    DECL_THISCALL_TAIL(ProcessBoatMovingOverWater, VehicleParams)
    DECL_THISCALL_HEAD(ProcessDummyTrainEngine, _ZN21CAEVehicleAudioEntity23ProcessDummyTrainEngineER14cVehicleParams, void, cVehicleParams& VehicleParams)
    DECL_THISCALL_TAIL(ProcessDummyTrainEngine, VehicleParams)
    DECL_THISCALL_HEAD(ProcessPlayerTrainEngine, _ZN21CAEVehicleAudioEntity24ProcessPlayerTrainEngineER14cVehicleParams, void, cVehicleParams& VehicleParams)
    DECL_THISCALL_TAIL(ProcessPlayerTrainEngine, VehicleParams)
    DECL_THISCALL_HEAD(UpdateTrainSound, _ZN21CAEVehicleAudioEntity16UpdateTrainSoundEsssff, void, i16 SoundType, i16 SlotID, i16 SoundID, float Frequency, float Volume)
    DECL_THISCALL_TAIL(UpdateTrainSound, SoundType, SlotID, SoundID, Frequency, Volume)
    DECL_THISCALL_HEAD(ProcessTrainTrackSound, _ZN21CAEVehicleAudioEntity22ProcessTrainTrackSoundER14cVehicleParams, void, cVehicleParams& VehicleParams)
    DECL_THISCALL_TAIL(ProcessTrainTrackSound, VehicleParams)
    DECL_THISCALL_HEAD(ProcessPlayerTrainBrakes, _ZN21CAEVehicleAudioEntity24ProcessPlayerTrainBrakesER14cVehicleParams, void, cVehicleParams& VehicleParams)
    DECL_THISCALL_TAIL(ProcessPlayerTrainBrakes, VehicleParams)
    DECL_THISCALL_HEAD(PlayTrainBrakeSound, _ZN21CAEVehicleAudioEntity19PlayTrainBrakeSoundEsff, void, i16 SurfaceSoundID, float Frequency, float VehicleRelativeVolume)
    DECL_THISCALL_TAIL(PlayTrainBrakeSound, SurfaceSoundID, Frequency, VehicleRelativeVolume)
    DECL_THISCALL_HEAD(ProcessSpecialVehicle, _ZN21CAEVehicleAudioEntity21ProcessSpecialVehicleER14cVehicleParams, void, cVehicleParams& VehicleParams)
    DECL_THISCALL_TAIL(ProcessSpecialVehicle, VehicleParams)
    DECL_THISCALL_HEAD(ProcessDummyRCPlane, _ZN21CAEVehicleAudioEntity19ProcessDummyRCPlaneER14cVehicleParams, void, cVehicleParams& vp)
    DECL_THISCALL_TAIL(ProcessDummyRCPlane, vp)
    DECL_THISCALL_HEAD(ProcessPlayerRCPlane, _ZN21CAEVehicleAudioEntity20ProcessPlayerRCPlaneER14cVehicleParams, void, cVehicleParams& vp)
    DECL_THISCALL_TAIL(ProcessPlayerRCPlane, vp)
    DECL_THISCALL_HEAD(ProcessDummyRCHeli, _ZN21CAEVehicleAudioEntity18ProcessDummyRCHeliER14cVehicleParams, void, cVehicleParams& vp)
    DECL_THISCALL_TAIL(ProcessDummyRCHeli, vp)
    DECL_THISCALL_HEAD(ProcessPlayerRCHeli, _ZN21CAEVehicleAudioEntity19ProcessPlayerRCHeliER14cVehicleParams, void, cVehicleParams& vp)
    DECL_THISCALL_TAIL(ProcessPlayerRCHeli, vp)
    DECL_THISCALL_HEAD(ProcessDummyRCCar, _ZN21CAEVehicleAudioEntity17ProcessDummyRCCarER14cVehicleParams, void, cVehicleParams& vp)
    DECL_THISCALL_TAIL(ProcessDummyRCCar, vp)
    DECL_THISCALL_HEAD(ProcessPlayerRCCar, _ZN21CAEVehicleAudioEntity18ProcessPlayerRCCarER14cVehicleParams, void, cVehicleParams& vp)
    DECL_THISCALL_TAIL(ProcessPlayerRCCar, vp)
    DECL_THISCALL_HEAD(ProcessDummyHovercraft, _ZN21CAEVehicleAudioEntity22ProcessDummyHovercraftER14cVehicleParams, void, cVehicleParams& vp)
    DECL_THISCALL_TAIL(ProcessDummyHovercraft, vp)
    DECL_THISCALL_HEAD(ProcessPlayerHovercraft, _ZN21CAEVehicleAudioEntity23ProcessPlayerHovercraftER14cVehicleParams, void, cVehicleParams& vp)
    DECL_THISCALL_TAIL(ProcessPlayerHovercraft, vp)
    DECL_THISCALL_HEAD(ProcessDummyGolfCart, _ZN21CAEVehicleAudioEntity20ProcessDummyGolfCartER14cVehicleParams, void, cVehicleParams& vp)
    DECL_THISCALL_TAIL(ProcessDummyGolfCart, vp)
    DECL_THISCALL_HEAD(ProcessPlayerGolfCart, _ZN21CAEVehicleAudioEntity21ProcessPlayerGolfCartER14cVehicleParams, void, cVehicleParams& vp)
    DECL_THISCALL_TAIL(ProcessPlayerGolfCart, vp)
    DECL_THISCALL_HEAD(ProcessPlayerCombine, _ZN21CAEVehicleAudioEntity20ProcessPlayerCombineER14cVehicleParams, void, cVehicleParams& vp)
    DECL_THISCALL_TAIL(ProcessPlayerCombine, vp)
    DECL_THISCALL_HEAD(ProcessEngineDamage, _ZN21CAEVehicleAudioEntity19ProcessEngineDamageER14cVehicleParams, void, cVehicleParams& vp)
    DECL_THISCALL_TAIL(ProcessEngineDamage, vp)
    DECL_THISCALL_HEAD(UpdateGenericVehicleSound, _ZN21CAEVehicleAudioEntity25UpdateGenericVehicleSoundEssssfff, void, i16 SoundType, i16 SlotID, i16 BankID, i16 SoundID, float fFrequency, float fVolume, float fRollOff)
    DECL_THISCALL_TAIL(UpdateGenericVehicleSound, SoundType, SlotID, BankID, SoundID, fFrequency, fVolume, fRollOff)
    DECL_THISCALL_HEAD(ProcessMovingParts, _ZN21CAEVehicleAudioEntity18ProcessMovingPartsER14cVehicleParams, void, cVehicleParams& vp)
    DECL_THISCALL_TAIL(ProcessMovingParts, vp)
    DECL_OBJECT_ARRAY_PLT(tDummyEngineSlot, s_DummyEngineSlots, BYBIT(0x6785FC, 0x84EC10));
DECL_CLASS_END()
CHECKSIZE(CAEVehicleAudioEntity, 0x24C, 0x310);



DECL_CLASS_BASED(CAEWeatherAudioEntity, CAEAudioEntity)
    CAEWeatherAudioEntity() = delete;

    // STATIC functions
    DECL_FASTCALL_SIMPLE(StaticInitialise, _ZN21CAEWeatherAudioEntity16StaticInitialiseEv, void);
    DECL_FASTCALL_SIMPLE(StaticReset, _ZN21CAEWeatherAudioEntity11StaticResetEv, void);

    // STATIC values
    DECL_VALUE_PLT_FLT(m_sfRainVolume, BYBIT(0x678250, 0x84E4B8));
    DECL_VALUE_PLT_I16(m_snLastRainDropSoundID, BYBIT(0x67782C, 0x84D080));
    DECL_OBJECT_PLT(CAETwinLoopSoundEntity, m_sRainSoundL, BYBIT(0x67805C, 0x84E0D8));
    DECL_OBJECT_PLT(CAETwinLoopSoundEntity, m_sRainSoundR, BYBIT(0x679B18, 0x851650));

    // Member functions
    DECL_THISCALL_SIMPLE(Service, _ZN21CAEWeatherAudioEntity7ServiceEv, void);

    DECL_THISCALL_HEAD(AddAudioEvent, _ZN21CAEWeatherAudioEntity13AddAudioEventEi, void, int AudioEvent)
    DECL_THISCALL_TAIL(AddAudioEvent, AudioEvent)

    // Member values
    i8 m_nLastThunderFrequencyIndex;
DECL_CLASS_END()



DECL_CLASS_BASED(CAEFireAudioEntity, CAEAudioEntity)
    CAEFireAudioEntity() = delete;

    // STATIC functions
    DECL_FASTCALL_SIMPLE(StaticInitialise, _ZN18CAEFireAudioEntity16StaticInitialiseEv, void);

    // STATIC values
    DECL_VALUE_PLT_I8(m_snLastFireFrequencyIndex, BYBIT(0x676460, 0x84A918));

    // Member functions
    DECL_THISCALL_SIMPLE(Terminate, _ZN18CAEFireAudioEntity9TerminateEv, void);

    DECL_THISCALL_HEAD(Initialise, _ZN18CAEFireAudioEntity10InitialiseEP10FxSystem_c, void, FxSystem_c *pParent)
    DECL_THISCALL_TAIL(Initialise, pParent)

    DECL_THISCALL_HEAD(AddAudioEvent, _ZN18CAEFireAudioEntity13AddAudioEventEiR7CVector, void, int AudioEvent, CVector &vPosition)
    DECL_THISCALL_TAIL(AddAudioEvent, AudioEvent, vPosition)

    DECL_THISCALL_HEAD(PlayWaterSounds, _ZN18CAEFireAudioEntity15PlayWaterSoundsEiR7CVector, void, int AudioEvent, CVector &vPosition)
    DECL_THISCALL_TAIL(PlayWaterSounds, AudioEvent, vPosition)

    DECL_THISCALL_HEAD(PlayFireSounds, _ZN18CAEFireAudioEntity14PlayFireSoundsEiR7CVector, void, int AudioEvent, CVector &vPosition)
    DECL_THISCALL_TAIL(PlayFireSounds, AudioEvent, vPosition)

    // Member values
    CAESound   *m_pFireSound;
    CAESound   *m_pFireSound2;
    FxSystem_c *m_pParentEffectSystem;
DECL_CLASS_END()

#define m_pAudioEventVolumes m_pAudioEventVolumes()

#define s_Conversation s_Conversation()
#define s_ConversationLength s_ConversationLength()
#define s_bForceAudible s_bForceAudible()
#define s_PhraseMemory s_PhraseMemory()
#define s_NextSpeechSlot s_NextSpeechSlot()
#define s_pConversationPed1 s_pConversationPed1()
#define s_pConversationPed2 s_pConversationPed2()
#define s_pConversationPedSlot1 s_pConversationPedSlot1()
#define s_pConversationPedSlot2 s_pConversationPedSlot2()
#define s_pPlayerConversationPed s_pPlayerConversationPed()
#define s_bPedConversationHappening s_bPedConversationHappening()
#define s_bPlayerConversationHappening s_bPlayerConversationHappening()
#define s_bAllSpeechDisabled s_bAllSpeechDisabled()
#define s_bAPlayerSpeaking s_bAPlayerSpeaking()
#define s_nCJMoodOverrideTime s_nCJMoodOverrideTime()
#define s_nCJBasicMood s_nCJBasicMood()
#define s_nCJGangBanging s_nCJGangBanging()
#define s_nCJFat s_nCJFat()
#define s_nCJWellDressed s_nCJWellDressed()

#define s_pPlayerDriver s_pPlayerDriver()
#define s_pPlayerAttachedForRadio s_pPlayerAttachedForRadio()
#define s_pVehicleAudioSettingsForRadio s_pVehicleAudioSettingsForRadio()
#define s_NextDummyEngineSlot s_NextDummyEngineSlot()
#define s_HelicoptorsDisabled s_HelicoptorsDisabled()

#define m_sfRainVolume m_sfRainVolume()
#define m_snLastRainDropSoundID m_snLastRainDropSoundID()
#define m_sRainSoundL m_sRainSoundL()
#define m_sRainSoundR m_sRainSoundR()

#define m_snLastFireFrequencyIndex m_snLastFireFrequencyIndex()

DECL_CLASS_BASED(CAEPoliceScannerAudioEntity, CAEAudioEntity)
    CAEPoliceScannerAudioEntity() = delete;

    // Construct/Deconstruct functions
    DECL_DTORCALL(CAEPoliceScannerAudioEntity, _ZN27CAEPoliceScannerAudioEntityD2Ev);

    // STATIC functions
    DECL_FASTCALL_SIMPLE(StaticInitialise, _ZN27CAEPoliceScannerAudioEntity16StaticInitialiseEv, void);
    DECL_FASTCALL_SIMPLE(Service, _ZN27CAEPoliceScannerAudioEntity7ServiceEv, void);
    DECL_FASTCALL_SIMPLE(Reset, _ZN27CAEPoliceScannerAudioEntity5ResetEv, void);
    DECL_FASTCALL_SIMPLE(DisableScanner, _ZN27CAEPoliceScannerAudioEntity14DisableScannerEhh, void, u8 bCurtail, u8 bInstantCurtail);
    DECL_FASTCALL_SIMPLE(EnableScanner, _ZN27CAEPoliceScannerAudioEntity13EnableScannerEv, void);
    DECL_FASTCALL_SIMPLE(StopScanner, _ZN27CAEPoliceScannerAudioEntity11StopScannerEh, void, u8 bInstantStop);
    DECL_FASTCALL_SIMPLE(PopulateScannerDialogueLists, _ZN27CAEPoliceScannerAudioEntity28PopulateScannerDialogueListsEP12tScannerSlotS1_, void, tScannerSlot* pScannerSlotFirst, tScannerSlot* pScannerSlotSecond);
    DECL_FASTCALL_SIMPLE(CanWePlayNewScannerDialogue, _ZN27CAEPoliceScannerAudioEntity27CanWePlayNewScannerDialogueEv, u8);
    DECL_FASTCALL_SIMPLE(LoadSlots, _ZN27CAEPoliceScannerAudioEntity9LoadSlotsEv, void);
    DECL_FASTCALL_SIMPLE(FinishedPlayingScannerDialogue, _ZN27CAEPoliceScannerAudioEntity30FinishedPlayingScannerDialogueEv, void);

    // STATIC values
    DECL_VALUE_PLT_U32(s_NextNewScannerDialogueTime, BYBIT(0x676C3C, 0x84B8C0));
    DECL_OBJECT_PLT(u8, s_bScannerDisabled, BYBIT(0x676D04, 0x84BA50));
    DECL_OBJECT_PLT(i16, s_nScannerPlaybackState, BYBIT(0x6792D8, 0x8505C8));
    DECL_OBJECT_PLT(CAEPoliceScannerAudioEntity*, s_pPSControlling, BYBIT(0x67748C, 0x84C950));
    DECL_OBJECT_ARRAY_PLT(tScannerSlot, s_ScannerSlotFirst, BYBIT(0x679830, 0x851070));
    DECL_OBJECT_ARRAY_PLT(tScannerSlot, s_ScannerSlotSecond, BYBIT(0x67603C, 0x84A0E8));
    DECL_OBJECT_ARRAY_PLT(i16, s_SlotState, BYBIT(0x67666C, 0x84AD30));
    DECL_OBJECT_PLT(tScannerSlot*, s_pCurrentSlots, BYBIT(0x6777D8, 0x84CFD8));
    DECL_VALUE_PLT_U32(s_nPlaybackStartTime, BYBIT(0x6762BC, 0x84A5D8));
    DECL_VALUE_PLT_U32(s_nAbortPlaybackTime, BYBIT(0x679904, 0x851228));
    DECL_OBJECT_PLT(u8, s_bStoppingScanner, BYBIT(0x678568, 0x84EAE8));
    DECL_OBJECT_PLT(i16, s_nSectionPlaying, BYBIT(0x676AE0, 0x84B608));
    DECL_OBJECT_PLT(CAESound*, s_pSound, BYBIT(0x679920, 0x851260));
    DECL_VALUE_PLT_FLT(s_fVolumeOffset, BYBIT(0x678588, 0x84EB28));

    // Member functions
    DECL_THISCALL_HEAD(AddAudioEvent, _ZN27CAEPoliceScannerAudioEntity13AddAudioEventEi10eCrimeTypeRK7CVector, void, i32 AudioEvent, eCrimeType CrimeType, CVector const& vPosition)
    DECL_THISCALL_TAIL(AddAudioEvent, AudioEvent, CrimeType, vPosition)
    DECL_THISCALL_HEAD(PlayPoliceScannerDialogue, _ZN27CAEPoliceScannerAudioEntity25PlayPoliceScannerDialogueEP12tScannerSlotS1_, void, tScannerSlot* pCrimeSlots, tScannerSlot* pLastSeenSlots)
    DECL_THISCALL_TAIL(PlayPoliceScannerDialogue, pCrimeSlots, pLastSeenSlots)
    DECL_THISCALL_SIMPLE(PlayLoadedDialogue, _ZN27CAEPoliceScannerAudioEntity18PlayLoadedDialogueEv, void);
    DECL_THISCALL_SIMPLE(PrepSlots, _ZN27CAEPoliceScannerAudioEntity9PrepSlotsEv, void);
DECL_CLASS_END()
CHECKSIZE(CAEPoliceScannerAudioEntity, 0x7C, 0x90);

#endif // __AML_PSDK_SAAEAUDIOENTITY_H
