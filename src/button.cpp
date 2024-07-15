#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "header/button.h"

Button::Button() {}

Button::~Button() {}

Button::Button(int x, int y, int w, int h, SDL_Texture* texture) 
    : rect{x, y , w, h}, texture(texture) {
    dest = rect;
} 

void Button::render(SDL_Renderer* renderer) {
    //std::cout << this->getSrc().w << " " << this->getDest().w << std::endl;
    SDL_RenderCopy(renderer, texture, &this->getSrc(), &this->getDest());
}

bool Button::eventHandler(SDL_Event* e) {
    if (e->type == SDL_MOUSEBUTTONDOWN) {
        int mouseX, mouseY;
        SDL_GetMouseState(&mouseX, &mouseY);

        bool inside = true;
        if (mouseX < rect.x) {
            inside = false;
        } else if (mouseX > rect.x + rect.w) {
            inside = false;
        } else if (mouseY < rect.y) {
            inside = false;
        } else if (mouseY > rect.y + rect.h) {
            inside = false;
        }

        if (inside) {
            return true;
        }
    }
    return false;
}

// void Button::createButton(int x, int y, int w, int h, SDL_Texture* texture) {
//     Button(int x, int y, int w, int h, SDL_Texture* texture);
// }

void Button::loadTexture(SDL_Renderer* renderer) {
    
}
