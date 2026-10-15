#ifndef __AML_PSDK_SAESCALATORS_H
#define __AML_PSDK_SAESCALATORS_H

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/game_sa/base/Matrix.h>

struct CEntity;
struct CObject;

DECL_CLASS(CEscalatorAttr)
    // Member values
    float Coors1X;
    float Coors1Y;
    float Coors1Z;
    float Coors2X;
    float Coors2Y;
    float Coors2Z;
    float Coors3X;
    float Coors3Y;
    float Coors3Z;
    bool bGoingUp;
DECL_CLASS_END()
CHECKSIZE(CEscalatorAttr, 0x28, 0x28);

DECL_CLASS(CEscalator)
    // Member functions
    DECL_THISCALL_HEAD(AddThisOne, _ZN10CEscalator10AddThisOneERK7CVectorS2_S2_S2_bP7CEntity, void, CVector const& ArgPoint1, CVector const& ArgPoint2, CVector const& ArgPoint3, CVector const& ArgPoint4, bool ArgGoingDown, CEntity* pOwner)
    DECL_THISCALL_TAIL(AddThisOne, ArgPoint1, ArgPoint2, ArgPoint3, ArgPoint4, ArgGoingDown, pOwner)
    DECL_THISCALL_SIMPLE(Update, _ZN10CEscalator6UpdateEv, void);
    DECL_THISCALL_SIMPLE(SwitchOff, _ZN10CEscalator9SwitchOffEv, void);

    // Member values
    CVector Point1;
    CVector Point2;
    CVector Point3;
    CVector Point4;
    CMatrix StepMatrix;
    bool bUsed;
    bool bActive;
    bool bGoingDown;
    i32 NumNormalStepsNeeded;
    i32 NumBiggerStepsNeeded1;
    i32 NumBiggerStepsNeeded2;
    float FractionPoint2;
    float FractionPoint3;
    CVector SpriteCenter;
    float SpriteSize;
    float StepShift;
    CEntity* pOwnerEntity;
    CObject* pSteps[42];
DECL_CLASS_END()
CHECKSIZE(CEscalator, 0x150, 0x208);

DECL_CLASS(CEscalators)
    // Member functions
    DECL_FASTCALL_SIMPLE(Init, _ZN11CEscalators4InitEv, void);
    DECL_FASTCALL_SIMPLE(Update, _ZN11CEscalators6UpdateEv, void);
    DECL_FASTCALL_SIMPLE(Shutdown, _ZN11CEscalators8ShutdownEv, void);
    DECL_FASTCALL_SIMPLE(AddOne, _ZN11CEscalators6AddOneERK7CVectorS2_S2_S2_bP7CEntity, void, CVector const& Point1, CVector const& Point2, CVector const& Point3, CVector const& Point4, bool ArgGoingDown, CEntity* pOwner);

    // STATIC values
    DECL_OBJECT_ARRAY_PLT(CEscalator, aArray, BYBIT(0x67733C, 0x84C6B0));

DECL_CLASS_END()
CHECKSIZE(CEscalators, 0x1, 0x1);

#endif // __AML_PSDK_SAESCALATORS_H
