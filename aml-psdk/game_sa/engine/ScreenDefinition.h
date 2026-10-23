#ifndef __AML_PSDK_SASCREENDEFINITION_H
#define __AML_PSDK_SASCREENDEFINITION_H

#include "../plugin.h"

struct CScreenDefinition
{
    float x1;
    float y1;
    float z1;
    float x2;
    float y2;
    float z2;
    float x3;
    float y3;
    float z3;
    float x4;
    float y4;
    float z4;
};
CHECKSIZE(CScreenDefinition, 0x30, 0x30);

#endif // __AML_PSDK_SASCREENDEFINITION_H
