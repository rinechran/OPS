#include "InputComponent.h"

InputComponent::InputComponent(Actor* owner)
	: MoveComponent(owner){

}

void InputComponent::ProcessInput(const std::uint8_t* keyState) {

	float forwardSpeed = 0.0f;
	if (keyState[mForwardKey]) {
		forwardSpeed += mMaxForwardSpeed;
	}
	SetForwardSpeed(forwardSpeed);

}

void InputComponent::SetForwardKey(int key) {
	mForwardKey = key;
}

void InputComponent::SetBackKey(int key) { mBackKey = key; }

void InputComponent::SetClockwiseKey(int key) { mClockwiseKey = key; }

void InputComponent::SetCounterClockwiseKey(int key) { mCounterClockwiseKey = key; }
