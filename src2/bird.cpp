#include "header/bird.h"

// Bird::Bird() {

// }

Bird::Bird(const SDL_Rect& rect, const std::map<BirdDirection, Texture>& directionTextures,
     const float& velocity) :
	rect(rect),
	directionTextures(directionTextures),
	velocity(velocity),
	yPos(rect.y)
{

}

SDL_Rect Bird::getRect() {
	return rect;
}

Texture Bird::getTexture()
{
	return directionTextures.at(direction);
}

void Bird::updateYPos(const float& deltaTime)
{
	const float GRAVITY = -0.01f;
	velocity -= GRAVITY * deltaTime;
	direction = velocity > 0 ? UP : DOWN;
	yPos += velocity * deltaTime;
	rect.y = yPos;
}

void Bird::jump()
{
	velocity = -0.8f;

}