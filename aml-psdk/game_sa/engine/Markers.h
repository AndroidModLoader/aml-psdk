#ifndef __AML_PSDK_SAMARKERS_H
#define __AML_PSDK_SAMARKERS_H

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/game_sa/enum/Effects.h>
#include <aml-psdk/game_sa/base/Matrix.h>
#include <aml-psdk/gta_base/RGBA.h>
#include <aml-psdk/renderware/RpClump.h>

DECL_CLASS(C3dMarker)
    // Member functions
    DECL_THISCALL_HEAD(AddMarker, BYBIT(_ZN9C3dMarker9AddMarkerEjtfhhhhtfs, _ZN9C3dMarker9AddMarkerEytfhhhhtfs), u8, uptr nIdentifier, u16 nType, float fSize, u8 setr, u8 setg, u8 setb, u8 seta, u16 nPeriod, float fPulseFrac, i16 nRotRate)
    DECL_THISCALL_TAIL(AddMarker, nIdentifier, nType, fSize, setr, setg, setb, seta, nPeriod, fPulseFrac, nRotRate)
    DECL_THISCALL_SIMPLE(DeleteMarkerObject, _ZN9C3dMarker18DeleteMarkerObjectEv, void);
    DECL_THISCALL_SIMPLE(Render, _ZN9C3dMarker6RenderEv, void);
    DECL_THISCALL_HEAD(UpdateZCoordinate, _ZN9C3dMarker17UpdateZCoordinateE7CVectorf, void, CVector vecTempPlayerPos, float fSize)
    DECL_THISCALL_TAIL(UpdateZCoordinate, vecTempPlayerPos, fSize)
    DECL_THISCALL_HEAD(SetZCoordinateIfNotUpToDate, _ZN9C3dMarker27SetZCoordinateIfNotUpToDateEf, void, float NewZ)
    DECL_THISCALL_TAIL(SetZCoordinateIfNotUpToDate, NewZ)
    DECL_THISCALL_SIMPLE(IsZCoordinateUpToDate, _ZN9C3dMarker21IsZCoordinateUpToDateEv, bool);

    // Member values
    CMatrix m_mat;
    RwObject* m_pRwObject;
    RpMaterial* m_pMaterial;
    u16 m_nType;
    bool m_bIsUsed;
    bool m_bIsActive;
    uptr m_nIdentifier;
    RwRGBA rwColour;
    u16 m_nPulsePeriod;
    i16 m_nRotateRate;
    u32 m_nStartTime;
    float m_fPulseFraction;
    float m_fStdSize;
    float m_fSize;
    float m_fBrightness;
    float m_fCameraRange;
    CVector m_normal;
    i16 m_LastMapReadX;
    i16 m_LastMapReadY;
    float m_LastMapReadResultZ;
    float m_roofHeight;
    CVector m_lastPosition;
    u32 m_OnScreenTestTime;
DECL_CLASS_END()
CHECKSIZE(C3dMarker, 0xA0, 0xB8);

DECL_CLASS(C3dMarkers)
    struct user3dMarkers
    {
        // Member values
        bool bActive;
        CVector pos;
        i32 r;
        i32 g;
        i32 b;
    };
    CHECKSIZE(C3dMarkers::user3dMarkers, 0x1C, 0x1C);

    struct directionArrows
    {
        // Member values
        bool bActive;
        CVector pos;
        float fSize;
        CVector normal;
        i32 r;
        i32 g;
        i32 b;
        i32 a;
    };
    CHECKSIZE(C3dMarkers::directionArrows, 0x30, 0x30);

    // STATIC functions
    DECL_FASTCALL_SIMPLE(User3dMarkerFindFirstFreeSlot, _ZN10C3dMarkers29User3dMarkerFindFirstFreeSlotEv, i32);
    DECL_FASTCALL_SIMPLE(User3dMarkerSet, _ZN10C3dMarkers15User3dMarkerSetEfffi, i32, float x, float y, float z, i32 colID);
    DECL_FASTCALL_SIMPLE(User3dMarkerDelete, _ZN10C3dMarkers18User3dMarkerDeleteEi, void, i32 n);
    DECL_FASTCALL_SIMPLE(User3dMarkerDeleteAll, _ZN10C3dMarkers21User3dMarkerDeleteAllEv, void);
    DECL_FASTCALL_SIMPLE(User3dMarkersDraw, _ZN10C3dMarkers17User3dMarkersDrawEv, void);
    DECL_FASTCALL_SIMPLE(User3dMarkerAtomicCB, _ZN10C3dMarkers20User3dMarkerAtomicCBEP8RpAtomicPv, RpAtomic*, RpAtomic* pAtomic, void* pData);
    DECL_FASTCALL_SIMPLE(LoadUser3dMarkers, _ZN10C3dMarkers17LoadUser3dMarkersEv, bool);
    DECL_FASTCALL_SIMPLE(SaveUser3dMarkers, _ZN10C3dMarkers17SaveUser3dMarkersEv, bool);
    DECL_FASTCALL_SIMPLE(DirectionArrowsInit, _ZN10C3dMarkers19DirectionArrowsInitEv, void);
    DECL_FASTCALL_SIMPLE(DirectionArrowFindFirstFreeSlot, _ZN10C3dMarkers31DirectionArrowFindFirstFreeSlotEv, i32);
    DECL_FASTCALL_SIMPLE(DirectionArrowSet, _ZN10C3dMarkers17DirectionArrowSetE7CVectorfiiiifff, void, CVector pos, float fSize, i32 r, i32 g, i32 b, i32 a, float normalX, float normalY, float normalZ);
    DECL_FASTCALL_SIMPLE(DirectionArrowsDraw, _ZN10C3dMarkers19DirectionArrowsDrawEv, void);
    DECL_FASTCALL_SIMPLE(Init, _ZN10C3dMarkers4InitEv, void);
    DECL_FASTCALL_SIMPLE(Shutdown, _ZN10C3dMarkers8ShutdownEv, void);
    DECL_FASTCALL_SIMPLE(Update, _ZN10C3dMarkers6UpdateEv, void);
    DECL_FASTCALL_SIMPLE(Render, _ZN10C3dMarkers6RenderEv, void);
    DECL_FASTCALL_SIMPLE(ForceRender, _ZN10C3dMarkers11ForceRenderEh, void, u8 value);
    DECL_FASTCALL_SIMPLE(LoadMarker, _ZN10C3dMarkers10LoadMarkerEPKc, RpClump*, char const* name);
    DECL_FASTCALL_SIMPLE(PlaceMarkerCone, BYBIT(_ZN10C3dMarkers15PlaceMarkerConeEjR7CVectorfhhhhtfsh, _ZN10C3dMarkers15PlaceMarkerConeEyR7CVectorfhhhhtfsh), void, uptr nIdentifier, CVector& vecPosition, float fSize, u8 r, u8 g, u8 b, u8 a, u16 nPeriod, float fPulseFrac, i16 nRotRate, u8 useCollision);
    DECL_FASTCALL_SIMPLE(PlaceMarker, BYBIT(_ZN10C3dMarkers11PlaceMarkerEjtR7CVectorfhhhhtfsfffb, _ZN10C3dMarkers11PlaceMarkerEytR7CVectorfhhhhtfsfffb), C3dMarker*, uptr nIdentifier, u16 nType, CVector& vecPosition, float fSize, u8 r, u8 g, u8 b, u8 a, u16 nPeriod, float fPulseFrac, i16 nRotRate, float normalX, float normalY, float normalZ, bool zCheck);
    DECL_FASTCALL_SIMPLE(PlaceMarkerSet, BYBIT(_ZN10C3dMarkers14PlaceMarkerSetEjtR7CVectorfhhhhtfs, _ZN10C3dMarkers14PlaceMarkerSetEytR7CVectorfhhhhtfs), C3dMarker*, uptr nIdentifier, u16 nType, CVector& vecPosition, float fSize, u8 r, u8 g, u8 b, u8 a, u16 nPeriod, float fPulseFrac, i16 nRotRate);

    // STATIC values
    DECL_OBJECT_PLT(u8, IgnoreRenderLimit, BYBIT(0x6778E0, 0x84D1E8));
    DECL_OBJECT_ARRAY_PLT(C3dMarkers::user3dMarkers, ms_user3dMarkers, BYBIT(0x676E68, 0x84BD10));
    DECL_OBJECT_PLT(RwRGBA, m_user3dMarkerColor, BYBIT(0x67635C, 0x84A710));
    DECL_OBJECT_ARRAY_PLT(C3dMarkers::directionArrows, ms_directionArrows, BYBIT(0x677830, 0x84D088));
    DECL_OBJECT_ARRAY_PLT(RpClump*, m_pRpClumpArray, BYBIT(0x678434, 0x84E880));
    DECL_OBJECT_ARRAY_PLT(C3dMarker, m_aMarkerArray, BYBIT(0x6799DC, 0x8513D0));
    DECL_VALUE_PLT_I32(NumActiveMarkers, BYBIT(0x679EAC, 0x851D68));
    DECL_OBJECT_PLT(CRGBA, m_colDiamond, BYBIT(0x679E08, 0x851C20));
    DECL_VALUE_PLT_FLT(m_angleDiamond, BYBIT(0x6771B0, 0x84C390));

DECL_CLASS_END()
CHECKSIZE(C3dMarkers, 0x1, 0x1);

#endif // __AML_PSDK_SAMARKERS_H
