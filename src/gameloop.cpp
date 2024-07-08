#include "header/gameloop.h"
#include <SDL2/SDL.h>
#include "header/background.h"
#include "header/mainMenu.h"
#include "header/gamestate.h"
#include "header/gameplay.h"
#include "header/gameover.h"

GameState currentState;

MainMenu* mainMenu = new MainMenu();

GameLoop::GameLoop() {
    window = NULL;
    renderer = NULL;
    gState = false;
}   

// GameLoop* 

bool GameLoop::getGState() {
    return gState;
}

void GameLoop::event() {
    SDL_PollEvent(&event_); // The SDL_PollEvent function is used to poll for currently pending events and processes them
    if (event_.type == SDL_QUIT) {
        gState = false;
    }
    if (event_.type == SDL_MOUSEMOTION) {
        // std::cout << event_.motion.x << " " << event_.motion.y << std::endl;
    }
}

void GameLoop::initialize() {
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow(
        "Flappy Bird", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_RESIZABLE
    );
    if (window) {
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer) {
            std::cerr << "Success" << std::endl;
            GameState currentState = GameState::STATE_PLAYING;
            gState = true;
        }
        else {
            std::cerr << "Not done" << std::endl;
            gState = false;
        }
    }
    else {
        std::cout << "windows not create" << std::endl;
        gState = false;
    }
}

SDL_Renderer* GameLoop::getRender() {
    return renderer;
}

GamePlay* gamePlay = new GamePlay();
GameOver* gameOver = new GameOver();

void GameLoop::render() {

    SDL_RenderClear(renderer);
   // std::cout << currentState << " ";
    //if (currentState == STATE_PLAYING) {
    // gamePlay->loadGamePlay(renderer);
    //}
    gameOver->renderGO(renderer);
    //mainMenu->menuRender(renderer, event_);
    SDL_RenderPresent(renderer);
}

void GameLoop::clear() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}

void GameLoop::endGame() {
    SDL_DestroyWindow(window);
    SDL_Quit();
}

int GameLoop::getWindowHeight() {
    return WINDOW_HEIGHT;
}

int GameLoop::getWindowWidth() {
    return WINDOW_WIDTH;
}