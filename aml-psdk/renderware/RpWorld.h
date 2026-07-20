#ifndef __AML_PSDK_RPWORLD_H
#define __AML_PSDK_RPWORLD_H

#include <aml-psdk/sdk_base.h>
#include "RwBase.h"
#include "RwLinks.h"
#include "RwObject.h"
#include "RwVector.h"
#include "RwRGBA.h"
#include "RwResource.h"
#include "RxPipeline.h"
#include "RpMesh.h"
#include "RpMaterial.h"
#include "RpGeometry.h"  // RwTexCoords, rwMAXTEXTURECOORDS

struct RpWorld;
struct RpWorldSector;

enum RpWorldRenderOrder : RwInt32
{
    rpWORLDRENDERNARENDERORDER = 0x0,
    rpWORLDRENDERFRONT2BACK = 0x1,
    rpWORLDRENDERBACK2FRONT = 0x2,
};

enum RpWorldFlag : RwInt32
{
    rpWORLDTRISTRIP = 0x1,
    rpWORLDPOSITIONS = 0x2,
    rpWORLDTEXTURED = 0x4,
    rpWORLDPRELIT = 0x8,
    rpWORLDNORMALS = 0x10,
    rpWORLDLIGHT = 0x20,
    rpWORLDMODULATEMATERIALCOLOR = 0x40,
    rpWORLDTEXTURED2 = 0x80,
    rpWORLDNATIVE = 0x1000000,
    rpWORLDNATIVEINSTANCE = 0x2000000,
    rpWORLDFLAGSMASK = 0xFF,
    rpWORLDNATIVEFLAGSMASK = 0xF000000,
    rpWORLDSECTORSOVERLAP = 0x40000000,
};

/* A world triangle. Note the field order differs from RpTriangle: here the
 * material index comes first. */
struct RpPolygon
{
    RwUInt16 matIndex;
    RwUInt16 vertIndex[3];
};

/* World sector normals are stored as signed bytes, not floats. */
struct RpVertexNormal
{
    RwInt8  x;
    RwInt8  y;
    RwInt8  z;
    RwUInt8 pad;
};

/* Common head of both RpWorldSector and the BSP plane sectors. Read `type`
 * to tell which one a RpSector* actually points at: a value in 0..2 is a
 * plane sector (the split axis), anything else is a world sector. */
struct RpSector
{
    RwInt32 type;
};

struct RpWorldSector
{
    RwInt32         type;

    RpPolygon      *polygons;
    RwV3d          *vertices;
    RpVertexNormal *normals;
    RwTexCoords    *texCoords[rwMAXTEXTURECOORDS];
    RwRGBA         *preLitLum;

    RwResEntry     *repEntry;

    RwLinkList      collAtomicsInWorldSector;
    RwLinkList      noCollAtomicsInWorldSector;
    RwLinkList      lightsInWorldSector;

    RwBBox          boundingBox;      /* Sector bounds from the BSP split */
    RwBBox          tightBoundingBox; /* Bounds that actually enclose the geometry */

    RpMeshHeader   *mesh;
    RxPipeline     *pipeline;

    RwUInt16        matListWindowBase;
    RwUInt16        numVertices;
    RwUInt16        numPolygons;
    RwUInt16        pad;
};


struct RpWorld
{
    RwObject                    object;
    RwUInt32                    flags;
    RpWorldRenderOrder          renderOrder;
    RpMaterialList              matList;
    RpSector                   *rootSector;
    RwInt32                     numTexCoordSets;
    RwInt32                     numClumpsInWorld;
    RwLLLink                   *currentClumpLink;
    RwLinkList                  clumpList;
    RwLinkList                  lightList;
    RwLinkList                  directionalLightList;
    RwV3d                       worldOrigin;
    RwBBox                      boundingBox;
    RpWorldSectorCallBackRender renderCallBack;
    RxPipeline                 *pipeline;
};

/* Header of a world chunk in a stream, filled in by _rpWorldChunkInfoRead(). */
struct RpWorldChunkInfo
{
    RwBool  rootIsWorldSector;
    RwV3d   invWorldOrigin;
    RwInt32 numPolygons;
    RwInt32 numVertices;
    RwInt32 numPlaneSectors;
    RwInt32 numWorldSectors;
    RwInt32 colSectorSize;
    RwInt32 format;
    RwBBox  boundingBox;
};

/* Per-sector header inside a world chunk. RenderWare spells the struct
 * RpWorldChunkInfoSector and typedefs it; both names are kept here. */
struct RpWorldChunkInfoSector
{
    RwInt32 matListWindowBase;
    RwInt32 numPolygons;
    RwInt32 numVertices;
    RwV3d   inf;
    RwV3d   sup;
    RwBool  collSectorPresent;
    RwBool  unused;
};
typedef RpWorldChunkInfoSector RpWorldSectorChunkInfo;

CHECKSIZE(RpWorldChunkInfo, 0x40, 0x40);
CHECKSIZE(RpWorldChunkInfoSector, 0x2C, 0x2C);
CHECKSIZE(RpPolygon, 0x8, 0x8);
CHECKSIZE(RpVertexNormal, 0x4, 0x4);
CHECKSIZE(RpSector, 0x4, 0x4);
CHECKSIZE(RpWorldSector, 0x90, 0xE8);
CHECKSIZE(RpWorld, 0x70, 0xA8);

DECL_FASTCALL_SIMPLE_GLO(_rpWorldChunkInfoRead, _Z21_rpWorldChunkInfoReadP8RwStreamP16RpWorldChunkInfoPi, RpWorldChunkInfo*, RwStream* stream, RpWorldChunkInfo* worldChunkInfo, RwInt32* bytesRead);
DECL_FASTCALL_SIMPLE_GLO(_rpWorldFindBBox, _Z16_rpWorldFindBBoxP7RpWorldP6RwBBox, RwBool, RpWorld* world, RwBBox* boundingBox);
DECL_FASTCALL_SIMPLE_GLO(_rpWorldForAllGlobalLights, _Z26_rpWorldForAllGlobalLightsPFP7RpLightS0_PvES1_, RwBool, RpLightCallBack callBack, void* pData);
DECL_FASTCALL_SIMPLE_GLO(_rpWorldObjRegisterExtensions, _Z29_rpWorldObjRegisterExtensionsv, RwBool);
DECL_FASTCALL_SIMPLE_GLO(_rpWorldPipeAttach, _Z18_rpWorldPipeAttachv, RwBool);
DECL_FASTCALL_SIMPLE_GLO(_rpWorldPipelineClose, _Z21_rpWorldPipelineClosev, void);
DECL_FASTCALL_SIMPLE_GLO(_rpWorldPipelineOpen, _Z20_rpWorldPipelineOpenv, RwBool);
DECL_FASTCALL_SIMPLE_GLO(_rpWorldRegisterWorld, _Z21_rpWorldRegisterWorldP7RpWorldj, void, RpWorld* world, RwUInt32 memorySize);
DECL_FASTCALL_SIMPLE_GLO(_rpWorldSectorChunkInfoRead, _Z27_rpWorldSectorChunkInfoReadP8RwStreamP22RpWorldChunkInfoSectorPi, RpWorldSectorChunkInfo*, RwStream* stream, RpWorldSectorChunkInfo* worldSectorChunkInfo, RwInt32* bytesRead);
DECL_FASTCALL_SIMPLE_GLO(_rpWorldSectorForAllLocalLights, _Z31_rpWorldSectorForAllLocalLightsP13RpWorldSectorPFP7RpLightS2_PvES3_, RpWorldSector*, RpWorldSector* sector, RpLightCallBack callBack, void* pData);
DECL_FASTCALL_SIMPLE_GLO(_rpWorldSectorNativeRead, _Z24_rpWorldSectorNativeReadP8RwStreamP13RpWorldSector, RpWorldSector*, RwStream* stream, RpWorldSector* sector);
DECL_FASTCALL_SIMPLE_GLO(_rpWorldSectorNativeSize, _Z24_rpWorldSectorNativeSizePK13RpWorldSector, RwInt32, const RpWorldSector* sector);
DECL_FASTCALL_SIMPLE_GLO(_rpWorldSectorNativeWrite, _Z25_rpWorldSectorNativeWriteP8RwStreamPK13RpWorldSector, RwStream*, RwStream* stream, const RpWorldSector* sector);
DECL_FASTCALL_SIMPLE_GLO(_rpWorldSetupSectorBoundingBoxes, _Z32_rpWorldSetupSectorBoundingBoxesP7RpWorld, RpWorld*, RpWorld* world);
DECL_FASTCALL_SIMPLE_GLO(_rpWorldUnregisterWorld, _Z23_rpWorldUnregisterWorldP7RpWorld, void, RpWorld* world);
DECL_FASTCALL_SIMPLE_GLO(RpWorldAddAtomic, _Z16RpWorldAddAtomicP7RpWorldP8RpAtomic, RpWorld*, RpWorld* world, RpAtomic* atomic);
DECL_FASTCALL_SIMPLE_GLO(RpWorldAddCamera, _Z16RpWorldAddCameraP7RpWorldP8RwCamera, RpWorld*, RpWorld* world, RwCamera* camera);
DECL_FASTCALL_SIMPLE_GLO(RpWorldAddClump, _Z15RpWorldAddClumpP7RpWorldP7RpClump, RpWorld*, RpWorld* world, RpClump* clump);
DECL_FASTCALL_SIMPLE_GLO(RpWorldAddLight, _Z15RpWorldAddLightP7RpWorldP7RpLight, RpWorld*, RpWorld* world, RpLight* light);
DECL_FASTCALL_SIMPLE_GLO(RpWorldCreate, _Z13RpWorldCreateP6RwBBox, RpWorld*, RwBBox* boundingBox);
DECL_FASTCALL_SIMPLE_GLO(RpWorldDestroy, _Z14RpWorldDestroyP7RpWorld, RwBool, RpWorld* world);
DECL_FASTCALL_SIMPLE_GLO(RpWorldForAllClumps, _Z19RpWorldForAllClumpsP7RpWorldPFP7RpClumpS2_PvES3_, RpWorld*, RpWorld* world, RpClumpCallBack fpCallBack, void* pData);
DECL_FASTCALL_SIMPLE_GLO(RpWorldForAllLights, _Z19RpWorldForAllLightsP7RpWorldPFP7RpLightS2_PvES3_, RpWorld*, RpWorld* world, RpLightCallBack fpCallBack, void* pData);
DECL_FASTCALL_SIMPLE_GLO(RpWorldForAllMaterials, _Z22RpWorldForAllMaterialsP7RpWorldPFP10RpMaterialS2_PvES3_, RpWorld*, RpWorld* world, RpMaterialCallBack fpCallBack, void* pData);
DECL_FASTCALL_SIMPLE_GLO(RpWorldForAllWorldSectors, _Z25RpWorldForAllWorldSectorsP7RpWorldPFP13RpWorldSectorS2_PvES3_, RpWorld*, RpWorld* world, RpWorldSectorCallBack fpCallBack, void* pData);
DECL_FASTCALL_SIMPLE_GLO(RpWorldGetPluginOffset, _Z22RpWorldGetPluginOffsetj, RwInt32, RwUInt32 pluginID);
DECL_FASTCALL_SIMPLE_GLO(RpWorldGetSectorRenderCallBack, _Z30RpWorldGetSectorRenderCallBackPK7RpWorld, RpWorldSectorCallBackRender, const RpWorld* world);
DECL_FASTCALL_SIMPLE_GLO(RpWorldInstance, _Z15RpWorldInstanceP7RpWorld, RwBool, RpWorld* world);
DECL_FASTCALL_SIMPLE_GLO(RpWorldLock, _Z11RpWorldLockP7RpWorld, RpWorld*, RpWorld* world);
DECL_FASTCALL_SIMPLE_GLO(RpWorldPluginAttach, _Z19RpWorldPluginAttachv, RwBool);
DECL_FASTCALL_SIMPLE_GLO(RpWorldRegisterPlugin, _Z21RpWorldRegisterPluginijPFPvS_iiES1_PFS_S_PKviiE, RwInt32, RwInt32 size, RwUInt32 pluginID, RwPluginObjectConstructor constructCB, RwPluginObjectDestructor destructCB, RwPluginObjectCopy copyCB);
DECL_FASTCALL_SIMPLE_GLO(RpWorldRegisterPluginStream, _Z27RpWorldRegisterPluginStreamjPFP8RwStreamS0_iPviiEPFS0_S0_iPKviiEPFiS5_iiE, RwInt32, RwUInt32 pluginID, RwPluginDataChunkReadCallBack readCB, RwPluginDataChunkWriteCallBack writeCB, RwPluginDataChunkGetSizeCallBack getSizeCB);
DECL_FASTCALL_SIMPLE_GLO(RpWorldRemoveAtomic, _Z19RpWorldRemoveAtomicP7RpWorldP8RpAtomic, RpWorld*, RpWorld* world, RpAtomic* atomic);
DECL_FASTCALL_SIMPLE_GLO(RpWorldRemoveCamera, _Z19RpWorldRemoveCameraP7RpWorldP8RwCamera, RpWorld*, RpWorld* world, RwCamera* camera);
DECL_FASTCALL_SIMPLE_GLO(RpWorldRemoveClump, _Z18RpWorldRemoveClumpP7RpWorldP7RpClump, RpWorld*, RpWorld* world, RpClump* clump);
DECL_FASTCALL_SIMPLE_GLO(RpWorldRemoveLight, _Z18RpWorldRemoveLightP7RpWorldP7RpLight, RpWorld*, RpWorld* world, RpLight* light);
DECL_FASTCALL_SIMPLE_GLO(RpWorldRender, _Z13RpWorldRenderP7RpWorld, RpWorld*, RpWorld* world);
DECL_FASTCALL_SIMPLE_GLO(RpWorldSectorForAllAtomics, _Z26RpWorldSectorForAllAtomicsP13RpWorldSectorPFP8RpAtomicS2_PvES3_, RpWorldSector*, RpWorldSector* sector, RpAtomicCallBack callback, void* data);
DECL_FASTCALL_SIMPLE_GLO(RpWorldSectorForAllCollisionAtomics, _Z35RpWorldSectorForAllCollisionAtomicsP13RpWorldSectorPFP8RpAtomicS2_PvES3_, RpWorldSector*, RpWorldSector* sector, RpAtomicCallBack callback, void* data);
DECL_FASTCALL_SIMPLE_GLO(RpWorldSectorForAllLights, _Z25RpWorldSectorForAllLightsP13RpWorldSectorPFP7RpLightS2_PvES3_, RpWorldSector*, RpWorldSector* sector, RpLightCallBack callback, void* data);
DECL_FASTCALL_SIMPLE_GLO(RpWorldSectorForAllMeshes, _Z25RpWorldSectorForAllMeshesPK13RpWorldSectorPFP6RpMeshS3_P12RpMeshHeaderPvES6_, const RpWorldSector*, const RpWorldSector* sector, RpMeshCallBack fpCallBack, void* pData);
DECL_FASTCALL_SIMPLE_GLO(RpWorldSectorGetNumPolygons, _Z27RpWorldSectorGetNumPolygonsPK13RpWorldSector, RwInt32, const RpWorldSector* sector);
DECL_FASTCALL_SIMPLE_GLO(RpWorldSectorGetNumVertices, _Z27RpWorldSectorGetNumVerticesPK13RpWorldSector, RwInt32, const RpWorldSector* sector);
DECL_FASTCALL_SIMPLE_GLO(RpWorldSectorGetPluginOffset, _Z28RpWorldSectorGetPluginOffsetj, RwInt32, RwUInt32 pluginID);
DECL_FASTCALL_SIMPLE_GLO(RpWorldSectorGetWorld, _Z21RpWorldSectorGetWorldPK13RpWorldSector, RpWorld*, const RpWorldSector* sector);
DECL_FASTCALL_SIMPLE_GLO(RpWorldSectorRegisterPlugin, _Z27RpWorldSectorRegisterPluginijPFPvS_iiES1_PFS_S_PKviiE, RwInt32, RwInt32 size, RwUInt32 pluginID, RwPluginObjectConstructor constructCB, RwPluginObjectDestructor destructCB, RwPluginObjectCopy copyCB);
DECL_FASTCALL_SIMPLE_GLO(RpWorldSectorRegisterPluginStream, _Z33RpWorldSectorRegisterPluginStreamjPFP8RwStreamS0_iPviiEPFS0_S0_iPKviiEPFiS5_iiE, RwInt32, RwUInt32 pluginID, RwPluginDataChunkReadCallBack readCB, RwPluginDataChunkWriteCallBack writeCB, RwPluginDataChunkGetSizeCallBack getSizeCB);
DECL_FASTCALL_SIMPLE_GLO(RpWorldSectorRender, _Z19RpWorldSectorRenderP13RpWorldSector, RpWorldSector*, RpWorldSector* sector);
DECL_FASTCALL_SIMPLE_GLO(RpWorldSectorSetStreamAlwaysCallBack, _Z36RpWorldSectorSetStreamAlwaysCallBackjPFiPviiE, RwInt32, RwUInt32 pluginID, RwPluginDataChunkAlwaysCallBack alwaysCB);
DECL_FASTCALL_SIMPLE_GLO(RpWorldSectorSetStreamRightsCallBack, _Z36RpWorldSectorSetStreamRightsCallBackjPFiPviijE, RwInt32, RwUInt32 pluginID, RwPluginDataChunkRightsCallBack rightsCB);
DECL_FASTCALL_SIMPLE_GLO(RpWorldSectorValidatePlugins, _Z28RpWorldSectorValidatePluginsPK13RpWorldSector, RwBool, const RpWorldSector* sector);
DECL_FASTCALL_SIMPLE_GLO(RpWorldSetDefaultSectorPipeline, _Z31RpWorldSetDefaultSectorPipelineP10RxPipeline, RxPipeline*, RxPipeline* pipeline);
DECL_FASTCALL_SIMPLE_GLO(RpWorldSetSectorRenderCallBack, _Z30RpWorldSetSectorRenderCallBackP7RpWorldPFP13RpWorldSectorS2_E, RpWorld*, RpWorld* world, RpWorldSectorCallBackRender fpCallBack);
DECL_FASTCALL_SIMPLE_GLO(RpWorldSetStreamAlwaysCallBack, _Z30RpWorldSetStreamAlwaysCallBackjPFiPviiE, RwInt32, RwUInt32 pluginID, RwPluginDataChunkAlwaysCallBack alwaysCB);
DECL_FASTCALL_SIMPLE_GLO(RpWorldSetStreamRightsCallBack, _Z30RpWorldSetStreamRightsCallBackjPFiPviijE, RwInt32, RwUInt32 pluginID, RwPluginDataChunkRightsCallBack rightsCB);
DECL_FASTCALL_SIMPLE_GLO(RpWorldStreamGetSize, _Z20RpWorldStreamGetSizePK7RpWorld, RwUInt32, const RpWorld* world);
DECL_FASTCALL_SIMPLE_GLO(RpWorldStreamRead, _Z17RpWorldStreamReadP8RwStream, RpWorld*, RwStream* stream);
DECL_FASTCALL_SIMPLE_GLO(RpWorldStreamWrite, _Z18RpWorldStreamWritePK7RpWorldP8RwStream, const RpWorld*, const RpWorld* world, RwStream* stream);
DECL_FASTCALL_SIMPLE_GLO(RpWorldUnlock, _Z13RpWorldUnlockP7RpWorld, RpWorld*, RpWorld* world);
DECL_FASTCALL_SIMPLE_GLO(RpWorldValidatePlugins, _Z22RpWorldValidatePluginsP7RpWorld, RwBool, RpWorld* world);

#endif // __AML_PSDK_RPWORLD_H
