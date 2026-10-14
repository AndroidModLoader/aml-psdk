#ifndef __AML_PSDK_SAANIMBLOCK_H
#define __AML_PSDK_SAANIMBLOCK_H

/*
    Plugin-SDK (Grand Theft Auto San Andreas) header file
    Authors: GTA Community. See more here
    https://github.com/DK22Pac/plugin-sdk
    Do not delete this comment block. Respect others' work!
*/

#include "../plugin.h"
#include "../enum/AnimGroup.h"

struct CAnimBlock
{
    char szName[16];
    bool bLoaded;
    i16 usRefs;
    i32 startAnimation;
    i32 animationCount;
    AssocGroupId animationStyle;
};
CHECKSIZE(CAnimBlock, 0x20, 0x20);

struct CAnimNameDescriptor
{
    char m_animName[24];
    char m_animGroupName[16];
};
CHECKSIZE(CAnimNameDescriptor, 0x28, 0x28);

#endif // __AML_PSDK_SAANIMBLOCK_H
