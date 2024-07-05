#include "header/collision.h"

bool Collision::check_Collision(SDL_Rect* a, SDL_Rect *b)
{
    SDL_bool colliosion = SDL_HasIntersection(a, b);
    if (colliosion) {
        return true;
    }
    return false;
}