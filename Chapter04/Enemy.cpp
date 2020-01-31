#include "Enemy.h"
#include "Game.h"
#include "SpriteComponent.h"
Enemy::Enemy(Game* game)
	: Actor(game)
{
	
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
