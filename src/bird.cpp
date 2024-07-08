#include "header/bird.h"
#include <iostream>

int Bird::getYpos() {
	return Ypos;
}

bool Bird::jumpState() {
	return inJump;
}

void Bird::render(SDL_Renderer* ren)
{
	animationTimer++;
	SDL_Texture* birdTexture = Texture::texture_create("res/brown_bird.jpg", ren);
	if (animationTimer < 25)
	{
		SDL_RenderCopyEx(ren, birdTexture, &this->src, &this->dest, angle, NULL, SDL_FLIP_NONE);
	}
	else if (animationTimer >= 25 && animationTimer <= 50)
	{
		SDL_RenderCopyEx(ren, birdTexture, &this->src, &this->dest, angle, NULL, SDL_FLIP_NONE);
	}
	else if (animationTimer > 50)
	{
		SDL_RenderCopyEx(ren, birdTexture, &this->src, &this->dest, angle, NULL, SDL_FLIP_NONE);
	}
	if (animationTimer > 75)
	{
		animationTimer = 0;
	}
	// SDL_Texture* birdTexture = Texture::texture_create("res/brown_bird.jpg", ren);
	// SDL_Rect birdRect = {10, 10, 10, 10};
	// SDL_RenderCopy(ren, birdTexture, NULL, &birdRect);
}

void Bird::gravity() {
	
	if (jumpState()) {
		accelerator1 = accelerator1 + 0.03;
		accelerator2 = accelerator2 + 0.03;
		jumpHeight = jumpHeight + gravity_;
		angle -= 30;
		Ypos += gravity_ + accelerator1 + accelerator2 + jumpHeight;
		setDest(25, Ypos, 35, 30);
		if (jumpHeight > 0) {
			inJump = false;
			jumpHeight = -5;
		}
	}
	else {
		if(angle >= -45 && angle <= -30) {
			angle += 2;
		}
		else if(angle > -30 && angle <= 0) {
			angle += 1.5;
		}
		else {
			angle += 1;
		}
		accelerator1 = accelerator1 + 0.04;
		accelerator2 = accelerator2 + 0.04;
		Ypos = Ypos + gravity_ + accelerator1 + accelerator2;
		setDest(25, Ypos, 35, 30);
	}

    if (angle >= 90) {
        angle = 90;
    }
    else if(angle <= -45) {
        angle = -45;
    }
}

void Bird::jump() {
	if (jumpTimer - lastJump > 10) {
		accelerator1 = 0;
		accelerator2 = 0;
		inJump = true;
		lastJump = jumpTimer;
	}
	else {
		gravity();
	}
}

void Bird::getJumpTime() {
	jumpTimer = SDL_GetTicks();
}

void Bird::reset() {
	accelerator1 = 0;
	accelerator2 = 0;
	Ypos = 256;
	lastJump = 0;
	angle = 0;
}
