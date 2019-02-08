#pragma region project include
#include "Boss.h"
#include "Config.h"
#include "Macro.h"
#include "Game.h"
#include "Player.h"
#include "Bullet.h"
#include "BossBullet.h"
#include "Animation.h"  
#pragma endregion

#include <ctime>
#pragma endregion

#pragma region public override function

float bossTimer = 0.0f;

// update every frame
void GBoss::Update(float _deltaSeconds)
{
	m_BossAnimation.SetAnimationRect(SRect(297, 382, 0, 382));
	_i = 1485 / 990;

	_l += _i;

	if (_l >= 6 && _l <= 12)
	{
		m_BossAnimation.SetAnimationRect(SRect(297, 382, 297, 382));
	}
	if (_l >= 15 && _l <= 21)
	{
		m_BossAnimation.SetAnimationRect(SRect(297, 382, 594, 382));
	}
	if (_l >= 24 && _l <= 30)
	{
		m_BossAnimation.SetAnimationRect(SRect(297, 382, 891, 382));
	}
	if (_l >= 33 && _l <= 39)
	{
		m_BossAnimation.SetAnimationRect(SRect(297, 382, 1188, 382));
	}
	if (_l >= 42)
	{
		_l = 0;
	}
	bossTimer += 1.0f;

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

	if (bossTimer * _deltaSeconds >= BOSS_EVENT_TIMER)
	{
		REvent();
		// reset timer
		bossTimer = 0.0f;
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

void GBoss::REvent()
{
	int random;
	srand(time(0));
	random = rand() % 3;

	switch (random)
	{
	case 0:
		m_speed = BOSS_SPEED;
		Shoot();
		break;
	case 1:
		m_speed = BOSS_ROLL_SPEED;
		break;
	case 2:
		Shoot();
		m_speed = BOSS_SPEED;
		break;
	default:
		break;
	}
}

void GBoss::Shoot()
{
	GBossBullet* pBullet = new GBossBullet("Texture/Bullet/T_Horn.png", m_position, SVector2(16, 16));
	CTM->AddPersistantObject(pBullet);
	pBullet->SetSpeed(BULLET_SPEED);
	pBullet->SetColType(ECollisionType::MOVE);
	pBullet->SetTag("Bullet");

	if (m_mirror.X)
	{
		pBullet->SetMovement(SVector2(1.0f, 0.0f));
		pBullet->SetPosition(m_position + SVector2(m_rect.w * 0.8f, 30.0f));
	}
	else
	{
		pBullet->SetMovement(SVector2(-1.0f, 0.0f));
		pBullet->SetPosition(m_position + SVector2(-m_rect.w * -0.2f, 30.0f));
	}
}

// render every frame
void GBoss::Render()
{
	SetSrcRect(m_BossAnimation.GetAnimationRect());

	// render parent
	CMoveObject::Render();
}
#pragma endregion

#pragma region public function
// initialize move enemy
void GBoss::Init()
{
	

	// set tag
	m_pTag = "Boss";

	// activate gravity
	m_gravity = true;

	// set speed
	m_speed = BOSS_SPEED;

	// set collision type
	m_colType = ECollisionType::ENEMY;

	// set health
	m_health = BOSS_HEALTH;

	// random between 0 and 1

	if (rand() % 2)
		m_movement.X = 1.0f;
	else
		m_movement.X = -1.0f;
}
#pragma endregion