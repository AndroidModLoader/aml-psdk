#ifndef __AML_PSDK_SAKEYGEN_H
#define __AML_PSDK_SAKEYGEN_H

#include <aml-psdk/game_sa/plugin.h>

DECL_CLASS(CKeyGen)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(GetKey1, _ZN7CKeyGen6GetKeyEPKci, u32, char const* str, i32 size);
    DECL_FASTCALL_SIMPLE(GetKey2, _ZN7CKeyGen6GetKeyEPKc, u32, char const* str);
    DECL_FASTCALL_SIMPLE(GetUppercaseKey, _ZN7CKeyGen15GetUppercaseKeyEPKc, u32, char const* str);
    DECL_FASTCALL_SIMPLE(AppendStringToKey, _ZN7CKeyGen17AppendStringToKeyEjPKc, u32, u32 key, char const* str);

    // Helper functions
    static u32 GetKey(char const* str, i32 size)
    {
        return GetKey1(str, size);
    }
    static u32 GetKey(char const* str)
    {
        return GetKey2(str);
    }

    // STATIC values
    DECL_OBJECT_ARRAY_PLT(u32, keyTable, BYBIT(0x678CAC, 0x84F980));
DECL_CLASS_END()

#define keyTable keyTable()

#endif // __AML_PSDK_SAKEYGEN_H
