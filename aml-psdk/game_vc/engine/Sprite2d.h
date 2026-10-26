#ifndef __AML_PSDK_VCSPRITE2D_H
#define __AML_PSDK_VCSPRITE2D_H

#include <aml-psdk/game_vc/plugin.h>
#include <aml-psdk/gta_base/Rect.h>
#include <aml-psdk/gta_base/RGBA.h>

struct RwTexture;
enum RwTextureAddressMode : u32;

struct RwOpenGLVertex
{
    float x, y, z;
    CRGBA color;
    float u, v, w, q;
    float rhw;
};
CHECKSIZE(RwOpenGLVertex, 0x24, 0x24);

DECL_CLASS(CSprite2d)
    // Construct/Deconstruct functions
    DECL_CTORCALL(CSprite2d, _ZN9CSprite2dC2Ev);
    DECL_DTORCALL(CSprite2d, _ZN9CSprite2dD2Ev);
    CSprite2d(CSprite2d const&) = delete;
    CSprite2d& operator=(CSprite2d const&) = delete;

    // STATIC functions
    DECL_FASTCALL_SIMPLE(InitPerFrame, _ZN9CSprite2d12InitPerFrameEv, void);
    DECL_FASTCALL_SIMPLE(IsVertexBufferFull, _ZN9CSprite2d18IsVertexBufferFullEv, bool);
    DECL_FASTCALL_SIMPLE(IsVertexBufferEmpty, _ZN9CSprite2d19IsVertexBufferEmptyEv, bool);
    DECL_FASTCALL_SIMPLE(RenderVertexBuffer, _ZN9CSprite2d18RenderVertexBufferEv, void);
    DECL_FASTCALL_SIMPLE(OffsetTexCoordForBilinearFiltering, _ZN9CSprite2d34OffsetTexCoordForBilinearFilteringEff, void, float width, float height);
    DECL_FASTCALL_SIMPLE(AddToBuffer, _ZN9CSprite2d11AddToBufferERK5CRectRK5CRGBAffffffff, void, CRect const& rect, CRGBA const& color, float u1, float v1, float u2, float v2, float u3, float v3, float u4, float v4);
    DECL_FASTCALL_SIMPLE(SetMaskVertices, _ZN9CSprite2d15SetMaskVerticesEiPf, void, i32 count, float* vertices);
    DECL_FASTCALL_SIMPLE(DrawTxRect, _ZN9CSprite2d10DrawTxRectERK5CRectRK5CRGBA, void, CRect const& rect, CRGBA const& color);
    DECL_FASTCALL_SIMPLE(DrawRectXLU, _ZN9CSprite2d11DrawRectXLUERK5CRectRK5CRGBAS5_S5_S5_, void, CRect const& rect, CRGBA const& topLeft, CRGBA const& topRight, CRGBA const& bottomLeft, CRGBA const& bottomRight);
    DECL_FASTCALL_SIMPLE(DrawAnyRect, _ZN9CSprite2d11DrawAnyRectEffffffffRK5CRGBAS2_S2_S2_, void, float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, CRGBA const& topLeft, CRGBA const& topRight, CRGBA const& bottomLeft, CRGBA const& bottomRight);
    DECL_FASTCALL_SIMPLE(Draw2DPolygon, _ZN9CSprite2d13Draw2DPolygonEffffffffRK5CRGBA, void, float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, CRGBA const& color);
    DECL_FASTCALL_SIMPLE(DrawCircleAtNearClip, _ZN9CSprite2d20DrawCircleAtNearClipERK9CVector2DfRK5CRGBAi, void, CVector2D const& center, float radius, CRGBA const& color, i32 sectors);
    DECL_FASTCALL_SIMPLE(SetVerticesForSniper, _ZN9CSprite2d20SetVerticesForSniperERK5CRectRK5CRGBAS5_S5_S5_, void, CRect const& rect, CRGBA const& topLeft, CRGBA const& topRight, CRGBA const& bottomLeft, CRGBA const& bottomRight);
    DECL_FASTCALL_SIMPLE(DrawSpecialRectForSniper, _ZN9CSprite2d24DrawSpecialRectForSniperERK5CRectRK5CRGBAS5_S5_S5_, void, CRect const& rect, CRGBA const& topLeft, CRGBA const& topRight, CRGBA const& bottomLeft, CRGBA const& bottomRight);

    inline static void SetVertices(RwOpenGLVertex* vertices, CRect const& rect, CRGBA const& topLeft, CRGBA const& topRight, CRGBA const& bottomLeft, CRGBA const& bottomRight, float u1, float v1, float u2, float v2, float u3, float v3, float u4, float v4)
    {
        static auto native = GetMainLibrarySymbol<void(*)(RwOpenGLVertex*, CRect const&, CRGBA const&, CRGBA const&, CRGBA const&, CRGBA const&, float, float, float, float, float, float, float, float)>("_ZN9CSprite2d11SetVerticesEP14RwOpenGLVertexRK5CRectRK5CRGBAS7_S7_S7_ffffffff");
        return native(vertices, rect, topLeft, topRight, bottomLeft, bottomRight, u1, v1, u2, v2, u3, v3, u4, v4);
    }
    inline static void SetVertices(CRect const& rect, CRGBA const& topLeft, CRGBA const& topRight, CRGBA const& bottomLeft, CRGBA const& bottomRight)
    {
        static auto native = GetMainLibrarySymbol<void(*)(CRect const&, CRGBA const&, CRGBA const&, CRGBA const&, CRGBA const&)>("_ZN9CSprite2d11SetVerticesERK5CRectRK5CRGBAS5_S5_S5_");
        return native(rect, topLeft, topRight, bottomLeft, bottomRight);
    }
    inline static void SetVertices(CRect const& rect, CRGBA const& topLeft, CRGBA const& topRight, CRGBA const& bottomLeft, CRGBA const& bottomRight, float u1, float v1, float u2, float v2, float u3, float v3, float u4, float v4)
    {
        static auto native = GetMainLibrarySymbol<void(*)(CRect const&, CRGBA const&, CRGBA const&, CRGBA const&, CRGBA const&, float, float, float, float, float, float, float, float)>("_ZN9CSprite2d11SetVerticesERK5CRectRK5CRGBAS5_S5_S5_ffffffff");
        return native(rect, topLeft, topRight, bottomLeft, bottomRight, u1, v1, u2, v2, u3, v3, u4, v4);
    }
    inline static void SetVertices(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, CRGBA const& topLeft, CRGBA const& topRight, CRGBA const& bottomLeft, CRGBA const& bottomRight)
    {
        static auto native = GetMainLibrarySymbol<void(*)(float, float, float, float, float, float, float, float, CRGBA const&, CRGBA const&, CRGBA const&, CRGBA const&)>("_ZN9CSprite2d11SetVerticesEffffffffRK5CRGBAS2_S2_S2_");
        return native(x1, y1, x2, y2, x3, y3, x4, y4, topLeft, topRight, bottomLeft, bottomRight);
    }
    inline static void SetVertices(i32 count, float* vertices, float* texCoords, CRGBA const& color)
    {
        static auto native = GetMainLibrarySymbol<void(*)(i32, float*, float*, CRGBA const&)>("_ZN9CSprite2d11SetVerticesEiPfS0_RK5CRGBA");
        return native(count, vertices, texCoords, color);
    }
    inline static void SetVertices(i32 count, float* vertices, CRGBA* colors)
    {
        static auto native = GetMainLibrarySymbol<void(*)(i32, float*, CRGBA*)>("_ZN9CSprite2d11SetVerticesEiPfP5CRGBA");
        return native(count, vertices, colors);
    }
    inline static void DrawRect(CRect const& rect, CRGBA const& color)
    {
        static auto native = GetMainLibrarySymbol<void(*)(CRect const&, CRGBA const&)>("_ZN9CSprite2d8DrawRectERK5CRectRK5CRGBA");
        return native(rect, color);
    }
    inline static void DrawRect(CRect const& rect, CRGBA const& topLeft, CRGBA const& topRight, CRGBA const& bottomLeft, CRGBA const& bottomRight)
    {
        static auto native = GetMainLibrarySymbol<void(*)(CRect const&, CRGBA const&, CRGBA const&, CRGBA const&, CRGBA const&)>("_ZN9CSprite2d8DrawRectERK5CRectRK5CRGBAS5_S5_S5_");
        return native(rect, topLeft, topRight, bottomLeft, bottomRight);
    }

    // Member functions
    DECL_THISCALL_SIMPLE(Delete, _ZN9CSprite2d6DeleteEv, void);
    DECL_THISCALL_SIMPLE(SetRenderState, _ZN9CSprite2d14SetRenderStateEv, void);
    DECL_THISCALL_HEAD(SetTexture, _ZN9CSprite2d10SetTextureEPc, void, const char* filename)
    DECL_THISCALL_TAIL(SetTexture, filename)
    DECL_THISCALL_NAMED_HEAD(SetTexture1, SetTexture, _ZN9CSprite2d10SetTextureEPcS0_, void, const char* filename, const char* mask)
    DECL_THISCALL_TAIL(SetTexture1, filename, mask)
    DECL_THISCALL_HEAD(SetAddressing, _ZN9CSprite2d13SetAddressingE20RwTextureAddressMode, RwTexture*, RwTextureAddressMode mode)
    DECL_THISCALL_TAIL(SetAddressing, mode)
    // The native function updates U only; addressV is ignored.
    DECL_THISCALL_HEAD(SetAddressingUV, _ZN9CSprite2d15SetAddressingUVE20RwTextureAddressModeS0_, RwTexture*, RwTextureAddressMode addressU, RwTextureAddressMode addressV)
    DECL_THISCALL_TAIL(SetAddressingUV, addressU, addressV)
    DECL_THISCALL_HEAD(Draw, _ZN9CSprite2d4DrawEffffRK5CRGBA, void, float x, float y, float width, float height, CRGBA const& color)
    DECL_THISCALL_TAIL(Draw, x, y, width, height, color)
    DECL_THISCALL_NAMED_HEAD(Draw1, Draw, _ZN9CSprite2d4DrawERK5CRectRK5CRGBA, void, CRect const& rect, CRGBA const& color)
    DECL_THISCALL_TAIL(Draw1, rect, color)
    DECL_THISCALL_NAMED_HEAD(Draw2, Draw, _ZN9CSprite2d4DrawERK5CRectRK5CRGBAffffffff, void, CRect const& rect, CRGBA const& color, float u1, float v1, float u2, float v2, float u3, float v3, float u4, float v4)
    DECL_THISCALL_TAIL(Draw2, rect, color, u1, v1, u2, v2, u3, v3, u4, v4)
    DECL_THISCALL_NAMED_HEAD(Draw3, Draw, _ZN9CSprite2d4DrawERK5CRectRK5CRGBAS5_S5_S5_, void, CRect const& rect, CRGBA const& topLeft, CRGBA const& topRight, CRGBA const& bottomLeft, CRGBA const& bottomRight)
    DECL_THISCALL_TAIL(Draw3, rect, topLeft, topRight, bottomLeft, bottomRight)
    DECL_THISCALL_NAMED_HEAD(Draw4, Draw, _ZN9CSprite2d4DrawEffffffffRK5CRGBA, void, float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, CRGBA const& color)
    DECL_THISCALL_TAIL(Draw4, x1, y1, x2, y2, x3, y3, x4, y4, color)
    DECL_THISCALL_NAMED_HEAD(Draw5, Draw, _ZN9CSprite2d4DrawEffffffffRK5CRGBAS2_S2_S2_, void, float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, CRGBA const& topLeft, CRGBA const& topRight, CRGBA const& bottomLeft, CRGBA const& bottomRight)
    DECL_THISCALL_TAIL(Draw5, x1, y1, x2, y2, x3, y3, x4, y4, topLeft, topRight, bottomLeft, bottomRight)
    DECL_THISCALL_HEAD(DrawWithBilinearOffset, _ZN9CSprite2d22DrawWithBilinearOffsetERK5CRectRK5CRGBA, void, CRect const& rect, CRGBA const& color)
    DECL_THISCALL_TAIL(DrawWithBilinearOffset, rect, color)
    DECL_THISCALL_HEAD(DrawAntiAliased, _ZN9CSprite2d15DrawAntiAliasedEffffffffRK5CRGBAS2_S2_S2_, void, float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, CRGBA const& topLeft, CRGBA const& topRight, CRGBA const& bottomLeft, CRGBA const& bottomRight)
    DECL_THISCALL_TAIL(DrawAntiAliased, x1, y1, x2, y2, x3, y3, x4, y4, topLeft, topRight, bottomLeft, bottomRight)

    // Helper functions
    inline static void SetVertices(CRect const& rect, CRGBA const& color)
    {
        SetVertices(rect, color, color, color, color);
    }
    inline RwTexture* SetAddressing(u32 mode) { return SetAddressing((RwTextureAddressMode)mode); }
    inline RwTexture* SetAddressingUV(u32 addressU, u32 addressV)
    {
        return SetAddressingUV((RwTextureAddressMode)addressU, (RwTextureAddressMode)addressV);
    }

    // STATIC values
    DECL_OBJECT_ARRAY_PLT(RwOpenGLVertex, maVertices, BYBIT(0x3953A8, 0x5787B0));
    DECL_VALUE_PLT_FLT(RecipNearClip, BYBIT(0x3956CC, 0x578E20));
    DECL_VALUE_PLT_FLT(NearScreenZ, BYBIT(0x3962B8, 0x57A578));
    DECL_VALUE_PLT_I32(nextBufferVertex, BYBIT(0x395110, 0x578288));
    DECL_VALUE_PLT_I32(nextBufferIndex, BYBIT(0x395358, 0x578708));

    // Member values
    RwTexture* m_pTexture;
DECL_CLASS_END()
CHECKSIZE(CSprite2d, 0x4, 0x8);

#define RecipNearClip RecipNearClip()
#define NearScreenZ NearScreenZ()
#define nextBufferVertex nextBufferVertex()
#define nextBufferIndex nextBufferIndex()

#endif // __AML_PSDK_VCSPRITE2D_H
