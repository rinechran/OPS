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
			mTiles[i][j]->SetPosition(Vector2(TITLE_SIZE / 2.0f + j * TITLE_SIZE, START_X + i * TITLE_SIZE));
		}
	}
	GetStartTitle()->SetTileState(Tile::eTileState::Start);
	GetEndTile()->SetTileState(Tile::eTileState::Base);



	for (size_t i = 0; i < NUM_ROWS; ++i) {
		for (size_t j = 0; j < NUM_ROWS; ++j) {

		}
	}

	FindPath(GetStartTitle(), GetEndTile());


	mNextEnemy = EnemyTime;

}

void Grid::ProcessClick(int x, int y)
{
}

void Grid::BuildTower()
{
}

bool Grid::FindPath(Tile* start, Tile* end)
{
	return false;
}

Tile* Grid::GetStartTitle()
{
	return mTiles[3][0];
}

Tile* Grid::GetEndTile()
{
	return mTiles[3][15];
}
