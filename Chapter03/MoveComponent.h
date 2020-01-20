#pragma once
#include "Component.h"

class Actor;

class MoveComponent : public Component
{
public:
	MoveComponent(Actor* owner, int updateOrder = 10);
	void Update(float deltaTime) override;


private:
	float mAngularSpeed;
	float mForwardSpeed;
};

