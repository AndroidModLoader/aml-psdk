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


DECL_CLASS(CFireManager)
    // Construct/Deconstruct functions
    DECL_CTORCALL(CFireManager, _ZN12CFireManagerC2Ev);
    DECL_DTORCALL(CFireManager, _ZN12CFireManagerD2Ev);

    // Member functions
    DECL_THISCALL_SIMPLE(Init, _ZN12CFireManager4InitEv, void);
    DECL_THISCALL_SIMPLE(Shutdown, _ZN12CFireManager8ShutdownEv, void);
    DECL_THISCALL_HEAD(GetNextFreeFire, _ZN12CFireManager15GetNextFreeFireEh, CFire*, u8 bCanOverwriteAnExistingFire)
    DECL_THISCALL_TAIL(GetNextFreeFire, bCanOverwriteAnExistingFire)

    DECL_THISCALL_SIMPLE(GetNumOfNonScriptFires, _ZN12CFireManager22GetNumOfNonScriptFiresEv, u16);
    DECL_THISCALL_HEAD(FindNearestFire, _ZN12CFireManager15FindNearestFireERK7CVectorbb, CFire*, CVector const& vSearchPosition, bool bRequireUnattendedFire, bool bRequireNonScriptFire)
    DECL_THISCALL_TAIL(FindNearestFire, vSearchPosition, bRequireUnattendedFire, bRequireNonScriptFire)

    DECL_THISCALL_NAMED_HEAD(StartFire1, StartFire, _ZN12CFireManager9StartFireE7CVectorfhP7CEntityjah, CFire*, CVector arg0, float arg1, u8 arg2, CEntity* arg3, u32 arg4, i8 arg5, u8 arg6)
    DECL_THISCALL_TAIL(StartFire1, arg0, arg1, arg2, arg3, arg4, arg5, arg6)

    DECL_THISCALL_NAMED_HEAD(StartFire2, StartFire, _ZN12CFireManager9StartFireEP7CEntityS1_fhja, CFire*, CEntity* pBurningEntity, CEntity* pStartedFireEntity, float fFireSize, u8 bExtinguishEnabled, u32 ArgBurnTime, i8 NumGenerationsAllowed)
    DECL_THISCALL_TAIL(StartFire2, pBurningEntity, pStartedFireEntity, fFireSize, bExtinguishEnabled, ArgBurnTime, NumGenerationsAllowed)

    DECL_THISCALL_HEAD(StartScriptFire, _ZN12CFireManager15StartScriptFireERK7CVectorP7CEntityfhai, i32, CVector const& Coors, CEntity* pEntity, float fFireSize, u8 bExtinguishEnabled, i8 NumGenerationsAllowed, i32 Strength)
    DECL_THISCALL_TAIL(StartScriptFire, Coors, pEntity, fFireSize, bExtinguishEnabled, NumGenerationsAllowed, Strength)

    DECL_THISCALL_SIMPLE(Update, _ZN12CFireManager6UpdateEv, void);
    DECL_THISCALL_HEAD(ExtinguishPoint, _ZN12CFireManager15ExtinguishPointE7CVectorf, void, CVector Coors, float Radius)
    DECL_THISCALL_TAIL(ExtinguishPoint, Coors, Radius)

    DECL_THISCALL_HEAD(ExtinguishPointWithWater, _ZN12CFireManager24ExtinguishPointWithWaterE7CVectorff, bool, CVector Coors, float Radius, float fStrength)
    DECL_THISCALL_TAIL(ExtinguishPointWithWater, Coors, Radius, fStrength)

    DECL_THISCALL_HEAD(IsScriptFireExtinguished, _ZN12CFireManager24IsScriptFireExtinguishedEs, u8, i16 FireNum)
    DECL_THISCALL_TAIL(IsScriptFireExtinguished, FireNum)

    DECL_THISCALL_HEAD(RemoveScriptFire, _ZN12CFireManager16RemoveScriptFireEs, void, i16 FireNum)
    DECL_THISCALL_TAIL(RemoveScriptFire, FireNum)

    DECL_THISCALL_SIMPLE(RemoveAllScriptFires, _ZN12CFireManager20RemoveAllScriptFiresEv, void);
    DECL_THISCALL_SIMPLE(ClearAllScriptFireFlags, _ZN12CFireManager23ClearAllScriptFireFlagsEv, void);
    DECL_THISCALL_HEAD(SetScriptFireAudio, _ZN12CFireManager18SetScriptFireAudioEsb, void, i16 FireNum, bool bAudioFlag)
    DECL_THISCALL_TAIL(SetScriptFireAudio, FireNum, bAudioFlag)

    DECL_THISCALL_HEAD(GetScriptFireCoords, _ZN12CFireManager19GetScriptFireCoordsEs, CVector&, i16 FireNum)
    DECL_THISCALL_TAIL(GetScriptFireCoords, FireNum)

    DECL_THISCALL_HEAD(GetNumFiresInRange, _ZN12CFireManager18GetNumFiresInRangeEP7CVectorf, i32, CVector* pos, float range)
    DECL_THISCALL_TAIL(GetNumFiresInRange, pos, range)

    DECL_THISCALL_HEAD(GetNumFiresInArea, _ZN12CFireManager17GetNumFiresInAreaEffffff, i32, float MinX, float MinY, float MinZ, float MaxX, float MaxY, float MaxZ)
    DECL_THISCALL_TAIL(GetNumFiresInArea, MinX, MinY, MinZ, MaxX, MaxY, MaxZ)

    DECL_THISCALL_SIMPLE(PlentyFiresAvailable, _ZN12CFireManager20PlentyFiresAvailableEv, bool);

    // Member values
    union
    {
        CFire m_aFires[60];
    };
    i32 m_nMaxFireGenerationsAllowed;
DECL_CLASS_END()
CHECKSIZE(CFireManager, 0x964, 0xD28);

DECL_OBJECT_PLT_GLOBAL(CFireManager, gFireManager, BYBIT(0x676448, 0x84A8E8));
#define gFireManager gFireManager()

#endif // __AML_PSDK_SAFIRE_H
