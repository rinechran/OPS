#include "SpriteComponent.h"
#include "Actor.h"
#include "Game.h"

SpriteComponent::SpriteComponent(Actor* actor, int drawOrder)
	: Component(actor)
	, mTexture(nullptr)
	, mDrawOwder(drawOrder)
	, mTextHeight(0)
	, mTextWidth(0)
{
	mOwner->GetGame();
}

SpriteComponent::~SpriteComponent()
{
}

void SpriteComponent::Draw(SDL_Renderer* renderer)
{
}

void SpriteComponent::SetTexture(SDL_Texture* texture)
{
}
