#ifndef __AML_PSDK_VCANIMBLENDFRAMEDATA_H
#define __AML_PSDK_VCANIMBLENDFRAMEDATA_H

#include <aml-psdk/game_vc/plugin.h>
#include <aml-psdk/gta_base/Vector.h>

struct RwFrame;
struct RpHAnimInterpFrame;

struct AnimBlendFrameData
{
    u32 m_nFlags;
    CVector m_vecOffset;
    union
    {
        RwFrame* m_pFrame;
        RpHAnimInterpFrame* m_pKeyFrame;
    };
    u32 m_nNodeId;
};
CHECKSIZE(AnimBlendFrameData, 0x18, 0x20);

#endif // __AML_PSDK_VCANIMBLENDFRAMEDATA_H
