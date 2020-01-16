#include "Component.h"
#include "Actor.h"
Component::Component(Actor* owner, int updateOrder)
	: mUpdateOrder(updateOrder)
	, mOwner(owner)
{
	owner->AddComponent(this);
	
}

Component::~Component()
{
	mOwner->RemoveComponent(this);
}


int Component::GetUpdateOrder() {
	return mUpdateOrder;
}

void Component::Update(float deltaTime)
{
}
