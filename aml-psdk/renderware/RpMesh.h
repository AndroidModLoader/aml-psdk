#ifndef __AML_PSDK_RPMESH_H
#define __AML_PSDK_RPMESH_H

#include <aml-psdk/sdk_base.h>
#include "RwBase.h"
#include "RwObject.h"
#include "RpMaterial.h"

typedef RwUInt16 RxVertexIndex;

enum RpMeshHeaderFlags : RwInt32
{
    rpMESHHEADERTRISTRIP = 0x1,   /**< Grouped as tristrips */
    rpMESHHEADERTRIFAN = 0x2,     /**< Grouped as trifans */
    rpMESHHEADERLINELIST = 0x4,   /**< Grouped as lines */
    rpMESHHEADERPOLYLINE = 0x8,   /**< Grouped as polylines */
    rpMESHHEADERPOINTLIST = 0x10, /**< Grouped as points */
    rpMESHHEADERPRIMMASK = 0xFF,  /**< Mask for the primitive type */
    rpMESHHEADERUNINDEXED = 0x100,/**< Vertices are in order, no index data */
};

/* One batch of indices sharing a single material. */
struct RpMesh
{
    RxVertexIndex *indices;
    RwUInt32       numIndices;
    RpMaterial    *material;    /* Material the batch is rendered with */
    RwUInt32       indexOffset; /* Offset into the geometry's index buffer */
};

/* Header of the mesh array. The RpMesh entries follow it in memory --
 * use RpMeshHeaderGetMeshes() to reach the first one. */
struct RpMeshHeader
{
    RwUInt32  flags;
    RwUInt16  numMeshes;          /* Number of meshes following the header */
    RwUInt16  serialNum;          /* Bumped whenever the meshes change */
    RwUInt32  totalIndicesInMesh; /* Sum of numIndices over all meshes */
    RwUInt32  firstMeshOffset;    /* Bytes from this header to mesh [0] */
    uintptr_t indexBuffer;        /* Mobile: native index buffer handle */
};

/* The mesh array is appended right after the header. */
inline RpMesh* RpMeshHeaderGetMeshes(RpMeshHeader *header)
{
    return (RpMesh*)((uintptr_t)(header + 1) + header->firstMeshOffset);
}

/* Unsorted triangle soup handed to the tri-stripper, which turns it into an
 * RpMeshHeader. Only relevant if you install your own strip method. */
struct RpBuildMeshTriangle
{
    RwUInt16    vertIndex[3];
    RpMaterial *material;
};

struct RpBuildMesh
{
    RwUInt32             triangleBufferSize;
    RwUInt32             numTriangles;
    RpBuildMeshTriangle *meshTriangles;
};

typedef RpMeshHeader *(*RpTriStripMeshCallBack)(RpBuildMesh *buildMesh, void *data);

CHECKSIZE(RpMesh, 0x10, 0x20);
CHECKSIZE(RpMeshHeader, 0x14, 0x18);
CHECKSIZE(RpBuildMeshTriangle, 0xC, 0x10);
CHECKSIZE(RpBuildMesh, 0xC, 0x10);

DECL_FASTCALL_SIMPLE_GLO(_rpMeshClose, _Z12_rpMeshClosePvii, void*, void* instance, RwInt32 offset, RwInt32 size);
DECL_FASTCALL_SIMPLE_GLO(_rpMeshDestroy, _Z14_rpMeshDestroyP12RpMeshHeader, RwBool, RpMeshHeader* mesh);
DECL_FASTCALL_SIMPLE_GLO(_rpMeshGetNextSerialNumber, _Z26_rpMeshGetNextSerialNumberv, RwInt16);
DECL_FASTCALL_SIMPLE_GLO(_rpMeshHeaderCreate, _Z19_rpMeshHeaderCreatej, RpMeshHeader*, RwUInt32 size);
DECL_FASTCALL_SIMPLE_GLO(_rpMeshHeaderDestroy, _Z20_rpMeshHeaderDestroyP12RpMeshHeader, void, RpMeshHeader* meshHeader);
DECL_FASTCALL_SIMPLE_GLO(_rpMeshHeaderForAllMeshes, _Z25_rpMeshHeaderForAllMeshesP12RpMeshHeaderPFP6RpMeshS2_S0_PvES3_, RpMeshHeader*, RpMeshHeader* meshHeader, RpMeshCallBack fpCallBack, void* pData);
DECL_FASTCALL_SIMPLE_GLO(_rpMeshOpen, _Z11_rpMeshOpenPvii, void*, void* instance, RwInt32 offset, RwInt32 size);
DECL_FASTCALL_SIMPLE_GLO(_rpMeshOptimise, _Z15_rpMeshOptimiseP11RpBuildMeshj, RpMeshHeader*, RpBuildMesh* mesh, RwUInt32 flags);
DECL_FASTCALL_SIMPLE_GLO(_rpMeshRead, _Z11_rpMeshReadP8RwStreamPKvPK14RpMaterialList, RpMeshHeader*, RwStream* stream, const void* object, const RpMaterialList* matList);
DECL_FASTCALL_SIMPLE_GLO(_rpMeshSize, _Z11_rpMeshSizePK12RpMeshHeaderPKv, RwInt32, const RpMeshHeader* meshHeader, const void* object);
DECL_FASTCALL_SIMPLE_GLO(_rpMeshWrite, _Z12_rpMeshWritePK12RpMeshHeaderPKvP8RwStreamPK14RpMaterialList, RwStream*, const RpMeshHeader* meshHeader, const void* object, RwStream* stream, const RpMaterialList* matList);
DECL_FASTCALL_SIMPLE_GLO(RpMeshGetTriStripMethod, _Z23RpMeshGetTriStripMethodPPFP12RpMeshHeaderP11RpBuildMeshPvEPS3_, RwBool, RpTriStripMeshCallBack* callback, void** data);
DECL_FASTCALL_SIMPLE_GLO(RpMeshSetTriStripMethod, _Z23RpMeshSetTriStripMethodPFP12RpMeshHeaderP11RpBuildMeshPvES3_, RwBool, RpTriStripMeshCallBack callback, void* data);

#endif // __AML_PSDK_RPMESH_H
