#ifndef __AML_PSDK_GTAQUAT_H
#define __AML_PSDK_GTAQUAT_H

#include <aml-psdk/gta_base/Vector.h>
#include <aml-psdk/renderware/RwMatrix.h>

DECL_CLASS(CQuaternion)
    // Member functions
    DECL_THISCALL_HEAD(Set, _ZN11CQuaternion3SetERK11RwMatrixTag, void, const RwMatrix &mat)
    DECL_THISCALL_TAIL(Set, mat)

    DECL_THISCALL_NAMED_HEAD(Set1, Set, _ZN11CQuaternion3SetEfff, void, float ax, float ay, float az)
    DECL_THISCALL_TAIL(Set1, ax, ay, az)

    DECL_THISCALL_NAMED_HEAD(Set2, Set, _ZN11CQuaternion3SetEP5RwV3df, void, RwV3d *pVec, float fRotation)
    DECL_THISCALL_TAIL(Set2, pVec, fRotation)

    DECL_THISCALL_HEAD(Get, _ZNK11CQuaternion3GetEP11RwMatrixTag, void, RwMatrix *pmat)
    DECL_THISCALL_TAIL(Get, pmat)

    DECL_THISCALL_NAMED_HEAD(Get1, Get, _ZNK11CQuaternion3GetEPfS0_S0_, void, float *pax, float *pay, float *paz)
    DECL_THISCALL_TAIL(Get1, pax, pay, paz)

    DECL_THISCALL_NAMED_HEAD(Get2, Get, _ZNK11CQuaternion3GetEP5RwV3dPf, void, RwV3d *pVec, float *fRotation)
    DECL_THISCALL_TAIL(Get2, pVec, fRotation)

    DECL_THISCALL_HEAD(Multiply, _ZN11CQuaternion8MultiplyERKS_S1_, void, const CQuaternion &quat1, const CQuaternion &quat2)
    DECL_THISCALL_TAIL(Multiply, quat1, quat2)

    DECL_THISCALL_HEAD(Slerp, _ZN11CQuaternion5SlerpERKS_S1_fff, void, const CQuaternion &quatStart, const CQuaternion &quatEnd, float fTheta, float fOOSinTheta, float fInterpValue)
    DECL_THISCALL_TAIL(Slerp, quatStart, quatEnd, fTheta, fOOSinTheta, fInterpValue)

    DECL_THISCALL_NAMED_HEAD(Slerp1, Slerp, _ZN11CQuaternion5SlerpERKS_S1_f, void, const CQuaternion &quatStart, const CQuaternion &quatEnd, float fInterpValue)
    DECL_THISCALL_TAIL(Slerp1, quatStart, quatEnd, fInterpValue)

    // Helper functions
    inline void operator+=(CQuaternion const& right)
    {
        imag += right.imag;
        real += right.real;
    }
    inline void operator-=(CQuaternion const& right)
    {
        imag -= right.imag;
        real -= right.real;
    }
    inline void operator*=(float multiplier) { Scale(multiplier); }
    inline void Scale(float multiplier)
    {
        imag *= multiplier;
        real *= multiplier;
    }
    inline void Conjugate()
    {
        imag.x = -imag.x;
        imag.y = -imag.y;
        imag.z = -imag.z;
    }
    inline float GetLengthSquared()
    {
        return SQ(real) + imag.MagnitudeSqr();
    }
    inline void Copy(CQuaternion const& from)
    {
        *this = from;
    }
    inline float Dot(CQuaternion const& a)
    {
        return (real * a.real + imag.x * a.imag.x + imag.y * a.imag.y + imag.z * a.imag.z);
    }
    inline void Normalise()
    {
        float norm = GetLengthSquared();
        if(norm == 0.0f)
        {
            real = 1.0;
        }
        else
        {
            float invNormSqrt = 1.0 / sqrtf(norm);
            imag.x = invNormSqrt * imag.x;
            imag.y = invNormSqrt * imag.y;
            imag.z = invNormSqrt * imag.z;
            real = invNormSqrt * real;
        }
    }
    inline float GetLength() const { return sqrtf(imag.MagnitudeSqr() + SQ(real)); }
    inline bool IsNormalized() const { return fabsf(imag.MagnitudeSqr() + SQ(real) - 1.0f) < 0.001f; }
    inline CQuaternion Conjugated() const
    {
        CQuaternion result = *this;
        result.Conjugate();
        return result;
    }
    inline CQuaternion Normalized() const
    {
        CQuaternion result = *this;
        result.Normalise();
        return result;
    }
    inline CQuaternion operator*(CQuaternion const& right) const
    {
        CQuaternion result;
        result.imag = imag.Cross(right.imag) + imag * right.real + right.imag * real;
        result.real = real * right.real - imag.Dot(right.imag);
        return result;
    }
    inline CQuaternion& operator*=(CQuaternion const& right)
    {
        *this = *this * right;
        return *this;
    }
    inline CQuaternion Inverted() const
    {
        float norm = imag.MagnitudeSqr() + SQ(real);
        CQuaternion result;
        if(norm == 0.0f)
        {
            result.imag.Set(0.0f);
            result.real = 1.0f;
        }
        else
        {
            result.imag = imag * (-1.0f / norm);
            result.real = real / norm;
        }
        return result;
    }
    inline CVector RotateVector(CVector const& vector) const
    {
        float norm = imag.MagnitudeSqr() + SQ(real);
        if(norm == 0.0f) return vector;
        CVector cross = imag.Cross(vector);
        return vector + (cross * real + imag.Cross(cross)) * (2.0f / norm);
    }

    // Member values
    CVector imag;
    float real;
DECL_CLASS_END()
CHECKSIZE(CQuaternion, 0x10, 0x10);

#endif // __AML_PSDK_GTAQUAT_H
