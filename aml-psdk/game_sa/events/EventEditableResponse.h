#ifndef __AML_PSDK_SAEVENTEDITABLERESPONSE_H
#define __AML_PSDK_SAEVENTEDITABLERESPONSE_H

#include "Event.h"

DECL_CLASS_BASED(CEventEditableResponse, CEvent)
    // Construct/Deconstruct functions
    DECL_DTORCALL_PROXY(CEventEditableResponse, _ZN22CEventEditableResponseD2Ev);
    DECL_CTORCALL_PROXY(CEventEditableResponse, _ZN22CEventEditableResponseC2Ev);

    // Virtual functions
    virtual CEvent* CloneEditable() const;

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
    

    /*
DECL_THISCALL_HEAD(ComputeResponseTask, _ZN22CEventEditableResponse, void, CVector vecForce)


    DECL_THISCALL_TAIL(ComputeResponseTask, vecForce)
    
    DECL_THISCALL_HEAD(ComputeResponseTask, _ZN22CEventEditableResponse, void, CVector vecForce)
    DECL_THISCALL_TAIL(ComputeResponseTask, vecForce)
    
    DECL_THISCALL_HEAD(ComputeResponseTask, _ZN22CEventEditableResponse, void, CVector vecForce)
    DECL_THISCALL_TAIL(ComputeResponseTask, vecForce)
    
    DECL_THISCALL_HEAD(ComputeResponseTask, _ZN22CEventEditableResponse, void, CVector vecForce)
    DECL_THISCALL_TAIL(ComputeResponseTask, vecForce)
    
    DECL_THISCALL_HEAD(ComputeResponseTask, _ZN22CEventEditableResponse, void, CVector vecForce)
    DECL_THISCALL_TAIL(ComputeResponseTask, vecForce)
    
    DECL_THISCALL_HEAD(ComputeResponseTask, _ZN22CEventEditableResponse, void, CVector vecForce)
    DECL_THISCALL_TAIL(ComputeResponseTask, vecForce)
    
    DECL_THISCALL_HEAD(ComputeResponseTask, _ZN22CEventEditableResponse, void, CVector vecForce)
    DECL_THISCALL_TAIL(ComputeResponseTask, vecForce)*/

    // Member values
    bool m_bWitnessedFirstHand;
    short m_iTaskType;
    short m_iFacialTaskType;
DECL_CLASS_END()

#endif // __AML_PSDK_SAEVENTEDITABLERESPONSE_H
