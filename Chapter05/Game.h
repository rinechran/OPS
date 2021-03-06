#pragma once
#include <iostream>
#include <unordered_map>
#include <vector>
#include "SDL/SDL.h"
#include "Asteroid.h"

class Shader;
class Actor;
class VertexArray;
class SpriteComponent;
class Ship;
class Texture;
class mAsteroids;
class Game
{
public:
	Game();

	bool Initialize();
	void RunLoop();
	void Shutdown();

	void AddActor(Actor* actor);
	void RemoveActor(class Actor* actor);
	void AddSprite( SpriteComponent* sprite);
	void RemoveSprite( SpriteComponent* sprite);
	Texture* GetTexture(const std::string& fileName);
	std::vector<Asteroid*>& GetAsteroids() { return mAsteroids; }
	void AddAsteroid(Asteroid* ast);
	void RemoveAsteroid(Asteroid* ast);
	void CreateSpriteVerts();


private:
	void UpdateGame();
	void ProcessInput();
	bool LoadShaders();
	void LoadData();
	void GenerateOutput();


private:
	SDL_Window* mWindow;
	SDL_GLContext mContext;

	std::uint32_t mTicksCount;

	bool mIsRunning;
	VertexArray* mSpriteVerts;
	Shader* mSpriteShader;

	std::vector<Actor*> mActors;
	std::vector<Actor*> mPendingActors;
	std::vector<SpriteComponent*> mSprites;
	
	std::unordered_map<std::string, Texture*> mTextures;

	std::vector<Asteroid*> mAsteroids;

	bool mUpdatingActors;


	Ship* mShip;


};

