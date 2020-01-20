#include "Asteroid.h"
#include "Random.h"
#include "Game.h"
#include "MoveComponent.h"
#include "SpriteComponent.h"
#include "CircleComponent.h"

Asteroid::Asteroid(Game* game) 
	: Actor(game)
	, mCircle(nullptr){

	Vector2 randPos = Random::GetVector(Vector2::Zero,
		Vector2(1025.f, 768.0f));

	SetPosition(randPos);
	SetRotation(Random::GetFloatRange(0.0f, Math::TwoPi));

	SpriteComponent* sc = new SpriteComponent(this);
	sc->SetTexture(game->GetTexture("Assets/Asteroid.png"));

	MoveComponent* mv = new MoveComponent(this);
	mv->SetForwardSpeed(150.0f);

	mCircle = new CircleComponent(this);
	mCircle->SetRadius(40.0f);

	game->AddAsteroid(this);

}

Asteroid::~Asteroid()
{
	GetGame()->RemoveAsteroid(this);
}
