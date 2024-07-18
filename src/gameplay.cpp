#include "header/gameplay.h"
#include "header/gameloop.h"
#include <stdlib.h>
#include <ctime>

GamePlay::GamePlay() {

}

SDL_Texture* GamePlay::loadPipe(SDL_Renderer* renderer) {
    SDL_Texture* pipeTexture = Texture::texture_create("res/pipeTop.png", renderer);
    pipe.setTexture(pipeTexture);
    return pipeTexture;
}

void GamePlay::loadGamePlay(SDL_Renderer* renderer) {
    // Render game play 
    SDL_Texture* groundTexture = Texture::texture_create("res/baselong.png", renderer);
    SDL_Texture* skyTexture = Texture::texture_create("res/playBackground.png", renderer);
    SDL_Texture* birdTexture = Texture::texture_create("res/brown_bird.png", renderer);
    // SDL_Texture* topPipeTexture = Texture::texture_create("res/pipeTop.png", renderer);
    // SDL_Texture* bottomPipeTexture = Texture::texture_create("res/pipeBottom.png", renderer);
    //textureRender(skyTexture, renderer, {0, 0, GameLoop::getWindowWidth(), GameLoop::getWindowHeight()});
    //loadPipe(renderer);
    //textureRender(groundTexture, renderer, {0, 500, 800, 140});
    bird.setTexture(birdTexture);
    bird.setRender(renderer);   
    bird.render(renderer, birdTexture);
}

bool GamePlay::isDie() {
    return false;
}

GameLoop* gameLoop;

void GamePlay::handleEvent(SDL_Event &event) {
    // bird.getJumpTime();
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            gameLoop->setGState(false);
        }
        else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_SPACE) {
            std::cout << "True" << "\n";
            bird.flap();
        }

        bird.update();
        SDL_Renderer* renderer = bird.getRender();
        SDL_RenderClear(renderer);
        bird.render(renderer, bird.getTexture());
        SDL_RenderPresent(renderer);
        //SDL_Delay(16); 

    }
}

void GamePlay::textureRender(SDL_Texture* texture, SDL_Renderer* renderer, SDL_Rect rect) {
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, &rect);
    SDL_RenderPresent(renderer);
}

// Screen dimensions
const int SCREEN_WIDTH = GameLoop::getWindowWidth();
const int SCREEN_HEIGHT = GameLoop::getWindowHeight();
const int PIPE_HEIGHT = 320;

// Pipe properties
const int PIPE_GAP = 200;
const int PIPE_SPAWN_INTERVAL = 200; // Frames between new pipe spawns

int frameCount = 0;

void GamePlay::spawnPipes(SDL_Renderer* renderer) {
    srand(SDL_GetTicks());
    if (frameCount % PIPE_SPAWN_INTERVAL == 0) {
        int gapY = rand() % (SCREEN_HEIGHT - PIPE_GAP - 150) + 50;
        std::cout << gapY << " ";
        pipes.emplace_back(loadPipe(renderer),
        GameLoop::getWindowHeight(), gapY + PIPE_GAP, true);
        pipes.emplace_back(loadPipe(renderer), 
        GameLoop::getWindowHeight(), gapY - PIPE_HEIGHT, false);
    }

    for (auto it = pipes.begin(); it != pipes.end();) {
        
        it->update();
        if (it->isOffScreen()) {
            it = pipes.erase(it);
        } else {
            ++it;
        }
    }

    for (auto& pipe : pipes) {
        pipe.render(renderer);
    }

    SDL_SetRenderDrawColor(renderer, 173, 216, 230, 255); // Light blue color

    //SDL_RenderPresent(renderer);
    SDL_Delay(16); // Delay to control frame rate (approximately 60 FPS)
    frameCount++;
}
