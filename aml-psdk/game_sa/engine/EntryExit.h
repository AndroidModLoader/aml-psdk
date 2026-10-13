#ifndef __AML_PSDK_SAENTRYEXIT_H
#define __AML_PSDK_SAENTRYEXIT_H

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/gta_base/Rect.h>
#include <aml-psdk/gta_base/Vector.h>

struct CEntity;
struct CPed;
struct CQuadTreeNode;
template<class A, class B> struct CPool;

DECL_CLASS(CEntryExit)
    char                               m_szName[8];
    CRect                              m_recEntrance;
    float                              m_fEntranceZ;
    float                              m_fEntranceAngle;
    CVector                            m_vecExitPos;
    float                              m_fExitAngle;
    u16                                m_nFlags;
    u8                                 m_nArea;
    u8                                 m_nSkyColor;
    u8                                 m_nTimeOn;
    u8                                 m_nTimeOff;
    i8                                 m_nNumberOfPeds;
    CEntryExit*                        m_pLink;

    // Functions
    DECL_THISCALL(IsInArea, _ZN10CEntryExit8IsInAreaERK7CVector, bool, CVector const& position);
    DECL_THISCALL(TransitionStarted, _ZN10CEntryExit17TransitionStartedEP4CPed, bool, CPed* player);
    DECL_THISCALL(TransitionFinished, _ZN10CEntryExit18TransitionFinishedEP4CPed, bool, CPed* player);
    DECL_THISCALL(WarpGangWithPlayer, _ZN10CEntryExit18WarpGangWithPlayerEP4CPed, void, CPed* player);
    DECL_THISCALL(FindValidTeleportPoint, _ZN10CEntryExit22FindValidTeleportPointER7CVector, void, CVector& position);
    DECL_THISCALL(GetPositionRelativeToOutsideWorld, _ZN10CEntryExit33GetPositionRelativeToOutsideWorldER7CVector, void, CVector& positionInOut);
    DECL_THISCALL_SIMPLE(RequestAmbientPeds, _ZN10CEntryExit18RequestAmbientPedsEv, void);
    DECL_THISCALL(GenerateAmbientPeds, _ZN10CEntryExit19GenerateAmbientPedsERK7CVector, void, CVector const& position);
    DECL_THISCALL(ProcessStealableObjects, _ZN10CEntryExit23ProcessStealableObjectsEP4CPed, void, CPed* player);
    DECL_THISCALL_SIMPLE(RequestObjectsInFrustum, _ZN10CEntryExit23RequestObjectsInFrustumEv, void);
    DECL_THISCALL_SIMPLE(GetEntryExitToDisplayNameOf, _ZN10CEntryExit27GetEntryExitToDisplayNameOfEv, CEntryExit*);

    // Static values
    DECL_OBJECT_PLT(CEntryExit*, ms_spawnPoint, BYBIT(0x677710, 0x84CE48));
    DECL_OBJECT_PLT(CEntity*, ms_pDoor, BYBIT(0x678B24, 0x84F670));
    DECL_VALUE_PLT_BOOL(ms_bWarping, BYBIT(0x676480, 0x84A950));
DECL_CLASS_END()
CHECKSIZE(CEntryExit, 0x3C, 0x40);

typedef CPool<CEntryExit, CEntryExit> CEntryExitPool;

DECL_CLASS(CEntryExitManager)
    // Functions
    DECL_FASTCALL_SIMPLE(Init, _ZN17CEntryExitManager4InitEv, void);
    DECL_FASTCALL_SIMPLE(Shutdown, _ZN17CEntryExitManager8ShutdownEv, void);
    DECL_FASTCALL_SIMPLE(ShutdownForRestart, _ZN17CEntryExitManager18ShutdownForRestartEv, void);
    DECL_FASTCALL_SIMPLE(Update, _ZN17CEntryExitManager6UpdateEv, void);
    DECL_FASTCALL_SIMPLE(AddOne, _ZN17CEntryExitManager6AddOneEfffffffffffiiiiiiPKc, i32, float entranceX, float entranceY, float entranceZ, float entranceAngle, float entranceRangeX, float entranceRangeY, float entranceRangeZ, float exitX, float exitY, float exitZ, float exitAngle, i32 area, i32 flags, i32 skyColor, i32 timeOn, i32 timeOff, i32 numberOfPeds, char const* name);
    DECL_FASTCALL_SIMPLE(DeleteOne, _ZN17CEntryExitManager9DeleteOneEi, void, i32 index);
    DECL_FASTCALL_SIMPLE(EnableBurglaryHouses, _ZN17CEntryExitManager20EnableBurglaryHousesEb, void, bool enable);
    DECL_FASTCALL_SIMPLE(FindNearestDoor, _ZN17CEntryExitManager15FindNearestDoorERK10CEntryExitf, CEntity*, CEntryExit const& entryExit, float range);
    DECL_FASTCALL_SIMPLE(FindNearestEntryExit, _ZN17CEntryExitManager20FindNearestEntryExitERK9CVector2Dfi, i32, CVector2D const& position, float range, i32 ignoreArea);
    DECL_FASTCALL_SIMPLE(GetEntryExitIndex, _ZN17CEntryExitManager17GetEntryExitIndexEPKctt, i32, char const* name, u16 enabledFlags, u16 disabledFlags);
    DECL_FASTCALL_SIMPLE(GetPositionRelativeToOutsideWorld, _ZN17CEntryExitManager33GetPositionRelativeToOutsideWorldER7CVector, void, CVector& positionInOut);
    DECL_FASTCALL_SIMPLE(GotoEntryExit, _ZN17CEntryExitManager13GotoEntryExitEP10CEntryExit, void, CEntryExit* entryExit);
    DECL_FASTCALL_SIMPLE(GotoEntryExitVC, _ZN17CEntryExitManager15GotoEntryExitVCEPKc, void, char const* name);
    DECL_FASTCALL_SIMPLE(GotoNextEntryExit, _ZN17CEntryExitManager17GotoNextEntryExitEv, void);
    DECL_FASTCALL_SIMPLE(GotoPreviousEntryExit, _ZN17CEntryExitManager21GotoPreviousEntryExitEv, void);
    DECL_FASTCALL_SIMPLE(LinkEntryExit, _ZN17CEntryExitManager13LinkEntryExitEP10CEntryExit, void, CEntryExit* entryExit);
    DECL_FASTCALL_SIMPLE(PostEntryExitsCreation, _ZN17CEntryExitManager22PostEntryExitsCreationEv, void);
    DECL_FASTCALL_SIMPLE(ResetAreaCodeForVisibleObjects, _ZN17CEntryExitManager30ResetAreaCodeForVisibleObjectsEv, void);
    DECL_FASTCALL_SIMPLE(SetAreaCodeForVisibleObjects, _ZN17CEntryExitManager28SetAreaCodeForVisibleObjectsEv, void);
    DECL_FASTCALL_SIMPLE(SetEnabled, _ZN17CEntryExitManager10SetEnabledEib, void, i32 index, bool enable);
    DECL_FASTCALL_SIMPLE(SetEnabledByName, _ZN17CEntryExitManager16SetEnabledByNameEPKcb, void, char const* name, bool enable);
    DECL_FASTCALL_SIMPLE(SetEntryExitFlag, _ZN17CEntryExitManager16SetEntryExitFlagEPKcjb, void, char const* name, u32 flag, bool enable);
    DECL_FASTCALL_SIMPLE(SetEntryExitFlagWithIndex, _ZN17CEntryExitManager25SetEntryExitFlagWithIndexEijb, void, i32 index, u32 flag, bool enable);
    DECL_FASTCALL_SIMPLE(AddEntryExitToStack, _ZN17CEntryExitManager19AddEntryExitToStackEP10CEntryExit, void, CEntryExit* entryExit);
    DECL_FASTCALL_SIMPLE(WeAreInInteriorTransition, _ZN17CEntryExitManager25WeAreInInteriorTransitionEv, bool);
    DECL_FASTCALL_SIMPLE(Save, _ZN17CEntryExitManager4SaveEv, bool);
    DECL_FASTCALL_SIMPLE(Load, _ZN17CEntryExitManager4LoadEv, bool);

    // Static values
    DECL_OBJECT_PLT(CQuadTreeNode*, mp_QuadTree, BYBIT(0x677810, 0x84D048));
    DECL_OBJECT_PLT(CEntryExitPool*, mp_poolEntryExits, BYBIT(0x677FEC, 0x84DFF8));
    DECL_OBJECT_PLT(CEntryExit*, mp_Active, BYBIT(0x6787C4, 0x84EFB0));
    DECL_OBJECT_ARRAY_PLT(CEntryExit*, ms_entryExitStack, BYBIT(0x676804, 0x84B060));
    DECL_VALUE_PLT_I32(ms_entryExitStackPosn, BYBIT(0x6794E4, 0x8509E0));
    DECL_OBJECT_ARRAY_PLT(CEntity*, ms_visibleEntityList, BYBIT(0x678244, 0x84E4A0));
    DECL_VALUE_PLT_I32(ms_numVisibleEntities, BYBIT(0x677FF0, 0x84E000));
    DECL_VALUE_PLT_I32(ms_oldAreaCode, BYBIT(0x679EA4, 0x851D58));
    DECL_VALUE_PLT_I32(ms_exitEnterState, BYBIT(0x678618, 0x84EC50));
    DECL_VALUE_PLT_BOOL(ms_bDisabled, BYBIT(0x676D18, 0x84BA78));
    DECL_VALUE_PLT_BOOL(ms_bBurglaryHousesEnabled, BYBIT(0x67933C, 0x850690));
DECL_CLASS_END()

#define ms_spawnPoint ms_spawnPoint()
#define ms_pDoor ms_pDoor()
#define ms_bWarping ms_bWarping()
#define mp_QuadTree mp_QuadTree()
#define mp_poolEntryExits mp_poolEntryExits()
#define mp_Active mp_Active()
#define ms_entryExitStack ms_entryExitStack()
#define ms_entryExitStackPosn ms_entryExitStackPosn()
#define ms_visibleEntityList ms_visibleEntityList()
#define ms_numVisibleEntities ms_numVisibleEntities()
#define ms_oldAreaCode ms_oldAreaCode()
#define ms_exitEnterState ms_exitEnterState()
#define ms_bDisabled ms_bDisabled()
#define ms_bBurglaryHousesEnabled ms_bBurglaryHousesEnabled()

#endif // __AML_PSDK_SAENTRYEXIT_H
