#include "Ship.h"
#include "Game.h"
#include "SpriteComponent.h"

Ship::Ship(Game* mGame)
	: Actor(mGame)
	, mLaserCooldown(0.0f)
{
	SpriteComponent* sc = new SpriteComponent(this, 150);
	sc->SetTexture()
	
}

void Ship::UpdateActor(float deltaTime)
{
	mLaserCooldown -= deltaTime;
}

void Ship::ActorInput(const uint8_t* keyState)
{
}
