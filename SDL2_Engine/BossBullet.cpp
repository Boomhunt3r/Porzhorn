#pragma region project include
#include "BossBullet.h"
#include "Engine.h"
#include "ContentManagement.h"
#include "MoveEnemy.h"
#include "Config.h"
#include "Macro.h"
#include "Input.h"
#include "Boss.h"
#include "Game.h"
#pragma endregion

#pragma region public override function
// update every frame
void GBossBullet::Update(float _deltaSeconds)
{
	if (m_pColTarget)
	{
		CTM->RemoveObject(this);

		if (m_pColTarget->GetTag() == "Player")
			GAME->GameOver();
	}

	CMoveObject::Update(_deltaSeconds);

}

// render every frame
void GBossBullet::Render()
{
	CMoveObject::Render();
}
#pragma endregion