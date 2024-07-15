#pragma once
#include "header/mainMenu.h"
#include "header/gameloop.h"

MainMenu::MainMenu() {
	isClicked = false;
	isSelected = false;
	destButton.x = 270;
	destButton.y = 500;
	destButton.w = 250;
	destButton.h = 70;
}

void MainMenu::Initialize(SDL_Renderer* renderer)
{
	SDL_Texture* startTextture = Texture::texture_create("res/PressStart.PNG", renderer);

	startButton = new Button(destButton.x, destButton.y, destButton.w, destButton.h, startTextture);
	startButton->setSrc(0, 0, 225, 66);
	startButton->setDest(destButton.x, destButton.y, destButton.w, destButton.h);
	startButton->render(renderer);
	
	menuBackground.loadBackground(renderer, "res/MainMenu.png");

	startSound = Mix_LoadWAV("res/audio/replaySound.wav");
	if(startSound == NULL)
	{
		std::cout<< Mix_GetError() <<std::endl;
	}
}

bool MainMenu::checkSelected(int x, int y)
{
	if (x >= destButton.x 
	   && x <= destButton.x + destButton.w 
	   && y >= destButton.y 
	   && y <= destButton.y + destButton.h) {
		return true;
	}
	return false;
}

void MainMenu::menuRender(SDL_Renderer* renderer, SDL_Event &e)
{	
	Initialize(renderer);
	while(true)
	{	
		startButton->render(renderer);
		//SDL_RenderCopy(renderer, startButton, &this->getSrc(), &this->getDest());
		while(SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT) {
				exit(0);
			}
			if(e.type == SDL_MOUSEMOTION) {
				if(checkSelected(e.motion.x, e.motion.y))
				{
					if(!isSelected)
					{
						isSelected = true;
						start.setSrc(0, 0, 225, 66);
						start.setDest(destButton.x, destButton.y, destButton.w, destButton.h);
						std::cout << "F1" << std::endl;
					}
				}
				else
				{
					if(isSelected)
					{
						isSelected = false;
						start.setSrc(252,0, 225, 66);
						start.setDest(destButton.x, destButton.y, destButton.w, destButton.h);
						std::cout << "F2" << std::endl;

					}
				}
			}
			if (e.type == SDL_MOUSEBUTTONDOWN
				&& e.motion.x > destButton.x 
				&& e.motion.x < destButton.x + destButton.w 
				&& e.motion.y > destButton.y 
				&& e.motion.y < destButton.y + destButton.h)
			{
				Mix_PlayChannel(-1, startSound, 0);
				std::cout << "FFFFF" << std::endl;
				isClicked = true;
			}
				// std::cout << "true" << std::endl;
			if (startButton->eventHandler(&e)) {
				std::cout << "True" << std::endl;
			}	
		}
			if(isClicked) {
				break;
			}
		}
}

MainMenu::~MainMenu() {
	// isClicked = false;
	// isSelected = false;
	startButton = NULL;
	Mix_FreeChunk(startSound);
	Mix_CloseAudio();
    Mix_Quit();
	// SDL_DestroyTexture(startText)
}

void MainMenu::loadTexture(SDL_Renderer* renderer) {
	
}