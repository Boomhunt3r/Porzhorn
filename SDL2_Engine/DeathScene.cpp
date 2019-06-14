#pragma region project include
#include "DeathScene.h"
#include "CreditScene.h"
#include "WinScene.h"
#include "MenuScene.h"
#include "Engine.h"
#include "ContentManagement.h"
#include "Texture.h"
#include "Text.h"
#include "Game.h"
#include "Input.h"
#include "Macro.h"  
#include "Animation.h"
#include "Level1Scene.h"
#pragma endregion

void GDeathScene::Load()
{
	// initialize Death Background Music
	m_pBackground = new CMusic("Audio/M_DeathBackground.mp3");
	m_pBackground->SetVolume(50);
	m_pBackground->Play(true);

	CTexturedObject* pBackground = new CTexturedObject("Texture/Background/T_Dead.png",
		SVector2(0, 0), SVector2(1280, 720));
	pBackground->SetSrcRect(SRect(1280, 720, 0, 0));
	pBackground->SetInWorld(false);
	CTM->AddUIObject(pBackground);

	// create mouse texture
	CTexture* pMouseTexture = new CTexture("Texture/Mouse/T_Mouse.png");

	// set mouse texture
	ENGINE->SetMouseTexture(pMouseTexture);
	ENGINE->SetMouseVisible(true);
	ENGINE->SetMouseCenter(SVector2());

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
        CInput::GetMousePos().X >= 550 && CInput::GetMousePos().X <= 700 &&
        CInput::GetMousePos().Y >= 140 && CInput::GetMousePos().Y <= 350)
    {
        ENGINE->ChangeScene(new GLevel1Scene());
    }
    // if mouse position in start game button
    if (CInput::GetMouseButtonDown(0) &&
        CInput::GetMousePos().X >= 530 && CInput::GetMousePos().X <= 750 &&
        CInput::GetMousePos().Y >= 530 && CInput::GetMousePos().Y <= 620)
    {
        ENGINE->ChangeScene(new GMenuScene());
    }
}

void GDeathScene::Render()
{

}
#pragma endregion
