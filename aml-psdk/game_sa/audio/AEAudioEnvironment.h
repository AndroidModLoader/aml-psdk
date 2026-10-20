#ifndef __AML_PSDK_SAAEAUDIOENVIRONMENT_H
#define __AML_PSDK_SAAEAUDIOENVIRONMENT_H

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/gta_base/Vector.h>

struct CPlaceable;

DECL_CLASS(CAEAudioEnvironment)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(GetDopplerRelativeFrequency, _ZN19CAEAudioEnvironment27GetDopplerRelativeFrequencyEffjjf, float, float previousDistance, float currentDistance, u32 previousTime, u32 currentTime, float timeScale);
    DECL_FASTCALL_SIMPLE(GetPositionRelativeToCamera1, _ZN19CAEAudioEnvironment27GetPositionRelativeToCameraEP7CVectorS1_, void, CVector* relativePos, CVector* pos);
    inline static void GetPositionRelativeToCamera(CVector* relativePos, CVector* pos) { return GetPositionRelativeToCamera1(relativePos, pos); }
    DECL_FASTCALL_SIMPLE(GetPositionRelativeToCamera2, _ZN19CAEAudioEnvironment27GetPositionRelativeToCameraEP7CVectorP10CPlaceable, void, CVector* relativePos, CPlaceable* pos);
    inline static void GetPositionRelativeToCamera(CVector* relativePos, CPlaceable* pos) { return GetPositionRelativeToCamera2(relativePos, pos); }
    DECL_FASTCALL_SIMPLE(GetDistanceAttenuation, _ZN19CAEAudioEnvironment22GetDistanceAttenuationEf, float, float distance);
    DECL_FASTCALL_SIMPLE(GetDirectionalMikeAttenuation, _ZN19CAEAudioEnvironment29GetDirectionalMikeAttenuationERK7CVector, float, CVector const& direction);
    DECL_FASTCALL_SIMPLE(GetReverbEnvironmentAndDepth, _ZN19CAEAudioEnvironment28GetReverbEnvironmentAndDepthEPaPi, void, i8* environment, i32* depth);

DECL_CLASS_END()
CHECKSIZE(CAEAudioEnvironment, 0x1, 0x1);

#endif // __AML_PSDK_SAAEAUDIOENVIRONMENT_H
