#pragma region project include
#include "Boss.h"
#include "Config.h"
#include "Macro.h"
#include "Game.h"
#include "Player.h"
#include "Bullet.h"
#include "BossBullet.h"

#include <ctime>
#pragma endregion

#pragma region public override function

float bossTimer = 0.0f;

// update every frame
void GBoss::Update(float _deltaSeconds)
{
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
		LOG("0");
		break;
	case 1:
		m_speed = BOSS_ROLL_SPEED;
		LOG("1");
		break;
	case 2:
		m_speed = BOSS_SPEED;
		LOG("2");
		break;
	default:
		break;
	}
}

void GBoss::Shoot()
{
	GBossBullet* pBullet = new GBossBullet("Texture/Bullet/T_Bullet.png", m_position, SVector2(8, 8));
	CTM->AddPersistantObject(pBullet);
	pBullet->SetSpeed(BULLET_SPEED);
	pBullet->SetColType(ECollisionType::MOVE);
	pBullet->SetTag("Bullet");

	if (m_mirror.X)
	{
		pBullet->SetMovement(SVector2(-1.0f, 0.0f));
		pBullet->SetPosition(m_position + SVector2(-m_rect.w * -0.2f, 30.0f));
	}
	else
	{
		pBullet->SetMovement(SVector2(1.0f, 0.0f));
		pBullet->SetPosition(m_position + SVector2(m_rect.w * 0.8f, 30.0f));
	}
}

// render every frame
void GBoss::Render()
{
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
	//m_speed = BOSS_SPEED;

	// set collision type
	m_colType = ECollisionType::ENEMY;

	// set health
	//m_health = BOSS_HEALTH;

	// random between 0 and 1

	if (rand() % 2)
		m_movement.X = 1.0f;
	else
		m_movement.X = -1.0f;
}
#pragma endregion