#include "SpriteComponent.h"
#include "Actor.h"
#include "Game.h"

SpriteComponent::SpriteComponent(Actor* owner, int drawOrder)
    : Component(owner)
    , mTexture(nullptr)
    , mTextWidth(0)
    , mTexHeight(0)
    , mDrawOrder(0){

    mOwner->GetGame()->AddSprite(this);
}

SpriteComponent::~SpriteComponent()
{
    mOwner->GetGame()->RemoveSprite(this);
}

void SpriteComponent::Draw(SDL_Renderer* renderer)
{
    if (mTexture) {
        SDL_Rect r;

    }
}

void SpriteComponent::SetTexture(SDL_Texture* texture)
{
    mTexture = texture;
    SDL_QueryTexture(texture, nullptr, nullptr ,&mTextWidth, &mTexHeight);
}
