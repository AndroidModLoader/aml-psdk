#ifndef __AML_PSDK_SAMOVINGTHINGS_H
#define __AML_PSDK_SAMOVINGTHINGS_H

#include "../plugin.h"

DECL_CLASS(CMovingThings)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(Init, _ZN13CMovingThings4InitEv, void);
    DECL_FASTCALL_SIMPLE(Shutdown, _ZN13CMovingThings8ShutdownEv, void);
    DECL_FASTCALL_SIMPLE(Update, _ZN13CMovingThings6UpdateEv, void);
    DECL_FASTCALL_SIMPLE(Render_BeforeClouds, _ZN13CMovingThings19Render_BeforeCloudsEv, void);
    DECL_FASTCALL_SIMPLE(Render, _ZN13CMovingThings6RenderEv, void);
DECL_CLASS_END()
CHECKSIZE(CMovingThings, 0x1, 0x1);

#endif // __AML_PSDK_SAMOVINGTHINGS_H
