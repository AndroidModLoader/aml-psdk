#ifndef __AML_PSDK_VCSPRITE_H
#define __AML_PSDK_VCSPRITE_H

#include "Sprite2d.h"

DECL_CLASS(CSprite)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(CalcScreenCoors, _ZN7CSprite15CalcScreenCoorsERK5RwV3dPS0_PfS4_b, bool, CVector const& point, CVector* screen, float* scaleX, float* scaleY, bool clipFarPlane);
    DECL_FASTCALL_SIMPLE(CalcHorizonCoors, _ZN7CSprite16CalcHorizonCoorsEv, float);
    DECL_FASTCALL_SIMPLE(FlushSpriteBuffer, _ZN7CSprite17FlushSpriteBufferEv, void);
    DECL_FASTCALL_SIMPLE(InitSpriteBuffer, _ZN7CSprite16InitSpriteBufferEv, void);
    DECL_FASTCALL_SIMPLE(InitSpriteBuffer2D, _ZN7CSprite18InitSpriteBuffer2DEv, void);
    DECL_FASTCALL_SIMPLE(RenderBufferedOneXLUSprite, _ZN7CSprite26RenderBufferedOneXLUSpriteEfffffhhhsfh, void, float x, float y, float z, float width, float height, u8 red, u8 green, u8 blue, i16 intensity, float recipZ, u8 alpha);
    DECL_FASTCALL_SIMPLE(RenderOneXLUSprite, _ZN7CSprite18RenderOneXLUSpriteEfffffhhhsfh, void, float x, float y, float z, float width, float height, u8 red, u8 green, u8 blue, i16 intensity, float recipZ, u8 alpha);
    DECL_FASTCALL_SIMPLE(RenderBufferedOneXLUSprite_Rotate_Aspect, _ZN7CSprite40RenderBufferedOneXLUSprite_Rotate_AspectEfffffhhhsffh, void, float x, float y, float z, float width, float height, u8 red, u8 green, u8 blue, i16 intensity, float recipZ, float rotation, u8 alpha);
    DECL_FASTCALL_SIMPLE(RenderOneXLUSprite_Rotate_Aspect, _ZN7CSprite32RenderOneXLUSprite_Rotate_AspectEfffffhhhsffh, void, float x, float y, float z, float width, float height, u8 red, u8 green, u8 blue, i16 intensity, float recipZ, float rotation, u8 alpha);
    DECL_FASTCALL_SIMPLE(RenderBufferedOneXLUSprite_Rotate_Dimension, _ZN7CSprite43RenderBufferedOneXLUSprite_Rotate_DimensionEfffffhhhsffh, void, float x, float y, float z, float width, float height, u8 red, u8 green, u8 blue, i16 intensity, float recipZ, float rotation, u8 alpha);
    DECL_FASTCALL_SIMPLE(RenderOneXLUSprite_Rotate_Dimension, _ZN7CSprite35RenderOneXLUSprite_Rotate_DimensionEfffffhhhsffh, void, float x, float y, float z, float width, float height, u8 red, u8 green, u8 blue, i16 intensity, float recipZ, float rotation, u8 alpha);
    DECL_FASTCALL_SIMPLE(RenderBufferedOneXLUSprite_Rotate_2Colours, _ZN7CSprite42RenderBufferedOneXLUSprite_Rotate_2ColoursEfffffhhhhhhffffh, void, float x, float y, float z, float width, float height, u8 red1, u8 green1, u8 blue1, u8 red2, u8 green2, u8 blue2, float colorDirectionX, float colorDirectionY, float recipZ, float rotation, u8 alpha);
    DECL_FASTCALL_SIMPLE(RenderOneXLUSprite_Rotate_2Colours, _ZN7CSprite34RenderOneXLUSprite_Rotate_2ColoursEfffffhhhhhhffffh, void, float x, float y, float z, float width, float height, u8 red1, u8 green1, u8 blue1, u8 red2, u8 green2, u8 blue2, float colorDirectionX, float colorDirectionY, float recipZ, float rotation, u8 alpha);
    DECL_FASTCALL_SIMPLE(RenderBufferedOneXLUSprite2D, _ZN7CSprite28RenderBufferedOneXLUSprite2DEffffRK6RwRGBAsh, void, float x, float y, float width, float height, CRGBA const& color, i16 intensity, u8 alpha);
    DECL_FASTCALL_SIMPLE(RenderOneXLUSprite2D, _ZN7CSprite20RenderOneXLUSprite2DEffffRK6RwRGBAsh, void, float x, float y, float width, float height, CRGBA const& color, i16 intensity, u8 alpha);
    DECL_FASTCALL_SIMPLE(RenderBufferedOneXLUSprite2D_Rotate_Dimension, _ZN7CSprite45RenderBufferedOneXLUSprite2D_Rotate_DimensionEffffRK6RwRGBAsfh, void, float x, float y, float width, float height, CRGBA const& color, i16 intensity, float rotation, u8 alpha);
    DECL_FASTCALL_SIMPLE(RenderOneXLUSprite2D_Rotate_Dimension, _ZN7CSprite37RenderOneXLUSprite2D_Rotate_DimensionEffffRK6RwRGBAsfh, void, float x, float y, float width, float height, CRGBA const& color, i16 intensity, float rotation, u8 alpha);

    inline static void Set4Vertices2D(RwOpenGLVertex* vertices, CRect const& rect, CRGBA const& topLeft, CRGBA const& topRight, CRGBA const& bottomLeft, CRGBA const& bottomRight)
    {
        static auto native = GetMainLibrarySymbol<void(*)(RwOpenGLVertex*, CRect const&, CRGBA const&, CRGBA const&, CRGBA const&, CRGBA const&)>("_ZN7CSprite14Set4Vertices2DEP14RwOpenGLVertexRK5CRectRK5CRGBAS7_S7_S7_");
        return native(vertices, rect, topLeft, topRight, bottomLeft, bottomRight);
    }
    inline static void Set4Vertices2D(RwOpenGLVertex* vertices, float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, CRGBA const& topLeft, CRGBA const& topRight, CRGBA const& bottomLeft, CRGBA const& bottomRight)
    {
        static auto native = GetMainLibrarySymbol<void(*)(RwOpenGLVertex*, float, float, float, float, float, float, float, float, CRGBA const&, CRGBA const&, CRGBA const&, CRGBA const&)>("_ZN7CSprite14Set4Vertices2DEP14RwOpenGLVertexffffffffRK5CRGBAS4_S4_S4_");
        return native(vertices, x1, y1, x2, y2, x3, y3, x4, y4, topLeft, topRight, bottomLeft, bottomRight);
    }

    // STATIC values
    DECL_VALUE_PLT_FLT(m_f2DNearScreenZ, BYBIT(0x396A18, 0x57B438));
    DECL_VALUE_PLT_FLT(m_f2DFarScreenZ, BYBIT(0x395710, 0x578EA8));
    DECL_VALUE_PLT_FLT(m_fRecipNearClipPlane, BYBIT(0x396198, 0x57A348));
    DECL_VALUE_PLT_U32(m_bFlushSpriteBufferSwitchZTest, BYBIT(0x396E68, 0x57BCC0));
DECL_CLASS_END()

#define m_f2DNearScreenZ m_f2DNearScreenZ()
#define m_f2DFarScreenZ m_f2DFarScreenZ()
#define m_fRecipNearClipPlane m_fRecipNearClipPlane()
#define m_bFlushSpriteBufferSwitchZTest m_bFlushSpriteBufferSwitchZTest()

#endif // __AML_PSDK_VCSPRITE_H
