#include <SDL2/SDL.h>
#pragma once

#include <iostream>


class GameLoop {

private:
    const int WINDOW_HEIGHT = 640;
    const int WINDOW_WIDTH = 800;
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool gState;
    SDL_Event event_;
public: 
    GameLoop();
    bool getGState();
    void initialize();
    void event();
    void render();
    void clear();
    void endGame();
    SDL_Renderer* getRender();
};