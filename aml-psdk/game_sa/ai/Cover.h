#ifndef __AML_PSDK_SACOVER_H
#define __AML_PSDK_SACOVER_H

#include "../entity/Ped.h"
#include "../base/ColModel.h"

DECL_CLASS(CCover)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(Init, _ZN6CCover4InitEv, void);
    DECL_FASTCALL_SIMPLE(Update, _ZN6CCover6UpdateEv, void);
    DECL_FASTCALL_SIMPLE(AddCoverPoint, _ZN6CCover13AddCoverPointEiP7CEntityP7CVectorah, void,
        i32 type, CEntity* entity, CVector* position, i8 usage, u8 direction);
    DECL_FASTCALL_SIMPLE(RemoveCoverPointsForThisEntity, _ZN6CCover30RemoveCoverPointsForThisEntityEP7CEntity, void, CEntity* entity);
    DECL_FASTCALL_SIMPLE(FindCoverPointsForThisBuilding, _ZN6CCover30FindCoverPointsForThisBuildingEP9CBuilding, void, CBuilding* building);
    DECL_FASTCALL_SIMPLE(FindVectorFromFirstToMissingVertex, _ZN6CCover34FindVectorFromFirstToMissingVertexEP12CColTrianglePiP7CVector, CVector,
        CColTriangle* triangle, i32* sharedVertices, CVector* vertices);
    DECL_FASTCALL_SIMPLE(CalculateHorizontalSize, _ZN6CCover23CalculateHorizontalSizeEP12CColTriangleP7CVector, float,
        CColTriangle* triangle, CVector* vertices);
    DECL_FASTCALL_SIMPLE(Find2HighestPoints, _ZN6CCover18Find2HighestPointsEP12CColTriangleP7CVectorRiS4_, void,
        CColTriangle* triangle, CVector* vertices, i32& first, i32& second);
    DECL_FASTCALL_SIMPLE(DoLineCheckWithinObject, _ZN6CCover23DoLineCheckWithinObjectEP12CColTriangleiP7CVectorS3_S2_S2_, bool,
        CColTriangle* triangles, i32 numTriangles, CVector* vertices, CVector* normals, CVector start, CVector end);
    DECL_FASTCALL_SIMPLE(ShouldThisBuildingHaveItsCoverPointsCreated, _ZN6CCover43ShouldThisBuildingHaveItsCoverPointsCreatedEP9CBuilding, bool, CBuilding* building);
    DECL_FASTCALL_SIMPLE(FindAndReserveCoverPoint, _ZN6CCover24FindAndReserveCoverPointEP4CPedR7CVectorb, CCoverPoint*,
        CPed* ped, CVector& position, bool useThreatDirection);
    DECL_FASTCALL_SIMPLE(FindCoordinatesCoverPoint, _ZN6CCover25FindCoordinatesCoverPointEP11CCoverPointP4CPedR7CVectorS5_, bool,
        CCoverPoint* coverPoint, CPed* ped, CVector& source, CVector& position);
    DECL_FASTCALL_SIMPLE(FindDirFromVector, _ZN6CCover17FindDirFromVectorE7CVector, u8, CVector direction);
    DECL_FASTCALL_SIMPLE(FindVectorFromDir, _ZN6CCover17FindVectorFromDirEh, CVector, u8 direction);
    DECL_FASTCALL_SIMPLE(RemoveCoverPointIfEntityLost, _ZN6CCover28RemoveCoverPointIfEntityLostEP11CCoverPoint, void, CCoverPoint* coverPoint);
    DECL_FASTCALL_SIMPLE(DoesCoverPointStillProvideCover, _ZN6CCover31DoesCoverPointStillProvideCoverEP11CCoverPoint7CVector, bool,
        CCoverPoint* coverPoint, CVector position);

    // STATIC values
    DECL_OBJECT_ARRAY_PLT(CCoverPoint, m_aPoints, BYBIT(0x6790EC, 0x850200));
    DECL_VALUE_PLT_I32(m_NumPoints, BYBIT(0x676820, 0x84B098));
    DECL_OBJECT_PLT(CPtrListDoubleLink, m_ListOfProcessedBuildings, BYBIT(0x677FC0, 0x84DFA0));
    DECL_VALUE_SYM_BOOL(bRenderCoverPoints, _ZN6CCover18bRenderCoverPointsE);
    DECL_VALUE_SYM_I32(LastTimeRecorded, _ZN6CCover16LastTimeRecordedE);
    DECL_VALUE_SYM_I32(SlowestTimeRecorded, _ZN6CCover19SlowestTimeRecordedE);
DECL_CLASS_END()

#define m_aPoints m_aPoints()
#define m_NumPoints m_NumPoints()
#define m_ListOfProcessedBuildings m_ListOfProcessedBuildings()
#define bRenderCoverPoints bRenderCoverPoints()
#define LastTimeRecorded LastTimeRecorded()
#define SlowestTimeRecorded SlowestTimeRecorded()

#endif // __AML_PSDK_SACOVER_H
