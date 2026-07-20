#include <mod/amlmod.h>

#include <aml-psdk/game_sa/Events.h>
#include <aml-psdk/game_sa/base/Timer.h>
#include <aml-psdk/game_sa/engine/RsGlobal.h>
#include <aml-psdk/game_sa/engine/Sprite2d.h>
#include <aml-psdk/game_sa/entity/PlayerPed.h>
#include <aml-psdk/game_sa/other/PlayerData.h>
#include <aml-psdk/game_sa/other/Stats.h>

MYMOD(net.rusjj.psdkexample.staminabar, AML PSDK Example: Stamina Bar, 1.0, RusJJ)

static CRGBA frColor(255, 255, 255, 255);
static CRGBA bgColor(  0,   0,   0, 255);
static u32 g_nTimeToHide = 1;
ON_MOD_LOAD()
{
    Events::drawHudEvent += []()
    {
        CPlayerPed* player = FindPlayerPed(-1);
        if(!player || !player->m_pPlayerData) return;

        float stamina = player->m_pPlayerData->m_fTimeCanRun;
        float maxStamina = CStats::GetFatAndMuscleModifier(eStatModAbilities::STAT_MOD_TIME_CAN_RUN);

        if(stamina >= maxStamina)
        {
            if(g_nTimeToHide == 0) g_nTimeToHide = CTimer::GetTimeMS() + 3000;
        }
        else
        {
            g_nTimeToHide = 0;
        }

        bool bShouldBlinkAndHide = false;
        if(stamina < 0.125f * maxStamina)
        {
            bShouldBlinkAndHide = ( CTimer::GetTimeMS() % 350 <= 150 );
        }
        else if(stamina < 0.25f * maxStamina)
        {
            bShouldBlinkAndHide = ( CTimer::GetTimeMS() % 500 <= 200 );
        }

        if(!bShouldBlinkAndHide && ( g_nTimeToHide == 0 || g_nTimeToHide > CTimer::GetTimeMS() ))
        {
            float screenW = RsGlobal.maximumWidth;
            float screenH = RsGlobal.maximumHeight;

            #define SCALEX(__v) ( __v * screenW / 640.0f )
            #define SCALEY(__v) ( __v * screenH / 448.0f )

            u16 width = 3 * SCALEY(34); // yes, scale __Y__
            u8 height = 3 * SCALEY(5);
            CSprite2d::DrawBarChart(SCALEX(640.0f / 2.0f) - width / 2, SCALEY(448.0f) - 1.3f * height,
                                    width, height, 100.0f * stamina / maxStamina, 0, false, true, frColor, bgColor);
        }
    };
}