#pragma region project include
#include "Game.h"
#include "MenuScene.h"
#include "Engine.h"
#include "Font.h"
#include "Texture.h"
#include "WinScene.h"
#include "CreditScene.h"
#include "DeathScene.h"
#include "MainScene.h"
#include "World.h"
#include "BossLevelScene.h"
#pragma endregion

#pragma region public function
// initialize game
void GGame::Init()
{
	// create garamond font
	m_PGaramond = new CFont("Font/F_Garamond.ttf", 100);

	// set state to menu
	m_state = EGameState::MENU;

	// create new main scene
	ENGINE->ChangeScene(new GMenuScene());
}

// update every frame
void GGame::Update(float _deltaSeconds)
{
	switch (m_state)
	{
	case MENU:
		break;
	case MAIN:
		break;
	case GAMEOVER:
		ENGINE->ChangeScene(new GDeathScene());
		m_state = EGameState::DEATHSCENE;
		break;
	case WIN:
		ENGINE->ChangeScene(new GWinScene());
		m_state = EGameState::WINMENU;
		break;
	case WINMENU:
		break;
	case CREDIT:
		ENGINE->ChangeScene(new GCreditScene());
		break;
	case CREDITSCENE:
		break;
	case DEATHSCENE:
		break;
	case BOSSLEVEL:
		ENGINE->ChangeScene(new GBossLevelScene());
		m_state = EGameState::BOSSSCENE;
		break;
	case BOSSSCENE:
		break;
	default:
		break;
	}
}

// if player dies
void GGame::GameOver()
{
	m_state = EGameState::GAMEOVER;
}

// if player wins
void GGame::Win()
{
	m_state = EGameState::WIN;
}

// if player goes trough the Door
void GGame::BossLevel()
{
	m_state = EGameState::BOSSLEVEL;
}
#pragma endregion