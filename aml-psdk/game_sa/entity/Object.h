#ifndef __AML_PSDK_SAOBJECT_H
#define __AML_PSDK_SAOBJECT_H

#include "Physical.h"
#include "../engine/ObjectData.h"

struct CFire;
struct RwTexture;
struct CPed;
struct RwFrame;

enum eObjectType : unsigned char
{
    OBJECT_UNKNOWN,
    OBJECT_MISSION = 2,
    OBJECT_TEMPORARY = 3,
    OBJECT_MISSION2 = 6
};

DECL_CLASS_BASED(CObject, CPhysical)
    // Construct/Deconstruct functions
    DECL_CTORCALL(CObject, _ZN7CObjectC2Ev);
    DECL_FASTCALL_SIMPLE(FuncProxy_ctorCObject1, _ZN7CObjectC2Eib, void, CObject* object, i32 modelId, bool bCreate);
    DECL_FASTCALL_SIMPLE(FuncProxy_ctorCObject2, _ZN7CObjectC2EP12CDummyObject, void, CObject* object, CDummyObject* dummyObj);
    CObject(i32 modelId, bool bCreate) { FuncProxy_ctorCObject1(this, modelId, bCreate); }
    CObject(CDummyObject* dummyObj) { FuncProxy_ctorCObject2(this, dummyObj); }
    DECL_DTORCALL(CObject, _ZN7CObjectD2Ev);
    DECL_NEWCALL(CObject, BYBIT(_ZN7CObjectnwEj, _ZN7CObjectnwEm) );
    DECL_DLCALL(CObject, _ZN7CObjectdlEPv);
    DECL_FASTCALL_SIMPLE(InstantiateAt, BYBIT(_ZN7CObjectnwEji, _ZN7CObjectnwEmi), CObject*, size_t size, i32 poolRef);

    // STATIC functions
    DECL_FASTCALL_SIMPLE(Create1, _ZN7CObject6CreateEib, CObject*, i32 modelIndex, bool bCreate);
    DECL_FASTCALL_SIMPLE(Create2, _ZN7CObject6CreateEP12CDummyObject, CObject*, CDummyObject* dummyObject);
    static inline CObject* Create(i32 modelIndex, bool bCreate) { return Create1(modelIndex, bCreate); }
    static inline CObject* Create(CDummyObject* dummyObject) { return Create2(dummyObject); }
    DECL_FASTCALL_SIMPLE(SetMatrixForTrainCrossing, _ZN7CObject25SetMatrixForTrainCrossingEP7CMatrixf, void, CMatrix* matrix, float angle);
    DECL_FASTCALL_SIMPLE(TryToFreeUpTempObjects, _ZN7CObject22TryToFreeUpTempObjectsEi, void, i32 numObjects);
    DECL_FASTCALL_SIMPLE(DeleteAllTempObjects, _ZN7CObject20DeleteAllTempObjectsEv, void);
    DECL_FASTCALL_SIMPLE(DeleteAllTempObjectsInArea, _ZN7CObject26DeleteAllTempObjectsInAreaE7CVectorf, void, CVector point, float radius);
    DECL_FASTCALL_SIMPLE(DeleteAllMissionObjects, _ZN7CObject23DeleteAllMissionObjectsEv, void);

    // STATIC values
    DECL_OBJECT_PLT(u16, nNoTempObjects, BYBIT(0x677F68, 0x84DEF0));
    DECL_OBJECT_SYM(i16, nBodyCastHealth, _ZN7CObject15nBodyCastHealthE);
    DECL_OBJECT_PLT(float, fDistToNearestTree, BYBIT(0x676FC4, 0x84BFC0));
    DECL_OBJECT_PLT(bool, bArea51SamSiteDisabled, BYBIT(0x678368, 0x84E6E8));
    DECL_OBJECT_PLT(bool, bAircraftCarrierSamSiteDisabled, BYBIT(0x679D88, 0x851B28));

    // Member functions
    DECL_THISCALL_SIMPLE(Init, _ZN7CObject4InitEv, void);
    DECL_THISCALL_SIMPLE(CanBeDeleted, _ZN7CObject12CanBeDeletedEv, u8);
    DECL_THISCALL_HEAD(SetRelatedDummy, _ZN7CObject15SetRelatedDummyEP12CDummyObject, void, CDummyObject* relatedDummy)
    DECL_THISCALL_TAIL(SetRelatedDummy, relatedDummy)
    DECL_THISCALL_SIMPLE(ProcessControlLogic, _ZN7CObject19ProcessControlLogicEv, void);
    DECL_THISCALL_SIMPLE(ProcessSamSiteBehaviour, _ZN7CObject23ProcessSamSiteBehaviourEv, void);
    DECL_THISCALL_SIMPLE(ProcessTrainCrossingBehaviour, _ZN7CObject29ProcessTrainCrossingBehaviourEv, void);
    DECL_THISCALL_SIMPLE(ProcessGarageDoorBehaviour, _ZN7CObject26ProcessGarageDoorBehaviourEv, void);
    DECL_THISCALL_HEAD(ObjectDamage, _ZN7CObject12ObjectDamageEfP7CVectorS1_P7CEntity11eWeaponType, void, float damage, CVector* fxOrigin, CVector* fxDirection, CEntity* damager, eWeaponType weaponType)
    DECL_THISCALL_TAIL(ObjectDamage, damage, fxOrigin, fxDirection, damager, weaponType)
    DECL_THISCALL_HEAD(ObjectFireDamage, _ZN7CObject16ObjectFireDamageEfP7CEntity, void, float damage, CEntity* damager)
    DECL_THISCALL_TAIL(ObjectFireDamage, damage, damager)
    DECL_THISCALL_SIMPLE(GetLightingFromCollisionBelow, _ZN7CObject29GetLightingFromCollisionBelowEv, void);
    DECL_THISCALL_SIMPLE(TryToExplode, _ZN7CObject12TryToExplodeEv, u8);
    DECL_THISCALL_SIMPLE(Explode, _ZN7CObject7ExplodeEv, void);
    DECL_THISCALL_HEAD(SetObjectTargettable, _ZN7CObject20SetObjectTargettableEh, void, u8 targetable)
    DECL_THISCALL_TAIL(SetObjectTargettable, targetable)
    DECL_THISCALL_SIMPLE(CanBeTargetted, _ZN7CObject14CanBeTargettedEv, u8);
    DECL_THISCALL_HEAD(RefModelInfo, _ZN7CObject12RefModelInfoEi, void, i32 modelIndex)
    DECL_THISCALL_TAIL(RefModelInfo, modelIndex)
    DECL_THISCALL_HEAD(SetRemapTexture, _ZN7CObject15SetRemapTextureEP9RwTexturePKc, void, RwTexture* remapTexture, char const* txdName)
    DECL_THISCALL_TAIL(SetRemapTexture, remapTexture, txdName)
    DECL_THISCALL_SIMPLE(AddToControlCodeList, _ZN7CObject20AddToControlCodeListEv, void);
    DECL_THISCALL_SIMPLE(RemoveFromControlCodeList, _ZN7CObject25RemoveFromControlCodeListEv, void);
    DECL_THISCALL_SIMPLE(GetRopeHeight, _ZN7CObject13GetRopeHeightEv, float);
    DECL_THISCALL_HEAD(SetRopeHeight, _ZN7CObject13SetRopeHeightEf, void, float height)
    DECL_THISCALL_TAIL(SetRopeHeight, height)
    DECL_THISCALL_SIMPLE(GetObjectCarriedWithRope, _ZN7CObject24GetObjectCarriedWithRopeEv, CPhysical*);
    DECL_THISCALL_SIMPLE(ReleaseObjectCarriedWithRope, _ZN7CObject28ReleaseObjectCarriedWithRopeEv, void);
    DECL_THISCALL_HEAD(GrabObjectToCarryWithRope, _ZN7CObject25GrabObjectToCarryWithRopeEP9CPhysical, void, CPhysical* attachTo)
    DECL_THISCALL_TAIL(GrabObjectToCarryWithRope, attachTo)
    DECL_THISCALL_SIMPLE(CanBeUsedToTakeCoverBehind, _ZN7CObject26CanBeUsedToTakeCoverBehindEv, bool);
    DECL_THISCALL_SIMPLE(ResetDoorAngle, _ZN7CObject14ResetDoorAngleEv, void);
    DECL_THISCALL_SIMPLE(LockDoor, _ZN7CObject8LockDoorEv, void);
    DECL_THISCALL_SIMPLE(DoBurnEffect, _ZN7CObject12DoBurnEffectEv, void);
    DECL_THISCALL_SIMPLE(Save, _ZN7CObject4SaveEv, bool);
    DECL_THISCALL_SIMPLE(Load, _ZN7CObject4LoadEv, bool);

    // Member values
    CPtrNodeDoubleLink *m_pControlCodeList;
    unsigned char   m_nObjectType; // see enum eObjectType
    unsigned char   m_nBonusValue;
    unsigned short  m_wCostValue;
    struct
    {
        unsigned int bIsPickup : 1;
        unsigned int bNoPickupEffects : 1;
        unsigned int bPickupPropertyForSale : 1;
        unsigned int bPickupInShopOutOfStock : 1;
        unsigned int bGlassBroken : 1;
        unsigned int bGlassBrokenAltogether : 1;
        unsigned int bIsExploded : 1;
        unsigned int bParentIsACar : 1;

        unsigned int bIsLampPost : 1;
        unsigned int bIsTargatable : 1;
        unsigned int bIsBroken : 1;
        unsigned int bTrainCrossEnabled : 1;
        unsigned int bIsPhotographed : 1;
        unsigned int bIsLiftable : 1;
        unsigned int bIsDoorMoving : 1;
        unsigned int bbIsDoorOpen : 1;

        unsigned int bHasNoModel : 1;
        unsigned int bIsScaled : 1;
        unsigned int bCanBeAttachedToMagnet : 1;
        unsigned int bLandedOnMovingCol : 1;
        unsigned int ScriptBrainStatus : 2;
        unsigned int bFadingIn : 1; // works only for objects with type 2 (OBJECT_MISSION)
        unsigned int bAffectedByColBrightness : 1;

        unsigned int bEnableDisabledAttractors : 1;
        unsigned int bDoNotRender : 1;
        unsigned int bFadingIn2 : 1; // not exists?
        unsigned int b28 : 1;
        unsigned int b29 : 1;
        unsigned int b30 : 1;
        unsigned int b31 : 1;
        unsigned int b32 : 1;
    } m_nObjectFlags;
    
    unsigned char   m_nColDamageEffect;
    unsigned char   m_nStoredColDamageEffect;
    unsigned char KeepieUppyCounter;
    signed char     m_nGarageDoorGarageIndex;
    signed char     m_nLastWeaponDamage;
    unsigned char   m_nDayBrightness : 4;
    unsigned char   m_nNightBrightness : 4;
    short           m_nRefModelIndex;
    unsigned char   m_nCarColor[4]; // this is used for detached car parts
    unsigned int    m_dwRemovalTime; // time when this object must be deleted
    float           m_fHealth;
    float           m_fDoorStartAngle; // this is used for door objects
    float           m_fScale;
    B64MACRO(__attribute__((packed)) __attribute__((aligned(1)))) CObjectInfo    *m_pObjectInfo;
    B64MACRO(__attribute__((packed)) __attribute__((aligned(1)))) CFire     *m_pFire; // CFire *
    short           m_wScriptTriggerIndex;
    const char* m_szRemapTxdName; // this is different from PC. there was "m_wRemapTxd"
    RwTexture      *m_pRemapTexture; // this is used for detached car parts
    CDummyObject   *m_pDummyObject; // used for dynamic objects like garage doors, train crossings etc.
    int             m_dwBurnTime; // time when particles must be stopped
    float           m_fBurnDamage;
DECL_CLASS_END()
CHECKSIZE(CObject, 0x184, 0x1F8);

DECL_CLASS_BASED(CHandObject, CObject)
    // Construct/Deconstruct functions
    CHandObject(){}
    DECL_CTORCALL_ARG_HEAD(CHandObject, _ZN11CHandObjectC2EiP4CPedb, i32 modelId, CPed* pPed, bool bLeft)
    DECL_CTORCALL_ARG_TAIL(modelId, pPed, bLeft)

    CPed       *m_pPed;
    int m_nBoneIndex;
    RwTexture   *m_pTexture;
    unsigned char m_bUpdatedMatricesArray;
DECL_CLASS_END()

DECL_CLASS_BASED(CCutsceneObject, CObject)
    // Construct/Deconstruct functions
    DECL_CTORCALL(CCutsceneObject, _ZN15CCutsceneObjectC2Ev);
    DECL_DTORCALL(CCutsceneObject, _ZN15CCutsceneObjectD2Ev);

    union
    {
        RwFrame *m_pAttachTo;
        int m_nAttachBone; // this one if m_pAttachmentObject != 0
    };
    CCutsceneObject *m_pAttachmentObject;
    CVector m_vWorldPosition;
    CVector m_vForce;
DECL_CLASS_END()

DECL_FASTCALL_SIMPLE_GLO(IsObjectPointerValid, _Z20IsObjectPointerValidP7CObject, bool, CObject* pObject);
DECL_FASTCALL_SIMPLE_GLO(IsObjectPointerValid_NotInWorld, _Z31IsObjectPointerValid_NotInWorldP7CObject, bool, CObject* pObject);

#endif // __AML_PSDK_SAOBJECT_H
