#ifndef __AML_PSDK_SACUSTOMBUILDINGRENDERER_H
#define __AML_PSDK_SACUSTOMBUILDINGRENDERER_H

#include "../plugin.h"
#include "../../renderware/RwBase.h"
#include "../../renderware/RwRGBA.h"

struct RpAtomic;
struct RpClump;
struct RpMaterial;
struct RpGeometry;
struct RwTexture;
struct RxPipeline;
struct RwResEntry;
struct RxOpenGLMeshInstanceData;

struct CDNGeomExtension
{
    RwRGBA* m_pNightColTable;
    RwRGBA* m_pDayColTable;
    float m_fCurrentDNValue;
};
CHECKSIZE(CDNGeomExtension, 0xC, 0x18);

DECL_CLASS(CCustomBuildingPipeline)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(CreatePipe, _ZN23CCustomBuildingPipeline10CreatePipeEv, RwBool);
    DECL_FASTCALL_SIMPLE(DestroyPipe, _ZN23CCustomBuildingPipeline11DestroyPipeEv, void);
    DECL_FASTCALL_SIMPLE(CustomPipeAtomicSetup, _ZN23CCustomBuildingPipeline21CustomPipeAtomicSetupEP8RpAtomic, RpAtomic*, RpAtomic* atomic);
    DECL_FASTCALL_SIMPLE(CustomPipeMaterialSetup, _ZN23CCustomBuildingPipeline23CustomPipeMaterialSetupEP10RpMaterialPv, RpMaterial*, RpMaterial* material, void* data);
    DECL_FASTCALL_SIMPLE(SetFxEnvTexture, _ZN23CCustomBuildingPipeline15SetFxEnvTextureEP10RpMaterialP9RwTexture, void, RpMaterial* material, RwTexture* texture);
    DECL_FASTCALL_SIMPLE(GetFxEnvTexture, _ZN23CCustomBuildingPipeline15GetFxEnvTextureEP10RpMaterial, RwTexture*, RpMaterial* material);
    DECL_FASTCALL_SIMPLE(SetFxEnvShininess, _ZN23CCustomBuildingPipeline17SetFxEnvShininessEP10RpMaterialf, void, RpMaterial* material, float value);
    DECL_FASTCALL_SIMPLE(GetFxEnvShininess, _ZN23CCustomBuildingPipeline17GetFxEnvShininessEP10RpMaterial, float, RpMaterial* material);
    DECL_FASTCALL_SIMPLE(SetFxEnvScale, _ZN23CCustomBuildingPipeline13SetFxEnvScaleEP10RpMaterialff, void, RpMaterial* material, float x, float y);
    DECL_FASTCALL_SIMPLE(GetFxEnvScaleX, _ZN23CCustomBuildingPipeline14GetFxEnvScaleXEP10RpMaterial, float, RpMaterial* material);
    DECL_FASTCALL_SIMPLE(GetFxEnvScaleY, _ZN23CCustomBuildingPipeline14GetFxEnvScaleYEP10RpMaterial, float, RpMaterial* material);
    DECL_FASTCALL_SIMPLE(SetFxEnvTransScl, _ZN23CCustomBuildingPipeline16SetFxEnvTransSclEP10RpMaterialff, void, RpMaterial* material, float x, float y);
    DECL_FASTCALL_SIMPLE(GetFxEnvTransSclX, _ZN23CCustomBuildingPipeline17GetFxEnvTransSclXEP10RpMaterial, float, RpMaterial* material);
    DECL_FASTCALL_SIMPLE(GetFxEnvTransSclY, _ZN23CCustomBuildingPipeline17GetFxEnvTransSclYEP10RpMaterial, float, RpMaterial* material);
    DECL_FASTCALL_SIMPLE(CustomPipeRenderCB, _ZN23CCustomBuildingPipeline18CustomPipeRenderCBEP10RwResEntryPvhj, void, RwResEntry* resourceEntry, void* object, RwUInt8 type, RwUInt32 flags);
    DECL_FASTCALL_SIMPLE(CreateCustomObjPipe, _ZN23CCustomBuildingPipeline19CreateCustomObjPipeEv, RxPipeline*);

    // STATIC values
    DECL_OBJECT_PLT(RxPipeline*, ObjPipeline, BYBIT(0x678ff0, 0x850008));
DECL_CLASS_END()
CHECKSIZE(CCustomBuildingPipeline, 0x1, 0x1);

DECL_CLASS(CCustomBuildingDNPipeline)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(CustomPipeMaterialSetup, _ZN25CCustomBuildingDNPipeline23CustomPipeMaterialSetupEP10RpMaterialPv, RpMaterial*, RpMaterial* material, void* data);
    DECL_FASTCALL_SIMPLE(pluginExtraVertColourConstructorCB, _ZN25CCustomBuildingDNPipeline34pluginExtraVertColourConstructorCBEPvii, void*, void* object, RwInt32 offset, RwInt32 size);
    DECL_FASTCALL_SIMPLE(pluginExtraVertColourDestructorCB, _ZN25CCustomBuildingDNPipeline33pluginExtraVertColourDestructorCBEPvii, void*, void* object, RwInt32 offset, RwInt32 size);
    DECL_FASTCALL_SIMPLE(pluginExtraVertColourStreamReadCB, _ZN25CCustomBuildingDNPipeline33pluginExtraVertColourStreamReadCBEP8RwStreamiPvii, RwStream*, RwStream* stream, RwInt32 binaryLength, void* object, RwInt32 offset, RwInt32 size);
    DECL_FASTCALL_SIMPLE(pluginExtraVertColourStreamWriteCB, _ZN25CCustomBuildingDNPipeline34pluginExtraVertColourStreamWriteCBEP8RwStreamiPKvii, RwStream*, RwStream* stream, RwInt32 binaryLength, void const* object, RwInt32 offset, RwInt32 size);
    DECL_FASTCALL_SIMPLE(pluginExtraVertColourStreamGetSizeCB, _ZN25CCustomBuildingDNPipeline36pluginExtraVertColourStreamGetSizeCBEPKvii, RwInt32, void const* object, RwInt32 offset, RwInt32 size);
    DECL_FASTCALL_SIMPLE(CustomPipeInstanceCB, _ZN25CCustomBuildingDNPipeline20CustomPipeInstanceCBEPvP24RxOpenGLMeshInstanceDataii, RwBool, void* object, RxOpenGLMeshInstanceData* instanceData, RwBool reinstance, RwBool checkMeshes);
    DECL_FASTCALL_SIMPLE(CustomPipeRenderCB, _ZN25CCustomBuildingDNPipeline18CustomPipeRenderCBEP10RwResEntryPvhj, void, RwResEntry* resourceEntry, void* object, RwUInt8 type, RwUInt32 flags);
    DECL_FASTCALL_SIMPLE(CreateCustomObjPipe, _ZN25CCustomBuildingDNPipeline19CreateCustomObjPipeEv, RxPipeline*);
    DECL_FASTCALL_SIMPLE(CreatePipe, _ZN25CCustomBuildingDNPipeline10CreatePipeEv, RwBool);
    DECL_FASTCALL_SIMPLE(DestroyPipe, _ZN25CCustomBuildingDNPipeline11DestroyPipeEv, void);
    DECL_FASTCALL_SIMPLE(CustomPipeAtomicSetup, _ZN25CCustomBuildingDNPipeline21CustomPipeAtomicSetupEP8RpAtomic, RpAtomic*, RpAtomic* atomic);
    DECL_FASTCALL_SIMPLE(UsesThisPipeline, _ZN25CCustomBuildingDNPipeline16UsesThisPipelineEP8RpAtomic, RwBool, RpAtomic* atomic);
    DECL_FASTCALL_SIMPLE(ExtraVertColourPluginAttach, _ZN25CCustomBuildingDNPipeline27ExtraVertColourPluginAttachEv, RwBool);
    DECL_FASTCALL_SIMPLE(GetExtraVertColourPtr, _ZN25CCustomBuildingDNPipeline21GetExtraVertColourPtrEP10RpGeometry, u8*, RpGeometry* geometry);
    DECL_FASTCALL_SIMPLE(SetFxEnvTexture, _ZN25CCustomBuildingDNPipeline15SetFxEnvTextureEP10RpMaterialP9RwTexture, void, RpMaterial* material, RwTexture* texture);
    DECL_FASTCALL_SIMPLE(GetFxEnvTexture, _ZN25CCustomBuildingDNPipeline15GetFxEnvTextureEP10RpMaterial, RwTexture*, RpMaterial* material);
    DECL_FASTCALL_SIMPLE(SetFxEnvShininess, _ZN25CCustomBuildingDNPipeline17SetFxEnvShininessEP10RpMaterialf, void, RpMaterial* material, float value);
    DECL_FASTCALL_SIMPLE(GetFxEnvShininess, _ZN25CCustomBuildingDNPipeline17GetFxEnvShininessEP10RpMaterial, float, RpMaterial* material);
    DECL_FASTCALL_SIMPLE(SetFxEnvScale, _ZN25CCustomBuildingDNPipeline13SetFxEnvScaleEP10RpMaterialff, void, RpMaterial* material, float x, float y);
    DECL_FASTCALL_SIMPLE(GetFxEnvScaleX, _ZN25CCustomBuildingDNPipeline14GetFxEnvScaleXEP10RpMaterial, float, RpMaterial* material);
    DECL_FASTCALL_SIMPLE(GetFxEnvScaleY, _ZN25CCustomBuildingDNPipeline14GetFxEnvScaleYEP10RpMaterial, float, RpMaterial* material);
    DECL_FASTCALL_SIMPLE(SetFxEnvTransScl, _ZN25CCustomBuildingDNPipeline16SetFxEnvTransSclEP10RpMaterialff, void, RpMaterial* material, float x, float y);
    DECL_FASTCALL_SIMPLE(GetFxEnvTransSclX, _ZN25CCustomBuildingDNPipeline17GetFxEnvTransSclXEP10RpMaterial, float, RpMaterial* material);
    DECL_FASTCALL_SIMPLE(GetFxEnvTransSclY, _ZN25CCustomBuildingDNPipeline17GetFxEnvTransSclYEP10RpMaterial, float, RpMaterial* material);

    // STATIC values
    DECL_OBJECT_PLT(RxPipeline*, ObjPipeline, BYBIT(0x679dcc, 0x851bb0));
    DECL_OBJECT_PLT(float, m_fDNBalanceParam, BYBIT(0x676e94, 0x84bd68));
    DECL_OBJECT_SYM(u32, m_AtmDNWorkingIndex, _ZN25CCustomBuildingDNPipeline19m_AtmDNWorkingIndexE);
    DECL_OBJECT_SYM(RwBool, m_bCameraChange, _ZN25CCustomBuildingDNPipeline15m_bCameraChangeE);
    DECL_OBJECT_SYM(RwBool, m_bDeviceSupportsVS11, _ZN25CCustomBuildingDNPipeline21m_bDeviceSupportsVS11E);
    DECL_OBJECT_PLT(i32, ms_extraVertColourPluginOffset, BYBIT(0x67710c, 0x84c250));
DECL_CLASS_END()
CHECKSIZE(CCustomBuildingDNPipeline, 0x1, 0x1);

DECL_CLASS(CCustomBuildingRenderer)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(Initialise, _ZN23CCustomBuildingRenderer10InitialiseEv, RwBool);
    DECL_FASTCALL_SIMPLE(PluginAttach, _ZN23CCustomBuildingRenderer12PluginAttachEv, RwBool);
    DECL_FASTCALL_SIMPLE(Shutdown, _ZN23CCustomBuildingRenderer8ShutdownEv, void);
    DECL_FASTCALL_SIMPLE(Update, _ZN23CCustomBuildingRenderer6UpdateEv, void);
    DECL_FASTCALL_SIMPLE(AtomicSetup, _ZN23CCustomBuildingRenderer11AtomicSetupEP8RpAtomic, RpAtomic*, RpAtomic* atomic);
    DECL_FASTCALL_SIMPLE(IsCBPCPipelineAttached, _ZN23CCustomBuildingRenderer22IsCBPCPipelineAttachedEP8RpAtomic, RwBool, RpAtomic* atomic);
    DECL_FASTCALL_SIMPLE(UpdateDayNightBalanceParam, _ZN23CCustomBuildingRenderer26UpdateDayNightBalanceParamEv, void);
DECL_CLASS_END()
CHECKSIZE(CCustomBuildingRenderer, 0x1, 0x1);

#endif // __AML_PSDK_SACUSTOMBUILDINGRENDERER_H
