#ifndef __AML_PSDK_VCENTITY_H
#define __AML_PSDK_VCENTITY_H

#include "Placeable.h"
#include <aml-psdk/gta_base/Rect.h>

struct RwObject;
struct RpAtomic;
struct RpClump;
struct CEntity;

struct CReference
{
    CReference* m_pNext;
    CEntity** m_ppEntity;
};
CHECKSIZE(CReference, 0x8, 0x10);

enum eEntityType : u8
{
    ENTITY_TYPE_NOTHING = 0,
    ENTITY_TYPE_BUILDING = 1,
    ENTITY_TYPE_VEHICLE = 2,
    ENTITY_TYPE_PED = 3,
    ENTITY_TYPE_OBJECT = 4,
    ENTITY_TYPE_DUMMY = 5
};

DECL_CLASS_BASED(CEntity, CPlaceable)
    // Construct/Deconstruct functions
    DECL_CTORCALL(CEntity, _ZN7CEntityC2Ev);
    CEntity(CEntity const&) = delete;
    CEntity& operator=(CEntity const&) = delete;

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(CEntity, Add, _ZTV7CEntity, 0, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CEntity, Remove, _ZTV7CEntity, 1, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_DTORCALL_VIRTUAL_SLOT(CEntity, _ZN7CEntityD2Ev, _ZN7CEntity, _ZTV7CEntity, 2);
    DECL_VIRTUALCALL_HEAD(CEntity, SetModelIndex, _ZTV7CEntity, 4, void, u32 modelIndex)
    DECL_VIRTUALCALL_TAIL(modelIndex)
    DECL_VIRTUALCALL_HEAD(CEntity, SetModelIndexNoCreate, _ZTV7CEntity, 5, void, u32 modelIndex)
    DECL_VIRTUALCALL_TAIL(modelIndex)
    DECL_VIRTUALCALL_HEAD(CEntity, CreateRwObject, _ZTV7CEntity, 6, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CEntity, DeleteRwObject, _ZTV7CEntity, 7, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CEntity, GetBoundRect, _ZTV7CEntity, 8, CRect)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CEntity, ProcessControl, _ZTV7CEntity, 9, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CEntity, ProcessCollision, _ZTV7CEntity, 10, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CEntity, ProcessShift, _ZTV7CEntity, 11, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CEntity, Teleport, _ZTV7CEntity, 12, void, CVector destination)
    DECL_VIRTUALCALL_TAIL(destination)
    DECL_VIRTUALCALL_HEAD(CEntity, PreRender, _ZTV7CEntity, 13, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CEntity, Render, _ZTV7CEntity, 14, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CEntity, SetupLighting, _ZTV7CEntity, 15, bool)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CEntity, RemoveLighting, _ZTV7CEntity, 16, void, bool resetWorldColors)
    DECL_VIRTUALCALL_TAIL(resetWorldColors)
    DECL_VIRTUALCALL_HEAD(CEntity, FlagToDestroyWhenNextProcessed, _ZTV7CEntity, 17, void)
    DECL_VIRTUALCALL_TAIL()

    // Member functions
    DECL_THISCALL_SIMPLE(HasPreRenderEffects, _ZN7CEntity19HasPreRenderEffectsEv, bool);
    DECL_THISCALL_HEAD(AttachToRwObject, _ZN7CEntity16AttachToRwObjectEP8RwObject, void, RwObject* object)
    DECL_THISCALL_TAIL(AttachToRwObject, object)
    DECL_THISCALL_SIMPLE(DetachFromRwObject, _ZN7CEntity18DetachFromRwObjectEv, void);
    DECL_THISCALL_SIMPLE(GetBoundCentre, _ZN7CEntity14GetBoundCentreEv, CVector);
    DECL_THISCALL_NAMED_HEAD(GetBoundCentre1, GetBoundCentre, _ZN7CEntity14GetBoundCentreER7CVector, void, CVector& out)
    DECL_THISCALL_TAIL(GetBoundCentre1, out)
    DECL_THISCALL_SIMPLE(UpdateRwFrame, _ZN7CEntity13UpdateRwFrameEv, void);
    DECL_THISCALL_SIMPLE(UpdateRpHAnim, _ZN7CEntity13UpdateRpHAnimEv, void);
    DECL_THISCALL_SIMPLE(GetIsOnScreen, _ZN7CEntity13GetIsOnScreenEv, bool);
    DECL_THISCALL_SIMPLE(GetIsOnScreenComplex, _ZN7CEntity20GetIsOnScreenComplexEv, bool);
    DECL_THISCALL_SIMPLE(IsVisible, _ZN7CEntity9IsVisibleEv, bool);
    DECL_THISCALL_SIMPLE(IsVisibleComplex, _ZN7CEntity16IsVisibleComplexEv, bool);
    DECL_THISCALL_HEAD(GetIsTouching, _ZN7CEntity13GetIsTouchingEPS_, bool, CEntity* entity)
    DECL_THISCALL_TAIL(GetIsTouching, entity)
    DECL_THISCALL_NAMED_HEAD(GetIsTouching1, GetIsTouching, _ZN7CEntity13GetIsTouchingERK7CVectorf, bool, CVector const& position, float radius)
    DECL_THISCALL_TAIL(GetIsTouching1, position, radius)
    DECL_THISCALL_SIMPLE(ModifyMatrixForTreeInWind, _ZN7CEntity25ModifyMatrixForTreeInWindEv, void);
    DECL_THISCALL_SIMPLE(ModifyMatrixForBannerInWind, _ZN7CEntity27ModifyMatrixForBannerInWindEv, void);
    DECL_THISCALL_SIMPLE(PreRenderForGlassWindow, _ZN7CEntity23PreRenderForGlassWindowEv, void);
    DECL_THISCALL_SIMPLE(SetupBigBuilding, _ZN7CEntity16SetupBigBuildingEv, void);
    DECL_THISCALL_HEAD(SetRwObjectAlpha, _ZN7CEntity16SetRwObjectAlphaEi, void, i32 alpha)
    DECL_THISCALL_TAIL(SetRwObjectAlpha, alpha)
    DECL_THISCALL_SIMPLE(GetDistanceFromCentreOfMassToBaseOfModel, _ZN7CEntity40GetDistanceFromCentreOfMassToBaseOfModelEv, float);
    DECL_THISCALL_HEAD(RegisterReference, _ZN7CEntity17RegisterReferenceEPPS_, void, CEntity** entity)
    DECL_THISCALL_TAIL(RegisterReference, entity)
    DECL_THISCALL_HEAD(CleanUpOldReference, _ZN7CEntity19CleanUpOldReferenceEPPS_, void, CEntity** entity)
    DECL_THISCALL_TAIL(CleanUpOldReference, entity)
    DECL_THISCALL_SIMPLE(ResolveReferences, _ZN7CEntity17ResolveReferencesEv, void);
    DECL_THISCALL_SIMPLE(PruneReferences, _ZN7CEntity15PruneReferencesEv, void);
    DECL_THISCALL_SIMPLE(ProcessLightsForEntity, _ZN7CEntity22ProcessLightsForEntityEv, void);
    DECL_THISCALL_SIMPLE(IsEntityOccluded, _ZN7CEntity16IsEntityOccludedEv, bool);
    DECL_THISCALL_HEAD(AddSteamsFromGround, _ZN7CEntity19AddSteamsFromGroundEP7CVector, void, CVector* position)
    DECL_THISCALL_TAIL(AddSteamsFromGround, position)

    // Helper functions
    inline eEntityType GetType() const { return static_cast<eEntityType>(m_nType); }
    inline void SetType(eEntityType type) { m_nType = type; }
    inline CVector TransformFromObjectSpace(CVector const& offset) const { return TransformPoint(offset); }

    // Member values
    union
    {
        RwObject* m_pRwObject;
        RpAtomic* m_pRwAtomic;
        RpClump* m_pRwClump;
    };
    bool bDontCull;
    u8 m_nAdditionalShading;
    u32 : 0;

    u32 m_nType : 3;
    u32 m_nState : 5;
    u32 bUsesCollision : 1;
    u32 bEntUFlag02 : 1;
    u32 bIsStatic : 1;
    u32 bEntUFlag04 : 1;
    u32 bEntUFlag05 : 1;
    u32 bEntUFlag06 : 1;
    u32 bEntUFlag07 : 1;
    u32 bRecordCollisions : 1;
    u32 bEntUFlag09 : 1;
    u32 bExplosionProof : 1;
    u32 bIsVisible : 1;
    u32 bHasCollided : 1;
    u32 bRenderScorched : 1;
    u32 bHasBlip : 1;
    u32 bUseLevelSectors : 1;
    u32 bIsBigBuilding : 1;
    u32 bEntUFlag17 : 1;
    u32 bBulletProof : 1;
    u32 bFireProof : 1;
    u32 bCollisionProof : 1;
    u32 bMeleeProof : 1;
    u32 bImmuneToNonPlayerDamage : 1;
    u32 bEntUFlag23 : 1;
    u32 bRemoveFromWorld : 1;
    u32 bEntUFlag25 : 1;
    u32 bImBeingRendered : 1;
    u32 bIsTouchingWater : 1;
    u32 bEntUFlag28 : 1;
    u32 bEntUFlag29 : 1;
    u32 bEntUFlag30 : 1;
    u32 bEntUFlag31 : 1;
    u32 bEntUFlag32 : 1;
    u32 bEntUFlag33 : 1;
    u32 bDontCastShadowsOn : 1;
    u32 bEntUFlag35 : 1;
    u32 bIsStaticWaitingForCollision : 1;
    u32 bEntUFlag37 : 1;
    u32 bEntUFlag38 : 1;
    u32 bHasPreRenderEffects : 1;
    u32 : 17;

    u16 m_nScanCode;
    u16 m_nRandomSeed;
    i16 m_nModelIndex;
    i8 m_nLevel;
    u8 m_nAreaCode;
    CReference* m_pFirstRef;
DECL_CLASS_END()
CHECKSIZE(CEntity, 0x68, 0x80);

#endif // __AML_PSDK_VCENTITY_H
