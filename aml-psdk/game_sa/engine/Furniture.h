#ifndef __AML_PSDK_SAFURNITURE_H
#define __AML_PSDK_SAFURNITURE_H

#include <aml-psdk/game_sa/base/Lists.h>

struct CEntity;

DECL_CLASS_BASED(Furniture_c, ListItem_c)
    // Member values
    u16 m_modelIndex;
    i16 m_refId;
    u8 m_width;
    u8 m_depth;
    u8 m_ratingMin;
    u8 m_ratingMax;
    u8 m_onWindowTile;
    u8 m_isTall;
    u8 m_isStealable;
    u8 m_maxAngle;
DECL_CLASS_END()
CHECKSIZE(Furniture_c, 0x14, 0x20);

DECL_CLASS_BASED(FurnitureEntity_c, ListItem_c)
    // Member values
    CEntity* m_pData;
    u16 m_tileX;
    u16 m_tileY;
DECL_CLASS_END()
CHECKSIZE(FurnitureEntity_c, 0x10, 0x20);

DECL_CLASS_BASED(FurnitureSubGroup_c, ListItem_c)
    // Member functions
    DECL_THISCALL_HEAD(AddFurniture, _ZN19FurnitureSubGroup_c12AddFurnitureEtshhh, u8, u16 modelIndex, i16 refId, u8 minRating, u8 maxRating, u8 maxAngle)
    DECL_THISCALL_TAIL(AddFurniture, modelIndex, refId, minRating, maxRating, maxAngle)
    DECL_THISCALL_HEAD(GetFurniture, _ZN19FurnitureSubGroup_c12GetFurnitureEsh, Furniture_c*, i16 refId, u8 rating)
    DECL_THISCALL_TAIL(GetFurniture, refId, rating)
    DECL_THISCALL_HEAD(GetRandomId, _ZN19FurnitureSubGroup_c11GetRandomIdEh, i32, u8 rating)
    DECL_THISCALL_TAIL(GetRandomId, rating)

    // Member values
    i32 m_subGroupId;
    List_c m_furnitureList;
    u8 m_onWindowTile;
    u8 m_isTall;
    u8 m_isStealable;
DECL_CLASS_END()
CHECKSIZE(FurnitureSubGroup_c, 0x1C, 0x38);

DECL_CLASS(FurnitureGroup_c)
    // Member functions
    DECL_THISCALL_SIMPLE(Init, _ZN16FurnitureGroup_c4InitEv, i32);
    DECL_THISCALL_SIMPLE(Exit, _ZN16FurnitureGroup_c4ExitEv, void);
    DECL_THISCALL_HEAD(AddSubGroup, _ZN16FurnitureGroup_c11AddSubGroupEiiiiihhh, u8, i32 subGroupId, i32 minW, i32 minD, i32 maxW, i32 maxD, u8 onWindow, u8 isTall, u8 isStealable)
    DECL_THISCALL_TAIL(AddSubGroup, subGroupId, minW, minD, maxW, maxD, onWindow, isTall, isStealable)
    DECL_THISCALL_HEAD(AddFurniture, _ZN16FurnitureGroup_c12AddFurnitureEitshhh, u8, i32 subGroupId, u16 modelIndex, i16 refId, u8 minRating, u8 maxRating, u8 maxAngle)
    DECL_THISCALL_TAIL(AddFurniture, subGroupId, modelIndex, refId, minRating, maxRating, maxAngle)
    DECL_THISCALL_HEAD(GetFurniture, _ZN16FurnitureGroup_c12GetFurnitureEish, Furniture_c*, i32 subGroupId, i16 refId, u8 rating)
    DECL_THISCALL_TAIL(GetFurniture, subGroupId, refId, rating)
    DECL_THISCALL_HEAD(GetRandomId, _ZN16FurnitureGroup_c11GetRandomIdEih, i32, i32 subGroupId, u8 rating)
    DECL_THISCALL_TAIL(GetRandomId, subGroupId, rating)

    // Member values
    List_c m_subGroupList;
DECL_CLASS_END()
CHECKSIZE(FurnitureGroup_c, 0xC, 0x18);

DECL_CLASS(FurnitureManager_c)
    // Member functions
    DECL_CTORCALL(FurnitureManager_c, _ZN18FurnitureManager_cC2Ev);
    DECL_DTORCALL(FurnitureManager_c, _ZN18FurnitureManager_cD2Ev);
    DECL_THISCALL_SIMPLE(Init, _ZN18FurnitureManager_c4InitEv, i32);
    DECL_THISCALL_SIMPLE(Exit, _ZN18FurnitureManager_c4ExitEv, void);
    DECL_THISCALL_HEAD(GetFurniture, _ZN18FurnitureManager_c12GetFurnitureEiish, Furniture_c*, i32 groupId, i32 subGroupId, i16 refId, u8 rating)
    DECL_THISCALL_TAIL(GetFurniture, groupId, subGroupId, refId, rating)
    DECL_THISCALL_HEAD(GetRandomId, _ZN18FurnitureManager_c11GetRandomIdEiih, i32, i32 groupId, i32 subGroupId, u8 rating)
    DECL_THISCALL_TAIL(GetRandomId, groupId, subGroupId, rating)
    DECL_THISCALL_SIMPLE(LoadFurniture, _ZN18FurnitureManager_c13LoadFurnitureEv, void);
    DECL_THISCALL_HEAD(GetGroupId, _ZN18FurnitureManager_c10GetGroupIdEPc, i32, char* groupString)
    DECL_THISCALL_TAIL(GetGroupId, groupString)
    DECL_THISCALL_HEAD(GetSubGroupId, _ZN18FurnitureManager_c13GetSubGroupIdEPc, i32, char* subGroupString)
    DECL_THISCALL_TAIL(GetSubGroupId, subGroupString)

    // Member values
    FurnitureGroup_c m_groups[9];
    FurnitureEntity_c m_furnitureEntities[512];
    List_c m_furnitureEntityPool;
DECL_CLASS_END()
CHECKSIZE(FurnitureManager_c, 0x2078, 0x40F0);

DECL_OBJECT_PLT_GLOBAL(FurnitureManager_c, g_furnitureMan, BYBIT(0x679BA8, 0x851770));

#endif // __AML_PSDK_SAFURNITURE_H
