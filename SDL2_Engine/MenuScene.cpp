#pragma region project include
#include "MenuScene.h"
#include "MainScene.h"
#include "Engine.h"
#include "ContentManagement.h"
#include "Texture.h"
#include "Text.h"
#include "Game.h"
#include "Input.h"
#include "CreditScene.h"
#include "Macro.h"
#include "Animation.h"
#pragma endregion

#pragma region public function
// load scene
void GMenuScene::Load()
{
	CTexturedObject* pBackgroundTexture = new CTexturedObject("Texture/Background/T_Menu.png",
		SVector2(0, 0), SVector2(1280, 720));
		pBackgroundTexture->SetSrcRect(SRect(1280, 720, 0, 0));
		m_MenuAnimation.SetAnimationObject(pBackgroundTexture);
		m_MenuAnimation.SetAnimationRect(SRect(1280, 720, 0, 0));
		pBackgroundTexture->SetInWorld(false);
		CTM->AddUIObject(pBackgroundTexture);

	// create mouse texture
	CTexture* pMouseTexture = new CTexture("Texture/Mouse/T_Mouse.png");

	// set mouse texture
	ENGINE->SetMouseTexture(pMouseTexture);
	ENGINE->SetMouseVisible(true);
	ENGINE->SetMouseCenter(SVector2());

}

// clean scene
void GMenuScene::Clean()
{
	// clean ui objects
	CTM->CleanUIObjects();
}

// update every frame
void GMenuScene::Update(float _deltaSeconds)
{
	m_MenuAnimation.SetAnimationRect(SRect(1280, 720, 0, 0));
	
	_i = 606 / 404;
	
	_l += _i;
	
	if (_l >= 0 && _l <= 12)
	{
		m_MenuAnimation.SetAnimationRect(SRect(1280, 720, 1280, 0));
	}
	if (_l >= 24 && _l <= 36)
	{
		m_MenuAnimation.SetAnimationRect(SRect(1280, 720, 2560, 0));
	}
	if (_l >= 48 && _l <= 60)
	{
		m_MenuAnimation.SetAnimationRect(SRect(1280, 720, 0, 720));
	}
	if (_l >= 72 && _l <= 84)
	{
		m_MenuAnimation.SetAnimationRect(SRect(1280, 720, 1280, 720));
	}
	if (_l >= 96 && _l <= 108)
	{
		m_MenuAnimation.SetAnimationRect(SRect(1280, 720, 2560, 720));
	}
	if (_l >= 120 && _l <= 134)
	{
		m_MenuAnimation.SetAnimationRect(SRect(1280, 720, 0, 1440));
	}
	if (_l >= 146 && _l <= 158)
	{
		m_MenuAnimation.SetAnimationRect(SRect(1280, 720, 1280, 1440));
	}
	
	if (_l >= 170)
	{
		_l = 0;
	}
	// if mouse position in start game button
	if (CInput::GetMouseButtonDown(0) &&
		CInput::GetMousePos().X >= (SCREEN_WIDTH / 2 - 560) && CInput::GetMousePos().X <= (SCREEN_WIDTH / 2 - 380) &&
		CInput::GetMousePos().Y >= 300 && CInput::GetMousePos().Y <= 415)
	{
		ENGINE->ChangeScene(new GMainScene());
	}
	// if mouse position in start game button
	if (CInput::GetMouseButtonDown(0) &&
		CInput::GetMousePos().X >= (SCREEN_WIDTH / 2 - 610) && CInput::GetMousePos().X <= (SCREEN_WIDTH / 2 - 415) &&
		CInput::GetMousePos().Y >= 540 && CInput::GetMousePos().Y <= 700)
	{
		ENGINE->ChangeScene(new GCreditScene());
	}
}

// render every frame
void GMenuScene::Render()
{
	m_MenuAnimation.GetAnimationObject()->SetSrcRect(m_MenuAnimation.GetAnimationRect());
}
#pragma endregion