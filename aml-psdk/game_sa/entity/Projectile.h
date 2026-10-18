#ifndef __AML_PSDK_SAPROJECTILE_H
#define __AML_PSDK_SAPROJECTILE_H

/*
    Plugin-SDK (Grand Theft Auto San Andreas) header file
    Authors: GTA Community. See more here
    https://github.com/DK22Pac/plugin-sdk
    Do not delete this comment block. Respect others' work!
*/

#include "Object.h"

DECL_CLASS_BASED(CProjectile, CObject)
    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CProjectile, _ZN11CProjectileC2Ei, i32 modelId)
    DECL_CTORCALL_ARG_TAIL(modelId)
    DECL_DTORCALL_VIRTUAL(CProjectile, _ZN11CProjectileD2Ev, _ZN11CProjectile, _ZTV11CProjectile);
    DECL_THISCALL_SIMPLE(Delete, _ZN11CProjectileD0Ev, void);
DECL_CLASS_END()
CHECKSIZE(CProjectile, 0x184, 0x1F8);

#endif // __AML_PSDK_SAPROJECTILE_H
