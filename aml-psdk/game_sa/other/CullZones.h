#ifndef __AML_PSDK_SACULLZONES_H
#define __AML_PSDK_SACULLZONES_H

/*
    Plugin-SDK (Grand Theft Auto San Andreas) header file
    Authors: GTA Community. See more here
    https://github.com/DK22Pac/plugin-sdk
    Do not delete this comment block. Respect others' work!
*/

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/gta_base/Vector.h>

enum eZoneAttributes : u16
{
    ATTRZONE_NONE = 0x0,
    ATTRZONE_CAMCLOSEIN = 0x1,
    ATTRZONE_STAIRS = 0x2,
    ATTRZONE_1STPERSONS = 0x4,
    ATTRZONE_NORAIN = 0x8,
    ATTRZONE_NOPOLICE = 0x10,
    ATTRZONE_DOINEEDCOLLISION = 0x40,
    ATTRZONE_POLICEABANDONCAR = 0x100,
    ATTRZONE_INROOMSFORAUDIO = 0x200,
    ATTRZONE_INROOMSFEWERPEDS = 0x400,
    ATTRZONE_MILITARYZONE = 0x1000,
    ATTRZONE_EXTRAAIRRESISTANCE = 0x4000,
    ATTRZONE_FEWERCARS = 0x8000
};

DECL_CLASS(CZoneDef)
    // Member functions
    DECL_THISCALL_SIMPLE(FindCenter, _ZN8CZoneDef10FindCenterEv, CVector);
    DECL_THISCALL_HEAD(FindBoundingBox, _ZN8CZoneDef15FindBoundingBoxEP7CVectorS1_, void, CVector *pMin, CVector *pMax)
    DECL_THISCALL_TAIL(FindBoundingBox, pMin, pMax)
    DECL_THISCALL_HEAD(IsPointWithin, _ZN8CZoneDef13IsPointWithinE7CVector, bool, CVector point)
    DECL_THISCALL_TAIL(IsPointWithin, point)

    // Member values
    i16 x1;
    i16 y1;
    i16 x2;
    i16 y2;
    i16 x3;
    i16 y3;
    i16 z1;
    i16 z2;
DECL_CLASS_END()
CHECKSIZE(CZoneDef, 0x10, 0x10);

struct CCullZone
{
    CZoneDef zoneDef;
    i16 flags;
};
CHECKSIZE(CCullZone, 0x12, 0x12);

struct CCullZoneReflection
{
    CZoneDef zoneDef;
    float cm;
    i8 vx;
    i8 vy;
    i8 vz;
    i8 flags;
};
CHECKSIZE(CCullZoneReflection, 0x18, 0x18);

DECL_CLASS(CCullZones)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(Init, _ZN10CCullZones4InitEv, void);
    DECL_FASTCALL_SIMPLE(Update, _ZN10CCullZones6UpdateEv, void);
    DECL_FASTCALL_SIMPLE(FindAttributesForCoors, _ZN10CCullZones22FindAttributesForCoorsE7CVector, i32, CVector pos);
    DECL_FASTCALL_SIMPLE(FindTunnelAttributesForCoors, _ZN10CCullZones28FindTunnelAttributesForCoorsE7CVector, i32, CVector pos);
    DECL_FASTCALL_SIMPLE(FindMirrorAttributesForCoors, _ZN10CCullZones28FindMirrorAttributesForCoorsE7CVector, CCullZoneReflection*, CVector pos);
    DECL_FASTCALL_SIMPLE(FindZoneWithStairsAttributeForPlayer, _ZN10CCullZones36FindZoneWithStairsAttributeForPlayerEv, CCullZone*);
    DECL_FASTCALL_SIMPLE(AddCullZone, _ZN10CCullZones11AddCullZoneERK7CVectorffffffts, void,
        CVector const& center, float unk1, float y1, float z1, float x2, float unk2, float z2, u16 flags, i16 room);
    DECL_FASTCALL_SIMPLE(AddTunnelAttributeZone, _ZN10CCullZones22AddTunnelAttributeZoneERK7CVectorfffffft, void,
        CVector const& pos, float vec1X, float vec1Y, float minZ, float vec2X, float vec2Y, float maxZ, u16 flags);
    DECL_FASTCALL_SIMPLE(AddMirrorAttributeZone, _ZN10CCullZones22AddMirrorAttributeZoneERK7CVectorfffffftffff, void,
        CVector const& pos, float vec1X, float vec1Y, float minZ, float vec2X, float vec2Y, float maxZ, u16 flags, float mirrorV, float mirrorNormalX, float mirrorNormalY, float mirrorNormalZ);
    DECL_FASTCALL_SIMPLE(CamCloseInForPlayer, _ZN10CCullZones19CamCloseInForPlayerEv, bool);
    DECL_FASTCALL_SIMPLE(CamStairsForPlayer, _ZN10CCullZones18CamStairsForPlayerEv, bool);
    DECL_FASTCALL_SIMPLE(Cam1stPersonForPlayer, _ZN10CCullZones21Cam1stPersonForPlayerEv, bool);
    DECL_FASTCALL_SIMPLE(NoPolice, _ZN10CCullZones8NoPoliceEv, bool);
    DECL_FASTCALL_SIMPLE(PoliceAbandonCars, _ZN10CCullZones17PoliceAbandonCarsEv, bool);
    DECL_FASTCALL_SIMPLE(InRoomForAudio, _ZN10CCullZones14InRoomForAudioEv, bool);
    DECL_FASTCALL_SIMPLE(FewerCars, _ZN10CCullZones9FewerCarsEv, bool);
    DECL_FASTCALL_SIMPLE(FewerPeds, _ZN10CCullZones9FewerPedsEv, bool);
    DECL_FASTCALL_SIMPLE(DoINeedToLoadCollision, _ZN10CCullZones22DoINeedToLoadCollisionEv, bool);
    DECL_FASTCALL_SIMPLE(CamNoRain, _ZN10CCullZones9CamNoRainEv, bool);
    DECL_FASTCALL_SIMPLE(PlayerNoRain, _ZN10CCullZones12PlayerNoRainEv, bool);
    DECL_FASTCALL_SIMPLE(DoExtraAirResistanceForPlayer, _ZN10CCullZones29DoExtraAirResistanceForPlayerEv, bool);

    // STATIC values
    DECL_VALUE_PLT_I32(NumAttributeZones, BYBIT(0x6788D0, 0x84F1C0));
    DECL_VALUE_PLT_I32(NumMirrorAttributeZones, BYBIT(0x678F2C, 0x84FE80));
    DECL_VALUE_PLT_I32(NumTunnelAttributeZones, BYBIT(0x676BEC, 0x84B820));
    DECL_VALUE_PLT_I32(CurrentFlags_Camera, BYBIT(0x6793E0, 0x8507D8));
    DECL_VALUE_PLT_I32(CurrentFlags_Player, BYBIT(0x6762C4, 0x84A5E8));
    DECL_VALUE_SYM_BOOL(bRenderCullzones, _ZN10CCullZones16bRenderCullzonesE);
    DECL_VALUE_PLT_BOOL(bMilitaryZonesDisabled, BYBIT(0x678218, 0x84E448));
    DECL_OBJECT_ARRAY_PLT(CCullZone, aAttributeZones, BYBIT(0x67787C, 0x84D120));
    DECL_OBJECT_ARRAY_PLT(CCullZone, aTunnelAttributeZones, BYBIT(0x676200, 0x84A460));
    DECL_OBJECT_ARRAY_PLT(CCullZoneReflection, aMirrorAttributeZones, BYBIT(0x67992C, 0x851278));
DECL_CLASS_END()

#define NumAttributeZones NumAttributeZones()
#define NumMirrorAttributeZones NumMirrorAttributeZones()
#define NumTunnelAttributeZones NumTunnelAttributeZones()
#define CurrentFlags_Camera CurrentFlags_Camera()
#define CurrentFlags_Player CurrentFlags_Player()
#define bRenderCullzones bRenderCullzones()
#define bMilitaryZonesDisabled bMilitaryZonesDisabled()
#define aAttributeZones aAttributeZones()
#define aTunnelAttributeZones aTunnelAttributeZones()
#define aMirrorAttributeZones aMirrorAttributeZones()

#endif // __AML_PSDK_SACULLZONES_H
