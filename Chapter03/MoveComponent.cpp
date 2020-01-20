#include "MoveComponent.h"

MoveComponent::MoveComponent(Actor* owner, int updateOrder) 
	: Component(owner, updateOrder)
	, mAngularSpeed(0.0f)
	, mForwardSpeed(0.0f){

}

void MoveComponent::Update(float deltaTime) {

}
