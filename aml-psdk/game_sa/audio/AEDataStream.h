#ifndef __AML_PSDK_SAAEDATASTREAM_H
#define __AML_PSDK_SAAEDATASTREAM_H

#include "AudioEngine.h"
#include "../engine/OS.h"
#include <cstddef>

DECL_CLASS(tStream)

    // Member values
    unsigned int NumBytes;
    unsigned short Frequency;
    short Headroom;
DECL_CLASS_END()
CHECKSIZE(tStream, 0x8, 0x8);

DECL_CLASS(tTrackHeader)

    // Member values
    tBeatInfoBeat BeatInfoList[1000];
    tStream Streams[8];
    short NumStreams;
DECL_CLASS_END()
CHECKSIZE(tTrackHeader, 0x1F84, 0x1F84);

DECL_CLASS(CAEDataStream)
    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CAEDataStream, _ZN13CAEDataStreamC2EiPciib, int ID, char* file, int start, int size, bool encrypted)
    DECL_CTORCALL_ARG_TAIL(ID, file, start, size, encrypted)
    DECL_DTORCALL(CAEDataStream, _ZN13CAEDataStreamD2Ev);

    // Member functions
    DECL_THISCALL_HEAD(FillBuffer, BYBIT(_ZN13CAEDataStream10FillBufferEPvj, _ZN13CAEDataStream10FillBufferEPvm), size_t, void* dest, size_t destSize)
    DECL_THISCALL_TAIL(FillBuffer, dest, destSize)
    DECL_THISCALL_SIMPLE(GetCurrentPosition, _ZN13CAEDataStream18GetCurrentPositionEv, long int);
    DECL_THISCALL_HEAD(Seek, _ZN13CAEDataStream4SeekEli, int, long int pos, int whence)
    DECL_THISCALL_TAIL(Seek, pos, whence)
    DECL_THISCALL_SIMPLE(Close, _ZN13CAEDataStream5CloseEv, int);
    DECL_THISCALL_SIMPLE(Initialise, _ZN13CAEDataStream10InitialiseEv, bool);

    // Member values
    tTrackHeader* m_pHeader;
    OSFile m_File;
    char* m_pFileName;
    bool m_bInitialised;
    unsigned int m_cur;
    unsigned int m_start;
    unsigned int m_size;
    int m_ID;
    bool m_bEncrypted;
    long int m_cRefs;
DECL_CLASS_END()
CHECKSIZE(CAEDataStream, 0x28, 0x38);

#endif // __AML_PSDK_SAAEDATASTREAM_H
