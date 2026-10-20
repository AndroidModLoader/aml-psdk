#ifndef __AML_PSDK_SAAUDIOZONES_H
#define __AML_PSDK_SAAUDIOZONES_H

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/gta_base/Vector.h>

DECL_CLASS(CAudioZoneData)
    // Member values
    char m_Name[8];
    i16 m_Sound;
    i16 m_bActive : 1;
DECL_CLASS_END()
CHECKSIZE(CAudioZoneData, 0xc, 0xc);

DECL_CLASS_BASED(CAudioBox, CAudioZoneData)
    // Member values
    i16 m_iMinX;
    i16 m_iMinY;
    i16 m_iMinZ;
    i16 m_iMaxX;
    i16 m_iMaxY;
    i16 m_iMaxZ;
DECL_CLASS_END()
CHECKSIZE(CAudioBox, 0x18, 0x18);

DECL_CLASS_BASED(CAudioSphere, CAudioZoneData)
    // Member values
    CVector m_Coors;
    float m_Range;
DECL_CLASS_END()
CHECKSIZE(CAudioSphere, 0x1c, 0x1c);

DECL_CLASS(CAudioZones)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(Init, _ZN11CAudioZones4InitEv, void);
    DECL_FASTCALL_SIMPLE(Update, _ZN11CAudioZones6UpdateEb7CVector, void, bool forceUpdate, CVector pos);
    DECL_FASTCALL_SIMPLE(RegisterAudioSphere, _ZN11CAudioZones19RegisterAudioSphereEPcibffff, void, char* name, i32 sound, bool active, float x, float y, float z, float radius);
    DECL_FASTCALL_SIMPLE(RegisterAudioBox, _ZN11CAudioZones16RegisterAudioBoxEPcibffffff, void, char* name, i32 sound, bool active, float minX, float minY, float minZ, float maxX, float maxY, float maxZ);
    DECL_FASTCALL_SIMPLE(SwitchAudioZone, _ZN11CAudioZones15SwitchAudioZoneEPcb, void, char* name, bool active);

    // STATIC values
    DECL_OBJECT_ARRAY_PLT(CAudioSphere, m_aSpheres, BYBIT(0x677bf8, 0x84d810));
    DECL_OBJECT_ARRAY_PLT(CAudioBox, m_aAudioBoxes, BYBIT(0x676cd8, 0x84b9f8));
    DECL_OBJECT_PLT(i32, m_nNumSpheres, BYBIT(0x678edc, 0x84fde0));
    DECL_OBJECT_PLT(i32, m_nNumBoxes, BYBIT(0x677bd4, 0x84d7c8));
    DECL_OBJECT_PLT(i32, m_nNumActiveSpheres, BYBIT(0x679d5c, 0x851ad0));
    DECL_OBJECT_PLT(i32, m_nNumActiveBoxes, BYBIT(0x678718, 0x84ee58));
    DECL_OBJECT_ARRAY_PLT(i32, m_aActiveSpheres, BYBIT(0x679938, 0x851290));
    DECL_OBJECT_ARRAY_PLT(i32, m_aActiveBoxes, BYBIT(0x6776b8, 0x84cda0));
    DECL_OBJECT_SYM(bool, m_bRenderAudioZones, _ZN11CAudioZones19m_bRenderAudioZonesE);

DECL_CLASS_END()
CHECKSIZE(CAudioZones, 0x1, 0x1);

#endif // __AML_PSDK_SAAUDIOZONES_H
