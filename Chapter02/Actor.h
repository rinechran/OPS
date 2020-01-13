#pragma once
#include <vector>
#include "Math.h"
class Actor
{
public:
	enum class eState {
		Active,
		Paused,
		Dead
	};
	Actor(class Game* game);
	~Actor();

	eState GetState() const;
	
	void Update(float deltaTime);
	
	virtual void UpdateActor(float deltaTime);

	void RemoveComponent(class Component* component);
	void AddComponent(class Component* component);

	void SetPosition(const Vector2 pos);
	Vector2 GetPosition();

	float GetScale();
	void SetScale(float scale);
	float GetRotation() const { return mRotation; }

	class Game* GetGame() { return mGame; }

	eState mState;

private:
	void UpdateComponents(float deltaTime);

	std::vector<class Component*> mComponents;
	
	float mScale;
	float mRotation;
	class Game* mGame;

	Vector2 mPosition;

	
};

