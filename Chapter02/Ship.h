#pragma once
#include "Actor.h"
class Ship : public Actor
{
public:
	Ship(class Game* game);

private:
	float mRightSpeed;
	float mDownSpeed;
};

