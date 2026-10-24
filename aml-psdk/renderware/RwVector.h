#ifndef __AML_PSDK_RWVECTOR_H
#define __AML_PSDK_RWVECTOR_H

#include <aml-psdk/gta_base/Vector.h>
#include "RwBase.h"

#define RwV2d CVector2D
#define RwV3d CVector

struct RwV4d
{
    float x, y, z, w;
};

union RQVector
{
    float v[4];
    struct { float x, y, z, w; };
    struct { float r, g, b, a; };

    inline RQVector operator*(float f)
    {
        RQVector result;
        result.x = this->x * f;
        result.y = this->y * f;
        result.z = this->z * f;
        result.w = this->w * f;
        return result;
    }
    inline RQVector operator*=(float f)
    {
        this->x *= f;
        this->y *= f;
        this->z *= f;
        this->w *= f;
        return *this;
    }
};

struct RwSphere
{
    RwV3d center;
    RwReal radius;
};

struct RwBBox
{
    RwV3d sup; /* Supremum corner (max) */
    RwV3d inf; /* Infimum corner (min) */
};

struct RwPlane
{
    RwV3d normal;
    RwReal distance;
};

CHECKSIZE(RwV4d, 0x10, 0x10);
CHECKSIZE(RwSphere, 0x10, 0x10);
CHECKSIZE(RwBBox, 0x18, 0x18);
CHECKSIZE(RwPlane, 0x10, 0x10);

struct RwMatrix;

DECL_FASTCALL_SIMPLE_GLO(RwBBoxAddPoint, _Z14RwBBoxAddPointP6RwBBoxPK5RwV3d, RwBBox*, RwBBox* boundBox, RwV3d const* vertex);
DECL_FASTCALL_SIMPLE_GLO(RwV3dTransformVectors, _Z21RwV3dTransformVectorsP5RwV3dPKS_iPK11RwMatrixTag, RwV3d*, RwV3d* vectorsOut, RwV3d const* vectorsIn, RwInt32 numPoints, RwMatrix const* matrix);
DECL_FASTCALL_SIMPLE_GLO(RwBBoxInitialize, _Z16RwBBoxInitializeP6RwBBoxPK5RwV3d, RwBBox*, RwBBox* boundBox, RwV3d const* vertex);
DECL_FASTCALL_SIMPLE_GLO(RwBBoxContainsPoint, _Z19RwBBoxContainsPointPK6RwBBoxPK5RwV3d, RwBool, RwBBox const* boundBox, RwV3d const* vertex);
DECL_FASTCALL_SIMPLE_GLO(RwV3dTransformVector, _Z20RwV3dTransformVectorP5RwV3dPKS_PK11RwMatrixTag, RwV3d*, RwV3d* vectorOut, RwV3d const* vectorIn, RwMatrix const* matrix);
DECL_FASTCALL_SIMPLE_GLO(RwV2dLength, _Z11RwV2dLengthPK5RwV2d, RwReal, RwV2d const* in);
DECL_FASTCALL_SIMPLE_GLO(RwV2dNormalize, _Z14RwV2dNormalizeP5RwV2dPKS_, RwReal, RwV2d* out, RwV2d const* in);
DECL_FASTCALL_SIMPLE_GLO(RwV3dTransformPoint, _Z19RwV3dTransformPointP5RwV3dPKS_PK11RwMatrixTag, RwV3d*, RwV3d* pointOut, RwV3d const* pointIn, RwMatrix const* matrix);
DECL_FASTCALL_SIMPLE_GLO(RwV3dLength, _Z11RwV3dLengthPK5RwV3d, RwReal, RwV3d const* in);
DECL_FASTCALL_SIMPLE_GLO(RwV3dNormalize, _Z14RwV3dNormalizeP5RwV3dPKS_, RwReal, RwV3d* out, RwV3d const* in);
DECL_FASTCALL_SIMPLE_GLO(RwBBoxCalculate, _Z15RwBBoxCalculateP6RwBBoxPK5RwV3di, RwBBox*, RwBBox* boundBox, RwV3d const* verts, RwInt32 numVerts);
DECL_FASTCALL_SIMPLE_GLO(RwV3dTransformPoints, _Z20RwV3dTransformPointsP5RwV3dPKS_iPK11RwMatrixTag, RwV3d*, RwV3d* pointsOut, RwV3d const* pointsIn, RwInt32 numPoints, RwMatrix const* matrix);

#endif // __AML_PSDK_RWVECTOR_H
