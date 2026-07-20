#ifndef __AML_PSDK_RXPIPELINE_H
#define __AML_PSDK_RXPIPELINE_H

#include <aml-psdk/sdk_base.h>
#include "RwBase.h"

/* The pipeline internals are never touched from a mod -- every field below
 * that refers to them is a pointer, so a forward declaration is enough and
 * the layout stays correct on both ABIs. */
struct RxPipelineNode;
struct RxPacket;
struct RxPipelineRequiresCluster;

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

#endif // __AML_PSDK_RXPIPELINE_H
