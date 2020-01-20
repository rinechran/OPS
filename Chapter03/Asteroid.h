#pragma once
#include "Actor.h"
class CircleComponent;
class Game;
class Asteroid : public Actor
{
public:
	Asteroid(Game* game);
	

	~Asteroid();
	CircleComponent* GetCircle() { return mCircle; }

private:
	CircleComponent* mCircle;
};

