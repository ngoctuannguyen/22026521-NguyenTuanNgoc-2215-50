#ifndef PIPE_H
#define PIPE_H

#include <SDL2/SDL.h>

class Pipe {
public:
    Pipe(SDL_Texture* texture, int x, int y, bool isBottom);
    void update();
    void render(SDL_Renderer* renderer);
    SDL_Rect getRect() const;
    bool isOffScreen() const;

private:
    SDL_Texture* texture;
    int x, y;
    bool isBottom;
};

#endif
