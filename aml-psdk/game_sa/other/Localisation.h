#ifndef __AML_PSDK_SALOCALISATION_H
#define __AML_PSDK_SALOCALISATION_H

#include <aml-psdk/game_sa/plugin.h>

DECL_CLASS(CLocalisation)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(Initialise, _ZN13CLocalisation10InitialiseEv, void);
    DECL_FASTCALL_SIMPLE(SetNormalGame, _ZN13CLocalisation13SetNormalGameEv, void);
    DECL_FASTCALL_SIMPLE(SetFrenchGame, _ZN13CLocalisation13SetFrenchGameEv, void);
    DECL_FASTCALL_SIMPLE(SetGermanGame, _ZN13CLocalisation13SetGermanGameEv, void);
    DECL_FASTCALL_SIMPLE(GermanGame, _ZN13CLocalisation10GermanGameEv, u8);
    DECL_FASTCALL_SIMPLE(FrenchGame, _ZN13CLocalisation10FrenchGameEv, u8);
    DECL_FASTCALL_SIMPLE(Metric, _ZN13CLocalisation6MetricEv, u8);
    DECL_FASTCALL_SIMPLE(Blood, _ZN13CLocalisation5BloodEv, u8);
    DECL_FASTCALL_SIMPLE(Porn, _ZN13CLocalisation4PornEv, u8);
    DECL_FASTCALL_SIMPLE(ScreamsFromKills, _ZN13CLocalisation16ScreamsFromKillsEv, u8);
    DECL_FASTCALL_SIMPLE(Prostitutes, _ZN13CLocalisation11ProstitutesEv, u8);
    DECL_FASTCALL_SIMPLE(KickingWhenDown, _ZN13CLocalisation15KickingWhenDownEv, u8);
    DECL_FASTCALL_SIMPLE(ShootLimbs, _ZN13CLocalisation10ShootLimbsEv, u8);
    DECL_FASTCALL_SIMPLE(KnockDownPeds, _ZN13CLocalisation13KnockDownPedsEv, u8);
    DECL_FASTCALL_SIMPLE(KillFrenzy, _ZN13CLocalisation10KillFrenzyEv, u8);
    DECL_FASTCALL_SIMPLE(StealFromDeadPed, _ZN13CLocalisation16StealFromDeadPedEv, u8);
    DECL_FASTCALL_SIMPLE(KillPeds, _ZN13CLocalisation8KillPedsEv, u8);
    DECL_FASTCALL_SIMPLE(PedsOnFire, _ZN13CLocalisation10PedsOnFireEv, u8);

    // STATIC values
    DECL_VALUE_PLT_U8(frenchGame, BYBIT(0x678A14, 0x84F448));
    DECL_VALUE_PLT_U8(germanGame, BYBIT(0x678414, 0x84E840));
    DECL_VALUE_PLT_U8(nastyGame, BYBIT(0x67895C, 0x84F2D8));
DECL_CLASS_END()

#define frenchGame frenchGame()
#define germanGame germanGame()
#define nastyGame nastyGame()

#endif // __AML_PSDK_SALOCALISATION_H
