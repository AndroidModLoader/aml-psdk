#ifndef __AML_PSDK_RPMATERIAL_H
#define __AML_PSDK_RPMATERIAL_H

#include <aml-psdk/sdk_base.h>
#include "RwBase.h"
#include "RwTexture.h"
#include "RwRGBA.h"

struct RxPipeline;

struct RwSurfaceProperties
{
    RwReal ambient;
    RwReal specular;
    RwReal diffuse;
};

struct RpMaterial
{
    RwTexture          *texture;
    RwRGBA              color;
    RxPipeline         *pipeline;
    RwSurfaceProperties surfaceProps;
    RwInt16             refCount;
};

// TODO: global functions

#endif // __AML_PSDK_RPMATERIAL_H