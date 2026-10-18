#ifndef __AML_PSDK_SAFXSYSTEM_H
#define __AML_PSDK_SAFXSYSTEM_H

#include <aml-psdk/game_sa/base/Lists.h>
#include <aml-psdk/game_sa/audio/AEAudioEntity.h>
#include <aml-psdk/gta_base/Vector.h>
#include <aml-psdk/renderware/RwMatrix.h>
#include <aml-psdk/game_sa/base/FxPrimitives.h>
#include <aml-psdk/renderware/RwTexture.h>

struct FxPrimBP_c;
struct FxName32_t;
struct FxInfo_c;
struct EmissionInfo_t;
struct MovementInfo_t;
struct RenderInfo_t;
struct Particle_c;
struct FxPrtMult_c;
struct FxSystemBP_c;
struct FxBox_c;
struct CEntity;
struct FxSphere_c;
struct FxPrim_c;
struct RwCamera;

enum eFxSystemKillStatus : u8
{
    FX_NOT_KILLED = 0,
    FX_PLAY_AND_KILL = 1,
    FX_KILLED = 2
};

enum eFxSystemPlayStatus : u8
{
    FX_PLAYING = 0,
    FX_STOPPED = 1
};

typedef void (*particleCB)(Particle_c *, int, void **);

DECL_CLASS(FxInfoManager_c)
    // Construct/Deconstruct functions
    DECL_DTORCALL(FxInfoManager_c, _ZN15FxInfoManager_cD2Ev);

    // Member functions
    DECL_THISCALL_HEAD(Load, BYBIT(_ZN15FxInfoManager_c4LoadEji, _ZN15FxInfoManager_c4LoadEyi), void, uptr fileId, i32 version)
    DECL_THISCALL_TAIL(Load, fileId, version)
    DECL_THISCALL_HEAD(AddFxInfo, _ZN15FxInfoManager_c9AddFxInfoEi, FxInfo_c*, i32 type)
    DECL_THISCALL_TAIL(AddFxInfo, type)
    DECL_THISCALL_HEAD(ProcessEmissionInfo, _ZN15FxInfoManager_c19ProcessEmissionInfoEfffhP14EmissionInfo_t, void, float st, float dt, float len, u8 useConst, EmissionInfo_t* emissionInfo)
    DECL_THISCALL_TAIL(ProcessEmissionInfo, st, dt, len, useConst, emissionInfo)
    DECL_THISCALL_HEAD(ProcessMovementInfo, _ZN15FxInfoManager_c19ProcessMovementInfoEffffhP14MovementInfo_t, void, float st, float pt, float dt, float len, u8 useConst, MovementInfo_t* movementInfo)
    DECL_THISCALL_TAIL(ProcessMovementInfo, st, pt, dt, len, useConst, movementInfo)
    DECL_THISCALL_HEAD(ProcessRenderInfo, _ZN15FxInfoManager_c17ProcessRenderInfoEffffhP12RenderInfo_t, void, float st, float pt, float dt, float len, u8 useConst, RenderInfo_t* renderInfo)
    DECL_THISCALL_TAIL(ProcessRenderInfo, st, pt, dt, len, useConst, renderInfo)

    // Member values
    i32 m_numFxInfos;
    FxInfo_c** m_fxInfoPtrs;
    i8 m_movementOffset;
    i8 m_renderOffset;
DECL_CLASS_END()
CHECKSIZE(FxInfoManager_c, 0xC, 0x18);

DECL_CLASS_VTABLE(FxPrimBP_c)
    // Construct/Deconstruct functions
    DECL_CTORCALL(FxPrimBP_c, _ZN10FxPrimBP_cC2Ev);
    DECL_DTORCALL_VIRTUAL(FxPrimBP_c, _ZN10FxPrimBP_cD2Ev, _ZN10FxPrimBP_c, _ZTV10FxPrimBP_c);

    // Virtual functions
    virtual u8 Load(uptr arg1, i32 arg2, FxName32_t* arg3) = 0;
    virtual u8 LoadTextures(FxName32_t* arg1, i32 arg2) = 0;
    virtual FxPrim_c* CreateInstance() = 0;
    virtual i32 Update(float arg1) = 0;
    virtual void Render(RwCamera* arg1, u32 arg2, float arg3, u8 arg4) = 0;
    virtual u8 FreePrtFromPrim(FxSystem_c* arg1) = 0;

    // Member functions
    DECL_THISCALL_HEAD(GetRWMatrix, _ZN10FxPrimBP_c11GetRWMatrixEP11RwMatrixTag, void, RwMatrix* mat)
    DECL_THISCALL_TAIL(GetRWMatrix, mat)

    // Member values
    i8 m_type;
    i8 m_srcBlendId;
    i8 m_dstBlendId;
    u8 m_alphaOn;
    i16* m_matVals_i16;
    RwTexture* m_texturePtr;
    RwTexture* m_texturePtr2;
    RwTexture* m_texturePtr3;
    RwTexture* m_texturePtr4;
    i32 m_txdIndex;
    List_c m_particleList;
    FxInfoManager_c m_fxInfoMan;
DECL_CLASS_END()
CHECKSIZE(FxPrimBP_c, 0x38, 0x70);

DECL_CLASS_VTABLE(FxPrim_c)
    // Construct/Deconstruct functions
    DECL_CTORCALL(FxPrim_c, _ZN8FxPrim_cC2Ev);
    DECL_DTORCALL_VIRTUAL(FxPrim_c, _ZN8FxPrim_cD2Ev, _ZN8FxPrim_c, _ZTV8FxPrim_c);

    // Virtual functions
    virtual u8 Init(FxPrimBP_c* arg1, FxSystem_c* arg2) = 0;
    virtual void Update(float arg1, float arg2) = 0;
    virtual void Reset() = 0;
    virtual void AddParticle(RwV3d* arg1, RwV3d* arg2, float arg3, FxPrtMult_c* arg4, float arg5, float arg6, u8 arg7) = 0;
    virtual void AddParticle(RwMatrix* arg1, RwV3d* arg2, float arg3, FxPrtMult_c* arg4, float arg5, float arg6, u8 arg7) = 0;

    // Member functions
    DECL_THISCALL_HEAD(Enable, _ZN8FxPrim_c6EnableEh, void, u8 on)
    DECL_THISCALL_TAIL(Enable, on)

    // Member values
    FxPrimBP_c* m_bpPtr;
    FxSystem_c* m_fxSysPtr;
    u8 m_enabled;
DECL_CLASS_END()
CHECKSIZE(FxPrim_c, 0x10, 0x20);

DECL_CLASS_BASED(FxSystemBP_c, ListItem_c)
    // Construct/Deconstruct functions
    DECL_DTORCALL(FxSystemBP_c, _ZN12FxSystemBP_cD2Ev);
    DECL_CTORCALL(FxSystemBP_c, _ZN12FxSystemBP_cC2Ev);

    // Member functions
    DECL_THISCALL_HEAD(Load, BYBIT(_ZN12FxSystemBP_c4LoadEPcji, _ZN12FxSystemBP_c4LoadEPcyi), u8, char* filename, uptr fileId, i32 version)
    DECL_THISCALL_TAIL(Load, filename, fileId, version)
    DECL_THISCALL_SIMPLE(Unload, _ZN12FxSystemBP_c6UnloadEv, void);
    DECL_THISCALL_HEAD(Update, _ZN12FxSystemBP_c6UpdateEf, i32, float deltaTime)
    DECL_THISCALL_TAIL(Update, deltaTime)
    DECL_THISCALL_HEAD(Render, _ZN12FxSystemBP_c6RenderEP8RwCamerafh, void, RwCamera* camPtr, float brightness, u8 doHeatHaze)
    DECL_THISCALL_TAIL(Render, camPtr, brightness, doHeatHaze)
    DECL_THISCALL_HEAD(FreePrtFromSystem, _ZN12FxSystemBP_c17FreePrtFromSystemEP10FxSystem_c, u8, FxSystem_c* pFxSys)
    DECL_THISCALL_TAIL(FreePrtFromSystem, pFxSys)
    DECL_THISCALL_SIMPLE(GetBoundingSphere, _ZN12FxSystemBP_c17GetBoundingSphereEv, FxSphere_c*);
    DECL_THISCALL_HEAD(SetBoundingSphere, _ZN12FxSystemBP_c17SetBoundingSphereEP5RwV3df, void, RwV3d* center, float radius)
    DECL_THISCALL_TAIL(SetBoundingSphere, center, radius)

    // Member values
    u32 m_hashName;
    float m_length;
    float m_loopIntervalMin;
    float m_loopIntervalMax;
    u16 m_cullDist_ui16;
    i8 m_playMode;
    i8 m_numFxPrimBPs;
    FxPrimBP_c** m_fxPrimBPPtrs;
    FxSphere_c* m_boundingSphere;
DECL_CLASS_END()
CHECKSIZE(FxSystemBP_c, 0x24, 0x38);

DECL_CLASS_BASED(FxSystem_c, ListItem_c)
    // Construct/Deconstruct functions
    DECL_CTORCALL(FxSystem_c, _ZN10FxSystem_cC2Ev);
    DECL_DTORCALL(FxSystem_c, _ZN10FxSystem_cD2Ev);

    // STATIC functions
    DECL_FASTCALL_SIMPLE(UpdateBoundingBoxCB, _ZN10FxSystem_c19UpdateBoundingBoxCBEP10Particle_ciPPv, void, Particle_c *prtPtr, i32 type, void **userPtr);

    // Member functions
    DECL_THISCALL_SIMPLE(Play, _ZN10FxSystem_c4PlayEv, void);
    DECL_THISCALL_SIMPLE(Pause, _ZN10FxSystem_c5PauseEv, void);
    DECL_THISCALL_SIMPLE(Stop, _ZN10FxSystem_c4StopEv, void);
    DECL_THISCALL_SIMPLE(PlayAndKill, _ZN10FxSystem_c11PlayAndKillEv, void);
    DECL_THISCALL_SIMPLE(Kill, _ZN10FxSystem_c4KillEv, void);
    DECL_THISCALL_SIMPLE(Exit, _ZN10FxSystem_c4ExitEv, void);
    DECL_THISCALL_SIMPLE(IsVisible, _ZN10FxSystem_c9IsVisibleEv, u8);
    DECL_THISCALL_SIMPLE(CopyParentMatrix, _ZN10FxSystem_c16CopyParentMatrixEv, void);
    DECL_THISCALL_SIMPLE(GetPlayStatus, _ZN10FxSystem_c13GetPlayStatusEv, int);
    DECL_THISCALL_SIMPLE(ResetBoundingSphere, _ZN10FxSystem_c19ResetBoundingSphereEv, void);
    
    DECL_THISCALL_HEAD(AttachToBone, _ZN10FxSystem_c12AttachToBoneEP7CEntityi, void, CEntity *pEntity, i32 boneTag)
    DECL_THISCALL_TAIL(AttachToBone, pEntity, boneTag)
    
    DECL_THISCALL_NAMED_HEAD(AddParticle1, AddParticle, _ZN10FxSystem_c11AddParticleEP5RwV3dS1_fP11FxPrtMult_cfffh, void, RwV3d *pos, RwV3d *vel, float timeSince, FxPrtMult_c *fxMults, float zRot, float lightMult, float lightMultLimit, u8 createLocal)
    DECL_THISCALL_TAIL(AddParticle1, pos, vel, timeSince, fxMults, zRot, lightMult, lightMultLimit, createLocal)
    
    DECL_THISCALL_NAMED_HEAD(AddParticle2, AddParticle, _ZN10FxSystem_c11AddParticleEP11RwMatrixTagP5RwV3dfP11FxPrtMult_cfffh, void, RwMatrix *mat, RwV3d *vel, float timeSince, FxPrtMult_c *fxMults, float zRot, float lightMult, float lightMultLimit, u8 createLocal)
    DECL_THISCALL_TAIL(AddParticle2, mat, vel, timeSince, fxMults, zRot, lightMult, lightMultLimit, createLocal)
    
    DECL_THISCALL_HEAD(EnablePrim, _ZN10FxSystem_c10EnablePrimEih, void, i32 primId, u8 on)
    DECL_THISCALL_TAIL(EnablePrim, primId, on)
    
    DECL_THISCALL_HEAD(SetMatrix, _ZN10FxSystem_c9SetMatrixEP11RwMatrixTag, void, RwMatrix *mat)
    DECL_THISCALL_TAIL(SetMatrix, mat)
    
    DECL_THISCALL_HEAD(SetOffsetPos, _ZN10FxSystem_c12SetOffsetPosEP5RwV3d, void, RwV3d *pos)
    DECL_THISCALL_TAIL(SetOffsetPos, pos)
    
    DECL_THISCALL_HEAD(AddOffsetPos, _ZN10FxSystem_c12AddOffsetPosEP5RwV3d, void, RwV3d *pos)
    DECL_THISCALL_TAIL(AddOffsetPos, pos)
    
    DECL_THISCALL_HEAD(SetConstTime, _ZN10FxSystem_c12SetConstTimeEhf, void, u8 on, float time)
    DECL_THISCALL_TAIL(SetConstTime, on, time)
    
    DECL_THISCALL_HEAD(SetRateMult, _ZN10FxSystem_c11SetRateMultEf, void, float rateMult)
    DECL_THISCALL_TAIL(SetRateMult, rateMult)
    
    DECL_THISCALL_HEAD(SetTimeMult, _ZN10FxSystem_c11SetTimeMultEf, void, float timeMult)
    DECL_THISCALL_TAIL(SetTimeMult, timeMult)
    
    DECL_THISCALL_HEAD(SetVelAdd, _ZN10FxSystem_c9SetVelAddEP5RwV3d, void, RwV3d *vel)
    DECL_THISCALL_TAIL(SetVelAdd, vel)
    
    DECL_THISCALL_HEAD(Init, _ZN10FxSystem_c4InitEP12FxSystemBP_cP11RwMatrixTagS3_, u8, FxSystemBP_c *fxSysBPPtr, RwMatrix *offsetMat, RwMatrix *parentMat)
    DECL_THISCALL_TAIL(Init, fxSysBPPtr, offsetMat, parentMat)
    
    DECL_THISCALL_HEAD(GetBoundingSphereWld, _ZN10FxSystem_c20GetBoundingSphereWldEP10FxSphere_c, u8, FxSphere_c *bSphere)
    DECL_THISCALL_TAIL(GetBoundingSphereWld, bSphere)
    
    DECL_THISCALL_HEAD(Update, _ZN10FxSystem_c6UpdateEP8RwCameraf, u8, RwCamera *camPtr, float deltaTime)
    DECL_THISCALL_TAIL(Update, camPtr, deltaTime)
    
    DECL_THISCALL_HEAD(GetCompositeMatrix, _ZN10FxSystem_c18GetCompositeMatrixEP11RwMatrixTag, void, RwMatrix *compMat)
    DECL_THISCALL_TAIL(GetCompositeMatrix, compMat)
    
    DECL_THISCALL_HEAD(DoFxAudio, _ZN10FxSystem_c9DoFxAudioE7CVector, void, CVector fxPos)
    DECL_THISCALL_TAIL(DoFxAudio, fxPos)
    
    DECL_THISCALL_HEAD(SetLocalParticles, _ZN10FxSystem_c17SetLocalParticlesEh, void, u8 on)
    DECL_THISCALL_TAIL(SetLocalParticles, on)
    
    DECL_THISCALL_HEAD(ForAllParticles, _ZN10FxSystem_c15ForAllParticlesEPFvP10Particle_ciPPvES2_, i32, particleCB cback, void *userPtr)
    DECL_THISCALL_TAIL(ForAllParticles, cback, userPtr)
    
    DECL_THISCALL_HEAD(GetBoundingBox, _ZN10FxSystem_c14GetBoundingBoxEP7FxBox_c, void, FxBox_c *bBox)
    DECL_THISCALL_TAIL(GetBoundingBox, bBox)
    
    DECL_THISCALL_HEAD(GetBoundingSphereLcl, _ZN10FxSystem_c20GetBoundingSphereLclEP10FxSphere_c, u8, FxSphere_c *bSphere)
    DECL_THISCALL_TAIL(GetBoundingSphereLcl, bSphere)
    
    DECL_THISCALL_HEAD(SetBoundingSphere, _ZN10FxSystem_c17SetBoundingSphereEP10FxSphere_c, void, FxSphere_c *bSphere)
    DECL_THISCALL_TAIL(SetBoundingSphere, bSphere)
    
    DECL_THISCALL_HEAD(SetZTestEnable, _ZN10FxSystem_c14SetZTestEnableEh, void, u8 on)
    DECL_THISCALL_TAIL(SetZTestEnable, on)
    
    DECL_THISCALL_HEAD(SetMustCreatePrts, _ZN10FxSystem_c17SetMustCreatePrtsEh, void, u8 on)
    DECL_THISCALL_TAIL(SetMustCreatePrts, on)

    // Helper functions
    inline CAEFireAudioEntity* GetFireAudio() { return &m_fireAudio; }

    // Member values
    void              *m_pBlueprint;
    RwMatrix          *m_pParentMatrix;
    CEntity           *m_pEntity; // mobile stuff
    RwMatrix           m_localMatrix;
    signed char        m_nPlayStatus; // see eFxSystemPlayStatus
    signed char        m_nKillStatus; // see eFxSystemKillStatus
    unsigned char      m_bConstTimeSet;
    float              m_fCurrentProgress;
    float              m_fCameraDistance;
    unsigned short     m_nConstTime;
    unsigned short     m_nRateMult;
    unsigned short     m_nTimeMult;
    struct
    {
        unsigned char  bOwnedParentMatrix: 1;
        unsigned char  bLocalParticles : 1;
        unsigned char  bZTestEnabled : 1;
        unsigned char  bDontCreateParticles : 1;
        unsigned char  bPreviouslyCulled : 1;
        unsigned char  bMustCreatePtrs : 1;
    } m_nFlags;
    float              m_fLoopInterval;
    CVector            m_vecVelAdd;
    FxSphere_c        *m_pBounding;
    FxPrim_c         **m_pPrimsPtrList;
    union
    {
        CAEFireAudioEntity m_fireAudio;
    };
DECL_CLASS_END()
CHECKSIZE(FxSystem_c, 0x108, 0x148);

#endif // __AML_PSDK_SAFXSYSTEM_H
