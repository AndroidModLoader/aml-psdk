#ifndef __AML_PSDK_SAOBJECTDATA_H
#define __AML_PSDK_SAOBJECTDATA_H

/*
    Plugin-SDK (Grand Theft Auto San Andreas) header file
    Authors: GTA Community. See more here
    https://github.com/DK22Pac/plugin-sdk
    Do not delete this comment block. Respect others' work!
*/

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/gta_base/Vector.h>

struct CObject;
struct FxSystemBP_c;

DECL_CLASS(CObjectInfo)
    // Member values
    float m_fMass;
    float m_fTurnMass;
    float m_fAirResistance;
    float m_fElasticity;
    float m_fBuoyancyConstant;
    float m_fUprootLimit;
    float m_fColDamageMultiplier;
    u8 m_nColDamageEffect;
    u8 m_nSpecialColResponseCase;
    u8 m_nCameraAvoidObject;
    u8 m_bCausesExplosion;
    u8 m_nFxType;
    CVector m_vFxOffset;
    FxSystemBP_c* m_pFxSystem;
    float m_fSmashMultiplier;
    CVector m_vecBreakVelocity;
    float m_fBreakVelocityRand;
    i32 m_nGunBreakMode;
    u8 m_nSparksOnImpact;
DECL_CLASS_END()
CHECKSIZE(CObjectInfo, 0x50, 0x58);

DECL_CLASS(CObjectData)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(Initialise, _ZN11CObjectData10InitialiseEPcb, void, char* pFilename, bool bUnused);
    DECL_FASTCALL_SIMPLE(SetObjectData, _ZN11CObjectData13SetObjectDataEiR7CObject, void, i32 modelIndex, CObject& object);

    // STATIC values
    DECL_OBJECT_ARRAY_SYM(CObjectInfo, ms_aObjectInfo, _ZN11CObjectData14ms_aObjectInfoE);
DECL_CLASS_END()
CHECKSIZE(CObjectData, 0x1, 0x1);

#define ms_aObjectInfo ms_aObjectInfo()

#endif // __AML_PSDK_SAOBJECTDATA_H
