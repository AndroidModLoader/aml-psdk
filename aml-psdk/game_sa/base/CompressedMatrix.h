#ifndef __AML_PSDK_SACOMPRESSEDMATRIX_H
#define __AML_PSDK_SACOMPRESSEDMATRIX_H

#include "../plugin.h"

struct CMatrix;

DECL_CLASS(CCompressedMatrixNotAligned)
    // Member functions
    DECL_THISCALL_HEAD(DecompressIntoFullMatrix, _ZN27CCompressedMatrixNotAligned24DecompressIntoFullMatrixER7CMatrix, void, CMatrix& matrix)
    DECL_THISCALL_TAIL(DecompressIntoFullMatrix, matrix)
    DECL_THISCALL_HEAD(CompressFromFullMatrix, _ZN27CCompressedMatrixNotAligned22CompressFromFullMatrixER7CMatrix, void, CMatrix& matrix)
    DECL_THISCALL_TAIL(CompressFromFullMatrix, matrix)

    // Member values
    float CoorX;
    float CoorY;
    float CoorZ;
    i8 Matrix_xx;
    i8 Matrix_yx;
    i8 Matrix_zx;
    i8 Matrix_xy;
    i8 Matrix_yy;
    i8 Matrix_zy;
DECL_CLASS_END()
CHECKSIZE(CCompressedMatrixNotAligned, 0x14, 0x14);

DECL_CLASS_BASED(CCompressedMatrix, CCompressedMatrixNotAligned)
    u16 : 16;
DECL_CLASS_END()
CHECKSIZE(CCompressedMatrix, 0x18, 0x18);

#endif // __AML_PSDK_SACOMPRESSEDMATRIX_H
