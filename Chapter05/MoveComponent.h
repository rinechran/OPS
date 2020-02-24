#pragma once
#include "Component.h"

class Actor;
class MoveComponent : public Component
{
public:
	MoveComponent(Actor* owner, int updateorder = 10);

	void Update(float deltaTime) override;
	float GetAngularSpeed() const { return mAngularSpeed; }
	float GetForwardSpeed() const { return mForwardSpeed; }
	void SetAngularSpeed(float speed) { mAngularSpeed = speed; }
	void SetForwardSpeed(float speed) { mForwardSpeed = speed; }
private:
	float mAngularSpeed;
	float mForwardSpeed;
};

