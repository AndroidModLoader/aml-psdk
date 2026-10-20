#ifndef __AML_PSDK_SAPEDPLACEMENT_H
#define __AML_PSDK_SAPEDPLACEMENT_H

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/gta_base/Vector.h>

struct CPed;
struct CEntity;

DECL_CLASS(CPedPlacement)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(IsPositionClearForPed, _ZN13CPedPlacement21IsPositionClearForPedERK7CVectorfiPP7CEntityhhh, bool, CVector const& pos, float radius, i32 maxNumObjects, CEntity** objectList, u8 checkVehicles, u8 checkPeds, u8 checkObjects);
    DECL_FASTCALL_SIMPLE(IsPositionClearOfCars1, _ZN13CPedPlacement21IsPositionClearOfCarsEPK7CVector, CEntity*, CVector const* pos);
    inline static CEntity* IsPositionClearOfCars(CVector const* pos) { return IsPositionClearOfCars1(pos); }
    DECL_FASTCALL_SIMPLE(IsPositionClearOfCars2, _ZN13CPedPlacement21IsPositionClearOfCarsEPK4CPed, CEntity*, CPed const* ped);
    inline static CEntity* IsPositionClearOfCars(CPed const* ped) { return IsPositionClearOfCars2(ped); }
    DECL_FASTCALL_SIMPLE(FindZCoorForPed, _ZN13CPedPlacement15FindZCoorForPedEP7CVector, bool, CVector* pos);
DECL_CLASS_END()
CHECKSIZE(CPedPlacement, 0x1, 0x1);

#endif // __AML_PSDK_SAPEDPLACEMENT_H
