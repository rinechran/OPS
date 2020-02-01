#pragma once
#include "MoveComponent.h"
#include "Math.h"

class Actor;
class Tile;
class NavComponent : public MoveComponent
{
public:
	NavComponent(Actor* owner, int updateOrder = 10);
	void Update(float daltaTime) override;
	void StartPath(Tile* start);
	void TrunTo(const Vector2& pos);

private:

	const Tile* mNextNode;
};

