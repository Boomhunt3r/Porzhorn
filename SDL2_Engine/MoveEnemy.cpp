#pragma region project include
#include "MoveEnemy.h"
#include "Config.h"
#include "Macro.h"
#include "Game.h"
#include "Player.h"
#include "Animation.h"
#pragma endregion

#pragma region public override function
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
	m_colType = ECollisionType::ENEMY;

	// set health
	m_health = MOVE_ENEMY_HEALTH;

	// initiaize Move animation
	m_pMoveAnim = new CAnimation(SVector2(0.0f, EnemyMovePositionY),
		SVector2(EnemyMoveWidth, EnemyMoveHeight), 16);
	m_pMoveAnim->SetAnimationTime(0.75f);

	m_pCurrentAnim = m_pMoveAnim;

	// random between 0 and 1

	if (rand() % 2)
		m_movement.X = 1.0f;
	else
		m_movement.X = -1.0f;
}

// update every frame
void GMoveEnemy::Update(float _deltaSeconds)
{
	
	// if Target is nullpointer
	if (m_pColTarget == nullptr)
	{
		// do nothing and continue
		// until target is not nullptr anymore
	}
	else
	{
		// if target run check collison function
		CheckBoxCollision();
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

	// update current animation
	m_pCurrentAnim->Update(_deltaSeconds);

	// set src rect
	m_srcRect = SRect(
		SVector2(m_pCurrentAnim->GetCurrentTexturePosition().X, m_pCurrentAnim->GetCurrentTexturePosition().Y),
		m_pCurrentAnim->GetSize()
	);
}

// render every frame
void GMoveEnemy::Render()
{
	// render parent
	CMoveObject::Render();
}
#pragma endregion

#pragma region public function
// check collision function
void GMoveEnemy::CheckBoxCollision()
{
	// if movement is to the right, and target hits a Wall
	if (m_movement.X == 1.0f && m_pColTarget->GetColType() == ECollisionType::WALL)
	{
		// move left
		m_movement = -1.0f;
		// mirror left
		m_mirror.X = 0.0f;
	}
	// if movement is if to the left and tag is Barrier
	else if (m_movement.X == 1.0f && m_pColTarget->GetTag() == "Barrier")
	{
		// move left
		m_movement = -1.0f;
		// mirror left
		m_mirror.X = 0.0f;
	}
	// if movement is to the left and target hits a wall
	else if (m_movement.X == -1.0f && m_pColTarget->GetColType() == ECollisionType::WALL)
	{
		// move right
		m_movement.X = 1.0f;
		// mirror right
		m_mirror.X = 1.0f;
	}
	// if movement is to the right and tag is Barrier
	else if (m_movement.X == -1.0f && m_pColTarget->GetTag() == "Barrier")
	{
		// move right
		m_movement.X = 1.0f;
		// mirror right
		m_mirror.X = 1.0f;
	}
}
#pragma endregion