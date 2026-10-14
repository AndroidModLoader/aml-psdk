#ifndef __AML_PSDK_SAANIMBLENDHIERARCHY_H
#define __AML_PSDK_SAANIMBLENDHIERARCHY_H

/*
    Plugin-SDK (Grand Theft Auto San Andreas) header file
    Authors: GTA Community. See more here
    https://github.com/DK22Pac/plugin-sdk
    Do not delete this comment block. Respect others' work!
*/

#include "../plugin.h"
#include "AnimBlendSequence.h"
#include "../base/Lists.h"

DECL_CLASS(CAnimBlendHierarchy)
    // Construct/Deconstruct functions
    DECL_CTORCALL(CAnimBlendHierarchy, _ZN19CAnimBlendHierarchyC2Ev);
    DECL_DTORCALL(CAnimBlendHierarchy, _ZN19CAnimBlendHierarchyD2Ev);

    // Member functions
    DECL_THISCALL_SIMPLE(GetSequenceBlock, _ZN19CAnimBlendHierarchy16GetSequenceBlockEv, u8*);
    DECL_THISCALL_HEAD(AllocSequenceBlock, _ZN19CAnimBlendHierarchy18AllocSequenceBlockEb, u8*, bool compressed)
    DECL_THISCALL_TAIL(AllocSequenceBlock, compressed)
    DECL_THISCALL_SIMPLE(Shutdown, _ZN19CAnimBlendHierarchy8ShutdownEv, void);
    DECL_THISCALL_HEAD(SetName, _ZN19CAnimBlendHierarchy7SetNameEPKc, void, const char* name)
    DECL_THISCALL_TAIL(SetName, name)
    DECL_THISCALL_SIMPLE(RemoveAnimSequences, _ZN19CAnimBlendHierarchy19RemoveAnimSequencesEv, void);
    DECL_THISCALL_HEAD(FindSequence, _ZN19CAnimBlendHierarchy12FindSequenceEPc, CAnimBlendSequence*, char* name)
    DECL_THISCALL_TAIL(FindSequence, name)
    DECL_THISCALL_SIMPLE(CalcTotalTime, _ZN19CAnimBlendHierarchy13CalcTotalTimeEv, void);
    DECL_THISCALL_SIMPLE(CalcTotalTimeCompressed, _ZN19CAnimBlendHierarchy23CalcTotalTimeCompressedEv, void);
    DECL_THISCALL_SIMPLE(RemoveQuaternionFlips, _ZN19CAnimBlendHierarchy21RemoveQuaternionFlipsEv, void);
    DECL_THISCALL_SIMPLE(Uncompress, _ZN19CAnimBlendHierarchy10UncompressEv, void);
    DECL_THISCALL_SIMPLE(CompressKeyframes, _ZN19CAnimBlendHierarchy17CompressKeyframesEv, void);
    DECL_THISCALL_SIMPLE(RemoveUncompressedData, _ZN19CAnimBlendHierarchy22RemoveUncompressedDataEv, void);
    DECL_THISCALL_SIMPLE(MoveMemory, _ZN19CAnimBlendHierarchy10MoveMemoryEv, bool);
    DECL_THISCALL_SIMPLE(Print, _ZN19CAnimBlendHierarchy5PrintEv, void);

    // Member values
    u32 m_hashKey;
    CAnimBlendSequence *m_pSequences;
    i16 m_nSeqCount;
    bool m_bCompressed;
    bool m_bRunningCompressed;
    i32 m_nAnimBlockId;
    float m_fTotalTime;
    CLink<CAnimBlendHierarchy*> *m_pLink;
DECL_CLASS_END()
CHECKSIZE(CAnimBlendHierarchy, 0x18, 0x28);

#endif // __AML_PSDK_SAANIMBLENDHIERARCHY_H
