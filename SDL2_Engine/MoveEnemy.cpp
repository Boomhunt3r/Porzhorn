#pragma region project include
#include "MoveEnemy.h"
#include "Config.h"
#include "Macro.h"
#include "Game.h"
#include "Player.h"
#include "Animation.h"
#pragma endregion

#pragma region public override function
// update every frame
void GMoveEnemy::Update(float _deltaSeconds)
{
	m_EnemyAnimation.SetAnimationRect(SRect(127, 127, 0, 0));
	_i = 508 / 169;

	_l += _i;

	if (_l >= 6 && _l <= 12)
	{
		m_EnemyAnimation.SetAnimationRect(SRect(127, 127, 127, 0));
	}
	if (_l >= 9 && _l <= 15)
	{
		m_EnemyAnimation.SetAnimationRect(SRect(127, 127, 254, 0));
	}
	if (_l >= 18 && _l <= 24)
	{
		m_EnemyAnimation.SetAnimationRect(SRect(127, 127, 381, 0));
	}
	if (_l >= 27 && _l <= 33)
	{
		m_EnemyAnimation.SetAnimationRect(SRect(127, 127, 0, 127));
	}
	if (_l >= 36 && _l <= 42)
	{
		m_EnemyAnimation.SetAnimationRect(SRect(127, 127, 127, 127));
	}
	if (_l >= 45 && _l <= 51)
	{
		m_EnemyAnimation.SetAnimationRect(SRect(127, 127, 254, 127));
	}
	if (_l >= 54 && _l <= 60)
	{
		m_EnemyAnimation.SetAnimationRect(SRect(127, 127, 381, 127));
	}
	if (_l >= 63 && _l <= 69)
	{
		m_EnemyAnimation.SetAnimationRect(SRect(127, 127, 0, 254));
	}
	if (_l >= 72 && _l <= 78)
	{
		m_EnemyAnimation.SetAnimationRect(SRect(127, 127, 127, 254));
	}
	if (_l >= 81 && _l <= 87)
	{
		m_EnemyAnimation.SetAnimationRect(SRect(127, 127, 254, 254));
	}
	if (_l >= 90 && _l <= 96)
	{
		m_EnemyAnimation.SetAnimationRect(SRect(127, 127, 381, 254));
	}
	if (_l >= 99 && _l <= 105)
	{
		m_EnemyAnimation.SetAnimationRect(SRect(127, 127, 0, 381));
	}
	if (_l >= 108 && _l <= 114)
	{
		m_EnemyAnimation.SetAnimationRect(SRect(127, 127, 127, 381));
	}
	if (_l >= 117 && _l <= 123)
	{
		m_EnemyAnimation.SetAnimationRect(SRect(127, 127, 254, 381));
	}
	if (_l >= 126 && _l <= 132)
	{
		m_EnemyAnimation.SetAnimationRect(SRect(127, 127, 381, 381));
	}
	if (_l >= 135)
	{
		_l = 0;
	}
	// if Target is nullpointer
	if (m_pColTarget == nullptr)
	{
		// do nothing and continue
		// until targes is not nullptr anymore
	}
	else
	{
			
		// if movement is to the right, and target hits a Wall
		if (m_movement.X == 1.0f && m_pColTarget->GetColType() == ECollisionType::WALL || m_movement.X == 1.0f && m_pColTarget->GetTag() == "Barrier")
		{
			// move left
			m_movement = -1.0f;
			m_mirror.X = 0.0f;
		}
		// if movement is to the left and target hits a wall
		else if (m_movement.X == -1.0f && m_pColTarget->GetColType() == ECollisionType::WALL || m_movement.X == -1.0f && m_pColTarget->GetTag() == "Barrier")
		{
			// move right
			m_movement.X = 1.0f;
			m_mirror.X = 1.0f;
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
	SetSrcRect(m_EnemyAnimation.GetAnimationRect());
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
	m_colType = ECollisionType::ENEMY;

	// set health
	m_health = MOVE_ENEMY_HEALTH;

	// random between 0 and 1

	if (rand() % 2)
		m_movement.X = 1.0f;
	else
		m_movement.X = -1.0f;
}
#pragma endregion