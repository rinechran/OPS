#include "CircleComponent.h"
#include "Actor.h"
CircleComponent::CircleComponent(Actor* owner) 
	: Component(owner)
	, mRadius(0.0f){

}

void CircleComponent::SetRadius(float redius) 
{
	mRadius = redius;
}

float CircleComponent::GetRadius() const 
{
	return mRadius;
}

const Vector2& CircleComponent::GetCenter() const
{
	return mOwner->GetPosition();
}

bool Intersect(const CircleComponent& a, const CircleComponent& b)
{
	Vector2 diff = a.GetCenter() - b.GetCenter();
	float centerLength = diff.LengthSq();
	float radiiSq = a.GetRadius() + b.GetRadius();

	return false;
}
