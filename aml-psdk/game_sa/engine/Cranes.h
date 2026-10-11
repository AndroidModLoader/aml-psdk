#ifndef __AML_PSDK_SACRANES_H
#define __AML_PSDK_SACRANES_H

#include <aml-psdk/game_sa/plugin.h>

struct CVehicle;

DECL_CLASS(CCranes)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(InitCranes, _ZN7CCranes10InitCranesEv, void);
    DECL_FASTCALL_SIMPLE(IsThisCarPickedUp, _ZN7CCranes17IsThisCarPickedUpEffP8CVehicle, bool, float a1, float a2, CVehicle* vehicle);
    DECL_FASTCALL_SIMPLE(UpdateCranes, _ZN7CCranes12UpdateCranesEv, void);
    DECL_FASTCALL_SIMPLE(IsThisCarBeingCarriedByAnyCrane, _ZN7CCranes31IsThisCarBeingCarriedByAnyCraneEP8CVehicle, bool, CVehicle* vehicle);
    DECL_FASTCALL_SIMPLE(IsThisCarBeingTargettedByAnyCrane, _ZN7CCranes33IsThisCarBeingTargettedByAnyCraneEP8CVehicle, bool, CVehicle* vehicle);
    DECL_FASTCALL_SIMPLE(Save, _ZN7CCranes4SaveEPhPj, void, u8* pBuffer, u32* pSize);
DECL_CLASS_END()

#endif // __AML_PSDK_SACRANES_H
