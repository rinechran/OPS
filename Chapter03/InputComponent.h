#pragma once
#include "MoveComponent.h"
#include <cstdint>

class Actor;
class InputComponent : public MoveComponent
{
public:
	InputComponent(Actor* owner);

	void ProcessInput(const std::uint8_t* keyState) override;
	float GetMaxForward() const { return mMaxForwardSpeed; }
	float GetMaxAngular() const { return mMaxAngularSpeed; }

	void SetForwardKey(int key);
	void SetBackKey(int key);
	void SetClockwiseKey(int key);
	void SetCounterClockwiseKey(int key);


private:
	float mMaxForwardSpeed;
	float mMaxAngularSpeed;


	// Key Setting
	int mForwardKey;
	int mBackKey;

	int mClockwiseKey;
	int mCounterClockwiseKey;

};

