#ifndef __AML_PSDK_SAFILELOADER_H
#define __AML_PSDK_SAFILELOADER_H

#include "../plugin.h"
#include "../base/ColModel.h"
#include <aml-psdk/renderware/RwStream.h>

struct CEntity;
struct RpAtomic;
struct RpClump;
struct RwTexDictionary;

DECL_CLASS(CFileObjectInstance)
    enum
    {
        FLAG_NONE = 0,
        FLAG_LOWPRIORITY = 1,
        FLAG_FULLMATRIX = 2,
        FLAG_UNDERWATER = 4,
        FLAG_TUNNEL = 8,
        FLAG_TUNNELTRANSITION = 16,
    };

    // Member values
    float posx;
    float posy;
    float posz;
    float quatx;
    float quaty;
    float quatz;
    float quatw;
    i32 instanceIndex;
    union
    {
        i32 areaCodeAndFlags;
        struct
        {
            i32 areacode : 8;
            i32 flags : 24;
        } aaf;
    };
    i32 lodIndex;
DECL_CLASS_END()
CHECKSIZE(CFileObjectInstance, 0x28, 0x28);

DECL_CLASS(CFileCarGenerator)
    // Member values
    float m_x;
    float m_y;
    float m_z;
    float m_r;
    i32 m_modelID;
    i32 m_col1;
    i32 m_col2;
    i32 m_flagVal;
    i32 m_alarmChance;
    i32 m_lockedChance;
    i32 m_minDelay;
    i32 m_maxDelay;
DECL_CLASS_END()
CHECKSIZE(CFileCarGenerator, 0x30, 0x30);

DECL_CLASS(CIPLFileBinaryHeader)
    // Member values
    i16 iNumObjectInstance;
    i16 iNumMultiBuilding;
    i16 iNumZone;
    i16 iNumCullZone;
    i16 iNumOcclusionVolume;
    i16 iNumEntryExit;
    i16 iNumGarage;
    i16 iNumPickup;
    i16 iNumCarGenerator;
    i16 iNumStuntJump;
    i16 iNumTimeCyclesMod;
    i16 iNumPath;
    CFileObjectInstance* pObjectInstances;
    void* pMultiBuildings;
    void* pZones;
    void* pCullZones;
    void* pOcclusionVolumes;
    void* pEntryExits;
    void* pGarages;
    void* pPickups;
    CFileCarGenerator* pCarGenerators;
    void* pStuntJumps;
    void* pTimeCyclesMods;
    void* pPaths;
DECL_CLASS_END()
CHECKSIZE(CIPLFileBinaryHeader, 0x48, 0x78);

DECL_CLASS(CIPLFileBinaryHeaderSerialize)
    // Member values
    i16 iNumObjectInstance;
    i16 iNumMultiBuilding;
    i16 iNumZone;
    i16 iNumCullZone;
    i16 iNumOcclusionVolume;
    i16 iNumEntryExit;
    i16 iNumGarage;
    i16 iNumPickup;
    i16 iNumCarGenerator;
    i16 iNumStuntJump;
    i16 iNumTimeCyclesMod;
    i16 iNumPath;
    u32 pObjectInstances;
    u32 pMultiBuildings;
    u32 pZones;
    u32 pCullZones;
    u32 pOcclusionVolumes;
    u32 pEntryExits;
    u32 pGarages;
    u32 pPickups;
    u32 pCarGenerators;
    u32 pStuntJumps;
    u32 pTimeCyclesMods;
    u32 pPaths;
DECL_CLASS_END()
CHECKSIZE(CIPLFileBinaryHeaderSerialize, 0x48, 0x48);

DECL_CLASS(CFileLoader)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(LoadObjectTypes, _ZN11CFileLoader15LoadObjectTypesEPKc, void, char const* pFilename);
    DECL_FASTCALL_SIMPLE(ReloadObjectTypes, _ZN11CFileLoader17ReloadObjectTypesEPKc, void, char const* pFilename);
    DECL_FASTCALL_SIMPLE(ReloadPaths, _ZN11CFileLoader11ReloadPathsEPKc, void, char const* pFilename);
    DECL_FASTCALL_SIMPLE(LoadScene, _ZN11CFileLoader9LoadSceneEPKc, void, char const* pFilename);
    DECL_FASTCALL_SIMPLE(LoadLevel, _ZN11CFileLoader9LoadLevelEPKc, void, char const* pDatFilename);
    DECL_FASTCALL_SIMPLE(LoadAtomicFile1, _ZN11CFileLoader14LoadAtomicFileEPKc, void, char const* pFilename);
    inline static void LoadAtomicFile(char const* pFilename)
    {
        return LoadAtomicFile1(pFilename);
    }
    DECL_FASTCALL_SIMPLE(LoadAtomicFile2Return, _ZN11CFileLoader21LoadAtomicFile2ReturnEPKc, RpClump*, char const* pFilename);
    DECL_FASTCALL_SIMPLE(LoadClumpFile1, _ZN11CFileLoader13LoadClumpFileEPKc, void, char const* pFilename);
    inline static void LoadClumpFile(char const* pFilename)
    {
        return LoadClumpFile1(pFilename);
    }
    DECL_FASTCALL_SIMPLE(LoadAtomicFile2, _ZN11CFileLoader14LoadAtomicFileEP8RwStreamj, bool, RwStream* pStream, u32 index);
    inline static bool LoadAtomicFile(RwStream* pStream, u32 index)
    {
        return LoadAtomicFile2(pStream, index);
    }
    DECL_FASTCALL_SIMPLE(LoadClumpFile2, _ZN11CFileLoader13LoadClumpFileEP8RwStreamj, bool, RwStream* pStream, u32 index);
    inline static bool LoadClumpFile(RwStream* pStream, u32 index)
    {
        return LoadClumpFile2(pStream, index);
    }
    DECL_FASTCALL_SIMPLE(StartLoadClumpFile, _ZN11CFileLoader18StartLoadClumpFileEP8RwStreamj, bool, RwStream* pStream, u32 index);
    DECL_FASTCALL_SIMPLE(FinishLoadClumpFile, _ZN11CFileLoader19FinishLoadClumpFileEP8RwStreamj, bool, RwStream* pStream, u32 index);
    DECL_FASTCALL_SIMPLE(LoadTexDictionary, _ZN11CFileLoader17LoadTexDictionaryEPKc, RwTexDictionary*, char const* pFilename);
    DECL_FASTCALL_SIMPLE(AddTexDictionaries, _ZN11CFileLoader18AddTexDictionariesEP15RwTexDictionaryS1_, void, RwTexDictionary* pMasterTxd, RwTexDictionary* pTxd);
    DECL_FASTCALL_SIMPLE(LoadCollisionFile1, _ZN11CFileLoader17LoadCollisionFileEPKch, void, char const* pFilename, u8 level);
    inline static void LoadCollisionFile(char const* pFilename, u8 level)
    {
        return LoadCollisionFile1(pFilename, level);
    }
    DECL_FASTCALL_SIMPLE(LoadCollisionFile2, _ZN11CFileLoader17LoadCollisionFileEPhjh, bool, u8* pBuffer, u32 size, u8 level);
    inline static bool LoadCollisionFile(u8* pBuffer, u32 size, u8 level)
    {
        return LoadCollisionFile2(pBuffer, size, level);
    }
    DECL_FASTCALL_SIMPLE(LoadCollisionFileFirstTime, _ZN11CFileLoader26LoadCollisionFileFirstTimeEPhjh, bool, u8* pBuffer, u32 size, u8 level);
    DECL_FASTCALL_SIMPLE(SaveTexDictionary, _ZN11CFileLoader17SaveTexDictionaryEP15RwTexDictionaryPKc, void, RwTexDictionary* pTxd, char const* pFilename);
    DECL_FASTCALL_SIMPLE(LoadCollisionModel, _ZN11CFileLoader18LoadCollisionModelEPhR9CColModelPKc, void, u8* p, CColModel& colModel, char const* pColModelName);
    DECL_FASTCALL_SIMPLE(LoadCollisionModelVer2, _ZN11CFileLoader22LoadCollisionModelVer2EPhjR9CColModelPKc, void, u8* pData, u32 size, CColModel& colModel, char const* pColModelName);
    DECL_FASTCALL_SIMPLE(LoadCollisionModelVer3, _ZN11CFileLoader22LoadCollisionModelVer3EPhjR9CColModelPKc, void, u8* pData, u32 size, CColModel& colModel, char const* pColModelName);
    DECL_FASTCALL_SIMPLE(LoadCollisionModelVer4, _ZN11CFileLoader22LoadCollisionModelVer4EPhjR9CColModelPKc, void, u8* pData, u32 size, CColModel& colModel, char const* pColModelName);
    DECL_FASTCALL_SIMPLE(LoadLine1, BYBIT(_ZN11CFileLoader8LoadLineEj, _ZN11CFileLoader8LoadLineEy), char*, uptr arg1);
    inline static char* LoadLine(uptr arg1)
    {
        return LoadLine1(arg1);
    }
    DECL_FASTCALL_SIMPLE(LoadLine2, _ZN11CFileLoader8LoadLineEPPhRi, char*, u8** ppData, i32& size);
    inline static char* LoadLine(u8** ppData, i32& size)
    {
        return LoadLine2(ppData, size);
    }
    DECL_FASTCALL_SIMPLE(FindRelatedModelInfoCB, _ZN11CFileLoader22FindRelatedModelInfoCBEP8RpAtomicPv, RpAtomic*, RpAtomic* pAtomic, void* data);
    DECL_FASTCALL_SIMPLE(SetRelatedModelInfoCB, _ZN11CFileLoader21SetRelatedModelInfoCBEP8RpAtomicPv, RpAtomic*, RpAtomic* pAtomic, void* data);
    DECL_FASTCALL_SIMPLE(LoadBoundingBox, _ZN11CFileLoader15LoadBoundingBoxEPhR12CBoundingBox, void, u8* p, CBoundingBox& boundingBox);
    DECL_FASTCALL_SIMPLE(LoadObject, _ZN11CFileLoader10LoadObjectEPKc, i32, char const* pLine);
    DECL_FASTCALL_SIMPLE(LoadTimeObject, _ZN11CFileLoader14LoadTimeObjectEPKc, i32, char const* pLine);
    DECL_FASTCALL_SIMPLE(LoadWeaponObject, _ZN11CFileLoader16LoadWeaponObjectEPKc, i32, char const* pLine);
    DECL_FASTCALL_SIMPLE(LoadAnimatedClumpObject, _ZN11CFileLoader23LoadAnimatedClumpObjectEPKc, i32, char const* pLine);
    DECL_FASTCALL_SIMPLE(LoadClumpObject, _ZN11CFileLoader15LoadClumpObjectEPKc, i32, char const* pLine);
    DECL_FASTCALL_SIMPLE(LoadVehicleObject, _ZN11CFileLoader17LoadVehicleObjectEPKc, i32, char const* pLine);
    DECL_FASTCALL_SIMPLE(LoadPedObject, _ZN11CFileLoader13LoadPedObjectEPKc, i32, char const* pLine);
    DECL_FASTCALL_SIMPLE(LoadPathHeader, _ZN11CFileLoader14LoadPathHeaderEPKcRi, i32, char const* pLine, i32& type);
    DECL_FASTCALL_SIMPLE(LoadPedPathNode, _ZN11CFileLoader15LoadPedPathNodeEPKcii, void, char const* pLine, i32 pathId, i32 nodeId);
    DECL_FASTCALL_SIMPLE(LoadCarPathNode, _ZN11CFileLoader15LoadCarPathNodeEPKciib, void, char const* pLine, i32 pathId, i32 nodeId, bool bOnWater);
    DECL_FASTCALL_SIMPLE(LoadGarage, _ZN11CFileLoader10LoadGarageEPKc, void, char const* pLine);
    DECL_FASTCALL_SIMPLE(LoadEntryExit, _ZN11CFileLoader13LoadEntryExitEPKc, void, char const* pLine);
    DECL_FASTCALL_SIMPLE(Load2dEffect, _ZN11CFileLoader12Load2dEffectEPKc, void, char const* pLine);
    DECL_FASTCALL_SIMPLE(LoadTXDParent, _ZN11CFileLoader13LoadTXDParentEPKc, void, char const* pLine);
    DECL_FASTCALL_SIMPLE(LoadCullZone, _ZN11CFileLoader12LoadCullZoneEPKc, void, char const* pLine);
    DECL_FASTCALL_SIMPLE(LoadOcclusionVolume, _ZN11CFileLoader19LoadOcclusionVolumeEPKcS1_, void, char const* pLine, char const* pFilename);
    DECL_FASTCALL_SIMPLE(LoadAudioZone, _ZN11CFileLoader13LoadAudioZoneEPKc, void, char const* pLine);
    DECL_FASTCALL_SIMPLE(LoadObjectInstance1, _ZN11CFileLoader18LoadObjectInstanceEPKc, CEntity*, char const* arg1);
    inline static CEntity* LoadObjectInstance(char const* arg1)
    {
        return LoadObjectInstance1(arg1);
    }
    DECL_FASTCALL_SIMPLE(LoadObjectInstance2, _ZN11CFileLoader18LoadObjectInstanceEP19CFileObjectInstancePKc, CEntity*, CFileObjectInstance* pObject, char const* pName);
    inline static CEntity* LoadObjectInstance(CFileObjectInstance* pObject, char const* pName)
    {
        return LoadObjectInstance2(pObject, pName);
    }
    DECL_FASTCALL_SIMPLE(LoadZone, _ZN11CFileLoader8LoadZoneEPKc, void, char const* pLine);
    DECL_FASTCALL_SIMPLE(LoadPickup, _ZN11CFileLoader10LoadPickupEPKc, void, char const* pLine);
    DECL_FASTCALL_SIMPLE(LoadCarGenerator1, _ZN11CFileLoader16LoadCarGeneratorEPKci, void, char const* pLine, i32 level);
    inline static void LoadCarGenerator(char const* pLine, i32 level)
    {
        return LoadCarGenerator1(pLine, level);
    }
    DECL_FASTCALL_SIMPLE(LoadCarGenerator2, _ZN11CFileLoader16LoadCarGeneratorEP17CFileCarGeneratori, void, CFileCarGenerator* pFileCarGen, i32 level);
    inline static void LoadCarGenerator(CFileCarGenerator* pFileCarGen, i32 level)
    {
        return LoadCarGenerator2(pFileCarGen, level);
    }
    DECL_FASTCALL_SIMPLE(LoadStuntJump, _ZN11CFileLoader13LoadStuntJumpEPKc, void, char const* pLine);
    DECL_FASTCALL_SIMPLE(LoadTimeCyclesModifier, _ZN11CFileLoader22LoadTimeCyclesModifierEPKc, void, char const* pLine);
    // STATIC values
    DECL_OBJECT_ARRAY_PLT(char, ms_line, BYBIT(0x679478, 0x850908));
DECL_CLASS_END()

#endif // __AML_PSDK_SAFILELOADER_H
