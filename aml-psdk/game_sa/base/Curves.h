#ifndef __AML_PSDK_SACURVES_H
#define __AML_PSDK_SACURVES_H

#include "../plugin.h"
#include "../../gta_base/Vector.h"

DECL_CLASS(CCurves)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(TestCurves, _ZN7CCurves10TestCurvesEv, void);
    DECL_FASTCALL_SIMPLE(DistForLineToCrossOtherLine, _ZN7CCurves27DistForLineToCrossOtherLineEffffffff, float,
        float x1, float y1, float dir1X, float dir1Y, float x2, float y2, float dir2X, float dir2Y);
    DECL_FASTCALL_SIMPLE(CalcSpeedVariationInBend, _ZN7CCurves24CalcSpeedVariationInBendERK7CVectorS2_ffff, float,
        CVector const& point1, CVector const& point2, float dir1X, float dir1Y, float dir2X, float dir2Y);
    DECL_FASTCALL_SIMPLE(CalcSpeedScaleFactor, _ZN7CCurves20CalcSpeedScaleFactorERK7CVectorS2_ffff, float,
        CVector const& point1, CVector const& point2, float dir1X, float dir1Y, float dir2X, float dir2Y);
    DECL_FASTCALL_SIMPLE(CalcCurvePoint, _ZN7CCurves14CalcCurvePointERK7CVectorS2_S2_S2_fiRS0_S3_, void,
        CVector const& point1, CVector const& point2, CVector const& dir1, CVector const& dir2, float t, i32 timeScale, CVector& position, CVector& direction);
    DECL_FASTCALL_SIMPLE(CalcCorrectedDist, _ZN7CCurves17CalcCorrectedDistEfffPf, float,
        float distance, float totalLength, float scale, float* blend);
DECL_CLASS_END()

#endif // __AML_PSDK_SACURVES_H
