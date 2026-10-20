#ifndef __AML_PSDK_SAFXINFO_H
#define __AML_PSDK_SAFXINFO_H

#include <aml-psdk/game_sa/plugin.h>

DECL_CLASS_VTABLE(FxInterpInfo_c)
    // Construct/Deconstruct functions
    DECL_CTORCALL(FxInterpInfo_c, _ZN14FxInterpInfo_cC2Ev);
    DECL_DTORCALL_VIRTUAL(FxInterpInfo_c, _ZN14FxInterpInfo_cD2Ev, _ZN14FxInterpInfo_c, _ZTV14FxInterpInfo_c);

    // Virtual functions
    virtual void Load(FILESTREAM file) = 0;

    // Member values
    u8 m_looped;
    i8 m_numKeys;
    i8 m_numAttribs;
    u16* m_times;
DECL_CLASS_END()
CHECKSIZE(FxInterpInfo_c, 0xc, 0x18);

DECL_CLASS_BASED(FxInterpInfo255_c, FxInterpInfo_c)
    // Construct/Deconstruct functions
    DECL_CTORCALL(FxInterpInfo255_c, _ZN17FxInterpInfo255_cC2Ev);
    DECL_DTORCALL_VIRTUAL(FxInterpInfo255_c, _ZN17FxInterpInfo255_cD2Ev, _ZN17FxInterpInfo255_c, _ZTV17FxInterpInfo255_c);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(FxInterpInfo255_c, Load, _ZTV17FxInterpInfo255_c, 2, void, FILESTREAM file)
    DECL_VIRTUALCALL_TAIL(file)

    // Member functions
    DECL_THISCALL_HEAD(GetVal, _ZN17FxInterpInfo255_c6GetValEPff, void, float* values, float time)
    DECL_THISCALL_TAIL(GetVal, values, time)

    // Member values
    i16** m_keys;
DECL_CLASS_END()
CHECKSIZE(FxInterpInfo255_c, 0x10, 0x20);

DECL_CLASS_BASED(FxInterpInfo32_c, FxInterpInfo_c)
    // Construct/Deconstruct functions
    DECL_CTORCALL(FxInterpInfo32_c, _ZN16FxInterpInfo32_cC2Ev);
    DECL_DTORCALL_VIRTUAL(FxInterpInfo32_c, _ZN16FxInterpInfo32_cD2Ev, _ZN16FxInterpInfo32_c, _ZTV16FxInterpInfo32_c);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(FxInterpInfo32_c, Load, _ZTV16FxInterpInfo32_c, 2, void, FILESTREAM file)
    DECL_VIRTUALCALL_TAIL(file)

    // Member functions
    DECL_THISCALL_HEAD(GetVal, _ZN16FxInterpInfo32_c6GetValEPff, void, float* values, float time)
    DECL_THISCALL_TAIL(GetVal, values, time)

    // Member values
    i16** m_keys;
DECL_CLASS_END()
CHECKSIZE(FxInterpInfo32_c, 0x10, 0x20);

DECL_CLASS_BASED(FxInterpInfoFloat_c, FxInterpInfo_c)
    // Construct/Deconstruct functions
    DECL_CTORCALL(FxInterpInfoFloat_c, _ZN19FxInterpInfoFloat_cC2Ev);
    DECL_DTORCALL_VIRTUAL(FxInterpInfoFloat_c, _ZN19FxInterpInfoFloat_cD2Ev, _ZN19FxInterpInfoFloat_c, _ZTV19FxInterpInfoFloat_c);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(FxInterpInfoFloat_c, Load, _ZTV19FxInterpInfoFloat_c, 2, void, FILESTREAM file)
    DECL_VIRTUALCALL_TAIL(file)

    // Member functions
    DECL_THISCALL_NAMED_HEAD(GetVal1, GetVal, _ZN19FxInterpInfoFloat_c6GetValEPff, void, float* values, float time)
    DECL_THISCALL_TAIL(GetVal1, values, time)
    DECL_THISCALL_NAMED_HEAD(GetVal2, GetVal, _ZN19FxInterpInfoFloat_c6GetValEiff, float, i32 attribute, float time, float deltaTime)
    DECL_THISCALL_TAIL(GetVal2, attribute, time, deltaTime)

    // Member values
    float** m_keys;
DECL_CLASS_END()
CHECKSIZE(FxInterpInfoFloat_c, 0x10, 0x20);

DECL_CLASS_BASED(FxInterpInfoU255_c, FxInterpInfo_c)
    // Construct/Deconstruct functions
    DECL_CTORCALL(FxInterpInfoU255_c, _ZN18FxInterpInfoU255_cC2Ev);
    DECL_DTORCALL_VIRTUAL(FxInterpInfoU255_c, _ZN18FxInterpInfoU255_cD2Ev, _ZN18FxInterpInfoU255_c, _ZTV18FxInterpInfoU255_c);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(FxInterpInfoU255_c, Load, _ZTV18FxInterpInfoU255_c, 2, void, FILESTREAM file)
    DECL_VIRTUALCALL_TAIL(file)

    // Member functions
    DECL_THISCALL_HEAD(GetVal, _ZN18FxInterpInfoU255_c6GetValEPff, void, float* values, float time)
    DECL_THISCALL_TAIL(GetVal, values, time)

    // Member values
    u16** m_keys;
DECL_CLASS_END()
CHECKSIZE(FxInterpInfoU255_c, 0x10, 0x20);

DECL_CLASS(FxInfo_c)
    // Construct/Deconstruct functions
    virtual ~FxInfo_c() = 0;

    // Virtual functions
    virtual void Load(FILESTREAM file, i32 version) = 0;
    virtual void GetValue(float currentTime, float particleTime, float deltaTime, float length, u8 useConst, void* value) = 0;

    // Member values
    u16 m_type;
    u8 m_timeModeParticle;
DECL_CLASS_END()
CHECKSIZE(FxInfo_c, 0x8, 0x10);

inline FxInfo_c::~FxInfo_c() = default;

DECL_CLASS_BASED(FxInfoAnimTexture_c, FxInfo_c)
    // Construct/Deconstruct functions
    DECL_CTORCALL(FxInfoAnimTexture_c, _ZN19FxInfoAnimTexture_cC2Ev);
    DECL_DTORCALL_VIRTUAL(FxInfoAnimTexture_c, _ZN19FxInfoAnimTexture_cD2Ev, _ZN19FxInfoAnimTexture_c, _ZTV19FxInfoAnimTexture_c);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(FxInfoAnimTexture_c, Load, _ZTV19FxInfoAnimTexture_c, 2, void, FILESTREAM file, i32 version)
    DECL_VIRTUALCALL_TAIL(file, version)
    DECL_VIRTUALCALL_HEAD(FxInfoAnimTexture_c, GetValue, _ZTV19FxInfoAnimTexture_c, 3, void, float currentTime, float particleTime, float deltaTime, float length, u8 useConst, void* value)
    DECL_VIRTUALCALL_TAIL(currentTime, particleTime, deltaTime, length, useConst, value)

    // Member values
    FxInterpInfo32_c m_interpInfo;
DECL_CLASS_END()
CHECKSIZE(FxInfoAnimTexture_c, 0x18, 0x30);

DECL_CLASS_BASED(FxInfoAttractLine_c, FxInfo_c)
    // Construct/Deconstruct functions
    DECL_CTORCALL(FxInfoAttractLine_c, _ZN19FxInfoAttractLine_cC2Ev);
    DECL_DTORCALL_VIRTUAL(FxInfoAttractLine_c, _ZN19FxInfoAttractLine_cD2Ev, _ZN19FxInfoAttractLine_c, _ZTV19FxInfoAttractLine_c);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(FxInfoAttractLine_c, Load, _ZTV19FxInfoAttractLine_c, 2, void, FILESTREAM file, i32 version)
    DECL_VIRTUALCALL_TAIL(file, version)
    DECL_VIRTUALCALL_HEAD(FxInfoAttractLine_c, GetValue, _ZTV19FxInfoAttractLine_c, 3, void, float currentTime, float particleTime, float deltaTime, float length, u8 useConst, void* value)
    DECL_VIRTUALCALL_TAIL(currentTime, particleTime, deltaTime, length, useConst, value)

    // Member values
    FxInterpInfo32_c m_interpInfo;
DECL_CLASS_END()
CHECKSIZE(FxInfoAttractLine_c, 0x18, 0x30);

DECL_CLASS_BASED(FxInfoAttractPt_c, FxInfo_c)
    // Construct/Deconstruct functions
    DECL_CTORCALL(FxInfoAttractPt_c, _ZN17FxInfoAttractPt_cC2Ev);
    DECL_DTORCALL_VIRTUAL(FxInfoAttractPt_c, _ZN17FxInfoAttractPt_cD2Ev, _ZN17FxInfoAttractPt_c, _ZTV17FxInfoAttractPt_c);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(FxInfoAttractPt_c, Load, _ZTV17FxInfoAttractPt_c, 2, void, FILESTREAM file, i32 version)
    DECL_VIRTUALCALL_TAIL(file, version)
    DECL_VIRTUALCALL_HEAD(FxInfoAttractPt_c, GetValue, _ZTV17FxInfoAttractPt_c, 3, void, float currentTime, float particleTime, float deltaTime, float length, u8 useConst, void* value)
    DECL_VIRTUALCALL_TAIL(currentTime, particleTime, deltaTime, length, useConst, value)

    // Member values
    FxInterpInfo32_c m_interpInfo;
DECL_CLASS_END()
CHECKSIZE(FxInfoAttractPt_c, 0x18, 0x30);

DECL_CLASS_BASED(FxInfoColourBright_c, FxInfo_c)
    // Construct/Deconstruct functions
    DECL_CTORCALL(FxInfoColourBright_c, _ZN20FxInfoColourBright_cC2Ev);
    DECL_DTORCALL_VIRTUAL(FxInfoColourBright_c, _ZN20FxInfoColourBright_cD2Ev, _ZN20FxInfoColourBright_c, _ZTV20FxInfoColourBright_c);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(FxInfoColourBright_c, Load, _ZTV20FxInfoColourBright_c, 2, void, FILESTREAM file, i32 version)
    DECL_VIRTUALCALL_TAIL(file, version)
    DECL_VIRTUALCALL_HEAD(FxInfoColourBright_c, GetValue, _ZTV20FxInfoColourBright_c, 3, void, float currentTime, float particleTime, float deltaTime, float length, u8 useConst, void* value)
    DECL_VIRTUALCALL_TAIL(currentTime, particleTime, deltaTime, length, useConst, value)

    // Member values
    FxInterpInfoU255_c m_interpInfo;
DECL_CLASS_END()
CHECKSIZE(FxInfoColourBright_c, 0x18, 0x30);

DECL_CLASS_BASED(FxInfoColourRange_c, FxInfo_c)
    // Construct/Deconstruct functions
    DECL_CTORCALL(FxInfoColourRange_c, _ZN19FxInfoColourRange_cC2Ev);
    DECL_DTORCALL_VIRTUAL(FxInfoColourRange_c, _ZN19FxInfoColourRange_cD2Ev, _ZN19FxInfoColourRange_c, _ZTV19FxInfoColourRange_c);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(FxInfoColourRange_c, Load, _ZTV19FxInfoColourRange_c, 2, void, FILESTREAM file, i32 version)
    DECL_VIRTUALCALL_TAIL(file, version)
    DECL_VIRTUALCALL_HEAD(FxInfoColourRange_c, GetValue, _ZTV19FxInfoColourRange_c, 3, void, float currentTime, float particleTime, float deltaTime, float length, u8 useConst, void* value)
    DECL_VIRTUALCALL_TAIL(currentTime, particleTime, deltaTime, length, useConst, value)

    // Member values
    FxInterpInfoU255_c m_interpInfo;
DECL_CLASS_END()
CHECKSIZE(FxInfoColourRange_c, 0x18, 0x30);

DECL_CLASS_BASED(FxInfoColour_c, FxInfo_c)
    // Construct/Deconstruct functions
    DECL_CTORCALL(FxInfoColour_c, _ZN14FxInfoColour_cC2Ev);
    DECL_DTORCALL_VIRTUAL(FxInfoColour_c, _ZN14FxInfoColour_cD2Ev, _ZN14FxInfoColour_c, _ZTV14FxInfoColour_c);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(FxInfoColour_c, Load, _ZTV14FxInfoColour_c, 2, void, FILESTREAM file, i32 version)
    DECL_VIRTUALCALL_TAIL(file, version)
    DECL_VIRTUALCALL_HEAD(FxInfoColour_c, GetValue, _ZTV14FxInfoColour_c, 3, void, float currentTime, float particleTime, float deltaTime, float length, u8 useConst, void* value)
    DECL_VIRTUALCALL_TAIL(currentTime, particleTime, deltaTime, length, useConst, value)

    // Member values
    FxInterpInfoU255_c m_interpInfo;
DECL_CLASS_END()
CHECKSIZE(FxInfoColour_c, 0x18, 0x30);

DECL_CLASS_BASED(FxInfoDir_c, FxInfo_c)
    // Construct/Deconstruct functions
    DECL_CTORCALL(FxInfoDir_c, _ZN11FxInfoDir_cC2Ev);
    DECL_DTORCALL_VIRTUAL(FxInfoDir_c, _ZN11FxInfoDir_cD2Ev, _ZN11FxInfoDir_c, _ZTV11FxInfoDir_c);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(FxInfoDir_c, Load, _ZTV11FxInfoDir_c, 2, void, FILESTREAM file, i32 version)
    DECL_VIRTUALCALL_TAIL(file, version)
    DECL_VIRTUALCALL_HEAD(FxInfoDir_c, GetValue, _ZTV11FxInfoDir_c, 3, void, float currentTime, float particleTime, float deltaTime, float length, u8 useConst, void* value)
    DECL_VIRTUALCALL_TAIL(currentTime, particleTime, deltaTime, length, useConst, value)

    // Member values
    FxInterpInfoFloat_c m_interpInfo;
DECL_CLASS_END()
CHECKSIZE(FxInfoDir_c, 0x18, 0x30);

DECL_CLASS_BASED(FxInfoEmAngle_c, FxInfo_c)
    // Construct/Deconstruct functions
    DECL_CTORCALL(FxInfoEmAngle_c, _ZN15FxInfoEmAngle_cC2Ev);
    DECL_DTORCALL_VIRTUAL(FxInfoEmAngle_c, _ZN15FxInfoEmAngle_cD2Ev, _ZN15FxInfoEmAngle_c, _ZTV15FxInfoEmAngle_c);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(FxInfoEmAngle_c, Load, _ZTV15FxInfoEmAngle_c, 2, void, FILESTREAM file, i32 version)
    DECL_VIRTUALCALL_TAIL(file, version)
    DECL_VIRTUALCALL_HEAD(FxInfoEmAngle_c, GetValue, _ZTV15FxInfoEmAngle_c, 3, void, float currentTime, float particleTime, float deltaTime, float length, u8 useConst, void* value)
    DECL_VIRTUALCALL_TAIL(currentTime, particleTime, deltaTime, length, useConst, value)

    // Member values
    FxInterpInfoFloat_c m_interpInfo;
DECL_CLASS_END()
CHECKSIZE(FxInfoEmAngle_c, 0x18, 0x30);

DECL_CLASS_BASED(FxInfoEmDir_c, FxInfo_c)
    // Construct/Deconstruct functions
    DECL_CTORCALL(FxInfoEmDir_c, _ZN13FxInfoEmDir_cC2Ev);
    DECL_DTORCALL_VIRTUAL(FxInfoEmDir_c, _ZN13FxInfoEmDir_cD2Ev, _ZN13FxInfoEmDir_c, _ZTV13FxInfoEmDir_c);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(FxInfoEmDir_c, Load, _ZTV13FxInfoEmDir_c, 2, void, FILESTREAM file, i32 version)
    DECL_VIRTUALCALL_TAIL(file, version)
    DECL_VIRTUALCALL_HEAD(FxInfoEmDir_c, GetValue, _ZTV13FxInfoEmDir_c, 3, void, float currentTime, float particleTime, float deltaTime, float length, u8 useConst, void* value)
    DECL_VIRTUALCALL_TAIL(currentTime, particleTime, deltaTime, length, useConst, value)

    // Member values
    FxInterpInfo32_c m_interpInfo;
DECL_CLASS_END()
CHECKSIZE(FxInfoEmDir_c, 0x18, 0x30);

DECL_CLASS_BASED(FxInfoEmLife_c, FxInfo_c)
    // Construct/Deconstruct functions
    DECL_CTORCALL(FxInfoEmLife_c, _ZN14FxInfoEmLife_cC2Ev);
    DECL_DTORCALL_VIRTUAL(FxInfoEmLife_c, _ZN14FxInfoEmLife_cD2Ev, _ZN14FxInfoEmLife_c, _ZTV14FxInfoEmLife_c);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(FxInfoEmLife_c, Load, _ZTV14FxInfoEmLife_c, 2, void, FILESTREAM file, i32 version)
    DECL_VIRTUALCALL_TAIL(file, version)
    DECL_VIRTUALCALL_HEAD(FxInfoEmLife_c, GetValue, _ZTV14FxInfoEmLife_c, 3, void, float currentTime, float particleTime, float deltaTime, float length, u8 useConst, void* value)
    DECL_VIRTUALCALL_TAIL(currentTime, particleTime, deltaTime, length, useConst, value)

    // Member values
    FxInterpInfoU255_c m_interpInfo;
DECL_CLASS_END()
CHECKSIZE(FxInfoEmLife_c, 0x18, 0x30);

DECL_CLASS_BASED(FxInfoEmPos_c, FxInfo_c)
    // Construct/Deconstruct functions
    DECL_CTORCALL(FxInfoEmPos_c, _ZN13FxInfoEmPos_cC2Ev);
    DECL_DTORCALL_VIRTUAL(FxInfoEmPos_c, _ZN13FxInfoEmPos_cD2Ev, _ZN13FxInfoEmPos_c, _ZTV13FxInfoEmPos_c);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(FxInfoEmPos_c, Load, _ZTV13FxInfoEmPos_c, 2, void, FILESTREAM file, i32 version)
    DECL_VIRTUALCALL_TAIL(file, version)
    DECL_VIRTUALCALL_HEAD(FxInfoEmPos_c, GetValue, _ZTV13FxInfoEmPos_c, 3, void, float currentTime, float particleTime, float deltaTime, float length, u8 useConst, void* value)
    DECL_VIRTUALCALL_TAIL(currentTime, particleTime, deltaTime, length, useConst, value)

    // Member values
    FxInterpInfoFloat_c m_interpInfo;
DECL_CLASS_END()
CHECKSIZE(FxInfoEmPos_c, 0x18, 0x30);

DECL_CLASS_BASED(FxInfoEmRate_c, FxInfo_c)
    // Construct/Deconstruct functions
    DECL_CTORCALL(FxInfoEmRate_c, _ZN14FxInfoEmRate_cC2Ev);
    DECL_DTORCALL_VIRTUAL(FxInfoEmRate_c, _ZN14FxInfoEmRate_cD2Ev, _ZN14FxInfoEmRate_c, _ZTV14FxInfoEmRate_c);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(FxInfoEmRate_c, Load, _ZTV14FxInfoEmRate_c, 2, void, FILESTREAM file, i32 version)
    DECL_VIRTUALCALL_TAIL(file, version)
    DECL_VIRTUALCALL_HEAD(FxInfoEmRate_c, GetValue, _ZTV14FxInfoEmRate_c, 3, void, float currentTime, float particleTime, float deltaTime, float length, u8 useConst, void* value)
    DECL_VIRTUALCALL_TAIL(currentTime, particleTime, deltaTime, length, useConst, value)

    // Member values
    FxInterpInfoFloat_c m_interpInfo;
DECL_CLASS_END()
CHECKSIZE(FxInfoEmRate_c, 0x18, 0x30);

DECL_CLASS_BASED(FxInfoEmRotation_c, FxInfo_c)
    // Construct/Deconstruct functions
    DECL_CTORCALL(FxInfoEmRotation_c, _ZN18FxInfoEmRotation_cC2Ev);
    DECL_DTORCALL_VIRTUAL(FxInfoEmRotation_c, _ZN18FxInfoEmRotation_cD2Ev, _ZN18FxInfoEmRotation_c, _ZTV18FxInfoEmRotation_c);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(FxInfoEmRotation_c, Load, _ZTV18FxInfoEmRotation_c, 2, void, FILESTREAM file, i32 version)
    DECL_VIRTUALCALL_TAIL(file, version)
    DECL_VIRTUALCALL_HEAD(FxInfoEmRotation_c, GetValue, _ZTV18FxInfoEmRotation_c, 3, void, float currentTime, float particleTime, float deltaTime, float length, u8 useConst, void* value)
    DECL_VIRTUALCALL_TAIL(currentTime, particleTime, deltaTime, length, useConst, value)

    // Member values
    FxInterpInfoFloat_c m_interpInfo;
DECL_CLASS_END()
CHECKSIZE(FxInfoEmRotation_c, 0x18, 0x30);

DECL_CLASS_BASED(FxInfoEmSize_c, FxInfo_c)
    // Construct/Deconstruct functions
    DECL_CTORCALL(FxInfoEmSize_c, _ZN14FxInfoEmSize_cC2Ev);
    DECL_DTORCALL_VIRTUAL(FxInfoEmSize_c, _ZN14FxInfoEmSize_cD2Ev, _ZN14FxInfoEmSize_c, _ZTV14FxInfoEmSize_c);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(FxInfoEmSize_c, Load, _ZTV14FxInfoEmSize_c, 2, void, FILESTREAM file, i32 version)
    DECL_VIRTUALCALL_TAIL(file, version)
    DECL_VIRTUALCALL_HEAD(FxInfoEmSize_c, GetValue, _ZTV14FxInfoEmSize_c, 3, void, float currentTime, float particleTime, float deltaTime, float length, u8 useConst, void* value)
    DECL_VIRTUALCALL_TAIL(currentTime, particleTime, deltaTime, length, useConst, value)

    // Member values
    FxInterpInfo32_c m_interpInfo;
DECL_CLASS_END()
CHECKSIZE(FxInfoEmSize_c, 0x18, 0x30);

DECL_CLASS_BASED(FxInfoEmSpeed_c, FxInfo_c)
    // Construct/Deconstruct functions
    DECL_CTORCALL(FxInfoEmSpeed_c, _ZN15FxInfoEmSpeed_cC2Ev);
    DECL_DTORCALL_VIRTUAL(FxInfoEmSpeed_c, _ZN15FxInfoEmSpeed_cD2Ev, _ZN15FxInfoEmSpeed_c, _ZTV15FxInfoEmSpeed_c);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(FxInfoEmSpeed_c, Load, _ZTV15FxInfoEmSpeed_c, 2, void, FILESTREAM file, i32 version)
    DECL_VIRTUALCALL_TAIL(file, version)
    DECL_VIRTUALCALL_HEAD(FxInfoEmSpeed_c, GetValue, _ZTV15FxInfoEmSpeed_c, 3, void, float currentTime, float particleTime, float deltaTime, float length, u8 useConst, void* value)
    DECL_VIRTUALCALL_TAIL(currentTime, particleTime, deltaTime, length, useConst, value)

    // Member values
    FxInterpInfo32_c m_interpInfo;
DECL_CLASS_END()
CHECKSIZE(FxInfoEmSpeed_c, 0x18, 0x30);

DECL_CLASS_BASED(FxInfoEmWeather_c, FxInfo_c)
    // Construct/Deconstruct functions
    DECL_CTORCALL(FxInfoEmWeather_c, _ZN17FxInfoEmWeather_cC2Ev);
    DECL_DTORCALL_VIRTUAL(FxInfoEmWeather_c, _ZN17FxInfoEmWeather_cD2Ev, _ZN17FxInfoEmWeather_c, _ZTV17FxInfoEmWeather_c);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(FxInfoEmWeather_c, Load, _ZTV17FxInfoEmWeather_c, 2, void, FILESTREAM file, i32 version)
    DECL_VIRTUALCALL_TAIL(file, version)
    DECL_VIRTUALCALL_HEAD(FxInfoEmWeather_c, GetValue, _ZTV17FxInfoEmWeather_c, 3, void, float currentTime, float particleTime, float deltaTime, float length, u8 useConst, void* value)
    DECL_VIRTUALCALL_TAIL(currentTime, particleTime, deltaTime, length, useConst, value)

    // Member values
    FxInterpInfoFloat_c m_interpInfo;
DECL_CLASS_END()
CHECKSIZE(FxInfoEmWeather_c, 0x18, 0x30);

DECL_CLASS_BASED(FxInfoFlat_c, FxInfo_c)
    // Construct/Deconstruct functions
    DECL_CTORCALL(FxInfoFlat_c, _ZN12FxInfoFlat_cC2Ev);
    DECL_DTORCALL_VIRTUAL(FxInfoFlat_c, _ZN12FxInfoFlat_cD2Ev, _ZN12FxInfoFlat_c, _ZTV12FxInfoFlat_c);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(FxInfoFlat_c, Load, _ZTV12FxInfoFlat_c, 2, void, FILESTREAM file, i32 version)
    DECL_VIRTUALCALL_TAIL(file, version)
    DECL_VIRTUALCALL_HEAD(FxInfoFlat_c, GetValue, _ZTV12FxInfoFlat_c, 3, void, float currentTime, float particleTime, float deltaTime, float length, u8 useConst, void* value)
    DECL_VIRTUALCALL_TAIL(currentTime, particleTime, deltaTime, length, useConst, value)

    // Member values
    FxInterpInfoFloat_c m_interpInfo;
DECL_CLASS_END()
CHECKSIZE(FxInfoFlat_c, 0x18, 0x30);

DECL_CLASS_BASED(FxInfoFloat_c, FxInfo_c)
    // Construct/Deconstruct functions
    DECL_CTORCALL(FxInfoFloat_c, _ZN13FxInfoFloat_cC2Ev);
    DECL_DTORCALL_VIRTUAL(FxInfoFloat_c, _ZN13FxInfoFloat_cD2Ev, _ZN13FxInfoFloat_c, _ZTV13FxInfoFloat_c);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(FxInfoFloat_c, Load, _ZTV13FxInfoFloat_c, 2, void, FILESTREAM file, i32 version)
    DECL_VIRTUALCALL_TAIL(file, version)
    DECL_VIRTUALCALL_HEAD(FxInfoFloat_c, GetValue, _ZTV13FxInfoFloat_c, 3, void, float currentTime, float particleTime, float deltaTime, float length, u8 useConst, void* value)
    DECL_VIRTUALCALL_TAIL(currentTime, particleTime, deltaTime, length, useConst, value)

    // Member values
    FxInterpInfoFloat_c m_interpInfo;
DECL_CLASS_END()
CHECKSIZE(FxInfoFloat_c, 0x18, 0x30);

DECL_CLASS_BASED(FxInfoForce_c, FxInfo_c)
    // Construct/Deconstruct functions
    DECL_CTORCALL(FxInfoForce_c, _ZN13FxInfoForce_cC2Ev);
    DECL_DTORCALL_VIRTUAL(FxInfoForce_c, _ZN13FxInfoForce_cD2Ev, _ZN13FxInfoForce_c, _ZTV13FxInfoForce_c);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(FxInfoForce_c, Load, _ZTV13FxInfoForce_c, 2, void, FILESTREAM file, i32 version)
    DECL_VIRTUALCALL_TAIL(file, version)
    DECL_VIRTUALCALL_HEAD(FxInfoForce_c, GetValue, _ZTV13FxInfoForce_c, 3, void, float currentTime, float particleTime, float deltaTime, float length, u8 useConst, void* value)
    DECL_VIRTUALCALL_TAIL(currentTime, particleTime, deltaTime, length, useConst, value)

    // Member values
    FxInterpInfo32_c m_interpInfo;
DECL_CLASS_END()
CHECKSIZE(FxInfoForce_c, 0x18, 0x30);

DECL_CLASS_BASED(FxInfoFriction_c, FxInfo_c)
    // Construct/Deconstruct functions
    DECL_CTORCALL(FxInfoFriction_c, _ZN16FxInfoFriction_cC2Ev);
    DECL_DTORCALL_VIRTUAL(FxInfoFriction_c, _ZN16FxInfoFriction_cD2Ev, _ZN16FxInfoFriction_c, _ZTV16FxInfoFriction_c);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(FxInfoFriction_c, Load, _ZTV16FxInfoFriction_c, 2, void, FILESTREAM file, i32 version)
    DECL_VIRTUALCALL_TAIL(file, version)
    DECL_VIRTUALCALL_HEAD(FxInfoFriction_c, GetValue, _ZTV16FxInfoFriction_c, 3, void, float currentTime, float particleTime, float deltaTime, float length, u8 useConst, void* value)
    DECL_VIRTUALCALL_TAIL(currentTime, particleTime, deltaTime, length, useConst, value)

    // Member values
    FxInterpInfo32_c m_interpInfo;
DECL_CLASS_END()
CHECKSIZE(FxInfoFriction_c, 0x18, 0x30);

DECL_CLASS_BASED(FxInfoGroundCollide_c, FxInfo_c)
    // Construct/Deconstruct functions
    DECL_CTORCALL(FxInfoGroundCollide_c, _ZN21FxInfoGroundCollide_cC2Ev);
    DECL_DTORCALL_VIRTUAL(FxInfoGroundCollide_c, _ZN21FxInfoGroundCollide_cD2Ev, _ZN21FxInfoGroundCollide_c, _ZTV21FxInfoGroundCollide_c);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(FxInfoGroundCollide_c, Load, _ZTV21FxInfoGroundCollide_c, 2, void, FILESTREAM file, i32 version)
    DECL_VIRTUALCALL_TAIL(file, version)
    DECL_VIRTUALCALL_HEAD(FxInfoGroundCollide_c, GetValue, _ZTV21FxInfoGroundCollide_c, 3, void, float currentTime, float particleTime, float deltaTime, float length, u8 useConst, void* value)
    DECL_VIRTUALCALL_TAIL(currentTime, particleTime, deltaTime, length, useConst, value)

    // Member values
    FxInterpInfo32_c m_interpInfo;
DECL_CLASS_END()
CHECKSIZE(FxInfoGroundCollide_c, 0x18, 0x30);

DECL_CLASS_BASED(FxInfoHeatHaze_c, FxInfo_c)
    // Construct/Deconstruct functions
    DECL_CTORCALL(FxInfoHeatHaze_c, _ZN16FxInfoHeatHaze_cC2Ev);
    DECL_DTORCALL_VIRTUAL(FxInfoHeatHaze_c, _ZN16FxInfoHeatHaze_cD2Ev, _ZN16FxInfoHeatHaze_c, _ZTV16FxInfoHeatHaze_c);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(FxInfoHeatHaze_c, Load, _ZTV16FxInfoHeatHaze_c, 2, void, FILESTREAM file, i32 version)
    DECL_VIRTUALCALL_TAIL(file, version)
    DECL_VIRTUALCALL_HEAD(FxInfoHeatHaze_c, GetValue, _ZTV16FxInfoHeatHaze_c, 3, void, float currentTime, float particleTime, float deltaTime, float length, u8 useConst, void* value)
    DECL_VIRTUALCALL_TAIL(currentTime, particleTime, deltaTime, length, useConst, value)

    // Member values
    FxInterpInfo255_c m_interpInfo;
DECL_CLASS_END()
CHECKSIZE(FxInfoHeatHaze_c, 0x18, 0x30);

DECL_CLASS_BASED(FxInfoJitter_c, FxInfo_c)
    // Construct/Deconstruct functions
    DECL_CTORCALL(FxInfoJitter_c, _ZN14FxInfoJitter_cC2Ev);
    DECL_DTORCALL_VIRTUAL(FxInfoJitter_c, _ZN14FxInfoJitter_cD2Ev, _ZN14FxInfoJitter_c, _ZTV14FxInfoJitter_c);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(FxInfoJitter_c, Load, _ZTV14FxInfoJitter_c, 2, void, FILESTREAM file, i32 version)
    DECL_VIRTUALCALL_TAIL(file, version)
    DECL_VIRTUALCALL_HEAD(FxInfoJitter_c, GetValue, _ZTV14FxInfoJitter_c, 3, void, float currentTime, float particleTime, float deltaTime, float length, u8 useConst, void* value)
    DECL_VIRTUALCALL_TAIL(currentTime, particleTime, deltaTime, length, useConst, value)

    // Member values
    FxInterpInfo32_c m_interpInfo;
DECL_CLASS_END()
CHECKSIZE(FxInfoJitter_c, 0x18, 0x30);

DECL_CLASS_BASED(FxInfoNoise_c, FxInfo_c)
    // Construct/Deconstruct functions
    DECL_CTORCALL(FxInfoNoise_c, _ZN13FxInfoNoise_cC2Ev);
    DECL_DTORCALL_VIRTUAL(FxInfoNoise_c, _ZN13FxInfoNoise_cD2Ev, _ZN13FxInfoNoise_c, _ZTV13FxInfoNoise_c);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(FxInfoNoise_c, Load, _ZTV13FxInfoNoise_c, 2, void, FILESTREAM file, i32 version)
    DECL_VIRTUALCALL_TAIL(file, version)
    DECL_VIRTUALCALL_HEAD(FxInfoNoise_c, GetValue, _ZTV13FxInfoNoise_c, 3, void, float currentTime, float particleTime, float deltaTime, float length, u8 useConst, void* value)
    DECL_VIRTUALCALL_TAIL(currentTime, particleTime, deltaTime, length, useConst, value)

    // Member values
    FxInterpInfo32_c m_interpInfo;
DECL_CLASS_END()
CHECKSIZE(FxInfoNoise_c, 0x18, 0x30);

DECL_CLASS_BASED(FxInfoRotSpeed_c, FxInfo_c)
    // Construct/Deconstruct functions
    DECL_CTORCALL(FxInfoRotSpeed_c, _ZN16FxInfoRotSpeed_cC2Ev);
    DECL_DTORCALL_VIRTUAL(FxInfoRotSpeed_c, _ZN16FxInfoRotSpeed_cD2Ev, _ZN16FxInfoRotSpeed_c, _ZTV16FxInfoRotSpeed_c);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(FxInfoRotSpeed_c, Load, _ZTV16FxInfoRotSpeed_c, 2, void, FILESTREAM file, i32 version)
    DECL_VIRTUALCALL_TAIL(file, version)
    DECL_VIRTUALCALL_HEAD(FxInfoRotSpeed_c, GetValue, _ZTV16FxInfoRotSpeed_c, 3, void, float currentTime, float particleTime, float deltaTime, float length, u8 useConst, void* value)
    DECL_VIRTUALCALL_TAIL(currentTime, particleTime, deltaTime, length, useConst, value)

    // Member values
    FxInterpInfoFloat_c m_interpInfo;
DECL_CLASS_END()
CHECKSIZE(FxInfoRotSpeed_c, 0x18, 0x30);

DECL_CLASS_BASED(FxInfoSelfLit_c, FxInfo_c)
    // Construct/Deconstruct functions
    DECL_CTORCALL(FxInfoSelfLit_c, _ZN15FxInfoSelfLit_cC2Ev);
    DECL_DTORCALL_VIRTUAL(FxInfoSelfLit_c, _ZN15FxInfoSelfLit_cD2Ev, _ZN15FxInfoSelfLit_c, _ZTV15FxInfoSelfLit_c);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(FxInfoSelfLit_c, Load, _ZTV15FxInfoSelfLit_c, 2, void, FILESTREAM file, i32 version)
    DECL_VIRTUALCALL_TAIL(file, version)
    DECL_VIRTUALCALL_HEAD(FxInfoSelfLit_c, GetValue, _ZTV15FxInfoSelfLit_c, 3, void, float currentTime, float particleTime, float deltaTime, float length, u8 useConst, void* value)
    DECL_VIRTUALCALL_TAIL(currentTime, particleTime, deltaTime, length, useConst, value)

    // Member values
    FxInterpInfoU255_c m_interpInfo;
DECL_CLASS_END()
CHECKSIZE(FxInfoSelfLit_c, 0x18, 0x30);

DECL_CLASS_BASED(FxInfoSize_c, FxInfo_c)
    // Construct/Deconstruct functions
    DECL_CTORCALL(FxInfoSize_c, _ZN12FxInfoSize_cC2Ev);
    DECL_DTORCALL_VIRTUAL(FxInfoSize_c, _ZN12FxInfoSize_cD2Ev, _ZN12FxInfoSize_c, _ZTV12FxInfoSize_c);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(FxInfoSize_c, Load, _ZTV12FxInfoSize_c, 2, void, FILESTREAM file, i32 version)
    DECL_VIRTUALCALL_TAIL(file, version)
    DECL_VIRTUALCALL_HEAD(FxInfoSize_c, GetValue, _ZTV12FxInfoSize_c, 3, void, float currentTime, float particleTime, float deltaTime, float length, u8 useConst, void* value)
    DECL_VIRTUALCALL_TAIL(currentTime, particleTime, deltaTime, length, useConst, value)

    // Member values
    FxInterpInfo32_c m_interpInfo;
DECL_CLASS_END()
CHECKSIZE(FxInfoSize_c, 0x18, 0x30);

DECL_CLASS_BASED(FxInfoSmoke_c, FxInfo_c)
    // Construct/Deconstruct functions
    DECL_CTORCALL(FxInfoSmoke_c, _ZN13FxInfoSmoke_cC2Ev);
    DECL_DTORCALL_VIRTUAL(FxInfoSmoke_c, _ZN13FxInfoSmoke_cD2Ev, _ZN13FxInfoSmoke_c, _ZTV13FxInfoSmoke_c);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(FxInfoSmoke_c, Load, _ZTV13FxInfoSmoke_c, 2, void, FILESTREAM file, i32 version)
    DECL_VIRTUALCALL_TAIL(file, version)
    DECL_VIRTUALCALL_HEAD(FxInfoSmoke_c, GetValue, _ZTV13FxInfoSmoke_c, 3, void, float currentTime, float particleTime, float deltaTime, float length, u8 useConst, void* value)
    DECL_VIRTUALCALL_TAIL(currentTime, particleTime, deltaTime, length, useConst, value)

    // Member values
    FxInterpInfoU255_c m_interpInfo;
DECL_CLASS_END()
CHECKSIZE(FxInfoSmoke_c, 0x18, 0x30);

DECL_CLASS_BASED(FxInfoSpriteRect_c, FxInfo_c)
    // Construct/Deconstruct functions
    DECL_CTORCALL(FxInfoSpriteRect_c, _ZN18FxInfoSpriteRect_cC2Ev);
    DECL_DTORCALL_VIRTUAL(FxInfoSpriteRect_c, _ZN18FxInfoSpriteRect_cD2Ev, _ZN18FxInfoSpriteRect_c, _ZTV18FxInfoSpriteRect_c);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(FxInfoSpriteRect_c, Load, _ZTV18FxInfoSpriteRect_c, 2, void, FILESTREAM file, i32 version)
    DECL_VIRTUALCALL_TAIL(file, version)
    DECL_VIRTUALCALL_HEAD(FxInfoSpriteRect_c, GetValue, _ZTV18FxInfoSpriteRect_c, 3, void, float currentTime, float particleTime, float deltaTime, float length, u8 useConst, void* value)
    DECL_VIRTUALCALL_TAIL(currentTime, particleTime, deltaTime, length, useConst, value)

    // Member values
    FxInterpInfo255_c m_interpInfo;
DECL_CLASS_END()
CHECKSIZE(FxInfoSpriteRect_c, 0x18, 0x30);

DECL_CLASS_BASED(FxInfoTrail_c, FxInfo_c)
    // Construct/Deconstruct functions
    DECL_CTORCALL(FxInfoTrail_c, _ZN13FxInfoTrail_cC2Ev);
    DECL_DTORCALL_VIRTUAL(FxInfoTrail_c, _ZN13FxInfoTrail_cD2Ev, _ZN13FxInfoTrail_c, _ZTV13FxInfoTrail_c);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(FxInfoTrail_c, Load, _ZTV13FxInfoTrail_c, 2, void, FILESTREAM file, i32 version)
    DECL_VIRTUALCALL_TAIL(file, version)
    DECL_VIRTUALCALL_HEAD(FxInfoTrail_c, GetValue, _ZTV13FxInfoTrail_c, 3, void, float currentTime, float particleTime, float deltaTime, float length, u8 useConst, void* value)
    DECL_VIRTUALCALL_TAIL(currentTime, particleTime, deltaTime, length, useConst, value)

    // Member values
    FxInterpInfoU255_c m_interpInfo;
DECL_CLASS_END()
CHECKSIZE(FxInfoTrail_c, 0x18, 0x30);

DECL_CLASS_BASED(FxInfoUnderwater_c, FxInfo_c)
    // Construct/Deconstruct functions
    DECL_CTORCALL(FxInfoUnderwater_c, _ZN18FxInfoUnderwater_cC2Ev);
    DECL_DTORCALL_VIRTUAL(FxInfoUnderwater_c, _ZN18FxInfoUnderwater_cD2Ev, _ZN18FxInfoUnderwater_c, _ZTV18FxInfoUnderwater_c);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(FxInfoUnderwater_c, Load, _ZTV18FxInfoUnderwater_c, 2, void, FILESTREAM file, i32 version)
    DECL_VIRTUALCALL_TAIL(file, version)
    DECL_VIRTUALCALL_HEAD(FxInfoUnderwater_c, GetValue, _ZTV18FxInfoUnderwater_c, 3, void, float currentTime, float particleTime, float deltaTime, float length, u8 useConst, void* value)
    DECL_VIRTUALCALL_TAIL(currentTime, particleTime, deltaTime, length, useConst, value)

    // Member values
    FxInterpInfoU255_c m_interpInfo;
DECL_CLASS_END()
CHECKSIZE(FxInfoUnderwater_c, 0x18, 0x30);

DECL_CLASS_BASED(FxInfoWind_c, FxInfo_c)
    // Construct/Deconstruct functions
    DECL_CTORCALL(FxInfoWind_c, _ZN12FxInfoWind_cC2Ev);
    DECL_DTORCALL_VIRTUAL(FxInfoWind_c, _ZN12FxInfoWind_cD2Ev, _ZN12FxInfoWind_c, _ZTV12FxInfoWind_c);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(FxInfoWind_c, Load, _ZTV12FxInfoWind_c, 2, void, FILESTREAM file, i32 version)
    DECL_VIRTUALCALL_TAIL(file, version)
    DECL_VIRTUALCALL_HEAD(FxInfoWind_c, GetValue, _ZTV12FxInfoWind_c, 3, void, float currentTime, float particleTime, float deltaTime, float length, u8 useConst, void* value)
    DECL_VIRTUALCALL_TAIL(currentTime, particleTime, deltaTime, length, useConst, value)

    // Member values
    FxInterpInfo32_c m_interpInfo;
DECL_CLASS_END()
CHECKSIZE(FxInfoWind_c, 0x18, 0x30);

#endif // __AML_PSDK_SAFXINFO_H
