#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include "SDL/SDL.h"


class Actor;
class SpriteComponent;
class Grid;
class Game
{
public:
	Game();
	bool Initalize();
	void RunLoop();
	void Shutdown();


	void AddActor(Actor* actor);
	void RemoveActor(Actor* actor);

	void AddSprite(SpriteComponent* sprite);
	void RemoveSprite(SpriteComponent* sprite);

	SDL_Texture* GetTexture(const std::string& fileName);


private:
	void ProcessInput();
	void UpdateGame();
	void GenerateOutput();

	void LoadData();
	void UnLoadData();


	bool mIsRunning;
	Uint32 mTicksCount;
	SDL_Window* mWindow;
	SDL_Renderer* mRenderer;


	std::unordered_map<std::string, SDL_Texture*> mTextures;

	bool mUpdateActor;
	std::vector<Actor*> mActors;
	std::vector<Actor*> mPendingActors;
	std::vector<SpriteComponent*> mSprites;

	Grid* mGrid;

};

