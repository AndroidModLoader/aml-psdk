#ifndef __AML_PSDK_SAZONES_H
#define __AML_PSDK_SAZONES_H

/*
    Plugin-SDK (Grand Theft Auto San Andreas) header file
    Authors: GTA Community. See more here
    https://github.com/DK22Pac/plugin-sdk
    Do not delete this comment block. Respect others' work!
*/

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/game_sa/enum/LevelName.h>
#include <aml-psdk/gta_base/Vector.h>
#include <aml-psdk/gta_base/GxtChar.h>
#include <aml-psdk/gta_base/RGBA.h>

enum eZoneType : u32
{
    ZONE_NAVIGATION,
    ZONE_LOCAL_NAVIGATION,
    ZONE_INFORMATION,
    ZONE_MAP,
    ZONE_TYPE_NAVI = ZONE_NAVIGATION,
    ZONE_TYPE_MAP = ZONE_MAP
};

struct CZoneInfo
{
    u8 m_nGangDensity[10];
    u8 m_nDealerCounter;
    CRGBA m_ZoneColor;
    union
    {
        u8 m_nFlags;
        struct
        {
            u8 m_nZonePopulationType : 5;
            u8 m_nRadarMode : 2;
            u8 m_bNoCops : 1;
        };
    };
    union
    {
        u8 m_nPopulationRace;
        struct
        {
            u8 m_nZonePopulationRace : 4;
        };
    };
};
CHECKSIZE(CZoneInfo, 0x11, 0x11);

DECL_CLASS(CZone)
    // Member functions
    DECL_THISCALL_SIMPLE(GetTranslatedName, _ZN5CZone17GetTranslatedNameEv, GxtChar*);

    // Member values
    union
    {
        unsigned long long m_nInfoLabel;
        char m_szLabel[8];
    };
    union
    {
        unsigned long long m_nTextLabel;
        char m_szTextKey[8];
    };
    i16 m_fX1;
    i16 m_fY1;
    i16 m_fZ1;
    i16 m_fX2;
    i16 m_fY2;
    i16 m_fZ2;
    u16 m_nZoneExtraIndexInfo;
    u8 m_nType;
    u8 m_nLevel;
DECL_CLASS_END()
CHECKSIZE(CZone, 0x20, 0x20);

typedef u8 tZoneVisitedRow[10];

DECL_CLASS(CTheZones)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(ZoneIsEntirelyContainedWithinOtherZone, _ZN9CTheZones38ZoneIsEntirelyContainedWithinOtherZoneEP5CZoneS1_, u8, CZone* pZone1, CZone* pZone2);
    DECL_FASTCALL_SIMPLE(Init, _ZN9CTheZones4InitEv, void);
    DECL_FASTCALL_SIMPLE(InitZonesPopulationSettings, _ZN9CTheZones27InitZonesPopulationSettingsEv, void);
    DECL_FASTCALL_SIMPLE(Update, _ZN9CTheZones6UpdateEv, void);
    DECL_FASTCALL_SIMPLE(ResetZonesRevealed, _ZN9CTheZones18ResetZonesRevealedEv, void);
    DECL_FASTCALL_SIMPLE(SetCurrentZoneAsUnlocked, _ZN9CTheZones24SetCurrentZoneAsUnlockedEv, void);
    DECL_FASTCALL_SIMPLE(GetCurrentZoneLockedOrUnlocked, _ZN9CTheZones30GetCurrentZoneLockedOrUnlockedEff, u8, float posx, float posy);
    DECL_FASTCALL_SIMPLE(CreateZone, _ZN9CTheZones10CreateZoneEPc9eZoneTypeffffff10eLevelNameS0_, void, char* name, eZoneType type, float posX1, float posY1, float posZ1, float posX2, float posY2, float posZ2, eLevelName island, char* GXT_key);
    DECL_FASTCALL_SIMPLE(AssignZoneInfoForThisZone, _ZN9CTheZones25AssignZoneInfoForThisZoneEt, void, u16 index);
    DECL_FASTCALL_SIMPLE(CheckZonesForOverlap, _ZN9CTheZones20CheckZonesForOverlapEv, void);
    DECL_FASTCALL_SIMPLE(PostZoneCreation, _ZN9CTheZones16PostZoneCreationEv, void);
    DECL_FASTCALL_SIMPLE(PointLiesWithinZone, _ZN9CTheZones19PointLiesWithinZoneEPK7CVectorP5CZone, u8, CVector const* pPoint, CZone* pZone);
    DECL_FASTCALL_SIMPLE(DoesPointLieWithinZoneWithGivenName, _ZN9CTheZones35DoesPointLieWithinZoneWithGivenNameEPK7CVectory9eZoneType, u8, CVector const* point, unsigned long long zoneName, eZoneType type);
    DECL_FASTCALL_SIMPLE(FindZoneByLabelAndReturnIndex, _ZN9CTheZones29FindZoneByLabelAndReturnIndexEPc9eZoneType, i16, char* name, eZoneType type);
    DECL_FASTCALL_SIMPLE(GetLevelFromPosition, _ZN9CTheZones20GetLevelFromPositionEPK7CVector, eLevelName, CVector const* pPoint);
    DECL_FASTCALL_SIMPLE(FindSmallestZoneForPosition, _ZN9CTheZones27FindSmallestZoneForPositionEPK7CVectorh, CZone*, CVector const* point, u8 FindOnlyZonesType0);
    DECL_FASTCALL_SIMPLE(GetZoneInfo, _ZN9CTheZones11GetZoneInfoEPK7CVectorPP5CZone, CZoneInfo*, CVector const* point, CZone** outzone);
    DECL_FASTCALL_SIMPLE(SetZoneRadarColours, _ZN9CTheZones19SetZoneRadarColoursEihhhh, void, i32 index, u8 flag, u8 red, u8 green, u8 blue);
    DECL_FASTCALL_SIMPLE(GetNavigationZone, _ZN9CTheZones17GetNavigationZoneEt, CZone*, u16 index);
    DECL_FASTCALL_SIMPLE(GetMapZone, _ZN9CTheZones10GetMapZoneEt, CZone*, u16 index);
    DECL_FASTCALL_SIMPLE(Save, _ZN9CTheZones4SaveEv, bool);
    DECL_FASTCALL_SIMPLE(Load, _ZN9CTheZones4LoadEv, bool);
    DECL_FASTCALL_SIMPLE(FillZonesWithGangColours, _ZN9CTheZones24FillZonesWithGangColoursEb, void, bool DisableRadarGangColors);
    DECL_FASTCALL_SIMPLE(Calc2DDistanceBetween2Zones, _ZN9CTheZones27Calc2DDistanceBetween2ZonesEP5CZoneS1_, float, CZone* Zone1, CZone* Zone2);

    // STATIC values
    DECL_OBJECT_PLT(eLevelName, m_CurrLevel, BYBIT(0x6788D4, 0x84F1C8));
    DECL_OBJECT_ARRAY_PLT(CZone, NavigationZoneArray, BYBIT(0x678550, 0x84EAB8));
    DECL_OBJECT_ARRAY_PLT(CZoneInfo, ZoneInfoArray, BYBIT(0x6781D8, 0x84E3C8));
    DECL_VALUE_PLT_U16(TotalNumberOfNavigationZones, BYBIT(0x676508, 0x84AA68));
    DECL_VALUE_PLT_U16(TotalNumberOfInfoZones, BYBIT(0x6787D8, 0x84EFD8));
    DECL_OBJECT_ARRAY_PLT(CZone, MapZoneArray, BYBIT(0x6777F8, 0x84D018));
    DECL_VALUE_PLT_U16(TotalNumberOfMapZones, BYBIT(0x677408, 0x84C848));
    DECL_OBJECT_ARRAY_PLT(tZoneVisitedRow, ExploredTerritoriesArray, BYBIT(0x676C84, 0x84B950));
    DECL_VALUE_PLT_U32(TotalNumberExploredTerritories, BYBIT(0x67743C, 0x84C8B0));

    static inline eLevelName GetLevelPlayerIsIn()
    {
        return m_CurrLevel();
    }
DECL_CLASS_END()
CHECKSIZE(CTheZones, 0x1, 0x1);

#define m_CurrLevel m_CurrLevel()
#define NavigationZoneArray NavigationZoneArray()
#define ZoneInfoArray ZoneInfoArray()
#define TotalNumberOfNavigationZones TotalNumberOfNavigationZones()
#define TotalNumberOfInfoZones TotalNumberOfInfoZones()
#define MapZoneArray MapZoneArray()
#define TotalNumberOfMapZones TotalNumberOfMapZones()
#define ExploredTerritoriesArray ExploredTerritoriesArray()
#define TotalNumberExploredTerritories TotalNumberExploredTerritories()

#endif // __AML_PSDK_SAZONES_H
