#pragma region system include
#include <string>
#pragma endregion

#pragma region project include
#include "World.h"
#include "Config.h"
#include "Macro.h"
#include "Engine.h"
#include "ContentManagement.h"
#include "Player.h"
#include "MoveEnemy.h"
#include "Boss.h"
#include "Animation.h"
#include "NPC.h"
#include "Item.h"
#pragma endregion

#pragma region using
using namespace std;
#pragma endregion

#pragma region public function

// initlialize world
void GWorld::Init()
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

#pragma region Level01
	if (m_level == 1)
	{
		world += "T0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000GSSSS\n";
		world += "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000GSSSS\n";
		world += "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000GSSSS\n";
		world += "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000GSSSS\n";
		world += "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000GSSSS\n";
		world += "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000GSSSS\n";
		world += "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000GSSSS\n";
		world += "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000B000000B0000000000000000000000000000000000000000000000000000GSSSSS\n";
		world += "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000GGGGGG00000000000000000000000000000000000000000000000000000GSSSSS\n";
		world += "00000000000000000000000P0000000000000000000000000000000000000V000000000000000000000000000000000000000000000000000000000000000000000000000000000000000GSSSS\n";
		world += "0000000000000000000000000000000000000000000000000000DDDDGGGGGGGGGGGGGGGGGG0000000000000000000000000000000000000000000000000000000NNNNNNNNNN0000000GGSSSSSS\n";
		world += "000000000000000000000000000000000000000000000000000DDDDDDDDDDDDDDDDDDDDDDDD00000000000000000000000000000000000000000000000000000N0000000000N000GGGSSSSSSSS\n";
		world += "00000000000000000000000000000000000000000000000000DDDDDDDSSSSSSSSSSSSSSSSDDD0000000000000000000000000000000000000000000000GGGGGGGWWWWWWWWWWGGGGSSSSSSSSSSS\n";
		world += "0000000000000000000000000000000000000000000000000DDDDDSSSSSSSSSSSSSSSSSSSSDDG0000000000000000000000000000000GGGGGGGG000000GSSSSSDWWWWWWWWWWDSSSSSSSSSSSSSS\n";
		world += "000000000000000000000000000000000000000000000000DDDDDSSSSSSSSSSSSSSSSSSSSSSSDDGGG000000GGGGGGGGGGG000000E000GDDDDDDD000000DSSSSSDDWWWWWWWWDSSSSSSSSSSSSSSS\n";
		world += "DDDDDDDGGGGGGGGGGGGG0000000000000000000GGGGGGGGGGGDDDSSSSSSSSSSSSSSSSSSSSSSSSSDDDDGGGGGGDDDDDDDDDDDGG0000000GDDDDDDDD00000SSSSSSSDWWWWWWWWDSSSSSSSSSSSSSSS\n";
		world += "SSSSSDDDDDDDDDDDDDDDGGGGG000000000000GGDDDDDDDDDDDDDSSSSSSSSSSSSS00000000SSSSSSSSDDDDDDDDDSSSSSSSSDDDGGGGGGGDDSSSSSDDDDSSSSSSSSSSSWWWWWWWWSSSSSSSSSSSSSSSS\n";
		world += "SSSSSSSSSSSSSSSSSSDDDDDDDGGGGGGGG0000GDDDDDDDDDDDDDSSSSSSSS0000000000000000000SSSSSSSSSSSSS00000SSSSSSSDDDDDDSSSSSSSSSSSSSSSSSSSSSWWWWWWWWSSSSSSSSSSSSSSSS\n";
		world += "SSSSSSSSSSSSSSSSSSSSSSSSDDDDDDDDDDDDDDSSSSSSSSSSSSS00000000000000000000000000000SS0000000000000000000000SSSSS000000000000SSSSSSSSSWWWWWWWWSSSSSSSSSSSSSSSS\n";
		world += "SSSSSSSSSSSSSSSSSSSSSSSSSSSDDSSSSD0000D000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000NWWWWWWWWSSSSSSSSSSSSSSSS\n";
		world += "SSSSSSSSSSSSSSSSSSSSSSSSSSSSDSSSSSD000D0000000000000000000000000000000000000000000000000B00000000000B0000000000000000000000000000NWWWWWWWWSSSSSSSSSSSSSSSS\n";
		world += "SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSDDDDDDDDDDDDDDDDDDD00000000000000000000000000000000000SSSSSSSSSSS00000000000000000000000000000NWWWWWWWWSSSSSSSSSSSSSSSS\n";
		world += "SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSDDDDDD00000000000000000000000000000SSSSSSSSSSSNNNNNNNNNNNNNN00000DDDDDDDDDDDWWWWWWWWSSSSSSSSSSSSSSSS\n";
		world += "SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSD0000000000SSSS000000000000000SSSSSSSSSSSWWWWWWWWWWWWWWDDDDDDDSSSSDDDSSWWWWWWWWSSSSSSSSSSSSSSSS\n";
		world += "SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSDDD0000000SSSSSSS0000000SS000SSSSSSSSSSSWWWSSSSWWWWWWWSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS\n";
		world += "SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSDDSS000SSSSSSSSS00000SS000SSSSSSSSSSSWWWSSSSWWWWWWWSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS\n";
		world += "SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS\n";
		world += "SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS\n";
		world += "SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS\n";
		world += "SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS";
	}
#pragma endregion Level01

#pragma region Level02
	if (m_level == 2)
	{
		world += "L000000000000SSS000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000\n";
		world += "0000000000000SS0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000\n";
		world += "0000000000000S00000000000000000000000000000000SSSSSSSS0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000\n";
		world += "0000000000000S000000000000000000SSSS0000000000S000000S0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000\n";
		world += "0000000000000S0000000000000000000SS00000000000S000000S0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000\n";
		world += "000000000000S0000000SSSSS000000000000000000000S0000000SSS00000000000000000GGGGGG000000000000GGGGGG00000000000000000000000000000000000000000000000000000000\n";
		world += "000000000000S00000000SSS0000000000000000000000S000000000S00000000000000000G0000S000000000000D0000S00000000000000000000000000000000000000000000000000000000\n";
		world += "000000000000S000000000000000000000000000000000S0000000000SS000000000000000G0000S00000000000DD0000S0000000000000000000000000000000000GG000000P0000000000000\n";
		world += "000000000000S000000000000000000SSSSS00000000000S0000000000S000000000000GGG00000S00000000000SS0000SGGGGG00000000000000GGGGG0000000GGGDS00000000000000000000\n";
		world += "000000000000S00000000000000000000SS000000000000S00000000000S0000000GGGG00000000S0000000000SS0000000000S00000000000GGG0000D0000000DDDDS0000GGGGGGGGGGGGGGGG\n";
		world += "000000000000S00000000000000000000000000000SSSSSS000000000000GGGGGGG00000000000S00000000000SS0000000000S000000GGGGG0000000D0000000SDSSSGGGGDDDDDDDDDDDDDDDD\n";
		world += "0000000000000SSS00000000000000000000000000000SSSS00000000000000000000000000000S0000000000SSS0000000000S000000S00000000000S0000000SDD0DDDDDDDSSSSSSSDDDDSSS\n";
		world += "0000000000000000S0000000000000000000000000000000S00000000000000000000000000000S0000000000SSS00000000000SSSSS0S0000000000SSS000000S000000000000000000000000\n";
		world += "0000000000000000S000000000000000000SS000000000000S0000000000000000000000000000S00000000SSSSS0000000000000000SS0000000000SS000000SSS00000000000000000000000\n";
		world += "0000000000000000S00000000000000000000000000000000S00000000000000000000000000000SSS0000000SSS0000000000000000000000000000S000000000S00000000000000000000000\n";
		world += "00000000000000000S0000000000000000000000000000000S000000000000000000000000000000SS0000000000SSS0000000000000000000000000SS000000000SS000000000000000000000\n";
		world += "00000000000000000S0000000000000000000000000SSS000SSS0000000000000000000000000000SS0000000000000SS00000000000000000000000SSSS000000000SSSS00000000000000000\n";
		world += "000000000000000000SSS00000000000000000000000S0000000SSSSS000000000000000000000000SSS0000000000000SSSSSSS00000000000000000S000000000000000SSSSSS00000000000\n";
		world += "000000000000000000000SSS000000000000000000000000000000000SSSSSSS0000SSSSSS00000000SS00000000000000000000SSSSS000000000000S000000000V00000000000S0000000000\n";
		world += "000000000000000000000000SSSS000000000SSS000000000000000000000000SSSS000000SSSSSSS00SSS00000000000000000000000SSSSSS00000S0000000000S000000000000S000000000\n";
		world += "0000000000000000000000000000SSSSSSSSSSS0000000SSSS0000000000000000000000000000000SSSSS00000000000000000000000000000SSSSS0000000000SS000000000000S000000000\n";
		world += "0000000000000000000000000000000000000SSSSSSSSS0000SSSS000000000000000000000000000000SSSSSSSSS0000000000000000000000000000000000000SSS00000000000S000000000\n";
		world += "000000000000000000000000000000000000000000000000000000SSSSSS000000000000000000000000S0000000S000000SSS000000000000000000000000000SSSS00000000000S000000000\n";
		world += "000000000000000000000000000000000000000000000000000000000000SSSSSSSSSS00000000000000S0000000S000000SSSSSSSSSSSS00000000000000000SSSSSS000000000S0000000000\n";
		world += "0000000000000000000000000000000000000000000000000000000000000000000000SSSSSSSSWWWWSSS0000000SFFFFFFSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS00000000000";
	}
#pragma endregion Level02

#pragma region Level03
	if (m_level == 3)
	{
		world += "00000000000000000SNNPNNS0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000\n";
		world += "00000000000000000SWWWWWS0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000\n";
		world += "00000000000000000SWWWWWS0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000\n";
		world += "00000000000000000SWWWWWS0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000\n";
		world += "000SS000000000000SWWWWWN0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000\n";
		world += "00S00SSSSS0000000SWWWWWN000000000000000000000000000000000000000000000000000SSSS000000000000000000000000000000000000000000000000000000000000000000000000000\n";
		world += "00S0000000SSSSS00SWWWWWN000000000000000000000000000000000000000000000000000SS00000000SSSS00000000000000000000000000000000000000000000000000000000000000000\n";
		world += "00S000000000000SSSWWWWWSSSSS00000000000000000000000000000000000000000000SSSS0000000000SS000000SSS000000000000000000000000000000000000000000000000000000000\n";
		world += "00S00000000000000NWWWWWSS000000000000000000000000000000000SSS0000000000000000000000000000000000S0000000000000000000000000000000000000000000000000000000000\n";
		world += "000S0000000000000NWWWWWS00000000000000000000000000SSSS000000000000SS0000000000000000000000000000000SSSSSS0000000000000000000000000000000000000000000000000\n";
		world += "000S0000000000000NWWWWWN000000000000000000000000000000000000000000000000000000000000000000000000000S000000000000000000000000000000000000000000000000000000\n";
		world += "000S00000000000SSSWWWWWNN000000000000SSSSSSSS000000000000000000000000000000000000000000000000000000S000000000000000000000000000000000000000000000000000000\n";
		world += "0000SS00000SSSS000SSWWW00N0000SSSSSSS000000000000000000000000000000000000000000000SSSS00000000000SS0000000000000000000000000000000000000000000000000000000\n";
		world += "00000S00000000000NWWSSWWWSSSSS00000000000000000000000000000000000000000000000000000SS00000000SSSS000000000000000000000000000000000000000000000000000000000\n";
		world += "00000SSS000000000NWWWWSSS000000000000000000000000000SSSSSS00000000000000000SSSS000000000000000000000000000000000000000000000000000000000000000000000000000\n";
		world += "0000000S000000000NWWWWWN0000000000000000000000000000S000000000SSSSSS00000000SS0000000000000000000000000000000000000000000000000000000000000000000000000000\n";
		world += "0000000S000000000NWWWWWN0000SSSSS0000SSSSS0000000SSS000000000000SSS000000000000000000000000000000000000000000000000000000000000000000000000000000000000000\n";
		world += "00000000S00000000NWWWWWSSSSS00000SSSS00000SSSSSSS000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000\n";
		world += "00000000S00000000NWWWWWN0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000\n";
		world += "000000000SS000000NWWWWWN0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000\n";
		world += "00000000000SS0000NWWWWWSSSS0000SSS0000000SSS00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000\n";
		world += "0000000000000SSSSSWWWWWN000SSSS000SSSSSSS000SSSS0000000000000000000000000000000000000000SSS000000000000000000000000000000000000000000000000000000000000000\n";
		world += "00000000000000000NWWWWWN000000000000000000000000SSSSSS000000000000000SSSS000000000000000SSS000000000000000000000000000000000000000000000000000000000000000\n";
		world += "00000000000000000NWWWWWN000000000000000000000000000000SSSSSSSSSS00000SSSS0000000SSSSS000SSS000000000000000000000000000000000000000000000000000000000000000\n";
		world += "00000000000000000NWWWWWN0000000000000000000000000000000000000000FFFFFSSSSFFFFFFFSSSSSFFFSSS000000000000000000000000000000000000000000000000000000000000000";
	}
#pragma endregion Level03

#pragma region Level04
	if (m_level == 4)
	{
		world += "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000\n";
		world += "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000\n";
		world += "00000000S0000000000000S00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000\n";
		world += "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000\n";
		world += "000000000000000000000000S000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000\n";
		world += "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000\n";
		world += "0000000S00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000\n";
		world += "0000000000000000000000000S00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000\n";
		world += "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000\n";
		world += "0000000000S00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000\n";
		world += "0000000000000000000000S00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000\n";
		world += "00000000S0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000\n";
		world += "00000000000000000000000000000000000000000000000000000000000000000000000SS000000000000000000000000000000SSSSSS000000000000000000000000000000000000000000000\n";
		world += "00000000000000000000000000000000000000000000000000000000000000000000000SS000000000000000000000000000000SSSSSS000000000000000000000000000000000000000000000\n";
		world += "0000000000000000000000000S0000000000000000000000000000000000000000000SSSS000000000000000000000000000000SSSSSS000000000000000000000000000000000000000000000\n";
		world += "000000000S00000000000000000000000000000000000000000000000000000000000SSSS000000000000000000000000000000SSSSSS000000000000000000000000000000000000000000000\n";
		world += "0000000000000000000000000000000000000000000000000000000000000000000SSSSSS000000000000000000000000000000SSSSSS000000000000000000000000000000000000000000000\n";
		world += "000000000000000P00000S000000000000000000000000000000000000000000000SSSSSS000000000000000000000000000000SSSSSS000000000000000000000000000000000000000000000\n";
		world += "00000000000000000000000000000000000000000000000000000000000000000SSSSSSSS00000000SSSS000000000SSS000000SSSSSS000000000000000000000000000000000000000000000\n";
		world += "0000000S000000000000000000000000000000000000000000000000000000000SSSSSSSS000000000000000000000000000000SSSSSS000000000000000000000000000000000000000000000\n";
		world += "000000000000000000000000000000000000000000000000SSSSSS0000SS000SSSSSSSSSSS0000000000000K00000000000000SSSSSSS000000000000000000000000000000000000000000000\n";
		world += "0000000000000000000000000000SSSSS00000SSSSSS0000S0000S0000SS000S00000000SS0000000000000000000000000000SSSSSSS000000000000000000000000000000000000000000000\n";
		world += "SSSSSSSSSSSSSSSSSSSSSSSSSSSS0000S00000S0000S0000S0000S0000SS000S00000000SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS000000000000000000000000000000000000000000000\n";
		world += "00000000000000000000000000000000S00000S0000S0000S0000S0000SS000S0000000000000000000000000000000000000000SSSSS000000000000000000000000000000000000000000000\n";
		world += "00000000000000000000000000000000SFFFFFS0000SFFFFS0000SFFFFSSFFFS00000000000000000000000000000000000000000SSSSS00000000000000000000000000000000000000000004";
	}
#pragma endregion Level04

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
			pObj->SetColType(ECollisionType::COL);
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
			CTexturedObject* pWorld01 = new CTexturedObject("Texture/World/level1.png",
				SVector2(0, 36), SVector2(7392, 1440));
			CTM->AddPersistantObject(pWorld01);
		}

		// if L
		if (world[i] == 'L')
		{
			// load texture
			CTexturedObject* pWorld01 = new CTexturedObject("Texture/World/level2.png",
				SVector2(0, 0), SVector2(7392, 1200));
			CTM->AddPersistantObject(pWorld01);
		}

		// if 4
		if (world[i] == '4')
		{
			// load texture
			CTexturedObject* pWorld01 = new CTexturedObject("Texture/World/level4.png",
				SVector2(0, 48), SVector2(7392, 1200));
			CTM->AddPersistantObject(pWorld01);
		}

		// if player
		else if (world[i] == 'P')
		{
			// load player, initialize and add to ctm
			GPlayer* pPlayer = new GPlayer("Texture/Player/T_Jurgo.png",
				SVector2(width * BLOCK_WIDTH, (height - 1) * BLOCK_HEIGHT), SVector2(64, 64));
			pPlayer->m_animation.SetAnimationRect(SRect(202, 225, 0, 225));
			pPlayer->m_animation.SetAnimationObject(pPlayer);
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
			pEnemy->m_EnemyAnimation.SetAnimationRect(SRect(127, 127, 0, 0));
			pEnemy->m_EnemyAnimation.SetAnimationObject(pEnemy);
			pEnemy->Init();
			CTM->AddPersistantObject(pEnemy);
		}

		// if Boss
		else if (world[i] == 'K')
		{
			// load Boss, initialize and add to ctm
			GBoss* pBoss = new GBoss("Texture/Enemy/T_King.png",
				SVector2(width * BLOCK_WIDTH, (height - 4.5) * BLOCK_HEIGHT), SVector2(BOSS_WIDTH, BOSS_HEIGHT));
			pBoss->m_BossAnimation.SetAnimationRect(SRect(297, 382, 0, 0));
			pBoss->m_BossAnimation.SetAnimationObject(pBoss);
			pBoss->Init();
			CTM->AddPersistantObject(pBoss);
		}

		// if NPC 1
		else if (world[i] == '1')
		{
			// load NPC and add to ctm
			GNPC* pNpc = new GNPC("Texture/NPC/T_Npc.png",
				SVector2(width * BLOCK_WIDTH, (height - 1.5f) * BLOCK_HEIGHT), SVector2(55, 64));
			pNpc->SetTag("NPC");
			pNpc->SetColType(COL);
			pNpc->m_NPC.SetAnimationRect(SRect(154, 245, 0, 0));
			pNpc->m_NPC.SetAnimationObject(pNpc);
			CTM->AddPersistantObject(pNpc);
		}
		// if Z (goal)
		else if (world[i] == 'Z')
		{
			// load goal and add to ctm
			CTexturedObject* pGoal = new GNPC("Texture/Enemy/T_Panda.png",
				SVector2(width * BLOCK_WIDTH, (height - 1) * BLOCK_HEIGHT), SVector2(MOVE_ENEMY_WIDTH, MOVE_ENEMY_HEIGHT));
			pGoal->SetTag("Goal");
			pGoal->SetColType(COL);
			CTM->AddPersistantObject(pGoal);
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