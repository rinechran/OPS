#pragma once
class Component
{
public:
	Component(class Actor* owner, int updateOrder = 100);
	virtual ~Component();
	virtual void Update(float deltaTime);

protected:
	class Actor* mOwner;
	int mUpdateOrder;

};

