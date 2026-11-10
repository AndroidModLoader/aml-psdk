#ifndef __AML_PSDK_VCBULLETINFO_H
#define __AML_PSDK_VCBULLETINFO_H

#include "Weapon.h"

DECL_CLASS(CBulletInfo)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(Initialise, _ZN11CBulletInfo10InitialiseEv, void);
    DECL_FASTCALL_SIMPLE(Shutdown, _ZN11CBulletInfo8ShutdownEv, void);
    DECL_FASTCALL_SIMPLE(AddBullet, _ZN11CBulletInfo9AddBulletEP7CEntity11eWeaponType7CVectorS3_, bool, CEntity* creator, eWeaponType type, CVector position, CVector velocity);
    DECL_FASTCALL_SIMPLE(Update, _ZN11CBulletInfo6UpdateEv, void);
    DECL_FASTCALL_SIMPLE(TestForSniperBullet, _ZN11CBulletInfo19TestForSniperBulletEffffff, bool, float minX, float maxX, float minY, float maxY, float minZ, float maxZ);

    // Member values
    eWeaponType m_nWeaponType;
    CEntity* m_pCreator;
    float m_nDestroyTime;
    bool m_bExists;
    CVector m_vecPosition;
    CVector m_vecVelocity;
    i16 m_nDamage;
DECL_CLASS_END()
CHECKSIZE(CBulletInfo, 0x2C, 0x38);

DECL_OBJECT_ARRAY_ADDR_GLOBAL(CBulletInfo, aBulletInfos, BYBIT(0x7255B4, 0x9A2AE8));
DECL_VALUE_PLT_BOOL_GLOBAL(bPlayerSniperBullet, BYBIT(0x395C90, 0x579938));
DECL_OBJECT_PLT_GLOBAL(CVector, PlayerSniperBulletStart, BYBIT(0x395E58, 0x579CE0));
DECL_OBJECT_PLT_GLOBAL(CVector, PlayerSniperBulletEnd, BYBIT(0x39688C, 0x57B100));
#define aBulletInfos aBulletInfos()
#define bPlayerSniperBullet bPlayerSniperBullet()
#define PlayerSniperBulletStart PlayerSniperBulletStart()
#define PlayerSniperBulletEnd PlayerSniperBulletEnd()

#endif // __AML_PSDK_VCBULLETINFO_H
