#ifndef __AML_PSDK_SAGROUPEVENTHANDLER_H
#define __AML_PSDK_SAGROUPEVENTHANDLER_H

#include "../plugin.h"

struct CEvent;
struct CEventGroupEvent;
struct CPed;
struct CPedGroup;
struct CTaskAllocator;

DECL_CLASS(CGroupEventHandler)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(ComputeEventResponseTasks, _ZN18CGroupEventHandler25ComputeEventResponseTasksERK16CEventGroupEventP9CPedGroup, CTaskAllocator*, CEventGroupEvent const& event, CPedGroup* group);
    DECL_FASTCALL_SIMPLE(ComputeResponseLeaderEnteredCar, _ZN18CGroupEventHandler31ComputeResponseLeaderEnteredCarERK6CEventP9CPedGroupP4CPed, CTaskAllocator*, CEvent const& event, CPedGroup* group, CPed* ped);
    DECL_FASTCALL_SIMPLE(ComputeResponseLeaderExitedCar, _ZN18CGroupEventHandler30ComputeResponseLeaderExitedCarERK6CEventP9CPedGroupP4CPed, CTaskAllocator*, CEvent const& event, CPedGroup* group, CPed* ped);
    DECL_FASTCALL_SIMPLE(ComputeResponsLeaderQuitEnteringCar, _ZN18CGroupEventHandler35ComputeResponsLeaderQuitEnteringCarERK6CEventP9CPedGroupP4CPed, CTaskAllocator*, CEvent const& event, CPedGroup* group, CPed* ped);
    DECL_FASTCALL_SIMPLE(ComputeResponseLeaderEnterExit, _ZN18CGroupEventHandler30ComputeResponseLeaderEnterExitERK6CEventP9CPedGroupP4CPed, CTaskAllocator*, CEvent const& event, CPedGroup* group, CPed* ped);
    DECL_FASTCALL_SIMPLE(ComputeResponsePedThreat, _ZN18CGroupEventHandler24ComputeResponsePedThreatERK6CEventP9CPedGroupP4CPed, CTaskAllocator*, CEvent const& event, CPedGroup* group, CPed* ped);
    DECL_FASTCALL_SIMPLE(ComputeResponsePedFriend, _ZN18CGroupEventHandler24ComputeResponsePedFriendERK6CEventP9CPedGroupP4CPed, CTaskAllocator*, CEvent const& event, CPedGroup* group, CPed* ped);
    DECL_FASTCALL_SIMPLE(ComputeResponseSeenCop, _ZN18CGroupEventHandler22ComputeResponseSeenCopERK6CEventP9CPedGroupP4CPed, CTaskAllocator*, CEvent const& event, CPedGroup* group, CPed* ped);
    DECL_FASTCALL_SIMPLE(ComputeResponseDamage, _ZN18CGroupEventHandler21ComputeResponseDamageERK6CEventP9CPedGroupP4CPed, CTaskAllocator*, CEvent const& event, CPedGroup* group, CPed* ped);
    DECL_FASTCALL_SIMPLE(ComputeResponseSexyPed, _ZN18CGroupEventHandler22ComputeResponseSexyPedERK6CEventP9CPedGroupP4CPed, CTaskAllocator*, CEvent const& event, CPedGroup* group, CPed* ped);
    DECL_FASTCALL_SIMPLE(ComputeResponseGunAimedAt, _ZN18CGroupEventHandler25ComputeResponseGunAimedAtERK6CEventP9CPedGroupP4CPed, CTaskAllocator*, CEvent const& event, CPedGroup* group, CPed* ped);
    DECL_FASTCALL_SIMPLE(ComputeResponseShotFired, _ZN18CGroupEventHandler24ComputeResponseShotFiredERK6CEventP9CPedGroupP4CPed, CTaskAllocator*, CEvent const& event, CPedGroup* group, CPed* ped);
    DECL_FASTCALL_SIMPLE(ComputeResponseDraggedOutCar, _ZN18CGroupEventHandler28ComputeResponseDraggedOutCarERK6CEventP9CPedGroupP4CPed, CTaskAllocator*, CEvent const& event, CPedGroup* group, CPed* ped);
    DECL_FASTCALL_SIMPLE(ComputeResponseVehicleDamage, _ZN18CGroupEventHandler28ComputeResponseVehicleDamageERK6CEventP9CPedGroupP4CPed, CTaskAllocator*, CEvent const& event, CPedGroup* group, CPed* ped);
    DECL_FASTCALL_SIMPLE(ComputeResponseNewGangMember, _ZN18CGroupEventHandler28ComputeResponseNewGangMemberERK6CEventP9CPedGroupP4CPed, CTaskAllocator*, CEvent const& event, CPedGroup* group, CPed* ped);
    DECL_FASTCALL_SIMPLE(ComputeResponsePlayerCommand, _ZN18CGroupEventHandler28ComputeResponsePlayerCommandERK6CEventP9CPedGroupP4CPed, CTaskAllocator*, CEvent const& event, CPedGroup* group, CPed* ped);
    DECL_FASTCALL_SIMPLE(ComputeResponseDanger, _ZN18CGroupEventHandler21ComputeResponseDangerERK6CEventP9CPedGroupP4CPed, CTaskAllocator*, CEvent const& event, CPedGroup* group, CPed* ped);
    DECL_FASTCALL_SIMPLE(ComputeLeanOnVehicleResponse, _ZN18CGroupEventHandler28ComputeLeanOnVehicleResponseERK6CEventP9CPedGroupP4CPed, CTaskAllocator*, CEvent const& event, CPedGroup* group, CPed* ped);
    DECL_FASTCALL_SIMPLE(ComputeResponseGather, _ZN18CGroupEventHandler21ComputeResponseGatherERK6CEventP9CPedGroupP4CPed, CTaskAllocator*, CEvent const& event, CPedGroup* group, CPed* ped);
    DECL_FASTCALL_SIMPLE(ComputeMemberResponses, _ZN18CGroupEventHandler22ComputeMemberResponsesERK6CEventP9CPedGroupP4CPed, CTaskAllocator*, CEvent const& event, CPedGroup* group, CPed* ped);
    DECL_FASTCALL_SIMPLE(ComputeKillThreatsBasicResponse, _ZN18CGroupEventHandler31ComputeKillThreatsBasicResponseEP9CPedGroupP4CPedS3_h, CTaskAllocator*, CPedGroup* group, CPed* ped, CPed* target, u8 option);
    DECL_FASTCALL_SIMPLE(ComputeKillPlayerBasicResponse, _ZN18CGroupEventHandler30ComputeKillPlayerBasicResponseEP9CPedGroupP4CPedS3_h, CTaskAllocator*, CPedGroup* group, CPed* ped, CPed* target, u8 option);
    DECL_FASTCALL_SIMPLE(ComputeFleePedResponse, _ZN18CGroupEventHandler22ComputeFleePedResponseEP9CPedGroupP4CPedS3_h, CTaskAllocator*, CPedGroup* group, CPed* ped, CPed* target, u8 option);
    DECL_FASTCALL_SIMPLE(ComputeStareResponse, _ZN18CGroupEventHandler20ComputeStareResponseEP9CPedGroupP4CPedS3_ii, CTaskAllocator*, CPedGroup* group, CPed* ped, CPed* target, i32 parameter1, i32 parameter2);
    DECL_FASTCALL_SIMPLE(ComputeHassleThreatResponse, _ZN18CGroupEventHandler27ComputeHassleThreatResponseEP9CPedGroupP4CPedS3_b, CTaskAllocator*, CPedGroup* group, CPed* ped, CPed* target, bool option);
    DECL_FASTCALL_SIMPLE(ComputeHassleSexyPedResponse, _ZN18CGroupEventHandler28ComputeHassleSexyPedResponseEP9CPedGroupP4CPedS3_, CTaskAllocator*, CPedGroup* group, CPed* ped, CPed* target);
    DECL_FASTCALL_SIMPLE(ComputeDoDealResponse, _ZN18CGroupEventHandler21ComputeDoDealResponseEP9CPedGroupP4CPedS3_, CTaskAllocator*, CPedGroup* group, CPed* ped, CPed* target);
    DECL_FASTCALL_SIMPLE(ComputeGreetResponse, _ZN18CGroupEventHandler20ComputeGreetResponseEP9CPedGroupP4CPedS3_, CTaskAllocator*, CPedGroup* group, CPed* ped, CPed* target);
    DECL_FASTCALL_SIMPLE(ComputeHandSignalResponse, _ZN18CGroupEventHandler25ComputeHandSignalResponseEP9CPedGroupP4CPedS3_, CTaskAllocator*, CPedGroup* group, CPed* ped, CPed* target);
    DECL_FASTCALL_SIMPLE(ComputeDrivebyResponse, _ZN18CGroupEventHandler22ComputeDrivebyResponseEP9CPedGroupP4CPedS3_, CTaskAllocator*, CPedGroup* group, CPed* ped, CPed* target);
    DECL_FASTCALL_SIMPLE(ComputeWalkAlongsideResponse, _ZN18CGroupEventHandler28ComputeWalkAlongsideResponseEP9CPedGroupP4CPedS3_, CTaskAllocator*, CPedGroup* group, CPed* ped, CPed* target);
    DECL_FASTCALL_SIMPLE(IsKillTaskAppropriate, _ZN18CGroupEventHandler21IsKillTaskAppropriateEP9CPedGroupP4CPed, bool, CPedGroup* group, CPed* ped);
DECL_CLASS_END()
CHECKSIZE(CGroupEventHandler, 0x1, 0x1);

#endif // __AML_PSDK_SAGROUPEVENTHANDLER_H
