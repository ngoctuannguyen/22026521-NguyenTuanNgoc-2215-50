#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "texture.h"
#include "object.h"

class GameOver: Object {
private:
    SDL_Texture* fontGO;
    SDL_Texture* background;
public:
    void renderGO(SDL_Renderer* renderer);
    void loadTexture(SDL_Renderer* renderer);
};