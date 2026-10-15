#ifndef __AML_PSDK_SAPEDTYPE_H
#define __AML_PSDK_SAPEDTYPE_H

#include <aml-psdk/game_sa/entity/Ped.h>

DECL_CLASS(CPedType)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(Initialise, _ZN8CPedType10InitialiseEv, void);
    DECL_FASTCALL_SIMPLE(Shutdown, _ZN8CPedType8ShutdownEv, void);
    DECL_FASTCALL_SIMPLE(LoadPedData, _ZN8CPedType11LoadPedDataEv, void);
    DECL_FASTCALL_SIMPLE(FindPedType, _ZN8CPedType11FindPedTypeEPc, ePedType, char* pString);
    DECL_FASTCALL_SIMPLE(GetPedFlag, _ZN8CPedType10GetPedFlagEi, u32, i32 nPedType);
    DECL_FASTCALL_SIMPLE(GetPedTypeAcquaintances1, _ZN8CPedType23GetPedTypeAcquaintancesEi, CPedAcquaintance const&, i32 PedType);
    inline static CPedAcquaintance const& GetPedTypeAcquaintances(i32 PedType)
    {
        return GetPedTypeAcquaintances1(PedType);
    }
    DECL_FASTCALL_SIMPLE(GetPedTypeAcquaintances2, _ZN8CPedType23GetPedTypeAcquaintancesEii, u32, i32 AcquaintanceType, i32 PedType);
    inline static u32 GetPedTypeAcquaintances(i32 AcquaintanceType, i32 PedType)
    {
        return GetPedTypeAcquaintances2(AcquaintanceType, PedType);
    }
    DECL_FASTCALL_SIMPLE(SetPedTypeAsAcquaintance, _ZN8CPedType24SetPedTypeAsAcquaintanceEiij, void, i32 AcquaintanceType, i32 PedType, u32 AcquaintancePedTypeFlag);
    DECL_FASTCALL_SIMPLE(ClearPedTypeAsAcquaintance, _ZN8CPedType26ClearPedTypeAsAcquaintanceEiij, void, i32 AcquaintanceType, i32 PedType, u32 AcquaintancePedTypeFlag);
    DECL_FASTCALL_SIMPLE(ClearPedTypeAcquaintances, _ZN8CPedType25ClearPedTypeAcquaintancesEii, void, i32 AcquaintanceType, i32 PedType);
    DECL_FASTCALL_SIMPLE(Save, _ZN8CPedType4SaveEv, bool);
    DECL_FASTCALL_SIMPLE(Load, _ZN8CPedType4LoadEv, bool);
    DECL_FASTCALL_SIMPLE(PoliceDontCareAboutCrimesAgainstPedType, _ZN8CPedType39PoliceDontCareAboutCrimesAgainstPedTypeEi, bool, i32 PedType);

    // STATIC values
    DECL_OBJECT_PLT(CPedType*, ms_apPedTypes, BYBIT(0x67851C, 0x84EA50));

    // Member values
    CPedAcquaintance m_acquaintances;
DECL_CLASS_END()
CHECKSIZE(CPedType, 0x14, 0x14);

#endif // __AML_PSDK_SAPEDTYPE_H
