#pragma once
#include "module.h"
#include <SDL2/SDL.h>

class Timer : public Module {
private:
    float deltaTime;
    float lastTime;
public:
    Timer();
    bool update() override;
    float& getDeltaTime();
};