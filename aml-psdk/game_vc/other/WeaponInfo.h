#ifndef __AML_PSDK_VCWEAPONINFO_H
#define __AML_PSDK_VCWEAPONINFO_H

#include "Weapon.h"

enum eWeaponFire : u32
{
    WEAPON_FIRE_MELEE = 0,
    WEAPON_FIRE_INSTANT_HIT = 1,
    WEAPON_FIRE_PROJECTILE = 2,
    WEAPON_FIRE_AREA_EFFECT = 3,
    WEAPON_FIRE_CAMERA = 4
};

DECL_CLASS(CWeaponInfo)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(Initialise, _ZN11CWeaponInfo10InitialiseEv, void);
    DECL_FASTCALL_SIMPLE(Shutdown, _ZN11CWeaponInfo8ShutdownEv, void);
    DECL_FASTCALL_SIMPLE(LoadWeaponData, _ZN11CWeaponInfo14LoadWeaponDataEv, void);
    DECL_FASTCALL_SIMPLE(GetWeaponInfo, _ZN11CWeaponInfo13GetWeaponInfoE11eWeaponType, CWeaponInfo*, eWeaponType type);
    DECL_FASTCALL_SIMPLE(GetWeaponName, _ZN11CWeaponInfo13GetWeaponNameE11eWeaponType, char const*, eWeaponType type);
    DECL_FASTCALL_SIMPLE(FindWeaponType, _ZN11CWeaponInfo14FindWeaponTypeEPc, eWeaponType, char* name);
    DECL_FASTCALL_SIMPLE(FindWeaponFireType, _ZN11CWeaponInfo18FindWeaponFireTypeEPc, eWeaponFire, char* name);

    // STATIC values
    DECL_OBJECT_ARRAY_PLT(char const*, ms_aWeaponNames, BYBIT(0x396810, 0x57B018));
    DECL_OBJECT_ARRAY_PLT(i32, ms_aMaxAmmoForWeapon, BYBIT(0x396E70, 0x57BCD8));
    DECL_OBJECT_ARRAY_PLT(u16, ms_aReloadSampleTime, BYBIT(0x395614, 0x578C88));

    // Member values
    eWeaponFire m_eWeaponFire;
    float m_fRange;
    u32 m_nFiringRate;
    u32 m_nReload;
    i32 m_nAmountofAmmunition;
    u32 m_nDamage;
    float m_fSpeed;
    float m_fRadius;
    float m_fLifespan;
    float m_fSpread;
    CVector m_vecFireOffset;
    i32 m_nAnimToPlay;
    float m_fAnimLoopStart;
    float m_fAnimLoopEnd;
    float m_fAnimFrameFire;
    float m_fAnim2LoopStart;
    float m_fAnim2LoopEnd;
    float m_fAnim2FrameFire;
    float m_fAnimBreakout;
    i32 m_nModelId;
    i32 m_nModel2Id;
    union
    {
        u32 m_nWeaponFlags;
        struct
        {
            u32 m_bUseGravity : 1;
            u32 m_bSlowsDown : 1;
            u32 m_bDissipates : 1;
            u32 m_bRandSpeed : 1;
            u32 m_bExpands : 1;
            u32 m_bExplodes : 1;
            u32 m_bCanAim : 1;
            u32 m_bCanAimWithArm : 1;
            u32 m_b1stPerson : 1;
            u32 m_bHeavy : 1;
            u32 m_bThrow : 1;
            u32 m_bReloadLoop2Start : 1;
            u32 m_bUse2nd : 1;
            u32 m_bGround2nd : 1;
            u32 m_bFinish3rd : 1;
            u32 m_bReload : 1;
            u32 m_bFightMode : 1;
            u32 m_bCrouchFire : 1;
            u32 m_bCop3rd : 1;
            u32 m_bGround3rd : 1;
            u32 m_bPartialAttack : 1;
            u32 m_bAnimDetonate : 1;
        };
    };
    u32 m_WeaponSlot;
DECL_CLASS_END()
CHECKSIZE(CWeaponInfo, 0x64, 0x64);

#define ms_aWeaponNames ms_aWeaponNames()
#define ms_aMaxAmmoForWeapon ms_aMaxAmmoForWeapon()
#define ms_aReloadSampleTime ms_aReloadSampleTime()

#endif // __AML_PSDK_VCWEAPONINFO_H
