#include "Actor.h"
#include "Component.h"

Component::Component(Actor* owner, int updateOrder)
    : mOwner(owner) 
    , mUpdateOrder(updateOrder){

    mOwner->AddComponent(this);
}

int Component::GetUpdateOrder() const {
    return mUpdateOrder; 
}



Component::~Component() {
    mOwner->RemoveComponent(this);
}
void Component::Update(float deltaTime)
{
}

void Component::ProcessInput(const std::uint8_t* key)
{
}