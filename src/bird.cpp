#include "header/bird.h"
#include <iostream>
#include "header/gameloop.h"

int Bird::getYpos() {
	return yPos;
}

bool Bird::jumpState() {
	return inJump;
}

// Bird::Bird(SDL_Texture* birdTexture_) {
// 	birdTexture = birdTexture_;
// }

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
	animationTimer++;
	// if (animationTimer < 25)
	// {
	// 	SDL_RenderCopyEx(ren, birdTexture, &this->src, &this->dest, angle, NULL, SDL_FLIP_NONE);
	// }
	// else if (animationTimer >= 25 && animationTimer <= 50)
	// {
	// 	SDL_RenderCopyEx(ren, birdTexture, &this->src, &this->dest, angle, NULL, SDL_FLIP_NONE);
	// }
	// else if (animationTimer > 50)
	// {
	// 	SDL_RenderCopyEx(ren, birdTexture, &this->src, &this->dest, angle, NULL, SDL_FLIP_NONE);
	// }
	// if (animationTimer > 75)	
	// {
	// 	animationTimer = 0;
	// }
	SDL_Rect destRect = {30, yPos, 50, 50};
	SDL_RenderCopy(ren, texture, NULL, &destRect);
}

void Bird::gravity() {
	
	// if (jumpState()) {
	// 	accelerator1 = accelerator1 + 0.03;
	// 	accelerator2 = accelerator2 + 0.03;
	// 	jumpHeight = jumpHeight + gravity_;
	// 	angle -= 30;
	// 	yPos += gravity_ + accelerator1 + accelerator2 + jumpHeight;
	// 	if (yPos > 800) {
	// 		yPos = 800;
	// 	}
	// 	if (yPos < 0) {
	// 		yPos = 0;
	// 	}
	// 	setDest(25, yPos, 35, 30);
	// 	if (jumpHeight > 0) {
	// 		inJump = false;
	// 		jumpHeight = -5;
	// 	}
	// }
	// else {
	// 	if(angle >= -45 && angle <= -30) {
	// 		angle += 2;
	// 	}
	// 	else if(angle > -30 && angle <= 0) {
	// 		angle += 1.5;
	// 	}
	// 	else {
	// 		angle += 1;
	// 	}
	// 	accelerator1 = accelerator1 + 0.04;
	// 	accelerator2 = accelerator2 + 0.04;
	// 	yPos = yPos + gravity_ + accelerator1 + accelerator2;
	// 	if (yPos > 800) {
	// 		yPos = 800;
	// 	}
	// 	if (yPos < 0) {
	// 		yPos = 0;
	// 	}
	// 	setDest(25, yPos, 35, 30);
	// }

    // if (angle >= 90) {
    //     angle = 90;
    // }
    // else if(angle <= -45) {
    //     angle = -45;
    // }
}

void Bird::flap() {
    velocity = FLAP_STRENGTH;
	std::cout << "True" << "\n";
}

void Bird::update() {
	velocity += gravity_;
    yPos += velocity;
	if (yPos < 0) 
		yPos = 0;
	if (yPos > GameLoop::getWindowHeight() - BIRD_HEIGHT) 
		yPos = GameLoop::getWindowHeight() - BIRD_HEIGHT;

	// Update animation frame
	// animationTime++;
	// if (animationTime % 10 == 0) { // Adjust the modulus value to change animation speed
	// 	frame = (frame + 1) % animationFrames.size();
    // }
}

void Bird::jump() {
	inJump = true;
	flap();
	//gravity();
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
