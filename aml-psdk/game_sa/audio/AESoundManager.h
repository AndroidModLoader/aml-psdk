#ifndef __AML_PSDK_SAAESOUNDMANAGER_H
#define __AML_PSDK_SAAESOUNDMANAGER_H

#include "AEAudioEntity.h"

struct CPhysical;

DECL_CLASS(CAEPhysicallyPlayingSound)

    // Member values
    i16 m_SoundReference;
DECL_CLASS_END()
CHECKSIZE(CAEPhysicallyPlayingSound, 0x2, 0x2);

DECL_CLASS(CAESoundManager)
    // Construct/Deconstruct functions
    DECL_DTORCALL(CAESoundManager, _ZN15CAESoundManagerD2Ev);

    // Member functions
    DECL_THISCALL_SIMPLE(Initialise, _ZN15CAESoundManager10InitialiseEv, u8);
    DECL_THISCALL_SIMPLE(Terminate, _ZN15CAESoundManager9TerminateEv, void);
    DECL_THISCALL_SIMPLE(Service, _ZN15CAESoundManager7ServiceEv, void);
    DECL_THISCALL_SIMPLE(Reset, _ZN15CAESoundManager5ResetEv, void);
    DECL_THISCALL_HEAD(PauseManually, _ZN15CAESoundManager13PauseManuallyEh, void, u8 On)
    DECL_THISCALL_TAIL(PauseManually, On)
    DECL_THISCALL_HEAD(RequestNewSound, _ZN15CAESoundManager15RequestNewSoundEP8CAESound, CAESound*, CAESound* pRequestedSound)
    DECL_THISCALL_TAIL(RequestNewSound, pRequestedSound)
    DECL_THISCALL_HEAD(AreSoundsPlayingInBankSlot, _ZN15CAESoundManager26AreSoundsPlayingInBankSlotEs, i16, i16 BankSlotID)
    DECL_THISCALL_TAIL(AreSoundsPlayingInBankSlot, BankSlotID)
    DECL_THISCALL_HEAD(AreSoundsOfThisEventPlayingForThisEntity, _ZN15CAESoundManager40AreSoundsOfThisEventPlayingForThisEntityEsP14CAEAudioEntity, i16, i16 nAudioEvent, CAEAudioEntity* pAudioEntity)
    DECL_THISCALL_TAIL(AreSoundsOfThisEventPlayingForThisEntity, nAudioEvent, pAudioEntity)
    DECL_THISCALL_HEAD(AreSoundsOfThisEventPlayingForThisEntityAndPhysical, _ZN15CAESoundManager51AreSoundsOfThisEventPlayingForThisEntityAndPhysicalEsP14CAEAudioEntityP9CPhysical, i16, i16 nAudioEvent, CAEAudioEntity* pAudioEntity, CPhysical* pPhysical)
    DECL_THISCALL_TAIL(AreSoundsOfThisEventPlayingForThisEntityAndPhysical, nAudioEvent, pAudioEntity, pPhysical)
    DECL_THISCALL_HEAD(CancelSoundsOfThisEventPlayingForThisEntity, _ZN15CAESoundManager43CancelSoundsOfThisEventPlayingForThisEntityEsP14CAEAudioEntity, void, i16 nAudioEvent, CAEAudioEntity* pAudioEntity)
    DECL_THISCALL_TAIL(CancelSoundsOfThisEventPlayingForThisEntity, nAudioEvent, pAudioEntity)
    DECL_THISCALL_HEAD(CancelSoundsOfThisEventPlayingForThisEntityAndPhysical, _ZN15CAESoundManager54CancelSoundsOfThisEventPlayingForThisEntityAndPhysicalEsP14CAEAudioEntityP9CPhysical, void, i16 nAudioEvent, CAEAudioEntity* pAudioEntity, CPhysical* pPhysical)
    DECL_THISCALL_TAIL(CancelSoundsOfThisEventPlayingForThisEntityAndPhysical, nAudioEvent, pAudioEntity, pPhysical)
    DECL_THISCALL_HEAD(CancelSoundsInBankSlot, _ZN15CAESoundManager22CancelSoundsInBankSlotEsh, void, i16 BankSlotID, u8 Forget)
    DECL_THISCALL_TAIL(CancelSoundsInBankSlot, BankSlotID, Forget)
    DECL_THISCALL_HEAD(CancelSoundsOwnedByAudioEntity, _ZN15CAESoundManager30CancelSoundsOwnedByAudioEntityEP14CAEAudioEntityh, void, CAEAudioEntity* pAudioEntity, u8 Forget)
    DECL_THISCALL_TAIL(CancelSoundsOwnedByAudioEntity, pAudioEntity, Forget)
    DECL_THISCALL_HEAD(GetVirtualChannelForPhysicalChannel, _ZN15CAESoundManager35GetVirtualChannelForPhysicalChannelEs, i16, i16 PhysicalChannel)
    DECL_THISCALL_TAIL(GetVirtualChannelForPhysicalChannel, PhysicalChannel)

    // Member values
    u16 m_AllocatedPhysicalChannels;
    i16 m_AudioHardwareHandle;
    CAESound m_VirtuallyPlayingSoundList[300];
    CAEPhysicallyPlayingSound* m_PhysicallyPlayingSoundList;
    i16* m_ChannelPosition;
    i16* m_PrioritisedSoundList;
    i16 m_VirtualChannelSoundLengths[300];
    i16 m_VirtualChannelSoundLoopStartTimes[300];
    u32 m_TimeLastCalled;
    u8 m_GamePausedLastFrame;
    u8 m_bManualPause;
    u32 m_TimeLastCalledUnpaused;
DECL_CLASS_END()
CHECKSIZE(CAESoundManager, 0x8CBC, 0x9AE0);

DECL_OBJECT_PLT_GLOBAL(CAESoundManager, AESoundManager, BYBIT(0x6774D8, 0x84C9E8));
#define AESoundManager AESoundManager()

#endif // __AML_PSDK_SAAESOUNDMANAGER_H
