#ifndef __AML_PSDK_RWBASE_H
#define __AML_PSDK_RWBASE_H

#include <aml-psdk/sdk_base.h>

#define RwInt32 i32
#define RwUInt32 u32
#define RwInt16 i16
#define RwUInt16 u16
#define RwInt8 i8
#define RwUInt8 u8
#define RwBool i32
#define RwReal float
#define RwChar char
#define RwFixed i64

struct RwRect
{
    RwInt32 x;
    RwInt32 y;
    RwInt32 w;
    RwInt32 h;
};

enum RwOpCombineType : RwInt32
{
    rwCOMBINEREPLACE = 0x0,
    rwCOMBINEPRECONCAT = 0x1,
    rwCOMBINEPOSTCONCAT = 0x2,
};

enum RwPlatformID : RwInt32
{
    rwID_PCD3D7 = 0x1,
    rwID_PCOGL = 0x2,
    rwID_MAC = 0x3,
    rwID_PS2 = 0x4,
    rwID_XBOX = 0x5,
    rwID_GAMECUBE = 0x6,
    rwID_SOFTRAS = 0x7,
    rwID_PCD3D8 = 0x8,
    rwID_PCD3D9 = 0x9,
    rwID_ES2_DXT = 0xA,
    rwID_ES2_PVR = 0xB,
    rwID_ES2_ATC = 0xC,
    rwID_ES2_UNC = 0xD,
};



struct RwStream;

typedef void *(*RwPluginObjectConstructor)(void *, RwInt32, RwInt32);
typedef void *(*RwPluginObjectDestructor)(void *, RwInt32, RwInt32);
typedef void *(*RwPluginObjectCopy)(void *, const void *, RwInt32, RwInt32);
typedef void *(*RwPluginErrorStrCallBack)(void *);
typedef RwBool (*RwPluginDataChunkRightsCallBack)(void *, RwInt32, RwInt32, RwUInt32);
typedef RwBool (*RwPluginDataChunkAlwaysCallBack)(void *, RwInt32, RwInt32);
typedef RwInt32 (*RwPluginDataChunkGetSizeCallBack)(const void *, RwInt32, RwInt32);
typedef RwStream *(*RwPluginDataChunkWriteCallBack)(RwStream *, RwInt32, const void *, RwInt32, RwInt32);
typedef RwStream *(*RwPluginDataChunkReadCallBack)(RwStream *, RwInt32, void *, RwInt32, RwInt32);

struct RwPluginRegistry;

/* One registered plugin. Every Rw/Rp object type owns a registry, and each
 * RpXxxRegisterPlugin() call appends an entry like this to it. `offset` is
 * what RpXxxGetPluginOffset() hands back. */
struct RwPluginRegEntry
{
    RwInt32                           offset;
    RwInt32                           size;
    RwUInt32                          pluginID;

    RwPluginDataChunkReadCallBack     readCB;
    RwPluginDataChunkWriteCallBack    writeCB;
    RwPluginDataChunkGetSizeCallBack  getSizeCB;
    RwPluginDataChunkAlwaysCallBack   alwaysCB;
    RwPluginDataChunkRightsCallBack   rightsCB;

    RwPluginObjectConstructor         constructCB;
    RwPluginObjectDestructor          destructCB;
    RwPluginObjectCopy                copyCB;
    RwPluginErrorStrCallBack          errStrCB;

    RwPluginRegEntry                 *nextRegEntry;
    RwPluginRegEntry                 *prevRegEntry;
    RwPluginRegistry                 *parentRegistry;
};

CHECKSIZE(RwPluginRegEntry, 0x3C, 0x70);

#endif // __AML_PSDK_RWBASE_H