#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "gamestate.h"
#include "bird.h"
#include "background.h"
#include "pipe.h"

class GamePlay {

private:
    Bird bird;
    Background playBG;
    // Pipe lowerPipe, upperPipe;

public:
    GameState currentState;
    void checkpoint();
    void loadGamePlay(SDL_Renderer* renderer);
    bool isDie();
    void textureRender(SDL_Texture* texture, SDL_Renderer* renderer, SDL_Rect rect);
};