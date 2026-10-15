#ifndef __AML_PSDK_RPSKIN_H
#define __AML_PSDK_RPSKIN_H

#include "RpHAnim.h"

typedef void* SkinUnaligned;
struct RxPipeline;
struct RpAtomic;
struct RpGeometry;

enum RpSkinType
{
    rpNASKINTYPE = 0,
    rpSKINTYPEGENERIC = 1,
    rpSKINTYPEMATFX = 2,
    rpSKINTYPETOON = 3,
    rpSKINTYPEFORCEENUMSIZEINT = 2147483647,
};

enum RpSkinOpenGLPipeline
{
    rpNASKINOPENGLPIPELINE = 0,
    rpSKINOPENGLPIPELINEGENERIC = 1,
    rpSKINOPENGLPIPELINEMATFX = 2,
    rpSKINOPENGLPIPELINETOON = 3,
    rpSKINOPENGLPIPELINEMATFXTOON = 4,
    rpSKINOPENGLPIPELINEMAX = 5,
    rpSKINOPENGLPIPELINEFORCEENUMSIZEINT = 2147483647,
};

struct RwMatrixWeights
{
    RwReal w0;
    RwReal w1;
    RwReal w2;
    RwReal w3;
};
CHECKSIZE(RwMatrixWeights, 0x10, 0x10);

struct SkinBoneData
{
    RwUInt32 numBones;
    RwUInt32 numUsedBones;
    RwUInt8* usedBoneList;
    RwMatrix* invBoneToSkinMat;
};
CHECKSIZE(SkinBoneData, 0x10, 0x18);

struct SkinVertexMaps
{
    RwUInt32 maxWeights;
    RwUInt32* matrixIndices;
    RwMatrixWeights* matrixWeights;
};
CHECKSIZE(SkinVertexMaps, 0xC, 0x18);

struct SkinPlatformData
{
    RwUInt32 maxWeights;
};
CHECKSIZE(SkinPlatformData, 0x4, 0x4);

struct SkinSplitData
{
    RwUInt32 boneLimit;
    RwUInt32 numMeshes;
    RwUInt32 numRLE;
    RwUInt8* matrixRemapIndices;
    RwUInt8* meshRLECount;
    RwUInt8* meshRLE;
};
CHECKSIZE(SkinSplitData, 0x18, 0x28);

struct RpSkin
{
    SkinBoneData boneData;
    SkinVertexMaps vertexMaps;
    SkinPlatformData platformData;
    SkinSplitData skinSplitData;
    SkinUnaligned* unaligned;
};
CHECKSIZE(RpSkin, 0x3C, 0x68);

DECL_FASTCALL_SIMPLE_GLO(RpSkinGetOpenGLPipeline, RpSkinGetOpenGLPipeline, RxPipeline*, RpSkinOpenGLPipeline openglPipeline);
DECL_FASTCALL_SIMPLE_GLO(RpSkinAtomicGetHAnimHierarchy, RpSkinAtomicGetHAnimHierarchy, RpHAnimHierarchy*, RpAtomic const* atomic);
DECL_FASTCALL_SIMPLE_GLO(RpSkinGetVertexBoneIndices, RpSkinGetVertexBoneIndices, RwUInt32 const*, RpSkin* skin);
DECL_FASTCALL_SIMPLE_GLO(RpSkinAtomicSetType, RpSkinAtomicSetType, RpAtomic*, RpAtomic* atomic, RpSkinType type);
DECL_FASTCALL_SIMPLE_GLO(RpSkinGeometrySetSkin, RpSkinGeometrySetSkin, RpGeometry*, RpGeometry* geometry, RpSkin* skin);
DECL_FASTCALL_SIMPLE_GLO(RpSkinAtomicSetHAnimHierarchy, RpSkinAtomicSetHAnimHierarchy, RpAtomic*, RpAtomic* atomic, RpHAnimHierarchy* hierarchy);
DECL_FASTCALL_SIMPLE_GLO(RpSkinAtomicGetType, RpSkinAtomicGetType, RpSkinType, RpAtomic* atomic);
DECL_FASTCALL_SIMPLE_GLO(RpSkinGetVertexBoneWeights, RpSkinGetVertexBoneWeights, RwMatrixWeights const*, RpSkin* skin);
DECL_FASTCALL_SIMPLE_GLO(RpSkinPluginAttach, RpSkinPluginAttach, RwBool);
DECL_FASTCALL_SIMPLE_GLO(RpSkinDestroy, RpSkinDestroy, RpSkin*, RpSkin* skin);
DECL_FASTCALL_SIMPLE_GLO(RpSkinCreate, RpSkinCreate, RpSkin*, RwUInt32 numVertices, RwUInt32 numBones, RwMatrixWeights* vertexWeights, RwUInt32* vertexIndices, RwMatrix* inverseMatrices);
DECL_FASTCALL_SIMPLE_GLO(RpSkinGetSkinToBoneMatrices, RpSkinGetSkinToBoneMatrices, RwMatrix const*, RpSkin* skin);
DECL_FASTCALL_SIMPLE_GLO(RpSkinIsSplit, RpSkinIsSplit, RwBool, RpSkin* skin);
DECL_FASTCALL_SIMPLE_GLO(RpSkinGeometryGetSkin, RpSkinGeometryGetSkin, RpSkin*, RpGeometry* geometry);
DECL_FASTCALL_SIMPLE_GLO(RpSkinSetFreeListCreateParams, RpSkinSetFreeListCreateParams, void, RwInt32 blockSize, RwInt32 numBlocksToPrealloc);
DECL_FASTCALL_SIMPLE_GLO(RpSkinGetNumBones, RpSkinGetNumBones, RwUInt32, RpSkin* skin);

#endif // __AML_PSDK_RPSKIN_H
