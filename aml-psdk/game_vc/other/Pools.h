#ifndef __AML_PSDK_VCPOOLS_H
#define __AML_PSDK_VCPOOLS_H

#include <aml-psdk/game_vc/plugin.h>

#ifdef GetObject
    #undef GetObject
#endif

struct CPed;
struct CPlayerPed;
struct CVehicle;
struct CAutomobile;
struct CObject;
struct CCutsceneObject;
struct CBuilding;
struct CDummy;
struct CColModel;
struct cAudioScriptObject;
struct CTreadable;
struct CPtrNode;
struct CEntryInfoNode;

union tPoolObjectFlags
{
    struct
    {
        u8 nId : 7;
        bool bEmpty : 1;
    };
    u8 nValue;
    inline u8 IntValue() const { return nValue; }
};
CHECKSIZE(tPoolObjectFlags, 0x1, 0x1);

// Native pool metadata. Use CPools for allocation and object lookup.
template<class A, class B = A>
struct CPool
{
    inline i32 GetSize() const { return m_nSize; }
    inline bool IsFreeSlotAtIndex(i32 index) const { return m_byteMap[index].bEmpty; }
    inline i32 GetNoOfUsedSpaces() const
    {
        i32 count = 0;
        for(i32 i = 0; i < m_nSize; ++i) if(!m_byteMap[i].bEmpty) ++count;
        return count;
    }
    inline i32 GetNoOfFreeSpaces() const { return m_nSize - GetNoOfUsedSpaces(); }

    B* m_pObjects;
    tPoolObjectFlags* m_byteMap;
    i32 m_nSize;
    i32 m_nFirstFree;
};
CHECKSIZE(CPool<int>, 0x10, 0x18);

typedef CPool<CPed, CPlayerPed> CPedPool;
typedef CPool<CVehicle, CAutomobile> CVehiclePool;
typedef CPool<CObject, CCutsceneObject> CObjectPool;
typedef CPool<CBuilding> CBuildingPool;
typedef CPool<CDummy> CDummyPool;
typedef CPool<CColModel> CColModelPool;
typedef CPool<cAudioScriptObject> CAudioScriptObjectPool;
typedef CPool<CTreadable> CTreadablePool;
typedef CPool<CPtrNode> CPtrNodePool;
typedef CPool<CEntryInfoNode> CEntryInfoNodePool;

DECL_CLASS(CPools)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(Initialise, _ZN6CPools10InitialiseEv, void);
    DECL_FASTCALL_SIMPLE(ShutDown, _ZN6CPools8ShutDownEv, void);
    DECL_FASTCALL_SIMPLE(CheckPoolsEmpty, _ZN6CPools15CheckPoolsEmptyEv, void);
    DECL_FASTCALL_SIMPLE(GetPed, _ZN6CPools6GetPedEi, CPed*, i32 handle);
    DECL_FASTCALL_SIMPLE(GetPedRef, _ZN6CPools9GetPedRefEP4CPed, i32, CPed* ped);
    DECL_FASTCALL_SIMPLE(GetVehicle, _ZN6CPools10GetVehicleEi, CVehicle*, i32 handle);
    DECL_FASTCALL_SIMPLE(GetVehicleRef, _ZN6CPools13GetVehicleRefEP8CVehicle, i32, CVehicle* vehicle);
    DECL_FASTCALL_SIMPLE(GetObject, _ZN6CPools9GetObjectEi, CObject*, i32 handle);
    DECL_FASTCALL_SIMPLE(GetObjectRef, _ZN6CPools12GetObjectRefEP7CObject, i32, CObject* object);
    DECL_FASTCALL_SIMPLE(MakeSureSlotInObjectPoolIsEmpty, _ZN6CPools31MakeSureSlotInObjectPoolIsEmptyEi, void, i32 slot);
    DECL_FASTCALL_SIMPLE(LoadPedPool, _ZN6CPools11LoadPedPoolEPhj, void, u8* buffer, u32 size);
    DECL_FASTCALL_SIMPLE(SavePedPool, _ZN6CPools11SavePedPoolEPhPj, void, u8* buffer, u32* outSize);
    DECL_FASTCALL_SIMPLE(LoadVehiclePool, _ZN6CPools15LoadVehiclePoolEPhj, void, u8* buffer, u32 size);
    DECL_FASTCALL_SIMPLE(SaveVehiclePool, _ZN6CPools15SaveVehiclePoolEPhPj, void, u8* buffer, u32* outSize);
    DECL_FASTCALL_SIMPLE(LoadObjectPool, _ZN6CPools14LoadObjectPoolEPhj, void, u8* buffer, u32 size);
    DECL_FASTCALL_SIMPLE(SaveObjectPool, _ZN6CPools14SaveObjectPoolEPhPj, void, u8* buffer, u32* outSize);

    // STATIC values
    DECL_OBJECT_PLT(CPedPool*, ms_pPedPool, BYBIT(0x394C50, 0x577978));
    DECL_OBJECT_PLT(CVehiclePool*, ms_pVehiclePool, BYBIT(0x394AD0, 0x577688));
    DECL_OBJECT_PLT(CObjectPool*, ms_pObjectPool, BYBIT(0x396000, 0x57A018));
    DECL_OBJECT_PLT(CBuildingPool*, ms_pBuildingPool, BYBIT(0x394440, 0x5769D0));
    DECL_OBJECT_PLT(CDummyPool*, ms_pDummyPool, BYBIT(0x39657C, 0x57AAF0));
    DECL_OBJECT_PLT(CColModelPool*, ms_pColModelPool, BYBIT(0x395F0C, 0x579E48));
    DECL_OBJECT_PLT(CAudioScriptObjectPool*, ms_pAudioScriptObjectPool, BYBIT(0x394A2C, 0x577548));
    DECL_OBJECT_PLT(CTreadablePool*, ms_pTreadablePool, BYBIT(0x394688, 0x576E78));
    DECL_OBJECT_PLT(CPtrNodePool*, ms_pPtrNodePool, BYBIT(0x396DC0, 0x57BB78));
    DECL_OBJECT_PLT(CEntryInfoNodePool*, ms_pEntryInfoNodePool, BYBIT(0x396FA0, 0x57BF38));
DECL_CLASS_END()

#define ms_pPedPool ms_pPedPool()
#define ms_pVehiclePool ms_pVehiclePool()
#define ms_pObjectPool ms_pObjectPool()
#define ms_pBuildingPool ms_pBuildingPool()
#define ms_pDummyPool ms_pDummyPool()
#define ms_pColModelPool ms_pColModelPool()
#define ms_pAudioScriptObjectPool ms_pAudioScriptObjectPool()
#define ms_pTreadablePool ms_pTreadablePool()
#define ms_pPtrNodePool ms_pPtrNodePool()
#define ms_pEntryInfoNodePool ms_pEntryInfoNodePool()

#endif // __AML_PSDK_VCPOOLS_H
