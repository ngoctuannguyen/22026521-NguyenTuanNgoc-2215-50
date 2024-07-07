#include "header/texture.h"
#include <SDL2/SDL_image.h>

SDL_Texture* Texture::texture_create(const char* file_location, SDL_Renderer* renderer) {
    
    SDL_Texture *texture = IMG_LoadTexture(renderer, file_location);
    return texture;
}

// void Texture::textureRender(SDL_Texture* texture, SDL_Renderer* renderer, SDL_Rect rect) {
//     SDL_RenderClear(renderer);
//     SDL_RenderCopy(renderer, texture, NULL, &rect);
//     SDL_RenderPresent(renderer);
// }