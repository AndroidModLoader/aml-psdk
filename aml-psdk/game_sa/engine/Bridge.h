#ifndef __AML_PSDK_SABRIDGE_H
#define __AML_PSDK_SABRIDGE_H

#include <aml-psdk/game_sa/plugin.h>

struct CEntity;

DECL_CLASS(CBridge)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(Init, _ZN7CBridge4InitEv, void);
    DECL_FASTCALL_SIMPLE(Update, _ZN7CBridge6UpdateEv, void);
    DECL_FASTCALL_SIMPLE(ShouldLightsBeFlashing, _ZN7CBridge22ShouldLightsBeFlashingEv, bool);
    DECL_FASTCALL_SIMPLE(FindBridgeEntities, _ZN7CBridge18FindBridgeEntitiesEv, void);
    DECL_FASTCALL_SIMPLE(ThisIsABridgeObjectMovingUp, _ZN7CBridge27ThisIsABridgeObjectMovingUpEj, bool, u32 modelIndex);

    // STATIC values
    DECL_OBJECT_SYM(u32, TimeOfBridgeBecomingOperational, _ZN7CBridge31TimeOfBridgeBecomingOperationalE);
    DECL_OBJECT_SYM(i32, m_nBridgeState, _ZN7CBridge5StateE);
    DECL_OBJECT_SYM(i32, m_nOldBridgeState, _ZN7CBridge8OldStateE);
    DECL_OBJECT_SYM(float, OldLift, _ZN7CBridge7OldLiftE);
    DECL_OBJECT_SYM(CEntity*, pLiftPart, _ZN7CBridge9pLiftPartE);
    DECL_OBJECT_SYM(CEntity*, pLiftRoad, _ZN7CBridge9pLiftRoadE);
    DECL_OBJECT_SYM(CEntity*, pWeight, _ZN7CBridge7pWeightE);
    DECL_OBJECT_SYM(float, DefaultZLiftPart, _ZN7CBridge16DefaultZLiftPartE);
    DECL_OBJECT_SYM(float, DefaultZLiftRoad, _ZN7CBridge16DefaultZLiftRoadE);
    DECL_OBJECT_SYM(float, DefaultZLiftWeight, _ZN7CBridge18DefaultZLiftWeightE);
DECL_CLASS_END()

#define TimeOfBridgeBecomingOperational TimeOfBridgeBecomingOperational()
#define m_nBridgeState m_nBridgeState()
#define m_nOldBridgeState m_nOldBridgeState()
#define OldLift OldLift()
#define pLiftPart pLiftPart()
#define pLiftRoad pLiftRoad()
#define pWeight pWeight()
#define DefaultZLiftPart DefaultZLiftPart()
#define DefaultZLiftRoad DefaultZLiftRoad()
#define DefaultZLiftWeight DefaultZLiftWeight()

#endif // __AML_PSDK_SABRIDGE_H
