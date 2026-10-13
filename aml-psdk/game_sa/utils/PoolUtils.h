#ifndef __AML_PSDK_SAPOOLUTILS_H
#define __AML_PSDK_SAPOOLUTILS_H

#include "../other/Pools.h"

struct PoolUtils
{
    template<class A, class B>
    static inline int GetIndex(CPool<A, B>* pool, A* object)
    {
        if(!pool || !object || !pool->m_pObjects || !pool->m_byteMap || pool->m_nSize <= 0) return -1;
        uintptr_t base = (uintptr_t)pool->m_pObjects;
        uintptr_t address = (uintptr_t)object;
        if(address < base) return -1;
        uintptr_t offset = address - base;
        if(offset % sizeof(B) || offset / sizeof(B) >= (uintptr_t)pool->m_nSize) return -1;
        return offset / sizeof(B);
    }

    template<class A, class B>
    static inline bool GetRef(CPool<A, B>* pool, A* object, int& ref)
    {
        int index = GetIndex(pool, object);
        if(index < 0 || pool->m_byteMap[index].bEmpty)
        {
            ref = -1;
            return false;
        }
        ref = (index << 8) | pool->m_byteMap[index].nValue;
        return true;
    }

    template<class A, class B>
    static inline A* GetAtRef(CPool<A, B>* pool, int ref)
    {
        if(!pool || ref < 0 || !pool->m_pObjects || !pool->m_byteMap) return NULL;
        int index = ref >> 8;
        if(index >= pool->m_nSize || pool->m_byteMap[index].bEmpty || pool->m_byteMap[index].nValue != (ref & 0xFF)) return NULL;
        return (A*)&pool->m_pObjects[index];
    }

    template<class A, class B, typename Fn>
    static inline void ForEach(CPool<A, B>* pool, Fn fn)
    {
        if(!pool || !pool->m_pObjects || !pool->m_byteMap) return;
        for(int i = 0; i < pool->m_nSize; ++i)
        {
            if(!pool->m_byteMap[i].bEmpty) fn((A*)&pool->m_pObjects[i]);
        }
    }

    template<class A, class B, typename Fn>
    static inline A* Find(CPool<A, B>* pool, Fn fn)
    {
        if(!pool || !pool->m_pObjects || !pool->m_byteMap) return NULL;
        for(int i = 0; i < pool->m_nSize; ++i)
        {
            if(pool->m_byteMap[i].bEmpty) continue;
            A* object = (A*)&pool->m_pObjects[i];
            if(fn(object)) return object;
        }
        return NULL;
    }

    template<typename Fn> static inline void ForEachPed(Fn fn) { ForEach(CPools::ms_pPedPool, fn); }
    template<typename Fn> static inline void ForEachVehicle(Fn fn) { ForEach(CPools::ms_pVehiclePool, fn); }
    template<typename Fn> static inline void ForEachObject(Fn fn) { ForEach(CPools::ms_pObjectPool, fn); }
    template<typename Fn> static inline void ForEachBuilding(Fn fn) { ForEach(CPools::ms_pBuildingPool, fn); }
    template<typename Fn> static inline void ForEachDummy(Fn fn) { ForEach(CPools::ms_pDummyPool, fn); }
};

#endif // __AML_PSDK_SAPOOLUTILS_H
