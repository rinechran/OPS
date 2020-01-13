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

	int myOrder = component->GetUpdateOrder();
	auto iter = mComponents.begin();
	for (; 
		iter!= mComponents.end();
		++iter
		)
	{
		if (myOrder < (*iter)->GetUpdateOrder()) {
			break;
		}
		
	}

	mComponents.insert(iter, component);
}

void Actor::RemoveComponent(Component* component)
{
	auto iter = std::find(mComponents.begin(), mComponents.end(), component);
	if (iter != mComponents.end())
	{
		mComponents.erase(iter);
	}
}

void Actor::Update(float deltaTime)
{
	if (mState == Actor::eState::Active)
	{
		UpdateComponents(deltaTime);
		UpdateActor(deltaTime);
	}
}

void Actor::UpdateActor(float deltaTime){}



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
	for (auto comp : mComponents) {
		comp->Update(deltaTime);
	}
}

