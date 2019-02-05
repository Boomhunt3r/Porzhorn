#pragma region project include
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

void GCreditScene::Load()
{
	// create mouse texture
	CTexture* pMouseTexture = new CTexture("Texture/Mouse/T_Mouse.png");

	// set mouse texture
	ENGINE->SetMouseTexture(pMouseTexture);
	ENGINE->SetMouseVisible(true);
	ENGINE->SetMouseCenter(SVector2());

	// create text and add to ctm
	CText* pMenuGame = new CText("Menü", GAME->m_PGaramond, SRect(SVector2(SCREEN_WIDTH / 2 - 55, SCREEN_HEIGHT - 50), SVector2(100, 50)), SColor(255, 255, 255));
	pMenuGame->SetInWorld(false);
	CTM->AddUIObject(pMenuGame);

	// create win text and add to ctm
	CText* pCreditText = new CText("Hier kommen die Credits hin", GAME->m_PGaramond, SRect(SVector2(SCREEN_WIDTH / 2 - 200, 200), SVector2(350, 50)), SColor(255, 255, 255));
	pCreditText->SetInWorld(false);
	CTM->AddUIObject(pCreditText);
}

void GCreditScene::Clean()
{
	// clean ui objects
	CTM->CleanUIObjects();
}

void GCreditScene::Update(float _deltaSeconds)
{
	// if mouse position in start game button
	if (CInput::GetMouseButtonDown(0) &&
		CInput::GetMousePos().X >= (SCREEN_WIDTH / 2 - 50) && CInput::GetMousePos().X <= (SCREEN_WIDTH / 2 - 50) + 100 &&
		CInput::GetMousePos().Y >= SCREEN_HEIGHT - 50 && CInput::GetMousePos().Y <= SCREEN_HEIGHT)
	{
		ENGINE->ChangeScene(new GMenuScene());
	}
}

void GCreditScene::Render()
{

}
