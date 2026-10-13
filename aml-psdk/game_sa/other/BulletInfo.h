#ifndef __AML_PSDK_SABULLETINFO_H
#define __AML_PSDK_SABULLETINFO_H

/*
    Plugin-SDK (Grand Theft Auto San Andreas) header file
    Authors: GTA Community. See more here
    https://github.com/DK22Pac/plugin-sdk
    Do not delete this comment block. Respect others' work!
*/

#include "../plugin.h"
#include "../enum/WeaponType.h"
#include <aml-psdk/gta_base/Vector.h>

struct CEntity;

DECL_CLASS(CBulletInfo)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(Initialise, _ZN11CBulletInfo10InitialiseEv, void);
    DECL_FASTCALL_SIMPLE(Shutdown, _ZN11CBulletInfo8ShutdownEv, void);
    DECL_FASTCALL_SIMPLE(AddBullet, _ZN11CBulletInfo9AddBulletEP7CEntity11eWeaponType7CVectorS3_, bool,
        CEntity* creator, eWeaponType weaponType, CVector position, CVector velocity);
    DECL_FASTCALL_SIMPLE(Update, _ZN11CBulletInfo6UpdateEv, void);

    // Member values
    eWeaponType m_nWeaponType;
    CEntity *m_pCreator;
    float m_fDestroyTime;
    bool m_bExists;
    CVector m_vecPosition;
    CVector m_vecVelocity;
    i16 m_nDamage;
DECL_CLASS_END()
CHECKSIZE(CBulletInfo, 0x2C, 0x38);

DECL_OBJECT_ARRAY_ADDR_GLOBAL(CBulletInfo, aBulletInfos, BYBIT(0xA84178, 0xD28A08));
DECL_OBJECT_PLT_GLOBAL(CVector, PlayerSniperBulletStart, BYBIT(0x676464, 0x84A920));
DECL_OBJECT_PLT_GLOBAL(CVector, PlayerSniperBulletEnd, BYBIT(0x67869C, 0x84ED60));

#define aBulletInfos aBulletInfos()
#define PlayerSniperBulletStart PlayerSniperBulletStart()
#define PlayerSniperBulletEnd PlayerSniperBulletEnd()

#endif // __AML_PSDK_SABULLETINFO_H
