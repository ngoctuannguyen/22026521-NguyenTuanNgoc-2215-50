#include "header/render.h"
#include "header/gamewindow.h"
#include "header/gamemanager.h"
#include <iostream>
#include "header/common.h"

const SDL_Rect SCORE_BOX = {
    200, 80, 100, 50
};

Renderer::Renderer()
{   
    // std::cout << gameManager->moduleWindow << std::endl;
    renderer = SDL_CreateRenderer(gameManager->moduleWindow->getWindow(), -1, 0);
    if (renderer == NULL) {
        std::cerr << "Error: " << SDL_GetError() << std::endl;
    }
    // SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
}

bool Renderer::preUpdate()
{   
    SDL_RenderClear(renderer);
    return true;
}

void Renderer::renderTexture(const Texture &texture, const SDL_Rect &rect, bool isBottom)
{
    if (!isBottom) {
        SDL_RenderCopy(renderer, texture.getTexture(), NULL, &rect);
    } else {
        SDL_RenderCopyEx(renderer, texture.getTexture(), NULL, &rect,
        180, 0, SDL_FLIP_HORIZONTAL);
    }
}

void Renderer::renderTexture(const Texture &texture, const SDL_Rect &srcRect, const SDL_Rect &destRect)
{
    SDL_RenderCopy(renderer, texture.getTexture(), &srcRect, &destRect);
}

bool Renderer::update()
{   
    int gameState = gameManager->moduleObject->getGameStateManager().getGameState();

    // Background
    for(auto& background : gameManager->moduleObject->getScrollingBackground().getBackgrounds())
	{           
        // Render background
        renderTexture(background.first.getTexture()[0].first, background.first.getTexture()[0].second + background.second);
        // Rendere base
        renderTexture(background.first.getTexture()[1].first, background.first.getTexture()[1].second + background.second);

        // std::cout << "NTN" << background.first.getPipes().getPipes().size() << std::endl;
        // Render pipes
		for (auto& pipe : background.first.getPipes().getPipes()) {
            //std::cout << pipe.rect.x << " " << background.second << " " << (pipe.rect + background.second).x << std::endl;
			renderTexture(background.first.getPipes().getTexture(), pipe.rect + background.second, pipe.isBottom);
        }
	}

    // Menu
    if(gameState == MENU) {
        SDL_Rect menuRect = {300, 180, 200, 400};
        renderTexture(gameManager->moduleObject->getMenuTexture(), menuRect);
    }

    // // Bird
    
    Bird bird = gameManager->moduleObject->getBird();
    renderTexture(bird.getTexture(), bird.getRect());

    // // Score

    // Sound Texture
    
    SDL_Rect srcRect = {0, 0, 404, 309};
    if (gameManager->moduleObject->getOnPlay() == false) {
        SDL_Rect srcRect = {404, 0, 403, 309};
    }
    SDL_Rect destRect = {750, 0, 50, 50};
    renderTexture(gameManager->moduleObject->getSoundTexture(), srcRect, destRect);

    // // Gameover

    if(gameState == DEAD) {
        SDL_Rect deadRect = {300, 300, 300, 100};
		renderTexture(gameManager->moduleObject->getDeadTexture(), deadRect);
    }

    SDL_RenderPresent(renderer);

    return true;
}

bool Renderer::clear()
{   
    SDL_DestroyRenderer(renderer);
    return true;
}

SDL_Renderer *Renderer::getRenderer()
{
    return renderer;
}

