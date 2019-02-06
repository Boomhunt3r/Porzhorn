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
	CTexturedObject* pBackgroundTexture = new CTexturedObject("Texture/Background/T_Main_Slim.png", SVector2(-SCREEN_WIDTH / 2, -SCREEN_HEIGHT / 2), SVector2(1280, 720));
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

}
#pragma endregion