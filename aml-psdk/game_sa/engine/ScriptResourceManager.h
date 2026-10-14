#ifndef __AML_PSDK_SASCRIPTRESOURCEMANAGER_H
#define __AML_PSDK_SASCRIPTRESOURCEMANAGER_H

/*
    Plugin-SDK (Grand Theft Auto San Andreas) header file
    Authors: GTA Community. See more here
    https://github.com/DK22Pac/plugin-sdk
    Do not delete this comment block. Respect others' work!
*/

#include "../plugin.h"
#include "RunningScript.h"

struct tScriptResource
{
    i32 m_nModelId;
    CRunningScript *m_pThread;
    u16 type;
};
CHECKSIZE(tScriptResource, 0xC, 0x18);

DECL_CLASS(CScriptResourceManager)
    // Member functions
    DECL_THISCALL_SIMPLE(Initialise, _ZN22CScriptResourceManager10InitialiseEv, void);
    DECL_THISCALL_SIMPLE(Save, _ZN22CScriptResourceManager4SaveEv, void);
    DECL_THISCALL_SIMPLE(Load, _ZN22CScriptResourceManager4LoadEv, void);

    DECL_THISCALL_HEAD(AddToResourceManager, _ZN22CScriptResourceManager20AddToResourceManagerEijP14CRunningScript, void,
        i32 modelId, u32 resourceType, CRunningScript* script)
    DECL_THISCALL_TAIL(AddToResourceManager, modelId, resourceType, script)
    DECL_THISCALL_HEAD(RemoveFromResourceManager, _ZN22CScriptResourceManager25RemoveFromResourceManagerEijP14CRunningScript, u8,
        i32 modelId, u32 resourceType, CRunningScript* script)
    DECL_THISCALL_TAIL(RemoveFromResourceManager, modelId, resourceType, script)
    DECL_THISCALL_HEAD(HasResourceBeenRequested, _ZN22CScriptResourceManager24HasResourceBeenRequestedEij, u8, i32 modelId, u32 resourceType)
    DECL_THISCALL_TAIL(HasResourceBeenRequested, modelId, resourceType)

    // Member values
    tScriptResource m_aScriptResources[75];
DECL_CLASS_END()
CHECKSIZE(CScriptResourceManager, 0x384, 0x708);

#endif // __AML_PSDK_SASCRIPTRESOURCEMANAGER_H
