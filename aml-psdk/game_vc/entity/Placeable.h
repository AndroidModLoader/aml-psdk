#ifndef __AML_PSDK_VCPLACEABLE_H
#define __AML_PSDK_VCPLACEABLE_H

#include <aml-psdk/game_vc/plugin.h>
#include "../base/Matrix.h"

DECL_CLASS_BASED(CPlaceable, CMatrix)
    // Construct/Deconstruct functions
    DECL_CTORCALL(CPlaceable, _ZN10CPlaceableC2Ev);

    // Member functions
    DECL_THISCALL_HEAD(SetHeading, _ZN10CPlaceable10SetHeadingEf, void, float heading)
    DECL_THISCALL_TAIL(SetHeading, heading)
    DECL_THISCALL_HEAD(PointAt, _ZN10CPlaceable7PointAtEfff, void, float x, float y, float z)
    DECL_THISCALL_TAIL(PointAt, x, y, z)
    DECL_THISCALL_NAMED_HEAD(PointAt1, PointAt, _ZN10CPlaceable7PointAtEffff, void, float x, float y, float z, float roll)
    DECL_THISCALL_TAIL(PointAt1, x, y, z, roll)
    DECL_THISCALL_HEAD(IsWithinArea, _ZN10CPlaceable12IsWithinAreaEffff, bool, float x1, float y1, float x2, float y2)
    DECL_THISCALL_TAIL(IsWithinArea, x1, y1, x2, y2)
    DECL_THISCALL_NAMED_HEAD(IsWithinArea1, IsWithinArea, _ZN10CPlaceable12IsWithinAreaEffffff, bool, float x1, float y1, float z1, float x2, float y2, float z2)
    DECL_THISCALL_TAIL(IsWithinArea1, x1, y1, z1, x2, y2, z2)

    // Helper functions
    inline CMatrix& GetMatrix() { return *this; }
    inline CMatrix const& GetMatrix() const { return *this; }
    inline void SetPosition(CVector const& position) { pos = position; }
    inline void SetPosition(float x, float y, float z) { pos.Set(x, y, z); }
    inline float GetHeading() const { return atan2f(-up.x, up.y); }
    inline void SetOrientation(float x, float y, float z)
    {
        CVector position = pos;
        SetRotate(x, y, z);
        pos = position;
    }
DECL_CLASS_END()
CHECKSIZE(CPlaceable, 0x48, 0x50);

#endif // __AML_PSDK_VCPLACEABLE_H
