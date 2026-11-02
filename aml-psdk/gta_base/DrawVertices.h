#ifndef __AML_PSDK_GTADRAWVERTICES_H
#define __AML_PSDK_GTADRAWVERTICES_H

#include <aml-psdk/renderware/RwRGBA.h>

typedef u16 RwImVertexIndex;

#ifdef GTAVC
struct RwOpenGLVertex
{
    RwReal x;
    RwReal y;
    RwReal z;
    union
    {
        RwRGBA color = {};
        struct
        {
            RwUInt8 r;
            RwUInt8 g;
            RwUInt8 b;
            RwUInt8 a;
        };
        RwUInt32 emissiveColor;
    };
    RwReal u;
    RwReal v;
    RwReal w;
    RwReal q;
    RwReal rhw;
};
typedef RwOpenGLVertex RwIm2DVertex;
CHECKSIZE(RwOpenGLVertex, 0x24, 0x24);

struct RxObjSpace3DVertex
{
    RxObjSpace3DVertex() : normal() {}
    union
    {
        struct { RwReal x, y, z; };
        RwV3d objVertex;
    };
    union
    {
        RwV3d normal;
        RwV3d objNormal;
    };
    union
    {
        RwRGBA color = {};
        struct
        {
            RwUInt8 r;
            RwUInt8 g;
            RwUInt8 b;
            RwUInt8 a;
        };
        RwUInt32 emissiveColor;
    };
    RwReal u;
    RwReal v;
};
typedef RxObjSpace3DVertex RwIm3DVertex;
CHECKSIZE(RxObjSpace3DVertex, 0x24, 0x24);
#else
struct RwIm2DVertex
{
    RwIm2DVertex(){}
    RwReal      x;              /**< Screen X */
    RwReal      y;              /**< Screen Y */
    RwReal      z;              /**< Screen Z */
    RwReal      rhw;            /**< Reciprocal of homogeneous W */

    union
    {
        struct
        {
            unsigned char r;
            unsigned char g;
            unsigned char b;
            unsigned char a;
        };
        RwRGBA      color;
        RwUInt32    emissiveColor;  /**< Vertex color */
    };

    RwReal      u;              /**< Texture coordinate U */
    RwReal      v;              /**< Texture coordinate V */
};

struct RwIm3DVertex
{
    RwIm3DVertex(){}
    RwReal      x;              /**< World X */
    RwReal      y;              /**< World Y */
    RwReal      z;              /**< World Z */
    RwV3d normal;

    union
    {
        struct
        {
            unsigned char r;
            unsigned char g;
            unsigned char b;
            unsigned char a;
        };
        RwRGBA      color;
        RwUInt32    emissiveColor;  /**< Vertex color */
    };

    RwReal      u;              /**< Texture coordinate U */
    RwReal      v;              /**< Texture coordinate V */
};
#endif

#endif // __AML_PSDK_GTADRAWVERTICES_H
