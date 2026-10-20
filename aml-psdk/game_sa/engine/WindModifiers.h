#ifndef __AML_PSDK_SAWINDMODIFIERS_H
#define __AML_PSDK_SAWINDMODIFIERS_H

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/gta_base/Vector.h>

DECL_CLASS(CWindModifier)
    // Member values
    CVector Coors;
    i32 Type;
    float Multiplier;
DECL_CLASS_END()
CHECKSIZE(CWindModifier, 0x14, 0x14);

DECL_CLASS(CWindModifiers)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(RegisterOne, _ZN14CWindModifiers11RegisterOneE7CVectorif, void, CVector pos, i32 type, float multiplier);
    DECL_FASTCALL_SIMPLE(FindWindModifier, _ZN14CWindModifiers16FindWindModifierE7CVectorPfS1_, bool, CVector pos, float* windX, float* windY);

    // STATIC values
    DECL_OBJECT_PLT(i32, Number, BYBIT(0x67968c, 0x850d28));
    DECL_OBJECT_ARRAY_PLT(CWindModifier, Array, BYBIT(0x677334, 0x84c6a0));

DECL_CLASS_END()
CHECKSIZE(CWindModifiers, 0x1, 0x1);

#endif // __AML_PSDK_SAWINDMODIFIERS_H
