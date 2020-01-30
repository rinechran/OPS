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

	bool FindPath(Tile* start, Tile* end);
	void UpdatePathTiles(Tile* start);

	std::vector<std::vector<Tile*>> mTiles;

	Tile* GetStartTile();
	Tile* GetEndTile();

private:
	float mNextEnemy;
	float EnemyTime;

	const size_t NUM_ROWS = 7;
	const size_t NUM_COLS = 16;
	const float START_Y = 192.0f;
	const float TILE_SIZE = 64.0f;
	const float ENEMY_TIME = 1.5f;
};

