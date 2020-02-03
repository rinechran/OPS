#include "Tower.h"
#include "SpriteComponent.h"
#include "MoveComponent.h"
#include "Game.h"
#include "Enemy.h"
#include "Bullet.h"
Tower::Tower(Game* game)
	: Actor(game)
{
	SpriteComponent* sc = new SpriteComponent(this, 200);

	sc->SetTexture(game->GetTexture("Assets/Tower.png"));
	mNextAttack = AttackTime;
	

	mMove = new MoveComponent(this);

	mNextAttack = AttackTime;
}

void Tower::UpdateActor(const float deltaTime)
{
	Actor::UpdateActor(deltaTime);

	mNextAttack -= deltaTime;
	if (mNextAttack <= 0.0f)
	{
		Enemy* e = GetGame()->GetNearestEnemy(GetPosition());
		if (e != nullptr)
		{
			Vector2 dir = e->GetPosition() - GetPosition();
			float dist = dir.Length();
			if (dist < AttackRange)
			{
				SetRotation(Math::Atan2(-dir.y, dir.x));
				Bullet* b = new Bullet(GetGame());
				b->SetPosition(GetPosition());
				b->SetRotation(GetRotation());
			}
		}
		mNextAttack += AttackTime;
	}
}
