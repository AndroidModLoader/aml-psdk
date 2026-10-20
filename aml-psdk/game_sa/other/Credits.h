#ifndef __AML_PSDK_SACREDITS_H
#define __AML_PSDK_SACREDITS_H

#include <aml-psdk/game_sa/plugin.h>

DECL_CLASS(CCredits)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(Render, _ZN8CCredits6RenderEv, void);
    DECL_FASTCALL_SIMPLE(Start, _ZN8CCredits5StartEv, void);
    DECL_FASTCALL_SIMPLE(Stop, _ZN8CCredits4StopEv, void);
    DECL_FASTCALL_SIMPLE(Update, _ZN8CCredits6UpdateEv, void);
    DECL_FASTCALL_SIMPLE(RenderCredits, _ZN8CCredits13RenderCreditsEv, void);
    DECL_FASTCALL_SIMPLE(PrintCreditText, _ZN8CCredits15PrintCreditTextEffPtRjfb, void, float scaleX, float scaleY, u16* text, u32& position, float spacing, bool highlighted);
    DECL_FASTCALL_SIMPLE(PrintCreditSpace, _ZN8CCredits16PrintCreditSpaceEfRj, void, float spacing, u32& position);

    // STATIC values
    DECL_OBJECT_PLT(bool, bCreditsGoing, BYBIT(0x6793f4, 0x850800));
    DECL_OBJECT_PLT(u32, CreditsStartTime, BYBIT(0x676784, 0x84af60));

DECL_CLASS_END()
CHECKSIZE(CCredits, 0x1, 0x1);

#endif // __AML_PSDK_SACREDITS_H
