#include "Actor.h"
#include "Game.h"
#include "Math.h"
#include "Component.h"

Actor::Actor(Game* game)
	: mGame(game)
	, mState(Actor::eState::Active)
	, mPosition(Vector2::Zero)
	, mScale(1.0f)
	, mRecomputeWorldTransform(true)
{
	mGame->AddActor(this);
}

Actor::~Actor()
{
	mGame->RemoveActor(this);
	while (!mComponents.empty()) {
		delete mComponents.back();
	}
}

void Actor::Update(float deltaTime)
{
	if (mState == Actor::eState::Active) {
		ComputeWorldTransform();

		UpdateComponents(deltaTime);
		UpdateActor(deltaTime);

		ComputeWorldTransform();
	}
}

void Actor::UpdateComponents(float deltaTime)
{
	for (auto comp : mComponents) {
		comp->Update(deltaTime);
	};
}

void Actor::UpdateActor(float deltaTime)
{
}

void Actor::ActorInput(const uint8_t* keyState)
{
}



void Actor::ProcessInput(const std::uint8_t* keyState)
{
	if (mState == Actor::eState::Active) {
		for (auto comp : mComponents) {
			comp->ProcessInput(keyState);
		};
		ActorInput(keyState);
		
	}
}

void Actor::ComputeWorldTransform()
{
	if (mRecomputeWorldTransform) {
		mRecomputeWorldTransform = false;
		// S R T 
		mWorldTransform = Matrix4::CreateScale(mScale);
		mWorldTransform *= Matrix4::CreateRotationZ(mRotation);
		mWorldTransform *= Matrix4::CreateTranslation(Vector3(mPosition.x, mPosition.y, 0.0f));

		for (auto comp : mComponents)
		{
			comp->OnUpdateWorldTransform();
		}
	}
}

void Actor::RemoveComponent(Component* component)
{
	auto iter = std::find(mComponents.begin(), mComponents.end(), component);
	if (iter != mComponents.end()) {
		mComponents.erase(iter);
	}
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
