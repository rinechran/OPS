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

	void AddComponent(class Component* component);
	void Update(float deltaTime);

	void RemoveComponent(class Component* component);
	
	void SetPosition(const Vector2 pos);
	Vector2 GetPosition();

	float GetScale();
	void SetScale(float scale);


	eState mState;

private:
	void UpdateComponents(float deltaTime);

	std::vector<class Component*> mComponents;
	
	float mScale;
	float mRotation;
	class Game* mGame;

	Vector2 mPosition;

	
};

