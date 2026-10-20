#ifndef __AML_PSDK_SAAEWAVEDECODER_H
#define __AML_PSDK_SAAEWAVEDECODER_H

#include <aml-psdk/game_sa/audio/AEStreamingDecoder.h>

DECL_CLASS(WaveHeader)
    // Member values
    u8 RIFF[4];
    u32 dwRiffSize;
    u8 WAVE[4];
    u8 fmt_[4];
    u32 dwFmtSize;
    u16 wCompression;
    u16 wChnls;
    u32 dwSRate;
    u32 BytesPerSec;
    u16 wBlkAlign;
    u16 BitsPerSample;
    u8 DATA[4];
    u32 dwDataSize;
DECL_CLASS_END()
CHECKSIZE(WaveHeader, 0x2c, 0x2c);

DECL_CLASS_BASED(CAEWaveDecoder, CAEStreamingDecoder)
    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CAEWaveDecoder, _ZN14CAEWaveDecoderC2EP13CAEDataStream, CAEDataStream* stream)
    DECL_CTORCALL_ARG_TAIL(stream)

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(CAEWaveDecoder, Initialise, _ZTV14CAEWaveDecoder, 0, bool)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CAEWaveDecoder, FillBuffer, _ZTV14CAEWaveDecoder, 1, long, void* buffer, unsigned long size, i32* bytesRead)
    DECL_VIRTUALCALL_TAIL(buffer, size, bytesRead)
    DECL_VIRTUALCALL_HEAD(CAEWaveDecoder, GetStreamLengthMs, _ZTV14CAEWaveDecoder, 2, long)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CAEWaveDecoder, GetStreamPlayTimeMs, _ZTV14CAEWaveDecoder, 3, long)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CAEWaveDecoder, SetCursor, _ZTV14CAEWaveDecoder, 4, void, unsigned long timeMs)
    DECL_VIRTUALCALL_TAIL(timeMs)
    DECL_VIRTUALCALL_HEAD(CAEWaveDecoder, GetSampleRate, _ZTV14CAEWaveDecoder, 5, long)
    DECL_VIRTUALCALL_TAIL()
    DECL_DTORCALL_VIRTUAL_SLOT(CAEWaveDecoder, _ZN14CAEWaveDecoderD2Ev, _ZN14CAEWaveDecoder, _ZTV14CAEWaveDecoder, 6);
    DECL_VIRTUALCALL_HEAD(CAEWaveDecoder, GetStreamID, _ZTV14CAEWaveDecoder, 8, i32)
    DECL_VIRTUALCALL_TAIL()

    // Member values
    bool m_bInitialised;
    CAEDataStream* m_pStream;
    WaveHeader m_header;
DECL_CLASS_END()
CHECKSIZE(CAEWaveDecoder, 0x3c, 0x50);

#endif // __AML_PSDK_SAAEWAVEDECODER_H
