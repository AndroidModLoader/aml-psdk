#ifndef __AML_PSDK_VCFIRE_H
#define __AML_PSDK_VCFIRE_H

#include <aml-psdk/game_vc/plugin.h>
#include <aml-psdk/gta_base/Vector.h>

struct CEntity;

DECL_CLASS(CFire)
    // Construct/Deconstruct functions
    DECL_CTORCALL(CFire, _ZN5CFireC2Ev);
    DECL_DTORCALL(CFire, _ZN5CFireD2Ev);

    // Member functions
    DECL_THISCALL_SIMPLE(ProcessFire, _ZN5CFire11ProcessFireEv, void);
    DECL_THISCALL_SIMPLE(Extinguish, _ZN5CFire10ExtinguishEv, void);
    DECL_THISCALL_SIMPLE(ReportThisFire, _ZN5CFire14ReportThisFireEv, void);

    // Member values
    bool m_bActive;
    bool m_bCreatedByScript;
    u8 m_bMoves;
    bool m_bMakesNoise;
    CVector m_vecPosition;
    CEntity* m_pEntityTarget;
    CEntity* m_pEntityCreator;
    u32 m_nTimeToBurn;
    u32 m_uShadowTimer;
    u32 m_uPeriodTimer;
    float m_fParticleSize;
    float m_fStrength;
    bool m_bBeingExtinguished;
DECL_CLASS_END()
CHECKSIZE(CFire, 0x30, 0x38);

DECL_CLASS(CFireManager)
    // Construct/Deconstruct functions
    DECL_CTORCALL(CFireManager, _ZN12CFireManagerC2Ev);
    DECL_DTORCALL(CFireManager, _ZN12CFireManagerD2Ev);

    // Member functions
    DECL_THISCALL_SIMPLE(Update, _ZN12CFireManager6UpdateEv, void);
    DECL_THISCALL_SIMPLE(GetNextFreeFire, _ZN12CFireManager15GetNextFreeFireEv, CFire*);
    DECL_THISCALL_HEAD(FindNearestFire, _ZN12CFireManager15FindNearestFireE7CVectorPf, CFire*, CVector position, float* distance)
    DECL_THISCALL_TAIL(FindNearestFire, position, distance)
    DECL_THISCALL_HEAD(FindFurthestFire_NeverMindFireMen, _ZN12CFireManager33FindFurthestFire_NeverMindFireMenE7CVectorff, CFire*, CVector position, float minDistance, float maxDistance)
    DECL_THISCALL_TAIL(FindFurthestFire_NeverMindFireMen, position, minDistance, maxDistance)
    DECL_THISCALL_NAMED_HEAD(StartFire1, StartFire, _ZN12CFireManager9StartFireE7CVectorfh, void, CVector position, float size, u8 moves)
    DECL_THISCALL_TAIL(StartFire1, position, size, moves)
    DECL_THISCALL_NAMED_HEAD(StartFire2, StartFire, _ZN12CFireManager9StartFireEP7CEntityS1_fh, CFire*, CEntity* target, CEntity* creator, float size, u8 moves)
    DECL_THISCALL_TAIL(StartFire2, target, creator, size, moves)
    DECL_THISCALL_HEAD(StartScriptFire, _ZN12CFireManager15StartScriptFireERK7CVectorP7CEntityfh, i32, CVector const& position, CEntity* target, float size, u8 moves)
    DECL_THISCALL_TAIL(StartScriptFire, position, target, size, moves)
    DECL_THISCALL_HEAD(ExtinguishPoint, _ZN12CFireManager15ExtinguishPointE7CVectorf, void, CVector position, float radius)
    DECL_THISCALL_TAIL(ExtinguishPoint, position, radius)
    DECL_THISCALL_HEAD(ExtinguishPointWithWater, _ZN12CFireManager24ExtinguishPointWithWaterE7CVectorf, bool, CVector position, float radius)
    DECL_THISCALL_TAIL(ExtinguishPointWithWater, position, radius)
    DECL_THISCALL_HEAD(IsScriptFireExtinguished, _ZN12CFireManager24IsScriptFireExtinguishedEs, bool, i16 index)
    DECL_THISCALL_TAIL(IsScriptFireExtinguished, index)
    DECL_THISCALL_HEAD(RemoveScriptFire, _ZN12CFireManager16RemoveScriptFireEs, void, i16 index)
    DECL_THISCALL_TAIL(RemoveScriptFire, index)
    DECL_THISCALL_SIMPLE(RemoveAllScriptFires, _ZN12CFireManager20RemoveAllScriptFiresEv, void);
    DECL_THISCALL_HEAD(SetScriptFireAudio, _ZN12CFireManager18SetScriptFireAudioEsb, void, i16 index, bool enabled)
    DECL_THISCALL_TAIL(SetScriptFireAudio, index, enabled)

    // Member values
    u32 m_nTotalFires;
    CFire m_aFires[40];
DECL_CLASS_END()
CHECKSIZE(CFireManager, 0x784, 0x8C8);

DECL_OBJECT_PLT_GLOBAL(CFireManager, gFireManager, BYBIT(0x395528, 0x578AB8));
#define gFireManager gFireManager()

#endif // __AML_PSDK_VCFIRE_H
