#ifndef __AML_PSDK_SACREEPINGFIRE_H
#define __AML_PSDK_SACREEPINGFIRE_H

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/gta_base/Vector.h>

DECL_CLASS(CCreepingFire)
    enum
    {
        CRFIRE_GRIDSIZE = 32
    };

    enum
    {
        CRFRSTAT_READY = 0,
        CRFRSTAT_ALMOSTBURNING1 = 1,
        CRFRSTAT_ALMOSTBURNING2 = 2,
        CRFRSTAT_ALMOSTBURNING3 = 3,
        CRFRSTAT_BURNT1 = 4,
        CRFRSTAT_BURNT2 = 5,
        CRFRSTAT_BURNT3 = 6
    };

    // STATIC functions
    DECL_FASTCALL_SIMPLE(SetReadyToBurn, _ZN13CCreepingFire14SetReadyToBurnEv, void);
    DECL_FASTCALL_SIMPLE(Update, _ZN13CCreepingFire6UpdateEv, void);
    DECL_FASTCALL_SIMPLE(TryToStartFireAtCoors, _ZN13CCreepingFire21TryToStartFireAtCoorsE7CVectorabbf, bool, CVector pos, i8 direction, bool scriptFire, bool pointLight, float generationDist);

    // STATIC values
    typedef u8 m_aFireStatus_t[32];
    DECL_OBJECT_ARRAY_PLT(m_aFireStatus_t, m_aFireStatus, BYBIT(0x677ce8, 0x84d9f0));

DECL_CLASS_END()
CHECKSIZE(CCreepingFire, 0x1, 0x1);

#endif // __AML_PSDK_SACREEPINGFIRE_H
