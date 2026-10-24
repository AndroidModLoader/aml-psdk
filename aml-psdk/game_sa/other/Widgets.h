#ifndef __AML_PSDK_SAWIDGETS_H
#define __AML_PSDK_SAWIDGETS_H

#include <aml-psdk/game_sa/engine/Sprite2d.h>
#include <aml-psdk/gta_base/Vector.h>
#include <aml-psdk/gta_base/RGBA.h>
#include <aml-psdk/gta_base/DrawVertices.h>
#include "../enum/HID.h"

struct CPed;

struct WidgetPosition
{
    float m_fOriginX;
    float m_fOriginY;
    float m_fScaleX;
    float m_fScaleY;
};

DECL_CLASS(CHoldEffect)
    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CHoldEffect, _ZN11CHoldEffectC2EPKcb5CRGBAb, char const* pchar1, bool arg2, CRGBA arg3, bool arg4)
    DECL_CTORCALL_ARG_TAIL(pchar1, arg2, arg3, arg4)
    DECL_DTORCALL(CHoldEffect, _ZN11CHoldEffectD2Ev);

    // STATIC functions
    DECL_FASTCALL_SIMPLE(UpdateAll, _ZN11CHoldEffect9UpdateAllEv, void);
    DECL_FASTCALL_SIMPLE(DrawAll, _ZN11CHoldEffect7DrawAllEv, void);

    // STATIC values
    DECL_OBJECT_PLT(CHoldEffect*, m_pChainHead, BYBIT(0x676198, 0x84A390));
    DECL_OBJECT_PLT(CHoldEffect*, m_pChainTail, BYBIT(0x6781FC, 0x84E410));

    // Member functions
    DECL_THISCALL_SIMPLE(Draw, _ZN11CHoldEffect4DrawEv, void);
    DECL_THISCALL_HEAD(SetVertices, _ZN11CHoldEffect11SetVerticesEiPfS0_RK5CRGBA, void, i32 arg1, float* pfloat2, float* pfloat3, CRGBA const& arg4)
    DECL_THISCALL_TAIL(SetVertices, arg1, pfloat2, pfloat3, arg4)

    // Member values
    CHoldEffect* m_pPrev;
    CHoldEffect* m_pNext;
    CSprite2d m_Sprite;
    CRect m_RectScreen;
    float m_fProgress;
    bool m_bSquare;
    CRGBA m_Color;
    bool m_bExplicitRender;
    RwIm2DVertex maVertices[48];
DECL_CLASS_END()
CHECKSIZE(CHoldEffect, 0x568, 0x578);

DECL_CLASS(CTapEffect)
    // Construct/Deconstruct functions
    // Update deletes finished effects; allocate with new.
    DECL_CTORCALL_ARG_HEAD(CTapEffect, _ZN10CTapEffectC2EPKc9CVector2D, char const* spriteName, CVector2D screenPosition)
    DECL_CTORCALL_ARG_TAIL(spriteName, screenPosition)
    DECL_DTORCALL(CTapEffect, _ZN10CTapEffectD2Ev);

    // STATIC functions
    DECL_FASTCALL_SIMPLE(UpdateAll, _ZN10CTapEffect9UpdateAllEv, void);
    DECL_FASTCALL_SIMPLE(DrawAll, _ZN10CTapEffect7DrawAllEv, void);

    // STATIC values
    DECL_OBJECT_PLT(CTapEffect*, m_pChainHead, BYBIT(0x67633C, 0x84A6D0));
    DECL_OBJECT_PLT(CTapEffect*, m_pChainTail, BYBIT(0x677558, 0x84CAE8));

    // Member functions
    DECL_THISCALL_SIMPLE(Update, _ZN10CTapEffect6UpdateEv, void);
    DECL_THISCALL_SIMPLE(Draw, _ZN10CTapEffect4DrawEv, void);

    // Member values
    CTapEffect* m_pPrev;
    CTapEffect* m_pNext;
    CSprite2d m_Sprite;
    CVector2D m_vecScreen;
    float m_fScale;
    float m_fRate;
    CRect m_RectScreen;
DECL_CLASS_END()
CHECKSIZE(CTapEffect, 0x2C, 0x38);



DECL_CLASS_BASED(CWidget, SimpleVTable)
    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CWidget, _ZN7CWidgetC2EPKcRK14WidgetPositionj10HIDMapping, char const* pszSprite, WidgetPosition const& WidgetPos, u32 nFlags, HIDMapping Mapping)
    DECL_CTORCALL_ARG_TAIL(pszSprite, WidgetPos, nFlags, Mapping)
    DECL_DTORCALL_VIRTUAL(CWidget, _ZN7CWidgetD2Ev, _ZN7CWidget, _ZTV7CWidget);

    // Virtual functions
    virtual const char* GetName() = 0;
    DECL_VIRTUALCALL_HEAD(CWidget, CoordsAreInsideWidget, _ZTV7CWidget, 3, bool, CVector2D const& arg1, bool arg2)
    DECL_VIRTUALCALL_TAIL(arg1, arg2)
    DECL_VIRTUALCALL_HEAD(CWidget, DrawHelpIcon, _ZTV7CWidget, 4, void, char const* arg1, float arg2, float arg3, float arg4, int arg5)
    DECL_VIRTUALCALL_TAIL(arg1, arg2, arg3, arg4, arg5)
    DECL_VIRTUALCALL_HEAD(CWidget, Draw, _ZTV7CWidget, 5, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidget, GetPinchDistance, _ZTV7CWidget, 6, float)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidget, GetWidgetValue, _ZTV7CWidget, 7, float)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidget, GetWidgetValue2, _ZTV7CWidget, 8, void, float * arg1, float * arg2)
    DECL_VIRTUALCALL_TAIL(arg1, arg2)
    DECL_VIRTUALCALL_HEAD(CWidget, IsButton, _ZTV7CWidget, 9, bool)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidget, IsDoubleTapped, _ZTV7CWidget, 10, bool)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidget, IsHeldDown, _ZTV7CWidget, 11, bool)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidget, IsPinchZooming, _ZTV7CWidget, 12, bool, CVector2D * arg1)
    DECL_VIRTUALCALL_TAIL(arg1)
    DECL_VIRTUALCALL_HEAD(CWidget, IsReleased, _ZTV7CWidget, 13, bool, CVector2D * arg1)
    DECL_VIRTUALCALL_TAIL(arg1)
    DECL_VIRTUALCALL_HEAD(CWidget, IsRegion, _ZTV7CWidget, 14, bool)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidget, IsSwiped, _ZTV7CWidget, 15, bool)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidget, IsSwipedDown, _ZTV7CWidget, 16, bool)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidget, IsSwipedLeft, _ZTV7CWidget, 17, bool)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidget, IsSwipedRight, _ZTV7CWidget, 18, bool)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidget, IsSwipedUp, _ZTV7CWidget, 19, bool)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidget, IsTouched, _ZTV7CWidget, 20, bool, CVector2D * arg1)
    DECL_VIRTUALCALL_TAIL(arg1)
    DECL_VIRTUALCALL_HEAD(CWidget, OnInitialTouch, _ZTV7CWidget, 21, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidget, OnPinchZoomStart, _ZTV7CWidget, 22, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidget, OnReleasedTouch, _ZTV7CWidget, 23, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidget, OnSwipeTouch, _ZTV7CWidget, 24, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidget, Pulsate, _ZTV7CWidget, 25, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidget, SetEquippedItem, _ZTV7CWidget, 26, void, int arg1)
    DECL_VIRTUALCALL_TAIL(arg1)
    DECL_VIRTUALCALL_HEAD(CWidget, SetSliderRange, _ZTV7CWidget, 27, void, float arg1, float arg2)
    DECL_VIRTUALCALL_TAIL(arg1, arg2)
    DECL_VIRTUALCALL_HEAD(CWidget, SetWidgetValue, _ZTV7CWidget, 28, void, float arg1)
    DECL_VIRTUALCALL_TAIL(arg1)
    DECL_VIRTUALCALL_HEAD(CWidget, SetWidgetValue2, _ZTV7CWidget, 29, void, float arg1, float arg2)
    DECL_VIRTUALCALL_TAIL(arg1, arg2)
    DECL_VIRTUALCALL_HEAD(CWidget, SetWidgetValue3, _ZTV7CWidget, 30, void, float arg1, float arg2, float arg3)
    DECL_VIRTUALCALL_TAIL(arg1, arg2, arg3)
    DECL_VIRTUALCALL_HEAD(CWidget, SetWidgetInfo, _ZTV7CWidget, 31, void, char * arg1, float arg2, bool arg3, bool arg4, bool arg5, bool arg6, int arg7)
    DECL_VIRTUALCALL_TAIL(arg1, arg2, arg3, arg4, arg5, arg6, arg7)
    DECL_VIRTUALCALL_HEAD(CWidget, SetWidgetInfo2, _ZTV7CWidget, 32, void, int arg1, int arg2, int arg3, int arg4, char * arg5, char * arg6)
    DECL_VIRTUALCALL_TAIL(arg1, arg2, arg3, arg4, arg5, arg6)
    DECL_VIRTUALCALL_HEAD(CWidget, Update, _ZTV7CWidget, 33, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidget, Visualize, _ZTV7CWidget, 34, void)
    DECL_VIRTUALCALL_TAIL()

    // STATIC functions
    DECL_FASTCALL_SIMPLE(SetScissor, _ZN7CWidget10SetScissorER5CRect, void, CRect& rectScissor);
    DECL_FASTCALL_SIMPLE(DrawTitleSafeArea, _ZN7CWidget17DrawTitleSafeAreaEv, void);
    DECL_FASTCALL_SIMPLE(GetScreenWidth, _ZN7CWidget14GetScreenWidthEv, u32);
    DECL_FASTCALL_SIMPLE(UpdateTiming, _ZN7CWidget12UpdateTimingEv, void);
    DECL_FASTCALL_SIMPLE(IsInsideRect, _ZN7CWidget12IsInsideRectE9CVector2D5CRect, bool, CVector2D point, CRect rect);
    DECL_FASTCALL_SIMPLE(IsInsideCircle, _ZN7CWidget14IsInsideCircleE9CVector2D5CRect, bool, CVector2D point, CRect rect);
    DECL_FASTCALL_SIMPLE(SetInitialTouchWidget, _ZN7CWidget21SetInitialTouchWidgetEiPS_, void, i32 touchIndex, CWidget *pWidget);
    DECL_FASTCALL_SIMPLE(SetReleasedWidget, _ZN7CWidget17SetReleasedWidgetEiPS_, void, i32 touchIndex, CWidget *pWidget);
    DECL_FASTCALL_SIMPLE(SetSwipedWidget, _ZN7CWidget15SetSwipedWidgetEiPS_, void, i32 touchIndex, CWidget *pWidget);
    DECL_FASTCALL_SIMPLE(SetPinchZoomWidget, _ZN7CWidget18SetPinchZoomWidgetEPS_, void, CWidget *pWidget);
    DECL_FASTCALL_SIMPLE(SetTextureStatic, _ZN7CWidget16SetTextureStaticER9CSprite2dPc, void, CSprite2d& sprite, char *pTextureName);

    // STATIC values
    DECL_OBJECT_ARRAY_PLT(CWidget*, m_pInitialTouchWidget, BYBIT(0x67656C, 0x84AB30));
    DECL_OBJECT_ARRAY_PLT(CWidget*, m_pReleasedWidget, BYBIT(0x678AC8, 0x84F5B8));
    DECL_OBJECT_ARRAY_PLT(CWidget*, m_pSwipedWidget, BYBIT(0x678AC4, 0x84F5B0));
    DECL_OBJECT_PLT(CWidget*, m_pPinchZoomWidget, BYBIT(0x678220, 0x84E458));
    DECL_OBJECT_ARRAY_PLT(CVector2D, m_vecTouchAnchor, BYBIT(0x678C50, 0x84F8C8));
    DECL_OBJECT_PLT(double, m_fTime, BYBIT(0x676CCC, 0x84B9E0));
    DECL_OBJECT_PLT(double, m_fElapsedTime, BYBIT(0x678AFC, 0x84F620));
    DECL_VALUE_SYM_BOOL(m_bInsidePause, _ZN7CWidget14m_bInsidePauseE);
    DECL_VALUE_PLT_FLT(SWIPE_DISTANCE, BYBIT(0x678ECC, 0x84FDC0));

    // Member functions
    DECL_THISCALL_SIMPLE(ClearTapHistory, _ZN7CWidget15ClearTapHistoryEv, void);
    DECL_THISCALL_SIMPLE(DecrementFrameCount, _ZN7CWidget19DecrementFrameCountEv, void);
    DECL_THISCALL_SIMPLE(AndroidBackEnabled, _ZN7CWidget18AndroidBackEnabledEv, bool);
    DECL_THISCALL_SIMPLE(GetEnabled, _ZN7CWidget10GetEnabledEv, bool);
    DECL_THISCALL_SIMPLE(ManageAlpha, _ZN7CWidget11ManageAlphaEv, void);

    DECL_THISCALL_HEAD(CreateHoldEffect, _ZN7CWidget16CreateHoldEffectEPKcb5CRGBAb, void,
        const char *pTextureName, bool square, CRGBA color, bool explicitRender)
    DECL_THISCALL_TAIL(CreateHoldEffect, pTextureName, square, color, explicitRender)

    DECL_THISCALL_HEAD(GetGradientColor, _ZN7CWidget16GetGradientColorEfi, CRGBA, float progress, i32 alpha)
    DECL_THISCALL_TAIL(GetGradientColor, progress, alpha)

    DECL_THISCALL_HEAD(GetNumTapsInTime, _ZN7CWidget16GetNumTapsInTimeEf, i32, float time)
    DECL_THISCALL_TAIL(GetNumTapsInTime, time)

    DECL_THISCALL_HEAD(SetEnabled, _ZN7CWidget10SetEnabledEb, void, bool enabled)
    DECL_THISCALL_TAIL(SetEnabled, enabled)

    DECL_THISCALL_HEAD(SetScreenRect, _ZN7CWidget13SetScreenRectERK5CRect, void, CRect const& rect)
    DECL_THISCALL_TAIL(SetScreenRect, rect)

    DECL_THISCALL_HEAD(SetTexture, _ZN7CWidget10SetTextureER9CSprite2dPcb, void, CSprite2d& sprite, char *pTextureName, bool bilinear)
    DECL_THISCALL_TAIL(SetTexture, sprite, pTextureName, bilinear)

    // Member values
    HIDMapping m_HIDMapping;
    CSprite2d m_Sprite;
    union
    {
        WidgetPosition m_Position;
        struct
        {
            float m_fOriginX;
            float m_fOriginY;
            float m_fScaleX;
            float m_fScaleY;
        };
    };
    float m_fFadeRate;
    CRect m_RectScreen;
    float m_fExtraPaddingScale;
    CRect m_RectPaddedScreen;
    float m_fTapHoldTime;
    bool m_bTaphold;
    CRGBA m_Color;
    bool m_bEnabled;
    bool m_bCachedEnabled;
    float m_fTapHistory[10];
    int m_nTouchIndex;
    int m_nFrameCount;
    union
    {
        unsigned int m_nFlags;
        struct
        {
            unsigned int m_bUseRadiusForRangeCheck : 1;
            unsigned int m_bUseXForScaling : 1;
            unsigned int m_bFlag4 : 1;
            unsigned int m_bFlag8 : 1;
            unsigned int m_bFlag10 : 1;
            unsigned int m_bFlag20 : 1;
            unsigned int m_bPointerClickable : 1;
            unsigned int m_bFlag80 : 1;

            unsigned int m_bFlag100 : 1;
            unsigned int m_bFlag200 : 1;
            unsigned int m_bFlag400 : 1;
            unsigned int m_bFlag800 : 1;
            unsigned int m_bCorrectAspect : 1;
            unsigned int m_bHasHIDAttached : 1;
            unsigned int m_bFlag4000 : 1;
            unsigned int m_bFlag8000 : 1;

            unsigned int m_bFlag10000 : 1;
            unsigned int m_bFlag20000 : 1;
            unsigned int m_bFlag40000 : 1;
            unsigned int m_bFlag80000 : 1;
            unsigned int m_bFlag100000 : 1;
            unsigned int m_bFlag200000 : 1;
            unsigned int m_bFlag400000 : 1;
            unsigned int m_bFlag800000 : 1;

            unsigned int m_bFlag1000000 : 1;
            unsigned int m_bFlag2000000 : 1;
            unsigned int m_bFlag4000000 : 1;
            unsigned int m_bFlag8000000 : 1;
            unsigned int m_bFlag10000000 : 1;
            unsigned int m_bFlag20000000 : 1;
            unsigned int m_bFlag40000000 : 1;
            unsigned int m_bFlag80000000 : 1;
        };
    };
    float m_fUserData;
    CHoldEffect *m_pHoldEffect;
    float m_fHoldEffectPeriod;
DECL_CLASS_END()
CHECKSIZE(CWidget, 0x90, 0xA8);

struct TextureDatabaseRuntime;
struct CWidgetButton;
struct CWidgetButtonAnimated;
struct CWidgetButtonAnimatedArcade;
struct CWidgetButtonAttack;
struct CWidgetButtonAutoHydraulics;
struct CWidgetButtonBasketballShoot;
struct CWidgetButtonDrop;
struct CWidgetButtonEnterCar;
struct CWidgetButtonHelpText;
struct CWidgetButtonHorn;
struct CWidgetButtonHydraulics;
struct CWidgetButtonMissionCancel;
struct CWidgetButtonMissionStart;
struct CWidgetButtonRocket;
struct CWidgetButtonSchool;
struct CWidgetButtonSkipCutscene;
struct CWidgetButtonSprint;
struct CWidgetButtonSwapWeapons;
struct CWidgetButtonSwim;
struct CWidgetButtonTargeting;
struct CWidgetButtonVCShoot;
struct CWidgetButtonVehicleShoot;
struct CWidgetButtonZoom;
struct CWidgetHelpText;
struct CWidgetHorseResults;
struct CWidgetInfoFrame;
struct CWidgetList;
struct CWidgetListShop;
struct CWidgetListText;
struct CWidgetMap;
struct CWidgetMissionTimers;
struct CWidgetPlayerInfo;
struct CWidgetPool;
struct CWidgetRaceResults;
struct CWidgetRacing;
struct CWidgetRadar;
struct CWidgetRegion;
struct CWidgetRegionArcadeStick;
struct CWidgetRegionBasketBallJump;
struct CWidgetRegionColorPicker;
struct CWidgetRegionDriveHybrid;
struct CWidgetRegionFlick;
struct CWidgetRegionGang;
struct CWidgetRegionHydraulics;
struct CWidgetRegionLook;
struct CWidgetRegionMove;
struct CWidgetRegionPoolBallInHand;
struct CWidgetRegionPoolEnglish;
struct CWidgetRegionResponse;
struct CWidgetRegionRhythmSelect;
struct CWidgetRegionSprint;
struct CWidgetRegionSteer;
struct CWidgetRegionSteeringSelection;
struct CWidgetRegionSwipeRadio;
struct CWidgetRegionTouchLayoutSelection;
struct CWidgetReplay;
struct CWidgetRouletteSpin;
struct CWidgetSaveNotification;
struct CWidgetSlider;
struct CWidgetTapMeter;
struct CWidgetThumbCircle;
struct CWidgetVitalStats;
struct CWidgetWager;

DECL_CLASS(CTouchInterface)
    enum WidgetIDs
    {
        WIDGET_ENTER_CAR = 0,
        WIDGET_ATTACK = 1,
        WIDGET_ACCELERATE = 2,
        WIDGET_BRAKE = 3,
        WIDGET_HANDBRAKE = 4,
        WIDGET_VEHICLE_STEER_LEFT = 5,
        WIDGET_VEHICLE_STEER_RIGHT = 6,
        WIDGET_HORN = 7,
        WIDGET_PHONE = 8,
        WIDGET_GIFT = 9,
        WIDGET_KISS = 10,
        WIDGET_CAR_SHOOT = 11,
        WIDGET_HYDRAULICS = 12,
        WIDGET_AUTO_HYDRAULICS = 13,
        WIDGET_DROP_CRANE = 14,
        WIDGET_DROP_ITEM = 15,
        WIDGET_VEHICLE_SHOOT_LEFT = 16,
        WIDGET_VEHICLE_SHOOT_RIGHT = 17,
        WIDGET_CAM_TOGGLE = 18,
        WIDGET_ENTER_TARGETING = 19,
        WIDGET_EXIT_TARGETING = 20,
        WIDGET_VC_SHOOT = 21,
        WIDGET_VC_SHOOT_ALT = 22,
        WIDGET_AIR_GUN = 23,
        WIDGET_ROCKET = 24,
        WIDGET_VEHICLE_BOMB = 25,
        WIDGET_VEHICLE_TURRET_LEFT = 26,
        WIDGET_VEHICLE_TURRET_RIGHT = 27,
        WIDGET_PURCHASE = 28,
        WIDGET_SWAP_WEAPONS = 29,
        WIDGET_NITRO = 30,
        WIDGET_BUTTON_SPRINT = 31,
        WIDGET_BUTTON_CROUCH = 32,
        WIDGET_BUTTON_DIVE = 33,
        WIDGET_BUTTON_SWIM = 34,
        WIDGET_POOL_ENGLISH = 35,
        WIDGET_POOL_BALL_IN_HAND = 36,
        WIDGET_ARCADE_BUTTON = 37,
        WIDGET_ARCADE_POWER_OFF = 38,
        WIDGET_ARCADE_RESET = 39,
        WIDGET_ARCADE_JOYSTICK = 40,
        WIDGET_SKIP_CUTSCENE = 41,
        WIDGET_TRAIN_NEXT_STATION = 42,
        WIDGET_TAP_METER_BUTTON = 43,
        WIDGET_CRANE_UP = 44,
        WIDGET_CRANE_DOWN = 45,
        WIDGET_HELICOPTER_MAGNET_UP = 46,
        WIDGET_HELICOPTER_MAGNET_DOWN = 47,
        WIDGET_GYM_EASIER = 48,
        WIDGET_GYM_HARDER = 49,
        WIDGET_ZOOM_IN = 50,
        WIDGET_ZOOM_OUT = 51,
        WIDGET_RACE_LEFT = 52,
        WIDGET_RACE_RIGHT = 53,
        WIDGET_STORE_ACCEPT = 54,
        WIDGET_STORE_CANCEL = 55,
        WIDGET_STORE_BACK = 56,
        WIDGET_STORE_BUY = 57,
        WIDGET_ROULETTE_UP = 58,
        WIDGET_ROULETTE_DOWN = 59,
        WIDGET_ROULETTE_LEFT = 60,
        WIDGET_ROULETTE_RIGHT = 61,
        WIDGET_PLACE_BET = 62,
        WIDGET_REMOVE_BET = 63,
        WIDGET_STEERING_SELECTION = 64,
        WIDGET_TOUCH_LAYOUT_SELECTION = 65,
        WIDGET_GRAB = 66,
        WIDGET_MAGNET = 67,
        WIDGET_STINGER = 68,
        WIDGET_MISSION_START = 69,
        WIDGET_MISSION_START_VIGILANTE = 70,
        WIDGET_MISSION_CANCEL = 71,
        WIDGET_MISSION_CANCEL_VIGILANTE = 72,
        WIDGET_MINIGAME_START = 73,
        WIDGET_MINIGAME_CANCEL = 74,
        WIDGET_SCHOOL_EXIT = 75,
        WIDGET_SCHOOL_LEFT = 76,
        WIDGET_SCHOOL_RIGHT = 77,
        WIDGET_SCHOOL_START = 78,
        WIDGET_SCHOOL_CONTINUE = 79,
        WIDGET_SCHOOL_TITLE_BACKGROUND = 80,
        WIDGET_SCHOOL_AWARD = 81,
        WIDGET_SCHOOL_RESULTS = 82,
        WIDGET_SCHOOL_FRAME_ONE = 83,
        WIDGET_SCHOOL_FRAME_TWO = 84,
        WIDGET_SCHOOL_FRAME_THREE = 85,
        WIDGET_SCHOOL_FRAME_FOUR = 86,
        WIDGET_BASKETBALL_SHOOT = 87,
        WIDGET_BASKETBALL_TRICK = 88,
        WIDGET_GAMBLING_QUIT = 89,
        WIDGET_GAMBLING_CONTINUE = 90,
        WIDGET_BLACK_JACK_SPLIT = 91,
        WIDGET_BLACK_JACK_DOUBLE = 92,
        WIDGET_BLACK_JACK_HIT = 93,
        WIDGET_BLACK_JACK_STAND = 94,
        WIDGET_BLACK_JACK_REGION = 95,
        WIDGET_MENU_SLIDER = 96,
        WIDGET_RHYTHM_UP = 97,
        WIDGET_RHYTHM_DOWN = 98,
        WIDGET_RHYTHM_LEFT = 99,
        WIDGET_RHYTHM_RIGHT = 100,
        WIDGET_RHYTHM_SELECT = 101,
        WIDGET_RHYTHM_EXIT = 102,
        WIDGET_PLAYER_SCORE = 103,
        WIDGET_OPPOSITION_SCORE = 104,
        WIDGET_GANG_REGION = 105,
        WIDGET_GANG_RECRUIT = 106,
        WIDGET_GANG_IGNORE = 107,
        WIDGET_GANG_FOLLOW = 108,
        WIDGET_GANG_HOLD_POSITION = 109,
        WIDGET_POSITIVE = 110,
        WIDGET_NEGATIVE = 111,
        WIDGET_COLOR_PICKER = 112,
        WIDGET_VEHICLE_SLIDER_LEFT_BUTTON = 113,
        WIDGET_VEHICLE_SLIDER_RIGHT_BUTTON = 114,
        WIDGET_WOF_FIRST_BET = 115,
        WIDGET_WOF_SECOND_BET = 116,
        WIDGET_WOF_THIRD_BET = 117,
        WIDGET_WOF_FOURTH_BET = 118,
        WIDGET_WOF_FIFTH_BET = 119,
        WIDGET_WOF_SIXTH_BET = 120,
        WIDGET_VIDEO_POKER_ADD_COIN = 121,
        WIDGET_VIDEO_POKER_REMOVE_COIN = 122,
        WIDGET_VIDEO_POKER_DEAL = 123,
        WIDGET_VIDEO_POKER_HOLD_FIRST_CARD = 124,
        WIDGET_VIDEO_POKER_HOLD_SECOND_CARD = 125,
        WIDGET_VIDEO_POKER_HOLD_THIRD_CARD = 126,
        WIDGET_VIDEO_POKER_HOLD_FOURTH_CARD = 127,
        WIDGET_VIDEO_POKER_HOLD_FIFTH_CARD = 128,
        WIDGET_VIDEO_POKER_HOLD_FIRST_CARD_REGION = 129,
        WIDGET_VIDEO_POKER_HOLD_SECOND_CARD_REGION = 130,
        WIDGET_VIDEO_POKER_HOLD_THIRD_CARD_REGION = 131,
        WIDGET_VIDEO_POKER_HOLD_FOURTH_CARD_REGION = 132,
        WIDGET_VIDEO_POKER_HOLD_FIFTH_CARD_REGION = 133,
        WIDGET_VIDEO_POKER_EXIT = 134,
        WIDGET_ITB_FIRST_HORSE = 135,
        WIDGET_ITB_SECOND_HORSE = 136,
        WIDGET_ITB_THIRD_HORSE = 137,
        WIDGET_ITB_FOURTH_HORSE = 138,
        WIDGET_ITB_FIFTH_HORSE = 139,
        WIDGET_ITB_FIRST_BET = 140,
        WIDGET_ITB_SECOND_BET = 141,
        WIDGET_ITB_THIRD_BET = 142,
        WIDGET_ITB_FOURTH_BET = 143,
        WIDGET_ITB_FIFTH_BET = 144,
        WIDGET_ITB_SIXTH_BET = 145,
        WIDGET_ITB_SEVENTH_BET = 146,
        WIDGET_ITB_EIGHTH_BET = 147,
        WIDGET_ITB_PLACE_BET = 148,
        WIDGET_ITB_EXIT = 149,
        WIDGET_MAP = 150,
        WIDGET_WEAPON_SLOT_CHEATS = 151,
        WIDGET_CAR_CHEATS = 152,
        WIDGET_MISSION_SKIP = 153,
        WIDGET_CHEATS = 154,
        WIDGET_CHEAT_MENU = 155,
        WIDGET_SHOP = 156,
        WIDGET_RESPONSE = 157,
        WIDGET_DRIVE_HYBRID = 158,
        WIDGET_REPLAY = 159,
        WIDGET_PLAYER_INFO = 160,
        WIDGET_RADAR = 161,
        WIDGET_HELP_TEXT = 162,
        WIDGET_TAP_METER = 163,
        WIDGET_THUMB_CIRCLE = 164,
        WIDGET_MENU = 165,
        WIDGET_SWIPE_RADIO = 166,
        WIDGET_PED_MOVE = 167,
        WIDGET_SPRINT = 168,
        WIDGET_BASKETBALL_JUMP = 169,
        WIDGET_SHOOT_LOOK = 170,
        WIDGET_VEHICLE_LANECORRECTION = 171,
        WIDGET_VEHICLE_STEER_ANALOG = 172,
        WIDGET_VEHICLE_FLICK = 173,
        WIDGET_CHEATS_RECT = 174,
        WIDGET_LOOK = 175,
        WIDGET_MISSION_TIMERS = 176,
        WIDGET_RACING = 177,
        WIDGET_RACE_RESULTS = 178,
        WIDGET_HORSE_RESULTS = 179,
        WIDGET_WAGER = 180,
        WIDGET_POOL = 181,
        WIDGET_POKER_PAYOUT = 182,
        WIDGET_VITAL_STATS = 183,
        WIDGET_ROULETTE_SPIN = 184,
        WIDGET_AIRPORT_LEFT = 185,
        WIDGET_AIRPORT_RIGHT = 186,
        WIDGET_PARACHUTE = 187,
        WIDGET_TATTOO_PREVIEW = 188,
        WIDGET_SAVE_NOTIFICATION = 189,
        NUM_WIDGETS = 190
    };

    enum WidgetPositionIDs
    {
        WIDGET_POSITION_ENTER_CAR = 0,
        WIDGET_POSITION_CAR_SHOOT = 1,
        WIDGET_POSITION_ACCELERATE = 2,
        WIDGET_POSITION_BUTTON_SPRINT_AND_SWIM = 3,
        WIDGET_POSITION_BRAKE = 4,
        WIDGET_POSITION_VEHICLE_STEER_LEFT = 5,
        WIDGET_POSITION_VEHICLE_STEER_RIGHT = 6,
        WIDGET_POSITION_HORN = 7,
        WIDGET_POSITION_HORN_ALT = 8,
        WIDGET_POSITION_PHONE = 9,
        WIDGET_POSITION_VEHICLE_SHOOT_LEFT = 10,
        WIDGET_POSITION_VEHICLE_SHOOT_RIGHT = 11,
        WIDGET_POSITION_HANDBRAKE_AND_AIR_SHOOT = 12,
        WIDGET_POSITION_CAM_TOGGLE = 13,
        WIDGET_POSITION_TARGETING_AND_ATTACK = 14,
        WIDGET_POSITION_VC_SHOOT = 15,
        WIDGET_POSITION_VC_SHOOT_ALT = 16,
        WIDGET_POSITION_SWAP_WEAPONS = 17,
        WIDGET_POSITION_PLACE_BET = 18,
        WIDGET_POSITION_REMOVE_BET = 19,
        WIDGET_POSITION_NEGATIVE = 20,
        WIDGET_POSITION_POSITIVE = 21,
        WIDGET_POSITION_POOL_ENGLISH = 22,
        WIDGET_POSITION_ARCADE_BUTTON = 23,
        WIDGET_POSITION_ARCADE_POWER_OFF = 24,
        WIDGET_POSITION_ARCADE_RESET = 25,
        WIDGET_POSITION_ARCADE_JOYSTICK = 26,
        WIDGET_POSITION_SKIP_CUTSCENE = 27,
        WIDGET_POSITION_RACE_LEFT = 28,
        WIDGET_POSITION_RACE_RIGHT = 29,
        WIDGET_POSITION_STORE_ACCEPT = 30,
        WIDGET_POSITION_STORE_CANCEL = 31,
        WIDGET_POSITION_STORE_BUY = 32,
        WIDGET_POSITION_STEERING_SELECTION = 33,
        WIDGET_POSITION_TOUCH_LAYOUT_SELECTION = 34,
        WIDGET_POSITION_THUMB_CIRCLE = 35,
        WIDGET_POSITION_TAP_METER = 36,
        WIDGET_POSITION_TAP_METER_BUTTON = 37,
        WIDGET_POSITION_MISSION_START_AND_MISSION_CANCEL = 38,
        WIDGET_POSITION_MISSION_CANCEL_ALT = 39,
        WIDGET_POSITION_SCHOOL_EXIT = 40,
        WIDGET_POSITION_SCHOOL_LEFT = 41,
        WIDGET_POSITION_SCHOOL_RIGHT = 42,
        WIDGET_POSITION_SCHOOL_START = 43,
        WIDGET_POSITION_SCHOOL_CONTINUE = 44,
        WIDGET_POSITION_SCHOOL_TITLE_BACKGROUND = 45,
        WIDGET_POSITION_SCHOOL_AWARD = 46,
        WIDGET_POSITION_SCHOOL_RESULTS = 47,
        WIDGET_POSITION_SCHOOL_FRAME_ONE = 48,
        WIDGET_POSITION_SCHOOL_FRAME_TWO = 49,
        WIDGET_POSITION_SCHOOL_FRAME_THREE = 50,
        WIDGET_POSITION_SCHOOL_FRAME_FOUR = 51,
        WIDGET_POSITION_BASKETBALL_SHOOT = 52,
        WIDGET_POSITION_BASKETBALL_TRICK = 53,
        WIDGET_POSITION_GAMBLING_QUIT = 54,
        WIDGET_POSITION_GAMBLING_CONTINUE = 55,
        WIDGET_POSITION_BLACK_JACK_SPLIT = 56,
        WIDGET_POSITION_BLACK_JACK_DOUBLE = 57,
        WIDGET_POSITION_BLACK_JACK_HIT = 58,
        WIDGET_POSITION_BLACK_JACK_STAND = 59,
        WIDGET_POSITION_BLACK_JACK_REGION = 60,
        WIDGET_POSITION_BLACK_JACK_SLIDER = 61,
        WIDGET_POSITION_RHYTHM_UP = 62,
        WIDGET_POSITION_RHYTHM_DOWN = 63,
        WIDGET_POSITION_RHYTHM_LEFT = 64,
        WIDGET_POSITION_RHYTHM_RIGHT = 65,
        WIDGET_POSITION_RHYTHM_SELECT = 66,
        WIDGET_POSITION_RHYTHM_EXIT = 67,
        WIDGET_POSITION_PLAYER_SCORE = 68,
        WIDGET_POSITION_OPPOSITION_SCORE = 69,
        WIDGET_POSITION_GANG_REGION = 70,
        WIDGET_POSITION_COLOR_PICKER = 71,
        WIDGET_POSITION_COLOR_PICKER_PHONES = 72,
        WIDGET_POSITION_WOF_FIRST_BET = 73,
        WIDGET_POSITION_WOF_SECOND_BET = 74,
        WIDGET_POSITION_WOF_THIRD_BET = 75,
        WIDGET_POSITION_WOF_FOURTH_BET = 76,
        WIDGET_POSITION_WOF_FIFTH_BET = 77,
        WIDGET_POSITION_WOF_SIXTH_BET = 78,
        WIDGET_POSITION_VIDEO_POKER_ADD_COIN = 79,
        WIDGET_POSITION_VIDEO_POKER_REMOVE_COIN = 80,
        WIDGET_POSITION_VIDEO_POKER_HOLD_FIRST_CARD = 81,
        WIDGET_POSITION_VIDEO_POKER_HOLD_SECOND_CARD = 82,
        WIDGET_POSITION_VIDEO_POKER_HOLD_THIRD_CARD = 83,
        WIDGET_POSITION_VIDEO_POKER_HOLD_FOURTH_CARD = 84,
        WIDGET_POSITION_VIDEO_POKER_HOLD_FIFTH_CARD = 85,
        WIDGET_POSITION_VIDEO_POKER_HOLD_FIRST_CARD_REGION = 86,
        WIDGET_POSITION_VIDEO_POKER_HOLD_SECOND_CARD_REGION = 87,
        WIDGET_POSITION_VIDEO_POKER_HOLD_THIRD_CARD_REGION = 88,
        WIDGET_POSITION_VIDEO_POKER_HOLD_FOURTH_CARD_REGION = 89,
        WIDGET_POSITION_VIDEO_POKER_HOLD_FIFTH_CARD_REGION = 90,
        WIDGET_POSITION_VIDEO_POKER_EXIT = 91,
        WIDGET_POSITION_VIDEO_POKER_DEAL = 92,
        WIDGET_POSITION_ITB_FIRST_HORSE = 93,
        WIDGET_POSITION_ITB_SECOND_HORSE = 94,
        WIDGET_POSITION_ITB_THIRD_HORSE = 95,
        WIDGET_POSITION_ITB_FOURTH_HORSE = 96,
        WIDGET_POSITION_ITB_FIFTH_HORSE = 97,
        WIDGET_POSITION_ITB_FIRST_BET = 98,
        WIDGET_POSITION_ITB_SECOND_BET = 99,
        WIDGET_POSITION_ITB_THIRD_BET = 100,
        WIDGET_POSITION_ITB_FOURTH_BET = 101,
        WIDGET_POSITION_ITB_FIFTH_BET = 102,
        WIDGET_POSITION_ITB_SIXTH_BET = 103,
        WIDGET_POSITION_ITB_SEVENTH_BET = 104,
        WIDGET_POSITION_ITB_EIGHTH_BET = 105,
        WIDGET_POSITION_ITB_PLACE_BET = 106,
        WIDGET_POSITION_ITB_EXIT = 107,
        WIDGET_POSITION_MAP = 108,
        WIDGET_POSITION_RESPONSE = 109,
        WIDGET_POSITION_HYDRAULICS = 110,
        WIDGET_POSITION_DRIVE = 111,
        WIDGET_POSITION_PLAYER_INFO = 112,
        WIDGET_POSITION_RADAR = 113,
        WIDGET_POSITION_HELP_TEXT = 114,
        WIDGET_POSITION_HELP_TEXT_ALT = 115,
        WIDGET_POSITION_HELP_TEXT_ALT_SHOPS = 116,
        WIDGET_POSITION_SWIPE_RADIO = 117,
        WIDGET_POSITION_PED_MOVE = 118,
        WIDGET_POSITION_SPRINT_AND_BASKETBALL_JUMP = 119,
        WIDGET_POSITION_SHOOT_LOOK = 120,
        WIDGET_POSITION_VEHICLE_STEER_ANALOG = 121,
        WIDGET_POSITION_VEHICLE_FLICK = 122,
        WIDGET_POSITION_LOOK = 123,
        WIDGET_POSITION_MISSION_TIMERS = 124,
        WIDGET_POSITION_RACING = 125,
        WIDGET_POSITION_RACE_RESULTS = 126,
        WIDGET_POSITION_HORSE_RESULTS = 127,
        WIDGET_POSITION_WAGER = 128,
        WIDGET_POSITION_POOL = 129,
        WIDGET_POSITION_POKER_PAYOUT = 130,
        WIDGET_POSITION_VITAL_STATS = 131,
        WIDGET_POSITION_MINIGAME_CANCEL = 132,
        WIDGET_POSITION_AIRPORT_LEFT = 133,
        WIDGET_POSITION_AIRPORT_RIGHT = 134,
        WIDGET_POSITION_TATTOO_PREVIEW = 135,
        WIDGET_POSITION_SAVE_NOTIFICATION = 136,
        WIDGET_POSITION_REPLAY = 137,
        NUM_WIDGET_POSITIONS = 138
    };

    // STATIC functions
    DECL_FASTCALL_SIMPLE(AnyWidgetsUsingAltBack, _ZN15CTouchInterface22AnyWidgetsUsingAltBackEv, bool);
    DECL_FASTCALL_SIMPLE(AddButtonFlag, _ZN15CTouchInterface13AddButtonFlagENS_9WidgetIDsEi, void, WidgetIDs value, i32 index);
    DECL_FASTCALL_SIMPLE(AddWidgetFlag, _ZN15CTouchInterface13AddWidgetFlagENS_9WidgetIDsEi, void, WidgetIDs value, i32 index);
    DECL_FASTCALL_SIMPLE(Clear, _ZN15CTouchInterface5ClearEv, void);
    DECL_FASTCALL_SIMPLE(ClearTapHistory, _ZN15CTouchInterface15ClearTapHistoryENS_9WidgetIDsE, void, WidgetIDs value);
    DECL_FASTCALL_SIMPLE(CreateAll, _ZN15CTouchInterface9CreateAllEv, void);
    DECL_FASTCALL_SIMPLE(CreateListTextWidget1, _ZN15CTouchInterface20CreateListTextWidgetEPPKciNS_9WidgetIDsEbbb, void, char const** value, i32 index, WidgetIDs value1, bool enabled1, bool enabled2, bool enabled3);
    inline static void CreateListTextWidget(char const** value, i32 index, WidgetIDs value1, bool enabled1, bool enabled2, bool enabled3) { return CreateListTextWidget1(value, index, value1, enabled1, enabled2, enabled3); }
    DECL_FASTCALL_SIMPLE(CreateListTextWidget2, _ZN15CTouchInterface20CreateListTextWidgetEPPKciNS_9WidgetIDsER14WidgetPositionbbb, void, char const** value, i32 index, WidgetIDs value1, WidgetPosition& value14, bool enabled1, bool enabled2, bool enabled3);
    inline static void CreateListTextWidget(char const** value, i32 index, WidgetIDs value1, WidgetPosition& value14, bool enabled1, bool enabled2, bool enabled3) { return CreateListTextWidget2(value, index, value1, value14, enabled1, enabled2, enabled3); }
    DECL_FASTCALL_SIMPLE(CreateShopWidget, _ZN15CTouchInterface16CreateShopWidgetEPKcPS1_iR14WidgetPositionb, void, char const* text, char const** value, i32 index, WidgetPosition& value1, bool enabled);
    DECL_FASTCALL_SIMPLE(CreateTapMeterWidget, _ZN15CTouchInterface20CreateTapMeterWidgetEv, void);
    DECL_FASTCALL_SIMPLE(CreateThumbCircleWidget, _ZN15CTouchInterface23CreateThumbCircleWidgetEv, void);
    DECL_FASTCALL_SIMPLE(DebugReload, _ZN15CTouchInterface11DebugReloadEv, void);
    DECL_FASTCALL_SIMPLE(DeleteAll, _ZN15CTouchInterface9DeleteAllEv, void);
    DECL_FASTCALL_SIMPLE(DeleteWidget, _ZN15CTouchInterface12DeleteWidgetENS_9WidgetIDsE, void, WidgetIDs value);
    DECL_FASTCALL_SIMPLE(DrawAll, _ZN15CTouchInterface7DrawAllEb, void, bool enabled);
    DECL_FASTCALL_SIMPLE(DrawHelpIcon, _ZN15CTouchInterface12DrawHelpIconEPKcfffi, void, char const* text, float value1, float value2, float value3, i32 index);
    DECL_FASTCALL_SIMPLE(GetWidgetValue, _ZN15CTouchInterface14GetWidgetValueENS_9WidgetIDsE, float, WidgetIDs value);
    DECL_FASTCALL_SIMPLE(GetWidgetValue2, _ZN15CTouchInterface15GetWidgetValue2ENS_9WidgetIDsEPfS1_, void, WidgetIDs value, float* value1, float* value2);
    DECL_FASTCALL_SIMPLE(GetWidgetPosition1, _ZN15CTouchInterface17GetWidgetPositionENS_9WidgetIDsERfS1_S1_S1_, bool, WidgetIDs value, float& value1, float& value2, float& value3, float& value4);
    inline static bool GetWidgetPosition(WidgetIDs value, float& value1, float& value2, float& value3, float& value4) { return GetWidgetPosition1(value, value1, value2, value3, value4); }
    DECL_FASTCALL_SIMPLE(GetWidgetPosition2, _ZN15CTouchInterface17GetWidgetPositionENS_17WidgetPositionIDsERfS1_S1_S1_, void, WidgetPositionIDs value, float& value1, float& value2, float& value3, float& value4);
    inline static void GetWidgetPosition(WidgetPositionIDs value, float& value1, float& value2, float& value3, float& value4) { return GetWidgetPosition2(value, value1, value2, value3, value4); }
    DECL_FASTCALL_SIMPLE(GetTouchPosition, _ZN15CTouchInterface16GetTouchPositionEi, CVector2D, i32 index);
    DECL_FASTCALL_SIMPLE(GetTouchDelta, _ZN15CTouchInterface13GetTouchDeltaEi, CVector2D, i32 index);
    DECL_FASTCALL_SIMPLE(GetNumTouches, _ZN15CTouchInterface13GetNumTouchesEv, i32);
    DECL_FASTCALL_SIMPLE(IsDoubleTapped, _ZN15CTouchInterface14IsDoubleTappedENS_9WidgetIDsEbi, bool, WidgetIDs value, bool enabled, i32 index);
    DECL_FASTCALL_SIMPLE(IsHeldDown, _ZN15CTouchInterface10IsHeldDownENS_9WidgetIDsEi, bool, WidgetIDs value, i32 index);
    DECL_FASTCALL_SIMPLE(IsPinchZooming, _ZN15CTouchInterface14IsPinchZoomingENS_9WidgetIDsEP9CVector2Di, bool, WidgetIDs value, CVector2D* value1, i32 index);
    DECL_FASTCALL_SIMPLE(IsReleased, _ZN15CTouchInterface10IsReleasedENS_9WidgetIDsEP9CVector2Di, bool, WidgetIDs value, CVector2D* value1, i32 index);
    DECL_FASTCALL_SIMPLE(IsSwipedDown, _ZN15CTouchInterface12IsSwipedDownENS_9WidgetIDsEi, bool, WidgetIDs value, i32 index);
    DECL_FASTCALL_SIMPLE(IsSwipedLeft, _ZN15CTouchInterface12IsSwipedLeftENS_9WidgetIDsEi, bool, WidgetIDs value, i32 index);
    DECL_FASTCALL_SIMPLE(IsSwipedRight, _ZN15CTouchInterface13IsSwipedRightENS_9WidgetIDsEi, bool, WidgetIDs value, i32 index);
    DECL_FASTCALL_SIMPLE(IsSwipedUp, _ZN15CTouchInterface10IsSwipedUpENS_9WidgetIDsEi, bool, WidgetIDs value, i32 index);
    DECL_FASTCALL_SIMPLE(IsTouchDown, _ZN15CTouchInterface11IsTouchDownEi, bool, i32 index);
    DECL_FASTCALL_SIMPLE(IsTouched, _ZN15CTouchInterface9IsTouchedENS_9WidgetIDsEP9CVector2Di, bool, WidgetIDs value, CVector2D* value1, i32 index);
    DECL_FASTCALL_SIMPLE(LoadAllTextureDBs, _ZN15CTouchInterface17LoadAllTextureDBsEv, void);
    DECL_FASTCALL_SIMPLE(LoadDefaultConfigFile, _ZN15CTouchInterface21LoadDefaultConfigFileEv, void);
    DECL_FASTCALL_SIMPLE(LoadTextureDB, _ZN15CTouchInterface13LoadTextureDBEv, TextureDatabaseRuntime*);
    DECL_FASTCALL_SIMPLE(MarketingHack, _ZN15CTouchInterface13MarketingHackEi, void, i32 index);
    DECL_FASTCALL_SIMPLE(LoadTouchControls, _ZN15CTouchInterface17LoadTouchControlsEv, void);
    DECL_FASTCALL_SIMPLE(LoadFromFile, _ZN15CTouchInterface12LoadFromFileEPKcb, void, char const* text, bool enabled);
    DECL_FASTCALL_SIMPLE(RemoveButtonFlag, _ZN15CTouchInterface16RemoveButtonFlagENS_9WidgetIDsEi, void, WidgetIDs value, i32 index);
    DECL_FASTCALL_SIMPLE(RemoveWidgetFlag, _ZN15CTouchInterface16RemoveWidgetFlagENS_9WidgetIDsEi, void, WidgetIDs value, i32 index);
    DECL_FASTCALL_SIMPLE(RepositionAdjustableWidgets, _ZN15CTouchInterface27RepositionAdjustableWidgetsEv, void);
    DECL_FASTCALL_SIMPLE(SetEquippedItem, _ZN15CTouchInterface15SetEquippedItemENS_9WidgetIDsEi, void, WidgetIDs value, i32 index);
    DECL_FASTCALL_SIMPLE(SetSliderRange, _ZN15CTouchInterface14SetSliderRangeENS_9WidgetIDsEff, void, WidgetIDs value, float value1, float value2);
    DECL_FASTCALL_SIMPLE(SetWidgetTexture, _ZN15CTouchInterface16SetWidgetTextureENS_9WidgetIDsEPc, void, WidgetIDs value, char* text);
    DECL_FASTCALL_SIMPLE(SetWidgetValue, _ZN15CTouchInterface14SetWidgetValueENS_9WidgetIDsEf, void, WidgetIDs value, float value1);
    DECL_FASTCALL_SIMPLE(SetWidgetValue2, _ZN15CTouchInterface15SetWidgetValue2ENS_9WidgetIDsEff, void, WidgetIDs value, float value1, float value2);
    DECL_FASTCALL_SIMPLE(SetWidgetValue3, _ZN15CTouchInterface15SetWidgetValue3ENS_9WidgetIDsEfff, void, WidgetIDs value, float value1, float value2, float value3);
    DECL_FASTCALL_SIMPLE(SetWidgetInfo, _ZN15CTouchInterface13SetWidgetInfoENS_9WidgetIDsEPcfbbbbi, void, WidgetIDs value, char* text, float value1, bool enabled1, bool enabled2, bool enabled3, bool enabled4, i32 index);
    DECL_FASTCALL_SIMPLE(SetWidgetInfo2, _ZN15CTouchInterface14SetWidgetInfo2ENS_9WidgetIDsEiiiiPcS1_, void, WidgetIDs value, i32 index1, i32 index2, i32 index3, i32 index4, char* text1, char* text2);
    DECL_FASTCALL_SIMPLE(UnloadAllTextureDBs, _ZN15CTouchInterface19UnloadAllTextureDBsEv, void);
    DECL_FASTCALL_SIMPLE(UnloadTextureDB, _ZN15CTouchInterface15UnloadTextureDBEP22TextureDatabaseRuntime, void, TextureDatabaseRuntime* value);
    DECL_FASTCALL_SIMPLE(Update, _ZN15CTouchInterface6UpdateEv, void);
    DECL_FASTCALL_SIMPLE(VisualizeAll, _ZN15CTouchInterface12VisualizeAllEb, void, bool enabled);
    DECL_FASTCALL_SIMPLE(SetupLayoutObjects, _ZN15CTouchInterface18SetupLayoutObjectsEv, void);
    DECL_FASTCALL_SIMPLE(SetupSteeringMode, _ZN15CTouchInterface17SetupSteeringModeEv, void);

    // STATIC values
    DECL_OBJECT_ARRAY_PLT(CWidget*, m_pWidgets, BYBIT(0x67947c, 0x850910));
    typedef char m_pszWidgetTextures_t[128];
    DECL_OBJECT_ARRAY_PLT(m_pszWidgetTextures_t, m_pszWidgetTextures, BYBIT(0x678860, 0x84f0e0));
    DECL_OBJECT_ARRAY_PLT(WidgetPosition, m_WidgetPosition, BYBIT(0x676328, 0x84a6a8));
    DECL_OBJECT_ARRAY_PLT(char const*, m_pszWidgetPositionNames, BYBIT(0x678e2c, 0x84fc80));
    DECL_OBJECT_PLT(bool, m_bPinchZoom, BYBIT(0x678a50, 0x84f4c8));
    DECL_OBJECT_PLT(i32, m_nMaxTouches, BYBIT(0x679d28, 0x851a68));
    DECL_OBJECT_ARRAY_PLT(bool, m_bTouchDown, BYBIT(0x67935c, 0x8506d0));
    DECL_OBJECT_ARRAY_PLT(CVector2D, m_vecCachedPos, BYBIT(0x677418, 0x84c868));
    DECL_OBJECT_ARRAY_PLT(CVector2D, m_vecCachedDelta, BYBIT(0x679180, 0x850328));

DECL_CLASS_END()
CHECKSIZE(CTouchInterface, 0x1, 0x1);

DECL_CLASS(QueuedMessage)
    // Member values
    u16 m_GxtString[400];
    float m_fDisplayPeriod;
    u16 m_nStatID;
    float m_fStatRate;
    float m_fStatMaxValue;
    u32 m_nConditionFlag;
DECL_CLASS_END()
CHECKSIZE(QueuedMessage, 0x334, 0x334);

DECL_CLASS(SDataCell)
    // Member values
    char m_szLabel[128];
    char m_szText[128];
    i32 m_nIntegerValue0;
    i32 m_nIntegerValue1;
    i32 m_nColor;
DECL_CLASS_END()
CHECKSIZE(SDataCell, 0x10c, 0x10c);

DECL_CLASS(ItemData)
    // Member values
    char m_szItemName[128];
    char m_szItemPrice[128];
    CSprite2d m_Sprite;
    CRect m_RectUVs;
    CRGBA m_Color;
    bool m_bBorder;
DECL_CLASS_END()
CHECKSIZE(ItemData, 0x11c, 0x120);

DECL_CLASS(SFileEntry)
    // Member values
    char m_szItemName[32];
    char m_szFileName[32];
    CRect m_RectUVs;
    CRGBA m_Color;
    bool m_bBorder;
DECL_CLASS_END()
CHECKSIZE(SFileEntry, 0x58, 0x58);

DECL_CLASS_BASED(CWidgetButton, CWidget)
    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CWidgetButton, _ZN13CWidgetButtonC2EPKcRK14WidgetPositionjj10HIDMapping, char const* textureName, WidgetPosition const& position, u32 flags1, u32 flags2, HIDMapping mapping)
    DECL_CTORCALL_ARG_TAIL(textureName, position, flags1, flags2, mapping)
    DECL_DTORCALL_VIRTUAL(CWidgetButton, _ZN13CWidgetButtonD2Ev, _ZN13CWidgetButton, _ZTV13CWidgetButton);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(CWidgetButton, Draw, _ZTV13CWidgetButton, 5, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetButton, DrawHelpIcon, _ZTV13CWidgetButton, 4, void, char const* text, float value1, float value2, float value3, i32 index)
    DECL_VIRTUALCALL_TAIL(text, value1, value2, value3, index)
    DECL_VIRTUALCALL_HEAD(CWidgetButton, GetName, _ZTV13CWidgetButton, 2, char const*)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetButton, IsButton, _ZTV13CWidgetButton, 9, bool)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetButton, Pulsate, _ZTV13CWidgetButton, 25, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetButton, Update, _ZTV13CWidgetButton, 33, void)
    DECL_VIRTUALCALL_TAIL()

    // STATIC functions
    DECL_FASTCALL_SIMPLE(DrawHelpIconExplicit, _ZN13CWidgetButton20DrawHelpIconExplicitE10HIDMappingPKcfffi, void, HIDMapping mapping, char const* text, float value1, float value2, float value3, i32 index);

    // STATIC values
    DECL_OBJECT_PLT(CSprite2d, m_StaticSprite, BYBIT(0x677e40, 0x84dca0));
    static constexpr i32 BUTTON_FLAGS_TURNS_RED = 1;
    static constexpr i32 BUTTON_FLAG_CAN_STICK_DOWN = 2;
    static constexpr i32 BUTTON_FLAG_IS_STUCK_DOWN = 4;
    static constexpr i32 BUTTON_FLAG_IS_HIGHLIGHTED = 8;
    static constexpr i32 BUTTON_FLAG_MAPPING_DISABLED = 16;

    // Member functions
    DECL_THISCALL_HEAD(SetFillSprite, _ZN13CWidgetButton13SetFillSpriteEPKcff, void, char const* text, float value1, float value2)
    DECL_THISCALL_TAIL(SetFillSprite, text, value1, value2)

    // Member values
    u32 m_nButtonFlags;
    float m_fPulssateTime;
    CSprite2d m_SpriteFill;
    float m_fFillLevel;
    float m_fTVTop;
    float m_fTVBottom;
DECL_CLASS_END()
CHECKSIZE(CWidgetButton, 0xa8, 0xc8);

DECL_CLASS_BASED(CWidgetHelpText, CWidget)
    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CWidgetHelpText, _ZN15CWidgetHelpTextC2EPKcRK14WidgetPosition, char const* textureName, WidgetPosition const& position)
    DECL_CTORCALL_ARG_TAIL(textureName, position)
    DECL_DTORCALL_VIRTUAL(CWidgetHelpText, _ZN15CWidgetHelpTextD2Ev, _ZN15CWidgetHelpText, _ZTV15CWidgetHelpText);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(CWidgetHelpText, GetName, _ZTV15CWidgetHelpText, 2, char const*)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetHelpText, Update, _ZTV15CWidgetHelpText, 33, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetHelpText, Visualize, _ZTV15CWidgetHelpText, 34, void)
    DECL_VIRTUALCALL_TAIL()

    // STATIC functions
    DECL_FASTCALL_SIMPLE(ConditionSatisfied, _ZN15CWidgetHelpText18ConditionSatisfiedEj, void, u32 flags);

    // STATIC values
    static constexpr i32 STATE_IDLE = 0;
    static constexpr i32 STATE_ANIMATING_IN = 1;
    static constexpr i32 STATE_WAITING = 2;
    static constexpr i32 STATE_TRANSITION_OUT = 3;
    static constexpr i32 STATE_TRANSITION_IN = 4;
    static constexpr i32 STATE_ANIMATING_OUT = 5;
    DECL_OBJECT_PLT(CWidgetHelpText*, m_pInstance, BYBIT(0x6787c8, 0x84efb8));
    static constexpr i32 CONDITION_FLAG_ENTER_CAR = 1;
    static constexpr i32 CONDITION_FLAG_ACCELERATE = 2;
    static constexpr i32 CONDITION_FLAG_MOVE_CARL = 4;
    static constexpr i32 CONDITION_FLAG_BRAKE = 8;
    static constexpr i32 CONDITION_FLAG_RECRUIT_GANG_MEMBER = 16;
    static constexpr i32 CONDITION_FLAG_BUNNY_HOP = 32;
    static constexpr i32 CONDITION_FLAG_RADIO_STATION = 64;
    static constexpr i32 CONDITION_FLAG_ANSWER_PHONE = 128;
    static constexpr i32 CONDITION_FLAG_ATTACK = 256;
    static constexpr i32 CONDITION_FLAG_VIEW_STATS = 512;
    static constexpr i32 CONDITION_FLAG_CLIMB = 1024;
    static constexpr i32 CONDITION_FLAG_CYCLE_TARGETS = 2048;
    static constexpr i32 CONDITION_FLAG_CROUCH = 4096;
    static constexpr i32 CONDITION_FLAG_GRAB = 8192;

    // Member functions
    DECL_THISCALL_HEAD(ConditionSatisfiedInstance, _ZN15CWidgetHelpText26ConditionSatisfiedInstanceEj, void, u32 flags)
    DECL_THISCALL_TAIL(ConditionSatisfiedInstance, flags)
    DECL_THISCALL_SIMPLE(RenderTopStyle, _ZN15CWidgetHelpText14RenderTopStyleEv, void);
    DECL_THISCALL_SIMPLE(ProcessMidScreenStyle, _ZN15CWidgetHelpText21ProcessMidScreenStyleEv, void);
    DECL_THISCALL_SIMPLE(ProcessTopStyle, _ZN15CWidgetHelpText15ProcessTopStyleEv, void);
    DECL_THISCALL_HEAD(RenderStat, _ZN15CWidgetHelpText10RenderStatEffbf, void, float value1, float value2, bool enabled, float value3)
    DECL_THISCALL_TAIL(RenderStat, value1, value2, enabled, value3)
    DECL_THISCALL_HEAD(SetFontProps, _ZN15CWidgetHelpText12SetFontPropsEPt, i32, u16* text)
    DECL_THISCALL_TAIL(SetFontProps, text)
    DECL_THISCALL_SIMPLE(UseTopStyle, _ZN15CWidgetHelpText11UseTopStyleEv, bool);
    DECL_THISCALL_HEAD(AddMessageToQueue, _ZN15CWidgetHelpText17AddMessageToQueueEPtbtffj, void, u16* text, bool enabled, u16 text1, float value1, float value2, u32 flags)
    DECL_THISCALL_TAIL(AddMessageToQueue, text, enabled, text1, value1, value2, flags)
    DECL_THISCALL_HEAD(ClearQueue, _ZN15CWidgetHelpText10ClearQueueEb, void, bool enabled)
    DECL_THISCALL_TAIL(ClearQueue, enabled)
    DECL_THISCALL_SIMPLE(GetNumQueuedMessages, _ZN15CWidgetHelpText20GetNumQueuedMessagesEv, i32);
    DECL_THISCALL_HEAD(IsStringQueued, _ZN15CWidgetHelpText14IsStringQueuedEPt, bool, u16* text)
    DECL_THISCALL_TAIL(IsStringQueued, text)
    DECL_THISCALL_SIMPLE(Process, _ZN15CWidgetHelpText7ProcessEv, void);

    // Member values
    float m_fTextAlpha;
    float m_fBackdropAlpha;
    float m_fStateTime;
    i32 m_nState;
    float m_fTextHeight;
    float m_fYOffset;
    CRect m_RectClient;
    QueuedMessage m_messages[10];
DECL_CLASS_END()
CHECKSIZE(CWidgetHelpText, 0x20c0, 0x20d8);

DECL_CLASS_BASED(CWidgetHorseResults, CWidget)
    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CWidgetHorseResults, _ZN19CWidgetHorseResultsC2EPKcRK14WidgetPosition, char const* textureName, WidgetPosition const& position)
    DECL_CTORCALL_ARG_TAIL(textureName, position)
    DECL_DTORCALL_VIRTUAL_VTABLE(CWidgetHorseResults, _ZN19CWidgetHorseResults, _ZTV19CWidgetHorseResults);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(CWidgetHorseResults, Draw, _ZTV19CWidgetHorseResults, 5, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetHorseResults, GetName, _ZTV19CWidgetHorseResults, 2, char const*)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetHorseResults, SetWidgetInfo2, _ZTV19CWidgetHorseResults, 32, void, i32 index1, i32 index2, i32 index3, i32 index4, char* text1, char* text2)
    DECL_VIRTUALCALL_TAIL(index1, index2, index3, index4, text1, text2)
    DECL_VIRTUALCALL_HEAD(CWidgetHorseResults, Update, _ZTV19CWidgetHorseResults, 33, void)
    DECL_VIRTUALCALL_TAIL()

    // Member values
    SDataCell m_DataCell[7];
DECL_CLASS_END()
CHECKSIZE(CWidgetHorseResults, 0x7e4, 0x7f8);

DECL_CLASS_BASED(CWidgetInfoFrame, CWidget)
    enum ColorTypes
    {
        WHITE = 0,
        BLUE = 1,
        GREEN = 2,
        RED = 3,
        MONEY = 4
    };

    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CWidgetInfoFrame, _ZN16CWidgetInfoFrameC2EPKcRK14WidgetPosition, char const* textureName, WidgetPosition const& position)
    DECL_CTORCALL_ARG_TAIL(textureName, position)
    DECL_DTORCALL_VIRTUAL(CWidgetInfoFrame, _ZN16CWidgetInfoFrameD2Ev, _ZN16CWidgetInfoFrame, _ZTV16CWidgetInfoFrame);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(CWidgetInfoFrame, Draw, _ZTV16CWidgetInfoFrame, 5, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetInfoFrame, GetName, _ZTV16CWidgetInfoFrame, 2, char const*)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetInfoFrame, SetWidgetInfo, _ZTV16CWidgetInfoFrame, 31, void, char* text, float value, bool enabled1, bool enabled2, bool enabled3, bool enabled4, i32 index)
    DECL_VIRTUALCALL_TAIL(text, value, enabled1, enabled2, enabled3, enabled4, index)
    DECL_VIRTUALCALL_HEAD(CWidgetInfoFrame, Update, _ZTV16CWidgetInfoFrame, 33, void)
    DECL_VIRTUALCALL_TAIL()

    // STATIC functions
    DECL_FASTCALL_SIMPLE(AnyObjectEnabled, _ZN16CWidgetInfoFrame16AnyObjectEnabledEv, bool);

    // STATIC values
    DECL_OBJECT_PLT(CWidgetInfoFrame*, m_pChainHead, BYBIT(0x678f78, 0x84ff18));
    DECL_OBJECT_PLT(CWidgetInfoFrame*, m_pChainTail, BYBIT(0x679dc4, 0x851ba0));

    // Member functions
    DECL_THISCALL_HEAD(RenderRowText, _ZN16CWidgetInfoFrame13RenderRowTextE5CRectPKcf, void, CRect rect, char const* text, float value)
    DECL_THISCALL_TAIL(RenderRowText, rect, text, value)

    // Member values
    CWidgetInfoFrame* m_pPrev;
    CWidgetInfoFrame* m_pNext;
    char TextLabel[10];
    i32 m_nValue;
    bool m_bHasTitle;
    bool m_bIsPercentage;
    bool m_bIsTime;
    bool m_bIsNumber;
    i32 m_nColorType;
DECL_CLASS_END()
CHECKSIZE(CWidgetInfoFrame, 0xb0, 0xd0);

DECL_CLASS_BASED(CWidgetList, CWidget)
    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CWidgetList, _ZN11CWidgetListC2EPKcRK14WidgetPositionPS1_ibbb, char const* textureName, WidgetPosition const& position, char const** entries, i32 value, bool enabled1, bool enabled2, bool enabled3)
    DECL_CTORCALL_ARG_TAIL(textureName, position, entries, value, enabled1, enabled2, enabled3)
    DECL_DTORCALL_VIRTUAL(CWidgetList, _ZN11CWidgetListD2Ev, _ZN11CWidgetList, _ZTV11CWidgetList);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(CWidgetList, AddItem, _ZTV11CWidgetList, 35, void, char const* text1, char const* text2)
    DECL_VIRTUALCALL_TAIL(text1, text2)
    DECL_VIRTUALCALL_HEAD(CWidgetList, Draw, _ZTV11CWidgetList, 5, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetList, GetWidgetValue, _ZTV11CWidgetList, 7, float)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetList, IsReleased, _ZTV11CWidgetList, 13, bool, CVector2D* value)
    DECL_VIRTUALCALL_TAIL(value)
    DECL_VIRTUALCALL_HEAD(CWidgetList, IsSwiped, _ZTV11CWidgetList, 15, bool)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetList, IsSwipedLeft, _ZTV11CWidgetList, 17, bool)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetList, IsSwipedRight, _ZTV11CWidgetList, 18, bool)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetList, OnInitialTouch, _ZTV11CWidgetList, 21, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetList, SetEquippedItem, _ZTV11CWidgetList, 26, void, i32 index)
    DECL_VIRTUALCALL_TAIL(index)
    DECL_VIRTUALCALL_HEAD(CWidgetList, SetWidgetValue, _ZTV11CWidgetList, 28, void, float value)
    DECL_VIRTUALCALL_TAIL(value)
    DECL_VIRTUALCALL_HEAD(CWidgetList, Update, _ZTV11CWidgetList, 33, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetList, Visualize, _ZTV11CWidgetList, 34, void)
    DECL_VIRTUALCALL_TAIL()

    // STATIC functions
    DECL_FASTCALL_SIMPLE(AlphabetizeSort, _ZN11CWidgetList15AlphabetizeSortEPKvS1_, i32, void const* value1, void const* value2);

    // Member functions
    DECL_THISCALL_HEAD(Alphebetize, _ZN11CWidgetList11AlphebetizeEPPKci, void, char const** value, i32 index)
    DECL_THISCALL_TAIL(Alphebetize, value, index)
    DECL_THISCALL_HEAD(GetAlphaAtIndex, _ZN11CWidgetList15GetAlphaAtIndexEi, float, i32 index)
    DECL_THISCALL_TAIL(GetAlphaAtIndex, index)
    DECL_THISCALL_HEAD(GetSelectedEntry, _ZN11CWidgetList16GetSelectedEntryEPc, i32, char* text)
    DECL_THISCALL_TAIL(GetSelectedEntry, text)
    DECL_THISCALL_HEAD(ShrinkTextToFit, _ZN11CWidgetList15ShrinkTextToFitEf, void, float value)
    DECL_THISCALL_TAIL(ShrinkTextToFit, value)

    // Member values
    ItemData m_ItemData[256];
    CRect m_RectClient;
    CRect m_RectScissor;
    i32 m_nEntries;
    float m_fRowHeight;
    float m_fScroll;
    float m_fScrollVelocity;
    i32 m_nSelectedItem;
    i32 m_nEquippedItem;
    float m_fTextScale;
    float m_fLastPressTime;
    float m_fLastTouchPositionY;
    bool m_bScrolling;
    bool m_bLocalize;
    bool m_bAlwaysHasSelection;
    bool m_bShowNumbers;
    CRGBA m_ColorBorder;
    CRGBA m_ColorSelectedItemLeft;
    CRGBA m_ColorSelectedItemRight;
    CRGBA m_ColorEvenItem;
    CRGBA m_ColorOddItem;
    CRGBA m_ColorEquippedItem;
DECL_CLASS_END()
CHECKSIZE(CWidgetList, 0x11cf0, 0x12108);

DECL_CLASS_BASED(CWidgetMap, CWidget)
    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CWidgetMap, _ZN10CWidgetMapC2EPKcRK14WidgetPosition, char const* textureName, WidgetPosition const& position)
    DECL_CTORCALL_ARG_TAIL(textureName, position)
    DECL_DTORCALL_VIRTUAL_VTABLE(CWidgetMap, _ZN10CWidgetMap, _ZTV10CWidgetMap);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(CWidgetMap, GetName, _ZTV10CWidgetMap, 2, char const*)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetMap, IsTouched, _ZTV10CWidgetMap, 20, bool, CVector2D* value)
    DECL_VIRTUALCALL_TAIL(value)

DECL_CLASS_END()
CHECKSIZE(CWidgetMap, 0x90, 0xa8);

DECL_CLASS_BASED(CWidgetMissionTimers, CWidget)
    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CWidgetMissionTimers, _ZN20CWidgetMissionTimersC2EPKcRK14WidgetPosition, char const* textureName, WidgetPosition const& position)
    DECL_CTORCALL_ARG_TAIL(textureName, position)
    DECL_DTORCALL_VIRTUAL_VTABLE(CWidgetMissionTimers, _ZN20CWidgetMissionTimers, _ZTV20CWidgetMissionTimers);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(CWidgetMissionTimers, Draw, _ZTV20CWidgetMissionTimers, 5, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetMissionTimers, GetName, _ZTV20CWidgetMissionTimers, 2, char const*)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetMissionTimers, Update, _ZTV20CWidgetMissionTimers, 33, void)
    DECL_VIRTUALCALL_TAIL()

DECL_CLASS_END()
CHECKSIZE(CWidgetMissionTimers, 0x90, 0xa8);

DECL_CLASS_BASED(CWidgetPlayerInfo, CWidget)
    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CWidgetPlayerInfo, _ZN17CWidgetPlayerInfoC2EPKcRK14WidgetPosition, char const* textureName, WidgetPosition const& position)
    DECL_CTORCALL_ARG_TAIL(textureName, position)
    DECL_DTORCALL_VIRTUAL(CWidgetPlayerInfo, _ZN17CWidgetPlayerInfoD2Ev, _ZN17CWidgetPlayerInfo, _ZTV17CWidgetPlayerInfo);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(CWidgetPlayerInfo, CoordsAreInsideWidget, _ZTV17CWidgetPlayerInfo, 3, bool, CVector2D const& pos, bool enabled)
    DECL_VIRTUALCALL_TAIL(pos, enabled)
    DECL_VIRTUALCALL_HEAD(CWidgetPlayerInfo, Draw, _ZTV17CWidgetPlayerInfo, 5, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetPlayerInfo, DrawHelpIcon, _ZTV17CWidgetPlayerInfo, 4, void, char const* text, float value1, float value2, float value3, i32 index)
    DECL_VIRTUALCALL_TAIL(text, value1, value2, value3, index)
    DECL_VIRTUALCALL_HEAD(CWidgetPlayerInfo, GetName, _ZTV17CWidgetPlayerInfo, 2, char const*)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetPlayerInfo, IsHeldDown, _ZTV17CWidgetPlayerInfo, 11, bool)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetPlayerInfo, IsSwipedLeft, _ZTV17CWidgetPlayerInfo, 17, bool)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetPlayerInfo, IsSwipedRight, _ZTV17CWidgetPlayerInfo, 18, bool)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetPlayerInfo, Update, _ZTV17CWidgetPlayerInfo, 33, void)
    DECL_VIRTUALCALL_TAIL()

    // Member functions
    DECL_THISCALL_HEAD(DrawAmmo, _ZN17CWidgetPlayerInfo8DrawAmmoEP4CPed5CRectf, void, CPed* ped, CRect rect, float value)
    DECL_THISCALL_TAIL(DrawAmmo, ped, rect, value)
    DECL_THISCALL_SIMPLE(DrawWanted, _ZN17CWidgetPlayerInfo10DrawWantedEv, void);
    DECL_THISCALL_HEAD(DrawWeaponIcon, _ZN17CWidgetPlayerInfo14DrawWeaponIconEP4CPed5CRectf, void, CPed* ped, CRect rect, float value)
    DECL_THISCALL_TAIL(DrawWeaponIcon, ped, rect, value)
    DECL_THISCALL_SIMPLE(PassesDisplayConditions, _ZN17CWidgetPlayerInfo23PassesDisplayConditionsEv, bool);
    DECL_THISCALL_HEAD(RenderArmorBar, _ZN17CWidgetPlayerInfo14RenderArmorBarEif, void, i32 index, float value)
    DECL_THISCALL_TAIL(RenderArmorBar, index, value)
    DECL_THISCALL_HEAD(RenderBreathBar, _ZN17CWidgetPlayerInfo15RenderBreathBarEif, void, i32 index, float value)
    DECL_THISCALL_TAIL(RenderBreathBar, index, value)
    DECL_THISCALL_HEAD(RenderHealthBar, _ZN17CWidgetPlayerInfo15RenderHealthBarEif, void, i32 index, float value)
    DECL_THISCALL_TAIL(RenderHealthBar, index, value)

    // Member values
    i32 m_LastWanted;
    u32 m_LastBreathTime;
    CRect m_RectWeapon;
    float m_fSwipeLeftTime;
    float m_fSwipeRightTime;
    CSprite2d m_SpriteSwipe;
    bool m_bAltDrawingMode;
DECL_CLASS_END()
CHECKSIZE(CWidgetPlayerInfo, 0xb8, 0xd8);

DECL_CLASS_BASED(CWidgetPool, CWidget)
    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CWidgetPool, _ZN11CWidgetPoolC2EPKcRK14WidgetPosition, char const* textureName, WidgetPosition const& position)
    DECL_CTORCALL_ARG_TAIL(textureName, position)
    DECL_DTORCALL_VIRTUAL_VTABLE(CWidgetPool, _ZN11CWidgetPool, _ZTV11CWidgetPool);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(CWidgetPool, Draw, _ZTV11CWidgetPool, 5, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetPool, GetName, _ZTV11CWidgetPool, 2, char const*)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetPool, SetWidgetInfo2, _ZTV11CWidgetPool, 32, void, i32 index1, i32 index2, i32 index3, i32 index4, char* text1, char* text2)
    DECL_VIRTUALCALL_TAIL(index1, index2, index3, index4, text1, text2)
    DECL_VIRTUALCALL_HEAD(CWidgetPool, Update, _ZTV11CWidgetPool, 33, void)
    DECL_VIRTUALCALL_TAIL()

    // Member values
    SDataCell m_DataCell[2];
DECL_CLASS_END()
CHECKSIZE(CWidgetPool, 0x2a8, 0x2c0);

DECL_CLASS_BASED(CWidgetRaceResults, CWidget)
    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CWidgetRaceResults, _ZN18CWidgetRaceResultsC2EPKcRK14WidgetPosition, char const* textureName, WidgetPosition const& position)
    DECL_CTORCALL_ARG_TAIL(textureName, position)
    DECL_DTORCALL_VIRTUAL_VTABLE(CWidgetRaceResults, _ZN18CWidgetRaceResults, _ZTV18CWidgetRaceResults);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(CWidgetRaceResults, Draw, _ZTV18CWidgetRaceResults, 5, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetRaceResults, GetName, _ZTV18CWidgetRaceResults, 2, char const*)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetRaceResults, SetWidgetInfo2, _ZTV18CWidgetRaceResults, 32, void, i32 index1, i32 index2, i32 index3, i32 index4, char* text1, char* text2)
    DECL_VIRTUALCALL_TAIL(index1, index2, index3, index4, text1, text2)
    DECL_VIRTUALCALL_HEAD(CWidgetRaceResults, Update, _ZTV18CWidgetRaceResults, 33, void)
    DECL_VIRTUALCALL_TAIL()

    // Member functions
    DECL_THISCALL_HEAD(RenderTitleText, _ZN18CWidgetRaceResults15RenderTitleTextE5CRectf, void, CRect rect, float value)
    DECL_THISCALL_TAIL(RenderTitleText, rect, value)

    // Member values
    SDataCell m_DataCell[5];
    char m_szTitle[128];
DECL_CLASS_END()
CHECKSIZE(CWidgetRaceResults, 0x64c, 0x660);

DECL_CLASS_BASED(CWidgetRacing, CWidget)
    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CWidgetRacing, _ZN13CWidgetRacingC2EPKcRK14WidgetPosition, char const* textureName, WidgetPosition const& position)
    DECL_CTORCALL_ARG_TAIL(textureName, position)
    DECL_DTORCALL_VIRTUAL_VTABLE(CWidgetRacing, _ZN13CWidgetRacing, _ZTV13CWidgetRacing);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(CWidgetRacing, Draw, _ZTV13CWidgetRacing, 5, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetRacing, GetName, _ZTV13CWidgetRacing, 2, char const*)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetRacing, SetWidgetValue2, _ZTV13CWidgetRacing, 29, void, float value1, float value2)
    DECL_VIRTUALCALL_TAIL(value1, value2)
    DECL_VIRTUALCALL_HEAD(CWidgetRacing, SetWidgetValue3, _ZTV13CWidgetRacing, 30, void, float value1, float value2, float value3)
    DECL_VIRTUALCALL_TAIL(value1, value2, value3)
    DECL_VIRTUALCALL_HEAD(CWidgetRacing, Update, _ZTV13CWidgetRacing, 33, void)
    DECL_VIRTUALCALL_TAIL()

    // Member functions
    DECL_THISCALL_HEAD(RenderRowText, _ZN13CWidgetRacing13RenderRowTextEPKc5CRectS1_f, void, char const* text1, CRect rect, char const* text2, float value)
    DECL_THISCALL_TAIL(RenderRowText, text1, rect, text2, value)

    // Member values
    i32 m_nPlace;
    i32 m_nOpponents;
    i32 m_nCurrentLap;
    i32 m_nMaxLaps;
    i32 m_nTimeInSeconds;
DECL_CLASS_END()
CHECKSIZE(CWidgetRacing, 0xa4, 0xb8);

DECL_CLASS_BASED(CWidgetRadar, CWidget)
    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CWidgetRadar, _ZN12CWidgetRadarC2EPKcRK14WidgetPosition, char const* textureName, WidgetPosition const& position)
    DECL_CTORCALL_ARG_TAIL(textureName, position)
    DECL_DTORCALL_VIRTUAL(CWidgetRadar, _ZN12CWidgetRadarD2Ev, _ZN12CWidgetRadar, _ZTV12CWidgetRadar);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(CWidgetRadar, GetName, _ZTV12CWidgetRadar, 2, char const*)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetRadar, IsHeldDown, _ZTV12CWidgetRadar, 11, bool)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetRadar, Update, _ZTV12CWidgetRadar, 33, void)
    DECL_VIRTUALCALL_TAIL()

    // Member values
    CSprite2d mSpriteCrossHairs;
DECL_CLASS_END()
CHECKSIZE(CWidgetRadar, 0x94, 0xb0);

DECL_CLASS_BASED(CWidgetRegion, CWidget)
    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CWidgetRegion, _ZN13CWidgetRegionC2EPKcRK14WidgetPositioni10HIDMapping, char const* textureName, WidgetPosition const& position, i32 value, HIDMapping mapping)
    DECL_CTORCALL_ARG_TAIL(textureName, position, value, mapping)
    DECL_DTORCALL_VIRTUAL_VTABLE(CWidgetRegion, _ZN13CWidgetRegion, _ZTV13CWidgetRegion);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(CWidgetRegion, Draw, _ZTV13CWidgetRegion, 5, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetRegion, GetName, _ZTV13CWidgetRegion, 2, char const*)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetRegion, IsRegion, _ZTV13CWidgetRegion, 14, bool)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetRegion, Update, _ZTV13CWidgetRegion, 33, void)
    DECL_VIRTUALCALL_TAIL()

    // Member functions
    DECL_THISCALL_HEAD(DrawFrame, _ZN13CWidgetRegion9DrawFrameEf5CRectf, void, float value1, CRect rect, float value2)
    DECL_THISCALL_TAIL(DrawFrame, value1, rect, value2)
    DECL_THISCALL_HEAD(StretchX, _ZN13CWidgetRegion8StretchXEf, float, float value)
    DECL_THISCALL_TAIL(StretchX, value)
    DECL_THISCALL_HEAD(StretchY, _ZN13CWidgetRegion8StretchYEf, float, float value)
    DECL_THISCALL_TAIL(StretchY, value)

DECL_CLASS_END()
CHECKSIZE(CWidgetRegion, 0x90, 0xa8);

DECL_CLASS_BASED(CWidgetReplay, CWidget)
    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CWidgetReplay, _ZN13CWidgetReplayC2EPKcRK14WidgetPosition, char const* textureName, WidgetPosition const& position)
    DECL_CTORCALL_ARG_TAIL(textureName, position)
    DECL_DTORCALL_VIRTUAL(CWidgetReplay, _ZN13CWidgetReplayD2Ev, _ZN13CWidgetReplay, _ZTV13CWidgetReplay);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(CWidgetReplay, GetName, _ZTV13CWidgetReplay, 2, char const*)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetReplay, Update, _ZTV13CWidgetReplay, 33, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetReplay, Draw, _ZTV13CWidgetReplay, 5, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetReplay, OnReleasedTouch, _ZTV13CWidgetReplay, 23, void)
    DECL_VIRTUALCALL_TAIL()

    // Member functions
    DECL_THISCALL_SIMPLE(ForceStopRecording, _ZN13CWidgetReplay18ForceStopRecordingEv, void);

    // Member values
    CSprite2d mSpriteCrossHairs;
    bool ResponseWidgetActive;
    bool GangWidgetActive;
    bool waitingForSave;
    bool screenRecordingTouched;
    bool displayingRecordingTexture;
    u32 startRecordTime;
DECL_CLASS_END()
CHECKSIZE(CWidgetReplay, 0xa0, 0xc0);

DECL_CLASS_BASED(CWidgetRouletteSpin, CWidget)
    // Construct/Deconstruct functions
    DECL_CTORCALL(CWidgetRouletteSpin, _ZN19CWidgetRouletteSpinC2Ev);
    DECL_DTORCALL_VIRTUAL(CWidgetRouletteSpin, _ZN19CWidgetRouletteSpinD2Ev, _ZN19CWidgetRouletteSpin, _ZTV19CWidgetRouletteSpin);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(CWidgetRouletteSpin, Draw, _ZTV19CWidgetRouletteSpin, 5, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetRouletteSpin, GetName, _ZTV19CWidgetRouletteSpin, 2, char const*)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetRouletteSpin, SetWidgetValue2, _ZTV19CWidgetRouletteSpin, 29, void, float value1, float value2)
    DECL_VIRTUALCALL_TAIL(value1, value2)
    DECL_VIRTUALCALL_HEAD(CWidgetRouletteSpin, Update, _ZTV19CWidgetRouletteSpin, 33, void)
    DECL_VIRTUALCALL_TAIL()

    // Member values
    CSprite2d m_SpriteBallColor;
    i32 m_nBallNumber;
DECL_CLASS_END()
CHECKSIZE(CWidgetRouletteSpin, 0x98, 0xb8);

DECL_CLASS_BASED(CWidgetSaveNotification, CWidget)
    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CWidgetSaveNotification, _ZN23CWidgetSaveNotificationC2EPKcRK14WidgetPosition, char const* textureName, WidgetPosition const& position)
    DECL_CTORCALL_ARG_TAIL(textureName, position)
    DECL_DTORCALL_VIRTUAL_VTABLE(CWidgetSaveNotification, _ZN23CWidgetSaveNotification, _ZTV23CWidgetSaveNotification);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(CWidgetSaveNotification, Draw, _ZTV23CWidgetSaveNotification, 5, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetSaveNotification, GetName, _ZTV23CWidgetSaveNotification, 2, char const*)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetSaveNotification, Update, _ZTV23CWidgetSaveNotification, 33, void)
    DECL_VIRTUALCALL_TAIL()

    // Member functions
    DECL_THISCALL_SIMPLE(EndSave, _ZN23CWidgetSaveNotification7EndSaveEv, void);

    // Member values
    float m_fTimeRemaining;
    float m_fTimeEnabled;
DECL_CLASS_END()
CHECKSIZE(CWidgetSaveNotification, 0x98, 0xb0);

DECL_CLASS_BASED(CWidgetSlider, CWidget)
    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CWidgetSlider, _ZN13CWidgetSliderC2EPKcRK14WidgetPositionjjjN15CTouchInterface9WidgetIDsES6_, char const* textureName, WidgetPosition const& position, u32 flags1, u32 flags2, u32 flags3, CTouchInterface::WidgetIDs value1, CTouchInterface::WidgetIDs value2)
    DECL_CTORCALL_ARG_TAIL(textureName, position, flags1, flags2, flags3, value1, value2)
    DECL_DTORCALL_VIRTUAL(CWidgetSlider, _ZN13CWidgetSliderD2Ev, _ZN13CWidgetSlider, _ZTV13CWidgetSlider);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(CWidgetSlider, Draw, _ZTV13CWidgetSlider, 5, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetSlider, GetName, _ZTV13CWidgetSlider, 2, char const*)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetSlider, GetWidgetValue, _ZTV13CWidgetSlider, 7, float)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetSlider, Update, _ZTV13CWidgetSlider, 33, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetSlider, SetSliderRange, _ZTV13CWidgetSlider, 27, void, float value1, float value2)
    DECL_VIRTUALCALL_TAIL(value1, value2)
    DECL_VIRTUALCALL_HEAD(CWidgetSlider, SetWidgetValue, _ZTV13CWidgetSlider, 28, void, float value)
    DECL_VIRTUALCALL_TAIL(value)

    // STATIC values
    static constexpr i32 SLIDER_FLAGS_SHOW_NOTCHES = 1;
    static constexpr i32 SLIDER_FLAGS_ALLOW_RANDOM_ACCESS = 2;
    static constexpr i32 SLIDER_FLAGS_SHOW_FLOATS = 4;
    static constexpr i32 SLIDER_FLAGS_SHOW_INTS = 8;
    static constexpr i32 SLIDER_FLAGS_SHOW_PCT = 16;
    static constexpr i32 SLIDER_FLAGS_SHOW_NONE = 32;
    static constexpr i32 SLIDER_FLAGS_HAS_CONTROL_BUTTONS = 64;

    // Member functions
    DECL_THISCALL_SIMPLE(GetNotchedValue, _ZN13CWidgetSlider15GetNotchedValueEv, float);
    DECL_THISCALL_SIMPLE(GetTweenedValue, _ZN13CWidgetSlider15GetTweenedValueEv, float);
    DECL_THISCALL_HEAD(SetupNotches, _ZN13CWidgetSlider12SetupNotchesEiff, void, i32 index, float value1, float value2)
    DECL_THISCALL_TAIL(SetupNotches, index, value1, value2)

    // Member values
    i32 m_nNotches;
    float m_fNotchValues[100];
    float m_fSliderPosition;
    i32 m_nCurrentNotch;
    u32 m_nSliderFlags;
    CSprite2d m_SpriteThumb;
    CSprite2d m_SpriteNotch;
    CRect m_RectBar;
    CTouchInterface::WidgetIDs m_LeftControlButtonID;
    CTouchInterface::WidgetIDs m_RightControlButtonID;
    CRGBA m_ColorBar;
    CRGBA m_ColorThumb;
DECL_CLASS_END()
CHECKSIZE(CWidgetSlider, 0x258, 0x278);

DECL_CLASS_BASED(CWidgetTapMeter, CWidget)
    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CWidgetTapMeter, _ZN15CWidgetTapMeterC2EPKcRK14WidgetPosition, char const* textureName, WidgetPosition const& position)
    DECL_CTORCALL_ARG_TAIL(textureName, position)
    DECL_DTORCALL_VIRTUAL_VTABLE(CWidgetTapMeter, _ZN15CWidgetTapMeter, _ZTV15CWidgetTapMeter);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(CWidgetTapMeter, Draw, _ZTV15CWidgetTapMeter, 5, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetTapMeter, GetName, _ZTV15CWidgetTapMeter, 2, char const*)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetTapMeter, IsReleased, _ZTV15CWidgetTapMeter, 13, bool, CVector2D* value)
    DECL_VIRTUALCALL_TAIL(value)
    DECL_VIRTUALCALL_HEAD(CWidgetTapMeter, SetWidgetValue, _ZTV15CWidgetTapMeter, 28, void, float value)
    DECL_VIRTUALCALL_TAIL(value)
    DECL_VIRTUALCALL_HEAD(CWidgetTapMeter, Update, _ZTV15CWidgetTapMeter, 33, void)
    DECL_VIRTUALCALL_TAIL()

    // STATIC values
    static constexpr i32 STATE_ANIMATING = 0;
    static constexpr i32 STATE_DISPLAYING_RESULTS = 1;

    // Member functions
    DECL_THISCALL_SIMPLE(RespondToTap, _ZN15CWidgetTapMeter12RespondToTapEv, bool);

    // Member values
    i32 m_nState;
    float m_fStateTime;
    float m_fLevel;
    float m_fLevelInc;
    float m_fLevelRate;
    float m_fSuccessLevelMin;
    float m_fSuccessLevelMax;
    CRect m_RectClient;
DECL_CLASS_END()
CHECKSIZE(CWidgetTapMeter, 0xbc, 0xd0);

DECL_CLASS_BASED(CWidgetThumbCircle, CWidget)
    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CWidgetThumbCircle, _ZN18CWidgetThumbCircleC2EPKcRK14WidgetPosition, char const* textureName, WidgetPosition const& position)
    DECL_CTORCALL_ARG_TAIL(textureName, position)
    DECL_DTORCALL_VIRTUAL(CWidgetThumbCircle, _ZN18CWidgetThumbCircleD2Ev, _ZN18CWidgetThumbCircle, _ZTV18CWidgetThumbCircle);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(CWidgetThumbCircle, Draw, _ZTV18CWidgetThumbCircle, 5, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetThumbCircle, GetName, _ZTV18CWidgetThumbCircle, 2, char const*)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetThumbCircle, GetWidgetValue, _ZTV18CWidgetThumbCircle, 7, float)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetThumbCircle, OnInitialTouch, _ZTV18CWidgetThumbCircle, 21, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetThumbCircle, SetWidgetValue, _ZTV18CWidgetThumbCircle, 28, void, float value)
    DECL_VIRTUALCALL_TAIL(value)
    DECL_VIRTUALCALL_HEAD(CWidgetThumbCircle, Update, _ZTV18CWidgetThumbCircle, 33, void)
    DECL_VIRTUALCALL_TAIL()

    // Member values
    CSprite2d m_SpriteIndicator;
    CVector2D m_vecIndicatorOrigin;
    CVector2D m_vecMouseToOrigin;
    CRect m_RectClient;
    CRect m_RectTop;
    CRect m_RectBottom;
    float m_fPower;
    float m_fLosePowerRate;
    float m_fGainPowerRate;
    float m_fDragDirection;
    i32 m_nLastSubsection;
DECL_CLASS_END()
CHECKSIZE(CWidgetThumbCircle, 0xe8, 0x108);

DECL_CLASS_BASED(CWidgetVitalStats, CWidget)
    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CWidgetVitalStats, _ZN17CWidgetVitalStatsC2EPKcRK14WidgetPosition, char const* textureName, WidgetPosition const& position)
    DECL_CTORCALL_ARG_TAIL(textureName, position)
    DECL_DTORCALL_VIRTUAL_VTABLE(CWidgetVitalStats, _ZN17CWidgetVitalStats, _ZTV17CWidgetVitalStats);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(CWidgetVitalStats, Draw, _ZTV17CWidgetVitalStats, 5, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetVitalStats, GetName, _ZTV17CWidgetVitalStats, 2, char const*)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetVitalStats, Update, _ZTV17CWidgetVitalStats, 33, void)
    DECL_VIRTUALCALL_TAIL()

DECL_CLASS_END()
CHECKSIZE(CWidgetVitalStats, 0x90, 0xa8);

DECL_CLASS_BASED(CWidgetWager, CWidget)
    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CWidgetWager, _ZN12CWidgetWagerC2EPKcRK14WidgetPosition, char const* textureName, WidgetPosition const& position)
    DECL_CTORCALL_ARG_TAIL(textureName, position)
    DECL_DTORCALL_VIRTUAL_VTABLE(CWidgetWager, _ZN12CWidgetWager, _ZTV12CWidgetWager);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(CWidgetWager, Draw, _ZTV12CWidgetWager, 5, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetWager, GetName, _ZTV12CWidgetWager, 2, char const*)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetWager, SetWidgetInfo2, _ZTV12CWidgetWager, 32, void, i32 index1, i32 index2, i32 index3, i32 index4, char* text1, char* text2)
    DECL_VIRTUALCALL_TAIL(index1, index2, index3, index4, text1, text2)
    DECL_VIRTUALCALL_HEAD(CWidgetWager, SetWidgetValue, _ZTV12CWidgetWager, 28, void, float value)
    DECL_VIRTUALCALL_TAIL(value)
    DECL_VIRTUALCALL_HEAD(CWidgetWager, Update, _ZTV12CWidgetWager, 33, void)
    DECL_VIRTUALCALL_TAIL()

    // Member functions
    DECL_THISCALL_HEAD(RenderRowText, _ZN12CWidgetWager13RenderRowTextEPtS0_5CRectif, void, u16* text1, u16* text2, CRect rect, i32 index, float value)
    DECL_THISCALL_TAIL(RenderRowText, text1, text2, rect, index, value)
    DECL_THISCALL_HEAD(RenderTitleText, _ZN12CWidgetWager15RenderTitleTextE5CRectf, void, CRect rect, float value)
    DECL_THISCALL_TAIL(RenderTitleText, rect, value)

    // Member values
    char m_szTitle[128];
    SDataCell m_DataCell[4];
    bool m_bExtraCell;
DECL_CLASS_END()
CHECKSIZE(CWidgetWager, 0x544, 0x558);

DECL_CLASS_BASED(CWidgetButtonAnimated, CWidgetButton)
    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CWidgetButtonAnimated, _ZN21CWidgetButtonAnimatedC2EPKcS1_RK14WidgetPositionjjS1_10HIDMapping, char const* textureName1, char const* textureName2, WidgetPosition const& position, u32 flags1, u32 flags2, char const* textureName3, HIDMapping mapping)
    DECL_CTORCALL_ARG_TAIL(textureName1, textureName2, position, flags1, flags2, textureName3, mapping)
    DECL_DTORCALL_VIRTUAL(CWidgetButtonAnimated, _ZN21CWidgetButtonAnimatedD2Ev, _ZN21CWidgetButtonAnimated, _ZTV21CWidgetButtonAnimated);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(CWidgetButtonAnimated, GetName, _ZTV21CWidgetButtonAnimated, 2, char const*)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetButtonAnimated, Draw, _ZTV21CWidgetButtonAnimated, 5, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetButtonAnimated, GetWidgetValue, _ZTV21CWidgetButtonAnimated, 7, float)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetButtonAnimated, SetWidgetValue, _ZTV21CWidgetButtonAnimated, 28, void, float value)
    DECL_VIRTUALCALL_TAIL(value)
    DECL_VIRTUALCALL_HEAD(CWidgetButtonAnimated, SetWidgetValue2, _ZTV21CWidgetButtonAnimated, 29, void, float value1, float value2)
    DECL_VIRTUALCALL_TAIL(value1, value2)
    DECL_VIRTUALCALL_HEAD(CWidgetButtonAnimated, Update, _ZTV21CWidgetButtonAnimated, 33, void)
    DECL_VIRTUALCALL_TAIL()

    // STATIC functions
    DECL_FASTCALL_SIMPLE(AnyObjectEnabled, _ZN21CWidgetButtonAnimated16AnyObjectEnabledEv, bool);

    // STATIC values
    DECL_OBJECT_PLT(CWidgetButtonAnimated*, m_pChainHead, BYBIT(0x677878, 0x84d118));
    DECL_OBJECT_PLT(CWidgetButtonAnimated*, m_pChainTail, BYBIT(0x678504, 0x84ea20));

    // Member values
    CWidgetButtonAnimated* m_pPrev;
    CWidgetButtonAnimated* m_pNext;
    CSprite2d m_SpriteDepressed;
    char m_szText[256];
    CRGBA m_TextColor;
    float m_fTextPctY;
    HIDMapping m_HIDMappingInitial;
DECL_CLASS_END()
CHECKSIZE(CWidgetButtonAnimated, 0x1c0, 0x1f0);

DECL_CLASS_BASED(CWidgetButtonAttack, CWidgetButton)
    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CWidgetButtonAttack, _ZN19CWidgetButtonAttackC2EPKcRK14WidgetPosition, char const* textureName, WidgetPosition const& position)
    DECL_CTORCALL_ARG_TAIL(textureName, position)
    DECL_DTORCALL_VIRTUAL_VTABLE(CWidgetButtonAttack, _ZN19CWidgetButtonAttack, _ZTV19CWidgetButtonAttack);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(CWidgetButtonAttack, GetName, _ZTV19CWidgetButtonAttack, 2, char const*)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetButtonAttack, Update, _ZTV19CWidgetButtonAttack, 33, void)
    DECL_VIRTUALCALL_TAIL()

    // STATIC functions
    DECL_FASTCALL_SIMPLE(GetTextureName, _ZN19CWidgetButtonAttack14GetTextureNameEv, char const*);

DECL_CLASS_END()
CHECKSIZE(CWidgetButtonAttack, 0xa8, 0xc8);

DECL_CLASS_BASED(CWidgetButtonAutoHydraulics, CWidgetButton)
    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CWidgetButtonAutoHydraulics, _ZN27CWidgetButtonAutoHydraulicsC2EPKcRK14WidgetPosition, char const* textureName, WidgetPosition const& position)
    DECL_CTORCALL_ARG_TAIL(textureName, position)
    DECL_DTORCALL_VIRTUAL_VTABLE(CWidgetButtonAutoHydraulics, _ZN27CWidgetButtonAutoHydraulics, _ZTV27CWidgetButtonAutoHydraulics);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(CWidgetButtonAutoHydraulics, GetName, _ZTV27CWidgetButtonAutoHydraulics, 2, char const*)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetButtonAutoHydraulics, Update, _ZTV27CWidgetButtonAutoHydraulics, 33, void)
    DECL_VIRTUALCALL_TAIL()

    // Member values
    u8 m_bIsPlayerOnAMission;
DECL_CLASS_END()
CHECKSIZE(CWidgetButtonAutoHydraulics, 0xac, 0xc8);

DECL_CLASS_BASED(CWidgetButtonBasketballShoot, CWidgetButton)
    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CWidgetButtonBasketballShoot, _ZN28CWidgetButtonBasketballShootC2EPKcRK14WidgetPosition, char const* textureName, WidgetPosition const& position)
    DECL_CTORCALL_ARG_TAIL(textureName, position)
    DECL_DTORCALL_VIRTUAL_VTABLE(CWidgetButtonBasketballShoot, _ZN28CWidgetButtonBasketballShoot, _ZTV28CWidgetButtonBasketballShoot);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(CWidgetButtonBasketballShoot, GetName, _ZTV28CWidgetButtonBasketballShoot, 2, char const*)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetButtonBasketballShoot, Update, _ZTV28CWidgetButtonBasketballShoot, 33, void)
    DECL_VIRTUALCALL_TAIL()

DECL_CLASS_END()
CHECKSIZE(CWidgetButtonBasketballShoot, 0xa8, 0xc8);

DECL_CLASS_BASED(CWidgetButtonDrop, CWidgetButton)
    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CWidgetButtonDrop, _ZN17CWidgetButtonDropC2EPKcRK14WidgetPosition10HIDMapping, char const* textureName, WidgetPosition const& position, HIDMapping mapping)
    DECL_CTORCALL_ARG_TAIL(textureName, position, mapping)
    DECL_DTORCALL_VIRTUAL_VTABLE(CWidgetButtonDrop, _ZN17CWidgetButtonDrop, _ZTV17CWidgetButtonDrop);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(CWidgetButtonDrop, GetName, _ZTV17CWidgetButtonDrop, 2, char const*)
    DECL_VIRTUALCALL_TAIL()

DECL_CLASS_END()
CHECKSIZE(CWidgetButtonDrop, 0xa8, 0xc8);

DECL_CLASS_BASED(CWidgetButtonEnterCar, CWidgetButton)
    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CWidgetButtonEnterCar, _ZN21CWidgetButtonEnterCarC2EPKcRK14WidgetPosition, char const* textureName, WidgetPosition const& position)
    DECL_CTORCALL_ARG_TAIL(textureName, position)
    DECL_DTORCALL_VIRTUAL(CWidgetButtonEnterCar, _ZN21CWidgetButtonEnterCarD2Ev, _ZN21CWidgetButtonEnterCar, _ZTV21CWidgetButtonEnterCar);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(CWidgetButtonEnterCar, GetName, _ZTV21CWidgetButtonEnterCar, 2, char const*)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetButtonEnterCar, Draw, _ZTV21CWidgetButtonEnterCar, 5, void)
    DECL_VIRTUALCALL_TAIL()

    // Member functions
    DECL_THISCALL_HEAD(SetEnterCarVehicleType, _ZN21CWidgetButtonEnterCar22SetEnterCarVehicleTypeEiibRK7CVectori, void, i32 index1, i32 index2, bool enabled, CVector const& pos, i32 index3)
    DECL_THISCALL_TAIL(SetEnterCarVehicleType, index1, index2, enabled, pos, index3)

    // Member values
    float m_fRadians;
    CRect m_RectDot;
    CSprite2d m_SpriteIndicator;
DECL_CLASS_END()
CHECKSIZE(CWidgetButtonEnterCar, 0xc0, 0xe0);

DECL_CLASS_BASED(CWidgetButtonHelpText, CWidgetButton)
    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CWidgetButtonHelpText, _ZN21CWidgetButtonHelpTextC2EPKcRK14WidgetPosition, char const* textureName, WidgetPosition const& position)
    DECL_CTORCALL_ARG_TAIL(textureName, position)
    DECL_DTORCALL_VIRTUAL_VTABLE(CWidgetButtonHelpText, _ZN21CWidgetButtonHelpText, _ZTV21CWidgetButtonHelpText);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(CWidgetButtonHelpText, Draw, _ZTV21CWidgetButtonHelpText, 5, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetButtonHelpText, GetName, _ZTV21CWidgetButtonHelpText, 2, char const*)
    DECL_VIRTUALCALL_TAIL()

DECL_CLASS_END()
CHECKSIZE(CWidgetButtonHelpText, 0xa8, 0xc8);

DECL_CLASS_BASED(CWidgetButtonHorn, CWidgetButton)
    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CWidgetButtonHorn, _ZN17CWidgetButtonHornC2EPKcRK14WidgetPosition, char const* textureName, WidgetPosition const& position)
    DECL_CTORCALL_ARG_TAIL(textureName, position)
    DECL_DTORCALL_VIRTUAL_VTABLE(CWidgetButtonHorn, _ZN17CWidgetButtonHorn, _ZTV17CWidgetButtonHorn);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(CWidgetButtonHorn, GetName, _ZTV17CWidgetButtonHorn, 2, char const*)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetButtonHorn, Update, _ZTV17CWidgetButtonHorn, 33, void)
    DECL_VIRTUALCALL_TAIL()

    // Member functions
    DECL_THISCALL_SIMPLE(SetupPositionAndScale, _ZN17CWidgetButtonHorn21SetupPositionAndScaleEv, void);

DECL_CLASS_END()
CHECKSIZE(CWidgetButtonHorn, 0xa8, 0xc8);

DECL_CLASS_BASED(CWidgetButtonHydraulics, CWidgetButton)
    enum HydraulicStates
    {
        INACTIVE = 0,
        FRONT_2_ACTIVE = 1,
        BACK_2_ACTIVE = 2,
        LEFT_2_ACTIVE = 3,
        RIGHT_2_ACTIVE = 4,
        FRONT_LEFT_ACTIVE = 5,
        FRONT_RIGHT_ACTIVE = 6,
        BACK_LEFT_ACTIVE = 7,
        BACK_RIGHT_ACTIVE = 8,
        NUM_STATES = 9
    };

    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CWidgetButtonHydraulics, _ZN23CWidgetButtonHydraulicsC2EPKcRK14WidgetPosition, char const* textureName, WidgetPosition const& position)
    DECL_CTORCALL_ARG_TAIL(textureName, position)
    DECL_DTORCALL_VIRTUAL(CWidgetButtonHydraulics, _ZN23CWidgetButtonHydraulicsD2Ev, _ZN23CWidgetButtonHydraulics, _ZTV23CWidgetButtonHydraulics);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(CWidgetButtonHydraulics, GetName, _ZTV23CWidgetButtonHydraulics, 2, char const*)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetButtonHydraulics, Draw, _ZTV23CWidgetButtonHydraulics, 5, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetButtonHydraulics, Update, _ZTV23CWidgetButtonHydraulics, 33, void)
    DECL_VIRTUALCALL_TAIL()

    // Member values
    i32 m_eHydraulicState;
    bool m_bLocked;
    bool m_bHasHydraulics;
    float fRadians;
    float fCurRadians;
    CVector2D vCurrAnchor;
    CVector2D vCurrPoint;
    CSprite2d m_SpriteLock;
DECL_CLASS_END()
CHECKSIZE(CWidgetButtonHydraulics, 0xcc, 0xf0);

DECL_CLASS_BASED(CWidgetButtonMissionCancel, CWidgetButton)
    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CWidgetButtonMissionCancel, _ZN26CWidgetButtonMissionCancelC2EPKcRK14WidgetPosition10HIDMapping, char const* textureName, WidgetPosition const& position, HIDMapping mapping)
    DECL_CTORCALL_ARG_TAIL(textureName, position, mapping)
    DECL_DTORCALL_VIRTUAL_VTABLE(CWidgetButtonMissionCancel, _ZN26CWidgetButtonMissionCancel, _ZTV26CWidgetButtonMissionCancel);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(CWidgetButtonMissionCancel, GetName, _ZTV26CWidgetButtonMissionCancel, 2, char const*)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetButtonMissionCancel, Update, _ZTV26CWidgetButtonMissionCancel, 33, void)
    DECL_VIRTUALCALL_TAIL()

DECL_CLASS_END()
CHECKSIZE(CWidgetButtonMissionCancel, 0xa8, 0xc8);

DECL_CLASS_BASED(CWidgetButtonMissionStart, CWidgetButton)
    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CWidgetButtonMissionStart, _ZN25CWidgetButtonMissionStartC2EPKcRK14WidgetPosition10HIDMapping, char const* textureName, WidgetPosition const& position, HIDMapping mapping)
    DECL_CTORCALL_ARG_TAIL(textureName, position, mapping)
    DECL_DTORCALL_VIRTUAL_VTABLE(CWidgetButtonMissionStart, _ZN25CWidgetButtonMissionStart, _ZTV25CWidgetButtonMissionStart);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(CWidgetButtonMissionStart, GetName, _ZTV25CWidgetButtonMissionStart, 2, char const*)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetButtonMissionStart, Update, _ZTV25CWidgetButtonMissionStart, 33, void)
    DECL_VIRTUALCALL_TAIL()

DECL_CLASS_END()
CHECKSIZE(CWidgetButtonMissionStart, 0xa8, 0xc8);

DECL_CLASS_BASED(CWidgetButtonRocket, CWidgetButton)
    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CWidgetButtonRocket, _ZN19CWidgetButtonRocketC2EPKcRK14WidgetPosition, char const* textureName, WidgetPosition const& position)
    DECL_CTORCALL_ARG_TAIL(textureName, position)
    DECL_DTORCALL_VIRTUAL_VTABLE(CWidgetButtonRocket, _ZN19CWidgetButtonRocket, _ZTV19CWidgetButtonRocket);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(CWidgetButtonRocket, GetName, _ZTV19CWidgetButtonRocket, 2, char const*)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetButtonRocket, Update, _ZTV19CWidgetButtonRocket, 33, void)
    DECL_VIRTUALCALL_TAIL()

DECL_CLASS_END()
CHECKSIZE(CWidgetButtonRocket, 0xa8, 0xc8);

DECL_CLASS_BASED(CWidgetButtonSchool, CWidgetButton)
    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CWidgetButtonSchool, _ZN19CWidgetButtonSchoolC2EPKcRK14WidgetPositionS1_i10HIDMapping, char const* textureName1, WidgetPosition const& position, char const* textureName2, i32 value, HIDMapping mapping)
    DECL_CTORCALL_ARG_TAIL(textureName1, position, textureName2, value, mapping)
    DECL_DTORCALL_VIRTUAL_VTABLE(CWidgetButtonSchool, _ZN19CWidgetButtonSchool, _ZTV19CWidgetButtonSchool);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(CWidgetButtonSchool, GetName, _ZTV19CWidgetButtonSchool, 2, char const*)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetButtonSchool, Draw, _ZTV19CWidgetButtonSchool, 5, void)
    DECL_VIRTUALCALL_TAIL()

    // Member values
    char m_szText[256];
DECL_CLASS_END()
CHECKSIZE(CWidgetButtonSchool, 0x1a8, 0x1c8);

DECL_CLASS_BASED(CWidgetButtonSkipCutscene, CWidgetButton)
    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CWidgetButtonSkipCutscene, _ZN25CWidgetButtonSkipCutsceneC2EPKcRK14WidgetPosition, char const* textureName, WidgetPosition const& position)
    DECL_CTORCALL_ARG_TAIL(textureName, position)
    DECL_DTORCALL_VIRTUAL_VTABLE(CWidgetButtonSkipCutscene, _ZN25CWidgetButtonSkipCutscene, _ZTV25CWidgetButtonSkipCutscene);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(CWidgetButtonSkipCutscene, Draw, _ZTV25CWidgetButtonSkipCutscene, 5, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetButtonSkipCutscene, GetName, _ZTV25CWidgetButtonSkipCutscene, 2, char const*)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetButtonSkipCutscene, Update, _ZTV25CWidgetButtonSkipCutscene, 33, void)
    DECL_VIRTUALCALL_TAIL()

DECL_CLASS_END()
CHECKSIZE(CWidgetButtonSkipCutscene, 0xa8, 0xc8);

DECL_CLASS_BASED(CWidgetButtonSprint, CWidgetButton)
    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CWidgetButtonSprint, _ZN19CWidgetButtonSprintC2EPKcRK14WidgetPosition, char const* textureName, WidgetPosition const& position)
    DECL_CTORCALL_ARG_TAIL(textureName, position)
    DECL_DTORCALL_VIRTUAL_VTABLE(CWidgetButtonSprint, _ZN19CWidgetButtonSprint, _ZTV19CWidgetButtonSprint);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(CWidgetButtonSprint, DrawHelpIcon, _ZTV19CWidgetButtonSprint, 4, void, char const* text, float value1, float value2, float value3, i32 index)
    DECL_VIRTUALCALL_TAIL(text, value1, value2, value3, index)
    DECL_VIRTUALCALL_HEAD(CWidgetButtonSprint, GetName, _ZTV19CWidgetButtonSprint, 2, char const*)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetButtonSprint, IsDoubleTapped, _ZTV19CWidgetButtonSprint, 10, bool)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetButtonSprint, Update, _ZTV19CWidgetButtonSprint, 33, void)
    DECL_VIRTUALCALL_TAIL()

DECL_CLASS_END()
CHECKSIZE(CWidgetButtonSprint, 0xa8, 0xc8);

DECL_CLASS_BASED(CWidgetButtonSwapWeapons, CWidgetButton)
    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CWidgetButtonSwapWeapons, _ZN24CWidgetButtonSwapWeaponsC2EPKcRK14WidgetPosition, char const* textureName, WidgetPosition const& position)
    DECL_CTORCALL_ARG_TAIL(textureName, position)
    DECL_DTORCALL_VIRTUAL_VTABLE(CWidgetButtonSwapWeapons, _ZN24CWidgetButtonSwapWeapons, _ZTV24CWidgetButtonSwapWeapons);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(CWidgetButtonSwapWeapons, GetName, _ZTV24CWidgetButtonSwapWeapons, 2, char const*)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetButtonSwapWeapons, Update, _ZTV24CWidgetButtonSwapWeapons, 33, void)
    DECL_VIRTUALCALL_TAIL()

DECL_CLASS_END()
CHECKSIZE(CWidgetButtonSwapWeapons, 0xa8, 0xc8);

DECL_CLASS_BASED(CWidgetButtonSwim, CWidgetButton)
    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CWidgetButtonSwim, _ZN17CWidgetButtonSwimC2EPKcRK14WidgetPosition, char const* textureName, WidgetPosition const& position)
    DECL_CTORCALL_ARG_TAIL(textureName, position)
    DECL_DTORCALL_VIRTUAL_VTABLE(CWidgetButtonSwim, _ZN17CWidgetButtonSwim, _ZTV17CWidgetButtonSwim);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(CWidgetButtonSwim, GetName, _ZTV17CWidgetButtonSwim, 2, char const*)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetButtonSwim, Update, _ZTV17CWidgetButtonSwim, 33, void)
    DECL_VIRTUALCALL_TAIL()

DECL_CLASS_END()
CHECKSIZE(CWidgetButtonSwim, 0xa8, 0xc8);

DECL_CLASS_BASED(CWidgetButtonTargeting, CWidgetButton)
    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CWidgetButtonTargeting, _ZN22CWidgetButtonTargetingC2EPKcRK14WidgetPosition, char const* textureName, WidgetPosition const& position)
    DECL_CTORCALL_ARG_TAIL(textureName, position)
    DECL_DTORCALL_VIRTUAL_VTABLE(CWidgetButtonTargeting, _ZN22CWidgetButtonTargeting, _ZTV22CWidgetButtonTargeting);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(CWidgetButtonTargeting, GetName, _ZTV22CWidgetButtonTargeting, 2, char const*)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetButtonTargeting, Update, _ZTV22CWidgetButtonTargeting, 33, void)
    DECL_VIRTUALCALL_TAIL()

DECL_CLASS_END()
CHECKSIZE(CWidgetButtonTargeting, 0xa8, 0xc8);

DECL_CLASS_BASED(CWidgetButtonVCShoot, CWidgetButton)
    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CWidgetButtonVCShoot, _ZN20CWidgetButtonVCShootC2EPKcRK14WidgetPosition, char const* textureName, WidgetPosition const& position)
    DECL_CTORCALL_ARG_TAIL(textureName, position)
    DECL_DTORCALL_VIRTUAL_VTABLE(CWidgetButtonVCShoot, _ZN20CWidgetButtonVCShoot, _ZTV20CWidgetButtonVCShoot);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(CWidgetButtonVCShoot, GetName, _ZTV20CWidgetButtonVCShoot, 2, char const*)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetButtonVCShoot, Update, _ZTV20CWidgetButtonVCShoot, 33, void)
    DECL_VIRTUALCALL_TAIL()

DECL_CLASS_END()
CHECKSIZE(CWidgetButtonVCShoot, 0xa8, 0xc8);

DECL_CLASS_BASED(CWidgetButtonVehicleShoot, CWidgetButton)
    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CWidgetButtonVehicleShoot, _ZN25CWidgetButtonVehicleShootC2EPKcRK14WidgetPosition10HIDMapping, char const* textureName, WidgetPosition const& position, HIDMapping mapping)
    DECL_CTORCALL_ARG_TAIL(textureName, position, mapping)
    DECL_DTORCALL_VIRTUAL_VTABLE(CWidgetButtonVehicleShoot, _ZN25CWidgetButtonVehicleShoot, _ZTV25CWidgetButtonVehicleShoot);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(CWidgetButtonVehicleShoot, Update, _ZTV25CWidgetButtonVehicleShoot, 33, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetButtonVehicleShoot, IsTouched, _ZTV25CWidgetButtonVehicleShoot, 20, bool, CVector2D* value)
    DECL_VIRTUALCALL_TAIL(value)
    DECL_VIRTUALCALL_HEAD(CWidgetButtonVehicleShoot, GetName, _ZTV25CWidgetButtonVehicleShoot, 2, char const*)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetButtonVehicleShoot, IsHeldDown, _ZTV25CWidgetButtonVehicleShoot, 11, bool)
    DECL_VIRTUALCALL_TAIL()

    // Member functions
    DECL_THISCALL_SIMPLE(UpdatePosition, _ZN25CWidgetButtonVehicleShoot14UpdatePositionEv, void);

DECL_CLASS_END()
CHECKSIZE(CWidgetButtonVehicleShoot, 0xa8, 0xc8);

DECL_CLASS_BASED(CWidgetButtonZoom, CWidgetButton)
    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CWidgetButtonZoom, _ZN17CWidgetButtonZoomC2EPKcRK14WidgetPosition10HIDMapping, char const* textureName, WidgetPosition const& position, HIDMapping mapping)
    DECL_CTORCALL_ARG_TAIL(textureName, position, mapping)
    DECL_DTORCALL_VIRTUAL_VTABLE(CWidgetButtonZoom, _ZN17CWidgetButtonZoom, _ZTV17CWidgetButtonZoom);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(CWidgetButtonZoom, GetName, _ZTV17CWidgetButtonZoom, 2, char const*)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetButtonZoom, Update, _ZTV17CWidgetButtonZoom, 33, void)
    DECL_VIRTUALCALL_TAIL()

DECL_CLASS_END()
CHECKSIZE(CWidgetButtonZoom, 0xa8, 0xc8);

DECL_CLASS_BASED(CWidgetListShop, CWidgetList)
    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CWidgetListShop, _ZN15CWidgetListShopC2EPKcS1_RK14WidgetPositionPS1_ib, char const* textureName1, char const* textureName2, WidgetPosition const& position, char const** entries, i32 value, bool enabled)
    DECL_CTORCALL_ARG_TAIL(textureName1, textureName2, position, entries, value, enabled)
    DECL_DTORCALL_VIRTUAL_VTABLE(CWidgetListShop, _ZN15CWidgetListShop, _ZTV15CWidgetListShop);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(CWidgetListShop, AddItem, _ZTV15CWidgetListShop, 35, void, char const* text1, char const* text2)
    DECL_VIRTUALCALL_TAIL(text1, text2)
    DECL_VIRTUALCALL_HEAD(CWidgetListShop, Draw, _ZTV15CWidgetListShop, 5, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetListShop, GetName, _ZTV15CWidgetListShop, 2, char const*)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetListShop, Update, _ZTV15CWidgetListShop, 33, void)
    DECL_VIRTUALCALL_TAIL()

    // STATIC functions
    DECL_FASTCALL_SIMPLE(LoadFromFile, _ZN15CWidgetListShop12LoadFromFileEv, void);

    // STATIC values
    DECL_OBJECT_ARRAY_PLT(SFileEntry, m_FileEntry, BYBIT(0x677598, 0x84cb70));

    // Member functions
    DECL_THISCALL_HEAD(AssignImage, _ZN15CWidgetListShop11AssignImageEi, void, i32 index)
    DECL_THISCALL_TAIL(AssignImage, index)
    DECL_THISCALL_SIMPLE(AssignImages, _ZN15CWidgetListShop12AssignImagesEv, void);

    // Member values
    char m_szTitle[256];
    bool m_bShowThumbs;
DECL_CLASS_END()
CHECKSIZE(CWidgetListShop, 0x11df4, 0x12210);

DECL_CLASS_BASED(CWidgetListText, CWidgetList)
    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CWidgetListText, _ZN15CWidgetListTextC2EPKcRK14WidgetPositionPS1_ibbb, char const* textureName, WidgetPosition const& position, char const** entries, i32 value, bool enabled1, bool enabled2, bool enabled3)
    DECL_CTORCALL_ARG_TAIL(textureName, position, entries, value, enabled1, enabled2, enabled3)
    DECL_DTORCALL_VIRTUAL_VTABLE(CWidgetListText, _ZN15CWidgetListText, _ZTV15CWidgetListText);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(CWidgetListText, Draw, _ZTV15CWidgetListText, 5, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetListText, GetName, _ZTV15CWidgetListText, 2, char const*)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetListText, Update, _ZTV15CWidgetListText, 33, void)
    DECL_VIRTUALCALL_TAIL()

    // STATIC values
    DECL_OBJECT_PLT(float, m_fLastScroll, BYBIT(0x676028, 0x84a0c0));

DECL_CLASS_END()
CHECKSIZE(CWidgetListText, 0x11cf0, 0x12108);

DECL_CLASS_BASED(CWidgetRegionArcadeStick, CWidgetRegion)
    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CWidgetRegionArcadeStick, _ZN24CWidgetRegionArcadeStickC2EPKcRK14WidgetPositioni10HIDMapping, char const* textureName, WidgetPosition const& position, i32 value, HIDMapping mapping)
    DECL_CTORCALL_ARG_TAIL(textureName, position, value, mapping)
    DECL_DTORCALL_VIRTUAL_VTABLE(CWidgetRegionArcadeStick, _ZN24CWidgetRegionArcadeStick, _ZTV24CWidgetRegionArcadeStick);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(CWidgetRegionArcadeStick, GetName, _ZTV24CWidgetRegionArcadeStick, 2, char const*)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetRegionArcadeStick, Draw, _ZTV24CWidgetRegionArcadeStick, 5, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetRegionArcadeStick, GetWidgetValue2, _ZTV24CWidgetRegionArcadeStick, 8, void, float* value1, float* value2)
    DECL_VIRTUALCALL_TAIL(value1, value2)
    DECL_VIRTUALCALL_HEAD(CWidgetRegionArcadeStick, SetWidgetValue, _ZTV24CWidgetRegionArcadeStick, 28, void, float value)
    DECL_VIRTUALCALL_TAIL(value)
    DECL_VIRTUALCALL_HEAD(CWidgetRegionArcadeStick, Update, _ZTV24CWidgetRegionArcadeStick, 33, void)
    DECL_VIRTUALCALL_TAIL()

    // Member values
    i32 m_nCellX;
    i32 m_nCellY;
DECL_CLASS_END()
CHECKSIZE(CWidgetRegionArcadeStick, 0x98, 0xb0);

DECL_CLASS_BASED(CWidgetRegionBasketBallJump, CWidgetRegion)
    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CWidgetRegionBasketBallJump, _ZN27CWidgetRegionBasketBallJumpC2EPKcRK14WidgetPosition, char const* textureName, WidgetPosition const& position)
    DECL_CTORCALL_ARG_TAIL(textureName, position)
    DECL_DTORCALL_VIRTUAL_VTABLE(CWidgetRegionBasketBallJump, _ZN27CWidgetRegionBasketBallJump, _ZTV27CWidgetRegionBasketBallJump);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(CWidgetRegionBasketBallJump, GetName, _ZTV27CWidgetRegionBasketBallJump, 2, char const*)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetRegionBasketBallJump, IsTouched, _ZTV27CWidgetRegionBasketBallJump, 20, bool, CVector2D* value)
    DECL_VIRTUALCALL_TAIL(value)
    DECL_VIRTUALCALL_HEAD(CWidgetRegionBasketBallJump, OnInitialTouch, _ZTV27CWidgetRegionBasketBallJump, 21, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetRegionBasketBallJump, Update, _ZTV27CWidgetRegionBasketBallJump, 33, void)
    DECL_VIRTUALCALL_TAIL()

    // Member values
    bool m_bTouched;
DECL_CLASS_END()
CHECKSIZE(CWidgetRegionBasketBallJump, 0x94, 0xa8);

DECL_CLASS_BASED(CWidgetRegionColorPicker, CWidgetRegion)
    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CWidgetRegionColorPicker, _ZN24CWidgetRegionColorPickerC2EPKcRK14WidgetPosition, char const* textureName, WidgetPosition const& position)
    DECL_CTORCALL_ARG_TAIL(textureName, position)
    DECL_DTORCALL_VIRTUAL_VTABLE(CWidgetRegionColorPicker, _ZN24CWidgetRegionColorPicker, _ZTV24CWidgetRegionColorPicker);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(CWidgetRegionColorPicker, GetName, _ZTV24CWidgetRegionColorPicker, 2, char const*)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetRegionColorPicker, GetWidgetValue, _ZTV24CWidgetRegionColorPicker, 7, float)
    DECL_VIRTUALCALL_TAIL()

DECL_CLASS_END()
CHECKSIZE(CWidgetRegionColorPicker, 0x90, 0xa8);

DECL_CLASS_BASED(CWidgetRegionDriveHybrid, CWidgetRegion)
    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CWidgetRegionDriveHybrid, _ZN24CWidgetRegionDriveHybridC2EPKcRK14WidgetPosition, char const* textureName, WidgetPosition const& position)
    DECL_CTORCALL_ARG_TAIL(textureName, position)
    DECL_DTORCALL_VIRTUAL(CWidgetRegionDriveHybrid, _ZN24CWidgetRegionDriveHybridD2Ev, _ZN24CWidgetRegionDriveHybrid, _ZTV24CWidgetRegionDriveHybrid);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(CWidgetRegionDriveHybrid, GetName, _ZTV24CWidgetRegionDriveHybrid, 2, char const*)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetRegionDriveHybrid, Update, _ZTV24CWidgetRegionDriveHybrid, 33, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetRegionDriveHybrid, Draw, _ZTV24CWidgetRegionDriveHybrid, 5, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetRegionDriveHybrid, IsTouched, _ZTV24CWidgetRegionDriveHybrid, 20, bool, CVector2D* value)
    DECL_VIRTUALCALL_TAIL(value)

    // Member values
    i32 m_nCornerAlpha;
    CSprite2d mSpriteCorner;
    CSprite2d mSpriteCornerIcon;
DECL_CLASS_END()
CHECKSIZE(CWidgetRegionDriveHybrid, 0x9c, 0xb8);

DECL_CLASS_BASED(CWidgetRegionFlick, CWidgetRegion)
    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CWidgetRegionFlick, _ZN18CWidgetRegionFlickC2EPKcRK14WidgetPosition, char const* textureName, WidgetPosition const& position)
    DECL_CTORCALL_ARG_TAIL(textureName, position)
    DECL_DTORCALL_VIRTUAL(CWidgetRegionFlick, _ZN18CWidgetRegionFlickD2Ev, _ZN18CWidgetRegionFlick, _ZTV18CWidgetRegionFlick);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(CWidgetRegionFlick, Draw, _ZTV18CWidgetRegionFlick, 5, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetRegionFlick, GetName, _ZTV18CWidgetRegionFlick, 2, char const*)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetRegionFlick, IsTouched, _ZTV18CWidgetRegionFlick, 20, bool, CVector2D* value)
    DECL_VIRTUALCALL_TAIL(value)
    DECL_VIRTUALCALL_HEAD(CWidgetRegionFlick, Update, _ZTV18CWidgetRegionFlick, 33, void)
    DECL_VIRTUALCALL_TAIL()

    // Member values
    i32 m_nSteerAmount;
    CSprite2d mSpriteArrow;
DECL_CLASS_END()
CHECKSIZE(CWidgetRegionFlick, 0x98, 0xb0);

DECL_CLASS_BASED(CWidgetRegionGang, CWidgetRegion)
    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CWidgetRegionGang, _ZN17CWidgetRegionGangC2EPKcRK14WidgetPosition, char const* textureName, WidgetPosition const& position)
    DECL_CTORCALL_ARG_TAIL(textureName, position)
    DECL_DTORCALL_VIRTUAL(CWidgetRegionGang, _ZN17CWidgetRegionGangD2Ev, _ZN17CWidgetRegionGang, _ZTV17CWidgetRegionGang);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(CWidgetRegionGang, GetName, _ZTV17CWidgetRegionGang, 2, char const*)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetRegionGang, Draw, _ZTV17CWidgetRegionGang, 5, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetRegionGang, Update, _ZTV17CWidgetRegionGang, 33, void)
    DECL_VIRTUALCALL_TAIL()

    // Member functions
    DECL_THISCALL_SIMPLE(BuildRects, _ZN17CWidgetRegionGang10BuildRectsEv, void);

    // Member values
    CRect mTitle;
    CSprite2d mGangTitle;
    CSprite2d mSpriteOverlay;
DECL_CLASS_END()
CHECKSIZE(CWidgetRegionGang, 0xa8, 0xc8);

DECL_CLASS_BASED(CWidgetRegionHydraulics, CWidgetRegion)
    enum HydraulicStates
    {
        INACTIVE = 0,
        FRONT_2_ACTIVE = 1,
        BACK_2_ACTIVE = 2,
        LEFT_2_ACTIVE = 3,
        RIGHT_2_ACTIVE = 4,
        FRONT_LEFT_ACTIVE = 5,
        FRONT_RIGHT_ACTIVE = 6,
        BACK_LEFT_ACTIVE = 7,
        BACK_RIGHT_ACTIVE = 8,
        NUM_STATES = 9
    };

    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CWidgetRegionHydraulics, _ZN23CWidgetRegionHydraulicsC2EPKcRK14WidgetPosition, char const* textureName, WidgetPosition const& position)
    DECL_CTORCALL_ARG_TAIL(textureName, position)
    DECL_DTORCALL_VIRTUAL(CWidgetRegionHydraulics, _ZN23CWidgetRegionHydraulicsD2Ev, _ZN23CWidgetRegionHydraulics, _ZTV23CWidgetRegionHydraulics);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(CWidgetRegionHydraulics, GetName, _ZTV23CWidgetRegionHydraulics, 2, char const*)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetRegionHydraulics, Draw, _ZTV23CWidgetRegionHydraulics, 5, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetRegionHydraulics, Update, _ZTV23CWidgetRegionHydraulics, 33, void)
    DECL_VIRTUALCALL_TAIL()

    // Member functions
    DECL_THISCALL_SIMPLE(ResetHydraulicRegion, _ZN23CWidgetRegionHydraulics20ResetHydraulicRegionEv, void);

    // Member values
    bool m_bActive;
    i32 m_eHydraulicState;
    float m_fDeltaX;
    float m_fDeltaY;
    float m_fFade;
    CVector2D OldTouchPosition;
    bool m_bLocked;
    CRect m_RectLock;
    CSprite2d m_SpriteLock;
    CVector2D vLastTouchPos[2];
DECL_CLASS_END()
CHECKSIZE(CWidgetRegionHydraulics, 0xd4, 0xf0);

DECL_CLASS_BASED(CWidgetRegionLook, CWidgetRegion)
    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CWidgetRegionLook, _ZN17CWidgetRegionLookC2EPKcRK14WidgetPosition, char const* textureName, WidgetPosition const& position)
    DECL_CTORCALL_ARG_TAIL(textureName, position)
    DECL_DTORCALL_VIRTUAL_VTABLE(CWidgetRegionLook, _ZN17CWidgetRegionLook, _ZTV17CWidgetRegionLook);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(CWidgetRegionLook, DrawHelpIcon, _ZTV17CWidgetRegionLook, 4, void, char const* text, float value1, float value2, float value3, i32 index)
    DECL_VIRTUALCALL_TAIL(text, value1, value2, value3, index)
    DECL_VIRTUALCALL_HEAD(CWidgetRegionLook, GetName, _ZTV17CWidgetRegionLook, 2, char const*)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetRegionLook, GetWidgetValue2, _ZTV17CWidgetRegionLook, 8, void, float* value1, float* value2)
    DECL_VIRTUALCALL_TAIL(value1, value2)
    DECL_VIRTUALCALL_HEAD(CWidgetRegionLook, IsHeldDown, _ZTV17CWidgetRegionLook, 11, bool)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetRegionLook, IsPinchZooming, _ZTV17CWidgetRegionLook, 12, bool, CVector2D* value)
    DECL_VIRTUALCALL_TAIL(value)
    DECL_VIRTUALCALL_HEAD(CWidgetRegionLook, IsSwipedLeft, _ZTV17CWidgetRegionLook, 17, bool)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetRegionLook, IsSwipedRight, _ZTV17CWidgetRegionLook, 18, bool)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetRegionLook, IsTouched, _ZTV17CWidgetRegionLook, 20, bool, CVector2D* value)
    DECL_VIRTUALCALL_TAIL(value)
    DECL_VIRTUALCALL_HEAD(CWidgetRegionLook, OnInitialTouch, _ZTV17CWidgetRegionLook, 21, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetRegionLook, OnReleasedTouch, _ZTV17CWidgetRegionLook, 23, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetRegionLook, Update, _ZTV17CWidgetRegionLook, 33, void)
    DECL_VIRTUALCALL_TAIL()

    // Member values
    bool m_bLookBack;
    bool m_bDisableLookBack;
DECL_CLASS_END()
CHECKSIZE(CWidgetRegionLook, 0x94, 0xa8);

DECL_CLASS_BASED(CWidgetRegionMove, CWidgetRegion)
    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CWidgetRegionMove, _ZN17CWidgetRegionMoveC2EPKcRK14WidgetPosition, char const* textureName, WidgetPosition const& position)
    DECL_CTORCALL_ARG_TAIL(textureName, position)
    DECL_DTORCALL_VIRTUAL(CWidgetRegionMove, _ZN17CWidgetRegionMoveD2Ev, _ZN17CWidgetRegionMove, _ZTV17CWidgetRegionMove);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(CWidgetRegionMove, GetName, _ZTV17CWidgetRegionMove, 2, char const*)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetRegionMove, Draw, _ZTV17CWidgetRegionMove, 5, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetRegionMove, DrawHelpIcon, _ZTV17CWidgetRegionMove, 4, void, char const* text, float value1, float value2, float value3, i32 index)
    DECL_VIRTUALCALL_TAIL(text, value1, value2, value3, index)
    DECL_VIRTUALCALL_HEAD(CWidgetRegionMove, GetWidgetValue2, _ZTV17CWidgetRegionMove, 8, void, float* value1, float* value2)
    DECL_VIRTUALCALL_TAIL(value1, value2)
    DECL_VIRTUALCALL_HEAD(CWidgetRegionMove, IsDoubleTapped, _ZTV17CWidgetRegionMove, 10, bool)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetRegionMove, IsTouched, _ZTV17CWidgetRegionMove, 20, bool, CVector2D* value)
    DECL_VIRTUALCALL_TAIL(value)
    DECL_VIRTUALCALL_HEAD(CWidgetRegionMove, OnInitialTouch, _ZTV17CWidgetRegionMove, 21, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetRegionMove, Update, _ZTV17CWidgetRegionMove, 33, void)
    DECL_VIRTUALCALL_TAIL()

    // Member functions
    DECL_THISCALL_SIMPLE(ClampInternalTouchAnchor, _ZN17CWidgetRegionMove24ClampInternalTouchAnchorEv, void);

    // Member values
    float m_fRadians;
    float m_fTouchLimit;
    CSprite2d m_SpriteIndicator;
    CVector2D m_vecIndicatorOrigin;
    CVector2D m_vecTouchAnchorInternal;
DECL_CLASS_END()
CHECKSIZE(CWidgetRegionMove, 0xac, 0xc8);

DECL_CLASS_BASED(CWidgetRegionPoolBallInHand, CWidgetRegion)
    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CWidgetRegionPoolBallInHand, _ZN27CWidgetRegionPoolBallInHandC2EPKcRK14WidgetPosition, char const* textureName, WidgetPosition const& position)
    DECL_CTORCALL_ARG_TAIL(textureName, position)
    DECL_DTORCALL_VIRTUAL_VTABLE(CWidgetRegionPoolBallInHand, _ZN27CWidgetRegionPoolBallInHand, _ZTV27CWidgetRegionPoolBallInHand);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(CWidgetRegionPoolBallInHand, GetName, _ZTV27CWidgetRegionPoolBallInHand, 2, char const*)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetRegionPoolBallInHand, GetWidgetValue2, _ZTV27CWidgetRegionPoolBallInHand, 8, void, float* value1, float* value2)
    DECL_VIRTUALCALL_TAIL(value1, value2)
    DECL_VIRTUALCALL_HEAD(CWidgetRegionPoolBallInHand, IsTouched, _ZTV27CWidgetRegionPoolBallInHand, 20, bool, CVector2D* value)
    DECL_VIRTUALCALL_TAIL(value)
    DECL_VIRTUALCALL_HEAD(CWidgetRegionPoolBallInHand, SetWidgetValue3, _ZTV27CWidgetRegionPoolBallInHand, 30, void, float value1, float value2, float value3)
    DECL_VIRTUALCALL_TAIL(value1, value2, value3)

DECL_CLASS_END()
CHECKSIZE(CWidgetRegionPoolBallInHand, 0x90, 0xa8);

DECL_CLASS_BASED(CWidgetRegionPoolEnglish, CWidgetRegion)
    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CWidgetRegionPoolEnglish, _ZN24CWidgetRegionPoolEnglishC2EPKcRK14WidgetPosition, char const* textureName, WidgetPosition const& position)
    DECL_CTORCALL_ARG_TAIL(textureName, position)
    DECL_DTORCALL_VIRTUAL_VTABLE(CWidgetRegionPoolEnglish, _ZN24CWidgetRegionPoolEnglish, _ZTV24CWidgetRegionPoolEnglish);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(CWidgetRegionPoolEnglish, GetName, _ZTV24CWidgetRegionPoolEnglish, 2, char const*)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetRegionPoolEnglish, GetWidgetValue2, _ZTV24CWidgetRegionPoolEnglish, 8, void, float* value1, float* value2)
    DECL_VIRTUALCALL_TAIL(value1, value2)
    DECL_VIRTUALCALL_HEAD(CWidgetRegionPoolEnglish, IsTouched, _ZTV24CWidgetRegionPoolEnglish, 20, bool, CVector2D* value)
    DECL_VIRTUALCALL_TAIL(value)

DECL_CLASS_END()
CHECKSIZE(CWidgetRegionPoolEnglish, 0x90, 0xa8);

DECL_CLASS_BASED(CWidgetRegionResponse, CWidgetRegion)
    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CWidgetRegionResponse, _ZN21CWidgetRegionResponseC2EPKcRK14WidgetPosition, char const* textureName, WidgetPosition const& position)
    DECL_CTORCALL_ARG_TAIL(textureName, position)
    DECL_DTORCALL_VIRTUAL_VTABLE(CWidgetRegionResponse, _ZN21CWidgetRegionResponse, _ZTV21CWidgetRegionResponse);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(CWidgetRegionResponse, GetName, _ZTV21CWidgetRegionResponse, 2, char const*)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetRegionResponse, Update, _ZTV21CWidgetRegionResponse, 33, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetRegionResponse, Draw, _ZTV21CWidgetRegionResponse, 5, void)
    DECL_VIRTUALCALL_TAIL()

    // Member values
    bool m_bTapped;
    bool m_bDoubleTapped;
DECL_CLASS_END()
CHECKSIZE(CWidgetRegionResponse, 0x94, 0xa8);

DECL_CLASS_BASED(CWidgetRegionRhythmSelect, CWidgetButton)
    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CWidgetRegionRhythmSelect, _ZN25CWidgetRegionRhythmSelectC2EPKcRK14WidgetPosition, char const* textureName, WidgetPosition const& position)
    DECL_CTORCALL_ARG_TAIL(textureName, position)
    DECL_DTORCALL_VIRTUAL(CWidgetRegionRhythmSelect, _ZN25CWidgetRegionRhythmSelectD2Ev, _ZN25CWidgetRegionRhythmSelect, _ZTV25CWidgetRegionRhythmSelect);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(CWidgetRegionRhythmSelect, GetName, _ZTV25CWidgetRegionRhythmSelect, 2, char const*)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetRegionRhythmSelect, Update, _ZTV25CWidgetRegionRhythmSelect, 33, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetRegionRhythmSelect, Draw, _ZTV25CWidgetRegionRhythmSelect, 5, void)
    DECL_VIRTUALCALL_TAIL()

    // Member values
    i32 nCurrDir;
    i32 nPrevDir;
    i32 nSpritePrevAlpha;
    bool bRhythm;
    float fRadians;
    float fCurRadians;
    CRGBA SpriteNextColor;
    CRGBA SpritePrevColor;
    CVector2D vCurrAnchor;
    CVector2D vCurrPoint;
    CSprite2d mSpriteNext;
    CSprite2d mSpritePrev;
    CSprite2d mSpriteCurrent;
DECL_CLASS_END()
CHECKSIZE(CWidgetRegionRhythmSelect, 0xe4, 0x110);

DECL_CLASS_BASED(CWidgetRegionSprint, CWidgetRegion)
    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CWidgetRegionSprint, _ZN19CWidgetRegionSprintC2EPKcRK14WidgetPosition, char const* textureName, WidgetPosition const& position)
    DECL_CTORCALL_ARG_TAIL(textureName, position)
    DECL_DTORCALL_VIRTUAL(CWidgetRegionSprint, _ZN19CWidgetRegionSprintD2Ev, _ZN19CWidgetRegionSprint, _ZTV19CWidgetRegionSprint);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(CWidgetRegionSprint, GetName, _ZTV19CWidgetRegionSprint, 2, char const*)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetRegionSprint, IsDoubleTapped, _ZTV19CWidgetRegionSprint, 10, bool)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetRegionSprint, IsTouched, _ZTV19CWidgetRegionSprint, 20, bool, CVector2D* value)
    DECL_VIRTUALCALL_TAIL(value)
    DECL_VIRTUALCALL_HEAD(CWidgetRegionSprint, OnInitialTouch, _ZTV19CWidgetRegionSprint, 21, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetRegionSprint, Update, _ZTV19CWidgetRegionSprint, 33, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetRegionSprint, Draw, _ZTV19CWidgetRegionSprint, 5, void)
    DECL_VIRTUALCALL_TAIL()

    // Member values
    bool m_bTouched;
    i32 m_nCornerAlpha;
    float m_fSprintEnergyPercentage;
    CSprite2d mSpriteCorner;
    CSprite2d mSpriteCornerIcon;
DECL_CLASS_END()
CHECKSIZE(CWidgetRegionSprint, 0xa4, 0xc0);

DECL_CLASS_BASED(CWidgetRegionSteer, CWidgetRegion)
    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CWidgetRegionSteer, _ZN18CWidgetRegionSteerC2EPKcRK14WidgetPosition, char const* textureName, WidgetPosition const& position)
    DECL_CTORCALL_ARG_TAIL(textureName, position)
    DECL_DTORCALL_VIRTUAL(CWidgetRegionSteer, _ZN18CWidgetRegionSteerD2Ev, _ZN18CWidgetRegionSteer, _ZTV18CWidgetRegionSteer);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(CWidgetRegionSteer, GetName, _ZTV18CWidgetRegionSteer, 2, char const*)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetRegionSteer, Draw, _ZTV18CWidgetRegionSteer, 5, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetRegionSteer, IsTouched, _ZTV18CWidgetRegionSteer, 20, bool, CVector2D* value)
    DECL_VIRTUALCALL_TAIL(value)
    DECL_VIRTUALCALL_HEAD(CWidgetRegionSteer, OnInitialTouch, _ZTV18CWidgetRegionSteer, 21, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetRegionSteer, Update, _ZTV18CWidgetRegionSteer, 33, void)
    DECL_VIRTUALCALL_TAIL()

    // Member functions
    DECL_THISCALL_SIMPLE(ClampInternalTouchAnchor, _ZN18CWidgetRegionSteer24ClampInternalTouchAnchorEv, void);

    // Member values
    float m_fTouchLimit;
    CSprite2d m_SpriteIndicator;
    CVector2D m_vecIndicatorOrigin;
    CVector2D m_vecTouchAnchorInternal;
DECL_CLASS_END()
CHECKSIZE(CWidgetRegionSteer, 0xa8, 0xc0);

DECL_CLASS_BASED(CWidgetRegionSteeringSelection, CWidgetRegion)
    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CWidgetRegionSteeringSelection, _ZN30CWidgetRegionSteeringSelectionC2EPKcRK14WidgetPosition, char const* textureName, WidgetPosition const& position)
    DECL_CTORCALL_ARG_TAIL(textureName, position)
    DECL_DTORCALL_VIRTUAL(CWidgetRegionSteeringSelection, _ZN30CWidgetRegionSteeringSelectionD2Ev, _ZN30CWidgetRegionSteeringSelection, _ZTV30CWidgetRegionSteeringSelection);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(CWidgetRegionSteeringSelection, GetName, _ZTV30CWidgetRegionSteeringSelection, 2, char const*)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetRegionSteeringSelection, Draw, _ZTV30CWidgetRegionSteeringSelection, 5, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetRegionSteeringSelection, Update, _ZTV30CWidgetRegionSteeringSelection, 33, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetRegionSteeringSelection, IsReleased, _ZTV30CWidgetRegionSteeringSelection, 13, bool, CVector2D* value)
    DECL_VIRTUALCALL_TAIL(value)
    DECL_VIRTUALCALL_HEAD(CWidgetRegionSteeringSelection, OnInitialTouch, _ZTV30CWidgetRegionSteeringSelection, 21, void)
    DECL_VIRTUALCALL_TAIL()

    // Member functions
    DECL_THISCALL_SIMPLE(BuildRects, _ZN30CWidgetRegionSteeringSelection10BuildRectsEv, void);
    DECL_THISCALL_SIMPLE(DrawButtons, _ZN30CWidgetRegionSteeringSelection11DrawButtonsEv, void);

    // Member values
    i32 m_nCurrentSelection;
    i32 m_nInitialSelection;
    CRect mTitle;
    CSprite2d mSpriteOverlay;
    CRect mInfo;
    CRect mAnalogSelection;
    CSprite2d mSpriteNub;
    CSprite2d mSpriteCircle;
    CRect mDigitalSelection;
    CSprite2d mSpriteLeft;
    CSprite2d mSpriteRight;
    CRect mFlickSelection;
    CSprite2d mSpriteArrow;
DECL_CLASS_END()
CHECKSIZE(CWidgetRegionSteeringSelection, 0x100, 0x130);

DECL_CLASS_BASED(CWidgetRegionSwipeRadio, CWidgetRegion)
    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CWidgetRegionSwipeRadio, _ZN23CWidgetRegionSwipeRadioC2EPKcRK14WidgetPosition, char const* textureName, WidgetPosition const& position)
    DECL_CTORCALL_ARG_TAIL(textureName, position)
    DECL_DTORCALL_VIRTUAL_VTABLE(CWidgetRegionSwipeRadio, _ZN23CWidgetRegionSwipeRadio, _ZTV23CWidgetRegionSwipeRadio);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(CWidgetRegionSwipeRadio, DrawHelpIcon, _ZTV23CWidgetRegionSwipeRadio, 4, void, char const* text, float value1, float value2, float value3, i32 index)
    DECL_VIRTUALCALL_TAIL(text, value1, value2, value3, index)
    DECL_VIRTUALCALL_HEAD(CWidgetRegionSwipeRadio, GetName, _ZTV23CWidgetRegionSwipeRadio, 2, char const*)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetRegionSwipeRadio, IsSwipedLeft, _ZTV23CWidgetRegionSwipeRadio, 17, bool)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetRegionSwipeRadio, IsSwipedRight, _ZTV23CWidgetRegionSwipeRadio, 18, bool)
    DECL_VIRTUALCALL_TAIL()

DECL_CLASS_END()
CHECKSIZE(CWidgetRegionSwipeRadio, 0x90, 0xa8);

DECL_CLASS_BASED(CWidgetRegionTouchLayoutSelection, CWidgetRegion)
    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CWidgetRegionTouchLayoutSelection, _ZN33CWidgetRegionTouchLayoutSelectionC2EPKcRK14WidgetPosition, char const* textureName, WidgetPosition const& position)
    DECL_CTORCALL_ARG_TAIL(textureName, position)
    DECL_DTORCALL_VIRTUAL(CWidgetRegionTouchLayoutSelection, _ZN33CWidgetRegionTouchLayoutSelectionD2Ev, _ZN33CWidgetRegionTouchLayoutSelection, _ZTV33CWidgetRegionTouchLayoutSelection);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(CWidgetRegionTouchLayoutSelection, GetName, _ZTV33CWidgetRegionTouchLayoutSelection, 2, char const*)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetRegionTouchLayoutSelection, Draw, _ZTV33CWidgetRegionTouchLayoutSelection, 5, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetRegionTouchLayoutSelection, Update, _ZTV33CWidgetRegionTouchLayoutSelection, 33, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CWidgetRegionTouchLayoutSelection, IsReleased, _ZTV33CWidgetRegionTouchLayoutSelection, 13, bool, CVector2D* value)
    DECL_VIRTUALCALL_TAIL(value)
    DECL_VIRTUALCALL_HEAD(CWidgetRegionTouchLayoutSelection, OnInitialTouch, _ZTV33CWidgetRegionTouchLayoutSelection, 21, void)
    DECL_VIRTUALCALL_TAIL()

    // Member functions
    DECL_THISCALL_SIMPLE(BuildRects, _ZN33CWidgetRegionTouchLayoutSelection10BuildRectsEv, void);
    DECL_THISCALL_SIMPLE(DrawClassicButtons, _ZN33CWidgetRegionTouchLayoutSelection18DrawClassicButtonsEv, void);
    DECL_THISCALL_SIMPLE(DrawAdaptedButtons, _ZN33CWidgetRegionTouchLayoutSelection18DrawAdaptedButtonsEv, void);

    // Member values
    i32 m_nCurrentSelection;
    i32 m_nInitialSelection;
    CRect mTitle;
    CSprite2d mSpriteOverlay;
    CRect mClassicSelection;
    CSprite2d mSpriteCrouch;
    CSprite2d mSpriteSprint;
    CSprite2d mSpriteSprintRim;
    CRect mAdvancedSelection;
    CSprite2d mSpriteRunningMan;
    CSprite2d mSpriteRunningManBack;
    CSprite2d mSpriteAttack;
DECL_CLASS_END()
CHECKSIZE(CWidgetRegionTouchLayoutSelection, 0xe4, 0x118);

DECL_CLASS_BASED(CWidgetButtonAnimatedArcade, CWidgetButtonAnimated)
    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CWidgetButtonAnimatedArcade, _ZN27CWidgetButtonAnimatedArcadeC2EPKcS1_RK14WidgetPositionjjS1_10HIDMapping, char const* textureName1, char const* textureName2, WidgetPosition const& position, u32 flags1, u32 flags2, char const* textureName3, HIDMapping mapping)
    DECL_CTORCALL_ARG_TAIL(textureName1, textureName2, position, flags1, flags2, textureName3, mapping)
    DECL_DTORCALL_VIRTUAL_VTABLE(CWidgetButtonAnimatedArcade, _ZN27CWidgetButtonAnimatedArcade, _ZTV27CWidgetButtonAnimatedArcade);

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(CWidgetButtonAnimatedArcade, SetWidgetValue, _ZTV27CWidgetButtonAnimatedArcade, 28, void, float value)
    DECL_VIRTUALCALL_TAIL(value)

DECL_CLASS_END()
CHECKSIZE(CWidgetButtonAnimatedArcade, 0x1c0, 0x1f0);

#define m_pChainHead m_pChainHead()
#define m_pChainTail m_pChainTail()

#endif // __AML_PSDK_SAWIDGETS_H
