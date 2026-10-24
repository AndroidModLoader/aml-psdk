#ifndef __AML_PSDK_SACLOTHES_H
#define __AML_PSDK_SACLOTHES_H

/*
    Plugin-SDK (Grand Theft Auto San Andreas) header file
    Authors: GTA Community. See more here
    https://github.com/DK22Pac/plugin-sdk
    Do not delete this comment block. Respect others' work!
*/

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/game_sa/enum/AnimGroup.h>
#include <aml-psdk/renderware/RwRGBA.h>

struct CPlayerPed;
struct RwTexture;
struct RwTexDictionary;
struct RwMatrixWeights;
struct RpClump;
struct RpGeometry;
struct RpMaterial;
struct RpHAnimHierarchy;

enum ePlayerClothesModels
{
    CLOTHES_SHIRT = 0,
    CLOTHES_HEAD = 1,
    CLOTHES_HANDS = 2,
    CLOTHES_TROUSERS = 3,
    CLOTHES_SHOES = 4,
    CLOTHES_NECKLACE = 5,
    CLOTHES_WATCH = 6,
    CLOTHES_GLASSES = 7,
    CLOTHES_HAT = 8,
    CLOTHES_EXTRA1 = 9,
    CLOTHES_MAX_MODELS = 10,
};

enum ePlayerClothesTextures
{
    CLOTHES_TEX_SHIRT = 0,
    CLOTHES_TEX_HEAD = 1,
    CLOTHES_TEX_TROUSERS = 2,
    CLOTHES_TEX_SHOES = 3,
    CLOTHES_TEX_TATTOOS1 = 4,
    CLOTHES_TEX_TATTOOS2 = 5,
    CLOTHES_TEX_TATTOOS3 = 6,
    CLOTHES_TEX_TATTOOS4 = 7,
    CLOTHES_TEX_TATTOOS5 = 8,
    CLOTHES_TEX_TATTOOS6 = 9,
    CLOTHES_TEX_TATTOOS7 = 10,
    CLOTHES_TEX_TATTOOS8 = 11,
    CLOTHES_TEX_TATTOOS9 = 12,
    CLOTHES_TEX_NECKLACE = 13,
    CLOTHES_TEX_WATCH = 14,
    CLOTHES_TEX_GLASSES = 15,
    CLOTHES_TEX_HAT = 16,
    CLOTHES_TEX_EXTRA1 = 17,
    CLOTHES_MAX_TEXTURES = 18,
};

DECL_CLASS(CPedClothesDesc)
    // Construct functions
    DECL_CTORCALL(CPedClothesDesc, _ZN15CPedClothesDescC2Ev);

    // Member functions
    DECL_THISCALL_SIMPLE(Initialise, _ZN15CPedClothesDesc10InitialiseEv, void);
    DECL_THISCALL_NAMED_HEAD(SetTextureAndModel1, SetTextureAndModel, _ZN15CPedClothesDesc18SetTextureAndModelEjji, void, u32 texture, u32 model, i32 texturePart)
    DECL_THISCALL_TAIL(SetTextureAndModel1, texture, model, texturePart)
    DECL_THISCALL_NAMED_HEAD(SetTextureAndModel2, SetTextureAndModel, _ZN15CPedClothesDesc18SetTextureAndModelEPKcS1_i, void, char const* texturename, char const* modelname, i32 texturePart)
    DECL_THISCALL_TAIL(SetTextureAndModel2, texturename, modelname, texturePart)
    DECL_THISCALL_NAMED_HEAD(SetModel1, SetModel, _ZN15CPedClothesDesc8SetModelEji, void, u32 modelid, i32 modelPart)
    DECL_THISCALL_TAIL(SetModel1, modelid, modelPart)
    DECL_THISCALL_NAMED_HEAD(SetModel2, SetModel, _ZN15CPedClothesDesc8SetModelEPKci, void, char const* model, i32 modelPart)
    DECL_THISCALL_TAIL(SetModel2, model, modelPart)
    DECL_THISCALL_SIMPLE(GetIsWearingBalaclava, _ZN15CPedClothesDesc21GetIsWearingBalaclavaEv, bool);
    DECL_THISCALL(HasVisibleNewHairCut, _ZN15CPedClothesDesc20HasVisibleNewHairCutEi, bool, int arg1);
    DECL_THISCALL_SIMPLE(HasVisibleTattoo, _ZN15CPedClothesDesc16HasVisibleTattooEv, bool);

    // Member values
    u32 m_anModelKeys[10];
    u32 m_anTextureKeys[18];
    float m_fFatStat;
    float m_fMuscleStat;
DECL_CLASS_END()
CHECKSIZE(CPedClothesDesc, 0x78, 0x78);

DECL_CLASS(CClothes)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(RebuildPlayer, _ZN8CClothes13RebuildPlayerEP10CPlayerPedb, void, CPlayerPed* player, bool bIgnoreFatAndMuscle);
    DECL_FASTCALL_SIMPLE(RebuildCutscenePlayer, _ZN8CClothes21RebuildCutscenePlayerEP10CPlayerPedi, void, CPlayerPed* player, i32 modelid);
    DECL_FASTCALL_SIMPLE(ConstructPedModel, _ZN8CClothes17ConstructPedModelEjR15CPedClothesDescPKS0_b, void,
        u32 modelid, CPedClothesDesc& newclothes, CPedClothesDesc const* oldclothes, bool bCutscenePlayer);
    DECL_FASTCALL_SIMPLE(RebuildPlayerIfNeeded, _ZN8CClothes21RebuildPlayerIfNeededEP10CPlayerPed, void, CPlayerPed* player);
    DECL_FASTCALL_SIMPLE(Init, _ZN8CClothes4InitEv, void);
    DECL_FASTCALL_SIMPLE(GetDefaultPlayerMotionGroup, _ZN8CClothes27GetDefaultPlayerMotionGroupEv, AssocGroupId);
    DECL_FASTCALL_SIMPLE(GetPlayerMotionGroupToLoad, _ZN8CClothes26GetPlayerMotionGroupToLoadEv, AssocGroupId);
    DECL_FASTCALL_SIMPLE(RequestMotionGroupAnims, _ZN8CClothes23RequestMotionGroupAnimsEv, void);
    DECL_FASTCALL_SIMPLE(GetTextureDependency, _ZN8CClothes20GetTextureDependencyEi, ePlayerClothesModels, i32 texturePart);
    DECL_FASTCALL_SIMPLE(GetDependentTexture, _ZN8CClothes19GetDependentTextureEi, ePlayerClothesTextures, i32 modelPart);
    DECL_FASTCALL_SIMPLE(LoadClothesFile, _ZN8CClothes15LoadClothesFileEv, void);

    // STATIC values
    DECL_OBJECT_ARRAY_PLT(u32, ms_clothesRules, BYBIT(0x677DE4, 0x84DBE8));
    DECL_OBJECT_PLT(u32, ms_numRuleTags, BYBIT(0x67722C, 0x84C490));
    DECL_OBJECT_PLT(i32, ms_clothesImageId, BYBIT(0x678108, 0x84E228));
DECL_CLASS_END()
CHECKSIZE(CClothes, 0x1, 0x1);

DECL_CLASS(CClothesBuilder)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(CopyTexture, _ZN15CClothesBuilder11CopyTextureEP9RwTexture, RwTexture*, RwTexture* texture);
    DECL_FASTCALL_SIMPLE(CreateSkinnedClump, _ZN15CClothesBuilder18CreateSkinnedClumpEP7RpClumpP15RwTexDictionaryR15CPedClothesDescPKS4_b, RpClump*,
        RpClump* clump, RwTexDictionary* dict, CPedClothesDesc& newclothes, CPedClothesDesc const* oldclothes, bool bCutscenePlayer);
    DECL_FASTCALL_SIMPLE(ConstructTextures, _ZN15CClothesBuilder17ConstructTexturesEP15RwTexDictionaryPjfff, void,
        RwTexDictionary* dict, u32* hashes, float factorA, float factorB, float factorC);
    DECL_FASTCALL_SIMPLE(ConstructGeometryArray, _ZN15CClothesBuilder22ConstructGeometryArrayEPP10RpGeometryPjfff, void,
        RpGeometry** arg1, u32* arg2, float arg3, float arg4, float arg5);
    DECL_FASTCALL_SIMPLE(PreprocessClothesDesc, _ZN15CClothesBuilder21PreprocessClothesDescER15CPedClothesDescb, void, CPedClothesDesc& arg1, bool arg2);
    DECL_FASTCALL_SIMPLE(LoadCdDirectory, _ZN15CClothesBuilder15LoadCdDirectoryEv, void);
    DECL_FASTCALL_SIMPLE(RequestGeometry, _ZN15CClothesBuilder15RequestGeometryEij, void, i32 modelid, u32 crc);
    DECL_FASTCALL_SIMPLE(StoreBoneArray, _ZN15CClothesBuilder14StoreBoneArrayEP7RpClumpi, void, RpClump* clump, i32 arg2);
    DECL_FASTCALL_SIMPLE(ReleaseGeometry, _ZN15CClothesBuilder15ReleaseGeometryEi, void, i32 numToRelease);
    DECL_FASTCALL_SIMPLE(BlendGeometry1, _ZN15CClothesBuilder13BlendGeometryEP7RpClumpPKcS3_S3_fff, RpGeometry*,
        RpClump* clump, char const* arg2, char const* arg3, char const* arg4, float arg5, float arg6, float arg7);
    DECL_FASTCALL_SIMPLE(BlendGeometry2, _ZN15CClothesBuilder13BlendGeometryEP7RpClumpPKcS3_ff, RpGeometry*,
        RpClump* clump, char const* arg2, char const* arg3, float arg4, float arg5);
    inline static RpGeometry* BlendGeometry(RpClump* clump, char const* name, char const* name2, char const* name3, float factorA, float factorB, float factorC)
    {
        return BlendGeometry1(clump, name, name2, name3, factorA, factorB, factorC);
    }
    inline static RpGeometry* BlendGeometry(RpClump* clump, char const* name, char const* name2, float factorA, float factorB)
    {
        return BlendGeometry2(clump, name, name2, factorA, factorB);
    }
    DECL_FASTCALL_SIMPLE(CopyGeometry, _ZN15CClothesBuilder12CopyGeometryEP7RpClumpPKcS3_, RpGeometry*, RpClump* clump, char const* arg2, char const* arg3);
    DECL_FASTCALL_SIMPLE(ConstructGeometryAndSkinArrays, _ZN15CClothesBuilder30ConstructGeometryAndSkinArraysEP16RpHAnimHierarchyPP10RpGeometryPP15RwMatrixWeightsPPjjS4_PP10RpMaterial, void,
        RpHAnimHierarchy* arg1, RpGeometry** arg2, RwMatrixWeights** arg3, u32** arg4, u32 arg5, RpGeometry** arg6, RpMaterial** arg7);
    DECL_FASTCALL_SIMPLE(DestroySkinArrays, _ZN15CClothesBuilder17DestroySkinArraysEP15RwMatrixWeightsPj, void, RwMatrixWeights* arg1, u32* arg2);
    DECL_FASTCALL_SIMPLE(BuildBoneIndexConversionTable, _ZN15CClothesBuilder29BuildBoneIndexConversionTableEPhP16RpHAnimHierarchyi, void,
        u8* arg1, RpHAnimHierarchy* arg2, i32 arg3);
    DECL_FASTCALL_SIMPLE(PlaceTextureOnTopOfTexture, _ZN15CClothesBuilder26PlaceTextureOnTopOfTextureEP9RwTextureS1_b, void,
        RwTexture* texture1, RwTexture* texture2, bool arg3);
    DECL_FASTCALL_SIMPLE(BlendTextures1, _ZN15CClothesBuilder13BlendTexturesEP9RwTextureS1_ffi, void,
        RwTexture* texture1, RwTexture* texture2, float arg3, float arg4, i32 arg5);
    DECL_FASTCALL_SIMPLE(BlendTextures2, _ZN15CClothesBuilder13BlendTexturesEP9RwTextureS1_S1_fffi, void,
        RwTexture* texture1, RwTexture* texture2, RwTexture* texture3, float factorA, float factorB, float factorC, i32 arg7);
    DECL_FASTCALL_SIMPLE(BlendTextures3, _ZN15CClothesBuilder13BlendTexturesEP9RwTextureS1_S1_fffiS1_, void,
        RwTexture* texture1, RwTexture* texture2, RwTexture* texture3, float factorA, float factorB, float factorC, i32 arg7, RwTexture* texture4);
    inline static void BlendTextures(RwTexture* texture1, RwTexture* texture2, float factorA, float factorB, i32 arg5)
    {
        BlendTextures1(texture1, texture2, factorA, factorB, arg5);
    }
    inline static void BlendTextures(RwTexture* texture1, RwTexture* texture2, RwTexture* texture3, float factorA, float factorB, float factorC, i32 arg7)
    {
        BlendTextures2(texture1, texture2, texture3, factorA, factorB, factorC, arg7);
    }
    inline static void BlendTextures(RwTexture* texture1, RwTexture* texture2, RwTexture* texture3, float factorA, float factorB, float factorC, i32 arg7, RwTexture* texture4)
    {
        BlendTextures3(texture1, texture2, texture3, factorA, factorB, factorC, arg7, texture4);
    }
    DECL_FASTCALL_SIMPLE(ReducePaletteSize, _ZN15CClothesBuilder17ReducePaletteSizeEP9RwTexturei, void, RwTexture* texture, i32 numColorsToReduce);
    DECL_FASTCALL_SIMPLE(InitPaletteOctTree, _ZN15CClothesBuilder18InitPaletteOctTreeEi, void, i32 numColors);
    DECL_FASTCALL_SIMPLE(ShutdownPaletteOctTree, _ZN15CClothesBuilder22ShutdownPaletteOctTreeEv, void);
    DECL_FASTCALL_SIMPLE(ReducePaletteOctTree, _ZN15CClothesBuilder20ReducePaletteOctTreeEi, void, i32 numColorsToReduce);
    DECL_FASTCALL_SIMPLE(AddColour, _ZN15CClothesBuilder9AddColourEP6RwRGBA, void, RwRGBA* color);
    DECL_FASTCALL_SIMPLE(FillPalette, _ZN15CClothesBuilder11FillPaletteEP6RwRGBA, void, RwRGBA* color);
    DECL_FASTCALL_SIMPLE(FindNearestColour, _ZN15CClothesBuilder17FindNearestColourEP6RwRGBA, i32, RwRGBA* color);
    DECL_FASTCALL_SIMPLE(GetClothesTexture, _ZN15CClothesBuilder17GetClothesTextureEjPKc, RwTexture*, u32 key, char const* pName);
    DECL_FASTCALL_SIMPLE(PutOnClothes, _ZN15CClothesBuilder12PutOnClothesEP9RwTextureS1_b, RwTexture*, RwTexture* texture1, RwTexture* texture2, bool arg3);

    // STATIC values
    DECL_OBJECT_PLT(CPedClothesDesc const*, ms_pOldClothesState, BYBIT(0x678648, 0x84ECB8));
    DECL_OBJECT_PLT(bool, ms_ratiosHaveChanged, BYBIT(0x6765FC, 0x84AC50));
    DECL_OBJECT_PLT(bool, ms_geometryHasChanged, BYBIT(0x67941C, 0x850850));
    DECL_OBJECT_PLT(bool, ms_textureHasChanged, BYBIT(0x677BE8, 0x84D7F0));
DECL_CLASS_END()
CHECKSIZE(CClothesBuilder, 0x1, 0x1);

#define ms_clothesRules ms_clothesRules()
#define ms_numRuleTags ms_numRuleTags()
#define ms_clothesImageId ms_clothesImageId()
#define ms_pOldClothesState ms_pOldClothesState()
#define ms_ratiosHaveChanged ms_ratiosHaveChanged()
#define ms_geometryHasChanged ms_geometryHasChanged()
#define ms_textureHasChanged ms_textureHasChanged()

#endif // __AML_PSDK_SACLOTHES_H
