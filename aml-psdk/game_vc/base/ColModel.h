#ifndef __AML_PSDK_VCCOLMODEL_H
#define __AML_PSDK_VCCOLMODEL_H

#include <aml-psdk/game_vc/plugin.h>
#include <aml-psdk/gta_base/Vector.h>

DECL_CLASS(CColLine)
    CColLine() {}
    DECL_CTORCALL_ARG_HEAD(CColLine, _ZN8CColLineC2ERK7CVectorS2_, CVector const& start, CVector const& end)
    DECL_CTORCALL_ARG_TAIL(start, end)

    // Member functions
    DECL_THISCALL_HEAD(Set, _ZN8CColLine3SetERK7CVectorS2_, void, CVector const& start, CVector const& end)
    DECL_THISCALL_TAIL(Set, start, end)

    inline CVector GetDirection() const { return m_vecEnd - m_vecStart; }
    inline float GetLength() const { return GetDirection().Magnitude(); }
    inline CVector GetPoint(float progress) const { return CVector::Lerp(m_vecStart, m_vecEnd, progress); }

    // Member values
    CVector m_vecStart;
    u32 : 32;
    CVector m_vecEnd;
    u32 : 32;
DECL_CLASS_END()
CHECKSIZE(CColLine, 0x20, 0x20);

DECL_CLASS(CBox)
    CBox() {}
    CBox(CVector const& vecMin, CVector const& vecMax) : m_vecMin(vecMin), m_vecMax(vecMax) {}

    // Member functions
    DECL_THISCALL_HEAD(Set, _ZN4CBox3SetERK7CVectorS2_, void, CVector const& vecMin, CVector const& vecMax)
    DECL_THISCALL_TAIL(Set, vecMin, vecMax)

    inline bool IsInvalid() const
    {
        return m_vecMin.x > m_vecMax.x || m_vecMin.y > m_vecMax.y || m_vecMin.z > m_vecMax.z;
    }
    inline CVector GetCenter() const { return (m_vecMin + m_vecMax) * 0.5f; }
    inline CVector GetSize() const { return m_vecMax - m_vecMin; }
    inline bool IsPointInside(CVector const& point) const
    {
        return point.x >= m_vecMin.x && point.x <= m_vecMax.x &&
            point.y >= m_vecMin.y && point.y <= m_vecMax.y &&
            point.z >= m_vecMin.z && point.z <= m_vecMax.z;
    }
    inline bool DoesIntersect(CBox const& box) const
    {
        return !IsInvalid() && !box.IsInvalid() &&
            m_vecMin.x <= box.m_vecMax.x && m_vecMax.x >= box.m_vecMin.x &&
            m_vecMin.y <= box.m_vecMax.y && m_vecMax.y >= box.m_vecMin.y &&
            m_vecMin.z <= box.m_vecMax.z && m_vecMax.z >= box.m_vecMin.z;
    }
    inline bool Contains(CBox const& box) const
    {
        return !IsInvalid() && !box.IsInvalid() && IsPointInside(box.m_vecMin) && IsPointInside(box.m_vecMax);
    }
    inline bool GetIntersection(CBox const& box, CBox& result) const
    {
        if(IsInvalid() || box.IsInvalid()) return false;
        CBox intersection(
            CVector(fmaxf(m_vecMin.x, box.m_vecMin.x), fmaxf(m_vecMin.y, box.m_vecMin.y), fmaxf(m_vecMin.z, box.m_vecMin.z)),
            CVector(fminf(m_vecMax.x, box.m_vecMax.x), fminf(m_vecMax.y, box.m_vecMax.y), fminf(m_vecMax.z, box.m_vecMax.z)));
        if(intersection.IsInvalid()) return false;
        result = intersection;
        return true;
    }
    inline CVector GetClosestPoint(CVector const& point) const
    {
        return CVector(
            fmaxf(m_vecMin.x, fminf(point.x, m_vecMax.x)),
            fmaxf(m_vecMin.y, fminf(point.y, m_vecMax.y)),
            fmaxf(m_vecMin.z, fminf(point.z, m_vecMax.z)));
    }
    inline void StretchToPoint(CVector const& point)
    {
        if(IsInvalid())
        {
            m_vecMin = m_vecMax = point;
            return;
        }
        m_vecMin.x = fminf(m_vecMin.x, point.x);
        m_vecMin.y = fminf(m_vecMin.y, point.y);
        m_vecMin.z = fminf(m_vecMin.z, point.z);
        m_vecMax.x = fmaxf(m_vecMax.x, point.x);
        m_vecMax.y = fmaxf(m_vecMax.y, point.y);
        m_vecMax.z = fmaxf(m_vecMax.z, point.z);
    }
    inline void Translate(CVector const& offset)
    {
        CVector translation = offset;
        m_vecMin += translation;
        m_vecMax += translation;
    }
    inline void Grow(float amount)
    {
        CVector margin(amount);
        m_vecMin -= margin;
        m_vecMax += margin;
    }

    // Member values
    CVector m_vecMin;
    CVector m_vecMax;
DECL_CLASS_END()
CHECKSIZE(CBox, 0x18, 0x18);

DECL_CLASS(CSphere)
    CSphere() : m_fRadius(0.0f) {}
    CSphere(float radius, CVector const& center) : m_vecCentre(center), m_fRadius(radius) {}

    // Member functions
    DECL_THISCALL_HEAD(Set, _ZN7CSphere3SetEfRK7CVector, void, float radius, CVector const& center)
    DECL_THISCALL_TAIL(Set, radius, center)

    inline bool InSphere(CVector const& point) const
    {
        return m_fRadius >= 0.0f && (point - m_vecCentre).MagnitudeSqr() <= SQ(m_fRadius);
    }
    inline bool Contains(CSphere const& sphere) const
    {
        if(m_fRadius < 0.0f || sphere.m_fRadius < 0.0f) return false;
        float radius = m_fRadius - sphere.m_fRadius;
        return radius >= 0.0f && (sphere.m_vecCentre - m_vecCentre).MagnitudeSqr() <= SQ(radius);
    }
    inline bool DoesIntersect(CSphere const& sphere) const
    {
        return m_fRadius >= 0.0f && sphere.m_fRadius >= 0.0f &&
            (sphere.m_vecCentre - m_vecCentre).MagnitudeSqr() <= SQ(m_fRadius + sphere.m_fRadius);
    }
    inline bool DoesIntersect(CBox const& box) const
    {
        return m_fRadius >= 0.0f && !box.IsInvalid() &&
            (box.GetClosestPoint(m_vecCentre) - m_vecCentre).MagnitudeSqr() <= SQ(m_fRadius);
    }
    inline CVector GetClosestPoint(CVector const& point) const
    {
        if(m_fRadius <= 0.0f) return m_vecCentre;
        CVector offset = point - m_vecCentre;
        float distanceSqr = offset.MagnitudeSqr();
        if(distanceSqr <= SQ(m_fRadius)) return point;
        return m_vecCentre + offset * (m_fRadius / sqrtf(distanceSqr));
    }
    inline void Translate(CVector const& offset) { m_vecCentre += offset; }
    inline void Grow(float amount) { m_fRadius += amount; }

    // Member values
    CVector m_vecCentre;
    float m_fRadius;
DECL_CLASS_END()
CHECKSIZE(CSphere, 0x10, 0x10);

#endif // __AML_PSDK_VCCOLMODEL_H
