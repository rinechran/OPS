#include "Game.h"
#include "Actor.h"
#include "SDL/SDL_image.h"
#include "Grid.h"
#include "SpriteComponent.h"
#include "Bullet.h"
#include "Enemy.h"

Game::Game()
	: mIsRunning(true)
	, mWindow(nullptr)
	, mRenderer(nullptr)
	, mTicksCount(0)
	, mGrid(nullptr) {

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

	LoadData();
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

	UnLoadData();
	IMG_Quit();
	SDL_DestroyRenderer(mRenderer);
	SDL_DestroyWindow(mWindow);
	SDL_Quit();
}

void Game::AddActor(Actor* actor) {
	if (mUpdateActor) {
		mPendingActors.emplace_back(actor);
	}
	else {
		mActors.emplace_back(actor);
	}
}

void Game::RemoveActor(Actor* actor)
{
	auto iter = std::find(mPendingActors.begin(), mPendingActors.end(), actor);
	if (iter != mPendingActors.end()) {
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

void Game::AddSprite(SpriteComponent* sprite)
{
	int myDrawOrder = sprite->GetDrawOrder();
	auto iter = mSprites.begin();
	for (;
		iter != mSprites.end();
		++iter)
	{
		if (myDrawOrder < (*iter)->GetDrawOrder())
		{
			break;
		}
	}

	mSprites.insert(iter, sprite);
}

void Game::RemoveSprite(SpriteComponent* sprite)
{
	auto iter = std::find(mSprites.begin(), mSprites.end(), sprite);
	mSprites.erase(iter);
}

SDL_Texture* Game::GetTexture(const std::string& fileName)
{
	SDL_Texture* tex = nullptr;
	auto iter = mTextures.find(fileName);
	if (iter != mTextures.end()) {
		tex = iter->second;
	}
	else {
		SDL_Surface* surf = IMG_Load(fileName.c_str());
		if (!surf) {
			SDL_Log("Faild to load texture file %s", fileName.c_str());
			return nullptr;
		}
		tex = SDL_CreateTextureFromSurface(mRenderer, surf);
		SDL_FreeSurface(surf);
		if (!tex) {
			SDL_Log("Failed to convert surface to texture for  %s", fileName.c_str());
			return nullptr;
		}
		mTextures.emplace(fileName.c_str(), tex);

	}
	return tex;
}

Enemy* Game::GetNearestEnemy(const Vector2& pos)
{
	Enemy* best = nullptr;

	if (mEnemies.size() > 0)
	{
		best = mEnemies[0];
		// Save the distance squared of first enemy, and test if others are closer
		float bestDistSq = (pos - mEnemies[0]->GetPosition()).LengthSq();
		for (size_t i = 1; i < mEnemies.size(); i++)
		{
			float newDistSq = (pos - mEnemies[i]->GetPosition()).LengthSq();
			if (newDistSq < bestDistSq)
			{
				bestDistSq = newDistSq;
				best = mEnemies[i];
			}
		}
	}

	return best;
}


std::vector<Enemy*>& Game::GetEnemies() { return mEnemies; }

void Game::ProcessInput() {

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
	const std::uint8_t* keyState = SDL_GetKeyboardState(NULL);
	if (keyState[SDL_SCANCODE_ESCAPE])
	{
		mIsRunning = false;
	}
	if (keyState[SDL_SCANCODE_A]) {
		mGrid->BuildTower();
	}

	int x, y;
	Uint32 buttons = SDL_GetMouseState(&x, &y);
	if (SDL_BUTTON(buttons) & SDL_BUTTON_LEFT) {
		mGrid->ProcessClick(x, y);
	}


	mUpdateActor = true;
	for (auto actor : mActors)
	{
		actor->ProcessInput(keyState);
	}
	mUpdateActor = false;


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

	mUpdateActor = true;
	for (auto actor : mActors) {
		actor->Update(deltaTime);
	}
	mUpdateActor = false;

	for (auto pending : mPendingActors) {
		mActors.emplace_back(pending);
	}
	mPendingActors.clear();

	std::vector<Actor*> deadActor;
	for (auto actor : mActors) {
		if (actor->GetState() == Actor::eState::Dead) {
			deadActor.emplace_back(actor);
		}
	}

	for (auto actor : deadActor) {
		delete actor;
	}

}

void Game::GenerateOutput() {
	SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, 255);
	SDL_RenderClear(mRenderer);

	for (auto sprite : mSprites) {
		sprite->Draw(mRenderer);
	}
	SDL_RenderPresent(mRenderer);

}

void Game::LoadData()
{
	mGrid = new Grid(this);
}

void Game::UnLoadData()
{
	while (!mActors.empty()) {
		delete mActors.back();
	}
	for (auto i : mTextures)
	{
		SDL_DestroyTexture(i.second);
	}
	mTextures.clear();

}
