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
    CAEAudioEntity audio;
    short m_CollisionSoundIDHistory[195];
    short m_nLastBulletHitSoundID;
    int m_nActiveCollisionSounds;
    tCollisionAudioEntry m_CollisionSoundList[300];
DECL_CLASS_END()

#endif // __AML_PSDK_SAAECOLLISIONAUDIOENTITY_H
