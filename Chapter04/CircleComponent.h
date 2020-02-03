#pragma once
#include "Component.h"
#include "Math.h"


class Actor;

class CircleComponent : public Component
{
public:
	CircleComponent(Actor* owner);

	void SetRadius(float radius);

	float GetRadius() const;

	const Vector2& GetCenter() const;
private:
	float mRadius;
};

bool Intersect(const CircleComponent& a, const CircleComponent& b);
