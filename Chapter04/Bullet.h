#pragma once
#include "Actor.h"

class Game;
class CircleComponent;
class Bullet : public Actor
{
public:
	Bullet(Game* game);
	void UpdateActor(float deltaTime) override;

private:
	CircleComponent* mCircle;
	float mLiveTime;
};

