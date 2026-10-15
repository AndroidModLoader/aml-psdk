#ifndef __AML_PSDK_SACUSTOMROADSIGN_H
#define __AML_PSDK_SACUSTOMROADSIGN_H

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/renderware/RpClump.h>
#include <aml-psdk/renderware/RwTexture.h>
#include <aml-psdk/gta_base/Vector.h>

DECL_CLASS(CCustomRoadsignMgr)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(Initialise, _ZN18CCustomRoadsignMgr10InitialiseEv, u8);
    DECL_FASTCALL_SIMPLE(Shutdown, _ZN18CCustomRoadsignMgr8ShutdownEv, void);
    DECL_FASTCALL_SIMPLE(CreateRoadsignAtomic, _ZN18CCustomRoadsignMgr20CreateRoadsignAtomicEffiPcS0_S0_S0_ih, RpAtomic*, float rsWidth, float rsHeight, i32 nNumLines, char* text1, char* text2, char* text3, char* text4, i32 nNumLettersInLine, u8 nPalID);
    DECL_FASTCALL_SIMPLE(RenderRoadsignAtomic, _ZN18CCustomRoadsignMgr20RenderRoadsignAtomicEP8RpAtomicRK7CVector, RpAtomic*, RpAtomic* pAtomic, CVector const& camPos);
    DECL_FASTCALL_SIMPLE(CreateRoadsignTexture, _ZN18CCustomRoadsignMgr21CreateRoadsignTextureEPci, RwTexture*, char* PlateText, i32 numLettersInLine);
    DECL_FASTCALL_SIMPLE(CreateRoadsignAtomicA, _ZN18CCustomRoadsignMgr21CreateRoadsignAtomicAEffiPcS0_S0_S0_ih, RpAtomic*, float fRsWidth, float fRsHeight, i32 nNumLines, char* RoadsignText1, char* RoadsignText2, char* RoadsignText3, char* RoadsignText4, i32 nNumLettersInLine, u8 nPalID);
    DECL_FASTCALL_SIMPLE(SetupRoadsignAtomic, _ZN18CCustomRoadsignMgr19SetupRoadsignAtomicEP8RpAtomicPci, RpAtomic*, RpAtomic* pAtomic, char* RoadsignText, i32 nNumLetters);
    DECL_FASTCALL_SIMPLE(SetAtomicAlpha, _ZN18CCustomRoadsignMgr14SetAtomicAlphaEP8RpAtomich, RpAtomic*, RpAtomic* pAtomic, u8 alpha);
    DECL_FASTCALL_SIMPLE(RenderTest, _ZN18CCustomRoadsignMgr10RenderTestERK7CVector, u8, CVector const& campos);
    DECL_FASTCALL_SIMPLE(DebugDrawInternalTexture, _ZN18CCustomRoadsignMgr24DebugDrawInternalTextureEv, void);

    // STATIC values
    DECL_OBJECT_PLT(RwTexture*, pCharsetTex, BYBIT(0x679284, 0x850520));

DECL_CLASS_END()
CHECKSIZE(CCustomRoadsignMgr, 0x1, 0x1);

#endif // __AML_PSDK_SACUSTOMROADSIGN_H
