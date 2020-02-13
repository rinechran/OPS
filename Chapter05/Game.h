#pragma once
#include <iostream>
#include <vector>
#include "SDL/SDL.h"

class Shader;
class Actor;
class VertexArray;
class Game
{
public:
	Game();

	bool Initialize();
	void RunLoop();
	void Shutdown();

	void AddActor(Actor* actor);
	void RemoveActor(class Actor* actor);

private:
	void UpdateGame();
	void ProcessInput();
	bool LoadShaders();
	void LoadData();
	void GenerateOutput();

	void CreateSpriteVerts();

private:
	SDL_Window* mWindow;
	SDL_GLContext mContext;

	std::uint32_t mTicksCount;

	bool mIsRunning;
	VertexArray* mSpriteVerts;
	Shader* mSpriteShader;

	std::vector<Actor*> mActors;
	std::vector<Actor*> mPendingActors;

	bool mUpdatingActors;


};

