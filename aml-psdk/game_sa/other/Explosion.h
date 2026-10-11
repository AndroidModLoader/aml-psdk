#ifndef __AML_PSDK_SAEXPLOSION_H
#define __AML_PSDK_SAEXPLOSION_H

/*
    Plugin-SDK (Grand Theft Auto San Andreas) header file
    Authors: GTA Community. See more here
    https://github.com/DK22Pac/plugin-sdk
    Do not delete this comment block. Respect others' work!
*/

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/gta_base/Vector.h>
#include <aml-psdk/game_sa/audio/AEScriptAudioEntity.h>

struct CEntity;

enum eExplosionType
{
    EXPLOSION_GRENADE,
    EXPLOSION_MOLOTOV,
    EXPLOSION_ROCKET,
    EXPLOSION_WEAK_ROCKET,
    EXPLOSION_CAR,
    EXPLOSION_QUICK_CAR,
    EXPLOSION_BOAT,
    EXPLOSION_AIRCRAFT,
    EXPLOSION_MINE,
    EXPLOSION_OBJECT,
    EXPLOSION_TANK_FIRE,
    EXPLOSION_SMALL,
    EXPLOSION_RC_VEHICLE
};

DECL_CLASS(CExplosion)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(Initialise, _ZN10CExplosion10InitialiseEv, void);
    DECL_FASTCALL_SIMPLE(ClearAllExplosions, _ZN10CExplosion18ClearAllExplosionsEv, void);
    DECL_FASTCALL_SIMPLE(Shutdown, _ZN10CExplosion8ShutdownEv, void);
    DECL_FASTCALL_SIMPLE(GetExplosionActiveCounter, _ZN10CExplosion25GetExplosionActiveCounterEh, u8, u8 id);
    DECL_FASTCALL_SIMPLE(ResetExplosionActiveCounter, _ZN10CExplosion27ResetExplosionActiveCounterEh, void, u8 id);
    DECL_FASTCALL_SIMPLE(DoesExplosionMakeSound, _ZN10CExplosion22DoesExplosionMakeSoundEh, u8, u8 id);
    DECL_FASTCALL_SIMPLE(GetExplosionType, _ZN10CExplosion16GetExplosionTypeEh, eExplosionType, u8 explosionId);
    DECL_FASTCALL_SIMPLE(GetExplosionPosition, _ZN10CExplosion20GetExplosionPositionEh, CVector&, u8 explosionId);
    DECL_FASTCALL_SIMPLE(AddExplosion, _ZN10CExplosion12AddExplosionEP7CEntityS1_14eExplosionType7CVectorjhfh, bool,
        CEntity* victim, CEntity* creator, eExplosionType explosionType, CVector posn, u32 time, u8 makeSound, float camShake, u8 visibility);
    DECL_FASTCALL_SIMPLE(Update, _ZN10CExplosion6UpdateEv, void);
    DECL_FASTCALL_SIMPLE(TestForExplosionInArea, _ZN10CExplosion22TestForExplosionInAreaEiffffff, bool,
        i32 type, float minX, float maxX, float minY, float maxY, float minZ, float maxZ);
    DECL_FASTCALL_SIMPLE(RemoveAllExplosionsInArea, _ZN10CExplosion25RemoveAllExplosionsInAreaE7CVectorf, void, CVector pos, float radius);

    // STATIC values
    DECL_OBJECT_PLT(CAEExplosionAudioEntity, m_ExplosionAudioEntity, BYBIT(0x677560, 0x84CAF8));

    // Member values
    eExplosionType m_nType;
    CVector m_vecPosition;
    float m_fRadius;
    float m_fPropagationRate;
    CEntity *m_pCreator;
    CEntity *m_pVictim;
    // Mobile timestamps are floats; keep the Plugin-SDK member names.
    float m_nExpireTime;
    float m_fDamagePercentage;
    u8 m_bIsActive;
    u8 m_nActiveCounter;
    u8 m_bMakeSound;
    float m_nCreatedTime;
    u32 m_nParticlesExpireTime;
    float m_fVisibleDistance;
    float m_fGroundZ;
    u32 m_nFuelTimer;
    CVector m_vecFuelDirection[3];
    float m_fFuelOffsetDistance[3];
    float m_fFuelSpeed[3];
DECL_CLASS_END()
CHECKSIZE(CExplosion, 0x7C, 0x88);

DECL_OBJECT_ARRAY_ADDR_GLOBAL(CExplosion, aExplosions, BYBIT(0xA84370, 0xD28C78));
#define aExplosions aExplosions()

#define m_ExplosionAudioEntity m_ExplosionAudioEntity()

#endif // __AML_PSDK_SAEXPLOSION_H
