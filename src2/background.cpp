#include "header/background.h"

Background::Background() {

}

Background::Background(const std::vector<std::pair<Texture, SDL_Rect>>& texture, const Pipes& pipes) :
    texture(texture), pipes(pipes) 
{}

std::vector<std::pair<Texture, SDL_Rect>> Background::getTexture() {
    return texture;
}

Pipes& Background::getPipes() {
    return pipes;
}

void Background::resetHeight() {
    pipes.resetHeight(pipes.getPipes());
}