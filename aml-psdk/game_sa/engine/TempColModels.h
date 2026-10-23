#ifndef __AML_PSDK_SATEMPCOLMODELS_H
#define __AML_PSDK_SATEMPCOLMODELS_H

#include "../base/ColModel.h"

DECL_CLASS(CTempColModels)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(Initialise, _ZN14CTempColModels10InitialiseEv, void);
    DECL_FASTCALL_SIMPLE(Shutdown, _ZN14CTempColModels8ShutdownEv, void);

    // STATIC values
    DECL_OBJECT_PLT(CColModel, ms_colModelBBox, BYBIT(0x67896c, 0x84f2f8));
    DECL_OBJECT_ARRAY_PLT(CColModel, ms_colModelCutObj, BYBIT(0x676770, 0x84af38));
    DECL_OBJECT_PLT(CColModel, ms_colModelPed1, BYBIT(0x678a74, 0x84f510));
    DECL_OBJECT_PLT(CColModel, ms_colModelPed2, BYBIT(0x6763a0, 0x84a798));
    DECL_OBJECT_PLT(CColModel, ms_colModelDoor1, BYBIT(0x677e8c, 0x84dd38));
    DECL_OBJECT_PLT(CColModel, ms_colModelBumper1, BYBIT(0x679404, 0x850820));
    DECL_OBJECT_PLT(CColModel, ms_colModelPanel1, BYBIT(0x677a58, 0x84d4d8));
    DECL_OBJECT_PLT(CColModel, ms_colModelBonnet1, BYBIT(0x6765a8, 0x84aba8));
    DECL_OBJECT_PLT(CColModel, ms_colModelBoot1, BYBIT(0x67614c, 0x84a2f8));
    DECL_OBJECT_PLT(CColModel, ms_colModelWheel1, BYBIT(0x678ea4, 0x84fd70));
    DECL_OBJECT_PLT(CColModel, ms_colModelBodyPart1, BYBIT(0x6788bc, 0x84f198));
    DECL_OBJECT_PLT(CColModel, ms_colModelBodyPart2, BYBIT(0x678b00, 0x84f628));
    DECL_OBJECT_PLT(CColModel, ms_colModelWeapon, BYBIT(0x676344, 0x84a6e0));
DECL_CLASS_END()
CHECKSIZE(CTempColModels, 0x1, 0x1);

#endif // __AML_PSDK_SATEMPCOLMODELS_H
