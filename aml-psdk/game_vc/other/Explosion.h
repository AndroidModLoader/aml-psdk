#ifndef __AML_PSDK_VCEXPLOSION_H
#define __AML_PSDK_VCEXPLOSION_H

#include <aml-psdk/game_vc/plugin.h>
#include <aml-psdk/gta_base/Vector.h>

struct CEntity;

enum eExplosionType : u32
{
    EXPLOSION_GRENADE = 0,
    EXPLOSION_MOLOTOV = 1,
    EXPLOSION_ROCKET = 2,
    EXPLOSION_CAR = 3,
    EXPLOSION_CAR_QUICK = 4,
    EXPLOSION_BOAT = 5,
    EXPLOSION_HELI = 6,
    EXPLOSION_HELI2 = 7,
    EXPLOSION_MINE = 8,
    EXPLOSION_BARREL = 9,
    EXPLOSION_TANK_GRENADE = 10,
    EXPLOSION_HELI_BOMB = 11
};

DECL_CLASS(CExplosion)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(Initialise, _ZN10CExplosion10InitialiseEv, void);
    DECL_FASTCALL_SIMPLE(Shutdown, _ZN10CExplosion8ShutdownEv, void);
    DECL_FASTCALL_SIMPLE(ClearAllExplosions, _ZN10CExplosion18ClearAllExplosionsEv, void);
    DECL_FASTCALL_SIMPLE(Update, _ZN10CExplosion6UpdateEv, void);
    DECL_FASTCALL_SIMPLE(AddExplosion, _ZN10CExplosion12AddExplosionEP7CEntityS1_14eExplosionTypeRK7CVectorjhf, bool, CEntity* victim, CEntity* creator, eExplosionType type, CVector const& position, u32 delay, u8 makeSound, float radius);
    DECL_FASTCALL_SIMPLE(GetExplosionActiveCounter, _ZN10CExplosion25GetExplosionActiveCounterEh, u8, u8 index);
    DECL_FASTCALL_SIMPLE(ResetExplosionActiveCounter, _ZN10CExplosion27ResetExplosionActiveCounterEh, void, u8 index);
    DECL_FASTCALL_SIMPLE(DoesExplosionMakeSound, _ZN10CExplosion22DoesExplosionMakeSoundEh, u8, u8 index);
    DECL_FASTCALL_SIMPLE(GetExplosionType, _ZN10CExplosion16GetExplosionTypeEh, eExplosionType, u8 index);
    DECL_FASTCALL_SIMPLE(GetExplosionPosition, _ZN10CExplosion20GetExplosionPositionEh, CVector&, u8 index);
    DECL_FASTCALL_SIMPLE(TestForExplosionInArea, _ZN10CExplosion22TestForExplosionInAreaE14eExplosionTypeffffff, bool, eExplosionType type, float minX, float maxX, float minY, float maxY, float minZ, float maxZ);
    DECL_FASTCALL_SIMPLE(RemoveAllExplosionsInArea, _ZN10CExplosion25RemoveAllExplosionsInAreaE7CVectorf, void, CVector position, float radius);

    // Member values
    eExplosionType m_nType;
    CVector m_vecPosition;
    float m_fRadius;
    float m_fPropagationRate;
    CEntity* m_pCreator;
    CEntity* m_pVictim;
    float m_nExpireTime;
    u8 m_nIteration;
    u8 m_nActiveCounter;
    bool m_bIsBoat;
    u8 m_bMakeSound;
    float m_fStartTime;
    u32 m_nStartTime;
    float m_fPower;
    float m_fGroundZ;
DECL_CLASS_END()
CHECKSIZE(CExplosion, 0x38, 0x40);

DECL_OBJECT_ARRAY_ADDR_GLOBAL(CExplosion, aExplosions, BYBIT(0x726700, 0x9A40E8));
#define aExplosions aExplosions()

#endif // __AML_PSDK_VCEXPLOSION_H
