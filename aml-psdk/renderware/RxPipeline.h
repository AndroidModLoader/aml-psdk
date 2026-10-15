#ifndef __AML_PSDK_RXPIPELINE_H
#define __AML_PSDK_RXPIPELINE_H

#include <aml-psdk/sdk_base.h>
#include "RwBase.h"

struct RxPipeline;
struct RxPipelineNode;
struct RxPacket;
struct RxPipelineRequiresCluster;
struct RxCluster;
struct RxClusterRef;
struct RxClusterDefinition;
struct RxNodeDefinition;
struct RxNodeMethods;
struct RxIoSpec;
struct RxOutputSpec;
struct RxPipelineCluster;
struct RxHeap;
struct RxPipelineNodeParam;
struct RxPipelineNodeTopSortData;
struct rxHeapSuperBlockDescriptor;
struct rxHeapBlockHeader;
struct rxHeapFreeBlock;
struct rxReq;

enum rxEmbeddedPacketState : RwInt32
{
    rxPKST_PACKETLESS = 0x0,
    rxPKST_UNUSED = 0x1,
    rxPKST_INUSE = 0x2,
    rxPKST_PENDING = 0x3,
};

struct RxPipeline
{
    RwBool                     locked;
    RwUInt32                   numNodes;
    RxPipelineNode            *nodes;
    RwUInt32                   packetNumClusterSlots;
    rxEmbeddedPacketState      embeddedPacketState;
    RxPacket                  *embeddedPacket;
    RwUInt32                   numInputRequirements;
    RxPipelineRequiresCluster *inputRequirements;
    void                      *superBlock;
    RwUInt32                   superBlockSize;
    RwUInt32                   entryPoint;
    RwUInt32                   pluginId;
    RwUInt32                   pluginData;
};

CHECKSIZE(RxPipeline, 0x34, 0x48);

enum RxClusterValidityReq : RwInt32
{
    rxCLREQ_DONTWANT = 0,
    rxCLREQ_REQUIRED = 1,
    rxCLREQ_OPTIONAL = 2,
    rxCLUSTERVALIDITYREQFORCEENUMSIZEINT = 2147483647,
};

enum RxClusterForcePresent : RwInt32
{
    rxCLALLOWABSENT = 0,
    rxCLFORCEPRESENT = 1,
    rxCLUSTERFORCEPRESENTFORCEENUMSIZEINT = 2147483647,
};

enum RxNodeDefEditable : RwInt32
{
    rxNODEDEFCONST = 0,
    rxNODEDEFEDITABLE = 1,
    rxNODEDEFEDITABLEFORCEENUMSIZEINT = 2147483647,
};

enum RxClusterValid : RwInt32
{
    rxCLVALID_NOCHANGE = 0,
    rxCLVALID_VALID = 1,
    rxCLVALID_INVALID = 2,
    rxCLUSTERVALIDFORCEENUMSIZEINT = 2147483647,
};

typedef RwBool (*RxNodeBodyFn)(RxPipelineNode*, RxPipelineNodeParam const*);
typedef RwBool (*RxNodeInitFn)(RxNodeDefinition*);
typedef void (*RxNodeTermFn)(RxNodeDefinition*);
typedef RwBool (*RxPipelineNodeInitFn)(RxPipelineNode*);
typedef void (*RxPipelineNodeTermFn)(RxPipelineNode*);
typedef RwBool (*RxPipelineNodeConfigFn)(RxPipelineNode*, RxPipeline*);
typedef RwUInt32 (*RxConfigMsgHandlerFn)(RxPipelineNode*, RwUInt32, RwUInt32, void*);
typedef RxPipelineNode* (*RxPipelineNodeOutputCallBack)(RxPipelineNode*, RxPipelineNode*, void*);

struct RxPipelineRequiresCluster
{
    RxClusterDefinition* clusterDef;
    RxClusterValidityReq rqdOrOpt;
    RwUInt32 slotIndex;
};

CHECKSIZE(RxPipelineRequiresCluster, 0xC, 0x10);
struct RxClusterDefinition
{
    RwChar* name;
    RwUInt32 defaultStride;
    RwUInt32 defaultAttributes;
    RwChar const* attributeSet;
};

CHECKSIZE(RxClusterDefinition, 0x10, 0x18);
struct RxClusterRef
{
    RxClusterDefinition* clusterDef;
    RxClusterForcePresent forcePresent;
    RwUInt32 reserved;
};

CHECKSIZE(RxClusterRef, 0xC, 0x10);
struct RxOutputSpec
{
    RwChar* name;
    RxClusterValid* outputClusters;
    RxClusterValid allOtherClusters;
};

CHECKSIZE(RxOutputSpec, 0xC, 0x18);
struct RxIoSpec
{
    RwUInt32 numClustersOfInterest;
    RxClusterRef* clustersOfInterest;
    RxClusterValidityReq* inputRequirements;
    RwUInt32 numOutputs;
    RxOutputSpec* outputs;
};

CHECKSIZE(RxIoSpec, 0x14, 0x28);
struct RxNodeMethods
{
    RxNodeBodyFn nodeBody;
    RxNodeInitFn nodeInit;
    RxNodeTermFn nodeTerm;
    RxPipelineNodeInitFn pipelineNodeInit;
    RxPipelineNodeTermFn pipelineNodeTerm;
    RxPipelineNodeConfigFn pipelineNodeConfig;
    RxConfigMsgHandlerFn configMsgHandler;
};

CHECKSIZE(RxNodeMethods, 0x1C, 0x38);
struct RxNodeDefinition
{
    RwChar* name;
    RxNodeMethods nodeMethods;
    RxIoSpec io;
    RwUInt32 pipelineNodePrivateDataSize;
    RxNodeDefEditable editable;
    RwInt32 InputPipesCnt;
};

CHECKSIZE(RxNodeDefinition, 0x40, 0x78);
struct RxPipelineCluster
{
    RxClusterDefinition* clusterRef;
    RwUInt32 creationAttributes;
};

CHECKSIZE(RxPipelineCluster, 0x8, 0x10);
struct RxCluster
{
    RwUInt16 flags;
    RwUInt16 stride;
    void* data;
    void* currentData;
    RwUInt32 numAlloced;
    RwUInt32 numUsed;
    RxPipelineCluster* clusterRef;
    RwUInt32 attributes;
};

CHECKSIZE(RxCluster, 0x1C, 0x30);
struct RxPacket
{
    RwUInt16 flags;
    RwUInt16 numClusters;
    RxPipeline* pipeline;
    RwUInt32* inputToClusterSlot;
    RwUInt32* slotsContinue;
    RxPipelineCluster** slotClusterRefs;
    RxCluster clusters[1];
};

CHECKSIZE(RxPacket, 0x30, 0x58);
struct RxPipelineNodeTopSortData
{
    RwUInt32 numIns;
    RwUInt32 numInsVisited;
    rxReq* req;
};

CHECKSIZE(RxPipelineNodeTopSortData, 0xC, 0x10);
struct RxPipelineNode
{
    RxNodeDefinition* nodeDef;
    RwUInt32 numOutputs;
    RwUInt32* outputs;
    RxPipelineCluster** slotClusterRefs;
    RwUInt32* slotsContinue;
    void* privateData;
    RwUInt32* inputToClusterSlot;
    RxPipelineNodeTopSortData* topSortData;
    void* initializationData;
    RwUInt32 initializationDataSize;
};

CHECKSIZE(RxPipelineNode, 0x28, 0x50);
struct rxHeapSuperBlockDescriptor
{
    void* start;
    RwUInt32 size;
    rxHeapSuperBlockDescriptor* next;
};

CHECKSIZE(rxHeapSuperBlockDescriptor, 0xC, 0x18);
struct rxHeapFreeBlock
{
    RwUInt32 size;
    rxHeapBlockHeader* ptr;
};

CHECKSIZE(rxHeapFreeBlock, 0x8, 0x10);
struct RxHeap
{
    RwUInt32 superBlockSize;
    rxHeapSuperBlockDescriptor* head;
    rxHeapBlockHeader* headBlock;
    rxHeapFreeBlock* freeBlocks;
    RwUInt32 entriesAlloced;
    RwUInt32 entriesUsed;
    RwBool dirty;
};

CHECKSIZE(RxHeap, 0x1C, 0x30);
struct RxPipelineNodeParam
{
    void* dataParam;
    RxHeap* heap;
};

CHECKSIZE(RxPipelineNodeParam, 0x8, 0x10);
DECL_FASTCALL_SIMPLE_GLO(RxNodeDefinitionGetOpenGLSubmitNoLight, _Z38RxNodeDefinitionGetOpenGLSubmitNoLightv, RxNodeDefinition*);
DECL_FASTCALL_SIMPLE_GLO(RxNodeDefinitionGetOpenGLImmInstance, _Z36RxNodeDefinitionGetOpenGLImmInstancev, RxNodeDefinition*);
DECL_FASTCALL_SIMPLE_GLO(_rxPacketDestroy, _Z16_rxPacketDestroyP8RxPacket, void, RxPacket* packet);
DECL_FASTCALL_SIMPLE_GLO(RxClusterLockWrite, _Z18RxClusterLockWriteP8RxPacketjP14RxPipelineNode, RxCluster*, RxPacket* packet, RwUInt32 clusterIndex, RxPipelineNode* node);
DECL_FASTCALL_SIMPLE_GLO(RxPipelineSetFreeListCreateParams, _Z33RxPipelineSetFreeListCreateParamsii, void, RwInt32 blockSize, RwInt32 numBlocksToPrealloc);
DECL_FASTCALL_SIMPLE_GLO(RxClusterSetStride, _Z18RxClusterSetStrideP9RxClusteri, RxCluster*, RxCluster* cluster, RwInt32 stride);
DECL_FASTCALL_SIMPLE_GLO(_rxPipelineDestroy, _Z18_rxPipelineDestroyP10RxPipeline, void, RxPipeline* Pipeline);
DECL_FASTCALL_SIMPLE_GLO(RxPipelineNodeSendConfigMsg, _Z27RxPipelineNodeSendConfigMsgP14RxPipelineNodejjPv, RwUInt32, RxPipelineNode* dest, RwUInt32 msg, RwUInt32 intparam, void* ptrparam);
DECL_FASTCALL_SIMPLE_GLO(RxClusterDestroyData, _Z20RxClusterDestroyDataP9RxCluster, RxCluster*, RxCluster* cluster);
DECL_FASTCALL_SIMPLE_GLO(RxClusterGetAttributes, _Z22RxClusterGetAttributesP9RxCluster, RwUInt32, RxCluster* cluster);
DECL_FASTCALL_SIMPLE_GLO(RxPipelineCreate, _Z16RxPipelineCreatev, RxPipeline*);
DECL_FASTCALL_SIMPLE_GLO(RxClusterUnlock, _Z15RxClusterUnlockP9RxCluster, void, RxCluster* cluster);
DECL_FASTCALL_SIMPLE_GLO(RxClusterInitializeData, _Z23RxClusterInitializeDataP9RxClusterjt, RxCluster*, RxCluster* cluster, RwUInt32 numElements, RwUInt16 stride);
DECL_FASTCALL_SIMPLE_GLO(RxPipelineNodeGetPipelineCluster, _Z32RxPipelineNodeGetPipelineClusterP14RxPipelineNodej, RxPipelineCluster*, RxPipelineNode* node, RwUInt32 clustersOfInterestIndex);
DECL_FASTCALL_SIMPLE_GLO(RxClusterSetAttributes, _Z22RxClusterSetAttributesP9RxClusterj, RxCluster*, RxCluster* cluster, RwUInt32 attributes);
DECL_FASTCALL_SIMPLE_GLO(RxPipelineClusterGetCreationAttributes, _Z38RxPipelineClusterGetCreationAttributesP17RxPipelineCluster, RwUInt32, RxPipelineCluster* cluster);
DECL_FASTCALL_SIMPLE_GLO(RxPipelineClusterSetCreationAttributes, _Z38RxPipelineClusterSetCreationAttributesP17RxPipelineClusterj, RxPipelineCluster*, RxPipelineCluster* cluster, RwUInt32 creationAttributes);
DECL_FASTCALL_SIMPLE_GLO(RxClusterSetData, _Z16RxClusterSetDataP9RxClusterPvii, RxCluster*, RxCluster* cluster, void* data, RwInt32 stride, RwInt32 numElements);
DECL_FASTCALL_SIMPLE_GLO(RxPipelineExecute, _Z17RxPipelineExecuteP10RxPipelinePvi, RxPipeline*, RxPipeline* pipeline, void* data, RwBool heapReset);
DECL_FASTCALL_SIMPLE_GLO(RxHeapGetGlobalHeap, _Z19RxHeapGetGlobalHeapv, RxHeap*);
DECL_FASTCALL_SIMPLE_GLO(RxClusterResizeData, _Z19RxClusterResizeDataP9RxClusterj, RxCluster*, RxCluster* cluster, RwUInt32 numElements);
DECL_FASTCALL_SIMPLE_GLO(RxClusterSetExternalData, _Z24RxClusterSetExternalDataP9RxClusterPvii, RxCluster*, RxCluster* cluster, void* data, RwInt32 stride, RwInt32 numElements);
DECL_FASTCALL_SIMPLE_GLO(RxPipelineNodeForAllConnectedOutputs, _Z36RxPipelineNodeForAllConnectedOutputsP14RxPipelineNodeP10RxPipelinePFS0_S0_S0_PvES3_, RxPipelineNode*, RxPipelineNode* node, RxPipeline* pipeline, RxPipelineNodeOutputCallBack callbackfn, void* callbackdata);
DECL_FASTCALL_SIMPLE_GLO(RxLockedPipeAddPath, _Z19RxLockedPipeAddPathP10RxPipelinePjP14RxPipelineNode, RxPipeline*, RxPipeline* pipeline, RwUInt32* out, RxPipelineNode* in);
DECL_FASTCALL_SIMPLE_GLO(RxPipelineInsertDebugNode, _Z25RxPipelineInsertDebugNodeP10RxPipelineP14RxPipelineNodeS2_P16RxNodeDefinition, RxPipeline*, RxPipeline* pipeline, RxPipelineNode* before, RxPipelineNode* after, RxNodeDefinition* debugNodeDef);
DECL_FASTCALL_SIMPLE_GLO(RxLockedPipeDeleteNode, _Z22RxLockedPipeDeleteNodeP10RxPipelineP14RxPipelineNode, RxPipeline*, RxPipeline* pipeline, RxPipelineNode* node);
DECL_FASTCALL_SIMPLE_GLO(RxPipelineNodeFindOutputByIndex, _Z31RxPipelineNodeFindOutputByIndexP14RxPipelineNodej, RwUInt32*, RxPipelineNode* node, RwUInt32 outputindex);
DECL_FASTCALL_SIMPLE_GLO(RxLockedPipeDeletePath, _Z22RxLockedPipeDeletePathP10RxPipelinePjP14RxPipelineNode, RxPipeline*, RxPipeline* pipeline, RwUInt32* out, RxPipelineNode* in);
DECL_FASTCALL_SIMPLE_GLO(RxPipelineNodeRequestCluster, _Z28RxPipelineNodeRequestClusterP10RxPipelineP14RxPipelineNodeP19RxClusterDefinition, RxPipeline*, RxPipeline* pipeline, RxPipelineNode* node, RxClusterDefinition* clusterDef);
DECL_FASTCALL_SIMPLE_GLO(RxPipelineNodeGetInitData, _Z25RxPipelineNodeGetInitDataP14RxPipelineNode, void*, RxPipelineNode* node);
DECL_FASTCALL_SIMPLE_GLO(RxLockedPipeUnlock, _Z18RxLockedPipeUnlockP10RxPipeline, RxPipeline*, RxPipeline* pipeline);
DECL_FASTCALL_SIMPLE_GLO(RxPipelineNodeFindInput, _Z23RxPipelineNodeFindInputP14RxPipelineNode, RxPipelineNode*, RxPipelineNode* node);
DECL_FASTCALL_SIMPLE_GLO(RxPipelineFindNodeByIndex, _Z25RxPipelineFindNodeByIndexP10RxPipelinej, RxPipelineNode*, RxPipeline* pipeline, RwUInt32 nodeindex);
DECL_FASTCALL_SIMPLE_GLO(RxPipelineNodeCloneDefinition, _Z29RxPipelineNodeCloneDefinitionP14RxPipelineNodeP19RxClusterDefinition, RxNodeDefinition*, RxPipelineNode* node, RxClusterDefinition* cluster2add);
DECL_FASTCALL_SIMPLE_GLO(RxPipelineFindNodeByName, _Z24RxPipelineFindNodeByNameP10RxPipelinePKcP14RxPipelineNodePi, RxPipelineNode*, RxPipeline* pipeline, RwChar const* name, RxPipelineNode* start, RwInt32* nodeIndex);
DECL_FASTCALL_SIMPLE_GLO(RxPipelineNodeReplaceCluster, _Z28RxPipelineNodeReplaceClusterP10RxPipelineP14RxPipelineNodeP19RxClusterDefinitionS4_, RxPipeline*, RxPipeline* pipeline, RxPipelineNode* node, RxClusterDefinition* oldClusterDef, RxClusterDefinition* newClusterDef);
DECL_FASTCALL_SIMPLE_GLO(RxLockedPipeGetEntryPoint, _Z25RxLockedPipeGetEntryPointP10RxPipeline, RxPipelineNode*, RxPipeline* pipeline);
DECL_FASTCALL_SIMPLE_GLO(RxLockedPipeAddFragment, _Z23RxLockedPipeAddFragmentP10RxPipelinePjP16RxNodeDefinitionz, RxPipeline*, RxPipeline* pipeline, RwUInt32* firstIndex, RxNodeDefinition* nodeDef0, ...);
DECL_FASTCALL_SIMPLE_GLO(RxPipelineNodeCreateInitData, _Z28RxPipelineNodeCreateInitDataP14RxPipelineNodej, void*, RxPipelineNode* node, RwUInt32 size);
DECL_FASTCALL_SIMPLE_GLO(RxPipelineLock, _Z14RxPipelineLockP10RxPipeline, RxPipeline*, RxPipeline* pipeline);
DECL_FASTCALL_SIMPLE_GLO(RxLockedPipeReplaceNode, _Z23RxLockedPipeReplaceNodeP10RxPipelineP14RxPipelineNodeP16RxNodeDefinition, RxPipeline*, RxPipeline* pipeline, RxPipelineNode* node, RxNodeDefinition* nodeDef);
DECL_FASTCALL_SIMPLE_GLO(RxPipelineClone, _Z15RxPipelineCloneP10RxPipeline, RxPipeline*, RxPipeline* pipeline);
DECL_FASTCALL_SIMPLE_GLO(RxLockedPipeSetEntryPoint, _Z25RxLockedPipeSetEntryPointP10RxPipelineP14RxPipelineNode, RxPipeline*, RxPipeline* pipeline, RxPipelineNode* in);
DECL_FASTCALL_SIMPLE_GLO(RxPipelineNodeFindOutputByName, _Z30RxPipelineNodeFindOutputByNameP14RxPipelineNodePKc, RwUInt32*, RxPipelineNode* node, RwChar const* outputname);
DECL_FASTCALL_SIMPLE_GLO(RxHeapFree, _Z10RxHeapFreeP6RxHeapPv, void, RxHeap* heap, void* block);
DECL_FASTCALL_SIMPLE_GLO(RxHeapDestroy, _Z13RxHeapDestroyP6RxHeap, void, RxHeap* heap);
DECL_FASTCALL_SIMPLE_GLO(RxHeapAlloc, _Z11RxHeapAllocP6RxHeapj, void*, RxHeap* heap, RwUInt32 size);
DECL_FASTCALL_SIMPLE_GLO(RxHeapRealloc, _Z13RxHeapReallocP6RxHeapPvji, void*, RxHeap* heap, void* block, RwUInt32 newSize, RwBool allowCopy);
DECL_FASTCALL_SIMPLE_GLO(RxHeapCreate, _Z12RxHeapCreatej, RxHeap*, RwUInt32 size);
DECL_FASTCALL_SIMPLE_GLO(RxNodeDefinitionGetOpenGLAtomicAllInOne, _Z39RxNodeDefinitionGetOpenGLAtomicAllInOnev, RxNodeDefinition*);
DECL_FASTCALL_SIMPLE_GLO(RxNodeDefinitionGetOpenGLWorldSectorAllInOne, _Z44RxNodeDefinitionGetOpenGLWorldSectorAllInOnev, RxNodeDefinition*);

DECL_VALUE_PLT_I32_GLOBAL(_rxPipelineMaxNodes, BYBIT(0x67991C, 0x851258));

#endif // __AML_PSDK_RXPIPELINE_H
