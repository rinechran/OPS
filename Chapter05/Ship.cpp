#include "Ship.h"
#include "Game.h"
#include "SpriteComponent.h"
#include "Texture.h"
Ship::Ship(Game* game)
	: Actor(game)
	, mLaserCooldown(0.0f)
{
	SpriteComponent* sc = new SpriteComponent(this, 150);
	sc->SetTexture(game->GetTexture("Assets/Ship.png"));

}

void Ship::UpdateActor(float deltaTime)
{
	mLaserCooldown -= deltaTime;
}

void Ship::ActorInput(const uint8_t* keyState)
{
}
