#include "Actor.h"
#include "Component.h"

Component::Component(Actor* owner, int updateOrder)
    : mOwner(owner) , mUpdateOrder(updateOrder){


}

int Component::GetUpdateOrder() const { return mUpdateOrder; }

void Component::Update(float deltaTime)
{
}

void Component::ProcessInput(const std::uint8_t* key)
{
}

Component::~Component() {

}
