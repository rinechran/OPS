#include "CircleComponent.h"

CircleComponent::CircleComponent(Actor* owner)
	: Component(owner)
	, mRadius(0.0f)
{
}

void CircleComponent::SetRadius(float radius) { mRadius = radius; }

float CircleComponent::GetRadius() const
{
	return 0.0f;
}

const Vector2 CircleComponent::GetCenter() const
{
	return Vector2();
}

bool Intersect(const CircleComponent& a, const CircleComponent& b)
{
	Vector2 diff = a.GetCenter() - b.GetCenter();
	float distSq = diff.Length();

	float radiiSq = a.GetRadius() + b.GetRadius();
	radiiSq *= radiiSq;

	return distSq <= radiiSq;
}
