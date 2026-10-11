#ifndef __AML_PSDK_SACHECKPOINTS_H
#define __AML_PSDK_SACHECKPOINTS_H

/*
    Plugin-SDK (Grand Theft Auto San Andreas) header file
    Authors: GTA Community. See more here
    https://github.com/DK22Pac/plugin-sdk
    Do not delete this comment block. Respect others' work!
*/

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/gta_base/Vector.h>
#include <aml-psdk/gta_base/RGBA.h>

DECL_CLASS(CCheckpoint)
    // Member functions
    DECL_THISCALL_SIMPLE(Render, _ZN11CCheckpoint6RenderEv, void);

    // Member values
    u16 m_nType;
    bool m_bIsUsed;
    bool m_bMustBeRenderedThisFrame;
    u32 m_nIdentifier;
    CRGBA m_colour;
    u16 m_nPulsePeriod;
    i16 m_nRotateRate;
    CVector m_vecPosition;
    CVector m_vecDirection;
    float m_fPulseFraction;
    float m_fSize;
    float m_fDistanceToPlayer;
    float m_multiSize;
DECL_CLASS_END()
CHECKSIZE(CCheckpoint, 0x38, 0x38);

DECL_CLASS(CCheckpoints)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(Init, _ZN12CCheckpoints4InitEv, void);
    DECL_FASTCALL_SIMPLE(Update, _ZN12CCheckpoints6UpdateEv, void);
    DECL_FASTCALL_SIMPLE(Render, _ZN12CCheckpoints6RenderEv, void);
    DECL_FASTCALL_SIMPLE(Shutdown, _ZN12CCheckpoints8ShutdownEv, void);
    DECL_FASTCALL_SIMPLE(UpdatePos, _ZN12CCheckpoints9UpdatePosEjR7CVector, void, u32 id, CVector& posn);
    DECL_FASTCALL_SIMPLE(SetHeading, _ZN12CCheckpoints10SetHeadingEjf, void, u32 id, float angle);
    DECL_FASTCALL_SIMPLE(PlaceMarker, _ZN12CCheckpoints11PlaceMarkerEjtR7CVectorS1_fhhhhtfs, CCheckpoint*,
        u32 id, u16 type, CVector& posn, CVector& direction, float size, u8 red, u8 green, u8 blue, u8 alpha, u16 pulsePeriod, float pulseFraction, i16 rotateRate);
    DECL_FASTCALL_SIMPLE(DeleteCP, _ZN12CCheckpoints8DeleteCPEjt, void, u32 id, u16 type);

    // STATIC values
    DECL_OBJECT_ARRAY_PLT(CCheckpoint, m_aCheckPtArray, BYBIT(0x67764C, 0x84CCC8));
    DECL_VALUE_PLT_I32(NumActiveCPts, BYBIT(0x679D08, 0x851A28));
DECL_CLASS_END()

#define m_aCheckPtArray m_aCheckPtArray()
#define NumActiveCPts NumActiveCPts()

#endif // __AML_PSDK_SACHECKPOINTS_H
