#ifndef __AML_PSDK_SACALLEVENTS_H
#define __AML_PSDK_SACALLEVENTS_H

#include "plugin.h"
#include <aml-psdk/sdk_callevents.h>

struct CCamera;
struct CVehicle;
struct CPed;
struct CObject;
struct MobileMenu;
struct CPlayerInfo;

struct Events
{
    // PC psdk events (they are slightly different from PC. Please keep that in mind!)
    EVENT_PLT(restartGameEvent, void, (), BYBIT(0x674E38, 0x848318));
    EVENT_SYM(renderEffectsEvent, void, (), _Z13RenderEffectsv);
    EVENT_PLT(drawingEvent, void, (), BYBIT(0x675CC4, 0x849AB0));
    EVENT_PLT(drawHudEvent, void, (), BYBIT(0x6737EC, 0x845EC8));
    EVENT_PLT(drawAfterFadeEvent, void, (), BYBIT(0x673C4C, 0x846618));
    EVENT_SYM(drawRadarEvent, void, (), _ZN4CHud9DrawRadarEv);
    EVENT_PLT(drawBlipsEvent, void, (float), BYBIT(0x66E910, 0x83DED0));
    EVENT_SYM(drawRadarOverlayEvent, void, (bool), _ZN6CRadar20DrawRadarGangOverlayEb);
    // drawMenuBackgroundEvent
    EVENT_SYM(initRwEvent, bool, (), _ZN5CGame20InitialiseRenderWareEv);
    EVENT_PLT_BEFORE(shutdownRwEvent, void, (), BYBIT(0x6756F0, 0x849148));
    EVENT_SYM(vehicleCtorEvent, CVehicle*, (CVehicle*, u8), _ZN8CVehicleC2Eh, 0);
    EVENT_SYM_BEFORE(vehicleDtorEvent, CVehicle*, (CVehicle*), _ZN8CVehicleD2Ev, 0);
    EVENT_SYM(pedCtorEvent, CPed*, (CPed*, u32), _ZN4CPedC2Ej, 0);
    EVENT_SYM_BEFORE(pedDtorEvent, CPed*, (CPed*), _ZN4CPedD2Ev, 0);
    EVENT_SYM(objectCtorEvent, void, (CObject*), _ZN7CObject4InitEv, 0);
    EVENT_SYM_BEFORE(objectDtorEvent, CObject*, (CObject*), _ZN7CObjectD2Ev, 0);
    EVENT_PLT(initPoolsEvent, void, (), BYBIT(0x672468, 0x843F18));
    EVENT_PLT(shutdownPoolsEvent, void, (), BYBIT(0x66F218, 0x83EDC0));
    EVENT_SYM_BEFORE(vehicleRenderEvent, void, (CVehicle*), _ZN8CVehicle6RenderEv, 0);
    EVENT_SYM_BEFORE(pedRenderEvent, void, (CPed*), _ZN4CPed6RenderEv, 0);
    EVENT_SYM_BEFORE(objectRenderEvent, void, (CObject*), _ZN7CObject6RenderEv, 0);
    EVENT_SYM(vehicleSetModelEvent, void, (CVehicle*, int), _ZN8CVehicle13SetModelIndexEj, 0, 1);
    EVENT_SYM(pedSetModelEvent, void, (CPed*, int), _ZN4CPed13SetModelIndexEj, 0, 1);
    // d3dResetEvent // ogl analogue
    // d3dLostEvent // do we need this?
    EVENT_SYM(gameProcessEvent, void, (), _ZN5CGame7ProcessEv);
    EVENT_PLT(initGameEvent, void, (), BYBIT(0x6740A4, 0x846D20));
    EVENT_PLT(reInitGameEvent, void, (), BYBIT(0x672014, 0x843810));
    // onPauseAllSounds
    // onResumeAllSounds
    EVENT_PLT(initScriptsEvent, void, (), BYBIT(0x671B14, 0x842FC0));
    EVENT_PLT(processScriptsEvent, void, (), BYBIT(0x673178, 0x845438)); // wrong on PC. bruh...
    EVENT_PLT(menuDrawingEvent, void, (MobileMenu*), BYBIT(0x674254, 0x846FE8));
    EVENT_SYM(attachRwPluginsEvent, bool, (), _Z12PluginAttachv);

    // Additional events (aml psdk)
    EVENT_PLT(processCameraEvent, void, (CCamera* camera), BYBIT(0x6717BC, 0x8429D8), 0);
    EVENT_PLT(initWidgetsEvent, void, (), BYBIT(0x6734E4, 0x8459D8));
    EVENT_PLT(updateWidgetsEvent, void, (), BYBIT(0x6746E4, 0x847780));
    EVENT_SYM(initGameStage1Event, bool, (const char*), _ZN5CGame5Init1EPKc);
    EVENT_SYM(initGameStage2Event, bool, (const char*), _ZN5CGame5Init2EPKc);
    EVENT_SYM(initGameStage3Event, bool, (const char*), _ZN5CGame5Init3EPKc);
    EVENT_SYM(menuUpdateEvent, void, (void*), _ZN10MobileMenu6UpdateEv);
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
};

#endif // __AML_PSDK_SACALLEVENTS_H
