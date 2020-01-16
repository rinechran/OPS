#pragma once
#include "SDL/SDL.h"
#include "Component.h"

class Actor;
class SpriteComponent : public Component
{
public:
	SpriteComponent(Actor* actor, int drawOrder = 100);
	~SpriteComponent();

	virtual void Draw(SDL_Renderer* renderer);
	virtual void SetTexture(SDL_Texture* texture);

protected:
	SDL_Texture* mTexture;
	int mDrawOwder;
	int mTextWidth;
	int mTextHeight;
};

