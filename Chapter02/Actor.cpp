#include "Actor.h"
#include "Game.h"

Actor::Actor(Game * game)
	: mState(Actor::eState::Active)
	, mGame(game)
{
	mGame->AddActor(this);

}
Actor::~Actor() {

}