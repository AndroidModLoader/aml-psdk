#ifndef __AML_PSDK_RPMATFX_H
#define __AML_PSDK_RPMATFX_H

#include "RpMaterial.h"
#include "RwFrame.h"
#include "RwRender.h"

struct RpAtomic;
struct RpWorldSector;

enum RpMatFXMaterialFlags : RwInt32
{
    rpMATFXEFFECTNULL = 0,
    rpMATFXEFFECTBUMPMAP = 1,
    rpMATFXEFFECTENVMAP = 2,
    rpMATFXEFFECTBUMPENVMAP = 3,
    rpMATFXEFFECTDUAL = 4,
    rpMATFXEFFECTUVTRANSFORM = 5,
    rpMATFXEFFECTDUALUVTRANSFORM = 6,
    rpMATFXEFFECTMAX = 7,
    rpMATFXNUMEFFECTS = 6,
    rpMATFXFORCEENUMSIZEINT = 2147483647,
};

enum RpMatFXOpenGLPipeline : RwInt32
{
    rpNAMATFXOPENGLPIPELINE = 0,
    rpMATFXOPENGLATOMICPIPELINE = 1,
    rpMATFXOPENGLWORLDSECTORPIPELINE = 2,
    rpMATFXOPENGLPIPELINEMAX = 3,
    rpMATFXOPENGLPIPELINEFORCEENUMSIZEINT = 2147483647,
};

DECL_FASTCALL_SIMPLE_GLO(RpMatFXGetOpenGLPipeline, _Z24RpMatFXGetOpenGLPipeline21RpMatFXOpenGLPipeline, RxPipeline*, RpMatFXOpenGLPipeline openglPipeline);
DECL_FASTCALL_SIMPLE_GLO(RpMatFXMaterialGetBumpMapTexture, _Z32RpMatFXMaterialGetBumpMapTexturePK10RpMaterial, RwTexture*, RpMaterial const* material);
DECL_FASTCALL_SIMPLE_GLO(RpMatFXMaterialSetEnvMapCoefficient, _Z35RpMatFXMaterialSetEnvMapCoefficientP10RpMaterialf, RpMaterial*, RpMaterial* material, RwReal coef);
DECL_FASTCALL_SIMPLE_GLO(RpMatFXMaterialGetEnvMapFrameBufferAlpha, _Z40RpMatFXMaterialGetEnvMapFrameBufferAlphaPK10RpMaterial, RwBool, RpMaterial const* material);
DECL_FASTCALL_SIMPLE_GLO(RpMatFXMaterialGetDualTexture, _Z29RpMatFXMaterialGetDualTexturePK10RpMaterial, RwTexture*, RpMaterial const* material);
DECL_FASTCALL_SIMPLE_GLO(RpMatFXMaterialSetEnvMapFrameBufferAlpha, _Z40RpMatFXMaterialSetEnvMapFrameBufferAlphaP10RpMateriali, RpMaterial*, RpMaterial* material, RwBool useFrameBufferAlpha);
DECL_FASTCALL_SIMPLE_GLO(RpMatFXMaterialSetDualTexture, _Z29RpMatFXMaterialSetDualTextureP10RpMaterialP9RwTexture, RpMaterial*, RpMaterial* material, RwTexture* texture);
DECL_FASTCALL_SIMPLE_GLO(RpMatFXPluginAttach, _Z19RpMatFXPluginAttachv, RwBool);
DECL_FASTCALL_SIMPLE_GLO(RpMatFXMaterialGetEffects, _Z25RpMatFXMaterialGetEffectsPK10RpMaterial, RpMatFXMaterialFlags, RpMaterial const* material);
DECL_FASTCALL_SIMPLE_GLO(RpMatFXAtomicQueryEffects, _Z25RpMatFXAtomicQueryEffectsP8RpAtomic, RwBool, RpAtomic* atomic);
DECL_FASTCALL_SIMPLE_GLO(RpMatFXMaterialSetupBumpMap, _Z27RpMatFXMaterialSetupBumpMapP10RpMaterialP9RwTextureP7RwFramef, RpMaterial*, RpMaterial* material, RwTexture* texture, RwFrame* frame, RwReal coef);
DECL_FASTCALL_SIMPLE_GLO(RpMatFXMaterialSetupDualTexture, _Z31RpMatFXMaterialSetupDualTextureP10RpMaterialP9RwTexture15RwBlendFunctionS3_, RpMaterial*, RpMaterial* material, RwTexture* texture, RwBlendFunction srcBlendMode, RwBlendFunction dstBlendMode);
DECL_FASTCALL_SIMPLE_GLO(RpMatFXMaterialSetEffects, _Z25RpMatFXMaterialSetEffectsP10RpMaterial20RpMatFXMaterialFlags, RpMaterial*, RpMaterial* material, RpMatFXMaterialFlags flags);
DECL_FASTCALL_SIMPLE_GLO(RpMatFXMaterialSetBumpMapTexture, _Z32RpMatFXMaterialSetBumpMapTextureP10RpMaterialP9RwTexture, RpMaterial*, RpMaterial* material, RwTexture* bumpTexture);
DECL_FASTCALL_SIMPLE_GLO(RpMatFXMaterialGetEnvMapFrame, _Z29RpMatFXMaterialGetEnvMapFramePK10RpMaterial, RwFrame*, RpMaterial const* material);
DECL_FASTCALL_SIMPLE_GLO(RpMatFXAtomicEnableEffects, _Z26RpMatFXAtomicEnableEffectsP8RpAtomic, RpAtomic*, RpAtomic* atomic);
DECL_FASTCALL_SIMPLE_GLO(RpMatFXMaterialGetEnvMapTexture, _Z31RpMatFXMaterialGetEnvMapTexturePK10RpMaterial, RwTexture*, RpMaterial const* material);
DECL_FASTCALL_SIMPLE_GLO(RpMatFXMaterialSetupEnvMap, _Z26RpMatFXMaterialSetupEnvMapP10RpMaterialP9RwTextureP7RwFrameif, RpMaterial*, RpMaterial* material, RwTexture* texture, RwFrame* frame, RwBool useFrameBufferAlpha, RwReal coef);
DECL_FASTCALL_SIMPLE_GLO(RpMatFXMaterialSetEnvMapFrame, _Z29RpMatFXMaterialSetEnvMapFrameP10RpMaterialP7RwFrame, RpMaterial*, RpMaterial* material, RwFrame* frame);
DECL_FASTCALL_SIMPLE_GLO(RpMatFXMaterialGetUVTransformMatrices, _Z37RpMatFXMaterialGetUVTransformMatricesPK10RpMaterialPP11RwMatrixTagS4_, RpMaterial const*, RpMaterial const* material, RwMatrix** baseTransform, RwMatrix** dualTransform);
DECL_FASTCALL_SIMPLE_GLO(RpMatFXMaterialGetDualBlendModes, _Z32RpMatFXMaterialGetDualBlendModesPK10RpMaterialP15RwBlendFunctionS3_, RpMaterial const*, RpMaterial const* material, RwBlendFunction* srcBlendMode, RwBlendFunction* dstBlendMode);
DECL_FASTCALL_SIMPLE_GLO(RpMatFXMaterialSetEnvMapTexture, _Z31RpMatFXMaterialSetEnvMapTextureP10RpMaterialP9RwTexture, RpMaterial*, RpMaterial* material, RwTexture* texture);
DECL_FASTCALL_SIMPLE_GLO(RpMatFXMaterialSetUVTransformMatrices, _Z37RpMatFXMaterialSetUVTransformMatricesP10RpMaterialP11RwMatrixTagS2_, RpMaterial*, RpMaterial* material, RwMatrix* baseTransform, RwMatrix* dualTransform);
DECL_FASTCALL_SIMPLE_GLO(RpMatFXMaterialSetDualBlendModes, _Z32RpMatFXMaterialSetDualBlendModesP10RpMaterial15RwBlendFunctionS1_, RpMaterial*, RpMaterial* material, RwBlendFunction srcBlendMode, RwBlendFunction dstBlendMode);
DECL_FASTCALL_SIMPLE_GLO(RpMatFXWorldSectorEnableEffects, _Z31RpMatFXWorldSectorEnableEffectsP13RpWorldSector, RpWorldSector*, RpWorldSector* worldSector);
DECL_FASTCALL_SIMPLE_GLO(RpMatFXMaterialGetBumpMapCoefficient, _Z36RpMatFXMaterialGetBumpMapCoefficientPK10RpMaterial, RwReal, RpMaterial const* material);
DECL_FASTCALL_SIMPLE_GLO(RpMatFXMaterialDataSetFreeListCreateParams, _Z42RpMatFXMaterialDataSetFreeListCreateParamsii, void, RwInt32 blockSize, RwInt32 numBlocksToPrealloc);
DECL_FASTCALL_SIMPLE_GLO(RpMatFXMaterialGetBumpMapFrame, _Z30RpMatFXMaterialGetBumpMapFramePK10RpMaterial, RwFrame*, RpMaterial const* material);
DECL_FASTCALL_SIMPLE_GLO(RpMatFXMaterialSetBumpMapCoefficient, _Z36RpMatFXMaterialSetBumpMapCoefficientP10RpMaterialf, RpMaterial*, RpMaterial* material, RwReal coef);
DECL_FASTCALL_SIMPLE_GLO(RpMatFXWorldSectorQueryEffects, _Z30RpMatFXWorldSectorQueryEffectsP13RpWorldSector, RwBool, RpWorldSector* worldSector);
DECL_FASTCALL_SIMPLE_GLO(RpMatFXMaterialGetBumpMapBumpedTexture, _Z38RpMatFXMaterialGetBumpMapBumpedTexturePK10RpMaterial, RwTexture*, RpMaterial const* material);
DECL_FASTCALL_SIMPLE_GLO(RpMatFXMaterialGetEnvMapCoefficient, _Z35RpMatFXMaterialGetEnvMapCoefficientPK10RpMaterial, RwReal, RpMaterial const* material);
DECL_FASTCALL_SIMPLE_GLO(RpMatFXMaterialSetBumpMapFrame, _Z30RpMatFXMaterialSetBumpMapFrameP10RpMaterialP7RwFrame, RpMaterial*, RpMaterial* material, RwFrame* frame);

DECL_VALUE_PLT_I32_GLOBAL(MatFXMaterialDataOffset, BYBIT(0x679A04, 0x851420));

#endif // __AML_PSDK_RPMATFX_H
