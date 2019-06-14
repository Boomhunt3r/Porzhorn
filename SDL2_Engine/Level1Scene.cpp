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

#pragma region public overrice function
// Load scene
void GLevel1Scene::Load()
{
	// initialize background music
	m_pBackground = new CMusic("Audio/M_Background.mp3");
	// set volume
	m_pBackground->SetVolume(50);
	// play
	m_pBackground->Play(true);

	// create and initialize world
	m_pLevel = new GLevel01(nullptr);
	m_pLevel->Init();

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
#pragma endregion

