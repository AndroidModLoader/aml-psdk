#ifndef __AML_PSDK_VCHUD_H
#define __AML_PSDK_VCHUD_H

#include <aml-psdk/game_vc/plugin.h>

DECL_CLASS(CHud)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(Draw, _ZN4CHud4DrawEv, void);
    DECL_FASTCALL_SIMPLE(DrawAfterFade, _ZN4CHud13DrawAfterFadeEv, void);
    DECL_FASTCALL_SIMPLE(GetRidOfAllHudMessages, _ZN4CHud22GetRidOfAllHudMessagesEv, void);
    DECL_FASTCALL_SIMPLE(ResetWastedText, _ZN4CHud15ResetWastedTextEv, void);
    DECL_FASTCALL_SIMPLE(SetZoneName, _ZN4CHud11SetZoneNameEPt, void, u16* text);
    DECL_FASTCALL_SIMPLE(SetVehicleName, _ZN4CHud14SetVehicleNameEPt, void, u16* text);
    DECL_FASTCALL_SIMPLE(SetMessage, _ZN4CHud10SetMessageEPt, void, u16* text);
    DECL_FASTCALL_SIMPLE(SetPagerMessage, _ZN4CHud15SetPagerMessageEPt, void, u16* text);
    DECL_FASTCALL_SIMPLE(SetBigMessage, _ZN4CHud13SetBigMessageEPtt, void, u16* text, u16 style);
    DECL_FASTCALL_SIMPLE(SetHelpMessage, _ZN4CHud14SetHelpMessageEPtbbb, void, u16* text, bool quickMessage, bool permanent, bool addToBrief);
    DECL_FASTCALL_SIMPLE(SetHelpMessageWithNumber, _ZN4CHud24SetHelpMessageWithNumberEPtibb, void, u16* text, i32 number, bool quickMessage, bool permanent);
    DECL_FASTCALL_SIMPLE(IsHelpMessageBeingDisplayed, _ZN4CHud27IsHelpMessageBeingDisplayedEv, bool);

    // STATIC values
    DECL_VALUE_PLT_BOOL(m_Wants_To_Draw_Hud, BYBIT(0x395DCC, 0x579BC8));
    DECL_VALUE_PLT_BOOL(m_Wants_To_Draw_3dMarkers, BYBIT(0x3943AC, 0x5768A8));
    DECL_VALUE_PLT_BOOL(bScriptDontDisplayRadar, BYBIT(0x394858, 0x5771F0));
    DECL_VALUE_PLT_U16(m_ItemToFlash, BYBIT(0x395E10, 0x579C58));
DECL_CLASS_END()

#define m_Wants_To_Draw_Hud m_Wants_To_Draw_Hud()
#define m_Wants_To_Draw_3dMarkers m_Wants_To_Draw_3dMarkers()
#define bScriptDontDisplayRadar bScriptDontDisplayRadar()
#define m_ItemToFlash m_ItemToFlash()

#endif // __AML_PSDK_VCHUD_H
