#ifndef __AML_PSDK_SACUSTOMCARENVMAPPIPELINE_H
#define __AML_PSDK_SACUSTOMCARENVMAPPIPELINE_H

#include "../plugin.h"
#include "../../renderware/RwBase.h"

struct RpAtomic;
struct RpMaterial;
struct RwTexture;
struct RxPipeline;
struct RwResEntry;
struct RxOpenGLMeshInstanceData;
struct CustomEnvMapPipeMaterialDataPool;
struct CustomEnvMapPipeAtomicDataPool;
struct CustomSpecMapPipeMaterialDataPool;

struct CustomEnvMapPipeMaterialData
{
    i8 cfEnvScaleX;
    i8 cfEnvScaleY;
    i8 cfEnvTransSclX;
    i8 cfEnvTransSclY;
    u8 cfShininess;
    u16 nCurrentRenderFrame;
    RwTexture* pEnvTexture;
};
CHECKSIZE(CustomEnvMapPipeMaterialData, 0xc, 0x10);

struct CustomEnvMapPipeAtomicData
{
    float fOffsetU;
    float fPrevMapPosX;
    float fPrevMapPosY;
};
CHECKSIZE(CustomEnvMapPipeAtomicData, 0xc, 0xc);

struct CustomSpecMapPipeMaterialData
{
    float fSpecularity;
    RwTexture* pSpecularTexture;
};
CHECKSIZE(CustomSpecMapPipeMaterialData, 0x8, 0x10);

struct CustomEnvMapPipeMaterialDiskData
{
    float fEnvScaleX;
    float fEnvScaleY;
    float fEnvTransSclX;
    float fEnvTransSclY;
    float fShininess;
    RwTexture* pEnvTexture;
};
CHECKSIZE(CustomEnvMapPipeMaterialDiskData, 0x18, 0x20);

struct CustomSpecMapPipeMaterialDiskData
{
    float fSpecularity;
    char cName[24];
};
CHECKSIZE(CustomSpecMapPipeMaterialDiskData, 0x1c, 0x1c);

DECL_CLASS(CCustomCarEnvMapPipeline)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(pluginEnvMatDestructorCB, _ZN24CCustomCarEnvMapPipeline24pluginEnvMatDestructorCBEPvii, void*, void* object, RwInt32 offset, RwInt32 size);
    DECL_FASTCALL_SIMPLE(pluginEnvMatConstructorCB, _ZN24CCustomCarEnvMapPipeline25pluginEnvMatConstructorCBEPvii, void*, void* object, RwInt32 offset, RwInt32 size);
    DECL_FASTCALL_SIMPLE(pluginEnvMatCopyConstructorCB, _ZN24CCustomCarEnvMapPipeline29pluginEnvMatCopyConstructorCBEPvPKvii, void*, void* object, void const* source, RwInt32 offset, RwInt32 size);
    DECL_FASTCALL_SIMPLE(pluginEnvMatStreamWriteCB, _ZN24CCustomCarEnvMapPipeline25pluginEnvMatStreamWriteCBEP8RwStreamiPKvii, RwStream*, RwStream* stream, RwInt32 binaryLength, void const* object, RwInt32 offset, RwInt32 size);
    DECL_FASTCALL_SIMPLE(pluginEnvMatStreamReadCB, _ZN24CCustomCarEnvMapPipeline24pluginEnvMatStreamReadCBEP8RwStreamiPvii, RwStream*, RwStream* stream, RwInt32 binaryLength, void* object, RwInt32 offset, RwInt32 size);
    DECL_FASTCALL_SIMPLE(pluginEnvMatStreamGetSizeCB, _ZN24CCustomCarEnvMapPipeline27pluginEnvMatStreamGetSizeCBEPKvii, RwInt32, void const* object, RwInt32 offset, RwInt32 size);
    DECL_FASTCALL_SIMPLE(pluginEnvAtmDestructorCB, _ZN24CCustomCarEnvMapPipeline24pluginEnvAtmDestructorCBEPvii, void*, void* object, RwInt32 offset, RwInt32 size);
    DECL_FASTCALL_SIMPLE(pluginEnvAtmConstructorCB, _ZN24CCustomCarEnvMapPipeline25pluginEnvAtmConstructorCBEPvii, void*, void* object, RwInt32 offset, RwInt32 size);
    DECL_FASTCALL_SIMPLE(pluginEnvAtmCopyConstructorCB, _ZN24CCustomCarEnvMapPipeline29pluginEnvAtmCopyConstructorCBEPvPKvii, void*, void* object, void const* source, RwInt32 offset, RwInt32 size);
    DECL_FASTCALL_SIMPLE(pluginSpecMatConstructorCB, _ZN24CCustomCarEnvMapPipeline26pluginSpecMatConstructorCBEPvii, void*, void* object, int offset, int size);
    DECL_FASTCALL_SIMPLE(pluginSpecMatDestructorCB, _ZN24CCustomCarEnvMapPipeline25pluginSpecMatDestructorCBEPvii, void*, void* object, int offset, int size);
    DECL_FASTCALL_SIMPLE(pluginSpecMatCopyConstructorCB, _ZN24CCustomCarEnvMapPipeline30pluginSpecMatCopyConstructorCBEPvPKvii, void*, void* object, void const* source, int offset, int size);
    DECL_FASTCALL_SIMPLE(pluginSpecMatStreamWriteCB, _ZN24CCustomCarEnvMapPipeline26pluginSpecMatStreamWriteCBEP8RwStreamiPKvii, RwStream*, RwStream* stream, RwInt32 binaryLength, void const* object, RwInt32 offset, RwInt32 size);
    DECL_FASTCALL_SIMPLE(pluginSpecMatStreamReadCB, _ZN24CCustomCarEnvMapPipeline25pluginSpecMatStreamReadCBEP8RwStreamiPvii, RwStream*, RwStream* stream, RwInt32 binaryLength, void* object, RwInt32 offset, RwInt32 size);
    DECL_FASTCALL_SIMPLE(pluginSpecMatStreamGetSizeCB, _ZN24CCustomCarEnvMapPipeline28pluginSpecMatStreamGetSizeCBEPKvii, RwInt32, void const* object, RwInt32 offset, RwInt32 size);
    DECL_FASTCALL_SIMPLE(SetCustomEnvMapPipeMaterialDataDefaults, _ZN24CCustomCarEnvMapPipeline39SetCustomEnvMapPipeMaterialDataDefaultsEP28CustomEnvMapPipeMaterialData, void, CustomEnvMapPipeMaterialData* data);
    DECL_FASTCALL_SIMPLE(CustomPipeMaterialSetup, _ZN24CCustomCarEnvMapPipeline23CustomPipeMaterialSetupEP10RpMaterialPv, RpMaterial*, RpMaterial* material, void* data);
    DECL_FASTCALL_SIMPLE(CreateCustomOpenGLObjPipe, _ZN24CCustomCarEnvMapPipeline25CreateCustomOpenGLObjPipeEv, RxPipeline*);
    DECL_FASTCALL_SIMPLE(CustomPipeRenderCB, _ZN24CCustomCarEnvMapPipeline18CustomPipeRenderCBEP10RwResEntryPvhj, void, RwResEntry* resourceEntry, void* object, RwUInt8 type, RwUInt32 flags);
    DECL_FASTCALL_SIMPLE(CustomPipeInstanceCB, _ZN24CCustomCarEnvMapPipeline20CustomPipeInstanceCBEPvP24RxOpenGLMeshInstanceDataii, RwBool, void* object, RxOpenGLMeshInstanceData* instanceData, RwBool reinstance, RwBool checkMeshes);
    DECL_FASTCALL_SIMPLE(CreatePipe, _ZN24CCustomCarEnvMapPipeline10CreatePipeEv, RwBool);
    DECL_FASTCALL_SIMPLE(DestroyPipe, _ZN24CCustomCarEnvMapPipeline11DestroyPipeEv, void);
    DECL_FASTCALL_SIMPLE(PreRenderUpdate, _ZN24CCustomCarEnvMapPipeline15PreRenderUpdateEv, void);
    DECL_FASTCALL_SIMPLE(RegisterPlugin, _ZN24CCustomCarEnvMapPipeline14RegisterPluginEv, RwBool);
    DECL_FASTCALL_SIMPLE(AllocEnvMapPipeAtomicData, _ZN24CCustomCarEnvMapPipeline25AllocEnvMapPipeAtomicDataEP8RpAtomic, CustomEnvMapPipeAtomicData*, RpAtomic* atomic);
    DECL_FASTCALL_SIMPLE(SetCustomEnvMapPipeAtomicDataDefaults, _ZN24CCustomCarEnvMapPipeline37SetCustomEnvMapPipeAtomicDataDefaultsEP26CustomEnvMapPipeAtomicData, void, CustomEnvMapPipeAtomicData* data);
    DECL_FASTCALL_SIMPLE(SetFxEnvTexture, _ZN24CCustomCarEnvMapPipeline15SetFxEnvTextureEP10RpMaterialP9RwTexture, void, RpMaterial* material, RwTexture* texture);
    DECL_FASTCALL_SIMPLE(GetFxEnvTexture, _ZN24CCustomCarEnvMapPipeline15GetFxEnvTextureEP10RpMaterial, RwTexture*, RpMaterial* material);
    DECL_FASTCALL_SIMPLE(SetFxEnvShininess, _ZN24CCustomCarEnvMapPipeline17SetFxEnvShininessEP10RpMaterialf, void, RpMaterial* material, float value);
    DECL_FASTCALL_SIMPLE(GetFxEnvShininess, _ZN24CCustomCarEnvMapPipeline17GetFxEnvShininessEP10RpMaterial, float, RpMaterial* material);
    DECL_FASTCALL_SIMPLE(SetFxEnvScale, _ZN24CCustomCarEnvMapPipeline13SetFxEnvScaleEP10RpMaterialff, void, RpMaterial* material, float x, float y);
    DECL_FASTCALL_SIMPLE(GetFxEnvScaleX, _ZN24CCustomCarEnvMapPipeline14GetFxEnvScaleXEP10RpMaterial, float, RpMaterial* material);
    DECL_FASTCALL_SIMPLE(GetFxEnvScaleY, _ZN24CCustomCarEnvMapPipeline14GetFxEnvScaleYEP10RpMaterial, float, RpMaterial* material);
    DECL_FASTCALL_SIMPLE(SetFxEnvTransScl, _ZN24CCustomCarEnvMapPipeline16SetFxEnvTransSclEP10RpMaterialff, void, RpMaterial* material, float x, float y);
    DECL_FASTCALL_SIMPLE(GetFxEnvTransSclX, _ZN24CCustomCarEnvMapPipeline17GetFxEnvTransSclXEP10RpMaterial, float, RpMaterial* material);
    DECL_FASTCALL_SIMPLE(GetFxEnvTransSclY, _ZN24CCustomCarEnvMapPipeline17GetFxEnvTransSclYEP10RpMaterial, float, RpMaterial* material);
    DECL_FASTCALL_SIMPLE(DuplicateCustomEnvMapPipeMaterialData, _ZN24CCustomCarEnvMapPipeline37DuplicateCustomEnvMapPipeMaterialDataEPP28CustomEnvMapPipeMaterialData, CustomEnvMapPipeMaterialData*, CustomEnvMapPipeMaterialData** data);
    DECL_FASTCALL_SIMPLE(SetFxSpecTexture, _ZN24CCustomCarEnvMapPipeline16SetFxSpecTextureEP10RpMaterialP9RwTexture, void, RpMaterial* material, RwTexture* texture);
    DECL_FASTCALL_SIMPLE(GetFxSpecTexture, _ZN24CCustomCarEnvMapPipeline16GetFxSpecTextureEP10RpMaterial, RwTexture*, RpMaterial* material);
    DECL_FASTCALL_SIMPLE(SetFxSpecSpecularity, _ZN24CCustomCarEnvMapPipeline20SetFxSpecSpecularityEP10RpMaterialf, void, RpMaterial* material, float value);
    DECL_FASTCALL_SIMPLE(GetFxSpecSpecularity, _ZN24CCustomCarEnvMapPipeline20GetFxSpecSpecularityEP10RpMaterial, float, RpMaterial* material);
    DECL_FASTCALL_SIMPLE(CustomPipeAtomicSetup, _ZN24CCustomCarEnvMapPipeline21CustomPipeAtomicSetupEP8RpAtomic, RpAtomic*, RpAtomic* atomic);

    // STATIC values
    DECL_OBJECT_PLT(RxPipeline*, ObjPipeline, BYBIT(0x6765ac, 0x84abb0));
    DECL_OBJECT_PLT(i32, ms_envMapPluginOffset, BYBIT(0x677180, 0x84c338));
    DECL_OBJECT_PLT(CustomEnvMapPipeMaterialDataPool*, m_gEnvMapPipeMatDataPool, BYBIT(0x676a88, 0x84b558));
    DECL_OBJECT_PLT(CustomEnvMapPipeMaterialData, fakeEnvMapPipeMatData, BYBIT(0x6771d8, 0x84c3e8));
    DECL_OBJECT_PLT(float, m_EnvMapLightingMult, BYBIT(0x678e3c, 0x84fca0));
    DECL_OBJECT_PLT(i32, ms_envMapAtmPluginOffset, BYBIT(0x676c64, 0x84b910));
    DECL_OBJECT_PLT(CustomEnvMapPipeAtomicDataPool*, m_gEnvMapPipeAtmDataPool, BYBIT(0x676930, 0x84b2b0));
    DECL_OBJECT_PLT(i32, ms_specularMapPluginOffset, BYBIT(0x6795cc, 0x850ba8));
    DECL_OBJECT_PLT(CustomSpecMapPipeMaterialDataPool*, m_gSpecMapPipeMatDataPool, BYBIT(0x6785a0, 0x84eb58));
DECL_CLASS_END()
CHECKSIZE(CCustomCarEnvMapPipeline, 0x1, 0x1);

#endif // __AML_PSDK_SACUSTOMCARENVMAPPIPELINE_H
