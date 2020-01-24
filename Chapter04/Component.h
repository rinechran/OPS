#pragma once
#include <iostream>


class Actor;
class Component
{
public:
	Component(Actor* owner, int updateOrder = 100);

	int GetUpdateOrder() const;
	virtual void Update(float deltaTime);
	virtual void ProcessInput(const std::uint8_t* key);
	virtual ~Component();

protected:

	Actor* mOwner;
	int mUpdateOrder;

};

