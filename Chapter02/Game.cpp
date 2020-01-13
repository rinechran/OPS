#include "Game.h"
#include "SDL/SDL_image.h"
#include "Actor.h"
#include "Ship.h"
#include "SpriteComponent.h"


Game::Game() {
	mWindows = nullptr;
	mRenderer = nullptr;

}
void Game::AddActor(Actor* actor) {
	mActors.emplace_back(actor);
}
SDL_Texture* Game::GetTexture(const std::string& fileName) {
	SDL_Texture* tex = nullptr;

	auto iter = mTextures.find(fileName);

	if (iter != mTextures.end()) {
		tex = iter->second;
	}
	else {
		SDL_Surface* surf = IMG_Load(fileName.c_str());
		if (!surf) {
			SDL_Log("Failed to load texture file %s", SDL_GetError());
			return nullptr;
		}

		tex = SDL_CreateTextureFromSurface(mRenderer, surf);
		SDL_FreeSurface(surf);
		if (!tex) {
			SDL_Log("Failed to convert surface to texture for %s", SDL_GetError());
			return nullptr;
		}
		mTextures.emplace(fileName.c_str(), tex);
	}

	return tex;

}

void Game::AddSprite(SpriteComponent* sprite)
{
	int myDrawOrder = sprite->GetDrawOrder();
	auto iter = mSprites.begin();
	for (;
		iter != mSprites.end();
		++iter) {
		
		if (myDrawOrder < (*iter)->GetDrawOrder()) {
			break;
		}

	}

	mSprites.insert(iter, sprite);
}

void Game::RemoveSprite(SpriteComponent* sprite)
{
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


}

void Game::GenerateGraph() {
	SDL_SetRenderDrawColor(mRenderer, 0, 0, 0, 255);
	SDL_RenderClear(mRenderer);

	for (auto sprite : mSprites) {
		sprite->Draw(mRenderer);
	}
	SDL_RenderPresent(mRenderer);

}
void Game::loadData() {
	
	mShip = new Ship(this);
	mShip->SetPosition(Vector2(100.f, 350.0f));
	mShip->SetScale(1.0f);

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
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			mIsRunning = false;
			break;
		default:
			break;
		}
	}
	const Uint8* status = SDL_GetKeyboardState(nullptr);
	if (status[SDL_SCANCODE_ESCAPE]) {
		mIsRunning = false;
	}
	mShip->ProcessKeyBoard(status);

}

void Game::Update()
{
	while ((mTickCount + 16 )- SDL_GetTicks() <=0 ) {}
	float deltaTime = (SDL_GetTicks() - mTickCount)/1000.f;

	if (deltaTime > 0.05f) {
		deltaTime = 0.5;
	}


	mTickCount = SDL_GetTicks();

	// Update all acotr
	mUpdatingActors = true;
	for (auto actor : mActors) {
		actor->Update(deltaTime);
	}
	mUpdatingActors = false;

	for (auto pending : mPendingActors) {
		mActors.emplace_back(pending);
	}
	mPendingActors.clear();


	for (auto actor : mActors) {
		if (actor->GetState() == Actor::eState::Dead) {
			mDeadActors.emplace_back(actor);
		}
	}
	for (auto actor : mDeadActors) {
		delete actor;
	}
	mDeadActors.clear();


}
