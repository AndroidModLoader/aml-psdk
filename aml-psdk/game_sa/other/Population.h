#ifndef __AML_PSDK_SAPOPULATION_H
#define __AML_PSDK_SAPOPULATION_H

/*
    Plugin-SDK (Grand Theft Auto San Andreas) header file
    Authors: GTA Community. See more here
    https://github.com/DK22Pac/plugin-sdk
    Do not delete this comment block. Respect others' work!
*/

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/gta_base/Vector.h>
#include <aml-psdk/game_sa/enum/PedEnums.h>
#include <aml-psdk/game_sa/other/LoadedCarGroup.h>

struct CPed;
struct CVehicle;
struct CObject;
struct CDummy;
struct CDummyObject;
struct C2dEffect;
struct CEntity;

enum eLevelName : u32
{
    LEVEL_GENERIC,
    LEVEL_LOSANGELES,
    LEVEL_SANFRANCISCO,
    LEVEL_LASVEGAS,
    MAX_LEVELS
};

DECL_CLASS(CPopulation)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(Initialise, _ZN11CPopulation10InitialiseEv, void);
    DECL_FASTCALL_SIMPLE(LoadPedGroups, _ZN11CPopulation13LoadPedGroupsEv, void);
    DECL_FASTCALL_SIMPLE(LoadCarGroups, _ZN11CPopulation13LoadCarGroupsEv, void);
    DECL_FASTCALL_SIMPLE(Shutdown, _ZN11CPopulation8ShutdownEv, void);
    DECL_FASTCALL_SIMPLE(Update, _ZN11CPopulation6UpdateEb, void, bool generatePeds);
    DECL_FASTCALL_SIMPLE(AddToPopulation, _ZN11CPopulation15AddToPopulationEffff, bool, float arg0, float arg1, float arg2, float arg3);
    DECL_FASTCALL_SIMPLE(AddPedInCar, _ZN11CPopulation11AddPedInCarEP8CVehiclebiibb, CPed*, CVehicle* vehicle, bool driver, i32 gangPedType, i32 seatNumber, bool male, bool criminal);
    DECL_FASTCALL_SIMPLE(AddExistingPedInCar, _ZN11CPopulation19AddExistingPedInCarEP4CPedP8CVehicle, CPed*, CPed* ped, CVehicle* vehicle);
    DECL_FASTCALL_SIMPLE(AddPed, _ZN11CPopulation6AddPedE8ePedTypejRK7CVectorb, CPed*, ePedType pedType, u32 modelIndex, CVector const& posn, bool makeWander);
    DECL_FASTCALL_SIMPLE(AddDeadPedInFrontOfCar, _ZN11CPopulation22AddDeadPedInFrontOfCarERK7CVectorP8CVehicle, CPed*, CVector const& posn, CVehicle* vehicle);
    DECL_FASTCALL_SIMPLE(RemovePed, _ZN11CPopulation9RemovePedEP4CPed, void, CPed* ped);
    DECL_FASTCALL_SIMPLE(GeneratePedsAtStartOfGame, _ZN11CPopulation25GeneratePedsAtStartOfGameEv, void);
    DECL_FASTCALL_SIMPLE(FindDummyDistForModel, _ZN11CPopulation21FindDummyDistForModelEi, float, i32 modelIndex);
    DECL_FASTCALL_SIMPLE(ManageObject, _ZN11CPopulation12ManageObjectEP7CObjectRK7CVector, void, CObject* object, CVector const& posn);
    DECL_FASTCALL_SIMPLE(ManageDummy, _ZN11CPopulation11ManageDummyEP6CDummyRK7CVector, void, CDummy* dummy, CVector const& posn);
    DECL_FASTCALL_SIMPLE(ManagePed, _ZN11CPopulation9ManagePedEP4CPedRK7CVector, void, CPed* ped, CVector const& playerPosn);
    DECL_FASTCALL_SIMPLE(ManageAllPopulation, _ZN11CPopulation19ManageAllPopulationEv, void);
    DECL_FASTCALL_SIMPLE(ManagePopulation, _ZN11CPopulation16ManagePopulationEv, void);
    DECL_FASTCALL_SIMPLE(FindNumberOfPedsWeCanPlaceOnBenches, _ZN11CPopulation35FindNumberOfPedsWeCanPlaceOnBenchesEv, i32);
    DECL_FASTCALL_SIMPLE(FindPedDensityMultiplierCullZone, _ZN11CPopulation32FindPedDensityMultiplierCullZoneEv, float);
    DECL_FASTCALL_SIMPLE(RemovePedsIfThePoolGetsFull, _ZN11CPopulation27RemovePedsIfThePoolGetsFullEv, void);
    DECL_FASTCALL_SIMPLE(ConvertAllObjectsToDummyObjects, _ZN11CPopulation31ConvertAllObjectsToDummyObjectsEv, void);
    DECL_FASTCALL_SIMPLE(RemoveAllRandomPeds, _ZN11CPopulation19RemoveAllRandomPedsEv, void);
    DECL_FASTCALL_SIMPLE(ConvertToRealObject, _ZN11CPopulation19ConvertToRealObjectEP12CDummyObject, void, CDummyObject* dummyObject);
    DECL_FASTCALL_SIMPLE(ConvertToDummyObject, _ZN11CPopulation20ConvertToDummyObjectEP7CObject, void, CObject* object);
    DECL_FASTCALL_SIMPLE(TestRoomForDummyObject, _ZN11CPopulation22TestRoomForDummyObjectEP7CObject, bool, CObject* object);
    DECL_FASTCALL_SIMPLE(TestSafeForRealObject, _ZN11CPopulation21TestSafeForRealObjectEP12CDummyObject, bool, CDummyObject* dummyObject);
    DECL_FASTCALL_SIMPLE(ChoosePolicePedOccupation, _ZN11CPopulation25ChoosePolicePedOccupationEv, i32);
    DECL_FASTCALL_SIMPLE(ArePedStatsCompatible, _ZN11CPopulation21ArePedStatsCompatibleEii, u8, i32 statType1, i32 statType2);
    DECL_FASTCALL_SIMPLE(PedMICanBeCreatedAtAttractor, _ZN11CPopulation28PedMICanBeCreatedAtAttractorEi, bool, i32 modelIndex);
    DECL_FASTCALL_SIMPLE(PedMICanBeCreatedAtThisAttractor, _ZN11CPopulation32PedMICanBeCreatedAtThisAttractorEiPc, bool, i32 modelIndex, char* attrName);
    DECL_FASTCALL_SIMPLE(PedMICanBeCreatedInInterior, _ZN11CPopulation27PedMICanBeCreatedInInteriorEi, bool, i32 modelIndex);
    DECL_FASTCALL_SIMPLE(ChooseCivilianOccupation, _ZN11CPopulation24ChooseCivilianOccupationEbbiiibbbPc, i32, bool male, bool female, i32 animType, i32 ignoreModelIndex, i32 statType, bool arg5, bool arg6, bool checkAttractor, char* attrName);
    DECL_FASTCALL_SIMPLE(ChooseCivilianOccupationForVehicle, _ZN11CPopulation34ChooseCivilianOccupationForVehicleEbP8CVehicle, i32, bool male, CVehicle* vehicle);
    DECL_FASTCALL_SIMPLE(ChooseGangOccupation, _ZN11CPopulation20ChooseGangOccupationEi, i32, i32 gangId);
    DECL_FASTCALL_SIMPLE(PlaceGangMembers, _ZN11CPopulation16PlaceGangMembersE8ePedTypeiRK7CVector, void, ePedType pedType, i32 numPeds, CVector const& posn);
    DECL_FASTCALL_SIMPLE(PlaceMallPedsAsStationaryGroup, _ZN11CPopulation30PlaceMallPedsAsStationaryGroupERK7CVectori, void, CVector const& posn, i32 numPeds);
    DECL_FASTCALL_SIMPLE(PlaceCouple, _ZN11CPopulation11PlaceCoupleE8ePedTypeiS0_i7CVector, void, ePedType pedType1, i32 modelIndex1, ePedType pedType2, i32 modelIndex2, CVector posn);
    DECL_FASTCALL_SIMPLE(ChooseCivilianCoupleOccupations, _ZN11CPopulation31ChooseCivilianCoupleOccupationsERiS0_, void, i32& model1, i32& model2);
    DECL_FASTCALL_SIMPLE(IsMale, _ZN11CPopulation6IsMaleEi, bool, i32 modelIndex);
    DECL_FASTCALL_SIMPLE(IsFemale, _ZN11CPopulation8IsFemaleEi, bool, i32 modelIndex);
    DECL_FASTCALL_SIMPLE(IsSecurityGuard, _ZN11CPopulation15IsSecurityGuardE8ePedType, bool, ePedType pedType);
    DECL_FASTCALL_SIMPLE(IsSkateable, _ZN11CPopulation11IsSkateableERK7CVector, bool, CVector const& point);
    DECL_FASTCALL_SIMPLE(CreateWaitingCoppers, _ZN11CPopulation20CreateWaitingCoppersE7CVectorf, void, CVector posn, float arg1);
    DECL_FASTCALL_SIMPLE(UpdatePedCount, _ZN11CPopulation14UpdatePedCountEP4CPedh, void, CPed* ped, u8 updateState);
    DECL_FASTCALL_SIMPLE(MoveCarsAndPedsOutOfAbandonedZones, _ZN11CPopulation34MoveCarsAndPedsOutOfAbandonedZonesEv, void);
    DECL_FASTCALL_SIMPLE(DealWithZoneChange, _ZN11CPopulation18DealWithZoneChangeE10eLevelNameS0_b, void, eLevelName oldZone, eLevelName newZone, bool bForce);
    DECL_FASTCALL_SIMPLE(PedCreationDistMultiplier, _ZN11CPopulation25PedCreationDistMultiplierEv, float);
    DECL_FASTCALL_SIMPLE(IsSunbather, _ZN11CPopulation11IsSunbatherEi, bool, i32 modelIndex);
    DECL_FASTCALL_SIMPLE(CanSolicitPlayerOnFoot, _ZN11CPopulation22CanSolicitPlayerOnFootEi, bool, i32 modelIndex);
    DECL_FASTCALL_SIMPLE(CanSolicitPlayerInCar, _ZN11CPopulation21CanSolicitPlayerInCarEi, bool, i32 modelIndex);
    DECL_FASTCALL_SIMPLE(CanJeerAtStripper, _ZN11CPopulation17CanJeerAtStripperEi, bool, i32 modelIndex);
    DECL_FASTCALL_SIMPLE(LoadSpecificDriverModelsForCar, _ZN11CPopulation30LoadSpecificDriverModelsForCarEi, void, i32 carModelIndex);
    DECL_FASTCALL_SIMPLE(FindSpecificDriverModelForCar_ToUse, _ZN11CPopulation35FindSpecificDriverModelForCar_ToUseEi, i32, i32 carModelIndex);
    DECL_FASTCALL_SIMPLE(RemoveSpecificDriverModelsForCar, _ZN11CPopulation32RemoveSpecificDriverModelsForCarEi, void, i32 carModelIndex);
    DECL_FASTCALL_SIMPLE(FindPedRaceFromName, _ZN11CPopulation19FindPedRaceFromNameEPc, i32, char* modelName);
    DECL_FASTCALL_SIMPLE(PopulateInterior, _ZN11CPopulation16PopulateInteriorEi7CVector, void, i32 numPeds, CVector posn);
    DECL_FASTCALL_SIMPLE(GeneratePedsAtAttractors, _ZN11CPopulation24GeneratePedsAtAttractorsE7CVectorffffii, i32, CVector posn, float arg1, float arg2, float arg3, float arg4, i32 decisionMakerType, i32 numPeds);
    DECL_FASTCALL_SIMPLE(AddPedAtAttractor, _ZN11CPopulation17AddPedAtAttractorEiP9C2dEffect7CVectorP7CEntityi, u8, i32 modelIndex, C2dEffect* attractor, CVector posn, CEntity* entity, i32 decisionMakerType);
    DECL_FASTCALL_SIMPLE(FindDistanceToNearestPedOfType, _ZN11CPopulation30FindDistanceToNearestPedOfTypeE8ePedType7CVector, float, ePedType pedType, CVector posn);
    DECL_FASTCALL_SIMPLE(IsCorrectTimeOfDayForEffect, _ZN11CPopulation27IsCorrectTimeOfDayForEffectEPK9C2dEffect, bool, C2dEffect const* effect);
    DECL_FASTCALL_SIMPLE(PickGangCar, _ZN11CPopulation11PickGangCarEi, i32, i32 gangId);
    DECL_FASTCALL_SIMPLE(PickRiotRoadBlockCar, _ZN11CPopulation20PickRiotRoadBlockCarEv, i32);
    DECL_FASTCALL_SIMPLE(FindCarMultiplierMotorway, _ZN11CPopulation25FindCarMultiplierMotorwayEv, float);
    DECL_FASTCALL_SIMPLE(FindPedMultiplierMotorway, _ZN11CPopulation25FindPedMultiplierMotorwayEv, float);

    // STATIC values
    typedef u16 tm_PedGroups_row[21];
    typedef u16 tm_CarGroups_row[23];
    typedef u32 tm_TranslationArray_row[3];

    DECL_VALUE_PLT_I32(ms_nNumCivMale, BYBIT(0x677D7C, 0x84DB18));
    DECL_VALUE_PLT_I32(ms_nNumCivFemale, BYBIT(0x675EFC, 0x849E68));
    DECL_VALUE_PLT_I32(ms_nNumCop, BYBIT(0x6783F4, 0x84E800));
    DECL_VALUE_PLT_I32(ms_nNumEmergency, BYBIT(0x6797D0, 0x850FA8));
    DECL_OBJECT_ARRAY_PLT(i32, ms_nNumGang, BYBIT(0x677B08, 0x84D638));
    DECL_VALUE_PLT_I32(ms_nNumDealers, BYBIT(0x6772DC, 0x84C5F0));
    DECL_VALUE_PLT_I32(ms_nTotalCarPassengerPeds, BYBIT(0x6767B4, 0x84AFC0));
    DECL_VALUE_PLT_I32(ms_nTotalCivPeds, BYBIT(0x676A60, 0x84B508));
    DECL_VALUE_PLT_I32(ms_nTotalGangPeds, BYBIT(0x6781B8, 0x84E388));
    DECL_VALUE_PLT_I32(ms_nTotalMissionPeds, BYBIT(0x676C50, 0x84B8E8));
    DECL_VALUE_PLT_I32(ms_nTotalPeds, BYBIT(0x677090, 0x84C158));
    DECL_VALUE_PLT_U8(m_CountDownToPedsAtStart, BYBIT(0x678EFC, 0x84FE20));
    DECL_VALUE_PLT_BOOL(m_bIsHospital, BYBIT(0x678640, 0x84ECA8));
    DECL_VALUE_PLT_BOOL(m_bDontCreateRandomGangMembers, BYBIT(0x679E4C, 0x851CA8));
    DECL_VALUE_PLT_BOOL(m_bOnlyCreateRandomGangMembers, BYBIT(0x6784A8, 0x84E968));
    DECL_VALUE_PLT_BOOL(m_bDontCreateRandomCops, BYBIT(0x679DE4, 0x851BE0));
    DECL_VALUE_PLT_BOOL(m_bMoreCarsAndFewerPeds, BYBIT(0x678EB8, 0x84FD98));
    DECL_OBJECT_ARRAY_PLT(tm_PedGroups_row, m_PedGroups, BYBIT(0x6773A4, 0x84C780));
    DECL_OBJECT_ARRAY_PLT(tm_CarGroups_row, m_CarGroups, BYBIT(0x677364, 0x84C700));
    DECL_OBJECT_ARRAY_PLT(i16, m_nNumPedsInGroup, BYBIT(0x676638, 0x84ACC8));
    DECL_OBJECT_ARRAY_PLT(i16, m_nNumCarsInGroup, BYBIT(0x676B0C, 0x84B660));
    DECL_OBJECT_ARRAY_PLT(tm_TranslationArray_row, m_TranslationArray, BYBIT(0x678990, 0x84F340));
    DECL_OBJECT_ARRAY_PLT(CLoadedCarGroup, m_LoadedGangCars, BYBIT(0x679808, 0x851018));
    DECL_OBJECT_PLT(CLoadedCarGroup, m_AppropriateLoadedCars, BYBIT(0x679BDC, 0x8517D8));
    DECL_OBJECT_PLT(CLoadedCarGroup, m_InAppropriateLoadedCars, BYBIT(0x679EA8, 0x851D60));
    DECL_OBJECT_PLT(CLoadedCarGroup, m_LoadedBoats, BYBIT(0x679EC0, 0x851D90));
    DECL_OBJECT_SYM(CVector, RegenerationPoint_a, _ZN11CPopulation19RegenerationPoint_aE);
    DECL_OBJECT_SYM(CVector, RegenerationPoint_b, _ZN11CPopulation19RegenerationPoint_bE);
    DECL_OBJECT_SYM(CVector, RegenerationFront, _ZN11CPopulation17RegenerationFrontE);
    DECL_VALUE_PLT_BOOL(bZoneChangeHasHappened, BYBIT(0x6764BC, 0x84A9D0));
    DECL_VALUE_PLT_FLT(PedDensityMultiplier, BYBIT(0x6776E4, 0x84CDF8));
    DECL_VALUE_PLT_I32(m_AllRandomPedsThisType, BYBIT(0x677100, 0x84C238));
    DECL_VALUE_PLT_I32(MaxNumberOfPedsInUse, BYBIT(0x679BF8, 0x851808));
    DECL_VALUE_PLT_I32(NumberOfPedsInUseInterior, BYBIT(0x6780D0, 0x84E1B8));
    DECL_VALUE_PLT_BOOL(bInPoliceStation, BYBIT(0x678CC0, 0x84F9A8));
    DECL_VALUE_PLT_I32(NumMiamiViceCops, BYBIT(0x676E04, 0x84BC50));
    DECL_VALUE_PLT_I32(CurrentWorldZone, BYBIT(0x6782DC, 0x84E5D0));
DECL_CLASS_END()
CHECKSIZE(CPopulation, 0x1, 0x1);

#define ms_nNumCivMale ms_nNumCivMale()
#define ms_nNumCivFemale ms_nNumCivFemale()
#define ms_nNumCop ms_nNumCop()
#define ms_nNumEmergency ms_nNumEmergency()
#define ms_nNumGang ms_nNumGang()
#define ms_nNumDealers ms_nNumDealers()
#define ms_nTotalCarPassengerPeds ms_nTotalCarPassengerPeds()
#define ms_nTotalCivPeds ms_nTotalCivPeds()
#define ms_nTotalGangPeds ms_nTotalGangPeds()
#define ms_nTotalMissionPeds ms_nTotalMissionPeds()
#define ms_nTotalPeds ms_nTotalPeds()
#define m_CountDownToPedsAtStart m_CountDownToPedsAtStart()
#define m_bIsHospital m_bIsHospital()
#define m_bDontCreateRandomGangMembers m_bDontCreateRandomGangMembers()
#define m_bOnlyCreateRandomGangMembers m_bOnlyCreateRandomGangMembers()
#define m_bDontCreateRandomCops m_bDontCreateRandomCops()
#define m_bMoreCarsAndFewerPeds m_bMoreCarsAndFewerPeds()
#define m_PedGroups m_PedGroups()
#define m_CarGroups m_CarGroups()
#define m_nNumPedsInGroup m_nNumPedsInGroup()
#define m_nNumCarsInGroup m_nNumCarsInGroup()
#define m_TranslationArray m_TranslationArray()
#define m_LoadedGangCars m_LoadedGangCars()
#define m_AppropriateLoadedCars m_AppropriateLoadedCars()
#define m_InAppropriateLoadedCars m_InAppropriateLoadedCars()
#define m_LoadedBoats m_LoadedBoats()
#define RegenerationPoint_a RegenerationPoint_a()
#define RegenerationPoint_b RegenerationPoint_b()
#define RegenerationFront RegenerationFront()
#define bZoneChangeHasHappened bZoneChangeHasHappened()
#define PedDensityMultiplier PedDensityMultiplier()
#define m_AllRandomPedsThisType m_AllRandomPedsThisType()
#define MaxNumberOfPedsInUse MaxNumberOfPedsInUse()
#define NumberOfPedsInUseInterior NumberOfPedsInUseInterior()
#define bInPoliceStation bInPoliceStation()
#define NumMiamiViceCops NumMiamiViceCops()
#define CurrentWorldZone CurrentWorldZone()

#endif // __AML_PSDK_SAPOPULATION_H
