#pragma once
#include "Actor.h"
#include <vector>

class Game;
class Tile;
class Grid : public Actor
{
public:
	Grid(Game* game);

	void ProcessClick(int x, int y);
	void BuildTower();

	std::vector<std::vector<Tile*>> mTiles;


};

