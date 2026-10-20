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
#include <aml-psdk/game_sa/entity/Boat.h>
#include <aml-psdk/game_sa/entity/Train.h>
#include <aml-psdk/game_sa/entity/Pickup.h>
#include <aml-psdk/game_sa/entity/Object.h>
#include <aml-psdk/game_sa/other/Widgets.h>
#include <aml-psdk/game_sa/engine/RunningScript.h>
#include <aml-psdk/game_sa/engine/StreamedScripts.h>
#include <aml-psdk/game_sa/engine/ScriptResourceManager.h>
#include <aml-psdk/game_sa/engine/MissionCleanup.h>
#include <aml-psdk/game_sa/engine/TheScripts.h>
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
#include <aml-psdk/game_sa/utils/PoolUtils.h>
#include <aml-psdk/game_sa/utils/StreamingUtils.h>
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

#include <aml-psdk/game_sa/base/General.h>
#include <aml-psdk/game_sa/base/KeyGen.h>
#include <aml-psdk/game_sa/other/Restart.h>
#include <aml-psdk/game_sa/other/Explosion.h>
#include <aml-psdk/game_sa/other/WaterLevel.h>
#include <aml-psdk/game_sa/other/TimeCycle.h>
#include <aml-psdk/game_sa/other/Cheat.h>
#include <aml-psdk/game_sa/engine/TrafficLights.h>
#include <aml-psdk/game_sa/engine/Checkpoints.h>
#include <aml-psdk/game_sa/engine/SetPieces.h>
#include <aml-psdk/game_sa/engine/RoadBlocks.h>
#include <aml-psdk/game_sa/engine/Remote.h>
#include <aml-psdk/game_sa/engine/Cranes.h>
#include <aml-psdk/game_sa/other/GridRef.h>
#include <aml-psdk/game_sa/engine/Bridge.h>
#include <aml-psdk/game_sa/other/Birds.h>
#include <aml-psdk/game_sa/other/Gangs.h>
#include <aml-psdk/game_sa/engine/TagManager.h>
#include <aml-psdk/game_sa/other/Localisation.h>
#include <aml-psdk/game_sa/other/CullZones.h>
#include <aml-psdk/game_sa/engine/VehicleRecording.h>
#include <aml-psdk/game_sa/engine/IplStore.h>
#include <aml-psdk/game_sa/engine/QuadTree.h>
#include <aml-psdk/game_sa/engine/ColStore.h>
#include <aml-psdk/game_sa/engine/ColAccel.h>
#include <aml-psdk/game_sa/engine/CarAI.h>
#include <aml-psdk/game_sa/engine/Renderer.h>
#include <aml-psdk/game_sa/other/LoadedCarGroup.h>
#include <aml-psdk/game_sa/other/Population.h>
#include <aml-psdk/game_sa/other/PopCycle.h>
#include <aml-psdk/game_sa/engine/CarCtrl.h>
#include <aml-psdk/game_sa/engine/CarGenerators.h>
#include <aml-psdk/game_sa/other/Pickups.h>
#include <aml-psdk/game_sa/engine/EntryExit.h>
#include <aml-psdk/game_sa/engine/Zones.h>
#include <aml-psdk/game_sa/engine/OnscreenTimer.h>
#include <aml-psdk/game_sa/engine/ObjectData.h>
#include <aml-psdk/game_sa/other/Clothes.h>
#include <aml-psdk/game_sa/other/WeaponEffects.h>
#include <aml-psdk/game_sa/other/MotionBlurStreaks.h>
#include <aml-psdk/game_sa/other/ShinyTexts.h>
#include <aml-psdk/game_sa/other/BrightLights.h>
#include <aml-psdk/game_sa/enum/LevelName.h>
#include <aml-psdk/game_sa/enum/AnimGroup.h>

#include <aml-psdk/game_sa/anim/AnimBlendAssocGroup.h>
#include <aml-psdk/game_sa/anim/AnimBlock.h>
#include <aml-psdk/game_sa/anim/AnimBlendSequence.h>
#include <aml-psdk/game_sa/anim/AnimBlendHierarchy.h>
#include <aml-psdk/game_sa/anim/AnimBlendNode.h>
#include <aml-psdk/game_sa/anim/AnimBlendStaticAssociation.h>
#include <aml-psdk/game_sa/anim/AnimBlendAssociation.h>
#include <aml-psdk/game_sa/anim/AnimBlendClumpData.h>
#include <aml-psdk/game_sa/base/References.h>
#include <aml-psdk/game_sa/other/BulletInfo.h>
#include <aml-psdk/game_sa/other/ShotInfo.h>
#include <aml-psdk/game_sa/other/ProjectileInfo.h>
#include <aml-psdk/game_sa/entity/Projectile.h>
#include <aml-psdk/game_sa/utils/TextureUtils.h>
#include <aml-psdk/game_sa/utils/RenderWareUtils.h>

#include <aml-psdk/renderware/RpUVAnim.h>
#include <aml-psdk/renderware/RpSkin.h>
#include <aml-psdk/game_sa/anim/AnimManager.h>
#include <aml-psdk/game_sa/ai/tasks/TaskTypes.h>
#include <aml-psdk/game_sa/events/EventTypes.h>
#include <aml-psdk/game_sa/ai/PedGroup.h>
#include <aml-psdk/game_sa/ai/DecisionMaker.h>
#include <aml-psdk/game_sa/other/Wanted.h>

#include <aml-psdk/game_sa/engine/Collision.h>
#include <aml-psdk/game_sa/engine/Escalators.h>
#include <aml-psdk/game_sa/engine/Furniture.h>
#include <aml-psdk/game_sa/engine/Interior.h>
#include <aml-psdk/game_sa/engine/PedAttractor.h>
#include <aml-psdk/game_sa/engine/Ropes.h>
#include <aml-psdk/game_sa/engine/StuntJump.h>
#include <aml-psdk/game_sa/engine/SurfaceInfos.h>
#include <aml-psdk/game_sa/engine/VehicleAnimGroup.h>
#include <aml-psdk/game_sa/enum/Audio.h>
#include <aml-psdk/game_sa/enum/AudioBanks.h>
#include <aml-psdk/game_sa/enum/AudioEvents.h>
#include <aml-psdk/game_sa/enum/Collision.h>
#include <aml-psdk/game_sa/enum/Effects.h>
#include <aml-psdk/game_sa/enum/EventPriority.h>
#include <aml-psdk/game_sa/enum/Interior.h>
#include <aml-psdk/game_sa/enum/SpeechContexts.h>
#include <aml-psdk/game_sa/enum/TaskEnums.h>
#include <aml-psdk/game_sa/other/BulletTraces.h>
#include <aml-psdk/game_sa/other/Glass.h>
#include <aml-psdk/game_sa/other/Occlusion.h>
#include <aml-psdk/game_sa/other/RealTimeShadowManager.h>
#include <aml-psdk/game_sa/other/Skidmarks.h>
#include <aml-psdk/game_sa/other/SpecialFX.h>
#include <aml-psdk/game_sa/utils/WorldUtils.h>
#include <aml-psdk/renderware/RpMatFX.h>

#include <aml-psdk/game_sa/ai/IKChain.h>
#include <aml-psdk/game_sa/ai/PedGroups.h>
#include <aml-psdk/game_sa/ai/PedStats.h>
#include <aml-psdk/game_sa/ai/PedType.h>
#include <aml-psdk/game_sa/audio/AEAudioChannel.h>
#include <aml-psdk/game_sa/audio/AEAudioHardware.h>
#include <aml-psdk/game_sa/audio/AEAudioUtility.h>
#include <aml-psdk/game_sa/audio/AEDataStream.h>
#include <aml-psdk/game_sa/audio/AESoundManager.h>
#include <aml-psdk/game_sa/audio/AEStreamThread.h>
#include <aml-psdk/game_sa/engine/FileLoader.h>
#include <aml-psdk/game_sa/engine/GenericGameStorage.h>
#include <aml-psdk/game_sa/engine/Markers.h>
#include <aml-psdk/game_sa/engine/PostEffects.h>
#include <aml-psdk/game_sa/engine/WaterCannons.h>
#include <aml-psdk/game_sa/other/CustomCarPlate.h>
#include <aml-psdk/game_sa/other/CustomRoadsign.h>
#include <aml-psdk/game_sa/other/Shopping.h>

#include <aml-psdk/game_sa/ai/Formation.h>
#include <aml-psdk/game_sa/ai/PedPlacement.h>
#include <aml-psdk/game_sa/ai/PedGeometryAnalyser.h>
#include <aml-psdk/game_sa/engine/CarEnterExit.h>
#include <aml-psdk/game_sa/other/InterestingEvents.h>

#include <aml-psdk/game_sa/engine/FxInfo.h>
#include <aml-psdk/game_sa/engine/FxEmitter.h>
#include <aml-psdk/game_sa/entity/PedDamageResponseCalculator.h>
#include <aml-psdk/game_sa/audio/AudioZones.h>
#include <aml-psdk/game_sa/other/Darkel.h>
#include <aml-psdk/game_sa/engine/Scripted2dEffects.h>
#include <aml-psdk/game_sa/other/Clouds.h>
#include <aml-psdk/game_sa/engine/PlantMgr.h>
#include <aml-psdk/game_sa/engine/Mirrors.h>

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
