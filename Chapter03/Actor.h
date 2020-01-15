#pragma once
#include "Math.h"
class Game;
class Component;

class Actor
{
public:
	enum class eState {
		Active,
		Paused,
		Dead
	};


	Actor(Game* game);
	virtual ~Actor();

	virtual void Update(float deltaTime);


	float GetScale();
	void SetScale(float scale);



private:
	
	eState  mState;


	// Transform
	Vector2 mPosition;
	float mScale;
	float mRotation;

	Game* mGame;
};

