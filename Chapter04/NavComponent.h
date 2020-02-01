#pragma once
#include "MoveComponent.h"
#include "Math.h"

class Actor;
class NavComponent : public MoveComponent
{
public:
	NavComponent(Actor* owner, int updateOrder = 10);
};

