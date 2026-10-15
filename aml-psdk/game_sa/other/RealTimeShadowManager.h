#ifndef __AML_PSDK_SAREALTIMESHADOWMANAGER_H
#define __AML_PSDK_SAREALTIMESHADOWMANAGER_H

#include "../engine/Shadows.h"

struct CPhysical;

DECL_CLASS(CRealTimeShadowManager)
    // Construct/Deconstruct functions
    DECL_DTORCALL(CRealTimeShadowManager, _ZN22CRealTimeShadowManagerD2Ev);
    DECL_CTORCALL(CRealTimeShadowManager, _ZN22CRealTimeShadowManagerC2Ev);

    // STATIC functions
    DECL_FASTCALL_SIMPLE(CamDistComp, _ZN22CRealTimeShadowManager11CamDistCompEPKvS1_, int, void const* a, void const* b);

    // Member functions
    DECL_THISCALL_SIMPLE(Init, _ZN22CRealTimeShadowManager4InitEv, void);
    DECL_THISCALL_SIMPLE(Exit, _ZN22CRealTimeShadowManager4ExitEv, void);
    DECL_THISCALL_SIMPLE(Update, _ZN22CRealTimeShadowManager6UpdateEv, void);
    DECL_THISCALL_SIMPLE(ReInit, _ZN22CRealTimeShadowManager6ReInitEv, void);
    DECL_THISCALL_HEAD(DoShadowThisFrame, _ZN22CRealTimeShadowManager17DoShadowThisFrameEP9CPhysical, void, CPhysical* pPhysical)
    DECL_THISCALL_TAIL(DoShadowThisFrame, pPhysical)
    DECL_THISCALL_HEAD(GetRealTimeShadow, _ZN22CRealTimeShadowManager17GetRealTimeShadowEP9CPhysical, CRealTimeShadow*, CPhysical* pPhysical)
    DECL_THISCALL_TAIL(GetRealTimeShadow, pPhysical)
    DECL_THISCALL_HEAD(ReturnRealTimeShadow, _ZN22CRealTimeShadowManager20ReturnRealTimeShadowEP15CRealTimeShadow, void, CRealTimeShadow* pRealTimeShadow)
    DECL_THISCALL_TAIL(ReturnRealTimeShadow, pRealTimeShadow)
    // Member values
    u8 m_initialised;
    CRealTimeShadow* m_pRealTimeShadows[40];
    bool m_updatingShadows;
    CShadowCamera m_IPCameraMB;
    CShadowCamera m_IPCameraGradient;
DECL_CLASS_END()
CHECKSIZE(CRealTimeShadowManager, 0xB8, 0x170);

DECL_OBJECT_PLT_GLOBAL(CRealTimeShadowManager, g_realTimeShadowMan, BYBIT(0x679A98, 0x851550));

#define g_realTimeShadowMan g_realTimeShadowMan()

#endif // __AML_PSDK_SAREALTIMESHADOWMANAGER_H
