#ifndef __AML_PSDK_SAGRASSRENDERER_H
#define __AML_PSDK_SAGRASSRENDERER_H

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/gta_base/Vector.h>
#include <aml-psdk/renderware/RwVector.h>
#include <aml-psdk/renderware/RwMatrix.h>
#include <aml-psdk/renderware/RwRGBA.h>

struct RpAtomic;
struct RwTexture;

struct PPTriPlant
{
    CVector V1;
    CVector V2;
    CVector V3;
    CVector center;
    u16 model_id;
    u16 num_plants;
    RwV2d scale;
    RwTexture* texture_ptr;
    RwRGBA color;
    u8 intensity;
    u8 intensity_var;
    float seed;
    float scale_var_xy;
    float scale_var_z;
    float wind_bend_scale;
    float wind_bend_var;
};
CHECKSIZE(PPTriPlant, 0x5C, 0x68);

DECL_CLASS(CPPTriPlantBuffer)
    // Construct/Deconstruct functions
    DECL_CTORCALL(CPPTriPlantBuffer, _ZN17CPPTriPlantBufferC2Ev);
    DECL_DTORCALL(CPPTriPlantBuffer, _ZN17CPPTriPlantBufferD2Ev);

    // Member functions
    DECL_THISCALL_SIMPLE(Flush, _ZN17CPPTriPlantBuffer5FlushEv, void);
    DECL_THISCALL_HEAD(GetPPTriPlantPtr, _ZN17CPPTriPlantBuffer16GetPPTriPlantPtrEi, PPTriPlant*, i32 numTriPlants)
    DECL_THISCALL_TAIL(GetPPTriPlantPtr, numTriPlants)
    DECL_THISCALL_HEAD(ChangeCurrentPlantModelsSet, _ZN17CPPTriPlantBuffer27ChangeCurrentPlantModelsSetEi, void, i32 plantModelsSet)
    DECL_THISCALL_TAIL(ChangeCurrentPlantModelsSet, plantModelsSet)
    DECL_THISCALL_HEAD(IncreaseBufferIndex, _ZN17CPPTriPlantBuffer19IncreaseBufferIndexEii, void, i32 plantModelsSet, i32 numTriPlants)
    DECL_THISCALL_TAIL(IncreaseBufferIndex, plantModelsSet, numTriPlants)
    DECL_THISCALL_HEAD(SetPlantModelsTab, _ZN17CPPTriPlantBuffer17SetPlantModelsTabEjPP8RpAtomic, u8, u32 plantModelsSet, RpAtomic** models)
    DECL_THISCALL_TAIL(SetPlantModelsTab, plantModelsSet, models)
    DECL_THISCALL_HEAD(GetPlantModelsTab, _ZN17CPPTriPlantBuffer17GetPlantModelsTabEj, RpAtomic**, u32 plantModelsSet)
    DECL_THISCALL_TAIL(GetPlantModelsTab, plantModelsSet)

    // Member values
    i32 m_currentIndex;
    PPTriPlant m_Buffer[32];
    i32 m_plantModelsSet;
    RpAtomic** m_pPlantModelsTab[4];
DECL_CLASS_END()
CHECKSIZE(CPPTriPlantBuffer, 0xB98, 0xD30);

DECL_CLASS(CGrassRenderer)
    // Construct/Deconstruct functions
    DECL_CTORCALL(CGrassRenderer, _ZN14CGrassRendererC2Ev);
    DECL_DTORCALL(CGrassRenderer, _ZN14CGrassRendererD2Ev);

    // STATIC functions
    DECL_FASTCALL_SIMPLE(Initialise, _ZN14CGrassRenderer10InitialiseEv, bool);
    DECL_FASTCALL_SIMPLE(Shutdown, _ZN14CGrassRenderer8ShutdownEv, void);
    DECL_FASTCALL_SIMPLE(AddTriPlant, _ZN14CGrassRenderer11AddTriPlantEP10PPTriPlantj, void, PPTriPlant* triPlant, u32 plantModelsSet);
    DECL_FASTCALL_SIMPLE(FlushTriPlantBuffer, _ZN14CGrassRenderer19FlushTriPlantBufferEv, void);
    DECL_FASTCALL_SIMPLE(DrawTriPlants, _ZN14CGrassRenderer13DrawTriPlantsEP10PPTriPlantiPP8RpAtomicP11RwMatrixTag, RwBool, PPTriPlant* triPlants, i32 numTriPlants, RpAtomic** models, RwMatrix* matrix);
    DECL_FASTCALL_SIMPLE(SetPlantModelsTab, _ZN14CGrassRenderer17SetPlantModelsTabEjPP8RpAtomic, u8, u32 plantModelsSet, RpAtomic** models);
    DECL_FASTCALL_SIMPLE(GetPlantModelsTab, _ZN14CGrassRenderer17GetPlantModelsTabEj, RpAtomic**, u32 plantModelsSet);
    DECL_FASTCALL_SIMPLE(SetGlobalCameraPos, _ZN14CGrassRenderer18SetGlobalCameraPosERK7CVector, void, CVector const& cameraPos);
    DECL_FASTCALL_SIMPLE(SetCloseFarAlphaDist, _ZN14CGrassRenderer20SetCloseFarAlphaDistEff, void, float closeDist, float farDist);
    DECL_FASTCALL_SIMPLE(SetGlobalWindBending, _ZN14CGrassRenderer20SetGlobalWindBendingEf, void, float windBending);
    DECL_FASTCALL_SIMPLE(SetCurrentScanCode, _ZN14CGrassRenderer18SetCurrentScanCodeEt, void, u16 scanCode);

    // STATIC values
    DECL_OBJECT_PLT(CVector, m_vecCameraPos, BYBIT(0x6765EC, 0x84AC30));
    DECL_VALUE_PLT_FLT(m_closeDist, BYBIT(0x679600, 0x850C10));
    DECL_VALUE_PLT_FLT(m_farDist, BYBIT(0x678CD8, 0x84F9D8));
    DECL_VALUE_PLT_FLT(m_windBending, BYBIT(0x67821C, 0x84E450));
DECL_CLASS_END()
CHECKSIZE(CGrassRenderer, 0x1, 0x1);

#endif // __AML_PSDK_SAGRASSRENDERER_H
