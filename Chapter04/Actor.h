#pragma once
#include <iostream>
#include <vector>
#include "Math.h"
class Game;
class Component;
class Actor {
public:
	enum class eState {
		Active,
		EPaused,
		EDead
	};
	Actor(Game* game);
	virtual ~Actor();

	void Update(float deltaTime);

	virtual void updateActor(float deltaTime);
	void UpdateComponents(float deltaTime);

	void ProcessInput(const std::uint8_t * keyState);

	virtual void ActorInput(const std::uint8_t * keyState);

	const Vector2& GetPosition() const;
	void SetPosition(const Vector2& pos);

	void AddComponent(Component* component);
	void RemoveComponent(Component* component);

	Game* GetGame();

	eState GetState() const;
	void SetState(eState state);



private:

	Vector2 mPosition;
	float mScale;
	float mRouation;
	eState mState;
	std::vector <Component*> mComponents;
	Game* mGame;
};