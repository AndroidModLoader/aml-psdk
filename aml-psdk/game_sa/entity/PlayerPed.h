#ifndef __AML_PSDK_SAPLAYERPED_H
#define __AML_PSDK_SAPLAYERPED_H

#include "Ped.h"

DECL_CLASS_BASED(CPlayerPed, CPed)
    // Construct/Deconstruct functions
    CPlayerPed(){}
    DECL_CTORCALL_ARG_HEAD(CPlayerPed, _ZN10CPlayerPedC2Eib, i32 nPlayerInfoIndex, bool bForReplay)
    DECL_CTORCALL_ARG_TAIL(nPlayerInfoIndex, bForReplay)
    DECL_DTORCALL(CPlayerPed, _ZN10CPlayerPedD2Ev)

    // Member values
    CPed *m_pPlayerTargettedPed;
    int m_iMouseLockOnRecruitTimer;
DECL_CLASS_END()
CHECKSIZE(CPlayerPed, 0x7AC, 0x998);

DECL_FASTCALL_SIMPLE_GLO(FindPlayerPed, _Z13FindPlayerPedi, CPlayerPed*, int PlayerNum);
DECL_FASTCALL_SIMPLE_GLO(FindPlayerSpeed, _Z15FindPlayerSpeedi, CVector*, int PlayerNum);
DECL_FASTCALL_SIMPLE_GLO(FindPlayerVehicle, _Z17FindPlayerVehicleib, CVehicle*, int PlayerNum, bool bReturnRemoteVehicle);
DECL_FASTCALL_SIMPLE_GLO(FindPlayerTrain, _Z15FindPlayerTraini, CVehicle*, int PlayerNum);
DECL_FASTCALL_SIMPLE_GLO(IsPlayerRemotePlane, _Z19IsPlayerRemotePlanev, bool);
DECL_FASTCALL_SIMPLE_GLO(FindPlayerEntity, _Z16FindPlayerEntityi, CEntity*, int PlayerNum);
DECL_FASTCALL_SIMPLE_GLO(FindPlayerWanted, _Z16FindPlayerWantedi, CWanted*, int PlayerNum);
DECL_FASTCALL_SIMPLE_GLO(FindPlayerCentreOfWorld, _Z23FindPlayerCentreOfWorldi, CVector*, int PlayerNum);
DECL_FASTCALL_SIMPLE_GLO(FindPlayerCentreOfWorld_NoSniperShift, _Z37FindPlayerCentreOfWorld_NoSniperShifti, CVector*, int PlayerNum);
DECL_FASTCALL_SIMPLE_GLO(FindPlayerCentreOfWorldForMap, _Z29FindPlayerCentreOfWorldForMapi, CVector, int PlayerNum);
DECL_FASTCALL_SIMPLE_GLO(FindPlayerHeading, _Z17FindPlayerHeadingi, float, int PlayerNum);
DECL_FASTCALL_SIMPLE_GLO(FindPlayerHeight, _Z16FindPlayerHeightv, float);
DECL_FASTCALL_SIMPLE_GLO(FindPlayerCoors, _Z15FindPlayerCoorsi, CVector, int PlayerNum);

#endif // __AML_PSDK_SAPLAYERPED_H
