#pragma once
#include "Actor.h"

class Game;
class MoveComponent;
class Tower : public Actor
{
public:
	Tower(Game* game);
	void UpdateActor(float deltaTime) override;
private:
	MoveComponent* mMove;
	float mNextAttack;
	const float AttackTime = 2.5f;
	const float AttackRange = 100.0f;
};

