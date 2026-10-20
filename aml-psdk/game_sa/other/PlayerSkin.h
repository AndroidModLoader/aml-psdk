#ifndef __AML_PSDK_SAPLAYERSKIN_H
#define __AML_PSDK_SAPLAYERSKIN_H

#include <aml-psdk/game_sa/plugin.h>

struct RwTexture;

DECL_CLASS(CPlayerSkin)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(Initialise, _ZN11CPlayerSkin10InitialiseEv, void);
    DECL_FASTCALL_SIMPLE(Shutdown, _ZN11CPlayerSkin8ShutdownEv, void);
    DECL_FASTCALL_SIMPLE(GetSkinTexture, _ZN11CPlayerSkin14GetSkinTextureEPKc, RwTexture*, char const* name);
    DECL_FASTCALL_SIMPLE(BeginFrontendSkinEdit, _ZN11CPlayerSkin21BeginFrontendSkinEditEv, void);
    DECL_FASTCALL_SIMPLE(RenderFrontendSkinEdit, _ZN11CPlayerSkin22RenderFrontendSkinEditEv, void);
    DECL_FASTCALL_SIMPLE(EndFrontendSkinEdit, _ZN11CPlayerSkin19EndFrontendSkinEditEv, void);

    // STATIC values
    DECL_OBJECT_PLT(u32, m_txdSlot, BYBIT(0x678c04, 0x84f830));

DECL_CLASS_END()
CHECKSIZE(CPlayerSkin, 0x1, 0x1);

#endif // __AML_PSDK_SAPLAYERSKIN_H
