#pragma once
#include <iostream>
#include <vector>
#include "Math.h"
class Game;
class Component;

class Actor
{
public:
	enum class eState {
		Active,
		Paused,
		Dead
	};


	Actor(Game* game);
	virtual ~Actor();

	void ProcessInput(const std::uint8_t * keyStatus);
	virtual void ActorInput(const std::uint8_t* keyStatus);

	void Update(float deltaTime);

	void UpdateComponents(float deltaTime);
	virtual void UpdateActor(float deltaTime);

	const Vector2 GetPosition() const;
	void SetPosition(const Vector2& pos);

	float GetScale();
	void SetScale(float scale);

	float GetRotation() const;
	void SetRotation(float rotation);

	Vector2 GetForward() const;

	eState GetState() const;
	void SetState(Actor::eState state);


	void AddComponent(Component* component);
	void RemoveComponent(Component* component);

	Game* GetGame();


private:
	
	eState  mState;



	std::vector<Component*> mComponents;


	// Transform
	Vector2 mPosition;
	float mScale;
	float mRotation;

	Game* mGame;
};

