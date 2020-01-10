#include "Game.h"
#include "SDL/SDL_image.h"


Game::Game() {
	mWindows = nullptr;
	mRenderer = nullptr;

}

bool Game::Initialize() {
	int initResult = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

	if (initResult != 0) {
		SDL_Log("Failed to SDL Initialize %s", SDL_GetError());
		return false;
	}
	mWindows = SDL_CreateWindow(
		"Game",
		100,
		100,
		1024,
		768,
		0
	);
	if (!mWindows) {
		SDL_Log("Failed to create Windows %s", SDL_GetError());
		return false;
	}

	mRenderer = SDL_CreateRenderer(
		mWindows,
		-1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if (!mRenderer) {
		SDL_Log("Failed to Create Render %s", SDL_GetError());
		return false;
	}
	if (!IMG_Init(IMG_INIT_PNG)) {
		SDL_Log("Failed to initalize %s", SDL_GetError());
	}
	loadData();


	mIsRunning = true;
	
	mTickCount = SDL_GetTicks();
	return true;
}
void Game::Run() {

	while (mIsRunning) {
		Input();
		Update();
		GenerateGraph();
	}
	const Uint8 * status = SDL_GetKeyboardState(nullptr);
	if (status[SDL_SCANCODE_ESCAPE]) {
		mIsRunning = false;
	}

}

void Game::GenerateGraph() {
	SDL_SetRenderDrawColor(mRenderer, 0, 0, 0, 255);
	SDL_RenderClear(mRenderer);


	SDL_RenderPresent(mRenderer);

}
void Game::loadData() {

}
void Game::Shutdown()
{
	IMG_Quit();
	SDL_DestroyRenderer(mRenderer);
	SDL_DestroyWindow(mWindows);
	SDL_Quit();
}

void Game::Input()
{
	SDL_Event event;
	while(SDL_PollEvent(&event)){
		switch (event.type) {
		case SDL_QUIT:
			mIsRunning = false;
			break;
		default:
			break;
		}
	}
}

void Game::Update()
{
	while ((mTickCount + 16 )- SDL_GetTicks() <=0 ) {}
	float deltaTime = (SDL_GetTicks() - mTickCount)/1000.f;

	if (deltaTime > 0.05f) {
		deltaTime = 0.5;
	}


	mTickCount = SDL_GetTicks();

}
