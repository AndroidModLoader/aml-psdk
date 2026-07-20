#ifndef __AML_PSDK_RWVECTOR_H
#define __AML_PSDK_RWVECTOR_H

#include <aml-psdk/gta_base/Vector.h>
#include "RwBase.h"

#define RwV2d CVector2D
#define RwV3d CVector

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

CHECKSIZE(RwSphere, 0x10, 0x10);
CHECKSIZE(RwBBox, 0x18, 0x18);
CHECKSIZE(RwPlane, 0x10, 0x10);

#endif // __AML_PSDK_RWVECTOR_H