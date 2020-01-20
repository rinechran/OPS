#include "Ship.h"
#include "SpriteComponent.h"
#include "Game.h"
#include "InputComponent.h"
#include "Laser.h"

Ship::Ship(Game* game)
	: Actor(game)
	, mLaserCoolDown(0.0f)
{
	SpriteComponent* sc = new SpriteComponent(this, 150);
	sc->SetTexture(game->GetTexture("Assets/Ship.png"));

	InputComponent* ic = new InputComponent(this);
	ic->SetForwardKey(SDL_SCANCODE_W);
	


}

void Ship::UpdateActor(float deltaTime) {

}

void Ship::ActorInput(const uint8_t* keyState) {
	if (keyState[SDL_SCANCODE_SPACE] && mLaserCoolDown <= 0.0f) {

	}
}
