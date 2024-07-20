#include "header/bird.h"
#include <iostream>
#include "header/gameloop.h"

int Bird::getYpos() {
	return yPos;
}

bool Bird::jumpState() {
	return inJump;
}

void Bird::setRender(SDL_Renderer* renderer_) {
	renderer = renderer_;
}

SDL_Renderer* Bird::getRender() {
	return renderer;
}

void Bird::setTexture(SDL_Texture* texture) {
	birdTexture = texture;
}

SDL_Texture* Bird::getTexture() {
	return birdTexture;
}


void Bird::render(SDL_Renderer* ren, SDL_Texture* texture)
{
	SDL_Rect destRect = {30, yPos, 50, 50};
	SDL_RenderCopy(ren, texture, NULL, &destRect);
}

void Bird::flap() {
    velocity = FLAP_STRENGTH;
}

void Bird::update() {
	velocity += gravity;
	std::cout << velocity << std::endl;
    yPos += velocity;
	if (yPos < 0) 
		yPos = 0;
	int windowHeight = GameLoop::getWindowHeight();
	if (yPos > windowHeight - BIRD_HEIGHT) 
		yPos = windowHeight - BIRD_HEIGHT;

}

void Bird::getJumpTime() {
	jumpTimer = SDL_GetTicks();
}

void Bird::reset() {
	accelerator1 = 0;
	accelerator2 = 0;
	yPos = 256;
	lastJump = 0;
	angle = 0;
}

SDL_Rect Bird::getRect() {
	return {x, yPos, BIRD_WIDTH, BIRD_HEIGHT};
}
