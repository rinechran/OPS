#include "Actor.h"
#include "Game.h"
#include "Component.h"
#include <algorithm>

Actor::Actor(Game* game)
	: mState(Actor::eState::Active)
	, mGame(game)
	, mPosition(Vector2::Zero)
	, mScale(1.0f)
	, mRotation(0.0f)
{
	mGame->AddActor(this);
}
Actor::~Actor() {

}

Actor::eState Actor::GetState() const {
	return mState;
}

void Actor::AddComponent(Component* component)
{

}

void Actor::Update(float deltaTime)
{
}

void Actor::RemoveComponent(Component* component)
{
	auto iter = std::find(mComponents.begin(), mComponents.end(), component);
	if (iter != mComponents.end()) {
		mComponents.erase(iter);
	}
}

void Actor::SetPosition(const Vector2 pos) {
	mPosition = pos;
}

Vector2 Actor::GetPosition() {
	return mPosition;
}

float Actor::GetScale() {
	return mScale;
}

void Actor::SetScale(float scale) {
	mScale = scale;
}

void Actor::UpdateComponents(float deltaTime)
{
}

