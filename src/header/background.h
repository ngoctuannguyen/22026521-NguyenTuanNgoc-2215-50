# pragma once
#include <SDL2/SDL_image.h>
#include "object.h"  

class Background: public Object {

private:
    double scrollingOffset;
    SDL_Texture* texture;

public:
    void loadBackground(SDL_Renderer* renderer_, const char* file_location);
    void loadTexture(SDL_Renderer* renderer);
    void scroll(int distance);
};