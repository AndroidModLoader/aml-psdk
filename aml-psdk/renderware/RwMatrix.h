#ifndef __AML_PSDK_RWMATRIX_H
#define __AML_PSDK_RWMATRIX_H

#include <aml-psdk/sdk_base.h>
#include "RwBase.h"
#include "RwVector.h"
#include "RwStream.h"

struct rwStreamMatrix
{
    RwV3d right;
    RwV3d up;
    RwV3d at;
    RwV3d pos;
    RwInt32 type;
};
typedef rwStreamMatrix RwMatrixChunkInfo;


struct RwMatrix
{
    RwV3d right;
    u32   flags;
    RwV3d up;
    u32   pad1;
    RwV3d at;
    u32   pad2;
    RwV3d pos;
    u32   pad3;
};

struct RwMatrixTolerance
{
    float Normal;
    float Orthogonal;
    float Identity;
};

struct RQMatrix
{
    union
    {
        float v[16];
        struct
        {
            float f11, f21, f31, f41;
            float f12, f22, f32, f42;
            float f13, f23, f33, f43;
            float f14, f24, f34, f44;
        };
    };
    bool dirty; 
};

DECL_FASTCALL_SIMPLE_GLO(RwMatrixChunkInfoRead, _Z21RwMatrixChunkInfoReadP8RwStreamP14rwStreamMatrixPi, RwMatrixChunkInfo*, RwStream *stream, RwMatrixChunkInfo *matrixChunkInfo, RwInt32 *bytesRead);
DECL_FASTCALL_SIMPLE_GLO(RwMatrixCreate, _Z14RwMatrixCreatev, RwMatrix*);
DECL_FASTCALL_SIMPLE_GLO(RwMatrixDestroy, _Z15RwMatrixDestroyP11RwMatrixTag, RwBool, RwMatrix* matrix);
DECL_FASTCALL_SIMPLE_GLO(RwMatrixInvert, _Z14RwMatrixInvertP11RwMatrixTagPKS_, RwMatrix*, RwMatrix* dst, const RwMatrix* src);
DECL_FASTCALL_SIMPLE_GLO(RwMatrixMultiply, _Z16RwMatrixMultiplyP11RwMatrixTagPKS_S2_, RwMatrix*, RwMatrix *dst, const RwMatrix *src1, const RwMatrix *src2);
DECL_FASTCALL_SIMPLE_GLO(RwMatrixOptimize, _Z16RwMatrixOptimizeP11RwMatrixTagPK17RwMatrixTolerance, RwMatrix*, RwMatrix *matrix, const RwMatrixTolerance *tolerance);
DECL_FASTCALL_SIMPLE_GLO(RwMatrixOrthoNormalize, _Z22RwMatrixOrthoNormalizeP11RwMatrixTagPKS_, RwMatrix*, RwMatrix *dst, const RwMatrix *src);
DECL_FASTCALL_SIMPLE_GLO(RwMatrixQueryRotate, _Z19RwMatrixQueryRotatePK11RwMatrixTagP5RwV3dPfS3_, RwMatrix*, const RwMatrix *matrix, RwV3d *unitAxis, RwReal *angle, RwV3d *center);
DECL_FASTCALL_SIMPLE_GLO(RwMatrixRotate, _Z14RwMatrixRotateP11RwMatrixTagPK5RwV3df15RwOpCombineType, RwMatrix*, RwMatrix *matrix, const RwV3d *axis, RwReal angle, RwOpCombineType combineOp);
DECL_FASTCALL_SIMPLE_GLO(RwMatrixRotateOneMinusCosineSine, _Z32RwMatrixRotateOneMinusCosineSineP11RwMatrixTagPK5RwV3dff15RwOpCombineType, RwMatrix*, RwMatrix *matrix, const RwV3d *unitAxis, RwReal oneMinusCosine, RwReal sine, RwOpCombineType combineOp);
DECL_FASTCALL_SIMPLE_GLO(RwMatrixScale, _Z13RwMatrixScaleP11RwMatrixTagPK5RwV3d15RwOpCombineType, RwMatrix*, RwMatrix *matrix, const RwV3d *scale, RwOpCombineType combineOp);
DECL_FASTCALL_SIMPLE_GLO(RwMatrixSetFreeListCreateParams, _Z31RwMatrixSetFreeListCreateParamsii, void, RwInt32 blockSize, RwInt32 numBlocksToPrealloc);
DECL_FASTCALL_SIMPLE_GLO(RwMatrixStreamGetSize, _Z21RwMatrixStreamGetSizePK11RwMatrixTag, RwUInt32, const RwMatrix *matrix);
DECL_FASTCALL_SIMPLE_GLO(RwMatrixStreamRead, _Z18RwMatrixStreamReadP8RwStreamP11RwMatrixTag, RwMatrix*, RwStream *stream, RwMatrix *matrix);
DECL_FASTCALL_SIMPLE_GLO(RwMatrixStreamWrite, _Z19RwMatrixStreamWritePK11RwMatrixTagP8RwStream, RwMatrix*, const RwMatrix *matrix, RwStream *stream);
DECL_FASTCALL_SIMPLE_GLO(RwMatrixTransform, _Z17RwMatrixTransformP11RwMatrixTagPKS_15RwOpCombineType, RwMatrix*, RwMatrix *matrix, const RwMatrix *transform, RwOpCombineType combineOp);
DECL_FASTCALL_SIMPLE_GLO(RwMatrixTranslate, _Z17RwMatrixTranslateP11RwMatrixTagPK5RwV3d15RwOpCombineType, RwMatrix*, RwMatrix *matrix, const RwV3d *translation, RwOpCombineType combineOp);
DECL_FASTCALL_SIMPLE_GLO(RwMatrixUpdate, _Z14RwMatrixUpdateP11RwMatrixTag, RwMatrix*, RwMatrix *matrix);
DECL_FASTCALL_SIMPLE_GLO(TestMatrix, _Z10TestMatrixP11RwMatrixTag, void, RwMatrix *pTempMatrix);
DECL_FASTCALL_SIMPLE_GLO(RwEngineGetMatrixTolerances, _Z27RwEngineGetMatrixTolerancesP17RwMatrixTolerance, RwBool, RwMatrixTolerance *const tolerance);
DECL_FASTCALL_SIMPLE_GLO(RwEngineSetMatrixTolerances, _Z27RwEngineSetMatrixTolerancesPK17RwMatrixTolerance, RwBool, const RwMatrixTolerance *const tolerance);

#endif // __AML_PSDK_RWMATRIX_H
