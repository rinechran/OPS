#pragma once
#include <vector>
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

	void AddComponent(class Component* component);
	void RemoveComponent(class Component* component);
	eState mState;

private:
	void UpdateComponents(float deltaTime);
	class Game* mGame;
	std::vector<class Component*> mComponents;
	
};

