#ifndef __AML_PSDK_SASPRITE2D_H
#define __AML_PSDK_SASPRITE2D_H

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/gta_base/Vector.h>
#include <aml-psdk/gta_base/Rect.h>
#include <aml-psdk/gta_base/RGBA.h>
#include <aml-psdk/gta_base/DrawVertices.h>
#include <aml-psdk/renderware/RwRender.h>

struct RwTexture;
struct RwIm2DVertex;

DECL_CLASS(CSprite2d)
    // Construct/Deconstruct functions
    DECL_CTORCALL_PROXY(CSprite2d, _ZN9CSprite2dC2Ev);
    CSprite2d() { m_pTexture = NULL; }
    DECL_DTORCALL(CSprite2d, _ZN9CSprite2dD2Ev);

    // STATIC functions
    DECL_FASTCALL_SIMPLE(SetRecipNearClip, _ZN9CSprite2d16SetRecipNearClipEv, void);
    DECL_FASTCALL_SIMPLE(InitPerFrame, _ZN9CSprite2d12InitPerFrameEv, void);
    DECL_FASTCALL_SIMPLE(AddToBuffer, _ZN9CSprite2d11AddToBufferERK5CRectRK5CRGBAffffffff, void, CRect const &Rectangle, CRGBA const &rgba, float tu1, float tv1, float tu2, float tv2, float tu3, float tv3, float tu4, float tv4);
    DECL_FASTCALL_SIMPLE(SetVertices1, _ZN9CSprite2d11SetVerticesEP14RwOpenGLVertexRK5CRectRK5CRGBAS7_S7_S7_ffffffff, void,
        RwIm2DVertex *pVerts, CRect const &Rectangle, CRGBA const &TopLeftrgba, CRGBA const &TopRightrgba, CRGBA const &BottomLeftrgba,
        CRGBA const &BottomRightrgba, float tu1, float tv1, float tu2, float tv2, float tu3, float tv3, float tu4, float tv4);
    DECL_FASTCALL_SIMPLE(IsVertexBufferFull, _ZN9CSprite2d18IsVertexBufferFullEv, bool);
    DECL_FASTCALL_SIMPLE(RenderVertexBuffer, _ZN9CSprite2d18RenderVertexBufferEv, void);
    DECL_FASTCALL_SIMPLE(IsVertexBufferEmpty, _ZN9CSprite2d19IsVertexBufferEmptyEv, bool);
    DECL_FASTCALL_SIMPLE(SetVertices2, _ZN9CSprite2d11SetVerticesERK5CRectRK5CRGBAS5_S5_S5_, void, CRect const &Rectangle, CRGBA const &TopLeftrgba, CRGBA const &TopRightrgba, CRGBA const &BottomLeftrgba, CRGBA const &BottomRightrgba);
    DECL_FASTCALL_SIMPLE(SetVertices3, _ZN9CSprite2d11SetVerticesEiPfS0_RK5CRGBA, void, i32 number, float *pVert, float *pTc, CRGBA const &rgba);
    DECL_FASTCALL_SIMPLE(OffsetTexCoordForBilinearFiltering, _ZN9CSprite2d34OffsetTexCoordForBilinearFilteringEff, void, float xsize, float ysize);
    DECL_FASTCALL_SIMPLE(SetVertices4, _ZN9CSprite2d11SetVerticesERK5CRectRK5CRGBAS5_S5_S5_ffffffff, void, CRect const &Rectangle, CRGBA const &TopLeftrgba,
        CRGBA const &TopRightrgba, CRGBA const &BottomLeftrgba, CRGBA const &BottomRightrgba, float tu1, float tv1, float tu2, float tv2, float tu3, float tv3, float tu4, float tv4);
    DECL_FASTCALL_SIMPLE(SetVertices5, _ZN9CSprite2d11SetVerticesEffffffffRK5CRGBAS2_S2_S2_, void, float x1, float y1, float x2, float y2,
        float x3, float y3, float x4, float y4, CRGBA const &TopLeftrgba, CRGBA const &TopRightrgba, CRGBA const &BottomLeftrgba, CRGBA const &BottomRightrgba);
    DECL_FASTCALL_SIMPLE(Draw2DPolygon, _ZN9CSprite2d13Draw2DPolygonEffffffffRK5CRGBA, void, float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, CRGBA const &rgba);
    DECL_FASTCALL_SIMPLE(DrawBarChart, _ZN9CSprite2d12DrawBarChartEffthfahh5CRGBAS0_, void, float x, float y, u16 w, u8 h, float value, i8 increase, u8 legend, u8 border, CRGBA c, CRGBA c2);
    DECL_FASTCALL_SIMPLE(DrawRect1, _ZN9CSprite2d8DrawRectERK5CRectRK5CRGBA, void, CRect const &Rectangle, CRGBA const &rgba);
    DECL_FASTCALL_SIMPLE(SetVertices6, _ZN9CSprite2d11SetVerticesEiPfP5CRGBA, void, i32 number, float *pVert, CRGBA *pRGBA);
    DECL_FASTCALL_SIMPLE(SetMaskVertices, _ZN9CSprite2d15SetMaskVerticesEiPff, void, i32 number, float *pVert, float z);
    DECL_FASTCALL_SIMPLE(DrawTxRect, _ZN9CSprite2d10DrawTxRectERK5CRectRK5CRGBA, void, CRect const &Rectangle, CRGBA const &rgba);
    DECL_FASTCALL_SIMPLE(DrawRect2, _ZN9CSprite2d8DrawRectERK5CRectRK5CRGBAS5_S5_S5_, void, CRect const &Rectangle, CRGBA const &TopLeftrgba, CRGBA const &TopRightrgba, CRGBA const &BottomLeftrgba, CRGBA const &BottomRightrgba);
    DECL_FASTCALL_SIMPLE(DrawRectXLU, _ZN9CSprite2d11DrawRectXLUERK5CRectRK5CRGBAS5_S5_S5_, void, CRect const &Rectangle, CRGBA const &TopLeftrgba, CRGBA const &TopRightrgba, CRGBA const &BottomLeftrgba, CRGBA const &BottomRightrgba);
    DECL_FASTCALL_SIMPLE(DrawAnyRect, _ZN9CSprite2d11DrawAnyRectEffffffffRK5CRGBAS2_S2_S2_, void, float X1, float Y1, float X2, float Y2, float X3, float Y3, float X4, float Y4, CRGBA const &RGBA1, CRGBA const &RGBA2, CRGBA const &RGBA3, CRGBA const &RGBA4);
    DECL_FASTCALL_SIMPLE(DrawCircleAtNearClip, _ZN9CSprite2d20DrawCircleAtNearClipERK9CVector2DfRK5CRGBAi, void, CVector2D const &CenterOfCircle, float Radius, CRGBA const &rgba, int NumOfSectionsToCircle);
    DECL_FASTCALL_SIMPLE(SetVerticesForSniper, _ZN9CSprite2d20SetVerticesForSniperERK5CRectRK5CRGBAS5_S5_S5_, void, CRect const &Rectangle, CRGBA const &TopLeftrgba, CRGBA const &TopRightrgba, CRGBA const &BottomLeftrgba, CRGBA const &BottomRightrgba);

    // Helper functions
    static inline void SetVertices(RwIm2DVertex *pVerts, CRect const &Rectangle, CRGBA const &TopLeftrgba, CRGBA const &TopRightrgba, CRGBA const &BottomLeftrgba,
        CRGBA const &BottomRightrgba, float tu1, float tv1, float tu2, float tv2, float tu3, float tv3, float tu4, float tv4)
    {
        SetVertices1(pVerts, Rectangle, TopLeftrgba, TopRightrgba, BottomLeftrgba, BottomRightrgba, tu1, tv1, tu2, tv2, tu3, tv3, tu4, tv4);
    }
    static inline void SetVertices(CRect const &Rectangle, CRGBA const &TopLeftrgba, CRGBA const &TopRightrgba, CRGBA const &BottomLeftrgba, CRGBA const &BottomRightrgba)
    {
        SetVertices2(Rectangle, TopLeftrgba, TopRightrgba, BottomLeftrgba, BottomRightrgba);
    }
    static inline void SetVertices(CRect const &Rectangle, CRGBA const &rgba)
    {
        SetVertices2(Rectangle, rgba, rgba, rgba, rgba);
    }
    static inline void SetVertices(i32 number, float *pVert, float *pTc, CRGBA const &rgba)
    {
        SetVertices3(number, pVert, pTc, rgba);
    }
    static inline void SetVertices(CRect const &Rectangle, CRGBA const &TopLeftrgba, CRGBA const &TopRightrgba, CRGBA const &BottomLeftrgba,
        CRGBA const &BottomRightrgba, float tu1, float tv1, float tu2, float tv2, float tu3, float tv3, float tu4, float tv4)
    {
        SetVertices4(Rectangle, TopLeftrgba, TopRightrgba, BottomLeftrgba, BottomRightrgba, tu1, tv1, tu2, tv2, tu3, tv3, tu4, tv4);
    }
    static inline void SetVertices(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4,
        CRGBA const &TopLeftrgba, CRGBA const &TopRightrgba, CRGBA const &BottomLeftrgba, CRGBA const &BottomRightrgba)
    {
        SetVertices5(x1, y1, x2, y2, x3, y3, x4, y4, TopLeftrgba, TopRightrgba, BottomLeftrgba, BottomRightrgba);
    }
    static inline void SetVertices(i32 number, float *pVert, CRGBA *pRGBA)
    {
        SetVertices6(number, pVert, pRGBA);
    }
    static inline void DrawRect(CRect const &Rectangle, CRGBA const &rgba)
    {
        DrawRect1(Rectangle, rgba);
    }
    static inline void DrawRect(CRect const &Rectangle, CRGBA const &TopLeftrgba, CRGBA const &TopRightrgba, CRGBA const &BottomLeftrgba, CRGBA const &BottomRightrgba)
    {
        DrawRect2(Rectangle, TopLeftrgba, TopRightrgba, BottomLeftrgba, BottomRightrgba);
    }

    // Member functions
    DECL_THISCALL_SIMPLE(Delete, _ZN9CSprite2d6DeleteEv, void);
    DECL_THISCALL_SIMPLE(SetRenderState, _ZN9CSprite2d14SetRenderStateEv, void);

    DECL_THISCALL_HEAD(SetTexture, _ZN9CSprite2d10SetTextureEPc, void, char *pFilename)
    DECL_THISCALL_TAIL(SetTexture, pFilename)

    DECL_THISCALL_NAMED_HEAD(SetTexture1, SetTexture, _ZN9CSprite2d10SetTextureEPcS0_, void, char *pFilename, char* pMaskFilename)
    DECL_THISCALL_TAIL(SetTexture1, pFilename, pMaskFilename)

    DECL_THISCALL_HEAD(SetAddressingUV, _ZN9CSprite2d15SetAddressingUVE20RwTextureAddressModeS0_, RwTexture*, RwTextureAddressMode addressU, RwTextureAddressMode addressV)
    DECL_THISCALL_TAIL(SetAddressingUV, addressU, addressV)

    DECL_THISCALL_HEAD(SetAddressing, _ZN9CSprite2d13SetAddressingE20RwTextureAddressMode, RwTexture*, RwTextureAddressMode address)
    DECL_THISCALL_TAIL(SetAddressing, address)

    DECL_THISCALL_HEAD(Draw, _ZN9CSprite2d4DrawEffffRK5CRGBA, void, float x, float y, float Width, float Height, CRGBA const &rgba)
    DECL_THISCALL_TAIL(Draw, x, y, Width, Height, rgba)

    DECL_THISCALL_NAMED_HEAD(Draw1, Draw, _ZN9CSprite2d4DrawERK5CRectRK5CRGBA, void, CRect const &Rectangle, CRGBA const &rgba)
    DECL_THISCALL_TAIL(Draw1, Rectangle, rgba)

    DECL_THISCALL_HEAD(DrawTriangle, _ZN9CSprite2d12DrawTriangleEPfS0_RK5CRGBA, void, float *pFloats, float *pTc, CRGBA const &rgba)
    DECL_THISCALL_TAIL(DrawTriangle, pFloats, pTc, rgba)

    DECL_THISCALL_HEAD(DrawWithBilinearOffset, _ZN9CSprite2d22DrawWithBilinearOffsetERK5CRectRK5CRGBA, void, CRect const &Rectangle, CRGBA const &rgba)
    DECL_THISCALL_TAIL(DrawWithBilinearOffset, Rectangle, rgba)

    DECL_THISCALL_NAMED_HEAD(Draw2, Draw, _ZN9CSprite2d4DrawERK5CRectRK5CRGBAffffffff, void, CRect const &Rectangle, CRGBA const &rgba, float tu1, float tv1, float tu2, float tv2, float tu3, float tv3, float tu4, float tv4)
    DECL_THISCALL_TAIL(Draw2, Rectangle, rgba, tu1, tv1, tu2, tv2, tu3, tv3, tu4, tv4)

    DECL_THISCALL_NAMED_HEAD(Draw3, Draw, _ZN9CSprite2d4DrawERK5CRectRK5CRGBAS5_S5_S5_, void, CRect const &Rectangle, CRGBA const &TopLeftrgba, CRGBA const &TopRightrgba, CRGBA const &BottomLeftrgba, CRGBA const &BottomRightrgba)
    DECL_THISCALL_TAIL(Draw3, Rectangle, TopLeftrgba, TopRightrgba, BottomLeftrgba, BottomRightrgba)

    DECL_THISCALL_HEAD(DrawRotated, _ZN9CSprite2d11DrawRotatedER5CRectfRK5CRGBA, void, CRect &rect, float fRadians, CRGBA const &rgba)
    DECL_THISCALL_TAIL(DrawRotated, rect, fRadians, rgba)

    DECL_THISCALL_NAMED_HEAD(DrawRotated1, DrawRotated, _ZN9CSprite2d11DrawRotatedERK9CVector2DfffffffffRK5CRGBA, void, CVector2D const &vecCenter, float fX1, float fY1, float fX2, float fY2, float fX3, float fY3, float fX4, float fY4, float fRadians, CRGBA const &rgba)
    DECL_THISCALL_TAIL(DrawRotated1, vecCenter, fX1, fY1, fX2, fY2, fX3, fY3, fX4, fY4, fRadians, rgba)

    DECL_THISCALL_NAMED_HEAD(Draw4, Draw, _ZN9CSprite2d4DrawEffffffffRK5CRGBA, void, float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, CRGBA const &rgba)
    DECL_THISCALL_TAIL(Draw4, x1, y1, x2, y2, x3, y3, x4, y4, rgba)

    // Helper functions
    template<class CharT, std::enable_if_t<std::is_same_v<CharT, const char>, int> = 0>
    inline void SetTexture(CharT *pFilename)
    {
        SetTexture(const_cast<char*>(pFilename));
    }
    template<class CharT, std::enable_if_t<std::is_same_v<CharT, const char>, int> = 0>
    inline void SetTexture(CharT *pFilename, const char *pMaskFilename)
    {
        SetTexture(const_cast<char*>(pFilename), const_cast<char*>(pMaskFilename));
    }
    template<class CharT, std::enable_if_t<std::is_same_v<CharT, const char>, int> = 0>
    inline void SetTexture(char *pFilename, CharT *pMaskFilename)
    {
        SetTexture(pFilename, const_cast<char*>(pMaskFilename));
    }
    inline RwTexture* SetAddressingUV(int addressU, int addressV)
    {
        return SetAddressingUV((RwTextureAddressMode)addressU, (RwTextureAddressMode)addressV);
    }
    inline RwTexture* SetAddressing(int address)
    {
        return SetAddressing((RwTextureAddressMode)address);
    }

    // STATIC values
    DECL_OBJECT_ARRAY_PLT(RwIm2DVertex, maVertices, BYBIT(0x679E70, 0x851CF0));
    DECL_VALUE_PLT_FLT(RecipNearClip, BYBIT(0x6766B8, 0x84ADC8));
    DECL_VALUE_PLT_FLT(NearScreenZ, BYBIT(0x675F98, 0x849FA0));
    DECL_VALUE_PLT_I32(nextBufferVertex, BYBIT(0x678880, 0x84F120));
    DECL_VALUE_PLT_I32(nextBufferIndex, BYBIT(0x679E6C, 0x851CE8));

    // Member values
    RwTexture* m_pTexture;
DECL_CLASS_END()

DECL_FASTCALL_SIMPLE_GLO(CalcScreenCoors, _Z15CalcScreenCoorsRK7CVectorPS_, bool, CVector const& In, CVector* pResult);

//#define maVertices maVertices()
#define RecipNearClip RecipNearClip()
#define NearScreenZ NearScreenZ()
#define nextBufferVertex nextBufferVertex()
#define nextBufferIndex nextBufferIndex()

#endif // __AML_PSDK_SASPRITE2D_H
