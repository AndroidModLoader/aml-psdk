#ifndef __AML_PSDK_SAAESTREAMINGDECODER_H
#define __AML_PSDK_SAAESTREAMINGDECODER_H

#include <aml-psdk/game_sa/audio/AEDataStream.h>

DECL_CLASS(CAEStreamingDecoder)
    // Construct/Deconstruct functions
    DECL_CTORCALL_ARG_HEAD(CAEStreamingDecoder, _ZN19CAEStreamingDecoderC2EP13CAEDataStream, CAEDataStream* stream)
    DECL_CTORCALL_ARG_TAIL(stream)

    // Virtual functions
    virtual bool Initialise() = 0;
    virtual long FillBuffer(void* buffer, unsigned long size, i32* bytesRead) = 0;
    virtual long GetStreamLengthMs() = 0;
    virtual long GetStreamPlayTimeMs() = 0;
    virtual void SetCursor(unsigned long timeMs) = 0;
    virtual long GetSampleRate() = 0;
    DECL_DTORCALL_VIRTUAL_SLOT(CAEStreamingDecoder, _ZN19CAEStreamingDecoderD2Ev, _ZN19CAEStreamingDecoder, _ZTV19CAEStreamingDecoder, 6);
    virtual i32 GetStreamID() = 0;
    DECL_VIRTUALCALL_HEAD(CAEStreamingDecoder, GetHeader, _ZTV19CAEStreamingDecoder, 9, void*)
    DECL_VIRTUALCALL_TAIL()

    // Member values
    CAEDataStream* m_pStream;
DECL_CLASS_END()
CHECKSIZE(CAEStreamingDecoder, 0x8, 0x10);

#endif // __AML_PSDK_SAAESTREAMINGDECODER_H
