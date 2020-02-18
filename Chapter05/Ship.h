#pragma once
#include "Actor.h"
class Game;
class Ship : public Actor
{
public:
	Ship(Game * mGame);
	void UpdateActor(float deltaTime) override;
	void ActorInput(const uint8_t* keyState) override;

private:
	float mLaserCooldown;
};

