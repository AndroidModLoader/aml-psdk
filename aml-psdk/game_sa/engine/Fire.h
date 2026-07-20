#ifndef __AML_PSDK_SAFIRE_H
#define __AML_PSDK_SAFIRE_H

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/gta_base/Vector.h>
#include <aml-psdk/renderware/RwMatrix.h>

struct CEntity;
struct CVector;
struct FxSystem_c;
struct RwMatrix;
struct RwV3d;

DECL_CLASS(CFire)
    // Member values
    u8                                 m_bActive : 1;
    u8                                 m_bCreatedByScript : 1;
    u8                                 m_bMakesNoise : 1;
    u8                                 m_bBeingExtinguished : 1;
    u8                                 m_bFirstGeneration : 1;
    u16                                ScriptReferenceIndex;
    CVector                            m_vLocation;
    CEntity*                           m_pEntityOnFire;
    CEntity*                           m_pEntityStartedFire;
    u32                                m_nTimeToBurn;
    float                              m_Strength;
    i8                                 m_nNumGenerationsAllowed;
    u8                                 m_RemovalDist;
    FxSystem_c*                        m_fxSysPtr;

    // Functions
    DECL_CTORCALL(CFire, _ZN5CFireC2Ev);
    DECL_DTORCALL(CFire, _ZN5CFireD2Ev);
    DECL_THISCALL_SIMPLE(Initialise, _ZN5CFire10InitialiseEv, void);
    DECL_THISCALL_SIMPLE(Extinguish, _ZN5CFire10ExtinguishEv, void);
    DECL_THISCALL_SIMPLE(ProcessFire, _ZN5CFire11ProcessFireEv, void);
    DECL_THISCALL_HEAD(CreateFxSysForStrength, _ZN5CFire22CreateFxSysForStrengthEP5RwV3dP11RwMatrixTag, void, RwV3d* vecPosition, RwMatrix* parentMat)
    DECL_THISCALL_TAIL(CreateFxSysForStrength, vecPosition, parentMat)

DECL_CLASS_END()
CHECKSIZE(CFire, 0x28, 0x38);  // 64-bit from the IDB; 32-bit measured from this layout


#endif // __AML_PSDK_SAFIRE_H
