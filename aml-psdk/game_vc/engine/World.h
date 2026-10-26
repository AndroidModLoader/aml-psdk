#ifndef __AML_PSDK_VCWORLD_H
#define __AML_PSDK_VCWORLD_H

#include <aml-psdk/game_vc/plugin.h>
#include <aml-psdk/gta_base/Vector.h>
#include "../base/ColModel.h"

struct CEntity;

DECL_CLASS(CWorld)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(Add, _ZN6CWorld3AddEP7CEntity, void, CEntity* entity);
    DECL_FASTCALL_SIMPLE(Remove, _ZN6CWorld6RemoveEP7CEntity, void, CEntity* entity);
    DECL_FASTCALL_SIMPLE(GetIsLineOfSightClear, _ZN6CWorld21GetIsLineOfSightClearERK7CVectorS2_bbbbbbb, bool, CVector const& start, CVector const& end, bool buildings, bool vehicles, bool peds, bool objects, bool dummies, bool seeThrough, bool ignoreSomeObjectsForCamera);
    DECL_FASTCALL_SIMPLE(CameraToIgnoreThisObject, _ZN6CWorld24CameraToIgnoreThisObjectEP7CEntity, bool, CEntity* entity);
    DECL_FASTCALL_SIMPLE(FindGroundZForCoord, _ZN6CWorld19FindGroundZForCoordEff, float, float x, float y);
    DECL_FASTCALL_SIMPLE(FindGroundZFor3DCoord, _ZN6CWorld21FindGroundZFor3DCoordEfffPb, float, float x, float y, float z, bool* found);
    DECL_FASTCALL_SIMPLE(FindRoofZFor3DCoord, _ZN6CWorld19FindRoofZFor3DCoordEfffPb, float, float x, float y, float z, bool* found);
    DECL_FASTCALL_SIMPLE(FindLowestZForCoord, _ZN6CWorld19FindLowestZForCoordEff, float, float x, float y);
    DECL_FASTCALL_SIMPLE(FindObjectsInRange, _ZN6CWorld18FindObjectsInRangeERK7CVectorfbPssPP7CEntitybbbbb, void, CVector const& center, float radius, bool distance2D, i16* count, i16 maxCount, CEntity** entities, bool buildings, bool vehicles, bool peds, bool objects, bool dummies);
    DECL_FASTCALL_SIMPLE(FindObjectsOfTypeInRange, _ZN6CWorld24FindObjectsOfTypeInRangeEjRK7CVectorfbPssPP7CEntitybbbbb, void, u32 modelId, CVector const& center, float radius, bool distance2D, i16* count, i16 maxCount, CEntity** entities, bool buildings, bool vehicles, bool peds, bool objects, bool dummies);
    DECL_FASTCALL_SIMPLE(FindObjectsKindaColliding, _ZN6CWorld25FindObjectsKindaCollidingERK7CVectorfbPssPP7CEntitybbbbb, void, CVector const& center, float radius, bool distance2D, i16* count, i16 maxCount, CEntity** entities, bool buildings, bool vehicles, bool peds, bool objects, bool dummies);
    DECL_FASTCALL_SIMPLE(FindObjectsIntersectingCube, _ZN6CWorld27FindObjectsIntersectingCubeERK7CVectorS2_PssPP7CEntitybbbbb, void, CVector const& min, CVector const& max, i16* count, i16 maxCount, CEntity** entities, bool buildings, bool vehicles, bool peds, bool objects, bool dummies);
    DECL_FASTCALL_SIMPLE(FindMissionEntitiesIntersectingCube, _ZN6CWorld35FindMissionEntitiesIntersectingCubeERK7CVectorS2_PssPP7CEntitybbb, void, CVector const& min, CVector const& max, i16* count, i16 maxCount, CEntity** entities, bool vehicles, bool peds, bool objects);
    DECL_FASTCALL_SIMPLE(TestSphereAgainstWorld, _ZN6CWorld22TestSphereAgainstWorldE7CVectorfP7CEntitybbbbbb, CEntity*, CVector center, float radius, CEntity* ignoreEntity, bool buildings, bool vehicles, bool peds, bool objects, bool dummies, bool ignoreSeeThrough);
    DECL_FASTCALL_SIMPLE(IsWanderPathClear, _ZN6CWorld17IsWanderPathClearERK7CVectorS2_fi, bool, CVector const& start, CVector const& end, float maxHeightDifference, i32 maxDistance);
    DECL_FASTCALL_SIMPLE(RemoveReferencesToDeletedObject, _ZN6CWorld31RemoveReferencesToDeletedObjectEP7CEntity, void, CEntity* entity);
    DECL_FASTCALL_SIMPLE(ClearExcitingStuffFromArea, _ZN6CWorld26ClearExcitingStuffFromAreaERK7CVectorfh, void, CVector const& center, float radius, u8 removeProjectiles);
    DECL_FASTCALL_SIMPLE(ClearCarsFromArea, _ZN6CWorld17ClearCarsFromAreaEffffff, void, float minX, float minY, float minZ, float maxX, float maxY, float maxZ);
    DECL_FASTCALL_SIMPLE(ClearPedsFromArea, _ZN6CWorld17ClearPedsFromAreaEffffff, void, float minX, float minY, float minZ, float maxX, float maxY, float maxZ);
    DECL_FASTCALL_SIMPLE(SetAllCarsCanBeDamaged, _ZN6CWorld22SetAllCarsCanBeDamagedEb, void, bool canBeDamaged);
    DECL_FASTCALL_SIMPLE(CallOffChaseForArea, _ZN6CWorld19CallOffChaseForAreaEffff, void, float minX, float minY, float maxX, float maxY);
    DECL_FASTCALL_SIMPLE(SetPedsOnFire, _ZN6CWorld13SetPedsOnFireEffffP7CEntity, void, float x, float y, float z, float radius, CEntity* creator);
    DECL_FASTCALL_SIMPLE(SetPedsChoking, _ZN6CWorld14SetPedsChokingEffffP7CEntity, void, float x, float y, float z, float radius, CEntity* creator);
    DECL_FASTCALL_SIMPLE(SetCarsOnFire, _ZN6CWorld13SetCarsOnFireEffffP7CEntity, void, float x, float y, float z, float radius, CEntity* creator);
    DECL_FASTCALL_SIMPLE(TriggerExplosion, _ZN6CWorld16TriggerExplosionERK7CVectorffP7CEntityb, void, CVector const& position, float radius, float impulse, CEntity* explodingEntity, bool processVehicleBombTimers);
    DECL_FASTCALL_SIMPLE(ExtinguishAllCarFiresInArea, _ZN6CWorld27ExtinguishAllCarFiresInAreaE7CVectorf, void, CVector center, float radius);
    DECL_FASTCALL_SIMPLE(StopAllLawEnforcersInTheirTracks, _ZN6CWorld32StopAllLawEnforcersInTheirTracksEv, void);
    DECL_FASTCALL_SIMPLE(FindPlayerSlotWithPedPointer, _ZN6CWorld28FindPlayerSlotWithPedPointerEPv, i32, void* ped);

    DECL_FASTCALL_SIMPLE(ProcessLineOfSight, _ZN6CWorld18ProcessLineOfSightERK7CVectorS2_R9CColPointRP7CEntitybbbbbbbb, bool, CVector const& start, CVector const& end, CColPoint& point, CEntity*& entity, bool buildings, bool vehicles, bool peds, bool objects, bool dummies, bool seeThrough, bool ignoreSomeObjectsForCamera, bool shootThrough);
    DECL_FASTCALL_SIMPLE(ProcessVerticalLine, _ZN6CWorld19ProcessVerticalLineERK7CVectorfR9CColPointRP7CEntitybbbbbbP15CStoredCollPoly, bool, CVector const& start, float endZ, CColPoint& point, CEntity*& entity, bool buildings, bool vehicles, bool peds, bool objects, bool dummies, bool seeThrough, CStoredCollPoly* storedPoly);

    // STATIC values
    DECL_VALUE_PLT_U8(PlayerInFocus, BYBIT(0x394A44, 0x577578));
    DECL_VALUE_PLT_BOOL(bIncludeCarTyres, BYBIT(0x394EF4, 0x577E68));
    DECL_VALUE_PLT_BOOL(bIncludeDeadPeds, BYBIT(0x395E54, 0x579CD8));
    DECL_VALUE_PLT_BOOL(bIncludeBikers, BYBIT(0x395F88, 0x579F30));
    DECL_OBJECT_PLT(CEntity*, pIgnoreEntity, BYBIT(0x396E9C, 0x57BD30));
DECL_CLASS_END()

#define PlayerInFocus PlayerInFocus()
#define bIncludeCarTyres bIncludeCarTyres()
#define bIncludeDeadPeds bIncludeDeadPeds()
#define bIncludeBikers bIncludeBikers()
#define pIgnoreEntity pIgnoreEntity()

#endif // __AML_PSDK_VCWORLD_H
