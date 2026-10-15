#ifndef __AML_PSDK_SAAEAUDIOUTILITY_H
#define __AML_PSDK_SAAEAUDIOUTILITY_H

#include "../plugin.h"
#include <cstddef>

struct CVehicle;

DECL_CLASS(CAEAudioUtility)

    // STATIC functions
    DECL_FASTCALL_SIMPLE(StaticInitialise, _ZN15CAEAudioUtility16StaticInitialiseEv, void);
    DECL_FASTCALL_SIMPLE(GetRandomNumberInRange1, _ZN15CAEAudioUtility22GetRandomNumberInRangeEii, i32, i32 Min, i32 Max);
    inline static i32 GetRandomNumberInRange(i32 Min, i32 Max)
    {
        return GetRandomNumberInRange1(Min, Max);
    }
    DECL_FASTCALL_SIMPLE(GetRandomNumberInRange2, _ZN15CAEAudioUtility22GetRandomNumberInRangeEff, float, float Min, float Max);
    inline static float GetRandomNumberInRange(float Min, float Max)
    {
        return GetRandomNumberInRange2(Min, Max);
    }
    DECL_FASTCALL_SIMPLE(ResolveProbability, _ZN15CAEAudioUtility18ResolveProbabilityEf, u8, float Probability);
    DECL_FASTCALL_SIMPLE(GetBankAndSoundFromScriptSlotAudioEvent, _ZN15CAEAudioUtility39GetBankAndSoundFromScriptSlotAudioEventEPiS0_S0_i, u8, i32* pScriptSlotAudioEvent, int* pBankID, int* pSoundID, int Slot);
    DECL_FASTCALL_SIMPLE(GetPiecewiseLinear, _ZN15CAEAudioUtility18GetPiecewiseLinearEfsPA2_f, float, float fRatio, i16 Nodes, float (*Graph)[2]);
    DECL_FASTCALL_SIMPLE(FindVehicleOfPlayer, _ZN15CAEAudioUtility19FindVehicleOfPlayerEv, CVehicle*);
    DECL_FASTCALL_SIMPLE(AudioLog10, _ZN15CAEAudioUtility10AudioLog10Ef, float, float fRatio);
    DECL_FASTCALL_SIMPLE(GetCurrentTimeInMilliseconds, _ZN15CAEAudioUtility28GetCurrentTimeInMillisecondsEv, u64);
    DECL_FASTCALL_SIMPLE(ConvertFromBytesToMS, _ZN15CAEAudioUtility20ConvertFromBytesToMSEjjt, i32, u32 NumBytes, u32 SamplesPerSecond, u16 NumChannels);
    DECL_FASTCALL_SIMPLE(ConvertFromMSToBytes, _ZN15CAEAudioUtility20ConvertFromMSToBytesEjjt, i32, u32 NumMilliseconds, u32 SamplesPerSecond, u16 NumChannels);

    // STATIC values
    typedef float ts_LogLookupRow[2];
    DECL_OBJECT_ARRAY_PLT(ts_LogLookupRow, m_sfLogLookup, BYBIT(0x6780A0, 0x84E158));
DECL_CLASS_END()
CHECKSIZE(CAEAudioUtility, 0x1, 0x1);

#endif // __AML_PSDK_SAAEAUDIOUTILITY_H
