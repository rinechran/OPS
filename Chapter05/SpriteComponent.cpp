#include "SpriteComponent.h"
#include "Texture.h"
#include "Shader.h"
#include "Actor.h"
#include "Game.h"


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
		Matrix4 scaleMat = Matrix4::CreateScale(
			static_cast<float>(mTexWidth),
			static_cast<float>(mTexHeight),
			1.0f);


		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

	}
}

void SpriteComponent::SetTexture(Texture* texture)
{
}
