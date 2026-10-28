#ifndef __AML_PSDK_VCPHYSICAL_H
#define __AML_PSDK_VCPHYSICAL_H

#include "Entity.h"
#include "../base/Lists.h"
#include "../base/ColModel.h"

DECL_CLASS_BASED(CPhysical, CEntity)
    // Construct/Deconstruct functions
    DECL_CTORCALL(CPhysical, _ZN9CPhysicalC2Ev);
    DECL_DTORCALL_VIRTUAL_SLOT(CPhysical, _ZN9CPhysicalD2Ev, _ZN9CPhysical, _ZTV9CPhysical, 2);
    CPhysical(CPhysical const&) = delete;
    CPhysical& operator=(CPhysical const&) = delete;

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(CPhysical, Add, _ZTV9CPhysical, 0, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CPhysical, Remove, _ZTV9CPhysical, 1, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CPhysical, GetBoundRect, _ZTV9CPhysical, 8, CRect)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CPhysical, ProcessControl, _ZTV9CPhysical, 9, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CPhysical, ProcessCollision, _ZTV9CPhysical, 10, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CPhysical, ProcessShift, _ZTV9CPhysical, 11, void)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CPhysical, ProcessEntityCollision, _ZTV9CPhysical, 18, i32, CEntity* entity, CColPoint* colPoints)
    DECL_VIRTUALCALL_TAIL(entity, colPoints)

    // Static functions
    DECL_FASTCALL_SIMPLE(PlacePhysicalRelativeToOtherPhysical, _ZN9CPhysical36PlacePhysicalRelativeToOtherPhysicalEPS_S0_7CVector, void, CPhysical* physical1, CPhysical* physical2, CVector offset);

    // Member functions
    DECL_THISCALL_SIMPLE(RemoveAndAdd, _ZN9CPhysical12RemoveAndAddEv, void);
    DECL_THISCALL_SIMPLE(AddToMovingList, _ZN9CPhysical15AddToMovingListEv, void);
    DECL_THISCALL_SIMPLE(RemoveFromMovingList, _ZN9CPhysical20RemoveFromMovingListEv, void);
    DECL_THISCALL_SIMPLE(ApplyMoveSpeed, _ZN9CPhysical14ApplyMoveSpeedEv, void);
    DECL_THISCALL_SIMPLE(ApplyTurnSpeed, _ZN9CPhysical14ApplyTurnSpeedEv, void);
    DECL_THISCALL_SIMPLE(ApplyGravity, _ZN9CPhysical12ApplyGravityEv, void);
    DECL_THISCALL_SIMPLE(ApplyFriction, _ZN9CPhysical13ApplyFrictionEv, void);
    DECL_THISCALL_SIMPLE(ApplyAirResistance, _ZN9CPhysical18ApplyAirResistanceEv, void);
    DECL_THISCALL_SIMPLE(SkipPhysics, _ZN9CPhysical11SkipPhysicsEv, void);
    DECL_THISCALL_SIMPLE(CheckCollision, _ZN9CPhysical14CheckCollisionEv, bool);
    DECL_THISCALL_SIMPLE(CheckCollision_SimpleCar, _ZN9CPhysical24CheckCollision_SimpleCarEv, bool);

    DECL_THISCALL_HEAD(ApplyMoveForce, _ZN9CPhysical14ApplyMoveForceEfff, void, float x, float y, float z)
    DECL_THISCALL_TAIL(ApplyMoveForce, x, y, z)
    DECL_THISCALL_HEAD(ApplyTurnForce, _ZN9CPhysical14ApplyTurnForceEffffff, void, float forceX, float forceY, float forceZ, float pointX, float pointY, float pointZ)
    DECL_THISCALL_TAIL(ApplyTurnForce, forceX, forceY, forceZ, pointX, pointY, pointZ)
    DECL_THISCALL_HEAD(ApplyFrictionMoveForce, _ZN9CPhysical22ApplyFrictionMoveForceEfff, void, float x, float y, float z)
    DECL_THISCALL_TAIL(ApplyFrictionMoveForce, x, y, z)
    DECL_THISCALL_HEAD(ApplyFrictionTurnForce, _ZN9CPhysical22ApplyFrictionTurnForceEffffff, void, float forceX, float forceY, float forceZ, float pointX, float pointY, float pointZ)
    DECL_THISCALL_TAIL(ApplyFrictionTurnForce, forceX, forceY, forceZ, pointX, pointY, pointZ)

    DECL_THISCALL_HEAD(ProcessShiftSectorList, _ZN9CPhysical22ProcessShiftSectorListEP8CPtrList, bool, CPtrList* list)
    DECL_THISCALL_TAIL(ProcessShiftSectorList, list)
    DECL_THISCALL_HEAD(ProcessCollisionSectorList, _ZN9CPhysical26ProcessCollisionSectorListEP8CPtrList, bool, CPtrList* list)
    DECL_THISCALL_TAIL(ProcessCollisionSectorList, list)
    DECL_THISCALL_HEAD(ProcessCollisionSectorList_SimpleCar, _ZN9CPhysical36ProcessCollisionSectorList_SimpleCarEP7CSector, bool, CSector* sector)
    DECL_THISCALL_TAIL(ProcessCollisionSectorList_SimpleCar, sector)
    DECL_THISCALL_HEAD(AddCollisionRecord, _ZN9CPhysical18AddCollisionRecordEP7CEntity, void, CEntity* entity)
    DECL_THISCALL_TAIL(AddCollisionRecord, entity)
    DECL_THISCALL_HEAD(AddCollisionRecord_Treadable, _ZN9CPhysical28AddCollisionRecord_TreadableEP7CEntity, void, CEntity* entity)
    DECL_THISCALL_TAIL(AddCollisionRecord_Treadable, entity)
    DECL_THISCALL_HEAD(RemoveRefsToEntity, _ZN9CPhysical18RemoveRefsToEntityEP7CEntity, void, CEntity* entity)
    DECL_THISCALL_TAIL(RemoveRefsToEntity, entity)
    DECL_THISCALL_HEAD(GetHasCollidedWith, _ZN9CPhysical18GetHasCollidedWithEP7CEntity, bool, CEntity* entity)
    DECL_THISCALL_TAIL(GetHasCollidedWith, entity)

    DECL_THISCALL_HEAD(ApplyCollision, _ZN9CPhysical14ApplyCollisionER9CColPointRf, bool, CColPoint& colPoint, float& impulse)
    DECL_THISCALL_TAIL(ApplyCollision, colPoint, impulse)
    DECL_THISCALL_NAMED_HEAD(ApplyCollision1, ApplyCollision, _ZN9CPhysical14ApplyCollisionEPS_R9CColPointRfS3_, bool, CPhysical* physical, CColPoint& colPoint, float& impulseA, float& impulseB)
    DECL_THISCALL_TAIL(ApplyCollision1, physical, colPoint, impulseA, impulseB)
    DECL_THISCALL_HEAD(ApplyCollisionAlt, _ZN9CPhysical17ApplyCollisionAltEP7CEntityR9CColPointRfR7CVectorS6_, bool, CEntity* entity, CColPoint& colPoint, float& impulse, CVector& moveSpeed, CVector& turnSpeed)
    DECL_THISCALL_TAIL(ApplyCollisionAlt, entity, colPoint, impulse, moveSpeed, turnSpeed)
    DECL_THISCALL_NAMED_HEAD(ApplyFriction1, ApplyFriction, _ZN9CPhysical13ApplyFrictionEfR9CColPoint, bool, float adhesiveLimit, CColPoint& colPoint)
    DECL_THISCALL_TAIL(ApplyFriction1, adhesiveLimit, colPoint)
    DECL_THISCALL_NAMED_HEAD(ApplyFriction2, ApplyFriction, _ZN9CPhysical13ApplyFrictionEPS_fR9CColPoint, bool, CPhysical* physical, float adhesiveLimit, CColPoint& colPoint)
    DECL_THISCALL_TAIL(ApplyFriction2, physical, adhesiveLimit, colPoint)
    DECL_THISCALL_HEAD(ApplySpringCollision, _ZN9CPhysical20ApplySpringCollisionEfR7CVectorS1_ff, bool, float springStrength, CVector& direction, CVector& point, float compression, float suspensionBias)
    DECL_THISCALL_TAIL(ApplySpringCollision, springStrength, direction, point, compression, suspensionBias)
    DECL_THISCALL_HEAD(ApplySpringCollisionAlt, _ZN9CPhysical23ApplySpringCollisionAltEfR7CVectorS1_ffS1_, bool, float springStrength, CVector& direction, CVector& point, float compression, float suspensionBias, CVector& normal)
    DECL_THISCALL_TAIL(ApplySpringCollisionAlt, springStrength, direction, point, compression, suspensionBias, normal)
    DECL_THISCALL_HEAD(ApplySpringDampening, _ZN9CPhysical20ApplySpringDampeningEfR7CVectorS1_S1_, bool, float damping, CVector& direction, CVector& point, CVector& speed)
    DECL_THISCALL_TAIL(ApplySpringDampening, damping, direction, point, speed)

    // Helper functions
    inline void ApplyMoveForce(CVector const& force) { ApplyMoveForce(force.x, force.y, force.z); }
    inline void ApplyTurnForce(CVector const& force, CVector const& point) { ApplyTurnForce(force.x, force.y, force.z, point.x, point.y, point.z); }
    inline void ApplyFrictionMoveForce(CVector const& force) { ApplyFrictionMoveForce(force.x, force.y, force.z); }
    inline void ApplyFrictionTurnForce(CVector const& force, CVector const& point) { ApplyFrictionTurnForce(force.x, force.y, force.z, point.x, point.y, point.z); }

    // Member values
    i32 m_nAudioEntityId;
    float m_fUnknownX;
    u32 m_nLastCollisionTime;
    CVector m_vecMoveSpeed;
    CVector m_vecTurnSpeed;
    CVector m_vecFrictionMoveForce;
    CVector m_vecFrictionTurnForce;
    CVector m_vecForce;
    CVector m_vecTorque;
    float m_fMass;
    float m_fTurnMass;
    float m_fVelocityFrequency;
    float m_fAirResistance;
    float m_fElasticity;
    float m_fBuoyancyConstant;
    CVector m_vecCentreOfMass;
    CEntryInfoList m_collisionList;
    CPtrNode* m_pMovingListNode;
    u8 uCollideExtra;
    u8 uCollideInfo;
    u8 m_nNumCollisionRecords;
    CEntity* m_apCollisionRecords[6];
    float m_fTotSpeed;
    float m_fCollisionPower;
    CEntity* m_pPhysColliding;
    CVector m_vecCollisionPower;
    u16 m_wComponentCol;
    union
    {
        u8 m_nMoveFlags;
        struct
        {
            u8 bIsHeavy : 1;
            u8 bAffectedByGravity : 1;
            u8 bInfiniteMass : 1;
            u8 bPhysicalFlag04 : 1;
            u8 bIsInWater : 1;
            u8 bPhysicalFlag06 : 1;
            u8 bPhysicalFlag07 : 1;
            u8 bSkipLineCol : 1;
        };
    };
    union
    {
        u8 m_nCollFlags;
        struct
        {
            u8 bIsFrozen : 1;
            u8 bDontLoadCollision : 1;
            u8 bIsBeingShifted : 1;
            u8 bJustCheckCollision : 1;
            u8 : 4;
        };
    };
    u8 m_nLastCollType;
    u8 m_nZoneLevel;
DECL_CLASS_END()
CHECKSIZE(CPhysical, 0x124, 0x168);

#endif // __AML_PSDK_VCPHYSICAL_H
