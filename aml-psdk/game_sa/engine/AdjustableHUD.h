#ifndef __AML_PSDK_SAADJUSTABLEHUD_H
#define __AML_PSDK_SAADJUSTABLEHUD_H

#pragma push_macro("m_pInstance")
#undef m_pInstance
#include "../other/Widgets.h"
#pragma pop_macro("m_pInstance")

struct AdjustableButton
{
    CTouchInterface::WidgetIDs m_WidgetID;
    CTouchInterface::WidgetPositionIDs m_WidgetPositionID;
    CRect m_RectScreen;
    CSprite2d m_SpriteBackground;
    CSprite2d m_Sprite;
    int m_nAdjustmentModeFlags;
    bool m_bShownAsRed;
    bool m_bEnabled;
};
CHECKSIZE(AdjustableButton, 0x28, 0x30);

DECL_CLASS(CAdjustableHUD)
    // Construct/Deconstruct functions
    DECL_CTORCALL(CAdjustableHUD, _ZN14CAdjustableHUDC2Ev);
    DECL_DTORCALL(CAdjustableHUD, _ZN14CAdjustableHUDD2Ev);

    // Member functions
    DECL_THISCALL_HEAD(ConstrainToDraggableRegion, _ZN14CAdjustableHUD26ConstrainToDraggableRegionER9CVector2Df, void, CVector2D& position, float radius)
    DECL_THISCALL_TAIL(ConstrainToDraggableRegion, position, radius)
    DECL_THISCALL_SIMPLE(EnableButtons, _ZN14CAdjustableHUD13EnableButtonsEv, void);
    DECL_THISCALL_HEAD(IsValidPosition, _ZN14CAdjustableHUD15IsValidPositionERK9CVector2DfPS0_, bool, CVector2D const& position, float radius, CVector2D* adjustedPosition)
    DECL_THISCALL_TAIL(IsValidPosition, position, radius, adjustedPosition)
    DECL_THISCALL_SIMPLE(RestoreDefaults, _ZN14CAdjustableHUD15RestoreDefaultsEv, void);
    DECL_THISCALL_SIMPLE(SaveToDisk, _ZN14CAdjustableHUD10SaveToDiskEv, void);
    DECL_THISCALL_SIMPLE(SetTextures, _ZN14CAdjustableHUD11SetTexturesEv, void);
    DECL_THISCALL_SIMPLE(Update, _ZN14CAdjustableHUD6UpdateEv, void);
    DECL_THISCALL_SIMPLE(Draw, _ZN14CAdjustableHUD4DrawEv, void);
    DECL_THISCALL_SIMPLE(RestoreButtonPositions, _ZN14CAdjustableHUD22RestoreButtonPositionsEv, void);
    DECL_FASTCALL_SIMPLE(GetTopAreaHeight, _ZN14CAdjustableHUD16GetTopAreaHeightEv, float);
    DECL_FASTCALL_SIMPLE(Toggle, _ZN14CAdjustableHUD6ToggleEv, void);

    inline i32 GetMode() { return m_nAdjustmentMode; }
    static inline CAdjustableHUD* GetInstance() { return ms_pInstance(); }

    // STATIC values
    DECL_OBJECT_PLT(CAdjustableHUD*, ms_pInstance, BYBIT(0x67740C, 0x84C850));

    // Member values
    int m_nAdjustmentMode;
    CRect m_RectOnFoot;
    CRect m_RectInCar;
    CRect m_RectCancel;
    CRect m_RectSave;
    CRect m_RectRestoreDefaults;
    CRect m_RectOverlapDialog;
    int m_nInitialTouchID;
    AdjustableButton m_AdjustableButtons[19];
    CRect m_SavedButtonPositions[19];
    int m_nSelectedButton;
    bool m_bMovedButton;
    bool m_bOverlappingDialog;
    bool m_bQueuedExit;
    CVector2D m_vecDragOffset;
    CVector2D m_vecDragAnchor;
    CVector2D m_vecCoords;
DECL_CLASS_END()
CHECKSIZE(CAdjustableHUD, 0x4B0, 0x548);

#endif // __AML_PSDK_SAADJUSTABLEHUD_H
