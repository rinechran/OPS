#pragma once
#include <algorithm>
#include "SDL/SDL.h"

class Game
{
public:

	// Function

	Game();
	bool Initialize();
	void Shutdown();
	void Run();



	// Variables

private:

	// Function
	void Update();
	void ProcessInput();

	void LoadData();
	// Variables
	SDL_Window* mWindow;
	SDL_Renderer* mRenderer;
	bool mIsRunning;

	std::uint32_t mTicksCount;

	bool mUpdateActors;


};

