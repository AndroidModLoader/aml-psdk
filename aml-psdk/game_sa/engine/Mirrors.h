#ifndef __AML_PSDK_SAMIRRORS_H
#define __AML_PSDK_SAMIRRORS_H

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/gta_base/Vector.h>

struct CMatrix;
struct RwRaster;

DECL_CLASS(CMirrors)
    enum
    {
        MIRTYPE_NONE = 0,
        MIRTYPE_WALL = 1,
        MIRTYPE_FLOOR = 2,
        MIRTYPE_SPHEREMAP = 3
    };

    // STATIC functions
    DECL_FASTCALL_SIMPLE(Init, _ZN8CMirrors4InitEv, void);
    DECL_FASTCALL_SIMPLE(ShutDown, _ZN8CMirrors8ShutDownEv, void);
    DECL_FASTCALL_SIMPLE(BeforeConstructRenderList, _ZN8CMirrors25BeforeConstructRenderListEv, void);
    DECL_FASTCALL_SIMPLE(BeforeMainRender, _ZN8CMirrors16BeforeMainRenderEv, void);
    DECL_FASTCALL_SIMPLE(RenderReflections, _ZN8CMirrors17RenderReflectionsEv, void);
    DECL_FASTCALL_SIMPLE(CreateBuffer, _ZN8CMirrors12CreateBufferEv, void);
    DECL_FASTCALL_SIMPLE(RenderMirrorBuffer, _ZN8CMirrors18RenderMirrorBufferEb, void, bool enabled);
    DECL_FASTCALL_SIMPLE(BuildCameraMatrixForScreens, _ZN8CMirrors27BuildCameraMatrixForScreensEP7CMatrix, void, CMatrix* value);
    DECL_FASTCALL_SIMPLE(BuildCamMatrix, _ZN8CMirrors14BuildCamMatrixEP7CMatrix7CVectorS2_, void, CMatrix* value, CVector pos1, CVector pos2);
    DECL_FASTCALL_SIMPLE(RenderReflBuffer, _ZN8CMirrors16RenderReflBufferEb, void, bool enabled);

    // STATIC values
    DECL_OBJECT_PLT(RwRaster*, pBuffer, BYBIT(0x678b44, 0x84f6b0));
    DECL_OBJECT_PLT(RwRaster*, pZBuffer, BYBIT(0x6784e4, 0x84e9e0));
    DECL_OBJECT_ARRAY_PLT(RwRaster*, reflBuffer, BYBIT(0x67950c, 0x850a28));
    DECL_OBJECT_PLT(float, MirrorV, BYBIT(0x6776a4, 0x84cd78));
    DECL_OBJECT_PLT(CVector, MirrorNormal, BYBIT(0x676bd0, 0x84b7e8));
    DECL_OBJECT_PLT(i32, TypeOfMirror, BYBIT(0x677ec0, 0x84dda0));
    DECL_OBJECT_PLT(u32, MirrorFlags, BYBIT(0x679948, 0x8512b0));
    DECL_OBJECT_PLT(bool, bRenderingReflection, BYBIT(0x6763f8, 0x84a848));
    DECL_OBJECT_PLT(bool, d3dRestored, BYBIT(0x677ed8, 0x84ddd0));

DECL_CLASS_END()
CHECKSIZE(CMirrors, 0x1, 0x1);

#endif // __AML_PSDK_SAMIRRORS_H
