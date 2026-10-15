#ifndef __AML_PSDK_SAROPES_H
#define __AML_PSDK_SAROPES_H

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/gta_base/Vector.h>

struct CPhysical;
struct CEntity;
struct CObject;

DECL_CLASS(CRope)
    // Member functions
    DECL_THISCALL_SIMPLE(DoControlsApply, _ZN5CRope15DoControlsApplyEv, bool);
    DECL_THISCALL_SIMPLE(Update, _ZN5CRope6UpdateEv, void);
    DECL_THISCALL_SIMPLE(Render, _ZN5CRope6RenderEv, void);
    DECL_THISCALL_SIMPLE(Remove, _ZN5CRope6RemoveEv, void);
    DECL_THISCALL_HEAD(UpdateWeightInRope, _ZN5CRope18UpdateWeightInRopeE7CVectorfPS0_, bool, CVector WeightCoors, float RelativeWeight, CVector* pNewWeightCoors)
    DECL_THISCALL_TAIL(UpdateWeightInRope, WeightCoors, RelativeWeight, pNewWeightCoors)
    DECL_THISCALL_SIMPLE(CreateHookObjectForRope, _ZN5CRope23CreateHookObjectForRopeEv, void);
    DECL_THISCALL_SIMPLE(ReleasePickedUpObject, _ZN5CRope21ReleasePickedUpObjectEv, void);
    DECL_THISCALL_HEAD(PickUpObject, _ZN5CRope12PickUpObjectEP7CEntity, void, CEntity* pToBePickedUp)
    DECL_THISCALL_TAIL(PickUpObject, pToBePickedUp)

    // Member values
    CVector aCoors[32];
    CVector aSpeeds[32];
    uptr ID;
    float GroundHeight;
    float m_RopeLength;
    float m_SegmentLength;
    CPhysical* pConnectedTo;
    CObject* m_pWinchHookObject;
    CPhysical* m_pWinchCarriedObject;
    float m_fWinchHeight;
    u32 TimeToBeKeptAliveTill;
    u8 FixedAtNode;
    u8 RopeType;
    u8 m_WinchDisabled;
    u8 bUpdatedThisFrame : 1;
    u8 bWeightInRope : 1;
    u8 bSitOnGround : 1;
DECL_CLASS_END()
CHECKSIZE(CRope, 0x328, 0x340);

DECL_CLASS(CRopes)
    // Member functions
    DECL_FASTCALL_SIMPLE(Init, _ZN6CRopes4InitEv, void);
    DECL_FASTCALL_SIMPLE(Update, _ZN6CRopes6UpdateEv, void);
    DECL_FASTCALL_SIMPLE(Render, _ZN6CRopes6RenderEv, void);
    DECL_FASTCALL_SIMPLE(Shutdown, _ZN6CRopes8ShutdownEv, void);
    DECL_FASTCALL_SIMPLE(RegisterRope, BYBIT(_ZN6CRopes12RegisterRopeEjj7CVectorbhbP9CPhysicali, _ZN6CRopes12RegisterRopeEyj7CVectorbhbP9CPhysicali), i32, uptr ID, u32 ArgRopeType, CVector Coors, bool bKeepAliveForAWhile, u8 ArgFixedAtNode, bool bArgSitOnGround, CPhysical* pArgConnectedTo, i32 LifeTime);
    DECL_FASTCALL_SIMPLE(SetSpeedOfTopNode, _ZN6CRopes17SetSpeedOfTopNodeEj7CVector, void, u32 ID, CVector Speed);
    DECL_FASTCALL_SIMPLE(FindCoorsAlongRope, _ZN6CRopes18FindCoorsAlongRopeEjfP7CVectorS1_, bool, u32 ID, float DistAlongRope, CVector* pResult, CVector* pResultSpeed);
    DECL_FASTCALL_SIMPLE(IsCarriedByRope, _ZN6CRopes15IsCarriedByRopeEP9CPhysical, bool, CPhysical* pPhysical);
    DECL_FASTCALL_SIMPLE(FindRope, BYBIT(_ZN6CRopes8FindRopeEj, _ZN6CRopes8FindRopeEy), i32, uptr ID);
    DECL_FASTCALL_SIMPLE(FindPickUpHeight, _ZN6CRopes16FindPickUpHeightEP7CEntity, float, CEntity* pCarried);
    DECL_FASTCALL_SIMPLE(CreateRopeForSwatPed, _ZN6CRopes20CreateRopeForSwatPedERK7CVector, int, CVector const& Coors);

    // STATIC values
    DECL_OBJECT_ARRAY_PLT(CRope, aRopes, BYBIT(0x6768C0, 0x84B1D8));
    DECL_VALUE_PLT_I32(PlayerControlsCrane, BYBIT(0x6782E8, 0x84E5E8));

DECL_CLASS_END()
CHECKSIZE(CRopes, 0x1, 0x1);

#endif // __AML_PSDK_SAROPES_H
