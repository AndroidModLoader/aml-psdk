#ifndef __AML_PSDK_SASHOTINFO_H
#define __AML_PSDK_SASHOTINFO_H

/*
    Plugin-SDK (Grand Theft Auto San Andreas) header file
    Authors: GTA Community. See more here
    https://github.com/DK22Pac/plugin-sdk
    Do not delete this comment block. Respect others' work!
*/

#include "../plugin.h"
#include "../enum/WeaponType.h"
#include <aml-psdk/gta_base/Vector.h>

struct CEntity;

DECL_CLASS(CShotInfo)
    // STATIC functions
    DECL_FASTCALL_SIMPLE(Initialise, _ZN9CShotInfo10InitialiseEv, void);
    DECL_FASTCALL_SIMPLE(Shutdown, _ZN9CShotInfo8ShutdownEv, void);
    DECL_FASTCALL_SIMPLE(AddShot, _ZN9CShotInfo7AddShotEP7CEntity11eWeaponType7CVectorS3_, bool,
        CEntity* creator, eWeaponType weaponType, CVector origin, CVector target);
    DECL_FASTCALL_SIMPLE(GetPositionOfPossibleFlame, _ZN9CShotInfo26GetPositionOfPossibleFlameEhR7CVector, u8, u8 shotId, CVector& outPosition);
    DECL_FASTCALL_SIMPLE(Update, _ZN9CShotInfo6UpdateEv, void);

    // STATIC values
    DECL_OBJECT_ARRAY_PLT(float, ms_afRandTable, BYBIT(0x677E5C, 0x84DCD8));

    // Member values
    eWeaponType m_nWeaponType;
    CVector m_vecOrigin;
    CVector m_vecTargetOffset;
    float m_fRange;
    CEntity *m_pCreator;
    float m_fDestroyTime;
    bool m_bExist;
    bool m_bExecuted;
DECL_CLASS_END()
CHECKSIZE(CShotInfo, 0x2C, 0x30);

DECL_OBJECT_ARRAY_ADDR_GLOBAL(CShotInfo, aShotInfos, BYBIT(0xA85040, 0xD29D08));

#define ms_afRandTable ms_afRandTable()
#define aShotInfos aShotInfos()

#endif // __AML_PSDK_SASHOTINFO_H
