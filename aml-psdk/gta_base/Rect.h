#ifndef __AML_PSDK_GTARECT_H
#define __AML_PSDK_GTARECT_H

#include <math.h>
#include "Vector.h"

struct CRect
{
    float left;          // x1
    float top;           // max y for world bounds
    float right;         // x2
    float bottom;        // min y for world bounds

    CRect(float _left, float _top, float _right, float _bottom)
    {
        left = _left;
        top = _top;
        right = _right;
        bottom = _bottom;
    }
    CRect(CVector2D const pos, float size)
    {
        SetFromCenter(pos.x, pos.y, size);
    }
    CRect() { Init(); }

    inline void Init()
    {
        left = bottom = 1000000.0f;
        right = top = -1000000.0f;
    }
    inline bool IsFlipped() const
    {
        return (left > right || bottom > top);
    }
    inline void Restrict(CRect const& r)
    {
        if(r.left < left) left = r.left;
        if(r.right > right) right = r.right;
        if(r.top > top) top = r.top;
        if(r.bottom < bottom) bottom = r.bottom;
    }
    inline void Grow(float l, float r, float t, float b)
    {
        left -= l;
        top += t;
        right += r;
        bottom -= b;
    }
    inline void Translate(float x, float y)
    {
        left += x;
        right += x;
        bottom += y;
        top += y;
    }
    inline void Reset()
    {
        left = right = bottom = top = 0.0f;
    }
    inline bool IsPointInside(CVector2D const& point) const
    {
        return (point.x >= left && point.x <= right && point.y >= bottom && point.y <= top);
    }
    inline CVector2D GetCenter() const
    {
        return CVector2D(0.5f * (left + right), 0.5f * (top + bottom));
    }
    inline void Resize(float resizeX, float resizeY)
    {
        Grow(resizeX, resizeX, resizeY, resizeY);
    }
    inline void Grow(float resizeX, float resizeY)
    {
        Resize(resizeX, resizeY);
    }
    inline void SetFromCenter(float x, float y, float size)
    {
        left = x - size;
        top = y + size;
        right = x + size;
        bottom = y - size;
    }
    inline void GetCenter(float *x, float *y) const
    {
        *x = 0.5f * (left + right);
        *y = 0.5f * (top + bottom);
    }
    inline void GetCentre(float &x, float &y) const
    {
        GetCenter(&x, &y);
    }
    inline void StretchToPoint(float x, float y)
    {
        if(x < left) left = x;
        if(x > right) right = x;
        if(y > top) top = y;
        if(y < bottom) bottom = y;
    }
    inline CRect& Add(float x, float y)
    {
        StretchToPoint(x, y);
        return *this;
    }
    inline CRect& operator+=(CVector2D const& point)
    {
        return Add(point.x, point.y);
    }
    inline CRect& operator+=(CRect const& r)
    {
        Restrict(r);
        return *this;
    }
    inline bool IsInside(CVector2D const& point) const
    {
        return IsPointInside(point);
    }
    inline bool DoesIntersect(CVector2D const& v, float radius) const
    {
        return !(v.x < left - radius || v.x > right + radius || v.y < bottom - radius || v.y > top + radius);
    }
    inline bool DoesIntersect(CRect const& r) const
    {
        return !(left > r.right || right < r.left || bottom > r.top || top < r.bottom);
    }
    inline bool IsInvalid() const
    {
        return IsFlipped();
    }
    inline float Width() const
    {
        return fabsf(right - left);
    }
    inline float Height() const
    {
        return fabsf(top - bottom);
    }
    inline CVector2D GetSize() const
    {
        return CVector2D(Width(), Height());
    }
    inline bool Contains(CRect const& rect) const
    {
        return !IsInvalid() && !rect.IsInvalid() &&
            rect.left >= left && rect.right <= right && rect.bottom >= bottom && rect.top <= top;
    }
    inline bool GetIntersection(CRect const& rect, CRect& result) const
    {
        if(IsInvalid() || rect.IsInvalid()) return false;
        CRect intersection(fmaxf(left, rect.left), fminf(top, rect.top), fminf(right, rect.right), fmaxf(bottom, rect.bottom));
        if(intersection.IsInvalid()) return false;
        result = intersection;
        return true;
    }
    inline bool DoesIntersectCircle(CVector2D const& center, float radius) const
    {
        if(IsInvalid() || radius < 0.0f) return false;
        float x = fmaxf(left, fminf(center.x, right));
        float y = fmaxf(bottom, fminf(center.y, top));
        return SQ(center.x - x) + SQ(center.y - y) <= SQ(radius);
    }
    inline CVector2D GetClosestPoint(CVector2D const& point) const
    {
        return CVector2D(fmaxf(left, fminf(point.x, right)), fmaxf(bottom, fminf(point.y, top)));
    }
};
CHECKSIZE(CRect, 0x10, 0x10);

#endif // __AML_PSDK_GTARECT_H
