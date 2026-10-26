#ifndef __AML_PSDK_VCANIMBLENDHIERARCHY_H
#define __AML_PSDK_VCANIMBLENDHIERARCHY_H

#include <aml-psdk/game_vc/plugin.h>
#include "AnimBlendSequence.h"

template<class T> struct CLink;

DECL_CLASS(CAnimBlendHierarchy)
    // Construct/Deconstruct functions
    DECL_CTORCALL(CAnimBlendHierarchy, _ZN19CAnimBlendHierarchyC2Ev);
    DECL_DTORCALL(CAnimBlendHierarchy, _ZN19CAnimBlendHierarchyD2Ev);

    // Member functions
    DECL_THISCALL_HEAD(SetName, _ZN19CAnimBlendHierarchy7SetNameEPKc, void, char const* name)
    DECL_THISCALL_TAIL(SetName, name)
    DECL_THISCALL_HEAD(FindSequence, _ZN19CAnimBlendHierarchy12FindSequenceEPc, CAnimBlendSequence*, char* name)
    DECL_THISCALL_TAIL(FindSequence, name)
    DECL_THISCALL_SIMPLE(Shutdown, _ZN19CAnimBlendHierarchy8ShutdownEv, void);
    DECL_THISCALL_SIMPLE(RemoveAnimSequences, _ZN19CAnimBlendHierarchy19RemoveAnimSequencesEv, void);
    DECL_THISCALL_SIMPLE(CalcTotalTime, _ZN19CAnimBlendHierarchy13CalcTotalTimeEv, void);
    DECL_THISCALL_SIMPLE(CalcTotalTimeCompressed, _ZN19CAnimBlendHierarchy23CalcTotalTimeCompressedEv, void);
    DECL_THISCALL_SIMPLE(RemoveQuaternionFlips, _ZN19CAnimBlendHierarchy21RemoveQuaternionFlipsEv, void);
    DECL_THISCALL_SIMPLE(Uncompress, _ZN19CAnimBlendHierarchy10UncompressEv, void);
    DECL_THISCALL_SIMPLE(RemoveUncompressedData, _ZN19CAnimBlendHierarchy22RemoveUncompressedDataEv, void);

    CAnimBlendHierarchy(CAnimBlendHierarchy const&) = delete;
    CAnimBlendHierarchy& operator=(CAnimBlendHierarchy const&) = delete;

    // Member values
    char m_szName[24];
    // The hierarchy owns this sequence array.
    CAnimBlendSequence* m_pSequences;
    i16 m_nSeqCount;
    bool m_bCompressed;
    bool m_bKeepCompressed;
    float m_fTotalTime;
    CLink<CAnimBlendHierarchy*>* m_pLink;
DECL_CLASS_END()
CHECKSIZE(CAnimBlendHierarchy, 0x28, 0x30);

#endif // __AML_PSDK_VCANIMBLENDHIERARCHY_H
