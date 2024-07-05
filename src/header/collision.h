#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Collision
{    
    public:
        static bool check_Collision(SDL_Rect* a, SDL_Rect *b);
};