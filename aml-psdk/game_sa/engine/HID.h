#ifndef __AML_PSDK_SAHID_H
#define __AML_PSDK_SAHID_H

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/game_sa/enum/HID.h>
#include <aml-psdk/game_sa/base/Lists.h>
#include <aml-psdk/game_sa/engine/OS.h>

enum HIDInputType : i32
{
    HID_INPUT_TYPE_TOUCH                       = 0x0,
    HID_INPUT_TYPE_JOYPAD                      = 0x1,
    HID_INPUT_TYPE_KEYBOARD                    = 0x2,
    NUM_HID_INPUT_TYPES                        = 0x3,
};

struct MappingPair
{
    HIDMapping                         m_Mapping;
    char                               m_szMapping[128];
};
CHECKSIZE(MappingPair, 0x84, 0x84);  // 64-bit from the IDB; 32-bit measured from this layout

struct CSprite2d;
struct CVector2D;

DECL_CLASS(CHID)
    // Member values
    void*                              __vftable;

    // Functions
    DECL_CTORCALL(CHID, _ZN4CHIDC2Ev);
    DECL_DTORCALL(CHID, _ZN4CHIDD2Ev);
    DECL_FASTCALL_SIMPLE(GetMappingByName, _ZN4CHID16GetMappingByNameEPKc, HIDMapping, const char* pszMapping);
    DECL_FASTCALL_SIMPLE(Implements, _ZN4CHID10ImplementsE10HIDMapping, bool, HIDMapping Mapping);
    DECL_FASTCALL_SIMPLE(Replaces, _ZN4CHID8ReplacesE10HIDMapping, bool, HIDMapping Mapping);
    DECL_FASTCALL_SIMPLE(IsDoubleTapped, _ZN4CHID14IsDoubleTappedE10HIDMapping, bool, HIDMapping Mapping);
    DECL_FASTCALL_SIMPLE(Use360ClassicVitalStatsHack, _ZN4CHID27Use360ClassicVitalStatsHackEv, bool);
    DECL_FASTCALL_SIMPLE(Update, _ZN4CHID6UpdateEv, void);
    DECL_FASTCALL_SIMPLE(IsJustPressed, _ZN4CHID13IsJustPressedE10HIDMapping, bool, HIDMapping Mapping);
    DECL_FASTCALL_SIMPLE(IsPressed, _ZN4CHID9IsPressedE10HIDMappingPf, bool, HIDMapping Mapping, float* pfValueOut);
    DECL_FASTCALL_SIMPLE(IsReleased, _ZN4CHID10IsReleasedE10HIDMapping, bool, HIDMapping Mapping);
    DECL_FASTCALL_SIMPLE(GetMappingWeight, _ZN4CHID16GetMappingWeightE10HIDMapping, float, HIDMapping Mapping);
    DECL_FASTCALL_SIMPLE(IsReleasedPositive, _ZN4CHID18IsReleasedPositiveE10HIDMapping, bool, HIDMapping Mapping);
    DECL_FASTCALL_SIMPLE(IsReleasedNegative, _ZN4CHID18IsReleasedNegativeE10HIDMapping, bool, HIDMapping Mapping);
    DECL_FASTCALL_SIMPLE(IsPressedPositive, _ZN4CHID17IsPressedPositiveE10HIDMapping, bool, HIDMapping Mapping);
    DECL_FASTCALL_SIMPLE(IsPressedNegative, _ZN4CHID17IsPressedNegativeE10HIDMapping, bool, HIDMapping Mapping);
    DECL_FASTCALL_SIMPLE(MappingIsAnalog, _ZN4CHID15MappingIsAnalogE10HIDMapping, bool, HIDMapping Mapping);
    DECL_FASTCALL_SIMPLE(DrawHelpIcon, _ZN4CHID12DrawHelpIconEPKc10HIDMappingfffib, void, const char* pszCharacters, HIDMapping Mapping, float fX, float fY, float fHeight, int nAlpha, bool bNegated);
    DECL_FASTCALL_SIMPLE(GetHelpSprite, _ZN4CHID13GetHelpSpriteEPKc10HIDMappingP9CVector2DS4_, CSprite2d*, const char* pszCharacters, HIDMapping Mapping, CVector2D* pvecUVLeftTop, CVector2D* pvecUVRightBottom);
    DECL_FASTCALL_SIMPLE(FlushQueuedText, _ZN4CHID15FlushQueuedTextEv, void);
    DECL_FASTCALL_SIMPLE(RemoveQueuedText, _ZN4CHID16RemoveQueuedTextEv, void);
    DECL_FASTCALL_SIMPLE(CheckForInputChange, _ZN4CHID19CheckForInputChangeEv, void);
    DECL_FASTCALL_SIMPLE(GetInputType, _ZN4CHID12GetInputTypeEv, HIDInputType);
    DECL_THISCALL_HEAD(InternalCacheAnalogValues, _ZN4CHID25InternalCacheAnalogValuesEj, void, u32 gamepadIndex)
    DECL_THISCALL_TAIL(InternalCacheAnalogValues, gamepadIndex)
    DECL_THISCALL_HEAD(InternalDrawHelpIcon, _ZN4CHID20InternalDrawHelpIconEPKc10HIDMappingfffib, void, const char* pszCharacters, HIDMapping Mapping, float fX, float fY, float fHeight, int nAlpha, bool bNegated)
    DECL_THISCALL_TAIL(InternalDrawHelpIcon, pszCharacters, Mapping, fX, fY, fHeight, nAlpha, bNegated)
    DECL_THISCALL_HEAD(InternalGetHelpSprite, _ZN4CHID21InternalGetHelpSpriteEPKc10HIDMappingP9CVector2DS4_, CSprite2d*, const char* pszCharacters, HIDMapping Mapping, CVector2D* pvecUVLeftTop, CVector2D* pvecUVRightBottom)
    DECL_THISCALL_TAIL(InternalGetHelpSprite, pszCharacters, Mapping, pvecUVLeftTop, pvecUVRightBottom)
    DECL_THISCALL_HEAD(InternalIsReleasedPositive, _ZN4CHID26InternalIsReleasedPositiveE10HIDMapping, bool, HIDMapping Mapping)
    DECL_THISCALL_TAIL(InternalIsReleasedPositive, Mapping)
    DECL_THISCALL_HEAD(InternalIsReleasedNegative, _ZN4CHID26InternalIsReleasedNegativeE10HIDMapping, bool, HIDMapping Mapping)
    DECL_THISCALL_TAIL(InternalIsReleasedNegative, Mapping)
    DECL_THISCALL_HEAD(InternalIsPressedPositive, _ZN4CHID25InternalIsPressedPositiveE10HIDMapping, bool, HIDMapping Mapping)
    DECL_THISCALL_TAIL(InternalIsPressedPositive, Mapping)
    DECL_THISCALL_HEAD(InternalIsPressedNegative, _ZN4CHID25InternalIsPressedNegativeE10HIDMapping, bool, HIDMapping Mapping)
    DECL_THISCALL_TAIL(InternalIsPressedNegative, Mapping)
    DECL_THISCALL_HEAD(InternalMappingIsAnalog, _ZN4CHID23InternalMappingIsAnalogE10HIDMapping, bool, HIDMapping Mapping)
    DECL_THISCALL_TAIL(InternalMappingIsAnalog, Mapping)
    DECL_THISCALL_HEAD(InternalGetMappingWeight, _ZN4CHID24InternalGetMappingWeightE10HIDMapping, float, HIDMapping Mapping)
    DECL_THISCALL_TAIL(InternalGetMappingWeight, Mapping)
    DECL_THISCALL_SIMPLE(InternalFlushQueuedText, _ZN4CHID23InternalFlushQueuedTextEv, void);
    DECL_THISCALL_SIMPLE(InternalRemoveQueuedText, _ZN4CHID24InternalRemoveQueuedTextEv, void);
    DECL_THISCALL_SIMPLE(InternalUpdate, _ZN4CHID14InternalUpdateEv, void);

    // Static values
    DECL_OBJECT_ARRAY_PLT(OSGamepadType, m_GamepadType, BYBIT(0x6775DC, 0x84CBE8));
    DECL_VALUE_PLT_BOOL(bAllowKeyboardInstance, BYBIT(0x675FE0, 0x84A030));
    DECL_OBJECT_ARRAY_PLT(CHID*, m_pInstance, BYBIT(0x6768C8, 0x84B1E8));
    DECL_VALUE_PLT_I32(m_nDeadFrames, BYBIT(0x679C04, 0x851820));
    DECL_OBJECT_PLT(OSArray<MappingPair>, m_MappingPairs, BYBIT(0x677AFC, 0x84D620));
    DECL_VALUE_PLT_I32(currentInstanceIndex, BYBIT(0x679994, 0x851340));
DECL_CLASS_END()
CHECKSIZE(CHID, 0x4, 0x8);  // 64-bit from the IDB; 32-bit measured from this layout

#define m_GamepadType m_GamepadType()
#define bAllowKeyboardInstance bAllowKeyboardInstance()
#define m_pInstance m_pInstance()
#define m_nDeadFrames m_nDeadFrames()
#define m_MappingPairs m_MappingPairs()
#define currentInstanceIndex currentInstanceIndex()

#endif // __AML_PSDK_SAHID_H
