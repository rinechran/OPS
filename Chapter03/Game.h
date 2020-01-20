#pragma once
#include <algorithm>
#include <string>
#include <unordered_map>
#include "SDL/SDL.h"


class Ship;
class Actor;
class SpriteComponent;

class Game
{
public:

	// Function

	Game();
	bool Initialize();
	void Shutdown();
	void Run();
	void GenerateOutput();

	void AddActor(Actor* actor);
	void RemoveActor(Actor* actor);

	void AddSprite(SpriteComponent * sprite);
	void RemoveSprite(SpriteComponent* sprite);

	SDL_Texture* GetTexture(const std::string& fileName);

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

	std::vector<Actor*> mActors;
	std::vector<Actor*> mPendingActors;
	
	std::vector<SpriteComponent*> mSprites;
	std::unordered_map<std::string, SDL_Texture*> mTextures;

	Ship* mShip;
};

