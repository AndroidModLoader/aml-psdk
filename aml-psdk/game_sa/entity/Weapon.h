#ifndef __AML_PSDK_SAWEAPON_H
#define __AML_PSDK_SAWEAPON_H

#include <aml-psdk/game_sa/plugin.h>
#include "../enum/WeaponType.h"
#include "../enum/PedEnums.h"
#include <aml-psdk/gta_base/Vector.h>

struct FxSystem_c;
struct CColModel;
struct CColPoint;
struct CEntity;
struct CMatrix;
struct CPed;
struct CVehicle;

DECL_CLASS(CWeaponSaveStructure)
    // Member values
    eWeaponType m_eWeaponType;
    eWeaponState m_eState;
    i32 m_nAmmoInClip;
    i32 m_nAmmoTotal;
    u32 m_nTimer;
    bool m_bFirstPersonWeaponModeSelected;
    bool m_bDontPlaceInHand;
    u32 m_pWeaponFxSys;
DECL_CLASS_END()
CHECKSIZE(CWeaponSaveStructure, 0x1C, 0x1C);

DECL_CLASS(CWeapon)
    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CWeapon, _ZN7CWeaponC2E11eWeaponTypei, eWeaponType weaponType, i32 ammo)
    DECL_CTORCALL_ARG_TAIL(weaponType, ammo)

    eWeaponType m_eWeaponType;
    eWeaponState m_nState;
    int m_nAmmoInClip;
    int m_nAmmoTotal;
    unsigned int m_nTimeForNextShot;
    bool m_bFirstPersonWeaponModeSelected;
    bool m_bNoModel;
    FxSystem_c *m_pFxSystem;

    // STATIC functions
    DECL_FASTCALL_SIMPLE(StaticUpdate, _ZN7CWeapon12StaticUpdateEv, void);
    DECL_FASTCALL_SIMPLE(InitialiseWeapons, _ZN7CWeapon17InitialiseWeaponsEv, void);
    DECL_FASTCALL_SIMPLE(ShutdownWeapons, _ZN7CWeapon15ShutdownWeaponsEv, void);
    DECL_FASTCALL_SIMPLE(UpdateWeapons, _ZN7CWeapon13UpdateWeaponsEv, void);
    DECL_FASTCALL_SIMPLE(CanBeUsedFor2Player2, _ZN7CWeapon19CanBeUsedFor2PlayerE11eWeaponType, bool, eWeaponType weaponType);
    DECL_FASTCALL_SIMPLE(DoDoomAiming, _ZN7CWeapon12DoDoomAimingEP7CEntityP7CVectorS3_, void, CEntity* owner, CVector* start, CVector* end);
    DECL_FASTCALL_SIMPLE(DoTankDoomAiming, _ZN7CWeapon16DoTankDoomAimingEP7CEntityS1_P7CVectorS3_, void, CEntity* vehicle, CEntity* owner, CVector* startPoint, CVector* endPoint);
    DECL_FASTCALL_SIMPLE(DoDriveByAutoAiming, _ZN7CWeapon19DoDriveByAutoAimingEP7CEntityP8CVehicleP7CVectorS5_b, void, CEntity* owner, CVehicle* vehicle, CVector* startPoint, CVector* endPoint, bool canAimVehicles);
    DECL_FASTCALL_SIMPLE(CheckForShootingVehicleOccupant, _ZN7CWeapon31CheckForShootingVehicleOccupantEPP7CEntityP9CColPoint11eWeaponTypeRK7CVectorS8_, void, CEntity** pCarEntity, CColPoint* colPoint, eWeaponType weaponType, CVector const& origin, CVector const& target);
    DECL_FASTCALL_SIMPLE(ProcessLineOfSight, _ZN7CWeapon18ProcessLineOfSightERK7CVectorS2_R9CColPointRP7CEntity11eWeaponTypeS6_bbbbbbb, bool, CVector const& startPoint, CVector const& endPoint, CColPoint& outColPoint, CEntity*& outEntity, eWeaponType weaponType, CEntity* arg5, bool buildings, bool vehicles, bool peds, bool objects, bool dummies, bool arg11, bool doIgnoreCameraCheck);
    DECL_FASTCALL_SIMPLE(GenerateDamageEvent, _ZN7CWeapon19GenerateDamageEventEP4CPedP7CEntity11eWeaponTypei14ePedPieceTypesi, u8, CPed* victim, CEntity* creator, eWeaponType weaponType, i32 damageFactor, ePedPieceTypes pedPiece, i32 direction);
    DECL_FASTCALL_SIMPLE(FindNearestTargetEntityWithScreenCoors, _ZN7CWeapon38FindNearestTargetEntityWithScreenCoorsEfff7CVectorPfS1_, CEntity*, float screenX, float screenY, float range, CVector point, float* outX, float* outY);
    DECL_FASTCALL_SIMPLE(PickTargetForHeatSeekingMissile, _ZN7CWeapon31PickTargetForHeatSeekingMissileE7CVectorS0_fP7CEntitybS2_, CEntity*, CVector origin, CVector direction, float distanceMultiplier, CEntity* ignoreEntity, bool fromVehicle, CEntity* lastEntity);
    DECL_FASTCALL_SIMPLE(EvaluateTargetForHeatSeekingMissile, _ZN7CWeapon35EvaluateTargetForHeatSeekingMissileEP7CEntityR7CVectorS3_fbS1_, float, CEntity* entity, CVector& posn, CVector& direction, float distanceMultiplier, bool fromVehicle, CEntity* lastEntity);
    DECL_FASTCALL_SIMPLE(TargetWeaponRangeMultiplier, _ZN7CWeapon27TargetWeaponRangeMultiplierEP7CEntityS1_, float, CEntity* victim, CEntity* weaponOwner);

    // STATIC values
    DECL_VALUE_PLT_BOOL(bPhotographHasBeenTaken, BYBIT(0x6761F0, 0x84A440));
    DECL_VALUE_PLT_BOOL(ms_bTakePhoto, BYBIT(0x67852C, 0x84EA70));
    DECL_VALUE_PLT_I32(m_nTakePhotoFrames, BYBIT(0x678A94, 0x84F550));
    DECL_OBJECT_PLT(CColModel, ms_PelletTestCol, BYBIT(0x67725C, 0x84C4F0));
    DECL_VALUE_PLT_FLT(ms_fExtinguisherAimAngle, BYBIT(0x679FCC, 0x851FA8));

    // Member functions
    DECL_THISCALL_HEAD(Initialise, _ZN7CWeapon10InitialiseE11eWeaponTypeiP4CPed, void, eWeaponType weaponType, i32 ammo, CPed* owner)
    DECL_THISCALL_TAIL(Initialise, weaponType, ammo, owner)
    DECL_THISCALL_SIMPLE(Shutdown, _ZN7CWeapon8ShutdownEv, void);
    DECL_THISCALL_SIMPLE(IsTypeMelee, _ZNK7CWeapon11IsTypeMeleeEv, bool);
    DECL_THISCALL_SIMPLE(IsType2Handed, _ZN7CWeapon13IsType2HandedEv, bool);
    DECL_THISCALL_SIMPLE(IsTypeProjectile, _ZN7CWeapon16IsTypeProjectileEv, bool);
    DECL_THISCALL_NAMED_HEAD(CanBeUsedFor2Player1, CanBeUsedFor2Player, _ZN7CWeapon19CanBeUsedFor2PlayerEv, bool)
    DECL_THISCALL_TAIL(CanBeUsedFor2Player1)
    DECL_THISCALL_HEAD(FireFromCar, _ZN7CWeapon11FireFromCarEP8CVehiclebb, bool, CVehicle* vehicle, bool leftSide, bool rightSide)
    DECL_THISCALL_TAIL(FireFromCar, vehicle, leftSide, rightSide)
    DECL_THISCALL_HEAD(Reload, _ZN7CWeapon6ReloadEP4CPed, void, CPed* owner)
    DECL_THISCALL_TAIL(Reload, owner)
    DECL_THISCALL_HEAD(Update, _ZN7CWeapon6UpdateEP4CPed, void, CPed* owner)
    DECL_THISCALL_TAIL(Update, owner)
    DECL_THISCALL_HEAD(FireInstantHit, _ZN7CWeapon14FireInstantHitEP7CEntityP7CVectorS3_S1_S3_S3_bb, bool, CEntity* firingEntity, CVector* origin, CVector* muzzlePosn, CEntity* targetEntity, CVector* target, CVector* originForDriveBy, bool arg6, bool muzzle)
    DECL_THISCALL_TAIL(FireInstantHit, firingEntity, origin, muzzlePosn, targetEntity, target, originForDriveBy, arg6, muzzle)
    DECL_THISCALL_HEAD(DoBulletImpact, _ZN7CWeapon14DoBulletImpactEP7CEntityS1_P7CVectorS3_P9CColPointi, void, CEntity* owner, CEntity* victim, CVector* startPoint, CVector* endPoint, CColPoint* colPoint, i32 arg5)
    DECL_THISCALL_TAIL(DoBulletImpact, owner, victim, startPoint, endPoint, colPoint, arg5)
    DECL_THISCALL_HEAD(FireProjectile, _ZN7CWeapon14FireProjectileEP7CEntityP7CVectorS1_S3_f, bool, CEntity* firingEntity, CVector* origin, CEntity* targetEntity, CVector* target, float force)
    DECL_THISCALL_TAIL(FireProjectile, firingEntity, origin, targetEntity, target, force)
    DECL_THISCALL_HEAD(FireAreaEffect, _ZN7CWeapon14FireAreaEffectEP7CEntityP7CVectorS1_S3_, bool, CEntity* firingEntity, CVector* origin, CEntity* targetEntity, CVector* target)
    DECL_THISCALL_TAIL(FireAreaEffect, firingEntity, origin, targetEntity, target)
    DECL_THISCALL_HEAD(FireSniper, _ZN7CWeapon10FireSniperEP4CPedP7CEntityP7CVector, bool, CPed* creator, CEntity* victim, CVector* target)
    DECL_THISCALL_TAIL(FireSniper, creator, victim, target)
    DECL_THISCALL_HEAD(TakePhotograph, _ZN7CWeapon14TakePhotographEP7CEntityP7CVector, bool, CEntity* owner, CVector* point)
    DECL_THISCALL_TAIL(TakePhotograph, owner, point)
    DECL_THISCALL_HEAD(FireM16_1stPerson, _ZN7CWeapon17FireM16_1stPersonEP4CPed, bool, CPed* owner)
    DECL_THISCALL_TAIL(FireM16_1stPerson, owner)
    DECL_THISCALL_HEAD(SetUpPelletCol, _ZN7CWeapon14SetUpPelletColEiP7CEntityS1_R7CVectorR9CColPointR7CMatrix, void, i32 numPellets, CEntity* owner, CEntity* victim, CVector& point, CColPoint& colPoint, CMatrix& outMatrix)
    DECL_THISCALL_TAIL(SetUpPelletCol, numPellets, owner, victim, point, colPoint, outMatrix)
    DECL_THISCALL_HEAD(FireInstantHitFromCar, _ZN7CWeapon21FireInstantHitFromCarEP8CVehiclebb, bool, CVehicle* vehicle, bool leftSide, bool rightSide)
    DECL_THISCALL_TAIL(FireInstantHitFromCar, vehicle, leftSide, rightSide)
    DECL_THISCALL_HEAD(FireInstantHitFromCar2, _ZN7CWeapon22FireInstantHitFromCar2E7CVectorS0_P8CVehicleP7CEntity, void, CVector startPoint, CVector endPoint, CVehicle* vehicle, CEntity* owner)
    DECL_THISCALL_TAIL(FireInstantHitFromCar2, startPoint, endPoint, vehicle, owner)
    DECL_THISCALL_HEAD(AddGunshell, _ZN7CWeapon11AddGunshellEP7CEntityRK7CVectorRK9CVector2Df, void, CEntity* creator, CVector const& position, CVector2D const& direction, float size)
    DECL_THISCALL_TAIL(AddGunshell, creator, position, direction, size)
    DECL_THISCALL_SIMPLE(HasWeaponAmmoToBeUsed, _ZN7CWeapon21HasWeaponAmmoToBeUsedEv, bool);
    DECL_THISCALL_HEAD(LaserScopeDot, _ZN7CWeapon13LaserScopeDotEP7CVectorPf, bool, CVector* outCoord, float* outSize)
    DECL_THISCALL_TAIL(LaserScopeDot, outCoord, outSize)
    DECL_THISCALL_HEAD(DoWeaponEffect, _ZN7CWeapon14DoWeaponEffectE7CVectorS0_, void, CVector origin, CVector target)
    DECL_THISCALL_TAIL(DoWeaponEffect, origin, target)
    DECL_THISCALL_SIMPLE(StopWeaponEffect, _ZN7CWeapon16StopWeaponEffectEv, void);
DECL_CLASS_END()
CHECKSIZE(CWeapon, 0x1C, 0x20);

#define bPhotographHasBeenTaken bPhotographHasBeenTaken()
#define ms_bTakePhoto ms_bTakePhoto()
#define m_nTakePhotoFrames m_nTakePhotoFrames()
#define ms_PelletTestCol ms_PelletTestCol()
#define ms_fExtinguisherAimAngle ms_fExtinguisherAimAngle()

#endif // __AML_PSDK_SAWEAPON_H
