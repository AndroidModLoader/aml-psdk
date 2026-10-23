#ifndef __AML_PSDK_SAPEDGENERATOR_H
#define __AML_PSDK_SAPEDGENERATOR_H

#include "../plugin.h"

struct CPedGenerator
{
    i32 VisibleModel;
    float x;
    float y;
    float z;
    float rotation;
    b8 bHighPriority;
    b8 bWaitUntilFarFromPlayer;
    u16 AreaCode;
    u32 NextGen;
    i32 LatestPedID;
    u16 GenerateCount;
};
CHECKSIZE(CPedGenerator, 0x24, 0x24);

#endif // __AML_PSDK_SAPEDGENERATOR_H
