// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
// 
// Released under the BSD License
// See LICENSE in root directory for full details.

#pragma once
#include "SDL/SDL.h"
#include "Ship.h"
#include <vector>
#include <iostream>
#include <unordered_map>
class Game
{
public:
	Game();
	bool Initialize();
	void Run();
	void Shutdown();

	void AddActor(class Actor* actor);
private:
	void Input();
	void Update();
	void GenerateGraph();
	void loadData();
	SDL_Window* mWindows;
	SDL_Renderer* mRenderer;
	std::uint32_t mTickCount;

	bool mIsRunning;

	bool mUpdatingActors;

	// Actor
	std::vector<class Actor*> mActors;
	// Pending actor
	std::vector<class Actor*> mPendingActors;


	std::unordered_map<std::string, SDL_Texture*> mTextures;

	class Ship* mShip;

};
