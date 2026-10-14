#ifndef __AML_PSDK_SAPATHFIND_H
#define __AML_PSDK_SAPATHFIND_H

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/game_sa/base/Matrix.h>
#include <aml-psdk/game_sa/base/Lists.h> // CNodeAddress

#define NUM_PATH_MAP_AREAS 64
#define NUM_PATH_INTERIOR_AREAS 8

struct RwStream;
struct CTempPathNode;

struct CPathNode
{
    inline CVector GetNodeCoors()
    {
        return m_vecPosn.Uncompressed();
    }
    
    CPathNode *m_pNext;
    CPathNode *m_pPrev;
    CompressedVector m_vecPosn;
    short m_nSearchList; //!< search list id
    short m_nBaseLinkId;
    union
    {
        struct 
        {
            unsigned short m_nAreaId;
            unsigned short m_nNodeId;
        };
        CNodeAddress m_Node;
    };
    unsigned char m_nPathWidth;
    unsigned char m_nFloodFill;
    
    union
    {
        struct
        {
            unsigned char m_nNumLinks : 4;
            unsigned char m_nTrafficLevel : 2;
            unsigned char m_bRoadBlocks : 1;
            unsigned char m_bWaterNode : 1;
        };
        struct
        {
            unsigned char : 4;
            unsigned char m_bOnDeadEnd : 1;
            unsigned char m_bSwitchedOff : 1;
            unsigned char : 2;
        };
    };
    union
    {
        struct
        {
            unsigned char m_bEmergencyVehiclesOnly : 1;
            unsigned char m_bAlreadyFound : 1;   //!< not used in paths data files
            unsigned char m_bDontWander : 1;
            unsigned char m_bInteriorNode : 1;   //!< not used in paths data files
            unsigned char m_bNotHighway : 1;
            unsigned char m_bHighway : 1;
            unsigned char unk3 : 1;             //!< not used in paths data files
            unsigned char unk4 : 1;             //!< not used in paths data files
        };
        struct
        {
            unsigned char : 4;
            unsigned char m_nSpeed : 2;
            unsigned char : 2;
        };
    };

    unsigned char m_nSpawnProbability : 4;
    unsigned char m_nBehaviourType : 4; //!< 1 - roadblock, 2 - parking node
};

DECL_CLASS(CCarPathLink)
    // Member functions
    DECL_THISCALL_SIMPLE(OneWayLaneOffset, _ZN12CCarPathLink16OneWayLaneOffsetEv, float);

    CompressedVector2D m_vecPosn;
    CNodeAddress m_address;
    signed char m_nDirX;
    signed char m_nDirY;
    unsigned char m_nPathNodeWidth;
    
    unsigned char m_nNumLeftLanes : 3;
    unsigned char m_nNumRightLanes : 3;
    unsigned char m_bTrafficLightDirection : 1; //!< 1 if the navi node has the same direction as the traffic light and 0 if the navi node points somewhere else
    unsigned char unk1 : 1;

    unsigned char m_nTrafficLightState : 2; //!< 1 - North-South, 2 - West-East cycle
    unsigned char m_bTrainCrossing : 1;
DECL_CLASS_END()

struct CPathIntersectionInfo
{
    unsigned char m_bRoadCross : 1;
    unsigned char m_bPedTrafficLight : 1;
};

struct CForbiddenArea
{
    float m_fX1;
    float m_fX2;
    float m_fY1;
    float m_fY2;
    float m_fZ1;
    float m_fZ2;
    bool m_bEnable;
    bool m_nType;
};

struct CLinkAddress
{
    unsigned short Address;
};


DECL_CLASS(CPathFind)
    CPathFind(){}
    
    // Member functions
    DECL_THISCALL_HEAD(StoreNodeInfoCar, _ZN9CPathFind16StoreNodeInfoCarEssaasssfaabbhbbhh, void, i16 arg1, i16 arg2, i8 arg3, i8 arg4, i16 arg5, i16 arg6, i16 arg7, float arg8, i8 arg9, i8 arg10, bool arg11, bool arg12, u8 arg13, bool arg14, bool arg15, u8 arg16, u8 arg17)
    DECL_THISCALL_TAIL(StoreNodeInfoCar, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17)
    DECL_THISCALL_HEAD(StoreNodeInfoPed, _ZN9CPathFind16StoreNodeInfoPedEssaasssfbhbh, void, i16 arg1, i16 arg2, i8 arg3, i8 arg4, i16 arg5, i16 arg6, i16 arg7, float arg8, bool arg9, u8 arg10, bool arg11, u8 arg12)
    DECL_THISCALL_TAIL(StoreNodeInfoPed, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12)
    DECL_THISCALL_HEAD(StoreDetachedNodeInfoPed, _ZN9CPathFind24StoreDetachedNodeInfoPedEiaiffffbbbhbhb, void, i32 arg1, i8 arg2, i32 arg3, float arg4, float arg5, float arg6, float arg7, bool arg8, bool arg9, bool arg10, u8 arg11, bool arg12, u8 arg13, bool arg14)
    DECL_THISCALL_TAIL(StoreDetachedNodeInfoPed, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14)
    DECL_THISCALL_HEAD(StoreDetachedNodeInfoCar, _ZN9CPathFind24StoreDetachedNodeInfoCarEiaiffffaabbhbbhbh, void, i32 arg1, i8 arg2, i32 arg3, float arg4, float arg5, float arg6, float arg7, i8 arg8, i8 arg9, bool arg10, bool arg11, u8 arg12, bool arg13, bool arg14, u8 arg15, bool arg16, u8 arg17)
    DECL_THISCALL_TAIL(StoreDetachedNodeInfoCar, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15, arg16, arg17)
    DECL_THISCALL_HEAD(RegisterMarker, _ZN9CPathFind14RegisterMarkerEP7CVector, void, CVector* pCVector1)
    DECL_THISCALL_TAIL(RegisterMarker, pCVector1)
    DECL_THISCALL_HEAD(SwitchRoadsInAngledArea, _ZN9CPathFind23SwitchRoadsInAngledAreaEfffffffhh, void, float arg1, float arg2, float arg3, float arg4, float arg5, float arg6, float arg7, u8 arg8, u8 arg9)
    DECL_THISCALL_TAIL(SwitchRoadsInAngledArea, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9)
    DECL_THISCALL_HEAD(MarkRoadsBetweenLevelsInArea, _ZN9CPathFind28MarkRoadsBetweenLevelsInAreaEffffff, void, float arg1, float arg2, float arg3, float arg4, float arg5, float arg6)
    DECL_THISCALL_TAIL(MarkRoadsBetweenLevelsInArea, arg1, arg2, arg3, arg4, arg5, arg6)
    DECL_THISCALL_HEAD(PedMarkRoadsBetweenLevelsInArea, _ZN9CPathFind31PedMarkRoadsBetweenLevelsInAreaEffffff, void, float arg1, float arg2, float arg3, float arg4, float arg5, float arg6)
    DECL_THISCALL_TAIL(PedMarkRoadsBetweenLevelsInArea, arg1, arg2, arg3, arg4, arg5, arg6)
    DECL_THISCALL_HEAD(MarkRoadsBetweenLevelsNodeAndNeighbours, _ZN9CPathFind39MarkRoadsBetweenLevelsNodeAndNeighboursEi, void, i32 arg1)
    DECL_THISCALL_TAIL(MarkRoadsBetweenLevelsNodeAndNeighbours, arg1)
    DECL_THISCALL_SIMPLE(Init, _ZN9CPathFind4InitEv, void);
    DECL_THISCALL_SIMPLE(ReInit, _ZN9CPathFind6ReInitEv, void);
    DECL_THISCALL_SIMPLE(ReleaseRequestedNodes, _ZN9CPathFind21ReleaseRequestedNodesEv, void);
    DECL_THISCALL_SIMPLE(PreparePathData, _ZN9CPathFind15PreparePathDataEv, void);
    DECL_THISCALL_SIMPLE(CheckGrid, _ZN9CPathFind9CheckGridEv, void);
    DECL_THISCALL_SIMPLE(AllocatePathFindInfoMem, _ZN9CPathFind23AllocatePathFindInfoMemEv, void);
    DECL_THISCALL_SIMPLE(TidyUpNodeSwitchesAfterMission, _ZN9CPathFind30TidyUpNodeSwitchesAfterMissionEv, void);
    DECL_THISCALL_SIMPLE(UnMarkAllRoadNodesAsDontWander, _ZN9CPathFind30UnMarkAllRoadNodesAsDontWanderEv, void);
    DECL_THISCALL_SIMPLE(Shutdown, _ZN9CPathFind8ShutdownEv, void);
    DECL_THISCALL_SIMPLE(HaveRequestedNodesBeenLoaded, _ZN9CPathFind28HaveRequestedNodesBeenLoadedEv, bool);
    DECL_THISCALL_SIMPLE(Save, _ZN9CPathFind4SaveEv, bool);
    DECL_THISCALL_SIMPLE(Load, _ZN9CPathFind4LoadEv, bool);

    DECL_THISCALL_HEAD(LoadPathFindData1, _ZN9CPathFind16LoadPathFindDataEi, void, i32 Region)
    DECL_THISCALL_TAIL(LoadPathFindData1, Region)

    DECL_THISCALL_HEAD(LoadPathFindData2, _ZN9CPathFind16LoadPathFindDataEP8RwStreami, void, RwStream *pStream, i32 Region)
    DECL_THISCALL_TAIL(LoadPathFindData2, pStream, Region)

    DECL_THISCALL_HEAD(SwitchRoadsOffInAreaForOneRegion, _ZN9CPathFind32SwitchRoadsOffInAreaForOneRegionEffffffbbib, void, float MinX, float MaxX, float MinY, float MaxY, float MinZ, float MaxZ, bool SwitchRoadsOff, bool bCars, i32 Region, bool bBackToOriginal)
    DECL_THISCALL_TAIL(SwitchRoadsOffInAreaForOneRegion, MinX, MaxX, MinY, MaxY, MinZ, MaxZ, SwitchRoadsOff, bCars, Region, bBackToOriginal)

    DECL_THISCALL_HEAD(UnLoadPathFindData, _ZN9CPathFind18UnLoadPathFindDataEi, void, i32 Region)
    DECL_THISCALL_TAIL(UnLoadPathFindData, Region)

    DECL_THISCALL_HEAD(ComputeRoute, _ZN9CPathFind12ComputeRouteEhRK7CVectorS2_RK12CNodeAddressR10CNodeRoute, void, const u8 GraphType, CVector const &StartCoors, CVector const &TargetCoors, CNodeAddress const &StartNode, CNodeRoute &route)
    DECL_THISCALL_TAIL(ComputeRoute, GraphType, StartCoors, TargetCoors, StartNode, route)

    DECL_THISCALL_HEAD(DoPathSearch, _ZN9CPathFind12DoPathSearchEh7CVector12CNodeAddressS0_PS1_PsiPffS2_fbS1_bb, void,
        u8 GraphType, CVector StartCoors, CNodeAddress StartNode, CVector TargetCoors, CNodeAddress *pNodeList, i16 *pNumNodesGiven,
        i32 NumNodesRequested, float *pDistance, float CutoffDistForNodeSearch, CNodeAddress *pGivenTargetNode, float MaxSearchDistance,
        bool bDontGoAgainstTraffic, CNodeAddress NodeToAvoid, bool bAmphibiousVehicle, bool bBoat)
    DECL_THISCALL_TAIL(DoPathSearch, GraphType, StartCoors, StartNode, TargetCoors, pNodeList, pNumNodesGiven, NumNodesRequested, pDistance,
        CutoffDistForNodeSearch, pGivenTargetNode, MaxSearchDistance, bDontGoAgainstTraffic, NodeToAvoid, bAmphibiousVehicle, bBoat)

    DECL_THISCALL_HEAD(FindNodeClosestToCoors, _ZN9CPathFind22FindNodeClosestToCoorsE7CVectorhfbbbbb, CNodeAddress, CVector SearchCoors, u8 GraphType, float CutoffDist, bool bIgnoreSwitchedOff, bool bIgnoreBetweenLevels, bool bIgnoreAlreadyFound, bool bBoatNodes, bool bIgnoreInteriors)
    DECL_THISCALL_TAIL(FindNodeClosestToCoors, SearchCoors, GraphType, CutoffDist, bIgnoreSwitchedOff, bIgnoreBetweenLevels, bIgnoreAlreadyFound, bBoatNodes, bIgnoreInteriors)

    DECL_THISCALL_HEAD(AddNodeToList, _ZN9CPathFind13AddNodeToListEP9CPathNodei, void, CPathNode *pNode, i32 Dist)
    DECL_THISCALL_TAIL(AddNodeToList, pNode, Dist)

    DECL_THISCALL_HEAD(RemoveNodeFromList, _ZN9CPathFind18RemoveNodeFromListEP9CPathNode, void, CPathNode *pNode)
    DECL_THISCALL_TAIL(RemoveNodeFromList, pNode)

    DECL_THISCALL_HEAD(RemoveBadStartNode, _ZN9CPathFind18RemoveBadStartNodeE7CVectorP12CNodeAddressPs, void, CVector StartCoors, CNodeAddress *pNodeList, i16 *pNumNodes)
    DECL_THISCALL_TAIL(RemoveBadStartNode, StartCoors, pNodeList, pNumNodes)

    DECL_THISCALL_HEAD(CountFloodFillGroups, _ZN9CPathFind20CountFloodFillGroupsEh, void, u8 GraphType)
    DECL_THISCALL_TAIL(CountFloodFillGroups, GraphType)

    DECL_THISCALL_HEAD(FindNextNodeWandering, _ZN9CPathFind21FindNextNodeWanderingEh7CVectorP12CNodeAddressS2_hPh, void, u8 GraphType, CVector CurrentCoors, CNodeAddress *pCurrentNode, CNodeAddress *pResultNode, u8 Direction, u8 *pDirectionFound)
    DECL_THISCALL_TAIL(FindNextNodeWandering, GraphType, CurrentCoors, pCurrentNode, pResultNode, Direction, pDirectionFound)

    DECL_THISCALL_HEAD(GeneratePedCreationCoors, _ZN9CPathFind24GeneratePedCreationCoorsEffffffP7CVectorP12CNodeAddressS3_PfbP7CMatrix, u8,
        float CentreX, float CentreY, float MinRad, float MaxRad, float MinRadClose, float MaxRadClose, CVector *pResult,
        CNodeAddress *pFromNode, CNodeAddress *pToNode, float *pFraction, bool bIncludeSwitchedOffs, CMatrix *pInvCam)
    DECL_THISCALL_TAIL(GeneratePedCreationCoors, CentreX, CentreY, MinRad, MaxRad, MinRadClose, MaxRadClose, pResult, pFromNode, pToNode, pFraction, bIncludeSwitchedOffs, pInvCam)

    DECL_THISCALL_HEAD(FindRegionForCoors, _ZN9CPathFind18FindRegionForCoorsEff, i32, float X, float Y)
    DECL_THISCALL_TAIL(FindRegionForCoors, X, Y)

    DECL_THISCALL_HEAD(GeneratePedCreationCoors_Interior, _ZN9CPathFind33GeneratePedCreationCoors_InteriorEffP7CVectorP12CNodeAddressS3_Pf, bool,
        float CentreX, float CentreY, CVector *pResult, CNodeAddress *pFromNode, CNodeAddress *pToNode, float *pFraction)
    DECL_THISCALL_TAIL(GeneratePedCreationCoors_Interior, CentreX, CentreY, pResult, pFromNode, pToNode, pFraction)

    DECL_THISCALL_HEAD(TestCoorsCloseness, _ZN9CPathFind18TestCoorsClosenessE7CVectorhS0_, bool, CVector Coors, u8 GraphType, CVector PlayerCoors)
    DECL_THISCALL_TAIL(TestCoorsCloseness, Coors, GraphType, PlayerCoors)

    DECL_THISCALL_HEAD(CalcRoadDensity, _ZN9CPathFind15CalcRoadDensityEff, float, float TestX, float TestY)
    DECL_THISCALL_TAIL(CalcRoadDensity, TestX, TestY)

    DECL_THISCALL_HEAD(CalcDistToAnyConnectingLinks, _ZN9CPathFind28CalcDistToAnyConnectingLinksEP9CPathNode7CVector, float, CPathNode *pNode, CVector SearchCoors)
    DECL_THISCALL_TAIL(CalcDistToAnyConnectingLinks, pNode, SearchCoors)

    DECL_THISCALL_HEAD(FindNodeClosestInRegion, _ZN9CPathFind23FindNodeClosestInRegionEP12CNodeAddresst7CVectorhPfbbbb, void,
        CNodeAddress *pNodeFound, u16 Region, CVector SearchCoors, u8 GraphType, float *pClosestDist, bool bIgnoreSwitchedOff, bool bIgnoreAlreadyFound, bool bBoatNodes, bool bIgnoreInteriors)
    DECL_THISCALL_TAIL(FindNodeClosestInRegion, pNodeFound, Region, SearchCoors, GraphType, pClosestDist, bIgnoreSwitchedOff, bIgnoreAlreadyFound, bBoatNodes, bIgnoreInteriors)

    DECL_THISCALL_HEAD(FindXRegionForCoors, _ZN9CPathFind19FindXRegionForCoorsEf, i32, float X)
    DECL_THISCALL_TAIL(FindXRegionForCoors, X)

    DECL_THISCALL_HEAD(FindYRegionForCoors, _ZN9CPathFind19FindYRegionForCoorsEf, i32, float Y)
    DECL_THISCALL_TAIL(FindYRegionForCoors, Y)

    DECL_THISCALL_HEAD(FindXCoorsForRegion, _ZN9CPathFind19FindXCoorsForRegionEi, float, i32 Region)
    DECL_THISCALL_TAIL(FindXCoorsForRegion, Region)

    DECL_THISCALL_HEAD(FindYCoorsForRegion, _ZN9CPathFind19FindYCoorsForRegionEi, float, i32 Region)
    DECL_THISCALL_TAIL(FindYCoorsForRegion, Region)

    DECL_THISCALL_HEAD(FindNthNodeClosestToCoors, _ZN9CPathFind25FindNthNodeClosestToCoorsE7CVectorhfbbibbP12CNodeAddress, CNodeAddress,
        CVector SearchCoors, u8 GraphType, float CutoffDist, bool bIgnoreSwitchedOff, bool bIgnoreBetweenLevels, i32 N, bool bWaterNode, bool bIgnoreInteriors, CNodeAddress *pNMinus1th)
    DECL_THISCALL_TAIL(FindNthNodeClosestToCoors, SearchCoors, GraphType, CutoffDist, bIgnoreSwitchedOff, bIgnoreBetweenLevels, N, bWaterNode, bIgnoreInteriors, pNMinus1th)

    DECL_THISCALL_HEAD(Find2NodesForCarCreation, _ZN9CPathFind24Find2NodesForCarCreationE7CVectorP12CNodeAddressS2_b, void, CVector SearchCoors, CNodeAddress *ClosestNode, CNodeAddress *OtherNode, bool bIgnoreSwitchedOff)
    DECL_THISCALL_TAIL(Find2NodesForCarCreation, SearchCoors, ClosestNode, OtherNode, bIgnoreSwitchedOff)

    DECL_THISCALL_HEAD(RecordNodesClosestToCoors, _ZN9CPathFind25RecordNodesClosestToCoorsE7CVectorhiP12CNodeAddressfbbbb, void,
        CVector SearchCoors, u8 GraphType, i32 NoOfNodes, CNodeAddress *ClosestNodes, float CutoffDist, bool bIgnoreSwitchedOff, bool bIgnoreBetweenLevels, bool bWaterNode, bool bIgnoreInteriors)
    DECL_THISCALL_TAIL(RecordNodesClosestToCoors, SearchCoors, GraphType, NoOfNodes, ClosestNodes, CutoffDist, bIgnoreSwitchedOff, bIgnoreBetweenLevels, bWaterNode, bIgnoreInteriors)

    DECL_THISCALL_HEAD(These2NodesAreAdjacent, _ZN9CPathFind22These2NodesAreAdjacentE12CNodeAddressS0_, bool, CNodeAddress Node1, CNodeAddress Node2)
    DECL_THISCALL_TAIL(These2NodesAreAdjacent, Node1, Node2)

    DECL_THISCALL_HEAD(RecordNodesInCircle, _ZN9CPathFind19RecordNodesInCircleERK7CVectorfhiP12CNodeAddressbbbbb, i32,
        CVector const &Centre, const float Radius, u8 GraphType, i32 NoOfNodes, CNodeAddress *Nodes, bool bIgnoreSwitchedOff, bool bIgnoreBetweenLevels, bool bIgnoreAlreadyFound, bool bBoatNodes, bool bIgnoreInteriors)
    DECL_THISCALL_TAIL(RecordNodesInCircle, Centre, Radius, GraphType, NoOfNodes, Nodes, bIgnoreSwitchedOff, bIgnoreBetweenLevels, bIgnoreAlreadyFound, bBoatNodes, bIgnoreInteriors)

    DECL_THISCALL_HEAD(FindNodeClosestToCoorsFavourDirection, _ZN9CPathFind37FindNodeClosestToCoorsFavourDirectionE7CVectorhff, CNodeAddress, CVector SearchCoors, u8 GraphType, float DirX, float DirY)
    DECL_THISCALL_TAIL(FindNodeClosestToCoorsFavourDirection, SearchCoors, GraphType, DirX, DirY)

    DECL_THISCALL_HEAD(FindNodePairClosestToCoors, _ZN9CPathFind26FindNodePairClosestToCoorsE7CVectorhP12CNodeAddressS2_Pfffbbb, void,
        CVector SearchCoors, u8 GraphType, CNodeAddress *pNode1, CNodeAddress *pNode2, float *pOrientation, float MinDistApart, float CutoffDistForNodeSearch, bool bIgnoreSwitchedOff, bool bIgnoreBetweenLevels, bool bWaterNode)
    DECL_THISCALL_TAIL(FindNodePairClosestToCoors, SearchCoors, GraphType, pNode1, pNode2, pOrientation, MinDistApart, CutoffDistForNodeSearch, bIgnoreSwitchedOff, bIgnoreBetweenLevels, bWaterNode)

    DECL_THISCALL_HEAD(FindNodeOrientationForCarPlacement, _ZN9CPathFind34FindNodeOrientationForCarPlacementE12CNodeAddress, float, CNodeAddress CarNode)
    DECL_THISCALL_TAIL(FindNodeOrientationForCarPlacement, CarNode)

    DECL_THISCALL_HEAD(FindNodeOrientationForCarPlacementFacingDestination, _ZN9CPathFind51FindNodeOrientationForCarPlacementFacingDestinationE12CNodeAddressffb, float, CNodeAddress CarNode, float DestX, float DestY, bool bTowardsDest)
    DECL_THISCALL_TAIL(FindNodeOrientationForCarPlacementFacingDestination, CarNode, DestX, DestY, bTowardsDest)

    DECL_THISCALL_HEAD(ThisNodeWillLeadIntoADeadEnd, _ZN9CPathFind28ThisNodeWillLeadIntoADeadEndEP9CPathNodeS1_, bool, CPathNode *pToNode, CPathNode *pFromNode)
    DECL_THISCALL_TAIL(ThisNodeWillLeadIntoADeadEnd, pToNode, pFromNode)

    DECL_THISCALL_HEAD(SwitchRoadsOffInArea, _ZN9CPathFind20SwitchRoadsOffInAreaEffffffbbb, void, float MinX, float MaxX, float MinY, float MaxY, float MinZ, float MaxZ, bool SwitchRoadsOff, bool bCars, bool bBackToOriginal)
    DECL_THISCALL_TAIL(SwitchRoadsOffInArea, MinX, MaxX, MinY, MaxY, MinZ, MaxZ, SwitchRoadsOff, bCars, bBackToOriginal)

    DECL_THISCALL_HEAD(SwitchPedRoadsOffInArea, _ZN9CPathFind23SwitchPedRoadsOffInAreaEffffffbb, void, float MinX, float MaxX, float MinY, float MaxY, float MinZ, float MaxZ, bool SwitchRoadsOff, bool bBackToOriginal)
    DECL_THISCALL_TAIL(SwitchPedRoadsOffInArea, MinX, MaxX, MinY, MaxY, MinZ, MaxZ, SwitchRoadsOff, bBackToOriginal)

    DECL_THISCALL_HEAD(ThisNodeHasToBeSwitchedOff, _ZN9CPathFind26ThisNodeHasToBeSwitchedOffEP9CPathNode, bool, CPathNode *pNode)
    DECL_THISCALL_TAIL(ThisNodeHasToBeSwitchedOff, pNode)

    DECL_THISCALL_HEAD(SwitchOffNodeAndNeighbours, _ZN9CPathFind26SwitchOffNodeAndNeighboursEP9CPathNodePS1_S2_bb, void, CPathNode *pNode, CPathNode **ppNextNode1, CPathNode **ppNextNode2, bool bWhatToSwitchTo, bool bBackToOriginal)
    DECL_THISCALL_TAIL(SwitchOffNodeAndNeighbours, pNode, ppNextNode1, ppNextNode2, bWhatToSwitchTo, bBackToOriginal)

    DECL_THISCALL_HEAD(CountNeighboursToBeSwitchedOff, _ZN9CPathFind30CountNeighboursToBeSwitchedOffEP9CPathNode, i32, CPathNode *pNode)
    DECL_THISCALL_TAIL(CountNeighboursToBeSwitchedOff, pNode)

    DECL_THISCALL_HEAD(MarkRoadNodeAsDontWander, _ZN9CPathFind24MarkRoadNodeAsDontWanderEfff, void, float NodeX, float NodeY, float NodeZ)
    DECL_THISCALL_TAIL(MarkRoadNodeAsDontWander, NodeX, NodeY, NodeZ)

    DECL_THISCALL_HEAD(TestForPedTrafficLight, _ZN9CPathFind22TestForPedTrafficLightE12CNodeAddressS0_, bool, CNodeAddress Node1, CNodeAddress Node2)
    DECL_THISCALL_TAIL(TestForPedTrafficLight, Node1, Node2)

    DECL_THISCALL_HEAD(TestCrossesRoad, _ZN9CPathFind15TestCrossesRoadE12CNodeAddressS0_, bool, CNodeAddress Node1, CNodeAddress Node2)
    DECL_THISCALL_TAIL(TestCrossesRoad, Node1, Node2)

    DECL_THISCALL_HEAD(FindStartPointOfRegion, _ZN9CPathFind22FindStartPointOfRegionEiiRfS0_, void, i32 RegionX, i32 RegionY, float &ResultX, float &ResultY)
    DECL_THISCALL_TAIL(FindStartPointOfRegion, RegionX, RegionY, ResultX, ResultY)

    DECL_THISCALL_HEAD(SetLinksBridgeLights, _ZN9CPathFind20SetLinksBridgeLightsEffffb, void, float MinX, float MaxX, float MinY, float MaxY, bool Value)
    DECL_THISCALL_TAIL(SetLinksBridgeLights, MinX, MaxX, MinY, MaxY, Value)

    DECL_THISCALL_HEAD(FindNodeCoorsForScript1, _ZN9CPathFind22FindNodeCoorsForScriptE12CNodeAddressPb, CVector, CNodeAddress Node, bool *pSuccess)
    DECL_THISCALL_TAIL(FindNodeCoorsForScript1, Node, pSuccess)

    DECL_THISCALL_HEAD(FindNodeCoorsForScript2, _ZN9CPathFind22FindNodeCoorsForScriptE12CNodeAddressS0_PfPb, CVector, CNodeAddress CurrentNode, CNodeAddress NewNode, float *pOrientation, bool *pSuccess)
    DECL_THISCALL_TAIL(FindNodeCoorsForScript2, CurrentNode, NewNode, pOrientation, pSuccess)

    DECL_THISCALL_HEAD(TakeWidthIntoAccountForWandering, _ZN9CPathFind32TakeWidthIntoAccountForWanderingE12CNodeAddresst, CVector, CNodeAddress Node, u16 RandomSeed)
    DECL_THISCALL_TAIL(TakeWidthIntoAccountForWandering, Node, RandomSeed)

    DECL_THISCALL_HEAD(TakeWidthIntoAccountForCoors, _ZN9CPathFind28TakeWidthIntoAccountForCoorsE12CNodeAddressS0_tPfS1_, void, CNodeAddress Node1, CNodeAddress Node2, u16 RandomSeed, float *pX, float *pY)
    DECL_THISCALL_TAIL(TakeWidthIntoAccountForCoors, Node1, Node2, RandomSeed, pX, pY)

    DECL_THISCALL_HEAD(MarkRegionsForCoors, _ZN9CPathFind19MarkRegionsForCoorsE7CVectorf, void, CVector Coors, float Range)
    DECL_THISCALL_TAIL(MarkRegionsForCoors, Coors, Range)

    DECL_THISCALL_HEAD(SetPathsNeededAtPosition, _ZN9CPathFind24SetPathsNeededAtPositionERK7CVector, void, CVector const &posn)
    DECL_THISCALL_TAIL(SetPathsNeededAtPosition, posn)

    DECL_THISCALL_HEAD(UpdateStreaming, _ZN9CPathFind15UpdateStreamingEb, void, bool bForceLoad)
    DECL_THISCALL_TAIL(UpdateStreaming, bForceLoad)

    DECL_THISCALL_HEAD(MakeRequestForNodesToBeLoaded, _ZN9CPathFind29MakeRequestForNodesToBeLoadedEffff, void, float MinX, float MaxX, float MinY, float MaxY)
    DECL_THISCALL_TAIL(MakeRequestForNodesToBeLoaded, MinX, MaxX, MinY, MaxY)

    DECL_THISCALL_HEAD(AreNodesLoadedForArea, _ZN9CPathFind21AreNodesLoadedForAreaEffff, bool, float MinX, float MaxX, float MinY, float MaxY)
    DECL_THISCALL_TAIL(AreNodesLoadedForArea, MinX, MaxX, MinY, MaxY)

    DECL_THISCALL_HEAD(LoadSceneForPathNodes, _ZN9CPathFind21LoadSceneForPathNodesE7CVector, void, CVector CenterCoors)
    DECL_THISCALL_TAIL(LoadSceneForPathNodes, CenterCoors)

    DECL_THISCALL_HEAD(IsWaterNodeNearby, _ZN9CPathFind17IsWaterNodeNearbyE7CVectorf, bool, CVector Coors, float Range)
    DECL_THISCALL_TAIL(IsWaterNodeNearby, Coors, Range)

    DECL_THISCALL_HEAD(StartNewInterior, _ZN9CPathFind16StartNewInteriorEj, void, u32 id)
    DECL_THISCALL_TAIL(StartNewInterior, id)

    DECL_THISCALL_HEAD(AddNodeToNewInterior, _ZN9CPathFind20AddNodeToNewInteriorEfffbaaaaaa, CNodeAddress, float X, float Y, float Z, bool bDontWander, i8 ConnectsTo1, i8 ConnectsTo2, i8 ConnectsTo3, i8 ConnectsTo4, i8 ConnectsTo5, i8 ConnectsTo6)
    DECL_THISCALL_TAIL(AddNodeToNewInterior, X, Y, Z, bDontWander, ConnectsTo1, ConnectsTo2, ConnectsTo3, ConnectsTo4, ConnectsTo5, ConnectsTo6)

    DECL_THISCALL_HEAD(AddInteriorLink, _ZN9CPathFind15AddInteriorLinkEii, void, i32 Node1, i32 Node2)
    DECL_THISCALL_TAIL(AddInteriorLink, Node1, Node2)

    DECL_THISCALL_HEAD(AddInteriorLinkToExternalNode, _ZN9CPathFind29AddInteriorLinkToExternalNodeEi12CNodeAddress, void, i32 Node, CNodeAddress ExternalNode)
    DECL_THISCALL_TAIL(AddInteriorLinkToExternalNode, Node, ExternalNode)

    DECL_THISCALL_HEAD(RemoveInteriorLinks, _ZN9CPathFind19RemoveInteriorLinksEi, void, i32 Node)
    DECL_THISCALL_TAIL(RemoveInteriorLinks, Node)

    DECL_THISCALL_HEAD(FindNearestExteriorNodeToInteriorNode, _ZN9CPathFind37FindNearestExteriorNodeToInteriorNodeEi, CNodeAddress, i32 Node)
    DECL_THISCALL_TAIL(FindNearestExteriorNodeToInteriorNode, Node)

    DECL_THISCALL_HEAD(CompleteNewInterior, _ZN9CPathFind19CompleteNewInteriorEP12CNodeAddress, void, CNodeAddress *pNearestExteriorNode)
    DECL_THISCALL_TAIL(CompleteNewInterior, pNearestExteriorNode)

    DECL_THISCALL_HEAD(AddDynamicLinkBetween2Nodes, _ZN9CPathFind27AddDynamicLinkBetween2NodesE12CNodeAddressS0_, void, CNodeAddress NodeAddress1, CNodeAddress NodeAddress2)
    DECL_THISCALL_TAIL(AddDynamicLinkBetween2Nodes, NodeAddress1, NodeAddress2)

    DECL_THISCALL_HEAD(AddDynamicLinkBetween2Nodes_For1Node, _ZN9CPathFind36AddDynamicLinkBetween2Nodes_For1NodeE12CNodeAddressS0_, void, CNodeAddress Node, CNodeAddress LinkedToNode)
    DECL_THISCALL_TAIL(AddDynamicLinkBetween2Nodes_For1Node, Node, LinkedToNode)

    DECL_THISCALL_HEAD(RemoveInterior, _ZN9CPathFind14RemoveInteriorEj, void, u32 id)
    DECL_THISCALL_TAIL(RemoveInterior, id)

    DECL_THISCALL_HEAD(ReturnInteriorNodeIndex, _ZN9CPathFind23ReturnInteriorNodeIndexEji, CNodeAddress, u32 id, i32 index)
    DECL_THISCALL_TAIL(ReturnInteriorNodeIndex, id, index)

    DECL_THISCALL_HEAD(FindLinkBetweenNodes, _ZN9CPathFind20FindLinkBetweenNodesE12CNodeAddressS0_, CLinkAddress, CNodeAddress Node1, CNodeAddress Node2)
    DECL_THISCALL_TAIL(FindLinkBetweenNodes, Node1, Node2)

    DECL_THISCALL_HEAD(FindParkingNodeInArea, _ZN9CPathFind21FindParkingNodeInAreaEffffff, CVector, float MinX, float MaxX, float MinY, float MaxY, float MinZ, float MaxZ)
    DECL_THISCALL_TAIL(FindParkingNodeInArea, MinX, MaxX, MinY, MaxY, MinZ, MaxZ)

    // Helper functions
    inline void LoadPathFindData(i32 Region)
    {
        LoadPathFindData1(Region);
    }
    inline void LoadPathFindData(RwStream *pStream, i32 Region)
    {
        LoadPathFindData2(pStream, Region);
    }
    inline CVector FindNodeCoorsForScript(CNodeAddress Node, bool *pSuccess)
    {
        return FindNodeCoorsForScript1(Node, pSuccess);
    }
    inline CVector FindNodeCoorsForScript(CNodeAddress CurrentNode, CNodeAddress NewNode, float *pOrientation, bool *pSuccess)
    {
        return FindNodeCoorsForScript2(CurrentNode, NewNode, pOrientation, pSuccess);
    }
    inline CPathNode* GetPathNode(CNodeAddress address)
    {
        return &m_pPathNodes[address.m_nAreaId][address.m_nNodeId];
    }

    // Member values
    unsigned char           info[2];
    CPathNode              *m_apNodesSearchLists[512];
    CPathNode              *m_pPathNodes[NUM_PATH_MAP_AREAS + NUM_PATH_INTERIOR_AREAS];
    CCarPathLink           *m_pNaviNodes[NUM_PATH_MAP_AREAS + NUM_PATH_INTERIOR_AREAS];
    CNodeAddress           *m_pNodeLinks[NUM_PATH_MAP_AREAS + NUM_PATH_INTERIOR_AREAS];
    unsigned char          *m_pLinkLengths[NUM_PATH_MAP_AREAS + NUM_PATH_INTERIOR_AREAS];
    CPathIntersectionInfo  *m_pPathIntersections[NUM_PATH_MAP_AREAS + NUM_PATH_INTERIOR_AREAS];
    CCarPathLinkAddress    *m_pNaviLinks[NUM_PATH_MAP_AREAS + NUM_PATH_INTERIOR_AREAS];
    CTempPathNode          *m_pTemporaryNodes[NUM_PATH_MAP_AREAS + NUM_PATH_INTERIOR_AREAS];
    int                     m_dwNumNodes[NUM_PATH_MAP_AREAS + NUM_PATH_INTERIOR_AREAS];
    int                     m_dwNumVehicleNodes[NUM_PATH_MAP_AREAS + NUM_PATH_INTERIOR_AREAS];
    int                     m_dwNumPedNodes[NUM_PATH_MAP_AREAS + NUM_PATH_INTERIOR_AREAS];
    int                     m_dwNumCarPathLinks[NUM_PATH_MAP_AREAS + NUM_PATH_INTERIOR_AREAS];
    int                     m_dwNumAddresses[NUM_PATH_MAP_AREAS + NUM_PATH_INTERIOR_AREAS];
    int                     m_dwOldAddressIndex[NUM_PATH_MAP_AREAS][16];
    int                     m_dwNewAddressIndex[NUM_PATH_MAP_AREAS][16];
    int                     m_dwTotalNumNodesInSearchList;
    unsigned int            m_nInteriorID[NUM_PATH_INTERIOR_AREAS];
    int                     m_dwNumForbiddenAreas;
    CForbiddenArea          m_aForbiddenAreas[NUM_PATH_MAP_AREAS];
    bool                    m_bForbiddenForScriptedCarsEnabled;
    float                   m_fForbiddenForScrCarsX1;
    float                   m_fForbiddenForScrCarsX2;
    float                   m_fForbiddenForScrCarsY1;
    float                   m_fForbiddenForScrCarsY2;
DECL_CLASS_END()
CHECKSIZE(CPathFind, 0x3CC0, 0x4CA8);

DECL_OBJECT_PLT_GLOBAL(CPathFind, ThePaths, BYBIT(0x677378, 0x84C728) );
#define ThePaths ThePaths()

#endif // __AML_PSDK_SAPATHFIND_H
