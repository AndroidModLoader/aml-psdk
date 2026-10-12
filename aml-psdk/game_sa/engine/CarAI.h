#ifndef __AML_PSDK_SACARAI_H
#define __AML_PSDK_SACARAI_H

/*
    Plugin-SDK (Grand Theft Auto San Andreas) header file
    Authors: GTA Community. See more here
    https://github.com/DK22Pac/plugin-sdk
    Do not delete this comment block. Respect others' work!
*/

#include <aml-psdk/game_sa/plugin.h>

struct CEntity;
struct CVehicle;
struct CVector;

DECL_CLASS(CCarAI)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(FindSwitchDistanceClose, _ZN6CCarAI23FindSwitchDistanceCloseEP8CVehicle, float, CVehicle* pVehicle);
    DECL_FASTCALL_SIMPLE(FindSwitchDistanceFar, _ZN6CCarAI21FindSwitchDistanceFarEP8CVehicle, float, CVehicle* pVehicle);
    DECL_FASTCALL_SIMPLE(EntitiesGoHeadOn, _ZN6CCarAI16EntitiesGoHeadOnEP7CEntityS1_, bool, CEntity* pEntity1, CEntity* pEntity2);
    DECL_FASTCALL_SIMPLE(BackToCruisingIfNoWantedLevel, _ZN6CCarAI29BackToCruisingIfNoWantedLevelEP8CVehicle, void, CVehicle* pVehicle);
    DECL_FASTCALL_SIMPLE(UpdateCarAI, _ZN6CCarAI11UpdateCarAIEP8CVehicle, void, CVehicle* pVehicle);
    DECL_FASTCALL_SIMPLE(CarHasReasonToStop, _ZN6CCarAI18CarHasReasonToStopEP8CVehicle, void, CVehicle* pVehicle);
    DECL_FASTCALL_SIMPLE(GetCarToGoToCoors, _ZN6CCarAI17GetCarToGoToCoorsEP8CVehicleP7CVectorib, float, CVehicle* pVehicle1, CVector* pVector, i32 drivingStyle, bool bSpeedLimit20);
    DECL_FASTCALL_SIMPLE(GetCarToGoToCoorsStraightLine, _ZN6CCarAI29GetCarToGoToCoorsStraightLineEP8CVehicleP7CVectorib, float, CVehicle* pVehicle1, CVector* pVector, i32 drivingStyle, bool bSpeedLimit20);
    DECL_FASTCALL_SIMPLE(GetCarToGoToCoorsAccurate, _ZN6CCarAI25GetCarToGoToCoorsAccurateEP8CVehicleP7CVectorib, float, CVehicle* pVehicle1, CVector* pVector, i32 drivingStyle, bool bSpeedLimit20);
    DECL_FASTCALL_SIMPLE(GetCarToGoToCoorsRacing, _ZN6CCarAI23GetCarToGoToCoorsRacingEP8CVehicleP7CVectorib, float, CVehicle* pVehicle1, CVector* pVector, i32 drivingStyle, bool bSpeedLimit20);
    DECL_FASTCALL_SIMPLE(GetCarToParkAtCoors, _ZN6CCarAI19GetCarToParkAtCoorsEP8CVehicleP7CVector, float, CVehicle* pVehicle, CVector* pVector);
    DECL_FASTCALL_SIMPLE(AddPoliceCarOccupants, _ZN6CCarAI21AddPoliceCarOccupantsEP8CVehicleb, void, CVehicle* pVehicle, bool arg2);
    DECL_FASTCALL_SIMPLE(AddAmbulanceOccupants, _ZN6CCarAI21AddAmbulanceOccupantsEP8CVehicle, void, CVehicle* pVehicle);
    DECL_FASTCALL_SIMPLE(AddFiretruckOccupants, _ZN6CCarAI21AddFiretruckOccupantsEP8CVehicle, void, CVehicle* pVehicle);
    DECL_FASTCALL_SIMPLE(TellOccupantsToLeaveCar, _ZN6CCarAI23TellOccupantsToLeaveCarEP8CVehicle, void, CVehicle* pVehicle);
    DECL_FASTCALL_SIMPLE(TellCarToRamOtherCar, _ZN6CCarAI20TellCarToRamOtherCarEP8CVehicleS1_, void, CVehicle* pVehicle1, CVehicle* pVehicle2);
    DECL_FASTCALL_SIMPLE(TellCarToBlockOtherCar, _ZN6CCarAI22TellCarToBlockOtherCarEP8CVehicleS1_, void, CVehicle* pVehicle1, CVehicle* pVehicle2);
    DECL_FASTCALL_SIMPLE(TellCarToFollowOtherCar, _ZN6CCarAI23TellCarToFollowOtherCarEP8CVehicleS1_f, void, CVehicle* pVehicle1, CVehicle* pVehicle2, float radius);
    DECL_FASTCALL_SIMPLE(FindPoliceCarMissionForWantedLevel, _ZN6CCarAI34FindPoliceCarMissionForWantedLevelEv, i8);
    DECL_FASTCALL_SIMPLE(FindPoliceBikeMissionForWantedLevel, _ZN6CCarAI35FindPoliceBikeMissionForWantedLevelEv, i8);
    DECL_FASTCALL_SIMPLE(FindPoliceBoatMissionForWantedLevel, _ZN6CCarAI35FindPoliceBoatMissionForWantedLevelEv, i8);
    DECL_FASTCALL_SIMPLE(FindPoliceCarSpeedForWantedLevel, _ZN6CCarAI32FindPoliceCarSpeedForWantedLevelEP8CVehicle, i32, CVehicle* pVehicle);
    DECL_FASTCALL_SIMPLE(MellowOutChaseSpeed, _ZN6CCarAI19MellowOutChaseSpeedEP8CVehicle, void, CVehicle* pVehicle);
    DECL_FASTCALL_SIMPLE(MellowOutChaseSpeedBoat, _ZN6CCarAI23MellowOutChaseSpeedBoatEP8CVehicle, void, CVehicle* pVehicle);
    DECL_FASTCALL_SIMPLE(MakeWayForCarWithSiren, _ZN6CCarAI22MakeWayForCarWithSirenEP8CVehicle, void, CVehicle* pVehicle);

    // STATIC values
    DECL_OBJECT_SYM(const float, ms_fAchievePointRadius, _ZN6CCarAI22ms_fAchievePointRadiusE);
    DECL_OBJECT_SYM(const float, ms_fAccurateAchievePointRadius, _ZN6CCarAI30ms_fAccurateAchievePointRadiusE);
DECL_CLASS_END()
CHECKSIZE(CCarAI, 0x1, 0x1);

#endif // __AML_PSDK_SACARAI_H
