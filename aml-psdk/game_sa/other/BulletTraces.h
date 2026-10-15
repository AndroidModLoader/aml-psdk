#ifndef __AML_PSDK_SABULLETTRACES_H
#define __AML_PSDK_SABULLETTRACES_H

#include "../plugin.h"
#include <aml-psdk/gta_base/Vector.h>

struct CEntity;

DECL_CLASS(CBulletTrace)
    // Member functions
    DECL_THISCALL_SIMPLE(Update, _ZN12CBulletTrace6UpdateEv, void);

    // Member values
    CVector m_vecStart;
    CVector m_vecEnd;
    bool m_bExists;
    u32 m_nCreationTime;
    u32 m_nLifeTime;
    float m_fRadius;
    u8 m_nTransparency;
DECL_CLASS_END()
CHECKSIZE(CBulletTrace, 0x2C, 0x2C);

DECL_CLASS(CBulletTraces)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(Init, _ZN13CBulletTraces4InitEv, void);
    DECL_FASTCALL_SIMPLE(AddTrace1, _ZN13CBulletTraces8AddTraceEP7CVectorS1_iP7CEntity, void, CVector* arg1, CVector* arg2, i32 arg3, CEntity* arg4);
    inline static void AddTrace(CVector* arg1, CVector* arg2, i32 arg3, CEntity* arg4)
    {
        return AddTrace1(arg1, arg2, arg3, arg4);
    }
    DECL_FASTCALL_SIMPLE(AddTrace2, _ZN13CBulletTraces8AddTraceEP7CVectorS1_fjh, void, CVector* pStart, CVector* pEnd, float SizeArg, u32 LifeTimeArg, u8 OpaquenessArg);
    inline static void AddTrace(CVector* pStart, CVector* pEnd, float SizeArg, u32 LifeTimeArg, u8 OpaquenessArg)
    {
        return AddTrace2(pStart, pEnd, SizeArg, LifeTimeArg, OpaquenessArg);
    }
    DECL_FASTCALL_SIMPLE(Render, _ZN13CBulletTraces6RenderEv, void);
    DECL_FASTCALL_SIMPLE(Update, _ZN13CBulletTraces6UpdateEv, void);

    // STATIC values
    DECL_OBJECT_ARRAY_PLT(CBulletTrace, aTraces, BYBIT(0x679ABC, 0x851598));
DECL_CLASS_END()

#endif // __AML_PSDK_SABULLETTRACES_H
