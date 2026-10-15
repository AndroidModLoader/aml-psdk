#ifndef __AML_PSDK_SASKIDMARKS_H
#define __AML_PSDK_SASKIDMARKS_H

#include "../plugin.h"
#include "../enum/Collision.h"
#include <aml-psdk/gta_base/Vector.h>

DECL_CLASS(CActiveSkidmark)
    enum
    {
        EMPTY = 0,
        ACTIVE = 1,
        INACTIVE = 2,
    };

    // Member values
    CVector aPoints[16];
    float SidesX[16];
    float SidesY[16];
    u32 ID;
    u32 LastPointStoredTime;
    u32 FadeOutTime;
    u32 RemoveTime;
    eSkidmarkType Type;
    i16 NumPoints;
    u8 Status;
    bool bUpdatedThisFrame;
DECL_CLASS_END()
CHECKSIZE(CActiveSkidmark, 0x158, 0x158);

DECL_CLASS(CSkidmarks)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(Init, _ZN10CSkidmarks4InitEv, void);
    DECL_FASTCALL_SIMPLE(Shutdown, _ZN10CSkidmarks8ShutdownEv, void);
    DECL_FASTCALL_SIMPLE(Clear, _ZN10CSkidmarks5ClearEv, void);
    DECL_FASTCALL_SIMPLE(Update, _ZN10CSkidmarks6UpdateEv, void);
    DECL_FASTCALL_SIMPLE(Render, _ZN10CSkidmarks6RenderEv, void);
    DECL_FASTCALL_SIMPLE(RegisterOne1, _ZN10CSkidmarks11RegisterOneEjRK7CVectorffPbS3_f, void, u32 arg1, CVector const& arg2, float arg3, float arg4, bool* arg5, bool* arg6, float arg7);
    inline static void RegisterOne(u32 arg1, CVector const& arg2, float arg3, float arg4, bool* arg5, bool* arg6, float arg7)
    {
        return RegisterOne1(arg1, arg2, arg3, arg4, arg5, arg6, arg7);
    }
    DECL_FASTCALL_SIMPLE(RegisterOne2, _ZN10CSkidmarks11RegisterOneEjRK7CVectorff13eSkidmarkTypePbf, void, u32 ID, CVector const& Coors, float CarFrontX, float CarFrontY, eSkidmarkType Type, bool* pBloody, float Width);
    inline static void RegisterOne(u32 ID, CVector const& Coors, float CarFrontX, float CarFrontY, eSkidmarkType Type, bool* pBloody, float Width)
    {
        return RegisterOne2(ID, Coors, CarFrontX, CarFrontY, Type, pBloody, Width);
    }

    // STATIC values
    DECL_OBJECT_ARRAY_PLT(CActiveSkidmark, aSkidmarks, BYBIT(0x678070, 0x84E100));
DECL_CLASS_END()

#endif // __AML_PSDK_SASKIDMARKS_H
