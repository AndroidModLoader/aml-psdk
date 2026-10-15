#ifndef __AML_PSDK_SAWORLDUTILS_H
#define __AML_PSDK_SAWORLDUTILS_H

#include "../engine/World.h"
#include <cstddef>

struct WorldUtils
{
    enum eSearchFlags : u32
    {
        SEARCH_BUILDINGS = 0x1,
        SEARCH_VEHICLES = 0x2,
        SEARCH_PEDS = 0x4,
        SEARCH_OBJECTS = 0x8,
        SEARCH_DUMMIES = 0x10,
        SEARCH_ALL = 0x1F,
    };

    // Results are borrowed world entities. Call on the game thread.
    static inline i16 FindInRange(const CVector& centre, float radius, CEntity** results, i32 maxNum, u32 flags, bool dist2D)
    {
        if(!results || maxNum <= 0 || !(radius >= 0.0f) || !(flags & SEARCH_ALL)) return 0;
        if(maxNum > 32767) maxNum = 32767;
        i16 count = 0;
        CWorld::FindObjectsInRange(centre, radius, dist2D, &count, maxNum, results,
            flags & SEARCH_BUILDINGS, flags & SEARCH_VEHICLES, flags & SEARCH_PEDS, flags & SEARCH_OBJECTS, flags & SEARCH_DUMMIES);
        return count;
    }

    template<size_t N>
    static inline i16 FindInRange(const CVector& centre, float radius, CEntity* (&results)[N], u32 flags = SEARCH_ALL, bool dist2D = false)
    {
        return FindInRange(centre, radius, results, N > 32767 ? 32767 : N, flags, dist2D);
    }

    static inline i16 FindOfTypeInRange(u32 modelId, const CVector& centre, float radius, CEntity** results, i32 maxNum, u32 flags, bool dist2D)
    {
        if(!results || maxNum <= 0 || !(radius >= 0.0f) || !(flags & SEARCH_ALL)) return 0;
        if(maxNum > 32767) maxNum = 32767;
        i16 count = 0;
        CWorld::FindObjectsOfTypeInRange(modelId, centre, radius, dist2D, &count, maxNum, results,
            flags & SEARCH_BUILDINGS, flags & SEARCH_VEHICLES, flags & SEARCH_PEDS, flags & SEARCH_OBJECTS, flags & SEARCH_DUMMIES);
        return count;
    }

    template<size_t N>
    static inline i16 FindOfTypeInRange(u32 modelId, const CVector& centre, float radius, CEntity* (&results)[N], u32 flags = SEARCH_ALL, bool dist2D = false)
    {
        return FindOfTypeInRange(modelId, centre, radius, results, N > 32767 ? 32767 : N, flags, dist2D);
    }

    static inline i16 FindInBox(const CVector& min, const CVector& max, CEntity** results, i32 maxNum, u32 flags)
    {
        if(!results || maxNum <= 0 || !(min.x <= max.x && min.y <= max.y && min.z <= max.z) || !(flags & SEARCH_ALL)) return 0;
        if(maxNum > 32767) maxNum = 32767;
        i16 count = 0;
        CWorld::FindObjectsIntersectingCube(min, max, &count, maxNum, results,
            flags & SEARCH_BUILDINGS, flags & SEARCH_VEHICLES, flags & SEARCH_PEDS, flags & SEARCH_OBJECTS, flags & SEARCH_DUMMIES);
        return count;
    }

    template<size_t N>
    static inline i16 FindInBox(const CVector& min, const CVector& max, CEntity* (&results)[N], u32 flags = SEARCH_ALL)
    {
        return FindInBox(min, max, results, N > 32767 ? 32767 : N, flags);
    }

    static inline CEntity* FindNearestOfType(i32 modelId, const CVector& centre, float radius, u32 flags = SEARCH_ALL, bool dist2D = false)
    {
        if(!(radius >= 0.0f) || !(flags & SEARCH_ALL)) return NULL;
        return CWorld::FindNearestObjectOfType(modelId, centre, radius, dist2D,
            flags & SEARCH_BUILDINGS, flags & SEARCH_VEHICLES, flags & SEARCH_PEDS, flags & SEARCH_OBJECTS, flags & SEARCH_DUMMIES);
    }
};

#endif // __AML_PSDK_SAWORLDUTILS_H
