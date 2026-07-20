
#ifndef __AML_PSDK_RPGEOMETRY_H
#define __AML_PSDK_RPGEOMETRY_H

#include <aml-psdk/sdk_base.h>
#include "RwObject.h"
#include "RwVector.h"
#include "RpMaterial.h"
#include "RwMatrix.h"
#include "RwResource.h"
#include "RpMesh.h"

#define rwMAXTEXTURECOORDS 8

struct RpGeometry;
struct RpSkin;  /* Skin plugin data -- opaque, always used through RpSkin* */
struct RpClump;

enum RpGeometryFlag : RwInt32
{
    rpGEOMETRYTRISTRIP = 0x1,             /**< Triangles are strippable */
    rpGEOMETRYPOSITIONS = 0x2,            /**< Vertex positions are present */
    rpGEOMETRYTEXTURED = 0x4,             /**< One set of texture coordinates */
    rpGEOMETRYPRELIT = 0x8,               /**< Pre-light colors are present */
    rpGEOMETRYNORMALS = 0x10,             /**< Vertex normals are present */
    rpGEOMETRYLIGHT = 0x20,               /**< Geometry is lit dynamically */
    rpGEOMETRYMODULATEMATERIALCOLOR = 0x40,/**< Modulate material color with vertex colors */
    rpGEOMETRYTEXTURED2 = 0x80,           /**< Two sets of texture coordinates */
    rpGEOMETRYPRELIT2 = 0x200,
    rpGEOMETRYISLOD = 0x400,
    rpGEOMETRYHASLOD = 0x800,
    rpGEOMETRYNATIVE = 0x1000000,
    rpGEOMETRYNATIVEINSTANCE = 0x2000000,
    rpGEOMETRYFLAGSMASK = 0xFFF,
    rpGEOMETRYNATIVEFLAGSMASK = 0xF000000,
};

enum RpGeometryLockMode : RwInt32
{
    rpGEOMETRYLOCKPOLYGONS = 0x1,
    rpGEOMETRYLOCKVERTICES = 0x2,
    rpGEOMETRYLOCKNORMALS = 0x4,
    rpGEOMETRYLOCKPRELIGHT = 0x8,
    rpGEOMETRYLOCKTEXCOORDS = 0x10,
    rpGEOMETRYLOCKTEXCOORDS1 = 0x10,
    rpGEOMETRYLOCKTEXCOORDS2 = 0x20,
    rpGEOMETRYLOCKTEXCOORDS3 = 0x40,
    rpGEOMETRYLOCKTEXCOORDS4 = 0x80,
    rpGEOMETRYLOCKTEXCOORDS5 = 0x100,
    rpGEOMETRYLOCKTEXCOORDS6 = 0x200,
    rpGEOMETRYLOCKTEXCOORDS7 = 0x400,
    rpGEOMETRYLOCKTEXCOORDS8 = 0x800,
    rpGEOMETRYLOCKTEXCOORDSALL = 0xFF0,
    rpGEOMETRYLOCKALL = 0xFFF,
};

struct RpTriangle
{
    RwUInt16            vertIndex[3];
    RwUInt16            matIndex;
};
struct RwTexCoords
{
    RwReal u;
    RwReal v;
};

/* One frame of vertex-morph animation. A geometry always has at least one;
 * the vertex/normal arrays live here rather than on the geometry itself. */
struct RpMorphTarget
{
    RpGeometry *parentGeom;
    RwSphere    boundingSphere;
    RwV3d      *verts;
    RwV3d      *normals;
};

/* Header of a geometry chunk in a stream, filled in by
 * _rpGeometryChunkInfoRead(). */
struct RpGeometryChunkInfo
{
    RwInt32 format; /* RpGeometryFlag bits, plus numTexCoordSets in bits 16..23 */
    RwInt32 numTriangles;
    RwInt32 numVertices;
    RwInt32 numMorphTargets;
};

struct RpGeometry
{
    RwObject            object;
    RwUInt32            flags;
    RwUInt16            lockedSinceLastInst;
    RwInt16             refCount;
    RwInt32             numTriangles;
    RwInt32             numVertices;
    RwInt32             numMorphTargets;
    RwInt32             numTexCoordSets;
    RpMaterialList      matList;
    RpTriangle         *triangles;
    RwRGBA             *preLitLum;
    RwTexCoords        *texCoords[rwMAXTEXTURECOORDS];
    uintptr_t           vertexBuffer; // Mobile
    RpMeshHeader       *mesh;
    RwResEntry         *repEntry;
    RpMorphTarget      *morphTarget;
};

typedef void (*RpGeometrySortByMaterialCallBack)(const RpGeometry *, RpGeometry *, RwUInt16 *, RwUInt16);

DECL_FASTCALL_SIMPLE_GLO(UseSkinning, _Z11UseSkinningPK10RpGeometry, bool, const RpGeometry* geometry);
DECL_FASTCALL_SIMPLE_GLO(_rpGeometryOpen, _Z15_rpGeometryOpenPvii, void*, void* instance, RwInt32 offset, RwInt32 size);
DECL_FASTCALL_SIMPLE_GLO(_rpGeometryClose, _Z16_rpGeometryClosePvii, void*, void* instance, RwInt32 offset, RwInt32 size);
DECL_FASTCALL_SIMPLE_GLO(_rpGeometryGetTKListFirstRegEntry, _Z33_rpGeometryGetTKListFirstRegEntryv, RwPluginRegEntry*, void);
DECL_FASTCALL_SIMPLE_GLO(RpGeometryTransform, _Z19RpGeometryTransformP10RpGeometryPK11RwMatrixTag, RpGeometry*, RpGeometry* geometry, const RwMatrix* matrix);
DECL_FASTCALL_SIMPLE_GLO(RpGeometryLock, _Z14RpGeometryLockP10RpGeometryi, RpGeometry*, RpGeometry* geometry, RwInt32 lockMode);
DECL_FASTCALL_SIMPLE_GLO(RpGeometryUnlock, _Z16RpGeometryUnlockP10RpGeometry, RpGeometry*, RpGeometry* geometry);
DECL_FASTCALL_SIMPLE_GLO(RpGeometryDestroy, _Z17RpGeometryDestroyP10RpGeometry, RwBool, RpGeometry* geometry);
DECL_FASTCALL_SIMPLE_GLO(RpGeometryCreateSpace, _Z21RpGeometryCreateSpacef, RpGeometry*, RwReal radius);
DECL_FASTCALL_SIMPLE_GLO(RpGeometryCreate, _Z16RpGeometryCreateiij, RpGeometry*, RwInt32 numVerts, RwInt32 numTriangles, RwUInt32 format);
DECL_FASTCALL_SIMPLE_GLO(RpGeometryAddMorphTargets, _Z25RpGeometryAddMorphTargetsP10RpGeometryi, RwInt32, RpGeometry* geometry, RwInt32 mtcount);
DECL_FASTCALL_SIMPLE_GLO(RpGeometryAddMorphTarget, _Z24RpGeometryAddMorphTargetP10RpGeometry, RwInt32, RpGeometry* geometry);
DECL_FASTCALL_SIMPLE_GLO(RpGeometryRemoveMorphTarget, _Z27RpGeometryRemoveMorphTargetP10RpGeometryi, RpGeometry*, RpGeometry* geometry, RwInt32 morphTargetIndex);
DECL_FASTCALL_SIMPLE_GLO(RpGeometryTriangleSetVertexIndices, _Z34RpGeometryTriangleSetVertexIndicesPK10RpGeometryP10RpTrianglettt, const RpGeometry*, const RpGeometry* geometry, RpTriangle* triangle, RwUInt16 vert1, RwUInt16 vert2, RwUInt16 vert3);
DECL_FASTCALL_SIMPLE_GLO(RpGeometryTriangleSetMaterial, _Z29RpGeometryTriangleSetMaterialP10RpGeometryP10RpTriangleP10RpMaterial, RpGeometry*, RpGeometry* geometry, RpTriangle* triangle, RpMaterial* material);
DECL_FASTCALL_SIMPLE_GLO(RpGeometryTriangleGetVertexIndices, _Z34RpGeometryTriangleGetVertexIndicesPK10RpGeometryPK10RpTrianglePtS5_S5_, const RpGeometry*, const RpGeometry* geometry, const RpTriangle* triangle, RwUInt16* vert1, RwUInt16* vert2, RwUInt16* vert3);
DECL_FASTCALL_SIMPLE_GLO(RpGeometryTriangleGetMaterial, _Z29RpGeometryTriangleGetMaterialPK10RpGeometryPK10RpTriangle, RpMaterial*, const RpGeometry* geometry, const RpTriangle* triangle);
DECL_FASTCALL_SIMPLE_GLO(RpGeometryForAllMaterials, _Z25RpGeometryForAllMaterialsP10RpGeometryPFP10RpMaterialS2_PvES3_, RpGeometry*, RpGeometry* geometry, RpMaterialCallBack fpCallBack, void* pData);
DECL_FASTCALL_SIMPLE_GLO(RpGeometryForAllMeshes, _Z22RpGeometryForAllMeshesPK10RpGeometryPFP6RpMeshS3_P12RpMeshHeaderPvES6_, const RpGeometry*, const RpGeometry* geometry, RpMeshCallBack fpCallBack, void* pData);
DECL_FASTCALL_SIMPLE_GLO(_rpGeometryAddRef, _Z17_rpGeometryAddRefP10RpGeometry, RpGeometry*, RpGeometry* geometry);
DECL_FASTCALL_SIMPLE_GLO(RpGeometryRegisterPlugin, _Z24RpGeometryRegisterPluginijPFPvS_iiES1_PFS_S_PKviiE, RwInt32, RwInt32 size, RwUInt32 pluginID, RwPluginObjectConstructor constructCB, RwPluginObjectDestructor destructCB, RwPluginObjectCopy copyCB);
DECL_FASTCALL_SIMPLE_GLO(RpGeometryRegisterPluginStream, _Z30RpGeometryRegisterPluginStreamjPFP8RwStreamS0_iPviiEPFS0_S0_iPKviiEPFiS5_iiE, RwInt32, RwUInt32 pluginID, RwPluginDataChunkReadCallBack readCB, RwPluginDataChunkWriteCallBack writeCB, RwPluginDataChunkGetSizeCallBack getSizeCB);
DECL_FASTCALL_SIMPLE_GLO(RpGeometrySetStreamAlwaysCallBack, _Z33RpGeometrySetStreamAlwaysCallBackjPFiPviiE, RwInt32, RwUInt32 pluginID, RwPluginDataChunkAlwaysCallBack alwaysCB);
DECL_FASTCALL_SIMPLE_GLO(RpGeometryGetPluginOffset, _Z25RpGeometryGetPluginOffsetj, RwInt32, RwUInt32 pluginID);
DECL_FASTCALL_SIMPLE_GLO(RpGeometryValidatePlugins, _Z25RpGeometryValidatePluginsPK10RpGeometry, RwBool, const RpGeometry* geometry);
DECL_FASTCALL_SIMPLE_GLO(RpGeometryStreamGetSize, _Z23RpGeometryStreamGetSizePK10RpGeometry, RwUInt32, const RpGeometry* geometry);
DECL_FASTCALL_SIMPLE_GLO(RpGeometryStreamWrite, _Z21RpGeometryStreamWritePK10RpGeometryP8RwStream, const RpGeometry*, const RpGeometry* geometry, RwStream* stream);
DECL_FASTCALL_SIMPLE_GLO(RpGeometryStreamRead, _Z20RpGeometryStreamReadP8RwStream, RpGeometry*, RwStream* stream);
DECL_FASTCALL_SIMPLE_GLO(_rpGeometryChunkInfoRead, _Z24_rpGeometryChunkInfoReadP8RwStreamP19RpGeometryChunkInfoPi, RpGeometryChunkInfo*, RwStream* stream, RpGeometryChunkInfo* geometryChunkInfo, RwInt32* bytesRead);
DECL_FASTCALL_SIMPLE_GLO(RpGeometryIsCorrectlySorted, _Z27RpGeometryIsCorrectlySortedPK10RpGeometryPi, const RpGeometry*, const RpGeometry* geometry, RwBool* result);
DECL_FASTCALL_SIMPLE_GLO(RpGeometrySortByMaterial, _Z24RpGeometrySortByMaterialPK10RpGeometryPFvS1_PS_PttE, RpGeometry*, const RpGeometry* source, RpGeometrySortByMaterialCallBack callback);
DECL_FASTCALL_SIMPLE_GLO(_rpGeometryNeedsPrecideUVs, _Z26_rpGeometryNeedsPrecideUVsPK10RpGeometryi, bool, const RpGeometry* geometry, int texCoordIndex);
DECL_FASTCALL_SIMPLE_GLO(_rpGeometryNeedsPreciseSkin, _Z27_rpGeometryNeedsPreciseSkinPK10RpGeometryP6RpSkin, bool, const RpGeometry* geometry, RpSkin* skin);
DECL_FASTCALL_SIMPLE_GLO(_rpGeometryNativeCompressNormal, _Z31_rpGeometryNativeCompressNormalf, RwInt8, float val);
DECL_FASTCALL_SIMPLE_GLO(_rpGeometryNativeCompressTexCoord, _Z33_rpGeometryNativeCompressTexCoordf, RwInt16, float val);
DECL_FASTCALL_SIMPLE_GLO(_rpGeometryNativeWrite, _Z22_rpGeometryNativeWriteP8RwStreamPK10RpGeometry, RwStream*, RwStream* stream, const RpGeometry* geometry);
DECL_FASTCALL_SIMPLE_GLO(_rpGeometryNativeRead, _Z21_rpGeometryNativeReadP8RwStreamP10RpGeometry, RpGeometry*, RwStream* stream, RpGeometry* geometry);
DECL_FASTCALL_SIMPLE_GLO(_rpGeometryNativeSize, _Z21_rpGeometryNativeSizePK10RpGeometry, RwInt32, const RpGeometry* geometry);
DECL_FASTCALL_SIMPLE_GLO(ConstructGeometryArray, _ZN15CClothesBuilder22ConstructGeometryArrayEPP10RpGeometryPjfff, void, RpGeometry** ppGeometry, uint32_t* pModelKeys, float normal, float fatness, float strength);
// CClothesBuilder::BlendGeometry is overloaded, and DECL_FASTCALL_SIMPLE_GLO
// declares a variable -- so the two flavours need distinct names. The inline
// wrappers below give the overloaded spelling back.
DECL_FASTCALL_SIMPLE_GLO(BlendGeometry1, _ZN15CClothesBuilder13BlendGeometryEP7RpClumpPKcS3_S3_fff, RpGeometry*, RpClump* pClump, const char* pName1, const char* pName2, const char* pName3, float r1, float r2, float r3);
DECL_FASTCALL_SIMPLE_GLO(BlendGeometry2, _ZN15CClothesBuilder13BlendGeometryEP7RpClumpPKcS3_ff, RpGeometry*, RpClump* pClump, const char* pName1, const char* pName2, float r1, float r2);

inline RpGeometry* BlendGeometry(RpClump* pClump, const char* pName1, const char* pName2, const char* pName3, float r1, float r2, float r3)
{
    return BlendGeometry1(pClump, pName1, pName2, pName3, r1, r2, r3);
}
inline RpGeometry* BlendGeometry(RpClump* pClump, const char* pName1, const char* pName2, float r1, float r2)
{
    return BlendGeometry2(pClump, pName1, pName2, r1, r2);
}
DECL_FASTCALL_SIMPLE_GLO(CopyGeometry, _ZN15CClothesBuilder12CopyGeometryEP7RpClumpPKcS3_, RpGeometry*, RpClump* pClump, const char* pName1, const char* pName2);
DECL_FASTCALL_SIMPLE_GLO_PLT(RpGeometry2dEffectConstructor, BYBIT(0x59C959, 0x6C0CE4), void*, void* pGeometry, RwInt32 offset, RwInt32 size);
DECL_FASTCALL_SIMPLE_GLO_PLT(RpGeometry2dEffectDestructor, BYBIT(0x59C96D, 0x6C0CF8), void*, void* pGeometry, RwInt32 offset, RwInt32 size);
DECL_FASTCALL_SIMPLE_GLO_PLT(RpGeometry2dEffectCopy, BYBIT(0x59CA29, 0x6C0E04), void*, void* pGeometry, const void* pOtherGeometry, RwInt32 offset, RwInt32 size);
DECL_FASTCALL_SIMPLE_GLO_PLT(RpGeometry2dEffectStreamRead, BYBIT(0x59CA3D, 0x6C0E18), RwStream*, RwStream* pStream, RwInt32 len, void* pData, RwInt32 offset, RwInt32 size);
DECL_FASTCALL_SIMPLE_GLO_PLT(RpGeometry2dEffectStreamWrite, BYBIT(0x59CE91, 0x6C1348), RwStream*, RwStream* pStream, RwInt32 len, const void* pData, RwInt32 offset, RwInt32 size);
DECL_FASTCALL_SIMPLE_GLO_PLT(RpGeometry2dEffectStreamGetSize, BYBIT(0x59CE93, 0x6C134C), RwInt32, const void* pData, RwInt32 offset, RwInt32 size);
DECL_FASTCALL_SIMPLE_GLO(RpGeometryReplaceOldMaterialWithNewMaterial, _Z43RpGeometryReplaceOldMaterialWithNewMaterialP10RpGeometryP10RpMaterialS2_, u8, RpGeometry* pGeometry, RpMaterial* pOldMaterial, RpMaterial* pNewMaterial);

#endif // __AML_PSDK_RPGEOMETRY_H