# pragma once
#include <SDL2/SDL_image.h>
#include "object.h"  

class Background: public Object {

public:
    void loadBackground(SDL_Renderer* renderer_, const char* file_location);
};