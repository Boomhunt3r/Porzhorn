#pragma region project include
#include "MainScene.h"
#include "Engine.h"
#include "ContentManagement.h"
#include "World.h"
#include "TextFPS.h"
#include "Game.h"
#include "Config.h"
#include "Physic.h"
#pragma endregion

#pragma region public override function
// load scene
void GMainScene::Load()
{
	// create and initialize world
	m_pWorld = new GWorld(nullptr);
	m_pWorld->Init();

	// load NPC and add to ctm
	//CTexturedObject* pNpc = new CTexturedObject("Texture/Player/T_Player.png", SVector2(350, 550), SVector2(32, 54));
	//CTM->AddSceneObject(pNpc);

	// create fps text and add to ctm
	GTextFPS* pFPS = new GTextFPS("60", GAME->m_PGaramond, SRect(SVector2(0, 0), SVector2(100, 50)), SColor(255, 255, 255));
	pFPS->SetInWorld(false);
	CTM->AddUIObject(pFPS);

	// disable mouse
	ENGINE->SetMouseVisible(false);

	// set gravity
	CPhysic::s_Gravity = EARTH_GRAVITY * BLOCK_HEIGHT;
}

// clean up scene
void GMainScene::Clean()
{
	// delete all objects
	CTM->CleanSceneObjects();
	CTM->CleanUIObjects();
	CTM->CleanPersistantObjects();

	// delete world
	delete m_pWorld;
}

// update every frame
void GMainScene::Update(float _deltaTime)
{
	
}

// render every frame
void GMainScene::Render()
{
	
}
#pragma endregion