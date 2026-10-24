#ifndef __AML_PSDK_GTAVECTOR_H
#define __AML_PSDK_GTAVECTOR_H

#include <aml-psdk/sdk_basetypes.h>

struct CMatrix;

struct CVector2D
{
    float x, y;
    CVector2D() : x(0.0f), y(0.0f) {}
    CVector2D(float V) : x(V), y(V) {}
    CVector2D(float X, float Y) : x(X), y(Y) {}

    inline void Reset() { Set(0.0f); }
    inline void Set(float value) { Set(value, value); }
    inline void Set(float X, float Y) { x = X; y = Y; }
    inline void FromSum(const CVector2D& left, const CVector2D& right) { *this = left + right; }
    inline void FromDiff(const CVector2D& left, const CVector2D& right) { *this = left - right; }

    operator CVector2D*() { return this; }
    inline void operator+=(const CVector2D& right)
    {
        this->x += right.x;
        this->y += right.y;
    }
    inline void operator-=(const CVector2D& right)
    {
        this->x -= right.x;
        this->y -= right.y;
    }
    inline CVector2D& operator*=(const float f)
    {
        this->x *= f;
        this->y *= f;
        return *this;
    }
    inline CVector2D& operator/=(const float f)
    {
        this->x /= f;
        this->y /= f;
        return *this;
    }
    inline CVector2D operator+(const CVector2D& vecTwo) const
    {
        return { x + vecTwo.x, y + vecTwo.y };
    }
    inline CVector2D operator-(const CVector2D& vecTwo) const
    {
        return { x - vecTwo.x, y - vecTwo.y };
    }
    inline CVector2D operator*(const float f) const
    {
        CVector2D result;
        result.x = this->x * f;
        result.y = this->y * f;
        return result;
    }
    inline CVector2D operator/(const float f) const
    {
        CVector2D result;
        result.x = this->x / f;
        result.y = this->y / f;
        return result;
    }
    float& operator[](int i)
    {
        if(i) return this->y; else return this->x;
    }
    float operator[](int i) const
    {
        if(i) return this->y; else return this->x;
    }

    inline bool InRange2D(float min, float max)
    {
        return (x <= max && x >= min &&
                y <= max && y >= min);
    }
    inline float Magnitude2D() const
    {
        return sqrtf(MagnitudeSqr2D());
    }
    inline float MagnitudeSqr2D() const
    {
        return SQ(x) + SQ(y);
    }
    inline float Magnitude() const { return Magnitude2D(); }
    inline float MagnitudeSqr() const { return MagnitudeSqr2D(); }
    inline bool IsZero() const { return x == 0.0f && y == 0.0f; }
    inline bool IsNormalized() const { return fabsf(MagnitudeSqr() - 1.0f) < 0.001f; }
    inline float Heading() const { return atan2f(-x, y); }
    inline float Dot(const CVector2D& other) const { return x * other.x + y * other.y; }
    inline float Cross(const CVector2D& other) const { return x * other.y - y * other.x; }
    inline float Distance(const CVector2D& other) const { return (*this - other).Magnitude(); }
    inline void Normalize() { NormalizeAndMag(); }
    inline float NormalizeAndMag()
    {
        float length = Magnitude();
        if(length > 0.0f) *this /= length;
        return length;
    }
    inline CVector2D Normalized() const
    {
        CVector2D result = *this;
        result.Normalize();
        return result;
    }
    inline static CVector2D Sum(const CVector2D& left, const CVector2D& right) { return left + right; }
    inline static CVector2D Diff(const CVector2D& left, const CVector2D& right) { return left - right; }
    inline static float Distance(const CVector2D& left, const CVector2D& right) { return left.Distance(right); }
    inline static float Dot(const CVector2D& left, const CVector2D& right) { return left.Dot(right); }
    inline static float Cross(const CVector2D& left, const CVector2D& right) { return left.Cross(right); }
};

DECL_CLASS(CVector)
    // Member functions
    DECL_THISCALL_HEAD(FromMultiply, _ZN7CVector12FromMultiplyERK7CMatrixRKS_, void, CMatrix const& arg1, CVector const& arg2)
    DECL_THISCALL_TAIL(FromMultiply, arg1, arg2)
    DECL_THISCALL_HEAD(FromMultiply3X3, _ZN7CVector15FromMultiply3X3ERK7CMatrixRKS_, void, CMatrix const& arg1, CVector const& arg2)
    DECL_THISCALL_TAIL(FromMultiply3X3, arg1, arg2)

    union
    {
        CVector2D m_vec2D;
        struct { float x, y; };
    };
    float z;

    CVector() : x(0.0f), y(0.0f), z(0.0f) {}
    CVector(float V) : x(V), y(V), z(V) {}
    CVector(float X, float Y, float Z) : x(X), y(Y), z(Z) {}
    CVector(const CVector2D& xy, float Z) : x(xy.x), y(xy.y), z(Z) {}

    inline void Reset() { Set(0.0f); }
    inline void Set(float value) { Set(value, value, value); }
    inline void Set(float X, float Y, float Z) { x = X; y = Y; z = Z; }
    inline void From2D(const CVector2D& xy, float Z) { Set(xy.x, xy.y, Z); }
    inline void FromSum(const CVector& left, const CVector& right) { *this = left + right; }
    inline void FromDiff(const CVector& left, const CVector& right) { *this = left - right; }
    inline void FromCross(const CVector& left, const CVector& right) { *this = left.Cross(right); }
    inline CVector2D To2D() const { return { x, y }; }

    inline void operator+=(const CVector& right)
    {
        this->x += right.x;
        this->y += right.y;
        this->z += right.z;
    }
    inline void operator-=(const CVector& right)
    {
        this->x -= right.x;
        this->y -= right.y;
        this->z -= right.z;
    }
    inline CVector& operator*=(const float f)
    {
        this->x *= f;
        this->y *= f;
        this->z *= f;
        return *this;
    }
    inline CVector& operator/=(const float f)
    {
        this->x /= f;
        this->y /= f;
        this->z /= f;
        return *this;
    }
    inline CVector operator+(const CVector& vecTwo) const
    {
        return { x + vecTwo.x, y + vecTwo.y, z + vecTwo.z };
    }
    inline CVector operator-(const CVector& vecTwo) const
    {
        return { x - vecTwo.x, y - vecTwo.y, z - vecTwo.z };
    }
    inline CVector operator*(const float f) const
    {
        CVector result;
        result.x = this->x * f;
        result.y = this->y * f;
        result.z = this->z * f;
        return result;
    }
    inline CVector operator/(const float f) const
    {
        CVector result;
        result.x = this->x / f;
        result.y = this->y / f;
        result.z = this->z / f;
        return result;
    }
    float& operator[](int i)
    {
        if(i == 2) return this->z; else if(i) return this->y; else return this->x;
    }
    float operator[](int i) const
    {
        if(i == 2) return this->z; else if(i) return this->y; else return this->x;
    }

    operator CVector2D&() { return m_vec2D; }
    operator CVector2D*() { return &m_vec2D; }
    operator CVector2D() const { return m_vec2D; }
    operator CVector*() { return this; }

    inline bool InRange2D(float min, float max)
    {
        return (x <= max && x >= min &&
                y <= max && y >= min);
    }
    inline bool InRange(float min, float max)
    {
        return (x <= max && x >= min &&
                y <= max && y >= min &&
                z <= max && z >= min);
    }
    inline float DistSqr2D(CVector& v)
    {
        return (*this - v).MagnitudeSqr2D();
    }
    inline float Dist2D(CVector& v)
    {
        return sqrtf(DistSqr2D(v));
    }
    inline float DistSqr(CVector& v)
    {
        return (*this - v).MagnitudeSqr();
    }
    inline float Dist(CVector& v)
    {
        return sqrtf(DistSqr(v));
    }
    inline CVector Abs()
    {
        return { fabsf(x), fabsf(y), fabsf(z) };
    }
    inline bool IsNormalized() const
    {
        return fabsf(MagnitudeSqr() - 1.0f) < 0.001f;
    }
    inline bool IsZero() const { return x == 0.0f && y == 0.0f && z == 0.0f; }
    inline float Heading() const { return atan2f(-x, y); }
    inline float Dot(const CVector& other) const { return x * other.x + y * other.y + z * other.z; }
    inline float Distance(const CVector& other) const { return (*this - other).Magnitude(); }
    inline float Distance2D(const CVector& other) const { return (*this - other).Magnitude2D(); }
    inline float Distance2D(const CVector2D& other) const { return To2D().Distance(other); }
    inline static CVector Sum(const CVector& left, const CVector& right) { return left + right; }
    inline static CVector Diff(const CVector& left, const CVector& right) { return left - right; }
    inline static float Distance(const CVector& left, const CVector& right) { return left.Distance(right); }
    inline static float Distance2D(const CVector& left, const CVector& right) { return left.Distance2D(right); }
    inline static float Distance2D(const CVector& left, const CVector2D& right) { return left.Distance2D(right); }
    inline static float Dot(const CVector& left, const CVector& right) { return left.Dot(right); }
    inline void Normalise()
    {
        float lenSq = SQ(x) + SQ(y) + SQ(z);
        if(lenSq < FLT_EPSILON)
        {
            x = 1.0f;
            return;
        }
        float invsqrt = 1.0f / sqrtf(lenSq);
        x *= invsqrt;
        y *= invsqrt;
        z *= invsqrt;
    }
    inline float NormaliseAndMag()
    {
        float lenSq = SQ(x) + SQ(y) + SQ(z);
        if(lenSq < FLT_EPSILON)
        {
            x = 1.0f;
            return x;
        }
        float lenSqrt = sqrtf(lenSq);
        float invsqrt = 1.0f / lenSqrt;
        x *= invsqrt;
        y *= invsqrt;
        z *= invsqrt;
        return lenSqrt;
    }
    inline float Magnitude() const
    {
        return sqrtf(MagnitudeSqr());
    }
    inline float Magnitude2D() const
    {
        return sqrtf(MagnitudeSqr2D());
    }
    inline float MagnitudeSqr() const
    {
        return SQ(x) + SQ(y) + SQ(z);
    }
    inline float MagnitudeSqr2D() const
    {
        return SQ(x) + SQ(y);
    }
    inline CVector Cross(const CVector& o) const
    {
        return
        {
            y * o.z - z * o.y,
            z * o.x - x * o.z,
            x * o.y - y * o.x
        };
    }
    inline void Cross(const CVector& a, const CVector& b)
    {
        *this = a.Cross(b);
    }
    inline CVector Normalized() const
    {
        CVector ret = *this;
        ret.Normalise();
        return ret;
    }
DECL_CLASS_END()
inline CVector operator*(const CVector& vecOne, const CVector& vecTwo)
{
    return { vecOne.x * vecTwo.x, vecOne.y * vecTwo.y, vecOne.z * vecTwo.z };
}
inline CVector operator*(float multiplier, const CVector& vec)
{
    return { vec.x * multiplier, vec.y * multiplier, vec.z * multiplier };
}

const CVector vectorNull(0, 0, 0);
const CVector vectorAxisX(1, 0, 0);
const CVector vectorAxisY(0, 1, 0);
const CVector vectorAxisZ(0, 0, 1);

struct CompressedVector2D
{
    CompressedVector2D() { Set(0, 0); }
    CompressedVector2D(short X, short Y) { Set(X, Y); }
    short x, y;
    
    inline void Set(short X, short Y)
    {
        x = X;
        y = Y;
    }
    inline void Set(CVector2D const& vec, float resolution = 8.0f)
    {
        x = vec.x * resolution;
        y = vec.y * resolution;
    }
    inline CVector2D Uncompress(float resolution)
    {
        return CVector2D((float)x / resolution, (float)y / resolution);
    }
    inline CVector2D Uncompressed()
    {
        return Uncompress(8.0f);
    }
    inline void Uncompress(CVector2D& out)
    {
        out = Uncompressed();
    }
};

struct CompressedVector
{
    CompressedVector() { Set(0, 0, 0); }
    CompressedVector(short X, short Y, short Z) { Set(X, Y, Z); }
    union
    {
        CompressedVector2D m_vec2D;
        struct { short x, y; };
    };
    short z;
    
    inline void Set(short X, short Y, short Z)
    {
        x = X;
        y = Y;
        z = Z;
    }
    inline void Set(CVector const& vec, float resolution = 8.0f)
    {
        x = vec.x * resolution;
        y = vec.y * resolution;
        z = vec.z * resolution;
    }
    inline CVector Uncompress(float resolution)
    {
        return CVector((float)x / resolution, (float)y / resolution, (float)z / resolution);
    }
    inline CVector Uncompressed()
    {
        return Uncompress(8.0f);
    }
    inline void Uncompress(CVector& out)
    {
        out = Uncompressed();
    }
    operator CompressedVector2D&() { return m_vec2D; }
    operator CompressedVector2D*() { return &m_vec2D; }
    operator CompressedVector2D() const { return m_vec2D; }
};

inline float DistanceBetweenPoints(CVector const& v1, CVector const& v2)
{
    return (v1 - v2).Magnitude();
}
inline float DistanceBetweenPoints2D(CVector const& v1, CVector const& v2)
{
    return (v1 - v2).Magnitude2D();
}
inline float DistanceBetweenPoints(CVector2D const& v1, CVector2D const& v2)
{
    return (v1 - v2).Magnitude2D();
}
inline float DistanceBetweenPoints2D(CVector2D const& v1, CVector2D const& v2)
{
    return (v1 - v2).Magnitude2D();
}
inline CVector CrossProduct(CVector *v1, CVector *v2)
{
    CVector cross;
    cross.x = v1->y*v2->z - v1->z*v2->y;
    cross.y = v1->z*v2->x - v1->x*v2->z;
    cross.z = v1->x*v2->y - v1->y*v2->x;
    return cross;
}
inline float DotProduct(const CVector& v1, const CVector& v2)
{
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}
inline float DotProduct2D(const CVector& v1, const CVector& v2)
{
    return v1.x * v2.x + v1.y * v2.y;
}
inline void VectorNormalise(CVector *vec)
{
    float lensq = vec->x*vec->x + vec->y*vec->y + vec->z*vec->z;
    if(lensq > 0.0f)
    {
        float invsqrt = 1.0f / sqrtf(lensq);
        vec->x *= invsqrt;
        vec->y *= invsqrt;
        vec->z *= invsqrt;
    }
    else vec->x = 1.0f;
}

#endif // __AML_PSDK_GTAVECTOR_H
