#ifndef __AML_PSDK_SAPEDGEOMETRYANALYSER_H
#define __AML_PSDK_SAPEDGEOMETRYANALYSER_H

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/gta_base/Vector.h>

struct CPed;
struct CEntity;
struct CPhysical;
struct CColSphere;
struct CPointRoute;

DECL_CLASS(CPedGeometryAnalyser)
    enum
    {
        WANDER_PATH_BLOCKED_HEIGHT = 0,
        WANDER_PATH_BLOCKED_LOS = 1,
        WANDER_PATH_BLOCKED_WATER = 2,
        WANDER_PATH_BLOCKED_SHARP_DROP = 3,
        WANDER_PATH_CLEAR = 4
    };

    // STATIC functions
    DECL_FASTCALL_SIMPLE(ComputePedHitSide1, _ZN20CPedGeometryAnalyser17ComputePedHitSideERK4CPedRK9CPhysical, i32, CPed const& ped, CPhysical const& physical);
    inline static i32 ComputePedHitSide(CPed const& ped, CPhysical const& physical) { return ComputePedHitSide1(ped, physical); }
    DECL_FASTCALL_SIMPLE(ComputePedHitSide2, _ZN20CPedGeometryAnalyser17ComputePedHitSideERK4CPedRK7CVector, i32, CPed const& ped, CVector const& hitPos);
    inline static i32 ComputePedHitSide(CPed const& ped, CVector const& hitPos) { return ComputePedHitSide2(ped, hitPos); }
    DECL_FASTCALL_SIMPLE(ComputeEntityHitSide1, _ZN20CPedGeometryAnalyser20ComputeEntityHitSideERK4CPedR7CEntity, i32, CPed const& ped, CEntity& entity);
    inline static i32 ComputeEntityHitSide(CPed const& ped, CEntity& entity) { return ComputeEntityHitSide1(ped, entity); }
    DECL_FASTCALL_SIMPLE(ComputeEntityHitSide2, _ZN20CPedGeometryAnalyser20ComputeEntityHitSideERK7CVectorR7CEntity, i32, CVector const& hitPos, CEntity& entity);
    inline static i32 ComputeEntityHitSide(CVector const& hitPos, CEntity& entity) { return ComputeEntityHitSide2(hitPos, entity); }
    DECL_FASTCALL_SIMPLE(ComputeEntityHitSide3, _ZN20CPedGeometryAnalyser20ComputeEntityHitSideERK7CVectorPS1_PKf, i32, CVector const& hitPos, CVector const* corners, float const* planes);
    inline static i32 ComputeEntityHitSide(CVector const& hitPos, CVector const* corners, float const* planes) { return ComputeEntityHitSide3(hitPos, corners, planes); }
    DECL_FASTCALL_SIMPLE(ComputeMoveDirToAvoidEntity, _ZN20CPedGeometryAnalyser27ComputeMoveDirToAvoidEntityERK4CPedR7CEntityR7CVector, void, CPed const& ped, CEntity& entity, CVector& outDirection);
    DECL_FASTCALL_SIMPLE(ComputeEntityDirs, _ZN20CPedGeometryAnalyser17ComputeEntityDirsERK7CEntityP7CVector, void, CEntity const& entity, CVector* outDirections);
    DECL_FASTCALL_SIMPLE(ComputeEntityBoundingBoxCentre, _ZN20CPedGeometryAnalyser30ComputeEntityBoundingBoxCentreEfR7CEntityR7CVector, void, float const scale, CEntity& entity, CVector& outCentre);
    DECL_FASTCALL_SIMPLE(ComputeEntityBoundingBoxCorners, _ZN20CPedGeometryAnalyser31ComputeEntityBoundingBoxCornersEfR7CEntityP7CVector, void, float const scale, CEntity& entity, CVector* outCorners);
    DECL_FASTCALL_SIMPLE(ComputeEntityBoundingBoxPlanes, _ZN20CPedGeometryAnalyser30ComputeEntityBoundingBoxPlanesEfR7CEntityP7CVectorPf, void, float const scale, CEntity& entity, CVector* outCorners, float* outPlanes);
    DECL_FASTCALL_SIMPLE(ComputeEntityBoundingBoxSegmentPlanes, _ZN20CPedGeometryAnalyser37ComputeEntityBoundingBoxSegmentPlanesEfR7CEntityP7CVectorPf, void, float const scale, CEntity& entity, CVector* outCorners, float* outPlanes);
    DECL_FASTCALL_SIMPLE(ComputeEntityBoundingSphere, _ZN20CPedGeometryAnalyser27ComputeEntityBoundingSphereERK4CPedR7CEntityR10CColSphere, void, CPed const& ped, CEntity& entity, CColSphere& outSphere);
    DECL_FASTCALL_SIMPLE(ComputeRouteRoundEntityBoundingBox1, _ZN20CPedGeometryAnalyser34ComputeRouteRoundEntityBoundingBoxERK4CPedR7CEntityRK7CVectorR11CPointRoutei, i32, CPed const& ped, CEntity& entity, CVector const& target, CPointRoute& route, i32 direction);
    inline static i32 ComputeRouteRoundEntityBoundingBox(CPed const& ped, CEntity& entity, CVector const& target, CPointRoute& route, i32 direction) { return ComputeRouteRoundEntityBoundingBox1(ped, entity, target, route, direction); }
    DECL_FASTCALL_SIMPLE(ComputeRouteRoundEntityBoundingBox2, _ZN20CPedGeometryAnalyser34ComputeRouteRoundEntityBoundingBoxERK4CPedRK7CVectorR7CEntityS5_R11CPointRoutei, i32, CPed const& ped, CVector const& pos, CEntity& entity, CVector const& target, CPointRoute& route, i32 direction);
    inline static i32 ComputeRouteRoundEntityBoundingBox(CPed const& ped, CVector const& pos, CEntity& entity, CVector const& target, CPointRoute& route, i32 direction) { return ComputeRouteRoundEntityBoundingBox2(ped, pos, entity, target, route, direction); }
    DECL_FASTCALL_SIMPLE(ComputeRouteRoundSphere, _ZN20CPedGeometryAnalyser23ComputeRouteRoundSphereERK4CPedRK10CColSphereRK7CVectorS8_RS6_S9_, bool, CPed const& ped, CColSphere const& sphere, CVector const& pos, CVector const& target, CVector& outPoint1, CVector& outPoint2);
    DECL_FASTCALL_SIMPLE(ComputeClosestSurfacePoint1, _ZN20CPedGeometryAnalyser26ComputeClosestSurfacePointERK4CPedR7CEntityR7CVector, bool, CPed const& ped, CEntity& entity, CVector& outPoint);
    inline static bool ComputeClosestSurfacePoint(CPed const& ped, CEntity& entity, CVector& outPoint) { return ComputeClosestSurfacePoint1(ped, entity, outPoint); }
    DECL_FASTCALL_SIMPLE(ComputeClosestSurfacePoint2, _ZN20CPedGeometryAnalyser26ComputeClosestSurfacePointERK7CVectorR7CEntityRS0_, bool, CVector const& pos, CEntity& entity, CVector& outPoint);
    inline static bool ComputeClosestSurfacePoint(CVector const& pos, CEntity& entity, CVector& outPoint) { return ComputeClosestSurfacePoint2(pos, entity, outPoint); }
    DECL_FASTCALL_SIMPLE(ComputeClosestSurfacePoint3, _ZN20CPedGeometryAnalyser26ComputeClosestSurfacePointERK7CVectorPS1_RS0_, bool, CVector const& pos, CVector const* corners, CVector& outPoint);
    inline static bool ComputeClosestSurfacePoint(CVector const& pos, CVector const* corners, CVector& outPoint) { return ComputeClosestSurfacePoint3(pos, corners, outPoint); }
    DECL_FASTCALL_SIMPLE(GetIsLineOfSightClear1, _ZN20CPedGeometryAnalyser21GetIsLineOfSightClearERK4CPedRK7CVectorR7CEntityRf, bool, CPed const& ped, CVector const& target, CEntity& entity, float& outFraction);
    inline static bool GetIsLineOfSightClear(CPed const& ped, CVector const& target, CEntity& entity, float& outFraction) { return GetIsLineOfSightClear1(ped, target, entity, outFraction); }
    DECL_FASTCALL_SIMPLE(GetIsLineOfSightClear2, _ZN20CPedGeometryAnalyser21GetIsLineOfSightClearERK7CVectorS2_R7CEntity, bool, CVector const& pos, CVector const& target, CEntity& entity);
    inline static bool GetIsLineOfSightClear(CVector const& pos, CVector const& target, CEntity& entity) { return GetIsLineOfSightClear2(pos, target, entity); }
    DECL_FASTCALL_SIMPLE(IsWanderPathClear, _ZN20CPedGeometryAnalyser17IsWanderPathClearERK7CVectorS2_fi, i32, CVector const& pos, CVector const& target, float const radius, i32 const flags);
    DECL_FASTCALL_SIMPLE(CanPedJumpObstacle1, _ZN20CPedGeometryAnalyser18CanPedJumpObstacleERK4CPedRK7CEntityRK7CVectorS8_, bool, CPed const& ped, CEntity const& entity, CVector const& pos, CVector const& target);
    inline static bool CanPedJumpObstacle(CPed const& ped, CEntity const& entity, CVector const& pos, CVector const& target) { return CanPedJumpObstacle1(ped, entity, pos, target); }
    DECL_FASTCALL_SIMPLE(CanPedJumpObstacle2, _ZN20CPedGeometryAnalyser18CanPedJumpObstacleERK4CPedRK7CEntity, bool, CPed const& ped, CEntity const& entity);
    inline static bool CanPedJumpObstacle(CPed const& ped, CEntity const& entity) { return CanPedJumpObstacle2(ped, entity); }
    DECL_FASTCALL_SIMPLE(ComputePedShotSide, _ZN20CPedGeometryAnalyser18ComputePedShotSideERK4CPedRK7CVector, i32, CPed const& ped, CVector const& shotPos);
    DECL_FASTCALL_SIMPLE(CanPedTargetPoint, _ZN20CPedGeometryAnalyser17CanPedTargetPointERK4CPedRK7CVectorb, bool, CPed const& ped, CVector const& target, bool const includeDeadPeds);
    DECL_FASTCALL_SIMPLE(CanPedTargetPed, _ZN20CPedGeometryAnalyser15CanPedTargetPedER4CPedS1_b, bool, CPed& ped, CPed& targetPed, bool const includeDeadPeds);
    DECL_FASTCALL_SIMPLE(IsInAir, _ZN20CPedGeometryAnalyser7IsInAirERK4CPed, bool, CPed const& ped);
    DECL_FASTCALL_SIMPLE(GetNearestPed, _ZN20CPedGeometryAnalyser13GetNearestPedERK7CVector, CPed const*, CVector const& pos);
    DECL_FASTCALL_SIMPLE(ComputeClearTarget, _ZN20CPedGeometryAnalyser18ComputeClearTargetERK4CPedRK7CVectorRS3_, void, CPed const& ped, CVector const& target, CVector& outTarget);
    DECL_FASTCALL_SIMPLE(ComputeBuildingHitPoints, _ZN20CPedGeometryAnalyser24ComputeBuildingHitPointsERK7CVectorS2_, i32, CVector const& pos, CVector const& target);
    DECL_FASTCALL_SIMPLE(LiesInsideBoundingBox, _ZN20CPedGeometryAnalyser21LiesInsideBoundingBoxERK4CPedRK7CVectorR7CEntity, bool, CPed const& ped, CVector const& pos, CEntity& entity);
    DECL_FASTCALL_SIMPLE(IsEntityBlockingTarget, _ZN20CPedGeometryAnalyser22IsEntityBlockingTargetEP7CEntityRK7CVectorf, bool, CEntity* entity, CVector const& target, float radius);
    DECL_FASTCALL_SIMPLE(ComputeEntityBoundingBoxCentreUncachedAll, _ZN20CPedGeometryAnalyser41ComputeEntityBoundingBoxCentreUncachedAllEfR7CEntityR7CVector, void, float scale, CEntity& entity, CVector& outCentre);
    DECL_FASTCALL_SIMPLE(ComputeEntityBoundingBoxCentreUncached, _ZN20CPedGeometryAnalyser38ComputeEntityBoundingBoxCentreUncachedEfPK7CVectorRS0_, void, float const scale, CVector const* corners, CVector& outCentre);
    DECL_FASTCALL_SIMPLE(ComputeEntityBoundingBoxCornersUncached, _ZN20CPedGeometryAnalyser39ComputeEntityBoundingBoxCornersUncachedEfR7CEntityP7CVector, bool, float const scale, CEntity& entity, CVector* outCorners);
    DECL_FASTCALL_SIMPLE(ComputeEntityBoundingBoxPlanesUncachedAll, _ZN20CPedGeometryAnalyser41ComputeEntityBoundingBoxPlanesUncachedAllEfR7CEntityP7CVectorPf, void, float const scale, CEntity& entity, CVector* outCorners, float* outPlanes);
    DECL_FASTCALL_SIMPLE(ComputeEntityBoundingBoxPlanesUncached, _ZN20CPedGeometryAnalyser38ComputeEntityBoundingBoxPlanesUncachedEfPK7CVectorPS0_Pf, void, float const scale, CVector const* corners, CVector* outCorners, float* outPlanes);
    DECL_FASTCALL_SIMPLE(ComputeEntityBoundingBoxSegmentPlanesUncachedAll, _ZN20CPedGeometryAnalyser48ComputeEntityBoundingBoxSegmentPlanesUncachedAllEfR7CEntityP7CVectorPf, void, float const scale, CEntity& entity, CVector* outCorners, float* outPlanes);
    DECL_FASTCALL_SIMPLE(ComputeEntityBoundingBoxSegmentPlanesUncached, _ZN20CPedGeometryAnalyser45ComputeEntityBoundingBoxSegmentPlanesUncachedEPK7CVectorRS0_PS0_Pf, void, CVector const* corners, CVector& pos, CVector* outCorners, float* outPlanes);

    // STATIC values
    DECL_OBJECT_SYM(float const, ms_fTargetRange, _ZN20CPedGeometryAnalyser15ms_fTargetRangeE);
    DECL_OBJECT_SYM(float const, ms_fInAirOffset, _ZN20CPedGeometryAnalyser15ms_fInAirOffsetE);
    DECL_OBJECT_SYM(float const, ms_fClearTargetSearchDistance, _ZN20CPedGeometryAnalyser29ms_fClearTargetSearchDistanceE);
    DECL_OBJECT_PLT(float, ms_fPedNominalRadius, BYBIT(0x676cb0, 0x84b9a8));
    DECL_OBJECT_SYM(bool const, ms_bUseEntityBoundsCaching, _ZN20CPedGeometryAnalyser26ms_bUseEntityBoundsCachingE);
    DECL_OBJECT_SYM(bool const, ms_bUseLineOfSightCaching, _ZN20CPedGeometryAnalyser25ms_bUseLineOfSightCachingE);
    DECL_OBJECT_SYM(bool const, ms_bDisplayProfilingInfo, _ZN20CPedGeometryAnalyser24ms_bDisplayProfilingInfoE);
DECL_CLASS_END()
CHECKSIZE(CPedGeometryAnalyser, 0x1, 0x1);

#endif // __AML_PSDK_SAPEDGEOMETRYANALYSER_H
