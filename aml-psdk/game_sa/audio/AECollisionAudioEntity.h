#ifndef __AML_PSDK_SAAECOLLISIONAUDIOENTITY_H
#define __AML_PSDK_SAAECOLLISIONAUDIOENTITY_H

#include "AEAudioEntity.h"

struct CEntity;

struct tCollisionAudioEntry
{
    CEntity *pEntityA;
    CEntity *pEntityB;
    CAESound *pSound;
    unsigned int LoopStopTimeMs;
    signed char SoundStatus;
    unsigned char SurfaceA;
    unsigned char SurfaceB;
};

DECL_CLASS(CAECollisionAudioEntity)
    CAECollisionAudioEntity() = delete;

    // STATIC functions
    DECL_FASTCALL_SIMPLE(GetSurfaceHardnessVolumeOffset, _ZN23CAECollisionAudioEntity30GetSurfaceHardnessVolumeOffsetEh, float, u8 Surface);

    CAEAudioEntity audio;
    short m_CollisionSoundIDHistory[195];
    short m_nLastBulletHitSoundID;
    int m_nActiveCollisionSounds;
    tCollisionAudioEntry m_CollisionSoundList[300];

    // Member functions
    DECL_THISCALL_SIMPLE(Initialise, _ZN23CAECollisionAudioEntity10InitialiseEv, void);
    DECL_THISCALL_SIMPLE(InitialisePostLoading, _ZN23CAECollisionAudioEntity21InitialisePostLoadingEv, void);
    DECL_THISCALL_HEAD(ReportCollision, _ZN23CAECollisionAudioEntity15ReportCollisionEP7CEntityS1_hhR7CVectorPS2_ffhh, void, CEntity* pEntityA, CEntity* pEntityB, u8 SurfaceA, u8 SurfaceB, CVector& vPosition, CVector* pvNormal, float fImpulseMagnitude, float fRelVelSqr, u8 bForceOneShot, u8 bForceLooping)
    DECL_THISCALL_TAIL(ReportCollision, pEntityA, pEntityB, SurfaceA, SurfaceB, vPosition, pvNormal, fImpulseMagnitude, fRelVelSqr, bForceOneShot, bForceLooping)
    DECL_THISCALL_HEAD(ReportBulletHit, _ZN23CAECollisionAudioEntity15ReportBulletHitEP7CEntityhR7CVectorf, void, CEntity* pHitEntity, u8 HitSurface, CVector& vPosition, float fAngleOfIncidence)
    DECL_THISCALL_TAIL(ReportBulletHit, pHitEntity, HitSurface, vPosition, fAngleOfIncidence)
    DECL_THISCALL_HEAD(ReportObjectDestruction, _ZN23CAECollisionAudioEntity23ReportObjectDestructionEP7CEntity, void, CEntity* pEntity)
    DECL_THISCALL_TAIL(ReportObjectDestruction, pEntity)
    DECL_THISCALL_HEAD(ReportGlassCollisionEvent, _ZN23CAECollisionAudioEntity25ReportGlassCollisionEventEiR7CVectorj, void, i32 AudioEvent, CVector& vPosition, u32 PlayDelayMs)
    DECL_THISCALL_TAIL(ReportGlassCollisionEvent, AudioEvent, vPosition, PlayDelayMs)
    DECL_THISCALL_NAMED_HEAD(ReportWaterSplash1, ReportWaterSplash, _ZN23CAECollisionAudioEntity17ReportWaterSplashEP9CPhysicalfh, void, CPhysical* pCPhysical1, float arg2, u8 arg3)
    DECL_THISCALL_TAIL(ReportWaterSplash1, pCPhysical1, arg2, arg3)
    DECL_THISCALL_NAMED_HEAD(ReportWaterSplash2, ReportWaterSplash, _ZN23CAECollisionAudioEntity17ReportWaterSplashE7CVectorf, void, CVector vPosition, float fForcedVolumeOffsetdB)
    DECL_THISCALL_TAIL(ReportWaterSplash2, vPosition, fForcedVolumeOffsetdB)
    DECL_THISCALL_SIMPLE(Service, _ZN23CAECollisionAudioEntity7ServiceEv, void);
    DECL_THISCALL_SIMPLE(Reset, _ZN23CAECollisionAudioEntity5ResetEv, void);
    DECL_THISCALL_HEAD(PlayOneShotCollisionSound, _ZN23CAECollisionAudioEntity25PlayOneShotCollisionSoundEP7CEntityS1_hhfR7CVector, void, CEntity* pEntityA, CEntity* pEntityB, u8 SurfaceA, u8 SurfaceB, float fImpulseMagnitude, CVector& vPosition)
    DECL_THISCALL_TAIL(PlayOneShotCollisionSound, pEntityA, pEntityB, SurfaceA, SurfaceB, fImpulseMagnitude, vPosition)
    DECL_THISCALL_HEAD(PlayLoopingCollisionSound, _ZN23CAECollisionAudioEntity25PlayLoopingCollisionSoundEP7CEntityS1_hhfR7CVectorh, void, CEntity* pEntityA, CEntity* pEntityB, u8 SurfaceA, u8 SurfaceB, float fImpulseMagnitude, CVector& vPosition, u8 bForceLooping)
    DECL_THISCALL_TAIL(PlayLoopingCollisionSound, pEntityA, pEntityB, SurfaceA, SurfaceB, fImpulseMagnitude, vPosition, bForceLooping)
    DECL_THISCALL_HEAD(PlayBulletHitCollisionSound, _ZN23CAECollisionAudioEntity27PlayBulletHitCollisionSoundEhR7CVectorf, void, u8 HitSurface, CVector& vPosition, float fAngleOfIncidence)
    DECL_THISCALL_TAIL(PlayBulletHitCollisionSound, HitSurface, vPosition, fAngleOfIncidence)
    DECL_THISCALL_HEAD(UpdateLoopingCollisionSound, _ZN23CAECollisionAudioEntity27UpdateLoopingCollisionSoundEP8CAESoundP7CEntityS3_hhfR7CVectorh, void, CAESound* pSound, CEntity* pEntityA, CEntity* pEntityB, u8 SurfaceA, u8 SurfaceB, float fImpulseMagnitude, CVector& vPosition, u8 bForceLooping)
    DECL_THISCALL_TAIL(UpdateLoopingCollisionSound, pSound, pEntityA, pEntityB, SurfaceA, SurfaceB, fImpulseMagnitude, vPosition, bForceLooping)
    DECL_THISCALL_HEAD(GetCollisionSoundStatus, _ZN23CAECollisionAudioEntity23GetCollisionSoundStatusEP7CEntityS1_hhPi, i8, CEntity* pEntityA, CEntity* pEntityB, u8 SurfaceA, u8 SurfaceB, i32* pCollisionIndex)
    DECL_THISCALL_TAIL(GetCollisionSoundStatus, pEntityA, pEntityB, SurfaceA, SurfaceB, pCollisionIndex)
    DECL_THISCALL_HEAD(ChooseCollisionSoundID, _ZN23CAECollisionAudioEntity22ChooseCollisionSoundIDEh, i16, u8 Surface)
    DECL_THISCALL_TAIL(ChooseCollisionSoundID, Surface)
    DECL_THISCALL_HEAD(AddCollisionSoundIDToHistory, _ZN23CAECollisionAudioEntity28AddCollisionSoundIDToHistoryEhs, void, u8 Surface, i16 SoundID)
    DECL_THISCALL_TAIL(AddCollisionSoundIDToHistory, Surface, SoundID)
    DECL_THISCALL_HEAD(AddCollisionSoundToList, _ZN23CAECollisionAudioEntity23AddCollisionSoundToListEP7CEntityS1_hhP8CAESoundi, void, CEntity* pEntityA, CEntity* pEntityB, u8 SurfaceA, u8 SurfaceB, CAESound* pSound, i32 SoundStatus)
    DECL_THISCALL_TAIL(AddCollisionSoundToList, pEntityA, pEntityB, SurfaceA, SurfaceB, pSound, SoundStatus)
DECL_CLASS_END()

#endif // __AML_PSDK_SAAECOLLISIONAUDIOENTITY_H
