#ifndef __AML_PSDK_SACARFXRENDERER_H
#define __AML_PSDK_SACARFXRENDERER_H

#include "../plugin.h"
#include "../../renderware/RwBase.h"

struct RpAtomic;
struct RpClump;
struct RpMaterial;
struct RwTexture;
struct CVehicleModelInfo;

DECL_CLASS(CCarFXRenderer)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(Initialise, _ZN14CCarFXRenderer10InitialiseEv, RwBool);
    DECL_FASTCALL_SIMPLE(RegisterPlugins, _ZN14CCarFXRenderer15RegisterPluginsEv, RwBool);
    DECL_FASTCALL_SIMPLE(Shutdown, _ZN14CCarFXRenderer8ShutdownEv, void);
    DECL_FASTCALL_SIMPLE(PreRenderUpdate, _ZN14CCarFXRenderer15PreRenderUpdateEv, void);
    DECL_FASTCALL_SIMPLE(CustomCarPipeClumpSetup, _ZN14CCarFXRenderer23CustomCarPipeClumpSetupEP7RpClump, RpClump*, RpClump* clump);
    DECL_FASTCALL_SIMPLE(CustomCarPipeAtomicSetup, _ZN14CCarFXRenderer24CustomCarPipeAtomicSetupEP8RpAtomic, RpAtomic*, RpAtomic* atomic);
    DECL_FASTCALL_SIMPLE(SetCustomFXAtomicRenderPipelinesVMICB, _ZN14CCarFXRenderer37SetCustomFXAtomicRenderPipelinesVMICBEP8RpAtomicPv, RpAtomic*, RpAtomic* atomic, void* data);
    DECL_FASTCALL_SIMPLE(IsCCPCPipelineAttached, _ZN14CCarFXRenderer22IsCCPCPipelineAttachedEP8RpAtomic, RwBool, RpAtomic* atomic);
    DECL_FASTCALL_SIMPLE(SetFxEnvMapLightMult, _ZN14CCarFXRenderer20SetFxEnvMapLightMultEf, void, float value);
    DECL_FASTCALL_SIMPLE(GetFxEnvMapLightMult, _ZN14CCarFXRenderer20GetFxEnvMapLightMultEv, float);
    DECL_FASTCALL_SIMPLE(InitialiseDirtTexture, _ZN14CCarFXRenderer21InitialiseDirtTextureEv, RwBool);
    DECL_FASTCALL_SIMPLE(RemapDirt, _ZN14CCarFXRenderer9RemapDirtEP17CVehicleModelInfoj, void, CVehicleModelInfo* modelInfo, u32 dirtLevel);
    DECL_FASTCALL_SIMPLE(MaterialRemapDirtCB, _ZN14CCarFXRenderer19MaterialRemapDirtCBEP10RpMaterialPv, RpMaterial*, RpMaterial* material, void* data);
    DECL_FASTCALL_SIMPLE(AtomicRemapDirtCB, _ZN14CCarFXRenderer17AtomicRemapDirtCBEP8RpAtomicPv, RpAtomic*, RpAtomic* atomic, void* data);

    // STATIC values
    DECL_OBJECT_ARRAY_PLT(RwTexture*, ms_aDirtTextures, BYBIT(0x6776a0, 0x84cd70));
DECL_CLASS_END()
CHECKSIZE(CCarFXRenderer, 0x1, 0x1);

#endif // __AML_PSDK_SACARFXRENDERER_H
