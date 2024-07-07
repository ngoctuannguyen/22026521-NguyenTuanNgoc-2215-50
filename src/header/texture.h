# pragma once
#include <iostream>
// #include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Texture {

public:
    static SDL_Texture* texture_create(const char* file_location, SDL_Renderer* renderer);
    //static void textureRender(SDL_Texture* texture_, SDL_Renderer* renderer, SDL_Rect rect);
};