#ifndef __AML_PSDK_VCDOOR_H
#define __AML_PSDK_VCDOOR_H

#include <aml-psdk/game_vc/plugin.h>
#include <aml-psdk/gta_base/Vector.h>

struct CVehicle;

DECL_CLASS(CDoor)
    // Construct/Deconstruct functions
    CDoor() : fAngleInPosOne(0.0f), fAngleInPosTwo(0.0f), nAxisDirection(0), nAxis(0), nState(0), fAngle(0.0f), fPrevAngle(0.0f), fVelAngle(0.0f), vecVelocity(0.0f, 0.0f, 0.0f) {}

    // Member functions
    DECL_THISCALL_HEAD(Open, _ZN5CDoor4OpenEf, void, float ratio)
    DECL_THISCALL_TAIL(Open, ratio)
    DECL_THISCALL_HEAD(Process, _ZN5CDoor7ProcessEP8CVehicle, void, CVehicle* vehicle)
    DECL_THISCALL_TAIL(Process, vehicle)
    DECL_THISCALL_SIMPLE(RetAngleWhenClosed, _ZN5CDoor18RetAngleWhenClosedEv, float);
    DECL_THISCALL_SIMPLE(RetAngleWhenOpen, _ZN5CDoor16RetAngleWhenOpenEv, float);
    DECL_THISCALL_SIMPLE(GetAngleOpenRatio, _ZN5CDoor17GetAngleOpenRatioEv, float);
    DECL_THISCALL_SIMPLE(IsFullyOpen, _ZN5CDoor11IsFullyOpenEv, bool);
    DECL_THISCALL_SIMPLE(IsClosed, _ZN5CDoor8IsClosedEv, bool);
    DECL_THISCALL_SIMPLE(IsInUse, _ZN5CDoor7IsInUseEv, bool);

    // Member values
    float fAngleInPosOne;
    float fAngleInPosTwo;
    u8 nAxisDirection;
    u8 nAxis;
    u8 nState;
    float fAngle;
    float fPrevAngle;
    float fVelAngle;
    CVector vecVelocity;
DECL_CLASS_END()
CHECKSIZE(CDoor, 0x24, 0x24);

#endif // __AML_PSDK_VCDOOR_H
