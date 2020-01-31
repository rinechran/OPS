#pragma once
#include "Component.h"

class Actor;
class MoveComponent : public Component
{
public:
	MoveComponent(Actor* owner, int updateOrder = 10);
	void Update(float deltaTime) override;
	float GetAngularSpeed() const;
	float GetForwardSpeed() const;
	void SetAngularSpeed(float speed);
	void SetForwardSpeed(float speed);

private:

	float mAngularSpeed;
	float mForwardSpeed;
};

