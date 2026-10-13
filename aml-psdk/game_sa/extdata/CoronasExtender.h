#ifndef __AML_PSDK_SACORONASEXTENDER_H
#define __AML_PSDK_SACORONASEXTENDER_H

#include <aml-psdk/game_sa/other/Coronas.h>
#include <aml-psdk/game_sa/other/Weather.h>
#include <aml-psdk/game_sa/entity/Camera.h>
#include <aml-psdk/game_sa/entity/Bike.h>
#include <aml-psdk/game_sa/engine/World.h>
#include <aml-psdk/game_sa/engine/Game.h>
#include <aml-psdk/game_sa/engine/Sprite.h>
#include <aml-psdk/game_sa/base/Timer.h>
#include <aml-psdk/game_sa/engine/RsGlobal.h>
#include <aml-psdk/renderware/RwRender.h>
#include "../Events.h"

#ifndef MAX_EXT_CORONAS_STORAGE
    #define MAX_EXT_CORONAS_STORAGE 16 // Set your value there. Keep it as low as possible to be optimised :)
#endif

struct CoronasExtender
{
    CoronasExtender()
    {
        Events::renderCoronasEvent.after += DrawExtCoronasCB;
        Events::updateCoronasEvent.after += UpdateExtCoronasCB;
        Events::reInitGameEvent.before += Clear;
        Events::shutdownGameEvent.before += Clear;
    }

    // The functions you should use
    static inline CRegisteredCorona* FindCorona(uintptr_t ID)
    {
        if(!ID) return NULL;
        for(int i = 0; i < MAX_EXT_CORONAS_STORAGE; ++i)
        {
            if(m_aCoronas[i].m_dwId == ID) return &m_aCoronas[i];
        }
        return NULL;
    }
    static inline void RemoveCorona(CRegisteredCorona* corona)
    {
        if(!corona || !corona->m_dwId) return;
        if(corona->m_pAttachedTo) corona->m_pAttachedTo->CleanUpOldReference(&corona->m_pAttachedTo);
        memset(corona, 0, sizeof(*corona));
        --m_nCoronasNum;
    }
    static inline bool RemoveCorona(uintptr_t ID)
    {
        CRegisteredCorona* corona = FindCorona(ID);
        if(!corona) return false;
        RemoveCorona(corona);
        return true;
    }
    static inline void Clear()
    {
        for(int i = 0; i < MAX_EXT_CORONAS_STORAGE; ++i) RemoveCorona(&m_aCoronas[i]);
        m_nCoronasNum = 0;
    }
    static inline int GetCount() { return m_nCoronasNum; }
    static inline int GetCapacity() { return MAX_EXT_CORONAS_STORAGE; }
    static inline CVector GetWorldPosition(CVector const& Coors, CEntity* pAttachedToEntity)
    {
        if(!pAttachedToEntity) return Coors;
        CMatrix* mat = pAttachedToEntity->GetMatrix();
        if(mat)
        {
            if(pAttachedToEntity->IsVehicle() && pAttachedToEntity->AsVehicle()->IsSubBike())
            {
                mat = &pAttachedToEntity->AsVehicle()->AsBike()->m_mLeanMatrix;
            }
            return *mat * Coors + mat->GetPosition();
        }
        return pAttachedToEntity->GetPosition() + pAttachedToEntity->GetRightDirection() * Coors.x +
            pAttachedToEntity->GetTopDirection() * Coors.y + CVector(0.0f, 0.0f, Coors.z);
    }
    static inline void RegisterCorona(uintptr_t ID, CVector const& Coors, CRGBA const& Color, float Size, float Range,
        eCoronaType CoronaType = CORONATYPE_SHINYSTAR, CEntity* pAttachedToEntity = NULL)
    {
        RegisterCorona(ID, pAttachedToEntity, Color.r, Color.g, Color.b, Color.a, Coors, Size, Range, CoronaType,
            FLARETYPE_NONE, 0, 0, 0, 0.0f, false, 0.0f, true, 15.0f, false, false);
    }
    static inline void RegisterCorona(uintptr_t ID, CEntity *pAttachedToEntity, u8 R, u8 G, u8 B, u8 Intensity, CVector const& Coors, float Size,
        float Range, eCoronaType CoronaType, eCoronaFlareType FlareType, u8 ReflType, u8 LOSCheck, u8 UsesTrails, float fNormalAngle,
        bool bNeonFade, float ArgPullTowardsCam, bool bFullBrightAtStart, float FadeSpeed, bool bOnlyFromBelow, bool bWhiteCore)
    {
        if(CoronaType < CORONATYPE_SHINYSTAR || CoronaType >= CORONATYPE_NONE) return;
        RegisterCorona(ID, pAttachedToEntity, R, G, B, Intensity, Coors, Size, Range, gpCoronaTexture[CoronaType], FlareType, ReflType, LOSCheck,
            UsesTrails, fNormalAngle, bNeonFade, ArgPullTowardsCam, bFullBrightAtStart, FadeSpeed, bOnlyFromBelow, bWhiteCore);
    }
    
    static inline void RegisterCorona(uintptr_t ID, CEntity *pAttachedToEntity, u8 R, u8 G, u8 B, u8 Intensity, CVector const& Coors, float Size,
        float Range, RwTexture *pCoronaTex, eCoronaFlareType FlareType, u8 ReflType, u8 LOSCheck, u8 UsesTrails, float fNormalAngle,
        bool bNeonFade, float ArgPullTowardsCam, bool bFullBrightAtStart, float FadeSpeed, bool bOnlyFromBelow, bool bWhiteCore)
    {
        if(!ID || Range <= 0.0f) return;
        CVector worldPos = GetWorldPosition(Coors, pAttachedToEntity);

        const CVector& camPos = TheCamera.GetPosition();
        if(SQ(Range) < (camPos - worldPos).MagnitudeSqr2D()) return;

        u8 alpha = Intensity;
        if(bNeonFade)
        {
            float distance3dSq = (camPos - worldPos).MagnitudeSqr();
            if (distance3dSq < SQ(35.0f)) return;
            if (distance3dSq < SQ(50.0f))
            {
                alpha = alpha * ((sqrtf(distance3dSq) + -35.0f) / 15.0f);
            }
        }
        
        CRegisteredCorona* corona = NULL;
        CRegisteredCorona* freeCorona = NULL;
        for(int i = 0; i < MAX_EXT_CORONAS_STORAGE; ++i)
        {
            if(m_aCoronas[i].m_dwId == (uintptr_t)ID)
            {
                corona = &m_aCoronas[i];
                if(!corona->m_Color.a && !alpha)
                {
                    RemoveCorona(corona);
                    return;
                }
                break;
            }
            if(!m_aCoronas[i].m_dwId && !freeCorona) freeCorona = &m_aCoronas[i];
        }
        if(!corona)
        {
            corona = freeCorona;
            if(!corona) return;
            ++m_nCoronasNum;

            corona->m_nFadeState       = bFullBrightAtStart ? alpha : 0;
            corona->m_bOffScreen       = true;
            corona->m_bReflectionDelay = false;
            corona->m_bJustCreated     = true;
            corona->m_dwId             = ID;
        }

        corona->m_Color                = CRGBA(R, G, B, alpha);
        corona->m_vPosn                = Coors;
        corona->m_fSize                = Size;
        corona->m_fAngle               = fNormalAngle;
        corona->m_bRegisteredThisFrame = true;
        corona->m_fFarClip             = Range;
        corona->m_fNearClip            = ArgPullTowardsCam;
        corona->m_pTexture             = pCoronaTex;
        corona->m_nFlareType           = FlareType;
        corona->m_bUsesReflection      = ReflType;
        corona->m_bCheckObstacles      = LOSCheck;
        corona->m_fFadeSpeed           = FadeSpeed;

        corona->m_bFlashWhileFading    = bNeonFade;
        corona->m_bOnlyFromBelow       = bOnlyFromBelow;
        corona->m_bDrawWithWhiteCore   = bWhiteCore;

        corona->m_bAttached            = !!pAttachedToEntity;
        if(corona->m_pAttachedTo != pAttachedToEntity)
        {
            if(corona->m_pAttachedTo) corona->m_pAttachedTo->CleanUpOldReference(&corona->m_pAttachedTo);
            corona->m_pAttachedTo = pAttachedToEntity;
            if(pAttachedToEntity) pAttachedToEntity->RegisterReference(&corona->m_pAttachedTo);
        }
    }

    // Callbacks
    static inline void DrawExtCoronasCB()
    {
        if(!m_nCoronasNum) return;
        CSprite::FlushSpriteBuffer();
        const RwRenderState states[] = { rwRENDERSTATEZWRITEENABLE, rwRENDERSTATEVERTEXALPHAENABLE,
            rwRENDERSTATESRCBLEND, rwRENDERSTATEDESTBLEND, rwRENDERSTATEZTESTENABLE, rwRENDERSTATETEXTURERASTER };
        void* savedStates[6] { NULL };
        bool restoreStates[6];
        for(int i = 0; i < 6; ++i) restoreStates[i] = !!RwRenderStateGet(states[i], &savedStates[i]);
        RwRenderStateSet(rwRENDERSTATEZWRITEENABLE,      (void*)false);
        RwRenderStateSet(rwRENDERSTATEVERTEXALPHAENABLE, (void*)true);
        RwRenderStateSet(rwRENDERSTATESRCBLEND,          (void*)rwBLENDONE);
        RwRenderStateSet(rwRENDERSTATEDESTBLEND,         (void*)rwBLENDONE);
        RwRenderStateSet(rwRENDERSTATEZTESTENABLE,       (void*)true);

        CVector2D halfscreen { 0.5f * RsGlobal.maximumWidth, 0.5f * RsGlobal.maximumHeight };

        bool zTestEnable = true;
        const CVector& camPos = TheCamera.GetPosition();
        for(int i = 0; i < MAX_EXT_CORONAS_STORAGE; ++i)
        {
            CRegisteredCorona& c = m_aCoronas[i];
            if(!c.m_dwId || (!c.m_nFadeState && !c.m_Color.a) ) continue;

            CVector cpos = GetWorldPosition(c.m_vPosn, c.m_pAttachedTo);

            CVector2D onScrSize;
            CVector   onScrPos;
            if(( c.m_bOffScreen = !CSprite::CalcScreenCoors(cpos, &onScrPos, &onScrSize.x, &onScrSize.y, true, true) ) || onScrPos.z >= c.m_fFarClip)
            {
                continue;
            }

            const float lerpFade = clampfloat(0.0f, 1.0f, (onScrPos.z - c.m_fFarClip) / (c.m_fFarClip / 2.0f - c.m_fFarClip) );
            const short intensity = (short)((float)c.m_nFadeState * lerpFade);
            const float rz = 1.0f / onScrPos.z;

            if(c.m_bCheckObstacles == zTestEnable)
            {
                zTestEnable = !zTestEnable;
                RwRenderStateSet(rwRENDERSTATEZTESTENABLE, (void*)(intptr_t)zTestEnable);
            }

            if(c.m_pTexture && intensity > 0)
            {
                RwRenderStateSet(rwRENDERSTATETEXTURERASTER, *(void**)c.m_pTexture);
                const float scale = fminf(40.0f, onScrPos.z) * CWeather::Foggyness / 40.0f + 1.0f;
                const float colorScale = 1.0f / scale;

                CVector worldPos = ( (c.m_fNearClip != 0.0f) ? (cpos - (cpos - camPos).Normalized() * c.m_fNearClip) : (cpos) );

                if(CSprite::CalcScreenCoors(worldPos, &onScrPos, &onScrSize.x, &onScrSize.y, true, true))
                {
                    CSprite::RenderOneXLUSprite_Rotate_Aspect(
                        onScrPos.x, onScrPos.y, onScrPos.z,
                        onScrSize.x * c.m_fSize * scale,
                        onScrSize.y * c.m_fSize * scale,
                        colorScale * c.m_Color.r,
                        colorScale * c.m_Color.g,
                        colorScale * c.m_Color.b,
                        intensity,
                        rz * 20.0f,
                        0.0f,
                        255
                    );
                }
            }

            if(c.m_nFlareType != FLARETYPE_NONE && gpCoronaTexture[CORONATYPE_SHINYSTAR])
            {
                RwRenderStateSet(rwRENDERSTATEZTESTENABLE, (void*)false);
                RwRenderStateSet(rwRENDERSTATETEXTURERASTER, *(void**)(gpCoronaTexture[CORONATYPE_SHINYSTAR]));

                CFlareDefinition* flare;
                switch(c.m_nFlareType)
                {
                    case FLARETYPE_HEADLIGHTS: flare = &HeadLightsFlareDef[0]; break;
                    case FLARETYPE_SUN:        flare = &SunFlareDef[0]; break;
                    default: continue;
                }

                float colorMult = 0.3f * ((float)rand() / (float)RAND_MAX);
                colorMult = ((colorMult + 0.7f) * c.m_nFadeState) / 65536.0f;

                CColPoint hitCP;
                CEntity* hitEntity;
                bool visible = !CWorld::ProcessLineOfSight(cpos, camPos, hitCP, hitEntity, false, true, true, false, false, false, false, true);
                while(flare->Sprite)
                {
                    if(visible)
                    {
                        const CRGBA flareColor(
                            (u8)( c.m_Color.r * colorMult * flare->RedMult ),
                            (u8)( c.m_Color.g * colorMult * flare->GreenMult ),
                            (u8)( c.m_Color.b * colorMult * flare->BlueMult ),
                            255);
                        CSprite::RenderBufferedOneXLUSprite2D(
                            onScrPos.x * flare->Position + halfscreen.x * (1.f - flare->Position),
                            onScrPos.y * flare->Position + halfscreen.y * (1.f - flare->Position),
                            flare->Size * 4.0f,
                            flare->Size * 4.0f,
                            flareColor,
                            255,
                            255
                        );
                    }
                    ++flare;
                }
                CSprite::FlushSpriteBuffer();
            }

            RwRenderStateSet(rwRENDERSTATEZTESTENABLE, (void*)(intptr_t)zTestEnable);
        }
        CSprite::FlushSpriteBuffer();
        for(int i = 0; i < 6; ++i)
        {
            if(restoreStates[i]) RwRenderStateSet(states[i], savedStates[i]);
        }
    }
    static inline void UpdateExtCoronasCB()
    {
        if(!m_nCoronasNum) return;
        CVector& camPos = TheCamera.GetPosition();
        const float timeStep = CTimer::GetTimeStep();

        for(int i = 0; i < MAX_EXT_CORONAS_STORAGE; ++i)
        {
            CRegisteredCorona& c = m_aCoronas[i];
            if(c.m_dwId)
            {
                // NOT using m_aCoronas[i].Update() as it's using CCoronas' values inside
                if(!c.m_bRegisteredThisFrame) c.m_Color.a = 0;
                if(c.m_bAttached && !c.m_pAttachedTo)
                {
                    RemoveCorona(&c);
                    continue;
                }

                const float fadeStep = timeStep * c.m_fFadeSpeed;
                CVector worldPos = GetWorldPosition(c.m_vPosn, c.m_pAttachedTo);
                if(!c.m_bCheckObstacles || CWorld::GetIsLineOfSightClear(worldPos, camPos, true, false, false, false, false, false, false) )
                {
                    if(c.m_bOffScreen || (c.m_bOnlyFromBelow && camPos.z > worldPos.z) )
                    {
                        c.m_nFadeState = (u8)(fmaxf(0.0f, (float)c.m_nFadeState - fadeStep));
                    }
                    else
                    {
                        if(CCoronas::bChangeBrightnessImmediately)
                        {
                            c.m_nFadeState = c.m_Color.a;
                        }
                        else if(c.m_nFadeState != c.m_Color.a)
                        {
                            if(c.m_nFadeState > c.m_Color.a)
                            {
                                c.m_nFadeState = (u8)(fmaxf((float)c.m_Color.a, (float)c.m_nFadeState - fadeStep));
                            }
                            else
                            {
                                c.m_nFadeState = (u8)(fminf((float)c.m_Color.a, (float)c.m_nFadeState + fadeStep));
                            }
                        }
                    }
                }
                else
                {
                    c.m_nFadeState = (u8)(fmaxf(0.0f, (float)c.m_nFadeState - fadeStep));
                }

                if(!c.m_nFadeState && !c.m_bJustCreated)
                {
                    RemoveCorona(&c);
                }

                c.m_bJustCreated = false;
                c.m_bRegisteredThisFrame = false;
            }
        }
    }
    static inline CRegisteredCorona m_aCoronas[MAX_EXT_CORONAS_STORAGE] { 0 };
    static inline int m_nCoronasNum = 0;
};
inline CoronasExtender g_CoronasExtenderStub;

#endif // __AML_PSDK_SACORONASEXTENDER_H
