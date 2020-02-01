#pragma once
#include "Actor.h"

class Game;
class CircleComponent;
class Enemy : public Actor
{
public:
	Enemy(Game* game);
	~Enemy();
	void UpdateActor(float deltaTime) override;
	CircleComponent* GetCircle();
private:
	CircleComponent* mCircle;
};

