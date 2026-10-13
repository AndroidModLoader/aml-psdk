#ifndef __AML_PSDK_RPHANIM_H
#define __AML_PSDK_RPHANIM_H

#include "RwFrame.h"

struct RtAnimInterpolator;

enum RpHAnimHierarchyFlag : RwInt32
{
    rpHANIMHIERARCHYSUBHIERARCHY = 0x1,
    rpHANIMHIERARCHYNOMATRICES = 0x2,
    rpHANIMHIERARCHYUPDATEMODELLINGMATRICES = 0x1000,
    rpHANIMHIERARCHYUPDATELTMS = 0x2000,
    rpHANIMHIERARCHYLOCALSPACEMATRICES = 0x4000,
    rpHANIMHIERARCHYFLAGFORCEENUMSIZEINT = 0x7FFFFFFF
};

struct RtQuat
{
    RwV3d imag;
    RwReal real;
};
CHECKSIZE(RtQuat, 0x10, 0x10);

struct RpHAnimBlendInterpFrame
{
    RtQuat q;
    RwV3d t;
};
CHECKSIZE(RpHAnimBlendInterpFrame, 0x1C, 0x1C);

struct RpHAnimNodeInfo
{
    RwInt32 nodeID;
    RwInt32 nodeIndex;
    RwInt32 flags;
    RwFrame *pFrame;
};
CHECKSIZE(RpHAnimNodeInfo, 0x10, 0x18);

struct RpHAnimHierarchy
{
    RwInt32 flags;
    RwInt32 numNodes;
    RwMatrix *pMatrixArray;
    void *pMatrixArrayUnaligned;
    RpHAnimNodeInfo *pNodeInfo;
    RwFrame *parentFrame;
    RpHAnimHierarchy *parentHierarchy;
    RwInt32 rootParentOffset;
    RtAnimInterpolator *currentAnim;
};
CHECKSIZE(RpHAnimHierarchy, 0x24, 0x40);

DECL_FASTCALL_SIMPLE_GLO(RpHAnimHierarchyCreate, _Z22RpHAnimHierarchyCreateiPjPi20RpHAnimHierarchyFlagi, RpHAnimHierarchy*,
    RwInt32 numNodes, RwUInt32* nodeFlags, RwInt32* nodeIDs, RpHAnimHierarchyFlag flags, RwInt32 maxInterpKeyFrameSize);
DECL_FASTCALL_SIMPLE_GLO(RpHAnimHierarchyDestroy, _Z23RpHAnimHierarchyDestroyP16RpHAnimHierarchy, RpHAnimHierarchy*, RpHAnimHierarchy* hierarchy);
DECL_FASTCALL_SIMPLE_GLO(RpHAnimHierarchyCreateFromHierarchy, _Z35RpHAnimHierarchyCreateFromHierarchyP16RpHAnimHierarchy20RpHAnimHierarchyFlagi, RpHAnimHierarchy*,
    RpHAnimHierarchy* hierarchy, RpHAnimHierarchyFlag flags, RwInt32 maxInterpKeyFrameSize);
DECL_FASTCALL_SIMPLE_GLO(RpHAnimHierarchyCreateSubHierarchy, _Z34RpHAnimHierarchyCreateSubHierarchyP16RpHAnimHierarchyi20RpHAnimHierarchyFlagi, RpHAnimHierarchy*,
    RpHAnimHierarchy* hierarchy, RwInt32 startNode, RpHAnimHierarchyFlag flags, RwInt32 maxInterpKeyFrameSize);
DECL_FASTCALL_SIMPLE_GLO(RpHAnimHierarchyGetMatrixArray, _Z30RpHAnimHierarchyGetMatrixArrayP16RpHAnimHierarchy, RwMatrix*, RpHAnimHierarchy* hierarchy);
DECL_FASTCALL_SIMPLE_GLO(RpHAnimHierarchyUpdateMatrices, _Z30RpHAnimHierarchyUpdateMatricesP16RpHAnimHierarchy, RwBool, RpHAnimHierarchy* hierarchy);
DECL_FASTCALL_SIMPLE_GLO(RpHAnimHierarchyAttach, _Z22RpHAnimHierarchyAttachP16RpHAnimHierarchy, RpHAnimHierarchy*, RpHAnimHierarchy* hierarchy);
DECL_FASTCALL_SIMPLE_GLO(RpHAnimHierarchyDetach, _Z22RpHAnimHierarchyDetachP16RpHAnimHierarchy, RpHAnimHierarchy*, RpHAnimHierarchy* hierarchy);
DECL_FASTCALL_SIMPLE_GLO(RpHAnimHierarchyAttachFrameIndex, _Z32RpHAnimHierarchyAttachFrameIndexP16RpHAnimHierarchyi, RpHAnimHierarchy*, RpHAnimHierarchy* hierarchy, RwInt32 nodeIndex);
DECL_FASTCALL_SIMPLE_GLO(RpHAnimHierarchyDetachFrameIndex, _Z32RpHAnimHierarchyDetachFrameIndexP16RpHAnimHierarchyi, RpHAnimHierarchy*, RpHAnimHierarchy* hierarchy, RwInt32 nodeIndex);
DECL_FASTCALL_SIMPLE_GLO(RpHAnimFrameGetHierarchy, _Z24RpHAnimFrameGetHierarchyP7RwFrame, RpHAnimHierarchy*, RwFrame* frame);
DECL_FASTCALL_SIMPLE_GLO(RpHAnimFrameSetHierarchy, _Z24RpHAnimFrameSetHierarchyP7RwFrameP16RpHAnimHierarchy, RwBool, RwFrame* frame, RpHAnimHierarchy* hierarchy);
DECL_FASTCALL_SIMPLE_GLO(RpHAnimFrameGetID, _Z17RpHAnimFrameGetIDP7RwFrame, RwInt32, RwFrame* frame);
DECL_FASTCALL_SIMPLE_GLO(RpHAnimFrameSetID, _Z17RpHAnimFrameSetIDP7RwFramei, RwBool, RwFrame* frame, RwInt32 id);
DECL_FASTCALL_SIMPLE_GLO(RpHAnimIDGetIndex, _Z17RpHAnimIDGetIndexP16RpHAnimHierarchyi, RwInt32, RpHAnimHierarchy* hierarchy, RwInt32 id);

#endif // __AML_PSDK_RPHANIM_H
