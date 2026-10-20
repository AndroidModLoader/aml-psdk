#ifndef __AML_PSDK_SAAEMP3DECODER_H
#define __AML_PSDK_SAAEMP3DECODER_H

#include <aml-psdk/game_sa/audio/AEStreamingDecoder.h>

struct mpg123_handle_struct;

enum mpg123_version
{
    MPG123_1_0 = 0,
    MPG123_2_0 = 1,
    MPG123_2_5 = 2
};


enum mpg123_mode
{
    MPG123_M_STEREO = 0,
    MPG123_M_JOINT = 1,
    MPG123_M_DUAL = 2,
    MPG123_M_MONO = 3
};


enum mpg123_flags
{
    MPG123_CRC = 1,
    MPG123_COPYRIGHT = 2,
    MPG123_PRIVATE = 4,
    MPG123_ORIGINAL = 8
};


enum mpg123_vbr
{
    MPG123_CBR = 0,
    MPG123_VBR = 1,
    MPG123_ABR = 2
};


DECL_CLASS(mpg123_frameinfo)
    // Member values
    mpg123_version version;
    i32 layer;
    long rate;
    mpg123_mode mode;
    i32 mode_ext;
    i32 framesize;
    mpg123_flags flags;
    i32 emphasis;
    i32 bitrate;
    i32 abr_rate;
    mpg123_vbr vbr;
DECL_CLASS_END()
CHECKSIZE(mpg123_frameinfo, 0x2c, 0x30);

DECL_CLASS_BASED(CAEMP3Decoder, CAEStreamingDecoder)
    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CAEMP3Decoder, _ZN13CAEMP3DecoderC2EP13CAEDataStreamb, CAEDataStream* stream, bool enforceMinBuffer)
    DECL_CTORCALL_ARG_TAIL(stream, enforceMinBuffer)

    // Virtual functions
    DECL_VIRTUALCALL_HEAD(CAEMP3Decoder, Initialise, _ZTV13CAEMP3Decoder, 0, bool)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CAEMP3Decoder, FillBuffer, _ZTV13CAEMP3Decoder, 1, long, void* buffer, unsigned long size, i32* bytesRead)
    DECL_VIRTUALCALL_TAIL(buffer, size, bytesRead)
    DECL_VIRTUALCALL_HEAD(CAEMP3Decoder, GetStreamLengthMs, _ZTV13CAEMP3Decoder, 2, long)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CAEMP3Decoder, GetStreamPlayTimeMs, _ZTV13CAEMP3Decoder, 3, long)
    DECL_VIRTUALCALL_TAIL()
    DECL_VIRTUALCALL_HEAD(CAEMP3Decoder, SetCursor, _ZTV13CAEMP3Decoder, 4, void, unsigned long timeMs)
    DECL_VIRTUALCALL_TAIL(timeMs)
    DECL_VIRTUALCALL_HEAD(CAEMP3Decoder, GetSampleRate, _ZTV13CAEMP3Decoder, 5, long)
    DECL_VIRTUALCALL_TAIL()
    DECL_DTORCALL_VIRTUAL_SLOT(CAEMP3Decoder, _ZN13CAEMP3DecoderD2Ev, _ZN13CAEMP3Decoder, _ZTV13CAEMP3Decoder, 6);
    DECL_VIRTUALCALL_HEAD(CAEMP3Decoder, GetStreamID, _ZTV13CAEMP3Decoder, 8, i32)
    DECL_VIRTUALCALL_TAIL()

    // STATIC functions
    DECL_FASTCALL_SIMPLE(DecodeEntireFile, _ZN13CAEMP3Decoder16DecodeEntireFileEPhjPjS1_S1_S1_, void*, u8* data, u32 size, u32* decodedSize, u32* sampleRate, u32* channels, u32* encoding);

    // Member functions
    DECL_THISCALL_HEAD(Feed, _ZN13CAEMP3Decoder4FeedEj, u32, u32 size)
    DECL_THISCALL_TAIL(Feed, size)

    // Member values
    bool m_bInitialised;
    bool m_bEnforceMinLength;
    CAEDataStream* m_pStream;
    long rate;
    i32 channels;
    i32 encoding;
    i32 length;
    i32 streamedTime;
    i32 frameSize;
    mpg123_handle_struct* mh;
    mpg123_frameinfo mi;
    u8* dataBuffer;
DECL_CLASS_END()
CHECKSIZE(CAEMP3Decoder, 0x5c, 0x80);

#endif // __AML_PSDK_SAAEMP3DECODER_H
