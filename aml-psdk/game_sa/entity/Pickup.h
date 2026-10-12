#ifndef __AML_PSDK_SAPICKUP_H
#define __AML_PSDK_SAPICKUP_H

#include <aml-psdk/gta_base/Vector.h>

struct CObject;
struct CPlayerPed;
struct CVehicle;

enum ePickupType : unsigned char
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
    PICKUP_PROPERTY_FORSALE = 18,
    PICKUP_MONEY_DOESNTDISAPPEAR = 19,
    PICKUP_SNAPSHOT = 20,
    PICKUP_2P = 21,
    PICKUP_ONCE_FOR_MISSION = 22
};

enum ePickupPropertyText : unsigned char
{
    PICKUP_PROPERTYTEXT_CANCEL = 0,   // "Cancel"
    PICKUP_PROPERTYTEXT_CANT_BUY = 1, // "You can't buy..."
    PICKUP_PROPERTYTEXT_CAN_BUY = 2   // "Press TAB to buy ..."
};

DECL_CLASS(CPickup, B64MACRO(__attribute__((packed)) __attribute__((aligned(4)))) )
    // Member functions
    DECL_THISCALL_SIMPLE(Remove, _ZN7CPickup6RemoveEv, void);
    DECL_THISCALL_SIMPLE(IsPickUpCloseEnoughForObjects, _ZN7CPickup29IsPickUpCloseEnoughForObjectsEv, bool);
    DECL_THISCALL_SIMPLE(GetRidOfObjects, _ZN7CPickup15GetRidOfObjectsEv, void);
    DECL_THISCALL_SIMPLE(PickUpShouldBeInvisible, _ZN7CPickup23PickUpShouldBeInvisibleEv, bool);
    
    DECL_THISCALL_HEAD(GiveUsAPickUpObject, _ZN7CPickup19GiveUsAPickUpObjectEPP7CObjecti, void, CObject** ppObject, int ForcedObjectIndex)
    DECL_THISCALL_TAIL(GiveUsAPickUpObject, ppObject, ForcedObjectIndex)
    
    DECL_THISCALL_HEAD(Update, _ZN7CPickup6UpdateEP10CPlayerPedP8CVehiclei, bool, CPlayerPed* pPlayerPed, CVehicle* pPlayerVehicle, int PlayerNum)
    DECL_THISCALL_TAIL(Update, pPlayerPed, pPlayerVehicle, PlayerNum)
    
    DECL_THISCALL_HEAD(FindTextIndexForString, _ZN7CPickup22FindTextIndexForStringEPc, int, char* pString)
    DECL_THISCALL_TAIL(FindTextIndexForString, pString)
    
    DECL_THISCALL_HEAD(ProcessGunShot, _ZN7CPickup14ProcessGunShotEP7CVectorS1_, void, CVector* pStart, CVector* pEnd)
    DECL_THISCALL_TAIL(ProcessGunShot, pStart, pEnd)
    
    DECL_THISCALL_HEAD(ExtractAmmoFromPickup, _ZN7CPickup21ExtractAmmoFromPickupEP10CPlayerPed, void, CPlayerPed* pPlayerPed)
    DECL_THISCALL_TAIL(ExtractAmmoFromPickup, pPlayerPed)
    
    DECL_THISCALL_HEAD(FindStringForTextIndex, _ZN7CPickup22FindStringForTextIndexEi, const char*, int TextIndex)
    DECL_THISCALL_TAIL(FindStringForTextIndex, TextIndex)
    
    // Member values
    float             m_fRevenueValue;
    CObject          *m_pObject;
    int               m_nAmmo;
    unsigned int      m_nRegenerationTime;
    CompressedVector  m_vecPos;
    unsigned short    m_nMoneyPerDay;
    unsigned short    m_nModelIndex;
    unsigned short    m_nReferenceIndex;
    unsigned char     m_nPickupType; // see ePickupType
    struct
    {
        unsigned char   bDisabled : 1; // waiting for regeneration
        unsigned char   bEmpty : 1; // no ammo
        unsigned char   bHelpMessageDisplayed : 1;
        unsigned char   bVisible : 1;
        unsigned char   nPropertyTextIndex : 3; // see enum ePickupPropertyText
    } m_nFlags;
DECL_CLASS_END()
CHECKSIZE(CPickup, 0x20, 0x24);

#endif // __AML_PSDK_SAPICKUP_H
