#ifndef __AML_PSDK_RWOBJECT_H
#define __AML_PSDK_RWOBJECT_H

#include <aml-psdk/sdk_base.h>
#include "RwLinks.h"
#include "RwBase.h"

#define rpATOMIC 1
#define rpCLUMP 2
#define rpLIGHT 3
#define rpWORLD 7
#define rpGEOMETRY 8

struct RwFrame;
struct RwObjectHasFrame;

/* Every Rw/Rp object type, forward declared in one place. The ForAll* calls
 * cross-reference each other constantly (a world walks lights, a light walks
 * world sectors), so their callback typedefs live here too -- that keeps the
 * per-object headers from having to include each other in a cycle. */
struct RpAtomic;
struct RpClump;
struct RpGeometry;
struct RpLight;
struct RpMaterial;
struct RpMesh;
struct RpMeshHeader;
struct RpWorld;
struct RpWorldSector;
struct RwCamera;

struct RwObject
{
    RwUInt8  type;
    RwUInt8  subType;
    RwUInt8  flags;
    RwUInt8  privateFlags;
    union
    {
        void    *parent;
        RwFrame *frame; // Mostly (or always) RwFrame*
    };
};

typedef RwObject *(*RwObjectCallBack)(RwObject *object, void *data);
typedef RwObjectHasFrame * (*RwObjectHasFrameSyncFunction)(RwObjectHasFrame *object);

typedef RpAtomic       *(*RpAtomicCallBack)(RpAtomic *atomic, void *data);
typedef RpClump        *(*RpClumpCallBack)(RpClump *clump, void *data);
typedef RpLight        *(*RpLightCallBack)(RpLight *light, void *data);
typedef RpMaterial     *(*RpMaterialCallBack)(RpMaterial *material, void *data);
typedef RpMesh         *(*RpMeshCallBack)(RpMesh *mesh, RpMeshHeader *meshHeader, void *data);
typedef RpWorld        *(*RpWorldCallBack)(RpWorld *world, void *data);
typedef RpWorldSector  *(*RpWorldSectorCallBack)(RpWorldSector *sector, void *data);
typedef RpWorldSector  *(*RpWorldSectorCallBackRender)(RpWorldSector *sector);
typedef RwCamera       *(*RwCameraCallBack)(RwCamera *camera, void *data);

struct RwObjectHasFrame
{
    RwObject                     object;
    RwLLLink                     lFrame;
    RwObjectHasFrameSyncFunction sync;
};

DECL_FASTCALL_SIMPLE_GLO(_rwObjectHasFrameSetFrame, _Z25_rwObjectHasFrameSetFramePvP7RwFrame, void, void* object, RwFrame* frame);
DECL_FASTCALL_SIMPLE_GLO(_rwObjectHasFrameReleaseFrame, _Z29_rwObjectHasFrameReleaseFramePv, void, RwFrame* object);

#endif // __AML_PSDK_RWOBJECT_H