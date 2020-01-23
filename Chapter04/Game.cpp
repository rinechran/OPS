#include "Game.h"
#include "SDL/SDL_image.h"

Game::Game()
	: mIsRunning(true)
	, mWindow(nullptr)
	, mRenderer(nullptr)
	, mTicksCount(0) {

}

bool Game::Initalize() {
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO)) {
		SDL_Log("Failed to sdl initalize %s", SDL_GetError());
		return false;
	}
	mWindow = SDL_CreateWindow("AI", 100, 100, 1024, 768, 0);
	if (!mWindow) {
		SDL_Log("Failed to sdl initalize %s", SDL_GetError());
		return false;
	}

	mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (!mRenderer)
	{
		SDL_Log("Failed to create renderer: %s", SDL_GetError());
		return false;
	}

	if (!IMG_Init(IMG_INIT_PNG))
	{
		SDL_Log("Unable to initialize SDL_image: %s", SDL_GetError());
		return false;
	}

	mTicksCount = SDL_GetTicks();

	return true;

}

void Game::RunLoop() {
	while (mIsRunning) {
		ProcessInput();
		UpdateGame();
		GenerateOutput();
	}
}

void Game::Shutdown() {

}

void Game::ProcessInput() {

}

void Game::UpdateGame() {
	while (SDL_GetTicks() < mTicksCount + 16) {
	}

	float deltaTime = (SDL_GetTicks() - mTicksCount) / 1000.0f;
	
	if (deltaTime > 0.05f)
	{
		deltaTime = 0.05f;
	}
	mTicksCount = SDL_GetTicks();



}

void Game::GenerateOutput() {

}
