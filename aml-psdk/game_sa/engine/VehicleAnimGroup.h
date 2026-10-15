#ifndef __AML_PSDK_SAVEHICLEANIMGROUP_H
#define __AML_PSDK_SAVEHICLEANIMGROUP_H

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/gta_base/Vector.h>

DECL_CLASS(CVehicleAnimGroup)
    // Member functions
    DECL_THISCALL_HEAD(GetGroup, _ZN17CVehicleAnimGroup8GetGroupEi, int, int const index)
    DECL_THISCALL_TAIL(GetGroup, index)
    DECL_THISCALL_HEAD(ComputeCriticalBlendTime, _ZN17CVehicleAnimGroup24ComputeCriticalBlendTimeEi, float, int const index)
    DECL_THISCALL_TAIL(ComputeCriticalBlendTime, index)
    DECL_THISCALL_HEAD(ComputeAnimDoorOffsets, _ZN17CVehicleAnimGroup22ComputeAnimDoorOffsetsEi, CVector, int const offsetType)
    DECL_THISCALL_TAIL(ComputeAnimDoorOffsets, offsetType)

    // Member values
    i8 m_firstGroup;
    i8 m_secondGroup;
    int m_flags;
    int m_specialFlags;
    float m_criticalBlendTimes[5];
    float m_processDoorStartTimes[4];
    float m_processDoorStopTimes[4];
    CVector m_offsets[7];
DECL_CLASS_END()
CHECKSIZE(CVehicleAnimGroup, 0x94, 0x94);

DECL_CLASS(CVehicleAnimGroupData)
    // STATIC values
    DECL_OBJECT_ARRAY_PLT(CVehicleAnimGroup, m_vehicleAnimGroups, BYBIT(0x67684C, 0x84B0F0));

DECL_CLASS_END()
CHECKSIZE(CVehicleAnimGroupData, 0x1, 0x1);

#endif // __AML_PSDK_SAVEHICLEANIMGROUP_H
