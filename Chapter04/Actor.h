#pragma once

class Game;

class Actor {
public:
	enum class State {
		Active,
		EPaused,
		EDead
	};
	Actor(Game* game);
	virtual ~Actor();

private:
	Game* mGame;
};