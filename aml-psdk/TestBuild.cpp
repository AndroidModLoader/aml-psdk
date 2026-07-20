#include <mod/amlmod.h>
#include <mod/logger.h>
#include <mod/config.h>

MYMOD(net.psdk.mymod.guid, AML PSDK Template, 1.0, Author)

// Just a list of all includes to see if they're getting compiled without errors and warnings

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/renderware/RwBase.h>
#include <aml-psdk/renderware/RwVector.h>

#include <aml-psdk/renderware/RpAtomic.h>
#include <aml-psdk/renderware/RpGeometry.h>
#include <aml-psdk/renderware/RpClump.h>
#include <aml-psdk/renderware/RwFrame.h>
#include <aml-psdk/renderware/RwResource.h>
#include <aml-psdk/renderware/RxPipeline.h>
#include <aml-psdk/renderware/RpMesh.h>
#include <aml-psdk/renderware/RpLight.h>
#include <aml-psdk/renderware/RwCamera.h>
#include <aml-psdk/renderware/RpWorld.h>
#include <aml-psdk/renderware/RpMaterial.h>
#include <aml-psdk/renderware/RwObject.h>
#include <aml-psdk/renderware/RwStream.h>
#include <aml-psdk/renderware/RwMatrix.h>
#include <aml-psdk/renderware/RwRender.h>

#include <aml-psdk/game_sa/base/Timer.h>
#include <aml-psdk/game_sa/entity/PlayerPed.h>
#include <aml-psdk/game_sa/entity/Automobile.h>
#include <aml-psdk/game_sa/engine/RunningScript.h>
#include <aml-psdk/game_sa/audio/AudioEngine.h>
#include <aml-psdk/game_sa/engine/Draw.h>
#include <aml-psdk/game_sa/engine/FileMgr.h>
#include <aml-psdk/game_sa/engine/Game.h>
#include <aml-psdk/game_sa/engine/GameLogic.h>
#include <aml-psdk/game_sa/other/PlayerData.h>
#include <aml-psdk/game_sa/ai/PedIntelligence.h>
#include <aml-psdk/game_sa/ai/tasks/Task.h>
#include <aml-psdk/game_sa/entity/Camera.h>
#include <aml-psdk/game_sa/engine/Sprite2d.h>
#include <aml-psdk/game_sa/engine/Sprite.h>
#include <aml-psdk/game_sa/other/Stats.h>
#include <aml-psdk/game_sa/engine/Text.h>
#include <aml-psdk/game_sa/engine/Font.h>
#include <aml-psdk/game_sa/engine/PathFind.h>
#include <aml-psdk/gta_base/DrawVertices.h>
#include <aml-psdk/game_sa/engine/MobileMenu.h>
#include <aml-psdk/game_sa/engine/VehicleModelInfo.h>
#include <aml-psdk/game_sa/other/Weather.h>
#include <aml-psdk/game_sa/other/Clock.h>
#include <aml-psdk/game_sa/other/Pools.h>
#include <aml-psdk/game_sa/Events.h>
#include <aml-psdk/game_sa/extdata/PedExtender.h>
#include <aml-psdk/game_sa/extdata/ObjectExtender.h>
#include <aml-psdk/game_sa/extdata/VehicleExtender.h>
#include <aml-psdk/game_sa/other/WeaponInfo.h>
#include <aml-psdk/game_sa/other/HandlingData.h>
#include <aml-psdk/game_sa/engine/Fx.h>
#include <aml-psdk/game_sa/engine/FxSystem.h>
#include <aml-psdk/game_sa/engine/FxManager.h>
#include <aml-psdk/game_sa/other/Coronas.h>
#include <aml-psdk/game_sa/extdata/CoronasExtender.h>
#include <aml-psdk/game_sa/engine/PointLights.h>
#include <aml-psdk/game_sa/engine/Shadows.h>
#include <aml-psdk/game_sa/other/CutsceneMgr.h>
#include <aml-psdk/game_sa/utils/OpcodeCaller.h>
#include <aml-psdk/renderware/RwTexture.h>
#include <aml-psdk/renderware/RwRaster.h>
#include <aml-psdk/renderware/RwImage.h>
#include <aml-psdk/game_sa/other/TextureDatabase.h>
#include <aml-psdk/game_sa/engine/OS.h>
#include <aml-psdk/game_sa/utils/ThreadSyncer.h>
#include <aml-psdk/game_sa/engine/TxdStore.h>
#include <aml-psdk/game_sa/engine/Hud.h>
#include <aml-psdk/game_sa/engine/Radar.h>
#include <aml-psdk/game_sa/other/CutsceneMgr.h>
#include <aml-psdk/game_sa/events/EventEditableResponse.h>
#include <aml-psdk/game_sa/engine/Fire.h>
#include <aml-psdk/game_sa/other/GangWars.h>
#include <aml-psdk/game_sa/engine/Garages.h>
#include <aml-psdk/game_sa/engine/HID.h>
#include <aml-psdk/game_sa/engine/LoadingScreen.h>
#include <aml-psdk/game_sa/base/MemoryMgr.h>
#include <aml-psdk/game_sa/engine/Messages.h>
#include <aml-psdk/game_sa/engine/Pad.h>
#include <aml-psdk/game_sa/engine/Streaming.h>
#include <aml-psdk/game_sa/engine/VisibilityPlugins.h>

DECL_HOOKv(CCamera__Process, CCamera* self)
{
    CCamera__Process(self);
    logger->Info("Camera! :o");
}

void Test()
{
    AudioEngine.m_pWeaponAudio = 0;

    // Yes, it's not "new" and "delete" but i want to allow usage of virtual funcs. It's faster and way shorter code!
    CTask* newTask = CTask::Instantiate();
    CLASS_CONSTRUCT(CTask, newTask);
    CLASS_DECONSTRUCT(CTask, newTask); // alternatively newTask->MyDestructor() from SimpleVTable or thing below (if we have it)
    //newTask->DeInstantiate();

    // GET_THISCALL_ADDR only works with declared funcs
    // HOOK(CCamera__Process, GetMainLibrarySymbol("_ZN7CCamera7ProcessEv") );
    HOOK(CCamera__Process, GET_THISCALL_ADDR(CCamera, Process) ); // <- this definitely looks better than above :p

    TheText.Get("do we compile?");

    RwIm2DVertex vert2d;
    RwIm3DVertex vert3d;

    float cx, cy, cz;
    Command<Commands::CAMERA_SET_VECTOR_MOVE>(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 100, true);
    Command<0x0936>(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 100, true); // CAMERA_SET_VECTOR_MOVE
    Command<Commands::GET_ACTIVE_CAMERA_POINT_AT>(&cx, &cy, &cz);
    Command<0x0000>(); // NOP

    Events::touchScreenEvent += [](int actionType, int trackNum, int x, int y)
    {
        ThreadSyncer::PushToMain
        (
            [=]()
            {
                char str[256];
                snprintf(str, sizeof(str), "actionType=%d trackNum=%d x=%d y=%d", actionType, trackNum, x, y);
                OS_DebugOut(str);
            }
        );
    };
}
