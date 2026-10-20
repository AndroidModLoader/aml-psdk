#ifndef __AML_PSDK_SACONVERSATIONS_H
#define __AML_PSDK_SACONVERSATIONS_H

#include <aml-psdk/game_sa/plugin.h>

struct CPed;

DECL_CLASS(CConversationNode)
    // Member functions
    DECL_THISCALL_SIMPLE(Clear, _ZN17CConversationNode5ClearEv, void);
    DECL_THISCALL_SIMPLE(ClearRecursively, _ZN17CConversationNode16ClearRecursivelyEv, void);

    // Member values
    char m_Name[8];
    i16 m_NodeYes;
    i16 m_NodeNo;
    i32 m_Speech;
    i32 m_SpeechY;
    i32 m_SpeechN;
DECL_CLASS_END()
CHECKSIZE(CConversationNode, 0x18, 0x18);

DECL_CLASS(CTempConversationNode)
    // Member values
    char m_Name[8];
    char m_NameNodeYes[8];
    char m_NameNodeNo[8];
    i32 m_FinalSlot;
    i16 m_NodeYes;
    i16 m_NodeNo;
    i32 m_Speech;
    i32 m_SpeechY;
    i32 m_SpeechN;
DECL_CLASS_END()
CHECKSIZE(CTempConversationNode, 0x2c, 0x2c);

DECL_CLASS(CConversationForPed)
    enum
    {
        STATUS_INACTIVE = 0,
        STATUS_PLAYER_SPEAKING = 1,
        STATUS_PED_SPEAKING = 2,
        STATUS_WAITINGFORINPUT = 3
    };

    // Member functions
    DECL_THISCALL_HEAD(Clear, _ZN19CConversationForPed5ClearEb, void, bool clearPed)
    DECL_THISCALL_TAIL(Clear, clearPed)
    DECL_THISCALL_SIMPLE(Update, _ZN19CConversationForPed6UpdateEv, void);
    DECL_THISCALL_HEAD(IsPlayerInPositionForConversation, _ZN19CConversationForPed33IsPlayerInPositionForConversationEb, bool, bool checkDistance)
    DECL_THISCALL_TAIL(IsPlayerInPositionForConversation, checkDistance)

    // Member values
    i32 m_FirstNode;
    i32 m_CurrentNode;
    CPed* m_pPed;
    u32 m_LastChange;
    u32 m_LastTimeWeWereCloseEnough;
    i32 m_Status;
    bool m_bEnabled;
    bool m_bSuppressSubtitles;
DECL_CLASS_END()
CHECKSIZE(CConversationForPed, 0x1c, 0x20);

DECL_CLASS(CConversations)
    enum
    {
        AWKWARDSAY_INACTIVE = 0,
        AWKWARDSAY_LOADING = 1,
        AWKWARDSAY_PLAYING = 2
    };

    // STATIC functions
    DECL_FASTCALL_SIMPLE(Clear, _ZN14CConversations5ClearEv, void);
    DECL_FASTCALL_SIMPLE(Update, _ZN14CConversations6UpdateEv, void);
    DECL_FASTCALL_SIMPLE(AwkwardSay, _ZN14CConversations10AwkwardSayEiP4CPed, void, i32 speech, CPed* ped);
    DECL_FASTCALL_SIMPLE(StartSettingUpConversation, _ZN14CConversations26StartSettingUpConversationEP4CPed, void, CPed* ped);
    DECL_FASTCALL_SIMPLE(DoneSettingUpConversation, _ZN14CConversations25DoneSettingUpConversationEb, void, bool suppressSubtitles);
    DECL_FASTCALL_SIMPLE(SetUpConversationNode, _ZN14CConversations21SetUpConversationNodeEPcS0_S0_iii, void, char* name, char* yesNode, char* noNode, i32 speech, i32 yesSpeech, i32 noSpeech);
    DECL_FASTCALL_SIMPLE(IsConversationAtNode, _ZN14CConversations20IsConversationAtNodeEPcP4CPed, bool, char* name, CPed* ped);
    DECL_FASTCALL_SIMPLE(RemoveConversationForPed, _ZN14CConversations24RemoveConversationForPedEP4CPed, void, CPed* ped);
    DECL_FASTCALL_SIMPLE(FindFreeConversationSlot, _ZN14CConversations24FindFreeConversationSlotEv, CConversationForPed*);
    DECL_FASTCALL_SIMPLE(FindConversationForPed, _ZN14CConversations22FindConversationForPedEP4CPed, CConversationForPed*, CPed* ped);
    DECL_FASTCALL_SIMPLE(FindFreeNodeSlot, _ZN14CConversations16FindFreeNodeSlotEv, i32);
    DECL_FASTCALL_SIMPLE(IsPlayerInPositionForConversation, _ZN14CConversations33IsPlayerInPositionForConversationEP4CPedb, bool, CPed* ped, bool checkDistance);
    DECL_FASTCALL_SIMPLE(EnableConversation, _ZN14CConversations18EnableConversationEP4CPedb, void, CPed* ped, bool enabled);
    DECL_FASTCALL_SIMPLE(GetConversationStatus, _ZN14CConversations21GetConversationStatusEP4CPed, i32, CPed* ped);
    DECL_FASTCALL_SIMPLE(IsConversationGoingOn, _ZN14CConversations21IsConversationGoingOnEv, bool);

    // STATIC values
    DECL_OBJECT_ARRAY_PLT(CConversationNode, m_aNodes, BYBIT(0x677238, 0x84c4a8));
    DECL_OBJECT_ARRAY_PLT(CTempConversationNode, m_aTempNodes, BYBIT(0x6767d4, 0x84b000));
    DECL_OBJECT_ARRAY_PLT(CConversationForPed, m_aConversations, BYBIT(0x676014, 0x84a098));
    DECL_OBJECT_PLT(bool, m_bSettingUpConversation, BYBIT(0x676884, 0x84b160));
    DECL_OBJECT_PLT(CPed*, m_pSettingUpConversationPed, BYBIT(0x676778, 0x84af48));
    DECL_OBJECT_PLT(i32, m_SettingUpConversationNumNodes, BYBIT(0x6764cc, 0x84a9f0));
    DECL_OBJECT_PLT(i32, m_AwkwardSayStatus, BYBIT(0x678598, 0x84eb48));

DECL_CLASS_END()
CHECKSIZE(CConversations, 0x1, 0x1);

DECL_CLASS(CPedToPlayerConversations)
    enum
    {
        P2PSTATE_INACTIVE = 0,
        P2PSTATE_PEDHASOPENED = 1,
        P2PSTATE_WAITINGFORFINALWORD = 2,
        P2PSTATE_WAITINGTOFINISH = 3
    };

    // STATIC functions
    DECL_FASTCALL_SIMPLE(Clear, _ZN25CPedToPlayerConversations5ClearEv, void);
    DECL_FASTCALL_SIMPLE(Update, _ZN25CPedToPlayerConversations6UpdateEv, void);
    DECL_FASTCALL_SIMPLE(EndConversation, _ZN25CPedToPlayerConversations15EndConversationEv, void);

    // STATIC values
    DECL_OBJECT_PLT(u32, m_State, BYBIT(0x676900, 0x84b250));
    DECL_OBJECT_PLT(CPed*, m_pPed, BYBIT(0x679978, 0x851308));
    DECL_OBJECT_PLT(u32, m_Topic, BYBIT(0x6764e0, 0x84aa18));
    DECL_OBJECT_PLT(u32, m_StartTime, BYBIT(0x6786c8, 0x84edb8));
    DECL_OBJECT_PLT(u32, m_TimeOfLastPlayerConversation, BYBIT(0x6791c0, 0x8503a0));
    DECL_OBJECT_PLT(bool, m_bPositiveOpening, BYBIT(0x678c9c, 0x84f960));
    DECL_OBJECT_SYM(bool, m_bPositiveReply, _ZN25CPedToPlayerConversations16m_bPositiveReplyE);

DECL_CLASS_END()
CHECKSIZE(CPedToPlayerConversations, 0x1, 0x1);

#endif // __AML_PSDK_SACONVERSATIONS_H
