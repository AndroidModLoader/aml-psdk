#ifndef __AML_PSDK_VCCOLLISIONENGINE_H
#define __AML_PSDK_VCCOLLISIONENGINE_H

#include "../plugin.h"
#include "../base/ColModel.h"

struct CMatrix;

DECL_CLASS(CCollision)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(Init, _ZN10CCollision4InitEv, void);
    DECL_FASTCALL_SIMPLE(Shutdown, _ZN10CCollision8ShutdownEv, void);
    DECL_FASTCALL_SIMPLE(SortOutCollisionAfterLoad, _ZN10CCollision25SortOutCollisionAfterLoadEv, void);
    DECL_FASTCALL_SIMPLE(CalculateTrianglePlanes, _ZN10CCollision23CalculateTrianglePlanesEP9CColModel, void, CColModel* model);
    DECL_FASTCALL_SIMPLE(RemoveTrianglePlanes, _ZN10CCollision20RemoveTrianglePlanesEP9CColModel, void, CColModel* model);
    DECL_FASTCALL_SIMPLE(TestSphereSphere, _ZN10CCollision16TestSphereSphereERK10CColSphereS2_, bool, CColSphere const& sphereA, CColSphere const& sphereB);
    DECL_FASTCALL_SIMPLE(ProcessSphereSphere, _ZN10CCollision19ProcessSphereSphereERK10CColSphereS2_R9CColPointRf, bool, CColSphere const& sphereA, CColSphere const& sphereB, CColPoint& point, float& distanceSqr);
    DECL_FASTCALL_SIMPLE(TestSphereBox, _ZN10CCollision13TestSphereBoxERK7CSphereRK4CBox, bool, CSphere const& sphere, CBox const& box);
    DECL_FASTCALL_SIMPLE(ProcessSphereBox, _ZN10CCollision16ProcessSphereBoxERK10CColSphereRK7CColBoxR9CColPointRf, bool, CColSphere const& sphere, CColBox const& box, CColPoint& point, float& distanceSqr);
    DECL_FASTCALL_SIMPLE(TestSphereTriangle, _ZN10CCollision18TestSphereTriangleERK10CColSpherePK16CompressedVectorRK12CColTriangleRK17CColTrianglePlane, bool, CColSphere const& sphere, CVector const* vertices, CColTriangle const& triangle, CColTrianglePlane const& plane);
    DECL_FASTCALL_SIMPLE(ProcessSphereTriangle, _ZN10CCollision21ProcessSphereTriangleERK10CColSpherePK16CompressedVectorRK12CColTriangleRK17CColTrianglePlaneR9CColPointRf, bool, CColSphere const& sphere, CVector const* vertices, CColTriangle const& triangle, CColTrianglePlane const& plane, CColPoint& point, float& distanceSqr);
    DECL_FASTCALL_SIMPLE(TestLineSphere, _ZN10CCollision14TestLineSphereERK8CColLineRK10CColSphere, bool, CColLine const& line, CColSphere const& sphere);
    DECL_FASTCALL_SIMPLE(DistToLine, _ZN10CCollision10DistToLineEPK7CVectorS2_S2_, float, CVector const* start, CVector const* end, CVector const* point);
    DECL_FASTCALL_SIMPLE(ProcessLineSphere, _ZN10CCollision17ProcessLineSphereERK8CColLineRK10CColSphereR9CColPointRf, bool, CColLine const& line, CColSphere const& sphere, CColPoint& point, float& ratio);
    DECL_FASTCALL_SIMPLE(TestLineBox, _ZN10CCollision11TestLineBoxERK8CColLineRK4CBox, bool, CColLine const& line, CBox const& box);
    DECL_FASTCALL_SIMPLE(TestVerticalLineBox, _ZN10CCollision19TestVerticalLineBoxERK8CColLineRK4CBox, bool, CColLine const& line, CBox const& box);
    DECL_FASTCALL_SIMPLE(ProcessLineBox, _ZN10CCollision14ProcessLineBoxERK8CColLineRK7CColBoxR9CColPointRf, bool, CColLine const& line, CColBox const& box, CColPoint& point, float& ratio);
    DECL_FASTCALL_SIMPLE(TestLineTriangle, _ZN10CCollision16TestLineTriangleERK8CColLinePK16CompressedVectorRK12CColTriangleRK17CColTrianglePlane, bool, CColLine const& line, CVector const* vertices, CColTriangle const& triangle, CColTrianglePlane const& plane);
    DECL_FASTCALL_SIMPLE(ProcessLineTriangle, _ZN10CCollision19ProcessLineTriangleERK8CColLinePK16CompressedVectorRK12CColTriangleRK17CColTrianglePlaneR9CColPointRfP15CStoredCollPoly, bool, CColLine const& line, CVector const* vertices, CColTriangle const& triangle, CColTrianglePlane const& plane, CColPoint& point, float& ratio, CStoredCollPoly* storedPoly);
    DECL_FASTCALL_SIMPLE(ProcessVerticalLineTriangle, _ZN10CCollision27ProcessVerticalLineTriangleERK8CColLinePK16CompressedVectorRK12CColTriangleRK17CColTrianglePlaneR9CColPointRfP15CStoredCollPoly, bool, CColLine const& line, CVector const* vertices, CColTriangle const& triangle, CColTrianglePlane const& plane, CColPoint& point, float& ratio, CStoredCollPoly* storedPoly);
    DECL_FASTCALL_SIMPLE(TestLineOfSight, _ZN10CCollision15TestLineOfSightERK8CColLineRK7CMatrixR9CColModelbb, bool, CColLine const& line, CMatrix const& matrix, CColModel& model, bool seeThrough, bool shootThrough);
    DECL_FASTCALL_SIMPLE(ProcessLineOfSight, _ZN10CCollision18ProcessLineOfSightERK8CColLineRK7CMatrixR9CColModelR9CColPointRfbb, bool, CColLine const& line, CMatrix const& matrix, CColModel& model, CColPoint& point, float& ratio, bool seeThrough, bool shootThrough);
    DECL_FASTCALL_SIMPLE(ProcessVerticalLine, _ZN10CCollision19ProcessVerticalLineERK8CColLineRK7CMatrixR9CColModelR9CColPointRfbbP15CStoredCollPoly, bool, CColLine const& line, CMatrix const& matrix, CColModel& model, CColPoint& point, float& ratio, bool seeThrough, bool shootThrough, CStoredCollPoly* storedPoly);
    DECL_FASTCALL_SIMPLE(ProcessColModels, _ZN10CCollision16ProcessColModelsERK7CMatrixR9CColModelS2_S4_P9CColPointS6_Pf, i32, CMatrix const& matrixA, CColModel& modelA, CMatrix const& matrixB, CColModel& modelB, CColPoint* points, CColPoint* linePoints, float* lineRatios);
    DECL_FASTCALL_SIMPLE(IsStoredPolyStillValidVerticalLine, _ZN10CCollision34IsStoredPolyStillValidVerticalLineERK7CVectorfR9CColPointP15CStoredCollPoly, bool, CVector const& start, float endZ, CColPoint& point, CStoredCollPoly* storedPoly);
    DECL_FASTCALL_SIMPLE(TestPillWithSpheresInColModel, _ZN10CCollision29TestPillWithSpheresInColModelERK8CColLinefRK7CMatrixR9CColModel, bool, CColLine const& line, float radius, CMatrix const& matrix, CColModel& model);

    // STATIC values
    DECL_VALUE_PLT_I32(ms_collisionInMemory, BYBIT(0x3955cc, 0x578c00));
DECL_CLASS_END()

#define ms_collisionInMemory ms_collisionInMemory()

#endif // __AML_PSDK_VCCOLLISIONENGINE_H
