#ifndef __AML_PSDK_SATHESCRIPTS_H
#define __AML_PSDK_SATHESCRIPTS_H

#include "../plugin.h"
#include "RunningScript.h"
#include "StreamedScripts.h"
#include "ScriptResourceManager.h"
#include "MissionCleanup.h"

struct CVehicle;

DECL_CLASS(CTheScripts)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(Init, _ZN11CTheScripts4InitEv, void);
    DECL_FASTCALL_SIMPLE(Process, _ZN11CTheScripts7ProcessEv, void);
    DECL_FASTCALL_SIMPLE(StartNewScript, _ZN11CTheScripts14StartNewScriptEPh, CRunningScript*, u8* startIp);
    DECL_FASTCALL_SIMPLE(StartNewScript2, _ZN11CTheScripts14StartNewScriptEPht, CRunningScript*, u8* startIp, u16 scriptIndex);
    DECL_FASTCALL_SIMPLE(IsPlayerOnAMission, _ZN11CTheScripts18IsPlayerOnAMissionEv, u8);
    DECL_FASTCALL_SIMPLE(IsVehicleStopped, _ZN11CTheScripts16IsVehicleStoppedEP8CVehicle, u8, CVehicle* vehicle);
    DECL_FASTCALL_SIMPLE(CleanUpThisVehicle, _ZN11CTheScripts18CleanUpThisVehicleEP8CVehicle, void, CVehicle* vehicle);
    DECL_FASTCALL_SIMPLE(RemoveScriptTextureDictionary, _ZN11CTheScripts29RemoveScriptTextureDictionaryEv, void);
    DECL_FASTCALL_SIMPLE(GetActualScriptThingIndex, _ZN11CTheScripts25GetActualScriptThingIndexEih, i32, i32 index, u8 type);

    // STATIC values
    DECL_OBJECT_ARRAY_PLT(CRunningScript, ScriptsArray, BYBIT(0x679658, 0x850CC0));
    DECL_OBJECT_PLT(CRunningScript*, pActiveScripts, BYBIT(0x679D14, 0x851A40));
    DECL_OBJECT_PLT(CRunningScript*, pIdleScripts, BYBIT(0x679B34, 0x851688));
    DECL_OBJECT_ARRAY_PLT(u8, ScriptSpace, BYBIT(0x676040, 0x84A0F0));
    DECL_OBJECT_ARRAY_PLT(i32, LocalVariablesForCurrentMission, BYBIT(0x676BE4, 0x84B810));
    DECL_OBJECT_PLT(CMissionCleanup, MissionCleanUp, BYBIT(0x677318, 0x84C668));
    DECL_OBJECT_PLT(CScriptResourceManager, ScriptResourceManager, BYBIT(0x677EB0, 0x84DD80));
    DECL_OBJECT_PLT(CStreamedScripts, StreamedScripts, BYBIT(0x6761B8, 0x84A3D0));
DECL_CLASS_END()

#define ScriptsArray ScriptsArray()
#define pActiveScripts pActiveScripts()
#define pIdleScripts pIdleScripts()
#define ScriptSpace ScriptSpace()
#define LocalVariablesForCurrentMission LocalVariablesForCurrentMission()
#define MissionCleanUp MissionCleanUp()
#define ScriptResourceManager ScriptResourceManager()
#define StreamedScripts StreamedScripts()

#endif // __AML_PSDK_SATHESCRIPTS_H
