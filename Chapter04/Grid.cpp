#include "Grid.h"
#include "Tile.h"
Grid::Grid(Game* game)
	: Actor(game)
{
	mTiles.resize(NUM_ROWS);

	for (size_t i = 0; i < mTiles.size(); ++i) {
		mTiles[i].resize(NUM_COLS);
	}


	// Create tiles
	for (size_t i = 0; i < NUM_ROWS; i++)
	{
		for (size_t j = 0; j < NUM_COLS; j++)
		{
			mTiles[i][j] = new Tile(GetGame());
			mTiles[i][j]->SetPosition(Vector2(TILE_SIZE / 2.0f + j * TILE_SIZE, START_Y + i * TILE_SIZE));
		}
	}
	GetStartTile()->SetTileState(Tile::eTileState::Start);
	GetEndTile()->SetTileState(Tile::eTileState::Base);



	// adjacent List Setup
	for (size_t i = 0; i < NUM_ROWS; ++i) {
		for (size_t j = 0; j < NUM_ROWS; ++j) {
			if (i > 0) {
				mTiles[i][j]->mAdjacent.push_back(mTiles[i - 1][j]);
			}
			if (i < NUM_ROWS - 1) {
				mTiles[i][j]->mAdjacent.push_back(mTiles[i + 1][j]);
			}
			if (j < 0) {
				mTiles[i][j]->mAdjacent.push_back(mTiles[i][j - 1]);
			}
			if (j < NUM_COLS) {
				mTiles[i][j]->mAdjacent.push_back(mTiles[i][j + 1]);
			}
		}
	}

	FindPath(GetStartTile(), GetEndTile());
	UpdatePathTiles(GetStartTile());


	mNextEnemy = EnemyTime;

}

void Grid::ProcessClick(int x, int y)
{
	y -= static_cast<int>(START_Y - (TILE_SIZE / 2));
	if (y > 0) {
		x /= static_cast<int>(TILE_SIZE);
		y /= static_cast<int>(TILE_SIZE);

		if (x >= 0 && x < static_cast<int>(NUM_COLS) && y >= 0 && y < static_cast<int>(NUM_ROWS))
		{
		}

	}
}

void Grid::BuildTower()
{
}

bool Grid::FindPath(Tile* start, Tile* end)
{
	return false;
}

void Grid::UpdatePathTiles(Tile* start)
{
}

Tile* Grid::GetStartTile()
{
	return mTiles[3][0];
}

Tile* Grid::GetEndTile()
{
	return mTiles[3][15];
}
