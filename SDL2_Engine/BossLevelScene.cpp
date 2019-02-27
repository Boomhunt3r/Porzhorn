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
#pragma endregion

// load scene
void GBossLevelScene::Load()
{
	// create and initialize world
	m_pLevel = new GLevel02(nullptr);
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
