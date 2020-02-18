#include "Texture.h"
#include "Actor.h"
#include "Game.h"
#include "SpriteComponent.h"

SpriteComponent::SpriteComponent(Actor* owner, int drawOrder)
	: Component(owner)
	, mTexture(nullptr)
{
	mOwner->GetGame()->AddSprite(this);
}

SpriteComponent::~SpriteComponent()
{
	mOwner->GetGame()->RemoveSprite(this);

}

void SpriteComponent::Draw(Shader* shader)
{
	if (mTexture) {

	}
}

void SpriteComponent::SetTexture(Texture* texture)
{
}
