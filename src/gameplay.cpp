#include "header/gameplay.h"
#include "header/gameloop.h"
#include <stdlib.h>
#include <ctime>

GamePlay::GamePlay() {

}

SDL_Texture* GamePlay::loadPipe(SDL_Renderer* renderer) {
    SDL_Texture* pipeTexture = Texture::texture_create("res/pipeTop.png", renderer);
    pipe.setTexture(pipeTexture);
    // std::cout << "OK";
    // upperPipe.setSrc(100, 500, 50, 50);
    // upperPipe.setDest(0, 0, 50, 50);
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
    // bird.setTexture(birdTexture);
    // bird.setRender(renderer);   
    // bird.render(renderer, birdTexture);
}

bool GamePlay::isDie() {
    return false;
}

GameLoop* gameLoop1 = new GameLoop();

void GamePlay::handleEvent(SDL_Event &e) {
    // bird.getJumpTime();
    // while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) {
            gameLoop1->setGState(false);
        }
        // e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_SPACE
        else if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_SPACE) {
            std::cout << "True" << "\n";
            bird.flap();
        }
    
        bird.update();
        bird.render(bird.getRender(), bird.getTexture());
    // }
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
const int PIPE_SPAWN_INTERVAL = 150; // Frames between new pipe spawns

int frameCount = 0;

void GamePlay::spawnPipes(SDL_Renderer* renderer) {
    srand(time(NULL));
    if (frameCount % PIPE_SPAWN_INTERVAL == 0) {
        int gapY = rand() % (SCREEN_HEIGHT - PIPE_GAP - 100) + 50;
        std::cout << gapY << " ";
        pipes.emplace_back(loadPipe(renderer),
        GameLoop::getWindowHeight(), gapY + PIPE_GAP, true);
        pipes.emplace_back(loadPipe(renderer), 
        GameLoop::getWindowWidth(), gapY - PIPE_HEIGHT, false);
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

// bool GamePlay::checkCollision() {
//     SDL_Rect birdRect = bird.getRect();
//     for (const auto& pipe : pipes) {
//         SDL_Rect pipeRect = pipe.getRect();
//         if (SDL_HasIntersection(&birdRect, &pipeRect)) {
//             return true;
//         }
//     }
//     return false;
// }