
#include "Game.h"

int main(int argc, char** argv) {

	Game game;
	bool success = game.Initialize();
	if (success)
	{
		game.Run();
	}

	game.Shutdown();
	

	return 0;
}