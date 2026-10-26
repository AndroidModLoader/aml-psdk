#ifndef __AML_PSDK_VCSTREAMING_H
#define __AML_PSDK_VCSTREAMING_H

#include <aml-psdk/game_vc/plugin.h>
#include <aml-psdk/gta_base/Vector.h>

DECL_CLASS(CStreaming)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(RequestModel, _ZN10CStreaming12RequestModelEii, void, i32 modelId, i32 flags);
    DECL_FASTCALL_SIMPLE(LoadAllRequestedModels, _ZN10CStreaming22LoadAllRequestedModelsEb, void, bool onlyPriority);
    DECL_FASTCALL_SIMPLE(RemoveModel, _ZN10CStreaming11RemoveModelEi, void, i32 modelId);
    DECL_FASTCALL_SIMPLE(SetModelIsDeletable, _ZN10CStreaming19SetModelIsDeletableEi, void, i32 modelId);
    DECL_FASTCALL_SIMPLE(SetMissionDoesntRequireModel, _ZN10CStreaming28SetMissionDoesntRequireModelEi, void, i32 modelId);
    DECL_FASTCALL_SIMPLE(RequestSpecialModel, _ZN10CStreaming19RequestSpecialModelEiPKci, void, i32 modelId, const char* name, i32 flags);
    DECL_FASTCALL_SIMPLE(RequestSpecialChar, _ZN10CStreaming18RequestSpecialCharEiPKci, void, i32 slot, const char* name, i32 flags);
    DECL_FASTCALL_SIMPLE(HasSpecialCharLoaded, _ZN10CStreaming20HasSpecialCharLoadedEi, bool, i32 slot);
    DECL_FASTCALL_SIMPLE(SetSpecialCharIsDeletable, _ZN10CStreaming25SetSpecialCharIsDeletableEi, void, i32 slot);
    DECL_FASTCALL_SIMPLE(SetMissionDoesntRequireSpecialChar, _ZN10CStreaming34SetMissionDoesntRequireSpecialCharEi, void, i32 slot);
    DECL_FASTCALL_SIMPLE(IsObjectInCdImage, _ZN10CStreaming17IsObjectInCdImageEi, bool, i32 modelId);
    DECL_FASTCALL_SIMPLE(AreAnimsUsedByRequestedModels, _ZN10CStreaming29AreAnimsUsedByRequestedModelsEi, bool, i32 animId);
    DECL_FASTCALL_SIMPLE(LoadScene, _ZN10CStreaming9LoadSceneERK7CVector, void, const CVector& position);
    DECL_FASTCALL_SIMPLE(LoadSceneCollision, _ZN10CStreaming18LoadSceneCollisionERK7CVector, void, const CVector& position);
    DECL_FASTCALL_SIMPLE(InstanceLoadedModels, _ZN10CStreaming20InstanceLoadedModelsERK7CVector, void, const CVector& position);
    DECL_FASTCALL_SIMPLE(FlushRequestList, _ZN10CStreaming16FlushRequestListEv, void);
    DECL_FASTCALL_SIMPLE(FlushChannels, _ZN10CStreaming13FlushChannelsEv, void);
    DECL_FASTCALL_SIMPLE(LoadRequestedModels, _ZN10CStreaming19LoadRequestedModelsEv, void);
    DECL_FASTCALL_SIMPLE(RemoveAllUnusedModels, _ZN10CStreaming21RemoveAllUnusedModelsEv, void);
    DECL_FASTCALL_SIMPLE(RemoveLeastUsedModel, _ZN10CStreaming20RemoveLeastUsedModelEj, bool, u32 flags);
    DECL_FASTCALL_SIMPLE(RemoveLoadedVehicle, _ZN10CStreaming19RemoveLoadedVehicleEv, bool);
    DECL_FASTCALL_SIMPLE(GetAvailableVehicleSlot, _ZN10CStreaming23GetAvailableVehicleSlotEv, i32);
    DECL_FASTCALL_SIMPLE(MakeSpaceFor, _ZN10CStreaming12MakeSpaceForEi, void, i32 bytes);
    DECL_FASTCALL_SIMPLE(Update, _ZN10CStreaming6UpdateEv, void);
    DECL_FASTCALL_SIMPLE(LoadZoneVehicle, _ZN10CStreaming15LoadZoneVehicleERK7CVector, void, const CVector& position);
    DECL_FASTCALL_SIMPLE(RequestAllModels, _ZN10CStreaming16RequestAllModelsEv, void);

    // STATIC values
    DECL_VALUE_PLT_BOOL(ms_disableStreaming, BYBIT(0x394980, 0x5773E8));
    DECL_VALUE_PLT_U32(ms_memoryUsed, BYBIT(0x39598C, 0x579358));
    DECL_VALUE_PLT_U32(ms_memoryAvailable, BYBIT(0x395440, 0x5788D8));
    DECL_VALUE_PLT_I32(ms_numModelsRequested, BYBIT(0x395FE0, 0x579FD8));
    DECL_VALUE_PLT_I32(ms_numPriorityRequests, BYBIT(0x3950D8, 0x578208));
    DECL_VALUE_PLT_I32(ms_numVehiclesLoaded, BYBIT(0x394F20, 0x577EB8));
    DECL_VALUE_PLT_I32(ms_numPedsLoaded, BYBIT(0x396C30, 0x57B870));
    DECL_VALUE_PLT_BOOL(ms_bLoadingBigModel, BYBIT(0x3966D8, 0x57ADB8));
DECL_CLASS_END()

#define ms_disableStreaming ms_disableStreaming()
#define ms_memoryUsed ms_memoryUsed()
#define ms_memoryAvailable ms_memoryAvailable()
#define ms_numModelsRequested ms_numModelsRequested()
#define ms_numPriorityRequests ms_numPriorityRequests()
#define ms_numVehiclesLoaded ms_numVehiclesLoaded()
#define ms_numPedsLoaded ms_numPedsLoaded()
#define ms_bLoadingBigModel ms_bLoadingBigModel()

#endif // __AML_PSDK_VCSTREAMING_H
