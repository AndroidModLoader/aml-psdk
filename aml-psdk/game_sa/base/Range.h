#ifndef __AML_PSDK_SARANGE_H
#define __AML_PSDK_SARANGE_H

#include "../plugin.h"
#include "../../gta_base/Vector.h"

DECL_CLASS(CRange2D)
    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CRange2D, _ZN8CRange2DC2E9CVector2DS0_, CVector2D topLeft, CVector2D botRight)
    DECL_CTORCALL_ARG_TAIL(topLeft, botRight)
    DECL_DTORCALL(CRange2D, _ZN8CRange2DD2Ev);

    // Member functions
    DECL_THISCALL_HEAD(IsInRange, _ZN8CRange2D9IsInRangeE9CVector2D, bool, CVector2D point)
    DECL_THISCALL_TAIL(IsInRange, point)
    DECL_THISCALL_SIMPLE(GetRandomPointInRange, _ZN8CRange2D21GetRandomPointInRangeEv, CVector2D);
    DECL_THISCALL_HEAD(DebugShowRange, _ZN8CRange2D14DebugShowRangeEfi, void, float z, i32 colour)
    DECL_THISCALL_TAIL(DebugShowRange, z, colour)

    inline void SetTopLeft(CVector2D point) { m_vec2DTopLeft = point; }
    inline CVector2D GetTopLeft() { return m_vec2DTopLeft; }
    inline void SetBotRight(CVector2D point) { m_vec2DBotRight = point; }
    inline CVector2D GetBotRight() { return m_vec2DBotRight; }

    // Member values
    CVector2D m_vec2DTopLeft;
    CVector2D m_vec2DBotRight;
DECL_CLASS_END()
CHECKSIZE(CRange2D, 0x10, 0x10);

DECL_CLASS(CRange3D)
    // Construct/Deconstruct functions
    CRange3D() {}
    DECL_CTORCALL_ARG_HEAD(CRange3D, _ZN8CRange3DC2E7CVectorS0_, CVector topLeft, CVector botRight)
    DECL_CTORCALL_ARG_TAIL(topLeft, botRight)

    // Member functions
    DECL_THISCALL_HEAD(IsInRange, _ZN8CRange3D9IsInRangeE7CVector, bool, CVector point)
    DECL_THISCALL_TAIL(IsInRange, point)
    DECL_THISCALL_SIMPLE(GetRandomPointInRange, _ZN8CRange3D21GetRandomPointInRangeEv, CVector);
    DECL_THISCALL_HEAD(DebugShowRange, _ZN8CRange3D14DebugShowRangeEi, void, i32 colour)
    DECL_THISCALL_TAIL(DebugShowRange, colour)

    inline void SetTopLeft(CVector point) { m_vecTopLeft = point; }
    inline CVector GetTopLeft() { return m_vecTopLeft; }
    inline void SetBotRight(CVector point) { m_vecBotRight = point; }
    inline CVector GetBotRight() { return m_vecBotRight; }

    // Member values
    CVector m_vecTopLeft;
    CVector m_vecBotRight;
DECL_CLASS_END()
CHECKSIZE(CRange3D, 0x18, 0x18);

#endif // __AML_PSDK_SARANGE_H
