#include "pipe.h"

// Pipe properties
const int PIPE_WIDTH = 50;
const int PIPE_HEIGHT = 320;
const int PIPE_VELOCITY = 2;

Pipe::Pipe(SDL_Texture* texture, int x, int y, bool isBottom)
    : texture(texture), x(x), y(y), isBottom(isBottom) {}

void Pipe::update() {
    x -= PIPE_VELOCITY;
}

void Pipe::render(SDL_Renderer* renderer) {
    SDL_Rect dstRect = {x, y, PIPE_WIDTH, PIPE_HEIGHT};
    SDL_RenderCopyEx(renderer, texture, NULL, &dstRect, 0, NULL, isBottom ? SDL_FLIP_VERTICAL : SDL_FLIP_NONE);
}

SDL_Rect Pipe::getRect() const {
    return {x, y, PIPE_WIDTH, PIPE_HEIGHT};
}

bool Pipe::isOffScreen() const {
    return x + PIPE_WIDTH < 0;
}
