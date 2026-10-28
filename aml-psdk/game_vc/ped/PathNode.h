#ifndef __AML_PSDK_VCPATHNODE_H
#define __AML_PSDK_VCPATHNODE_H

#include "../plugin.h"
#include <aml-psdk/gta_base/Vector.h>

DECL_CLASS(CPathNode)
    // Helper functions
    inline CVector GetPosition() const { return CVector(m_wPosX / 8.0f, m_wPosY / 8.0f, m_wPosZ / 8.0f); }

    // Member values
    i16 m_wPathData1;
    i16 m_wPathData2;
    i16 m_wPosX;
    i16 m_wPosY;
    i16 m_wPosZ;
    i16 m_nDistance;
    i16 m_nFirstLink;
    u8 m_nWidth;
    i8 m_nGroup;
    u8 m_nFlags[3];
DECL_CLASS_END()
CHECKSIZE(CPathNode, 0x14, 0x14);

#endif // __AML_PSDK_VCPATHNODE_H
