#ifndef __AML_PSDK_SAGENERAL_H
#define __AML_PSDK_SAGENERAL_H

#include <aml-psdk/game_sa/plugin.h>

DECL_CLASS(CGeneral)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(GetAngleBetweenPoints, _ZN8CGeneral21GetAngleBetweenPointsEffff, float, float x1, float y1, float x2, float y2);
    DECL_FASTCALL_SIMPLE(GetRadianAngleBetweenPoints, _ZN8CGeneral27GetRadianAngleBetweenPointsEffff, float, float x1, float y1, float x2, float y2);
    DECL_FASTCALL_SIMPLE(LimitAngle, _ZN8CGeneral10LimitAngleEf, float, float angle);
    DECL_FASTCALL_SIMPLE(LimitRadianAngle, _ZN8CGeneral16LimitRadianAngleEf, float, float angle);
    DECL_FASTCALL_SIMPLE(GetATanOfXY, _ZN8CGeneral11GetATanOfXYEff, float, float x, float y);
    DECL_FASTCALL_SIMPLE(GetNodeHeadingFromVector, _ZN8CGeneral24GetNodeHeadingFromVectorEff, u16, float x, float y);
    DECL_FASTCALL_SIMPLE(SolveQuadratic, _ZN8CGeneral14SolveQuadraticEfffRfS0_, bool, float a, float b, float c, float& x1, float& x2);
DECL_CLASS_END()

#endif // __AML_PSDK_SAGENERAL_H
