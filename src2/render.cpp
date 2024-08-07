#include "header/render.h"
#include "header/gamewindow.h"
#include "header/gamemanager.h"
#include <iostream>
#include "header/common.h"
#include "header/texture.h"

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
        SDL_Rect tutorialRect = {0, 0, 100, 100};
        renderTexture(gameManager->moduleObject->getTutorialButtonTexture(), tutorialRect);
        if (gameManager->moduleObject->getTutorialState()) {
            SDL_Rect tutorialRect = {0, 0, 800, 640};
            renderTexture(gameManager->moduleObject->getTutorialTexture(), tutorialRect);
        }
    }

     // Exit
    std::pair<Texture, SDL_Rect> exit = gameManager->moduleObject->getExitButtonTexture();
    renderTexture(exit.first, exit.second);


    // // Bird
    
    Bird bird = gameManager->moduleObject->getBird();
    renderTexture(bird.getTexture(), bird.getRect());

    // // Score

    // std::cout << "Score: " << gameManager->moduleObject->getScoreTextures().size() << std::endl;
    if (gameState == PLAY) {
        SDL_Rect scoreBox;
        std::vector<Texture> scoreTexture = gameManager->moduleObject->getScoreTextures();
        int offsetW = 0;
        for (auto score : scoreTexture) {
            scoreBox = {50 + offsetW, 50, 50, 50};
            renderTexture(score, scoreBox);
            offsetW += 50;
            // std::cout << "Score: " << &score << std::endl;
        };
    }

    // Sound Texture
    
    SDL_Rect srcRect = {0, 0, 404, 309};
    if (gameManager->moduleObject->getOnPlay() == false) {
        srcRect = {404, 0, 403, 309};
    }
    SDL_Rect destRect = {700, 0, 49, 50};
    renderTexture(gameManager->moduleObject->getSoundTexture(), srcRect, destRect);

    // Gameover

    if(gameState == DEAD) {
        SDL_Rect deadRect = {200, 200, 400, 400};
		renderTexture(gameManager->moduleObject->getDeadTexture(), deadRect);

        // Score

        SDL_Rect scoreBox = {500, 500, 20, 20};
        SDL_Rect bestScoreBox = {500, 600, 20, 20};
        int offsetW = 0;
        for (auto& score : gameManager->moduleObject->getScoreTextures()) {
            scoreBox = {520 + offsetW, 425, 20, 20};
            renderTexture(score, scoreBox);
            offsetW += 20;
            // std::cout << "Score: " << &score << std::endl;
        }

        offsetW = 0;
        for (auto& score : gameManager->moduleObject->getScoreTextures(true)) {
            bestScoreBox = {520 + offsetW, 525, 20, 20};
            renderTexture(score, bestScoreBox);
            offsetW += 20;
            // std::cout << "Score: " << &score << std::endl;
        }
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

