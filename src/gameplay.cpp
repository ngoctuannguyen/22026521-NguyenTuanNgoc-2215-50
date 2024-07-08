#include "header/gameplay.h"
#include "header/gameloop.h"

void GamePlay::loadGamePlay(SDL_Renderer* renderer) {
    // Render game play 
    SDL_Texture* groundTexture = Texture::texture_create("res/baselong.png", renderer);
    SDL_Texture* skyTexture = Texture::texture_create("res/playBackground.png", renderer);
    // SDL_Texture* topPipeTexture = Texture::texture_create("res/pipeTop.png", renderer);
    // SDL_Texture* bottomPipeTexture = Texture::texture_create("res/pipeBottom.png", renderer);
    //textureRender(skyTexture, renderer, {0, 0, GameLoop::getWindowWidth(), GameLoop::getWindowHeight()});
    //loadPipe(renderer);
    //textureRender(groundTexture, renderer, {0, 500, 800, 140});
    bird.render(renderer);
    
}

bool GamePlay::isDie() {
    return false;
}

void GamePlay::handleEvent() {
    bird.getJumpTime();
    SDL_PollEvent(&e);
    if (e.type == SDL_QUIT) {

    }
    else if (e.type == SDL_KEYDOWN)
	{
		if (e.key.keysym.sym == SDLK_SPACE)
		{
			if(!bird.jumpState())
			{
                bird.jump();
                // Mix_PlayChannel(-1, wingSound, 0);
			}
            else
            {
                bird.gravity();
            }
	    }
	}
	else {
		bird.gravity();
	}
	if (isDie())
	{
	// if(event.type == SDL_MOUSEBUTTONDOWN
	// 	&& event.motion.x > 250 
	// 	&& event.motion.x < 380 
	// 	&& event.motion.y > 600 
	// 	&& event.motion.y < 640)
	// 	{
	// 		Mix_PlayChannel(-1, replaySound, 0);
	// 		SDL_Delay(100);
	// 		Reset();
	// 	}
	// else if(event.type == SDL_MOUSEBUTTONDOWN 
	// 		&& event.motion.x > 250 
	// 		&& event.motion.x < 320 
	// 		&& event.motion.y > 650 
	// 		&& event.motion.y < 690)
	// 	{
	// 		Mix_PlayChannel(-1, exitSound, 0);
	// 		SDL_Delay(100);
	// 		isRunning = false;
	// 		clear();
	// 	}
    }
}

void GamePlay::textureRender(SDL_Texture* texture, SDL_Renderer* renderer, SDL_Rect rect) {
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, &rect);
    SDL_RenderPresent(renderer);
}

void GamePlay::loadPipe(SDL_Renderer* renderer) {
    SDL_Texture* topPipeTexture = Texture::texture_create("res/pipeTop.png", renderer);
    SDL_Texture* bottomPipeTexture = Texture::texture_create("res/pipeBottom.png", renderer);
    upperPipe.setSrc(100, 500, 50, 50);
    upperPipe.setDest(0, 0, 50, 50);
    // std::cerr << upperPipe.getDest().w << " " << upperPipe.getDest().h << " " << upperPipe.getDest().x << " " << upperPipe.getDest().y << "\n"; 
    upperPipe.Render(renderer);
}