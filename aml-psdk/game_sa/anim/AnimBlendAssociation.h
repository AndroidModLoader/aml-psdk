#ifndef __AML_PSDK_SAANIMBLENDASSOCIATION_H
#define __AML_PSDK_SAANIMBLENDASSOCIATION_H

/*
    Plugin-SDK (Grand Theft Auto San Andreas) header file
    Authors: GTA Community. See more here
    https://github.com/DK22Pac/plugin-sdk
    Do not delete this comment block. Respect others' work!
*/

#include "../plugin.h"
#include "AnimBlendStaticAssociation.h"
#include "AnimBlendNode.h"
#include "AnimBlendClumpData.h"
struct CAnimBlendAssociation;
typedef void(*AnimBlendCallback)(CAnimBlendAssociation*, void*);
enum eAnimationFlags
{
    ANIMATION_STARTED = 0x1,
    ANIMATION_LOOPED = 0x2,
    ANIMATION_FREEZE_LAST_FRAME = 0x4,
    ANIMATION_UNLOCK_LAST_FRAME = 0x8,
    ANIMATION_PARTIAL = 0x10,
    ANIMATION_MOVEMENT = 0x20,
    ANIMATION_TRANLSATE_X = 0x40,
    ANIMATION_TRANLSATE_Y = 0x80,
    ANIMATION_UNUSED_1 = 0x100,
    ANIMATION_UNUSED_2 = 0x200,
    ANIMATION_ADD_TO_BLEND = 0x400,
    ANIMATION_UNUSED_3 = 0x800,
    ANIMATION_UNUSED_4 = 0x1000,
    ANIMATION_FREEZE_TRANSLATION = 0x2000,
    ANIMATION_BLOCK_REFERENCED = 0x4000,
    ANIMATION_INDESTRUCTIBLE = 0x8000
};

enum AnimBlendCallbackType
{
    ABCB_NONE = 0,
    ABCB_FINISH = 1,
    ABCB_DELETE = 2,
};

DECL_CLASS(CAnimBlendAssociation)
    // Construct/Deconstruct functions
    DECL_CTORCALL(CAnimBlendAssociation, _ZN21CAnimBlendAssociationC2Ev);
    DECL_DTORCALL(CAnimBlendAssociation, _ZN21CAnimBlendAssociationD2Ev);
    DECL_CTORCALL_PROXY(CAnimBlendAssociation1, _ZN21CAnimBlendAssociationC2EP7RpClumpP19CAnimBlendHierarchy, RpClump* clump, CAnimBlendHierarchy* hierarchy);
    CAnimBlendAssociation(RpClump* clump, CAnimBlendHierarchy* hierarchy) { FuncProxy_ctorCAnimBlendAssociation1(this, clump, hierarchy); }
    DECL_CTORCALL_PROXY(CAnimBlendAssociation2, _ZN21CAnimBlendAssociationC2ERS_, CAnimBlendAssociation& source);
    CAnimBlendAssociation(CAnimBlendAssociation& source) { FuncProxy_ctorCAnimBlendAssociation2(this, source); }
    DECL_CTORCALL_PROXY(CAnimBlendAssociation3, _ZN21CAnimBlendAssociationC2ER27CAnimBlendStaticAssociation, CAnimBlendStaticAssociation& source);
    CAnimBlendAssociation(CAnimBlendStaticAssociation& source) { FuncProxy_ctorCAnimBlendAssociation3(this, source); }

    // Member functions
    DECL_THISCALL_SIMPLE(Delete, _ZN21CAnimBlendAssociationD0Ev, void);
    DECL_THISCALL_NAMED_HEAD(Init1, Init, _ZN21CAnimBlendAssociation4InitEP7RpClumpP19CAnimBlendHierarchy, void, RpClump* clump, CAnimBlendHierarchy* hierarchy)
    DECL_THISCALL_TAIL(Init1, clump, hierarchy)
    DECL_THISCALL_NAMED_HEAD(Init2, Init, _ZN21CAnimBlendAssociation4InitERS_, void, CAnimBlendAssociation& source)
    DECL_THISCALL_TAIL(Init2, source)
    DECL_THISCALL_NAMED_HEAD(Init3, Init, _ZN21CAnimBlendAssociation4InitER27CAnimBlendStaticAssociation, void, CAnimBlendStaticAssociation& source)
    DECL_THISCALL_TAIL(Init3, source)
    DECL_THISCALL_HEAD(AllocateAnimBlendNodeArray, _ZN21CAnimBlendAssociation26AllocateAnimBlendNodeArrayEi, void, i32 numNodes)
    DECL_THISCALL_TAIL(AllocateAnimBlendNodeArray, numNodes)
    DECL_THISCALL_SIMPLE(FreeAnimBlendNodeArray, _ZN21CAnimBlendAssociation22FreeAnimBlendNodeArrayEv, void);
    DECL_THISCALL_SIMPLE(ReferenceAnimBlock, _ZN21CAnimBlendAssociation18ReferenceAnimBlockEv, void);
    DECL_THISCALL_HEAD(SetCurrentTime, _ZN21CAnimBlendAssociation14SetCurrentTimeEf, void, float time)
    DECL_THISCALL_TAIL(SetCurrentTime, time)
    DECL_THISCALL_HEAD(SyncAnimation, _ZN21CAnimBlendAssociation13SyncAnimationEPS_, void, CAnimBlendAssociation* association)
    DECL_THISCALL_TAIL(SyncAnimation, association)
    DECL_THISCALL_HEAD(GetNode, _ZN21CAnimBlendAssociation7GetNodeEi, CAnimBlendNode*, i32 nodeIndex)
    DECL_THISCALL_TAIL(GetNode, nodeIndex)
    DECL_THISCALL_HEAD(SetBlend, _ZN21CAnimBlendAssociation8SetBlendEff, void, float blendAmount, float blendDelta)
    DECL_THISCALL_TAIL(SetBlend, blendAmount, blendDelta)
    DECL_THISCALL_HEAD(SetBlendTo, _ZN21CAnimBlendAssociation10SetBlendToEff, void, float blendAmount, float blendDelta)
    DECL_THISCALL_TAIL(SetBlendTo, blendAmount, blendDelta)
    DECL_THISCALL_HEAD(Start, _ZN21CAnimBlendAssociation5StartEf, void, float time)
    DECL_THISCALL_TAIL(Start, time)
    DECL_THISCALL_HEAD(UpdateBlend, _ZN21CAnimBlendAssociation11UpdateBlendEf, bool, float blendDeltaMult)
    DECL_THISCALL_TAIL(UpdateBlend, blendDeltaMult)
    DECL_THISCALL_HEAD(UpdateTime, _ZN21CAnimBlendAssociation10UpdateTimeEff, bool, float unused1, float unused2)
    DECL_THISCALL_TAIL(UpdateTime, unused1, unused2)
    DECL_THISCALL_HEAD(UpdateTimeStep, _ZN21CAnimBlendAssociation14UpdateTimeStepEff, void, float speedMult, float timeMult)
    DECL_THISCALL_TAIL(UpdateTimeStep, speedMult, timeMult)
    DECL_THISCALL_HEAD(SetFinishCallback, _ZN21CAnimBlendAssociation17SetFinishCallbackEPFvPS_PvES1_, void, AnimBlendCallback callback, void* data)
    DECL_THISCALL_TAIL(SetFinishCallback, callback, data)
    DECL_THISCALL_HEAD(SetDeleteCallback, _ZN21CAnimBlendAssociation17SetDeleteCallbackEPFvPS_PvES1_, void, AnimBlendCallback callback, void* data)
    DECL_THISCALL_TAIL(SetDeleteCallback, callback, data)

    // Member values
    void *vtable;
    ListLink m_link;
    i16 m_nNumBlendNodes;
    i16 m_nAnimGroup;
    CAnimBlendNode *m_pNodeArray;
    CAnimBlendHierarchy *m_pHierarchy;
    float m_fBlendAmount;
    float m_fBlendDelta;
    float m_fCurrentTime;
    float m_fSpeed;
    float fTimeStep;
    i16 m_nAnimId;
    u16 m_nFlags;
    AnimBlendCallbackType m_nCallbackType;
    AnimBlendCallback m_pCallbackFunc;
    void *m_pCallbackData;
DECL_CLASS_END()
CHECKSIZE(CAnimBlendAssociation, 0x3C, 0x60);

#endif // __AML_PSDK_SAANIMBLENDASSOCIATION_H
