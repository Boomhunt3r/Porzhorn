#pragma region project include
#include "WinScene.h"
#include "MenuScene.h"
#include "MainScene.h"
#include "Engine.h"
#include "ContentManagement.h"
#include "Texture.h"
#include "Text.h"
#include "Game.h"
#include "Input.h"
#include "Animation.h"
#pragma endregion

#pragma region public function
// load scene
void GWinScene::Load()
{
	CTexturedObject* pBackground = new CTexturedObject("Texture/Background/T_Win.png",
		SVector2(0, 0), SVector2(1280, 720));
	m_WinAnimation.SetAnimationObject(pBackground);
	m_WinAnimation.SetAnimationRect(SRect(1280, 720, 0, 0));
	pBackground->SetInWorld(false);
	CTM->AddUIObject(pBackground);
	// create mouse texture
	CTexture* pMouseTexture = new CTexture("Texture/Mouse/T_Mouse.png");

	// set mouse texture
	ENGINE->SetMouseTexture(pMouseTexture);
	ENGINE->SetMouseVisible(true);
	ENGINE->SetMouseCenter(SVector2());
}

// clean scene
void GWinScene::Clean()
{
	// clean ui objects
	CTM->CleanUIObjects();
}

// update every frame
void GWinScene::Update(float _deltaSeconds)
{
	m_WinAnimation.SetAnimationRect(SRect(1280, 720, 0, 0));

	_i = 606 / 404;

	_l += _i;

	if (_l >= 0 && _l <= 20)
	{
		m_WinAnimation.SetAnimationRect(SRect(1280, 720, 1280, 0));
	}
	if (_l >= 40 && _l <= 60)
	{
		m_WinAnimation.SetAnimationRect(SRect(1280, 720, 2560, 0));
	}
	if (_l >= 80 && _l <= 100)
	{
		m_WinAnimation.SetAnimationRect(SRect(1280, 720, 3840, 0));
	}
	if (_l >= 120 && _l <= 140)
	{
		m_WinAnimation.SetAnimationRect(SRect(1280, 720, 0, 720));
	}
	if (_l >= 160 && _l <= 180)
	{
		m_WinAnimation.SetAnimationRect(SRect(1280, 720, 1280, 720));
	}
	if (_l >= 200 && _l <= 220)
	{
		m_WinAnimation.SetAnimationRect(SRect(1280, 720, 2560, 720));
	}
	if (_l >= 240 && _l <= 260)
	{
		m_WinAnimation.SetAnimationRect(SRect(1280, 720, 3840, 720));
	}
	if (_l >= 280 && _l <= 300)
	{
		m_WinAnimation.SetAnimationRect(SRect(1280, 720, 0, 1440));
	}
	if (_l >= 320 && _l <= 340)
	{
		m_WinAnimation.SetAnimationRect(SRect(1280, 720, 1280, 1440));
	}
	if (_l >= 360 && _l <= 380)
	{
		m_WinAnimation.SetAnimationRect(SRect(1280, 720, 2560, 1440));
	}
	if (_l >= 400 && _l <= 420)
	{
		m_WinAnimation.SetAnimationRect(SRect(1280, 720, 3840, 1440));
	}
	if (_l >= 440 && _l <= 460)
	{
		m_WinAnimation.SetAnimationRect(SRect(1280, 720, 0, 2160));
	}
	if (_l >= 480 && _l <= 500)
	{
		m_WinAnimation.SetAnimationRect(SRect(1280, 720, 1280, 2160));
	}
	if (_l >= 520 && _l <= 540)
	{
		m_WinAnimation.SetAnimationRect(SRect(1280, 720, 2560, 2160));
	}
	if (_l >= 560 && _l <= 580)
	{
		m_WinAnimation.SetAnimationRect(SRect(1280, 720, 3840, 2160));
	}
	if (_l >= 600 && _l <= 660)
	{
		m_WinAnimation.SetAnimationRect(SRect(1280, 720, 0, 2880));
	}
	if (_l >= 680 && _l <= 700)
	{
		m_WinAnimation.SetAnimationRect(SRect(1280, 720, 1280, 2880));
	}
	if (_l >= 720 && _l <= 740)
	{
		m_WinAnimation.SetAnimationRect(SRect(1280, 720, 2560, 2880));
	}
	if (_l >= 760 && _l <= 780)
	{
		m_WinAnimation.SetAnimationRect(SRect(1280, 720, 3840, 2880));
	}
	if (_l >= 800 && _l <= 820)
	{
		m_WinAnimation.SetAnimationRect(SRect(1280, 720, 0, 3600));
	}
	if (_l >= 840 && _l <= 860)
	{
		m_WinAnimation.SetAnimationRect(SRect(1280, 720, 1280, 3600));
	}
	if (_l >= 880)
	{
		_l = 0;
	}
	// if mouse position in start game button
	if (CInput::GetMouseButtonDown(0) &&
		CInput::GetMousePos().X >= 525 && CInput::GetMousePos().X <= 750 &&
		CInput::GetMousePos().Y >= 600 && CInput::GetMousePos().Y <= 690)
	{
		ENGINE->ChangeScene(new GMenuScene());
	}
}

// render every frame
void GWinScene::Render()
{
	m_WinAnimation.GetAnimationObject()->SetSrcRect(m_WinAnimation.GetAnimationRect());
}
#pragma endregion