#ifndef __AML_PSDK_RWENGINE_H
#define __AML_PSDK_RWENGINE_H

#include "RwBase.h"

struct RwGlobals;
struct RwMetrics;
struct RwFileFunctions;

struct RwMemoryFunctions
{
    void* (*rwmalloc)(size_t size);
    void (*rwfree)(void* memory);
    void* (*rwrealloc)(void* memory, size_t size);
    void* (*rwcalloc)(size_t count, size_t size);
};
CHECKSIZE(RwMemoryFunctions, 0x10, 0x20);

struct RwEngineOpenParams
{
    void* displayID;
};
CHECKSIZE(RwEngineOpenParams, 0x4, 0x8);

enum RwVideoModeFlag : RwInt32
{
    rwVIDEOMODEEXCLUSIVE = 0x1
};

struct RwVideoMode
{
    RwInt32 width;
    RwInt32 height;
    RwInt32 depth;
    RwVideoModeFlag flags;
};
CHECKSIZE(RwVideoMode, 0x10, 0x10);

struct RwSubSystemInfo
{
    RwChar name[80];
};
CHECKSIZE(RwSubSystemInfo, 0x50, 0x50);

enum RwEngineInitFlag : RwInt32
{
    rwENGINEINITFREELISTS = 0,
    rwENGINEINITNOFREELISTS = 0x1
};

struct RwError
{
    RwInt32 pluginID;
    RwInt32 errorCode;
};
CHECKSIZE(RwError, 0x8, 0x8);

DECL_FASTCALL_SIMPLE_GLO(RwEngineGetVersion, _Z18RwEngineGetVersionv, RwInt32);
DECL_FASTCALL_SIMPLE_GLO(RwEngineInit, _Z12RwEngineInitPK17RwMemoryFunctionsjj, RwBool, RwMemoryFunctions const* memoryFunctions, RwUInt32 initFlags, RwUInt32 resourceArenaSize);
DECL_FASTCALL_SIMPLE_GLO(RwEngineTerm, _Z12RwEngineTermv, RwBool);
DECL_FASTCALL_SIMPLE_GLO(RwEngineOpen, _Z12RwEngineOpenP18RwEngineOpenParams, RwBool, RwEngineOpenParams* params);
DECL_FASTCALL_SIMPLE_GLO(RwEngineClose, _Z13RwEngineClosev, RwBool);
DECL_FASTCALL_SIMPLE_GLO(RwEngineStart, _Z13RwEngineStartv, RwBool);
DECL_FASTCALL_SIMPLE_GLO(RwEngineStop, _Z12RwEngineStopv, RwBool);
DECL_FASTCALL_SIMPLE_GLO(RwEngineRegisterPlugin, _Z22RwEngineRegisterPluginijPFPvS_iiES1_, RwInt32, RwInt32 size, RwUInt32 pluginID, RwPluginObjectConstructor constructCB, RwPluginObjectDestructor destructCB);
DECL_FASTCALL_SIMPLE_GLO(RwEngineGetPluginOffset, _Z23RwEngineGetPluginOffsetj, RwInt32, RwUInt32 pluginID);
DECL_FASTCALL_SIMPLE_GLO(RwEngineGetNumSubSystems, _Z24RwEngineGetNumSubSystemsv, RwInt32);
DECL_FASTCALL_SIMPLE_GLO(RwEngineGetSubSystemInfo, _Z24RwEngineGetSubSystemInfoP15RwSubSystemInfoi, RwSubSystemInfo*, RwSubSystemInfo* info, RwInt32 index);
DECL_FASTCALL_SIMPLE_GLO(RwEngineGetCurrentSubSystem, _Z27RwEngineGetCurrentSubSystemv, RwInt32);
DECL_FASTCALL_SIMPLE_GLO(RwEngineSetSubSystem, _Z20RwEngineSetSubSystemi, RwBool, RwInt32 index);
DECL_FASTCALL_SIMPLE_GLO(RwEngineGetNumVideoModes, _Z24RwEngineGetNumVideoModesv, RwInt32);
DECL_FASTCALL_SIMPLE_GLO(RwEngineGetVideoModeInfo, _Z24RwEngineGetVideoModeInfoP11RwVideoModei, RwVideoMode*, RwVideoMode* info, RwInt32 index);
DECL_FASTCALL_SIMPLE_GLO(RwEngineGetCurrentVideoMode, _Z27RwEngineGetCurrentVideoModev, RwInt32);
DECL_FASTCALL_SIMPLE_GLO(RwEngineSetVideoMode, _Z20RwEngineSetVideoModei, RwBool, RwInt32 index);
DECL_FASTCALL_SIMPLE_GLO(RwEngineGetTextureMemorySize, _Z28RwEngineGetTextureMemorySizev, RwInt32);
DECL_FASTCALL_SIMPLE_GLO(RwEngineGetMaxTextureSize, _Z25RwEngineGetMaxTextureSizev, RwInt32);
DECL_FASTCALL_SIMPLE_GLO(RwEngineSetFocus, _Z16RwEngineSetFocusi, RwBool, RwBool enable);
DECL_FASTCALL_SIMPLE_GLO(RwEngineGetMetrics, _Z18RwEngineGetMetricsv, RwMetrics*);
DECL_FASTCALL_SIMPLE_GLO(RwOsGetMemoryInterface, _Z22RwOsGetMemoryInterfacev, RwMemoryFunctions*);
DECL_FASTCALL_SIMPLE_GLO(RwOsGetFileInterface, _Z20RwOsGetFileInterfacev, RwFileFunctions*);
DECL_FASTCALL_SIMPLE_GLO(RwErrorGet, _Z10RwErrorGetP7RwError, RwError*, RwError* error);
DECL_FASTCALL_SIMPLE_GLO(RwErrorSet, _Z10RwErrorSetP7RwError, RwError*, RwError* error);

inline void* RwMalloc(size_t size) { return RwOsGetMemoryInterface()->rwmalloc(size); }
inline void RwFree(void* memory) { RwOsGetMemoryInterface()->rwfree(memory); }
inline void* RwRealloc(void* memory, size_t size) { return RwOsGetMemoryInterface()->rwrealloc(memory, size); }
inline void* RwCalloc(size_t count, size_t size) { return RwOsGetMemoryInterface()->rwcalloc(count, size); }

#ifdef GTAVC
DECL_OBJECT_PLT_GLOBAL(RwGlobals*, RwEngineInstance, BYBIT(0x3969C4, 0x57B388));
#elif defined(GTASA)
DECL_OBJECT_PLT_GLOBAL(RwGlobals*, RwEngineInstance, BYBIT(0x67897C, 0x84F318));
#endif
#define RwEngineInstance RwEngineInstance()
#endif // __AML_PSDK_RWENGINE_H
