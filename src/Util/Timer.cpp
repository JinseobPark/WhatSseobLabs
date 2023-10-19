#include "Timer.h"

void Timer::update()
{
    float currentFrame = static_cast<float>(glfwGetTime());
    _deltaTime = currentFrame - _lastFrame;
    _lastFrame = currentFrame;
    _totalTime += _deltaTime;
}
