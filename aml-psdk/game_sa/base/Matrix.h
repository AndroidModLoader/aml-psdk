#ifndef __AML_PSDK_GTAMATRIX_H
#define __AML_PSDK_GTAMATRIX_H

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/gta_base/Vector.h>
#include <aml-psdk/renderware/RwMatrix.h>

struct CQuaternion;

struct CMatrixSerialize
{
    float xx, yx, zx, wx;
    float xy, yy, zy, wy;
    float xz, yz, zz, wz;
    float tx, ty, tz, tw;
    u32 m_pRwMat;
    bool m_owner;
};
CHECKSIZE(CMatrixSerialize, 0x48, 0x48);

DECL_CLASS(CMatrix)
    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CMatrix, _ZN7CMatrixC2EP11RwMatrixTagb, RwMatrix* matrix, bool temporary)
    DECL_CTORCALL_ARG_TAIL(matrix, temporary)
    DECL_CTORCALL_NAMED_ARG_HEAD(CMatrix1, CMatrix, _ZN7CMatrixC2ERK16CMatrixSerialize, CMatrixSerialize const& matrix)
    DECL_CTORCALL_ARG_TAIL(matrix)
    DECL_CTORCALL_NAMED_ARG_HEAD(CMatrix2, CMatrix, _ZN7CMatrixC2ERKS_, CMatrix const& matrix)
    DECL_CTORCALL_ARG_TAIL(matrix)
    DECL_DTORCALL(CMatrix, _ZN7CMatrixD2Ev);

    // Member functions
    DECL_THISCALL_NAMED_HEAD(Assign, operator=, _ZN7CMatrixaSERKS_, CMatrix&, const CMatrix &matrix)
    DECL_THISCALL_TAIL(Assign, matrix)

    DECL_THISCALL_NAMED_HEAD(Assign1, operator=, _ZN7CMatrixaSERK16CMatrixSerialize, CMatrix&, const CMatrixSerialize &matrix)
    DECL_THISCALL_TAIL(Assign1, matrix)

    DECL_THISCALL_NAMED_HEAD(Add, operator+=, _ZN7CMatrixpLERKS_, CMatrix&, const CMatrix &matrix)
    DECL_THISCALL_TAIL(Add, matrix)

    DECL_THISCALL_NAMED_HEAD(SetRotate1, SetRotate, _ZN7CMatrix9SetRotateERK11CQuaternion, void, CQuaternion const& quat)
    DECL_THISCALL_TAIL(SetRotate1, quat)
    DECL_THISCALL_SIMPLE(Update, _ZN7CMatrix6UpdateEv, void);
    DECL_THISCALL_SIMPLE(UpdateRW, _ZNK7CMatrix8UpdateRWEv, void);
    DECL_THISCALL_SIMPLE(Detach, _ZN7CMatrix6DetachEv, void);
    DECL_THISCALL_SIMPLE(SetUnity, _ZN7CMatrix8SetUnityEv, void);
    DECL_THISCALL_SIMPLE(ResetOrientation, _ZN7CMatrix16ResetOrientationEv, void);
    DECL_THISCALL_SIMPLE(Reorthogonalise, _ZN7CMatrix15ReorthogonaliseEv, void);
    DECL_THISCALL_SIMPLE(CheckIntegrity, _ZN7CMatrix14CheckIntegrityEv, void);

    DECL_THISCALL_HEAD(ConvertToEulerAngles, _ZN7CMatrix20ConvertToEulerAnglesERfS0_S0_i, void, float &x, float &y, float &z, i32 order)
    DECL_THISCALL_TAIL(ConvertToEulerAngles, x, y, z, order)

    DECL_THISCALL_HEAD(ConvertFromEulerAngles, _ZN7CMatrix22ConvertFromEulerAnglesEfffi, void, float x, float y, float z, i32 order)
    DECL_THISCALL_TAIL(ConvertFromEulerAngles, x, y, z, order)

    DECL_THISCALL_HEAD(Attach, _ZN7CMatrix6AttachEP11RwMatrixTagb, void, RwMatrix *pRwMat, bool owner)
    DECL_THISCALL_TAIL(Attach, pRwMat, owner)

    DECL_THISCALL_HEAD(AttachRW, _ZN7CMatrix8AttachRWEP11RwMatrixTagb, void, RwMatrix *pRwMat, bool owner)
    DECL_THISCALL_TAIL(AttachRW, pRwMat, owner)

    DECL_THISCALL_HEAD(UpdateMatrix, _ZN7CMatrix12UpdateMatrixEP11RwMatrixTag, void, RwMatrix *pMatrix)
    DECL_THISCALL_TAIL(UpdateMatrix, pMatrix)

    DECL_THISCALL_HEAD(UpdateRwMatrix, _ZNK7CMatrix14UpdateRwMatrixEP11RwMatrixTag, void, RwMatrix *pRwMatrix)
    DECL_THISCALL_TAIL(UpdateRwMatrix, pRwMatrix)

    DECL_THISCALL_HEAD(CopyOnlyMatrix, _ZN7CMatrix14CopyOnlyMatrixERKS_, void, const CMatrix &m)
    DECL_THISCALL_TAIL(CopyOnlyMatrix, m)

    DECL_THISCALL_HEAD(SetScale, _ZN7CMatrix8SetScaleEfff, void, float sx, float sy, float sz)
    DECL_THISCALL_TAIL(SetScale, sx, sy, sz)

    DECL_THISCALL_HEAD(SetScale2, _ZN7CMatrix8SetScaleEf, void, float s)
    DECL_THISCALL_TAIL(SetScale2, s)

    DECL_THISCALL_HEAD(SetTranslate, _ZN7CMatrix12SetTranslateEfff, void, float tx, float ty, float tz)
    DECL_THISCALL_TAIL(SetTranslate, tx, ty, tz)

    DECL_THISCALL_HEAD(SetTranslateOnly, _ZN7CMatrix16SetTranslateOnlyEfff, void, float tx, float ty, float tz)
    DECL_THISCALL_TAIL(SetTranslateOnly, tx, ty, tz)

    DECL_THISCALL_HEAD(SetRotateXOnly, _ZN7CMatrix14SetRotateXOnlyEf, void, float a)
    DECL_THISCALL_TAIL(SetRotateXOnly, a)

    DECL_THISCALL_HEAD(SetRotateYOnly, _ZN7CMatrix14SetRotateYOnlyEf, void, float a)
    DECL_THISCALL_TAIL(SetRotateYOnly, a)

    DECL_THISCALL_HEAD(SetRotateZOnly, _ZN7CMatrix14SetRotateZOnlyEf, void, float a)
    DECL_THISCALL_TAIL(SetRotateZOnly, a)

    DECL_THISCALL_HEAD(SetRotateX, _ZN7CMatrix10SetRotateXEf, void, float a)
    DECL_THISCALL_TAIL(SetRotateX, a)

    DECL_THISCALL_HEAD(SetRotateY, _ZN7CMatrix10SetRotateYEf, void, float a)
    DECL_THISCALL_TAIL(SetRotateY, a)

    DECL_THISCALL_HEAD(SetRotateZ, _ZN7CMatrix10SetRotateZEf, void, float a)
    DECL_THISCALL_TAIL(SetRotateZ, a)

    DECL_THISCALL_HEAD(SetRotate, _ZN7CMatrix9SetRotateEfff, void, float ax, float ay, float az)
    DECL_THISCALL_TAIL(SetRotate, ax, ay, az)

    DECL_THISCALL_HEAD(RotateX, _ZN7CMatrix7RotateXEf, void, float a)
    DECL_THISCALL_TAIL(RotateX, a)

    DECL_THISCALL_HEAD(RotateY, _ZN7CMatrix7RotateYEf, void, float a)
    DECL_THISCALL_TAIL(RotateY, a)

    DECL_THISCALL_HEAD(RotateZ, _ZN7CMatrix7RotateZEf, void, float a)
    DECL_THISCALL_TAIL(RotateZ, a)

    DECL_THISCALL_HEAD(Rotate, _ZN7CMatrix6RotateEfff, void, float ax, float ay, float az)
    DECL_THISCALL_TAIL(Rotate, ax, ay, az)

    DECL_THISCALL_HEAD(ForceUpVector, _ZN7CMatrix13ForceUpVectorE7CVector, void, CVector NewUp)
    DECL_THISCALL_TAIL(ForceUpVector, NewUp)

    DECL_THISCALL_HEAD(CopyToRwMatrix, _ZNK7CMatrix14CopyToRwMatrixEP11RwMatrixTag, RwMatrix*, RwMatrix *pMatrix)
    DECL_THISCALL_TAIL(CopyToRwMatrix, pMatrix)

    // Helper functions
    inline CMatrix()
    {
        m_pAttachMatrix = NULL;
        m_bOwnsAttachedMatrix = false;
    }
    inline CVector& GetRight() { return right; }
    inline const CVector& GetRight() const { return right; }
    inline CVector& GetForward() { return up; }
    inline const CVector& GetForward() const { return up; }
    inline CVector& GetUp() { return at; }
    inline const CVector& GetUp() const { return at; }
    inline CVector& GetPosition() { return pos; }
    inline const CVector& GetPosition() const { return pos; }
    inline CVector GetScale() const { return { right.Magnitude(), up.Magnitude(), at.Magnitude() }; }
    inline void SetScale(float scale) { SetScale2(scale); }
    inline void Translate(float x, float y, float z)
    {
        pos.x += x;
        pos.y += y;
        pos.z += z;
    }
    inline void Translate(CVector const& offset) { pos += offset; }
    inline CMatrix operator*(CMatrix const& matrix) const
    {
        CMatrix result;
        result.right = *this * matrix.right;
        result.up = *this * matrix.up;
        result.at = *this * matrix.at;
        result.pos = *this * matrix.pos + pos;
        return result;
    }
    inline CMatrix& operator*=(CMatrix const& matrix)
    {
        CVector newRight = *this * matrix.right;
        CVector newForward = *this * matrix.up;
        CVector newUp = *this * matrix.at;
        CVector newPosition = *this * matrix.pos + pos;
        right = newRight;
        up = newForward;
        at = newUp;
        pos = newPosition;
        return *this;
    }
    inline CVector operator*(CVector const& vector) const
    {
        CVector result;
        result.x = this->right.x * vector.x + this->up.x * vector.y + this->at.x * vector.z;
        result.y = this->right.y * vector.x + this->up.y * vector.y + this->at.y * vector.z;
        result.z = this->right.z * vector.x + this->up.z * vector.y + this->at.z * vector.z;
        return result;
    }
    inline CVector TransformVector(CVector& v) const
    {
        return *this * v;
    }
    inline CVector TransformPos(CVector& v) const
    {
        return TransformVector(v) + pos;
    }
    inline CVector TransformPoint(CVector& v) const { return TransformPos(v); }
    inline void TransformPoints(CVector* output, i32 count, CVector const* input) const
    {
        for(i32 i = 0; i < count; ++i) output[i] = *this * input[i] + pos;
    }
    inline void TransformVectors(CVector* output, i32 count, CVector const* input) const
    {
        for(i32 i = 0; i < count; ++i) output[i] = *this * input[i];
    }
    // Inverse transforms require an orthonormal basis.
    inline CVector InverseTransformVector(CVector& v) const
    {
        return { DotProduct(right, v), DotProduct(up, v), DotProduct(at, v) };
    }
    inline CVector InverseTransformPoint(CVector const& point) const
    {
        CVector offset = point - pos;
        return InverseTransformVector(offset);
    }
    inline CMatrix Inverted() const
    {
        CMatrix result;
        result.right = { right.x, up.x, at.x };
        result.up = { right.y, up.y, at.y };
        result.at = { right.z, up.z, at.z };
        result.pos = { -DotProduct(right, pos), -DotProduct(up, pos), -DotProduct(at, pos) };
        return result;
    }

    // Member values
    CVector   right;
    float     flags;
    CVector   up;
    float     pad1;
    CVector   at;
    float     pad2;
    CVector   pos;
    float     pad3;
    RwMatrix* m_pAttachMatrix;
    unsigned int m_bOwnsAttachedMatrix;
DECL_CLASS_END()
CHECKSIZE(CMatrix, 0x48, 0x50);

#endif // __AML_PSDK_GTAMATRIX_H
