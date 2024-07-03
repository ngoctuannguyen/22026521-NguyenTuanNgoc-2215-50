#include <iostream>
#include <SDL2/SDL.h>

int main(int argc, char* argv[]) {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Create a window
    SDL_Window* window = SDL_CreateWindow(
        "SDL2 Window",                  // Window title
        SDL_WINDOWPOS_CENTERED,         // Initial x position
        SDL_WINDOWPOS_CENTERED,         // Initial y position
        800,                            // Width, in pixels
        600,                            // Height, in pixels
        SDL_WINDOW_SHOWN                // Flags
    );

    if (window == nullptr) {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    // The window is open: enter program loop (wait for events, etc.)
    bool quit = false;
    SDL_Event e;

    while (!quit) {
        // Handle events on queue
        while (SDL_PollEvent(&e) != 0) {
            // User requests quit
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }

        // Clear screen
        SDL_SetRenderDrawColor(SDL_GetRenderer(window), 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(SDL_GetRenderer(window));

        // Update screen
        SDL_RenderPresent(SDL_GetRenderer(window));
    }

    // Destroy window
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
