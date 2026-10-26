#ifndef __AML_PSDK_VCQUAT_H
#define __AML_PSDK_VCQUAT_H

#include <aml-psdk/game_vc/plugin.h>
#include <aml-psdk/gta_base/Vector.h>
#include <aml-psdk/renderware/RwMatrix.h>

DECL_CLASS(CQuaternion)
    CQuaternion() : imag(0.0f), real(1.0f) {}
    CQuaternion(float x, float y, float z, float w) : imag(x, y, z), real(w) {}
    CQuaternion(CVector const& vector, float scalar) : imag(vector), real(scalar) {}

    // Member functions
    DECL_THISCALL_HEAD(Set, _ZN11CQuaternion3SetERK11RwMatrixTag, void, RwMatrix const& matrix)
    DECL_THISCALL_TAIL(Set, matrix)

    DECL_THISCALL_NAMED_HEAD(Set1, Set, _ZN11CQuaternion3SetEfff, void, float x, float y, float z)
    DECL_THISCALL_TAIL(Set1, x, y, z)

    DECL_THISCALL_NAMED_HEAD(Set2, Set, _ZN11CQuaternion3SetEP5RwV3df, void, RwV3d* axis, float angle)
    DECL_THISCALL_TAIL(Set2, axis, angle)

    DECL_THISCALL_HEAD(Get, _ZN11CQuaternion3GetEP11RwMatrixTag, void, RwMatrix* matrix)
    DECL_THISCALL_TAIL(Get, matrix)

    DECL_THISCALL_NAMED_HEAD(Get1, Get, _ZN11CQuaternion3GetEPfS0_S0_, void, float* x, float* y, float* z)
    DECL_THISCALL_TAIL(Get1, x, y, z)

    DECL_THISCALL_NAMED_HEAD(Get2, Get, _ZN11CQuaternion3GetEP5RwV3dPf, void, RwV3d* axis, float* angle)
    DECL_THISCALL_TAIL(Get2, axis, angle)

    DECL_THISCALL_HEAD(Multiply, _ZN11CQuaternion8MultiplyERKS_S1_, void, CQuaternion const& left, CQuaternion const& right)
    DECL_THISCALL_TAIL(Multiply, left, right)

    DECL_THISCALL_HEAD(Slerp, _ZN11CQuaternion5SlerpERKS_S1_fff, void, CQuaternion const& start, CQuaternion const& end, float theta, float invSinTheta, float progress)
    DECL_THISCALL_TAIL(Slerp, start, end, theta, invSinTheta, progress)

    DECL_THISCALL_NAMED_HEAD(Slerp1, Slerp, _ZN11CQuaternion5SlerpERKS_S1_f, void, CQuaternion const& start, CQuaternion const& end, float progress)
    DECL_THISCALL_TAIL(Slerp1, start, end, progress)

    // Helper functions
    inline void Copy(CQuaternion const& from) { *this = from; }
    inline float Dot(CQuaternion const& other) const { return imag.Dot(other.imag) + real * other.real; }
    inline float GetLengthSquared() const { return imag.MagnitudeSqr() + SQ(real); }
    inline float GetLength() const { return sqrtf(GetLengthSquared()); }
    inline bool IsNormalized() const { return fabsf(GetLengthSquared() - 1.0f) < 0.001f; }
    inline void Scale(float multiplier)
    {
        imag *= multiplier;
        real *= multiplier;
    }
    inline void Conjugate() { imag *= -1.0f; }
    inline void Normalise()
    {
        float norm = GetLengthSquared();
        if(norm == 0.0f)
        {
            imag.Set(0.0f);
            real = 1.0f;
        }
        else Scale(1.0f / sqrtf(norm));
    }
    inline CQuaternion Conjugated() const { return { imag * -1.0f, real }; }
    inline CQuaternion Normalized() const
    {
        CQuaternion result = *this;
        result.Normalise();
        return result;
    }
    inline CQuaternion Inverted() const
    {
        float norm = GetLengthSquared();
        if(norm == 0.0f) return {};
        return { imag * (-1.0f / norm), real / norm };
    }
    inline CVector RotateVector(CVector const& vector) const
    {
        float norm = GetLengthSquared();
        if(norm == 0.0f) return vector;
        CVector cross = imag.Cross(vector);
        return vector + (cross * real + imag.Cross(cross)) * (2.0f / norm);
    }
    inline CQuaternion operator*(CQuaternion const& other) const
    {
        return { imag.Cross(other.imag) + imag * other.real + other.imag * real, real * other.real - imag.Dot(other.imag) };
    }
    inline CQuaternion& operator*=(CQuaternion const& other)
    {
        *this = *this * other;
        return *this;
    }
    inline void operator*=(float multiplier) { Scale(multiplier); }
    inline void operator+=(CQuaternion const& other)
    {
        imag += other.imag;
        real += other.real;
    }
    inline void operator-=(CQuaternion const& other)
    {
        imag -= other.imag;
        real -= other.real;
    }

    // Member values
    CVector imag;
    float real;
DECL_CLASS_END()
CHECKSIZE(CQuaternion, 0x10, 0x10);

#endif // __AML_PSDK_VCQUAT_H
