#include "Actor.h"
#include "Game.h"

Actor::Actor(Game* game)
	: mState(Actor::eState::Active)
	, mGame(game)
	, mScale(1.0f)
	, mRotation(0.0f)
	, mPosition(Vector2::Zero)

{
	
}

Actor::~Actor()
{
}

void Actor::Update(float deltaTime)
{
}

float Actor::GetScale() { return mScale; }

void Actor::SetScale(float scale) {
	mScale = scale;
}

