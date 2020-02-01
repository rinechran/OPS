#pragma once
#include "MoveComponent.h"
#include "Math.h"

class Actor;
class Tile;
class NavComponent : public MoveComponent
{
public:
	NavComponent(Actor* owner, int updateOrder = 10);
	void Update(float deltaTime) override;
	void StartPath(Tile* start);
	void TurnTo(const Vector2& pos);

private:

	const Tile* mNextNode;
};

