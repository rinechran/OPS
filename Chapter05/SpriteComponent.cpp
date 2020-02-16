#include "SpriteComponent.h"

SpriteComponent::SpriteComponent(Actor* owner, int drawOrder)
	: Component(owner)
{
}

SpriteComponent::~SpriteComponent()
{
}

void SpriteComponent::Draw(Shader* shader)
{
	if (mTexture) {

	}
}

void SpriteComponent::SetTexture(Texture* texture)
{
}
