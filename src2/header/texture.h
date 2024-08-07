#pragma once
#include <SDL2/SDL.h>
#include <string>

class Texture {

private:

    SDL_Texture* texture;
    std::string file_path;

public:
    Texture();
    Texture(const char* file_path, SDL_Renderer* renderer);
    SDL_Texture* getTexture() const; 
};