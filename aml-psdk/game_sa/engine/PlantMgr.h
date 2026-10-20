#ifndef __AML_PSDK_SAPLANTMGR_H
#define __AML_PSDK_SAPLANTMGR_H

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/gta_base/Vector.h>
#include <aml-psdk/gta_base/RGBA.h>
#include <aml-psdk/renderware/RwVector.h>
#include <aml-psdk/renderware/RwRGBA.h>

struct CEntity;
struct CAtomicModelInfo;
struct RwTexture;
struct RpAtomic;

DECL_CLASS(CPlantSurfPropPlantData)
    // Member values
    u16 m_nModelID;
    u16 m_nTextureID;
    RwRGBA m_rgbaColor;
    u8 m_nIntensity;
    u8 m_nIntensityVar;
    float m_fScaleXY;
    float m_fScaleZ;
    float m_fScaleVarXY;
    float m_fScaleVarZ;
    float m_fDensity;
    float m_fWindBendScale;
    float m_fWindBendVar;
DECL_CLASS_END()
CHECKSIZE(CPlantSurfPropPlantData, 0x28, 0x28);

DECL_CLASS(CPlantSurfProp)
    // Member values
    u16 m_nPlantSlotID;
    CPlantSurfPropPlantData m_PlantData[3];
DECL_CLASS_END()
CHECKSIZE(CPlantSurfProp, 0x7c, 0x7c);

DECL_CLASS(CPlantLocTri)
    // Member functions
    DECL_THISCALL_HEAD(Add, _ZN12CPlantLocTri3AddERK5RwV3dS2_S2_hhhh, CPlantLocTri*, RwV3d const& value1, RwV3d const& value2, RwV3d const& value3, u8 value14, u8 value25, u8 value36, u8 value4)
    DECL_THISCALL_TAIL(Add, value1, value2, value3, value14, value25, value36, value4)
    DECL_THISCALL_SIMPLE(Release, _ZN12CPlantLocTri7ReleaseEv, void);

    // Member values
    CVector m_V1;
    CVector m_V2;
    CVector m_V3;
    CVector m_Center;
    float m_SphereRadius;
    float m_Seed[3];
    u16 m_nMaxNumPlants[3];
    u8 m_nSurfaceType;
    u8 m_nLighting;
    u8 m_createsPlants : 1;
    u8 m_createsObjects : 1;
    u8 m_createdObjects : 1;
    CPlantLocTri* m_pNextTri;
    CPlantLocTri* m_pPrevTri;
DECL_CLASS_END()
CHECKSIZE(CPlantLocTri, 0x54, 0x60);

DECL_CLASS(CPlantColEntEntry)
    // Member functions
    DECL_THISCALL_HEAD(AddEntry, _ZN17CPlantColEntEntry8AddEntryEP7CEntity, CPlantColEntEntry*, CEntity* entity)
    DECL_THISCALL_TAIL(AddEntry, entity)
    DECL_THISCALL_SIMPLE(ReleaseEntry, _ZN17CPlantColEntEntry12ReleaseEntryEv, void);

    // Member values
    CEntity* m_pEntity;
    CPlantLocTri** m_LocTriArray;
    u16 m_nNumTris;
    CPlantColEntEntry* m_pNextEntry;
    CPlantColEntEntry* m_pPrevEntry;
DECL_CLASS_END()
CHECKSIZE(CPlantColEntEntry, 0x14, 0x28);

DECL_CLASS(CPlantSurfPropMgr)
    // Construct/Deconstruct functions
    DECL_CTORCALL(CPlantSurfPropMgr, _ZN17CPlantSurfPropMgrC2Ev);
    DECL_DTORCALL(CPlantSurfPropMgr, _ZN17CPlantSurfPropMgrD2Ev);

    // STATIC functions
    DECL_FASTCALL_SIMPLE(Initialise, _ZN17CPlantSurfPropMgr10InitialiseEv, u8);
    DECL_FASTCALL_SIMPLE(Shutdown, _ZN17CPlantSurfPropMgr8ShutdownEv, void);
    DECL_FASTCALL_SIMPLE(GetSurfProperties, _ZN17CPlantSurfPropMgr17GetSurfPropertiesEt, CPlantSurfProp*, u16 text);
    DECL_FASTCALL_SIMPLE(AllocSurfProperties, _ZN17CPlantSurfPropMgr19AllocSurfPropertiesEth, CPlantSurfProp*, u16 text, u8 value);
    DECL_FASTCALL_SIMPLE(LoadPlantsDat, _ZN17CPlantSurfPropMgr13LoadPlantsDatEPKc, u8, char const* text);

    // STATIC values
    DECL_OBJECT_ARRAY_PLT(CPlantSurfProp*, m_SurfPropPtrTab, BYBIT(0x678eb4, 0x84fd90));
    DECL_OBJECT_ARRAY_PLT(CPlantSurfProp, m_SurfPropTab, BYBIT(0x679c70, 0x8518f8));
    DECL_OBJECT_PLT(u32, m_countSurfPropsAllocated, BYBIT(0x679c30, 0x851878));

DECL_CLASS_END()
CHECKSIZE(CPlantSurfPropMgr, 0x1, 0x1);

DECL_CLASS(CPlantMgr)
    // Construct/Deconstruct functions
    DECL_CTORCALL(CPlantMgr, _ZN9CPlantMgrC2Ev);
    DECL_DTORCALL(CPlantMgr, _ZN9CPlantMgrD2Ev);

    // STATIC functions
    DECL_FASTCALL_SIMPLE(Initialise, _ZN9CPlantMgr10InitialiseEv, u8);
    DECL_FASTCALL_SIMPLE(Shutdown, _ZN9CPlantMgr8ShutdownEv, void);
    DECL_FASTCALL_SIMPLE(ReloadConfig, _ZN9CPlantMgr12ReloadConfigEv, u8);
    DECL_FASTCALL_SIMPLE(Update, _ZN9CPlantMgr6UpdateERK7CVector, u8, CVector const& pos);
    DECL_FASTCALL_SIMPLE(PreUpdateOnceForNewCameraPos, _ZN9CPlantMgr28PreUpdateOnceForNewCameraPosERK7CVector, u8, CVector const& pos);
    DECL_FASTCALL_SIMPLE(Render, _ZN9CPlantMgr6RenderEv, void);
    DECL_FASTCALL_SIMPLE(UpdateAmbientColor, _ZN9CPlantMgr18UpdateAmbientColorEv, void);
    DECL_FASTCALL_SIMPLE(CalculateWindBending, _ZN9CPlantMgr20CalculateWindBendingEv, float);
    DECL_FASTCALL_SIMPLE(SetPlantFriendlyFlagInAtomicMI, _ZN9CPlantMgr30SetPlantFriendlyFlagInAtomicMIEP16CAtomicModelInfo, u8, CAtomicModelInfo* value);
    DECL_FASTCALL_SIMPLE(_ColEntityCache_Update, _ZN9CPlantMgr22_ColEntityCache_UpdateERK7CVectorh, u8, CVector const& pos, u8 value);
    DECL_FASTCALL_SIMPLE(_ColEntityCache_FindInCache, _ZN9CPlantMgr27_ColEntityCache_FindInCacheEP7CEntity, CPlantColEntEntry*, CEntity* entity);
    DECL_FASTCALL_SIMPLE(_ColEntityCache_Add, _ZN9CPlantMgr19_ColEntityCache_AddEP7CEntityh, CPlantColEntEntry*, CEntity* entity, u8 value);
    DECL_FASTCALL_SIMPLE(_ColEntityCache_Remove, _ZN9CPlantMgr22_ColEntityCache_RemoveEP7CEntity, void, CEntity* entity);
    DECL_FASTCALL_SIMPLE(_UpdateLocTris, _ZN9CPlantMgr14_UpdateLocTrisERK7CVectori, u8, CVector const& pos, i32 index);
    DECL_FASTCALL_SIMPLE(_ProcessEntryCollisionDataSections, _ZN9CPlantMgr34_ProcessEntryCollisionDataSectionsEP17CPlantColEntEntryRK7CVectori, u8, CPlantColEntEntry* value, CVector const& pos, i32 index);
    DECL_FASTCALL_SIMPLE(_ProcessEntryCollisionDataSections_AddLocTris, _ZN9CPlantMgr45_ProcessEntryCollisionDataSections_AddLocTrisEP17CPlantColEntEntryRK7CVectoriii, void, CPlantColEntEntry* value, CVector const& pos, i32 index1, i32 index2, i32 index3);
    DECL_FASTCALL_SIMPLE(_ProcessEntryCollisionDataSections_RemoveLocTris, _ZN9CPlantMgr48_ProcessEntryCollisionDataSections_RemoveLocTrisEP17CPlantColEntEntryRK7CVectoriii, void, CPlantColEntEntry* value, CVector const& pos, i32 index1, i32 index2, i32 index3);
    DECL_FASTCALL_SIMPLE(DbgRenderLocTris, _ZN9CPlantMgr16DbgRenderLocTrisEv, u8);
    DECL_FASTCALL_SIMPLE(DbgRenderCachedEntities, _ZN9CPlantMgr23DbgRenderCachedEntitiesEPj, u8, u32* value);
    DECL_FASTCALL_SIMPLE(DbgCountLocTrisAndPlants, _ZN9CPlantMgr24DbgCountLocTrisAndPlantsEjPjS0_, u8, u32 flags, u32* value1, u32* value2);
    DECL_FASTCALL_SIMPLE(DbgCountCachedEntities, _ZN9CPlantMgr22DbgCountCachedEntitiesEPj, u8, u32* value);
    DECL_FASTCALL_SIMPLE(MoveColEntToList, _ZN9CPlantMgr16MoveColEntToListEPP17CPlantColEntEntryS2_S1_, CPlantColEntEntry*, CPlantColEntEntry** value1, CPlantColEntEntry** value2, CPlantColEntEntry* value);
    DECL_FASTCALL_SIMPLE(MoveLocTriToList, _ZN9CPlantMgr16MoveLocTriToListEPP12CPlantLocTriS2_S1_, CPlantLocTri*, CPlantLocTri** value1, CPlantLocTri** value2, CPlantLocTri* value);

    // STATIC values
    DECL_OBJECT_PLT(CPlantColEntEntry*, m_UnusedColEntListHead, BYBIT(0x678c14, 0x84f850));
    DECL_OBJECT_PLT(CPlantColEntEntry*, m_CloseColEntListHead, BYBIT(0x678890, 0x84f140));
    DECL_OBJECT_ARRAY_PLT(CPlantColEntEntry, m_ColEntCacheTab, BYBIT(0x678b34, 0x84f690));
    DECL_OBJECT_PLT(CPlantLocTri*, m_UnusedLocTriListHead, BYBIT(0x676e28, 0x84bc98));
    DECL_OBJECT_ARRAY_PLT(CPlantLocTri*, m_CloseLocTriListHead, BYBIT(0x6798c8, 0x8511b0));
    DECL_OBJECT_ARRAY_PLT(CPlantLocTri, m_LocTrisTab, BYBIT(0x675f60, 0x849f30));
    DECL_OBJECT_PLT(u16, m_scanCode, BYBIT(0x677c5c, 0x84d8d8));
    DECL_OBJECT_PLT(CRGBA, m_AmbientColor, BYBIT(0x679390, 0x850738));
    DECL_OBJECT_ARRAY_PLT(RwTexture*, PC_PlantTextureTab0, BYBIT(0x679364, 0x8506e0));
    DECL_OBJECT_ARRAY_PLT(RwTexture*, PC_PlantTextureTab1, BYBIT(0x677930, 0x84d288));
    DECL_OBJECT_ARRAY_PLT(RwTexture*, PC_PlantTextureTab2, BYBIT(0x677f7c, 0x84df18));
    DECL_OBJECT_ARRAY_PLT(RwTexture*, PC_PlantTextureTab3, BYBIT(0x677484, 0x84c940));
    DECL_OBJECT_ARRAY_SYM(RwTexture**, PC_PlantSlotTextureTab, _ZN9CPlantMgr22PC_PlantSlotTextureTabE);
    DECL_OBJECT_ARRAY_PLT(RpAtomic*, PC_PlantModelsTab0, BYBIT(0x6783a8, 0x84e768));
    DECL_OBJECT_ARRAY_PLT(RpAtomic*, PC_PlantModelsTab1, BYBIT(0x679a34, 0x851480));
    DECL_OBJECT_ARRAY_PLT(RpAtomic*, PC_PlantModelsTab2, BYBIT(0x6786ec, 0x84ee00));
    DECL_OBJECT_ARRAY_PLT(RpAtomic*, PC_PlantModelsTab3, BYBIT(0x676690, 0x84ad78));
    DECL_OBJECT_ARRAY_SYM(RpAtomic**, PC_PlantModelSlotTab, _ZN9CPlantMgr20PC_PlantModelSlotTabE);

DECL_CLASS_END()
CHECKSIZE(CPlantMgr, 0x1, 0x1);

#endif // __AML_PSDK_SAPLANTMGR_H
