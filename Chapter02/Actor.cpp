#include "Actor.h"
#include "Game.h"
#include "Component.h"
#include <algorithm>

Actor::Actor(Game * game)
	: mState(Actor::eState::Active)
	, mGame(game)
{
	mGame->AddActor(this);
}
Actor::~Actor() {

}

void Actor::AddComponent(Component* component)
{

}

void Actor::RemoveComponent(Component* component)
{
	auto iter = std::find(mComponents.begin(), mComponents.end(), component);
	if (iter != mComponents.end()) {
		mComponents.erase(iter);
	}
}

void Actor::UpdateComponents(float deltaTime)
{
}

