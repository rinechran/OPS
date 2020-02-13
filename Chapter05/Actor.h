#pragma once
#include <vector>
#include "Math.h"
#include <cstdint>

class Game;
class Component;
class Actor
{
	enum class eState {
		Active,
		Pause,
		Dead
	};
	Actor(Game* game);
	virtual ~Actor();

	void Update(float deltaTime);
	void UpdateComponents(float deltaTime);
	virtual void UpdateActor(float deltaTime);
	void ProcessInput(const uint8_t* keyState);

	const Vector2& GetPosition() const { return mPosition; }
	void SetPosition(const Vector2& pos) { mPosition = pos; mRecomputeWorldTransform = true; }
	float GetScale() const { return mScale; }
	void SetScale(float scale) { mScale = scale;  mRecomputeWorldTransform = true; }
	float GetRotation() const { return mRotation; }
	void SetRotation(float rotation) { mRotation = rotation;  mRecomputeWorldTransform = true; }

	void ComputeWorldTransform();

	Game* GetGame() { return mGame; }

	void RemoveComponent(Component* component);
	void AddComponent(Component* component);


private:
	// Actor's state
	eState mState;

	// Transform
	Matrix4 mWorldTransform;
	Vector2 mPosition;
	float mScale;
	float mRotation;
	bool mRecomputeWorldTransform;

	std::vector<Component*> mComponents;

	Game* mGame;
};

