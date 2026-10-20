#ifndef __AML_PSDK_SASCREENUTILS_H
#define __AML_PSDK_SASCREENUTILS_H

#include "../engine/RsGlobal.h"
#include "../engine/Sprite.h"
#include "../../gta_base/Vector.h"

struct ScreenUtils
{
    static inline i32 GetWidth() { return RsGlobal.maximumWidth; }
    static inline i32 GetHeight() { return RsGlobal.maximumHeight; }

    // HUD coordinates use a 640 x 448 reference canvas unless specified otherwise.
    static inline float ScaleX(float x, float width = 640.0f)
    {
        return width > 0.0f ? x * GetWidth() / width : 0.0f;
    }

    static inline float ScaleY(float y, float height = 448.0f)
    {
        return height > 0.0f ? y * GetHeight() / height : 0.0f;
    }

    static inline CVector2D Scale(const CVector2D& point, float width = 640.0f, float height = 448.0f)
    {
        return {ScaleX(point.x, width), ScaleY(point.y, height)};
    }

    static inline CRect Scale(const CRect& rect, float width = 640.0f, float height = 448.0f)
    {
        return {ScaleX(rect.left, width), ScaleY(rect.top, height), ScaleX(rect.right, width), ScaleY(rect.bottom, height)};
    }

    static inline float FromRight(float x, float width = 640.0f) { return GetWidth() - ScaleX(x, width); }
    static inline float FromBottom(float y, float height = 448.0f) { return GetHeight() - ScaleY(y, height); }

    // Uses the current camera. Returns pixel coordinates and camera depth; it does not clip the screen edges.
    static inline bool WorldToScreen(const CVector& world, CVector& screen, CVector2D* scale = NULL,
        bool clipFarPlane = true, bool clipNearPlane = true)
    {
        if(GetWidth() <= 0 || GetHeight() <= 0) return false;
        RwV3d point = {world.x, world.y, world.z}, projected;
        CVector2D projectedScale;
        if(!CSprite::CalcScreenCoors(point, &projected, scale ? &projectedScale.x : NULL,
            scale ? &projectedScale.y : NULL, clipFarPlane, clipNearPlane)) return false;
        screen = CVector(projected.x, projected.y, projected.z);
        if(scale) *scale = projectedScale;
        return true;
    }

    static inline bool IsOnScreen(const CVector& screen, float margin = 0.0f)
    {
        i32 width = GetWidth(), height = GetHeight();
        return width > 0 && height > 0 && screen.z > 0.0f && screen.x >= -margin && screen.y >= -margin &&
            screen.x <= width + margin && screen.y <= height + margin;
    }
};

#endif // __AML_PSDK_SASCREENUTILS_H
