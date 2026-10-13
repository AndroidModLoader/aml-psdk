#ifndef __AML_PSDK_SABRIGHTLIGHTS_H
#define __AML_PSDK_SABRIGHTLIGHTS_H

/*
    Plugin-SDK (Grand Theft Auto San Andreas) header file
    Authors: GTA Community. See more here
    https://github.com/DK22Pac/plugin-sdk
    Do not delete this comment block. Respect others' work!
*/

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/gta_base/Vector.h>

struct CBrightLight
{
    CVector Coors;
    CVector Up;
    CVector Side;
    CVector Front;
    float DistToCam;
    u8 Type;
    u8 Red;
    u8 Green;
    u8 Blue;
};
CHECKSIZE(CBrightLight, 0x38, 0x38);

DECL_CLASS(CBrightLights)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(Init, _ZN13CBrightLights4InitEv, void);
    DECL_FASTCALL_SIMPLE(Render, _ZN13CBrightLights6RenderEv, void);
    DECL_FASTCALL_SIMPLE(RenderOutGeometryBuffer, _ZN13CBrightLights23RenderOutGeometryBufferEv, void);
    DECL_FASTCALL_SIMPLE(RegisterOne, _ZN13CBrightLights11RegisterOneE7CVectorS0_S0_S0_hhhh, void, CVector Coors, CVector Up, CVector Side, CVector Front, u8 Type, u8 Red, u8 Green, u8 Blue);

    // STATIC values
    DECL_OBJECT_ARRAY_SYM(CBrightLight, aBrightLights, _ZN13CBrightLights13aBrightLightsE);
    DECL_OBJECT_SYM(i32, NumBrightLights, _ZN13CBrightLights15NumBrightLightsE);

DECL_CLASS_END()

#define aBrightLights aBrightLights()
#define NumBrightLights NumBrightLights()

#endif // __AML_PSDK_SABRIGHTLIGHTS_H
