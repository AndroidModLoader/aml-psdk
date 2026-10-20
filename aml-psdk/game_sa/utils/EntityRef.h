#ifndef __AML_PSDK_SAENTITYREF_H
#define __AML_PSDK_SAENTITYREF_H

#include "../entity/Entity.h"
#include "../base/References.h"

template<class T = CEntity>
struct EntityRef
{
private:
    CEntity* m_pEntity = NULL;

public:
    // Game thread. The game clears registered references when the entity is deleted.
    EntityRef(T* entity = NULL) { Set(entity); }
    EntityRef(const EntityRef& other) { Set(other.Get()); }
    EntityRef(EntityRef&& other) noexcept
    {
        T* entity = other.Get();
        other.Reset();
        Set(entity);
    }
    ~EntityRef() { Reset(); }

    EntityRef& operator=(const EntityRef& other)
    {
        Set(other.Get());
        return *this;
    }

    EntityRef& operator=(EntityRef&& other) noexcept
    {
        if(this == &other) return *this;
        T* entity = other.Get();
        other.Reset();
        Set(entity);
        return *this;
    }

    EntityRef& operator=(T* entity)
    {
        Set(entity);
        return *this;
    }

    // Returns false and stays empty if the game does not register the reference.
    inline bool Set(T* entity)
    {
        if(m_pEntity == entity) return true;
        if(m_pEntity) m_pEntity->CleanUpOldReference(&m_pEntity);
        m_pEntity = entity;
        if(!m_pEntity) return true;
        m_pEntity->RegisterReference(&m_pEntity);
        for(CReference* reference = m_pEntity->m_pReferences; reference; reference = reference->m_pNext)
            if(reference->m_ppEntity == (void**)&m_pEntity) return true;
        m_pEntity = NULL;
        return false;
    }

    inline void Reset() { Set(NULL); }
    inline T* Get() const { return static_cast<T*>(m_pEntity); }
    inline T* operator->() const { return Get(); }
    inline T& operator*() const { return *Get(); }
    explicit inline operator bool() const { return m_pEntity != NULL; }
};

#endif // __AML_PSDK_SAENTITYREF_H
