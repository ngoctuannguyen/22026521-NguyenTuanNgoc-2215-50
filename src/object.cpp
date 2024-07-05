#include "header/object.h"

Object::Object() {
	texture = NULL;
}

SDL_Texture* Object::getTexture() {
	return texture;
}

SDL_Rect& Object::getSrc() {
	return src;
}
SDL_Rect& Object::getDest() {
	return dest;
}

void Object::setSrc(int x, int y, int w, int h) {
	src.x = x;
	src.y = y;
	src.w = w;
	src.h = h;
}

void Object::setDest(int x, int y, int w, int h) {
	dest.x = x;
	dest.y = y;
	dest.w = w;
	dest.h = h;
}

void Object::CreateTexture(char* address, SDL_Renderer* ren) {
	texture = Texture::texture_create(address, ren);
}