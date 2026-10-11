#ifndef __AML_PSDK_SAGRIDREF_H
#define __AML_PSDK_SAGRIDREF_H

#include <aml-psdk/game_sa/plugin.h>
#include <aml-psdk/gta_base/Vector.h>

DECL_CLASS(CGridRef)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(Init, _ZN8CGridRef4InitEv, void);
    DECL_FASTCALL_SIMPLE(GetGridRefPositions1, _ZN8CGridRef19GetGridRefPositionsE7CVectorPhS1_, void, CVector posn, u8* outSectorX, u8* outSectorY);
    DECL_FASTCALL_SIMPLE(GetGridRefPositions2, _ZN8CGridRef19GetGridRefPositionsEPhS0_, void, u8* outSectorX, u8* outSectorY);
    DECL_FASTCALL_SIMPLE(GetAreaName, _ZN8CGridRef11GetAreaNameEhh, char*, u8 sectorX, u8 sectorY);
    DECL_FASTCALL_SIMPLE(GetArtistBugstarID, _ZN8CGridRef18GetArtistBugstarIDEhh, i32, u8 sectorX, u8 sectorY);

    // Helper functions
    static void GetGridRefPositions(CVector posn, u8* outSectorX, u8* outSectorY)
    {
        return GetGridRefPositions1(posn, outSectorX, outSectorY);
    }
    static void GetGridRefPositions(u8* outSectorX, u8* outSectorY)
    {
        return GetGridRefPositions2(outSectorX, outSectorY);
    }

    // STATIC values
    DECL_OBJECT_SYM(u8, displayWalls, _ZN8CGridRef12displayWallsE);
    DECL_OBJECT_SYM(u8, displayAllTheWalls, _ZN8CGridRef18displayAllTheWallsE);
    DECL_OBJECT_SYM(u8, displayCamCords, _ZN8CGridRef15displayCamCordsE);
    DECL_OBJECT_SYM(u8, displayGridRef, _ZN8CGridRef14displayGridRefE);
DECL_CLASS_END()

#define displayWalls displayWalls()
#define displayAllTheWalls displayAllTheWalls()
#define displayCamCords displayCamCords()
#define displayGridRef displayGridRef()

#endif // __AML_PSDK_SAGRIDREF_H
