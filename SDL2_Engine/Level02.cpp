#pragma region system include
#include <string>
#pragma endregion

#pragma region project include
#include "Level02.h"
#include "Config.h"
#include "Macro.h"
#include "Engine.h"
#include "ContentManagement.h"
#include "Player.h"
#include "MoveEnemy.h"
#include "Boss.h"
#include "Animation.h"
#include "NPC.h"
#pragma endregion

#pragma region using
using namespace std;
#pragma endregion

#pragma region public function

// initlialize world
void GLevel02::Init()
{
	// string to display world
	string world;

	// initialize world
	// 110 w x 25 h
	// D = dirt
	// G = way
	// 0 = background
	// F = fire
	// P = player
	// E = enemy
	// Z = goal
	// S = stone
	// W = Water
	// N = NoWater
	// B = Barriere
	// V = Gleiter

#pragma region BossLevel
	world += "T000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000\n";
	world += "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000\n";
	world += "00000000S0000000000000S00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000\n";
	world += "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000\n";
	world += "000000000000000000000000S000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000\n";
	world += "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000\n";
	world += "0000000S00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000\n";
	world += "0000000000000000000000000S00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000\n";
	world += "000000000000000P000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000\n";
	world += "0000000000S00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000\n";
	world += "0000000000000000000000S00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000\n";
	world += "00000000S0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000\n";
	world += "00000000000000000000000000000000000000000000000000000000000000000000000SS000000000000000000000000000000SSSSSS000000000000000000000000000000000000000000000\n";
	world += "00000000000000000000000000000000000000000000000000000000000000000000000SS000000000000000000000000000000SSSSSS000000000000000000000000000000000000000000000\n";
	world += "0000000000000000000000000S0000000000000000000000000000000000000000000SSSS000000000000000000000000000000SSSSSS000000000000000000000000000000000000000000000\n";
	world += "000000000S00000000000000000000000000000000000000000000000000000000000SSSS000000000000000000000000000000SSSSSS000000000000000000000000000000000000000000000\n";
	world += "0000000000000000000000000000000000000000000000000000000000000000000SSSSSS000000000000000000000000000000SSSSSS000000000000000000000000000000000000000000000\n";
	world += "000000000000000000000S000000000000000000000000000000000000000000000SSSSSS000000000000000000000000000000SSSSSS000000000000000000000000000000000000000000000\n";
	world += "00000000000000000000000000000000000000000000000000000000000000000SSSSSSSS00000000SSSS000000000SSS000000SSSSSS000000000000000000000000000000000000000000000\n";
	world += "0000000S000000000000000000000000000000000000000000000000000000000SSSSSSSS000000000000000000000000000000SSSSSS000000000000000000000000000000000000000000000\n";
	world += "000000000000000000000000000000000000000000000000SSSSSS0000SS000SSSSSSSSSSS0000000000000K00000000000000SSSSSSS000000000000000000000000000000000000000000000\n";
	world += "0000000000000000000000000000SSSSS00000SSSSSS0000S0000S0000SS000S00000000SS0000000000000000000000000000SSSSSSS000000000000000000000000000000000000000000000\n";
	world += "SSSSSSSSSSSSSSSSSSSSSSSSSSSS0000S00000S0000S0000S0000S0000SS000S00000000SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS000000000000000000000000000000000000000000000\n";
	world += "00000000000000000000000000000000S00000S0000S0000S0000S0000SS000S0000000000000000000000000000000000000000SSSSS000000000000000000000000000000000000000000000\n";
	world += "00000000000000000000000000000000SFFFFFS0000SFFFFS0000SFFFFSSFFFS00000000000000000000000000000000000000000SSSS000000000000000000000000000000000000000000000";
#pragma endregion Level02

	// width and height
	int width = 0, height = 1;

	// width of level
	int levelWidth = 0;

	// height of level
	int levelHeight = 1;

	// check all chars of world
	for (int i = 0; i < world.length(); i++)
	{
		// increase level width
		levelWidth++;

		// if new line
		if (world[i] == '\n')
		{
			// increase level height
			levelHeight++;

			// reset level width
			levelWidth = 0;
		}
	}

	// check all chars of world
	for (int i = 0; i < world.length(); i++)
	{

		// create new textured object
		CTexturedObject* pObj = new CTexturedObject("Texture/World/T_WorldSide.png",
			SVector2(width * BLOCK_WIDTH, (height - 1) * BLOCK_HEIGHT),
			SVector2(BLOCK_WIDTH, BLOCK_HEIGHT));

		// x position of texture in source
		int xPosTexture = 0;

		// check current char
		// X = dirt
		// W = way
		// 0 = background
		// F = fire
		// S = player
		// G = goal
		switch (world[i])
		{
		case 'S':
			xPosTexture = BLOCK_SOURCE_WIDTH;
			pObj->SetColType(ECollisionType::WALL);
			break;
		case 'G':
			xPosTexture = 2 * BLOCK_SOURCE_WIDTH;
			pObj->SetColType(ECollisionType::WALL);
			break;
		case 'F':
			xPosTexture = 3 * BLOCK_SOURCE_WIDTH;
			pObj->SetTag("Fire");
			pObj->SetColType(ECollisionType::ENEMY);
			break;
		case 'D':
			xPosTexture = 5 * BLOCK_SOURCE_WIDTH;
			pObj->SetColType(ECollisionType::WALL);
			break;
		case 'W':
			xPosTexture = 6 * BLOCK_SOURCE_WIDTH;
			pObj->SetTag("Water");
			pObj->SetColType(ECollisionType::COL);
			break;
		case 'N':
			xPosTexture = 0;
			pObj->SetTag("NoWater");
			pObj->SetColType(ECollisionType::COL);
			break;
		case 'B':
			xPosTexture = 5 * BLOCK_SOURCE_WIDTH;
			pObj->SetTag("Barrier");
			pObj->SetColType(ECollisionType::COL);
			break;
		default:
			break;
		}

		// if T
		if (world[i] == 'T')
		{
			// load texture
			CTexturedObject* pWorld01 = new CTexturedObject("Texture/World/T_BossLevelScale.png",
				SVector2(0, 36), SVector2(7392, 1200));
			CTM->AddPersistantObject(pWorld01);
		}
		// if Z (goal)
		else if (world[i] == 'Z')
		{
			// load goal and add to ctm
			CTexturedObject* pGoal = new CTexturedObject("Texture/World/T_Door.png",
				SVector2(width * BLOCK_WIDTH, (height - 1.4f) * BLOCK_HEIGHT), SVector2(213, 157));
			pGoal->SetTag("Goal");
			pGoal->SetColType(COL);
			CTM->AddPersistantObject(pGoal);
		}
		// if Boss
		else if (world[i] == 'K')
		{
			// load Boss, initialize and add to ctm
			GBoss* pBoss = new GBoss("Texture/Enemy/T_King.png",
				SVector2(width * BLOCK_WIDTH, (height - 4.5) * BLOCK_HEIGHT), SVector2(BOSS_WIDTH, BOSS_HEIGHT));
			pBoss->Init();
			CTM->AddPersistantObject(pBoss);
		}
		// if Schild I
		else if (world[i] == 'I')
		{
			// load NPC and add to ctm
			CTexturedObject* pSchild = new CTexturedObject("Texture/World/T_Sign.png",
				SVector2(width * BLOCK_WIDTH, (height - 1.3f)* BLOCK_HEIGHT), SVector2(55, 64));
			pSchild->SetTag("Tutorial");
			pSchild->SetColType(COL);
			CTM->AddPersistantObject(pSchild);
		}

		// if player
		else if (world[i] == 'P')
		{
			// load player, initialize and add to ctm
			GPlayer* pPlayer = new GPlayer("Texture/Player/T_Jurgo.png",
				SVector2(width * BLOCK_WIDTH, (height - 1) * BLOCK_HEIGHT), SVector2(64, 64));
			pPlayer->Init();
			pPlayer->SetTag("Player");
			pPlayer->SetCameraMaxPosition(
				SVector2(levelWidth * BLOCK_WIDTH - SCREEN_WIDTH / 2,
					levelHeight * BLOCK_HEIGHT - SCREEN_HEIGHT / 2));
			CTM->AddPersistantObject(pPlayer);
		}
		// if enemy
		else if (world[i] == 'E')
		{
			// load enemy, initialize and add to ctm
			GMoveEnemy* pEnemy = new GMoveEnemy("Texture/Enemy/T_Panda.png",
				SVector2(width * BLOCK_WIDTH, (height - 1) * BLOCK_HEIGHT), SVector2(MOVE_ENEMY_WIDTH, MOVE_ENEMY_HEIGHT));
			pEnemy->Init();
			CTM->AddPersistantObject(pEnemy);
		}
		// if NPC 1
		else if (world[i] == '1')
		{
			// load NPC and add to ctm
			GNPC* pNpc1 = new GNPC("Texture/NPC/T_Npc.png",
				SVector2(width * BLOCK_WIDTH, (height - 1.5f) * BLOCK_HEIGHT), SVector2(55, 64));
			pNpc1->SetTag("NPC1");
			pNpc1->SetColType(COL);
			pNpc1->Init();
			CTM->AddPersistantObject(pNpc1);
		}
		// if NPC 1
		else if (world[i] == '2')
		{
			// load NPC and add to ctm
			GNPC* pNpc2 = new GNPC("Texture/NPC/T_Npc.png",
				SVector2(width * BLOCK_WIDTH, (height - 1.5f) * BLOCK_HEIGHT), SVector2(55, 64));
			pNpc2->SetTag("NPC2");
			pNpc2->SetColType(COL);
			pNpc2->Init();
			CTM->AddPersistantObject(pNpc2);
		}
		// if R (key)
		else if (world[i] == 'R')
		{
			// load key and add to ctm
			CTexturedObject* pKey = new CTexturedObject("Texture/World/T_Key.png",
				SVector2(width * BLOCK_WIDTH, (height - 1) * BLOCK_HEIGHT), SVector2(44, 21));
			pKey->SetTag("Key");
			pKey->SetColType(COL);
			CTM->AddPersistantObject(pKey);
		}
		// if Glider
		else if (world[i] == 'V')
		{
			// load Glider and add to ctm
			CTexturedObject* pGlider = new CTexturedObject("Texture/World/T_Leaf.png",
				SVector2(width * BLOCK_WIDTH, (height - 1.5f) * BLOCK_HEIGHT), SVector2(64, 64));
			pGlider->SetTag("Gleiter");
			pGlider->SetColType(COL);
			CTM->AddPersistantObject(pGlider);
		}

		// set source rect
		pObj->SetSrcRect(SRect(
			SVector2(xPosTexture, 0.0f),
			SVector2(BLOCK_SOURCE_WIDTH, BLOCK_SOURCE_HEIGHT)));


		// increase width
		width++;

		// if new line
		if (world[i] == '\n')
		{
			// increase height and reset width
			height++;
			width = 0;

			/// TODO:
			// delete object
			//delete pObj;
		}

		// if not new line
		else
		{
			// add object to ctm
			CTM->AddSceneObject(pObj);
		}
	}
}
#pragma endregion