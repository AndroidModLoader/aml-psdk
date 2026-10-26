#ifndef __AML_PSDK_VCANIMBLOCK_H
#define __AML_PSDK_VCANIMBLOCK_H

#include <aml-psdk/game_vc/plugin.h>

struct CAnimBlock
{
    char name[20];
    bool bLoaded;
    u8 : 8;
    i16 usRefs;
    i32 startAnimation;
    i32 animationCount;
};
CHECKSIZE(CAnimBlock, 0x20, 0x20);

#endif // __AML_PSDK_VCANIMBLOCK_H
