#include <SDL2/SDL.h>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <SDL2/SDL_image.h>
#include "pipe.h"

// Screen dimensions
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int PIPE_HEIGHT = 320;

// Pipe properties
const int PIPE_GAP = 150;
const int PIPE_SPAWN_INTERVAL = 150; // Frames between new pipe spawns

bool init(SDL_Window*& window, SDL_Renderer*& renderer) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }

    window = SDL_CreateWindow("Pipes Running", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }

    return true;
}

int main(int argc, char* args[]) {
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;

    if (!init(window, renderer)) {
        std::cerr << "Failed to initialize!" << std::endl;
        return -1;
    }

    SDL_Texture* pipeTexture = IMG_LoadTexture(renderer, "res/pipeTop.png");
    if (pipeTexture == nullptr) {
        std::cerr << "Failed to load pipe texture! SDL_Error: " << SDL_GetError() << std::endl;
        return -1;
    }

    std::vector<Pipe> pipes;
    srand(time(nullptr));
    int frameCount = 0;

    bool running = true;
    SDL_Event e;

    // while (running) {
    //     while (SDL_PollEvent(&e) != 0) {
    //         if (e.type == SDL_QUIT) {
    //             running = false;
    //         }
    //     }

    //     if (frameCount % PIPE_SPAWN_INTERVAL == 0) {
    //         int gapY = rand() % (SCREEN_HEIGHT - PIPE_GAP - 100) + 50;
    //         pipes.emplace_back(pipeTexture, SCREEN_WIDTH, gapY + PIPE_GAP, true);
    //         pipes.emplace_back(pipeTexture, SCREEN_WIDTH, gapY - PIPE_HEIGHT, false);
    //     }

    //     for (auto it = pipes.begin(); it != pipes.end();) {
    //         it->update();
    //         if (it->isOffScreen()) {
    //             it = pipes.erase(it);
    //         } else {
    //             ++it;
    //         }
    //     }

    //     SDL_SetRenderDrawColor(renderer, 173, 216, 230, 255); // Light blue color
    //     SDL_RenderClear(renderer);

    //     for (auto& pipe : pipes) {
    //         pipe.render(renderer);
    //     }

    //     SDL_RenderPresent(renderer);
    //     SDL_Delay(16); // Delay to control frame rate (approximately 60 FPS)
    //     frameCount++;
    // }


    int textureWidth, textureHeight;

    SDL_QueryTexture(IMG_LoadTexture(renderer, "res/PressStart.PNG"), NULL, NULL, &textureWidth, &textureHeight);

    std::cout << textureHeight << " " << textureWidth;

    SDL_DestroyTexture(pipeTexture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

// g++ -std=c++11 -Wall -Ilibrary\include -o main main.cpp pipe.cpp -Llibrary\lib -w  -lmingw32 -lSDL2main -lSDL2 -lSDL2_image