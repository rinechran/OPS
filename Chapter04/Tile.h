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
	void ToggleSelect();
private:
	float f;
	float g;
	float h;
	Tile* mParent;

	bool mInOpenSet;
	bool mInClosedSet;
	bool mBlocked;
	std::vector<Tile*> mAdjacent;


	eTileState mTileState;
	SpriteComponent* mSprite;

	bool mSelected;
};

