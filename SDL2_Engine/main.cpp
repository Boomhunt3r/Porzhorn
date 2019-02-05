#pragma region project include
#include "Engine.h"
#include "Game.h"
#pragma endregion

/// <summary>
/// application entry point
/// </summary>
/// <param name="args">number of arguments</param>
/// <param name="argv">arguments</param>
/// <returns>shut down code</returns>
int main(int args, char* argv[])
{
	// shut down result
	int result;

	// initialize engine
	if (result = ENGINE->Init() == 0)
	{
		// initialize game
		GAME->Init();

		// run engine
		ENGINE->Run();
	}

	// clean engine
	ENGINE->Clean();

	// return shut down code
	return result;
}