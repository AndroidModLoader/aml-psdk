#ifndef __AML_PSDK_SASETPIECES_H
#define __AML_PSDK_SASETPIECES_H

/*
    Plugin-SDK (Grand Theft Auto San Andreas) header file
    Authors: GTA Community. See more here
    https://github.com/DK22Pac/plugin-sdk
    Do not delete this comment block. Respect others' work!
*/

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/gta_base/Vector.h>

struct CCopPed;
struct CAutomobile;

enum eSetPieceType
{
    SETPIECE_2CARS_SLOW_SPEED = 1,
    SETPIECE_1CAR_QUICK_SPEED = 2,
    SETPIECE_1CAR_MEDIUM_SPEED = 3,
    SETPIECE_1PED = 4,
    SETPIECE_2PEDS = 5,
    SETPIECE_2CARS_QUICK_SPEED_BEFORE_HIT = 6,
    SETPIECE_2CARS_QUICK_SPEED = 7,
    SETPIECE_2CARS_MEDIUM_SPEED = 8
};

DECL_CLASS(CSetPiece)
    // Member functions
    DECL_THISCALL_HEAD(TryToGenerateCopPed, _ZN9CSetPiece19TryToGenerateCopPedE9CVector2D, CCopPed*, CVector2D posn)
    DECL_THISCALL_TAIL(TryToGenerateCopPed, posn)
    DECL_THISCALL_HEAD(TryToGenerateCopCar, _ZN9CSetPiece19TryToGenerateCopCarE9CVector2DS0_, CAutomobile*, CVector2D posn, CVector2D target)
    DECL_THISCALL_TAIL(TryToGenerateCopCar, posn, target)
    DECL_THISCALL_SIMPLE(Update, _ZN9CSetPiece6UpdateEv, void);

    // Member values
    u32 m_nLastGenerationTime;
    i16 m_nAreaCornerX1;
    i16 m_nAreaCornerY1;
    i16 m_nAreaCornerX2;
    i16 m_nAreaCornerY2;
    i16 m_nSpawnCoord1X;
    i16 m_nSpawnCoord1Y;
    i16 m_nSpawnCoord2X;
    i16 m_nSpawnCoord2Y;
    i16 m_nTargetCoord1X;
    i16 m_nTargetCoord1Y;
    i16 m_nTargetCoord2X;
    i16 m_nTargetCoord2Y;
    u8 m_nType;
DECL_CLASS_END()
CHECKSIZE(CSetPiece, 0x20, 0x20);

DECL_CLASS(CSetPieces)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(Init, _ZN10CSetPieces4InitEv, void);
    DECL_FASTCALL_SIMPLE(AddOne, _ZN10CSetPieces6AddOneEh9CVector2DS0_S0_S0_S0_S0_, void,
        u8 type, CVector2D cornerA, CVector2D cornerB, CVector2D spawnCoord1, CVector2D targetCoord1, CVector2D spawnCoord2, CVector2D targetCoord2);
    DECL_FASTCALL_SIMPLE(Update, _ZN10CSetPieces6UpdateEv, void);
    DECL_FASTCALL_SIMPLE(Save, _ZN10CSetPieces4SaveEv, bool);
    DECL_FASTCALL_SIMPLE(Load, _ZN10CSetPieces4LoadEv, bool);

    // STATIC values
    DECL_VALUE_PLT_I32(NumSetPieces, BYBIT(0x6767A0, 0x84AF98));
    DECL_VALUE_PLT_BOOL(bDebug, BYBIT(0x676150, 0x84A300));
    DECL_OBJECT_ARRAY_PLT(CSetPiece, aSetPieces, BYBIT(0x677058, 0x84C0E8));
DECL_CLASS_END()

#define NumSetPieces NumSetPieces()
#define bDebug bDebug()
#define aSetPieces aSetPieces()

#endif // __AML_PSDK_SASETPIECES_H
