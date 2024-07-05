# pragma once
#include <SDL2/SDL_image.h>

class Background {

public:
    static void loadBackground(SDL_Renderer* renderer_, const char* file_location);
};