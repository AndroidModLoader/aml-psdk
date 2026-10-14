#ifndef __AML_PSDK_SACOLMODEL_H
#define __AML_PSDK_SACOLMODEL_H

#include <aml-psdk/gta_base/Vector.h>
#include "../enum/SurfaceType.h"
#include "Lists.h"

struct CColSphere;
struct CColDisk;
struct CColLine;
struct CColBox;

typedef CVector CollisionVector;
typedef float CollisionFloat;

struct __attribute__((aligned(4))) CColTriangle
{
	int32_t        m_nVertA; // vertex index in vertices array
	int32_t        m_nVertB; // vertex index in vertices array
	int32_t        m_nVertC; // vertex index in vertices array
	unsigned char  m_nMaterial;
	unsigned char  m_nLight;
};
struct __attribute__((aligned(4))) CColTrianglePlane
{
    CollisionVector m_normal;
    CollisionFloat  m_nDistance;
    u8              m_nOrientation;
};

DECL_CLASS(CCollisionData)
    // Construct/Deconstruct functions
    DECL_CTORCALL(CCollisionData, _ZN14CCollisionDataC2Ev);

    short               m_nNumSpheres;
    short               m_nNumBoxes;
    short               m_nNumTriangles;
    union
    {
        signed char     m_nNumLines;
        signed char     m_nNumDisks;
    };
    struct
    {
        unsigned char   bUsesDisks : 1;
        unsigned char   bUsesColModelSections : 1;
        unsigned char   bHasShadowTris : 1;
    } m_nFlags;
    CColSphere         *m_pSpheres;
    CColBox            *m_pBoxes;
    union
    {
        CColLine       *m_pLines;
        CColDisk       *m_pDisks;
    };
    CollisionVector    *m_pVertices;
    CColTriangle       *m_pTriangles;
    CColTrianglePlane  *m_pTrianglePlanes;
    int                 m_nNumShadowTriangles;
    int                 m_nNumShadowVertices;
    CollisionVector    *m_pShadowVertices;
    CColTriangle       *m_pShadowTriangles;
    int32_t            *m_modelSec;

    // Member functions
    DECL_THISCALL_HEAD(Copy, _ZN14CCollisionData4CopyERKS_, CCollisionData&, CCollisionData const& arg0)
    DECL_THISCALL_TAIL(Copy, arg0)
    DECL_THISCALL_SIMPLE(RemoveCollisionVolumes, _ZN14CCollisionData22RemoveCollisionVolumesEv, void);
    DECL_THISCALL_HEAD(GetTrianglePoint, _ZNK14CCollisionData16GetTrianglePointER7CVectori, void, CVector& outVec, i32 vertId)
    DECL_THISCALL_TAIL(GetTrianglePoint, outVec, vertId)
    DECL_THISCALL_HEAD(GetShadTrianglePoint, _ZNK14CCollisionData20GetShadTrianglePointER7CVectori, void, CVector& outVec, i32 vertId)
    DECL_THISCALL_TAIL(GetShadTrianglePoint, outVec, vertId)
    DECL_THISCALL_SIMPLE(CalculateTrianglePlanes, _ZN14CCollisionData23CalculateTrianglePlanesEv, void);
    DECL_THISCALL_SIMPLE(RemoveTrianglePlanes, _ZN14CCollisionData20RemoveTrianglePlanesEv, void);
    DECL_THISCALL_HEAD(SetLinkPtr, _ZN14CCollisionData10SetLinkPtrEP5CLinkIPS_E, void, CLink<CCollisionData *>* link)
    DECL_THISCALL_TAIL(SetLinkPtr, link)
    DECL_THISCALL_SIMPLE(GetLinkPtr, _ZN14CCollisionData10GetLinkPtrEv, CLink<CCollisionData *>*);
    DECL_THISCALL_SIMPLE(GetNoVectors, _ZNK14CCollisionData12GetNoVectorsEv, i32);
    DECL_THISCALL_SIMPLE(GetNoShadVectors, _ZNK14CCollisionData16GetNoShadVectorsEv, i32);
DECL_CLASS_END()

struct ColData
{
    u8 m_nSurfaceType;
    u8 m_nPieceType;
    u8 m_lighting;
};

DECL_CLASS(CBox)
    // Member functions
    DECL_THISCALL_HEAD(Set, _ZN4CBox3SetERK7CVectorS2_, void, CVector const& vecMin, CVector const& vecMax)
    DECL_THISCALL_TAIL(Set, vecMin, vecMax)
    DECL_THISCALL_SIMPLE(Recalc, _ZN4CBox6RecalcEv, void);

    CVector m_vecMin;
    CVector m_vecMax;
    CBox()
    {
        m_vecMin = CVector( 1,  1,  1);
        m_vecMax = CVector(-1, -1, -1);
    }
DECL_CLASS_END()

DECL_CLASS_BASED(CColBox, CBox)
    DECL_THISCALL_NAMED_HEAD(Assign, operator=, _ZN7CColBoxaSERKS_, CColBox&, const CColBox &box)
    DECL_THISCALL_TAIL(Assign, box)

    // Member functions
    DECL_THISCALL_HEAD(Set, _ZN7CColBox3SetERK7CVectorS2_hhh, void, CVector const& sup, CVector const& inf, u8 material, u8 flags, u8 lighting)
    DECL_THISCALL_TAIL(Set, sup, inf, material, flags, lighting)

    ColData m_data;
DECL_CLASS_END()

struct CSphere
{
    CVector m_vecCentre;
    float m_fRadius;

    inline void Set(float fRadius, const CVector &vecCentre)
    {
        m_vecCentre = vecCentre;
        m_fRadius = fRadius;
    }
    inline bool InSphere(CVector& pos)
    {
        return (pos - m_vecCentre).MagnitudeSqr() <= (SQ(m_fRadius));
    }
};

DECL_CLASS_BASED(CColSphere, CSphere)
    // Member functions
    DECL_THISCALL_HEAD(Set, _ZN10CColSphere3SetEfRK7CVectorhhh, void, float radius, CVector const& center, u8 material, u8 flags, u8 lighting)
    DECL_THISCALL_TAIL(Set, radius, center, material, flags, lighting)
    DECL_THISCALL_HEAD(IntersectRay, _ZNK10CColSphere12IntersectRayERK7CVectorS2_RS0_S3_, bool, CVector const& rayStart, CVector const& rayEnd, CVector& intPoint1, CVector& intPoint2)
    DECL_THISCALL_TAIL(IntersectRay, rayStart, rayEnd, intPoint1, intPoint2)
    DECL_THISCALL_HEAD(IntersectEdge, _ZNK10CColSphere13IntersectEdgeERK7CVectorS2_RS0_S3_, bool, CVector const& arg1, CVector const& arg2, CVector& arg3, CVector& arg4)
    DECL_THISCALL_TAIL(IntersectEdge, arg1, arg2, arg3, arg4)
    DECL_THISCALL_HEAD(IntersectPoint, _ZNK10CColSphere14IntersectPointERK7CVector, bool, CVector const& arg1)
    DECL_THISCALL_TAIL(IntersectPoint, arg1)
    DECL_THISCALL_HEAD(IntersectSphere, _ZNK10CColSphere15IntersectSphereERKS_, bool, CColSphere const& arg1)
    DECL_THISCALL_TAIL(IntersectSphere, arg1)

    ColData m_data;
DECL_CLASS_END()

struct CColDisk : CColSphere
{
    CVector m_vecThickness;
    float   m_fThickness;

    inline void Set(float startRadius, CVector const& start, CVector const& end, float endRadius, unsigned char material, unsigned char pieceType, unsigned char lighting)
    {
        m_fRadius = startRadius;
        m_vecCentre = start;
        m_fThickness = endRadius;
        m_vecThickness = end;
        m_data.m_nSurfaceType = material;
        m_data.m_nPieceType = pieceType;
        m_data.m_lighting = lighting;
    }
};

struct CBoundingBox : CBox
{
    CSphere m_boundSphere;

    CBoundingBox() : CBox() {}
};
CHECKSIZE(CBoundingBox, 0x28, 0x28);

DECL_CLASS(CColModel)
    // Construct/Deconstruct functions
    DECL_CTORCALL(CColModel, _ZN9CColModelC2Ev);
    DECL_DTORCALL(CColModel, _ZN9CColModelD2Ev);
    DECL_NEWCALL(CColModel, BYBIT(_ZN9CColModelnwEj, _ZN9CColModelnwEm));
    DECL_DLCALL(CColModel, _ZN9CColModeldlEPv);

    // Member functions
    DECL_THISCALL_NAMED_HEAD(Assign, operator=, _ZN9CColModelaSERKS_, CColModel&, const CColModel &model)
    DECL_THISCALL_TAIL(Assign, model)

    DECL_THISCALL_SIMPLE(MakeMultipleAlloc, _ZN9CColModel17MakeMultipleAllocEv, void);
    DECL_THISCALL_SIMPLE(AllocateData, _ZN9CColModel12AllocateDataEv, void);
    DECL_THISCALL_SIMPLE(RemoveCollisionVolumes, _ZN9CColModel22RemoveCollisionVolumesEv, void);
    DECL_THISCALL_SIMPLE(CalculateTrianglePlanes, _ZN9CColModel23CalculateTrianglePlanesEv, void);
    DECL_THISCALL_SIMPLE(RemoveTrianglePlanes, _ZN9CColModel20RemoveTrianglePlanesEv, void);

    DECL_THISCALL_NAMED_HEAD(AllocateData1, AllocateData, _ZN9CColModel12AllocateDataEiiiiib, void, i32 numSpheres, i32 numBoxes, i32 numLines, i32 numVertices, i32 numTriangles, bool bUseDisksNotLines)
    DECL_THISCALL_TAIL(AllocateData1, numSpheres, numBoxes, numLines, numVertices, numTriangles, bUseDisksNotLines)

    DECL_THISCALL_NAMED_HEAD(AllocateData2, AllocateData, _ZN9CColModel12AllocateDataEi, void, i32 size)
    DECL_THISCALL_TAIL(AllocateData2, size)

    // Member values
    CBox m_boundBox;
    CSphere m_boundSphere;
    unsigned char m_nColSlot;
    union
    {
        struct
        {
            unsigned char m_bHasCollisionVolumes : 1;
            unsigned char m_bIsSingleColDataAlloc : 1;
            unsigned char m_bIsActive : 1;
        };
        unsigned char m_nFlags;
    };
    CCollisionData* m_pColData;
DECL_CLASS_END()
CHECKSIZE(CColModel, 0x30, 0x38);

struct tColLighting
{
    unsigned char day : 4;
    unsigned char night : 4;
};
DECL_CLASS(CColPoint)
    // Member functions
    DECL_THISCALL_NAMED_HEAD(Assign, operator=, _ZN9CColPointaSERKS_, CColPoint&, const CColPoint &point)
    DECL_THISCALL_TAIL(Assign, point)

    // Member values
    CVector m_vecPoint;
    float field_C;
    CVector m_vecNormal;
    float field_1C;
    unsigned char m_nSurfaceTypeA; // see eSurfaceType
    unsigned char m_nPieceTypeA;
    tColLighting m_nLightingA;
    unsigned char m_nSurfaceTypeB; // see eSurfaceType
    unsigned char m_nPieceTypeB;
    tColLighting m_nLightingB;
    float m_fDepth;
DECL_CLASS_END()
CHECKSIZE(CColPoint, 0x2C, 0x2C);

struct CStoredCollPoly
{
    CVector      m_aMeshVertices[3];
    bool         m_bIsActual;
    unsigned int m_nLighting;
};

#endif // __AML_PSDK_SACOLMODEL_H
