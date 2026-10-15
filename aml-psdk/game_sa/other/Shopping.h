#ifndef __AML_PSDK_SASHOPPING_H
#define __AML_PSDK_SASHOPPING_H

#include <aml-psdk/game_sa/plugin.h>

struct CMultiBuilding;

enum ObjectPriceSection
{
    NoPrices = 0,
    CarModsPrices = 1,
    CarPaintJobPrices = 2,
    FurniturePrices = 3,
    ClothesPrices = 4,
    HaircutPrices = 5,
    TattoosPrices = 6,
    GiftsPrices = 7,
    FoodPrices = 8,
    WeaponsPrices = 9,
    PropertyPrices = 10,
    NumberOfPrices = 11,
};

DECL_CLASS(CShopping)
    struct ItemPrice
    {
        // Member values
        u32 key;
        u32 price;
        union
        {
            struct
            {
                u32 ammo;
            } weapon;
            struct
            {
                u32 modelKey;
                u32 type;
            } clothes;
            struct
            {
                u32 type1;
                u32 texKey;
            } tattoos;
            struct
            {
                i32 extra1;
                i32 extra2;
            } general;
        };
        char nameTag[8];
    };
    CHECKSIZE(CShopping::ItemPrice, 0x18, 0x18);

    struct PriceModifier
    {
        // Member values
        u32 key;
        u32 price;
    };
    CHECKSIZE(CShopping::PriceModifier, 0x8, 0x8);

    struct StatModifier
    {
        // Member values
        i8 stat1;
        i8 stat1Change;
        i8 stat2;
        i8 stat2Change;
    };
    CHECKSIZE(CShopping::StatModifier, 0x4, 0x4);

    // STATIC functions
    DECL_FASTCALL_SIMPLE(Init, _ZN9CShopping4InitEv, void);
    DECL_FASTCALL_SIMPLE(ShutdownForRestart, _ZN9CShopping18ShutdownForRestartEv, void);
    DECL_FASTCALL_SIMPLE(LoadPrices, _ZN9CShopping10LoadPricesEPKc, void, char const* pSectionName);
    DECL_FASTCALL_SIMPLE(LoadShop, _ZN9CShopping8LoadShopEPKc, void, char const* pShopName);
    DECL_FASTCALL_SIMPLE(LoadStats, _ZN9CShopping9LoadStatsEv, void);
    DECL_FASTCALL_SIMPLE(GetPrice, _ZN9CShopping8GetPriceEj, i32, u32 key);
    DECL_FASTCALL_SIMPLE(Buy, _ZN9CShopping3BuyEji, void, u32 key, i32 extraInfo);
    DECL_FASTCALL_SIMPLE(IncrementStat, _ZN9CShopping13IncrementStatEii, void, i32 statIndex, i32 change);
    DECL_FASTCALL_SIMPLE(IncrementStat2, _ZN9CShopping14IncrementStat2Eii, void, i32 stat, i32 change);
    DECL_FASTCALL_SIMPLE(UpdateStats, _ZN9CShopping11UpdateStatsEib, void, i32 index, bool bIncrement);
    DECL_FASTCALL_SIMPLE(GetExtraInfo, _ZN9CShopping12GetExtraInfoEji, i32, u32 key, i32 index);
    DECL_FASTCALL_SIMPLE(GetNameTag, _ZN9CShopping10GetNameTagEj, char const*, u32 key);
    DECL_FASTCALL_SIMPLE(RemoveLoadedShop, _ZN9CShopping16RemoveLoadedShopEv, void);
    DECL_FASTCALL_SIMPLE(RemoveLoadedPrices, _ZN9CShopping18RemoveLoadedPricesEv, void);
    DECL_FASTCALL_SIMPLE(GetPriceSectionFromName, _ZN9CShopping23GetPriceSectionFromNameEPKc, i32, char const* pSectionName);
    DECL_FASTCALL_SIMPLE(SetCurrentProperty, _ZN9CShopping18SetCurrentPropertyEP14CMultiBuilding, void, CMultiBuilding* pProperty);
    DECL_FASTCALL_SIMPLE(StoreClothesState, _ZN9CShopping17StoreClothesStateEv, void);
    DECL_FASTCALL_SIMPLE(RestoreClothesState, _ZN9CShopping19RestoreClothesStateEv, void);
    DECL_FASTCALL_SIMPLE(StoreVehicleMods, _ZN9CShopping16StoreVehicleModsEv, void);
    DECL_FASTCALL_SIMPLE(RestoreVehicleMods, _ZN9CShopping18RestoreVehicleModsEv, void);
    DECL_FASTCALL_SIMPLE(SetPlayerHasBought, _ZN9CShopping18SetPlayerHasBoughtEj, void, u32 key);
    DECL_FASTCALL_SIMPLE(HasPlayerBought, _ZN9CShopping15HasPlayerBoughtEj, bool, u32 key);
    DECL_FASTCALL_SIMPLE(AddPriceModifier1, _ZN9CShopping16AddPriceModifierEPKcS1_i, void, char const* pName, char const* pSection, i32 price);
    inline static void AddPriceModifier(char const* pName, char const* pSection, i32 price) { return AddPriceModifier1(pName, pSection, price); }
    DECL_FASTCALL_SIMPLE(AddPriceModifier2, _ZN9CShopping16AddPriceModifierEji, void, u32 key, i32 price);
    inline static void AddPriceModifier(u32 key, i32 price) { return AddPriceModifier2(key, price); }
    DECL_FASTCALL_SIMPLE(RemovePriceModifier1, _ZN9CShopping19RemovePriceModifierEPKcS1_, void, char const* pName, char const* pSection);
    inline static void RemovePriceModifier(char const* pName, char const* pSection) { return RemovePriceModifier1(pName, pSection); }
    DECL_FASTCALL_SIMPLE(RemovePriceModifier2, _ZN9CShopping19RemovePriceModifierEj, void, u32 key);
    inline static void RemovePriceModifier(u32 key) { return RemovePriceModifier2(key); }
    DECL_FASTCALL_SIMPLE(Save, _ZN9CShopping4SaveEv, bool);
    DECL_FASTCALL_SIMPLE(Load, _ZN9CShopping4LoadEv, bool);
    DECL_FASTCALL_SIMPLE(GetKey, _ZN9CShopping6GetKeyEPKci, u32, char const* pTag, i32 section);
    DECL_FASTCALL_SIMPLE(FindItem, _ZN9CShopping8FindItemEj, i32, u32 key);
    DECL_FASTCALL_SIMPLE(GetItemIndex, _ZN9CShopping12GetItemIndexEj, i32, u32 key);
    DECL_FASTCALL_SIMPLE(FindSection, BYBIT(_ZN9CShopping11FindSectionEjPKc, _ZN9CShopping11FindSectionEyPKc), bool, uptr fid, char const* pSectionName);
    DECL_FASTCALL_SIMPLE(GetNextSection, BYBIT(_ZN9CShopping14GetNextSectionEj, _ZN9CShopping14GetNextSectionEy), char const*, uptr fid);
    DECL_FASTCALL_SIMPLE(FindSectionInSection, BYBIT(_ZN9CShopping20FindSectionInSectionEjPKcS1_, _ZN9CShopping20FindSectionInSectionEyPKcS1_), bool, uptr fid, char const* pParentSectionName, char const* pSectionName);

    // STATIC values
    DECL_VALUE_PLT_I32(ms_priceSectionLoaded, BYBIT(0x677F1C, 0x84DE58));
    DECL_VALUE_PLT_I32(ms_numPrices, BYBIT(0x679D54, 0x851AC0));
    DECL_OBJECT_ARRAY_PLT(CShopping::ItemPrice, ms_prices, BYBIT(0x677158, 0x84C2E8));
    DECL_VALUE_PLT_I32(ms_numPriceModifiers, BYBIT(0x676B8C, 0x84B760));
    DECL_OBJECT_ARRAY_PLT(CShopping::PriceModifier, ms_priceModifiers, BYBIT(0x6798DC, 0x8511D8));
    DECL_OBJECT_ARRAY_PLT(char, ms_shopLoaded, BYBIT(0x67700C, 0x84C050));
    DECL_VALUE_PLT_I32(ms_numItemsInShop, BYBIT(0x679740, 0x850E88));
    DECL_OBJECT_ARRAY_PLT(u32, ms_shopContents, BYBIT(0x679128, 0x850278));
    DECL_OBJECT_ARRAY_PLT(char const*, ms_sectionNames, BYBIT(0x678620, 0x84EC60));
    DECL_VALUE_PLT_U32(ms_numBuyableItems, BYBIT(0x679058, 0x8500D8));
    DECL_OBJECT_ARRAY_PLT(u32, ms_keys, BYBIT(0x677BA8, 0x84D770));
    DECL_OBJECT_ARRAY_PLT(CShopping::StatModifier, ms_statModifiers, BYBIT(0x677D64, 0x84DAE8));
    DECL_OBJECT_ARRAY_PLT(bool, ms_bHasBought, BYBIT(0x6783D0, 0x84E7B8));

    // Helper functions
    inline static i32 GetNumItemsInShop() { return ms_numItemsInShop(); }
    inline static i32 GetItemInShop(i32 index) { return ms_shopContents()[index]; }
    inline static const char* GetShopLoaded() { return ms_shopLoaded(); }
    inline static i32 GetPricesLoaded() { return ms_priceSectionLoaded(); }
    inline static const char* GetPriceSectionName(i32 section) { return ms_sectionNames()[section]; }
DECL_CLASS_END()
CHECKSIZE(CShopping, 0x1, 0x1);

#endif // __AML_PSDK_SASHOPPING_H
