#include "Game.h"
#include "Tower.h"
#include "SpriteComponent.h"
#include "MoveComponent.h"
Tower::Tower(Game* game)
	: Actor(game)
{
	SpriteComponent* sc = new SpriteComponent(this, 200);

	sc->SetTexture(game->GetTexture("Assets/Tower.png"));
	mNextAttack = AttackTime;
	


}

void Tower::UpdateActor(float deltaTime)
{
}
