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

DECL_CLASS_BASED(CColSphere, CSphere)
    // Member functions
    DECL_THISCALL_HEAD(Set, _ZN10CColSphere3SetEfRK7CVectorhh, void, float radius, CVector const& center, u8 material, u8 piece)
    DECL_THISCALL_TAIL(Set, radius, center, material, piece)
    DECL_THISCALL_HEAD(IntersectRay, _ZNK10CColSphere12IntersectRayERK7CVectorS2_RS0_S3_, bool, CVector const& rayStart, CVector const& rayEnd, CVector& point1, CVector& point2)
    DECL_THISCALL_TAIL(IntersectRay, rayStart, rayEnd, point1, point2)

    // Member values
    u8 m_nMaterial;
    u8 m_nPiece;
DECL_CLASS_END()
CHECKSIZE(CColSphere, 0x14, 0x14);

DECL_CLASS_BASED(CColBox, CBox)
    // Member functions
    DECL_THISCALL_HEAD(Set, _ZN7CColBox3SetERK7CVectorS2_hh, void, CVector const& vecMin, CVector const& vecMax, u8 material, u8 piece)
    DECL_THISCALL_TAIL(Set, vecMin, vecMax, material, piece)
    DECL_THISCALL_NAMED_HEAD(Assign, operator=, _ZN7CColBoxaSERKS_, CColBox&, CColBox const& box)
    DECL_THISCALL_TAIL(Assign, box)

    // Member values
    u8 m_nMaterial;
    u8 m_nPiece;
DECL_CLASS_END()
CHECKSIZE(CColBox, 0x1C, 0x1C);

DECL_CLASS(CColPoint)
    CColPoint() : m_nSurfaceTypeA(0), m_nPieceTypeA(0), m_nSurfaceTypeB(0), m_nPieceTypeB(0), m_fDepth(0.0f) {}

    // Member functions
    // Native assignment leaves depth unchanged.
    DECL_THISCALL_NAMED_HEAD(Assign, operator=, _ZN9CColPointaSERKS_, CColPoint&, CColPoint const& point)
    DECL_THISCALL_TAIL(Assign, point)

    inline CVector& GetPosition() { return m_vecPoint; }
    inline CVector const& GetPosition() const { return m_vecPoint; }
    inline CVector& GetNormal() { return m_vNormal; }
    inline CVector const& GetNormal() const { return m_vNormal; }

    // Member values
    CVector m_vecPoint;
    u32 : 32;
    CVector m_vNormal;
    u32 : 32;
    u8 m_nSurfaceTypeA;
    u8 m_nPieceTypeA;
    u8 m_nSurfaceTypeB;
    u8 m_nPieceTypeB;
    float m_fDepth;
DECL_CLASS_END()
CHECKSIZE(CColPoint, 0x28, 0x28);

struct CColTriangle
{
    inline void Set(u16 vertA, u16 vertB, u16 vertC, u8 material)
    {
        m_nVertA = vertA;
        m_nVertB = vertB;
        m_nVertC = vertC;
        m_nMaterial = material;
    }

    u16 m_nVertA;
    u16 m_nVertB;
    u16 m_nVertC;
    u8 m_nMaterial;
    u8 : 8;
};
CHECKSIZE(CColTriangle, 0x8, 0x8);

DECL_CLASS(CColTrianglePlane)
    // Member functions
    DECL_THISCALL_HEAD(Set, _ZN17CColTrianglePlane3SetEPK16CompressedVectorR12CColTriangle, void, CVector const* vertices, CColTriangle& triangle)
    DECL_THISCALL_TAIL(Set, vertices, triangle)

    inline CVector const& GetNormal() const { return m_vecNormal; }
    inline float GetNormalOffset() const { return m_fDistance; }

    // Member values
    CVector m_vecNormal;
    float m_fDistance;
    u8 m_nOrientation;
DECL_CLASS_END()
CHECKSIZE(CColTrianglePlane, 0x14, 0x14);

struct CStoredCollPoly
{
    CStoredCollPoly() : m_bIsActual(false) {}

    CVector m_aVertices[3];
    bool m_bIsActual;
};
CHECKSIZE(CStoredCollPoly, 0x28, 0x28);

template<class T> struct CLink;

DECL_CLASS(CColModel)
    // Construct/Deconstruct functions
    DECL_CTORCALL(CColModel, _ZN9CColModelC2Ev);
    DECL_DTORCALL(CColModel, _ZN9CColModelD2Ev);
    #ifdef AML64
        DECL_NEWCALL(CColModel, _ZN9CColModelnwEm);
    #else
        DECL_NEWCALL(CColModel, _ZN9CColModelnwEj);
    #endif
    DECL_DLCALL(CColModel, _ZN9CColModeldlEPv);

    // Native assignment can overrun its box array.
    CColModel(CColModel const&) = delete;
    CColModel& operator=(CColModel const&) = delete;

    // Member functions
    DECL_THISCALL_SIMPLE(RemoveCollisionVolumes, _ZN9CColModel22RemoveCollisionVolumesEv, void);
    DECL_THISCALL_SIMPLE(CalculateTrianglePlanes, _ZN9CColModel23CalculateTrianglePlanesEv, void);
    DECL_THISCALL_SIMPLE(RemoveTrianglePlanes, _ZN9CColModel20RemoveTrianglePlanesEv, void);
    DECL_THISCALL_HEAD(GetTrianglePoint, _ZNK9CColModel16GetTrianglePointER7CVectori, void, CVector& point, i32 vertex)
    DECL_THISCALL_TAIL(GetTrianglePoint, point, vertex)
    DECL_THISCALL_HEAD(SetLinkPtr, _ZN9CColModel10SetLinkPtrEP5CLinkIPS_E, void, CLink<CColModel*>* link)
    DECL_THISCALL_TAIL(SetLinkPtr, link)
    DECL_THISCALL_SIMPLE(GetLinkPtr, _ZN9CColModel10GetLinkPtrEv, CLink<CColModel*>*);

    // Member values
    CSphere m_boundSphere;
    CBox m_boundBox;
    i16 m_nNumSpheres;
    i16 m_nNumBoxes;
    i16 m_nNumTriangles;
    i8 m_nNumLines;
    u8 m_nColStoreIndex;
    bool m_bOwnsCollisionVolumes;
    CColSphere* m_pSpheres;
    CColLine* m_pLines;
    CColBox* m_pBoxes;
    CVector* m_pVertices;
    CColTriangle* m_pTriangles;
    CColTrianglePlane* m_pTrianglePlanes;
DECL_CLASS_END()
CHECKSIZE(CColModel, 0x4C, 0x68);

#endif // __AML_PSDK_VCCOLMODEL_H
