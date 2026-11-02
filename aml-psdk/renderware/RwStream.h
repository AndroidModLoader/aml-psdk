#ifndef __AML_PSDK_RWSTREAM_H
#define __AML_PSDK_RWSTREAM_H

#include <aml-psdk/sdk_base.h>
#include "RwVector.h"

enum RwStreamType : RwInt32
{
    rwNASTREAM = 0x0,
    rwSTREAMFILE = 0x1,
    rwSTREAMFILENAME = 0x2,
    rwSTREAMMEMORY = 0x3,
    rwSTREAMCUSTOM = 0x4,
};

enum RwStreamAccessType : RwInt32
{
    rwNASTREAMACCESS = 0x0,
    rwSTREAMREAD = 0x1,
    rwSTREAMWRITE = 0x2,
    rwSTREAMAPPEND = 0x3,
};

typedef RwBool (*rwCustomStreamFnClose)(void *);
typedef RwUInt32 (*rwCustomStreamFnRead)(void *, void *, RwUInt32);
typedef RwBool (*rwCustomStreamFnWrite)(void *, const void *, RwUInt32);
typedef RwBool (*rwCustomStreamFnSkip)(void *, RwUInt32);
struct RwStreamMemory
{
    RwUInt32 position;
    RwUInt32 nSize;
    RwUInt8 *memBlock;
};
union RwStreamFile
{
    void *fpFile;
    const void *constfpFile;
};
struct RwStreamCustom
{
    rwCustomStreamFnClose sfnclose;
    rwCustomStreamFnRead sfnread;
    rwCustomStreamFnWrite sfnwrite;
    rwCustomStreamFnSkip sfnskip;
    void *data;
};
union RwStreamUnion
{
    RwStreamMemory memory;
    RwStreamFile file;
    RwStreamCustom custom;
};

struct RwChunkHeaderInfo
{
    RwUInt32 type;
    RwUInt32 length;
    RwUInt32 version;
    RwUInt32 buildNum;
    RwBool isComplex;
};



struct RwStream
{
    RwStreamType type;
    RwStreamAccessType accessType;
    RwInt32 position;
    RwStreamUnion Type;
    RwBool rwOwned;
};



DECL_FASTCALL_SIMPLE_GLO(RwStreamClose, _Z13RwStreamCloseP8RwStreamPv, RwBool, RwStream *stream, void *pData);
DECL_FASTCALL_SIMPLE_GLO(RwStreamFindChunk, _Z17RwStreamFindChunkP8RwStreamjPjS1_, RwBool, RwStream *stream, RwUInt32 type, RwUInt32 *lengthOut, RwUInt32 *versionOut);
DECL_FASTCALL_SIMPLE_GLO(RwStreamOpen, _Z12RwStreamOpen12RwStreamType18RwStreamAccessTypePKv, RwStream*, RwStreamType type, RwStreamAccessType accessType, const void *pData);
DECL_FASTCALL_SIMPLE_GLO(RwStreamRead, _Z12RwStreamReadP8RwStreamPvj, RwUInt32, RwStream *stream, void *buffer, RwUInt32 length);
DECL_FASTCALL_SIMPLE_GLO(RwStreamReadChunkHeaderInfo, _Z27RwStreamReadChunkHeaderInfoP8RwStreamP17RwChunkHeaderInfo, RwStream*, RwStream *stream, RwChunkHeaderInfo *chunkHeaderInfo);
DECL_FASTCALL_SIMPLE_GLO(RwStreamReadInt16, _Z17RwStreamReadInt16P8RwStreamPsj, RwStream*, RwStream *stream, RwInt16 *ints, RwUInt32 numBytes);
DECL_FASTCALL_SIMPLE_GLO(RwStreamReadInt32, _Z17RwStreamReadInt32P8RwStreamPij, RwStream*, RwStream *stream, RwInt32 *ints, RwUInt32 numBytes);
DECL_FASTCALL_SIMPLE_GLO(RwStreamReadReal, _Z16RwStreamReadRealP8RwStreamPfj, RwStream*, RwStream *stream, RwReal *reals, RwUInt32 numBytes);
DECL_FASTCALL_SIMPLE_GLO(RwStreamSetFreeListCreateParams, _Z31RwStreamSetFreeListCreateParamsii, void, RwInt32 blockSize, RwInt32 numBlocksToPrealloc);
DECL_FASTCALL_SIMPLE_GLO(RwStreamSkip, _Z12RwStreamSkipP8RwStreamj, RwStream*, RwStream *stream, RwUInt32 offset);
DECL_FASTCALL_SIMPLE_GLO(RwStreamWrite, _Z13RwStreamWriteP8RwStreamPKvj, RwStream*, RwStream *stream, const void *buffer, RwUInt32 length);
DECL_FASTCALL_SIMPLE_GLO(RwStreamWriteInt16, _Z18RwStreamWriteInt16P8RwStreamPKsj, RwStream*, RwStream *stream, const RwInt16 *ints, RwUInt32 numBytes);
DECL_FASTCALL_SIMPLE_GLO(RwStreamWriteInt32, _Z18RwStreamWriteInt32P8RwStreamPKij, RwStream*, RwStream *stream, const RwInt32 *ints, RwUInt32 numBytes);
DECL_FASTCALL_SIMPLE_GLO(RwStreamWriteReal, _Z17RwStreamWriteRealP8RwStreamPKfj, RwStream*, RwStream *stream, const RwReal *reals, RwUInt32 numBytes);

struct RwMemory
{
    RwUInt8* start;
    RwUInt32 length;
};
CHECKSIZE(RwMemory, 0x8, 0x10);
CHECKSIZE(RwStreamMemory, 0xC, 0x10);
CHECKSIZE(RwStreamCustom, 0x14, 0x28);
CHECKSIZE(RwStreamUnion, 0x14, 0x28);
CHECKSIZE(RwStream, 0x24, 0x40);
CHECKSIZE(RwChunkHeaderInfo, 0x14, 0x14);

DECL_FASTCALL_SIMPLE_GLO(_rwStreamInitialize, _Z19_rwStreamInitializeP8RwStreami12RwStreamType18RwStreamAccessTypePKv, RwStream*, RwStream* stream, RwBool owned, RwStreamType type, RwStreamAccessType accessType, void const* data);
DECL_FASTCALL_SIMPLE_GLO(_rwStreamWriteVersionedChunkHeader, _Z34_rwStreamWriteVersionedChunkHeaderP8RwStreamiijj, RwStream*, RwStream* stream, RwInt32 type, RwInt32 size, RwUInt32 version, RwUInt32 buildNum);
DECL_FASTCALL_SIMPLE_GLO(_rwStreamReadChunkHeader, _Z24_rwStreamReadChunkHeaderP8RwStreamPjS1_S1_S1_, RwBool, RwStream* stream, RwUInt32* type, RwUInt32* length, RwUInt32* version, RwUInt32* buildNum);
DECL_FASTCALL_SIMPLE_GLO(RwMemLittleEndian16, _Z19RwMemLittleEndian16Pvj, void*, void* memory, RwUInt32 size);
DECL_FASTCALL_SIMPLE_GLO(RwMemLittleEndian32, _Z19RwMemLittleEndian32Pvj, void*, void* memory, RwUInt32 size);
DECL_FASTCALL_SIMPLE_GLO(RwMemNative16, _Z13RwMemNative16Pvj, void*, void* memory, RwUInt32 size);
DECL_FASTCALL_SIMPLE_GLO(RwMemNative32, _Z13RwMemNative32Pvj, void*, void* memory, RwUInt32 size);
DECL_FASTCALL_SIMPLE_GLO(RwMemRealToFloat32, _Z18RwMemRealToFloat32Pvj, void*, void* memory, RwUInt32 size);
DECL_FASTCALL_SIMPLE_GLO(RwMemFloat32ToReal, _Z18RwMemFloat32ToRealPvj, void*, void* memory, RwUInt32 size);

#ifdef GTAVC
inline RwStream* RwStreamWriteChunkHeader(RwStream* stream, RwInt32 type, RwInt32 size)
{
    return _rwStreamWriteVersionedChunkHeader(stream, type, size, 0x34005, 0xFFFF);
}
#endif

#endif // __AML_PSDK_RWSTREAM_H
