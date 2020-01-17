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


	int GetDrawOrder() const { return mDrawOrder; }
	int GetTexHeight() const { return mTexHeight; }
	int GetTexWidth() const { return mTexWidth; }
protected:
	SDL_Texture* mTexture;
	int mDrawOrder;
	int mTexHeight;
	int mTexWidth;
};

