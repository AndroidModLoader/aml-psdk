#ifndef __AML_PSDK_VCWEAPON_H
#define __AML_PSDK_VCWEAPON_H

#include <aml-psdk/game_vc/plugin.h>
#include <aml-psdk/gta_base/Vector.h>

struct CEntity;
struct CPhysical;
struct CPed;
struct CVehicle;
struct CColPoint;
struct CColLine;

enum eWeaponType : u32
{
    WEAPONTYPE_UNARMED = 0,
    WEAPONTYPE_BRASSKNUCKLE = 1,
    WEAPONTYPE_SCREWDRIVER = 2,
    WEAPONTYPE_GOLFCLUB = 3,
    WEAPONTYPE_NIGHTSTICK = 4,
    WEAPONTYPE_KNIFE = 5,
    WEAPONTYPE_BASEBALLBAT = 6,
    WEAPONTYPE_HAMMER = 7,
    WEAPONTYPE_CLEAVER = 8,
    WEAPONTYPE_MACHETE = 9,
    WEAPONTYPE_KATANA = 10,
    WEAPONTYPE_CHAINSAW = 11,
    WEAPONTYPE_GRENADE = 12,
    WEAPONTYPE_DETONATOR_GRENADE = 13,
    WEAPONTYPE_TEARGAS = 14,
    WEAPONTYPE_MOLOTOV = 15,
    WEAPONTYPE_ROCKET = 16,
    WEAPONTYPE_PISTOL = 17,
    WEAPONTYPE_PYTHON = 18,
    WEAPONTYPE_SHOTGUN = 19,
    WEAPONTYPE_SPAS12_SHOTGUN = 20,
    WEAPONTYPE_STUBBY_SHOTGUN = 21,
    WEAPONTYPE_TEC9 = 22,
    WEAPONTYPE_UZI = 23,
    WEAPONTYPE_SILENCED_INGRAM = 24,
    WEAPONTYPE_MP5 = 25,
    WEAPONTYPE_M4 = 26,
    WEAPONTYPE_RUGER = 27,
    WEAPONTYPE_SNIPERRIFLE = 28,
    WEAPONTYPE_LASERSCOPE = 29,
    WEAPONTYPE_ROCKETLAUNCHER = 30,
    WEAPONTYPE_FLAMETHROWER = 31,
    WEAPONTYPE_M60 = 32,
    WEAPONTYPE_MINIGUN = 33,
    WEAPONTYPE_DETONATOR = 34,
    WEAPONTYPE_HELICANNON = 35,
    WEAPONTYPE_CAMERA = 36
};

enum eWeaponState : u32
{
    WEAPONSTATE_READY = 0,
    WEAPONSTATE_FIRING = 1,
    WEAPONSTATE_RELOADING = 2,
    WEAPONSTATE_OUT_OF_AMMO = 3
};

DECL_CLASS(CWeapon)
    // Construct/Deconstruct functions
    CWeapon() : CWeapon(WEAPONTYPE_UNARMED, 0) {}
    DECL_CTORCALL_ARG_HEAD(CWeapon, _ZN7CWeaponC2E11eWeaponTypei, eWeaponType type, i32 ammo)
    DECL_CTORCALL_ARG_TAIL(type, ammo)

    // STATIC functions
    DECL_FASTCALL_SIMPLE(InitialiseWeapons, _ZN7CWeapon17InitialiseWeaponsEv, void);
    DECL_FASTCALL_SIMPLE(ShutdownWeapons, _ZN7CWeapon15ShutdownWeaponsEv, void);
    DECL_FASTCALL_SIMPLE(UpdateWeapons, _ZN7CWeapon13UpdateWeaponsEv, void);
    DECL_FASTCALL_SIMPLE(AddGunFlashBigGuns, _ZN7CWeapon18AddGunFlashBigGunsE7CVectorS0_, void, CVector start, CVector end);
    DECL_FASTCALL_SIMPLE(GenerateFlameThrowerParticles, _ZN7CWeapon29GenerateFlameThrowerParticlesE7CVectorS0_, void, CVector start, CVector direction);
    DECL_FASTCALL_SIMPLE(DoDoomAiming, _ZN7CWeapon12DoDoomAimingEP7CEntityP7CVectorS3_, void, CEntity* owner, CVector* start, CVector* end);
    DECL_FASTCALL_SIMPLE(DoTankDoomAiming, _ZN7CWeapon16DoTankDoomAimingEP7CEntityS1_P7CVectorS3_, void, CEntity* entity, CEntity* owner, CVector* start, CVector* end);
    DECL_FASTCALL_SIMPLE(DoDriveByAutoAiming, _ZN7CWeapon19DoDriveByAutoAimingEP7CEntityP8CVehicleP7CVectorS5_, void, CEntity* owner, CVehicle* vehicle, CVector* start, CVector* end);
    DECL_FASTCALL_SIMPLE(MakePedsJumpAtShot, _ZN7CWeapon18MakePedsJumpAtShotEP9CPhysicalP7CVectorS3_, void, CPhysical* owner, CVector* start, CVector* end);
    DECL_FASTCALL_SIMPLE(BlowUpExplosiveThings, _ZN7CWeapon21BlowUpExplosiveThingsEP7CEntity, void, CEntity* entity);
    DECL_FASTCALL_SIMPLE(CheckForShootingVehicleOccupant, _ZN7CWeapon31CheckForShootingVehicleOccupantEPP7CEntityP9CColPoint11eWeaponTypeRK7CVectorS8_, void, CEntity** entity, CColPoint* colPoint, eWeaponType type, CVector const& start, CVector const& end);
    DECL_FASTCALL_SIMPLE(ProcessLineOfSight, _ZN7CWeapon18ProcessLineOfSightERK7CVectorS2_R9CColPointRP7CEntity11eWeaponTypeS6_bbbbbbb, bool, CVector const& start, CVector const& end, CColPoint& colPoint, CEntity*& entity, eWeaponType type, CEntity* owner, bool buildings, bool vehicles, bool peds, bool objects, bool dummies, bool seeThrough, bool cameraIgnore);

    // STATIC values
    DECL_VALUE_PLT_BOOL(bPhotographHasBeenTaken, BYBIT(0x395C98, 0x579948));

    // Member functions
    DECL_THISCALL_HEAD(Initialise, _ZN7CWeapon10InitialiseE11eWeaponTypei, void, eWeaponType type, i32 ammo)
    DECL_THISCALL_TAIL(Initialise, type, ammo)
    DECL_THISCALL_SIMPLE(Shutdown, _ZN7CWeapon8ShutdownEv, void);
    DECL_THISCALL_HEAD(Fire, _ZN7CWeapon4FireEP7CEntityP7CVector, bool, CEntity* owner, CVector* source)
    DECL_THISCALL_TAIL(Fire, owner, source)
    DECL_THISCALL_HEAD(FireFromCar, _ZN7CWeapon11FireFromCarEP8CVehiclebb, bool, CVehicle* vehicle, bool left, bool right)
    DECL_THISCALL_TAIL(FireFromCar, vehicle, left, right)
    DECL_THISCALL_HEAD(FireInstantHit, _ZN7CWeapon14FireInstantHitEP7CEntityP7CVector, bool, CEntity* owner, CVector* source)
    DECL_THISCALL_TAIL(FireInstantHit, owner, source)
    DECL_THISCALL_HEAD(AddGunshell, _ZN7CWeapon11AddGunshellEP7CEntityRK7CVectorRK9CVector2Df, void, CEntity* owner, CVector const& source, CVector2D const& direction, float size)
    DECL_THISCALL_TAIL(AddGunshell, owner, source, direction, size)
    DECL_THISCALL_HEAD(DoBulletImpact, _ZN7CWeapon14DoBulletImpactEP7CEntityS1_P7CVectorS3_P9CColPoint9CVector2D, void, CEntity* owner, CEntity* victim, CVector* start, CVector* end, CColPoint* colPoint, CVector2D ahead)
    DECL_THISCALL_TAIL(DoBulletImpact, owner, victim, start, end, colPoint, ahead)
    DECL_THISCALL_HEAD(FireShotgun, _ZN7CWeapon11FireShotgunEP7CEntityP7CVector, bool, CEntity* owner, CVector* source)
    DECL_THISCALL_TAIL(FireShotgun, owner, source)
    DECL_THISCALL_HEAD(FireProjectile, _ZN7CWeapon14FireProjectileEP7CEntityP7CVectorf, bool, CEntity* owner, CVector* source, float force)
    DECL_THISCALL_TAIL(FireProjectile, owner, source, force)
    DECL_THISCALL_HEAD(FireAreaEffect, _ZN7CWeapon14FireAreaEffectEP7CEntityP7CVector, bool, CEntity* owner, CVector* source)
    DECL_THISCALL_TAIL(FireAreaEffect, owner, source)
    DECL_THISCALL_HEAD(LaserScopeDot, _ZN7CWeapon13LaserScopeDotEP7CVectorPf, bool, CVector* position, float* distance)
    DECL_THISCALL_TAIL(LaserScopeDot, position, distance)
    DECL_THISCALL_HEAD(FireSniper, _ZN7CWeapon10FireSniperEP7CEntity, bool, CEntity* owner)
    DECL_THISCALL_TAIL(FireSniper, owner)
    DECL_THISCALL_HEAD(TakePhotograph, _ZN7CWeapon14TakePhotographEP7CEntity, bool, CEntity* owner)
    DECL_THISCALL_TAIL(TakePhotograph, owner)
    DECL_THISCALL_HEAD(FireM16_1stPerson, _ZN7CWeapon17FireM16_1stPersonEP7CEntity, bool, CEntity* owner)
    DECL_THISCALL_TAIL(FireM16_1stPerson, owner)
    DECL_THISCALL_HEAD(FireInstantHitFromCar, _ZN7CWeapon21FireInstantHitFromCarEP8CVehiclebb, bool, CVehicle* vehicle, bool left, bool right)
    DECL_THISCALL_TAIL(FireInstantHitFromCar, vehicle, left, right)
    DECL_THISCALL_SIMPLE(Reload, _ZN7CWeapon6ReloadEv, void);
    DECL_THISCALL_HEAD(Update, _ZN7CWeapon6UpdateEiP4CPed, void, i32 audioEntity, CPed* ped)
    DECL_THISCALL_TAIL(Update, audioEntity, ped)
    DECL_THISCALL_SIMPLE(IsTypeMelee, _ZN7CWeapon11IsTypeMeleeEv, bool);
    DECL_THISCALL_SIMPLE(IsType2Handed, _ZN7CWeapon13IsType2HandedEv, bool);
    DECL_THISCALL_SIMPLE(HasWeaponAmmoToBeUsed, _ZN7CWeapon21HasWeaponAmmoToBeUsedEv, bool);
    DECL_THISCALL_HEAD(HitsGround, _ZN7CWeapon10HitsGroundEP7CEntityP7CVectorS1_, bool, CEntity* owner, CVector* source, CEntity* target)
    DECL_THISCALL_TAIL(HitsGround, owner, source, target)
    DECL_THISCALL_HEAD(FireMelee, _ZN7CWeapon9FireMeleeEP7CEntityR7CVector, bool, CEntity* owner, CVector& source)
    DECL_THISCALL_TAIL(FireMelee, owner, source)
    DECL_THISCALL_NAMED_HEAD(FireMelee1, FireMelee, _ZN7CWeapon9FireMeleeEP7CEntityRK8CColLine, bool, CEntity* owner, CColLine const& line)
    DECL_THISCALL_TAIL(FireMelee1, owner, line)

    // Member values
    eWeaponType m_eWeaponType;
    eWeaponState m_eWeaponState;
    u32 m_nAmmoInClip;
    u32 m_nAmmoTotal;
    u32 m_nNextShotTime;
    bool m_bAddRotOffset;
DECL_CLASS_END()
CHECKSIZE(CWeapon, 0x18, 0x18);

#define bPhotographHasBeenTaken bPhotographHasBeenTaken()

#endif // __AML_PSDK_VCWEAPON_H
