#ifndef __AML_PSDK_SAWIDGETS_H
#define __AML_PSDK_SAWIDGETS_H

#include <aml-psdk/game_sa/engine/Sprite2d.h>
#include <aml-psdk/gta_base/Vector.h>
#include <aml-psdk/gta_base/RGBA.h>
#include <aml-psdk/gta_base/DrawVertices.h>
#include "../enum/HID.h"

struct WidgetPosition
{
    float m_fOriginX;
    float m_fOriginY;
    float m_fScaleX;
    float m_fScaleY;
};

DECL_CLASS(CHoldEffect)
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



DECL_CLASS_BASED(CWidget, SimpleVTable)

    // Virtual functions
    virtual const char* GetName(void);
    virtual bool CoordsAreInsideWidget(CVector2D const&,bool);
    virtual void DrawHelpIcon(char const*,float,float,float,int);
    virtual void Draw(void);
    virtual float GetPinchDistance(void);
    virtual float GetWidgetValue(void);
    virtual void GetWidgetValue2(float *,float *);
    virtual bool IsButton(void);
    virtual bool IsDoubleTapped(void);
    virtual bool IsHeldDown(void);
    virtual bool IsPinchZooming(CVector2D *);
    virtual bool IsReleased(CVector2D *);
    virtual bool IsRegion(void);
    virtual bool IsSwiped(void);
    virtual bool IsSwipedDown(void);
    virtual bool IsSwipedLeft(void);
    virtual bool IsSwipedRight(void);
    virtual bool IsSwipedUp(void);
    virtual bool IsTouched(CVector2D *);
    virtual void OnInitialTouch(void);
    virtual void OnPinchZoomStart(void);
    virtual void OnReleasedTouch(void);
    virtual void OnSwipeTouch(void);
    virtual void Pulsate(void);
    virtual void SetEquippedItem(int);
    virtual void SetSliderRange(float,float);
    virtual void SetWidgetValue(float);
    virtual void SetWidgetValue2(float,float);
    virtual void SetWidgetValue3(float,float,float);
    virtual void SetWidgetInfo(char *,float,bool,bool,bool,bool,int);
    virtual void SetWidgetInfo2(int,int,int,int,char *,char *);
    virtual void Update(void);
    virtual void Visualize(void);

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

#endif // __AML_PSDK_SAWIDGETS_H
