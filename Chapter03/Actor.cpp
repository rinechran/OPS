#include <algorithm>
#include "Actor.h"
#include "Game.h"
#include "Component.h"
Actor::Actor(Game* game)
	: mState(Actor::eState::Active)
	, mGame(game)
	, mScale(1.0f)
	, mRotation(0.0f)
	, mPosition(Vector2::Zero)

{
	mGame->AddActor(this);
}

Actor::~Actor()
{
	mGame->RemoveActor(this);

	// Componets ~Compoent call REmoveComponent
	while (!mComponents.empty())
	{
		delete mComponents.back();
	}
	
}

void Actor::ProcessInput(const std::uint8_t * keyStatus)
{
	if(mState == Actor::eState::Active){
		for (auto comp : mComponents) {
			comp->ProcessInput(keyStatus);
		}
		ActorInput(keyStatus);
	}
}

void Actor::ActorInput(const std::uint8_t* keyStatus)
{
}



void Actor::Update(float deltaTime)
{
	if (mState == Actor::eState::Active) {
		UpdateComponents(deltaTime);
		UpdateActor(deltaTime);
	}
}

void Actor::UpdateComponents(float deltaTime)
{
	for (auto& comp : mComponents) {
		comp->Update(deltaTime);
	}
}

void Actor::UpdateActor(float deltaTime)
{
}

const Vector2 Actor::GetPosition() const {
	return mPosition;
}

void Actor::SetPosition(const Vector2& pos) { mPosition = pos; }

float Actor::GetScale() { return mScale; }

void Actor::SetScale(float scale) {
	mScale = scale;
}

float Actor::GetRotation() const { return mRotation; }

void Actor::SetRotation(float rotation) { mRotation = rotation; }

Vector2 Actor::GetForward() const
{
	return Vector2(Math::Cos(mRotation), -Math::Sin(mRotation));
}

Actor::eState Actor::GetState() const {
	return mState;
}

void Actor::SetState(Actor::eState state) {
	mState = state;
}

void Actor::AddComponent(Component* component)
{
	int myOrder = component->GetUpdateOrder();
	auto iter = std::lower_bound(mComponents.begin(), mComponents.end(), myOrder, [](Component *component ,int order) {
		return component->GetUpdateOrder() < order;
	});
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

Game* Actor::GetGame() { return mGame; }

