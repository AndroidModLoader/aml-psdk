#ifndef __AML_PSDK_SAHID_H
#define __AML_PSDK_SAHID_H

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/game_sa/enum/HID.h>
#include <aml-psdk/game_sa/base/Lists.h>
#include <aml-psdk/game_sa/engine/OS.h>
#include <aml-psdk/game_sa/engine/Sprite2d.h>
#include <aml-psdk/gta_base/GxtChar.h>

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

enum MouseButtons : i32
{
    LEFT_MOUSE_BUTTON = 0,
    RIGHT_MOUSE_BUTTON = 1,
    MIDDLE_MOUSE_BUTTON = 2,
    MOUSE_WHEEL_FORWARD = 3,
    MOUSE_WHEEL_BACKWARD = 4,
    NUM_MOUSE_BUTTON_MAPPINGS = 5,
};

struct KeyboardButtonMapping
{
    OSKeyboardKey key;
    HIDMapping mapping;
    bool bNegate;
    MouseButtons MouseButton;
    float fLastReleaseTime;
};
CHECKSIZE(KeyboardButtonMapping, 0x14, 0x14);

struct JoystickButtonMapping
{
    i32 nButtonID;
    HIDMapping mapping;
    bool bAnalogPressedThisFrame;
    bool bAnalogReleasedThisFrame;
    float fLastAnalogValue;
    float fLastReleaseTime;
};
CHECKSIZE(JoystickButtonMapping, 0x14, 0x14);

struct QueuedText
{
    HIDMapping m_Mapping;
    float m_fX;
    float m_fY;
    float m_fHeight;
    i32 m_nAlpha;
    bool m_bNegated;
};
CHECKSIZE(QueuedText, 0x18, 0x18);

struct KeyPair
{
    OSKeyboardKey m_key;
    char m_szTag[8];
};
CHECKSIZE(KeyPair, 0xC, 0xC);

DECL_CLASS_BASED(CHIDKeyboard, CHID)
protected:
    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CHIDKeyboard, _ZN12CHIDKeyboardC2EPKc, char const* textureName)
    DECL_CTORCALL_ARG_TAIL(textureName)
public:
    DECL_DTORCALL(CHIDKeyboard, _ZN12CHIDKeyboardD2Ev);

    // Member functions
    DECL_THISCALL_HEAD(InternalCacheAnalogValues, _ZN12CHIDKeyboard25InternalCacheAnalogValuesEj, void, u32 gamepadIndex)
    DECL_THISCALL_TAIL(InternalCacheAnalogValues, gamepadIndex)
    DECL_THISCALL_HEAD(InternalImplements, _ZN12CHIDKeyboard18InternalImplementsE10HIDMapping, bool, HIDMapping mapping)
    DECL_THISCALL_TAIL(InternalImplements, mapping)
    DECL_THISCALL_HEAD(InternalReplaces, _ZN12CHIDKeyboard16InternalReplacesE10HIDMapping, bool, HIDMapping mapping)
    DECL_THISCALL_TAIL(InternalReplaces, mapping)
    DECL_THISCALL_HEAD(InternalIsDoubleTapped, _ZN12CHIDKeyboard22InternalIsDoubleTappedE10HIDMapping, bool, HIDMapping mapping)
    DECL_THISCALL_TAIL(InternalIsDoubleTapped, mapping)
    DECL_THISCALL_HEAD(InternalIsJustPressed, _ZN12CHIDKeyboard21InternalIsJustPressedE10HIDMapping, bool, HIDMapping mapping)
    DECL_THISCALL_TAIL(InternalIsJustPressed, mapping)
    DECL_THISCALL_HEAD(InternalIsPressed, _ZN12CHIDKeyboard17InternalIsPressedE10HIDMappingPf, bool, HIDMapping mapping, float* value)
    DECL_THISCALL_TAIL(InternalIsPressed, mapping, value)
    DECL_THISCALL_HEAD(InternalIsReleased, _ZN12CHIDKeyboard18InternalIsReleasedE10HIDMapping, bool, HIDMapping mapping)
    DECL_THISCALL_TAIL(InternalIsReleased, mapping)
    DECL_THISCALL_HEAD(InternalDrawHelpIcon, _ZN12CHIDKeyboard20InternalDrawHelpIconEPKc10HIDMappingfffib, void, char const* characters, HIDMapping mapping, float x, float y, float height, i32 alpha, bool negated)
    DECL_THISCALL_TAIL(InternalDrawHelpIcon, characters, mapping, x, y, height, alpha, negated)
    DECL_THISCALL_HEAD(InternalGetHelpSprite, _ZN12CHIDKeyboard21InternalGetHelpSpriteEPKc10HIDMappingP9CVector2DS4_, CSprite2d*, char const* characters, HIDMapping mapping, CVector2D* uvTopLeft, CVector2D* uvBottomRight)
    DECL_THISCALL_TAIL(InternalGetHelpSprite, characters, mapping, uvTopLeft, uvBottomRight)
    DECL_THISCALL_SIMPLE(InternalGetInputType, _ZN12CHIDKeyboard20InternalGetInputTypeEv, HIDInputType);
    DECL_THISCALL_HEAD(AddMapping, _ZN12CHIDKeyboard10AddMappingE13OSKeyboardKey10HIDMappingb12MouseButtons, void, OSKeyboardKey key, HIDMapping mapping, bool negated, MouseButtons mouseButton)
    DECL_THISCALL_TAIL(AddMapping, key, mapping, negated, mouseButton)
    DECL_THISCALL_HEAD(InternalGetMappingWeight, _ZN12CHIDKeyboard24InternalGetMappingWeightE10HIDMapping, float, HIDMapping mapping)
    DECL_THISCALL_TAIL(InternalGetMappingWeight, mapping)
    DECL_THISCALL_SIMPLE(InternalFlushQueuedText, _ZN12CHIDKeyboard23InternalFlushQueuedTextEv, void);
    DECL_THISCALL_SIMPLE(InternalRemoveQueuedText, _ZN12CHIDKeyboard24InternalRemoveQueuedTextEv, void);
    DECL_THISCALL_HEAD(QueueTextRender, _ZN12CHIDKeyboard15QueueTextRenderE10HIDMappingfffib, void, HIDMapping mapping, float x, float y, float height, i32 alpha, bool negated)
    DECL_THISCALL_TAIL(QueueTextRender, mapping, x, y, height, alpha, negated)
    DECL_THISCALL_SIMPLE(DoDefaultMappings, _ZN12CHIDKeyboard17DoDefaultMappingsEv, void);
    inline static GxtChar* GetMappingString(OSKeyboardKey key)
    {
        static auto native = GetMainLibrarySymbol<GxtChar*(*)(OSKeyboardKey)>("_ZN12CHIDKeyboard16GetMappingStringE13OSKeyboardKey");
        return native(key);
    }
    DECL_THISCALL_NAMED_HEAD(GetMappingString1, GetMappingString, _ZN12CHIDKeyboard16GetMappingStringE10HIDMappingb, GxtChar*, HIDMapping mapping, bool negated)
    DECL_THISCALL_TAIL(GetMappingString1, mapping, negated)
    DECL_FASTCALL_SIMPLE(GetTagName, _ZN12CHIDKeyboard10GetTagNameE13OSKeyboardKey, char const*, OSKeyboardKey key);
    DECL_THISCALL_HEAD(ReplaceMapping, _ZN12CHIDKeyboard14ReplaceMappingE10HIDMapping13OSKeyboardKeyb12MouseButtons, void, HIDMapping mapping, OSKeyboardKey key, bool negated, MouseButtons mouseButton)
    DECL_THISCALL_TAIL(ReplaceMapping, mapping, key, negated, mouseButton)
    DECL_FASTCALL_SIMPLE(RestoreDefaultMappings, _ZN12CHIDKeyboard22RestoreDefaultMappingsEv, void);
    DECL_THISCALL_HEAD(LoadMappingsFromDisk, _ZN12CHIDKeyboard20LoadMappingsFromDiskEb, bool, bool setDefaults)
    DECL_THISCALL_TAIL(LoadMappingsFromDisk, setDefaults)
    DECL_THISCALL_SIMPLE(SaveMappingsToDisk, _ZN12CHIDKeyboard18SaveMappingsToDiskEv, void);

    inline CRect FindUVsFromMapping(char const* characters, HIDMapping mapping, bool negated)
    {
        return ((CRect(*)(ThisClass*, char const*, HIDMapping, bool))((void**)__vftable)[21])(this, characters, mapping, negated);
    }

    // STATIC values
    DECL_OBJECT_PLT(OSArray<KeyPair>, m_KeyPairs, BYBIT(0x6773EC, 0x84C810));

    // Member values
    OSArray<KeyboardButtonMapping> m_Mappings;
    CSprite2d m_Sprite;
    i32 m_nNumTextQueued;
    QueuedText m_QueuedText[100];
DECL_CLASS_END()
CHECKSIZE(CHIDKeyboard, 0x978, 0x988);

DECL_CLASS_BASED(CHIDJoystick, CHID)
protected:
    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CHIDJoystick, _ZN12CHIDJoystickC2EPKc, char const* textureName)
    DECL_CTORCALL_ARG_TAIL(textureName)
public:
    DECL_DTORCALL(CHIDJoystick, _ZN12CHIDJoystickD2Ev);

    // Member functions
    DECL_THISCALL_HEAD(InternalCacheAnalogValues, _ZN12CHIDJoystick25InternalCacheAnalogValuesEj, void, u32 gamepadIndex)
    DECL_THISCALL_TAIL(InternalCacheAnalogValues, gamepadIndex)
    DECL_THISCALL_HEAD(InternalImplements, _ZN12CHIDJoystick18InternalImplementsE10HIDMapping, bool, HIDMapping mapping)
    DECL_THISCALL_TAIL(InternalImplements, mapping)
    DECL_THISCALL_HEAD(InternalReplaces, _ZN12CHIDJoystick16InternalReplacesE10HIDMapping, bool, HIDMapping mapping)
    DECL_THISCALL_TAIL(InternalReplaces, mapping)
    DECL_THISCALL_HEAD(InternalIsDoubleTapped, _ZN12CHIDJoystick22InternalIsDoubleTappedE10HIDMapping, bool, HIDMapping mapping)
    DECL_THISCALL_TAIL(InternalIsDoubleTapped, mapping)
    DECL_THISCALL_HEAD(InternalIsJustPressed, _ZN12CHIDJoystick21InternalIsJustPressedE10HIDMapping, bool, HIDMapping mapping)
    DECL_THISCALL_TAIL(InternalIsJustPressed, mapping)
    DECL_THISCALL_HEAD(InternalIsPressed, _ZN12CHIDJoystick17InternalIsPressedE10HIDMappingPf, bool, HIDMapping mapping, float* value)
    DECL_THISCALL_TAIL(InternalIsPressed, mapping, value)
    DECL_THISCALL_HEAD(InternalIsReleased, _ZN12CHIDJoystick18InternalIsReleasedE10HIDMapping, bool, HIDMapping mapping)
    DECL_THISCALL_TAIL(InternalIsReleased, mapping)
    DECL_THISCALL_HEAD(InternalIsReleasedPositive, _ZN12CHIDJoystick26InternalIsReleasedPositiveE10HIDMapping, bool, HIDMapping mapping)
    DECL_THISCALL_TAIL(InternalIsReleasedPositive, mapping)
    DECL_THISCALL_HEAD(InternalIsReleasedNegative, _ZN12CHIDJoystick26InternalIsReleasedNegativeE10HIDMapping, bool, HIDMapping mapping)
    DECL_THISCALL_TAIL(InternalIsReleasedNegative, mapping)
    DECL_THISCALL_HEAD(InternalIsPressedPositive, _ZN12CHIDJoystick25InternalIsPressedPositiveE10HIDMapping, bool, HIDMapping mapping)
    DECL_THISCALL_TAIL(InternalIsPressedPositive, mapping)
    DECL_THISCALL_HEAD(InternalIsPressedNegative, _ZN12CHIDJoystick25InternalIsPressedNegativeE10HIDMapping, bool, HIDMapping mapping)
    DECL_THISCALL_TAIL(InternalIsPressedNegative, mapping)
    DECL_THISCALL_HEAD(InternalMappingIsAnalog, _ZN12CHIDJoystick23InternalMappingIsAnalogE10HIDMapping, bool, HIDMapping mapping)
    DECL_THISCALL_TAIL(InternalMappingIsAnalog, mapping)
    DECL_THISCALL_HEAD(InternalDrawHelpIcon, _ZN12CHIDJoystick20InternalDrawHelpIconEPKc10HIDMappingfffib, void, char const* characters, HIDMapping mapping, float x, float y, float height, i32 alpha, bool negated)
    DECL_THISCALL_TAIL(InternalDrawHelpIcon, characters, mapping, x, y, height, alpha, negated)
    DECL_THISCALL_HEAD(InternalGetHelpSprite, _ZN12CHIDJoystick21InternalGetHelpSpriteEPKc10HIDMappingP9CVector2DS4_, CSprite2d*, char const* characters, HIDMapping mapping, CVector2D* uvTopLeft, CVector2D* uvBottomRight)
    DECL_THISCALL_TAIL(InternalGetHelpSprite, characters, mapping, uvTopLeft, uvBottomRight)
    DECL_THISCALL_SIMPLE(InternalGetInputType, _ZN12CHIDJoystick20InternalGetInputTypeEv, HIDInputType);
    DECL_THISCALL_HEAD(AddMapping, _ZN12CHIDJoystick10AddMappingEi10HIDMapping, void, i32 buttonId, HIDMapping mapping)
    DECL_THISCALL_TAIL(AddMapping, buttonId, mapping)
    DECL_THISCALL_SIMPLE(InternalUpdate, _ZN12CHIDJoystick14InternalUpdateEv, void);
    DECL_THISCALL_HEAD(GetButtonID, _ZN12CHIDJoystick11GetButtonIDE10HIDMapping, int, HIDMapping mapping)
    DECL_THISCALL_TAIL(GetButtonID, mapping)
    DECL_THISCALL_HEAD(MappingHasButtonID, _ZN12CHIDJoystick18MappingHasButtonIDEi, bool, i32 buttonId)
    DECL_THISCALL_TAIL(MappingHasButtonID, buttonId)

    inline CRect FindUVsFromMapping(char const* characters, HIDMapping mapping, bool negated)
    {
        return ((CRect(*)(ThisClass*, char const*, HIDMapping, bool))((void**)__vftable)[21])(this, characters, mapping, negated);
    }

    inline static bool InstanceEverCreated() { return m_bInstanceEverCreated(); }

    // STATIC values
    DECL_VALUE_PLT_BOOL(m_bInstanceEverCreated, BYBIT(0x676E58, 0x84BCF0));

    // Member values
    OSArray<JoystickButtonMapping> m_Mappings;
    CSprite2d m_Sprite;
    bool m_bContextButtonActive;
DECL_CLASS_END()
CHECKSIZE(CHIDJoystick, 0x18, 0x28);

DECL_CLASS_BASED(CHIDKeyboardPC, CHIDKeyboard)
    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CHIDKeyboardPC, _ZN14CHIDKeyboardPCC2EPKc, char const* textureName)
    DECL_CTORCALL_ARG_TAIL(textureName)

    // Member functions
    DECL_THISCALL_HEAD(FindUVsFromMapping, _ZN14CHIDKeyboardPC18FindUVsFromMappingEPKc10HIDMappingb, CRect, char const* characters, HIDMapping mapping, bool negated)
    DECL_THISCALL_TAIL(FindUVsFromMapping, characters, mapping, negated)
    DECL_THISCALL_SIMPLE(DoDefaultMappings, _ZN14CHIDKeyboardPC17DoDefaultMappingsEv, void);
DECL_CLASS_END()
CHECKSIZE(CHIDKeyboardPC, 0x978, 0x988);

DECL_CLASS_BASED(CHIDJoystickAndroidTV, CHIDJoystick)
    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CHIDJoystickAndroidTV, _ZN21CHIDJoystickAndroidTVC2EPKc, char const* textureName)
    DECL_CTORCALL_ARG_TAIL(textureName)

    // Member functions
    DECL_THISCALL_HEAD(FindUVsFromMapping, _ZN21CHIDJoystickAndroidTV18FindUVsFromMappingEPKc10HIDMappingb, CRect, char const* characters, HIDMapping mapping, bool negated)
    DECL_THISCALL_TAIL(FindUVsFromMapping, characters, mapping, negated)
DECL_CLASS_END()
CHECKSIZE(CHIDJoystickAndroidTV, 0x18, 0x28);

DECL_CLASS_BASED(CHIDJoystickAmazon, CHIDJoystick)
    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CHIDJoystickAmazon, _ZN18CHIDJoystickAmazonC2EPKc, char const* textureName)
    DECL_CTORCALL_ARG_TAIL(textureName)

    // Member functions
    DECL_THISCALL_HEAD(FindUVsFromMapping, _ZN18CHIDJoystickAmazon18FindUVsFromMappingEPKc10HIDMappingb, CRect, char const* characters, HIDMapping mapping, bool negated)
    DECL_THISCALL_TAIL(FindUVsFromMapping, characters, mapping, negated)
DECL_CLASS_END()
CHECKSIZE(CHIDJoystickAmazon, 0x18, 0x28);

DECL_CLASS_BASED(CHIDJoystickMogaPocket, CHIDJoystick)
    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CHIDJoystickMogaPocket, _ZN22CHIDJoystickMogaPocketC2EPKc, char const* textureName)
    DECL_CTORCALL_ARG_TAIL(textureName)

    // Member functions
    DECL_THISCALL_HEAD(FindUVsFromMapping, _ZN22CHIDJoystickMogaPocket18FindUVsFromMappingEPKc10HIDMappingb, CRect, char const* characters, HIDMapping mapping, bool negated)
    DECL_THISCALL_TAIL(FindUVsFromMapping, characters, mapping, negated)
DECL_CLASS_END()
CHECKSIZE(CHIDJoystickMogaPocket, 0x18, 0x28);

DECL_CLASS_BASED(CHIDJoystickMogaPro, CHIDJoystick)
    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CHIDJoystickMogaPro, _ZN19CHIDJoystickMogaProC2EPKc, char const* textureName)
    DECL_CTORCALL_ARG_TAIL(textureName)

    // Member functions
    DECL_THISCALL_HEAD(FindUVsFromMapping, _ZN19CHIDJoystickMogaPro18FindUVsFromMappingEPKc10HIDMappingb, CRect, char const* characters, HIDMapping mapping, bool negated)
    DECL_THISCALL_TAIL(FindUVsFromMapping, characters, mapping, negated)
DECL_CLASS_END()
CHECKSIZE(CHIDJoystickMogaPro, 0x18, 0x28);

DECL_CLASS_BASED(CHIDJoystickPS3, CHIDJoystick)
    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CHIDJoystickPS3, _ZN15CHIDJoystickPS3C2EPKc, char const* textureName)
    DECL_CTORCALL_ARG_TAIL(textureName)

    // Member functions
    DECL_THISCALL_HEAD(FindUVsFromMapping, _ZN15CHIDJoystickPS318FindUVsFromMappingEPKc10HIDMappingb, CRect, char const* characters, HIDMapping mapping, bool negated)
    DECL_THISCALL_TAIL(FindUVsFromMapping, characters, mapping, negated)
DECL_CLASS_END()
CHECKSIZE(CHIDJoystickPS3, 0x18, 0x28);

DECL_CLASS_BASED(CHIDJoystickXbox360, CHIDJoystick)
    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CHIDJoystickXbox360, _ZN19CHIDJoystickXbox360C2EPKc, char const* textureName)
    DECL_CTORCALL_ARG_TAIL(textureName)

    // Member functions
    DECL_THISCALL_HEAD(FindUVsFromMapping, _ZN19CHIDJoystickXbox36018FindUVsFromMappingEPKc10HIDMappingb, CRect, char const* characters, HIDMapping mapping, bool negated)
    DECL_THISCALL_TAIL(FindUVsFromMapping, characters, mapping, negated)
DECL_CLASS_END()
CHECKSIZE(CHIDJoystickXbox360, 0x18, 0x28);

DECL_CLASS_BASED(CHIDJoystickXbox360Standard, CHIDJoystick)
    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CHIDJoystickXbox360Standard, _ZN27CHIDJoystickXbox360StandardC2EPKc, char const* textureName)
    DECL_CTORCALL_ARG_TAIL(textureName)

    // Member functions
    DECL_THISCALL_HEAD(FindUVsFromMapping, _ZN27CHIDJoystickXbox360Standard18FindUVsFromMappingEPKc10HIDMappingb, CRect, char const* characters, HIDMapping mapping, bool negated)
    DECL_THISCALL_TAIL(FindUVsFromMapping, characters, mapping, negated)
DECL_CLASS_END()
CHECKSIZE(CHIDJoystickXbox360Standard, 0x18, 0x28);

#define m_GamepadType m_GamepadType()
#define bAllowKeyboardInstance bAllowKeyboardInstance()
#define m_pInstance m_pInstance()
#define m_nDeadFrames m_nDeadFrames()
#define m_MappingPairs m_MappingPairs()
#define currentInstanceIndex currentInstanceIndex()

#endif // __AML_PSDK_SAHID_H
