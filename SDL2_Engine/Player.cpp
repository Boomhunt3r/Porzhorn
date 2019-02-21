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
#include "World.h"
#include "Animation.h"
#pragma endregion

#pragma region public override function
// initialize object
void GPlayer::Init()
{
	// set tag
	m_pTag = "Player";

	// set speed
	m_speed = 250.0f;

	// set collision type
	m_colType = ECollisionType::MOVE;

	// deactivate Glider
	m_glider = false;

	// set swimming
	m_swimming = false;

	// activate gravity
	m_gravity = true;

	// initiaize ilde animation
	m_pIDLEAnim = new CAnimation(SVector2(0.0f, PlayerIdlePositionY),
		SVector2(PlayerIdleWidth, PlayerIdleHeight), 5);
	m_pIDLEAnim->SetAnimationTime(1.25f);

	// initialize run animation
	m_pRunAnim = new CAnimation(SVector2(0.0f, PlayerRunPositionY),
		SVector2(PlayerRunWidth, PlayerRunHeight), 4);
	m_pRunAnim->SetAnimationTime(0.5f);

	// initialize Jump animation
	m_pJumpAnim = new CAnimation(SVector2(0.0f, PlayerJumpPositionY),
		SVector2(PlayerJumpWidth, PlayerJumpHeight), 3);
	m_pJumpAnim->SetAnimationTime(0.5f);

	// initialize Swim animation
	m_pSwimAnim = new CAnimation(SVector2(0.0f, PlayerSwimPositionY),
		SVector2(PlayerSwimWidth, PlayerSwimHeight), 2);
	m_pSwimAnim->SetAnimationTime(0.5f);

	// initialize Glide animation
	m_pGlideAnim = new CAnimation(SVector2(0.0f, PlayerGlidePositionY),
		SVector2(PlayerGlideWidth, PlayerGlideHeight), 2);
	m_pGlideAnim->SetAnimationTime(0.5f);

	// initialize Box animation
	m_pBoxAnim = new CAnimation(SVector2(0.0f, PlayerBoxPositionY),
		SVector2(PlayerBoxWidth, PlayerBoxHeight), 3);
	m_pBoxAnim->SetAnimationTime(1.0f);

	// set current animation
	m_pCurrentAnim = m_pIDLEAnim;

	// initialize parent
	CMoveObject::Init();
}

// update every frame
void GPlayer::Update(float _deltaSeconds)
{

	if (m_pColTarget)
	{
		// if Targete has tag Enemy of Fire
		if (m_pColTarget->GetTag() == "Enemy" || m_pColTarget->GetTag() == "Fire" || m_pColTarget->GetTag() == "Boss")
		{
			// You die and game is over
			GAME->GameOver();
		}

		// if Target has tag Goal
		if (m_pColTarget->GetTag() == "Goal" && m_hasKey == true)
		{
			// you win
			GAME->Win();
		}

		// if Target has tag Key
		if (m_pColTarget->GetTag() == "Key")
		{
			m_hasKey = true;
			m_pColTarget->SetPosition(SVector2(10001.0f, 10000.0f));

		}

		// if target has tag NPC
		if (m_pColTarget->GetTag() == "NPC1" && m_NPC1 == false)
		{
			// safe position of Target in primitive valuble
			SVector2 position = m_pColTarget->GetPosition();
			// set text of npc and add to ctm
			CText* pNPCText = new CText("Die Prophezeiung! Wann sie wohl eintreten wird...", GAME->m_PGaramond,
				SRect(SVector2(position.X - 200, position.Y - 50), SVector2(500, 50)), SColor(255, 255, 255));
			pNPCText->SetInWorld(true);
			CTM->AddUIObject(pNPCText);
			m_NPC1 = true;
		}

		// if target has tag NPC
		if (m_pColTarget->GetTag() == "NPC2" && m_NPC2 == false)
		{
			// safe position of Target in primitive valuble
			SVector2 position = m_pColTarget->GetPosition();
			// set text of npc and add to ctm
			CText* pNPCText = new CText("Wo ist nur der Schl�ssel hin?", GAME->m_PGaramond,
				SRect(SVector2(position.X - 200, position.Y - 50), SVector2(500, 50)), SColor(255, 255, 255));
			pNPCText->SetInWorld(true);
			CTM->AddUIObject(pNPCText);
			m_NPC2 = true;
		}

		// if target has tag Schild
		if (m_pColTarget->GetTag() == "Tutorial" && m_Tutorial == false)
		{
			// safe position of Target in primitive valuble
			SVector2 position = m_pColTarget->GetPosition();
			// set text of npc and add to ctm
			CText* pSchildText = new CText("Bewegen: A, D | Springen: SPACE | Gleiten: F", GAME->m_PGaramond,
				SRect(SVector2(position.X - 180, position.Y - 60), SVector2(440, 50)), SColor(255, 255, 255));
			pSchildText->SetInWorld(true);
			CTM->AddUIObject(pSchildText);
			m_Tutorial = true;
		}

		// if target collects glider
		if (m_pColTarget->GetTag() == "Gleiter")
		{
			m_glider = true;
			m_pColTarget->SetPosition(SVector2(10001.0f, 10000.0f));
		}

		// if target has tag water
		if (m_pColTarget->GetTag() == "Water")
		{
			// set swimming to true
			m_swimming = true;

			// set gravity
			CPhysic::s_Gravity = WATER_GRAVITY * BLOCK_HEIGHT;
		}

		// if target has tag gleiter, m_glider is true
		if (m_pColTarget->GetTag() == "Gleiter") m_glider = true;

		// if target has tag gleiter, m_glider is true
		if (m_pColTarget->GetTag() == "Gleiter") m_glider = true;
		if (m_pColTarget->GetTag() == "NoWater")
			m_swimming = false;
	}

	// if key d pressed
	if (CInput::GetKey(SDL_SCANCODE_D))
	{
		// reset gravity when player is grounded and not swimming
		if (m_grounded) CPhysic::s_Gravity = EARTH_GRAVITY * BLOCK_HEIGHT;

		// set run animation
		m_pCurrentAnim = m_pRunAnim;

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
		// set run animation
		m_pCurrentAnim = m_pRunAnim;

		// reset gravity when player is grounded and not swimming
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
		if (!CInput::GetKeyDown(SDL_SCANCODE_RETURN))
			m_pCurrentAnim = m_pIDLEAnim;

		if (CInput::GetKeyDown(SDL_SCANCODE_RETURN))
		{
			m_pCurrentAnim = m_pBoxAnim;
		}

		// reset gravity when player is grounded and not swimming
		if (m_grounded) CPhysic::s_Gravity = EARTH_GRAVITY * BLOCK_HEIGHT;
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
		m_pCurrentAnim = m_pJumpAnim;

		if (m_grounded || m_swimming)
		{
			// jump
			m_fallTime = PLAYER_JUMP_FORCE;
		}
	}

	// if key shift, more speed
	if (CInput::GetKeyDown(SDL_SCANCODE_LSHIFT) && m_grounded)
	{
		m_speed = 355;
	}
	if (CInput::GetKeyUp(SDL_SCANCODE_LSHIFT))
	{
		m_speed = 255;
	}
	// if not grounded
	if (!m_grounded)
	{
		// if is Gliding
		if (m_isGliding == true)
		{
			m_pCurrentAnim = m_pGlideAnim;
		}
	}
	else
	{
		m_isGliding = false;
	}

	// if key f pressed down
	if (CInput::GetKeyDown(SDL_SCANCODE_F) && m_glider == true)
	{
		// if gliding key is pressed
		// isGliding true
		m_isGliding = true;

		if (!m_grounded)
		{
			// glide
			CPhysic::s_Gravity = GLIDE_GRAVITY * BLOCK_HEIGHT;
		}
	}

	if (CInput::GetKeyDown(SDL_SCANCODE_RETURN))
	{
		m_pCurrentAnim = m_pBoxAnim;

		GBullet* pBullet = new GBullet("Texture/Bullet/T_Bullet12.png", m_position, SVector2(8, 8));
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

	if (m_swimming == true)
	{
		m_pCurrentAnim = m_pSwimAnim;
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
		if (m_position.Y <= 415)
			RENDERER->SetCamera(SVector2(pos.X, RENDERER->GetCamera().Y));

		// if camera y in range
		else if (m_position.Y <= m_cameraMaxValue.Y  * RENDERER->GetZoom())
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

	// update current animation
	m_pCurrentAnim->Update(_deltaSeconds);

	// set src rect
	m_srcRect = SRect(
		SVector2(m_pCurrentAnim->GetCurrentTexturePosition().X, m_pCurrentAnim->GetCurrentTexturePosition().Y),
		m_pCurrentAnim->GetSize()
	);
}

// render every frame
void GPlayer::Render()
{
	// render parent
	CMoveObject::Render();
};
#pragma endregion