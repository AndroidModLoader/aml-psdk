#ifndef __AML_PSDK_SASCRIPTED2DEFFECTS_H
#define __AML_PSDK_SASCRIPTED2DEFFECTS_H

#include <aml-psdk/game_sa/engine/2dEffect.h>

DECL_CLASS(CEffectUserList)
    enum
    {
        MAX_NUM_USER_TYPES = 4
    };

    enum
    {
        EMPTY_SLOT = -1,
        SLOT_IS_PEDTYPE = -2
    };

    // Member values
    i32 m_userTypes[4];
    i32 m_userTypesByPedType[4];
    bool m_bUseList;
DECL_CLASS_END()
CHECKSIZE(CEffectUserList, 0x24, 0x24);

DECL_CLASS(CScriptedEffectPair)
    // Construct/Deconstruct functions
    DECL_CTORCALL(CScriptedEffectPair, _ZN19CScriptedEffectPairC2Ev);
    DECL_DTORCALL(CScriptedEffectPair, _ZN19CScriptedEffectPairD2Ev);

    // Member functions
    DECL_THISCALL_SIMPLE(Flush, _ZN19CScriptedEffectPair5FlushEv, void);

    // Member values
    i32 m_iEffect1;
    i32 m_iWaitingTask1;
    i32 m_iPartnerTask1;
    i32 m_iPartnerUseMode1;
    i32 m_iEffect2;
    i32 m_iWaitingTask2;
    i32 m_iPartnerTask2;
    i32 m_iPartnerUseMode2;
    bool m_bUsePartnerImmediately;
DECL_CLASS_END()
CHECKSIZE(CScriptedEffectPair, 0x24, 0x24);

DECL_CLASS(CScriptedEffectPairs)
    enum
    {
        MAX_NUM_EFFECT_PAIRS = 4
    };

    // Construct/Deconstruct functions
    DECL_CTORCALL(CScriptedEffectPairs, _ZN20CScriptedEffectPairsC2Ev);
    DECL_DTORCALL(CScriptedEffectPairs, _ZN20CScriptedEffectPairsD2Ev);

    // Member functions
    DECL_THISCALL_HEAD(AddPair, _ZN20CScriptedEffectPairs7AddPairERK19CScriptedEffectPair, void, CScriptedEffectPair const& pair)
    DECL_THISCALL_TAIL(AddPair, pair)
    DECL_THISCALL_SIMPLE(Flush, _ZN20CScriptedEffectPairs5FlushEv, void);

    // Member values
    i32 m_iNoOfPairs;
    CScriptedEffectPair m_pairs[4];
DECL_CLASS_END()
CHECKSIZE(CScriptedEffectPairs, 0x94, 0x94);

DECL_CLASS(CScripted2dEffects)
    enum
    {
        MAX_NUM_SCRIPTED_EFFECTS = 64
    };

    // STATIC functions
    DECL_FASTCALL_SIMPLE(GetEffectPairs, _ZN18CScripted2dEffects14GetEffectPairsEPK9C2dEffect, CScriptedEffectPairs const&, C2dEffect const* effect);
    DECL_FASTCALL_SIMPLE(AddScripted2DEffect, _ZN18CScripted2dEffects19AddScripted2DEffectEf, i32, float const radius);
    DECL_FASTCALL_SIMPLE(ReturnScripted2DEffect, _ZN18CScripted2dEffects22ReturnScripted2DEffectEi, void, i32 index);
    DECL_FASTCALL_SIMPLE(GetIndex, _ZN18CScripted2dEffects8GetIndexEPK9C2dEffect, i32, C2dEffect const* effect);
    DECL_FASTCALL_SIMPLE(Init, _ZN18CScripted2dEffects4InitEv, void);
    DECL_FASTCALL_SIMPLE(Save, _ZN18CScripted2dEffects4SaveEv, void);
    DECL_FASTCALL_SIMPLE(Load, _ZN18CScripted2dEffects4LoadEv, void);

    // STATIC values
    DECL_OBJECT_ARRAY_PLT(bool, ms_activated, BYBIT(0x6760e0, 0x84a230));
    DECL_OBJECT_ARRAY_PLT(u16, ScriptReferenceIndex, BYBIT(0x677460, 0x84c8f8));
    DECL_OBJECT_ARRAY_PLT(i32, ms_effectSequenceTaskIDs, BYBIT(0x6766ac, 0x84adb0));
    DECL_OBJECT_ARRAY_PLT(CEffectUserList, ms_userLists, BYBIT(0x676514, 0x84aa80));
    DECL_OBJECT_ARRAY_PLT(C2dEffect, ms_effects, BYBIT(0x6786dc, 0x84ede0));
    DECL_OBJECT_ARRAY_PLT(CScriptedEffectPairs, ms_effectPairs, BYBIT(0x6777ec, 0x84d000));
    DECL_OBJECT_ARRAY_PLT(bool, ms_useAgainFlags, BYBIT(0x679f00, 0x851e10));
    DECL_OBJECT_ARRAY_PLT(float, ms_radii, BYBIT(0x676578, 0x84ab48));

DECL_CLASS_END()
CHECKSIZE(CScripted2dEffects, 0x1, 0x1);

#endif // __AML_PSDK_SASCRIPTED2DEFFECTS_H
