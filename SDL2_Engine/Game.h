#pragma once

#pragma region forward decleration
class CFont;
#pragma endregion

#pragma region macro
#define GAME GGame::Get()
#pragma endregion

/// <summary>
/// game state enum
/// </summary>
enum EGameState
{
	MENU,
	MAIN,
	GAMEOVER,
	WIN,
	WINMENU,
	CREDIT,
	CREDITSCENE,
	DEAD,
	DEATHSCENE,
	BOSSLEVEL,
	BOSSSCENE
};

/// <summary>
/// core game class
/// </summary>
class GGame
{
public:
#pragma region constructor
	/// <summary>
	/// constructor
	/// </summary>
	GGame() {}
#pragma endregion

#pragma region destructor
	/// <summary>
	/// destructor
	/// </summary>
	~GGame() {}
#pragma endregion

#pragma region public variable
	/// <summary>
	/// garamond font
	/// </summary>
	CFont* m_PGaramond;
#pragma endregion

#pragma region public inline function
	/// <summary>
	/// get game
	/// </summary>
	/// <returns>game reference</returns>
	inline static GGame* Get()
	{
		// create game if not exists
		static GGame* pGame = new GGame();

		// return game
		return pGame;
	}
#pragma endregion

#pragma region public function
	/// <summary>
	/// initialize game
	/// </summary>
	void Init();

	/// <summary>
	/// update every frame
	/// </summary>
	/// <param name="_deltaSeconds">time since last frame</param>
	void Update(float _deltaSeconds);

	/// <summary>
	/// if player dies
	/// </summary>
	void GameOver();

	/// <summary>
	/// if player wins
	/// </summary>
	void Win();

	/// <summary>
	/// if player goes to Boss Level
	/// </summary>
	void BossLevel();
#pragma endregion

private:
#pragma region private variable
	/// <summary>
	/// current game state
	/// </summary>
	EGameState m_state;
#pragma endregion
};