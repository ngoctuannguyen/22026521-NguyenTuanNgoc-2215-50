#include "header/gameplay.h"
#include "header/gameloop.h"

void GamePlay::loadGamePlay(SDL_Renderer* renderer) {

    SDL_Texture* groundTexture = Texture::texture_create("res/baselong.png", renderer);
    SDL_Texture* skyTexture = Texture::texture_create("res/playBackground.png", renderer);
    //textureRender(skyTexture, renderer, {0, 0, GameLoop::getWindowWidth(), GameLoop::getWindowHeight()});
    //textureRender(groundTexture, renderer, {0, 500, 800, 140});
    bird.render(renderer);
}

bool GamePlay::isDie() {
    return false;
}

void GamePlay::textureRender(SDL_Texture* texture, SDL_Renderer* renderer, SDL_Rect rect) {
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, &rect);
    SDL_RenderPresent(renderer);
}
