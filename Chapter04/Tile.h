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

	void SetTileState(eTileState state);
	void UpdateTexture();
private:
	float f;
	float g;
	float h;

	eTileState mTitleState;
	SpriteComponent* mSprite;

	bool mSelected;
};

