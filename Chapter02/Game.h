// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
// 
// Released under the BSD License
// See LICENSE in root directory for full details.

#pragma once
#include "SDL/SDL.h"
#include <iostream>
class Game
{
public:
	Game();
	bool Initialize();
	void Run();
	void Shutdown();
private:
	void Input();
	void Update();
	void GenerateGraph();
	void loadData();
	SDL_Window* mWindows;
	SDL_Renderer* mRenderer;
	std::uint32_t mTickCount;
	bool mIsRunning;

};
