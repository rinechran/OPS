#include <GL/glew.h>
#include <algorithm>

#include "Game.h"
#include "VertexArray.h"
#include "Shader.h"

Game::Game()
	: mWindow(nullptr)
	, mContext(nullptr)
	, mIsRunning(true)
	, mUpdatingActors(false){

}

bool Game::Initialize() {

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0) {
		SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
		return false;
	}

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);

	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);

	mWindow = SDL_CreateWindow("Game Programing in C++", 100, 100, 1024, 768, SDL_WINDOW_OPENGL);

	if (!mWindow) {
		SDL_Log("Failed to create window : %s", SDL_GetError());
		return false;
	}
	mContext = SDL_GL_CreateContext(mWindow);

	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK) {
		SDL_Log("Failed to initalize GLEW.");
		return false;
	}

	if (!LoadShaders()) {
		SDL_Log("Failed to load shaders");
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
void Game::ProcessInput() {

}

void Game::UpdateGame() {

}
void Game::Shutdown() {

}

void Game::AddActor(Actor* actor)
{
	if (mUpdatingActors) {
		mPendingActors.emplace_back(actor);
	}
	else
	{
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

bool Game::LoadShaders()
{
	mSpriteShader = new Shader();
	if (!mSpriteShader->Load("Shaders/Sprite.vert", "Shaders/Sprite.frag"))
	{
		return false;
	}
	mSpriteShader->SetActve();
	Matrix4 viewProj = Matrix4::CreateSimpleViewProj(1024.f, 768.f);
	mSpriteShader->SetMatrixUniform("uViewProj", viewProj);

	return true;
}
void Game::LoadData()
{
}
void Game::GenerateOutput() {
	glClearColor(0.86f, 0.86f, 0.86f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);


	SDL_GL_SwapWindow(mWindow);

}

void Game::CreateSpriteVerts()
{
	float vertices[] = {
		-0.5f,  0.5f, 0.f, 0.f, 0.f, // top left
		 0.5f,  0.5f, 0.f, 1.f, 0.f, // top right
		 0.5f, -0.5f, 0.f, 1.f, 1.f, // bottom right
		-0.5f, -0.5f, 0.f, 0.f, 1.f  // bottom left
	};

	unsigned int indices[] = {
		0, 1, 2,
		2, 3, 0
	};

	mSpriteVerts = new VertexArray(vertices, 4, indices, 6);

}
