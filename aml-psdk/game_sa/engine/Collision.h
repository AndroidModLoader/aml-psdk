#ifndef __AML_PSDK_SACOLLISIONENGINE_H
#define __AML_PSDK_SACOLLISIONENGINE_H

#include "../plugin.h"
#include "../base/ColModel.h"
#include "../enum/LevelName.h"

struct CEntity;
struct CVehicle;
struct CMatrix;

struct CColCacheEntry
{
    u8 type;
    CEntity* pEnt;
    u16 triId;
    u16 sphId;
    u16 boxId;
};
CHECKSIZE(CColCacheEntry, 0x10, 0x18);

DECL_CLASS(CCollision)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(TestLineBox_DW, _ZN10CCollision14TestLineBox_DWERK8CColLineRK4CBox, bool, CColLine const& line, CBox const& box);
    DECL_FASTCALL_SIMPLE(Init, _ZN10CCollision4InitEv, void);
    DECL_FASTCALL_SIMPLE(Shutdown, _ZN10CCollision8ShutdownEv, void);
    DECL_FASTCALL_SIMPLE(Update, _ZN10CCollision6UpdateEv, void);
    DECL_FASTCALL_SIMPLE(SortOutCollisionAfterLoad, _ZN10CCollision25SortOutCollisionAfterLoadEv, void);
    DECL_FASTCALL_SIMPLE(CalculateTrianglePlanes1, _ZN10CCollision23CalculateTrianglePlanesEP9CColModel, void, CColModel* pModel);
    static void CalculateTrianglePlanes(CColModel* pModel)
    {
        return CalculateTrianglePlanes1(pModel);
    }
    DECL_FASTCALL_SIMPLE(RemoveTrianglePlanes1, _ZN10CCollision20RemoveTrianglePlanesEP9CColModel, void, CColModel* pModel);
    static void RemoveTrianglePlanes(CColModel* pModel)
    {
        return RemoveTrianglePlanes1(pModel);
    }
    DECL_FASTCALL_SIMPLE(CalculateTrianglePlanes2, _ZN10CCollision23CalculateTrianglePlanesEP14CCollisionData, void, CCollisionData* pColData);
    static void CalculateTrianglePlanes(CCollisionData* pColData)
    {
        return CalculateTrianglePlanes2(pColData);
    }
    DECL_FASTCALL_SIMPLE(RemoveTrianglePlanes2, _ZN10CCollision20RemoveTrianglePlanesEP14CCollisionData, void, CCollisionData* pColData);
    static void RemoveTrianglePlanes(CCollisionData* pColData)
    {
        return RemoveTrianglePlanes2(pColData);
    }
    DECL_FASTCALL_SIMPLE(TestSphereSphere, _ZN10CCollision16TestSphereSphereERK10CColSphereS2_, bool, CColSphere const& sphereA, CColSphere const& sphereB);
    DECL_FASTCALL_SIMPLE(ProcessSphereSphere, _ZN10CCollision19ProcessSphereSphereERK10CColSphereS2_R9CColPointRf, bool, CColSphere const& sphereA, CColSphere const& sphereB, CColPoint& colPoint, float& fDistanceSqr);
    DECL_FASTCALL_SIMPLE(TestSphereBox, _ZN10CCollision13TestSphereBoxERK7CSphereRK4CBox, bool, CSphere const& sphere, CBox const& box);
    DECL_FASTCALL_SIMPLE(ProcessSphereBox, _ZN10CCollision16ProcessSphereBoxERK10CColSphereRK7CColBoxR9CColPointRf, bool, CColSphere const& sphere, CColBox const& box, CColPoint& colPoint, float& fDistanceSqr);
    DECL_FASTCALL_SIMPLE(TestSphereTriangle, _ZN10CCollision18TestSphereTriangleERK10CColSpherePK7CVectorRK12CColTriangleRK17CColTrianglePlane, bool, CColSphere const& sphere, CollisionVector const* aVectors, CColTriangle const& triangle, CColTrianglePlane const& plane);
    DECL_FASTCALL_SIMPLE(ProcessSphereTriangle, _ZN10CCollision21ProcessSphereTriangleERK10CColSpherePK7CVectorRK12CColTriangleRK17CColTrianglePlaneR9CColPointRf, bool, CColSphere const& sphere, CollisionVector const* aVectors, CColTriangle const& triangle, CColTrianglePlane const& plane, CColPoint& colPoint, float& fDistanceSqr);
    DECL_FASTCALL_SIMPLE(TestLineSphere, _ZN10CCollision14TestLineSphereERK8CColLineRK10CColSphere, bool, CColLine const& line, CColSphere const& sphere);
    DECL_FASTCALL_SIMPLE(DistToLine, _ZN10CCollision10DistToLineEPK7CVectorS2_S2_, float, CVector const* pVecStart, CVector const* pVecEnd, CVector const* pPoint);
    DECL_FASTCALL_SIMPLE(DistToLineSqr, _ZN10CCollision13DistToLineSqrEPK7CVectorS2_S2_, float, CVector const* pVecStart, CVector const* pVecEnd, CVector const* pPoint);
    DECL_FASTCALL_SIMPLE(DistToMathematicalLine, _ZN10CCollision22DistToMathematicalLineEPK7CVectorS2_S2_, float, CVector const* pVecStart, CVector const* pVecEnd, CVector const* pPoint);
    DECL_FASTCALL_SIMPLE(DistToMathematicalLine2D, _ZN10CCollision24DistToMathematicalLine2DEffffff, float, float LineStartX, float LineStartY, float LineDirX, float LineDirY, float PointX, float PointY);
    DECL_FASTCALL_SIMPLE(DistAlongLine2D, _ZN10CCollision15DistAlongLine2DEffffff, float, float LineStartX, float LineStartY, float LineDirX, float LineDirY, float PointX, float PointY);
    DECL_FASTCALL_SIMPLE(ProcessLineSphere, _ZN10CCollision17ProcessLineSphereERK8CColLineRK10CColSphereR9CColPointRf, bool, CColLine const& line, CColSphere const& sphere, CColPoint& colPoint, float& fCollisionRatio);
    DECL_FASTCALL_SIMPLE(TestLineBox, _ZN10CCollision11TestLineBoxERK8CColLineRK4CBox, bool, CColLine const& line, CBox const& box);
    DECL_FASTCALL_SIMPLE(TestVerticalLineBox, _ZN10CCollision19TestVerticalLineBoxERK8CColLineRK4CBox, bool, CColLine const& Line, CBox const& box);
    DECL_FASTCALL_SIMPLE(ProcessLineBox, _ZN10CCollision14ProcessLineBoxERK8CColLineRK7CColBoxR9CColPointRf, bool, CColLine const& line, CColBox const& box, CColPoint& colPoint, float& fCollisionRatio);
    DECL_FASTCALL_SIMPLE(Test2DLineAgainst2DLine, _ZN10CCollision23Test2DLineAgainst2DLineEffffffff, bool, float Start1X, float Start1Y, float Delta1X, float Delta1Y, float Start2X, float Start2Y, float Delta2X, float Delta2Y);
    DECL_FASTCALL_SIMPLE(TestLineTriangle, _ZN10CCollision16TestLineTriangleERK8CColLinePK7CVectorRK12CColTriangleRK17CColTrianglePlane, bool, CColLine const& line, CollisionVector const* aVectors, CColTriangle const& triangle, CColTrianglePlane const& plane);
    DECL_FASTCALL_SIMPLE(ProcessLineTriangle, _ZN10CCollision19ProcessLineTriangleERK8CColLinePK7CVectorRK12CColTriangleRK17CColTrianglePlaneR9CColPointRfP15CStoredCollPoly, bool, CColLine const& line, CollisionVector const* aVectors, CColTriangle const& triangle, CColTrianglePlane const& plane, CColPoint& colPoint, float& fCollisionRatio, CStoredCollPoly* pStoredPoly);
    DECL_FASTCALL_SIMPLE(ProcessVerticalLineTriangle, _ZN10CCollision27ProcessVerticalLineTriangleERK8CColLinePK7CVectorRK12CColTriangleRK17CColTrianglePlaneR9CColPointRfP15CStoredCollPoly, bool, CColLine const& line, CollisionVector const* aVectors, CColTriangle const& triangle, CColTrianglePlane const& plane, CColPoint& colPoint, float& fCollisionRatio, CStoredCollPoly* pStoredPoly);
    DECL_FASTCALL_SIMPLE(TestLineOfSight, _ZN10CCollision15TestLineOfSightERK8CColLineRK7CMatrixR9CColModelbb, bool, CColLine const& line, CMatrix const& mat, CColModel& colModel, bool bSeeThroughStuff, bool bShootThroughStuff);
    DECL_FASTCALL_SIMPLE(ProcessLineOfSight, _ZN10CCollision18ProcessLineOfSightERK8CColLineRK7CMatrixR9CColModelR9CColPointRfbb, bool, CColLine const& line, CMatrix const& mat, CColModel& colModel, CColPoint& colPoint, float& fCollisionRatio, bool bSeeThroughStuff, bool bShootThroughStuff);
    DECL_FASTCALL_SIMPLE(ProcessVerticalLine, _ZN10CCollision19ProcessVerticalLineERK8CColLineRK7CMatrixR9CColModelR9CColPointRfbbP15CStoredCollPoly, bool, CColLine const& Line, CMatrix const& mat, CColModel& colModel, CColPoint& colPoint, float& fCollisionRatio, bool bSeeThroughStuff, bool bShootThroughStuff, CStoredCollPoly* pStoredPoly);
    DECL_FASTCALL_SIMPLE(ProcessColModels, _ZN10CCollision16ProcessColModelsERK7CMatrixR9CColModelS2_S4_P9CColPointS6_Pfb, i32, CMatrix const& matA, CColModel& colModelA, CMatrix const& matB, CColModel& colModelB, CColPoint* aColPoints, CColPoint* aLineColPoints, float* aLineRatios, bool bReturnAllCollisions);
    DECL_FASTCALL_SIMPLE(IsStoredPolyStillValidVerticalLine, _ZN10CCollision34IsStoredPolyStillValidVerticalLineERK7CVectorfR9CColPointP15CStoredCollPoly, bool, CVector const& vecStart, float zEnd, CColPoint& colPoint, CStoredCollPoly* pStoredPoly);
    DECL_FASTCALL_SIMPLE(CameraConeCastVsWorldCollision, _ZN10CCollision30CameraConeCastVsWorldCollisionEP10CColSphereS1_Pff, bool, CColSphere* pA, CColSphere* pB, float* pDist, float minDist);
    DECL_FASTCALL_SIMPLE(CheckCameraCollisionObjects, _ZN10CCollision27CheckCameraCollisionObjectsEiiP7CColBoxP10CColSphereS3_S3_, bool, i32 X, i32 Y, CColBox* pBox, CColSphere* pSph, CColSphere* pA, CColSphere* pB);
    DECL_FASTCALL_SIMPLE(CheckCameraCollisionBuildings, _ZN10CCollision29CheckCameraCollisionBuildingsEiiP7CColBoxP10CColSphereS3_S3_, bool, i32 X, i32 Y, CColBox* pBox, CColSphere* pSph, CColSphere* pA, CColSphere* pB);
    DECL_FASTCALL_SIMPLE(CheckCameraCollisionVehicles, _ZN10CCollision28CheckCameraCollisionVehiclesEiiP7CColBoxP10CColSphereS3_S3_P7CVector, bool, i32 X, i32 Y, CColBox* pBox, CColSphere* pSph, CColSphere* pA, CColSphere* pB, CVector* pMyVel);
    DECL_FASTCALL_SIMPLE(BuildCacheOfCameraCollision, _ZN10CCollision27BuildCacheOfCameraCollisionEP10CColSphereS1_, bool, CColSphere* pA, CColSphere* pB);
    DECL_FASTCALL_SIMPLE(GetBoundingBoxFromTwoSpheres, _ZN10CCollision28GetBoundingBoxFromTwoSpheresEP7CColBoxP10CColSphereS3_, void, CColBox* pBox, CColSphere* pA, CColSphere* pB);
    DECL_FASTCALL_SIMPLE(SphereCastVsSphere, _ZN10CCollision18SphereCastVsSphereEP10CColSphereS1_S1_, bool, CColSphere* pA, CColSphere* pB, CColSphere* pS);
    DECL_FASTCALL_SIMPLE(SphereCastVersusVsPoly, _ZN10CCollision22SphereCastVersusVsPolyEP10CColSphereS1_P12CColTriangleP17CColTrianglePlaneP7CVector, bool, CColSphere* pA, CColSphere* pB, CColTriangle* pP, CColTrianglePlane* pPlane, CollisionVector* pVerts);
    DECL_FASTCALL_SIMPLE(SphereCastVsEntity, _ZN10CCollision18SphereCastVsEntityEP10CColSphereS1_P7CEntity, bool, CColSphere* pA, CColSphere* pB, CEntity* pEntity);
    DECL_FASTCALL_SIMPLE(SphereCastVsCaches, _ZN10CCollision18SphereCastVsCachesEP10CColSphereP7CVectoriP14CColCacheEntryPiS5_, bool, CColSphere* pA, CVector* pVel, i32 numTest, CColCacheEntry* pTest, i32* pNumWrite, CColCacheEntry* pWrite);
    DECL_FASTCALL_SIMPLE(SphereCastVsBBox, _ZN10CCollision16SphereCastVsBBoxEP10CColSphereS1_P7CColBox, bool, CColSphere* pA, CColSphere* pB, CColBox* pBox);
    DECL_FASTCALL_SIMPLE(RayPolyPOP, _ZN10CCollision10RayPolyPOPEP7CVectorS1_P12CColTriangleS1_S1_, i32, CVector* pRS, CVector* pRD, CColTriangle* pP, CVector* pNormal, CVector* pVert);
    DECL_FASTCALL_SIMPLE(GetPrincipleAxis, _ZN10CCollision16GetPrincipleAxisEP7CVector, i32, CVector* pNormal);
    DECL_FASTCALL_SIMPLE(PointInPoly, _ZN10CCollision11PointInPolyEP7CVectorP12CColTriangleS1_S1_, bool, CVector* pP, CColTriangle* pPoly, CVector* pNormal, CVector* pV);
    DECL_FASTCALL_SIMPLE(ClosestPointOnLine, _ZN10CCollision18ClosestPointOnLineEP7CVectorS1_S1_S1_, void, CVector* pP, CVector* pS, CVector* pE, CVector* pClosest);
    DECL_FASTCALL_SIMPLE(ClosestPointsOnPoly, _ZN10CCollision19ClosestPointsOnPolyEP12CColTriangleP7CVectorS3_S3_, void, CColTriangle* pP, CVector* pV, CVector* pClosest, CVector* pVec);
    DECL_FASTCALL_SIMPLE(Closest3, _ZN10CCollision8Closest3EP7CVectorS1_, void, CVector* pP, CVector* pClosest);
    DECL_FASTCALL_SIMPLE(ClosestPointOnPoly, _ZN10CCollision18ClosestPointOnPolyEP12CColTriangleP7CVectorS3_, void, CColTriangle* pP, CVector* pVerts, CVector* pClosest);
    DECL_FASTCALL_SIMPLE(CheckCameraCollisionPeds, _ZN10CCollision24CheckCameraCollisionPedsEiiP7CVectorS1_Pf, bool, i32 X, i32 Y, CVector* pPos, CVector* pNorm, float* pNearestDist);
    DECL_FASTCALL_SIMPLE(CheckPeds, _ZN10CCollision9CheckPedsEP7CVectorS1_Pf, bool, CVector* pSource, CVector* pNorm, float* pNearest);
    DECL_FASTCALL_SIMPLE(SphereVsEntity, _ZN10CCollision14SphereVsEntityEP10CColSphereP7CEntity, bool, CColSphere* pA, CEntity* pEntity);
    DECL_FASTCALL_SIMPLE(IsThisVehicleSittingOnMe, _ZN10CCollision24IsThisVehicleSittingOnMeEP8CVehicleS1_, bool, CVehicle* pVehicleMe, CVehicle* pVehicleTest);

    // Member functions
    DECL_THISCALL_HEAD(PointInTriangle, _ZN10CCollision15PointInTriangleERK7CVectorPS1_, bool, CVector const& testPoint, CVector const* triPts)
    DECL_THISCALL_TAIL(PointInTriangle, testPoint, triPts)

    // STATIC values
    DECL_VALUE_PLT_BOOL(bCamCollideWithVehicles, BYBIT(0x678D78, 0x84FB18));
    DECL_VALUE_PLT_BOOL(bCamCollideWithObjects, BYBIT(0x677584, 0x84CB48));
    DECL_VALUE_PLT_BOOL(bCamCollideWithBuildings, BYBIT(0x679734, 0x850E70));
    DECL_VALUE_PLT_BOOL(bCamCollideWithPeds, BYBIT(0x678EF4, 0x84FE10));
    DECL_VALUE_PLT_FLT(relVelCamCollisionVehiclesSqr, BYBIT(0x679F54, 0x851EB0));
    DECL_VALUE_PLT_U32(ms_nProcessLineNumCrossings, BYBIT(0x6783D8, 0x84E7C8));
    DECL_OBJECT_PLT(CLinkList<CCollisionData*>, ms_colModelCache, BYBIT(0x677A8C, 0x84D540));
    DECL_OBJECT_PLT(eLevelName, ms_collisionInMemory, BYBIT(0x6773C4, 0x84C7C0));
DECL_CLASS_END()

#endif // __AML_PSDK_SACOLLISIONENGINE_H
