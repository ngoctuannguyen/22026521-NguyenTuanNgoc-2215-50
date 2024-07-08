#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "object.h"

class Button: public Object {

private:
    SDL_Texture* texture;
    SDL_Rect rect;

public:
    Button(int x, int y, int w, int h, SDL_Texture* texture);
    Button();
    ~Button();
    void createButton(int x, int y, int w, int h, SDL_Texture* texture);
    void render(SDL_Renderer* renderer);
    bool eventHandler(SDL_Event* e);
    void loadTexture(SDL_Renderer* renderer);
};