#pragma once
class Actor
{
public:
	enum class eState {
		Active,
		Paused,
		Dead
	};
	Actor(class Game* game);
	~Actor();

	eState getState() const {
		return mState;
	}

	eState mState;

private:
	class Game* mGame;
};

