#pragma region project include
#include "Player.h"
#include "Bullet.h"
#include "Config.h"
#include "Input.h"
#include "Macro.h"
#include "Engine.h"
#include "ContentManagement.h"
#include "Renderer.h"
#include "MenuScene.h"
#include "Game.h"
#include "Text.h"
#include "MainScene.h"
#include "Physic.h"
#pragma endregion

#pragma region public override function
// initialize object
void GPlayer::Init()
{
	// set tag
	m_pTag = "Player";

	// set speed
	m_speed = 2500.0f;

	// set collision type
	m_colType = ECollisionType::MOVE;

	// activate gravity
	m_gravity = true;

	// activate gravity
	m_gravity = true;

	// initialize parent
	CMoveObject::Init();
}

// update every frame
void GPlayer::Update(float _deltaSeconds)
{
	if (m_pColTarget)
	{
		if (m_pColTarget->GetTag() == "Enemy" || m_pColTarget->GetTag() == "Fire")
			GAME->GameOver();
		if (m_pColTarget->GetTag() == "Goal")
			GAME->Win();
		if (m_pColTarget->GetTag() == "NPC1")
		{
			SVector2 position = m_pColTarget->GetPosition();
			CText* pNPCText = new CText("Hier kommt eine Story 1 hin !", GAME->m_PGaramond,
				SRect(SVector2(position.X - 150, position.Y - 50), SVector2(500, 50)), SColor(255, 255, 255));
			pNPCText->SetInWorld(true);
			CTM->AddUIObject(pNPCText);
		}
	if (m_pColTarget->GetTag() == "Gleiter")
		m_glider = true;
	}


	// if target has nullptr, do nothing
	if (m_pColTarget == nullptr)
	{

	}
	// if the target has tag water
	else if (m_pColTarget->GetTag() == "Water")
	{
		// set grounded to always true
		m_grounded = true;

		// set gravity
		CPhysic::s_Gravity = WATER_GRAVITY * BLOCK_HEIGHT;
	}
	// if target has tag ___ 
	else if (m_pColTarget->GetTag() == "NoWater")
	{
		// set gravity to normal again
		CPhysic::s_Gravity = EARTH_GRAVITY * BLOCK_HEIGHT;
	}

	// if key d pressed
	if (CInput::GetKey(SDL_SCANCODE_D))
	{
		// set Game Gravity when play is grounded
		if (m_grounded) CPhysic::s_Gravity = EARTH_GRAVITY * BLOCK_HEIGHT;
		// set movement right and mirror not
		if (m_movement.X < 1.0f)
		{
			m_movement.X += 0.2f;
		}
		if (m_movement.X > 0)
		{
			m_mirror.X = 0.0f;
		}
		if (m_movement.X > 1.0f)
		{
			m_movement.X = 1.0f;
		}
	}

	// if key a pressed
	else if (CInput::GetKey(SDL_SCANCODE_A))
	{
		// set Game Gravity when play is grounded
		if (m_grounded) CPhysic::s_Gravity = EARTH_GRAVITY * BLOCK_HEIGHT;
		// set movement left and mirror horizontal
		if (m_movement.X > -1.0f)
		{
			m_movement.X -= 0.2f;
		}
		if (m_movement.X < 0)
		{
			m_mirror.X = 1.0f;
		}
		if (m_movement.X < -1.0f)
		{
			m_movement.X = -1.0f;
		}
	}

	// if not key d or a pressed
	else if (!CInput::GetKey(SDL_SCANCODE_D) && !CInput::GetKey(SDL_SCANCODE_A))
	{
		// reset movement left right
		if (m_movement.X > 0)
		{
			m_movement.X -= 0.1f;
		}
		if (m_movement.X < 0)
		{
			m_movement.X += 0.1f;
		}
		if (m_movement.X > -0.1f && m_movement.X < 0.1f)
		{
			m_movement.X = 0;
		}
	}

	// if key space pressed down
	if (CInput::GetKeyDown(SDL_SCANCODE_SPACE))
	{
		if (m_grounded)
			// jump
			m_fallTime = PLAYER_JUMP_FORCE;
	}

	// if key shift, more speed
	if (CInput::GetKeyDown(SDL_SCANCODE_LSHIFT))
	{
		m_speed = 355;
	}
	if (CInput::GetKeyUp(SDL_SCANCODE_LSHIFT))
	{
		m_speed = 255;
	}

	// if key y pressed down
	if (CInput::GetKeyDown(SDL_SCANCODE_F) && m_glider == true)
	{
		if (!m_grounded)
			// glide
			CPhysic::s_Gravity = GLIDE_GRAVITY * BLOCK_HEIGHT;
	}

	if (CInput::GetKeyDown(SDL_SCANCODE_RETURN))
	{
		GBullet* pBullet = new GBullet("Texture/Bullet/T_Bullet.png", m_position, SVector2(8, 8));
		CTM->AddPersistantObject(pBullet);
		pBullet->SetSpeed(BULLET_SPEED);
		pBullet->SetColType(ECollisionType::MOVE);
		pBullet->SetTag("Bullet");

		if (m_mirror.X)
		{
			pBullet->SetMovement(SVector2(-1.0f, 0.0f));
			pBullet->SetPosition(m_position + SVector2(-m_rect.w * 0.5f, 16.0f));
		}
		else
		{
			pBullet->SetMovement(SVector2(1.0f, 0.0f));
			pBullet->SetPosition(m_position + SVector2(m_rect.w * 1.5f, 16.0f));
		}
	}

	// update move object parent
	CMoveObject::Update(_deltaSeconds);

	// set camera position
	SVector2 pos = m_position;
	pos.X *= RENDERER->GetZoom();
	pos.Y *= RENDERER->GetZoom();

	// if camera x in range
	if (m_position.X * RENDERER->GetZoom() >= SCREEN_WIDTH / 2 &&
		m_position.X * RENDERER->GetZoom() <= m_cameraMaxValue.X)
	{
		// if camera y in range
		if (m_position.Y <= m_cameraMaxValue.Y  * RENDERER->GetZoom())
			RENDERER->SetCamera(SVector2(pos.X, pos.Y));

		// if camera y not in range
		else
			RENDERER->SetCamera(SVector2(pos.X, RENDERER->GetCamera().Y));
	}

	// if camera y in range and x not in range
	else if (m_position.Y <= m_cameraMaxValue.Y  * RENDERER->GetZoom())
	{
		RENDERER->SetCamera(SVector2(RENDERER->GetCamera().X, pos.Y));
	}

	// if camera x and y not in range
	else
		RENDERER->SetCamera(SVector2(RENDERER->GetCamera().X, RENDERER->GetCamera().Y));

	// if player hits NPC
	if (m_position.X >= 256 - m_rect.w && m_position.X <= 350 + 32 && m_position.Y <= 550 + 54 && m_position.Y >= 468 - m_rect.h)
	{
		// create text and add to ctm
		CText* pNPCText = new CText("Hier kommt eine Story hin !", GAME->m_PGaramond, SRect(SVector2(300, 400), SVector2(500, 50)), SColor(255, 255, 255));
		pNPCText->SetInWorld(true);
		CTM->AddUIObject(pNPCText);
	}
}

// render every frame
void GPlayer::Render()
{
	// render parent
	CMoveObject::Render();
}
#pragma endregion