#ifndef __AML_PSDK_VCAUTOPILOT_H
#define __AML_PSDK_VCAUTOPILOT_H

#include <aml-psdk/game_vc/base/Timer.h>
#include <aml-psdk/gta_base/Vector.h>

struct CPathNode;
struct CVehicle;

enum eCarDrivingStyle : u8
{
    DRIVINGSTYLE_STOP_FOR_CARS = 0,
    DRIVINGSTYLE_SLOW_DOWN_FOR_CARS = 1,
    DRIVINGSTYLE_AVOID_CARS = 2,
    DRIVINGSTYLE_PLOUGH_THROUGH = 3,
    DRIVINGSTYLE_STOP_FOR_CARS_IGNORE_LIGHTS = 4
};

enum eCarTempAction : u8
{
    TEMPACT_NONE = 0,
    TEMPACT_WAIT = 1,
    TEMPACT_REVERSE = 2,
    TEMPACT_HANDBRAKETURNLEFT = 3,
    TEMPACT_HANDBRAKETURNRIGHT = 4,
    TEMPACT_HANDBRAKESTRAIGHT = 5,
    TEMPACT_TURNLEFT = 6,
    TEMPACT_TURNRIGHT = 7,
    TEMPACT_GOFORWARD = 8,
    TEMPACT_SWERVELEFT = 9,
    TEMPACT_SWERVERIGHT = 10
};

DECL_CLASS(CAutoPilot)
    CAutoPilot() : m_nCurrentRouteNode(0), m_nNextRouteNode(0), m_nPrevRouteNode(0),
        m_nTimeEnteredCurve(0), m_nTimeToSpendOnCurrentCurve(1000), m_nCurrentPathNodeInfo(0),
        m_nNextPathNodeInfo(0), m_nPreviousPathNodeInfo(0), m_nAntiReverseTimer(CTimer::GetTimeInMS()),
        m_nTimeToStartMission(m_nAntiReverseTimer), m_nPreviousDirection(0), m_nCurrentDirection(1),
        m_nNextDirection(1), m_nCurrentLane(0), m_nNextLane(0), m_nDrivingStyle(DRIVINGSTYLE_STOP_FOR_CARS),
        m_nCarMission(0), m_nTempAction(TEMPACT_NONE), m_nTimeTempAction(0), m_fMaxTrafficSpeed(10.0f),
        m_nCruiseSpeed(10), m_nCruiseSpeedMultiplierType(0), m_fCruiseSpeedMultiplier(1.0f),
        m_bSlowedDownBecauseOfCars(false), m_bSlowedDownBecauseOfPeds(false), m_bStayInCurrentLevel(false),
        m_bStayInFastLane(false), m_bIgnorePathfinding(false), m_nSwitchDistance(20),
        m_aPathFindNodesInfo{}, m_nPathFindNodesCount(0), m_pTargetCar(nullptr) {}

    // Member functions
    DECL_THISCALL_HEAD(ModifySpeed, _ZN10CAutoPilot11ModifySpeedEf, void, float speed)
    DECL_THISCALL_TAIL(ModifySpeed, speed)
    DECL_THISCALL_SIMPLE(RemoveOnePathNode, _ZN10CAutoPilot17RemoveOnePathNodeEv, void);

    inline float GetCruiseSpeed() const { return m_nCruiseSpeed * m_fCruiseSpeedMultiplier; }

    // Member values
    i32 m_nCurrentRouteNode;
    i32 m_nNextRouteNode;
    i32 m_nPrevRouteNode;
    u32 m_nTimeEnteredCurve;
    i32 m_nTimeToSpendOnCurrentCurve;
    i32 m_nCurrentPathNodeInfo;
    i32 m_nNextPathNodeInfo;
    i32 m_nPreviousPathNodeInfo;
    u32 m_nAntiReverseTimer;
    u32 m_nTimeToStartMission;
    i8 m_nPreviousDirection;
    i8 m_nCurrentDirection;
    i8 m_nNextDirection;
    i8 m_nCurrentLane;
    i8 m_nNextLane;
    eCarDrivingStyle m_nDrivingStyle;
    u8 m_nCarMission;
    eCarTempAction m_nTempAction;
    u32 m_nTimeTempAction;
    float m_fMaxTrafficSpeed;
    u8 m_nCruiseSpeed;
    u8 m_nCruiseSpeedMultiplierType;
    float m_fCruiseSpeedMultiplier;
    u8 m_bSlowedDownBecauseOfCars : 1;
    u8 m_bSlowedDownBecauseOfPeds : 1;
    u8 m_bStayInCurrentLevel : 1;
    u8 m_bStayInFastLane : 1;
    u8 m_bIgnorePathfinding : 1;
    u8 : 3;
    u8 m_nSwitchDistance;
    CVector m_vecDestinationCoors;
    CPathNode* m_aPathFindNodesInfo[8];
    i16 m_nPathFindNodesCount;
    CVehicle* m_pTargetCar;
DECL_CLASS_END()
CHECKSIZE(CAutoPilot, 0x78, 0xA0);

#endif // __AML_PSDK_VCAUTOPILOT_H
