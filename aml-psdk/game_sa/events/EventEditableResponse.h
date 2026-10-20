#ifndef __AML_PSDK_SAEVENTEDITABLERESPONSE_H
#define __AML_PSDK_SAEVENTEDITABLERESPONSE_H

#include "Event.h"

DECL_CLASS_BASED(CEventEditableResponse, CEvent)
    DECL_VIRTUALCALL_CONST_HEAD(CEventEditableResponse, Clone, _ZTV22CEventEditableResponse, 5, CEvent*)
    DECL_VIRTUALCALL_TAIL()

    // Construct/Deconstruct functions
    DECL_DTORCALL_VIRTUAL(CEventEditableResponse, _ZN22CEventEditableResponseD2Ev, _ZN22CEventEditableResponse, _ZTV22CEventEditableResponse);
    DECL_CTORCALL(CEventEditableResponse, _ZN22CEventEditableResponseC2Ev);

    // Virtual functions
    DECL_VIRTUALCALL_CONST_HEAD(CEventEditableResponse, HasEditableResponse, _ZTV22CEventEditableResponse, 10, bool)
    DECL_VIRTUALCALL_TAIL()
    virtual CEvent* CloneEditable() const = 0;

    // Member functions
    DECL_THISCALL_NAMED_HEAD(ComputeResponseTaskType1, ComputeResponseTaskType, _ZN22CEventEditableResponse23ComputeResponseTaskTypeEP4CPedb, void, CPed* pPed, bool bUseInGroupDecisionMaker)
    DECL_THISCALL_TAIL(ComputeResponseTaskType1, pPed, bUseInGroupDecisionMaker)
    DECL_THISCALL_HEAD(ComputeResponseTaskOfType, _ZNK22CEventEditableResponse25ComputeResponseTaskOfTypeEP4CPedi, bool, CPed* pPed, i32 iTaskTypeToSeek)
    DECL_THISCALL_TAIL(ComputeResponseTaskOfType, pPed, iTaskTypeToSeek)
    DECL_THISCALL_HEAD(InformGroup, _ZNK22CEventEditableResponse11InformGroupEP4CPed, bool, CPed* pPed)
    DECL_THISCALL_TAIL(InformGroup, pPed)
    DECL_THISCALL_HEAD(InformRespectedFriends, _ZNK22CEventEditableResponse22InformRespectedFriendsEP4CPed, bool, CPed* pPed)
    DECL_THISCALL_TAIL(InformRespectedFriends, pPed)
    DECL_THISCALL_HEAD(InformVehicleOccupants, _ZNK22CEventEditableResponse22InformVehicleOccupantsEP4CPed, bool, CPed* pPed)
    DECL_THISCALL_TAIL(InformVehicleOccupants, pPed)
    DECL_THISCALL_HEAD(TriggerLookAt, _ZNK22CEventEditableResponse13TriggerLookAtEP4CPed, bool, CPed* pPed)
    DECL_THISCALL_TAIL(TriggerLookAt, pPed)
    DECL_THISCALL_SIMPLE(WillRespond, _ZNK22CEventEditableResponse11WillRespondEv, bool);
    
    DECL_THISCALL_HEAD(ComputeResponseTaskType, _ZN22CEventEditableResponse23ComputeResponseTaskTypeEP9CPedGroup, void, CPedGroup* pPedGroup);
    DECL_THISCALL_TAIL(ComputeResponseTaskType, pPedGroup)

    inline void SetResponseTaskType(i32 taskType) { m_iTaskType = (i16)taskType; }
    inline void SetFacialResponseTaskType(i32 taskType) { m_iFacialTaskType = (i16)taskType; }
    inline i32 GetResponseTaskType() const { return m_iTaskType; }
    inline i32 GetFacialResponseTaskType() const { return m_iFacialTaskType; }

    // Member values
    bool m_bWitnessedFirstHand;
    short m_iTaskType;
    short m_iFacialTaskType;
DECL_CLASS_END()
CHECKSIZE(CEventEditableResponse, 0x10, 0x18);

#endif // __AML_PSDK_SAEVENTEDITABLERESPONSE_H
