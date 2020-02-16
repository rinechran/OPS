#pragma once
#include "Component.h"
#include "SDL/SDL.h"

class Actor;
class Shader;
class Texture;
class SpriteComponent : public Component
{
public:
	SpriteComponent(Actor* owner, int drawOrder = 100);
	~SpriteComponent();

	virtual void Draw(Shader* shader);
	virtual void SetTexture(Texture* texture);

	int GetDrawOrder() const { return mDrawOrder; }
	int GetTexHeight() const { return mTexHeight; }
	int GetTexWidth() const { return mTexWidth; }
protected:
	Texture* mTexture;
	int mDrawOrder;
	int mTexWidth;
	int mTexHeight;
};

