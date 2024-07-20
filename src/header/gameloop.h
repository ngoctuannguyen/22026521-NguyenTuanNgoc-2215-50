#include <SDL2/SDL.h>
#pragma once
#include <SDL2/SDL_mixer.h>
#include <iostream>
#include <fstream>


class GameLoop {

private:
    static const int WINDOW_HEIGHT = 640;
    static const int WINDOW_WIDTH = 800;
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool gState;
    SDL_Event event_;

public: 
    GameLoop();
    void initSound();
    bool getGState();
    void setGState(bool _gState);
    void initialize();
    void event();
    void render();
    void clear();
    void endGame();
    SDL_Renderer* getRender();
    static int getWindowHeight();
    static int getWindowWidth();
    void reset();
    int loadHighScore();
    void saveHighScore(int highScore);

    // Sound
    
    Mix_Chunk* startSound;
    Mix_Chunk* wingSound;
    Mix_Chunk* pointSound;
    Mix_Chunk* dieSound;
    Mix_Chunk* hitSound;
    Mix_Chunk* exitSound;
};