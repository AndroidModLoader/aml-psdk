#ifndef __AML_PSDK_SABIRDS_H
#define __AML_PSDK_SABIRDS_H

/*
    Plugin-SDK (Grand Theft Auto San Andreas) header file
    Authors: GTA Community. See more here
    https://github.com/DK22Pac/plugin-sdk
    Do not delete this comment block. Respect others' work!
*/

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/gta_base/Vector.h>

struct CBird
{
    CVector m_vecPosn;
    CVector m_vecCurrentVelocity;
    CVector m_vecVelocity;
    float m_fAngle;
    u32 m_nStartMovementTime;
    u32 m_nWingSpeed;
    float m_fSize;
    float m_fMaxBirdDistance;
    u8 m_nActivity;
    u8 m_anPolyColors[6];
    bool m_bCreated;
    bool m_bMustDoCurves;
};
CHECKSIZE(CBird, 0x44, 0x44);

DECL_CLASS(CBirds)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(Init, _ZN6CBirds4InitEv, void);
    DECL_FASTCALL_SIMPLE(Update, _ZN6CBirds6UpdateEv, void);
    DECL_FASTCALL_SIMPLE(CreateNumberOfBirds, _ZN6CBirds19CreateNumberOfBirdsE7CVectorS0_iib, void,
        CVector vecStartPos, CVector vecTargetPos, i32 iBirdCount, i32 biome, bool bCheckObstacles);
    DECL_FASTCALL_SIMPLE(Render, _ZN6CBirds6RenderEv, void);
    DECL_FASTCALL_SIMPLE(Shutdown, _ZN6CBirds8ShutdownEv, void);
    DECL_FASTCALL_SIMPLE(HandleGunShot, _ZN6CBirds13HandleGunShotEPK7CVectorS2_, void, CVector const* pointA, CVector const* pointB);

    // STATIC values
    DECL_OBJECT_ARRAY_PLT(CBird, aBirds, BYBIT(0x6793CC, 0x8507B0));
    DECL_VALUE_PLT_I32(NumberOfBirds, BYBIT(0x676EA0, 0x84BD80));
    DECL_VALUE_PLT_BOOL(bHasBirdBeenShot, BYBIT(0x676C58, 0x84B8F8));
    DECL_OBJECT_PLT(CVector, BirdShotAt, BYBIT(0x679580, 0x850B10));
DECL_CLASS_END()

#define aBirds aBirds()
#define NumberOfBirds NumberOfBirds()
#define bHasBirdBeenShot bHasBirdBeenShot()
#define BirdShotAt BirdShotAt()

#endif // __AML_PSDK_SABIRDS_H
