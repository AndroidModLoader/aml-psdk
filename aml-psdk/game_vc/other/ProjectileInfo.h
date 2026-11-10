#ifndef __AML_PSDK_VCPROJECTILEINFO_H
#define __AML_PSDK_VCPROJECTILEINFO_H

#include "Weapon.h"

struct CObject;
struct CProjectile;

DECL_CLASS(CProjectileInfo)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(Initialise, _ZN15CProjectileInfo10InitialiseEv, void);
    DECL_FASTCALL_SIMPLE(Shutdown, _ZN15CProjectileInfo8ShutdownEv, void);
    DECL_FASTCALL_SIMPLE(GetProjectileInfo, _ZN15CProjectileInfo17GetProjectileInfoEi, CProjectileInfo*, i32 index);
    DECL_FASTCALL_SIMPLE(AddProjectile, _ZN15CProjectileInfo13AddProjectileEP7CEntity11eWeaponType7CVectorf, bool, CEntity* source, eWeaponType type, CVector position, float force);
    DECL_FASTCALL_SIMPLE(RemoveProjectile, _ZN15CProjectileInfo16RemoveProjectileEPS_P11CProjectile, void, CProjectileInfo* info, CProjectile* projectile);
    DECL_FASTCALL_SIMPLE(RemoveNotAdd, _ZN15CProjectileInfo12RemoveNotAddEP7CEntity11eWeaponType7CVector, void, CEntity* source, eWeaponType type, CVector position);
    DECL_FASTCALL_SIMPLE(Update, _ZN15CProjectileInfo6UpdateEv, void);
    DECL_FASTCALL_SIMPLE(IsProjectileInRange, _ZN15CProjectileInfo19IsProjectileInRangeEffffffb, bool, float minX, float maxX, float minY, float maxY, float minZ, float maxZ, bool destroy);
    DECL_FASTCALL_SIMPLE(RemoveDetonatorProjectiles, _ZN15CProjectileInfo26RemoveDetonatorProjectilesEv, void);
    DECL_FASTCALL_SIMPLE(RemoveAllProjectiles, _ZN15CProjectileInfo20RemoveAllProjectilesEv, void);
    DECL_FASTCALL_SIMPLE(RemoveIfThisIsAProjectile, _ZN15CProjectileInfo25RemoveIfThisIsAProjectileEP7CObject, bool, CObject* object);

    // STATIC values
    DECL_OBJECT_ARRAY_PLT(CProjectile*, ms_apProjectile, BYBIT(0x395BD0, 0x5797C0));

    // Member values
    eWeaponType nWeaponId;
    CEntity* pSource;
    u32 dwTimer;
    bool bInUse;
    CVector vecPos;
DECL_CLASS_END()
CHECKSIZE(CProjectileInfo, 0x1C, 0x28);

DECL_OBJECT_ARRAY_PLT_GLOBAL(CProjectileInfo, gaProjectileInfo, BYBIT(0x3965C8, 0x57AB88));
#define ms_apProjectile ms_apProjectile()
#define gaProjectileInfo gaProjectileInfo()

#endif // __AML_PSDK_VCPROJECTILEINFO_H
