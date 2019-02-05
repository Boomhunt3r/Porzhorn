#pragma region project include
#include "MoveEnemy.h"
#include "Config.h"
#include "Macro.h"
#include "Game.h"
#pragma endregion

#pragma region public override function
// update every frame
void GMoveEnemy::Update(float _deltaSeconds)
{
	// if Target is nullpointer
	if (m_pColTarget == nullptr)
	{
		// do nothing and continue
		// until targes is not nullptr anymore
	}
	else
	{
		// if movement is to the right, and target hits a Wall
		if (m_movement.X == 1.0f && m_pColTarget->GetColType() == ECollisionType::WALL && m_pColTarget->GetTag() == "Barrier")
		{
			// move left
			m_movement = -1.0f;
		}
		// if movement is to the left and target hits a wall
		else if (m_movement.X == -1.0f && m_pColTarget->GetColType() == ECollisionType::WALL && m_pColTarget->GetTag() == "Barrier")
		{
			// move right
			m_movement.X = 1.0f;
		}
	}
	// if Target is true
	if (m_pColTarget)
	{
		// if target is Player
		if (m_pColTarget->GetTag() == "Player")
		{
			// Game Over
			GAME->GameOver();
		}
	}
	// update parent
	CMoveObject::Update(_deltaSeconds);
}

// render every frame
void GMoveEnemy::Render()
{
	// render parent
	CMoveObject::Render();
}
#pragma endregion

#pragma region public function
// initialize move enemy
void GMoveEnemy::Init()
{
	// set tag
	m_pTag = "Enemy";

	// activate gravity
	m_gravity = true;

	// set speed
	m_speed = MOVE_ENEMY_SPEED;

	// set collision type
	m_colType = ECollisionType::MOVE;

	// set health
	m_health = MOVE_ENEMY_HEALTH;

	// random between 0 and 1

	if (rand() % 2)
		m_movement.X = 1.0f;
	else
		m_movement.X = -1.0f;
}
#pragma endregion