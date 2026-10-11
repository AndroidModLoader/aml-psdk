#ifndef __AML_PSDK_SAROADBLOCKS_H
#define __AML_PSDK_SAROADBLOCKS_H

/*
    Plugin-SDK (Grand Theft Auto San Andreas) header file
    Authors: GTA Community. See more here
    https://github.com/DK22Pac/plugin-sdk
    Do not delete this comment block. Respect others' work!
*/

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/gta_base/Vector.h>
#include <aml-psdk/game_sa/base/Lists.h>
#include <aml-psdk/game_sa/enum/PedEnums.h>

struct CVehicle;

struct tScriptRoadBlocks
{
    CVector cornerA;
    CVector cornerB;
    u8 m_nActive;
    u8 m_bIsCreated;
    u8 type;
};
CHECKSIZE(tScriptRoadBlocks, 0x1C, 0x1C);

DECL_CLASS(CRoadBlocks)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(Init, _ZN11CRoadBlocks4InitEv, void);
    DECL_FASTCALL_SIMPLE(ClearScriptRoadBlocks, _ZN11CRoadBlocks21ClearScriptRoadBlocksEv, void);
    DECL_FASTCALL_SIMPLE(GenerateRoadBlocks, _ZN11CRoadBlocks18GenerateRoadBlocksEv, void);
    DECL_FASTCALL_SIMPLE(GetRoadBlockNodeInfo, _ZN11CRoadBlocks20GetRoadBlockNodeInfoE12CNodeAddressRfR7CVector, bool, CNodeAddress nodeAddress, float& outWidth, CVector& outDir);
    DECL_FASTCALL_SIMPLE(CreateRoadBlockBetween2Points, _ZN11CRoadBlocks29CreateRoadBlockBetween2PointsE7CVectorS0_j, void, CVector a, CVector b, u32 isGangRoadBlock);
    DECL_FASTCALL_SIMPLE(GenerateRoadBlockPedsForCar, _ZN11CRoadBlocks27GenerateRoadBlockPedsForCarEP8CVehiclei8ePedType, bool,
        CVehicle* vehicle, i32 orientationToCar, ePedType pedType);
    DECL_FASTCALL_SIMPLE(ClearSpaceForRoadBlockObject, _ZN11CRoadBlocks28ClearSpaceForRoadBlockObjectE7CVectorS0_, bool, CVector cornerA, CVector cornerB);
    DECL_FASTCALL_SIMPLE(RegisterScriptRoadBlock, _ZN11CRoadBlocks23RegisterScriptRoadBlockE7CVectorS0_b, void, CVector cornerA, CVector cornerB, bool isGangRoadBlock);

    // STATIC values
    DECL_VALUE_PLT_I32(NumRoadBlocks, BYBIT(0x679350, 0x8506B8));
    DECL_OBJECT_ARRAY_PLT(CNodeAddress, RoadBlockNodes, BYBIT(0x679B30, 0x851680));
    DECL_OBJECT_ARRAY_PLT(u8, InOrOut, BYBIT(0x676B80, 0x84B748));
    DECL_OBJECT_ARRAY_PLT(tScriptRoadBlocks, aScriptRoadBlocks, BYBIT(0x676FD0, 0x84BFD8));
    DECL_VALUE_PLT_BOOL(bGenerateDynamicRoadBlocks, BYBIT(0x6776C4, 0x84CDB8));
DECL_CLASS_END()

#define NumRoadBlocks NumRoadBlocks()
#define RoadBlockNodes RoadBlockNodes()
#define InOrOut InOrOut()
#define aScriptRoadBlocks aScriptRoadBlocks()
#define bGenerateDynamicRoadBlocks bGenerateDynamicRoadBlocks()

#endif // __AML_PSDK_SAROADBLOCKS_H
