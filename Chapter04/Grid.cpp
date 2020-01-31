#include "Grid.h"
#include "Tower.h"
#include "Tile.h"
Grid::Grid(Game* game)
	: Actor(game)
	, mSelectedTile(nullptr)
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
			SelectTile(y, x);
		}

	}
}

void Grid::BuildTower()
{
	if (mSelectedTile && !mSelectedTile->mBlocked) {
		mSelectedTile->mBlocked = true;

		if (FindPath(GetEndTile(), GetStartTile()))
		{
			Tower* t = new Tower(GetGame());
			t->SetPosition(mSelectedTile->GetPosition());
		}
		else
		{
			mSelectedTile->mBlocked = false;
			FindPath(GetEndTile(), GetStartTile());
		}
		UpdatePathTiles(GetStartTile());
	}
}

bool Grid::FindPath(Tile* start, Tile* end)
{
	for (size_t i = 0; i < NUM_ROWS; i++)
	{
		for (size_t j = 0; j < NUM_COLS; j++)
		{
			mTiles[i][j]->g = 0.0f;
			mTiles[i][j]->mInOpenSet = false;
			mTiles[i][j]->mInClosedSet = false;
		}
	}
	std::vector<Tile*> openSet;

	Tile* current = start;
	current->mInClosedSet = true;
	return true;
}

void Grid::UpdatePathTiles(Tile* start)
{
}

void Grid::SelectTile(size_t row, size_t col)
{
	Tile::eTileState tileStatus = mTiles[row][col]->GetTileState();
	if (tileStatus != Tile::eTileState::Start && tileStatus != Tile::eTileState::Base) {
		if (mSelectedTile!=nullptr) {
			mSelectedTile->ToggleSelect();
		}
		mSelectedTile = mTiles[row][col];
		mSelectedTile->ToggleSelect();

	}
}

Tile* Grid::GetStartTile()
{
	return mTiles[3][0];
}

Tile* Grid::GetEndTile()
{
	return mTiles[3][15];
}
