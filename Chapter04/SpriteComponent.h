#pragma once
#include "Component.h"
#include "SDL/SDL.h"

class Actor;

class SpriteComponent : public Component
{
public:
	SpriteComponent(Actor* owner, int drawOrder);
	virtual ~SpriteComponent();
	
	virtual void Draw(SDL_Renderer* renderer);
	virtual void SetTexture(SDL_Texture* texture);

	int GetDrawOrder() const { return mDrawOrder; }
	int GetTexHeight() const { return mTexHeight; }
	int GetTexWidth() const { return mTextWidth; }

protected:
	SDL_Texture* mTexture;
	int mDrawOrder;
	int mTextWidth;
	int mTexHeight;
};

