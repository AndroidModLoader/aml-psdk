#ifndef __AML_PSDK_VCMESSAGES_H
#define __AML_PSDK_VCMESSAGES_H

#include <aml-psdk/game_vc/plugin.h>

DECL_CLASS(CMessages)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(Init, _ZN9CMessages4InitEv, void);
    DECL_FASTCALL_SIMPLE(Process, _ZN9CMessages7ProcessEv, void);
    DECL_FASTCALL_SIMPLE(Display, _ZN9CMessages7DisplayEv, void);
    DECL_FASTCALL_SIMPLE(ClearPreviousBriefArray, _ZN9CMessages23ClearPreviousBriefArrayEv, void);
    DECL_FASTCALL_SIMPLE(ClearSmallMessagesOnly, _ZN9CMessages22ClearSmallMessagesOnlyEv, void);
    DECL_FASTCALL_SIMPLE(ClearMessages, _ZN9CMessages13ClearMessagesEb, void, bool clearMissionMessages);
    DECL_FASTCALL_SIMPLE(ClearAllMessagesDisplayedByGame, _ZN9CMessages31ClearAllMessagesDisplayedByGameEb, void, bool clearMissionMessages);
    DECL_FASTCALL_SIMPLE(ClearThisPrint, _ZN9CMessages14ClearThisPrintEPt, void, u16* text);
    DECL_FASTCALL_SIMPLE(ClearThisBigPrint, _ZN9CMessages17ClearThisBigPrintEPt, void, u16* text);
    DECL_FASTCALL_SIMPLE(AddHelpMessage, _ZN9CMessages14AddHelpMessageEPt, void, u16* text);
    DECL_FASTCALL_SIMPLE(AddMessage, _ZN9CMessages10AddMessageEPtjt, void, u16* text, u32 duration, u16 flag);
    DECL_FASTCALL_SIMPLE(AddMessageJumpQ, _ZN9CMessages15AddMessageJumpQEPtjt, void, u16* text, u32 duration, u16 flag);
    DECL_FASTCALL_SIMPLE(AddMessageSoon, _ZN9CMessages14AddMessageSoonEPtjt, void, u16* text, u32 duration, u16 flag);
    DECL_FASTCALL_SIMPLE(AddBigMessage, _ZN9CMessages13AddBigMessageEPtjt, void, u16* text, u32 duration, u16 flag);
    DECL_FASTCALL_SIMPLE(AddBigMessageQ, _ZN9CMessages14AddBigMessageQEPtjt, void, u16* text, u32 duration, u16 flag);
    DECL_FASTCALL_SIMPLE(AddMessageWithNumber, _ZN9CMessages20AddMessageWithNumberEPtjtiiiiii, void, u16* text, u32 duration, u16 flag, i32 number1, i32 number2, i32 number3, i32 number4, i32 number5, i32 number6);
    DECL_FASTCALL_SIMPLE(AddMessageJumpQWithNumber, _ZN9CMessages25AddMessageJumpQWithNumberEPtjtiiiiii, void, u16* text, u32 duration, u16 flag, i32 number1, i32 number2, i32 number3, i32 number4, i32 number5, i32 number6);
    DECL_FASTCALL_SIMPLE(AddMessageSoonWithNumber, _ZN9CMessages24AddMessageSoonWithNumberEPtjtiiiiii, void, u16* text, u32 duration, u16 flag, i32 number1, i32 number2, i32 number3, i32 number4, i32 number5, i32 number6);
    DECL_FASTCALL_SIMPLE(AddBigMessageWithNumber, _ZN9CMessages23AddBigMessageWithNumberEPtjtiiiiii, void, u16* text, u32 duration, u16 flag, i32 number1, i32 number2, i32 number3, i32 number4, i32 number5, i32 number6);
    DECL_FASTCALL_SIMPLE(AddBigMessageWithNumberQ, _ZN9CMessages24AddBigMessageWithNumberQEPtjtiiiiii, void, u16* text, u32 duration, u16 flag, i32 number1, i32 number2, i32 number3, i32 number4, i32 number5, i32 number6);
    DECL_FASTCALL_SIMPLE(AddMessageWithString, _ZN9CMessages20AddMessageWithStringEPtjtS0_, void, u16* text, u32 duration, u16 flag, u16* string);
    DECL_FASTCALL_SIMPLE(AddMessageJumpQWithString, _ZN9CMessages25AddMessageJumpQWithStringEPtjtS0_, void, u16* text, u32 duration, u16 flag, u16* string);
    DECL_FASTCALL_SIMPLE(AddMessageSoonWithString, _ZN9CMessages24AddMessageSoonWithStringEPtjtS0_, void, u16* text, u32 duration, u16 flag, u16* string);
    DECL_FASTCALL_SIMPLE(GetWideStringLength, _ZN9CMessages19GetWideStringLengthEPt, u16, u16* text);
    DECL_FASTCALL_SIMPLE(WideStringCopy, _ZN9CMessages14WideStringCopyEPtS0_t, void, u16* destination, u16* source, u16 size);
    DECL_FASTCALL_SIMPLE(WideStringCompare, _ZN9CMessages17WideStringCompareEPtS0_t, bool, u16* left, u16* right, u16 size);
    DECL_FASTCALL_SIMPLE(InsertNumberInString, _ZN9CMessages20InsertNumberInStringEPtiiiiiiS0_, void, u16* text, i32 number1, i32 number2, i32 number3, i32 number4, i32 number5, i32 number6, u16* output);
    DECL_FASTCALL_SIMPLE(InsertStringInString, _ZN9CMessages20InsertStringInStringEPtS0_, void, u16* text, u16* string);
    DECL_FASTCALL_SIMPLE(InsertPlayerControlKeysInString, _ZN9CMessages31InsertPlayerControlKeysInStringEPt, void, u16* text);
DECL_CLASS_END()

#endif // __AML_PSDK_VCMESSAGES_H
