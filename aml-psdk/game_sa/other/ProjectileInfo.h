#ifndef __AML_PSDK_SAPROJECTILEINFO_H
#define __AML_PSDK_SAPROJECTILEINFO_H

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
struct CObject;
struct CProjectile;
struct FxSystem_c;

DECL_CLASS(CProjectileInfo)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(Initialise, _ZN15CProjectileInfo10InitialiseEv, void);
    DECL_FASTCALL_SIMPLE(Shutdown, _ZN15CProjectileInfo8ShutdownEv, void);
    DECL_FASTCALL_SIMPLE(GetProjectileInfo, _ZN15CProjectileInfo17GetProjectileInfoEi, CProjectileInfo*, i32 infoId);
    DECL_FASTCALL_SIMPLE(AddProjectile, _ZN15CProjectileInfo13AddProjectileEP7CEntity11eWeaponType7CVectorfPS3_S1_, bool,
        CEntity* creator, eWeaponType weaponType, CVector position, float force, CVector* direction, CEntity* victim);
    DECL_FASTCALL_SIMPLE(RemoveProjectile, _ZN15CProjectileInfo16RemoveProjectileEPS_P11CProjectile, void, CProjectileInfo* info, CProjectile* projectile);
    DECL_FASTCALL_SIMPLE(RemoveNotAdd, _ZN15CProjectileInfo12RemoveNotAddEP7CEntity11eWeaponType7CVector, void,
        CEntity* creator, eWeaponType weaponType, CVector position);
    DECL_FASTCALL_SIMPLE(Update, _ZN15CProjectileInfo6UpdateEv, void);
    DECL_FASTCALL_SIMPLE(IsProjectileInRange, _ZN15CProjectileInfo19IsProjectileInRangeEffffffb, bool,
        float x1, float y1, float z1, float x2, float y2, float z2, bool bDestroy);
    DECL_FASTCALL_SIMPLE(RemoveDetonatorProjectiles, _ZN15CProjectileInfo26RemoveDetonatorProjectilesEv, void);
    DECL_FASTCALL_SIMPLE(RemoveAllProjectiles, _ZN15CProjectileInfo20RemoveAllProjectilesEv, void);
    DECL_FASTCALL_SIMPLE(RemoveIfThisIsAProjectile, _ZN15CProjectileInfo25RemoveIfThisIsAProjectileEP7CObject, bool, CObject* object);

    // Member functions
    DECL_THISCALL_HEAD(RemoveFXSystem, _ZN15CProjectileInfo14RemoveFXSystemEh, void, u8 bInstantly)
    DECL_THISCALL_TAIL(RemoveFXSystem, bInstantly)

    // STATIC values
    DECL_OBJECT_ARRAY_PLT(CProjectile*, ms_apProjectile, BYBIT(0x679544, 0x850A98));

    // Member values
    eWeaponType m_nWeaponType;
    CEntity *m_pCreator;
    CEntity *m_pVictim;
    u32 m_nDestroyTime;
    bool m_bActive;
    CVector m_vecLastPosn;
    FxSystem_c *m_pFxSystem;
DECL_CLASS_END()
CHECKSIZE(CProjectileInfo, 0x24, 0x38);

DECL_OBJECT_ARRAY_PLT_GLOBAL(CProjectileInfo, gaProjectileInfo, BYBIT(0x67812C, 0x84E270));

#define ms_apProjectile ms_apProjectile()
#define gaProjectileInfo gaProjectileInfo()

#endif // __AML_PSDK_SAPROJECTILEINFO_H
