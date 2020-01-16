#pragma once
#include <iostream>
class Actor;
class Component
{
public:
	Component(Actor* owner, int updateOrder = 100);
	virtual ~Component();
	int GetUpdateOrder();

	virtual void Update(float deltaTime);
	virtual void ProcessInput(const std::uint8_t* keyState) {}

protected:

	Actor* mOwner;

	int mUpdateOrder;
};

