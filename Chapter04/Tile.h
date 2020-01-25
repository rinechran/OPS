#pragma once
#include "Actor.h"

class Grid;
class Game;
class Tile : public Actor
{
public: 
	friend Grid;
	enum class TileState {
		Default,
		Path,
		Start,
		Base,
	};

	Tile(Game* game);
};

