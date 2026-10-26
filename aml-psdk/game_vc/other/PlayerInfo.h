#ifndef __AML_PSDK_VCPLAYERINFO_H
#define __AML_PSDK_VCPLAYERINFO_H

#include <aml-psdk/game_vc/plugin.h>
#include <aml-psdk/gta_base/Vector.h>

struct CPlayerPed;
struct CVehicle;
struct CEntity;

DECL_FASTCALL_SIMPLE_GLO(FindPlayerPed, _Z13FindPlayerPedv, CPlayerPed*);
DECL_FASTCALL_SIMPLE_GLO(FindPlayerVehicle, _Z17FindPlayerVehiclev, CVehicle*);
DECL_FASTCALL_SIMPLE_GLO(FindPlayerTrain, _Z15FindPlayerTrainv, CVehicle*);
DECL_FASTCALL_SIMPLE_GLO(FindPlayerEntity, _Z16FindPlayerEntityv, CEntity*);
DECL_FASTCALL_SIMPLE_GLO(FindPlayerCoors, _Z15FindPlayerCoorsv, CVector);
DECL_FASTCALL_SIMPLE_GLO(FindPlayerSpeed, _Z15FindPlayerSpeedv, CVector&);
DECL_FASTCALL_SIMPLE_GLO(FindPlayerHeading, _Z17FindPlayerHeadingv, float);
DECL_FASTCALL_SIMPLE_GLO(FindPlayerHeight, _Z16FindPlayerHeightv, float);
DECL_FASTCALL_SIMPLE_GLO(FindPlayerCentreOfWorld, _Z23FindPlayerCentreOfWorldi, CVector&, i32 playerId);
DECL_FASTCALL_SIMPLE_GLO(FindPlayerCentreOfWorld_NoSniperShift, _Z37FindPlayerCentreOfWorld_NoSniperShiftv, CVector&);

#endif // __AML_PSDK_VCPLAYERINFO_H
