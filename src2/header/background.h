#pragma once
#include <vector>
#include <SDL2/SDL.h>
#include "texture.h"
#include "pipe.h"

class Background {
private: 
    std::vector<std::pair<Texture, SDL_Rect>> texture;
    Pipes pipes;

public:
    Background();
    Background(const std::vector<std::pair<Texture,SDL_Rect>>& texture, const Pipes& pipes);

    std::vector<std::pair<Texture,SDL_Rect>> getTexture();
    Pipes& getPipes();
    void resetHeight();
};
