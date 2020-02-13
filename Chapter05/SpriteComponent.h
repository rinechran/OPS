#pragma once
#include "Component.h"
#include "SDL/SDL.h"

class Actor;
class SpriteComponent : public Component
{
public:
	SpriteComponent(Actor* owner, int drawOrder = 100);
};

