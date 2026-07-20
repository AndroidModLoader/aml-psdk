#ifndef __AML_PSDK_SAGARAGES_H
#define __AML_PSDK_SAGARAGES_H

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/game_sa/audio/AEDoorAudioEntity.h>
#include <aml-psdk/gta_base/Vector.h>

struct CGarageFlags
{
    u8                                 bClosingEmpty : 1;
    u8                                 bDeActivated : 1;
    u8                                 bResprayHappened : 1;
    u8                                 bRotatyDoor : 1;
    u8                                 bInvertRotation : 1;
    u8                                 bLeaveCameraAlone : 1;
    u8                                 bShouldDoorsHaveCollision : 1;
    u8                                 bFreeResprays : 1;
};
CHECKSIZE(CGarageFlags, 0x1, 0x1);  // 64-bit from the IDB; 32-bit measured from this layout

struct CStoredCar
{
    float                              CoorX;
    float                              CoorY;
    float                              CoorZ;
    u32                                FlagsLocal;
    u16                                Bits;
    u16                                ModelIndex;
    i16                                CarMods[15];
    u8                                 Colour1;
    u8                                 Colour2;
    u8                                 Colour3;
    u8                                 Colour4;
    u8                                 RadioStation;
    i8                                 Comp1;
    i8                                 Comp2;
    i8                                 BombOnBoard;
    i8                                 PaintJob;
    i8                                 m_nNitroBoosts;
    i8                                 iFrontX;
    i8                                 iFrontY;
    i8                                 iFrontZ;
};
CHECKSIZE(CStoredCar, 0x40, 0x40);  // 64-bit from the IDB; 32-bit measured from this layout

struct CAEDoorAudioEntity;
struct CAutomobile;
struct CEntity;
struct CObject;
struct CPed;
struct CVector;
struct CVehicle;

DECL_CLASS(CGarage, __attribute__((packed, aligned(4))))
    // Member values
    float                              BaseX;
    float                              BaseY;
    float                              BaseZ;
    float                              Delta1X;
    float                              Delta1Y;
    float                              Delta2X;
    float                              Delta2Y;
    float                              CeilingZ;
    float                              Delta1Length;
    float                              Delta2Length;
    float                              MinX;
    float                              MaxX;
    float                              MinY;
    float                              MaxY;
    float                              Openness;
    u32                                TimeOfNextEvent;
    CAutomobile*                       pCarToCollect;
    char                               Name[8];
    u8                                 Type;
    u8                                 State;
    CGarageFlags                       Flags;
    u8                                 OriginalType;
    CAEDoorAudioEntity                 m_DoorAudioEntity;

    // Functions
    DECL_THISCALL_SIMPLE(InitDoorsAtStart, _ZN7CGarage16InitDoorsAtStartEv, void);
    DECL_THISCALL_HEAD(Update, _ZN7CGarage6UpdateEi, void, i32 MyIndex)
    DECL_THISCALL_TAIL(Update, MyIndex)
    DECL_THISCALL_SIMPLE(TidyUpGarage, _ZN7CGarage12TidyUpGarageEv, void);
    DECL_THISCALL_SIMPLE(TidyUpGarageClose, _ZN7CGarage17TidyUpGarageCloseEv, void);
    DECL_THISCALL_SIMPLE(SlideDoorOpen, _ZN7CGarage13SlideDoorOpenEv, bool);
    DECL_THISCALL_HEAD(FindDoorsWithGarage, _ZN7CGarage19FindDoorsWithGarageEPP7CObjectS2_, void, CObject** ppDoor1, CObject** ppDoor2)
    DECL_THISCALL_TAIL(FindDoorsWithGarage, ppDoor1, ppDoor2)
    DECL_THISCALL_SIMPLE(SlideDoorClosed, _ZN7CGarage15SlideDoorClosedEv, bool);
    DECL_THISCALL_HEAD(IsEntityEntirelyInside3D, _ZN7CGarage24IsEntityEntirelyInside3DEP7CEntityf, bool, CEntity* pEntity, float Margin)
    DECL_THISCALL_TAIL(IsEntityEntirelyInside3D, pEntity, Margin)
    DECL_THISCALL_HEAD(IsEntityEntirelyOutside, _ZN7CGarage23IsEntityEntirelyOutsideEP7CEntityf, bool, CEntity* pEntity, float Margin)
    DECL_THISCALL_TAIL(IsEntityEntirelyOutside, pEntity, Margin)
    DECL_THISCALL_SIMPLE(IsStaticPlayerCarEntirelyInside, _ZN7CGarage31IsStaticPlayerCarEntirelyInsideEv, bool);
    DECL_THISCALL_HEAD(IsPlayerOutsideGarage, _ZN7CGarage21IsPlayerOutsideGarageEf, bool, float Margin)
    DECL_THISCALL_TAIL(IsPlayerOutsideGarage, Margin)
    DECL_THISCALL_HEAD(CalcDistToGarageRectangleSquared, _ZN7CGarage32CalcDistToGarageRectangleSquaredEff, float, float X, float Y)
    DECL_THISCALL_TAIL(CalcDistToGarageRectangleSquared, X, Y)
    DECL_THISCALL_HEAD(ThrowCarsNearDoorOutOfGarage, _ZN7CGarage28ThrowCarsNearDoorOutOfGarageEP8CVehicle, void, CVehicle* pException)
    DECL_THISCALL_TAIL(ThrowCarsNearDoorOutOfGarage, pException)
    DECL_THISCALL_HEAD(IsEntityTouching3D, _ZN7CGarage18IsEntityTouching3DEP7CEntity, bool, CEntity* pEntity)
    DECL_THISCALL_TAIL(IsEntityTouching3D, pEntity)
    DECL_THISCALL_SIMPLE(IsGarageEmpty, _ZN7CGarage13IsGarageEmptyEv, bool);
    DECL_THISCALL_SIMPLE(IsAnyCarBlockingDoor, _ZN7CGarage20IsAnyCarBlockingDoorEv, bool);
    DECL_THISCALL_HEAD(CountCarsWithCenterPointWithinGarage, _ZN7CGarage36CountCarsWithCenterPointWithinGarageEP7CEntity, i32, CEntity* pException)
    DECL_THISCALL_TAIL(CountCarsWithCenterPointWithinGarage, pException)
    DECL_THISCALL_SIMPLE(FindMaxNumStoredCarsForGarage, _ZN7CGarage29FindMaxNumStoredCarsForGarageEv, i32);
    DECL_THISCALL_SIMPLE(RemoveCarsBlockingDoorNotInside, _ZN7CGarage31RemoveCarsBlockingDoorNotInsideEv, void);
    DECL_THISCALL_HEAD(StoreAndRemoveCarsForThisHideOut, _ZN7CGarage32StoreAndRemoveCarsForThisHideOutEP10CStoredCari, void, CStoredCar* aStoredCars, i32 MaxNumStored)
    DECL_THISCALL_TAIL(StoreAndRemoveCarsForThisHideOut, aStoredCars, MaxNumStored)
    DECL_THISCALL_HEAD(RestoreCarsForThisHideOut, _ZN7CGarage25RestoreCarsForThisHideOutEP10CStoredCar, bool, CStoredCar* aStoredCars)
    DECL_THISCALL_TAIL(RestoreCarsForThisHideOut, aStoredCars)
    DECL_THISCALL_HEAD(StoreAndRemoveCarsForThisImpoundingGarage, _ZN7CGarage41StoreAndRemoveCarsForThisImpoundingGarageEP10CStoredCari, void, CStoredCar* aStoredCars, i32 MaxNumStored)
    DECL_THISCALL_TAIL(StoreAndRemoveCarsForThisImpoundingGarage, aStoredCars, MaxNumStored)
    DECL_THISCALL_HEAD(NeatlyLineUpStoredCars, _ZN7CGarage22NeatlyLineUpStoredCarsEP10CStoredCar, void, CStoredCar* aStoredCars)
    DECL_THISCALL_TAIL(NeatlyLineUpStoredCars, aStoredCars)
    DECL_THISCALL_HEAD(RestoreCarsForThisImpoundingGarage, _ZN7CGarage34RestoreCarsForThisImpoundingGarageEP10CStoredCar, bool, CStoredCar* aStoredCars)
    DECL_THISCALL_TAIL(RestoreCarsForThisImpoundingGarage, aStoredCars)
    DECL_THISCALL_HEAD(RightModTypeForThisGarage, _ZN7CGarage25RightModTypeForThisGarageEP8CVehicle, bool, CVehicle* pVeh)
    DECL_THISCALL_TAIL(RightModTypeForThisGarage, pVeh)
    DECL_THISCALL_HEAD(IsAnyOtherCarTouchingGarage, _ZN7CGarage27IsAnyOtherCarTouchingGarageEP8CVehicle, bool, CVehicle* pException)
    DECL_THISCALL_TAIL(IsAnyOtherCarTouchingGarage, pException)
    DECL_THISCALL_HEAD(IsPointInsideGarage, _ZN7CGarage19IsPointInsideGarageE7CVectorf, bool, CVector Point, float Margin)
    DECL_THISCALL_TAIL(IsPointInsideGarage, Point, Margin)
    DECL_THISCALL_SIMPLE(IsPlayerEntirelyInsideGarage, _ZN7CGarage28IsPlayerEntirelyInsideGarageEv, bool);
    DECL_THISCALL_HEAD(EntityHasASphereWayOutsideGarage, _ZN7CGarage32EntityHasASphereWayOutsideGarageEP7CEntityf, bool, CEntity* pEntity, float Margin)
    DECL_THISCALL_TAIL(EntityHasASphereWayOutsideGarage, pEntity, Margin)
    DECL_THISCALL_HEAD(IsAnyOtherPedTouchingGarage, _ZN7CGarage27IsAnyOtherPedTouchingGarageEP4CPed, bool, CPed* pException)
    DECL_THISCALL_TAIL(IsAnyOtherPedTouchingGarage, pException)
    DECL_THISCALL_HEAD(IsPointInsideGarage1, _ZN7CGarage19IsPointInsideGarageE7CVector, bool, CVector Point)
    DECL_THISCALL_TAIL(IsPointInsideGarage1, Point)
    DECL_FASTCALL_SIMPLE(BuildRotatedDoorMatrix, _ZN7CGarage22BuildRotatedDoorMatrixEP7CEntityf, void, CEntity* pDoor, float RotationAmount);
    DECL_THISCALL_SIMPLE(OpenThisGarage, _ZN7CGarage14OpenThisGarageEv, void);
    DECL_THISCALL_SIMPLE(CloseThisGarage, _ZN7CGarage15CloseThisGarageEv, void);
    DECL_THISCALL_SIMPLE(PlayerArrestedOrDied, _ZN7CGarage20PlayerArrestedOrDiedEv, void);
    DECL_THISCALL_HEAD(CenterCarInGarage, _ZN7CGarage17CenterCarInGarageEP8CVehicle, void, CVehicle* pVehicle)
    DECL_THISCALL_TAIL(CenterCarInGarage, pVehicle)

DECL_CLASS_END()
CHECKSIZE(CGarage, 0xD8, 0xF4);  // 64-bit from the IDB; 32-bit measured from this layout

DECL_CLASS(CGarages)
    // Functions
    DECL_FASTCALL_SIMPLE(Init, _ZN8CGarages4InitEv, void);
    DECL_FASTCALL_SIMPLE(Shutdown, _ZN8CGarages8ShutdownEv, void);
    DECL_FASTCALL_SIMPLE(Init_AfterRestart, _ZN8CGarages17Init_AfterRestartEv, void);
    DECL_FASTCALL_SIMPLE(Update, _ZN8CGarages6UpdateEv, void);
    DECL_FASTCALL_SIMPLE(AddOne, _ZN8CGarages6AddOneEffffffffhjPcj, i16, float BaseX, float BaseY, float BaseZ, float Point1X, float Point1Y, float Point2X, float Point2Y, float CeilingZ, u8 Type, u32 ModelIndexToBeCollected, char* pName, u32 FlagsFromMax);
    DECL_FASTCALL_SIMPLE(FindGarageIndex, _ZN8CGarages15FindGarageIndexEPc, i16, char* pName);
    DECL_FASTCALL_SIMPLE(ChangeGarageType, _ZN8CGarages16ChangeGarageTypeEshj, void, i16 NumGarage, u8 NewType, u32 ModelIndexToBeCollected);
    DECL_FASTCALL_SIMPLE(IsCarSprayable, _ZN8CGarages14IsCarSprayableEP8CVehicle, bool, CVehicle* pCar);
    DECL_FASTCALL_SIMPLE(TriggerMessage, _ZN8CGarages14TriggerMessageEPcsts, void, char* pMessageID, i16 NumberInString, u16 Duration, i16 NumberInString2);
    DECL_FASTCALL_SIMPLE(GivePlayerDetonator, _ZN8CGarages19GivePlayerDetonatorEv, void);
    DECL_FASTCALL_SIMPLE(FindSafeHouseIndexForGarageType, _ZN8CGarages31FindSafeHouseIndexForGarageTypeEi, i32, i32 GarageType);
    DECL_FASTCALL_SIMPLE(CountCarsInHideoutGarage, _ZN8CGarages24CountCarsInHideoutGarageEh, i32, u8 Type);
    DECL_FASTCALL_SIMPLE(PrintMessages, _ZN8CGarages13PrintMessagesEv, void);
    DECL_FASTCALL_SIMPLE(SetTargetCarForMissionGarage, _ZN8CGarages28SetTargetCarForMissionGarageEsP11CAutomobile, void, i16 NumGarage, CAutomobile* pCar);
    DECL_FASTCALL_SIMPLE(HasCarBeenDroppedOffYet, _ZN8CGarages23HasCarBeenDroppedOffYetEs, bool, i16 NumGarage);
    DECL_FASTCALL_SIMPLE(DeActivateGarage, _ZN8CGarages16DeActivateGarageEs, void, i16 NumGarage);
    DECL_FASTCALL_SIMPLE(ActivateGarage, _ZN8CGarages14ActivateGarageEs, void, i16 NumGarage);
    DECL_FASTCALL_SIMPLE(IsGarageOpen, _ZN8CGarages12IsGarageOpenEs, bool, i16 NumGarage);
    DECL_FASTCALL_SIMPLE(IsGarageClosed, _ZN8CGarages14IsGarageClosedEs, bool, i16 NumGarage);
    DECL_FASTCALL_SIMPLE(HasResprayHappened, _ZN8CGarages18HasResprayHappenedEs, bool, i16 NumGarage);
    DECL_FASTCALL_SIMPLE(IsThisCarWithinGarageArea, _ZN8CGarages25IsThisCarWithinGarageAreaEsP7CEntity, bool, i16 NumGarage, CEntity* pEntity);
    DECL_FASTCALL_SIMPLE(IsPointInAGarageCameraZone, _ZN8CGarages26IsPointInAGarageCameraZoneE7CVector, bool, CVector Coors);
    DECL_FASTCALL_SIMPLE(CameraShouldBeOutside, _ZN8CGarages21CameraShouldBeOutsideEv, bool);
    DECL_FASTCALL_SIMPLE(FindDoorHeightForMI, _ZN8CGarages19FindDoorHeightForMIEj, float, u32 MI);
    DECL_FASTCALL_SIMPLE(PlayerArrestedOrDied, _ZN8CGarages20PlayerArrestedOrDiedEv, void);
    DECL_FASTCALL_SIMPLE(CloseHideOutGaragesBeforeSave, _ZN8CGarages29CloseHideOutGaragesBeforeSaveEv, void);
    DECL_FASTCALL_SIMPLE(StopCarFromBlowingUp, _ZN8CGarages20StopCarFromBlowingUpEP11CAutomobile, void, CAutomobile* pCar);
    DECL_FASTCALL_SIMPLE(IsPointWithinHideOutGarage, _ZN8CGarages26IsPointWithinHideOutGarageER7CVector, bool, CVector* Point);
    DECL_FASTCALL_SIMPLE(IsPointWithinAnyGarage, _ZN8CGarages22IsPointWithinAnyGarageER7CVector, bool, CVector* Point);
    DECL_FASTCALL_SIMPLE(FindGarageForObject, _ZN8CGarages19FindGarageForObjectEP7CObject, i32, CObject* pObject);
    DECL_FASTCALL_SIMPLE(StoreCarInNearestImpoundingGarage, _ZN8CGarages33StoreCarInNearestImpoundingGarageEP8CVehicle, void, CVehicle* pVeh);
    DECL_FASTCALL_SIMPLE(IsModelIndexADoor, _ZN8CGarages17IsModelIndexADoorEi, bool, i32 MI);
    DECL_FASTCALL_SIMPLE(AllRespraysCloseOrOpen, _ZN8CGarages22AllRespraysCloseOrOpenEb, void, bool bOpen);
    DECL_FASTCALL_SIMPLE(Save, _ZN8CGarages4SaveEv, bool);
    DECL_FASTCALL_SIMPLE(Load, _ZN8CGarages4LoadEv, bool);

    // Static values
    DECL_OBJECT_ARRAY_PLT(CGarage, aGarages, BYBIT(0x678A40, 0x84F4A0));
    DECL_VALUE_PLT_U32(NumGarages, BYBIT(0x6776FC, 0x84CE20));
    DECL_VALUE_PLT_U32(MessageStartTime, BYBIT(0x678D30, 0x84FA88));
    DECL_VALUE_PLT_U32(MessageEndTime, BYBIT(0x679CA4, 0x851960));
    DECL_OBJECT_ARRAY_PLT(char, MessageIDString, BYBIT(0x6791E4, 0x8503E8));
    DECL_VALUE_PLT_I32(MessageNumberInString, BYBIT(0x67865C, 0x84ECE0));
    DECL_VALUE_PLT_I32(MessageNumberInString2, BYBIT(0x6777E0, 0x84CFE8));
    DECL_VALUE_PLT_BOOL(PlayerInGarage, BYBIT(0x676680, 0x84AD58));
    DECL_VALUE_PLT_BOOL(BombsAreFree, BYBIT(0x677C7C, 0x84D918));
    DECL_VALUE_PLT_BOOL(RespraysAreFree, BYBIT(0x676750, 0x84AEF8));
    DECL_VALUE_PLT_BOOL(NoResprays, BYBIT(0x6771BC, 0x84C3A8));
    DECL_VALUE_PLT_I32(CarsCollected, BYBIT(0x676540, 0x84AAD8));
    DECL_VALUE_PLT_I32(BankVansCollected, BYBIT(0x67674C, 0x84AEF0));
    DECL_VALUE_PLT_I32(PoliceCarsCollected, BYBIT(0x678FB8, 0x84FF98));
    DECL_OBJECT_ARRAY_PLT(u32, CarTypesCollected, BYBIT(0x679C48, 0x8518A8));
    DECL_VALUE_PLT_I32(CrushedCarId, BYBIT(0x676F88, 0x84BF50));
    DECL_VALUE_PLT_BOOL(bCamShouldBeOutside, BYBIT(0x67641C, 0x84A890));
    DECL_VALUE_PLT_U32(LastTimeHelpMessage, BYBIT(0x679AC8, 0x8515B0));
    DECL_VALUE_PLT_I32(LastGaragePlayerWasIn, BYBIT(0x676F1C, 0x84BE78));
    DECL_VALUE_ADDR_BOOL(bDebugDisplayGarages, BYBIT(0x7A4DE0, 0x9855AC));  // no .got slot: addressed PC-relatively
    typedef CStoredCar taCarsInSafeHouse_row[4];
    DECL_OBJECT_ARRAY_PLT(taCarsInSafeHouse_row, aCarsInSafeHouse, BYBIT(0x676020, 0x84A0B0));
DECL_CLASS_END()

#define aGarages aGarages()
#define NumGarages NumGarages()
#define MessageStartTime MessageStartTime()
#define MessageEndTime MessageEndTime()
#define MessageIDString MessageIDString()
#define MessageNumberInString MessageNumberInString()
#define MessageNumberInString2 MessageNumberInString2()
#define PlayerInGarage PlayerInGarage()
#define BombsAreFree BombsAreFree()
#define RespraysAreFree RespraysAreFree()
#define NoResprays NoResprays()
#define CarsCollected CarsCollected()
#define BankVansCollected BankVansCollected()
#define PoliceCarsCollected PoliceCarsCollected()
#define CarTypesCollected CarTypesCollected()
#define CrushedCarId CrushedCarId()
#define bCamShouldBeOutside bCamShouldBeOutside()
#define LastTimeHelpMessage LastTimeHelpMessage()
#define LastGaragePlayerWasIn LastGaragePlayerWasIn()
#define bDebugDisplayGarages bDebugDisplayGarages()
#define aCarsInSafeHouse aCarsInSafeHouse()

#endif // __AML_PSDK_SAGARAGES_H
