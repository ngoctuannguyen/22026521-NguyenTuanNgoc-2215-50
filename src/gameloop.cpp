#include "header/gameloop.h"
#include <SDL2/SDL.h>
#include "header/background.h"
#include "header/mainMenu.h"
#include "header/gamestate.h"
#include "header/gameplay.h"
#include "header/gameover.h"

GameState currentState;

MainMenu* mainMenu = new MainMenu();

GamePlay* gamePlay = new GamePlay();
GameOver* gameOver = new GameOver();

const std::string HIGH_SCORE_FILE = "highscore.txt";

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
    while(SDL_PollEvent(&event_)) {
        // The SDL_PollEvent function is used to poll for currently pending events and processes them
        if (event_.type == SDL_QUIT) {
            gState = false;
        }
        if (event_.type == SDL_MOUSEMOTION) {
            // std::cout << event_.motion.x << " " << event_.motion.y << std::endl;
        }
        gamePlay->handleEvent(event_);

    }
    // gamePlay->handleEvent(event_);

}

void GameLoop::initialize() {
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow(
        "Flappy Bird", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0
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

void GameLoop::render() {

    SDL_RenderClear(renderer);
   // std::cout << currentState << " ";
    //if (currentState == STATE_PLAYING) {
    gamePlay->loadGamePlay(renderer); 
    // Load gameplay with bird, ground, sky
    //}
    // gameOver->renderGO(renderer);
    //mainMenu->menuRender(renderer, event_);
    //gamePlay->spawnPipes(renderer);
    SDL_RenderPresent(renderer);
}

void GameLoop::clear() {
    mainMenu->destroy();
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

void GameLoop::setGState(bool _gState) {
    gState = _gState;
}

int loadHighScore() {
    std::ifstream file(HIGH_SCORE_FILE);
    int highScore = 0;
    if (file.is_open()) {
        file >> highScore;
        file.close();
    }
    return highScore;
}

void saveHighScore(int highScore) {
    std::ofstream file(HIGH_SCORE_FILE);
    if (file.is_open()) {
        file << highScore;
        file.close();
    }
}