#ifndef __AML_PSDK_RTQUAT_H
#define __AML_PSDK_RTQUAT_H

#include "RwMatrix.h"

struct RtQuat
{
    RwV3d imag;
    RwReal real;
};
CHECKSIZE(RtQuat, 0x10, 0x10);

struct RtQuatSlerpCache
{
    RtQuat raFrom;
    RtQuat raTo;
    RwReal omega;
    RwBool nearlyZeroOm;
};
CHECKSIZE(RtQuatSlerpCache, 0x28, 0x28);

struct RtQuatSlerpArgandCache
{
    RtQuat logTo;
    RtQuat logBase;
};
CHECKSIZE(RtQuatSlerpArgandCache, 0x20, 0x20);

struct RtSlerp
{
    RwInt32 matRefMask;
    RwMatrix* startMat;
    RwMatrix* endMat;
    RwV3d axis;
    RwReal angle;
    RwBool useLerp;
};
CHECKSIZE(RtSlerp, 0x20, 0x30);

enum RtSlerpRefFlag : RwInt32
{
    rtSLERPREFNONE = 0,
    rtSLERPREFSTARTMAT = 0x1,
    rtSLERPREFENDMAT = 0x2,
    rtSLERPREFALL = -1
};

DECL_FASTCALL_SIMPLE_GLO(RtQuatConvertFromMatrix, _Z23RtQuatConvertFromMatrixP6RtQuatPK11RwMatrixTag, RwBool, RtQuat* quat, RwMatrix const* matrix);
DECL_FASTCALL_SIMPLE_GLO(RtQuatRotate, _Z12RtQuatRotateP6RtQuatPK5RwV3df15RwOpCombineType, RtQuat*, RtQuat* quat, RwV3d const* axis, RwReal angle, RwOpCombineType combineOp);
DECL_FASTCALL_SIMPLE_GLO(RtQuatQueryRotate, _Z17RtQuatQueryRotatePK6RtQuatP5RwV3dPf, RtQuat const*, RtQuat const* quat, RwV3d* axis, RwReal* angle);
DECL_FASTCALL_SIMPLE_GLO(RtQuatTransformVectors, _Z22RtQuatTransformVectorsP5RwV3dPKS_iPK6RtQuat, RwV3d*, RwV3d* out, RwV3d const* in, RwInt32 count, RtQuat const* quat);
DECL_FASTCALL_SIMPLE_GLO(RtQuatModulus, _Z13RtQuatModulusP6RtQuat, RwReal, RtQuat* quat);
DECL_FASTCALL_SIMPLE_GLO(RtQuatSetupSlerpCache, _Z21RtQuatSetupSlerpCacheP6RtQuatS0_P16RtQuatSlerpCache, void, RtQuat* from, RtQuat* to, RtQuatSlerpCache* cache);
DECL_FASTCALL_SIMPLE_GLO(RtQuatSetupSlerpArgandCache, _Z27RtQuatSetupSlerpArgandCacheP6RtQuatS0_P22RtQuatSlerpArgandCache, void, RtQuat* from, RtQuat* to, RtQuatSlerpArgandCache* cache);
DECL_FASTCALL_SIMPLE_GLO(RtSlerpCreate, _Z13RtSlerpCreatei, RtSlerp*, RwInt32 matRefMask);
DECL_FASTCALL_SIMPLE_GLO(RtSlerpDestroy, _Z14RtSlerpDestroyP7RtSlerp, void, RtSlerp* slerp);
DECL_FASTCALL_SIMPLE_GLO(RtSlerpInitialize, _Z17RtSlerpInitializeP7RtSlerpP11RwMatrixTagS2_, RtSlerp*, RtSlerp* slerp, RwMatrix* start, RwMatrix* end);
DECL_FASTCALL_SIMPLE_GLO(RtSlerpGetMatrix, _Z16RtSlerpGetMatrixP7RtSlerpP11RwMatrixTagf, RwMatrix*, RtSlerp* slerp, RwMatrix* matrix, RwReal progress);
DECL_FASTCALL_SIMPLE_GLO(RtSlerpSetLerp, _Z14RtSlerpSetLerpP7RtSlerpi, RtSlerp*, RtSlerp* slerp, RwBool useLerp);

inline void RtQuatInit(RtQuat* quat, RwReal x, RwReal y, RwReal z, RwReal w)
{
    quat->imag.Set(x, y, z);
    quat->real = w;
}
inline void RtQuatAssign(RtQuat* out, RtQuat const* in) { *out = *in; }
inline void RtQuatAdd(RtQuat* out, RtQuat const* a, RtQuat const* b)
{
    out->imag = a->imag + b->imag;
    out->real = a->real + b->real;
}
inline void RtQuatSub(RtQuat* out, RtQuat const* a, RtQuat const* b)
{
    out->imag = a->imag - b->imag;
    out->real = a->real - b->real;
}
inline void RtQuatScale(RtQuat* out, RtQuat const* in, RwReal scale)
{
    out->imag = in->imag * scale;
    out->real = in->real * scale;
}
inline void RtQuatConjugate(RtQuat* out, RtQuat const* in)
{
    out->imag = in->imag * -1.0f;
    out->real = in->real;
}
inline RwReal RtQuatModulusSquared(RtQuat const* quat) { return quat->imag.MagnitudeSqr() + quat->real * quat->real; }
#endif // __AML_PSDK_RTQUAT_H
