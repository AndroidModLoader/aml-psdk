#ifndef __AML_PSDK_SAREFERENCES_H
#define __AML_PSDK_SAREFERENCES_H

/*
    Plugin-SDK (Grand Theft Auto San Andreas) header file
    Authors: GTA Community. See more here
    https://github.com/DK22Pac/plugin-sdk
    Do not delete this comment block. Respect others' work!
*/

#include "../plugin.h"

struct CEntity;

struct CReference
{
    CReference *m_pNext;
    void **m_ppEntity;
};
CHECKSIZE(CReference, 0x8, 0x10);

DECL_CLASS(CReferences)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(Init, _ZN11CReferences4InitEv, void);
    DECL_FASTCALL_SIMPLE(ListSize, _ZN11CReferences8ListSizeEP10CReference, i32, CReference* list);
    DECL_FASTCALL_SIMPLE(RemoveReferencesToPlayer, _ZN11CReferences24RemoveReferencesToPlayerEv, void);
    DECL_FASTCALL_SIMPLE(PruneAllReferencesInWorld, _ZN11CReferences25PruneAllReferencesInWorldEv, void);

    // STATIC values
    DECL_OBJECT_PLT(CReference*, pEmptyList, BYBIT(0x676DCC, 0x84BBE0));
    DECL_OBJECT_ARRAY_PLT(CReference, aRefs, BYBIT(0x679020, 0x850068));
DECL_CLASS_END()

#define pEmptyList pEmptyList()
#define aRefs aRefs()

#endif // __AML_PSDK_SAREFERENCES_H
