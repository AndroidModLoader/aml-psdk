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
    DECL_FASTCALL_SIMPLE(FuncProxy_ctorCProjectile, _ZN11CProjectileC2Ei, void, CProjectile* object, i32 modelId);
    CProjectile(i32 modelId) { FuncProxy_ctorCProjectile(this, modelId); }
    DECL_DTORCALL(CProjectile, _ZN11CProjectileD2Ev);
    DECL_THISCALL_SIMPLE(Delete, _ZN11CProjectileD0Ev, void);
DECL_CLASS_END()
CHECKSIZE(CProjectile, 0x184, 0x1F8);

#endif // __AML_PSDK_SAPROJECTILE_H
