#ifndef __AML_PSDK_VCMATRIX_H
#define __AML_PSDK_VCMATRIX_H

#include <aml-psdk/game_vc/plugin.h>
#include <aml-psdk/gta_base/Vector.h>
#include <aml-psdk/renderware/RwMatrix.h>

DECL_CLASS(CMatrix)
    // Construct/Deconstruct functions
    inline CMatrix() : m_pAttachMatrix(NULL), m_bOwnsAttachedMatrix(false) {}
    DECL_CTORCALL_ARG_HEAD(CMatrix, _ZN7CMatrixC2EP11RwMatrixTagb, RwMatrix* matrix, bool owner)
    DECL_CTORCALL_ARG_TAIL(matrix, owner)
    DECL_CTORCALL_NAMED_ARG_HEAD(CMatrix1, CMatrix, _ZN7CMatrixC2ERKS_, CMatrix const& matrix)
    DECL_CTORCALL_ARG_TAIL(matrix)
    DECL_DTORCALL(CMatrix, _ZN7CMatrixD2Ev);

    // Member functions
    DECL_THISCALL_NAMED_HEAD(Assign, operator=, _ZN7CMatrixaSERKS_, CMatrix&, CMatrix const& matrix)
    DECL_THISCALL_TAIL(Assign, matrix)
    DECL_THISCALL_NAMED_HEAD(Add, operator+=, _ZN7CMatrixpLERKS_, CMatrix&, CMatrix const& matrix)
    DECL_THISCALL_TAIL(Add, matrix)

    DECL_THISCALL_SIMPLE(Update, _ZN7CMatrix6UpdateEv, void);
    DECL_THISCALL_SIMPLE(UpdateRW, _ZN7CMatrix8UpdateRWEv, void);
    DECL_THISCALL_SIMPLE(Detach, _ZN7CMatrix6DetachEv, void);
    DECL_THISCALL_SIMPLE(SetUnity, _ZN7CMatrix8SetUnityEv, void);
    DECL_THISCALL_SIMPLE(ResetOrientation, _ZN7CMatrix16ResetOrientationEv, void);
    DECL_THISCALL_SIMPLE(Reorthogonalise, _ZN7CMatrix15ReorthogonaliseEv, void);
    DECL_THISCALL_SIMPLE(CheckIntegrity, _ZN7CMatrix14CheckIntegrityEv, void);

    DECL_THISCALL_HEAD(Attach, _ZN7CMatrix6AttachEP11RwMatrixTagb, void, RwMatrix* matrix, bool owner)
    DECL_THISCALL_TAIL(Attach, matrix, owner)
    DECL_THISCALL_HEAD(AttachRW, _ZN7CMatrix8AttachRWEP11RwMatrixTagb, void, RwMatrix* matrix, bool owner)
    DECL_THISCALL_TAIL(AttachRW, matrix, owner)
    DECL_THISCALL_HEAD(CopyOnlyMatrix, _ZN7CMatrix14CopyOnlyMatrixERKS_, void, CMatrix const& matrix)
    DECL_THISCALL_TAIL(CopyOnlyMatrix, matrix)
    DECL_THISCALL_HEAD(CopyToRwMatrix, _ZN7CMatrix14CopyToRwMatrixEP11RwMatrixTag, RwMatrix*, RwMatrix* matrix)
    DECL_THISCALL_TAIL(CopyToRwMatrix, matrix)

    DECL_THISCALL_HEAD(SetScale, _ZN7CMatrix8SetScaleEfff, void, float x, float y, float z)
    DECL_THISCALL_TAIL(SetScale, x, y, z)
    DECL_THISCALL_NAMED_HEAD(SetScale1, SetScale, _ZN7CMatrix8SetScaleEf, void, float scale)
    DECL_THISCALL_TAIL(SetScale1, scale)
    DECL_THISCALL_HEAD(SetTranslate, _ZN7CMatrix12SetTranslateEfff, void, float x, float y, float z)
    DECL_THISCALL_TAIL(SetTranslate, x, y, z)
    DECL_THISCALL_HEAD(SetTranslateOnly, _ZN7CMatrix16SetTranslateOnlyEfff, void, float x, float y, float z)
    DECL_THISCALL_TAIL(SetTranslateOnly, x, y, z)

    DECL_THISCALL_HEAD(SetRotateXOnly, _ZN7CMatrix14SetRotateXOnlyEf, void, float angle)
    DECL_THISCALL_TAIL(SetRotateXOnly, angle)
    DECL_THISCALL_HEAD(SetRotateYOnly, _ZN7CMatrix14SetRotateYOnlyEf, void, float angle)
    DECL_THISCALL_TAIL(SetRotateYOnly, angle)
    DECL_THISCALL_HEAD(SetRotateZOnly, _ZN7CMatrix14SetRotateZOnlyEf, void, float angle)
    DECL_THISCALL_TAIL(SetRotateZOnly, angle)
    DECL_THISCALL_HEAD(SetRotateX, _ZN7CMatrix10SetRotateXEf, void, float angle)
    DECL_THISCALL_TAIL(SetRotateX, angle)
    DECL_THISCALL_HEAD(SetRotateY, _ZN7CMatrix10SetRotateYEf, void, float angle)
    DECL_THISCALL_TAIL(SetRotateY, angle)
    DECL_THISCALL_HEAD(SetRotateZ, _ZN7CMatrix10SetRotateZEf, void, float angle)
    DECL_THISCALL_TAIL(SetRotateZ, angle)
    DECL_THISCALL_HEAD(SetRotate, _ZN7CMatrix9SetRotateEfff, void, float x, float y, float z)
    DECL_THISCALL_TAIL(SetRotate, x, y, z)
    DECL_THISCALL_HEAD(RotateX, _ZN7CMatrix7RotateXEf, void, float angle)
    DECL_THISCALL_TAIL(RotateX, angle)
    DECL_THISCALL_HEAD(RotateY, _ZN7CMatrix7RotateYEf, void, float angle)
    DECL_THISCALL_TAIL(RotateY, angle)
    DECL_THISCALL_HEAD(RotateZ, _ZN7CMatrix7RotateZEf, void, float angle)
    DECL_THISCALL_TAIL(RotateZ, angle)
    DECL_THISCALL_HEAD(Rotate, _ZN7CMatrix6RotateEfff, void, float x, float y, float z)
    DECL_THISCALL_TAIL(Rotate, x, y, z)

    // Helper functions
    inline CVector& GetRight() { return right; }
    inline CVector const& GetRight() const { return right; }
    inline CVector& GetForward() { return up; }
    inline CVector const& GetForward() const { return up; }
    inline CVector& GetUp() { return at; }
    inline CVector const& GetUp() const { return at; }
    inline CVector& GetPosition() { return pos; }
    inline CVector const& GetPosition() const { return pos; }
    inline CVector GetScale() const { return { right.Magnitude(), up.Magnitude(), at.Magnitude() }; }
    inline void Translate(float x, float y, float z)
    {
        pos.x += x;
        pos.y += y;
        pos.z += z;
    }
    inline void Translate(CVector const& offset) { pos += offset; }
    inline CVector TransformVector(CVector const& vector) const
    {
        return right * vector.x + up * vector.y + at * vector.z;
    }
    inline CVector TransformPoint(CVector const& point) const { return TransformVector(point) + pos; }
    inline CVector TransformPos(CVector const& point) const { return TransformPoint(point); }
    inline CVector operator*(CVector const& point) const { return TransformPoint(point); }
    inline CMatrix operator*(CMatrix const& matrix) const
    {
        CMatrix result;
        result.right = TransformVector(matrix.right);
        result.up = TransformVector(matrix.up);
        result.at = TransformVector(matrix.at);
        result.pos = TransformPoint(matrix.pos);
        return result;
    }
    inline CMatrix& operator*=(CMatrix const& matrix)
    {
        CVector newRight = TransformVector(matrix.right);
        CVector newForward = TransformVector(matrix.up);
        CVector newUp = TransformVector(matrix.at);
        CVector newPosition = TransformPoint(matrix.pos);
        right = newRight;
        up = newForward;
        at = newUp;
        pos = newPosition;
        return *this;
    }
    inline void TransformPoints(CVector* output, i32 count, CVector const* input) const
    {
        for(i32 i = 0; i < count; ++i) output[i] = TransformPoint(input[i]);
    }
    inline void TransformVectors(CVector* output, i32 count, CVector const* input) const
    {
        for(i32 i = 0; i < count; ++i) output[i] = TransformVector(input[i]);
    }
    // Inverse transforms require an orthonormal basis.
    inline CVector InverseTransformVector(CVector const& vector) const
    {
        return { DotProduct(right, vector), DotProduct(up, vector), DotProduct(at, vector) };
    }
    inline CVector InverseTransformPoint(CVector const& point) const { return InverseTransformVector(point - pos); }
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
    CVector right;
    u32 : 32;
    CVector up;
    u32 : 32;
    CVector at;
    u32 : 32;
    CVector pos;
    u32 : 32;
    RwMatrix* m_pAttachMatrix;
    u32 m_bOwnsAttachedMatrix;
DECL_CLASS_END()
CHECKSIZE(CMatrix, 0x48, 0x50);

inline void Invert(CMatrix const& matrix, CMatrix& result)
{
    CVector right(matrix.right.x, matrix.up.x, matrix.at.x);
    CVector up(matrix.right.y, matrix.up.y, matrix.at.y);
    CVector at(matrix.right.z, matrix.up.z, matrix.at.z);
    CVector pos(-DotProduct(matrix.right, matrix.pos), -DotProduct(matrix.up, matrix.pos), -DotProduct(matrix.at, matrix.pos));
    result.right = right;
    result.up = up;
    result.at = at;
    result.pos = pos;
}
inline CMatrix Invert(CMatrix const& matrix) { return matrix.Inverted(); }
inline CVector Multiply3x3(CMatrix const& matrix, CVector const& vector) { return matrix.TransformVector(vector); }
inline CVector Multiply3x3(CVector const& vector, CMatrix const& matrix)
{
    return { DotProduct(matrix.right, vector), DotProduct(matrix.up, vector), DotProduct(matrix.at, vector) };
}

inline void CVector::FromMultiply(CMatrix const& matrix, CVector const& vector)
{
    *this = matrix.TransformPoint(vector);
}
inline void CVector::FromMultiply3X3(CMatrix const& matrix, CVector const& vector)
{
    *this = matrix.TransformVector(vector);
}

#endif // __AML_PSDK_VCMATRIX_H
