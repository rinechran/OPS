#include "Game.h"
#include "Actor.h"
#include "SDL/SDL_image.h"
#include "Random.h"
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
	if (IMG_Init(IMG_INIT_PNG) == 0) {
		SDL_Log("Failed to initalize IMG : %s", SDL_GetError());
		return false;
	}

	Random::Init();


	LoadData();


	mTicksCount = SDL_GetTicks();
	
	return true;
}

void Game::Shutdown()
{
	IMG_Quit();
	SDL_DestroyRenderer(mRenderer);
	SDL_DestroyWindow(mWindow);
	SDL_Quit();
}

void Game::Run()
{
	while (mIsRunning) {
		ProcessInput();
		Update();
		GenerateOutput();
	}
}

void Game::GenerateOutput()
{
	SDL_SetRenderDrawColor(mRenderer, 220, 220, 220, 255);

	SDL_RenderClear(mRenderer);


	SDL_RenderPresent(mRenderer);
}

void Game::AddActor(Actor* actor) {
	if (mUpdateActors) {
		mPendingActors.emplace_back(actor);
	}
	else {
		mActors.emplace_back(actor);
	}
}

void Game::RemoveActor(Actor* actor)
{
	auto iter = std::find(mPendingActors.begin(), mPendingActors.end(), actor);
	if (iter != mPendingActors.end())
	{
		std::iter_swap(iter, mPendingActors.end() - 1);
		mPendingActors.pop_back();
	}

	iter = std::find(mActors.begin(), mActors.end(), actor);
	if (iter != mActors.end())
	{
		std::iter_swap(iter, mActors.end() - 1);
		mActors.pop_back();
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

	mUpdateActors = true;
	for (auto actor : mActors) {
		actor->Update(deltaTime);
	}
	mUpdateActors = false;

	for (auto mPendActor : mPendingActors) {
		mActors.emplace_back(mPendActor);
	}
	mPendingActors.clear();

	std::vector<Actor*> deadActor;

	for (auto actor : mActors) {
		if (actor->GetState() == Actor::eState::Dead) {
			deadActor.emplace_back(actor);
		}
	}

	for (auto deadActor : deadActor) {
		delete deadActor;
	}



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
	for (auto actor : mActors) {
		actor->ProcessInput(keyState);
	}

	mUpdateActors = false;

}

void Game::LoadData()
{
}
