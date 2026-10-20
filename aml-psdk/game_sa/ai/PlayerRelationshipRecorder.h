#ifndef __AML_PSDK_SAPLAYERRELATIONSHIPRECORDER_H
#define __AML_PSDK_SAPLAYERRELATIONSHIPRECORDER_H

#include <aml-psdk/game_sa/plugin.h>

struct CPed;

DECL_CLASS(CPlayerRelationshipRecord)
    // Member values
    CPed const* m_pPed;
    u8 m_iType;
DECL_CLASS_END()
CHECKSIZE(CPlayerRelationshipRecord, 0x8, 0x10);

DECL_CLASS(CPlayerRelationshipRecorder)
    enum
    {
        MAX_PLAYER_RELATIONSHIPS = 16
    };

    // Construct/Deconstruct functions
    DECL_CTORCALL(CPlayerRelationshipRecorder, _ZN27CPlayerRelationshipRecorderC2Ev);
    DECL_DTORCALL(CPlayerRelationshipRecorder, _ZN27CPlayerRelationshipRecorderD2Ev);

    // Member functions
    DECL_THISCALL_HEAD(RecordRelationshipWithPlayer, _ZN27CPlayerRelationshipRecorder28RecordRelationshipWithPlayerEPK4CPed, void, CPed const* ped)
    DECL_THISCALL_TAIL(RecordRelationshipWithPlayer, ped)
    DECL_FASTCALL_SIMPLE(FuncProxy_GetRelationshipWithPlayer, _ZNK27CPlayerRelationshipRecorder25GetRelationshipWithPlayerEPK4CPed, u8, ThisClass const* self, CPed const* ped);
    inline u8 GetRelationshipWithPlayer(CPed const* ped) const { return FuncProxy_GetRelationshipWithPlayer(this, ped); }
    DECL_THISCALL_HEAD(ClearRelationshipWithPlayer, _ZN27CPlayerRelationshipRecorder27ClearRelationshipWithPlayerEPK4CPed, void, CPed const* ped)
    DECL_THISCALL_TAIL(ClearRelationshipWithPlayer, ped)
    DECL_THISCALL_SIMPLE(Flush, _ZN27CPlayerRelationshipRecorder5FlushEv, void);
    DECL_THISCALL_HEAD(AddRelationship, _ZN27CPlayerRelationshipRecorder15AddRelationshipEPK4CPedi, void, CPed const* ped, i32 const type)
    DECL_THISCALL_TAIL(AddRelationship, ped, type)

    // Member values
    CPlayerRelationshipRecord m_records[16];
DECL_CLASS_END()
CHECKSIZE(CPlayerRelationshipRecorder, 0x80, 0x100);

#endif // __AML_PSDK_SAPLAYERRELATIONSHIPRECORDER_H
