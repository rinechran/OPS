#pragma once
#include <iostream>
#include "SDL/SDL.h"

class Shader;
class VertexArray;
class Game
{
public:
	Game();

	bool Initialize();
	void RunLoop();
	void Shutdown();

private:
	void UpdateGame();
	void ProcessInput();
	bool LoadShaders();
	void LoadData();
	void GenerateOutput();

	void CreateSpriteVerts();
	SDL_Window* mWindow;
	SDL_GLContext mContext;

	std::uint32_t mTicksCount;

	bool mIsRunning;
	VertexArray* mSpriteVerts;
	Shader* mSpriteShader;
};

