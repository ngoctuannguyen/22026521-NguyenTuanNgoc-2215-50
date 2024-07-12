#include <SDL2/SDL_image.h>
#include "header/background.h"

void Background::loadBackground(SDL_Renderer* renderer_, const char* file_name) {
    SDL_Texture* texture = IMG_LoadTexture(renderer_, file_name);
    SDL_RenderCopy(renderer_, texture, 0, 0);
    SDL_RenderPresent(renderer_);
}

void Background::loadTexture(SDL_Renderer* renderer) {
    
}

void Background::scroll(int distance) {

    if (scrollingOffset > distance) {
        scrollingOffset -= distance;
    }    
    else scrollingOffset = 0; ////////
}