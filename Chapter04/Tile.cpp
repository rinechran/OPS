#include "Tile.h"
#include "SpriteComponent.h"
#include "Game.h"
Tile::Tile(Game* game)
	: Actor(game)
	, f(0.0f)
	, g(0.0f)
	, h(0.0f)
	, mSprite(nullptr)
	, mSelected(false)
	, mBlocked(false)
{

	mSprite = new SpriteComponent(this);
	UpdateTexture();

}

Tile::eTileState Tile::GetTileState() {
	return mTileState;
}

void Tile::SetTileState(eTileState state)
{
	mTileState = state;
	UpdateTexture();
}

void Tile::UpdateTexture()
{
	std::string text;
	switch (mTileState)
	{
	case Tile::eTileState::Start:
		text = "Assets/TileTan.png";
		break;
	case Tile::eTileState::Base:
		text = "Assets/TileGreen.png";
		break;
	case Tile::eTileState::Path:
		if (mSelected)
			text = "Assets/TileGreySelected.png";
		else
			text = "Assets/TileGrey.png";
		break;
		break;
	case Tile::eTileState::Default:
		if (mSelected)
			text = "Assets/TileBrownSelected.png";
		else
			text = "Assets/TileBrown.png";
	break;	default:
		break;
	}
	mSprite->SetTexture(GetGame()->GetTexture(text));
	
}

void Tile::ToggleSelect()
{
	mSelected = !mSelected;
	UpdateTexture();

}
