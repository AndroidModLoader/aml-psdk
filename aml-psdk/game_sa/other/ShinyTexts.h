#ifndef __AML_PSDK_SASHINYTEXTS_H
#define __AML_PSDK_SASHINYTEXTS_H

/*
    Plugin-SDK (Grand Theft Auto San Andreas) header file
    Authors: GTA Community. See more here
    https://github.com/DK22Pac/plugin-sdk
    Do not delete this comment block. Respect others' work!
*/

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/gta_base/Vector.h>

struct CShinyText
{
    CVector Coors1;
    CVector Coors2;
    CVector Coors3;
    CVector Coors4;
    float Tex1U;
    float Tex1V;
    float Tex2U;
    float Tex2V;
    float Tex3U;
    float Tex3V;
    float Tex4U;
    float Tex4V;
    float DistToCam;
    u8 Type;
    u8 Red;
    u8 Green;
    u8 Blue;
};
CHECKSIZE(CShinyText, 0x58, 0x58);

DECL_CLASS(CShinyTexts)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(Init, _ZN11CShinyTexts4InitEv, void);
    DECL_FASTCALL_SIMPLE(Render, _ZN11CShinyTexts6RenderEv, void);
    DECL_FASTCALL_SIMPLE(RenderOutGeometryBuffer, _ZN11CShinyTexts23RenderOutGeometryBufferEv, void);
    DECL_FASTCALL_SIMPLE(RegisterOne, _ZN11CShinyTexts11RegisterOneE7CVectorS0_S0_S0_ffffffffhhhhf, void, CVector Coors1, CVector Coors2, CVector Coors3, CVector Coors4, float Tex1U, float Tex1V, float Tex2U, float Tex2V, float Tex3U, float Tex3V, float Tex4U, float Tex4V, u8 Type, u8 Red, u8 Green, u8 Blue, float Range);

    // STATIC values
    DECL_OBJECT_ARRAY_PLT(CShinyText, aShinyTexts, BYBIT(0x679AC0, 0x8515A0));
    DECL_OBJECT_PLT(i32, NumShinyTexts, BYBIT(0x6779F8, 0x84D418));

DECL_CLASS_END()

#define aShinyTexts aShinyTexts()
#define NumShinyTexts NumShinyTexts()

#endif // __AML_PSDK_SASHINYTEXTS_H
