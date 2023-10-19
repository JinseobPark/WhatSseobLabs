#pragma once
#include <glfw/glfw3.h>\

class Timer
{
public:
	Timer() {}
	~Timer() {}

	void update();
	float getDeltaTime() const { return _deltaTime; }
	float getTotalTime() const { return _totalTime; }

private:
	float _deltaTime = 0.0f;
	float _lastFrame = 0.0f;
	float _totalTime = 0.0f;
};
