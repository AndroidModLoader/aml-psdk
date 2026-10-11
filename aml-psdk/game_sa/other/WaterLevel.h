#ifndef __AML_PSDK_SAWATERLEVEL_H
#define __AML_PSDK_SAWATERLEVEL_H

/*
    Plugin-SDK (Grand Theft Auto San Andreas) header file
    Authors: GTA Community. See more here
    https://github.com/DK22Pac/plugin-sdk
    Do not delete this comment block. Respect others' work!
*/

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/gta_base/Vector.h>
#include <aml-psdk/game_sa/base/ColModel.h>
#include <aml-psdk/gta_base/RGBA.h>

struct CObject;

enum eBeachToy : i32
{
    BEACHTOY_BEACHBALL = 0x1,
    BEACHTOY_LOUNGE_WOOD_UP = 0x2,
    BEACHTOY_LOUNGE_TOWEL_UP = 0x3,
    BEACHTOY_LOUNGE_WOOD_DN = 0x4,
    BEACHTOY_LOUNGE_ANY = 0x5,
    BEACHTOY_LOTION = 0x6,
    BEACHTOY_BEACHTOWEL01 = 0x7,
    BEACHTOY_BEACHTOWEL02 = 0x8,
    BEACHTOY_BEACHTOWEL03 = 0x9,
    BEACHTOY_BEACHTOWEL04 = 0xA,
    BEACHTOY_BEACHTOWEL_ANY = 0xB
};

struct CRenPar
{
    float z;
    float bigWaves;
    float smallWaves;
    i8 flowX;
    i8 flowY;
};
CHECKSIZE(CRenPar, 0x10, 0x10);

struct CWaterVertex
{
    i16 x;
    i16 y;
    CRenPar rp;
};
CHECKSIZE(CWaterVertex, 0x14, 0x14);

struct CWaterTriangle
{
    i16 verts[3];
    u16 bToBeRendered : 1;
    u16 bInvisible : 1;
    u16 bLimitedDepth : 1;
};
CHECKSIZE(CWaterTriangle, 0x8, 0x8);

struct CWaterQuad
{
    i16 verts[4];
    u16 bToBeRendered : 1;
    u16 bInvisible : 1;
    u16 bLimitedDepth : 1;
};
CHECKSIZE(CWaterQuad, 0xA, 0xA);

struct tWaterFog
{
    i16 minX[70];
    i16 minY[70];
    i16 maxX[70];
    i16 maxY[70];
    float z[70];
};
CHECKSIZE(tWaterFog, 0x348, 0x348);

typedef u16 tWaterQuadTriangleBlock[12];

DECL_CLASS(CWaterLevel)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(WaterLevelInitialise, _ZN11CWaterLevel20WaterLevelInitialiseEv, void);
    DECL_FASTCALL_SIMPLE(AddWaterLevelQuad, _ZN11CWaterLevel17AddWaterLevelQuadEii7CRenPariiS0_iiS0_iiS0_j, void,
        i32 X1, i32 Y1, CRenPar P1, i32 X2, i32 Y2, CRenPar P2, i32 X3, i32 Y3, CRenPar P3, i32 X4, i32 Y4, CRenPar P4, u32 Flags);
    DECL_FASTCALL_SIMPLE(AddWaterLevelTriangle, _ZN11CWaterLevel21AddWaterLevelTriangleEii7CRenPariiS0_iiS0_j, void,
        i32 X1, i32 Y1, CRenPar P1, i32 X2, i32 Y2, CRenPar P2, i32 X3, i32 Y3, CRenPar P3, u32 Flags);
    DECL_FASTCALL_SIMPLE(FillQuadsAndTrianglesList, _ZN11CWaterLevel25FillQuadsAndTrianglesListEv, void);
    DECL_FASTCALL_SIMPLE(FixVertexOnToLine, _ZN11CWaterLevel17FixVertexOnToLineEP12CWaterVertexS1_S1_Pf, void,
        CWaterVertex* pVertex, CWaterVertex* pLineStart, CWaterVertex* pLineEnd, float* pError);
    DECL_FASTCALL_SIMPLE(AddToQuadsAndTrianglesList, _ZN11CWaterLevel26AddToQuadsAndTrianglesListEiiij, void, i32 blockX, i32 blockY, i32 index, u32 flags);
    DECL_FASTCALL_SIMPLE(MarkQuadsAndPolysToBeRendered, _ZN11CWaterLevel29MarkQuadsAndPolysToBeRenderedEiib, void, i32 blockX, i32 blockY, bool isInInterior);
    DECL_FASTCALL_SIMPLE(Shutdown, _ZN11CWaterLevel8ShutdownEv, void);
    DECL_FASTCALL_SIMPLE(AddWaterLevelVertex, _ZN11CWaterLevel19AddWaterLevelVertexEii7CRenPar, i32, i32 X, i32 Y, CRenPar P);
    DECL_FASTCALL_SIMPLE(AddWaveToResult1, _ZN11CWaterLevel15AddWaveToResultEffPfffP7CVector, void,
        float x, float y, float* pWaterZ, float bigWaves, float smallWaves, CVector* pNormal);
    DECL_FASTCALL_SIMPLE(CalculateWavesOnlyForCoordinate, _ZN11CWaterLevel31CalculateWavesOnlyForCoordinateEiiffPf, void,
        i32 X, i32 Y, float BigWavesAmpl, float SmallWavesAmpl, float* pResultHeight);
    DECL_FASTCALL_SIMPLE(AddWaveToResult2, _ZN11CWaterLevel15AddWaveToResultEiiPfff, void, i32 x, i32 y, float* pWaterZ, float bigWaves, float smallWaves);
    DECL_FASTCALL_SIMPLE(GetWaterLevel, _ZN11CWaterLevel13GetWaterLevelEfffPfbP7CVector, bool,
        float x, float y, float z, float* pOutWaterLevel, bool bTouchingWater, CVector* pVecNormals);
    DECL_FASTCALL_SIMPLE(GetWaterLevelNoWaves, _ZN11CWaterLevel20GetWaterLevelNoWavesEfffPfS0_S0_, bool,
        float x, float y, float z, float* pWaterZ, float* pBigWaves, float* pSmallWaves);
    DECL_FASTCALL_SIMPLE(TestQuadToGetWaterLevel, _ZN11CWaterLevel23TestQuadToGetWaterLevelEP10CWaterQuadfffPfS2_S2_, bool,
        CWaterQuad* pQuad, float x, float y, float z, float* pWaterZ, float* pBigWaves, float* pSmallWaves);
    DECL_FASTCALL_SIMPLE(TestTriangleToGetWaterLevel, _ZN11CWaterLevel27TestTriangleToGetWaterLevelEP14CWaterTrianglefffPfS2_S2_, bool,
        CWaterTriangle* pTriangle, float x, float y, float z, float* pWaterZ, float* pBigWaves, float* pSmallWaves);
    DECL_FASTCALL_SIMPLE(TestLineAgainstWater, _ZN11CWaterLevel20TestLineAgainstWaterE7CVectorS0_PS0_, bool, CVector vecStart, CVector vecEnd, CVector* pResult);
    DECL_FASTCALL_SIMPLE(PreRenderWater, _ZN11CWaterLevel14PreRenderWaterEv, void);
    DECL_FASTCALL_SIMPLE(ScanThroughBlocks, _ZN11CWaterLevel17ScanThroughBlocksEv, void);
    DECL_FASTCALL_SIMPLE(FindNearestWaterAndItsFlow, _ZN11CWaterLevel26FindNearestWaterAndItsFlowEv, void);
    DECL_FASTCALL_SIMPLE(HandleBeachToysStuff, _ZN11CWaterLevel20HandleBeachToysStuffEv, void);
    DECL_FASTCALL_SIMPLE(RenderSeaBedSegment, _ZN11CWaterLevel19RenderSeaBedSegmentEiiffff, void, i32 x, i32 y, float x1, float y1, float x2, float y2);
    DECL_FASTCALL_SIMPLE(RenderDetailedSeaBedSegment, _ZN11CWaterLevel27RenderDetailedSeaBedSegmentEiiffff, void, i32 x, i32 y, float x1, float y1, float x2, float y2);
    DECL_FASTCALL_SIMPLE(RenderWater, _ZN11CWaterLevel11RenderWaterEv, void);
    DECL_FASTCALL_SIMPLE(SetCameraRange, _ZN11CWaterLevel14SetCameraRangeEv, void);
    DECL_FASTCALL_SIMPLE(RenderAndEmptyRenderBuffer, _ZN11CWaterLevel26RenderAndEmptyRenderBufferEv, void);
    DECL_FASTCALL_SIMPLE(RenderWaterTriangle, _ZN11CWaterLevel19RenderWaterTriangleEii7CRenPariiS0_iiS0_, void,
        i32 x1, i32 y1, CRenPar p1, i32 x2, i32 y2, CRenPar p2, i32 x3, i32 y3, CRenPar p3);
    DECL_FASTCALL_SIMPLE(RenderWaterRectangle, _ZN11CWaterLevel20RenderWaterRectangleEiiii7CRenParS0_S0_S0_, void,
        i32 minX, i32 maxX, i32 Y1, i32 Y2, CRenPar P1, CRenPar P2, CRenPar P3, CRenPar P4);
    DECL_FASTCALL_SIMPLE(RenderBoatWakes, _ZN11CWaterLevel15RenderBoatWakesEv, void);
    DECL_FASTCALL_SIMPLE(BlockHit, _ZN11CWaterLevel8BlockHitEii, void, i32 X, i32 Y);
    DECL_FASTCALL_SIMPLE(CalculateWavesForCoordinate, _ZN11CWaterLevel27CalculateWavesForCoordinateEiiffPfS0_S0_P7CVector, void,
        i32 x, i32 y, float bigWaves, float smallWaves, float* pWaterZ, float* pColourMult, float* pGlare, CVector* pNormal);
    DECL_FASTCALL_SIMPLE(RenderHighDetailWaterTriangle, _ZN11CWaterLevel29RenderHighDetailWaterTriangleEii7CRenPariiS0_iiS0_, void,
        i32 X1, i32 Y1, CRenPar P1, i32 X2, i32 Y2, CRenPar P2, i32 X3, i32 Y3, CRenPar P3);
    DECL_FASTCALL_SIMPLE(SplitWaterTriangleAlongXLine, _ZN11CWaterLevel28SplitWaterTriangleAlongXLineEiii7CRenPariiS0_iiS0_, void,
        i32 splitAt, i32 x1, i32 y1, CRenPar p1, i32 x2, i32 y2, CRenPar p2, i32 x3, i32 y3, CRenPar p3);
    DECL_FASTCALL_SIMPLE(RenderHighDetailWaterTriangle_OneLayer, _ZN11CWaterLevel38RenderHighDetailWaterTriangle_OneLayerEii7CRenPariiS0_iiS0_iiii, void,
        i32 x1, i32 y1, CRenPar p1, i32 x2, i32 y2, CRenPar p2, i32 x3, i32 y3, CRenPar p3, i32 waterLayer, i32 r, i32 g, i32 b);
    DECL_FASTCALL_SIMPLE(RenderFlatWaterTriangle, _ZN11CWaterLevel23RenderFlatWaterTriangleEii7CRenPariiS0_iiS0_, void,
        i32 x1, i32 y1, CRenPar p1, i32 x2, i32 y2, CRenPar p2, i32 x3, i32 y3, CRenPar p3);
    DECL_FASTCALL_SIMPLE(RenderFlatWaterTriangle_OneLayer, _ZN11CWaterLevel32RenderFlatWaterTriangle_OneLayerEii7CRenPariiS0_iiS0_i, void,
        i32 X1, i32 Y1, CRenPar P1, i32 X2, i32 Y2, CRenPar P2, i32 X3, i32 Y3, CRenPar P3, i32 WaterLayer);
    DECL_FASTCALL_SIMPLE(RenderHighDetailWaterRectangle, _ZN11CWaterLevel30RenderHighDetailWaterRectangleEiiii7CRenParS0_S0_S0_, void,
        i32 minX, i32 maxX, i32 Y1, i32 Y2, CRenPar P1, CRenPar P2, CRenPar P3, CRenPar P4);
    DECL_FASTCALL_SIMPLE(SplitWaterRectangleAlongXLine, _ZN11CWaterLevel29SplitWaterRectangleAlongXLineEiiiii7CRenParS0_S0_S0_, void,
        i32 splitAtX, i32 minX, i32 maxX, i32 Y1, i32 Y2, CRenPar P1, CRenPar P2, CRenPar P3, CRenPar P4);
    DECL_FASTCALL_SIMPLE(SplitWaterRectangleAlongYLine, _ZN11CWaterLevel29SplitWaterRectangleAlongYLineEiiiii7CRenParS0_S0_S0_, void,
        i32 splitAtY, i32 minX, i32 maxX, i32 Y1, i32 Y2, CRenPar P1, CRenPar P2, CRenPar P3, CRenPar P4);
    DECL_FASTCALL_SIMPLE(SetUpWaterFog, _ZN11CWaterLevel13SetUpWaterFogEiiii, void, i32 minX, i32 minY, i32 maxX, i32 maxY);
    DECL_FASTCALL_SIMPLE(RenderHighDetailWaterRectangle_OneLayer, _ZN11CWaterLevel39RenderHighDetailWaterRectangle_OneLayerEiiii7CRenParS0_S0_S0_iiiii, void,
        i32 minX, i32 maxX, i32 y1, i32 y2, CRenPar p1, CRenPar p2, CRenPar p3, CRenPar p4, i32 waterLayer, i32 r, i32 g, i32 b, i32 alpha);
    DECL_FASTCALL_SIMPLE(RenderFlatWaterRectangle, _ZN11CWaterLevel24RenderFlatWaterRectangleEiiii7CRenParS0_S0_S0_, void,
        i32 minX, i32 maxX, i32 Y1, i32 Y2, CRenPar P1, CRenPar P2, CRenPar P3, CRenPar P4);
    DECL_FASTCALL_SIMPLE(RenderFlatWaterRectangle_OneLayer, _ZN11CWaterLevel33RenderFlatWaterRectangle_OneLayerEiiii7CRenParS0_S0_S0_i, void,
        i32 minX, i32 maxX, i32 Y1, i32 Y2, CRenPar P1, CRenPar P2, CRenPar P3, CRenPar P4, i32 WaterLayer);
    DECL_FASTCALL_SIMPLE(SplitWaterTriangleAlongYLine, _ZN11CWaterLevel28SplitWaterTriangleAlongYLineEiii7CRenPariiS0_iiS0_, void,
        i32 splitAt, i32 x1, i32 y1, CRenPar p1, i32 x2, i32 y2, CRenPar p2, i32 x3, i32 y3, CRenPar p3);
    DECL_FASTCALL_SIMPLE(RenderTransparentWater, _ZN11CWaterLevel22RenderTransparentWaterEv, void);
    DECL_FASTCALL_SIMPLE(RenderWakeSegment, _ZN11CWaterLevel17RenderWakeSegmentER9CVector2DS1_S1_S1_RfS2_S2_S2_S2_, void,
        CVector2D& vecA, CVector2D& vecB, CVector2D& vecC, CVector2D& vecD, float& widthA, float& widthB, float& alphaA, float& alphaB, float& wakeZ);
    DECL_FASTCALL_SIMPLE(ChangeWaterConfiguration, _ZN11CWaterLevel24ChangeWaterConfigurationEi, void, i32 NewWaterConfig);
    DECL_FASTCALL_SIMPLE(SyncWater, _ZN11CWaterLevel9SyncWaterEv, void);
    DECL_FASTCALL_SIMPLE(GetGroundLevel, _ZN11CWaterLevel14GetGroundLevelERK7CVectorPfP7ColDataf, bool, CVector const& pos, float* pGroundZ, ColData* pColData, float distance);
    DECL_FASTCALL_SIMPLE(GetGroundLevel_WS, _ZN11CWaterLevel17GetGroundLevel_WSERK7CVectorPfP7ColDataf, bool, CVector const& pos, float* pGroundZ, ColData* pColData, float distance);
    DECL_FASTCALL_SIMPLE(IsLocationOutOfWorldBounds_WS, _ZN11CWaterLevel29IsLocationOutOfWorldBounds_WSERK7CVectori, bool, CVector const& pos, i32 distance);
    DECL_FASTCALL_SIMPLE(GetWaterDepth, _ZN11CWaterLevel13GetWaterDepthERK7CVectorPfS3_S3_, bool,
        CVector const& vecPos, float* pOutWaterDepth, float* pOutWaterLevel, float* pOutGroundLevel);
    DECL_FASTCALL_SIMPLE(RenderWaterFog, _ZN11CWaterLevel14RenderWaterFogEv, void);
    DECL_FASTCALL_SIMPLE(RenderShipsOnHorizon, _ZN11CWaterLevel20RenderShipsOnHorizonEv, void);
    DECL_FASTCALL_SIMPLE(CreateBeachToy, _ZN11CWaterLevel14CreateBeachToyERK7CVector9eBeachToy, CObject*, CVector const& pos, eBeachToy beachToy);

    // Helper functions
    static void AddWaveToResult(float x, float y, float* pWaterZ, float bigWaves, float smallWaves, CVector* pNormal)
    {
        return AddWaveToResult1(x, y, pWaterZ, bigWaves, smallWaves, pNormal);
    }
    static void AddWaveToResult(i32 x, i32 y, float* pWaterZ, float bigWaves, float smallWaves)
    {
        return AddWaveToResult2(x, y, pWaterZ, bigWaves, smallWaves);
    }

    // STATIC values
    DECL_VALUE_PLT_BOOL(m_bWaterFog, BYBIT(0x676724, 0x84AEA0));
    DECL_VALUE_PLT_BOOL(m_bWaterFogScript, BYBIT(0x675F58, 0x849F20));
    DECL_VALUE_SYM_I32(m_WaterFogHourOfDayStart, _ZN11CWaterLevel24m_WaterFogHourOfDayStartE);
    DECL_VALUE_SYM_I32(m_WaterFogHourOfDayEnd, _ZN11CWaterLevel22m_WaterFogHourOfDayEndE);
    DECL_VALUE_PLT_I32(m_WaterFogDensity, BYBIT(0x67649C, 0x84A990));
    DECL_VALUE_PLT_FLT(m_fWaterFogHeight, BYBIT(0x6760AC, 0x84A1C8));
    DECL_VALUE_PLT_FLT(m_fWaterFogInsideFadeSpeed, BYBIT(0x6771E8, 0x84C408));
    DECL_VALUE_PLT_I32(m_nNumOfWaterTriangles, BYBIT(0x677150, 0x84C2D8));
    DECL_VALUE_PLT_I32(m_nNumOfWaterQuads, BYBIT(0x6762B4, 0x84A5C8));
    DECL_OBJECT_ARRAY_PLT(CWaterTriangle, m_aTriangles, BYBIT(0x676054, 0x84A118));
    DECL_OBJECT_ARRAY_PLT(CWaterQuad, m_aQuads, BYBIT(0x679620, 0x850C50));
    DECL_VALUE_PLT_I32(m_nNumOfWaterVertices, BYBIT(0x676604, 0x84AC60));
    DECL_OBJECT_ARRAY_PLT(CWaterVertex, m_aVertices, BYBIT(0x678980, 0x84F320));
    DECL_OBJECT_ARRAY_PLT(tWaterQuadTriangleBlock, m_QuadsAndTrianglesInEachBlock, BYBIT(0x676154, 0x84A308));
    DECL_OBJECT_ARRAY_PLT(u16, m_QuadsAndTrianglesList, BYBIT(0x678E14, 0x84FC50));
    DECL_VALUE_PLT_I32(m_ElementsOnQuadsAndTrianglesList, BYBIT(0x679E18, 0x851C40));
    DECL_VALUE_PLT_I32(m_NumBlocksOutsideWorldToBeRendered, BYBIT(0x678A04, 0x84F428));
    DECL_OBJECT_ARRAY_PLT(i16, m_BlocksToBeRenderedOutsideWorldX, BYBIT(0x6777C4, 0x84CFB0));
    DECL_OBJECT_ARRAY_PLT(i16, m_BlocksToBeRenderedOutsideWorldY, BYBIT(0x678A84, 0x84F530));
    DECL_VALUE_PLT_FLT(m_CurrentFlowX, BYBIT(0x679C00, 0x851818));
    DECL_VALUE_PLT_FLT(m_CurrentFlowY, BYBIT(0x678DD0, 0x84FBC8));
    DECL_VALUE_PLT_FLT(m_CurrentDesiredFlowX, BYBIT(0x6789CC, 0x84F3B8));
    DECL_VALUE_PLT_FLT(m_CurrentDesiredFlowY, BYBIT(0x679BC4, 0x8517A8));
    DECL_VALUE_PLT_I32(m_nWaterConfiguration, BYBIT(0x67909C, 0x850160));
    DECL_VALUE_PLT_U32(m_nWaterTimeOffset, BYBIT(0x6771DC, 0x84C3F0));
    DECL_OBJECT_PLT(CRGBA, m_WaterFogCol, BYBIT(0x678430, 0x84E878));
    DECL_OBJECT_PLT(CRGBA, m_WaterFogInsideCol, BYBIT(0x6798FC, 0x851218));
    DECL_OBJECT_PLT(tWaterFog, ms_WaterFog, BYBIT(0x6779A0, 0x84D370));
DECL_CLASS_END()

#define m_bWaterFog m_bWaterFog()
#define m_bWaterFogScript m_bWaterFogScript()
#define m_WaterFogHourOfDayStart m_WaterFogHourOfDayStart()
#define m_WaterFogHourOfDayEnd m_WaterFogHourOfDayEnd()
#define m_WaterFogDensity m_WaterFogDensity()
#define m_fWaterFogHeight m_fWaterFogHeight()
#define m_fWaterFogInsideFadeSpeed m_fWaterFogInsideFadeSpeed()
#define m_nNumOfWaterTriangles m_nNumOfWaterTriangles()
#define m_nNumOfWaterQuads m_nNumOfWaterQuads()
#define m_aTriangles m_aTriangles()
#define m_aQuads m_aQuads()
#define m_nNumOfWaterVertices m_nNumOfWaterVertices()
#define m_aVertices m_aVertices()
#define m_QuadsAndTrianglesInEachBlock m_QuadsAndTrianglesInEachBlock()
#define m_QuadsAndTrianglesList m_QuadsAndTrianglesList()
#define m_ElementsOnQuadsAndTrianglesList m_ElementsOnQuadsAndTrianglesList()
#define m_NumBlocksOutsideWorldToBeRendered m_NumBlocksOutsideWorldToBeRendered()
#define m_BlocksToBeRenderedOutsideWorldX m_BlocksToBeRenderedOutsideWorldX()
#define m_BlocksToBeRenderedOutsideWorldY m_BlocksToBeRenderedOutsideWorldY()
#define m_CurrentFlowX m_CurrentFlowX()
#define m_CurrentFlowY m_CurrentFlowY()
#define m_CurrentDesiredFlowX m_CurrentDesiredFlowX()
#define m_CurrentDesiredFlowY m_CurrentDesiredFlowY()
#define m_nWaterConfiguration m_nWaterConfiguration()
#define m_nWaterTimeOffset m_nWaterTimeOffset()
#define m_WaterFogCol m_WaterFogCol()
#define m_WaterFogInsideCol m_WaterFogInsideCol()
#define ms_WaterFog ms_WaterFog()

#endif // __AML_PSDK_SAWATERLEVEL_H
