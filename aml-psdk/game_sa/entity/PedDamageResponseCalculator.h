#ifndef __AML_PSDK_SAPEDDAMAGERESPONSECALCULATOR_H
#define __AML_PSDK_SAPEDDAMAGERESPONSECALCULATOR_H

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/game_sa/enum/WeaponType.h>
#include <aml-psdk/game_sa/enum/PedEnums.h>

struct CPed;
struct CEntity;

DECL_CLASS(CPedDamageResponse)
    CPedDamageResponse() : m_fHealthLost(0.0f), m_fArmourLost(0.0f), m_bKilled(false), m_bInstantKill(false), m_bDamageCalculated(false), m_bAffectsPed(false) {}

    // Member values
    float m_fHealthLost;
    float m_fArmourLost;
    bool m_bKilled;
    bool m_bInstantKill;
    bool m_bDamageCalculated;
    bool m_bAffectsPed;
DECL_CLASS_END()
CHECKSIZE(CPedDamageResponse, 0xC, 0xC);

DECL_CLASS(CPedDamageResponseCalculator)
    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CPedDamageResponseCalculator, _ZN28CPedDamageResponseCalculatorC2EPK7CEntityf11eWeaponType14ePedPieceTypesb, CEntity const* inflictor, float const damage, eWeaponType const weaponType, ePedPieceTypes const pedPiece, bool const jumpedOutOfMovingCar)
    DECL_CTORCALL_ARG_TAIL(inflictor, damage, weaponType, pedPiece, jumpedOutOfMovingCar)
    DECL_DTORCALL(CPedDamageResponseCalculator, _ZN28CPedDamageResponseCalculatorD2Ev);

    // STATIC values
    DECL_OBJECT_PLT(float, ms_fStealthKillDamage, BYBIT(0x679444, 0x8508a0));

    // Member functions
    DECL_THISCALL_HEAD(AdjustPedDamage, _ZN28CPedDamageResponseCalculator15AdjustPedDamageEP4CPed, void, CPed* ped)
    DECL_THISCALL_TAIL(AdjustPedDamage, ped)
    DECL_THISCALL_HEAD(ComputeDamageResponse, _ZN28CPedDamageResponseCalculator21ComputeDamageResponseEP4CPedR18CPedDamageResponseb, void, CPed* ped, CPedDamageResponse& response, bool const speak)
    DECL_THISCALL_TAIL(ComputeDamageResponse, ped, response, speak)
    DECL_THISCALL_HEAD(AccountForPedDamageStats, _ZN28CPedDamageResponseCalculator24AccountForPedDamageStatsEP4CPedR18CPedDamageResponse, void, CPed* ped, CPedDamageResponse& response)
    DECL_THISCALL_TAIL(AccountForPedDamageStats, ped, response)
    DECL_THISCALL_HEAD(AccountForPedArmour, _ZN28CPedDamageResponseCalculator19AccountForPedArmourEP4CPedR18CPedDamageResponse, void, CPed* ped, CPedDamageResponse& response)
    DECL_THISCALL_TAIL(AccountForPedArmour, ped, response)
    DECL_THISCALL_HEAD(ComputeWillKillPed, _ZN28CPedDamageResponseCalculator18ComputeWillKillPedEP4CPedR18CPedDamageResponseb, void, CPed* ped, CPedDamageResponse& response, bool const speak)
    DECL_THISCALL_TAIL(ComputeWillKillPed, ped, response, speak)
    DECL_THISCALL_HEAD(ComputeWillForceDeath, _ZN28CPedDamageResponseCalculator21ComputeWillForceDeathEP4CPedR18CPedDamageResponse, bool, CPed* ped, CPedDamageResponse& response)
    DECL_THISCALL_TAIL(ComputeWillForceDeath, ped, response)
    DECL_THISCALL_HEAD(IsBleedingWeapon, _ZN28CPedDamageResponseCalculator16IsBleedingWeaponEP4CPed, bool, CPed* ped)
    DECL_THISCALL_TAIL(IsBleedingWeapon, ped)

    // Member values
    CEntity const* m_pInflictor;
    float m_fRawDamage;
    ePedPieceTypes m_eHitZone;
    eWeaponType m_eWeaponUsed;
    bool m_bJumpedOutOfMovingCar;
DECL_CLASS_END()
CHECKSIZE(CPedDamageResponseCalculator, 0x14, 0x18);

#endif // __AML_PSDK_SAPEDDAMAGERESPONSECALCULATOR_H
