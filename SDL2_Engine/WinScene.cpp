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
	pBackground->SetSrcRect((SRect(1280, 720, 0, 0)));
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
}
#pragma endregion