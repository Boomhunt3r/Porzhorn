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
	CTexturedObject* pBackgroundTexture = new CTexturedObject("Texture/Background/T_Main_Slim.png",
		SVector2(-SCREEN_WIDTH / 2, -SCREEN_HEIGHT / 2), SVector2(1280, 720));
		pBackgroundTexture->SetSrcRect(SRect(1280, 720, 0, 0));
		m_MenuAnimation.SetAnimationObject(pBackgroundTexture);
		m_MenuAnimation.SetAnimationRect(SRect(1280, 720, 0, 0));
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
	//m_MenuAnimation.SetAnimationRect(SRect(1280, 720, 0, 0));
	//
	//_i = 606 / 404;
	//
	//_l += _i;
	//
	//if (_l >= 6 && _l <= 12)
	//{
	//	m_MenuAnimation.SetAnimationRect(SRect(1280, 720, 1280, 0));
	//}
	//if (_l >= 15 && _l <= 21)
	//{
	//	m_MenuAnimation.SetAnimationRect(SRect(1280, 720, 2560, 0));
	//}
	//if (_l >= 24 && _l <= 30)
	//{
	//	m_MenuAnimation.SetAnimationRect(SRect(1280, 720, 3840, 0));
	//}
	//if (_l >= 33 && _l <= 39)
	//{
	//	m_MenuAnimation.SetAnimationRect(SRect(1280, 720, 5120, 0));
	//}
	//if (_l >= 42 && _l <= 48)
	//{
	//	m_MenuAnimation.SetAnimationRect(SRect(1280, 720, 6400, 0));
	//}
	//if (_l >= 51 && _l <= 57)
	//{
	//	m_MenuAnimation.SetAnimationRect(SRect(1280, 720, 7680, 0));
	//}
	//if (_l >= 60 && _l <= 66)
	//{
	//	m_MenuAnimation.SetAnimationRect(SRect(1280, 720, 8960, 0));
	//}
	//
	//if (_l >= 69)
	//{
	//	_l = 0;
	//}
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