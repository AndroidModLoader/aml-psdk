#ifndef __AML_PSDK_SAPEDGROUPPLACER_H
#define __AML_PSDK_SAPEDGROUPPLACER_H

#include "../plugin.h"
#include "../enum/PedEnums.h"
#include "../../gta_base/Vector.h"

DECL_CLASS(CPedGroupPlacer)
    // Member functions
    DECL_THISCALL_HEAD(PlaceGroup, _ZNK15CPedGroupPlacer10PlaceGroupE8ePedTypeiRK7CVectori, bool,
        ePedType pedType, i32 modelId, CVector const& position, i32 gangSize)
    DECL_THISCALL_TAIL(PlaceGroup, pedType, modelId, position, gangSize)
    DECL_THISCALL_HEAD(PlaceFormationGroup, _ZNK15CPedGroupPlacer19PlaceFormationGroupE8ePedTypeiRK7CVectori, bool,
        ePedType pedType, i32 modelId, CVector const& position, i32 gangSize)
    DECL_THISCALL_TAIL(PlaceFormationGroup, pedType, modelId, position, gangSize)
    DECL_THISCALL_HEAD(PlaceChatGroup, _ZNK15CPedGroupPlacer14PlaceChatGroupE8ePedTypeiRK7CVectori, bool,
        ePedType pedType, i32 modelId, CVector const& position, i32 gangSize)
    DECL_THISCALL_TAIL(PlaceChatGroup, pedType, modelId, position, gangSize)
    DECL_THISCALL_HEAD(PlaceRandomGroup, _ZNK15CPedGroupPlacer16PlaceRandomGroupE8ePedTypeiRK7CVectori, bool,
        ePedType pedType, i32 modelId, CVector const& position, i32 gangSize)
    DECL_THISCALL_TAIL(PlaceRandomGroup, pedType, modelId, position, gangSize)

    // STATIC values
    DECL_OBJECT_PLT(i32 const, ms_minGangSize, BYBIT(0x676048, 0x84A100));
    DECL_OBJECT_PLT(i32 const, ms_maxGangSize, BYBIT(0x6760C0, 0x84A1F0));
DECL_CLASS_END()

#define ms_minGangSize ms_minGangSize()
#define ms_maxGangSize ms_maxGangSize()

#endif // __AML_PSDK_SAPEDGROUPPLACER_H
