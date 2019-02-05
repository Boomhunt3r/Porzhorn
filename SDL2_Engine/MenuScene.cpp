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
#pragma endregion

#pragma region public function
// load scene
void GMenuScene::Load()
{
	// create mouse texture
	CTexture* pMouseTexture = new CTexture("Texture/Mouse/T_Mouse.png");

	// set mouse texture
	ENGINE->SetMouseTexture(pMouseTexture);
	ENGINE->SetMouseVisible(true);
	ENGINE->SetMouseCenter(SVector2());

	// create text and add to ctm
	CText* pStartGame = new CText("Start", GAME->m_PGaramond, SRect(SVector2(SCREEN_WIDTH / 2 - 55, 300), SVector2(100, 50)), SColor(255, 255, 255));
	pStartGame->SetInWorld(false);
	CTM->AddUIObject(pStartGame);

	// create text and add to ctm
	CText* pCredit = new CText("Credits", GAME->m_PGaramond, SRect(SVector2(SCREEN_WIDTH / 2 - 55, 400), SVector2(100, 50)), SColor(255, 255, 255));
	pCredit->SetInWorld(false);
	CTM->AddUIObject(pCredit);
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
	// if mouse position in start game button
	if (CInput::GetMouseButtonDown(0) &&
		CInput::GetMousePos().X >= (SCR EEN_WIDTH / 2 - 50) && CInput::GetMousePos().X <= (SCREEN_WIDTH / 2 - 50) + 100 &&
		CInput::GetMousePos().Y >= 300 && CInput::GetMousePos().Y <= 350)
	{
		ENGINE->ChangeScene(new GMainScene());
	}
	// if mouse position in start game button
	if (CInput::GetMouseButtonDown(0) &&
		CInput::GetMousePos().X >= (SCREEN_WIDTH / 2 - 50) && CInput::GetMousePos().X <= (SCREEN_WIDTH / 2 - 50) + 100 &&
		CInput::GetMousePos().Y >= 400 && CInput::GetMousePos().Y <= 450)
	{
		ENGINE->ChangeScene(new GCreditScene());
	}
}

// render every frame
void GMenuScene::Render()
{
	
}
#pragma endregion