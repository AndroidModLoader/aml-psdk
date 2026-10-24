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
    inline bool IsEmpty() const
    {
        return !(m_vec2DTopLeft.x < m_vec2DBotRight.x && m_vec2DTopLeft.y < m_vec2DBotRight.y);
    }
    inline CVector2D GetCenter() const { return (m_vec2DTopLeft + m_vec2DBotRight) * 0.5f; }
    inline CVector2D GetSize() const { return m_vec2DBotRight - m_vec2DTopLeft; }
    inline void Translate(CVector2D offset)
    {
        m_vec2DTopLeft += offset;
        m_vec2DBotRight += offset;
    }
    inline bool DoesIntersect(CRange2D const& range) const
    {
        return !IsEmpty() && !range.IsEmpty() &&
            m_vec2DTopLeft.x < range.m_vec2DBotRight.x && m_vec2DBotRight.x > range.m_vec2DTopLeft.x &&
            m_vec2DTopLeft.y < range.m_vec2DBotRight.y && m_vec2DBotRight.y > range.m_vec2DTopLeft.y;
    }
    inline bool GetIntersection(CRange2D const& range, CRange2D& result) const
    {
        if(IsEmpty() || range.IsEmpty()) return false;
        CVector2D topLeft(fmaxf(m_vec2DTopLeft.x, range.m_vec2DTopLeft.x), fmaxf(m_vec2DTopLeft.y, range.m_vec2DTopLeft.y));
        CVector2D botRight(fminf(m_vec2DBotRight.x, range.m_vec2DBotRight.x), fminf(m_vec2DBotRight.y, range.m_vec2DBotRight.y));
        if(topLeft.x >= botRight.x || topLeft.y >= botRight.y) return false;
        result.m_vec2DTopLeft = topLeft;
        result.m_vec2DBotRight = botRight;
        return true;
    }

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
    inline bool IsEmpty() const
    {
        return !(m_vecTopLeft.x < m_vecBotRight.x && m_vecTopLeft.y < m_vecBotRight.y && m_vecTopLeft.z < m_vecBotRight.z);
    }
    inline CVector GetCenter() const { return (m_vecTopLeft + m_vecBotRight) * 0.5f; }
    inline CVector GetSize() const { return m_vecBotRight - m_vecTopLeft; }
    inline void Translate(CVector offset)
    {
        m_vecTopLeft += offset;
        m_vecBotRight += offset;
    }
    inline bool DoesIntersect(CRange3D const& range) const
    {
        return !IsEmpty() && !range.IsEmpty() &&
            m_vecTopLeft.x < range.m_vecBotRight.x && m_vecBotRight.x > range.m_vecTopLeft.x &&
            m_vecTopLeft.y < range.m_vecBotRight.y && m_vecBotRight.y > range.m_vecTopLeft.y &&
            m_vecTopLeft.z < range.m_vecBotRight.z && m_vecBotRight.z > range.m_vecTopLeft.z;
    }
    inline bool GetIntersection(CRange3D const& range, CRange3D& result) const
    {
        if(IsEmpty() || range.IsEmpty()) return false;
        CVector topLeft(fmaxf(m_vecTopLeft.x, range.m_vecTopLeft.x), fmaxf(m_vecTopLeft.y, range.m_vecTopLeft.y), fmaxf(m_vecTopLeft.z, range.m_vecTopLeft.z));
        CVector botRight(fminf(m_vecBotRight.x, range.m_vecBotRight.x), fminf(m_vecBotRight.y, range.m_vecBotRight.y), fminf(m_vecBotRight.z, range.m_vecBotRight.z));
        if(topLeft.x >= botRight.x || topLeft.y >= botRight.y || topLeft.z >= botRight.z) return false;
        result.m_vecTopLeft = topLeft;
        result.m_vecBotRight = botRight;
        return true;
    }

    // Member values
    CVector m_vecTopLeft;
    CVector m_vecBotRight;
DECL_CLASS_END()
CHECKSIZE(CRange3D, 0x18, 0x18);

#endif // __AML_PSDK_SARANGE_H
