#ifndef __AML_PSDK_SAREMOTE_H
#define __AML_PSDK_SAREMOTE_H

#include <aml-psdk/game_sa/plugin.h>

struct CVehicle;

DECL_CLASS(CRemote)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(GivePlayerRemoteControlledCar, _ZN7CRemote29GivePlayerRemoteControlledCarEfffft, void, float x, float y, float z, float rotation, u16 modelId);
    DECL_FASTCALL_SIMPLE(TakeRemoteControlledCarFromPlayer, _ZN7CRemote33TakeRemoteControlledCarFromPlayerEb, void, bool bCreateRemoteVehicleExplosion);
    DECL_FASTCALL_SIMPLE(TakeRemoteControlOfCar, _ZN7CRemote22TakeRemoteControlOfCarEP8CVehicle, void, CVehicle* pVehicle);
DECL_CLASS_END()

#endif // __AML_PSDK_SAREMOTE_H
