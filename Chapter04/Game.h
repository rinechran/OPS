#pragma once
#include <iostream>
#include <vector>
#include "SDL/SDL.h"


class Actor;
class Game
{
public:
	Game();
	bool Initalize();
	void RunLoop();
	void Shutdown();

private:
	void ProcessInput();
	void UpdateGame();
	void GenerateOutput();

	
	bool mIsRunning;
	std::uint32_t mTicksCount;
	SDL_Window* mWindow;
	SDL_Renderer* mRenderer;


	std::vector<Actor*> mActors;

};

