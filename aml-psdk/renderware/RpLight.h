#ifndef __AML_PSDK_RPLIGHT_H
#define __AML_PSDK_RPLIGHT_H

#include <aml-psdk/sdk_base.h>
#include "RwBase.h"
#include "RwLinks.h"
#include "RwObject.h"
#include "RwRGBA.h"

struct RpLight;

enum RpLightType : RwInt32
{
    rpNALIGHTTYPE = 0x0,
    /* Lights that have no position, only a direction */
    rpLIGHTDIRECTIONAL = 0x1,
    rpLIGHTAMBIENT = 0x2,
    /* Lights that have a position, from here on */
    rpLIGHTPOINT = 0x80,
    rpLIGHTSPOT = 0x81,
    rpLIGHTSPOTSOFT = 0x82,
};

enum RpLightFlag : RwInt32
{
    rpLIGHTLIGHTATOMICS = 0x1, /**< The light illuminates atomics */
    rpLIGHTLIGHTWORLD = 0x2,   /**< The light illuminates world sectors */
};

struct RpLight
{
    RwObjectHasFrame object;
    RwReal           radius;
    RwRGBAReal       color;         /* Light color, alpha is unused */
    RwReal           minusCosAngle; /* Spot lights: -cos(cone half angle) */
    RwLinkList       WorldSectorsInLight;
    RwLLLink         inWorld;
    RwUInt16         lightFrame;
    RwUInt8          isMainLight;
    RwUInt8          pad;
};

/* Two-way link between a light and a world sector it illuminates. Each side
 * owns one of the two list nodes. */
struct RpLightTie
{
    RwLLLink       lightInWorldSector;
    RpLight       *light;
    RwLLLink       WorldSectorInLight;
    RpWorldSector *sect;
};

/* Header of a light chunk in a stream, filled in by _rpLightChunkInfoRead(). */
struct RpLightChunkInfo
{
    RwReal   radius;
    RwReal   red;
    RwReal   green;
    RwReal   blue;
    RwReal   minusCosAngle;
    RwUInt32 typeAndFlags; /* Low 16 bits RpLightFlag, high 16 bits RpLightType */
};

CHECKSIZE(RpLight, 0x40, 0x68);
CHECKSIZE(RpLightTie, 0x18, 0x30);
CHECKSIZE(RpLightChunkInfo, 0x18, 0x18);

DECL_FASTCALL_SIMPLE_GLO(_rpLightChunkInfoRead, _Z21_rpLightChunkInfoReadP8RwStreamP16RpLightChunkInfoPi, RpLightChunkInfo*, RwStream* stream, RpLightChunkInfo* lightChunkInfo, RwInt32* bytesRead);
DECL_FASTCALL_SIMPLE_GLO(_rpLightClose, _Z13_rpLightClosePvii, void*, void* instance, RwInt32 offset, RwInt32 size);
DECL_FASTCALL_SIMPLE_GLO(_rpLightOpen, _Z12_rpLightOpenPvii, void*, void* instance, RwInt32 offset, RwInt32 size);
DECL_FASTCALL_SIMPLE_GLO(_rpLightTieDestroy, _Z18_rpLightTieDestroyP10RpLightTie, RwBool, RpLightTie* tie);
DECL_FASTCALL_SIMPLE_GLO(RpLightCreate, _Z13RpLightCreatei, RpLight*, RwInt32 type);
DECL_FASTCALL_SIMPLE_GLO(RpLightDestroy, _Z14RpLightDestroyP7RpLight, RwBool, RpLight* light);
DECL_FASTCALL_SIMPLE_GLO(RpLightForAllWorldSectors, _Z25RpLightForAllWorldSectorsP7RpLightPFP13RpWorldSectorS2_PvES3_, RpLight*, RpLight* light, RpWorldSectorCallBack callback, void* data);
DECL_FASTCALL_SIMPLE_GLO(RpLightGetClump, _Z15RpLightGetClumpPK7RpLight, RpClump*, const RpLight* light);
DECL_FASTCALL_SIMPLE_GLO(RpLightGetConeAngle, _Z19RpLightGetConeAnglePK7RpLight, RwReal, const RpLight* light);
DECL_FASTCALL_SIMPLE_GLO(RpLightGetPluginOffset, _Z22RpLightGetPluginOffsetj, RwInt32, RwUInt32 pluginID);
DECL_FASTCALL_SIMPLE_GLO(RpLightGetWorld, _Z15RpLightGetWorldPK7RpLight, RpWorld*, const RpLight* light);
DECL_FASTCALL_SIMPLE_GLO(RpLightRegisterPlugin, _Z21RpLightRegisterPluginijPFPvS_iiES1_PFS_S_PKviiE, RwInt32, RwInt32 size, RwUInt32 pluginID, RwPluginObjectConstructor constructCB, RwPluginObjectDestructor destructCB, RwPluginObjectCopy copyCB);
DECL_FASTCALL_SIMPLE_GLO(RpLightRegisterPluginStream, _Z27RpLightRegisterPluginStreamjPFP8RwStreamS0_iPviiEPFS0_S0_iPKviiEPFiS5_iiE, RwInt32, RwUInt32 pluginID, RwPluginDataChunkReadCallBack readCB, RwPluginDataChunkWriteCallBack writeCB, RwPluginDataChunkGetSizeCallBack getSizeCB);
DECL_FASTCALL_SIMPLE_GLO(RpLightSetColor, _Z15RpLightSetColorP7RpLightPK10RwRGBAReal, RpLight*, RpLight* light, const RwRGBAReal* color);
DECL_FASTCALL_SIMPLE_GLO(RpLightSetConeAngle, _Z19RpLightSetConeAngleP7RpLightf, RpLight*, RpLight* light, RwReal angle);
DECL_FASTCALL_SIMPLE_GLO(RpLightSetFreeListCreateParams, _Z30RpLightSetFreeListCreateParamsii, void, RwInt32 blockSize, RwInt32 numBlocksToPrealloc);
DECL_FASTCALL_SIMPLE_GLO(RpLightSetRadius, _Z16RpLightSetRadiusP7RpLightf, RpLight*, RpLight* light, RwReal radius);
DECL_FASTCALL_SIMPLE_GLO(RpLightSetStreamAlwaysCallBack, _Z30RpLightSetStreamAlwaysCallBackjPFiPviiE, RwInt32, RwUInt32 pluginID, RwPluginDataChunkAlwaysCallBack alwaysCB);
DECL_FASTCALL_SIMPLE_GLO(RpLightStreamGetSize, _Z20RpLightStreamGetSizePK7RpLight, RwUInt32, const RpLight* light);
DECL_FASTCALL_SIMPLE_GLO(RpLightStreamRead, _Z17RpLightStreamReadP8RwStream, RpLight*, RwStream* stream);
DECL_FASTCALL_SIMPLE_GLO(RpLightStreamWrite, _Z18RpLightStreamWritePK7RpLightP8RwStream, const RpLight*, const RpLight* light, RwStream* stream);
DECL_FASTCALL_SIMPLE_GLO(RpLightTieSetFreeListCreateParams, _Z33RpLightTieSetFreeListCreateParamsii, void, RwInt32 blockSize, RwInt32 numBlocksToPrealloc);
DECL_FASTCALL_SIMPLE_GLO(RpLightValidatePlugins, _Z22RpLightValidatePluginsPK7RpLight, RwBool, const RpLight* light);

#endif // __AML_PSDK_RPLIGHT_H
