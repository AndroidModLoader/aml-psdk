#ifndef __AML_PSDK_SASTREAMEDSCRIPTS_H
#define __AML_PSDK_SASTREAMEDSCRIPTS_H

/*
    Plugin-SDK (Grand Theft Auto San Andreas) header file
    Authors: GTA Community. See more here
    https://github.com/DK22Pac/plugin-sdk
    Do not delete this comment block. Respect others' work!
*/

#include "../plugin.h"
#include "RunningScript.h"
#include <aml-psdk/renderware/RwStream.h>

struct tStreamedScript
{
    u8 *data;
    u8 m_nStatus;
    i16 m_nScmIndex;
    char m_Name[20];
    i32 m_nsize;
};
CHECKSIZE(tStreamedScript, 0x20, 0x28);

DECL_CLASS(CStreamedScripts)
    // Member functions
    DECL_THISCALL_SIMPLE(Initialise, _ZN16CStreamedScripts10InitialiseEv, void);
    DECL_THISCALL_SIMPLE(ReInitialise, _ZN16CStreamedScripts12ReInitialiseEv, void);
    DECL_THISCALL_SIMPLE(ReadStreamedScriptData, _ZN16CStreamedScripts22ReadStreamedScriptDataEv, void);

    DECL_THISCALL_HEAD(RegisterScript, _ZN16CStreamedScripts14RegisterScriptEPKc, i32, const char* scriptName)
    DECL_THISCALL_TAIL(RegisterScript, scriptName)
    DECL_THISCALL_HEAD(FindStreamedScript, _ZN16CStreamedScripts18FindStreamedScriptEPKc, i32, const char* scriptName)
    DECL_THISCALL_TAIL(FindStreamedScript, scriptName)
    DECL_THISCALL_HEAD(FindStreamedScriptQuiet, _ZN16CStreamedScripts23FindStreamedScriptQuietEPKc, i32, const char* scriptName)
    DECL_THISCALL_TAIL(FindStreamedScriptQuiet, scriptName)
    DECL_THISCALL_HEAD(GetProperIndexFromIndexUsedByScript, _ZN16CStreamedScripts35GetProperIndexFromIndexUsedByScriptEs, i16, i16 scmIndex)
    DECL_THISCALL_TAIL(GetProperIndexFromIndexUsedByScript, scmIndex)
    DECL_THISCALL_HEAD(LoadStreamedScript, _ZN16CStreamedScripts18LoadStreamedScriptEP8RwStreami, bool, RwStream* stream, i32 index)
    DECL_THISCALL_TAIL(LoadStreamedScript, stream, index)
    DECL_THISCALL_HEAD(StartNewStreamedScript, _ZN16CStreamedScripts22StartNewStreamedScriptEi, CRunningScript*, i32 index)
    DECL_THISCALL_TAIL(StartNewStreamedScript, index)
    DECL_THISCALL_HEAD(RemoveStreamedScriptFromMemory, _ZN16CStreamedScripts30RemoveStreamedScriptFromMemoryEi, void, i32 index)
    DECL_THISCALL_TAIL(RemoveStreamedScriptFromMemory, index)
    DECL_THISCALL_HEAD(GetStreamedScriptFilename, _ZN16CStreamedScripts25GetStreamedScriptFilenameEt, const char*, u16 index)
    DECL_THISCALL_TAIL(GetStreamedScriptFilename, index)
    DECL_THISCALL_HEAD(GetStreamedScriptWithThisStartAddress, _ZN16CStreamedScripts37GetStreamedScriptWithThisStartAddressEPh, i32, u8* dataPtr)
    DECL_THISCALL_TAIL(GetStreamedScriptWithThisStartAddress, dataPtr)

    inline u16 GetNumberOfStreamedScripts() { return m_nCountOfScripts; }

    // Member values
    tStreamedScript m_aScripts[82];
    u32 m_nLargestExternalSize;
    u16 m_nCountOfScripts;
DECL_CLASS_END()
CHECKSIZE(CStreamedScripts, 0xA48, 0xCD8);

#endif // __AML_PSDK_SASTREAMEDSCRIPTS_H
