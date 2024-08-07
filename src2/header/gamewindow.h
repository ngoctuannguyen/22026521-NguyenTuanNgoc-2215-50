#pragma once
#include <SDL2/SDL.h>
#include "module.h"

class GameWindow : public Module {

private:
    SDL_Window* gameWindow;
    const int WINDOW_HEIGHT = 640;
    const int WINDOW_WIDTH = 800;

public:
    GameWindow();
    SDL_Window* getWindow();
    bool update() override;
    bool clear() override;
};