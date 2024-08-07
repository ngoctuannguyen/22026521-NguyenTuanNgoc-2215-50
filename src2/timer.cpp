#include "header/timer.h"

Timer::Timer() {
    lastTime = 0;
    deltaTime = 0;
}

bool Timer::update() {

    float current = SDL_GetTicks();
    deltaTime = (current - lastTime) / 10.0f;
    lastTime = current;
    return true;
}

float& Timer::getDeltaTime() {
    return deltaTime;
}