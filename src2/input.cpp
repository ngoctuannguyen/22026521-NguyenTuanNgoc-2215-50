#include "header/gamemanager.h"
#include "header/input.h"
#include "header/object.h"
#include <SDL2/SDL.h>
#include <iostream>

bool handleSoundClick(SDL_Rect& buttonRect) {
    int x, y;
    SDL_GetMouseState(&x, &y);
    if (x >= buttonRect.x && x <= (buttonRect.x + buttonRect.w) &&
        y >= buttonRect.y && y <= (buttonRect.y + buttonRect.h)) {
        return true;
    }
    return false;
}

bool handleTutorialClick(SDL_Rect& buttonRect) {
    int x, y;
    SDL_GetMouseState(&x, &y);
    if (x >= buttonRect.x && x <= (buttonRect.x + buttonRect.w) &&
        y >= buttonRect.y && y <= (buttonRect.y + buttonRect.h)) {
        return true;
    }
    return false;
}

bool handleExitClick(SDL_Rect& buttonRect) {
	int x, y;
	SDL_GetMouseState(&x, &y);
	SDL_Point point = {x, y};
	return SDL_PointInRect(&point, &buttonRect);
}

bool Input::update()
{
	SDL_Event e;
	Bird &bird = gameManager->moduleObject->Bird();
	bool onPlay = gameManager->moduleObject->getOnPlay();

	while (SDL_PollEvent(&e))
	{ 
		if (e.type == SDL_QUIT)
			return false;

		if (e.type == SDL_MOUSEBUTTONDOWN && handleExitClick(gameManager->moduleObject->getExitButtonTexture().second)) {
			return false;
		}

		if (e.type == SDL_MOUSEBUTTONDOWN)
		{		
			// SDL_Rect rect = gameManager->moduleObject->getSoundRect();
			SDL_Rect rect = {700, 0, 50, 49};
			SDL_Rect tutorialButtonRect = {0, 0, 100, 100};
			if (handleSoundClick(rect)) {
				onPlay = gameManager->moduleObject->getOnPlay();
				std::cout << "Handle 1 " << onPlay << std::endl;
				gameManager->moduleObject->setOnPlay(!onPlay);
				onPlay = gameManager->moduleObject->getOnPlay();
				std::cout << "Handle 2 " << onPlay << std::endl;
				gameManager->moduleObject->toggleSound();
			}
			else if (handleTutorialClick(tutorialButtonRect)) {
				gameManager->moduleObject->setTutorialState(!gameManager->moduleObject->getTutorialState());
			}
			else {
				if(gameManager->moduleObject->getGameStateManager().getGameState() == MENU) {
					gameManager->moduleObject->getGameStateManager().setGameState(PLAY);
					if (onPlay)
						gameManager->moduleSound->playClick();
				}
				else
				{
					gameManager->moduleObject->getGameStateManager().setGameState(MENU);
					gameManager->moduleObject->resetGame();
					if (onPlay)
						gameManager->moduleSound->playDead();
				}
			}
		}
		if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_SPACE) {
			if(gameManager->moduleObject->getGameStateManager().getGameState() == PLAY) {
				bird.jump();
				if (onPlay)
					gameManager->moduleSound->playJump();
				//std::cout << bird.getRect().y << std::endl;
			}
		}
	}

	return true;
}