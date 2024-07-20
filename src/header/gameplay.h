#pragma once
#include <SDL2/SDL.h>
#include <vector>
#include <SDL2/SDL_image.h>
#include "gamestate.h"
#include "bird.h"
#include "background.h"
#include "pipe.h"
#include "gameloop.h"

class GamePlay {

private:
    Bird bird;
    Background playBG;
    Pipe pipe;
    SDL_Event e;
    std::vector<Pipe> pipes;
    Mix_Chunk* wingSound;

public:
    GameState currentState;
    GamePlay();

    // Sound
    void initSound();

    void checkpoint();
    void loadGamePlay(SDL_Renderer* renderer);
    bool isDie();
    void handleEvent(SDL_Event& event);
    SDL_Texture* loadPipe(SDL_Renderer* renderer);
    void textureRender(SDL_Texture* texture, SDL_Renderer* renderer, SDL_Rect rect);
    // PIPE
    void spawnPipes(SDL_Renderer* renderer);
    bool checkCollision();
};