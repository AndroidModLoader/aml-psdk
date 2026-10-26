#ifndef __AML_PSDK_VCCALLEVENTS_H
#define __AML_PSDK_VCCALLEVENTS_H

#include "plugin.h"
#include <aml-psdk/sdk_callevents.h>
#include <aml-psdk/gta_base/Vector.h>

enum OSEventType : i32
{
    OSET_RequestExit = 0x0,
    OSET_KeyboardDown = 0x1,
    OSET_KeyboardUp = 0x2,
    OSET_PointerMove = 0x3,
    OSET_PointerButton = 0x4,
    OSET_GamepadConnection = 0x5,
    OSET_GamepadButtonDown = 0x6,
    OSET_GamepadButtonUp = 0x7,
    OSET_Pause = 0x8,
    OSET_Resume = 0x9,
    OSET_KeyboardSoft = 0xA,
    OSET_LowMemory = 0x14,
};

struct CAutomobile;
struct CBike;
struct CBoat;
struct CCamera;
struct CDummyObject;
struct CEntity;
struct CFire;
struct CHeli;
struct CMenuManager;
struct CObject;
struct CPed;
struct CPickup;
struct CPlane;
struct CPlayerInfo;
struct CPlayerPed;
struct CRunningScript;
struct CVehicle;
struct CWeapon;
struct Touchscreen;
struct cAudioManager;
struct cMusicManager;

struct Events
{
    // PC psdk events (they are slightly different from PC. Please keep that in mind!)
    EVENT_SYM(initRwEvent, bool, (), _ZN5CGame20InitialiseRenderWareEv);
    EVENT_SYM_BEFORE(shutdownRwEvent, void, (), _ZN5CGame18ShutdownRenderWareEv);
    EVENT_SYM(initGameEvent, bool, (const char*), _ZN5CGame10InitialiseEPKc, 0);
    EVENT_SYM(restartGameEvent, void, (), _ZN5CGame24InitialiseWhenRestartingEv);
    EVENT_SYM(gameProcessEvent, void, (), _ZN5CGame7ProcessEv);
    EVENT_SYM(initScriptsEvent, void, (), _ZN11CTheScripts4InitEv);
    EVENT_SYM(processScriptsEvent, void, (), _ZN11CTheScripts7ProcessEv);
    EVENT_SYM(drawingEvent, void, (), _Z13Render2dStuffv);
    EVENT_SYM(drawHudEvent, void, (), _ZN4CHud4DrawEv);
    EVENT_SYM(drawBlipsEvent, void, (), _ZN6CRadar9DrawBlipsEv);
    EVENT_SYM(renderEffectsEvent, void, (), _Z13RenderEffectsv);
    EVENT_SYM(menuDrawingEvent, void, (CMenuManager* menu), _ZN12CMenuManager12DrawFrontEndEv, 0);
    EVENT_SYM(renderSceneEvent, void, (), _Z11RenderScenev);
    EVENT_SYM(drawFontsEvent, void, (), _ZN5CFont16RenderFontBufferEv);
    EVENT_SYM(drawRadarMapEvent, void, (), _ZN6CRadar12DrawRadarMapEv);
    EVENT_SYM(initPoolsEvent, void, (), _ZN6CPools10InitialiseEv);
    EVENT_SYM(shutdownPoolsEvent, void, (), _ZN6CPools8ShutDownEv);
    EVENT_SYM(attachRwPluginsEvent, bool, (), _Z12PluginAttachv);
    EVENT_SYM(vehicleCtorEvent, PSDK_LIFETIME_RET(CVehicle), (CVehicle* vehicle, u8 createdBy), _ZN8CVehicleC2Eh, 0);
    EVENT_SYM_BEFORE(vehicleDtorEvent, PSDK_LIFETIME_RET(CVehicle), (CVehicle* vehicle), _ZN8CVehicleD2Ev, 0);
    EVENT_SYM(pedCtorEvent, PSDK_LIFETIME_RET(CPed), (CPed* ped, u32 pedType), _ZN4CPedC2Ej, 0);
    EVENT_SYM_BEFORE(pedDtorEvent, PSDK_LIFETIME_RET(CPed), (CPed* ped), _ZN4CPedD2Ev, 0);
    EVENT_SYM(objectCtorEvent, PSDK_LIFETIME_RET(CObject), (CObject* object), _ZN7CObjectC2Ev, 0);
    EVENT_SYM_BEFORE(objectDtorEvent, PSDK_LIFETIME_RET(CObject), (CObject* object), _ZN7CObjectD2Ev, 0);
    EVENT_SYM_BEFORE(pedRenderEvent, void, (CPed* ped), _ZN4CPed6RenderEv, 0);
    EVENT_SYM_BEFORE(objectRenderEvent, void, (CObject* object), _ZN7CObject6RenderEv, 0);
    EVENT_SYM(vehicleSetModelEvent, void, (CVehicle* vehicle, u32 modelId), _ZN8CVehicle13SetModelIndexEj, 0, 1);
    EVENT_SYM(pedSetModelEvent, void, (CPed* ped, u32 modelId), _ZN4CPed13SetModelIndexEj, 0, 1);

    // Additional events (aml psdk)
    EVENT_SYM(preinitEngineEvent, bool, (), _ZN5CGame22InitialiseOnceBeforeRWEv);
    EVENT_SYM_BEFORE(shutdownGameEvent, bool, (), _ZN5CGame8ShutdownEv);
    EVENT_SYM(reInitGameEvent, void, (), _ZN5CGame25ReInitGameObjectVariablesEv);
    EVENT_SYM(worldProcessEvent, void, (), _ZN6CWorld7ProcessEv);
    EVENT_SYM(processCameraEvent, void, (CCamera* camera), _ZN7CCamera7ProcessEv, 0);
    EVENT_SYM(timerUpdateEvent, void, (), _ZN6CTimer6UpdateEv);
    EVENT_SYM(weatherUpdateEvent, void, (), _ZN8CWeather6UpdateEv);
    EVENT_SYM(streamingUpdateEvent, void, (), _ZN10CStreaming6UpdateEv);
    EVENT_SYM(drawAfterFadeEvent, void, (), _ZN4CHud13DrawAfterFadeEv);
    EVENT_SYM(renderCoronasEvent, void, (), _ZN8CCoronas6RenderEv);
    EVENT_SYM(updateCoronasEvent, void, (), _ZN8CCoronas6UpdateEv);
    EVENT_SYM(waterRenderEvent, void, (), _ZN11CWaterLevel11RenderWaterEv);
    EVENT_SYM(initEngineEvent, i32, (), _Z12RsInitializev);
    EVENT_SYM(menuUpdateEvent, void, (CMenuManager* menu), _ZN12CMenuManager7ProcessEv, 0);
    EVENT_SYM(objectModelCtorEvent, PSDK_LIFETIME_RET(CObject), (CObject* object, i32 modelId, bool createRwObject), _ZN7CObjectC2Eib, 0, 1, 2);
    EVENT_SYM(objectDummyCtorEvent, PSDK_LIFETIME_RET(CObject), (CObject* object, CDummyObject* dummy), _ZN7CObjectC2EP12CDummyObject, 0, 1);
    EVENT_SYM(entitySetModelEvent, void, (CEntity* entity, u32 modelId), _ZN7CEntity13SetModelIndexEj, 0, 1);
    EVENT_SYM_BEFORE(entityRenderEvent, void, (CEntity* entity), _ZN7CEntity6RenderEv, 0);
    EVENT_SYM_BEFORE(automobileRenderEvent, void, (CAutomobile* vehicle), _ZN11CAutomobile6RenderEv, 0);
    EVENT_SYM_BEFORE(bikeRenderEvent, void, (CBike* vehicle), _ZN5CBike6RenderEv, 0);
    EVENT_SYM_BEFORE(boatRenderEvent, void, (CBoat* vehicle), _ZN5CBoat6RenderEv, 0);
    EVENT_SYM_BEFORE(heliRenderEvent, void, (CHeli* vehicle), _ZN5CHeli6RenderEv, 0);
    EVENT_SYM_BEFORE(planeRenderEvent, void, (CPlane* vehicle), _ZN6CPlane6RenderEv, 0);
    EVENT_SYM(scriptStartEvent, CRunningScript*, (i32 startOffset), _ZN11CTheScripts14StartNewScriptEi, 0);
    EVENT_SYM(scriptProcessEvent, u8, (CRunningScript* script), _ZN14CRunningScript7ProcessEv, 0);
    EVENT_SYM_BEFORE(scriptCommandEvent, i8, (CRunningScript* script), _ZN14CRunningScript17ProcessOneCommandEv, 0);
    EVENT_SYM(requestModelEvent, void, (i32 modelId, i32 flags), _ZN10CStreaming12RequestModelEii, 0, 1);
    EVENT_SYM_BEFORE(removeModelEvent, void, (i32 modelId), _ZN10CStreaming11RemoveModelEi, 0);
    EVENT_SYM(convertModelEvent, bool, (char* buffer, i32 modelId), _ZN10CStreaming21ConvertBufferToObjectEPci, 1);
    EVENT_SYM(entityAddEvent, void, (CEntity* entity), _ZN6CWorld3AddEP7CEntity, 0);
    EVENT_SYM_BEFORE(entityRemoveEvent, void, (CEntity* entity), _ZN6CWorld6RemoveEP7CEntity, 0);
    EVENT_SYM(userPauseEvent, void, (), _ZN6CTimer14StartUserPauseEv);
    EVENT_SYM(userResumeEvent, void, (), _ZN6CTimer12EndUserPauseEv);
    EVENT_SYM(playerInfoUpdateEvent, void, (CPlayerInfo* info), _ZN11CPlayerInfo7ProcessEv, 0);
    EVENT_SYM(playerKillEvent, void, (CPlayerInfo* info), _ZN11CPlayerInfo10KillPlayerEv, 0);
    EVENT_SYM(playerArrestEvent, void, (CPlayerInfo* info), _ZN11CPlayerInfo12ArrestPlayerEv, 0);
    EVENT_SYM(pedGiveWeaponEvent, i32, (CPed* ped, i32 weaponType, u32 ammo, bool makeCurrent), _ZN4CPed10GiveWeaponE11eWeaponTypejb, 0, 1, 2, 3);
    EVENT_SYM(pedSetWeaponEvent, void, (CPed* ped, i32 weaponSlot), _ZN4CPed16SetCurrentWeaponEi, 0, 1);
    EVENT_SYM(pedClearWeaponsEvent, void, (CPed* ped), _ZN4CPed12ClearWeaponsEv, 0);
    EVENT_SYM_BEFORE(weaponFireEvent, bool, (CWeapon* weapon, CEntity* owner, CVector* start), _ZN7CWeapon4FireEP7CEntityP7CVector, 0, 1, 2);
    EVENT_SYM(vehicleDamageEvent, void, (CVehicle* vehicle, CEntity* attacker, i32 weaponType, float damage, CVector hitPos), _ZN8CVehicle13InflictDamageEP7CEntity11eWeaponTypef7CVector, 0, 1, 2, 3, 4);
    EVENT_SYM(pedDamageEvent, bool, (CPed* ped, void* attacker, i32 weaponType, float damage, i32 hitPiece, u8 direction), _ZN4CPed13InflictDamageEPv11eWeaponTypef14ePedPieceTypesh, 0, 1, 2, 3, 4, 5);
    EVENT_SYM(pickupUpdateEvent, bool, (CPickup* pickup, CPlayerPed* player, CVehicle* vehicle, i32 playerNum), _ZN7CPickup6UpdateEP10CPlayerPedP8CVehiclei, 0, 1, 2, 3);
    EVENT_SYM_BEFORE(pickupRemoveEvent, void, (i32 pickupRef), _ZN8CPickups12RemovePickUpEi, 0);
    EVENT_SYM(playerResurrectEvent, void, (CPlayerPed* player, CVector pos, float heading), _ZN10CGameLogic36RestorePlayerStuffDuringResurrectionEP10CPlayerPed7CVectorf, 0, 1, 2);
    EVENT_SYM(addExplosionEvent, bool, (CEntity* victim, CEntity* creator, i32 explosionType, CVector const& pos, u32 time, u8 makeSound, float cameraShake), _ZN10CExplosion12AddExplosionEP7CEntityS1_14eExplosionTypeRK7CVectorjhf, 0, 1, 2, 3, 4, 5, 6);
    EVENT_SYM_BEFORE(fireExtinguishEvent, void, (CFire* fire), _ZN5CFire10ExtinguishEv, 0);
    EVENT_SYM(forceWeatherEvent, void, (i16 weatherType), _ZN8CWeather12ForceWeatherEs, 0);
    EVENT_SYM(forceWeatherNowEvent, void, (i16 weatherType), _ZN8CWeather15ForceWeatherNowEs, 0);
    EVENT_SYM(releaseWeatherEvent, void, (), _ZN8CWeather14ReleaseWeatherEv);
    EVENT_SYM(gameLogicUpdateEvent, void, (), _ZN10CGameLogic6UpdateEv);
    EVENT_SYM(loadGameEvent, bool, (), _Z11GenericLoadv);
    EVENT_SYM(saveGameEvent, bool, (FILESTREAM file), SELBYBIT(_Z11GenericSavej, _Z11GenericSavey), 0);
    EVENT_SYM_BEFORE(cutsceneLoadRequestEvent, void, (const char* name), _ZN12CCutsceneMgr16LoadCutsceneDataEPKc, 0);
    EVENT_SYM(cutsceneStartEvent, void, (), _ZN12CCutsceneMgr20SetupCutsceneToStartEv);
    EVENT_SYM(cutsceneCameraFinishEvent, void, (CCamera* camera), _ZN7CCamera14FinishCutsceneEv, 0);
    EVENT_SYM_BEFORE(cutsceneDeleteEvent, void, (), _ZN12CCutsceneMgr18DeleteCutsceneDataEv);
    EVENT_SYM(cutsceneUpdateEvent, void, (), _ZN12CCutsceneMgr6UpdateEv);
    EVENT_SYM(audioServiceEvent, void, (cAudioManager* audio), _ZN13cAudioManager7ServiceEv, 0);
    EVENT_SYM(setRadioChannelEvent, void, (cMusicManager* music, u32 channel, i32 position), _ZN13cMusicManager23SetRadioChannelByScriptEji, 0, 1, 2);
    EVENT_SYM(musicModeChangeEvent, void, (cMusicManager* music, u8 mode), _ZN13cMusicManager15ChangeMusicModeEh, 0, 1);
    EVENT_SYM(renderSpecialEffectsEvent, void, (), _ZN10CSpecialFX6RenderEv);
    EVENT_SYM(renderWeaponEffectsEvent, void, (), _ZN14CWeaponEffects6RenderEv);
    EVENT_SYM(render3dMarkersEvent, void, (), _ZN10C3dMarkers6RenderEv);
    EVENT_SYM(roadsRenderEvent, void, (), _ZN9CRenderer11RenderRoadsEv);
    EVENT_SYM(barRoadsRenderEvent, void, (), _ZN9CRenderer24RenderEverythingBarRoadsEv);
    EVENT_SYM(preRenderEvent, void, (), _ZN9CRenderer9PreRenderEv);
    EVENT_SYM(constructRenderListEvent, void, (), _ZN9CRenderer19ConstructRenderListEv);
    EVENT_SYM(horizonRenderEvent, void, (), _ZN7CClouds13RenderHorizonEv);

    // Exclusive mobile events
    EVENT_SYM(touchScreenEvent, void, (int actionType, int trackNum, int x, int y), _Z14AND_TouchEventiiii, 0, 1, 2, 3);
    EVENT_SYM(initWidgetsEvent, void, (Touchscreen* widgets), _ZN11Touchscreen10InitializeEv, 0);
    EVENT_SYM_BEFORE(shutdownWidgetsEvent, PSDK_LIFETIME_RET(Touchscreen), (Touchscreen* widgets), _ZN11TouchscreenD2Ev, 0);
    EVENT_SYM(updateWidgetsEvent, void, (Touchscreen* widgets, float timeStep, bool enabled), _ZN11Touchscreen6UpdateEfb, 0, 1, 2);
    EVENT_SYM(drawWidgetsEvent, void, (Touchscreen* widgets), _ZN11Touchscreen6RenderEv, 0);
    EVENT_SYM(updateWidgetAdjustmentEvent, void, (Touchscreen* widgets, float timeStep), _ZN11Touchscreen16UpdateAdjustmentEf, 0, 1);
    EVENT_SYM(moveWidgetEvent, bool, (Touchscreen* widgets, i32 button, float x, float y), _ZN11Touchscreen10MoveButtonEiff, 0, 1, 2, 3);
    EVENT_SYM(resizeWidgetEvent, void, (Touchscreen* widgets, i32 button), _ZN11Touchscreen12ResizeButtonEi, 0, 1);
    EVENT_SYM(keyboardEvent, void, (bool down, i32 keyCode, i32 unicode, bool softKeyboard), _Z17AND_KeyboardEventbiib, 0, 1, 2, 3);
    EVENT_SYM(gamepadUpdateEvent, void, (), _Z17AND_GamepadUpdatev);
    EVENT_SYM_BEFORE(screenSwapBuffersEvent, void, (), _Z20OS_ScreenSwapBuffersv);
    EVENT_SYM(mobileProcessEvent, bool, (float timeStep), _Z12MainGameTickf, 0);
    EVENT_SYM(processInputEventsEvent, bool, (bool), _Z13ProcessEventsb, 0);
    EVENT_SYM(initGraphicsEvent, bool, (), _Z12initGraphicsv);
    EVENT_SYM(makeCurrentEvent, void, (), _Z20OS_ThreadMakeCurrentv);
    EVENT_SYM_BEFORE(unmakeCurrentEvent, void, (), _Z22OS_ThreadUnmakeCurrentv);
    EVENT_SYM(applicationEvent, void, (OSEventType type, void* data), _Z19OS_ApplicationEvent11OSEventTypePv, 0, 1);
};

#endif // __AML_PSDK_VCCALLEVENTS_H
