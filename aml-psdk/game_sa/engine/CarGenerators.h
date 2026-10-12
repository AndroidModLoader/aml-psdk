#ifndef __AML_PSDK_SACARGENERATORS_H
#define __AML_PSDK_SACARGENERATORS_H

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/gta_base/Vector.h>

struct tCarGenPlateText
{
    i32                                m_nCarGenId;
    char                               m_szPlateText[9];
};
CHECKSIZE(tCarGenPlateText, 0x10, 0x10);

DECL_CLASS(CSpecialPlateHandler)
    enum : i32
    {
        MAX_SPECIAL_PLATES             = 15,
    };

    tCarGenPlateText                    m_plateTextEntries[MAX_SPECIAL_PLATES];
    i32                                m_nCount;

    // Functions
    DECL_THISCALL_SIMPLE(Init, _ZN20CSpecialPlateHandler4InitEv, void);
    DECL_THISCALL(Find, _ZN20CSpecialPlateHandler4FindEiPc, i32, i32 carGenId, char* outText);
    DECL_THISCALL(Add, _ZN20CSpecialPlateHandler3AddEiPc, void, i32 carGenId, char* plateText);
    DECL_THISCALL(Remove, _ZN20CSpecialPlateHandler6RemoveEi, void, i32 plateTextId);
DECL_CLASS_END()
CHECKSIZE(CSpecialPlateHandler, 0xF4, 0xF4);

DECL_CLASS(CCarGenerator)
    i16                                m_nModelId;
    u8                                 m_nColor1;
    u8                                 m_nColor2;
    CompressedVector                   m_vecPosn;
    u8                                 m_nAngle;
    u8                                 m_nAlarm;
    u8                                 m_nDoorLock;
    union
    {
        struct
        {
            u8 bWaitUntilFarFromPlayer : 1;
            u8 bHighPriority : 1;
            u8 bActive : 1;
            u8 bPlayerHasAlreadyOwnedCar : 1;
            u8 bIgnorePopulationLimit : 1;
        };
        u8                             m_nFlags;
    };
    u16                                m_nMinDelay;
    u16                                m_nMaxDelay;
    u32                                m_nNextGenTime;
    i16                                m_nVehicleHandle;
    u16                                m_nGenerateCount;
    u8                                 m_nIplId;
    u8                                 m_bIsUsed;

    // Functions
    DECL_THISCALL_SIMPLE(CalcNextGen, _ZN13CCarGenerator11CalcNextGenEv, u32);
    DECL_THISCALL(CheckForBlockage, _ZN13CCarGenerator16CheckForBlockageEi, u8, i32 modelId);
    DECL_THISCALL_SIMPLE(CheckIfWithinRangeOfAnyPlayers, _ZN13CCarGenerator30CheckIfWithinRangeOfAnyPlayersEv, u8);
    DECL_THISCALL(Setup, _ZN13CCarGenerator5SetupEffffisshhhtthh, void, float x, float y, float z, float angle, i32 modelId, i16 color1, i16 color2, u8 forceSpawn, u8 alarmChances, u8 doorLockChances, u16 minDelay, u16 maxDelay, u8 iplId, u8 bIgnorePopulationLimit);
    DECL_THISCALL_SIMPLE(SwitchOff, _ZN13CCarGenerator9SwitchOffEv, void);
    DECL_THISCALL_SIMPLE(SwitchOn, _ZN13CCarGenerator8SwitchOnEv, void);
    DECL_THISCALL_SIMPLE(Process, _ZN13CCarGenerator7ProcessEv, void);
    DECL_THISCALL_SIMPLE(DoInternalProcessing, _ZN13CCarGenerator20DoInternalProcessingEv, void);
DECL_CLASS_END()
CHECKSIZE(CCarGenerator, 0x20, 0x20);

DECL_CLASS(CTheCarGenerators)
    // Functions
    DECL_FASTCALL_SIMPLE(Init, _ZN17CTheCarGenerators4InitEv, void);
    DECL_FASTCALL_SIMPLE(CreateCarGenerator, _ZN17CTheCarGenerators18CreateCarGeneratorEffffisshhhtthh, i32, float x, float y, float z, float angle, i32 modelId, i16 color1, i16 color2, u8 forceSpawn, u8 alarmChances, u8 doorLockChances, u16 minDelay, u16 maxDelay, u8 iplId, u8 bIgnorePopulationLimit);
    DECL_FASTCALL_SIMPLE(RemoveCarGenerators, _ZN17CTheCarGenerators19RemoveCarGeneratorsEh, void, u8 iplId);
    DECL_FASTCALL_SIMPLE(Process, _ZN17CTheCarGenerators7ProcessEv, void);
    DECL_FASTCALL_SIMPLE(Save, _ZN17CTheCarGenerators4SaveEv, bool);
    DECL_FASTCALL_SIMPLE(Load, _ZN17CTheCarGenerators4LoadEv, bool);

    // Static values
    DECL_OBJECT_ARRAY_PLT(CCarGenerator, CarGeneratorArray, BYBIT(0x677640, 0x84CCB0));
    DECL_VALUE_PLT_I32(NumOfCarGenerators, BYBIT(0x679ACC, 0x8515B8));
    DECL_VALUE_PLT_U8(ProcessCounter, BYBIT(0x676B9C, 0x84B780));
    DECL_VALUE_PLT_U8(GenerateEvenIfPlayerIsCloseCounter, BYBIT(0x677950, 0x84D2C8));
    DECL_OBJECT_PLT(CSpecialPlateHandler, m_SpecialPlateHandler, BYBIT(0x677614, 0x84CC58));
DECL_CLASS_END()

#define CarGeneratorArray CarGeneratorArray()
#define NumOfCarGenerators NumOfCarGenerators()
#define ProcessCounter ProcessCounter()
#define GenerateEvenIfPlayerIsCloseCounter GenerateEvenIfPlayerIsCloseCounter()
#define m_SpecialPlateHandler m_SpecialPlateHandler()

#endif // __AML_PSDK_SACARGENERATORS_H
