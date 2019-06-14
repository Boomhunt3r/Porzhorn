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
	// if collision target
	if (m_pColTarget)
	{
		// remove Object
		CTM->RemoveObject(this);

		// if collision target is Player
		if (m_pColTarget->GetTag() == "Player")
			GAME->GameOver(); // Player dies and Game is lost
	}

	// update parent
	CMoveObject::Update(_deltaSeconds);

}

// render every frame
void GBossBullet::Render()
{
	// render parent
	CMoveObject::Render();
}
#pragma endregion