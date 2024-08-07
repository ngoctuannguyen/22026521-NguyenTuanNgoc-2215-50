#pragma once
#include <SDL2/SDL.h>
#include "module.h"
#include "texture.h"

class Renderer : public Module {
private:
    SDL_Renderer* renderer = NULL;

public:
    Renderer(); 
    bool preUpdate() override;
    bool update() override;
    bool clear() override;

    SDL_Renderer* getRenderer();
    void renderTexture(const Texture& texture, const SDL_Rect& rect, bool isBottom = false);
    void renderTexture(const Texture& texture, const SDL_Rect& srcRect, const SDL_Rect& destRect);
};
