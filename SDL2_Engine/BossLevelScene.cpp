#pragma region project include
#include "BossLevelScene.h"
#include "Engine.h"
#include "ContentManagement.h"
#include "World.h"
#include "TextFPS.h"
#include "Game.h"
#include "Config.h"
#include "Physic.h"
#include "Level02.h"  
#include "Music.h"
#pragma endregion

#pragma region public override function
// load scene
void GBossLevelScene::Load()
{
	// initialize background music
	m_pBackground = new CMusic("Audio/M_BattleBackground.mp3");
	// sett volume
	m_pBackground->SetVolume(50);
	// play music
	m_pBackground->Play(true);

	// create and initialize world
	m_pLevel = new GLevel02(nullptr);
	m_pLevel->Init();

	// disable mouse
	ENGINE->SetMouseVisible(false);

	// set gravity
	CPhysic::s_Gravity = EARTH_GRAVITY * BLOCK_HEIGHT;
}

// clean scene
void GBossLevelScene::Clean()
{
	// delete all objects
	CTM->CleanSceneObjects();
	CTM->CleanUIObjects();
	CTM->CleanPersistantObjects();

	// delete world
	delete m_pLevel;
}


// update every frame
void GBossLevelScene::Update(float _deltaTime)
{
}

// render every frame
void GBossLevelScene::Render()
{
}

#pragma endregion
