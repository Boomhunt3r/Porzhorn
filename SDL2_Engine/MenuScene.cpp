#pragma region project include
#include "MenuScene.h"
#include "MainScene.h"
#include "Level1Scene.h"
#include "Engine.h"
#include "ContentManagement.h"
#include "Texture.h"
#include "Text.h"
#include "Game.h"
#include "Input.h"
#include "CreditScene.h"
#include "Macro.h"
#include "Animation.h"
#include "BossLevelScene.h"
#pragma endregion

#pragma region public function
// load scene
void GMenuScene::Load()
{
	CTexturedObject* pBackgroundTexture = new CTexturedObject("Texture/Background/T_Menu.png",
		SVector2(0, 0), SVector2(1280, 720));
		pBackgroundTexture->SetSrcRect(SRect(1280, 720, 0, 0));
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
	// if mouse position in start game button
	if (CInput::GetMouseButtonDown(0) &&
		CInput::GetMousePos().X >= (SCREEN_WIDTH / 2 - 560) && CInput::GetMousePos().X <= (SCREEN_WIDTH / 2 - 380) &&
		CInput::GetMousePos().Y >= 300 && CInput::GetMousePos().Y <= 415)
	{
		ENGINE->ChangeScene(new GLevel1Scene());
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
}
#pragma endregion