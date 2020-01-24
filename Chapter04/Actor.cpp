#include "Actor.h"
#include "Game.h"

Actor::Actor(Game* game)
	: mGame(game)
{
	mGame->AddActor(this);
}

Actor::~Actor() {

	mGame->RemoveActor(this);
}
