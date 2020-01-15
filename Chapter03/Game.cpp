#include "Game.h"

Game::Game()
	: mWindow(nullptr)
	, mRenderer(nullptr)
	, mIsRunning(true)
	, mTicksCount(0)
	, mUpdateActors(false)
{
}

bool Game::Initialize()
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) !=0)
	{
		SDL_Log("Failed Initalize SDL : %s", SDL_GetError());
		return false;
	}

	mWindow = SDL_CreateWindow("Game Programing in C++", 100, 100, 1024, 768, 0);
	if (!mWindow)
	{
		SDL_Log("Failed to create Window : %s", SDL_GetError());
		return false;
	}

	mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (!mRenderer) {
		SDL_Log("Failed to create render : %s", SDL_GetError());
		return false;
	}
	LoadData();


	mTicksCount = SDL_GetTicks();
	
	return true;
}

void Game::Shutdown()
{
}

void Game::Run()
{
	while (mIsRunning) {
		Update();
	}
}

void Game::Update()
{
	while ((mTicksCount + 16) - SDL_GetTicks() > 0) {
		;
	}
	float deltaTime = (SDL_GetTicks() - mTicksCount) / 1000;

	if (deltaTime > 0.5f) {
		deltaTime = 0.5;
	}

	mTicksCount = SDL_GetTicks();
}

void Game::ProcessInput()
{
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type)
		{
		case SDL_QUIT:
			mIsRunning = false;
			break;
		default:
			break;
		}
	}

	const std::uint8_t * keyState = SDL_GetKeyboardState(nullptr);

	mUpdateActors = true;
	/*
	*/
	mUpdateActors = false;

}

void Game::LoadData()
{
}
