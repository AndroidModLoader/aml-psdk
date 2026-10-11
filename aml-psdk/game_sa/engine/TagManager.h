#ifndef __AML_PSDK_SATAGMANAGER_H
#define __AML_PSDK_SATAGMANAGER_H

/*
    Plugin-SDK (Grand Theft Auto San Andreas) header file
    Authors: GTA Community. See more here
    https://github.com/DK22Pac/plugin-sdk
    Do not delete this comment block. Respect others' work!
*/

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/gta_base/Vector.h>
#include <aml-psdk/gta_base/Rect.h>

struct CEntity;
struct RpAtomic;

struct tTagDesc
{
    CEntity *m_pEntity;
    u8 m_nAlpha;
};
CHECKSIZE(tTagDesc, 0x8, 0x10);

DECL_CLASS(CTagManager)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(Init, _ZN11CTagManager4InitEv, void);
    DECL_FASTCALL_SIMPLE(ShutdownForRestart, _ZN11CTagManager18ShutdownForRestartEv, void);
    DECL_FASTCALL_SIMPLE(GetTagPos, _ZN11CTagManager9GetTagPosEi, CVector&, i32 idx);
    DECL_FASTCALL_SIMPLE(AddTag, _ZN11CTagManager6AddTagEP7CEntity, void, CEntity* entity);
    DECL_FASTCALL_SIMPLE(FindTagDesc, _ZN11CTagManager11FindTagDescEP7CEntity, tTagDesc*, CEntity* entity);
    DECL_FASTCALL_SIMPLE(IsTag, _ZN11CTagManager5IsTagEPK7CEntity, bool, CEntity const* entity);
    DECL_FASTCALL_SIMPLE(SetAlpha1, _ZN11CTagManager8SetAlphaEP7CEntityh, void, CEntity* pEntity, u8 alpha);
    DECL_FASTCALL_SIMPLE(SetAlpha2, _ZN11CTagManager8SetAlphaEP8RpAtomich, void, RpAtomic* pAtomic, u8 alpha);
    DECL_FASTCALL_SIMPLE(UpdateNumTagged, _ZN11CTagManager15UpdateNumTaggedEv, void);
    DECL_FASTCALL_SIMPLE(GetAlpha1, _ZN11CTagManager8GetAlphaEP7CEntity, u8, CEntity* pEntity);
    DECL_FASTCALL_SIMPLE(GetAlpha2, _ZN11CTagManager8GetAlphaEP8RpAtomic, u8, RpAtomic* pAtomic);
    DECL_FASTCALL_SIMPLE(ResetAlpha, _ZN11CTagManager10ResetAlphaEP7CEntity, void, CEntity* entity);
    DECL_FASTCALL_SIMPLE(SetAlphaInArea, _ZN11CTagManager14SetAlphaInAreaER5CRecth, void, CRect& area, u8 alphaToSet);
    DECL_FASTCALL_SIMPLE(GetPercentageTaggedInArea, _ZN11CTagManager25GetPercentageTaggedInAreaER5CRect, i32, CRect& area);
    DECL_FASTCALL_SIMPLE(GetPercentageTagged, _ZN11CTagManager19GetPercentageTaggedEv, i32);
    DECL_FASTCALL_SIMPLE(GetNearestTag, _ZN11CTagManager13GetNearestTagERK7CVector, CEntity*, CVector const& nearestToPoint);
    DECL_FASTCALL_SIMPLE(SetupAtomic, _ZN11CTagManager11SetupAtomicEP8RpAtomic, void, RpAtomic* atomic);
    DECL_FASTCALL_SIMPLE(RenderTagForPC, _ZN11CTagManager14RenderTagForPCEP8RpAtomic, void, RpAtomic* atomic);
    DECL_FASTCALL_SIMPLE(Save, _ZN11CTagManager4SaveEv, bool);
    DECL_FASTCALL_SIMPLE(Load, _ZN11CTagManager4LoadEv, bool);

    // Helper functions
    static void SetAlpha(CEntity* pEntity, u8 alpha)
    {
        return SetAlpha1(pEntity, alpha);
    }
    static void SetAlpha(RpAtomic* pAtomic, u8 alpha)
    {
        return SetAlpha2(pAtomic, alpha);
    }
    static u8 GetAlpha(CEntity* pEntity)
    {
        return GetAlpha1(pEntity);
    }
    static u8 GetAlpha(RpAtomic* pAtomic)
    {
        return GetAlpha2(pAtomic);
    }

    // STATIC values
    DECL_OBJECT_ARRAY_PLT(tTagDesc, ms_tagDesc, BYBIT(0x676C98, 0x84B978));
    DECL_VALUE_PLT_U32(ms_numTags, BYBIT(0x675FA4, 0x849FB8));
    DECL_VALUE_PLT_U32(ms_numTagged, BYBIT(0x677FC8, 0x84DFB0));
DECL_CLASS_END()

#define ms_tagDesc ms_tagDesc()
#define ms_numTags ms_numTags()
#define ms_numTagged ms_numTagged()

#endif // __AML_PSDK_SATAGMANAGER_H
