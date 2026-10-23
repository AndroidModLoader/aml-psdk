#ifndef __AML_PSDK_SAPEDPATH_H
#define __AML_PSDK_SAPEDPATH_H

#include "../plugin.h"
#include "../../gta_base/Vector.h"
#include "../base/Lists.h"

struct CEntity;

struct CPedPathNode
{
    u8 BlockedState;
    i8 X;
    i8 Y;
    i16 DistanceToTarget;
    CPedPathNode* pNext;
    CPedPathNode* pPrevious;
};
CHECKSIZE(CPedPathNode, 0x10, 0x18);

DECL_CLASS(CPedPath)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(CalcPedRoute, _ZN8CPedPath12CalcPedRouteEh7CVectorS0_PS0_Pss, u8,
        u8 routeType, CVector start, CVector end, CVector* points, i16* numPoints, i16 maxNumPoints);
    DECL_FASTCALL_SIMPLE(AddBlockade, _ZN8CPedPath11AddBlockadeEP7CEntityPA40_12CPedPathNodeP7CVector, void,
        CEntity* entity, CPedPathNode (*nodes)[40], CVector* position);
    DECL_FASTCALL_SIMPLE(AddBlockadeSectorList, _ZN8CPedPath21AddBlockadeSectorListER8CPtrListPA40_12CPedPathNodeP7CVector, void,
        CPtrList& list, CPedPathNode (*nodes)[40], CVector* position);
    DECL_FASTCALL_SIMPLE(AddBuildingBlockade, _ZN8CPedPath19AddBuildingBlockadeEP7CEntityPA40_12CPedPathNodeP7CVector, void,
        CEntity* entity, CPedPathNode (*nodes)[40], CVector* position);
    DECL_FASTCALL_SIMPLE(AddBuildingBlockadeSectorList, _ZN8CPedPath29AddBuildingBlockadeSectorListER8CPtrListPA40_12CPedPathNodeP7CVector, void,
        CPtrList& list, CPedPathNode (*nodes)[40], CVector* position);
DECL_CLASS_END()

#endif // __AML_PSDK_SAPEDPATH_H
