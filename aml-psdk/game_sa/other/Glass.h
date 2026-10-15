#ifndef __AML_PSDK_SAGLASS_H
#define __AML_PSDK_SAGLASS_H

#include "../plugin.h"
#include "../base/Matrix.h"

struct CEntity;
struct CVehicle;
struct CPtrList;

DECL_CLASS(CFallingGlassPane)
    // Member functions
    DECL_THISCALL_SIMPLE(Update, _ZN17CFallingGlassPane6UpdateEv, void);
    DECL_THISCALL_SIMPLE(Render, _ZN17CFallingGlassPane6RenderEv, void);

    // Member values
    CMatrix Matrix;
    CVector MoveSpeed;
    CVector Spin;
    u32 TimeOfActivation;
    float GroundZ;
    float ScaleShatteredTexture;
    u8 TriangleType;
    bool Active;
    bool bShattered;
    bool bWindScreen;
DECL_CLASS_END()
CHECKSIZE(CFallingGlassPane, 0x70, 0x78);

DECL_CLASS(CGlass)
    enum
    {
        ALL_AT_ONCE = 0,
        SLOWLY_FROM_POINT = 1,
        SMASH_CAR_WINDSCREEN = 2,
    };

    // STATIC functions
    DECL_FASTCALL_SIMPLE(Init, _ZN6CGlass4InitEv, void);
    DECL_FASTCALL_SIMPLE(Update, _ZN6CGlass6UpdateEv, void);
    DECL_FASTCALL_SIMPLE(FindFreePane, _ZN6CGlass12FindFreePaneEv, CFallingGlassPane*);
    DECL_FASTCALL_SIMPLE(Render, _ZN6CGlass6RenderEv, void);
    DECL_FASTCALL_SIMPLE(GeneratePanesForWindow, _ZN6CGlass22GeneratePanesForWindowEj7CVectorS0_S0_S0_S0_fbbib, void, u32 TypeOfAccident, CVector BaseCoors, CVector UpVec, CVector SideVec, CVector InitialSpeed, CVector CollisionPoint, float ExplodingForce, bool bShattered, bool bExplosion, i32 NumberMultiplier, bool bArgWindScreen);
    DECL_FASTCALL_SIMPLE(AskForObjectToBeRenderedInGlass, _ZN6CGlass31AskForObjectToBeRenderedInGlassEP7CEntity, void, CEntity* pEntity);
    DECL_FASTCALL_SIMPLE(CalcAlphaWithNormal, _ZN6CGlass19CalcAlphaWithNormalEP7CVector, u8, CVector* pNormal);
    DECL_FASTCALL_SIMPLE(RenderHiLightPolys, _ZN6CGlass18RenderHiLightPolysEv, void);
    DECL_FASTCALL_SIMPLE(RenderShatteredPolys, _ZN6CGlass20RenderShatteredPolysEv, void);
    DECL_FASTCALL_SIMPLE(RenderReflectionPolys, _ZN6CGlass21RenderReflectionPolysEv, void);
    DECL_FASTCALL_SIMPLE(WindowRespondsToCollision, _ZN6CGlass25WindowRespondsToCollisionEP7CEntityf7CVectorS2_b, void, CEntity* pEntity, float ImpulsMagnitude, CVector OtherGuysSpeed, CVector CollisionCoors, bool bExplosion);
    DECL_FASTCALL_SIMPLE(WindowRespondsToSoftCollision, _ZN6CGlass29WindowRespondsToSoftCollisionEP7CEntityf, void, CEntity* pEntity, float ImpulsMagnitude);
    DECL_FASTCALL_SIMPLE(WasGlassHitByBullet, _ZN6CGlass19WasGlassHitByBulletEP7CEntity7CVector, void, CEntity* pEntity, CVector CoorsOfImpact);
    DECL_FASTCALL_SIMPLE(WindowRespondsToExplosion, _ZN6CGlass25WindowRespondsToExplosionEP7CEntity7CVector, void, CEntity* pEntity, CVector CoorsOfExplosion);
    DECL_FASTCALL_SIMPLE(CarWindscreenShatters, _ZN6CGlass21CarWindscreenShattersEP8CVehicleb, void, CVehicle* pVehicle, bool bExplosion);
    DECL_FASTCALL_SIMPLE(HasGlassBeenShatteredAtCoors, _ZN6CGlass28HasGlassBeenShatteredAtCoorsEfff, bool, float CoorsX, float CoorsY, float CoorsZ);
    DECL_FASTCALL_SIMPLE(FindWindowSectorList, _ZN6CGlass20FindWindowSectorListER8CPtrListPfPP7CEntityfff, void, CPtrList& list, float* pClosestDist, CEntity** ppNearestGlassEnt, float CoorsX, float CoorsY, float CoorsZ);
    DECL_FASTCALL_SIMPLE(BreakGlassPhysically, _ZN6CGlass20BreakGlassPhysicallyE7CVectorf, void, CVector Coors, float Radius);

    // STATIC values
    DECL_VALUE_PLT_U32(NumGlassEntities, BYBIT(0x67856C, 0x84EAF0));
    DECL_OBJECT_ARRAY_PLT(CEntity*, apEntitiesToBeRendered, BYBIT(0x678AF4, 0x84F610));
    DECL_OBJECT_ARRAY_PLT(CFallingGlassPane, aGlassPanes, BYBIT(0x6763B4, 0x84A7C0));
DECL_CLASS_END()

#endif // __AML_PSDK_SAGLASS_H
