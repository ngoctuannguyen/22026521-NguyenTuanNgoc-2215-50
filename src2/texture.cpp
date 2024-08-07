#include "header/texture.h"
#include <SDL2/SDL_image.h>

Texture::Texture() {

}

Texture::Texture(const char* file_path, SDL_Renderer* renderer) {
    this->file_path = file_path;
    this->texture = IMG_LoadTexture(renderer, file_path);
}

SDL_Texture* Texture::getTexture() const {
    return texture;
}