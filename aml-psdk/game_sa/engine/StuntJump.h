#ifndef __AML_PSDK_SASTUNTJUMP_H
#define __AML_PSDK_SASTUNTJUMP_H

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/gta_base/Vector.h>
#include <aml-psdk/game_sa/other/Pools.h>

DECL_CLASS(CBoundBox)
    // Member functions
    DECL_THISCALL_HEAD(IsPointWithin, _ZN9CBoundBox13IsPointWithinERK7CVector, bool, CVector const& vecTest)
    DECL_THISCALL_TAIL(IsPointWithin, vecTest)

    // Member values
    CVector m_vecMin;
    CVector m_vecMax;
DECL_CLASS_END()
CHECKSIZE(CBoundBox, 0x18, 0x18);

DECL_CLASS(CStuntJump)
    // Member values
    CBoundBox m_bbStart;
    CBoundBox m_bbEnd;
    CVector m_vecCamera;
    i32 m_iScore;
    bool m_bPassed;
    bool m_bFound;
DECL_CLASS_END()
CHECKSIZE(CStuntJump, 0x44, 0x44);

typedef CPool<CStuntJump, CStuntJump> CStuntJumpPool;

DECL_CLASS(CStuntJumpManager)
    // Member functions
    DECL_FASTCALL_SIMPLE(Init, _ZN17CStuntJumpManager4InitEv, void);
    DECL_FASTCALL_SIMPLE(Shutdown, _ZN17CStuntJumpManager8ShutdownEv, void);
    DECL_FASTCALL_SIMPLE(ShutdownForRestart, _ZN17CStuntJumpManager18ShutdownForRestartEv, void);
    DECL_FASTCALL_SIMPLE(Update, _ZN17CStuntJumpManager6UpdateEv, void);
    DECL_FASTCALL_SIMPLE(Render, _ZN17CStuntJumpManager6RenderEv, void);
    DECL_FASTCALL_SIMPLE(AddOne, _ZN17CStuntJumpManager6AddOneERK9CBoundBoxS2_RK7CVectori, i32, CBoundBox const& r_bbStart, CBoundBox const& r_bbEnd, CVector const& r_vecCamera, i32 iScore);
    DECL_FASTCALL_SIMPLE(SetActive, _ZN17CStuntJumpManager9SetActiveEb, void, bool bNewState);
    DECL_FASTCALL_SIMPLE(Save, _ZN17CStuntJumpManager4SaveEv, bool);
    DECL_FASTCALL_SIMPLE(Load, _ZN17CStuntJumpManager4LoadEv, bool);

    enum JumpState
    {
        JUMP_INACTIVE = 0,
        JUMP_JUMPING = 1,
        JUMP_LANDED = 2,
    };

    // STATIC values
    DECL_OBJECT_PLT(CStuntJumpPool*, mp_poolStuntJumps, BYBIT(0x678BF4, 0x84F810));
    DECL_OBJECT_PLT(CStuntJump*, mp_ActiveStuntJump, BYBIT(0x678E48, 0x84FCB8));
    DECL_VALUE_PLT_BOOL(m_bActive, BYBIT(0x679800, 0x851008));
    DECL_VALUE_PLT_BOOL(m_bHitReward, BYBIT(0x67650C, 0x84AA70));
    DECL_VALUE_PLT_I32(m_iTimer, BYBIT(0x677E88, 0x84DD30));
    DECL_VALUE_PLT_I32(m_iNumCompleted, BYBIT(0x677328, 0x84C688));
    DECL_VALUE_PLT_I32(m_iNumJumps, BYBIT(0x6787F8, 0x84F018));
    DECL_OBJECT_PLT(JumpState, m_jumpState, BYBIT(0x676428, 0x84A8A8));

DECL_CLASS_END()
CHECKSIZE(CStuntJumpManager, 0x1, 0x1);

#endif // __AML_PSDK_SASTUNTJUMP_H
