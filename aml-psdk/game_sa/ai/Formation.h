#ifndef __AML_PSDK_SAFORMATION_H
#define __AML_PSDK_SAFORMATION_H

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/gta_base/Vector.h>

struct CPed;
struct CVehicle;
struct CMatrix;
struct CPedGroupMembership;

DECL_CLASS(CPointList)
    CPointList() : m_nCount(0), m_abUsedCoords{} {}

    // Member functions
    DECL_THISCALL_SIMPLE(Empty, _ZN10CPointList5EmptyEv, void);
    DECL_THISCALL_HEAD(AddPoint, _ZN10CPointList8AddPointE7CVector, void, CVector point)
    DECL_THISCALL_TAIL(AddPoint, point)
    DECL_THISCALL_HEAD(MergeListsRemovingDoubles, _ZN10CPointList25MergeListsRemovingDoublesEPS_S0_, void, CPointList* list1, CPointList* list2)
    DECL_THISCALL_TAIL(MergeListsRemovingDoubles, list1, list2)

    // Member values
    i32 m_nCount;
    CVector m_avCoords[24];
    bool m_abUsedCoords[24];
DECL_CLASS_END()
CHECKSIZE(CPointList, 0x13C, 0x13C);

DECL_CLASS(CPedList)
    CPedList() : m_nCount(0), m_apPeds{} {}

    // Member functions
    DECL_THISCALL_SIMPLE(Empty, _ZN8CPedList5EmptyEv, void);
    DECL_THISCALL_HEAD(BuildListFromGroup_NoLeader, _ZN8CPedList27BuildListFromGroup_NoLeaderEP19CPedGroupMembership, void, CPedGroupMembership* pedGroupMembership)
    DECL_THISCALL_TAIL(BuildListFromGroup_NoLeader, pedGroupMembership)
    DECL_THISCALL_HEAD(BuildListFromGroup_NotInCar_NoLeader, _ZN8CPedList36BuildListFromGroup_NotInCar_NoLeaderEP19CPedGroupMembership, void, CPedGroupMembership* pedGroupMembership)
    DECL_THISCALL_TAIL(BuildListFromGroup_NotInCar_NoLeader, pedGroupMembership)
    DECL_THISCALL_HEAD(BuildListOfPedsOfPedType, _ZN8CPedList24BuildListOfPedsOfPedTypeEi, void, i32 pedType)
    DECL_THISCALL_TAIL(BuildListOfPedsOfPedType, pedType)
    DECL_THISCALL_SIMPLE(RemovePedsThatDontListenToPlayer, _ZN8CPedList32RemovePedsThatDontListenToPlayerEv, void);
    DECL_THISCALL_HEAD(RemovePedsAttackingPedType, _ZN8CPedList26RemovePedsAttackingPedTypeEi, void, i32 pedType)
    DECL_THISCALL_TAIL(RemovePedsAttackingPedType, pedType)
    DECL_THISCALL_HEAD(ExtractPedsWithGuns, _ZN8CPedList19ExtractPedsWithGunsERS_, void, CPedList& pedList)
    DECL_THISCALL_TAIL(ExtractPedsWithGuns, pedList)
    DECL_THISCALL_HEAD(AddMember, _ZN8CPedList9AddMemberEP4CPed, void, CPed* ped)
    DECL_THISCALL_TAIL(AddMember, ped)
    DECL_THISCALL_SIMPLE(FillUpHoles, _ZN8CPedList11FillUpHolesEv, void);

    // Member values
    i32 m_nCount;
    CPed* m_apPeds[30];
DECL_CLASS_END()
CHECKSIZE(CPedList, 0x7C, 0xF8);

DECL_CLASS(CFormation)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(GenerateGatherDestinations, _ZN10CFormation26GenerateGatherDestinationsEP8CPedListP4CPed, void, CPedList* pedList, CPed* ped);
    DECL_FASTCALL_SIMPLE(GenerateGatherDestinations_AroundCar, _ZN10CFormation36GenerateGatherDestinations_AroundCarEP8CPedListP8CVehicle, void, CPedList* pedList, CVehicle* vehicle);
    DECL_FASTCALL_SIMPLE(FindNearestAvailableDestination, _ZN10CFormation31FindNearestAvailableDestinationE7CVectorRf, i32, CVector pos, float& outDistance);
    DECL_FASTCALL_SIMPLE(DistributeDestinations, _ZN10CFormation22DistributeDestinationsEP8CPedList, void, CPedList* pedList);
    DECL_FASTCALL_SIMPLE(DistributeDestinations_CoverPoints, _ZN10CFormation34DistributeDestinations_CoverPointsEP8CPedList7CVector, void, CPedList* pedList, CVector pos);
    DECL_FASTCALL_SIMPLE(DistributeDestinations_PedsToAttack, _ZN10CFormation35DistributeDestinations_PedsToAttackEP8CPedList, void, CPedList* pedList);
    DECL_FASTCALL_SIMPLE(ReturnDestinationForPed, _ZN10CFormation23ReturnDestinationForPedEP4CPedR7CVector, bool, CPed* ped, CVector& outPos);
    DECL_FASTCALL_SIMPLE(ReturnTargetPedForPed, _ZN10CFormation21ReturnTargetPedForPedEP4CPedPS1_, void, CPed* ped, CPed** outTargetPed);
    DECL_FASTCALL_SIMPLE(FindCoverPoints, _ZN10CFormation15FindCoverPointsE7CVectorf, void, CVector pos, float radius);
    DECL_FASTCALL_SIMPLE(FindCoverPointsBehindBox, _ZN10CFormation24FindCoverPointsBehindBoxEP10CPointList7CVectorP7CMatrixPKS2_S6_S6_f, void, CPointList* pointList, CVector pos, CMatrix* coverEntityMatrix, CVector const* centre, CVector const* min, CVector const* max, float radius);

    // STATIC values
    DECL_OBJECT_PLT(CPointList, m_Destinations, BYBIT(0x6762a0, 0x84a5a0));
    DECL_OBJECT_PLT(CPedList, m_DestinationPeds, BYBIT(0x676df8, 0x84bc38));
    DECL_OBJECT_PLT(CPedList, m_Peds, BYBIT(0x675f48, 0x849f00));
    DECL_OBJECT_ARRAY_PLT(i32, m_aPedLinkToDestinations, BYBIT(0x67779c, 0x84cf60));
    DECL_OBJECT_ARRAY_PLT(i32, m_aFinalPedLinkToDestinations, BYBIT(0x679098, 0x850158));
DECL_CLASS_END()
CHECKSIZE(CFormation, 0x1, 0x1);

#endif // __AML_PSDK_SAFORMATION_H
