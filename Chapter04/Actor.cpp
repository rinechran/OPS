#include "Actor.h"
#include "Game.h"
#include "Component.h"

Actor::Actor(Game* game)
	: mGame(game)
	, mPosition(Vector2::Zero)
	, mScale(1.0f)
	, mRotation(0.0f)
	, mState(Actor::eState::Active)
{
	mGame->AddActor(this);
}

Actor::~Actor() {

	mGame->RemoveActor(this);
}

void Actor::Update(float deltaTime)
{
	if (mState == eState::Active) {
		UpdateComponents(deltaTime);
		UpdateActor(deltaTime);
	}
}

void Actor::UpdateActor(float deltaTime)
{
}

void Actor::UpdateComponents(float deltaTime)
{
	for (auto comp : mComponents) {
		comp->Update(deltaTime);
	}
}


void Actor::ProcessInput(const std::uint8_t * keyState)
{
	if (mState == eState::Active) {
		for (auto comp : mComponents) {
			comp->ProcessInput(keyState);
		}
		ActorInput(keyState);
	}
}

void Actor::ActorInput(const std::uint8_t * keyState)
{

}

const Vector2& Actor::GetPosition() const
{
	return mPosition;
}

void Actor::SetPosition(const Vector2& pos)
{
	mPosition = pos;
}

void Actor::AddComponent(Component* component)
{
	int myOrder = component->GetUpdateOrder();
	auto iter = mComponents.begin();
	for (;
		iter != mComponents.end();
		++iter) {

		if (myOrder < (*iter)->GetUpdateOrder()) {
			break;
		}
	}
	mComponents.insert(iter, component);
}

void Actor::RemoveComponent(Component* component)
{
	auto iter = std::find(mComponents.begin(), mComponents.end(), component);
	if (iter != mComponents.end()) {
		mComponents.erase(iter);
	}
}

Game* Actor::GetGame()
{
	return mGame;
}

Actor::eState Actor::GetState() const { return mState; }

void Actor::SetState(eState state) { mState = state; }

float Actor::GetScale() const { return mScale; }

void Actor::SetScale(float scale) {
	mScale = scale;
}

float Actor::GetRotation() const { return mRotation; }

void Actor::SetRotation(float rotation) { mRotation = rotation; }

Vector2 Actor::GetForward() const {
	return Vector2(Math::Cos(mRotation), -Math::Sin(mRotation));
}
