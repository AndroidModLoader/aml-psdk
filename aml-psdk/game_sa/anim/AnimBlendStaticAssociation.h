#ifndef __AML_PSDK_SAANIMBLENDSTATICASSOCIATION_H
#define __AML_PSDK_SAANIMBLENDSTATICASSOCIATION_H

/*
    Plugin-SDK (Grand Theft Auto San Andreas) header file
    Authors: GTA Community. See more here
    https://github.com/DK22Pac/plugin-sdk
    Do not delete this comment block. Respect others' work!
*/

#include "../plugin.h"
#include "AnimBlendHierarchy.h"
struct RpClump;

DECL_CLASS(CAnimBlendStaticAssociation)
    // Construct/Deconstruct functions
    DECL_CTORCALL(CAnimBlendStaticAssociation, _ZN27CAnimBlendStaticAssociationC2Ev);
    DECL_DTORCALL(CAnimBlendStaticAssociation, _ZN27CAnimBlendStaticAssociationD2Ev);
    DECL_CTORCALL_NAMED_ARG_HEAD(CAnimBlendStaticAssociation1, CAnimBlendStaticAssociation, _ZN27CAnimBlendStaticAssociationC2EP7RpClumpP19CAnimBlendHierarchy, RpClump* clump, CAnimBlendHierarchy* hierarchy)
    DECL_CTORCALL_ARG_TAIL(clump, hierarchy)

    // Member functions
    DECL_THISCALL_SIMPLE(Delete, _ZN27CAnimBlendStaticAssociationD0Ev, void);
    DECL_THISCALL_HEAD(Init, _ZN27CAnimBlendStaticAssociation4InitEP7RpClumpP19CAnimBlendHierarchy, void, RpClump* clump, CAnimBlendHierarchy* hierarchy)
    DECL_THISCALL_TAIL(Init, clump, hierarchy)
    DECL_THISCALL_HEAD(AllocateSequenceArray, _ZN27CAnimBlendStaticAssociation21AllocateSequenceArrayEi, void, i32 numNodes)
    DECL_THISCALL_TAIL(AllocateSequenceArray, numNodes)
    DECL_THISCALL_SIMPLE(FreeSequenceArray, _ZN27CAnimBlendStaticAssociation17FreeSequenceArrayEv, void);

    // Member values
    void *vtable;
    i16 m_nNumBlendNodes;
    i16 m_nAnimId;
    i16 m_nAnimGroup;
    u16 m_nFlags;
    CAnimBlendSequence **m_pSequences;
    CAnimBlendHierarchy *m_pHierarchy;
DECL_CLASS_END()
CHECKSIZE(CAnimBlendStaticAssociation, 0x14, 0x20);

#endif // __AML_PSDK_SAANIMBLENDSTATICASSOCIATION_H
