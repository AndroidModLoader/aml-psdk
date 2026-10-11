#ifndef __AML_PSDK_SAGANGINFO_H
#define __AML_PSDK_SAGANGINFO_H

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/game_sa/enum/WeaponType.h>

DECL_CLASS(CGangInfo)
    // Member values
    i8                                 PedModelOverride;
    eWeaponType                        FirstWeapon;
    eWeaponType                        SecondWeapon;
    eWeaponType                        ThirdWeapon;

    // Functions
    DECL_CTORCALL(CGangInfo, _ZN9CGangInfoC2Ev);
    DECL_DTORCALL(CGangInfo, _ZN9CGangInfoD2Ev);

DECL_CLASS_END()
CHECKSIZE(CGangInfo, 0x10, 0x10);  // 64-bit from the IDB; 32-bit measured from this layout

#endif // __AML_PSDK_SAGANGINFO_H
