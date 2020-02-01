#include "NavComponent.h"

NavComponent::NavComponent(Actor* owner, int updateOrder)
	: MoveComponent(owner,updateOrder)
	, mNextNode(nullptr)
{
}

void NavComponent::Update(float daltaTime)
{

}

void NavComponent::StartPath(Tile* start)
{
}

void NavComponent::TrunTo(const Vector2& pos)
{
}
