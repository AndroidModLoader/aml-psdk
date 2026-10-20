#ifndef __AML_PSDK_SAAESTREAMTRANSFORMER_H
#define __AML_PSDK_SAAESTREAMTRANSFORMER_H

#include <aml-psdk/game_sa/plugin.h>

DECL_CLASS(CAEStreamTransformer)
    // Member functions
    DECL_THISCALL_HEAD(TransformBuffer, _ZN20CAEStreamTransformer15TransformBufferEPvmm, void, void* buffer, unsigned long size, unsigned long position)
    DECL_THISCALL_TAIL(TransformBuffer, buffer, size, position)
    DECL_THISCALL_SIMPLE(Initialise, _ZN20CAEStreamTransformer10InitialiseEv, void);

    // Member values
    u8 key[16];
DECL_CLASS_END()
CHECKSIZE(CAEStreamTransformer, 0x10, 0x10);

#endif // __AML_PSDK_SAAESTREAMTRANSFORMER_H
