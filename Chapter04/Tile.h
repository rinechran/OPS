#pragma once
#include "Actor.h"

class Grid;
class SpriteComponent;
class Game;
class Tile : public Actor
{
public: 
	friend Grid;
	enum class eTileState {
		Default,
		Path,
		Start,
		Base,
	};

	Tile(Game* game);
	Tile::eTileState GetTileState();
	void SetTileState(eTileState state);
	void UpdateTexture();
private:
	float f;
	float g;
	float h;


	std::vector<Tile*> mAdjacent;


	eTileState mTileState;
	SpriteComponent* mSprite;

	bool mSelected;
};

