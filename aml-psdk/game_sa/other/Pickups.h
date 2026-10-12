#ifndef __AML_PSDK_SAPICKUPS_H
#define __AML_PSDK_SAPICKUPS_H

/*
    Plugin-SDK (Grand Theft Auto San Andreas) header file
    Authors: GTA Community. See more here
    https://github.com/DK22Pac/plugin-sdk
    Do not delete this comment block. Respect others' work!
*/

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/game_sa/entity/Pickup.h>
#include <aml-psdk/game_sa/enum/WeaponType.h>
#include <aml-psdk/gta_base/GxtChar.h>
#include <aml-psdk/gta_base/RGBA.h>

struct CEntity;

struct CPickupMessage
{
    float x;
    float y;
    eWeaponType weaponType;
    float width;
    float height;
    CRGBA color;
    union
    {
        u8 flags;
        struct
        {
            u8 bOutOfStock : 1;
            u8 bInsertAmountInString : 1;
        };
    };
    u8 messageNumber;
    u32 price;
    GxtChar* messageText;
};
CHECKSIZE(CPickupMessage, 0x24, 0x28);

typedef CPickupMessage tPickupMessage;

DECL_CLASS(CPickups)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(Init, _ZN8CPickups4InitEv, void);
    DECL_FASTCALL_SIMPLE(ReInit, _ZN8CPickups6ReInitEv, void);
    DECL_FASTCALL_SIMPLE(Update, _ZN8CPickups6UpdateEv, void);
    DECL_FASTCALL_SIMPLE(GenerateNewOne, _ZN8CPickups14GenerateNewOneE7CVectorjhjjbPc, i32, CVector coors, u32 modelId, u8 pickupType, u32 ammo, u32 moneyPerDay, bool isEmpty, char* message);
    DECL_FASTCALL_SIMPLE(GenerateNewOne_WeaponType, _ZN8CPickups25GenerateNewOne_WeaponTypeE7CVector11eWeaponTypehjbPc, i32, CVector coors, eWeaponType weaponType, u8 pickupType, u32 ammo, bool isEmpty, char* message);
    DECL_FASTCALL_SIMPLE(TryToMerge_WeaponType, _ZN8CPickups21TryToMerge_WeaponTypeE7CVector11eWeaponTypehjb, bool, CVector posn, eWeaponType weaponType, u8 pickupType, u32 ammo, bool arg4);
    DECL_FASTCALL_SIMPLE(ModelForWeapon, _ZN8CPickups14ModelForWeaponE11eWeaponType, i32, eWeaponType weaponType);
    DECL_FASTCALL_SIMPLE(WeaponForModel, _ZN8CPickups14WeaponForModelEi, eWeaponType, i32 modelId);
    DECL_FASTCALL_SIMPLE(IsPickUpPickedUp, _ZN8CPickups16IsPickUpPickedUpEi, bool, i32 pickupHandle);
    DECL_FASTCALL_SIMPLE(RemovePickUp, _ZN8CPickups12RemovePickUpEi, void, i32 pickupHandle);
    DECL_FASTCALL_SIMPLE(UpdateMoneyPerDay, _ZN8CPickups17UpdateMoneyPerDayEit, void, i32 pickupHandle, u16 money);
    DECL_FASTCALL_SIMPLE(DetonateMinesHitByGunShot, _ZN8CPickups25DetonateMinesHitByGunShotEP7CVectorS1_, void, CVector* shotOrigin, CVector* shotTarget);
    DECL_FASTCALL_SIMPLE(DoPickUpEffects, _ZN8CPickups15DoPickUpEffectsEP7CEntity, void, CEntity* entity);
    DECL_FASTCALL_SIMPLE(DoMoneyEffects, _ZN8CPickups14DoMoneyEffectsEP7CEntity, void, CEntity* entity);
    DECL_FASTCALL_SIMPLE(DoMineEffects, _ZN8CPickups13DoMineEffectsEP7CEntity, void, CEntity* entity);
    DECL_FASTCALL_SIMPLE(DoCollectableEffects, _ZN8CPickups20DoCollectableEffectsEP7CEntity, void, CEntity* entity);
    DECL_FASTCALL_SIMPLE(RenderPickUpText, _ZN8CPickups16RenderPickUpTextEv, void);
    DECL_FASTCALL_SIMPLE(CreatePickupCoorsCloseToCoors, _ZN8CPickups29CreatePickupCoorsCloseToCoorsEfffPfS0_S0_, void, float in_x, float in_y, float in_z, float* out_x, float* out_y, float* out_z);
    DECL_FASTCALL_SIMPLE(TestForPickupsInBubble, _ZN8CPickups22TestForPickupsInBubbleE7CVectorf, bool, CVector posn, float radius);
    DECL_FASTCALL_SIMPLE(GivePlayerGoodiesWithPickUpMI, _ZN8CPickups29GivePlayerGoodiesWithPickUpMIEti, bool, u16 modelId, i32 playerId);
    DECL_FASTCALL_SIMPLE(PassTime, _ZN8CPickups8PassTimeEj, void, u32 time);
    DECL_FASTCALL_SIMPLE(AddToCollectedPickupsArray, _ZN8CPickups26AddToCollectedPickupsArrayEi, void, i32 handle);
    DECL_FASTCALL_SIMPLE(GetNewUniquePickupIndex, _ZN8CPickups23GetNewUniquePickupIndexEi, i32, i32 pickupIndex);
    DECL_FASTCALL_SIMPLE(GetUniquePickupIndex, _ZN8CPickups20GetUniquePickupIndexEi, i32, i32 pickupIndex);
    DECL_FASTCALL_SIMPLE(GetActualPickupIndex, _ZN8CPickups20GetActualPickupIndexEi, i32, i32 pickupIndex);
    DECL_FASTCALL_SIMPLE(Save, _ZN8CPickups4SaveEv, bool);
    DECL_FASTCALL_SIMPLE(Load, _ZN8CPickups4LoadEv, bool);
    DECL_FASTCALL_SIMPLE(CreateSomeMoney, _ZN8CPickups15CreateSomeMoneyE7CVectori, void, CVector coors, i32 amount);
    DECL_FASTCALL_SIMPLE(FindPickUpForThisObject, _ZN8CPickups23FindPickUpForThisObjectEP7CObject, CPickup*, CObject* object);
    DECL_FASTCALL_SIMPLE(RemoveUnnecessaryPickups, _ZN8CPickups24RemoveUnnecessaryPickupsERK7CVectorf, void, CVector const& posn, float radius);
    DECL_FASTCALL_SIMPLE(PictureTaken, _ZN8CPickups12PictureTakenEv, void);
    DECL_FASTCALL_SIMPLE(PickedUpOyster, _ZN8CPickups14PickedUpOysterEv, void);
    DECL_FASTCALL_SIMPLE(PickedUpHorseShoe, _ZN8CPickups17PickedUpHorseShoeEv, void);
    DECL_FASTCALL_SIMPLE(RemovePickupObjects, _ZN8CPickups19RemovePickupObjectsEv, void);
    DECL_FASTCALL_SIMPLE(PlayerCanPickUpThisWeaponTypeAtThisMoment, _ZN8CPickups41PlayerCanPickUpThisWeaponTypeAtThisMomentE11eWeaponType, bool, eWeaponType weaponType);
    DECL_FASTCALL_SIMPLE(RemovePickUpsInArea, _ZN8CPickups19RemovePickUpsInAreaEffffff, void, float cornerA_x, float cornerA_y, float cornerA_z, float cornerB_x, float cornerB_y, float cornerB_z);
    DECL_FASTCALL_SIMPLE(RemoveMissionPickUps, _ZN8CPickups20RemoveMissionPickUpsEv, void);

    // STATIC values
    DECL_OBJECT_ARRAY_PLT(CPickup, aPickUps, BYBIT(0x678BF8, 0x84F818));
    DECL_OBJECT_ARRAY_PLT(CPickupMessage, aMessages, BYBIT(0x679240, 0x8504A0));
    DECL_VALUE_PLT_U16(NumMessages, BYBIT(0x677D20, 0x84DA60));
    DECL_OBJECT_ARRAY_PLT(i32, aPickUpsCollected, BYBIT(0x67732C, 0x84C690));
    DECL_VALUE_PLT_U16(CollectedPickUpIndex, BYBIT(0x676BF8, 0x84B838));
    DECL_VALUE_PLT_BOOL(bPickUpcamActivated, BYBIT(0x67822C, 0x84E470));
    DECL_OBJECT_PLT(CEntity*, pPlayerVehicle, BYBIT(0x6769C8, 0x84B3D8));
    DECL_OBJECT_PLT(CVector, StaticCamCoors, BYBIT(0x67948C, 0x850930));
    DECL_VALUE_PLT_U32(StaticCamStartTime, BYBIT(0x677B64, 0x84D6E8));
    DECL_VALUE_PLT_I32(PlayerOnWeaponPickup, BYBIT(0x679D70, 0x851AF8));
    DECL_VALUE_PLT_U8(DisplayHelpMessage, BYBIT(0x679FEC, 0x851FE8));
DECL_CLASS_END()
CHECKSIZE(CPickups, 0x1, 0x1);

#define aPickUps aPickUps()
#define aMessages aMessages()
#define NumMessages NumMessages()
#define aPickUpsCollected aPickUpsCollected()
#define CollectedPickUpIndex CollectedPickUpIndex()
#define bPickUpcamActivated bPickUpcamActivated()
#define pPlayerVehicle pPlayerVehicle()
#define StaticCamCoors StaticCamCoors()
#define StaticCamStartTime StaticCamStartTime()
#define PlayerOnWeaponPickup PlayerOnWeaponPickup()
#define DisplayHelpMessage DisplayHelpMessage()

#endif // __AML_PSDK_SAPICKUPS_H
