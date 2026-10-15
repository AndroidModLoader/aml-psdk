#ifndef __AML_PSDK_SAOCCLUSION_H
#define __AML_PSDK_SAOCCLUSION_H

#include "../plugin.h"
#include "../base/Matrix.h"

struct CActiveOccluder;

DECL_CLASS(COcclusionLine)
    // Member values
    float BaseX;
    float BaseY;
    float DeltaX;
    float DeltaY;
    float Length;
DECL_CLASS_END()
CHECKSIZE(COcclusionLine, 0x14, 0x14);

DECL_CLASS(CActiveOccluder)
    // Member functions
    DECL_THISCALL_HEAD(IsPointWithinOcclusionArea, _ZN15CActiveOccluder26IsPointWithinOcclusionAreaEfff, bool, float PointX, float PointY, float Radius)
    DECL_THISCALL_TAIL(IsPointWithinOcclusionArea, PointX, PointY, Radius)
    DECL_THISCALL_HEAD(IsPointBehindOccluder, _ZN15CActiveOccluder21IsPointBehindOccluderE7CVectorf, bool, CVector Pos, float Radius)
    DECL_THISCALL_TAIL(IsPointBehindOccluder, Pos, Radius)
    // Member values
    COcclusionLine Lines[6];
    i16 DistToCam;
    i8 LinesUsed;
    i8 FacesUsed;
    CVector FaceNormals[3];
    float FaceOffset[3];
DECL_CLASS_END()
CHECKSIZE(CActiveOccluder, 0xAC, 0xAC);

DECL_CLASS(COccluder)
    // Member functions
    DECL_THISCALL_HEAD(ProcessOneOccluder, _ZN9COccluder18ProcessOneOccluderEP15CActiveOccluder, bool, CActiveOccluder* pActive)
    DECL_THISCALL_TAIL(ProcessOneOccluder, pActive)
    DECL_THISCALL_HEAD(ProcessLineSegment, _ZN9COccluder18ProcessLineSegmentEiiP15CActiveOccluder, bool, i32 Pnt1, i32 Pnt2, CActiveOccluder* pActive)
    DECL_THISCALL_TAIL(ProcessLineSegment, Pnt1, Pnt2, pActive)
    DECL_THISCALL_SIMPLE(NearCamera, _ZN9COccluder10NearCameraEv, bool);

    // Member values
    i16 iCenterX;
    i16 iCenterY;
    i16 iCenterZ;
    i16 iLength;
    i16 iWidth;
    i16 iHeight;
    u8 iRotZ;
    u8 iRotY;
    u8 iRotX;
    i16 NextInList : 15;
    i16 bDontStream : 1;
DECL_CLASS_END()
CHECKSIZE(COccluder, 0x12, 0x12);

DECL_CLASS(COcclusion)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(Init, _ZN10COcclusion4InitEv, void);
    DECL_FASTCALL_SIMPLE(AddOne, _ZN10COcclusion6AddOneEfffffffffjb, void, float X, float Y, float Z, float ArgWidth, float ArgLength, float ArgHeight, float ZRot, float YRot, float XRot, u32 Flags, bool bInterior);
    DECL_FASTCALL_SIMPLE(ProcessBeforeRendering, _ZN10COcclusion22ProcessBeforeRenderingEv, void);
    DECL_FASTCALL_SIMPLE(OccluderHidesBehind, _ZN10COcclusion19OccluderHidesBehindEP15CActiveOccluderS1_, bool, CActiveOccluder* pTestOcc, CActiveOccluder* pHideOcc);
    DECL_FASTCALL_SIMPLE(IsPositionOccluded, _ZN10COcclusion18IsPositionOccludedE7CVectorf, bool, CVector Pos, float Radius);

    // STATIC values
    DECL_OBJECT_ARRAY_PLT(COccluder, aOccluders, BYBIT(0x678444, 0x84E8A0));
    DECL_VALUE_PLT_I32(NumOccludersOnMap, BYBIT(0x67816C, 0x84E2F0));
    DECL_OBJECT_ARRAY_PLT(COccluder, aInteriorOccluders, BYBIT(0x6791D4, 0x8503C8));
    DECL_VALUE_PLT_I32(NumInteriorOccludersOnMap, BYBIT(0x679CC0, 0x851998));
    DECL_OBJECT_ARRAY_PLT(CActiveOccluder, aActiveOccluders, BYBIT(0x676D6C, 0x84BB20));
    DECL_VALUE_PLT_I32(NumActiveOccluders, BYBIT(0x679964, 0x8512E0));
    DECL_OBJECT_PLT(i16, FarAwayList, BYBIT(0x6774F4, 0x84CA20));
    DECL_OBJECT_PLT(i16, NearbyList, BYBIT(0x679788, 0x850F18));
    DECL_OBJECT_PLT(i16, ListWalkThroughFA, BYBIT(0x6781C4, 0x84E3A0));
    DECL_OBJECT_PLT(i16, PreviousListWalkThroughFA, BYBIT(0x678DF0, 0x84FC08));
DECL_CLASS_END()

#endif // __AML_PSDK_SAOCCLUSION_H
