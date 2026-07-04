#include <mod/amlmod.h>

#include <aml-psdk/game_sa/Events.h>
#include <aml-psdk/game_sa/engine/Lines.h>
#include <aml-psdk/game_sa/engine/ModelInfo.h>
#include <aml-psdk/game_sa/entity/PlayerPed.h>
#include <aml-psdk/game_sa/other/Pools.h>
#include <aml-psdk/game_sa/base/ColModel.h>

MYMOD(net.rusjj.psdkexample.collines, AML PSDK Example: ColLines, 1.0, FoxiruFoxcatIsDW)

// FoxiruFoxcatIsDW
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

    //                     0x R G B A
    const uint32_t color = 0x00FF00FF;

    for(int i = 0; i < numTriangles; ++i)
    {
        CColTriangle* currentTri = &pTriangles[i];
        uint32_t vA = currentTri->m_nVertA;
        uint32_t vB = currentTri->m_nVertB;
        uint32_t vC = currentTri->m_nVertC;

        CVector v1 = pVertices[vA];
        CVector v2 = pVertices[vB];
        CVector v3 = pVertices[vC];
        
        float temp;
        temp = v1.y; v1.y = v1.z; v1.z = temp;
        temp = v2.y; v2.y = v2.z; v2.z = temp;
        temp = v3.y; v3.y = v3.z; v3.z = temp;

        v1 = matrix->TransformPos(v1);
        v2 = matrix->TransformPos(v2);
        v3 = matrix->TransformPos(v3);

        CLines::RenderLineWithClipping(v1.x, v1.y, v1.z, v2.x, v2.y, v2.z, color, color);
        CLines::RenderLineWithClipping(v1.x, v1.y, v1.z, v3.x, v3.y, v3.z, color, color);
        CLines::RenderLineWithClipping(v2.x, v2.y, v2.z, v3.x, v3.y, v3.z, color, color);
    }
}

ON_MOD_LOAD()
{
    Events::drawingEvent += []()
    {
        CPlayerPed* player = FindPlayerPed(-1);
        if(!player) return;

        CBuildingPool* buildingPool = CPools::ms_pBuildingPool;
        if(buildingPool)
        {
            int size = buildingPool->GetSize();
            for(int i = 0; i < size; ++i)
            {
                CBuilding* building = buildingPool->GetAt(i);
                if(building && building->GetDistanceSqrTo(player) > 100*100)
                {
                    DrawEntityCollision(building);
                }
            }
        }
    };
}