#ifndef __AML_PSDK_SAFXEMITTER_H
#define __AML_PSDK_SAFXEMITTER_H

#include <aml-psdk/game_sa/engine/FxSystem.h>
#include <aml-psdk/game_sa/engine/FxInfo.h>

DECL_CLASS_BASED(FxEmitterBP_c, FxPrimBP_c)
    // Construct/Deconstruct functions
    DECL_CTORCALL(FxEmitterBP_c, _ZN13FxEmitterBP_cC2Ev);
    DECL_DTORCALL_VIRTUAL(FxEmitterBP_c, _ZN13FxEmitterBP_cD2Ev, _ZN13FxEmitterBP_c, _ZTV13FxEmitterBP_c);
    DECL_FASTCALL_SIMPLE(FuncProxy_opnewFxEmitterBP_c, BYBIT(_ZN13FxEmitterBP_cnwEj, _ZN13FxEmitterBP_cnwEm), FxEmitterBP_c*, size_t size);
    // Allocate raw storage from the FX arena.
    inline static FxEmitterBP_c* Instantiate(size_t size = sizeof(FxEmitterBP_c)) { return FuncProxy_opnewFxEmitterBP_c(size); }

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(FxEmitterBP_c, Load, _ZTV13FxEmitterBP_c, 2, u8, FILESTREAM file, i32 version, FxName32_t* textureNames)
    DECL_VIRTUALCALL_TAIL(file, version, textureNames)
    DECL_VIRTUALCALL_HEAD(FxEmitterBP_c, LoadTextures, _ZTV13FxEmitterBP_c, 3, u8, FxName32_t* textureNames, i32 version)
    DECL_VIRTUALCALL_TAIL(textureNames, version)
    DECL_VIRTUALCALL_HEAD(FxEmitterBP_c, CreateInstance, _ZTV13FxEmitterBP_c, 4, FxPrim_c*)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(FxEmitterBP_c, Update, _ZTV13FxEmitterBP_c, 5, i32, float deltaTime)
    DECL_VIRTUALCALL_TAIL(deltaTime)
    DECL_VIRTUALCALL_HEAD(FxEmitterBP_c, Render, _ZTV13FxEmitterBP_c, 6, void, RwCamera* camera, u32 primId, float brightness, u8 heatHaze)
    DECL_VIRTUALCALL_TAIL(camera, primId, brightness, heatHaze)
    DECL_VIRTUALCALL_HEAD(FxEmitterBP_c, FreePrtFromPrim, _ZTV13FxEmitterBP_c, 7, u8, FxSystem_c* system)
    DECL_VIRTUALCALL_TAIL(system)

    // Member functions
    DECL_THISCALL_HEAD(RenderHeatHaze, _ZN13FxEmitterBP_c14RenderHeatHazeEP8RwCamerajf, void, RwCamera* camera, u32 primId, float brightness)
    DECL_THISCALL_TAIL(RenderHeatHaze, camera, primId, brightness)
    DECL_THISCALL_HEAD(UpdateParticle, _ZN13FxEmitterBP_c14UpdateParticleEfP14FxEmitterPrt_c, u8, float deltaTime, FxEmitterPrt_c* particle)
    DECL_THISCALL_TAIL(UpdateParticle, deltaTime, particle)
    DECL_THISCALL_HEAD(IsFxInfoPresent, _ZN13FxEmitterBP_c15IsFxInfoPresentEi, u8, i32 type)
    DECL_THISCALL_TAIL(IsFxInfoPresent, type)

    // Member values
    u16 m_lodStart_ui16;
    u16 m_lodEnd_ui16;
    u8 m_hasFlatFxInfo;
    u8 m_hasHeatHazeFxInfo;
DECL_CLASS_END()
CHECKSIZE(FxEmitterBP_c, 0x40, 0x78);

DECL_CLASS_BASED(FxEmitter_c, FxPrim_c)
    // Construct/Deconstruct functions
    FxEmitter_c() {}
    DECL_DTORCALL_VIRTUAL_VTABLE(FxEmitter_c, _ZN11FxEmitter_c, _ZTV11FxEmitter_c);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(FxEmitter_c, Init, _ZTV11FxEmitter_c, 2, u8, FxPrimBP_c* blueprint, FxSystem_c* system)
    DECL_VIRTUALCALL_TAIL(blueprint, system)
    DECL_VIRTUALCALL_HEAD(FxEmitter_c, Update, _ZTV11FxEmitter_c, 3, void, float currentTime, float deltaTime)
    DECL_VIRTUALCALL_TAIL(currentTime, deltaTime)
    DECL_VIRTUALCALL_HEAD(FxEmitter_c, Reset, _ZTV11FxEmitter_c, 4, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(FxEmitter_c, AddParticle, _ZTV11FxEmitter_c, 5, void, RwV3d* pos, RwV3d* velocity, float timeSince, FxPrtMult_c* multipliers, float zRotation, float lightMult, u8 local)
    DECL_VIRTUALCALL_TAIL(pos, velocity, timeSince, multipliers, zRotation, lightMult, local)
    DECL_VIRTUALCALL_HEAD(FxEmitter_c, AddParticle, _ZTV11FxEmitter_c, 6, void, RwMatrix* matrix, RwV3d* velocity, float timeSince, FxPrtMult_c* multipliers, float zRotation, float lightMult, u8 local)
    DECL_VIRTUALCALL_TAIL(matrix, velocity, timeSince, multipliers, zRotation, lightMult, local)

    // Member functions
    DECL_THISCALL_HEAD(CreateParticles, _ZN11FxEmitter_c15CreateParticlesEff, void, float currentTime, float deltaTime)
    DECL_THISCALL_TAIL(CreateParticles, currentTime, deltaTime)
    DECL_THISCALL_HEAD(CreateParticle, _ZN11FxEmitter_c14CreateParticleEP14EmissionInfo_tP11RwMatrixTagP5RwV3dfP11FxPrtMult_cfh, FxEmitterPrt_c*, EmissionInfo_t* emissionInfo, RwMatrix* matrix, RwV3d* velocity, float timeSince, FxPrtMult_c* multipliers, float zRotation, u8 local)
    DECL_THISCALL_TAIL(CreateParticle, emissionInfo, matrix, velocity, timeSince, multipliers, zRotation, local)

    // Member values
    float m_particleCount;
DECL_CLASS_END()
CHECKSIZE(FxEmitter_c, 0x14, 0x20);

DECL_CLASS_BASED(FxEntitySystem_c, ListItem_c)
    // Member values
    FxSystem_c* pFxSys;
    CEntity* pEntity;
DECL_CLASS_END()
CHECKSIZE(FxEntitySystem_c, 0x10, 0x20);

#endif // __AML_PSDK_SAFXEMITTER_H
