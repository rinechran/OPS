#pragma once
#include <cstdint>;

class Actor;
class Component
{
public:
	Component(Actor* owner, int updateOrder = 100);
	~Component();
	virtual void Update(float deltaTime);
	virtual void ProcessInput(const std::uint8_t * keyState);
	virtual void OnUpdateWorldTransform() { }
	int GetUpdateOrder() const { return mUpdateOrder; }
protected:
	Actor* mOwner;
	int mUpdateOrder;
};

