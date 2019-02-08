#pragma region project include
#include "DeathScene.h"
#include "CreditScene.h"
#include "WinScene.h"
#include "MenuScene.h"
#include "MainScene.h"
#include "Engine.h"
#include "ContentManagement.h"
#include "Texture.h"
#include "Text.h"
#include "Game.h"
#include "Input.h"
#include "Macro.h"  
#pragma endregion

void GDeathScene::Load()
{

	// create mouse texture
	CTexture* pMouseTexture = new CTexture("Texture/Mouse/T_Mouse.png");

	// set mouse texture
	ENGINE->SetMouseTexture(pMouseTexture);
	ENGINE->SetMouseVisible(true);
	ENGINE->SetMouseCenter(SVector2());

	CTexturedObject* pBackground = new CTexturedObject("Texture/Background/T_dead.png",
		SVector2(0, 0), SVector2(1280, 720));
	// m_MenuAnimation.SetAnimationObject(pBackgroundTexture);
	// m_MenuAnimation.SetAnimationRect(SRect(1280, 720, 0, 0));
	pBackground->SetInWorld(false);
	CTM->AddUIObject(pBackground);

	// create text and add to ctm
	CText* pStartGame = new CText("Restart", GAME->m_PGaramond, SRect(SVector2(SCREEN_WIDTH / 2 - 55, 300), SVector2(100, 50)), SColor(255, 255, 255));
	pStartGame->SetInWorld(false);
	CTM->AddUIObject(pStartGame);

	// create text and add to ctm
	CText* pMenu = new CText("Menü", GAME->m_PGaramond, SRect(SVector2(SCREEN_WIDTH / 2 - 55, 400), SVector2(100, 50)), SColor(255, 255, 255));
	pMenu->SetInWorld(false);
	CTM->AddUIObject(pMenu);
}

void GDeathScene::Clean()
{
	// clean ui objects
	CTM->CleanUIObjects();
}

void GDeathScene::Update(float _deltaSeconds)
{
	// if mouse position in start game button
	if (CInput::GetMouseButtonDown(0) &&
		CInput::GetMousePos().X >= (SCREEN_WIDTH / 2 - 50) && CInput::GetMousePos().X <= (SCREEN_WIDTH / 2 - 50) + 100 &&
		CInput::GetMousePos().Y >= 300 && CInput::GetMousePos().Y <= 350)
	{
		ENGINE->ChangeScene(new GMainScene());
	}
	// if mouse position in start game button
	if (CInput::GetMouseButtonDown(0) &&
		CInput::GetMousePos().X >= (SCREEN_WIDTH / 2 - 50) && CInput::GetMousePos().X <= (SCREEN_WIDTH / 2 - 50) + 100 &&
		CInput::GetMousePos().Y >= 400 && CInput::GetMousePos().Y <= 450)
	{
		ENGINE->ChangeScene(new GMenuScene());
	}
}

void GDeathScene::Render()
{

}
#pragma endregion
