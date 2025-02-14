#pragma region project include
#include "Boss.h"
#include "Config.h"
#include "Macro.h"
#include "Game.h"
#include "Player.h"
#include "Bullet.h"
#include "BossBullet.h"
#include "Animation.h"  
#include "Texture.h"
#pragma endregion

#pragma region system include
#include <ctime>  
#pragma endregion


#pragma region public override function

float bossTimer = 0.0f;

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

	// initiaize Move animation
	m_pMoveAnim = new CAnimation(SVector2(0.0f, BossMovePositionY),
		SVector2(BossMoveWidth, BossMoveHeight), 5);
	m_pMoveAnim->SetAnimationTime(1.25f);

	// initialize Shoot animation
	m_pShootAnim = new CAnimation(SVector2(0.0f, BossShootPositionY),
		SVector2(BossShootWidth, BossShootHeight), 4);
	m_pShootAnim->SetAnimationTime(0.5f);

	// set Current Animation to Move
	m_pCurrentAnim = m_pMoveAnim;

	// random between 0 and 1
	m_movement = -1.0f;
}

// update every frame
void GBoss::Update(float _deltaSeconds)
{
	m_pCurrentAnim = m_pMoveAnim;

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

	// if Bosstimer * deltaseconds Higer or as Boss Event Timer
	if (bossTimer * _deltaSeconds >= BOSS_EVENT_TIMER)
	{
		// open random event function
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

	// update current animation
	m_pCurrentAnim->Update(_deltaSeconds);

	// set src rect
	m_srcRect = SRect(
		SVector2(m_pCurrentAnim->GetCurrentTexturePosition().X, m_pCurrentAnim->GetCurrentTexturePosition().Y),
		m_pCurrentAnim->GetSize()
	);
}

// Random Event Function
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

// shoot event function
void GBoss::Shoot()
{
	m_pCurrentAnim = m_pShootAnim;

	GBossBullet* pBullet = new GBossBullet("Texture/Bullet/T_Horn.png", m_position, SVector2(32, 32));
	CTM->AddPersistantObject(pBullet);
	pBullet->SetSpeed(BULLET_SPEED);
	pBullet->SetColType(ECollisionType::MOVE);
	pBullet->SetTag("Bullet");

	if (m_mirror.X)
	{
		pBullet->SetMovement(SVector2(1.0f, 0.0f));
		pBullet->SetPosition(m_position + SVector2(m_rect.w * 1.0f, 60.0f));
		CTexture* pBossBullet = new CTexture("Texture/Bullet/T_Horn_R.png");
		pBullet->SetTexture(pBossBullet);
	}
	else
	{
		pBullet->SetMovement(SVector2(-1.0f, 0.0f));
		pBullet->SetPosition(m_position + SVector2(-m_rect.w * 0.1f, 60.0f));
	}
}

// death function
void GBoss::Death()
{
	GAME->Win();
}

// render every frame
void GBoss::Render()
{
	// render parent
	CMoveObject::Render();
}
#pragma endregion