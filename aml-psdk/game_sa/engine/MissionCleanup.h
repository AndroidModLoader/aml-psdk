#ifndef __AML_PSDK_SAMISSIONCLEANUP_H
#define __AML_PSDK_SAMISSIONCLEANUP_H

/*
    Plugin-SDK (Grand Theft Auto San Andreas) header file
    Authors: GTA Community. See more here
    https://github.com/DK22Pac/plugin-sdk
    Do not delete this comment block. Respect others' work!
*/

#include "../plugin.h"

struct tMissionCleanupEntity
{
    u8 type;
    i32 handle;
};
CHECKSIZE(tMissionCleanupEntity, 0x8, 0x8);

DECL_CLASS(CMissionCleanup)
    // Member functions
    DECL_CTORCALL(CMissionCleanup, _ZN15CMissionCleanupC2Ev);
    DECL_THISCALL_SIMPLE(Init, _ZN15CMissionCleanup4InitEv, void);
    DECL_THISCALL_SIMPLE(Process, _ZN15CMissionCleanup7ProcessEv, void);
    DECL_THISCALL_SIMPLE(FindFree, _ZN15CMissionCleanup8FindFreeEv, tMissionCleanupEntity*);
    DECL_THISCALL_SIMPLE(CheckIfCollisionHasLoadedForMissionObjects, _ZN15CMissionCleanup42CheckIfCollisionHasLoadedForMissionObjectsEv, void);
    DECL_THISCALL_SIMPLE(DoFadeScrewUpCheck, _ZN15CMissionCleanup18DoFadeScrewUpCheckEv, void);

    DECL_THISCALL_HEAD(AddEntityToList, _ZN15CMissionCleanup15AddEntityToListEih, void, i32 handle, u8 type)
    DECL_THISCALL_TAIL(AddEntityToList, handle, type)
    DECL_THISCALL_HEAD(RemoveEntityFromList, _ZN15CMissionCleanup20RemoveEntityFromListEih, void, i32 handle, u8 type)
    DECL_THISCALL_TAIL(RemoveEntityFromList, handle, type)

    // Member values
    tMissionCleanupEntity m_Objects[75];
    u8 m_Count;
DECL_CLASS_END()
CHECKSIZE(CMissionCleanup, 0x25C, 0x25C);

#endif // __AML_PSDK_SAMISSIONCLEANUP_H
