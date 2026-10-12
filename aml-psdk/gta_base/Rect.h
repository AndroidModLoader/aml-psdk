#ifndef __AML_PSDK_GTARECT_H
#define __AML_PSDK_GTARECT_H

#include "Vector.h"

struct CRect
{
    float left;          // x1
    float top;           // y1
    float right;         // x2
    float bottom;        // y2

    CRect(float _left, float _top, float _right, float _bottom)
    {
        left = _left;
        top = _top;
        right = _right;
        bottom = _bottom;
    }
    CRect() { Reset(); }

    inline bool IsFlipped()
    {
        return (left > right || top > bottom);
    }
    inline void Restrict(CRect const& r)
    {
        if(r.left < left) left = r.left;
        if(r.right > right) right = r.right;
        if(r.top < top) top = r.top;
        if(r.bottom > bottom) bottom = r.bottom;
    }
    inline void Grow(float l, float r, float t, float b)
    {
        left -= l;
        top -= t;
        right += r;
        bottom += b;
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
    inline bool IsPointInside(CVector2D const& point)
    {
        return (point.x >= left && point.x <= right && point.y >= top && point.y <= bottom);
    }
    inline CVector2D GetCenter()
    {
        return CVector2D(0.5f * (left + right), 0.5f * (top + bottom));
    }
};

#endif // __AML_PSDK_GTARECT_H
