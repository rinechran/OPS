#include "Enemy.h"
#include "Game.h"
#include "SpriteComponent.h"
#include "CircleComponent.h"
#include "Game.h"
#include "Grid.h"
#include "Tile.h"

Enemy::Enemy(Game* game)
	: Actor(game)
{
	game->GetEnemies().emplace_back(this);

	SpriteComponent* sc = new SpriteComponent(this);
	sc->SetTexture(game->GetTexture("Assets/Airplane.png"));
	SetPosition(GetGame()->GetGrid()->GetStartTile()->GetPosition());


}

Enemy::~Enemy()
{
}

void Enemy::UpdateActor(float deltaTime)
{
}

CircleComponent* Enemy::GetCircle() {
	return mCircle;
}
