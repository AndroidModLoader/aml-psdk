#ifndef __AML_PSDK_SATRAFFICLIGHTS_H
#define __AML_PSDK_SATRAFFICLIGHTS_H

#include <aml-psdk/game_sa/plugin.h>

struct CEntity;
struct CVehicle;

enum eTrafficLightsState
{
    LIGHT_GREEN = 0,
    LIGHT_YELLOW = 1,
    LIGHT_RED = 2,
    LIGHT_OFF = 3
};

DECL_CLASS(CTrafficLights)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(ShouldCarStopForLight, _ZN14CTrafficLights21ShouldCarStopForLightEP8CVehicleb, u8, CVehicle* vehicle, bool bUnkn);
    DECL_FASTCALL_SIMPLE(LightForCars1, _ZN14CTrafficLights13LightForCars1Ev, u8);
    DECL_FASTCALL_SIMPLE(LightForCars2, _ZN14CTrafficLights13LightForCars2Ev, u8);
    DECL_FASTCALL_SIMPLE(LightForCars1_Visual, _ZN14CTrafficLights20LightForCars1_VisualEv, u8);
    DECL_FASTCALL_SIMPLE(LightForCars2_Visual, _ZN14CTrafficLights20LightForCars2_VisualEv, u8);
    DECL_FASTCALL_SIMPLE(LightForPeds, _ZN14CTrafficLights12LightForPedsEv, u8);
    DECL_FASTCALL_SIMPLE(DisplayActualLight, _ZN14CTrafficLights18DisplayActualLightEP7CEntity, void, CEntity* entity);
    DECL_FASTCALL_SIMPLE(FindTrafficLightType, _ZN14CTrafficLights20FindTrafficLightTypeEP7CEntity, i32, CEntity* entity);
    DECL_FASTCALL_SIMPLE(ShouldCarStopForBridge, _ZN14CTrafficLights22ShouldCarStopForBridgeEP8CVehicle, bool, CVehicle* vehicle);
    DECL_FASTCALL_SIMPLE(FindTrafficLightTypeFromOrientation, _ZN14CTrafficLights35FindTrafficLightTypeFromOrientationEf, i32, float fOrientation);
    DECL_FASTCALL_SIMPLE(FindOrientationForTrafficLightType, _ZN14CTrafficLights34FindOrientationForTrafficLightTypeEP7CEntity, float, CEntity* entity);
    DECL_FASTCALL_SIMPLE(IsMITrafficLight, _ZN14CTrafficLights16IsMITrafficLightEi, bool, i32 modelIndex);
DECL_CLASS_END()

#endif // __AML_PSDK_SATRAFFICLIGHTS_H
