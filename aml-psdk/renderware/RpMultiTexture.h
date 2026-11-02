#ifndef __AML_PSDK_RPMULTITEXTURE_H
#define __AML_PSDK_RPMULTITEXTURE_H

#include "RpMaterial.h"

struct RpMTEffectDict;

typedef RpMTEffect* (*RpMTEffectCallBack)(RpMTEffect* effect, void* data);
typedef RpMTEffectDict* (*RpMTEffectDictCallBack)(RpMTEffectDict* dict, void* data);

DECL_FASTCALL_SIMPLE_GLO(RpMultiTextureGetNumTextures, _Z28RpMultiTextureGetNumTexturesPK14RpMultiTexture, RwUInt32, RpMultiTexture const* multiTexture);
DECL_FASTCALL_SIMPLE_GLO(RpMultiTextureGetTexture, _Z24RpMultiTextureGetTexturePK14RpMultiTexturej, RwTexture*, RpMultiTexture const* multiTexture, RwUInt32 index);
DECL_FASTCALL_SIMPLE_GLO(RpMultiTextureSetTexture, _Z24RpMultiTextureSetTextureP14RpMultiTexturejP9RwTexture, RpMultiTexture*, RpMultiTexture* multiTexture, RwUInt32 index, RwTexture* texture);
DECL_FASTCALL_SIMPLE_GLO(RpMultiTextureGetCoords, _Z23RpMultiTextureGetCoordsPK14RpMultiTexturej, RwUInt32, RpMultiTexture const* multiTexture, RwUInt32 index);
DECL_FASTCALL_SIMPLE_GLO(RpMultiTextureSetCoords, _Z23RpMultiTextureSetCoordsP14RpMultiTexturejj, RpMultiTexture*, RpMultiTexture* multiTexture, RwUInt32 index, RwUInt32 texCoordIndex);
DECL_FASTCALL_SIMPLE_GLO(RpMultiTextureGetEffect, _Z23RpMultiTextureGetEffectPK14RpMultiTexture, RpMTEffect*, RpMultiTexture const* multiTexture);
DECL_FASTCALL_SIMPLE_GLO(RpMultiTextureSetEffect, _Z23RpMultiTextureSetEffectP14RpMultiTextureP10RpMTEffect, RpMultiTexture*, RpMultiTexture* multiTexture, RpMTEffect* effect);

DECL_FASTCALL_SIMPLE_GLO(RpMTEffectCreateDummy, _Z21RpMTEffectCreateDummyv, RpMTEffect*);
DECL_FASTCALL_SIMPLE_GLO(RpMTEffectAddRef, _Z16RpMTEffectAddRefP10RpMTEffect, RpMTEffect*, RpMTEffect* effect);
DECL_FASTCALL_SIMPLE_GLO(RpMTEffectDestroy, _Z17RpMTEffectDestroyP10RpMTEffect, void, RpMTEffect* effect);
DECL_FASTCALL_SIMPLE_GLO(RpMTEffectFind, _Z14RpMTEffectFindPc, RpMTEffect*, RwChar* name);
DECL_FASTCALL_SIMPLE_GLO(RpMTEffectGetName, _Z17RpMTEffectGetNameP10RpMTEffect, RwChar*, RpMTEffect* effect);
DECL_FASTCALL_SIMPLE_GLO(RpMTEffectSetName, _Z17RpMTEffectSetNameP10RpMTEffectPc, RpMTEffect*, RpMTEffect* effect, RwChar* name);
DECL_FASTCALL_SIMPLE_GLO(RpMTEffectGetPath, _Z17RpMTEffectGetPathv, RwChar*);
DECL_FASTCALL_SIMPLE_GLO(RpMTEffectSetPath, _Z17RpMTEffectSetPathPKc, RwChar const*, RwChar const* path);
DECL_FASTCALL_SIMPLE_GLO(RpMTEffectStreamGetSize, _Z23RpMTEffectStreamGetSizePK10RpMTEffect, RwUInt32, RpMTEffect const* effect);
DECL_FASTCALL_SIMPLE_GLO(RpMTEffectStreamRead, _Z20RpMTEffectStreamReadP8RwStream, RpMTEffect*, RwStream* stream);
DECL_FASTCALL_SIMPLE_GLO(RpMTEffectStreamWrite, _Z21RpMTEffectStreamWritePK10RpMTEffectP8RwStream, RpMTEffect const*, RpMTEffect const* effect, RwStream* stream);
DECL_FASTCALL_SIMPLE_GLO(RpMTEffectWrite, _Z15RpMTEffectWritePK10RpMTEffect, RpMTEffect const*, RpMTEffect const* effect);

DECL_FASTCALL_SIMPLE_GLO(RpMTEffectDictCreate, _Z20RpMTEffectDictCreatev, RpMTEffectDict*);
DECL_FASTCALL_SIMPLE_GLO(RpMTEffectDictDestroy, _Z21RpMTEffectDictDestroyP14RpMTEffectDict, void, RpMTEffectDict* dict);
DECL_FASTCALL_SIMPLE_GLO(RpMTEffectDictGetCurrent, _Z24RpMTEffectDictGetCurrentv, RpMTEffectDict*);
DECL_FASTCALL_SIMPLE_GLO(RpMTEffectDictSetCurrent, _Z24RpMTEffectDictSetCurrentP14RpMTEffectDict, RpMTEffectDict*, RpMTEffectDict* dict);
DECL_FASTCALL_SIMPLE_GLO(RpMTEffectDictAddEffect, _Z23RpMTEffectDictAddEffectP14RpMTEffectDictP10RpMTEffect, RpMTEffectDict*, RpMTEffectDict* dict, RpMTEffect* effect);
DECL_FASTCALL_SIMPLE_GLO(RpMTEffectDictRemoveEffect, _Z26RpMTEffectDictRemoveEffectP10RpMTEffect, RpMTEffect*, RpMTEffect* effect);
DECL_FASTCALL_SIMPLE_GLO(RpMTEffectDictFindNamedEffect, _Z29RpMTEffectDictFindNamedEffectPK14RpMTEffectDictPKc, RpMTEffect*, RpMTEffectDict const* dict, RwChar const* name);
DECL_FASTCALL_SIMPLE_GLO(RpMTEffectDictForAllDictionaries, _Z32RpMTEffectDictForAllDictionariesPFP14RpMTEffectDictS0_PvES1_, RwBool, RpMTEffectDictCallBack callBack, void* data);
DECL_FASTCALL_SIMPLE_GLO(RpMTEffectDictForAllEffects, _Z27RpMTEffectDictForAllEffectsPK14RpMTEffectDictPFP10RpMTEffectS3_PvES4_, RpMTEffectDict const*, RpMTEffectDict const* dict, RpMTEffectCallBack callBack, void* data);
DECL_FASTCALL_SIMPLE_GLO(RpMTEffectDictStreamGetSize, _Z27RpMTEffectDictStreamGetSizePK14RpMTEffectDict, RwUInt32, RpMTEffectDict const* dict);
DECL_FASTCALL_SIMPLE_GLO(RpMTEffectDictStreamRead, _Z24RpMTEffectDictStreamReadP8RwStream, RpMTEffectDict*, RwStream* stream);
DECL_FASTCALL_SIMPLE_GLO(RpMTEffectDictStreamWrite, _Z25RpMTEffectDictStreamWritePK14RpMTEffectDictP8RwStream, RpMTEffectDict const*, RpMTEffectDict const* dict, RwStream* stream);
#endif // __AML_PSDK_RPMULTITEXTURE_H
