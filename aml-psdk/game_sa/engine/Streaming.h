#ifndef __AML_PSDK_SASTREAMING_H
#define __AML_PSDK_SASTREAMING_H

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/game_sa/base/Lists.h>
#include <aml-psdk/gta_base/Vector.h>

enum Status : i32
{
    STATUS_IDLE                                = 0x0,
    STATUS_LOADING                             = 0x1,
    STATUS_LOADING_LARGEFILE                   = 0x2,
    STATUS_ERROR                               = 0x3,
};

struct DirectoryInfo
{
    u32                                posn;
    u16                                size;
    u16                                realSize;
    char                               name[24];
};
CHECKSIZE(DirectoryInfo, 0x20, 0x20);  // 64-bit from the IDB; 32-bit measured from this layout

struct CDirectory
{
    DirectoryInfo*                     m_pDirInfo;
    i32                                m_size;
    i32                                m_number;
    bool                               m_bOwnBuffer;
};
CHECKSIZE(CDirectory, 0x10, 0x18);  // 64-bit from the IDB; 32-bit measured from this layout

struct CStreamingInfo
{
    i16                                m_nextIndex;
    i16                                m_prevIndex;
    i16                                m_nextModelOnCd;
    u8                                 m_flags;
    u8                                 m_image;
    u32                                m_cdPosn;
    u32                                m_cdSize;
    u8                                 m_status;
};
CHECKSIZE(CStreamingInfo, 0x14, 0x14);  // 64-bit from the IDB; 32-bit measured from this layout

struct CStreamingFile
{
    char                               m_name[40];
    bool                               m_bRegister;
    i32                                m_lsn;
};
CHECKSIZE(CStreamingFile, 0x30, 0x30);  // 64-bit from the IDB; 32-bit measured from this layout

struct CLoadedCarGroup
{
    i16                                aMembers[23];
};
CHECKSIZE(CLoadedCarGroup, 0x2E, 0x2E);  // 64-bit from the IDB; 32-bit measured from this layout

struct StreamChannel
{
    i32                                currentLoading[16];
    i32                                bufferOffset[16];
    Status                             status;
    i32                                loadTime;
    i32                                loadStart;
    i32                                loadSize;
    i32                                attempts;
    i32                                error;
};
CHECKSIZE(StreamChannel, 0x98, 0x98);  // 64-bit from the IDB; 32-bit measured from this layout

struct CEntity;
struct CPtrList;
struct CVector;

DECL_CLASS(CStreaming)
    // Functions
    DECL_FASTCALL_SIMPLE(GetModelCDName, _ZN10CStreaming14GetModelCDNameEi, const char*, i32 index);
    DECL_FASTCALL_SIMPLE(IsInitialised, _ZN10CStreaming13IsInitialisedEv, bool);
    DECL_FASTCALL_SIMPLE(InitImageList, _ZN10CStreaming13InitImageListEv, void);
    DECL_FASTCALL_SIMPLE(AddImageToList, _ZN10CStreaming14AddImageToListEPKcb, i32, const char* pImageName, bool bRegisterFiles);
    DECL_FASTCALL_SIMPLE(Shutdown, _ZN10CStreaming8ShutdownEv, void);
    DECL_FASTCALL_SIMPLE(ReInit, _ZN10CStreaming6ReInitEv, void);
    DECL_FASTCALL_SIMPLE(FlushRequestList, _ZN10CStreaming16FlushRequestListEv, void);
    DECL_FASTCALL_SIMPLE(DeleteAllRwObjects, _ZN10CStreaming18DeleteAllRwObjectsEv, void);
    DECL_FASTCALL_SIMPLE(RemoveAllUnusedModels, _ZN10CStreaming21RemoveAllUnusedModelsEv, void);
    DECL_FASTCALL_SIMPLE(SetMissionDoesntRequireModel, _ZN10CStreaming28SetMissionDoesntRequireModelEi, void, i32 index);
    DECL_FASTCALL_SIMPLE(RemoveModel, _ZN10CStreaming11RemoveModelEi, void, i32 index);
    DECL_FASTCALL_SIMPLE(UpdateMemoryUsed, _ZN10CStreaming16UpdateMemoryUsedEv, void);
    DECL_FASTCALL_SIMPLE(Update, _ZN10CStreaming6UpdateEv, void);
    DECL_FASTCALL_SIMPLE(AddModelsToRequestList, _ZN10CStreaming22AddModelsToRequestListERK7CVectorj, void, const CVector* posn, u32 reqFlag);
    DECL_FASTCALL_SIMPLE(AddLodsToRequestList, _ZN10CStreaming20AddLodsToRequestListERK7CVectorj, void, const CVector* posn, u32 reqFlag);
    DECL_FASTCALL_SIMPLE(StreamVehiclesAndPeds_Always, _ZN10CStreaming28StreamVehiclesAndPeds_AlwaysERK7CVector, void, const CVector* posn);
    DECL_FASTCALL_SIMPLE(IsVeryBusy, _ZN10CStreaming10IsVeryBusyEv, bool);
    DECL_FASTCALL_SIMPLE(StreamVehiclesAndPeds, _ZN10CStreaming21StreamVehiclesAndPedsEv, void);
    DECL_FASTCALL_SIMPLE(StreamZoneModels, _ZN10CStreaming16StreamZoneModelsERK7CVector, void, const CVector* posn);
    DECL_FASTCALL_SIMPLE(LoadRequestedModels, _ZN10CStreaming19LoadRequestedModelsEv, void);
    DECL_FASTCALL_SIMPLE(PurgeRequestList, _ZN10CStreaming16PurgeRequestListEv, void);
    DECL_FASTCALL_SIMPLE(UpdateForAnimViewer, _ZN10CStreaming19UpdateForAnimViewerEv, void);
    DECL_FASTCALL_SIMPLE(RetryLoadFile, _ZN10CStreaming13RetryLoadFileEi, void, i32 ch);
    DECL_FASTCALL_SIMPLE(ProcessLoadingChannel, _ZN10CStreaming21ProcessLoadingChannelEi, bool, i32 ch);
    DECL_FASTCALL_SIMPLE(GetDiscInDrive, _ZN10CStreaming14GetDiscInDriveEv, i32);
    DECL_FASTCALL_SIMPLE(ProcessEntitiesInSectorList, _ZN10CStreaming27ProcessEntitiesInSectorListER8CPtrListj, void, CPtrList* list, u32 reqFlag);
    DECL_FASTCALL_SIMPLE(ProcessEntitiesInSectorList1, _ZN10CStreaming27ProcessEntitiesInSectorListER8CPtrListfffffffj, void, CPtrList* list, float CenterX, float CenterY, float MinX, float MinY, float MaxX, float MaxY, float radius, u32 reqFlag);
    DECL_FASTCALL_SIMPLE(RequestModel, _ZN10CStreaming12RequestModelEii, void, i32 index, i32 flags);
    DECL_FASTCALL_SIMPLE(InstanceLoadedModels, _ZN10CStreaming20InstanceLoadedModelsERK7CVector, void, const CVector* posn);
    DECL_FASTCALL_SIMPLE(InstanceLoadedModelsInSectorList, _ZN10CStreaming32InstanceLoadedModelsInSectorListER8CPtrList, void, CPtrList* list);
    DECL_FASTCALL_SIMPLE(IsObjectInCdImage, _ZN10CStreaming17IsObjectInCdImageEi, bool, i32 index);
    DECL_FASTCALL_SIMPLE(RemoveCarModel, _ZN10CStreaming14RemoveCarModelEi, void, i32 modelId);
    DECL_FASTCALL_SIMPLE(RequestVehicleUpgrade, _ZN10CStreaming21RequestVehicleUpgradeEii, void, i32 modelId, i32 flags);
    DECL_FASTCALL_SIMPLE(HasVehicleUpgradeLoaded, _ZN10CStreaming23HasVehicleUpgradeLoadedEi, bool, i32 modelId);
    DECL_FASTCALL_SIMPLE(ConvertBufferToObject, _ZN10CStreaming21ConvertBufferToObjectEPcii, bool, char* pBuffer, i32 index, i32 ch);
    DECL_FASTCALL_SIMPLE(AddToLoadedVehiclesList, _ZN10CStreaming23AddToLoadedVehiclesListEi, bool, i32 MI);
    DECL_FASTCALL_SIMPLE(AreAnimsUsedByRequestedModels, _ZN10CStreaming29AreAnimsUsedByRequestedModelsEi, bool, i32 index);
    DECL_FASTCALL_SIMPLE(FinishLoadingLargeFile, _ZN10CStreaming22FinishLoadingLargeFileEPci, bool, char* pBuffer, i32 index);
    DECL_FASTCALL_SIMPLE(RemoveLoadedVehicle, _ZN10CStreaming19RemoveLoadedVehicleEv, bool);
    DECL_FASTCALL_SIMPLE(MakeSpaceFor, _ZN10CStreaming12MakeSpaceForEi, void, i32 bytes);
    DECL_FASTCALL_SIMPLE(GetNextFileOnCd, _ZN10CStreaming15GetNextFileOnCdEib, i32, i32 cdPosn, bool bUsePriority);
    DECL_FASTCALL_SIMPLE(GetCdImageOffset, _ZN10CStreaming16GetCdImageOffsetEi, i32, i32 cdPosn);
    DECL_FASTCALL_SIMPLE(ForceLayerToRead, _ZN10CStreaming16ForceLayerToReadEi, void, i32 layer);
    DECL_FASTCALL_SIMPLE(RequestModelStream, _ZN10CStreaming18RequestModelStreamEi, void, i32 ch);
    DECL_FASTCALL_SIMPLE(LoadAllRequestedModels, _ZN10CStreaming22LoadAllRequestedModelsEb, void, bool bPriorityRequestsOnly);
    DECL_FASTCALL_SIMPLE(FlushChannels, _ZN10CStreaming13FlushChannelsEv, void);
    DECL_FASTCALL_SIMPLE(SetLoadVehiclesInLoadScene, _ZN10CStreaming26SetLoadVehiclesInLoadSceneEb, void, bool bLoad);
    DECL_FASTCALL_SIMPLE(RequestFilesInChannel, _ZN10CStreaming21RequestFilesInChannelEi, void, i32 ch);
    DECL_FASTCALL_SIMPLE(LoadScene, _ZN10CStreaming9LoadSceneERK7CVector, void, const CVector* posn);
    DECL_FASTCALL_SIMPLE(RequestBigBuildings, _ZN10CStreaming19RequestBigBuildingsERK7CVector, void, const CVector* posn);
    DECL_FASTCALL_SIMPLE(LoadZoneVehicle, _ZN10CStreaming15LoadZoneVehicleERK7CVector, void, const CVector* posn);
    DECL_FASTCALL_SIMPLE(StreamCopModels, _ZN10CStreaming15StreamCopModelsEi, void, i32 level);
    DECL_FASTCALL_SIMPLE(ClearFlagForAll, _ZN10CStreaming15ClearFlagForAllEj, void, u32 flag);
    DECL_FASTCALL_SIMPLE(LoadSceneCollision, _ZN10CStreaming18LoadSceneCollisionERK7CVector, void, const CVector* posn);
    DECL_FASTCALL_SIMPLE(DeleteFarAwayRwObjects, _ZN10CStreaming22DeleteFarAwayRwObjectsERK7CVector, void, const CVector* posn);
    DECL_FASTCALL_SIMPLE(DeleteRwObjectsInSectorList, _ZN10CStreaming27DeleteRwObjectsInSectorListER8CPtrListii, void, CPtrList* list, i32 x, i32 y);
    DECL_FASTCALL_SIMPLE(DeleteRwObjectsAfterDeath, _ZN10CStreaming25DeleteRwObjectsAfterDeathERK7CVector, void, const CVector* posn);
    DECL_FASTCALL_SIMPLE(RemoveBigBuildings, _ZN10CStreaming18RemoveBigBuildingsEv, void);
    DECL_FASTCALL_SIMPLE(RemoveBuildingsNotInArea, _ZN10CStreaming24RemoveBuildingsNotInAreaEi, void, i32 area);
    DECL_FASTCALL_SIMPLE(RequestAllModels, _ZN10CStreaming16RequestAllModelsEv, void);
    DECL_FASTCALL_SIMPLE(RemoveUnusedModelsInLoadedList, _ZN10CStreaming30RemoveUnusedModelsInLoadedListEv, void);
    DECL_FASTCALL_SIMPLE(RemoveLeastUsedModel, _ZN10CStreaming20RemoveLeastUsedModelEj, bool, u32 ignoreFlags);
    DECL_FASTCALL_SIMPLE(RemoveLoadedZoneModel, _ZN10CStreaming21RemoveLoadedZoneModelEv, bool);
    DECL_FASTCALL_SIMPLE(DeleteLeastUsedEntityRwObject, _ZN10CStreaming29DeleteLeastUsedEntityRwObjectEbj, bool, bool bVisibleOnly, u32 ignoreFlags);
    DECL_FASTCALL_SIMPLE(DeleteRwObjectsBehindCamera, _ZN10CStreaming27DeleteRwObjectsBehindCameraEi, void, i32 memory);
    DECL_FASTCALL_SIMPLE(AddEntity, _ZN10CStreaming9AddEntityEP7CEntity, CLink<CEntity *>*, CEntity* pEntity);
    DECL_FASTCALL_SIMPLE(StartRenderEntities, _ZN10CStreaming19StartRenderEntitiesEv, void);
    DECL_FASTCALL_SIMPLE(RenderEntity, _ZN10CStreaming12RenderEntityEP5CLinkIP7CEntityE, void, CLink<CEntity *>* pLink);
    DECL_FASTCALL_SIMPLE(RemoveEntity, _ZN10CStreaming12RemoveEntityEP5CLinkIP7CEntityE, void, CLink<CEntity *>* pLink);
    DECL_FASTCALL_SIMPLE(DeleteRwObjectsBehindCameraInSectorList, _ZN10CStreaming39DeleteRwObjectsBehindCameraInSectorListER8CPtrListi, bool, CPtrList* list, i32 memory);
    DECL_FASTCALL_SIMPLE(DeleteRwObjectsNotInFrustumInSectorList, _ZN10CStreaming39DeleteRwObjectsNotInFrustumInSectorListER8CPtrListi, bool, CPtrList* list, i32 memory);
    DECL_FASTCALL_SIMPLE(RemoveModelsNotVisibleFromCullzone, _ZN10CStreaming34RemoveModelsNotVisibleFromCullzoneEv, void);
    DECL_FASTCALL_SIMPLE(RemoveModelsNotVisibleFromCullzoneInSectorList, _ZN10CStreaming46RemoveModelsNotVisibleFromCullzoneInSectorListER8CPtrList, void, CPtrList* list);
    DECL_FASTCALL_SIMPLE(ImGonnaUseStreamingMemory, _ZN10CStreaming25ImGonnaUseStreamingMemoryEv, void);
    DECL_FASTCALL_SIMPLE(IHaveUsedStreamingMemory, _ZN10CStreaming24IHaveUsedStreamingMemoryEv, void);
    DECL_FASTCALL_SIMPLE(SetModelIsDeletable, _ZN10CStreaming19SetModelIsDeletableEi, void, i32 index);
    DECL_FASTCALL_SIMPLE(SetModelTxdIsDeletable, _ZN10CStreaming22SetModelTxdIsDeletableEi, void, i32 index);
    DECL_FASTCALL_SIMPLE(RequestSpecialModel, _ZN10CStreaming19RequestSpecialModelEiPKci, void, i32 index, const char* pName, i32 flags);
    DECL_FASTCALL_SIMPLE(RequestPlayerSection, _ZN10CStreaming20RequestPlayerSectionEiPKci, void, i32 index, const char* pName, i32 flags);
    DECL_FASTCALL_SIMPLE(RequestFile, _ZN10CStreaming11RequestFileEiiiii, void, i32 index, i32 posn, i32 size, i32 image, i32 flags);
    DECL_FASTCALL_SIMPLE(LoadInitialPeds, _ZN10CStreaming15LoadInitialPedsEv, void);
    DECL_FASTCALL_SIMPLE(LoadInitialWeapons, _ZN10CStreaming18LoadInitialWeaponsEv, void);
    DECL_FASTCALL_SIMPLE(GetDefaultCopModel, _ZN10CStreaming18GetDefaultCopModelEv, i32);
    DECL_FASTCALL_SIMPLE(GetDefaultCopCarModel, _ZN10CStreaming21GetDefaultCopCarModelEj, i32, u32 bNoBikes);
    DECL_FASTCALL_SIMPLE(DisableCopBikes, _ZN10CStreaming15DisableCopBikesEb, void, bool disable);
    DECL_FASTCALL_SIMPLE(GetDefaultMedicModel, _ZN10CStreaming20GetDefaultMedicModelEv, i32);
    DECL_FASTCALL_SIMPLE(GetDefaultAmbulanceModel, _ZN10CStreaming24GetDefaultAmbulanceModelEv, i32);
    DECL_FASTCALL_SIMPLE(GetDefaultFiremanModel, _ZN10CStreaming22GetDefaultFiremanModelEv, i32);
    DECL_FASTCALL_SIMPLE(GetDefaultCabDriverModel, _ZN10CStreaming24GetDefaultCabDriverModelEv, i32);
    DECL_FASTCALL_SIMPLE(GetDefaultFireEngineModel, _ZN10CStreaming25GetDefaultFireEngineModelEv, i32);
    DECL_FASTCALL_SIMPLE(StreamAmbulanceAndMedic, _ZN10CStreaming23StreamAmbulanceAndMedicEb, bool, bool bInMemory);
    DECL_FASTCALL_SIMPLE(StreamFireEngineAndFireman, _ZN10CStreaming26StreamFireEngineAndFiremanEb, bool, bool bInMemory);
    DECL_FASTCALL_SIMPLE(StreamZoneModels_Gangs, _ZN10CStreaming22StreamZoneModels_GangsERK7CVector, void, const CVector* posn);
    DECL_FASTCALL_SIMPLE(ReclassifyLoadedCars, _ZN10CStreaming20ReclassifyLoadedCarsEv, void);
    DECL_FASTCALL_SIMPLE(IsCarModelNeededInCurrentZone, _ZN10CStreaming29IsCarModelNeededInCurrentZoneEi, bool, i32 MI);
    DECL_FASTCALL_SIMPLE(RemoveCurrentZonesModels, _ZN10CStreaming24RemoveCurrentZonesModelsEv, void);
    DECL_FASTCALL_SIMPLE(RemoveInappropriatePedModels, _ZN10CStreaming28RemoveInappropriatePedModelsEv, void);
    DECL_FASTCALL_SIMPLE(RequestSpecialChar, _ZN10CStreaming18RequestSpecialCharEiPKci, void, i32 index, const char* pName, i32 flags);
    DECL_FASTCALL_SIMPLE(HasSpecialCharLoaded, _ZN10CStreaming20HasSpecialCharLoadedEi, bool, i32 index);
    DECL_FASTCALL_SIMPLE(SetSpecialCharIsDeletable, _ZN10CStreaming25SetSpecialCharIsDeletableEi, void, i32 index);
    DECL_FASTCALL_SIMPLE(SetMissionDoesntRequireSpecialChar, _ZN10CStreaming34SetMissionDoesntRequireSpecialCharEi, void, i32 index);
    DECL_FASTCALL_SIMPLE(LoadInitialVehicles, _ZN10CStreaming19LoadInitialVehiclesEv, void);
    DECL_FASTCALL_SIMPLE(StreamOneNewCar, _ZN10CStreaming15StreamOneNewCarEv, void);
    DECL_FASTCALL_SIMPLE(PlayerIsFlyingFast, _ZN10CStreaming18PlayerIsFlyingFastEv, bool);
    DECL_FASTCALL_SIMPLE(PossiblyStreamCarOutAfterCreation, _ZN10CStreaming33PossiblyStreamCarOutAfterCreationEi, void, i32 MI);
    DECL_FASTCALL_SIMPLE(WeAreTryingToPhaseVehicleOut, _ZN10CStreaming28WeAreTryingToPhaseVehicleOutEi, bool, i32 MI);
    DECL_FASTCALL_SIMPLE(ClearSlots, _ZN10CStreaming10ClearSlotsEi, void, i32 SlotsToClear);
    DECL_FASTCALL_SIMPLE(StreamPedsForInterior, _ZN10CStreaming21StreamPedsForInteriorEi, void, i32 InteriorType);
    DECL_FASTCALL_SIMPLE(FindMIPedSlotForInterior, _ZN10CStreaming24FindMIPedSlotForInteriorEi, i32, i32 Slot);
    DECL_FASTCALL_SIMPLE(StreamPedsIntoRandomSlots, _ZN10CStreaming25StreamPedsIntoRandomSlotsEPi, void, i32* pMI);
    DECL_FASTCALL_SIMPLE(RemoveDodgyPedsFromRandomSlots, _ZN10CStreaming30RemoveDodgyPedsFromRandomSlotsEv, void);
    DECL_FASTCALL_SIMPLE(CarIsCandateForRemoval, _ZN10CStreaming22CarIsCandateForRemovalEi, bool, i32 MI);
    DECL_FASTCALL_SIMPLE(GetGta3ImageIndex, _ZN10CStreaming17GetGta3ImageIndexEv, i32);
    DECL_FASTCALL_SIMPLE(Init, _ZN10CStreaming4InitEv, void);
    DECL_FASTCALL_SIMPLE(Init2, _ZN10CStreaming5Init2Ev, void);
    DECL_FASTCALL_SIMPLE(LoadCdDirectory, _ZN10CStreaming15LoadCdDirectoryEv, void);
    DECL_FASTCALL_SIMPLE(LoadCdDirectory1, _ZN10CStreaming15LoadCdDirectoryEPKci, void, const char* pDirName, i32 imgIndex);
    DECL_FASTCALL_SIMPLE(ReadIniFile, _ZN10CStreaming11ReadIniFileEv, void);
    DECL_FASTCALL_SIMPLE(Save, _ZN10CStreaming4SaveEv, bool);
    DECL_FASTCALL_SIMPLE(Load, _ZN10CStreaming4LoadEv, bool);

    // Static values
    DECL_VALUE_PLT_U32(ms_memoryAvailable, BYBIT(0x6791F4, 0x850408));
    DECL_VALUE_PLT_I32(desiredNumVehiclesLoaded, BYBIT(0x6795AC, 0x850B68));
    DECL_VALUE_PLT_BOOL(ms_disableStreaming, BYBIT(0x6767E8, 0x84B028));
    DECL_OBJECT_ARRAY_PLT(CStreamingInfo, ms_aInfoForModel, BYBIT(0x677DD8, 0x84DBD0));
    DECL_OBJECT_ARRAY_PLT(u32, ms_imageOffsets, BYBIT(0x67718C, 0x84C350));
    typedef u32 tms_imageSizes[6];
    DECL_OBJECT_ADDR(tms_imageSizes, ms_imageSizes, BYBIT(0x792B38, 0x97298C));  // no .got slot: addressed PC-relatively
    typedef u32 tms_interiorImageOffsets[2];
    DECL_OBJECT_ADDR(tms_interiorImageOffsets, ms_interiorImageOffsets, BYBIT(0x792B50, 0x9729A4));  // no .got slot: addressed PC-relatively
    DECL_VALUE_PLT_U32(ms_imageSize, BYBIT(0x676BCC, 0x84B7E0));
    DECL_VALUE_PLT_U32(ms_lastImageRead, BYBIT(0x678AE8, 0x84F5F8));
    DECL_OBJECT_PLT(CStreamingInfo*, ms_pStartLoadedList, BYBIT(0x677240, 0x84C4B8));
    DECL_OBJECT_PLT(CStreamingInfo*, ms_pEndLoadedList, BYBIT(0x678460, 0x84E8D8));
    DECL_OBJECT_PLT(CStreamingInfo*, ms_pStartRequestedList, BYBIT(0x6766CC, 0x84ADF0));
    DECL_OBJECT_PLT(CStreamingInfo*, ms_pEndRequestedList, BYBIT(0x677D0C, 0x84DA38));
    DECL_VALUE_PLT_I32(ms_numModelsRequested, BYBIT(0x676290, 0x84A580));
    DECL_VALUE_PLT_I32(ms_memoryUsed, BYBIT(0x679EB8, 0x851D80));
    DECL_VALUE_PLT_BOOL(ms_bEnableRequestListPurge, BYBIT(0x676474, 0x84A938));
    DECL_OBJECT_PLT(CLoadedCarGroup, ms_vehiclesLoaded, BYBIT(0x677E08, 0x84DC30));
    DECL_VALUE_PLT_I32(ms_currentZoneType, BYBIT(0x679E2C, 0x851C68));
    DECL_OBJECT_ARRAY_PLT(i32, ms_pedsLoaded, BYBIT(0x679D18, 0x851A48));
    DECL_OBJECT_ARRAY_PLT(i32, ms_NextPedToLoadFromGroup, BYBIT(0x676D78, 0x84BB38));
    DECL_VALUE_PLT_I32(ms_numPedsLoaded, BYBIT(0x6783F8, 0x84E808));
    DECL_VALUE_PLT_I16(ms_loadedGangs, BYBIT(0x676958, 0x84B300));
    DECL_VALUE_PLT_I16(ms_loadedGangCars, BYBIT(0x679E3C, 0x851C88));
    DECL_VALUE_PLT_I32(ms_lastCullZone, BYBIT(0x67862C, 0x84EC80));
    DECL_VALUE_PLT_I32(ms_numPriorityRequests, BYBIT(0x678E44, 0x84FCB0));
    DECL_VALUE_PLT_BOOL(m_bStreamHarvesterModelsThisFrame, BYBIT(0x67815C, 0x84E2D0));
    DECL_VALUE_PLT_BOOL(m_bHarvesterModelsRequested, BYBIT(0x678910, 0x84F240));
    DECL_VALUE_PLT_I32(ms_oldSectorX, BYBIT(0x676824, 0x84B0A0));
    DECL_VALUE_PLT_I32(ms_oldSectorY, BYBIT(0x676248, 0x84A4F0));
    DECL_VALUE_PLT_I32(ms_channelError, BYBIT(0x676CEC, 0x84BA20));
    DECL_VALUE_PLT_I32(ms_bIsInitialised, BYBIT(0x676524, 0x84AAA0));
    DECL_OBJECT_ARRAY_PLT(StreamChannel, ms_channel, BYBIT(0x678334, 0x84E680));
    DECL_VALUE_PLT_I32(ms_streamingBufferSize, BYBIT(0x679634, 0x850C78));
    DECL_OBJECT_ARRAY_PLT(char*, ms_pStreamingBuffer, BYBIT(0x676224, 0x84A4A8));
    DECL_VALUE_PLT_BOOL(ms_bLoadingBigModel, BYBIT(0x677D58, 0x84DAD0));
    DECL_OBJECT_ARRAY_PLT(CStreamingFile, ms_files, BYBIT(0x676AC4, 0x84B5D0));
    DECL_VALUE_PLT_BOOL(m_bBoatsNeeded, BYBIT(0x679670, 0x850CF0));
    DECL_OBJECT_PLT(CDirectory*, ms_pExtraObjectsDir, BYBIT(0x6770A4, 0x84C180));
    DECL_OBJECT_PLT(CLinkList<CEntity *>, ms_rwObjectInstances, BYBIT(0x67756C, 0x84CB10));
DECL_CLASS_END()

#define ms_memoryAvailable ms_memoryAvailable()
#define desiredNumVehiclesLoaded desiredNumVehiclesLoaded()
#define ms_disableStreaming ms_disableStreaming()
#define ms_aInfoForModel ms_aInfoForModel()
#define ms_imageOffsets ms_imageOffsets()
#define ms_imageSizes ms_imageSizes()
#define ms_interiorImageOffsets ms_interiorImageOffsets()
#define ms_imageSize ms_imageSize()
#define ms_lastImageRead ms_lastImageRead()
#define ms_pStartLoadedList ms_pStartLoadedList()
#define ms_pEndLoadedList ms_pEndLoadedList()
#define ms_pStartRequestedList ms_pStartRequestedList()
#define ms_pEndRequestedList ms_pEndRequestedList()
#define ms_numModelsRequested ms_numModelsRequested()
#define ms_memoryUsed ms_memoryUsed()
#define ms_bEnableRequestListPurge ms_bEnableRequestListPurge()
#define ms_vehiclesLoaded ms_vehiclesLoaded()
#define ms_currentZoneType ms_currentZoneType()
#define ms_pedsLoaded ms_pedsLoaded()
#define ms_NextPedToLoadFromGroup ms_NextPedToLoadFromGroup()
#define ms_numPedsLoaded ms_numPedsLoaded()
#define ms_loadedGangs ms_loadedGangs()
#define ms_loadedGangCars ms_loadedGangCars()
#define ms_lastCullZone ms_lastCullZone()
#define ms_numPriorityRequests ms_numPriorityRequests()
#define m_bStreamHarvesterModelsThisFrame m_bStreamHarvesterModelsThisFrame()
#define m_bHarvesterModelsRequested m_bHarvesterModelsRequested()
#define ms_oldSectorX ms_oldSectorX()
#define ms_oldSectorY ms_oldSectorY()
#define ms_channelError ms_channelError()
#define ms_bIsInitialised ms_bIsInitialised()
#define ms_channel ms_channel()
#define ms_streamingBufferSize ms_streamingBufferSize()
#define ms_pStreamingBuffer ms_pStreamingBuffer()
#define ms_bLoadingBigModel ms_bLoadingBigModel()
#define ms_files ms_files()
#define m_bBoatsNeeded m_bBoatsNeeded()
#define ms_pExtraObjectsDir ms_pExtraObjectsDir()
#define ms_rwObjectInstances ms_rwObjectInstances()

#endif // __AML_PSDK_SASTREAMING_H
