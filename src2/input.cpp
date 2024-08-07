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

bool Input::update()
{
	SDL_Event e;
	Bird &bird = gameManager->moduleObject->Bird();

	while (SDL_PollEvent(&e))
	{
		if(e.type == SDL_QUIT)
			return false;

		else if(e.type == SDL_MOUSEBUTTONDOWN)
		{		
			SDL_Rect rect = gameManager->moduleObject->getSoundRect();
			if (handleSoundClick(rect)) {
				bool onPlay = gameManager->moduleObject->getOnPlay();
				gameManager->moduleObject->setOnPlay(!onPlay);
				gameManager->moduleObject->toggleSound();
			}
			else {
				if(gameManager->moduleObject->getGameStateManager().getGameState() == MENU) {
					gameManager->moduleObject->getGameStateManager().setGameState(PLAY);
					gameManager->moduleSound->playClick();
				}
				else
				{
					gameManager->moduleObject->getGameStateManager().setGameState(MENU);
					gameManager->moduleObject->resetGame();
					gameManager->moduleSound->playDead();
				}
			}
		}
		if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_SPACE) {
			if(gameManager->moduleObject->getGameStateManager().getGameState() == PLAY) {
				bird.jump();
				gameManager->moduleSound->playJump();
				//std::cout << bird.getRect().y << std::endl;
			}
		}
	}

	return true;
}