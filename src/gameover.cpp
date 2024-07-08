#include "header/gameover.h"
#include "header/gameloop.h"


void GameOver::loadTexture(SDL_Renderer* renderer) {
    fontGO = Texture::texture_create("res/gameover.png", renderer);
    background = Texture::texture_create("res/playBackground.png", renderer);
} 

void GameOver::renderGO(SDL_Renderer* renderer) {
    loadTexture(renderer);
    SDL_RenderClear(renderer);
    SDL_Rect fontGORect = {GameLoop::getWindowWidth() / 2, GameLoop::getWindowHeight() / 2, 100, 100};
    // SDL_RenderCopy(renderer, fontGO, NULL, &fontGORect);
    SDL_RenderCopy(renderer, background, NULL, NULL);
    SDL_RenderCopy(renderer, fontGO, NULL, &fontGORect);
    SDL_RenderPresent(renderer);
}
