#include <mod/amlmod.h>

#include <aml-psdk/game_sa/Events.h>
#include <aml-psdk/game_sa/engine/Lines.h>
#include <aml-psdk/game_sa/engine/ModelInfo.h>
#include <aml-psdk/game_sa/entity/PlayerPed.h>
#include <aml-psdk/game_sa/other/Pools.h>
#include <aml-psdk/game_sa/base/ColModel.h>

#include <aml-psdk/renderware/RwRender.h>

MYMOD(net.rusjj.psdkexample.collines, AML PSDK Example: ColLines, 1.0, FoxiruFoxcatIsDW)

// FoxiruFoxcatIsDW
const float g_fDrawRadius = 150.0f;
void DrawEntityCollision(CEntity* entity)
{
    if(!entity->GetIsOnScreen()) return;

    CMatrix* matrix = entity->GetMatrix();
    if(!matrix) return;

    CBaseModelInfo* mi = CModelInfo::ms_modelInfoPtrs[entity->m_nModelIndex];
    if(!mi) return;
    
    CColModel* colModel = mi->m_pColModel;
    if(!colModel || !colModel->m_pColData) return;

    CCollisionData* colData = colModel->m_pColData;
    
    uint16_t numTriangles =     colData->m_nNumTriangles;
    CVector* pVertices =        colData->m_pVertices;
    CColTriangle* pTriangles =  colData->m_pTriangles;
    
    if(!pTriangles || !pVertices) return;

    //                    0x R G B A
    const uint32_t color = 0x00FF00FF;
    for(int i = 0; i < numTriangles; ++i)
    {
        CColTriangle* currentTri = &pTriangles[i];
        int32_t vA = currentTri->m_nVertA;
        int32_t vB = currentTri->m_nVertB;
        int32_t vC = currentTri->m_nVertC;

        CVector v1 = pVertices[vA];
        CVector v2 = pVertices[vB];
        CVector v3 = pVertices[vC];

        v1 = matrix->TransformPos(v1);
        v2 = matrix->TransformPos(v2);
        v3 = matrix->TransformPos(v3);

        CLines::RenderLineWithClipping(v1.x, v1.y, v1.z, v2.x, v2.y, v2.z, color, color);
        CLines::RenderLineWithClipping(v2.x, v2.y, v2.z, v3.x, v3.y, v3.z, color, color);
        CLines::RenderLineWithClipping(v3.x, v3.y, v3.z, v1.x, v1.y, v1.z, color, color);
    }
}

ON_MOD_LOAD()
{
    Events::pedRenderEvent += [](CPed* ped)
    {
        
    };
    Events::drawingEvent += []()
    {
        CPlayerPed* player = FindPlayerPed(-1);
        if(!player) return;

        RwRenderStateSet(rwRENDERSTATEZWRITEENABLE, (void*)true);
        RwRenderStateSet(rwRENDERSTATEVERTEXALPHAENABLE, (void*)true);
        RwRenderStateSet(rwRENDERSTATESRCBLEND, (void*)rwBLENDSRCALPHA);
        RwRenderStateSet(rwRENDERSTATEDESTBLEND, (void*)rwBLENDINVSRCALPHA);
        RwRenderStateSet(rwRENDERSTATETEXTURERASTER, (void*)NULL);

        #define DRAW_RAD_SQR (g_fDrawRadius*g_fDrawRadius)
        {
        auto curPool = CPools::ms_pVehiclePool;
        if(curPool)
        {
            int size = curPool->GetSize();
            for(int i = 0; i < size; ++i)
            {
                CEntity* ent = curPool->GetAt(i);
                if(ent && ent->GetDistanceSqrTo(player) < DRAW_RAD_SQR)
                {
                    DrawEntityCollision(ent);
                }
            }
        }
        }
        
        {
        auto curPool = CPools::ms_pPedPool;
        if(curPool)
        {
            int size = curPool->GetSize();
            for(int i = 0; i < size; ++i)
            {
                CEntity* ent = curPool->GetAt(i);
                if(ent && ent->GetDistanceSqrTo(player) < DRAW_RAD_SQR)
                {
                    DrawEntityCollision(ent);
                }
            }
        }
        }
        
        {
        auto curPool = CPools::ms_pBuildingPool;
        if(curPool)
        {
            int size = curPool->GetSize();
            for(int i = 0; i < size; ++i)
            {
                CEntity* ent = curPool->GetAt(i);
                if(ent && ent->GetDistanceSqrTo(player) < DRAW_RAD_SQR)
                {
                    DrawEntityCollision(ent);
                }
            }
        }
        }
        
        {
        auto curPool = CPools::ms_pObjectPool;
        if(curPool)
        {
            int size = curPool->GetSize();
            for(int i = 0; i < size; ++i)
            {
                CEntity* ent = curPool->GetAt(i);
                if(ent && ent->GetDistanceSqrTo(player) < DRAW_RAD_SQR)
                {
                    DrawEntityCollision(ent);
                }
            }
        }
        }
        
        RwRenderStateSet(rwRENDERSTATESRCBLEND, (void*)5);
        RwRenderStateSet(rwRENDERSTATEDESTBLEND, (void*)6);
        RwRenderStateSet(rwRENDERSTATEVERTEXALPHAENABLE, (void*)false);
        RwRenderStateSet(rwRENDERSTATEZWRITEENABLE, (void*)true);
        RwRenderStateSet(rwRENDERSTATEZTESTENABLE, (void*)true);
    };
}