#pragma once
#include "Component.h"
#include <unordered_map>
#include <string>

class Actor;
class AIComponent : public Component
{
public:
	AIComponent(Actor* owner);
	void Update(float deltaTime) override;

};

