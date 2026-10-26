#ifndef __AML_PSDK_VCFONT_H
#define __AML_PSDK_VCFONT_H

#include <aml-psdk/game_vc/plugin.h>
#include <aml-psdk/gta_base/RGBA.h>
#include <aml-psdk/gta_base/Rect.h>

DECL_CLASS(CFont)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(Initialise, _ZN5CFont10InitialiseEv, void);
    DECL_FASTCALL_SIMPLE(Shutdown, _ZN5CFont8ShutdownEv, void);
    DECL_FASTCALL_SIMPLE(InitPerFrame, _ZN5CFont12InitPerFrameEv, void);
    DECL_FASTCALL_SIMPLE(RenderFontBuffer, _ZN5CFont16RenderFontBufferEv, void);
    DECL_FASTCALL_SIMPLE(DrawFonts, _ZN5CFont9DrawFontsEv, void);
    DECL_FASTCALL_SIMPLE(PushState, _ZN5CFont9PushStateEv, void);
    DECL_FASTCALL_SIMPLE(PopState, _ZN5CFont8PopStateEv, void);
    DECL_FASTCALL_SIMPLE(SetScale, _ZN5CFont8SetScaleEff, void, float x, float y);
    DECL_FASTCALL_SIMPLE(SetSlantRefPoint, _ZN5CFont16SetSlantRefPointEff, void, float x, float y);
    DECL_FASTCALL_SIMPLE(SetSlant, _ZN5CFont8SetSlantEf, void, float slant);
    DECL_FASTCALL_SIMPLE(SetWrapx, _ZN5CFont8SetWrapxEf, void, float wrap);
    DECL_FASTCALL_SIMPLE(SetCentreSize, _ZN5CFont13SetCentreSizeEf, void, float width);
    DECL_FASTCALL_SIMPLE(SetRightJustifyWrap, _ZN5CFont19SetRightJustifyWrapEf, void, float wrap);
    DECL_FASTCALL_SIMPLE(SetAlphaFade, _ZN5CFont12SetAlphaFadeEf, void, float alpha);
    DECL_FASTCALL_SIMPLE(SetFontStyle, _ZN5CFont12SetFontStyleEs, void, i16 style);
    DECL_FASTCALL_SIMPLE(SetDropShadowPosition, _ZN5CFont21SetDropShadowPositionEs, void, i16 offset);

    // Native colour values use an indirect argument.
    DECL_FASTCALL_SIMPLE(SetColor, _ZN5CFont8SetColorE5CRGBA, void, CRGBA const& color);
    DECL_FASTCALL_SIMPLE(SetBackgroundColor, _ZN5CFont18SetBackgroundColorE5CRGBA, void, CRGBA const& color);
    DECL_FASTCALL_SIMPLE(SetDropColor, _ZN5CFont12SetDropColorE5CRGBA, void, CRGBA const& color);
    DECL_FASTCALL_SIMPLE(SetJustifyOn, _ZN5CFont12SetJustifyOnEv, void);
    DECL_FASTCALL_SIMPLE(SetJustifyOff, _ZN5CFont13SetJustifyOffEv, void);
    DECL_FASTCALL_SIMPLE(SetCentreOn, _ZN5CFont11SetCentreOnEv, void);
    DECL_FASTCALL_SIMPLE(SetCentreOff, _ZN5CFont12SetCentreOffEv, void);
    DECL_FASTCALL_SIMPLE(SetRightJustifyOn, _ZN5CFont17SetRightJustifyOnEv, void);
    DECL_FASTCALL_SIMPLE(SetRightJustifyOff, _ZN5CFont18SetRightJustifyOffEv, void);
    DECL_FASTCALL_SIMPLE(SetBackgroundOn, _ZN5CFont15SetBackgroundOnEv, void);
    DECL_FASTCALL_SIMPLE(SetBackgroundOff, _ZN5CFont16SetBackgroundOffEv, void);
    DECL_FASTCALL_SIMPLE(SetBackGroundOnlyTextOn, _ZN5CFont23SetBackGroundOnlyTextOnEv, void);
    DECL_FASTCALL_SIMPLE(SetBackGroundOnlyTextOff, _ZN5CFont24SetBackGroundOnlyTextOffEv, void);
    DECL_FASTCALL_SIMPLE(SetPropOn, _ZN5CFont9SetPropOnEv, void);
    DECL_FASTCALL_SIMPLE(SetPropOff, _ZN5CFont10SetPropOffEv, void);
    DECL_FASTCALL_SIMPLE(SetFlashOn, _ZN5CFont10SetFlashOnEv, void);
    DECL_FASTCALL_SIMPLE(SetFlashOff, _ZN5CFont11SetFlashOffEv, void);

    DECL_FASTCALL_SIMPLE(PrintString, _ZN5CFont11PrintStringEffPt, void, float x, float y, u16* text);
    DECL_FASTCALL_SIMPLE(PrintStringFromBottom, _ZN5CFont21PrintStringFromBottomEffPt, void, float x, float y, u16* text);
    DECL_FASTCALL_SIMPLE(PrintChar, _ZN5CFont9PrintCharEffs, void, float x, float y, i16 character);
    DECL_FASTCALL_SIMPLE(GetStringWidth, _ZN5CFont14GetStringWidthEPtb, float, u16* text, bool full);
    DECL_FASTCALL_SIMPLE(GetCharacterWidth, _ZN5CFont17GetCharacterWidthEt, float, u16 character);
    DECL_FASTCALL_SIMPLE(GetCharacterSize, _ZN5CFont16GetCharacterSizeEt, float, u16 character);
    DECL_FASTCALL_SIMPLE(GetNumberLines, _ZN5CFont14GetNumberLinesEffPt, i16, float x, float y, u16* text);
    DECL_FASTCALL_SIMPLE(FilterOutTokensFromString, _ZN5CFont25FilterOutTokensFromStringEPt, void, u16* text);

    DECL_FASTCALL_SIMPLE(GetTextRect, _ZN5CFont11GetTextRectEP5CRectffPt, void, CRect* rect, float x, float y, u16* text);

    inline static u16* ParseToken(u16* text)
    {
        static auto native = GetMainLibrarySymbol<u16*(*)(u16*)>("_ZN5CFont10ParseTokenEPt");
        return native(text);
    }
    inline static u16* ParseToken(u16* text, CRGBA& color, bool& flashing, bool& bold, bool& italic)
    {
        static auto native = GetMainLibrarySymbol<u16*(*)(u16*, CRGBA&, bool&, bool&, bool&)>("_ZN5CFont10ParseTokenEPtR5CRGBARbS3_S3_");
        return native(text, color, flashing, bold, italic);
    }
DECL_CLASS_END()

#endif // __AML_PSDK_VCFONT_H
