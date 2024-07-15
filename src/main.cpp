#include <iostream>
#include <SDL2/SDL.h>
#include "header/gameloop.h"
// #include "header/texture.h"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>

GameLoop* game_loop = new GameLoop();

void initSDL() {
    if (!IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG))
        std::cerr << "SDL_image error: " << IMG_GetError();
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        // return 0;
    }
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        std::cerr << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError() << std::endl;
        //return false;
    }

}

int main(int argc, char* argv[]) {

    initSDL();
    game_loop->initialize();
    while (game_loop->getGState()) {
        game_loop->render();
        
        game_loop->event();
    }
    game_loop->clear();

    // // Initialize SDL
    // if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    //     std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
    //     return 1;
    // }

    // // Create a window
    // SDL_Window* window = SDL_CreateWindow(
    //     "SDL2 Window",                  // Window title
    //     SDL_WINDOWPOS_CENTERED,         // Initial x position
    //     SDL_WINDOWPOS_CENTERED,         // Initial y position
    //     800,                            // Width, in pixels
    //     600,                            // Height, in pixels
    //     SDL_WINDOW_SHOWN                // Flags
    // );

    // if (window == nullptr) {
    //     std::cout << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
    //     SDL_Quit();
    //     return 1;
    // }

    // // The window is open: enter program loop (wait for events, etc.)
    // bool quit = false;
    // SDL_Event e;

    // while (!quit) {
    //     // Handle events on queue
    //     while (SDL_PollEvent(&e) != 0) {
    //         // User requests quit
    //         if (e.type == SDL_QUIT) {
    //             quit = true;
    //         }
    //     }

    //     // Clear screen
    //     SDL_SetRenderDrawColor(SDL_GetRenderer(window), 0xFF, 0xFF, 0xFF, 0xFF);
    //     SDL_RenderClear(SDL_GetRenderer(window));

    //     // Update screen
    //     SDL_RenderPresent(SDL_GetRenderer(window));
    // }

    //game_loop->endGame();

    return 0;
}

