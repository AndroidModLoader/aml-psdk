#ifndef __AML_PSDK_SACALLEVENTS_H
#define __AML_PSDK_SACALLEVENTS_H

#include "plugin.h"
#include <aml-psdk/sdk_callevents.h>
#include <aml-psdk/gta_base/Vector.h>
#include <aml-psdk/game_sa/enum/WeaponType.h>
#include <aml-psdk/game_sa/other/Explosion.h>

struct CCamera;
struct CEntity;
struct CWeapon;
struct CPickup;
struct CPlayerPed;
struct CRunningScript;
struct CVehicle;
struct CPed;
struct CObject;
struct MobileMenu;
struct CPlayerInfo;
struct CPedDamageResponseCalculator;
struct CPedDamageResponse;
struct CWanted;
struct CFire;
struct CAudioEngine;

struct Events
{
    B32MACRO(typedef CVehicle* VehicleLifetimeReturn;)
    B64MACRO(typedef void VehicleLifetimeReturn;)
    B32MACRO(typedef CPed* PedLifetimeReturn;)
    B64MACRO(typedef void PedLifetimeReturn;)
    B32MACRO(typedef CObject* ObjectLifetimeReturn;)
    B64MACRO(typedef void ObjectLifetimeReturn;)

    // PC psdk events (they are slightly different from PC. Please keep that in mind!)
    EVENT_PLT(restartGameEvent, void, (), BYBIT(0x674E38, 0x848318));
    EVENT_SYM(renderEffectsEvent, void, (), _Z13RenderEffectsv);
    EVENT_SYM(drawingEvent, void, (), _Z13Render2dStuffv);
    EVENT_PLT(drawHudEvent, void, (), BYBIT(0x6737EC, 0x845EC8));
    EVENT_PLT(drawAfterFadeEvent, void, (), BYBIT(0x673C4C, 0x846618));
    EVENT_SYM(drawRadarEvent, void, (), _ZN4CHud9DrawRadarEv);
    EVENT_PLT(drawBlipsEvent, void, (float), BYBIT(0x66E910, 0x83DED0));
    EVENT_SYM(drawRadarOverlayEvent, void, (bool), _ZN6CRadar20DrawRadarGangOverlayEb);
    // drawMenuBackgroundEvent
    EVENT_SYM(initRwEvent, bool, (), _ZN5CGame20InitialiseRenderWareEv);
    EVENT_PLT_BEFORE(shutdownRwEvent, void, (), BYBIT(0x6756F0, 0x849148));
    EVENT_SYM(vehicleCtorEvent, VehicleLifetimeReturn, (CVehicle*, u8), _ZN8CVehicleC2Eh, 0);
    EVENT_SYM_BEFORE(vehicleDtorEvent, VehicleLifetimeReturn, (CVehicle*), _ZN8CVehicleD2Ev, 0);
    EVENT_SYM(pedCtorEvent, PedLifetimeReturn, (CPed*, u32), _ZN4CPedC2Ej, 0);
    EVENT_SYM_BEFORE(pedDtorEvent, PedLifetimeReturn, (CPed*), _ZN4CPedD2Ev, 0);
    EVENT_SYM(objectCtorEvent, void, (CObject*), _ZN7CObject4InitEv, 0);
    EVENT_SYM_BEFORE(objectDtorEvent, ObjectLifetimeReturn, (CObject*), _ZN7CObjectD2Ev, 0);
    EVENT_PLT(initPoolsEvent, void, (), BYBIT(0x672468, 0x843F18));
    EVENT_PLT(shutdownPoolsEvent, void, (), BYBIT(0x66F218, 0x83EDC0));
    EVENT_SYM_BEFORE(vehicleRenderEvent, void, (CVehicle*), _ZN8CVehicle6RenderEv, 0);
    EVENT_SYM_BEFORE(pedRenderEvent, void, (CPed*), _ZN4CPed6RenderEv, 0);
    EVENT_SYM_BEFORE(objectRenderEvent, void, (CObject*), _ZN7CObject6RenderEv, 0);
    EVENT_SYM(vehicleSetModelEvent, void, (CVehicle*, u32), _ZN8CVehicle13SetModelIndexEj, 0, 1);
    EVENT_SYM(pedSetModelEvent, void, (CPed*, u32), _ZN4CPed13SetModelIndexEj, 0, 1);
    // d3dResetEvent // ogl analogue
    // d3dLostEvent // do we need this?
    EVENT_SYM(gameProcessEvent, void, (), _ZN5CGame7ProcessEv);
    EVENT_PLT(initGameEvent, void, (), BYBIT(0x6740A4, 0x846D20));
    EVENT_PLT(reInitGameEvent, void, (), BYBIT(0x672014, 0x843810));
    EVENT_PLT(initScriptsEvent, void, (), BYBIT(0x671B14, 0x842FC0));
    EVENT_PLT(processScriptsEvent, void, (), BYBIT(0x673178, 0x845438)); // wrong on PC. bruh...
    EVENT_PLT(menuDrawingEvent, void, (MobileMenu*), BYBIT(0x674254, 0x846FE8));
    EVENT_SYM(attachRwPluginsEvent, int, (), _Z12PluginAttachv);

    // Additional events (aml psdk)
    EVENT_PLT(processCameraEvent, void, (CCamera* camera), BYBIT(0x6717BC, 0x8429D8), 0);
    EVENT_PLT(initWidgetsEvent, void, (), BYBIT(0x6734E4, 0x8459D8));
    EVENT_PLT(updateWidgetsEvent, void, (), BYBIT(0x6746E4, 0x847780));
    EVENT_SYM(initGameStage1Event, bool, (const char*), _ZN5CGame5Init1EPKc);
    EVENT_SYM(initGameStage2Event, bool, (const char*), _ZN5CGame5Init2EPKc);
    EVENT_SYM(initGameStage3Event, bool, (const char*), _ZN5CGame5Init3EPKc);
    EVENT_SYM(menuUpdateEvent, void, (MobileMenu*), _ZN10MobileMenu6UpdateEv);
    EVENT_SYM(renderSpecialEffectsEvent, void, (), _ZN10CSpecialFX6RenderEv);
    EVENT_SYM(renderWeaponEffectsEvent, void, (), _ZN14CWeaponEffects6RenderEv);
    EVENT_SYM(renderCoronasEvent, void, (), _ZN8CCoronas6RenderEv);
    EVENT_SYM(updateCoronasEvent, void, (), _ZN8CCoronas6UpdateEv);
    EVENT_SYM(gameLogicUpdateEvent, void, (), _ZN10CGameLogic6UpdateEv);
    EVENT_SYM(preinitEngineEvent, bool, (), _ZN5CGame22InitialiseOnceBeforeRWEv);
    EVENT_SYM(initEngineEvent, int, (), _Z12RsInitializev);
    EVENT_SYM(touchScreenEvent, void, (int actionType, int trackNum, int x, int y), _Z14AND_TouchEventiiii, 0, 1, 2, 3);
    EVENT_SYM(pedPreRenderEvent, void, (CPed* ped), _ZN4CPed18PreRenderAfterTestEv, 0);
    EVENT_SYM(cloudsRenderEvent, void, (), _ZN7CClouds6RenderEv);
    EVENT_SYM(roadsRenderEvent, void, (), _ZN9CRenderer11RenderRoadsEv);
    EVENT_SYM(barRoadsRenderEvent, void, (), _ZN9CRenderer24RenderEverythingBarRoadsEv);
    EVENT_SYM(waterRenderEvent, void, (), _ZN11CWaterLevel11RenderWaterEv);
    EVENT_SYM(timerUpdateEvent, void, (), _ZN6CTimer6UpdateEv);
    EVENT_SYM(playerInfoUpdateEvent, void, (CPlayerInfo* info, int playerNum), _ZN11CPlayerInfo7ProcessEi, 0, 1);
    EVENT_SYM(loadIdeEvent, int, (const char*), _ZN11CFileLoader10LoadObjectEPKc, 0);

    EVENT_SYM_BEFORE(shutdownGameEvent, bool, (), _ZN5CGame8ShutdownEv);
    EVENT_SYM(saveGameEvent, bool, (int slot), _ZN19CGenericGameStorage11GenericSaveEi, 0);
    EVENT_SYM(loadGameEvent, bool, (bool& wrongVersion), _ZN19CGenericGameStorage11GenericLoadERb, 0);
    EVENT_SYM(entityAddEvent, void, (CEntity* entity), _ZN6CWorld3AddEP7CEntity, 0);
    EVENT_SYM_BEFORE(entityRemoveEvent, void, (CEntity* entity), _ZN6CWorld6RemoveEP7CEntity, 0);
    EVENT_SYM(worldProcessEvent, void, (), _ZN6CWorld7ProcessEv);
    EVENT_SYM(streamingUpdateEvent, void, (), _ZN10CStreaming6UpdateEv);
    EVENT_SYM(requestModelEvent, void, (int modelId, int flags), _ZN10CStreaming12RequestModelEii, 0, 1);
    EVENT_SYM_BEFORE(removeModelEvent, void, (int modelId), _ZN10CStreaming11RemoveModelEi, 0);
    EVENT_SYM(convertModelEvent, bool, (char* buffer, int modelId, int channel), _ZN10CStreaming21ConvertBufferToObjectEPcii, 1, 2);
    EVENT_SYM(scriptInitEvent, void, (CRunningScript* script), _ZN14CRunningScript4InitEv, 0);
    EVENT_SYM(scriptProcessEvent, u8, (CRunningScript* script), _ZN14CRunningScript7ProcessEv, 0);
    EVENT_SYM_BEFORE(scriptCommandEvent, i8, (CRunningScript* script), _ZN14CRunningScript17ProcessOneCommandEv, 0);
    EVENT_SYM_BEFORE(scriptShutdownEvent, void, (CRunningScript* script), _ZN14CRunningScript18ShutdownThisScriptEv, 0);
    EVENT_SYM(userPauseEvent, void, (), _ZN6CTimer14StartUserPauseEv);
    EVENT_SYM(userResumeEvent, void, (), _ZN6CTimer12EndUserPauseEv);
    EVENT_SYM_BEFORE(weaponFireEvent, bool, (CWeapon* weapon, CEntity* owner, CVector* start, CVector* barrel, CEntity* target, CVector* targetPos, CVector* driveByPos), _ZN7CWeapon4FireEP7CEntityP7CVectorS3_S1_S3_S3_, 0, 1, 2, 3, 4, 5, 6);
    EVENT_SYM(pedGiveWeaponEvent, int, (CPed* ped, eWeaponType weaponType, u32 ammo, bool makeCurrent), _ZN4CPed10GiveWeaponE11eWeaponTypejb, 0, 1, 2, 3);
    EVENT_SYM(vehicleDamageEvent, void, (CVehicle* vehicle, CEntity* attacker, eWeaponType weaponType, float damage, CVector hitPos), _ZN8CVehicle13InflictDamageEP7CEntity11eWeaponTypef7CVector, 0, 1, 2, 3, 4);
    EVENT_SYM(pickupUpdateEvent, bool, (CPickup* pickup, CPlayerPed* player, CVehicle* vehicle, int playerNum), _ZN7CPickup6UpdateEP10CPlayerPedP8CVehiclei, 0, 1, 2, 3);
    EVENT_SYM_BEFORE(pickupRemoveEvent, void, (CPickup* pickup), _ZN7CPickup6RemoveEv, 0);
    EVENT_SYM(pickupCollectedEvent, void, (int pickupIndex), _ZN8CPickups26AddToCollectedPickupsArrayEi, 0);
    EVENT_SYM(playerKillEvent, void, (CPlayerInfo* info), _ZN11CPlayerInfo10KillPlayerEv, 0);
    EVENT_SYM(playerArrestEvent, void, (CPlayerInfo* info), _ZN11CPlayerInfo12ArrestPlayerEv, 0);
    EVENT_SYM_BEFORE(frameEndEvent, void, (bool fromIdle), _Z19DoRWStuffEndOfFrameb, 0);
    EVENT_SYM(drawCrosshairEvent, void, (), _ZN4CHud14DrawCrossHairsEv);
    EVENT_SYM(render3dMarkersEvent, void, (), _ZN10C3dMarkers6RenderEv);
    EVENT_SYM(pedDamageResponseEvent, void, (CPedDamageResponseCalculator* calculator, CPed* ped, CPedDamageResponse& response, bool speak), _ZN28CPedDamageResponseCalculator21ComputeDamageResponseEP4CPedR18CPedDamageResponseb, 0, 1, 2, 3);
    EVENT_SYM(pedSetWeaponEvent, void, (CPed* ped, int weaponSlot), _ZN4CPed16SetCurrentWeaponEi, 0, 1);
    EVENT_SYM(pedClearWeaponsEvent, void, (CPed* ped), _ZN4CPed12ClearWeaponsEv, 0);
    EVENT_SYM(wantedLevelUpdateEvent, void, (CWanted* wanted), _ZN7CWanted17UpdateWantedLevelEv, 0);
    EVENT_SYM(addExplosionEvent, bool, (CEntity* victim, CEntity* creator, eExplosionType explosionType, CVector pos, u32 time, u8 makeSound, float cameraShake, u8 visibility), _ZN10CExplosion12AddExplosionEP7CEntityS1_14eExplosionType7CVectorjhfh, 0, 1, 2, 3, 4, 5, 6, 7);
    EVENT_SYM_BEFORE(fireExtinguishEvent, void, (CFire* fire), _ZN5CFire10ExtinguishEv, 0);
    EVENT_SYM(playerResurrectEvent, void, (CPlayerPed* player, CVector pos, float heading), _ZN10CGameLogic36RestorePlayerStuffDuringResurrectionEP10CPlayerPed7CVectorf, 0, 1, 2);
    EVENT_SYM_BEFORE(cutsceneLoadRequestEvent, void, (const char* name), _ZN12CCutsceneMgr16LoadCutsceneDataEPKc, 0);
    EVENT_SYM(cutsceneStartEvent, void, (), _ZN12CCutsceneMgr13StartCutsceneEv);
    EVENT_SYM(cutsceneFinishEvent, void, (), _ZN12CCutsceneMgr14FinishCutsceneEv);
    EVENT_SYM(cutsceneSkipEvent, void, (), _ZN12CCutsceneMgr12SkipCutsceneEv);
    EVENT_SYM_BEFORE(cutsceneDeleteEvent, void, (), _ZN12CCutsceneMgr18DeleteCutsceneDataEv);
    EVENT_SYM(pauseAllSoundsEvent, void, (CAudioEngine* audio), _ZN12CAudioEngine14PauseAllSoundsEv);
    EVENT_SYM(resumeAllSoundsEvent, void, (CAudioEngine* audio), _ZN12CAudioEngine15ResumeAllSoundsEv);
    EVENT_SYM(radioRetuneEvent, void, (CAudioEngine* audio, i8 stationId), _ZN12CAudioEngine11RetuneRadioEa, 0, 1);
    EVENT_SYM(forceWeatherEvent, void, (i16 weatherType), _ZN8CWeather12ForceWeatherEs, 0);
    EVENT_SYM(forceWeatherNowEvent, void, (i16 weatherType), _ZN8CWeather15ForceWeatherNowEs, 0);
    EVENT_SYM(releaseWeatherEvent, void, (), _ZN8CWeather14ReleaseWeatherEv);
};

#endif // __AML_PSDK_SACALLEVENTS_H
