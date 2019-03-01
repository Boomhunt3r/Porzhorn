#pragma region project include
#include "Level1Scene.h"
#include "Engine.h"
#include "ContentManagement.h"
#include "World.h"
#include "TextFPS.h"
#include "Game.h"
#include "Config.h"
#include "Physic.h"
#include "Level01.h" 
#include "Music.h"
#pragma endregion

// Load scene
void GLevel1Scene::Load()
{
	m_pBackground = new CMusic("Audio/M_Background.wav");
	m_pBackground->SetVolume(50);
	m_pBackground->Play(true);

	// create and initialize world
	m_pLevel = new GLevel01(nullptr);
	m_pLevel->Init();

	// create fps text and add to ctm
	GTextFPS* pFPS = new GTextFPS("60", GAME->m_PGaramond, SRect(SVector2(0, 0), SVector2(100, 50)), SColor(255, 255, 255));
	pFPS->SetInWorld(false);
	CTM->AddUIObject(pFPS);

	// disable mouse
	ENGINE->SetMouseVisible(false);

	// set gravity
	CPhysic::s_Gravity = EARTH_GRAVITY * BLOCK_HEIGHT;
}

// clean scene
void GLevel1Scene::Clean()
{
	// delete all objects
	CTM->CleanSceneObjects();
	CTM->CleanUIObjects();
	CTM->CleanPersistantObjects();

	delete m_pBackground;

	// delete world
	delete m_pLevel;
}
// update every frame
void GLevel1Scene::Update(float _deltaTime)
{

}

// render every frame
void GLevel1Scene::Render()
{

}
