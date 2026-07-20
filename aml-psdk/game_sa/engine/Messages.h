#ifndef __AML_PSDK_SAMESSAGES_H
#define __AML_PSDK_SAMESSAGES_H

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/gta_base/GxtChar.h>

struct CQueuedMessage
{
    char                               TextLabel[8];
    GxtChar*                           pMessage;
    u16                                Colour;
    u32                                Duration;
    u32                                WhenStarted;
    i32                                NumberToInsert;
    i32                                NumberToInsert2;
    i32                                NumberToInsert3;
    i32                                NumberToInsert4;
    i32                                NumberToInsert5;
    i32                                NumberToInsert6;
    GxtChar*                           pShortMessage;
    u8                                 bAddToPreviousBriefs;
};
CHECKSIZE(CQueuedMessage, 0x38, 0x48);  // 64-bit from the IDB; 32-bit measured from this layout

struct CPreviousMessage
{
    char                               TextLabel[8];
    GxtChar*                           pMessage;
    i32                                NumberToInsert;
    i32                                NumberToInsert2;
    i32                                NumberToInsert3;
    i32                                NumberToInsert4;
    i32                                NumberToInsert5;
    i32                                NumberToInsert6;
    GxtChar*                           pShortMessage;
};
CHECKSIZE(CPreviousMessage, 0x28, 0x30);  // 64-bit from the IDB; 32-bit measured from this layout

DECL_CLASS(CMessages)
    // Functions
    DECL_FASTCALL_SIMPLE(Init, _ZN9CMessages4InitEv, void);
    DECL_FASTCALL_SIMPLE(ClearPreviousBriefArray, _ZN9CMessages23ClearPreviousBriefArrayEv, void);
    DECL_FASTCALL_SIMPLE(GetGxtStringLength, _ZN9CMessages18GetGxtStringLengthEPt, u16, GxtChar* pGxtString);
    DECL_FASTCALL_SIMPLE(GxtStringCopy, _ZN9CMessages13GxtStringCopyEPtS0_t, void, GxtChar* pDest, GxtChar* pSource, u16 MaxLength);
    DECL_FASTCALL_SIMPLE(GxtStringCompare, _ZN9CMessages16GxtStringCompareEPtS0_t, u8, GxtChar* pGxtString1, GxtChar* pGxtString2, u16 NumOfCharsToCompare);
    DECL_FASTCALL_SIMPLE(Process, _ZN9CMessages7ProcessEv, void);
    DECL_FASTCALL_SIMPLE(AddToPreviousBriefArray, _ZN9CMessages23AddToPreviousBriefArrayEPKcPtiiiiiiS2_, void, const char* Label, GxtChar* pText, i32 NumToInsert, i32 NumToInsert2, i32 NumToInsert3, i32 NumToInsert4, i32 NumToInsert5, i32 NumToInsert6, GxtChar* pShortText);
    DECL_FASTCALL_SIMPLE(Display, _ZN9CMessages7DisplayEh, void, u8 bBeforeFade);
    DECL_FASTCALL_SIMPLE(InsertNumberInString, _ZN9CMessages20InsertNumberInStringEPtiiiiiiS0_, void, GxtChar* pOriginalString, i32 NumberToInsert, i32 NumberToInsert2, i32 NumberToInsert3, i32 NumberToInsert4, i32 NumberToInsert5, i32 NumberToInsert6, GxtChar* pNewString);
    DECL_FASTCALL_SIMPLE(InsertStringInString, _ZN9CMessages20InsertStringInStringEPtS0_, void, GxtChar* pBigString, GxtChar* pSmallString);
    DECL_FASTCALL_SIMPLE(CutString, _ZN9CMessages9CutStringEsPcPS0_, i16, i16 CharNum, char* pInString, char** ppCutStrings);
    DECL_FASTCALL_SIMPLE(AddMessage, _ZN9CMessages10AddMessageEPKcPtjtb, void, const char* Label, GxtChar* pText, u32 Duration, u16 Colour, bool bAddToPrevBriefs);
    DECL_FASTCALL_SIMPLE(AddMessageJumpQ, _ZN9CMessages15AddMessageJumpQEPKcPtjtb, void, const char* Label, GxtChar* pText, u32 Duration, u16 Colour, bool bAddToPrevBriefs);
    DECL_FASTCALL_SIMPLE(ClearMessages, _ZN9CMessages13ClearMessagesEh, void, u8 bIgnoreMissionTitle);
    DECL_FASTCALL_SIMPLE(ClearSmallMessagesOnly, _ZN9CMessages22ClearSmallMessagesOnlyEv, void);
    DECL_FASTCALL_SIMPLE(AddBigMessage, _ZN9CMessages13AddBigMessageEPtjt, void, GxtChar* pText, u32 Duration, u16 Row);
    DECL_FASTCALL_SIMPLE(AddBigMessageQ, _ZN9CMessages14AddBigMessageQEPtjt, void, GxtChar* pText, u32 Duration, u16 Row);
    DECL_FASTCALL_SIMPLE(ReloadPreviousBriefArray, _ZN9CMessages24ReloadPreviousBriefArrayEv, void);
    DECL_FASTCALL_SIMPLE(AddMessageWithNumber, _ZN9CMessages20AddMessageWithNumberEPKcPtjtiiiiiib, void, const char* Label, GxtChar* pText, u32 Duration, u16 Colour, i32 NumToInsert, i32 NumToInsert2, i32 NumToInsert3, i32 NumToInsert4, i32 NumToInsert5, i32 NumToInsert6, bool bAddToPrevBriefs);
    DECL_FASTCALL_SIMPLE(AddMessageJumpQWithNumber, _ZN9CMessages25AddMessageJumpQWithNumberEPtjtiiiiiib, void, GxtChar* pText, u32 Duration, u16 Colour, i32 NumToInsert, i32 NumToInsert2, i32 NumToInsert3, i32 NumToInsert4, i32 NumToInsert5, i32 NumToInsert6, bool bAddToPrevBriefs);
    DECL_FASTCALL_SIMPLE(AddBigMessageWithNumber, _ZN9CMessages23AddBigMessageWithNumberEPtjtiiiiii, void, GxtChar* pText, u32 Duration, u16 Row, i32 NumToInsert, i32 NumToInsert2, i32 NumToInsert3, i32 NumToInsert4, i32 NumToInsert5, i32 NumToInsert6);
    DECL_FASTCALL_SIMPLE(AddBigMessageWithNumberQ, _ZN9CMessages24AddBigMessageWithNumberQEPtjtiiiiii, void, GxtChar* pText, u32 Duration, u16 Row, i32 NumToInsert, i32 NumToInsert2, i32 NumToInsert3, i32 NumToInsert4, i32 NumToInsert5, i32 NumToInsert6);
    DECL_FASTCALL_SIMPLE(AddMessageWithString, _ZN9CMessages20AddMessageWithStringEPtjtS0_b, void, GxtChar* pText, u32 Duration, u16 Colour, GxtChar* pShortText, bool bAddToPrevBriefs);
    DECL_FASTCALL_SIMPLE(AddMessageJumpQWithString, _ZN9CMessages25AddMessageJumpQWithStringEPtjtS0_b, void, GxtChar* pText, u32 Duration, u16 Colour, GxtChar* pShortText, bool bAddToPrevBriefs);
    DECL_FASTCALL_SIMPLE(ClearThisPrint, _ZN9CMessages14ClearThisPrintEPt, void, GxtChar* pText);
    DECL_FASTCALL_SIMPLE(ClearThisBigPrint, _ZN9CMessages17ClearThisBigPrintEPt, void, GxtChar* pText);
    DECL_FASTCALL_SIMPLE(ClearThisBigPrintNow, _ZN9CMessages20ClearThisBigPrintNowEj, void, u32 Row);
    DECL_FASTCALL_SIMPLE(ClearAllMessagesDisplayedByGame, _ZN9CMessages31ClearAllMessagesDisplayedByGameEh, void, u8 bIgnoreMissionTitle);

    // Static values
    typedef CQueuedMessage tBIGMessages_row[4];
    DECL_OBJECT_ARRAY_PLT(tBIGMessages_row, BIGMessages, BYBIT(0x6766F8, 0x84AE48));
    DECL_OBJECT_ARRAY_PLT(CQueuedMessage, BriefMessages, BYBIT(0x678B84, 0x84F730));
    DECL_OBJECT_ARRAY_PLT(CPreviousMessage, PreviousBriefs, BYBIT(0x676368, 0x84A728));
DECL_CLASS_END()

#define BIGMessages BIGMessages()
#define BriefMessages BriefMessages()
#define PreviousBriefs PreviousBriefs()

#endif // __AML_PSDK_SAMESSAGES_H
