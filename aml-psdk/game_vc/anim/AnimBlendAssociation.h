#ifndef __AML_PSDK_VCANIMBLENDASSOCIATION_H
#define __AML_PSDK_VCANIMBLENDASSOCIATION_H

#include <aml-psdk/game_vc/plugin.h>
#include "AnimBlendHierarchy.h"
#include "AnimBlendNode.h"
#include <aml-psdk/renderware/RwLinks.h>

struct RpClump;
struct CAnimBlendAssociation;
typedef void(*AnimBlendCallback)(CAnimBlendAssociation*, void*);

enum eAnimBlendCallbackType : u32
{
    ANIMBLENDCALLBACK_NONE = 0,
    ANIMBLENDCALLBACK_FINISH = 1,
    ANIMBLENDCALLBACK_DELETE = 2,
};

enum eAnimationFlags
{
    ANIMATION_STARTED = 0x1,
    ANIMATION_LOOPED = 0x2,
    ANIMATION_BLEND_AUTO_REMOVE = 0x4,
    ANIMATION_FINISH_AUTO_REMOVE = 0x8,
    ANIMATION_PARTIAL = 0x10,
    ANIMATION_MOVEMENT = 0x20,
};

DECL_CLASS(CAnimBlendAssociation)
    // Construct/Deconstruct functions
    DECL_CTORCALL(CAnimBlendAssociation, _ZN21CAnimBlendAssociationC2Ev);
    DECL_CTORCALL_NAMED_ARG_HEAD(CAnimBlendAssociation1, CAnimBlendAssociation, _ZN21CAnimBlendAssociationC2EP7RpClumpP19CAnimBlendHierarchy, RpClump* clump, CAnimBlendHierarchy* hierarchy)
    DECL_CTORCALL_ARG_TAIL(clump, hierarchy)
    DECL_CTORCALL_NAMED_ARG_HEAD(CAnimBlendAssociation2, CAnimBlendAssociation, _ZN21CAnimBlendAssociationC2ERS_, CAnimBlendAssociation& source)
    DECL_CTORCALL_ARG_TAIL(source)
    DECL_DTORCALL_VIRTUAL(CAnimBlendAssociation, _ZN21CAnimBlendAssociationD2Ev, _ZN21CAnimBlendAssociation, _ZTV21CAnimBlendAssociation);

    // Member functions
    DECL_THISCALL_NAMED_HEAD(Init1, Init, _ZN21CAnimBlendAssociation4InitEP7RpClumpP19CAnimBlendHierarchy, void, RpClump* clump, CAnimBlendHierarchy* hierarchy)
    DECL_THISCALL_TAIL(Init1, clump, hierarchy)
    DECL_THISCALL_NAMED_HEAD(Init2, Init, _ZN21CAnimBlendAssociation4InitERS_, void, CAnimBlendAssociation& source)
    DECL_THISCALL_TAIL(Init2, source)
    DECL_THISCALL_HEAD(AllocateAnimBlendNodeArray, _ZN21CAnimBlendAssociation26AllocateAnimBlendNodeArrayEi, void, i32 nodeCount)
    DECL_THISCALL_TAIL(AllocateAnimBlendNodeArray, nodeCount)
    DECL_THISCALL_SIMPLE(FreeAnimBlendNodeArray, _ZN21CAnimBlendAssociation22FreeAnimBlendNodeArrayEv, void);
    DECL_THISCALL_HEAD(SetCurrentTime, _ZN21CAnimBlendAssociation14SetCurrentTimeEf, void, float time)
    DECL_THISCALL_TAIL(SetCurrentTime, time)
    DECL_THISCALL_HEAD(SyncAnimation, _ZN21CAnimBlendAssociation13SyncAnimationEPS_, void, CAnimBlendAssociation* association)
    DECL_THISCALL_TAIL(SyncAnimation, association)
    DECL_THISCALL_HEAD(GetNode, _ZN21CAnimBlendAssociation7GetNodeEi, CAnimBlendNode*, i32 nodeIndex)
    DECL_THISCALL_TAIL(GetNode, nodeIndex)
    DECL_THISCALL_HEAD(SetBlend, _ZN21CAnimBlendAssociation8SetBlendEff, void, float amount, float delta)
    DECL_THISCALL_TAIL(SetBlend, amount, delta)
    DECL_THISCALL_HEAD(SetBlendTo, _ZN21CAnimBlendAssociation10SetBlendToEff, void, float amount, float delta)
    DECL_THISCALL_TAIL(SetBlendTo, amount, delta)
    DECL_THISCALL_HEAD(Start, _ZN21CAnimBlendAssociation5StartEf, void, float time)
    DECL_THISCALL_TAIL(Start, time)
    // UpdateBlend may delete this association when auto-removal is enabled.
    DECL_THISCALL_HEAD(UpdateBlend, _ZN21CAnimBlendAssociation11UpdateBlendEf, bool, float delta)
    DECL_THISCALL_TAIL(UpdateBlend, delta)
    DECL_THISCALL_HEAD(UpdateTime, _ZN21CAnimBlendAssociation10UpdateTimeEff, bool, float value1, float value2)
    DECL_THISCALL_TAIL(UpdateTime, value1, value2)
    DECL_THISCALL_HEAD(UpdateTimeStep, _ZN21CAnimBlendAssociation14UpdateTimeStepEff, void, float speed, float timeStep)
    DECL_THISCALL_TAIL(UpdateTimeStep, speed, timeStep)
    DECL_THISCALL_HEAD(SetFinishCallback, _ZN21CAnimBlendAssociation17SetFinishCallbackEPFvPS_PvES1_, void, AnimBlendCallback callback, void* data)
    DECL_THISCALL_TAIL(SetFinishCallback, callback, data)
    DECL_THISCALL_HEAD(SetDeleteCallback, _ZN21CAnimBlendAssociation17SetDeleteCallbackEPFvPS_PvES1_, void, AnimBlendCallback callback, void* data)
    DECL_THISCALL_TAIL(SetDeleteCallback, callback, data)

    CAnimBlendAssociation& operator=(CAnimBlendAssociation const&) = delete;

    // Member values
    RwLLLink m_link;
    i16 m_nNumBlendNodes;
    u16 m_nAnimGroup;
    CAnimBlendNode* m_pNodeArray;
    CAnimBlendHierarchy* m_pHierarchy;
    float m_fBlendAmount;
    float m_fBlendDelta;
    float m_fCurrentTime;
    float m_fSpeed;
    float fTimeStep;
    i16 m_nAnimId;
    u16 m_nFlags;
    eAnimBlendCallbackType m_nCallbackType;
    AnimBlendCallback m_pCallbackFunc;
    void* m_pCallbackData;
DECL_CLASS_END()
CHECKSIZE(CAnimBlendAssociation, 0x3C, 0x60);

#endif // __AML_PSDK_VCANIMBLENDASSOCIATION_H
