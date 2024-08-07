#pragma once
#include <SDL2/SDL.h>
#include "texture.h"
#include <map>

enum BirdDirection {
    MID = 0,
    UP, 
    DOWN
};

class Bird {

private:
	SDL_Rect rect;
	BirdDirection direction = MID;
	std::map<BirdDirection, Texture> directionTextures;
	float velocity;
	float yPos;

public:

	Bird(const SDL_Rect& rect, const std::map<BirdDirection, Texture>& directionTextures,
     const float& velocity = -0.1f);

	SDL_Rect getRect();
	Texture getTexture();
	void updateYPos(const float& deltaTime);
	void jump();
};
