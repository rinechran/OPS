#include "MoveComponent.h"
#include "Math.h"
#include "Actor.h"

MoveComponent::MoveComponent(Actor* owner, int updateOrder)
	: Component(owner, updateOrder)
	, mAngularSpeed(0.0f)
	, mForwardSpeed(0.0f)
{
}

void MoveComponent::Update(float deltaTime)
{
	if (!Math::NearZero(mAngularSpeed)) {
	}
	
	if (!Math::NearZero(mForwardSpeed)) {

	}
}

float MoveComponent::GetAngularSpeed() const { return mAngularSpeed; }

float MoveComponent::GetForwardSpeed() const { return mForwardSpeed; }

void MoveComponent::SetAngularSpeed(float speed) { mAngularSpeed = speed; }

void MoveComponent::SetForwardSpeed(float speed) { mForwardSpeed = speed; }
