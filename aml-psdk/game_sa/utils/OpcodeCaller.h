#ifndef __AML_PSDK_SAOPCODECALLER_H
#define __AML_PSDK_SAOPCODECALLER_H

#include <aml-psdk/game_sa/engine/RunningScript.h>
#include <stddef.h>
#include "OpcodeCallerIDs.h"

struct ZeroArg {};

struct OpcodeCaller
{
    OpcodeCaller()
    {
        ResetScript();
    }

    static inline void ResetScript()
    {
        memset(&g_Script, 0, sizeof(g_Script));
        strcpy(g_Script.m_szName, "amlpsdk");
        g_Script.m_pBaseIP = g_Script.m_pCurrentIP = g_ScriptBuffer;
        
        // CRunningScript::Init
        g_Script.m_nScriptBrainType = -1;
        g_Script.m_bWastedBustedCheck = true;
    }

    static inline void ResetCommand()
    {
        g_Script.m_pNext = g_Script.m_pPrev = NULL;
        strcpy(g_Script.m_szName, "amlpsdk");
        g_Script.m_pBaseIP = g_Script.m_pCurrentIP = g_ScriptBuffer;
        g_Script.m_nSP = 0;
        memset((u8*)&g_Script + offsetof(CRunningScript, m_anTimers), 0, sizeof(g_Script) - offsetof(CRunningScript, m_anTimers));
        g_Script.m_nScriptBrainType = -1;
        g_Script.m_bWastedBustedCheck = true;
    }

    __attribute__((always_inline)) static inline bool ReserveBuffer(uint16_t size, uint16_t& bufferPos, bool& bufferError)
    {
        if(bufferError) return false;
        if(size > sizeof(g_ScriptBuffer) || bufferPos > sizeof(g_ScriptBuffer) - size)
        {
            bufferError = true;
            return false;
        }
        return true;
    }

    __attribute__((always_inline)) static inline void PushVarToBuffer(ZeroArg, uint16_t& bufferPos, uint8_t&, bool& bufferError)
    {
        if(!ReserveBuffer(1, bufferPos, bufferError)) return;
        g_ScriptBuffer[bufferPos++] = 0x00;
    }
    __attribute__((always_inline)) static inline void PushVarToBuffer(int v, uint16_t& bufferPos, uint8_t&, bool& bufferError)
    {
        if(__builtin_constant_p(v) && v >= -128 && v <= 127)
        {
            if(!ReserveBuffer(2, bufferPos, bufferError)) return;
            g_ScriptBuffer[bufferPos++] = 0x04;
            g_ScriptBuffer[bufferPos++] = (int8_t)v;
            return;
        }
        if(__builtin_constant_p(v) && v >= -32768 && v <= 32767)
        {
            if(!ReserveBuffer(3, bufferPos, bufferError)) return;
            int16_t value = v;
            g_ScriptBuffer[bufferPos++] = 0x05;
            memcpy(&g_ScriptBuffer[bufferPos], &value, 2);
            bufferPos += 2;
            return;
        }
        if(!ReserveBuffer(5, bufferPos, bufferError)) return;
        g_ScriptBuffer[bufferPos] = 0x01;
        memcpy(&g_ScriptBuffer[++bufferPos], &v, 4);
        bufferPos += 4;
    }
    __attribute__((always_inline)) static inline void PushVarToBuffer(unsigned int v, uint16_t& bufferPos, uint8_t& varsCount, bool& bufferError)
    {
        if(__builtin_constant_p(v) && v <= 32767)
        {
            PushVarToBuffer((int)v, bufferPos, varsCount, bufferError);
            return;
        }
        if(!ReserveBuffer(5, bufferPos, bufferError)) return;
        g_ScriptBuffer[bufferPos] = 0x01;
        memcpy(&g_ScriptBuffer[++bufferPos], &v, 4);
        bufferPos += 4;
    }
    __attribute__((always_inline)) static inline void PushVarToBuffer(float v, uint16_t& bufferPos, uint8_t&, bool& bufferError)
    {
        if(!ReserveBuffer(5, bufferPos, bufferError)) return;
        g_ScriptBuffer[bufferPos] = 0x06;
        memcpy(&g_ScriptBuffer[++bufferPos], &v, 4);
        bufferPos += 4;
    }
    __attribute__((always_inline)) static inline void PushVarToBuffer(double v, uint16_t& bufferPos, uint8_t& varsCount, bool& bufferError)
    {
        PushVarToBuffer((float)v, bufferPos, varsCount, bufferError);
    }
    __attribute__((always_inline)) static inline void PushVarToBuffer(const char* s, uint16_t& bufferPos, uint8_t&, bool& bufferError)
    {
        if(bufferError) return;
        if(!s)
        {
            bufferError = true;
            return;
        }
        size_t aLen = strnlen(s, 128);
        if(aLen == 128)
        {
            bufferError = true;
            return;
        }
        if(!ReserveBuffer(aLen + 2, bufferPos, bufferError)) return;
        g_ScriptBuffer[bufferPos] = 0x0E;
        g_ScriptBuffer[++bufferPos] = aLen;
        memcpy(&g_ScriptBuffer[++bufferPos], s, aLen);
        bufferPos += aLen;
    }
    __attribute__((always_inline)) static inline void PushVariable(void *v, uint16_t& bufferPos, uint8_t& varsCount, bool& bufferError)
    {
        if(bufferError) return;
        if(!v || varsCount >= sizeof(g_ScriptVarPointers) / sizeof(g_ScriptVarPointers[0]))
        {
            bufferError = true;
            return;
        }
        if(!ReserveBuffer(3, bufferPos, bufferError)) return;
        g_ScriptBuffer[bufferPos] = 0x03;
        g_ScriptVarPointers[varsCount] = (uint32_t*)v;
        memcpy(&g_Script.m_aLocalVars[varsCount], v, 4);
        uint16_t varIndex = varsCount;
        memcpy(&g_ScriptBuffer[++bufferPos], &varIndex, 2);
        bufferPos += 2;
        ++varsCount;
    }
    __attribute__((always_inline)) static inline void PushVarToBuffer(int *v, uint16_t& bufferPos, uint8_t& varsCount, bool& bufferError)
    {
        PushVariable(v, bufferPos, varsCount, bufferError);
    }
    __attribute__((always_inline)) static inline void PushVarToBuffer(unsigned int *v, uint16_t& bufferPos, uint8_t& varsCount, bool& bufferError)
    {
        PushVariable(v, bufferPos, varsCount, bufferError);
    }
    __attribute__((always_inline)) static inline void PushVarToBuffer(float *v, uint16_t& bufferPos, uint8_t& varsCount, bool& bufferError)
    {
        PushVariable(v, bufferPos, varsCount, bufferError);
    }

    static inline bool ReserveBuffer(uint16_t size) { return ReserveBuffer(size, g_nBufferPos, g_bBufferError); }
    static inline void PushVarToBuffer(ZeroArg v) { PushVarToBuffer(v, g_nBufferPos, g_nVarsCount, g_bBufferError); }
    static inline void PushVarToBuffer(int v) { PushVarToBuffer(v, g_nBufferPos, g_nVarsCount, g_bBufferError); }
    static inline void PushVarToBuffer(unsigned int v) { PushVarToBuffer(v, g_nBufferPos, g_nVarsCount, g_bBufferError); }
    static inline void PushVarToBuffer(float v) { PushVarToBuffer(v, g_nBufferPos, g_nVarsCount, g_bBufferError); }
    static inline void PushVarToBuffer(double v) { PushVarToBuffer(v, g_nBufferPos, g_nVarsCount, g_bBufferError); }
    static inline void PushVarToBuffer(const char* s) { PushVarToBuffer(s, g_nBufferPos, g_nVarsCount, g_bBufferError); }
    static inline void PushVariable(void *v) { PushVariable(v, g_nBufferPos, g_nVarsCount, g_bBufferError); }
    static inline void PushVarToBuffer(int *v) { PushVariable(v); }
    static inline void PushVarToBuffer(unsigned int *v) { PushVariable(v); }
    static inline void PushVarToBuffer(float *v) { PushVariable(v); }

    template<typename T>
    static inline void ReadVarFromScript(T, uint8_t&) {}

    static inline void ReadVariable(void *v, uint8_t& index)
    {
        memcpy(v, &g_Script.m_aLocalVars[index++], 4);
    }
    static inline void ReadVarFromScript(int *v, uint8_t& index) { ReadVariable(v, index); }
    static inline void ReadVarFromScript(unsigned int *v, uint8_t& index) { ReadVariable(v, index); }
    static inline void ReadVarFromScript(float *v, uint8_t& index) { ReadVariable(v, index); }

    static inline CRunningScript g_Script { 0 };
    static inline uint8_t g_ScriptBuffer[512] { 0 };
    static inline u32* g_ScriptVarPointers[40] { NULL };
    static inline uint16_t g_nBufferPos = 0;
    static inline uint8_t g_nVarsCount = 0;
    static inline bool g_bBufferError = false;
    static inline uint32_t g_nCallDepth = 0;
    static inline uint32_t g_nBatchDepth = 0;
    static inline tScriptParam* g_pScriptParams = NULL;
    static inline tScriptParam g_SavedScriptParams[32] { { 0 } };
};
inline OpcodeCaller g_OpcodeCallerStub;

inline void PushVars() {}

template <typename T>
inline void PushVars(T arg)
{
    OpcodeCaller::PushVarToBuffer(arg);
}
template <typename A1, typename... Args>
inline void PushVars(A1 arg, Args... args)
{
    PushVars(arg);
    PushVars(args...);
}

template<typename... ArgTypes>
__attribute__((always_inline)) inline bool CommandByIDDirect(uint16_t opcode, ArgTypes... args)
{
    ++OpcodeCaller::g_nCallDepth;
    OpcodeCaller::ResetCommand();
    memcpy(OpcodeCaller::g_ScriptBuffer, &opcode, 2);
    uint16_t bufferPos = 2;
    uint8_t varsCount = 0;
    bool bufferError = false;
    (OpcodeCaller::PushVarToBuffer(args, bufferPos, varsCount, bufferError), ...);
    OpcodeCaller::g_nBufferPos = bufferPos;
    OpcodeCaller::g_nVarsCount = varsCount;
    OpcodeCaller::g_bBufferError = bufferError;

    bool result = false;
    if(!bufferError)
    {
        if(!OpcodeCaller::g_pScriptParams)
        {
            OpcodeCaller::g_pScriptParams = GetMainLibrarySymbol<tScriptParam*>("ScriptParams");
        }
        tScriptParam* pScriptParams = OpcodeCaller::g_pScriptParams;
        if(pScriptParams)
        {
            bool saveParams = !OpcodeCaller::g_nBatchDepth || OpcodeCaller::g_nCallDepth > 1;
            if(saveParams) memcpy(OpcodeCaller::g_SavedScriptParams, pScriptParams, sizeof(OpcodeCaller::g_SavedScriptParams));
            OpcodeCaller::g_Script.ProcessOneCommand();
            if(saveParams) memcpy(pScriptParams, OpcodeCaller::g_SavedScriptParams, sizeof(OpcodeCaller::g_SavedScriptParams));
            uint8_t outputIndex = 0;
            (OpcodeCaller::ReadVarFromScript(args, outputIndex), ...);
            result = OpcodeCaller::g_Script.m_bCondResult;
        }
    }

    --OpcodeCaller::g_nCallDepth;
    return result;
}

template<typename... ArgTypes>
__attribute__((noinline, cold)) inline bool CommandByIDNested(uint16_t opcode, ArgTypes... args)
{
    CRunningScript savedScript;
    uint8_t savedBuffer[sizeof(OpcodeCaller::g_ScriptBuffer)];
    u32* savedVarPointers[40];
    tScriptParam savedScriptParams[32];
    uint16_t savedBufferPos = OpcodeCaller::g_nBufferPos;
    uint8_t savedVarsCount = OpcodeCaller::g_nVarsCount;
    bool savedBufferError = OpcodeCaller::g_bBufferError;
    memcpy(&savedScript, &OpcodeCaller::g_Script, sizeof(savedScript));
    memcpy(savedBuffer, OpcodeCaller::g_ScriptBuffer, sizeof(savedBuffer));
    memcpy(savedVarPointers, OpcodeCaller::g_ScriptVarPointers, sizeof(savedVarPointers));
    memcpy(savedScriptParams, OpcodeCaller::g_SavedScriptParams, sizeof(savedScriptParams));

    bool result = CommandByIDDirect(opcode, args...);

    memcpy(&OpcodeCaller::g_Script, &savedScript, sizeof(savedScript));
    memcpy(OpcodeCaller::g_ScriptBuffer, savedBuffer, sizeof(savedBuffer));
    memcpy(OpcodeCaller::g_ScriptVarPointers, savedVarPointers, sizeof(savedVarPointers));
    memcpy(OpcodeCaller::g_SavedScriptParams, savedScriptParams, sizeof(savedScriptParams));
    OpcodeCaller::g_nBufferPos = savedBufferPos;
    OpcodeCaller::g_nVarsCount = savedVarsCount;
    OpcodeCaller::g_bBufferError = savedBufferError;
    return result;
}

template<typename... ArgTypes>
inline bool CommandByID(uint16_t opcode, ArgTypes... args)
{
    if(OpcodeCaller::g_nCallDepth) return CommandByIDNested(opcode, args...);
    return CommandByIDDirect(opcode, args...);
}

template <uint16_t CommandID, typename... ArgTypes>
inline bool Command(ArgTypes... arguments)
{
    return CommandByID(CommandID, arguments...);
}

template<typename Fn>
inline void CommandBatch(Fn fn)
{
    if(OpcodeCaller::g_nCallDepth || OpcodeCaller::g_nBatchDepth)
    {
        fn();
        return;
    }
    if(!OpcodeCaller::g_pScriptParams)
    {
        OpcodeCaller::g_pScriptParams = GetMainLibrarySymbol<tScriptParam*>("ScriptParams");
    }
    if(!OpcodeCaller::g_pScriptParams)
    {
        fn();
        return;
    }

    struct BatchState
    {
        tScriptParam* params;
        tScriptParam savedParams[32];

        BatchState(tScriptParam* pParams) : params(pParams)
        {
            memcpy(savedParams, params, sizeof(savedParams));
            ++OpcodeCaller::g_nBatchDepth;
        }
        ~BatchState()
        {
            --OpcodeCaller::g_nBatchDepth;
            memcpy(params, savedParams, sizeof(savedParams));
        }
    };
    BatchState state(OpcodeCaller::g_pScriptParams);
    fn();
}

#endif // __AML_PSDK_SAOPCODECALLER_H
