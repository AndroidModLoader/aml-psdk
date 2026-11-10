#ifndef __AML_PSDK_VCPICKUPS_H
#define __AML_PSDK_VCPICKUPS_H

#include "Weapon.h"
#include <aml-psdk/gta_base/RGBA.h>

enum ePickupType : u8
{
    PICKUP_NONE = 0,
    PICKUP_IN_SHOP = 1,
    PICKUP_ON_STREET = 2,
    PICKUP_ONCE = 3,
    PICKUP_ONCE_TIMEOUT = 4,
    PICKUP_ONCE_TIMEOUT_SLOW = 5,
    PICKUP_COLLECTABLE1 = 6,
    PICKUP_IN_SHOP_OUT_OF_STOCK = 7,
    PICKUP_MONEY = 8,
    PICKUP_MINE_INACTIVE = 9,
    PICKUP_MINE_ARMED = 10,
    PICKUP_NAUTICAL_MINE_INACTIVE = 11,
    PICKUP_NAUTICAL_MINE_ARMED = 12,
    PICKUP_FLOATINGPACKAGE = 13,
    PICKUP_FLOATINGPACKAGE_FLOATING = 14,
    PICKUP_ON_STREET_SLOW = 15,
    PICKUP_ASSET_REVENUE = 16,
    PICKUP_PROPERTY_LOCKED = 17,
    PICKUP_PROPERTY_FORSALE = 18
};

struct CObject;
struct CPlayerPed;
struct CVehicle;

#pragma pack(push, 4)
DECL_CLASS(CPickup)
    // Member functions
    DECL_THISCALL_HEAD(Update, _ZN7CPickup6UpdateEP10CPlayerPedP8CVehiclei, bool, CPlayerPed* player, CVehicle* vehicle, i32 playerId)
    DECL_THISCALL_TAIL(Update, player, vehicle, playerId)
    DECL_THISCALL_HEAD(GiveUsAPickUpObject, _ZN7CPickup19GiveUsAPickUpObjectEPP7CObjectS2_ii, void, CObject** object, CObject** extraObject, i32 objectIndex, i32 extraObjectIndex)
    DECL_THISCALL_TAIL(GiveUsAPickUpObject, object, extraObject, objectIndex, extraObjectIndex)
    DECL_THISCALL_SIMPLE(GetRidOfObjects, _ZN7CPickup15GetRidOfObjectsEv, void);
    DECL_THISCALL_HEAD(ProcessGunShot, _ZN7CPickup14ProcessGunShotEP7CVectorS1_, void, CVector* start, CVector* end)
    DECL_THISCALL_TAIL(ProcessGunShot, start, end)
    DECL_THISCALL_HEAD(ExtractAmmoFromPickup, _ZN7CPickup21ExtractAmmoFromPickupEP10CPlayerPed, void, CPlayerPed* player)
    DECL_THISCALL_TAIL(ExtractAmmoFromPickup, player)

    // Member values
    CVector vecPos;
    float fRevenue;
    CObject* pObject;
    CObject* pExtraObject;
    u32 dwPickupQuantity;
    u32 nTimer;
    u16 wMoneySpeed;
    i16 nModelId;
    u16 wUniqueId;
    char szPickupTextKey[8];
    u8 bPickupType;
    bool bRemoved;
    union
    {
        u8 nFlags;
        struct
        {
            u8 bAmmoCollected : 1;
            u8 bHelpMessageDisplayed : 1;
        };
    };
DECL_CLASS_END()
#pragma pack(pop)
CHECKSIZE(CPickup, 0x34, 0x3C);

struct tPickupMessage
{
    CVector2D Pos;
    eWeaponType WeaponType;
    float fW;
    float fH;
    CRGBA Color;
    union
    {
        u8 Flags;
        struct
        {
            u8 bOutOfStock : 1;
        };
    };
    u8 nTextID;
    u16 nPrice;
};
CHECKSIZE(tPickupMessage, 0x1C, 0x1C);

DECL_CLASS(CPickups)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(Init, _ZN8CPickups4InitEv, void);
    DECL_FASTCALL_SIMPLE(Update, _ZN8CPickups6UpdateEv, void);
    DECL_FASTCALL_SIMPLE(GenerateNewOne, _ZN8CPickups14GenerateNewOneE7CVectorjhjjbPc, i32, CVector position, u32 modelId, u8 type, u32 quantity, u32 moneySpeed, bool highPriority, char* text);
    DECL_FASTCALL_SIMPLE(GenerateNewOne_WeaponType, _ZN8CPickups25GenerateNewOne_WeaponTypeE7CVector11eWeaponTypehjbPc, i32, CVector position, eWeaponType weaponType, u8 type, u32 quantity, bool highPriority, char* text);
    DECL_FASTCALL_SIMPLE(TryToMerge_WeaponType, _ZN8CPickups21TryToMerge_WeaponTypeE7CVector11eWeaponTypehjb, bool, CVector position, eWeaponType weaponType, u8 type, u32 quantity, bool unused);
    DECL_FASTCALL_SIMPLE(GetActualPickupIndex, _ZN8CPickups20GetActualPickupIndexEi, i32, i32 handle);
    DECL_FASTCALL_SIMPLE(GetNewUniquePickupIndex, _ZN8CPickups23GetNewUniquePickupIndexEi, i32, i32 index);
    DECL_FASTCALL_SIMPLE(AddToCollectedPickupsArray, _ZN8CPickups26AddToCollectedPickupsArrayEi, void, i32 index);
    DECL_FASTCALL_SIMPLE(IsPickUpPickedUp, _ZN8CPickups16IsPickUpPickedUpEi, bool, i32 handle);
    DECL_FASTCALL_SIMPLE(RemovePickUp, _ZN8CPickups12RemovePickUpEi, void, i32 handle);
    DECL_FASTCALL_SIMPLE(RemoveUnnecessaryPickups, _ZN8CPickups24RemoveUnnecessaryPickupsERK7CVectorf, void, CVector const& position, float radius);
    DECL_FASTCALL_SIMPLE(RemoveAllPickupsOfACertainWeaponGroupWithNoAmmo, _ZN8CPickups47RemoveAllPickupsOfACertainWeaponGroupWithNoAmmoE11eWeaponType, void, eWeaponType type);
    DECL_FASTCALL_SIMPLE(PassTime, _ZN8CPickups8PassTimeEj, void, u32 time);
    DECL_FASTCALL_SIMPLE(ModelForWeapon, _ZN8CPickups14ModelForWeaponE11eWeaponType, i32, eWeaponType type);
    DECL_FASTCALL_SIMPLE(WeaponForModel, _ZN8CPickups14WeaponForModelEi, eWeaponType, i32 modelId);
    DECL_FASTCALL_SIMPLE(GivePlayerGoodiesWithPickUpMI, _ZN8CPickups29GivePlayerGoodiesWithPickUpMIEti, bool, u16 modelId, i32 playerId);
    // Native lookup returns the first pickup when no object matches.
    DECL_FASTCALL_SIMPLE(FindPickUpForThisObject, _ZN8CPickups23FindPickUpForThisObjectEP7CObject, CPickup*, CObject* object);
    DECL_FASTCALL_SIMPLE(TestForPickupsInBubble, _ZN8CPickups22TestForPickupsInBubbleE7CVectorf, bool, CVector position, float radius);
    DECL_FASTCALL_SIMPLE(DetonateMinesHitByGunShot, _ZN8CPickups25DetonateMinesHitByGunShotEP7CVectorS1_, void, CVector* start, CVector* end);
    DECL_FASTCALL_SIMPLE(CreateSomeMoney, _ZN8CPickups15CreateSomeMoneyE7CVectori, void, CVector position, i32 amount);
    DECL_FASTCALL_SIMPLE(DoCollectableEffects, _ZN8CPickups20DoCollectableEffectsEP7CEntity, void, CEntity* entity);
    DECL_FASTCALL_SIMPLE(DoMineEffects, _ZN8CPickups13DoMineEffectsEP7CEntity, void, CEntity* entity);
    DECL_FASTCALL_SIMPLE(DoMoneyEffects, _ZN8CPickups14DoMoneyEffectsEP7CEntity, void, CEntity* entity);
    DECL_FASTCALL_SIMPLE(DoPickUpEffects, _ZN8CPickups15DoPickUpEffectsEP7CEntity, void, CEntity* entity);
    DECL_FASTCALL_SIMPLE(RenderPickUpText, _ZN8CPickups16RenderPickUpTextEv, void);
    DECL_FASTCALL_SIMPLE(Save, _ZN8CPickups4SaveEPhPj, void, u8* buffer, u32* size);
    DECL_FASTCALL_SIMPLE(Load, _ZN8CPickups4LoadEPhj, void, u8* buffer, u32 size);

    // STATIC values
    DECL_OBJECT_ARRAY_PLT(CPickup, aPickUps, BYBIT(0x395D6C, 0x579AF8));
    DECL_OBJECT_ARRAY_PLT(tPickupMessage, aMessages, BYBIT(0x3949B4, 0x577450));
    DECL_OBJECT_ARRAY_PLT(i32, aPickUpsCollected, BYBIT(0x395A64, 0x5794F0));
    DECL_VALUE_PLT_I16(NumMessages, BYBIT(0x39477C, 0x577048));
    DECL_VALUE_PLT_I16(CollectedPickUpIndex, BYBIT(0x395858, 0x579100));
    DECL_VALUE_PLT_BOOL(bPickUpcamActivated, BYBIT(0x395418, 0x578888));
    DECL_VALUE_PLT_U32(StaticCamStartTime, BYBIT(0x39578C, 0x578F90));
    DECL_OBJECT_PLT(CVector, StaticCamCoors, BYBIT(0x396AFC, 0x57B600));
    DECL_OBJECT_PLT(CVehicle*, pPlayerVehicle, BYBIT(0x396B78, 0x57B6E8));
    DECL_VALUE_PLT_I32(PlayerOnWeaponPickup, BYBIT(0x39652C, 0x57AA48));

    // Helper functions
    static inline CPickup* GetPickup(i32 handle)
    {
        i32 index = (u32)handle & 0xFFFF;
        if(index >= 336 || GetActualPickupIndex(handle) < 0) return NULL;
        return &aPickUps()[index];
    }
DECL_CLASS_END()

#define aPickUps aPickUps()
#define aMessages aMessages()
#define aPickUpsCollected aPickUpsCollected()
#define NumMessages NumMessages()
#define CollectedPickUpIndex CollectedPickUpIndex()
#define bPickUpcamActivated bPickUpcamActivated()
#define StaticCamStartTime StaticCamStartTime()
#define StaticCamCoors StaticCamCoors()
#define pPlayerVehicle pPlayerVehicle()
#define PlayerOnWeaponPickup PlayerOnWeaponPickup()

#endif // __AML_PSDK_VCPICKUPS_H
