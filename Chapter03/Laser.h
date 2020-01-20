#pragma once
#include "Actor.h"


class Game;
class CircleComponent;
class Laser : public Actor
{
public:
	Laser(Game* game);
	void UpdateActor(float deltaTime) override;
private:
	
	CircleComponent* mCircle;
	float mDeathTimer;

};

